#ifndef PandaTree_Objects_Constants_h
#define PandaTree_Objects_Constants_h

#include "TTree.h"
#include "TString.h"
#include "Rtypes.h"
#include "Math/GenVector/LorentzVector.h"
#include "Math/GenVector/PtEtaPhiM4D.h"
#include "TLorentzVector.h"
#include "TVector2.h"
#include <cmath>
#include <cstring>

namespace panda {

  typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<double>> LorentzVectorM;

  enum PhotonL1Object {
    fSEG34IorSEG40,
    fSEG40IorSJet200,
    fSEG34IorSEG40IorSJet200,
    fSEG24,
    fSEG30,
    fSEG40,
    nPhotonL1Objects
  };

  extern TString PhotonL1ObjectName[nPhotonL1Objects];
  TTree* makePhotonL1ObjectTree();

  enum PhotonHLTObject {
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
    nPhotonHLTObjects
  };

  extern TString PhotonHLTObjectName[nPhotonHLTObjects];
  TTree* makePhotonHLTObjectTree();

  enum ElectronHLTObject {
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
    nElectronHLTObjects
  };

  extern TString ElectronHLTObjectName[nElectronHLTObjects];
  TTree* makeElectronHLTObjectTree();

  enum MuonHLTObject {
    fMu20,
    fMuTrk20,
    fMu24,
    fMu27,
    nMuonHLTObjects
  };

  extern TString MuonHLTObjectName[nMuonHLTObjects];
  TTree* makeMuonHLTObjectTree();

  unsigned const nMaxHLTObjects(nElectronHLTObjects);

  enum Assertions {
    AST0 = sizeof(char[(nMaxHLTObjects >= nPhotonHLTObjects) ? 1 : -1]),
    AST1 = sizeof(char[(nMaxHLTObjects >= nElectronHLTObjects) ? 1 : -1]),
    AST2 = sizeof(char[(nMaxHLTObjects >= nMuonHLTObjects) ? 1 : -1]),
    nAssertionss
  };
  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
