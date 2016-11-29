#include "../Framework/interface/Object.h"
#include "../Framework/interface/Container.h"
#include "../Objects/interface/PParticle.h"
#include "../Objects/interface/PParticleM.h"
#include "../Objects/interface/PPFCand.h"
#include "../Objects/interface/PSuperCluster.h"
#include "../Objects/interface/PLepton.h"
#include "../Objects/interface/PElectron.h"
#include "../Objects/interface/PMuon.h"
#include "../Objects/interface/PTau.h"
#include "../Objects/interface/PPhoton.h"
#include "../Objects/interface/PJet.h"
#include "../Objects/interface/PFatJet.h"
#include "../Objects/interface/PGenJet.h"
#include "../Objects/interface/PGenParticle.h"
#include "../Objects/interface/PMET.h"
#include "../Objects/interface/PRecoMET.h"
#include "../Objects/interface/PMETFilters.h"
#include "../Objects/interface/HLTBits.h"
#include "../Objects/interface/Event.h"
#include "../Objects/interface/Run.h"

#ifdef __CLING__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;
#pragma link C++ namespace panda;

#pragma link C++ enum panda::PhotonL1Object;
#pragma link C++ enum panda::PhotonHLTObject;
#pragma link C++ enum panda::ElectronHLTObject;
#pragma link C++ enum panda::MuonHLTObject;
#pragma link C++ class panda::PParticle;
#pragma link C++ class panda::PParticleM;
#pragma link C++ class panda::PPFCand;
#pragma link C++ class panda::PSuperCluster;
#pragma link C++ class panda::PLepton;
#pragma link C++ class panda::PElectron;
#pragma link C++ class panda::PMuon;
#pragma link C++ class panda::PTau;
#pragma link C++ class panda::PPhoton;
#pragma link C++ class panda::PJet;
#pragma link C++ class std::array<PPFCandRefVector, 3>+;
#pragma link C++ class std::vector<std::array<PPFCandRefVector, 3>>+;
#pragma link C++ class panda::PFatJet;
#pragma link C++ class panda::PGenJet;
#pragma link C++ class panda::PGenParticle;
#pragma link C++ class panda::PMET;
#pragma link C++ class panda::PRecoMET;
#pragma link C++ class panda::PMETFilters;
#pragma link C++ class panda::HLTBits;
#pragma link C++ class Array<panda::PParticle>;
#pragma link C++ class Collection<panda::PParticle>;
#pragma link C++ class Array<panda::PParticleM>;
#pragma link C++ class Collection<panda::PParticleM>;
#pragma link C++ class Array<panda::PPFCand>;
#pragma link C++ class Collection<panda::PPFCand>;
#pragma link C++ class Array<panda::PSuperCluster>;
#pragma link C++ class Collection<panda::PSuperCluster>;
#pragma link C++ class Array<panda::PLepton>;
#pragma link C++ class Collection<panda::PLepton>;
#pragma link C++ class Array<panda::PElectron>;
#pragma link C++ class Collection<panda::PElectron>;
#pragma link C++ class Array<panda::PMuon>;
#pragma link C++ class Collection<panda::PMuon>;
#pragma link C++ class Array<panda::PTau>;
#pragma link C++ class Collection<panda::PTau>;
#pragma link C++ class Array<panda::PPhoton>;
#pragma link C++ class Collection<panda::PPhoton>;
#pragma link C++ class Array<panda::PJet>;
#pragma link C++ class Collection<panda::PJet>;
#pragma link C++ class Array<panda::PFatJet>;
#pragma link C++ class Collection<panda::PFatJet>;
#pragma link C++ class Array<panda::PGenJet>;
#pragma link C++ class Collection<panda::PGenJet>;
#pragma link C++ class Array<panda::PGenParticle>;
#pragma link C++ class Collection<panda::PGenParticle>;
#pragma link C++ typedef panda::PParticleArray;
#pragma link C++ typedef panda::PParticleCollection;
#pragma link C++ typedef panda::PParticleMArray;
#pragma link C++ typedef panda::PParticleMCollection;
#pragma link C++ typedef panda::PPFCandArray;
#pragma link C++ typedef panda::PPFCandCollection;
#pragma link C++ typedef panda::PSuperClusterArray;
#pragma link C++ typedef panda::PSuperClusterCollection;
#pragma link C++ typedef panda::PLeptonArray;
#pragma link C++ typedef panda::PLeptonCollection;
#pragma link C++ typedef panda::PElectronArray;
#pragma link C++ typedef panda::PElectronCollection;
#pragma link C++ typedef panda::PMuonArray;
#pragma link C++ typedef panda::PMuonCollection;
#pragma link C++ typedef panda::PTauArray;
#pragma link C++ typedef panda::PTauCollection;
#pragma link C++ typedef panda::PPhotonArray;
#pragma link C++ typedef panda::PPhotonCollection;
#pragma link C++ typedef panda::PJetArray;
#pragma link C++ typedef panda::PJetCollection;
#pragma link C++ typedef panda::PFatJetArray;
#pragma link C++ typedef panda::PFatJetCollection;
#pragma link C++ typedef panda::PGenJetArray;
#pragma link C++ typedef panda::PGenJetCollection;
#pragma link C++ typedef panda::PGenParticleArray;
#pragma link C++ typedef panda::PGenParticleCollection;
#pragma link C++ class panda::Event;
#pragma link C++ class panda::Run;

#endif
