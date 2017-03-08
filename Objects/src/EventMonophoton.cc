#include "../interface/EventMonophoton.h"

panda::EventMonophoton::EventMonophoton() :
  EventBase()
{
  std::vector<Object*> myObjects{{&genReweight, &superClusters, &electrons, &muons, &taus, &photons, &jets, &genJets, &genParticles, &partons, &t1Met, &rawMet, &caloMet, &metMuOnlyFix, &metNoFix, &metFilters}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&superClusters, &electrons, &muons, &taus, &photons, &jets, &genJets, &genParticles, &partons}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());

  electrons.data.superClusterContainer_ = &superClusters;
  electrons.data.matchedGenContainer_ = &genParticles;
  muons.data.matchedGenContainer_ = &genParticles;
  taus.data.matchedGenContainer_ = &genParticles;
  photons.data.superClusterContainer_ = &superClusters;
  photons.data.matchedGenContainer_ = &genParticles;
  genParticles.data.parentContainer_ = &genParticles;
  jets.data.matchedGenJetContainer_ = &genJets;
}

panda::EventMonophoton::EventMonophoton(EventMonophoton const& _src) :
  EventBase(_src),
  genReweight(_src.genReweight),
  superClusters(_src.superClusters),
  electrons(_src.electrons),
  muons(_src.muons),
  taus(_src.taus),
  photons(_src.photons),
  jets(_src.jets),
  genJets(_src.genJets),
  genParticles(_src.genParticles),
  partons(_src.partons),
  t1Met(_src.t1Met),
  rawMet(_src.rawMet),
  caloMet(_src.caloMet),
  metMuOnlyFix(_src.metMuOnlyFix),
  metNoFix(_src.metNoFix),
  metFilters(_src.metFilters),
  npv(_src.npv),
  npvTrue(_src.npvTrue),
  rho(_src.rho),
  rhoCentralCalo(_src.rhoCentralCalo)
{
  std::vector<Object*> myObjects{{&genReweight, &superClusters, &electrons, &muons, &taus, &photons, &jets, &genJets, &genParticles, &partons, &t1Met, &rawMet, &caloMet, &metMuOnlyFix, &metNoFix, &metFilters}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&superClusters, &electrons, &muons, &taus, &photons, &jets, &genJets, &genParticles, &partons}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());


  electrons.data.superClusterContainer_ = &superClusters;
  electrons.data.matchedGenContainer_ = &genParticles;
  muons.data.matchedGenContainer_ = &genParticles;
  taus.data.matchedGenContainer_ = &genParticles;
  photons.data.superClusterContainer_ = &superClusters;
  photons.data.matchedGenContainer_ = &genParticles;
  genParticles.data.parentContainer_ = &genParticles;
  jets.data.matchedGenJetContainer_ = &genJets;
}

panda::EventMonophoton&
panda::EventMonophoton::operator=(EventMonophoton const& _src)
{
  EventBase::operator=(_src);
  npv = _src.npv;
  npvTrue = _src.npvTrue;
  rho = _src.rho;
  rhoCentralCalo = _src.rhoCentralCalo;

  genReweight = _src.genReweight;
  superClusters = _src.superClusters;
  electrons = _src.electrons;
  muons = _src.muons;
  taus = _src.taus;
  photons = _src.photons;
  jets = _src.jets;
  genJets = _src.genJets;
  genParticles = _src.genParticles;
  partons = _src.partons;
  t1Met = _src.t1Met;
  rawMet = _src.rawMet;
  caloMet = _src.caloMet;
  metMuOnlyFix = _src.metMuOnlyFix;
  metNoFix = _src.metNoFix;
  metFilters = _src.metFilters;

  electrons.data.superClusterContainer_ = &superClusters;
  electrons.data.matchedGenContainer_ = &genParticles;
  muons.data.matchedGenContainer_ = &genParticles;
  taus.data.matchedGenContainer_ = &genParticles;
  photons.data.superClusterContainer_ = &superClusters;
  photons.data.matchedGenContainer_ = &genParticles;
  genParticles.data.parentContainer_ = &genParticles;
  jets.data.matchedGenJetContainer_ = &genJets;

  return *this;
}

/*static*/
panda::utils::BranchList
panda::EventMonophoton::getListOfBranches()
{
  utils::BranchList blist;
  blist += EventBase::getListOfBranches();

  blist += {"npv", "npvTrue", "rho", "rhoCentralCalo"};
  blist += GenReweight::getListOfBranches().fullNames("genReweight");
  blist += SuperCluster::getListOfBranches().fullNames("superClusters");
  blist += Electron::getListOfBranches().fullNames("electrons");
  blist += Muon::getListOfBranches().fullNames("muons");
  blist += Tau::getListOfBranches().fullNames("taus");
  blist += XPhoton::getListOfBranches().fullNames("photons");
  blist += Jet::getListOfBranches().fullNames("jets");
  blist += GenJet::getListOfBranches().fullNames("genJets");
  blist += GenParticle::getListOfBranches().fullNames("genParticles");
  blist += Parton::getListOfBranches().fullNames("partons");
  blist += RecoMet::getListOfBranches().fullNames("t1Met");
  blist += Met::getListOfBranches().fullNames("rawMet");
  blist += Met::getListOfBranches().fullNames("caloMet");
  blist += RecoMet::getListOfBranches().fullNames("metMuOnlyFix");
  blist += RecoMet::getListOfBranches().fullNames("metNoFix");
  blist += MetFilters::getListOfBranches().fullNames("metFilters");
  return blist;
}
/*protected*/
void
panda::EventMonophoton::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  EventBase::doSetStatus_(_tree, _branches);
  utils::setStatus(_tree, "", "npv", _branches);
  utils::setStatus(_tree, "", "npvTrue", _branches);
  utils::setStatus(_tree, "", "rho", _branches);
  utils::setStatus(_tree, "", "rhoCentralCalo", _branches);
}

/*protected*/
panda::utils::BranchList
panda::EventMonophoton::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;
  blist += EventBase::doGetStatus_(_tree);

  blist.push_back(utils::getStatus(_tree, "", "npv"));
  blist.push_back(utils::getStatus(_tree, "", "npvTrue"));
  blist.push_back(utils::getStatus(_tree, "", "rho"));
  blist.push_back(utils::getStatus(_tree, "", "rhoCentralCalo"));
  return blist;
}

/*protected*/
panda::utils::BranchList
panda::EventMonophoton::doGetBranchNames_() const
{
  return getListOfBranches();
}

/*protected*/
void
panda::EventMonophoton::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  EventBase::doSetAddress_(_tree, _branches, _setStatus);

  utils::setAddress(_tree, "", "npv", &npv, _branches, _setStatus);
  utils::setAddress(_tree, "", "npvTrue", &npvTrue, _branches, _setStatus);
  utils::setAddress(_tree, "", "rho", &rho, _branches, _setStatus);
  utils::setAddress(_tree, "", "rhoCentralCalo", &rhoCentralCalo, _branches, _setStatus);
}

/*protected*/
void
panda::EventMonophoton::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  EventBase::doBook_(_tree, _branches);

  utils::book(_tree, "", "npv", "", 's', &npv, _branches);
  utils::book(_tree, "", "npvTrue", "", 's', &npvTrue, _branches);
  utils::book(_tree, "", "rho", "", 'F', &rho, _branches);
  utils::book(_tree, "", "rhoCentralCalo", "", 'F', &rhoCentralCalo, _branches);
}

/*protected*/
void
panda::EventMonophoton::doGetEntry_(TTree& _tree, Long64_t _entry)
{
  EventBase::doGetEntry_(_tree, _entry);

  /* BEGIN CUSTOM EventMonophoton.cc.doGetEntry_ */
  /* END CUSTOM */
}

void
panda::EventMonophoton::doInit_()
{
  EventBase::doInit_();

  npv = 0;
  npvTrue = 0;
  rho = 0.;
  rhoCentralCalo = 0.;
  /* BEGIN CUSTOM EventMonophoton.cc.doInit_ */
  /* END CUSTOM */
}


/* BEGIN CUSTOM EventMonophoton.cc.global */
panda::EventMonophoton&
panda::EventMonophoton::operator=(Event const& _src)
{
  EventBase::operator=(_src);

  npv = _src.npv;
  npvTrue = _src.npvTrue;
  rho = _src.rho;
  rhoCentralCalo = _src.rhoCentralCalo;

  genReweight = _src.genReweight;
  superClusters = _src.superClusters;
  electrons = _src.electrons;
  muons = _src.muons;
  taus = _src.taus;
  photons.resize(_src.photons.size());
  for (unsigned iP(0); iP != photons.size(); ++iP)
    static_cast<Photon&>(photons[iP]) = _src.photons[iP];
  jets = _src.chsAK4Jets;
  genJets = _src.ak4GenJets;
  genParticles = _src.genParticles;
  partons = _src.partons;
  t1Met = _src.pfMet;
  rawMet = _src.rawMet;
  caloMet = _src.caloMet;
  metMuOnlyFix = _src.metMuOnlyFix;
  metNoFix = _src.metNoFix;
  metFilters = _src.metFilters;

  electrons.data.superClusterContainer_ = &superClusters;
  electrons.data.matchedGenContainer_ = &genParticles;
  muons.data.matchedGenContainer_ = &genParticles;
  taus.data.matchedGenContainer_ = &genParticles;
  photons.data.superClusterContainer_ = &superClusters;
  photons.data.matchedGenContainer_ = &genParticles;
  genParticles.data.parentContainer_ = &genParticles;
  jets.data.matchedGenJetContainer_ = &genJets;
  jets.data.constituentsContainer_ = 0;

  return *this;
}

/* END CUSTOM */
