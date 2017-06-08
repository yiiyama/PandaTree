#include "../interface/CollectionBase.h"
#include "../interface/IOUtils.h"

#include "TList.h"

panda::CollectionBase::~CollectionBase()
{
  auto deleteFromTree([this](TTree& _tree) {
      auto* uinfo(_tree.GetUserInfo());
      for (TObject* obj : *uinfo) {
        if (obj->GetName() != this->name_)
          continue;

        auto* cleaner(dynamic_cast<TreePointerCleaner*>(obj));
        if (cleaner && cleaner->getColl() == this) {
          uinfo->Remove(obj);
          delete obj;
          break;
        }
      }
    });

  for (auto& input : inputs_)
    deleteFromTree(*input.first);

  for (auto& output : outputs_)
    deleteFromTree(*output.first);
}

Int_t
panda::CollectionBase::getEntry(TTree& _tree, Long64_t _iEntry)
{
  init();

  prepareGetEntry(_tree, _iEntry);

  return _tree.GetEntry(_iEntry);
}

Int_t
panda::CollectionBase::fill(TTree& _tree)
{
  prepareFill(_tree);

  return _tree.Fill();
}

void
panda::CollectionBase::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  _out << "size: " << size() << ", allocated size: " << getData().nmax() << std::endl;
  ContainerBase::print(_out, _level);
}

void
panda::CollectionBase::dump(std::ostream& _out/* = std::cout*/) const
{
  _out << "size_ = " << size_ << std::endl;
  _out << "sizeIn_ = " << sizeIn_ << std::endl;
  _out << "inputs_  = map(" << inputs_.size() << ")" << std::endl;
  _out << "outputs_  = map(" << outputs_.size() << ")" << std::endl;
  ContainerBase::dump(_out);
}

void
panda::CollectionBase::resize(UInt_t _size)
{
  if (_size > getData().nmax()) {
    UInt_t nmax(getData().nmax());
    while (nmax < _size)
      nmax *= 2;

    reallocate_(nmax);

    // signal address change
    for (auto& input : inputs_)
      input.second.second = -1;
    for (auto& output : outputs_)
      output.second = -1;
  }

  unsigned oldSize(size_);

  size_ = _size;
  getData().resizeVectors_(_size);

  for (unsigned iE(oldSize); iE < size_; ++iE)
    elemAt(iE).init();
}

void
panda::CollectionBase::reserve(UInt_t _size)
{
  if (_size > getData().nmax()) {
    reallocate_(_size);

    // signal address change
    for (auto& input : inputs_)
      input.second.second = -1;
    for (auto& output : outputs_)
      output.second = -1;
  }
}

void
panda::CollectionBase::prepareGetEntry(TTree& _tree, Long64_t _iEntry, Long64_t _localEntry/* = -1*/)
{
  if (inputs_.empty())
    return;

  auto&& iItr(inputs_.find(&_tree));
  if (iItr == inputs_.end())
    return;

  if (_localEntry < 0) {
    // LoadTree returns the entry number on the current tree.
    _localEntry = _tree.LoadTree(_iEntry);
    if (_localEntry < 0)
      return;
  }
  // if _localEntry is non-negative, we assume that LoadTree is already called and therefore
  // _tree.GetTreeNumber() returns the correct tree number for the given _iEntry.

  if (iItr->second.second != _tree.GetTreeNumber()) {
    auto* branch(_tree.GetBranch(name_ + ".size"));
    if (!branch)
      throw std::runtime_error(("Could not find branch " + name_ + ".size in input tree").Data());

    branch->SetAddress(&sizeIn_);
    iItr->second.first = branch;
    iItr->second.second = _tree.GetTreeNumber();
  }

  iItr->second.first->GetEntry(_localEntry);
  resize(sizeIn_);

  // in-synch flag may be reset during resize()
  if (iItr->second.second < 0) {
    // setStatus is false -> won't set address on branches that are turned off
    doSetAddress_(_tree, {"*"}, false, true);
    iItr->second.second = _tree.GetTreeNumber();
  }
}

void
panda::CollectionBase::prepareFill(TTree& _tree)
{
  if (outputs_.empty())
    return;

  auto&& iItr(outputs_.find(&_tree));
  if (iItr == outputs_.end())
    return;

  if (iItr->second < 0) {
    doSetAddress_(_tree, {"*"}, false, false);
    iItr->second = _tree.GetTreeNumber();
  }
}

/*private*/
void
panda::CollectionBase::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  if (!_tree.GetBranch(name_ + ".size"))
    return;

  // If explicitly instructed to turn off size -> turn size false
  if (utils::BranchName("size").vetoed(_branches))
    _tree.SetBranchStatus(name_ + ".size", false);
  else
    _tree.SetBranchStatus(name_ + ".size", true);

  getData().setStatus(_tree, name_, _branches);
}

/*private*/
panda::utils::BranchList
panda::CollectionBase::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;

  if (_tree.GetBranch(name_ + ".size") && _tree.GetBranchStatus(name_ + ".size"))
    blist.emplace_back(name_ + ".size");
  else
    blist.emplace_back("!" + name_ + ".size");

  blist += getData().getStatus(_tree, name_);

  return blist;
}

/*private*/
void
panda::CollectionBase::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus, Bool_t _asInput)
{
  if (!_branches.matchesAny(getBranchNames(false)))
    return;

  if (_asInput) {
    auto* branch(_tree.GetBranch(name_ + ".size"));
    if (!branch)
      return;

    Int_t sizeStatus(utils::setAddress(_tree, name_, "size", &sizeIn_, {"size"}, _setStatus));
    if (sizeStatus != 1)
      return;

    if (inputs_.count(&_tree) == 0) {
      inputs_.emplace(&_tree, std::make_pair(branch, _tree.GetTreeNumber()));
      _tree.GetUserInfo()->Add(new TreePointerCleaner(this, &_tree, true));
    }
  }
  else {
    Int_t sizeStatus(utils::setAddress(_tree, name_, "size", &size_, {"size"}, _setStatus));
    if (sizeStatus != 1)
      return;
  }
  
  getData().setAddress(_tree, name_, _branches, _setStatus);
}

/*private*/
void
panda::CollectionBase::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  if (!_branches.matchesAny(getBranchNames(false)))
    return;

  if (outputs_.count(&_tree) != 0)
    throw std::runtime_error(("Doubly booking collection " + name_ + " on tree").Data());

  _tree.Branch(name_ + ".size", &size_, "size/i");

  getData().book(_tree, name_, _branches, true);

  outputs_.emplace(&_tree, _tree.GetTreeNumber());

  _tree.GetUserInfo()->Add(new TreePointerCleaner(this, &_tree, false));
}


panda::CollectionBase::TreePointerCleaner::TreePointerCleaner(CollectionBase* coll, TTree* tree, bool input) :
  coll_(coll),
  tree_(tree),
  input_(input)
{
  SetBit(kIsOnHeap);
}

panda::CollectionBase::TreePointerCleaner::~TreePointerCleaner()
{
  if (input_)
    coll_->inputs_.erase(tree_);
  else
    coll_->outputs_.erase(tree_);
}
