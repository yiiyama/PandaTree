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
  jets(_src.jets),
  fatJets(_src.fatJets),
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
  jets.init();
  fatJets.init();
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
  jets.setStatus(_tree, _status, _branches.subList("jets"));
  fatJets.setStatus(_tree, _status, _branches.subList("fatJets"));
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
  jets.setAddress(_tree, _branches.subList("jets"), _setStatus);
  fatJets.setAddress(_tree, _branches.subList("fatJets"), _setStatus);
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
  if (_tree.GetBranchStatus("jets.size"))
    sizeBranches_.push_back(_tree.GetBranch("jets.size"));
  if (_tree.GetBranchStatus("fatJets.size"))
    sizeBranches_.push_back(_tree.GetBranch("fatJets.size"));
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
  jets.book(_tree, _branches.subList("jets"));
  fatJets.book(_tree, _branches.subList("fatJets"));
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
  jets.releaseTree(_tree);
  fatJets.releaseTree(_tree);
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
  jets.resize(jets.size());
  fatJets.resize(fatJets.size());
  genJets.resize(genJets.size());
  genParticles.resize(genParticles.size());
}

