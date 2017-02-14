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
#include "Run.h"

namespace panda {

  class Event : public TreeEntry {
  public:
    Event();
    Event(Event const&);
    ~Event() {}
    Event& operator=(Event const&);

    GenReweight genReweight = GenReweight("genReweight");
    PFCandCollection pfCandidates = PFCandCollection("pfCandidates", 2048);
    SuperClusterCollection superClusters = SuperClusterCollection("superClusters", 64);
    ElectronCollection electrons = ElectronCollection("electrons", 32);
    MuonCollection muons = MuonCollection("muons", 32);
    TauCollection taus = TauCollection("taus", 64);
    PhotonCollection photons = PhotonCollection("photons", 32);
    JetCollection chsAK4Jets = JetCollection("chsAK4Jets", 64);
    JetCollection puppiAK4Jets = JetCollection("puppiAK4Jets", 64);
    FatJetCollection chsAK8Jets = FatJetCollection("chsAK8Jets", 8);
    MicroJetCollection chsAK8Subjets = MicroJetCollection("chsAK8Subjets", 64);
    FatJetCollection chsCA15Jets = FatJetCollection("chsCA15Jets", 8);
    MicroJetCollection chsCA15Subjets = MicroJetCollection("chsCA15Subjets", 64);
    FatJetCollection puppiAK8Jets = FatJetCollection("puppiAK8Jets", 8);
    MicroJetCollection puppiAK8Subjets = MicroJetCollection("puppiAK8Subjets", 64);
    FatJetCollection puppiCA15Jets = FatJetCollection("puppiCA15Jets", 8);
    MicroJetCollection puppiCA15Subjets = MicroJetCollection("puppiCA15Subjets", 64);
    GenJetCollection genJets = GenJetCollection("genJets", 64);
    GenParticleCollection genParticles = GenParticleCollection("genParticles", 256);
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
    RecoMet metMuOnlyFix = RecoMet("metMuOnlyFix");
    RecoMet metNoFix = RecoMet("metNoFix");
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
    /* BEGIN CUSTOM Event.h.classdef */

    //! Current run object.
    Run run;

    //! Use to declare a trigger path to be used in the analysis. Returns a token for the path.
    /*!
     * Call this function before the event loop for each trigger you will be using. The return value
     * is an integer unique to the path, and can be passed to triggerFired() in the event loop to retrieve
     * the trigger decision of the event.
     *
     * \param path   HLT path
     */
    UInt_t registerTrigger(char const* path) { return run.registerTrigger(path); }

    //! Trigger decision of the event.
    /*!
     * Pass the trigger token returned by registerTrigger().
     *
     * \param token   Token returned by registerTrigger()
     */
    Bool_t triggerFired(UInt_t token) const;

    /* END CUSTOM */
  };

  /* BEGIN CUSTOM Event.h.global */
  /* END CUSTOM */

}

#endif
