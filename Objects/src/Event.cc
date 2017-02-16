#include "../interface/Event.h"

panda::Event::Event() :
  EventBase()
{
  std::vector<Object*> myObjects{{&genReweight, &pfCandidates, &superClusters, &electrons, &muons, &taus, &photons, &chsAK4Jets, &puppiAK4Jets, &chsAK8Jets, &chsAK8Subjets, &chsCA15Jets, &chsCA15Subjets, &puppiAK8Jets, &puppiAK8Subjets, &puppiCA15Jets, &puppiCA15Subjets, &ak4GenJets, &ak8GenJets, &ca15GenJets, &genParticles, &partons, &pfMet, &puppiMet, &rawMet, &caloMet, &noMuMet, &noHFMet, &trkMet, &neutralMet, &photonMet, &hfMet, &genMet, &metMuOnlyFix, &metNoFix, &metFilters, &recoil}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&pfCandidates, &superClusters, &electrons, &muons, &taus, &photons, &chsAK4Jets, &puppiAK4Jets, &chsAK8Jets, &chsAK8Subjets, &chsCA15Jets, &chsCA15Subjets, &puppiAK8Jets, &puppiAK8Subjets, &puppiCA15Jets, &puppiCA15Subjets, &ak4GenJets, &ak8GenJets, &ca15GenJets, &genParticles, &partons}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());

  electrons.data.superClusterContainer_ = &superClusters;
  electrons.data.matchedGenContainer_ = &genParticles;
  muons.data.matchedGenContainer_ = &genParticles;
  taus.data.matchedGenContainer_ = &genParticles;
  photons.data.superClusterContainer_ = &superClusters;
  photons.data.matchedGenContainer_ = &genParticles;
  genParticles.data.parentContainer_ = &genParticles;
  chsAK4Jets.data.constituentsContainer_ = &pfCandidates;
  chsAK4Jets.data.matchedGenJetContainer_ = &ak4GenJets;
  puppiAK4Jets.data.constituentsContainer_ = &pfCandidates;
  puppiAK4Jets.data.matchedGenJetContainer_ = &ak4GenJets;
  chsAK8Jets.data.constituentsContainer_ = &pfCandidates;
  chsAK8Jets.data.subjetsContainer_ = &chsAK8Subjets;
  chsAK8Jets.data.matchedGenJetContainer_ = &ak8GenJets;
  chsCA15Jets.data.constituentsContainer_ = &pfCandidates;
  chsCA15Jets.data.subjetsContainer_ = &chsCA15Subjets;
  chsCA15Jets.data.matchedGenJetContainer_ = &ca15GenJets;
  puppiAK8Jets.data.constituentsContainer_ = &pfCandidates;
  puppiAK8Jets.data.subjetsContainer_ = &puppiAK8Subjets;
  puppiAK8Jets.data.matchedGenJetContainer_ = &ak8GenJets;
  puppiCA15Jets.data.constituentsContainer_ = &pfCandidates;
  puppiCA15Jets.data.subjetsContainer_ = &puppiCA15Subjets;
  puppiCA15Jets.data.matchedGenJetContainer_ = &ca15GenJets;
}

panda::Event::Event(Event const& _src) :
  EventBase(),
  genReweight(_src.genReweight),
  pfCandidates(_src.pfCandidates),
  superClusters(_src.superClusters),
  electrons(_src.electrons),
  muons(_src.muons),
  taus(_src.taus),
  photons(_src.photons),
  chsAK4Jets(_src.chsAK4Jets),
  puppiAK4Jets(_src.puppiAK4Jets),
  chsAK8Jets(_src.chsAK8Jets),
  chsAK8Subjets(_src.chsAK8Subjets),
  chsCA15Jets(_src.chsCA15Jets),
  chsCA15Subjets(_src.chsCA15Subjets),
  puppiAK8Jets(_src.puppiAK8Jets),
  puppiAK8Subjets(_src.puppiAK8Subjets),
  puppiCA15Jets(_src.puppiCA15Jets),
  puppiCA15Subjets(_src.puppiCA15Subjets),
  ak4GenJets(_src.ak4GenJets),
  ak8GenJets(_src.ak8GenJets),
  ca15GenJets(_src.ca15GenJets),
  genParticles(_src.genParticles),
  partons(_src.partons),
  pfMet(_src.pfMet),
  puppiMet(_src.puppiMet),
  rawMet(_src.rawMet),
  caloMet(_src.caloMet),
  noMuMet(_src.noMuMet),
  noHFMet(_src.noHFMet),
  trkMet(_src.trkMet),
  neutralMet(_src.neutralMet),
  photonMet(_src.photonMet),
  hfMet(_src.hfMet),
  genMet(_src.genMet),
  metMuOnlyFix(_src.metMuOnlyFix),
  metNoFix(_src.metNoFix),
  metFilters(_src.metFilters),
  recoil(_src.recoil),
  npv(_src.npv),
  npvTrue(_src.npvTrue),
  rho(_src.rho),
  rhoCentralCalo(_src.rhoCentralCalo)
{
  std::vector<Object*> myObjects{{&genReweight, &pfCandidates, &superClusters, &electrons, &muons, &taus, &photons, &chsAK4Jets, &puppiAK4Jets, &chsAK8Jets, &chsAK8Subjets, &chsCA15Jets, &chsCA15Subjets, &puppiAK8Jets, &puppiAK8Subjets, &puppiCA15Jets, &puppiCA15Subjets, &ak4GenJets, &ak8GenJets, &ca15GenJets, &genParticles, &partons, &pfMet, &puppiMet, &rawMet, &caloMet, &noMuMet, &noHFMet, &trkMet, &neutralMet, &photonMet, &hfMet, &genMet, &metMuOnlyFix, &metNoFix, &metFilters, &recoil}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&pfCandidates, &superClusters, &electrons, &muons, &taus, &photons, &chsAK4Jets, &puppiAK4Jets, &chsAK8Jets, &chsAK8Subjets, &chsCA15Jets, &chsCA15Subjets, &puppiAK8Jets, &puppiAK8Subjets, &puppiCA15Jets, &puppiCA15Subjets, &ak4GenJets, &ak8GenJets, &ca15GenJets, &genParticles, &partons}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());


  electrons.data.superClusterContainer_ = &superClusters;
  electrons.data.matchedGenContainer_ = &genParticles;
  muons.data.matchedGenContainer_ = &genParticles;
  taus.data.matchedGenContainer_ = &genParticles;
  photons.data.superClusterContainer_ = &superClusters;
  photons.data.matchedGenContainer_ = &genParticles;
  genParticles.data.parentContainer_ = &genParticles;
  chsAK4Jets.data.constituentsContainer_ = &pfCandidates;
  chsAK4Jets.data.matchedGenJetContainer_ = &ak4GenJets;
  puppiAK4Jets.data.constituentsContainer_ = &pfCandidates;
  puppiAK4Jets.data.matchedGenJetContainer_ = &ak4GenJets;
  chsAK8Jets.data.constituentsContainer_ = &pfCandidates;
  chsAK8Jets.data.subjetsContainer_ = &chsAK8Subjets;
  chsAK8Jets.data.matchedGenJetContainer_ = &ak8GenJets;
  chsCA15Jets.data.constituentsContainer_ = &pfCandidates;
  chsCA15Jets.data.subjetsContainer_ = &chsCA15Subjets;
  chsCA15Jets.data.matchedGenJetContainer_ = &ca15GenJets;
  puppiAK8Jets.data.constituentsContainer_ = &pfCandidates;
  puppiAK8Jets.data.subjetsContainer_ = &puppiAK8Subjets;
  puppiAK8Jets.data.matchedGenJetContainer_ = &ak8GenJets;
  puppiCA15Jets.data.constituentsContainer_ = &pfCandidates;
  puppiCA15Jets.data.subjetsContainer_ = &puppiCA15Subjets;
  puppiCA15Jets.data.matchedGenJetContainer_ = &ca15GenJets;
}

panda::Event&
panda::Event::operator=(Event const& _src)
{
  npv = _src.npv;
  npvTrue = _src.npvTrue;
  rho = _src.rho;
  rhoCentralCalo = _src.rhoCentralCalo;

  genReweight = _src.genReweight;
  pfCandidates = _src.pfCandidates;
  superClusters = _src.superClusters;
  electrons = _src.electrons;
  muons = _src.muons;
  taus = _src.taus;
  photons = _src.photons;
  chsAK4Jets = _src.chsAK4Jets;
  puppiAK4Jets = _src.puppiAK4Jets;
  chsAK8Jets = _src.chsAK8Jets;
  chsAK8Subjets = _src.chsAK8Subjets;
  chsCA15Jets = _src.chsCA15Jets;
  chsCA15Subjets = _src.chsCA15Subjets;
  puppiAK8Jets = _src.puppiAK8Jets;
  puppiAK8Subjets = _src.puppiAK8Subjets;
  puppiCA15Jets = _src.puppiCA15Jets;
  puppiCA15Subjets = _src.puppiCA15Subjets;
  ak4GenJets = _src.ak4GenJets;
  ak8GenJets = _src.ak8GenJets;
  ca15GenJets = _src.ca15GenJets;
  genParticles = _src.genParticles;
  partons = _src.partons;
  pfMet = _src.pfMet;
  puppiMet = _src.puppiMet;
  rawMet = _src.rawMet;
  caloMet = _src.caloMet;
  noMuMet = _src.noMuMet;
  noHFMet = _src.noHFMet;
  trkMet = _src.trkMet;
  neutralMet = _src.neutralMet;
  photonMet = _src.photonMet;
  hfMet = _src.hfMet;
  genMet = _src.genMet;
  metMuOnlyFix = _src.metMuOnlyFix;
  metNoFix = _src.metNoFix;
  metFilters = _src.metFilters;
  recoil = _src.recoil;

  electrons.data.superClusterContainer_ = &superClusters;
  electrons.data.matchedGenContainer_ = &genParticles;
  muons.data.matchedGenContainer_ = &genParticles;
  taus.data.matchedGenContainer_ = &genParticles;
  photons.data.superClusterContainer_ = &superClusters;
  photons.data.matchedGenContainer_ = &genParticles;
  genParticles.data.parentContainer_ = &genParticles;
  chsAK4Jets.data.constituentsContainer_ = &pfCandidates;
  chsAK4Jets.data.matchedGenJetContainer_ = &ak4GenJets;
  puppiAK4Jets.data.constituentsContainer_ = &pfCandidates;
  puppiAK4Jets.data.matchedGenJetContainer_ = &ak4GenJets;
  chsAK8Jets.data.constituentsContainer_ = &pfCandidates;
  chsAK8Jets.data.subjetsContainer_ = &chsAK8Subjets;
  chsAK8Jets.data.matchedGenJetContainer_ = &ak8GenJets;
  chsCA15Jets.data.constituentsContainer_ = &pfCandidates;
  chsCA15Jets.data.subjetsContainer_ = &chsCA15Subjets;
  chsCA15Jets.data.matchedGenJetContainer_ = &ca15GenJets;
  puppiAK8Jets.data.constituentsContainer_ = &pfCandidates;
  puppiAK8Jets.data.subjetsContainer_ = &puppiAK8Subjets;
  puppiAK8Jets.data.matchedGenJetContainer_ = &ak8GenJets;
  puppiCA15Jets.data.constituentsContainer_ = &pfCandidates;
  puppiCA15Jets.data.subjetsContainer_ = &puppiCA15Subjets;
  puppiCA15Jets.data.matchedGenJetContainer_ = &ca15GenJets;

  return *this;
}

/*static*/
panda::utils::BranchList
panda::Event::getListOfBranches()
{
  utils::BranchList blist;
  blist += {"npv", "npvTrue", "rho", "rhoCentralCalo"};
  blist += GenReweight::getListOfBranches().fullNames("genReweight");
  blist += PFCand::getListOfBranches().fullNames("pfCandidates");
  blist += SuperCluster::getListOfBranches().fullNames("superClusters");
  blist += Electron::getListOfBranches().fullNames("electrons");
  blist += Muon::getListOfBranches().fullNames("muons");
  blist += Tau::getListOfBranches().fullNames("taus");
  blist += Photon::getListOfBranches().fullNames("photons");
  blist += Jet::getListOfBranches().fullNames("chsAK4Jets");
  blist += Jet::getListOfBranches().fullNames("puppiAK4Jets");
  blist += FatJet::getListOfBranches().fullNames("chsAK8Jets");
  blist += MicroJet::getListOfBranches().fullNames("chsAK8Subjets");
  blist += FatJet::getListOfBranches().fullNames("chsCA15Jets");
  blist += MicroJet::getListOfBranches().fullNames("chsCA15Subjets");
  blist += FatJet::getListOfBranches().fullNames("puppiAK8Jets");
  blist += MicroJet::getListOfBranches().fullNames("puppiAK8Subjets");
  blist += FatJet::getListOfBranches().fullNames("puppiCA15Jets");
  blist += MicroJet::getListOfBranches().fullNames("puppiCA15Subjets");
  blist += GenJet::getListOfBranches().fullNames("ak4GenJets");
  blist += GenJet::getListOfBranches().fullNames("ak8GenJets");
  blist += GenJet::getListOfBranches().fullNames("ca15GenJets");
  blist += GenParticle::getListOfBranches().fullNames("genParticles");
  blist += Parton::getListOfBranches().fullNames("partons");
  blist += RecoMet::getListOfBranches().fullNames("pfMet");
  blist += RecoMet::getListOfBranches().fullNames("puppiMet");
  blist += Met::getListOfBranches().fullNames("rawMet");
  blist += Met::getListOfBranches().fullNames("caloMet");
  blist += Met::getListOfBranches().fullNames("noMuMet");
  blist += Met::getListOfBranches().fullNames("noHFMet");
  blist += Met::getListOfBranches().fullNames("trkMet");
  blist += Met::getListOfBranches().fullNames("neutralMet");
  blist += Met::getListOfBranches().fullNames("photonMet");
  blist += Met::getListOfBranches().fullNames("hfMet");
  blist += Met::getListOfBranches().fullNames("genMet");
  blist += RecoMet::getListOfBranches().fullNames("metMuOnlyFix");
  blist += RecoMet::getListOfBranches().fullNames("metNoFix");
  blist += MetFilters::getListOfBranches().fullNames("metFilters");
  blist += Recoil::getListOfBranches().fullNames("recoil");
  return blist;
}
/*protected*/
void
panda::Event::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::setStatus(_tree, "", "npv", _branches);
  utils::setStatus(_tree, "", "npvTrue", _branches);
  utils::setStatus(_tree, "", "rho", _branches);
  utils::setStatus(_tree, "", "rhoCentralCalo", _branches);
}

/*protected*/
panda::utils::BranchList
panda::Event::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;

  blist.push_back(utils::getStatus(_tree, "", "npv"));
  blist.push_back(utils::getStatus(_tree, "", "npvTrue"));
  blist.push_back(utils::getStatus(_tree, "", "rho"));
  blist.push_back(utils::getStatus(_tree, "", "rhoCentralCalo"));
  return blist;
}

/*protected*/
panda::utils::BranchList
panda::Event::doGetBranchNames_() const
{
  return getListOfBranches();
}

/*protected*/
void
panda::Event::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  utils::setAddress(_tree, "", "npv", &npv, _branches, _setStatus);
  utils::setAddress(_tree, "", "npvTrue", &npvTrue, _branches, _setStatus);
  utils::setAddress(_tree, "", "rho", &rho, _branches, _setStatus);
  utils::setAddress(_tree, "", "rhoCentralCalo", &rhoCentralCalo, _branches, _setStatus);
}

/*protected*/
void
panda::Event::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::book(_tree, "", "npv", "", 's', &npv, _branches);
  utils::book(_tree, "", "npvTrue", "", 's', &npvTrue, _branches);
  utils::book(_tree, "", "rho", "", 'F', &rho, _branches);
  utils::book(_tree, "", "rhoCentralCalo", "", 'F', &rhoCentralCalo, _branches);
}

/*protected*/
void
panda::Event::doGetEntry_(Long64_t _entry)
{
  /* BEGIN CUSTOM Event.cc.doGetEntry_ */
  EventBase::doGetEntry_(_entry);
  /* END CUSTOM */
}

/*protected*/
void
panda::Event::doReleaseTree_(TTree& _tree)
{
  utils::resetAddress(_tree, "", "npv");
  utils::resetAddress(_tree, "", "npvTrue");
  utils::resetAddress(_tree, "", "rho");
  utils::resetAddress(_tree, "", "rhoCentralCalo");
}

void
panda::Event::doInit_()
{
  npv = 0;
  npvTrue = 0;
  rho = 0.;
  rhoCentralCalo = 0.;
  /* BEGIN CUSTOM Event.cc.doInit_ */
  /* END CUSTOM */
}


/* BEGIN CUSTOM Event.cc.global */
/* END CUSTOM */
