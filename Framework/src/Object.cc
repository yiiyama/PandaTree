#include "../interface/Object.h"

#include <cstring>

namespace panda {
  panda::utils::StoreManager gStore;
}

panda::ContainerElement::ContainerElement(utils::AllocatorBase const& _allocator, char const* _name)
{
  gStore.assign(this, _allocator, _name);
}

void
panda::ContainerElement::setName(char const* _name)
{
  gStore.setName(this, _name);
}

void
panda::utils::StoreManager::assign(ContainerElement const* _element, AllocatorBase const& _allocator, char const* _name/* = ""*/)
{
  if (slots_.find(_element) != slots_.end()) // this element has space allocated already
    return;

  Assignments& assignments(dataStore_[_allocator.typeIndex()]);

  unsigned iSlot(0);
  for (; iSlot != assignments.first.size(); ++iSlot) {
    // find the first open slot
    if (!assignments.first[iSlot])
      break;
  }

  if (iSlot == assignments.first.size()) {
    assignments.second.push_back(_allocator.allocate());
    assignments.first.resize(assignments.first.size() + _allocator.nmax(), 0);
  }

  assignments.first[iSlot] = _element;
  slots_.emplace(_element, Slot(&assignments.second, iSlot));

  if (std::strlen(_name) != 0)
    names_.emplace(_element, _name);
}

void
panda::utils::StoreManager::free(ContainerElement const* _element)
{
  auto&& sitr(slots_.find(_element));
  if (sitr == slots_.end())
    return;

  Slot& slot(sitr->second);

  for (auto& store : dataStore_) {
    auto& assignments(store.second);
    if (&assignments.second != slot.first)
      continue;

    for (auto*& elem : assignments.first) {
      if (elem == _element) {
        elem = 0;
        break;
      }
    }
    break;
  }
          
  slots_.erase(sitr);
}

char const*
panda::utils::StoreManager::getName(ContainerElement const* _element)
{
  auto&& nitr(names_.find(_element));
  if (nitr == names_.end())
    return "";
  else
    return nitr->second.Data();
}
