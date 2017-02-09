#ifndef PandaTree_Objects_MetFilters_h
#define PandaTree_Objects_MetFilters_h
#include "Constants.h"
#include "../../Framework/interface/Singlet.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class MetFilters : public Singlet {
  public:
    typedef Singlet base_type;

    MetFilters(char const* name = "");
    MetFilters(MetFilters const&);
    ~MetFilters();
    MetFilters& operator=(MetFilters const&);

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

  protected:
    void doSetStatus_(TTree&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&) const override;
    void doSetAddress_(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&) override;
    void doInit_() override;
  };

  /* BEGIN CUSTOM MetFilters.h.global */
  /* END CUSTOM */

}

#endif
