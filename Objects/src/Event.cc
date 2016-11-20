#include "../interface/Event.h"

panda::Event::Event() :
  TreeEntry()
{
  for (auto& p : electrons)
    p.superClusterRef(superClusters);
  for (auto& p : photons)
    p.superClusterRef(superClusters);
  for (auto& p : genParticles)
    p.parentRef(genParticles);
}

panda::Event::Event(Event const& _src) :
  TreeEntry(),
  pfCandidates(_src.pfCandidates),
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
  mcWeight(_src.mcWeight),
  superClusters(_src.superClusters)
{
  for (auto& p : electrons)
    p.superClusterRef(superClusters);
  for (auto& p : photons)
    p.superClusterRef(superClusters);
  for (auto& p : genParticles)
    p.parentRef(genParticles);
}

void
panda::Event::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  pfCandidates.setStatus(_tree, _status, _branches.subList("pfCandidates"));
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
  utils::setStatus(_tree, "", "superClusters", _status, _branches);
}

void
panda::Event::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  TreeEntry::setAddress(_tree, _branches);

  pfCandidates.setAddress(_tree, _branches.subList("pfCandidates"));
  electrons.setAddress(_tree, _branches.subList("electrons"));
  muons.setAddress(_tree, _branches.subList("muons"));
  taus.setAddress(_tree, _branches.subList("taus"));
  photons.setAddress(_tree, _branches.subList("photons"));
  jets.setAddress(_tree, _branches.subList("jets"));
  fatJets.setAddress(_tree, _branches.subList("fatJets"));
  genJets.setAddress(_tree, _branches.subList("genJets"));
  genParticles.setAddress(_tree, _branches.subList("genParticles"));
  met.setAddress(_tree, _branches.subList("met"));
  metFilters.setAddress(_tree, _branches.subList("metFilters"));
  triggers.setAddress(_tree, _branches.subList("triggers"));
  utils::setStatusAndAddress(_tree, "", "runNumber", &runNumber, _branches);
  utils::setStatusAndAddress(_tree, "", "lumiNumber", &lumiNumber, _branches);
  utils::setStatusAndAddress(_tree, "", "eventNumber", &eventNumber, _branches);
  utils::setStatusAndAddress(_tree, "", "isData", &isData, _branches);
  utils::setStatusAndAddress(_tree, "", "npv", &npv, _branches);
  utils::setStatusAndAddress(_tree, "", "mcWeight", &mcWeight, _branches);
  utils::setStatusAndAddress(_tree, "", "superClusters", &superClusters, _branches);
}

void
panda::Event::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  pfCandidates.book(_tree, _branches.subList("pfCandidates"));
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
  utils::book(_tree, "", "superClusters", "", 'SuperClusterCollection', &superClusters, _branches);
}

void
panda::Event::init()
{
  pfCandidates.init();
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
  /*INITIALIZE superClusters*/
}

/* BEGIN CUSTOM */
/* END CUSTOM */
