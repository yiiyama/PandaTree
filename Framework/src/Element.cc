#include "../interface/Element.h"
#include "../interface/ArrayBase.h"

namespace panda {
  panda::utils::StoreManager gStore;
}

/*protected*/
panda::Element::Element(ArrayBase* _array)
{
  gStore.add(this, _array);
}

char const*
panda::Element::getName() const
{
  return gStore.getName(this);
}

void
panda::Element::setName(char const* _name)
{
  gStore.getArray(this).setName(_name);
}

void
panda::Element::setStatus(TTree& _tree, utils::BranchList const& _branches)
{
  gStore.getData(this).setStatus(_tree, gStore.getName(this), _branches);
}

panda::utils::BranchList
panda::Element::getStatus(TTree& _tree) const
{
  return gStore.getData(this).getStatus(_tree, gStore.getName(this));
}

panda::utils::BranchList
panda::Element::getBranchNames(Bool_t _fullName/* = kTRUE*/, Bool_t/* = kFALSE*/) const
{
  if (_fullName)
    return gStore.getData(this).getBranchNames(gStore.getName(this));
  else
    return gStore.getData(this).getBranchNames();
}

UInt_t
panda::Element::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  return gStore.getArray(this).setAddress(_tree, _branches, _setStatus);
}

void
panda::Element::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  doBook_(_tree, gStore.getName(this), _branches);
}

Int_t
panda::Element::getEntry(TTree& _tree, Long64_t _entry, Int_t _localEntry/* = -1*/)
{
  return gStore.getArray(this).getEntry(_tree, _entry, _localEntry);
}

Int_t
panda::Element::getEntry(UInt_t _treeId, Long64_t _entry, Int_t _localEntry/* = -1*/)
{
  return gStore.getArray(this).getEntry(_treeId, _entry, _localEntry);
}

char const*
panda::utils::StoreManager::getName(Element const* _obj) const
{
  return store_.at(_obj)->getName();
}

void
panda::utils::StoreManager::free(Element const* _obj)
{
  // Since virtual destructors are called recursively, destruction of one derived object
  // will result in multiple calls of free(). Not very efficient, but the alternative
  // is to add some "freed" flag to the objects.
  auto itr(store_.find(_obj));
  if (itr == store_.end())
    return;

  delete itr->second;
  store_.erase(itr);
}
