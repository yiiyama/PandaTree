#include "../interface/ContainerBase.h"

#include <algorithm>
#include <stdexcept>

void
panda::ContainerBase::setStatus(TTree& _tree, utils::BranchList const& _branches)
{
  doSetStatus_(_tree, _branches);
}

UInt_t
panda::ContainerBase::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  doSetAddress_(_tree, _branches, _setStatus);
  inputs_.push_back(&_tree);

  return inputs_.size() - 1;
}

UInt_t
panda::ContainerBase::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  if (std::find(outputs_.begin(), outputs_.end(), &_tree) != outputs_.end())
    throw std::runtime_error("ContainerBase::book tree branch already booked");

  doBook_(_tree, _branches);
  outputs_.push_back(&_tree);

  return outputs_.size() - 1;
}

void
panda::ContainerBase::releaseTree(TTree& _tree)
{
  for (auto*& t : inputs_) {
    if (t == &_tree)
      t = 0;
  }

  for (auto*& t : outputs_) {
    if (t == &_tree)
      t = 0;
  }

  doResetAddress_(_tree);
}

Int_t
panda::ContainerBase::getEntry(Long64_t _iEntry, UInt_t _treeIdx/* = 0*/)
{
  return inputs_[_treeIdx]->GetEntry(_iEntry);
}

/*protected*/
void
panda::ContainerBase::updateAddress_()
{
  for (auto* tree : inputs_) {
    if (tree)
      doSetAddress_(*tree, {"*"}, false);
  }
  for (auto* tree : outputs_) {
    if (tree)
      doSetAddress_(*tree, {"*"}, false, false);
  }
}
