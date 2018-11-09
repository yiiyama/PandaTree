#include "../interface/HLTObjectStore.h"

/*static*/
panda::HLTObjectStore::HLTObjectVector const panda::HLTObjectStore::emptyVector_{};

panda::HLTObjectStore::HLTObjectStore(HLTObjectStore const& _src) :
  HLTObjectCollection(_src)
{
  nameToSlot_ = _src.nameToSlot_;
  objectVectors_.resize(_src.objectVectors_.size());

  for (UInt_t fidx(0); fidx != _src.objectVectors_.size(); ++fidx) {
    objectVectors_[fidx].clear();
    for (auto* obj : _src.objectVectors_[fidx])
      objectVectors_[fidx].push_back(&at(obj - &_src.at(0)));
  }
}

panda::HLTObjectStore&
panda::HLTObjectStore::operator=(HLTObjectStore const& _rhs)
{
  HLTObjectCollection::operator=(_rhs);

  registeredFilters_ = _rhs.registeredFilters_;
  nameToSlot_ = _rhs.nameToSlot_;
  objectVectors_.resize(_rhs.objectVectors_.size());

  for (UInt_t fidx(0); fidx != _rhs.objectVectors_.size(); ++fidx) {
    objectVectors_[fidx].clear();
    for (auto* obj : _rhs.objectVectors_[fidx])
      objectVectors_[fidx].push_back(&at(obj - &_rhs.at(0)));
  }

  return *this;
}

void
panda::HLTObjectStore::setFilterObjectKeys(std::vector<TString> const& _filters)
{
  nameToSlot_.clear();

  if (registeredFilters_.empty()) {
    // all filters are used
    objectVectors_.resize(_filters.size());
    indexToSlot_.resize(_filters.size());

    for (UShort_t fidx(0); fidx != _filters.size(); ++fidx) {
      nameToSlot_[_filters[fidx]] = fidx;
      indexToSlot_[fidx] = fidx;
    }
  }
  else {
    indexToSlot_.assign(_filters.size(), -1);

    // only allow registered filters
    int slot(0);
    for (UShort_t fidx(0); fidx != _filters.size(); ++fidx) {
      auto& filter(_filters[fidx]);
      if (registeredFilters_.count(filter) != 0) {
        indexToSlot_[fidx] = slot;
        nameToSlot_[filter] = slot++;
      }
    }

    objectVectors_.resize(slot);

    if (slot == 0) {
      std::cerr << "Warning: No trigger objects with registered filter names were found";
      std::cerr << " in the list of " << _filters.size() << " filters." << std::endl;
    }
  }
}

void
panda::HLTObjectStore::makeMap()
{
  for (auto& objv : objectVectors_)
    objv.clear();

  for (auto& obj : *this) {
    for (UShort_t fidx : *obj.filters) {
      if (fidx >= indexToSlot_.size())
        throw std::runtime_error(TString::Format("Invalid trigger filter index %d found in trigger objects. There is very likely a bug in HLTObjectStore or EventBase.", fidx).Data());

      int slot(indexToSlot_[fidx]);
      if (slot >= 0)
        objectVectors_[slot].push_back(&obj);
    }
  }
}

panda::HLTObjectStore::HLTObjectVector const&
panda::HLTObjectStore::filterObjects(char const* _filter) const
{
  if (nameToSlot_.empty()) {
    std::cerr << "  HLTObjectStore has no filter objects. Store is filled by a call to makeMap(),"
              << "   which is executed in EventBase::doGetEntry_ if the following conditions are met:\n"
              << "   1.  runNumber branch is read in Event\n"
              << "   2a. event.run.setLoadTrigger(true) is called, or\n"
              << "   2b. event.registerTrigger(path_name) [equivalently event.run.registerTrigger(path_name)] is called.\n"
              << "  Please update your analysis code accordingly." << std::endl;

    throw std::out_of_range("HLT filters not loaded");
  }

  try {
    return objectVectors_[nameToSlot_.at(_filter)];
  }
  catch (std::out_of_range& ex) {
    if (ignoreMissing_)
      return emptyVector_;

    std::cerr << "Unknown HLT filter " << _filter << std::endl;
    throw;
  }
}
