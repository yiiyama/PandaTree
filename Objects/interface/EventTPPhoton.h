#ifndef PandaTree_Objects_EventTPPhoton_h
#define PandaTree_Objects_EventTPPhoton_h
#include "EventBase.h"
#include "Constants.h"
#include "TPPair.h"
#include "Lepton.h"
#include "XPhoton.h"
#include "Jet.h"
#include "RecoMet.h"
#include "Event.h"
#include "EventMonophoton.h"

namespace panda {

  class EventTPPhoton : public EventBase {
  public:
    EventTPPhoton();
    EventTPPhoton(EventTPPhoton const&);
    ~EventTPPhoton();
    EventTPPhoton& operator=(EventTPPhoton const&);

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    TPPairCollection tp = TPPairCollection("tp", 32);
    LeptonCollection tags = LeptonCollection("tags", 32);
    LeptonCollection looseTags = LeptonCollection("looseTags", 32);
    XPhotonCollection probes = XPhotonCollection("probes", 32);
    JetCollection jets = JetCollection("jets", 64);
    RecoMet t1Met = RecoMet("t1Met");

    UShort_t npv{};
    UShort_t npvTrue{};
    Float_t rho{};
    UInt_t sample{};

    static utils::BranchList getListOfBranches(Bool_t direct = kFALSE);

  protected:
    void doSetStatus_(TTree&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&) const override;
    utils::BranchList doGetBranchNames_() const override;
    void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus) override;
    void doBook_(TTree&, utils::BranchList const&) override;
    void doGetEntry_(TTree&) override;
    void doInit_() override;
    void doUnlink_(TTree&) override;

  public:
    /* BEGIN CUSTOM EventTPPhoton.h.classdef */
    EventTPPhoton& copy(Event const&);
    EventTPPhoton& copy(EventMonophoton const&);
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM EventTPPhoton.h.global */
  /* END CUSTOM */

}

#endif
