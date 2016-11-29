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
#pragma link C++ class panda::PFatJet;
#pragma link C++ class panda::PGenJet;
#pragma link C++ class panda::PGenParticle;
#pragma link C++ class panda::PMET;
#pragma link C++ class panda::PRecoMET;
#pragma link C++ class panda::PMETFilters;
#pragma link C++ class panda::HLTBits;
#pragma link C++ class Container<panda::PParticle, panda::Collection>;
#pragma link C++ typedef panda::PParticleCollection;
#pragma link C++ class Container<panda::PParticleM, panda::PParticleCollection>;
#pragma link C++ typedef panda::PParticleMCollection;
#pragma link C++ class Container<panda::PPFCand, panda::PParticleMCollection>;
#pragma link C++ typedef panda::PPFCandCollection;
#pragma link C++ class Container<panda::PSuperCluster, panda::Collection>;
#pragma link C++ typedef panda::PSuperClusterCollection;
#pragma link C++ class Container<panda::PLepton, panda::PParticleCollection>;
#pragma link C++ typedef panda::PLeptonCollection;
#pragma link C++ class Container<panda::PElectron, panda::PLeptonCollection>;
#pragma link C++ typedef panda::PElectronCollection;
#pragma link C++ class Container<panda::PMuon, panda::PLeptonCollection>;
#pragma link C++ typedef panda::PMuonCollection;
#pragma link C++ class Container<panda::PTau, panda::PParticleMCollection>;
#pragma link C++ typedef panda::PTauCollection;
#pragma link C++ class Container<panda::PPhoton, panda::PParticleCollection>;
#pragma link C++ typedef panda::PPhotonCollection;
#pragma link C++ class Container<panda::PJet, panda::PParticleMCollection>;
#pragma link C++ typedef panda::PJetCollection;
#pragma link C++ class Container<panda::PFatJet, panda::PJetCollection>;
#pragma link C++ typedef panda::PFatJetCollection;
#pragma link C++ class Container<panda::PGenJet, panda::PParticleMCollection>;
#pragma link C++ typedef panda::PGenJetCollection;
#pragma link C++ class Container<panda::PGenParticle, panda::PParticleMCollection>;
#pragma link C++ typedef panda::PGenParticleCollection;
#pragma link C++ class panda::Event;
#pragma link C++ class panda::Run;

#endif
