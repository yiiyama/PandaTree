#ifndef PandaTree_Objects_EventMonophoton_h
#define PandaTree_Objects_EventMonophoton_h
#include "EventBase.h"
#include "Constants.h"
#include "GenReweight.h"
#include "SuperCluster.h"
#include "Electron.h"
#include "Muon.h"
#include "Tau.h"
#include "Photon.h"
#include "Jet.h"
#include "GenJet.h"
#include "GenParticle.h"
#include "Parton.h"
#include "RecoMet.h"
#include "Met.h"
#include "MetFilters.h"

namespace panda {

  class EventMonophoton : public EventBase {
  public:
    EventMonophoton();
    EventMonophoton(EventMonophoton const&);
    ~EventMonophoton() {}
    EventMonophoton& operator=(EventMonophoton const&);

    GenReweight genReweight = GenReweight("genReweight");
    SuperClusterCollection superClusters = SuperClusterCollection("superClusters", 64);
    ElectronCollection electrons = ElectronCollection("electrons", 32);
    MuonCollection muons = MuonCollection("muons", 32);
    TauCollection taus = TauCollection("taus", 64);
    PhotonCollection photons = PhotonCollection("photons", 32);
    JetCollection chsAK4Jets = JetCollection("chsAK4Jets", 64);
    GenJetCollection ak4GenJets = GenJetCollection("ak4GenJets", 64);
    GenParticleCollection genParticles = GenParticleCollection("genParticles", 256);
    PartonCollection partons = PartonCollection("partons", 8);
    RecoMet pfMet = RecoMet("pfMet");
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
    void doGetEntry_(Long64_t) override;
    void doReleaseTree_(TTree&) override;
    void doInit_() override;

  public:
    /* BEGIN CUSTOM EventMonophoton.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM EventMonophoton.h.global */
  /* END CUSTOM */

}

#endif
