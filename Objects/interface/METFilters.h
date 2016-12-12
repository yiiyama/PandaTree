#ifndef PandaTree_Objects_METFilters_h
#define PandaTree_Objects_METFilters_h
#include "Constants.h"
#include "../../Framework/interface/Singlet.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class METFilters : public Singlet {
  public:
    METFilters(char const* name = "");
    METFilters(METFilters const&);
    ~METFilters();
    METFilters& operator=(METFilters const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {}) override;
    void setAddress(TTree&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {}) override;
    void resetAddress(TTree&) override;

    void init() override;

    virtual bool pass() const { return !globalHalo16 && !hbhe && !hbheIso && !ecalDeadCell && !badsc && !badTrack && !badMuonTrack; }

    Bool_t cschalo{};
    Bool_t globalHalo16{};
    Bool_t hbhe{};
    Bool_t hbheIso{};
    Bool_t ecalDeadCell{};
    Bool_t badsc{};
    Bool_t badTrack{};
    Bool_t badMuonTrack{};

    /* BEGIN CUSTOM METFilters.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM METFilters.h.global */
  /* END CUSTOM */

}

#endif
