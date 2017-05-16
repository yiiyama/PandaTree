#ifndef PandaTree_Objects_EventMonophoton_h
#define PandaTree_Objects_EventMonophoton_h
#include "EventBase.h"
#include "Constants.h"
#include "GenReweight.h"
#include "SuperCluster.h"
#include "Electron.h"
#include "Muon.h"
#include "Tau.h"
#include "XPhoton.h"
#include "Jet.h"
#include "GenJet.h"
#include "GenParticle.h"
#include "Parton.h"
#include "RecoMet.h"
#include "Met.h"
#include "MetFilters.h"
#include "Event.h"

namespace panda {

  class EventMonophoton : public EventBase {
  public:
    EventMonophoton();
    EventMonophoton(EventMonophoton const&);
    ~EventMonophoton();
    EventMonophoton& operator=(EventMonophoton const&);

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    GenReweight genReweight = GenReweight("genReweight");
    SuperClusterCollection superClusters = SuperClusterCollection("superClusters", 64);
    ElectronCollection electrons = ElectronCollection("electrons", 32);
    MuonCollection muons = MuonCollection("muons", 32);
    TauCollection taus = TauCollection("taus", 64);
    XPhotonCollection photons = XPhotonCollection("photons", 32);
    JetCollection jets = JetCollection("jets", 64);
    GenJetCollection genJets = GenJetCollection("genJets", 64);
    GenParticleCollection genParticles = GenParticleCollection("genParticles", 256);
    PartonCollection partons = PartonCollection("partons", 8);
    RecoMet t1Met = RecoMet("t1Met");
    Met rawMet = Met("rawMet");
    Met caloMet = Met("caloMet");
    RecoMet metMuOnlyFix = RecoMet("metMuOnlyFix");
    RecoMet metNoFix = RecoMet("metNoFix");
    MetFilters metFilters = MetFilters("metFilters");

    UShort_t npv{};
    UShort_t npvTrue{};
    Float_t rho{};
    Float_t rhoCentralCalo{};

    static utils::BranchList getListOfBranches();

  protected:
    void doSetStatus_(TTree&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&) const override;
    utils::BranchList doGetBranchNames_() const override;
    void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus) override;
    void doBook_(TTree&, utils::BranchList const&) override;
    void doGetEntry_(TTree&, Long64_t) override;
    void doInit_() override;

  public:
    /* BEGIN CUSTOM EventMonophoton.h.classdef */
    EventMonophoton& operator=(Event const&);
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM EventMonophoton.h.global */
  /* END CUSTOM */

}

#endif
