#ifndef PandaTree_Objects_HLTBits_h
#define PandaTree_Objects_HLTBits_h
#include "Constants.h"
#include "../../Framework/interface/Singlet.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class HLTBits : public Singlet {
  public:
    HLTBits(char const* name = "");
    HLTBits(HLTBits const&);
    ~HLTBits();
    HLTBits& operator=(HLTBits const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;
    void resetAddress(TTree&) override;

    void init() override;

    void set(unsigned iB) { words[iB / 32] |= (1 << (iB % 32)); }
    bool pass(unsigned iB) const { return ((words[iB / 32] >> (iB % 32)) & 1) != 0; }
    unsigned size() const { return size_; }

    UInt_t words[16]{};
    UInt_t size_{512};

    /* BEGIN CUSTOM HLTBits.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM HLTBits.h.global */
  /* END CUSTOM */

}

#endif
