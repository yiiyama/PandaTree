#include "../interface/EventTPME.h"

panda::EventTPME::EventTPME() :
  EventTP()
{
  std::vector<Object*> myObjects{{&tags, &probes}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&tags, &probes}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());
  /* BEGIN CUSTOM EventTPME.cc.ctor */
  /* END CUSTOM */
}

panda::EventTPME::EventTPME(EventTPME const& _src) :
  EventTP(_src),
  tags(_src.tags),
  probes(_src.probes)
{
  std::vector<Object*> myObjects{{&tags, &probes}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&tags, &probes}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());
  /* BEGIN CUSTOM EventTPME.cc.copy_ctor */
  /* END CUSTOM */
}

panda::EventTPME::~EventTPME()
{
  /* BEGIN CUSTOM EventTPME.cc.dtor */
  /* END CUSTOM */
}

panda::EventTPME&
panda::EventTPME::operator=(EventTPME const& _src)
{
  EventTP::operator=(_src);

  /* BEGIN CUSTOM EventTPME.cc.operator= */
  /* END CUSTOM */

  tags = _src.tags;
  probes = _src.probes;

  return *this;
}

void
panda::EventTPME::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM EventTPME.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::EventTPME::dump(std::ostream& _out/* = std::cout*/) const
{
  EventTP::dump(_out);

  tags.dump(_out);
  probes.dump(_out);

}
/*static*/
panda::utils::BranchList
panda::EventTPME::getListOfBranches(Bool_t _direct/* = kFALSE*/)
{
  utils::BranchList blist;
  blist += EventTP::getListOfBranches(_direct);

  blist += {};
  if (!_direct) {
    blist += Muon::getListOfBranches().fullNames("tags");
    blist += Electron::getListOfBranches().fullNames("probes");
  }
  /* BEGIN CUSTOM EventTPME.cc.getListOfBranches_ */
  /* END CUSTOM */
  return blist;
}

/*protected*/
void
panda::EventTPME::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  EventTP::doSetStatus_(_tree, _branches);
}

/*protected*/
panda::utils::BranchList
panda::EventTPME::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;
  blist += EventTP::doGetStatus_(_tree);

  return blist;
}

/*protected*/
panda::utils::BranchList
panda::EventTPME::doGetBranchNames_() const
{
  return getListOfBranches(true);
}

/*protected*/
void
panda::EventTPME::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  EventTP::doSetAddress_(_tree, _branches, _setStatus);

}

/*protected*/
void
panda::EventTPME::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  EventTP::doBook_(_tree, _branches);

}

/*protected*/
void
panda::EventTPME::doGetEntry_(TTree& _tree)
{
  EventTP::doGetEntry_(_tree);

  /* BEGIN CUSTOM EventTPME.cc.doGetEntry_ */
  /* END CUSTOM */
}

void
panda::EventTPME::doInit_()
{
  EventTP::doInit_();

  /* BEGIN CUSTOM EventTPME.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::EventTPME::doUnlink_(TTree& _tree)
{
  EventTP::doUnlink_(_tree);

  /* BEGIN CUSTOM EventTPME.cc.doUnlink_ */
  /* END CUSTOM */
}


/* BEGIN CUSTOM EventTPME.cc.global */
/* END CUSTOM */
