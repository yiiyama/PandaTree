#include "../interface/CollectionBase.h"
#include "../interface/IOUtils.h"

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
      input.second.second = false;
    for (auto& output : outputs_)
      output.second = false;
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
      input.second.second = false;
    for (auto& output : outputs_)
      output.second = false;
  }
}

void
panda::CollectionBase::prepareGetEntry(TTree& _tree, Long64_t _iEntry)
{
  auto&& iItr(inputs_.find(&_tree));
  if (iItr == inputs_.end())
    return;

  iItr->second.first->GetEntry(_iEntry);
  resize(sizeIn_);

  // in-synch flag may be reset during resize()
  if (!iItr->second.second) {
    doSetAddress_(_tree, {"*"}, false, true);
    iItr->second.second = true;
  }
}

void
panda::CollectionBase::prepareFill(TTree& _tree)
{
  auto&& iItr(outputs_.find(&_tree));
  if (iItr == outputs_.end())
    return;

  if (!iItr->second) {
    doSetAddress_(_tree, {"*"}, false, false);
    iItr->second = true;
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
  if (_asInput) {
    auto* branch(_tree.GetBranch(name_ + ".size"));
    if (!branch)
      return;

    Int_t sizeStatus(utils::setAddress(_tree, name_, "size", &sizeIn_, {"size"}, _setStatus));
    if (sizeStatus != 1)
      return;

    inputs_[&_tree] = std::make_pair(branch, true);
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

  _tree.Branch(name_ + ".size", &size_, "size/i");

  getData().book(_tree, name_, _branches, true);

  outputs_[&_tree] = true;
}
