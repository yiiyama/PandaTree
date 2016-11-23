#ifndef PandaTree_Objects_PMETFilters_h
#define PandaTree_Objects_PMETFilters_h
#include "Constants.h"
#include "../../Framework/interface/Object.h"
#include "../../Framework/interface/Container.h"

namespace panda {

  class PMETFilters : public Singlet {
  public:
    PMETFilters(char const* name = "");
    PMETFilters(PMETFilters const&);
    ~PMETFilters();
    PMETFilters& operator=(PMETFilters const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;

    void init() override;

    virtual bool pass() const { return !globalHalo16 && !hbhe && !hbheIso && !badsc && !badTrack && !badMuonTrack; }

    Bool_t cschalo{};
    Bool_t globalHalo16{};
    Bool_t hbhe{};
    Bool_t hbheIso{};
    Bool_t badsc{};
    Bool_t badTrack{};
    Bool_t badMuonTrack{};

    /* BEGIN CUSTOM */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
