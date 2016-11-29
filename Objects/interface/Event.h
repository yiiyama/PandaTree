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

    PPFCandCollection pfCandidates = PPFCandCollection("pfCandidates", 256);
    PSuperClusterCollection superClusters = PSuperClusterCollection("superClusters", 64);
    PElectronCollection electrons = PElectronCollection("electrons", 32);
    PMuonCollection muons = PMuonCollection("muons", 32);
    PTauCollection taus = PTauCollection("taus", 64);
    PPhotonCollection photons = PPhotonCollection("photons", 32);
    PJetCollection jets = PJetCollection("jets", 64);
    PFatJetCollection fatJets = PFatJetCollection("fatJets", 8);
    PGenJetCollection genJets = PGenJetCollection("genJets", 64);
    PGenParticleCollection genParticles = PGenParticleCollection("genParticles", 128);
    PMET met = PMET("met");
    PMETFilters metFilters = PMETFilters("metFilters");
    HLTBits triggers = HLTBits("triggers");

    UInt_t runNumber{};
    UInt_t lumiNumber{};
    UInt_t eventNumber{};
    Bool_t isData{};
    Int_t npv{};
    Float_t mcWeight{};

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
