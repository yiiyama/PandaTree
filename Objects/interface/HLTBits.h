#ifndef PandaTree_Objects_HLTBits_h
#define PandaTree_Objects_HLTBits_h
#include "Constants.h"
#include "../../Interface/interface/Object.h"
#include "../../Interface/interface/Container.h"

namespace panda {

  class HLTBits : public Singlet {
  public:
    HLTBits();
    HLTBits(HLTBits const&);
    HLTBits(TString const& name);
    ~HLTBits();
    HLTBits& operator=(HLTBits const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;

    void init() override;

    void set(unsigned iB) { words[iB / 32] |= (1 << (iB % 32)); }
    bool pass(unsigned iB) const { return ((words[iB / 32] >> (iB % 32)) & 1) != 0; }

    UInt_t words[16]{};

    /* BEGIN CUSTOM */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
