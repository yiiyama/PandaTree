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

    static char const* typeName() { return "MetFilters"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    virtual bool pass() const { return !globalHalo16 && !hbhe && !hbheIso && !ecalDeadCell && !badsc && !goodVertices && !badPFMuons && !badChargedHadrons && !ecalBadCalib; }

    Bool_t globalHalo16{};
    Bool_t hbhe{};
    Bool_t hbheIso{};
    Bool_t ecalDeadCell{};
    Bool_t goodVertices{};
    Bool_t badsc{};
    Bool_t badMuons{};
    Bool_t duplicateMuons{};
    Bool_t badPFMuons{};
    Bool_t badChargedHadrons{};
    Bool_t ecalBadCalib{};

    /* BEGIN CUSTOM MetFilters.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

  protected:
    void doSetStatus_(TTree&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&) const override;
    utils::BranchList doGetBranchNames_(Bool_t) const override;
    void doSetAddress_(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  /* BEGIN CUSTOM MetFilters.h.global */
  /* END CUSTOM */

}

#endif
