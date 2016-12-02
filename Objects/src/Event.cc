#include "../interface/Event.h"

panda::Event::Event() :
  TreeEntry()
{
  for (auto& p : electrons)
    p.superCluster.setContainer(superClusters);
  for (auto& p : photons)
    p.superCluster.setContainer(superClusters);
  for (auto& p : genParticles)
    p.parent.setContainer(genParticles);
}

panda::Event::Event(Event const& _src) :
  TreeEntry(),
  pfCandidates(_src.pfCandidates),
  superClusters(_src.superClusters),
  electrons(_src.electrons),
  muons(_src.muons),
  taus(_src.taus),
  photons(_src.photons),
  chsAK4(_src.chsAK4),
  puppiAK4(_src.puppiAK4),
  chsAK8(_src.chsAK8),
  chsCA15(_src.chsCA15),
  puppiAK8(_src.puppiAK8),
  puppiCA15(_src.puppiCA15),
  subjets(_src.subjets),
  genJets(_src.genJets),
  genParticles(_src.genParticles),
  met(_src.met),
  rawMet(_src.rawMet),
  caloMet(_src.caloMet),
  noMuMet(_src.noMuMet),
  noHFMet(_src.noHFMet),
  trkMet(_src.trkMet),
  neutralMet(_src.neutralMet),
  photonMet(_src.photonMet),
  hfMet(_src.hfMet),
  metFilters(_src.metFilters),
  triggers(_src.triggers),
  runNumber(_src.runNumber),
  lumiNumber(_src.lumiNumber),
  eventNumber(_src.eventNumber),
  isData(_src.isData),
  npv(_src.npv),
  npvTrue(_src.npvTrue),
  rho(_src.rho),
  weight(_src.weight)
{
  for (auto& p : electrons)
    p.superCluster.setContainer(superClusters);
  for (auto& p : photons)
    p.superCluster.setContainer(superClusters);
  for (auto& p : genParticles)
    p.parent.setContainer(genParticles);
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
  weight = _src.weight;

  for (auto& p : electrons)
    p.superCluster.setContainer(superClusters);
  for (auto& p : photons)
    p.superCluster.setContainer(superClusters);
  for (auto& p : genParticles)
    p.parent.setContainer(genParticles);

  return *this;
}

void
panda::Event::init()
{
  pfCandidates.init();
  superClusters.init();
  electrons.init();
  muons.init();
  taus.init();
  photons.init();
  chsAK4.init();
  puppiAK4.init();
  chsAK8.init();
  chsCA15.init();
  puppiAK8.init();
  puppiCA15.init();
  subjets.init();
  genJets.init();
  genParticles.init();
  met.init();
  rawMet.init();
  caloMet.init();
  noMuMet.init();
  noHFMet.init();
  trkMet.init();
  neutralMet.init();
  photonMet.init();
  hfMet.init();
  metFilters.init();
  triggers.init();
  runNumber = 0;
  lumiNumber = 0;
  eventNumber = 0;
  isData = false;
  npv = 0;
  npvTrue = 0;
  rho = 0.;
  weight = 0.;
}

/*protected*/
void
panda::Event::doSetStatus_(TTree& _tree, Bool_t _status, utils::BranchList const& _branches)
{
  pfCandidates.setStatus(_tree, _status, _branches.subList("pfCandidates"));
  superClusters.setStatus(_tree, _status, _branches.subList("superClusters"));
  electrons.setStatus(_tree, _status, _branches.subList("electrons"));
  muons.setStatus(_tree, _status, _branches.subList("muons"));
  taus.setStatus(_tree, _status, _branches.subList("taus"));
  photons.setStatus(_tree, _status, _branches.subList("photons"));
  chsAK4.setStatus(_tree, _status, _branches.subList("chsAK4"));
  puppiAK4.setStatus(_tree, _status, _branches.subList("puppiAK4"));
  chsAK8.setStatus(_tree, _status, _branches.subList("chsAK8"));
  chsCA15.setStatus(_tree, _status, _branches.subList("chsCA15"));
  puppiAK8.setStatus(_tree, _status, _branches.subList("puppiAK8"));
  puppiCA15.setStatus(_tree, _status, _branches.subList("puppiCA15"));
  subjets.setStatus(_tree, _status, _branches.subList("subjets"));
  genJets.setStatus(_tree, _status, _branches.subList("genJets"));
  genParticles.setStatus(_tree, _status, _branches.subList("genParticles"));
  met.setStatus(_tree, _status, _branches.subList("met"));
  rawMet.setStatus(_tree, _status, _branches.subList("rawMet"));
  caloMet.setStatus(_tree, _status, _branches.subList("caloMet"));
  noMuMet.setStatus(_tree, _status, _branches.subList("noMuMet"));
  noHFMet.setStatus(_tree, _status, _branches.subList("noHFMet"));
  trkMet.setStatus(_tree, _status, _branches.subList("trkMet"));
  neutralMet.setStatus(_tree, _status, _branches.subList("neutralMet"));
  photonMet.setStatus(_tree, _status, _branches.subList("photonMet"));
  hfMet.setStatus(_tree, _status, _branches.subList("hfMet"));
  metFilters.setStatus(_tree, _status, _branches.subList("metFilters"));
  triggers.setStatus(_tree, _status, _branches.subList("triggers"));
  utils::setStatus(_tree, "", "runNumber", _status, _branches);
  utils::setStatus(_tree, "", "lumiNumber", _status, _branches);
  utils::setStatus(_tree, "", "eventNumber", _status, _branches);
  utils::setStatus(_tree, "", "isData", _status, _branches);
  utils::setStatus(_tree, "", "npv", _status, _branches);
  utils::setStatus(_tree, "", "npvTrue", _status, _branches);
  utils::setStatus(_tree, "", "rho", _status, _branches);
  utils::setStatus(_tree, "", "weight", _status, _branches);
}

/*protected*/
void
panda::Event::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  pfCandidates.setAddress(_tree, _branches.subList("pfCandidates"), _setStatus);
  superClusters.setAddress(_tree, _branches.subList("superClusters"), _setStatus);
  electrons.setAddress(_tree, _branches.subList("electrons"), _setStatus);
  muons.setAddress(_tree, _branches.subList("muons"), _setStatus);
  taus.setAddress(_tree, _branches.subList("taus"), _setStatus);
  photons.setAddress(_tree, _branches.subList("photons"), _setStatus);
  chsAK4.setAddress(_tree, _branches.subList("chsAK4"), _setStatus);
  puppiAK4.setAddress(_tree, _branches.subList("puppiAK4"), _setStatus);
  chsAK8.setAddress(_tree, _branches.subList("chsAK8"), _setStatus);
  chsCA15.setAddress(_tree, _branches.subList("chsCA15"), _setStatus);
  puppiAK8.setAddress(_tree, _branches.subList("puppiAK8"), _setStatus);
  puppiCA15.setAddress(_tree, _branches.subList("puppiCA15"), _setStatus);
  subjets.setAddress(_tree, _branches.subList("subjets"), _setStatus);
  genJets.setAddress(_tree, _branches.subList("genJets"), _setStatus);
  genParticles.setAddress(_tree, _branches.subList("genParticles"), _setStatus);
  met.setAddress(_tree, _branches.subList("met"), _setStatus);
  rawMet.setAddress(_tree, _branches.subList("rawMet"), _setStatus);
  caloMet.setAddress(_tree, _branches.subList("caloMet"), _setStatus);
  noMuMet.setAddress(_tree, _branches.subList("noMuMet"), _setStatus);
  noHFMet.setAddress(_tree, _branches.subList("noHFMet"), _setStatus);
  trkMet.setAddress(_tree, _branches.subList("trkMet"), _setStatus);
  neutralMet.setAddress(_tree, _branches.subList("neutralMet"), _setStatus);
  photonMet.setAddress(_tree, _branches.subList("photonMet"), _setStatus);
  hfMet.setAddress(_tree, _branches.subList("hfMet"), _setStatus);
  metFilters.setAddress(_tree, _branches.subList("metFilters"), _setStatus);
  triggers.setAddress(_tree, _branches.subList("triggers"), _setStatus);
  utils::setAddress(_tree, "", "runNumber", &runNumber, _branches, _setStatus);
  utils::setAddress(_tree, "", "lumiNumber", &lumiNumber, _branches, _setStatus);
  utils::setAddress(_tree, "", "eventNumber", &eventNumber, _branches, _setStatus);
  utils::setAddress(_tree, "", "isData", &isData, _branches, _setStatus);
  utils::setAddress(_tree, "", "npv", &npv, _branches, _setStatus);
  utils::setAddress(_tree, "", "npvTrue", &npvTrue, _branches, _setStatus);
  utils::setAddress(_tree, "", "rho", &rho, _branches, _setStatus);
  utils::setAddress(_tree, "", "weight", &weight, _branches, _setStatus);

  sizeBranches_.clear();
  if (_tree.GetBranchStatus("pfCandidates.size"))
    sizeBranches_.push_back(_tree.GetBranch("pfCandidates.size"));
  if (_tree.GetBranchStatus("superClusters.size"))
    sizeBranches_.push_back(_tree.GetBranch("superClusters.size"));
  if (_tree.GetBranchStatus("electrons.size"))
    sizeBranches_.push_back(_tree.GetBranch("electrons.size"));
  if (_tree.GetBranchStatus("muons.size"))
    sizeBranches_.push_back(_tree.GetBranch("muons.size"));
  if (_tree.GetBranchStatus("taus.size"))
    sizeBranches_.push_back(_tree.GetBranch("taus.size"));
  if (_tree.GetBranchStatus("photons.size"))
    sizeBranches_.push_back(_tree.GetBranch("photons.size"));
  if (_tree.GetBranchStatus("chsAK4.size"))
    sizeBranches_.push_back(_tree.GetBranch("chsAK4.size"));
  if (_tree.GetBranchStatus("puppiAK4.size"))
    sizeBranches_.push_back(_tree.GetBranch("puppiAK4.size"));
  if (_tree.GetBranchStatus("chsAK8.size"))
    sizeBranches_.push_back(_tree.GetBranch("chsAK8.size"));
  if (_tree.GetBranchStatus("chsCA15.size"))
    sizeBranches_.push_back(_tree.GetBranch("chsCA15.size"));
  if (_tree.GetBranchStatus("puppiAK8.size"))
    sizeBranches_.push_back(_tree.GetBranch("puppiAK8.size"));
  if (_tree.GetBranchStatus("puppiCA15.size"))
    sizeBranches_.push_back(_tree.GetBranch("puppiCA15.size"));
  if (_tree.GetBranchStatus("subjets.size"))
    sizeBranches_.push_back(_tree.GetBranch("subjets.size"));
  if (_tree.GetBranchStatus("genJets.size"))
    sizeBranches_.push_back(_tree.GetBranch("genJets.size"));
  if (_tree.GetBranchStatus("genParticles.size"))
    sizeBranches_.push_back(_tree.GetBranch("genParticles.size"));
}

/*protected*/
void
panda::Event::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  pfCandidates.book(_tree, _branches.subList("pfCandidates"));
  superClusters.book(_tree, _branches.subList("superClusters"));
  electrons.book(_tree, _branches.subList("electrons"));
  muons.book(_tree, _branches.subList("muons"));
  taus.book(_tree, _branches.subList("taus"));
  photons.book(_tree, _branches.subList("photons"));
  chsAK4.book(_tree, _branches.subList("chsAK4"));
  puppiAK4.book(_tree, _branches.subList("puppiAK4"));
  chsAK8.book(_tree, _branches.subList("chsAK8"));
  chsCA15.book(_tree, _branches.subList("chsCA15"));
  puppiAK8.book(_tree, _branches.subList("puppiAK8"));
  puppiCA15.book(_tree, _branches.subList("puppiCA15"));
  subjets.book(_tree, _branches.subList("subjets"));
  genJets.book(_tree, _branches.subList("genJets"));
  genParticles.book(_tree, _branches.subList("genParticles"));
  met.book(_tree, _branches.subList("met"));
  rawMet.book(_tree, _branches.subList("rawMet"));
  caloMet.book(_tree, _branches.subList("caloMet"));
  noMuMet.book(_tree, _branches.subList("noMuMet"));
  noHFMet.book(_tree, _branches.subList("noHFMet"));
  trkMet.book(_tree, _branches.subList("trkMet"));
  neutralMet.book(_tree, _branches.subList("neutralMet"));
  photonMet.book(_tree, _branches.subList("photonMet"));
  hfMet.book(_tree, _branches.subList("hfMet"));
  metFilters.book(_tree, _branches.subList("metFilters"));
  triggers.book(_tree, _branches.subList("triggers"));
  utils::book(_tree, "", "runNumber", "", 'i', &runNumber, _branches);
  utils::book(_tree, "", "lumiNumber", "", 'i', &lumiNumber, _branches);
  utils::book(_tree, "", "eventNumber", "", 'i', &eventNumber, _branches);
  utils::book(_tree, "", "isData", "", 'O', &isData, _branches);
  utils::book(_tree, "", "npv", "", 'I', &npv, _branches);
  utils::book(_tree, "", "npvTrue", "", 'I', &npvTrue, _branches);
  utils::book(_tree, "", "rho", "", 'F', &rho, _branches);
  utils::book(_tree, "", "weight", "", 'F', &weight, _branches);
}

/*protected*/
void
panda::Event::doReleaseTree_(TTree& _tree)
{
  pfCandidates.releaseTree(_tree);
  superClusters.releaseTree(_tree);
  electrons.releaseTree(_tree);
  muons.releaseTree(_tree);
  taus.releaseTree(_tree);
  photons.releaseTree(_tree);
  chsAK4.releaseTree(_tree);
  puppiAK4.releaseTree(_tree);
  chsAK8.releaseTree(_tree);
  chsCA15.releaseTree(_tree);
  puppiAK8.releaseTree(_tree);
  puppiCA15.releaseTree(_tree);
  subjets.releaseTree(_tree);
  genJets.releaseTree(_tree);
  genParticles.releaseTree(_tree);
  met.resetAddress(_tree);
  rawMet.resetAddress(_tree);
  caloMet.resetAddress(_tree);
  noMuMet.resetAddress(_tree);
  noHFMet.resetAddress(_tree);
  trkMet.resetAddress(_tree);
  neutralMet.resetAddress(_tree);
  photonMet.resetAddress(_tree);
  hfMet.resetAddress(_tree);
  metFilters.resetAddress(_tree);
  triggers.resetAddress(_tree);
}


/* BEGIN CUSTOM */
/* END CUSTOM */
/*protected*/
void
panda::Event::adjustCollectionSizes_()
{
  pfCandidates.resize(pfCandidates.size());
  superClusters.resize(superClusters.size());
  electrons.resize(electrons.size());
  muons.resize(muons.size());
  taus.resize(taus.size());
  photons.resize(photons.size());
  chsAK4.resize(chsAK4.size());
  puppiAK4.resize(puppiAK4.size());
  chsAK8.resize(chsAK8.size());
  chsCA15.resize(chsCA15.size());
  puppiAK8.resize(puppiAK8.size());
  puppiCA15.resize(puppiCA15.size());
  subjets.resize(subjets.size());
  genJets.resize(genJets.size());
  genParticles.resize(genParticles.size());
}

