#include "../interface/TreeEntry.h"
#include "../interface/CollectionBase.h"

void
panda::TreeEntry::setStatus(TTree& _tree, utils::BranchList const& _branches)
{
  for (auto* obj : objects_)
    obj->setStatus(_tree, _branches.subList(obj->getName()));

  doSetStatus_(_tree, _branches);
}

UInt_t
panda::TreeEntry::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  collInputTokens_.emplace_back(collections_.size(), -1);
  for (auto* obj : objects_) {
    UInt_t token(obj->setAddress(_tree, _branches.subList(obj->getName()), _setStatus));
    for (unsigned iC(0); iC != collections_.size(); ++iC) {
      if (collections_[iC] == obj)
        collInputTokens_.back()[iC] = token;
    }
  }

  doSetAddress_(_tree, _branches, _setStatus);
  inputs_.push_back(&_tree);

  return inputs_.size() - 1;
}

UInt_t
panda::TreeEntry::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  if (std::find(outputs_.begin(), outputs_.end(), &_tree) != outputs_.end())
    throw std::runtime_error("TreeEntry::book tree branch already booked");

  for (auto* obj : objects_)
    obj->book(_tree, _branches.subList(obj->getName()));

  doBook_(_tree, _branches);
  outputs_.push_back(&_tree);

  return outputs_.size() - 1;
}

void
panda::TreeEntry::releaseTree(TTree& _tree)
{
  for (auto*& tree : inputs_) {
    if (tree == &_tree) {
      tree = 0;
      if (currentInput_ == tree)
        currentInput_ = 0;
    }
  }

  for (auto*& tree : outputs_) {
    if (tree == &_tree)
      tree = 0;
  }

  for (auto* obj : objects_)
    obj->releaseTree(_tree);

  doReleaseTree_(_tree);
}

Int_t
panda::TreeEntry::getEntry(Long64_t _entry, UInt_t _treeIdx/* = 0*/)
{
  if (_treeIdx >= inputs_.size() || !inputs_[_treeIdx])
    return -1;

  currentInput_ = inputs_[_treeIdx];

  // call prepareGetEntry on collections
  for (unsigned iC(0); iC != collections_.size(); ++iC)
    collections_[iC]->prepareGetEntry(_entry, collInputTokens_[_treeIdx][iC]);

  return currentInput_->GetEntry(_entry);
}
