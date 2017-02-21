#include "../interface/Singlet.h"

void
panda::Singlet::setStatus(TTree& _tree, utils::BranchList const& _branches)
{
  doSetStatus_(_tree, _branches);
}

panda::utils::BranchList
panda::Singlet::getStatus(TTree& _tree) const
{
  return doGetStatus_(_tree);
}

panda::utils::BranchList
panda::Singlet::getBranchNames(Bool_t _fullName/* = kTRUE*/) const
{
  return doGetBranchNames_(_fullName);
}

void
panda::Singlet::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  doSetAddress_(_tree, _branches, _setStatus);
}

void
panda::Singlet::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  doBook_(_tree, _branches);
}
