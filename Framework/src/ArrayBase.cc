#include "../interface/ArrayBase.h"

void
panda::ArrayBase::init()
{
  for (unsigned iP(0); iP != getData().nmax(); ++iP)
    elemAt(iP).init();
}

/*private*/
void
panda::ArrayBase::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  getData().setStatus(_tree, name_, _branches);
}

/*private*/
panda::utils::BranchList
panda::ArrayBase::doGetStatus_(TTree& _tree) const
{
  return getData().getStatus(_tree, name_);
}

/*private*/
void
panda::ArrayBase::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus, Bool_t)
{
  getData().setAddress(_tree, name_, _branches, _setStatus);
}

/*private*/
void
panda::ArrayBase::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  getData().book(_tree, name_, _branches, false);
}
