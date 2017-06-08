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
panda::TreeEntry::getBranchNames(Bool_t/* = kTRUE*/) const
{
  utils::BranchList blist;

  for (auto* obj : objects_)
    blist += obj->getBranchNames(true);

  blist += doGetBranchNames_();

  return blist;
}

void
panda::TreeEntry::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  for (auto* obj : objects_)
    obj->setAddress(_tree, _branches.subList(obj->getName()), _setStatus);

  doSetAddress_(_tree, _branches, _setStatus);
}

void
panda::TreeEntry::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  for (auto* obj : objects_)
    obj->book(_tree, _branches.subList(obj->getName()));

  doBook_(_tree, _branches);
}

void
panda::TreeEntry::init()
{
  for (auto* obj : objects_)
    obj->init();

  doInit_();
}

Int_t
panda::TreeEntry::getEntry(TTree& _tree, Long64_t _entry)
{
  init();

  Long64_t localEntry(_tree.LoadTree(_entry));
  if (localEntry < 0)
    return 0;

  for (unsigned iC(0); iC != collections_.size(); ++iC)
    collections_[iC]->prepareGetEntry(_tree, _entry, localEntry);

  Int_t bytes(_tree.GetEntry(_entry));

  if (bytes > 0)
    doGetEntry_(_tree, _entry);

  return bytes;
}

Int_t
panda::TreeEntry::fill(TTree& _tree)
{
  for (unsigned iC(0); iC != collections_.size(); ++iC)
    collections_[iC]->prepareFill(_tree);

  return _tree.Fill();
}
