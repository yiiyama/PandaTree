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
  metFilters(_src.metFilters),
  triggers(_src.triggers),
  runNumber(_src.runNumber),
  lumiNumber(_src.lumiNumber),
  eventNumber(_src.eventNumber),
  isData(_src.isData),
  npv(_src.npv),
  mcWeight(_src.mcWeight)
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
  mcWeight = _src.mcWeight;

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
  metFilters.init();
  triggers.init();
  runNumber = 0;
  lumiNumber = 0;
  eventNumber = 0;
  isData = false;
  npv = 0;
  mcWeight = 0.;
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
  metFilters.setStatus(_tree, _status, _branches.subList("metFilters"));
  triggers.setStatus(_tree, _status, _branches.subList("triggers"));
  utils::setStatus(_tree, "", "runNumber", _status, _branches);
  utils::setStatus(_tree, "", "lumiNumber", _status, _branches);
  utils::setStatus(_tree, "", "eventNumber", _status, _branches);
  utils::setStatus(_tree, "", "isData", _status, _branches);
  utils::setStatus(_tree, "", "npv", _status, _branches);
  utils::setStatus(_tree, "", "mcWeight", _status, _branches);
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
  metFilters.setAddress(_tree, _branches.subList("metFilters"), _setStatus);
  triggers.setAddress(_tree, _branches.subList("triggers"), _setStatus);
  utils::setAddress(_tree, "", "runNumber", &runNumber, _branches, _setStatus);
  utils::setAddress(_tree, "", "lumiNumber", &lumiNumber, _branches, _setStatus);
  utils::setAddress(_tree, "", "eventNumber", &eventNumber, _branches, _setStatus);
  utils::setAddress(_tree, "", "isData", &isData, _branches, _setStatus);
  utils::setAddress(_tree, "", "npv", &npv, _branches, _setStatus);
  utils::setAddress(_tree, "", "mcWeight", &mcWeight, _branches, _setStatus);
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
  metFilters.book(_tree, _branches.subList("metFilters"));
  triggers.book(_tree, _branches.subList("triggers"));
  utils::book(_tree, "", "runNumber", "", 'i', &runNumber, _branches);
  utils::book(_tree, "", "lumiNumber", "", 'i', &lumiNumber, _branches);
  utils::book(_tree, "", "eventNumber", "", 'i', &eventNumber, _branches);
  utils::book(_tree, "", "isData", "", 'O', &isData, _branches);
  utils::book(_tree, "", "npv", "", 'I', &npv, _branches);
  utils::book(_tree, "", "mcWeight", "", 'F', &mcWeight, _branches);
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
  metFilters.resetAddress(_tree);
  triggers.resetAddress(_tree);
}


/* BEGIN CUSTOM */
/* END CUSTOM */
