#include "../interface/ArrayBase.h"

void
panda::ArrayBase::init()
{
  for (unsigned iP(0); iP != getData().nmax(); ++iP)
    elemAt(iP).init();
}

/*protected*/
void
panda::ArrayBase::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  getData().setStatus(_tree, name_, _branches);
}

/*protected*/
void
panda::ArrayBase::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus, Bool_t)
{
  getData().setAddress(_tree, name_, _branches, _setStatus);
}

/*protected*/
void
panda::ArrayBase::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  getData().book(_tree, name_, _branches, false);
}

/*protected*/
void
panda::ArrayBase::doReleaseTree_(TTree& _tree)
{
  getData().releaseTree(_tree, name_);
}

/*private*/
UInt_t
panda::ArrayBase::addInput_(TTree& _tree)
{
  inputs_.push_back(&_tree);
  return inputs_.size() - 1;
}
