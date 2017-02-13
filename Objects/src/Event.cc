#include "../interface/Event.h"

panda::Event::Event() :
  TreeEntry("Event")
{
  objects_ = {&genReweight, &pfCandidates, &superClusters, &electrons, &muons, &taus, &photons, &chsAK4Jets, &puppiAK4Jets, &chsAK8Jets, &chsCA15Jets, &puppiAK8Jets, &puppiCA15Jets, &subjets, &genJets, &genParticles, &partons, &met, &puppiMet, &rawMet, &caloMet, &noMuMet, &noHFMet, &trkMet, &neutralMet, &photonMet, &hfMet, &genMet, &metMuOnlyFix, &metNoFix, &metFilters, &triggers, &recoil};
  collections_ = {&pfCandidates, &superClusters, &electrons, &muons, &taus, &photons, &chsAK4Jets, &puppiAK4Jets, &chsAK8Jets, &chsCA15Jets, &puppiAK8Jets, &puppiCA15Jets, &subjets, &genJets, &genParticles, &partons};

  electrons.data.superClusterContainer_ = &superClusters;
  electrons.data.matchedGenContainer_ = &genParticles;
  muons.data.matchedGenContainer_ = &genParticles;
  taus.data.matchedGenContainer_ = &genParticles;
  photons.data.superClusterContainer_ = &superClusters;
  photons.data.matchedGenContainer_ = &genParticles;
  genParticles.data.parentContainer_ = &genParticles;
  chsAK4Jets.data.constituentsContainer_ = &pfCandidates;
  chsAK4Jets.data.matchedGenJetContainer_ = &genJets;
  puppiAK4Jets.data.constituentsContainer_ = &pfCandidates;
  puppiAK4Jets.data.matchedGenJetContainer_ = &genJets;
  chsAK8Jets.data.constituentsContainer_ = &pfCandidates;
  chsAK8Jets.data.subjetsContainer_ = &subjets;
  chsCA15Jets.data.constituentsContainer_ = &pfCandidates;
  chsCA15Jets.data.subjetsContainer_ = &subjets;
  puppiAK8Jets.data.constituentsContainer_ = &pfCandidates;
  puppiAK8Jets.data.subjetsContainer_ = &subjets;
  puppiCA15Jets.data.constituentsContainer_ = &pfCandidates;
  puppiCA15Jets.data.subjetsContainer_ = &subjets;
}

panda::Event::Event(Event const& _src) :
  TreeEntry(_src.getName()),
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
  chsCA15Jets(_src.chsCA15Jets),
  puppiAK8Jets(_src.puppiAK8Jets),
  puppiCA15Jets(_src.puppiCA15Jets),
  subjets(_src.subjets),
  genJets(_src.genJets),
  genParticles(_src.genParticles),
  partons(_src.partons),
  met(_src.met),
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
  triggers(_src.triggers),
  recoil(_src.recoil),
  runNumber(_src.runNumber),
  lumiNumber(_src.lumiNumber),
  eventNumber(_src.eventNumber),
  isData(_src.isData),
  npv(_src.npv),
  npvTrue(_src.npvTrue),
  rho(_src.rho),
  rhoCentralCalo(_src.rhoCentralCalo),
  weight(_src.weight)
{
  objects_ = {&genReweight, &pfCandidates, &superClusters, &electrons, &muons, &taus, &photons, &chsAK4Jets, &puppiAK4Jets, &chsAK8Jets, &chsCA15Jets, &puppiAK8Jets, &puppiCA15Jets, &subjets, &genJets, &genParticles, &partons, &met, &puppiMet, &rawMet, &caloMet, &noMuMet, &noHFMet, &trkMet, &neutralMet, &photonMet, &hfMet, &genMet, &metMuOnlyFix, &metNoFix, &metFilters, &triggers, &recoil};
  collections_ = {&pfCandidates, &superClusters, &electrons, &muons, &taus, &photons, &chsAK4Jets, &puppiAK4Jets, &chsAK8Jets, &chsCA15Jets, &puppiAK8Jets, &puppiCA15Jets, &subjets, &genJets, &genParticles, &partons};

  electrons.data.superClusterContainer_ = &superClusters;
  electrons.data.matchedGenContainer_ = &genParticles;
  muons.data.matchedGenContainer_ = &genParticles;
  taus.data.matchedGenContainer_ = &genParticles;
  photons.data.superClusterContainer_ = &superClusters;
  photons.data.matchedGenContainer_ = &genParticles;
  genParticles.data.parentContainer_ = &genParticles;
  chsAK4Jets.data.constituentsContainer_ = &pfCandidates;
  chsAK4Jets.data.matchedGenJetContainer_ = &genJets;
  puppiAK4Jets.data.constituentsContainer_ = &pfCandidates;
  puppiAK4Jets.data.matchedGenJetContainer_ = &genJets;
  chsAK8Jets.data.constituentsContainer_ = &pfCandidates;
  chsAK8Jets.data.subjetsContainer_ = &subjets;
  chsCA15Jets.data.constituentsContainer_ = &pfCandidates;
  chsCA15Jets.data.subjetsContainer_ = &subjets;
  puppiAK8Jets.data.constituentsContainer_ = &pfCandidates;
  puppiAK8Jets.data.subjetsContainer_ = &subjets;
  puppiCA15Jets.data.constituentsContainer_ = &pfCandidates;
  puppiCA15Jets.data.subjetsContainer_ = &subjets;
}

panda::Event&
panda::Event::operator=(Event const& _src)
{
  runNumber = _src.runNumber;
  lumiNumber = _src.lumiNumber;
  eventNumber = _src.eventNumber;
  isData = _src.isData;
  npv = _src.npv;
  npvTrue = _src.npvTrue;
  rho = _src.rho;
  rhoCentralCalo = _src.rhoCentralCalo;
  weight = _src.weight;

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
  chsCA15Jets = _src.chsCA15Jets;
  puppiAK8Jets = _src.puppiAK8Jets;
  puppiCA15Jets = _src.puppiCA15Jets;
  subjets = _src.subjets;
  genJets = _src.genJets;
  genParticles = _src.genParticles;
  partons = _src.partons;
  met = _src.met;
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
  triggers = _src.triggers;
  recoil = _src.recoil;

  electrons.data.superClusterContainer_ = &superClusters;
  electrons.data.matchedGenContainer_ = &genParticles;
  muons.data.matchedGenContainer_ = &genParticles;
  taus.data.matchedGenContainer_ = &genParticles;
  photons.data.superClusterContainer_ = &superClusters;
  photons.data.matchedGenContainer_ = &genParticles;
  genParticles.data.parentContainer_ = &genParticles;
  chsAK4Jets.data.constituentsContainer_ = &pfCandidates;
  chsAK4Jets.data.matchedGenJetContainer_ = &genJets;
  puppiAK4Jets.data.constituentsContainer_ = &pfCandidates;
  puppiAK4Jets.data.matchedGenJetContainer_ = &genJets;
  chsAK8Jets.data.constituentsContainer_ = &pfCandidates;
  chsAK8Jets.data.subjetsContainer_ = &subjets;
  chsCA15Jets.data.constituentsContainer_ = &pfCandidates;
  chsCA15Jets.data.subjetsContainer_ = &subjets;
  puppiAK8Jets.data.constituentsContainer_ = &pfCandidates;
  puppiAK8Jets.data.subjetsContainer_ = &subjets;
  puppiCA15Jets.data.constituentsContainer_ = &pfCandidates;
  puppiCA15Jets.data.subjetsContainer_ = &subjets;

  return *this;
}

/*static*/
panda::utils::BranchList
panda::Event::getListOfBranches()
{
  utils::BranchList blist;
  blist += {"runNumber", "lumiNumber", "eventNumber", "isData", "npv", "npvTrue", "rho", "rhoCentralCalo", "weight"};
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
  blist += FatJet::getListOfBranches().fullNames("chsCA15Jets");
  blist += FatJet::getListOfBranches().fullNames("puppiAK8Jets");
  blist += FatJet::getListOfBranches().fullNames("puppiCA15Jets");
  blist += MicroJet::getListOfBranches().fullNames("subjets");
  blist += GenJet::getListOfBranches().fullNames("genJets");
  blist += GenParticle::getListOfBranches().fullNames("genParticles");
  blist += Parton::getListOfBranches().fullNames("partons");
  blist += RecoMet::getListOfBranches().fullNames("met");
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
  blist += HLTBits::getListOfBranches().fullNames("triggers");
  blist += Recoil::getListOfBranches().fullNames("recoil");
  return blist;
}
/*protected*/
void
panda::Event::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::setStatus(_tree, "", "runNumber", _branches);
  utils::setStatus(_tree, "", "lumiNumber", _branches);
  utils::setStatus(_tree, "", "eventNumber", _branches);
  utils::setStatus(_tree, "", "isData", _branches);
  utils::setStatus(_tree, "", "npv", _branches);
  utils::setStatus(_tree, "", "npvTrue", _branches);
  utils::setStatus(_tree, "", "rho", _branches);
  utils::setStatus(_tree, "", "rhoCentralCalo", _branches);
  utils::setStatus(_tree, "", "weight", _branches);
}

/*protected*/
panda::utils::BranchList
panda::Event::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;

  blist.push_back(utils::getStatus(_tree, "", "runNumber"));
  blist.push_back(utils::getStatus(_tree, "", "lumiNumber"));
  blist.push_back(utils::getStatus(_tree, "", "eventNumber"));
  blist.push_back(utils::getStatus(_tree, "", "isData"));
  blist.push_back(utils::getStatus(_tree, "", "npv"));
  blist.push_back(utils::getStatus(_tree, "", "npvTrue"));
  blist.push_back(utils::getStatus(_tree, "", "rho"));
  blist.push_back(utils::getStatus(_tree, "", "rhoCentralCalo"));
  blist.push_back(utils::getStatus(_tree, "", "weight"));
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
  utils::setAddress(_tree, "", "runNumber", &runNumber, _branches, _setStatus);
  utils::setAddress(_tree, "", "lumiNumber", &lumiNumber, _branches, _setStatus);
  utils::setAddress(_tree, "", "eventNumber", &eventNumber, _branches, _setStatus);
  utils::setAddress(_tree, "", "isData", &isData, _branches, _setStatus);
  utils::setAddress(_tree, "", "npv", &npv, _branches, _setStatus);
  utils::setAddress(_tree, "", "npvTrue", &npvTrue, _branches, _setStatus);
  utils::setAddress(_tree, "", "rho", &rho, _branches, _setStatus);
  utils::setAddress(_tree, "", "rhoCentralCalo", &rhoCentralCalo, _branches, _setStatus);
  utils::setAddress(_tree, "", "weight", &weight, _branches, _setStatus);
}

/*protected*/
void
panda::Event::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::book(_tree, "", "runNumber", "", 'i', &runNumber, _branches);
  utils::book(_tree, "", "lumiNumber", "", 'i', &lumiNumber, _branches);
  utils::book(_tree, "", "eventNumber", "", 'i', &eventNumber, _branches);
  utils::book(_tree, "", "isData", "", 'O', &isData, _branches);
  utils::book(_tree, "", "npv", "", 's', &npv, _branches);
  utils::book(_tree, "", "npvTrue", "", 's', &npvTrue, _branches);
  utils::book(_tree, "", "rho", "", 'F', &rho, _branches);
  utils::book(_tree, "", "rhoCentralCalo", "", 'F', &rhoCentralCalo, _branches);
  utils::book(_tree, "", "weight", "", 'F', &weight, _branches);
}

/*protected*/
void
panda::Event::doGetEntry_(Long64_t _entry)
{
  /* BEGIN CUSTOM Event.cc.doGetEntry_ */
  run.update(runNumber, *inputs_[currentInputIdx_]);
  /* END CUSTOM */
}

/*protected*/
void
panda::Event::doReleaseTree_(TTree& _tree)
{
  utils::resetAddress(_tree, "", "runNumber");
  utils::resetAddress(_tree, "", "lumiNumber");
  utils::resetAddress(_tree, "", "eventNumber");
  utils::resetAddress(_tree, "", "isData");
  utils::resetAddress(_tree, "", "npv");
  utils::resetAddress(_tree, "", "npvTrue");
  utils::resetAddress(_tree, "", "rho");
  utils::resetAddress(_tree, "", "rhoCentralCalo");
  utils::resetAddress(_tree, "", "weight");
}

void
panda::Event::doInit_()
{
  runNumber = 0;
  lumiNumber = 0;
  eventNumber = 0;
  isData = false;
  npv = 0;
  npvTrue = 0;
  rho = 0.;
  rhoCentralCalo = 0.;
  weight = 0.;
  /* BEGIN CUSTOM Event.cc.doInit_ */
  /* END CUSTOM */
}


/* BEGIN CUSTOM Event.cc.global */

Bool_t
panda::Event::triggerFired(UInt_t _token) const
{
  UInt_t idx(run.getTriggerIndex(_token));
  if (idx < run.triggerSize())
    return triggers.pass(idx);
  else
    return false;
}

/* END CUSTOM */
