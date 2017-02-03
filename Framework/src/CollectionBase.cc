#include "../interface/CollectionBase.h"
#include "../interface/IOUtils.h"

void
panda::CollectionBase::resize(UInt_t _size)
{
  if (_size > getData().nmax()) {
    UInt_t nmax(getData().nmax());
    while (nmax < _size)
      nmax *= 2;

    reallocate_(nmax);
  }

  unsigned oldSize(size_);

  size_ = _size;
  getData().resizeVectors_(_size);

  for (unsigned iE(oldSize); iE < size_; ++iE)
    elemAt(iE).init();
}

void
panda::CollectionBase::prepareGetEntry(Long64_t _iEntry, UInt_t _treeIdx)
{
  if (_treeIdx >= inputs_.size() || !inputs_[_treeIdx])
    return;

  sizeIn_[_treeIdx].first->GetEntry(_iEntry);
  resize(sizeIn_[_treeIdx].second);
}

Int_t
panda::CollectionBase::getEntry(Long64_t _iEntry, UInt_t _treeIdx)
{
  prepareGetEntry(_iEntry, _treeIdx);

  return ContainerBase::getEntry(_iEntry, _treeIdx);
}

/*protected*/
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

/*protected*/
void
panda::CollectionBase::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus, Bool_t _asInput)
{
  if (_asInput) {
    auto* branch(_tree.GetBranch(name_ + ".size"));
    if (!branch)
      return;

    sizeIn_.emplace_back(branch, 0);
    auto& sz(sizeIn_.back());

    Int_t sizeStatus(utils::setAddress(_tree, name_, "size", &sz.second, {"size"}, _setStatus));
    if (sizeStatus != 1)
      return;
  }
  else {
    Int_t sizeStatus(utils::setAddress(_tree, name_, "size", &size_, {"size"}, _setStatus));
    if (sizeStatus != 1)
      return;
  }
  
  getData().setAddress(_tree, name_, _branches, _setStatus);
}

/*protected*/
void
panda::CollectionBase::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  if (!_branches.any())
    return;

  _tree.Branch(name_ + ".size", &size_, "size/i");

  getData().book(_tree, name_, _branches, true);
}

/*protected*/
void
panda::CollectionBase::doReleaseTree_(TTree& _tree)
{
  auto* branch(_tree.GetBranch(name_ + ".size"));
  if (!branch)
    return;

  for (auto& sz : sizeIn_) {
    if (sz.first == branch) {
      branch->ResetAddress();
      sz.first = 0;
      break;
    }
  }

  getData().releaseTree(_tree, name_);
}
