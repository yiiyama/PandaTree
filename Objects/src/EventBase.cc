#include "../interface/EventBase.h"

panda::EventBase::EventBase() :
  TreeEntry()
{
  std::vector<Object*> myObjects{{&triggers}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
}

panda::EventBase::EventBase(EventBase const& _src) :
  TreeEntry(_src),
  triggers(_src.triggers),
  runNumber(_src.runNumber),
  lumiNumber(_src.lumiNumber),
  eventNumber(_src.eventNumber),
  isData(_src.isData),
  weight(_src.weight)
{
  std::vector<Object*> myObjects{{&triggers}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());

}

panda::EventBase&
panda::EventBase::operator=(EventBase const& _src)
{
  TreeEntry::operator=(_src);
  runNumber = _src.runNumber;
  lumiNumber = _src.lumiNumber;
  eventNumber = _src.eventNumber;
  isData = _src.isData;
  weight = _src.weight;

  run = _src.run;

  triggers = _src.triggers;

  return *this;
}

/*static*/
panda::utils::BranchList
panda::EventBase::getListOfBranches()
{
  utils::BranchList blist;
  blist += {"runNumber", "lumiNumber", "eventNumber", "isData", "weight"};
  blist += HLTBits::getListOfBranches().fullNames("triggers");
  return blist;
}
/*protected*/
void
panda::EventBase::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::setStatus(_tree, "", "runNumber", _branches);
  utils::setStatus(_tree, "", "lumiNumber", _branches);
  utils::setStatus(_tree, "", "eventNumber", _branches);
  utils::setStatus(_tree, "", "isData", _branches);
  utils::setStatus(_tree, "", "weight", _branches);
}

/*protected*/
panda::utils::BranchList
panda::EventBase::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;

  blist.push_back(utils::getStatus(_tree, "", "runNumber"));
  blist.push_back(utils::getStatus(_tree, "", "lumiNumber"));
  blist.push_back(utils::getStatus(_tree, "", "eventNumber"));
  blist.push_back(utils::getStatus(_tree, "", "isData"));
  blist.push_back(utils::getStatus(_tree, "", "weight"));
  return blist;
}

/*protected*/
panda::utils::BranchList
panda::EventBase::doGetBranchNames_() const
{
  return getListOfBranches();
}

/*protected*/
void
panda::EventBase::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  utils::setAddress(_tree, "", "runNumber", &runNumber, _branches, _setStatus);
  utils::setAddress(_tree, "", "lumiNumber", &lumiNumber, _branches, _setStatus);
  utils::setAddress(_tree, "", "eventNumber", &eventNumber, _branches, _setStatus);
  utils::setAddress(_tree, "", "isData", &isData, _branches, _setStatus);
  utils::setAddress(_tree, "", "weight", &weight, _branches, _setStatus);
}

/*protected*/
void
panda::EventBase::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::book(_tree, "", "runNumber", "", 'i', &runNumber, _branches);
  utils::book(_tree, "", "lumiNumber", "", 'i', &lumiNumber, _branches);
  utils::book(_tree, "", "eventNumber", "", 'i', &eventNumber, _branches);
  utils::book(_tree, "", "isData", "", 'O', &isData, _branches);
  utils::book(_tree, "", "weight", "", 'F', &weight, _branches);
}

/*protected*/
void
panda::EventBase::doGetEntry_(TTree& _tree, Long64_t _entry)
{
  /* BEGIN CUSTOM EventBase.cc.doGetEntry_ */
  run.update(runNumber, _tree);
  /* END CUSTOM */
}

void
panda::EventBase::doInit_()
{
  runNumber = 0;
  lumiNumber = 0;
  eventNumber = 0;
  isData = false;
  weight = 0.;
  /* BEGIN CUSTOM EventBase.cc.doInit_ */
  /* END CUSTOM */
}


/* BEGIN CUSTOM EventBase.cc.global */

Bool_t
panda::EventBase::triggerFired(UInt_t _token) const
{
  UInt_t idx(run.getTriggerIndex(_token));
  if (idx < run.triggerSize())
    return triggers.pass(idx);
  else
    return false;
}

/* END CUSTOM */
