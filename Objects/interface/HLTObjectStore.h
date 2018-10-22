#ifndef PandaTree_Objects_HLTObjectStore_h
#define PandaTree_Objects_HLTObjectStore_h

#include "HLTObject.h"

#include "TString.h"

#include <map>

namespace panda {
  
  class HLTObjectStore : public HLTObjectCollection {
  public:
    typedef std::vector<HLTObject const*> HLTObjectVector;

    HLTObjectStore(char const* name = "", UInt_t initialMax = 512) : HLTObjectCollection(name, initialMax) {}
    HLTObjectStore(HLTObjectStore const&);
    ~HLTObjectStore() {}
    HLTObjectStore& operator=(HLTObjectStore const&);

    //! Reset the filterObjects map for each run. Not to be called by users.
    void setFilterObjectKeys(std::vector<TString> const& filters);

    //! Fill the filterObjects map for each event. Not to be called by users.
    void makeMap();

    //! Use to declare a trigger filter name (key in the triggerObjects map) to be used in the analysis.
    /*!
     * By default, all trigger objects are loaded into the triggerObjects map at each call to getEntry.
     * Once a call to this function is made, only the objects for the registered filter will be loaded.
     */
    void registerFilter(char const* filter) { registeredFilters_.emplace(filter); }

    //! If set to true, return an empty vector when non-existent filter is asked for
    void setIgnoreMissing(Bool_t b) { ignoreMissing_ = b; }

    //! filterObjects_.at() with warnings. To be called by users.
    HLTObjectVector const& filterObjects(char const* filter) const;

  protected:
    Bool_t ignoreMissing_{false};
    //! List of trigger object filter names to use
    std::set<TString> registeredFilters_{};
    //! Map from filter name to the outer index of objectVectors
    std::map<TString, UInt_t> nameToSlot_{};
    //! Map from filter index to objectVectors slot
    std::vector<Int_t> indexToSlot_{};
    //! Vector of vector of pointers to the objects. Outer index for filters
    std::vector<HLTObjectVector> objectVectors_{};
    //! Empty vector as a return value to filterObjects when ignoreMissing is true
    static HLTObjectVector const emptyVector_;
  };

}

#endif
