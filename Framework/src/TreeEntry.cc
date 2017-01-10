#include "../interface/TreeEntry.h"

void
panda::TreeEntry::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  doSetStatus_(_tree, _status, _branches);
}

void
panda::TreeEntry::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  doSetAddress_(_tree, _branches, _setStatus);
  input_ = &_tree;
}

void
panda::TreeEntry::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  if (std::find(outputs_.begin(), outputs_.end(), &_tree) != outputs_.end())
    throw std::runtime_error("TreeEntry::book tree branch already booked");

  doBook_(_tree, _branches);
  outputs_.push_back(&_tree);
}

void
panda::TreeEntry::releaseTree(TTree& _tree)
{
  if (&_tree == input_) {
    input_ = 0;
    return;
  }

  for (auto itr(outputs_.begin()); itr != outputs_.end(); ++itr) {
    if (*itr == &_tree) {
      outputs_.erase(itr);
      break;
    }
  }

  doReleaseTree_(_tree);
}

Int_t
panda::TreeEntry::getEntry(Long64_t _entry)
{
  if (!input_)
    return -1;

  // call prepareGetEntry on collections
  doPrepareGetEntry_(_entry);

  return input_->GetEntry(_entry);
}
