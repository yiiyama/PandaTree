#ifndef PandaTree_Objects_PMETFilters_h
#define PandaTree_Objects_PMETFilters_h
#include "Constants.h"
#include "../../Framework/interface/Singlet.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class PMETFilters : public Singlet {
  public:
    PMETFilters(char const* name = "");
    PMETFilters(PMETFilters const&);
    ~PMETFilters();
    PMETFilters& operator=(PMETFilters const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;
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

    /* BEGIN CUSTOM PMETFilters.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM PMETFilters.h.global */
  /* END CUSTOM */

}

#endif
