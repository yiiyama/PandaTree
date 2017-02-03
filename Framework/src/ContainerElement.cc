#include "../interface/ContainerElement.h"
#include "../interface/ArrayBase.h"

namespace panda {
  panda::utils::StoreManager gStore;
}

/*protected*/
panda::ContainerElement::ContainerElement(ArrayBase* _array)
{
  gStore.add(this, _array);
}

char const*
panda::ContainerElement::getName() const
{
  return gStore.getName(this);
}

void
panda::ContainerElement::setName(char const* _name)
{
  gStore.getArray(this).setName(_name);
}

char const*
panda::utils::StoreManager::getName(ContainerElement const* _obj) const
{
  return store_.at(_obj)->getName();
}

void
panda::utils::StoreManager::free(ContainerElement const* _obj)
{
  delete store_.at(_obj);
  store_.erase(_obj);
}
