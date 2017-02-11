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
panda::Element::getBranchNames() const
{
  return gStore.getData(this).getBranchNames(gStore.getName(this));
}

UInt_t
panda::Element::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  auto& arr(gStore.getArray(this));
  doSetAddress_(_tree, arr.getName(), _branches, _setStatus);

  return arr.addInput_(_tree);
}

void
panda::Element::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  doBook_(_tree, gStore.getName(this), _branches);
}

TTree*
panda::Element::getInput(UInt_t treeIdx/* = 0*/) const
{
  return gStore.getArray(this).getInput(treeIdx);
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
