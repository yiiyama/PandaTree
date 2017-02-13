#include "../interface/Run.h"

panda::Run::Run() :
  TreeEntry("Run")
{
}

panda::Run::Run(Run const& _src) :
  TreeEntry(_src.getName()),
  runNumber(_src.runNumber),
  hltMenu(_src.hltMenu)
{
}

panda::Run&
panda::Run::operator=(Run const& _src)
{
  runNumber = _src.runNumber;
  hltMenu = _src.hltMenu;

  return *this;
}

/*static*/
panda::utils::BranchList
panda::Run::getListOfBranches()
{
  utils::BranchList blist;
  blist += {"runNumber", "hltMenu"};
  return blist;
}
/*protected*/
void
panda::Run::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::setStatus(_tree, "", "runNumber", _branches);
  utils::setStatus(_tree, "", "hltMenu", _branches);
}

/*protected*/
panda::utils::BranchList
panda::Run::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;

  blist.push_back(utils::getStatus(_tree, "", "runNumber"));
  blist.push_back(utils::getStatus(_tree, "", "hltMenu"));
  return blist;
}

/*protected*/
panda::utils::BranchList
panda::Run::doGetBranchNames_() const
{
  return getListOfBranches();
}

/*protected*/
void
panda::Run::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  utils::setAddress(_tree, "", "runNumber", &runNumber, _branches, _setStatus);
  utils::setAddress(_tree, "", "hltMenu", &hltMenu, _branches, _setStatus);
}

/*protected*/
void
panda::Run::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::book(_tree, "", "runNumber", "", 'i', &runNumber, _branches);
  utils::book(_tree, "", "hltMenu", "", 'i', &hltMenu, _branches);
}

/*protected*/
void
panda::Run::doReleaseTree_(TTree& _tree)
{
  utils::resetAddress(_tree, "", "runNumber");
  utils::resetAddress(_tree, "", "hltMenu");
}

void
panda::Run::doInit_()
{
  runNumber = 0;
  hltMenu = 0;
}


/* BEGIN CUSTOM Run.cc.global */
/* END CUSTOM */
