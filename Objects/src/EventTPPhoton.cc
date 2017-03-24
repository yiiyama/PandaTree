#include "../interface/EventTPPhoton.h"

panda::EventTPPhoton::EventTPPhoton() :
  EventBase()
{
  std::vector<Object*> myObjects{{&tp, &tags, &looseTags, &probes, &jets, &t1Met}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&tp, &tags, &looseTags, &probes, &jets}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());
}

panda::EventTPPhoton::EventTPPhoton(EventTPPhoton const& _src) :
  EventBase(_src),
  tp(_src.tp),
  tags(_src.tags),
  looseTags(_src.looseTags),
  probes(_src.probes),
  jets(_src.jets),
  t1Met(_src.t1Met),
  npv(_src.npv),
  npvTrue(_src.npvTrue),
  rho(_src.rho),
  sample(_src.sample)
{
  std::vector<Object*> myObjects{{&tp, &tags, &looseTags, &probes, &jets, &t1Met}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&tp, &tags, &looseTags, &probes, &jets}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());

  /* BEGIN CUSTOM EventTPPhoton.cc.copy_ctor */
  /* END CUSTOM */
}

panda::EventTPPhoton&
panda::EventTPPhoton::operator=(EventTPPhoton const& _src)
{
  EventBase::operator=(_src);

  /* BEGIN CUSTOM EventTPPhoton.cc.operator= */
  /* END CUSTOM */

  npv = _src.npv;
  npvTrue = _src.npvTrue;
  rho = _src.rho;
  sample = _src.sample;

  tp = _src.tp;
  tags = _src.tags;
  looseTags = _src.looseTags;
  probes = _src.probes;
  jets = _src.jets;
  t1Met = _src.t1Met;

  return *this;
}


void
panda::EventTPPhoton::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM EventTPPhoton.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::EventTPPhoton::dump(std::ostream& _out/* = std::cout*/) const
{
  EventBase::dump(_out);

  _out << "npv" << npv << std::endl;
  _out << "npvTrue" << npvTrue << std::endl;
  _out << "rho" << rho << std::endl;
  _out << "sample" << sample << std::endl;

  tp.dump(_out);
  tags.dump(_out);
  looseTags.dump(_out);
  probes.dump(_out);
  jets.dump(_out);
  t1Met.dump(_out);

}
/*static*/
panda::utils::BranchList
panda::EventTPPhoton::getListOfBranches()
{
  utils::BranchList blist;
  blist += EventBase::getListOfBranches();

  blist += {"npv", "npvTrue", "rho", "sample"};
  blist += TPPair::getListOfBranches().fullNames("tp");
  blist += Lepton::getListOfBranches().fullNames("tags");
  blist += Lepton::getListOfBranches().fullNames("looseTags");
  blist += XPhoton::getListOfBranches().fullNames("probes");
  blist += Jet::getListOfBranches().fullNames("jets");
  blist += RecoMet::getListOfBranches().fullNames("t1Met");
  return blist;
}

/*protected*/
void
panda::EventTPPhoton::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  EventBase::doSetStatus_(_tree, _branches);
  utils::setStatus(_tree, "", "npv", _branches);
  utils::setStatus(_tree, "", "npvTrue", _branches);
  utils::setStatus(_tree, "", "rho", _branches);
  utils::setStatus(_tree, "", "sample", _branches);
}

/*protected*/
panda::utils::BranchList
panda::EventTPPhoton::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;
  blist += EventBase::doGetStatus_(_tree);

  blist.push_back(utils::getStatus(_tree, "", "npv"));
  blist.push_back(utils::getStatus(_tree, "", "npvTrue"));
  blist.push_back(utils::getStatus(_tree, "", "rho"));
  blist.push_back(utils::getStatus(_tree, "", "sample"));
  return blist;
}

/*protected*/
panda::utils::BranchList
panda::EventTPPhoton::doGetBranchNames_() const
{
  return getListOfBranches();
}

/*protected*/
void
panda::EventTPPhoton::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  EventBase::doSetAddress_(_tree, _branches, _setStatus);

  utils::setAddress(_tree, "", "npv", &npv, _branches, _setStatus);
  utils::setAddress(_tree, "", "npvTrue", &npvTrue, _branches, _setStatus);
  utils::setAddress(_tree, "", "rho", &rho, _branches, _setStatus);
  utils::setAddress(_tree, "", "sample", &sample, _branches, _setStatus);
}

/*protected*/
void
panda::EventTPPhoton::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  EventBase::doBook_(_tree, _branches);

  utils::book(_tree, "", "npv", "", 's', &npv, _branches);
  utils::book(_tree, "", "npvTrue", "", 's', &npvTrue, _branches);
  utils::book(_tree, "", "rho", "", 'F', &rho, _branches);
  utils::book(_tree, "", "sample", "", 'i', &sample, _branches);
}

/*protected*/
void
panda::EventTPPhoton::doGetEntry_(TTree& _tree, Long64_t _entry)
{
  EventBase::doGetEntry_(_tree, _entry);

  /* BEGIN CUSTOM EventTPPhoton.cc.doGetEntry_ */
  /* END CUSTOM */
}

void
panda::EventTPPhoton::doInit_()
{
  EventBase::doInit_();

  npv = 0;
  npvTrue = 0;
  rho = 0.;
  sample = 0;
  /* BEGIN CUSTOM EventTPPhoton.cc.doInit_ */
  /* END CUSTOM */
}


/* BEGIN CUSTOM EventTPPhoton.cc.global */
panda::EventTPPhoton&
panda::EventTPPhoton::operator=(Event const& _src)
{
  EventBase::operator=(_src);

  npv = _src.npv;
  npvTrue = _src.npvTrue;
  rho = _src.rho;

  jets = _src.chsAK4Jets;
  t1Met = _src.pfMet;

  jets.data.matchedGenJetContainer_ = 0;
  jets.data.constituentsContainer_ = 0;

  return *this;
}

panda::EventTPPhoton&
panda::EventTPPhoton::operator=(EventMonophoton const& _src)
{
  EventBase::operator=(_src);

  npv = _src.npv;
  npvTrue = _src.npvTrue;
  rho = _src.rho;

  jets = _src.jets;
  t1Met = _src.t1Met;

  jets.data.matchedGenJetContainer_ = 0;
  jets.data.constituentsContainer_ = 0;

  return *this;
}
/* END CUSTOM */
