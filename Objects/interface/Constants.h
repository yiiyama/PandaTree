#ifndef PandaTree_Objects_Constants_h
#define PandaTree_Objects_Constants_h

#include "TTree.h"
#include "TString.h"
#include "Rtypes.h"
#include "TLorentzVector.h"
#include "TVector2.h"
#include <cmath>
#include <cstring>

namespace panda {

  enum PhotonTriggerObject {
    fSEG34IorSEG40,
    fSEG40IorSJet200,
    fSEG34IorSEG40IorSJet200,
    fSEG24,
    fSEG30,
    fSEG40,
    fPh120,
    fPh135,
    fPh165HE10,
    fPh175,
    fPh22EBR9Iso,
    fPh36EBR9Iso,
    fPh50EBR9Iso,
    fPh75EBR9Iso,
    fPh90EBR9Iso,
    fPh120EBR9Iso,
    nPhotonTriggerObjects
  };

  extern TString PhotonTriggerObjectName[nPhotonTriggerObjects];
  TTree* makePhotonTriggerObjectTree();

  enum ElectronTriggerObject {
    fEl23Loose,
    fEl27Loose,
    fEl120Ph,
    fEl135Ph,
    fEl165HE10Ph,
    fEl175Ph,
    fEl22EBR9IsoPh,
    fEl36EBR9IsoPh,
    fEl50EBR9IsoPh,
    fEl75EBR9IsoPh,
    fEl90EBR9IsoPh,
    fEl120EBR9IsoPh,
    nElectronTriggerObjects
  };

  extern TString ElectronTriggerObjectName[nElectronTriggerObjects];
  TTree* makeElectronTriggerObjectTree();

  enum MuonTriggerObject {
    fMu20,
    fMuTrk20,
    fMu24,
    fMu27,
    nMuonTriggerObjects
  };

  extern TString MuonTriggerObjectName[nMuonTriggerObjects];
  TTree* makeMuonTriggerObjectTree();

  enum RecoilCategory {
    rMET,
    rMonoMu,
    rMonoE,
    rDiMu,
    rDiE,
    rGamma,
    nRecoilCategories
  };

  extern TString RecoilCategoryName[nRecoilCategories];
  TTree* makeRecoilCategoryTree();

  enum Assertions {
    nAssertionses
  };
  /* BEGIN CUSTOM Constants.h.global */
  /* END CUSTOM */

}

#endif
