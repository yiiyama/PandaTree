#include "../interface/EventAnalysis.h"

panda::EventAnalysis::EventAnalysis() :
  Event()
{
  std::vector<Object*> myObjects{{&genParticlesU}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&genParticlesU}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());

  genParticlesU.data.parentContainer_ = &genParticlesU;
  /* BEGIN CUSTOM EventAnalysis.cc.ctor */
  /* END CUSTOM */
}

panda::EventAnalysis::EventAnalysis(EventAnalysis const& _src) :
  Event(_src),
  genParticlesU(_src.genParticlesU)
{
  std::vector<Object*> myObjects{{&genParticlesU}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&genParticlesU}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());

  genParticlesU.data.parentContainer_ = &genParticlesU;
  /* BEGIN CUSTOM EventAnalysis.cc.copy_ctor */
  /* END CUSTOM */
}

panda::EventAnalysis::~EventAnalysis()
{
  /* BEGIN CUSTOM EventAnalysis.cc.dtor */
  /* END CUSTOM */
}

panda::EventAnalysis&
panda::EventAnalysis::operator=(EventAnalysis const& _src)
{
  Event::operator=(_src);

  /* BEGIN CUSTOM EventAnalysis.cc.operator= */
  /* END CUSTOM */

  genParticlesU = _src.genParticlesU;

  genParticlesU.data.parentContainer_ = &genParticlesU;

  return *this;
}

void
panda::EventAnalysis::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM EventAnalysis.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::EventAnalysis::dump(std::ostream& _out/* = std::cout*/) const
{
  Event::dump(_out);

  genParticlesU.dump(_out);

}
/*static*/
panda::utils::BranchList
panda::EventAnalysis::getListOfBranches(Bool_t _direct/* = kFALSE*/)
{
  utils::BranchList blist;
  blist += Event::getListOfBranches(_direct);

  blist += {};
  if (!_direct) {
    blist += UnpackedGenParticle::getListOfBranches().fullNames("genParticlesU");
  }
  /* BEGIN CUSTOM EventAnalysis.cc.getListOfBranches_ */
  /* END CUSTOM */
  return blist;
}

/*protected*/
void
panda::EventAnalysis::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  Event::doSetStatus_(_tree, _branches);
}

/*protected*/
panda::utils::BranchList
panda::EventAnalysis::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;
  blist += Event::doGetStatus_(_tree);

  return blist;
}

/*protected*/
panda::utils::BranchList
panda::EventAnalysis::doGetBranchNames_() const
{
  return getListOfBranches(true);
}

/*protected*/
void
panda::EventAnalysis::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  Event::doSetAddress_(_tree, _branches, _setStatus);

}

/*protected*/
void
panda::EventAnalysis::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  Event::doBook_(_tree, _branches);

}

/*protected*/
void
panda::EventAnalysis::doGetEntry_(TTree& _tree)
{
  Event::doGetEntry_(_tree);

  /* BEGIN CUSTOM EventAnalysis.cc.doGetEntry_ */
  /* END CUSTOM */
}

void
panda::EventAnalysis::doInit_()
{
  Event::doInit_();

  /* BEGIN CUSTOM EventAnalysis.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::EventAnalysis::doUnlink_(TTree& _tree)
{
  Event::doUnlink_(_tree);

  /* BEGIN CUSTOM EventAnalysis.cc.doUnlink_ */
  /* END CUSTOM */
}



/* BEGIN CUSTOM EventAnalysis.cc.global */
/* END CUSTOM */
