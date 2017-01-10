#include "../interface/Event.h"

panda::Event::Event() :
  TreeEntry()
{
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
  TreeEntry(),
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

void
panda::Event::init()
{
  genReweight.init();
  pfCandidates.init();
  superClusters.init();
  electrons.init();
  muons.init();
  taus.init();
  photons.init();
  chsAK4Jets.init();
  puppiAK4Jets.init();
  chsAK8Jets.init();
  chsCA15Jets.init();
  puppiAK8Jets.init();
  puppiCA15Jets.init();
  subjets.init();
  genJets.init();
  genParticles.init();
  partons.init();
  met.init();
  puppiMet.init();
  rawMet.init();
  caloMet.init();
  noMuMet.init();
  noHFMet.init();
  trkMet.init();
  neutralMet.init();
  photonMet.init();
  hfMet.init();
  genMet.init();
  metFilters.init();
  triggers.init();
  recoil.init();
  runNumber = 0;
  lumiNumber = 0;
  eventNumber = 0;
  isData = false;
  npv = 0;
  npvTrue = 0;
  rho = 0.;
  rhoCentralCalo = 0.;
  weight = 0.;
}

/*protected*/
void
panda::Event::doSetStatus_(TTree& _tree, Bool_t _status, utils::BranchList const& _branches)
{
  genReweight.setStatus(_tree, _status, _branches.subList("genReweight"));
  pfCandidates.setStatus(_tree, _status, _branches.subList("pfCandidates"));
  superClusters.setStatus(_tree, _status, _branches.subList("superClusters"));
  electrons.setStatus(_tree, _status, _branches.subList("electrons"));
  muons.setStatus(_tree, _status, _branches.subList("muons"));
  taus.setStatus(_tree, _status, _branches.subList("taus"));
  photons.setStatus(_tree, _status, _branches.subList("photons"));
  chsAK4Jets.setStatus(_tree, _status, _branches.subList("chsAK4Jets"));
  puppiAK4Jets.setStatus(_tree, _status, _branches.subList("puppiAK4Jets"));
  chsAK8Jets.setStatus(_tree, _status, _branches.subList("chsAK8Jets"));
  chsCA15Jets.setStatus(_tree, _status, _branches.subList("chsCA15Jets"));
  puppiAK8Jets.setStatus(_tree, _status, _branches.subList("puppiAK8Jets"));
  puppiCA15Jets.setStatus(_tree, _status, _branches.subList("puppiCA15Jets"));
  subjets.setStatus(_tree, _status, _branches.subList("subjets"));
  genJets.setStatus(_tree, _status, _branches.subList("genJets"));
  genParticles.setStatus(_tree, _status, _branches.subList("genParticles"));
  partons.setStatus(_tree, _status, _branches.subList("partons"));
  met.setStatus(_tree, _status, _branches.subList("met"));
  puppiMet.setStatus(_tree, _status, _branches.subList("puppiMet"));
  rawMet.setStatus(_tree, _status, _branches.subList("rawMet"));
  caloMet.setStatus(_tree, _status, _branches.subList("caloMet"));
  noMuMet.setStatus(_tree, _status, _branches.subList("noMuMet"));
  noHFMet.setStatus(_tree, _status, _branches.subList("noHFMet"));
  trkMet.setStatus(_tree, _status, _branches.subList("trkMet"));
  neutralMet.setStatus(_tree, _status, _branches.subList("neutralMet"));
  photonMet.setStatus(_tree, _status, _branches.subList("photonMet"));
  hfMet.setStatus(_tree, _status, _branches.subList("hfMet"));
  genMet.setStatus(_tree, _status, _branches.subList("genMet"));
  metFilters.setStatus(_tree, _status, _branches.subList("metFilters"));
  triggers.setStatus(_tree, _status, _branches.subList("triggers"));
  recoil.setStatus(_tree, _status, _branches.subList("recoil"));
  utils::setStatus(_tree, "", "runNumber", _status, _branches);
  utils::setStatus(_tree, "", "lumiNumber", _status, _branches);
  utils::setStatus(_tree, "", "eventNumber", _status, _branches);
  utils::setStatus(_tree, "", "isData", _status, _branches);
  utils::setStatus(_tree, "", "npv", _status, _branches);
  utils::setStatus(_tree, "", "npvTrue", _status, _branches);
  utils::setStatus(_tree, "", "rho", _status, _branches);
  utils::setStatus(_tree, "", "rhoCentralCalo", _status, _branches);
  utils::setStatus(_tree, "", "weight", _status, _branches);
}

/*protected*/
void
panda::Event::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  genReweight.setAddress(_tree, _branches.subList("genReweight"), _setStatus);
  pfCandidates.setAddress(_tree, _branches.subList("pfCandidates"), _setStatus);
  superClusters.setAddress(_tree, _branches.subList("superClusters"), _setStatus);
  electrons.setAddress(_tree, _branches.subList("electrons"), _setStatus);
  muons.setAddress(_tree, _branches.subList("muons"), _setStatus);
  taus.setAddress(_tree, _branches.subList("taus"), _setStatus);
  photons.setAddress(_tree, _branches.subList("photons"), _setStatus);
  chsAK4Jets.setAddress(_tree, _branches.subList("chsAK4Jets"), _setStatus);
  puppiAK4Jets.setAddress(_tree, _branches.subList("puppiAK4Jets"), _setStatus);
  chsAK8Jets.setAddress(_tree, _branches.subList("chsAK8Jets"), _setStatus);
  chsCA15Jets.setAddress(_tree, _branches.subList("chsCA15Jets"), _setStatus);
  puppiAK8Jets.setAddress(_tree, _branches.subList("puppiAK8Jets"), _setStatus);
  puppiCA15Jets.setAddress(_tree, _branches.subList("puppiCA15Jets"), _setStatus);
  subjets.setAddress(_tree, _branches.subList("subjets"), _setStatus);
  genJets.setAddress(_tree, _branches.subList("genJets"), _setStatus);
  genParticles.setAddress(_tree, _branches.subList("genParticles"), _setStatus);
  partons.setAddress(_tree, _branches.subList("partons"), _setStatus);
  met.setAddress(_tree, _branches.subList("met"), _setStatus);
  puppiMet.setAddress(_tree, _branches.subList("puppiMet"), _setStatus);
  rawMet.setAddress(_tree, _branches.subList("rawMet"), _setStatus);
  caloMet.setAddress(_tree, _branches.subList("caloMet"), _setStatus);
  noMuMet.setAddress(_tree, _branches.subList("noMuMet"), _setStatus);
  noHFMet.setAddress(_tree, _branches.subList("noHFMet"), _setStatus);
  trkMet.setAddress(_tree, _branches.subList("trkMet"), _setStatus);
  neutralMet.setAddress(_tree, _branches.subList("neutralMet"), _setStatus);
  photonMet.setAddress(_tree, _branches.subList("photonMet"), _setStatus);
  hfMet.setAddress(_tree, _branches.subList("hfMet"), _setStatus);
  genMet.setAddress(_tree, _branches.subList("genMet"), _setStatus);
  metFilters.setAddress(_tree, _branches.subList("metFilters"), _setStatus);
  triggers.setAddress(_tree, _branches.subList("triggers"), _setStatus);
  recoil.setAddress(_tree, _branches.subList("recoil"), _setStatus);
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
  genReweight.book(_tree, _branches.subList("genReweight"));
  pfCandidates.book(_tree, _branches.subList("pfCandidates"));
  superClusters.book(_tree, _branches.subList("superClusters"));
  electrons.book(_tree, _branches.subList("electrons"));
  muons.book(_tree, _branches.subList("muons"));
  taus.book(_tree, _branches.subList("taus"));
  photons.book(_tree, _branches.subList("photons"));
  chsAK4Jets.book(_tree, _branches.subList("chsAK4Jets"));
  puppiAK4Jets.book(_tree, _branches.subList("puppiAK4Jets"));
  chsAK8Jets.book(_tree, _branches.subList("chsAK8Jets"));
  chsCA15Jets.book(_tree, _branches.subList("chsCA15Jets"));
  puppiAK8Jets.book(_tree, _branches.subList("puppiAK8Jets"));
  puppiCA15Jets.book(_tree, _branches.subList("puppiCA15Jets"));
  subjets.book(_tree, _branches.subList("subjets"));
  genJets.book(_tree, _branches.subList("genJets"));
  genParticles.book(_tree, _branches.subList("genParticles"));
  partons.book(_tree, _branches.subList("partons"));
  met.book(_tree, _branches.subList("met"));
  puppiMet.book(_tree, _branches.subList("puppiMet"));
  rawMet.book(_tree, _branches.subList("rawMet"));
  caloMet.book(_tree, _branches.subList("caloMet"));
  noMuMet.book(_tree, _branches.subList("noMuMet"));
  noHFMet.book(_tree, _branches.subList("noHFMet"));
  trkMet.book(_tree, _branches.subList("trkMet"));
  neutralMet.book(_tree, _branches.subList("neutralMet"));
  photonMet.book(_tree, _branches.subList("photonMet"));
  hfMet.book(_tree, _branches.subList("hfMet"));
  genMet.book(_tree, _branches.subList("genMet"));
  metFilters.book(_tree, _branches.subList("metFilters"));
  triggers.book(_tree, _branches.subList("triggers"));
  recoil.book(_tree, _branches.subList("recoil"));
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
panda::Event::doReleaseTree_(TTree& _tree)
{
  genReweight.resetAddress(_tree);
  pfCandidates.releaseTree(_tree);
  superClusters.releaseTree(_tree);
  electrons.releaseTree(_tree);
  muons.releaseTree(_tree);
  taus.releaseTree(_tree);
  photons.releaseTree(_tree);
  chsAK4Jets.releaseTree(_tree);
  puppiAK4Jets.releaseTree(_tree);
  chsAK8Jets.releaseTree(_tree);
  chsCA15Jets.releaseTree(_tree);
  puppiAK8Jets.releaseTree(_tree);
  puppiCA15Jets.releaseTree(_tree);
  subjets.releaseTree(_tree);
  genJets.releaseTree(_tree);
  genParticles.releaseTree(_tree);
  partons.releaseTree(_tree);
  met.resetAddress(_tree);
  puppiMet.resetAddress(_tree);
  rawMet.resetAddress(_tree);
  caloMet.resetAddress(_tree);
  noMuMet.resetAddress(_tree);
  noHFMet.resetAddress(_tree);
  trkMet.resetAddress(_tree);
  neutralMet.resetAddress(_tree);
  photonMet.resetAddress(_tree);
  hfMet.resetAddress(_tree);
  genMet.resetAddress(_tree);
  metFilters.resetAddress(_tree);
  triggers.resetAddress(_tree);
  recoil.resetAddress(_tree);
}


/* BEGIN CUSTOM Event.cc.global */
/* END CUSTOM */
/*protected*/
void
panda::Event::doPrepareGetEntry_(Long64_t _iEntry)
{
  pfCandidates.prepareGetEntry(_iEntry);
  superClusters.prepareGetEntry(_iEntry);
  electrons.prepareGetEntry(_iEntry);
  muons.prepareGetEntry(_iEntry);
  taus.prepareGetEntry(_iEntry);
  photons.prepareGetEntry(_iEntry);
  chsAK4Jets.prepareGetEntry(_iEntry);
  puppiAK4Jets.prepareGetEntry(_iEntry);
  chsAK8Jets.prepareGetEntry(_iEntry);
  chsCA15Jets.prepareGetEntry(_iEntry);
  puppiAK8Jets.prepareGetEntry(_iEntry);
  puppiCA15Jets.prepareGetEntry(_iEntry);
  subjets.prepareGetEntry(_iEntry);
  genJets.prepareGetEntry(_iEntry);
  genParticles.prepareGetEntry(_iEntry);
  partons.prepareGetEntry(_iEntry);
}

