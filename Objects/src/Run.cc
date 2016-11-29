#include "../interface/Run.h"

panda::Run::Run() :
  TreeEntry()
{
}

panda::Run::Run(Run const& _src) :
  TreeEntry(),
  run(_src.run),
  hltMenu(_src.hltMenu)
{
}

panda::Run&
panda::Run::operator=(Run const& _src)
{
  run = _src.run;
  hltMenu = _src.hltMenu;

  return *this;
}

void
panda::Run::init()
{
  run = 0;
  hltMenu = 0;
}

/*protected*/
void
panda::Run::doSetStatus_(TTree& _tree, Bool_t _status, utils::BranchList const& _branches)
{
  utils::setStatus(_tree, "", "run", _status, _branches);
  utils::setStatus(_tree, "", "hltMenu", _status, _branches);
}

/*protected*/
void
panda::Run::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  utils::setAddress(_tree, "", "run", &run, _branches, _setStatus);
  utils::setAddress(_tree, "", "hltMenu", &hltMenu, _branches, _setStatus);

  sizeBranches_.clear();
}

/*protected*/
void
panda::Run::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::book(_tree, "", "run", "", 'i', &run, _branches);
  utils::book(_tree, "", "hltMenu", "", 'i', &hltMenu, _branches);
}

/*protected*/
void
panda::Run::doReleaseTree_(TTree& _tree)
{
}


/* BEGIN CUSTOM */
/* END CUSTOM */
/*protected*/
void
panda::Run::adjustCollectionSizes_()
{
}

