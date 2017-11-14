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

    void makeMap(std::vector<TString> const& filters);
    HLTObjectVector const& filterObjects(char const* filter) const;

  protected:
    std::map<TString, HLTObjectVector> filterObjects_{};
  };

}

#endif
