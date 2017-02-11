#include "../interface/TreeEntry.h"
#include "../interface/CollectionBase.h"

void
panda::TreeEntry::setStatus(TTree& _tree, utils::BranchList const& _branches)
{
  for (auto* obj : objects_)
    obj->setStatus(_tree, _branches.subList(obj->getName()));

  doSetStatus_(_tree, _branches);
}

panda::utils::BranchList
panda::TreeEntry::getStatus(TTree& _tree) const
{
  utils::BranchList blist;

  for (auto* obj : objects_)
    blist += obj->getStatus(_tree);

  blist += doGetStatus_(_tree);

  return blist;
}

panda::utils::BranchList
panda::TreeEntry::getBranchNames() const
{
  utils::BranchList blist;

  for (auto* obj : objects_)
    blist += obj->getBranchNames();

  blist += doGetBranchNames_();

  return blist;
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

void
panda::TreeEntry::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  for (auto* obj : objects_)
    obj->book(_tree, _branches.subList(obj->getName()));

  doBook_(_tree, _branches);
}

void
panda::TreeEntry::releaseTree(TTree& _tree)
{
  if (inputs_[currentInputIdx_] == &_tree)
    currentInputIdx_ = -1;

  for (auto*& tree : inputs_) {
    if (tree == &_tree)
      tree = 0;
  }

  for (auto* obj : objects_)
    obj->releaseTree(_tree);

  doReleaseTree_(_tree);
}

void
panda::TreeEntry::init()
{
  for (auto* obj : objects_)
    obj->init();

  doInit_();
}

Int_t
panda::TreeEntry::getEntry(Long64_t _entry, UInt_t _treeIdx/* = 0*/)
{
  if (_treeIdx >= inputs_.size() || !inputs_[_treeIdx])
    return -1;

  currentInputIdx_ = _treeIdx;

  // call prepareGetEntry on collections
  for (unsigned iC(0); iC != collections_.size(); ++iC)
    collections_[iC]->prepareGetEntry(_entry, collInputTokens_[_treeIdx][iC]);

  return inputs_[_treeIdx]->GetEntry(_entry);
}
