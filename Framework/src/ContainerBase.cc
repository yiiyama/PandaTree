#include "../interface/ContainerBase.h"

#include <algorithm>
#include <stdexcept>

void
panda::ContainerBase::releaseTree(TTree& _tree)
{
  bool found(false);

  if (&_tree == input_) {
    input_ = 0;
    found = true;
  }

  if (!found) {
    for (auto itr(outputs_.begin()); itr != outputs_.end(); ++itr) {
      if (*itr == &_tree) {
        outputs_.erase(itr);
        found = true;
        break;
      }
    }
  }

  if (!found)
    return;

  doResetAddress_(_tree);
}

void
panda::ContainerBase::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  doSetStatus_(_tree, _status, _branches);
}

void
panda::ContainerBase::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  doSetAddress_(_tree, _branches, _setStatus);
  input_ = &_tree;
}

void
panda::ContainerBase::book(TTree& _tree, utils::BranchList const& _branches/* = {}*/)
{
  if (std::find(outputs_.begin(), outputs_.end(), &_tree) != outputs_.end())
    throw std::runtime_error("ContainerBase::book tree branch already booked");

  doBook_(_tree, _branches);
  outputs_.push_back(&_tree);
}

/*protected*/
void
panda::ContainerBase::updateAddress_()
{
  if (input_)
    doSetAddress_(*input_, {"*"}, false);
  for (auto* tree : outputs_)
    doSetAddress_(*tree, {"*"}, false);
}
