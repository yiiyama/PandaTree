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
    void makeMap(std::vector<bool> const& mask);

    //! filterObjects_.at() with warnings. To be called by users.
    HLTObjectVector const& filterObjects(char const* filter) const;

  protected:
    std::map<TString, HLTObjectVector> filterObjects_{};
    //! internal-use pointers to the values of filterObjects_
    std::vector<HLTObjectVector*> objectVectors_{};
  };

}

#endif
