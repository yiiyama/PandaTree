#include "../interface/ContainerBase.h"

#include <algorithm>
#include <stdexcept>

void
panda::ContainerBase::setStatus(TTree& _tree, utils::BranchList const& _branches)
{
  doSetStatus_(_tree, _branches);
}

panda::utils::BranchList
panda::ContainerBase::getStatus(TTree& _tree) const
{
  return doGetStatus_(_tree);
}

panda::utils::BranchList
panda::ContainerBase::getBranchNames() const
{
  return getData().getBranchNames(name_);
}

UInt_t
panda::ContainerBase::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  doSetAddress_(_tree, _branches, _setStatus, true);
  inputs_.push_back(&_tree);

  return inputs_.size() - 1;
}

void
panda::ContainerBase::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  doBook_(_tree, _branches);
}

void
panda::ContainerBase::releaseTree(TTree& _tree)
{
  for (auto*& t : inputs_) {
    if (t == &_tree)
      t = 0;
  }

  doReleaseTree_(_tree);
}
