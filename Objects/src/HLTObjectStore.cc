#include "../interface/HLTObjectStore.h"

panda::HLTObjectStore::HLTObjectStore(HLTObjectStore const& _src) :
  HLTObjectCollection(_src)
{
  for (auto& fo : _src.filterObjects_) {
    HLTObjectVector myVector;
    for (auto* obj : fo.second) {
      for (unsigned iO(0); iO != _src.size(); ++iO) {
        if (&(_src[iO]) == obj)
          myVector.push_back(&at(iO));
      }
    }

    filterObjects_.emplace(fo.first, myVector);
  }
}

panda::HLTObjectStore&
panda::HLTObjectStore::operator=(HLTObjectStore const& _rhs)
{
  HLTObjectCollection::operator=(_rhs);

  filterObjects_.clear();

  for (auto& fo : _rhs.filterObjects_) {
    HLTObjectVector myVector;
    for (auto* obj : fo.second) {
      for (unsigned iO(0); iO != _rhs.size(); ++iO) {
        if (&(_rhs[iO]) == obj)
          myVector.push_back(&at(iO));
      }
    }

    filterObjects_.emplace(fo.first, myVector);
  }

  return *this;
}

void
panda::HLTObjectStore::makeMap(std::vector<TString> const& _filters)
{
  std::vector<HLTObjectVector> objects(_filters.size());

  for (auto& obj : *this) {
    for (UShort_t fidx : *obj.filters) {
      if (fidx < _filters.size())
        objects[fidx].push_back(&obj);
      else
        throw std::runtime_error("List of filters passed to HLTObjectStore::makeMap too short");
    }
  }

  filterObjects_.clear();

  for (unsigned fidx(0); fidx != _filters.size(); ++fidx)
    filterObjects_.emplace(_filters[fidx], objects[fidx]);
}
