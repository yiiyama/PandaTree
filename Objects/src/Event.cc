#include "../interface/Event.h"

panda::Event::Event() :
  TreeEntry("Event")
{
  objects_ = {&genReweight, &pfCandidates, &superClusters, &electrons, &muons, &taus, &photons, &chsAK4Jets, &puppiAK4Jets, &chsAK8Jets, &chsCA15Jets, &puppiAK8Jets, &puppiCA15Jets, &subjets, &genJets, &genParticles, &partons, &met, &puppiMet, &rawMet, &caloMet, &noMuMet, &noHFMet, &trkMet, &neutralMet, &photonMet, &hfMet, &genMet, &metFilters, &triggers, &recoil};
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
  objects_ = {&genReweight, &pfCandidates, &superClusters, &electrons, &muons, &taus, &photons, &chsAK4Jets, &puppiAK4Jets, &chsAK8Jets, &chsCA15Jets, &puppiAK8Jets, &puppiCA15Jets, &subjets, &genJets, &genParticles, &partons, &met, &puppiMet, &rawMet, &caloMet, &noMuMet, &noHFMet, &trkMet, &neutralMet, &photonMet, &hfMet, &genMet, &metFilters, &triggers, &recoil};
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
  utils::BranchList blist;

  blist.push_back(utils::BranchName("runNumber").fullName(""));
  blist.push_back(utils::BranchName("lumiNumber").fullName(""));
  blist.push_back(utils::BranchName("eventNumber").fullName(""));
  blist.push_back(utils::BranchName("isData").fullName(""));
  blist.push_back(utils::BranchName("npv").fullName(""));
  blist.push_back(utils::BranchName("npvTrue").fullName(""));
  blist.push_back(utils::BranchName("rho").fullName(""));
  blist.push_back(utils::BranchName("rhoCentralCalo").fullName(""));
  blist.push_back(utils::BranchName("weight").fullName(""));
  return blist;
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
}


/* BEGIN CUSTOM Event.cc.global */

#include "TFile.h"
#include "TKey.h"
#include <iostream>

UInt_t
panda::Event::registerTrigger(char const* _path)
{
  TString path(_path);
  path += "_v";
  registeredTriggers_.push_back(path);

  // need to update the input
  runCache_.treeNumber = -1;

  return registeredTriggers_.size() - 1;
}

Bool_t
panda::Event::triggerFired(UInt_t _token) const
{
  if (_token >= registeredTriggers_.size())
    return false;

  if (initRun_()) {
    UInt_t idx(runCache_.triggerIndicesStore[runCache_.menuId][_token]);
    if (idx >= triggers.size())
      return false;

    return triggers.pass(idx);
  }

  return false;
}

char const*
panda::Event::triggerMenu() const
{
  if (initRun_())
    return runCache_.triggerMenuNames[runCache_.menuId];

  return "";
}

Bool_t
panda::Event::initRun_() const
{
  if (currentInputIdx_ > inputs_.size())
    return false;

  auto* input(inputs_[currentInputIdx_]);

  bool newRun(runNumber != runCache_.runNumber);

  if (input->GetTreeNumber() != runCache_.treeNumber) {
    // reading a new input file - refresh all cache
    
    runCache_.treeNumber = input->GetTreeNumber();

    // clear out the cache
    runCache_.triggerMenuNames.clear();
    runCache_.triggerIndicesStore.clear();
    runCache_.runToMenuIdMap.clear();

    auto* inputFile(input->GetCurrentFile());
    if (!inputFile)
      return false;

    // read out runs and hlt trees (using GetKey to create a "fresh" object - Get can fetch an in-memory object that may already be in use)
    auto* key(inputFile->GetKey("runs"));
    if (!key) {
      std::cerr << "File " << inputFile->GetName() << " does not have a run tree" << std::endl;
      throw std::runtime_error("InputError");
    }
    auto* runTree(static_cast<TTree*>(key->ReadObj()));

    // now read and save the run - menu index mapping
    unsigned run(0);
    unsigned hltMenu(0);
    runTree->SetBranchAddress("run", &run);
    runTree->SetBranchAddress("hltMenu", &hltMenu);

    long iEntry(0);
    while (runTree->GetEntry(iEntry++) > 0)
      runCache_.runToMenuIdMap.emplace(run, hltMenu);

    delete runTree;

    key = inputFile->GetKey("hlt");
    if (!key) {
      std::cerr << "File " << inputFile->GetName() << " does not have an hlt tree" << std::endl;
      return false;
    }
    auto* hltTree(static_cast<TTree*>(key->ReadObj()));

    auto* menu(new TString);
    auto* paths(new std::vector<TString>);
    hltTree->SetBranchAddress("menu", &menu);
    hltTree->SetBranchAddress("paths", &paths);

    iEntry = 0;
    while (hltTree->GetEntry(iEntry++) > 0) {
      runCache_.triggerMenuNames.push_back(*menu);

      runCache_.triggerIndicesStore.emplace_back();
      auto& indices(runCache_.triggerIndicesStore.back());

      // for each registered path, find the matching trigger in the given menu
      for (auto& path : registeredTriggers_) {
        unsigned iT(0);
        for (; iT != paths->size(); ++iT) {
          if ((*paths)[iT].BeginsWith(path)) {
            indices.push_back(iT);
            break;
          }
        }
        if (iT == paths->size())
          indices.push_back(-1);
      }
    }

    delete hltTree;
    delete menu;
    delete paths;

    // always treat file boundary as a run boundary
    newRun = true;
  }

  if (newRun) {
    runCache_.runNumber = runNumber;

    // find the menu id corresponding to the run
    auto idxItr(runCache_.runToMenuIdMap.find(runNumber));
    if (idxItr == runCache_.runToMenuIdMap.end()) {
      std::cerr << "Run " << runNumber << " not found in the run tree" << std::endl;
      throw std::runtime_error("InputError");
    }

    runCache_.menuId = idxItr->second;
  }

  return true;
}

/* END CUSTOM */
