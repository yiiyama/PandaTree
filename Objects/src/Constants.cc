#include "../interface/Constants.h"

TString panda::PhotonL1ObjectName[] = {
  "fSEG34IorSEG40",
  "fSEG40IorSJet200",
  "fSEG34IorSEG40IorSJet200",
  "fSEG24",
  "fSEG30",
  "fSEG40"
};

TTree*
panda::makePhotonL1ObjectTree()
{
  auto* tree(new TTree("PhotonL1Object", "PhotonL1Object"));
  TString* name(new TString);
  tree->Branch("name", "TString", &name);
  for (auto&& n : PhotonL1ObjectName) {
    *name = n;
    tree->Fill();
  }
  tree->ResetBranchAddresses();
  delete name;
  return tree;
}

TString panda::PhotonHLTObjectName[] = {
  "fPh120",
  "fPh135",
  "fPh165HE10",
  "fPh175",
  "fPh22EBR9Iso",
  "fPh36EBR9Iso",
  "fPh50EBR9Iso",
  "fPh75EBR9Iso",
  "fPh90EBR9Iso",
  "fPh120EBR9Iso"
};

TTree*
panda::makePhotonHLTObjectTree()
{
  auto* tree(new TTree("PhotonHLTObject", "PhotonHLTObject"));
  TString* name(new TString);
  tree->Branch("name", "TString", &name);
  for (auto&& n : PhotonHLTObjectName) {
    *name = n;
    tree->Fill();
  }
  tree->ResetBranchAddresses();
  delete name;
  return tree;
}

TString panda::ElectronHLTObjectName[] = {
  "fEl23Loose",
  "fEl27Loose",
  "fEl120Ph",
  "fEl135Ph",
  "fEl165HE10Ph",
  "fEl175Ph",
  "fEl22EBR9IsoPh",
  "fEl36EBR9IsoPh",
  "fEl50EBR9IsoPh",
  "fEl75EBR9IsoPh",
  "fEl90EBR9IsoPh",
  "fEl120EBR9IsoPh"
};

TTree*
panda::makeElectronHLTObjectTree()
{
  auto* tree(new TTree("ElectronHLTObject", "ElectronHLTObject"));
  TString* name(new TString);
  tree->Branch("name", "TString", &name);
  for (auto&& n : ElectronHLTObjectName) {
    *name = n;
    tree->Fill();
  }
  tree->ResetBranchAddresses();
  delete name;
  return tree;
}

TString panda::MuonHLTObjectName[] = {
  "fMu20",
  "fMuTrk20",
  "fMu24",
  "fMu27"
};

TTree*
panda::makeMuonHLTObjectTree()
{
  auto* tree(new TTree("MuonHLTObject", "MuonHLTObject"));
  TString* name(new TString);
  tree->Branch("name", "TString", &name);
  for (auto&& n : MuonHLTObjectName) {
    *name = n;
    tree->Fill();
  }
  tree->ResetBranchAddresses();
  delete name;
  return tree;
}

/* BEGIN CUSTOM */
/* END CUSTOM */
