#include "../interface/ContainerBase.h"

#include "TTree.h"

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
panda::ContainerBase::getBranchNames(Bool_t _fullName/* = kTRUE*/) const
{
  if (_fullName)
    return getData().getBranchNames(name_);
  else
    return getData().getBranchNames("");
}

void
panda::ContainerBase::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  doSetAddress_(_tree, _branches, _setStatus, true);
}

void
panda::ContainerBase::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  doBook_(_tree, _branches);
}

void
panda::ContainerBase::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  if (name_.Length() != 0)
    _out << "{" << name_ << "}" << std::endl;

  for (unsigned iE(0); iE != size(); ++iE) {
    _out << "[" << iE << "]";
    if (_level > 1)
      _out << std::endl;
    else
      _out << " ";
    elemAt(iE).print(_out, _level);
  }
}

void
panda::ContainerBase::dump(std::ostream& _out/* = std::cout*/) const
{
  _out << "name_ = " << name_ << std::endl;
  _out << "unitSize_ = " << unitSize_ << std::endl;
  _out << "array_ (" << (void*)(array_) << "): " << std::endl;
  for (unsigned iE(0); iE != size(); ++iE) {
    _out << "[" << iE << "]" << std::endl;
    elemAt(iE).dump(_out);
  }
  _out << std::endl;
}
