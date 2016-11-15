#include "../Interface/interface/Object.h"
#include "../Interface/interface/Container.h"
#include "../Objects/interface/PObject.h"
#include "../Objects/interface/PPFCand.h"
#include "../Objects/interface/PLeptonBase.h"
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

#pragma link C++ class panda::PObject;
#pragma link C++ class panda::PPFCand;
#pragma link C++ class panda::PLeptonBase;
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
#pragma link C++ class panda::PMETFilters;
#pragma link C++ class panda::HLTBits;
#pragma link C++ class Container<panda::PObject, panda::Collection>;
#pragma link C++ typedef panda::PObjectCollection;
#pragma link C++ class Container<panda::PPFCand, panda::PObjectCollection>;
#pragma link C++ typedef panda::PPFCandCollection;
#pragma link C++ class Container<panda::PLeptonBase, panda::PObjectCollection>;
#pragma link C++ typedef panda::PLeptonBaseCollection;
#pragma link C++ class Container<panda::PLepton, panda::PLeptonBaseCollection>;
#pragma link C++ typedef panda::PLeptonCollection;
#pragma link C++ class Container<panda::PElectron, panda::PLeptonCollection>;
#pragma link C++ typedef panda::PElectronCollection;
#pragma link C++ class Container<panda::PMuon, panda::PLeptonCollection>;
#pragma link C++ typedef panda::PMuonCollection;
#pragma link C++ class Container<panda::PTau, panda::PLeptonBaseCollection>;
#pragma link C++ typedef panda::PTauCollection;
#pragma link C++ class Container<panda::PPhoton, panda::PObjectCollection>;
#pragma link C++ typedef panda::PPhotonCollection;
#pragma link C++ class Container<panda::PJet, panda::PObjectCollection>;
#pragma link C++ typedef panda::PJetCollection;
#pragma link C++ class Container<panda::PFatJet, panda::PJetCollection>;
#pragma link C++ typedef panda::PFatJetCollection;
#pragma link C++ class Container<panda::PGenJet, panda::PObjectCollection>;
#pragma link C++ typedef panda::PGenJetCollection;
#pragma link C++ class Container<panda::PGenParticle, panda::PObjectCollection>;
#pragma link C++ typedef panda::PGenParticleCollection;
#pragma link C++ class panda::Event;
#pragma link C++ class panda::Run;

#endif
