#include "../interface/Run.h"

panda::Run::Run() :
  TreeEntry()
{
}

panda::Run::Run(Run const& _src) :
  TreeEntry(),
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

void
panda::Run::init()
{
  runNumber = 0;
  hltMenu = 0;
}

/*protected*/
void
panda::Run::doSetStatus_(TTree& _tree, Bool_t _status, utils::BranchList const& _branches)
{
  utils::setStatus(_tree, "", "runNumber", _status, _branches);
  utils::setStatus(_tree, "", "hltMenu", _status, _branches);
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
}


/* BEGIN CUSTOM Run.cc.global */
/* END CUSTOM */
/*protected*/
void
panda::Run::doPrepareGetEntry_(Long64_t _iEntry)
{
}

