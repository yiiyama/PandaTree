#ifndef PandaTree_Objects_Event_h
#define PandaTree_Objects_Event_h
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
#include "../../Framework/interface/TreeEntry.h"

namespace panda {

  class Event : public TreeEntry {
  public:
    Event();
    Event(Event const&);
    ~Event() {}
    Event& operator=(Event const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;

    void init() override;

    PPFCandCollection pfCandidates = PPFCandCollection("pfCandidates");
    PSuperClusterCollection superClusters = PSuperClusterCollection("superClusters");
    PElectronCollection electrons = PElectronCollection("electrons");
    PMuonCollection muons = PMuonCollection("muons");
    PTauCollection taus = PTauCollection("taus");
    PPhotonCollection photons = PPhotonCollection("photons");
    PJetCollection jets = PJetCollection("jets");
    PFatJetCollection fatJets = PFatJetCollection("fatJets");
    PGenJetCollection genJets = PGenJetCollection("genJets");
    PGenParticleCollection genParticles = PGenParticleCollection("genParticles");
    PMET met = PMET("met");
    PMETFilters metFilters = PMETFilters("metFilters");
    HLTBits triggers = HLTBits("triggers");

    UInt_t runNumber{};
    UInt_t lumiNumber{};
    UInt_t eventNumber{};
    Bool_t isData{};
    Int_t npv{};
    Float_t mcWeight{};

    /* BEGIN CUSTOM */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
