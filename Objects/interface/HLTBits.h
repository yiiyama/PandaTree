#ifndef PandaTree_Objects_HLTBits_h
#define PandaTree_Objects_HLTBits_h
#include "Constants.h"
#include "../../Framework/interface/Singlet.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class HLTBits : public Singlet {
  public:
    typedef Singlet base_type;

    HLTBits(char const* name = "");
    HLTBits(HLTBits const&);
    ~HLTBits();
    HLTBits& operator=(HLTBits const&);


    void set(unsigned iB) { words[iB / 32] |= (1 << (iB % 32)); }
    bool pass(unsigned iB) const { return ((words[iB / 32] >> (iB % 32)) & 1) != 0; }
    unsigned size() const { return size_; }

    UInt_t words[16]{};
    UInt_t size_{512};

    /* BEGIN CUSTOM HLTBits.h.classdef */
    /* END CUSTOM */

  protected:
    void doSetStatus_(TTree&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&) const override;
    void doSetAddress_(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&) override;
    void doInit_() override;
    };

  /* BEGIN CUSTOM HLTBits.h.global */
  /* END CUSTOM */

  }

  #endif
