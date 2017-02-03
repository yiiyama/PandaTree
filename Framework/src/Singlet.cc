#include "../interface/Singlet.h"

void
panda::Singlet::setStatus(TTree& _tree, utils::BranchList const& _branches)
{
  doSetStatus_(_tree, _branches);
}

UInt_t
panda::Singlet::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  doSetAddress_(_tree, _branches, _setStatus);

  return -1;
}

void
panda::Singlet::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  doBook_(_tree, _branches);
}

void
panda::Singlet::releaseTree(TTree& _tree)
{
  doReleaseTree_(_tree);
}
