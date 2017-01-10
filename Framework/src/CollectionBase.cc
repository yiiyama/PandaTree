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
  
  size_ = _size;
  getData().resizeVectors_(_size);
}

/*protected*/
void
panda::CollectionBase::doSetStatus_(TTree& _tree, Bool_t _status, utils::BranchList const& _branches)
{
  if (!_tree.GetBranch(name_ + ".size"))
    return;

  // If status is true -> turn size true
  // If explicitly instructed to turn off size -> turn size false
  if (_status || utils::BranchName("size").in(_branches))
    _tree.SetBranchStatus(name_ + ".size", _status);

  getData().setStatus(_tree, name_, _status, _branches);
}

/*protected*/
void
panda::CollectionBase::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  Int_t sizeStatus(utils::setAddress(_tree, name_, "size", &sizeIn_, {"size"}, _setStatus));
  if (sizeStatus == -1 || (!_setStatus && sizeStatus == 0))
    return;

  sizeInBranch_ = _tree.GetBranch(name_ + ".size");
  
  getData().setAddress(_tree, name_, _branches, _setStatus);
}

/*protected*/
void
panda::CollectionBase::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  if (!utils::BranchName("size").vetoed(_branches) || _branches.any())
    _tree.Branch(name_ + ".size", &size_, "size/i");

  getData().book(_tree, name_, _branches, true);
}

/*protected*/
void
panda::CollectionBase::doResetAddress_(TTree& _tree)
{
  if (sizeInBranch_)
    sizeInBranch_->ResetAddress();
  sizeInBranch_ = 0;

  getData().resetAddress(_tree, name_);
}

/*protected*/
void
panda::CollectionBase::doPrepareGetEntry_(Long64_t _iEntry)
{
  if (sizeInBranch_)
    sizeInBranch_->GetEntry(_iEntry);

  resize(sizeIn_);
}
