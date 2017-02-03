#ifndef PandaTree_Objects_MetFilters_h
#define PandaTree_Objects_MetFilters_h
#include "Constants.h"
#include "../../Framework/interface/Singlet.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class MetFilters : public Singlet {
  public:
    MetFilters(char const* name = "");
    MetFilters(MetFilters const&);
    ~MetFilters();
    MetFilters& operator=(MetFilters const&);

    void setStatus(TTree&, utils::BranchList const& = {"*"}) override;
    UInt_t setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    UInt_t book(TTree&, utils::BranchList const& = {"*"}) override;
    void releaseTree(TTree&) override;

    void init() override;

    virtual bool pass() const { return !globalHalo16 && !hbhe && !hbheIso && !ecalDeadCell && !badsc && !badTrack && !badMuonTrack; }

    Bool_t globalHalo16{};
    Bool_t hbhe{};
    Bool_t hbheIso{};
    Bool_t ecalDeadCell{};
    Bool_t badsc{};
    Bool_t badTrack{};
    Bool_t badMuonTrack{};

    /* BEGIN CUSTOM MetFilters.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM MetFilters.h.global */
  /* END CUSTOM */

}

#endif
