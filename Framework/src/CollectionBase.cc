#include "../interface/CollectionBase.h"
#include "../interface/IOUtils.h"

/*private*/
void
panda::CollectionBase::doSetStatus_(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  if (!_tree.GetBranch(name_ + ".size"))
    return;

  if (_status || utils::BranchName("size").in(_branches))
    _tree.SetBranchStatus(name_ + ".size", _status);

  getData().setStatus(_tree, name_, _status, _branches);
}

/*private*/
void
panda::CollectionBase::doSetAddress_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Int_t sizeStatus(utils::setAddress(_tree, name_, "size", &size_, {"size"}, _setStatus));
  if (sizeStatus == -1 || (!_setStatus && sizeStatus == 0))
    return;
  
  getData().setAddress(_tree, name_, _branches, _setStatus);
}

/*private*/
void
panda::CollectionBase::doBook_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  if (!utils::BranchName(name_).in(_branches))
    return;

  _tree.Branch(name_ + ".size", &size_, "size/i");

  getData().book(_tree, name_, _branches, true);
}
