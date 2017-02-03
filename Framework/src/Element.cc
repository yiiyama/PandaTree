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
panda::Element::setStatus(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  doSetStatus_(_tree, gStore.getName(this), _branches);
}

UInt_t
panda::Element::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  doSetAddress_(_tree, gStore.getName(this), _branches, _setStatus);

  return -1;
}

void
panda::Element::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  doBook_(_tree, gStore.getName(this), _branches);
}

void
panda::Element::releaseTree(TTree& _tree)
{
  doReleaseTree_(_tree, gStore.getName(this));
}

char const*
panda::utils::StoreManager::getName(Element const* _obj) const
{
  return store_.at(_obj)->getName();
}

void
panda::utils::StoreManager::free(Element const* _obj)
{
  delete store_.at(_obj);
  store_.erase(_obj);
}
