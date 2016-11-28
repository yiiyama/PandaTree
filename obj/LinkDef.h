#include "../Framework/interface/Object.h"
#include "../Framework/interface/Container.h"
#include "../Objects/interface/PParticle.h"

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
#pragma link C++ class Container<panda::PParticle, panda::Collection>;
#pragma link C++ typedef panda::PParticleCollection;

#endif
