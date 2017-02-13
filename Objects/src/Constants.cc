#include "../interface/Constants.h"

TString panda::PhotonTriggerObjectName[] = {
  "fSEG34IorSEG40",
  "fSEG40IorSJet200",
  "fSEG34IorSEG40IorSJet200",
  "fSEG24",
  "fSEG30",
  "fSEG40",
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
panda::makePhotonTriggerObjectTree()
{
  auto* tree(new TTree("PhotonTriggerObject", "PhotonTriggerObject"));
  TString* name(new TString);
  tree->Branch("name", "TString", &name);
  for (auto&& n : PhotonTriggerObjectName) {
    *name = n;
    tree->Fill();
  }
  tree->ResetBranchAddresses();
  delete name;
  return tree;
}

TString panda::ElectronTriggerObjectName[] = {
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
panda::makeElectronTriggerObjectTree()
{
  auto* tree(new TTree("ElectronTriggerObject", "ElectronTriggerObject"));
  TString* name(new TString);
  tree->Branch("name", "TString", &name);
  for (auto&& n : ElectronTriggerObjectName) {
    *name = n;
    tree->Fill();
  }
  tree->ResetBranchAddresses();
  delete name;
  return tree;
}

TString panda::MuonTriggerObjectName[] = {
  "fMu20",
  "fMuTrk20",
  "fMu24",
  "fMu27"
};

TTree*
panda::makeMuonTriggerObjectTree()
{
  auto* tree(new TTree("MuonTriggerObject", "MuonTriggerObject"));
  TString* name(new TString);
  tree->Branch("name", "TString", &name);
  for (auto&& n : MuonTriggerObjectName) {
    *name = n;
    tree->Fill();
  }
  tree->ResetBranchAddresses();
  delete name;
  return tree;
}

TString panda::RecoilCategoryName[] = {
  "rMET",
  "rMonoMu",
  "rMonoE",
  "rDiMu",
  "rDiE",
  "rGamma"
};

TTree*
panda::makeRecoilCategoryTree()
{
  auto* tree(new TTree("RecoilCategory", "RecoilCategory"));
  TString* name(new TString);
  tree->Branch("name", "TString", &name);
  for (auto&& n : RecoilCategoryName) {
    *name = n;
    tree->Fill();
  }
  tree->ResetBranchAddresses();
  delete name;
  return tree;
}

/* BEGIN CUSTOM Constants.cc.global */
/* END CUSTOM */
