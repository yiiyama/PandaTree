#ifndef PandaTree_Objects_Event_h
#define PandaTree_Objects_Event_h
#include "../../Framework/interface/TreeEntry.h"
#include "Constants.h"
#include "GenReweight.h"
#include "PFCand.h"
#include "SuperCluster.h"
#include "Electron.h"
#include "Muon.h"
#include "Tau.h"
#include "Photon.h"
#include "Jet.h"
#include "FatJet.h"
#include "MicroJet.h"
#include "GenJet.h"
#include "GenParticle.h"
#include "Parton.h"
#include "RecoMet.h"
#include "Met.h"
#include "MetFilters.h"
#include "HLTBits.h"
#include "Recoil.h"

namespace panda {

  class Event : public TreeEntry {
  public:
    Event();
    Event(Event const&);
    ~Event() {}
    Event& operator=(Event const&);

    void init() override;

    GenReweight genReweight = GenReweight("genReweight");
    PFCandCollection pfCandidates = PFCandCollection("pfCandidates", 256);
    SuperClusterCollection superClusters = SuperClusterCollection("superClusters", 64);
    ElectronCollection electrons = ElectronCollection("electrons", 32);
    MuonCollection muons = MuonCollection("muons", 32);
    TauCollection taus = TauCollection("taus", 64);
    PhotonCollection photons = PhotonCollection("photons", 32);
    JetCollection chsAK4Jets = JetCollection("chsAK4Jets", 64);
    JetCollection puppiAK4Jets = JetCollection("puppiAK4Jets", 64);
    FatJetCollection chsAK8Jets = FatJetCollection("chsAK8Jets", 8);
    FatJetCollection chsCA15Jets = FatJetCollection("chsCA15Jets", 8);
    FatJetCollection puppiAK8Jets = FatJetCollection("puppiAK8Jets", 8);
    FatJetCollection puppiCA15Jets = FatJetCollection("puppiCA15Jets", 8);
    MicroJetCollection subjets = MicroJetCollection("subjets", 64);
    GenJetCollection genJets = GenJetCollection("genJets", 64);
    GenParticleCollection genParticles = GenParticleCollection("genParticles", 128);
    PartonCollection partons = PartonCollection("partons", 8);
    RecoMet met = RecoMet("met");
    RecoMet puppiMet = RecoMet("puppiMet");
    Met rawMet = Met("rawMet");
    Met caloMet = Met("caloMet");
    Met noMuMet = Met("noMuMet");
    Met noHFMet = Met("noHFMet");
    Met trkMet = Met("trkMet");
    Met neutralMet = Met("neutralMet");
    Met photonMet = Met("photonMet");
    Met hfMet = Met("hfMet");
    Met genMet = Met("genMet");
    MetFilters metFilters = MetFilters("metFilters");
    HLTBits triggers = HLTBits("triggers");
    Recoil recoil = Recoil("recoil");

    UInt_t runNumber{};
    UInt_t lumiNumber{};
    UInt_t eventNumber{};
    Bool_t isData{};
    UShort_t npv{};
    UShort_t npvTrue{};
    Float_t rho{};
    Float_t rhoCentralCalo{};
    Float_t weight{};

  protected:
    void doSetStatus_(TTree&, Bool_t, utils::BranchList const&) override;
    void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus) override;
    void doBook_(TTree&, utils::BranchList const&) override;
    void doReleaseTree_(TTree&) override;
    void adjustCollectionSizes_() override;

  public:
    /* BEGIN CUSTOM Event.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM Event.h.global */
  /* END CUSTOM */

}

#endif
