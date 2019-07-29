#include "../interface/EventTP.h"

panda::EventTP::EventTP() :
  EventBase()
{
  std::vector<Object*> myObjects{{&electrons, &muons, &photons, &tp, &jets, &t1Met}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&electrons, &muons, &photons, &tp, &jets}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());
  /* BEGIN CUSTOM EventTP.cc.ctor */
  /* END CUSTOM */
}

panda::EventTP::EventTP(EventTP const& _src) :
  EventBase(_src),
  electrons(_src.electrons),
  muons(_src.muons),
  photons(_src.photons),
  tp(_src.tp),
  jets(_src.jets),
  t1Met(_src.t1Met),
  rho(_src.rho),
  sample(_src.sample)
{
  std::vector<Object*> myObjects{{&electrons, &muons, &photons, &tp, &jets, &t1Met}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&electrons, &muons, &photons, &tp, &jets}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());

  /* BEGIN CUSTOM EventTP.cc.copy_ctor */
  /* END CUSTOM */
}

panda::EventTP::~EventTP()
{
  /* BEGIN CUSTOM EventTP.cc.dtor */
  /* END CUSTOM */
}

panda::EventTP&
panda::EventTP::operator=(EventTP const& _src)
{
  EventBase::operator=(_src);

  /* BEGIN CUSTOM EventTP.cc.operator= */
  /* END CUSTOM */

  rho = _src.rho;
  sample = _src.sample;

  electrons = _src.electrons;
  muons = _src.muons;
  photons = _src.photons;
  tp = _src.tp;
  jets = _src.jets;
  t1Met = _src.t1Met;

  return *this;
}

void
panda::EventTP::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM EventTP.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::EventTP::dump(std::ostream& _out/* = std::cout*/) const
{
  EventBase::dump(_out);

  _out << "rho = " << rho << std::endl;
  _out << "sample = " << sample << std::endl;

  electrons.dump(_out);
  muons.dump(_out);
  photons.dump(_out);
  tp.dump(_out);
  jets.dump(_out);
  t1Met.dump(_out);

}
/*static*/
panda::utils::BranchList
panda::EventTP::getListOfBranches(Bool_t _direct/* = kFALSE*/)
{
  utils::BranchList blist;
  blist += EventBase::getListOfBranches(_direct);

  blist += {"rho", "sample"};
  if (!_direct) {
    blist += Electron::getListOfBranches().fullNames("electrons");
    blist += Muon::getListOfBranches().fullNames("muons");
    blist += Photon::getListOfBranches().fullNames("photons");
    blist += TPPair::getListOfBranches().fullNames("tp");
    blist += Jet::getListOfBranches().fullNames("jets");
    blist += RecoMet::getListOfBranches().fullNames("t1Met");
  }
  /* BEGIN CUSTOM EventTP.cc.getListOfBranches_ */
  /* END CUSTOM */
  return blist;
}

/*protected*/
void
panda::EventTP::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  EventBase::doSetStatus_(_tree, _branches);
  utils::setStatus(_tree, "", "rho", _branches);
  utils::setStatus(_tree, "", "sample", _branches);
}

/*protected*/
panda::utils::BranchList
panda::EventTP::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;
  blist += EventBase::doGetStatus_(_tree);

  blist.push_back(utils::getStatus(_tree, "", "rho"));
  blist.push_back(utils::getStatus(_tree, "", "sample"));
  return blist;
}

/*protected*/
panda::utils::BranchList
panda::EventTP::doGetBranchNames_() const
{
  return getListOfBranches(true);
}

/*protected*/
void
panda::EventTP::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  EventBase::doSetAddress_(_tree, _branches, _setStatus);

  utils::setAddress(_tree, "", "rho", &rho, _branches, _setStatus);
  utils::setAddress(_tree, "", "sample", &sample, _branches, _setStatus);
}

/*protected*/
void
panda::EventTP::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  EventBase::doBook_(_tree, _branches);

  utils::book(_tree, "", "rho", "", 'F', &rho, _branches);
  utils::book(_tree, "", "sample", "", 'i', &sample, _branches);
}

/*protected*/
void
panda::EventTP::doGetEntry_(TTree& _tree)
{
  EventBase::doGetEntry_(_tree);

  /* BEGIN CUSTOM EventTP.cc.doGetEntry_ */
  /* END CUSTOM */
}

void
panda::EventTP::doInit_()
{
  EventBase::doInit_();

  rho = 0.;
  sample = 0;
  /* BEGIN CUSTOM EventTP.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::EventTP::doUnlink_(TTree& _tree)
{
  EventBase::doUnlink_(_tree);

  /* BEGIN CUSTOM EventTP.cc.doUnlink_ */
  /* END CUSTOM */
}


/* BEGIN CUSTOM EventTP.cc.global */
/* END CUSTOM */
