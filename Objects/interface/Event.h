#ifndef PandaTree_Objects_Event_h
#define PandaTree_Objects_Event_h
#include "../../Framework/interface/TreeEntry.h"
#include "Constants.h"
#include "PPFCand.h"
#include "PSuperCluster.h"
#include "PElectron.h"
#include "PMuon.h"
#include "PTau.h"
#include "PPhoton.h"
#include "PJet.h"
#include "PFatJet.h"
#include "PGenJet.h"
#include "PGenParticle.h"
#include "PRecoMET.h"
#include "PMET.h"
#include "PMETFilters.h"
#include "HLTBits.h"

namespace panda {

  class Event : public TreeEntry {
  public:
    Event();
    Event(Event const&);
    ~Event() {}
    Event& operator=(Event const&);

    void init() override;

    double reweight(UInt_t i) const { return 1. + reweightDW[i]; }

    PPFCandCollection pfCandidates = PPFCandCollection("pfCandidates", 256);
    PSuperClusterCollection superClusters = PSuperClusterCollection("superClusters", 64);
    PElectronCollection electrons = PElectronCollection("electrons", 32);
    PMuonCollection muons = PMuonCollection("muons", 32);
    PTauCollection taus = PTauCollection("taus", 64);
    PPhotonCollection photons = PPhotonCollection("photons", 32);
    PJetCollection chsAK4Jets = PJetCollection("chsAK4Jets", 64);
    PJetCollection puppiAK4Jets = PJetCollection("puppiAK4Jets", 64);
    PFatJetCollection chsAK8Jets = PFatJetCollection("chsAK8Jets", 8);
    PFatJetCollection chsCA15Jets = PFatJetCollection("chsCA15Jets", 8);
    PFatJetCollection puppiAK8Jets = PFatJetCollection("puppiAK8Jets", 8);
    PFatJetCollection puppiCA15Jets = PFatJetCollection("puppiCA15Jets", 8);
    PJetCollection subjets = PJetCollection("subjets", 64);
    PGenJetCollection genJets = PGenJetCollection("genJets", 64);
    PGenParticleCollection genParticles = PGenParticleCollection("genParticles", 128);
    PRecoMET met = PRecoMET("met");
    PMET rawMet = PMET("rawMet");
    PMET caloMet = PMET("caloMet");
    PMET noMuMet = PMET("noMuMet");
    PMET noHFMet = PMET("noHFMet");
    PMET trkMet = PMET("trkMet");
    PMET neutralMet = PMET("neutralMet");
    PMET photonMet = PMET("photonMet");
    PMET hfMet = PMET("hfMet");
    PMET genMet = PMET("genMet");
    PMETFilters metFilters = PMETFilters("metFilters");
    HLTBits triggers = HLTBits("triggers");

    UInt_t runNumber{};
    UInt_t lumiNumber{};
    UInt_t eventNumber{};
    Bool_t isData{};
    UShort_t npv{};
    UShort_t npvTrue{};
    Float_t rho{};
    Float_t rhoCentralCalo{};
    Float_t weight{};
    Float_t reweightDW[512]{};

  protected:
    void doSetStatus_(TTree&, Bool_t, utils::BranchList const&) override;
    void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus) override;
    void doBook_(TTree&, utils::BranchList const&) override;
    void doReleaseTree_(TTree&) override;
    void adjustCollectionSizes_() override;

  public:
    /* BEGIN CUSTOM */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
