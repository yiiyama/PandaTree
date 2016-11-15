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

void
panda::Run::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  utils::setStatus(_tree, "", "run", _status, _branches);
  utils::setStatus(_tree, "", "hltMenu", _status, _branches);
}

void
panda::Run::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  TreeEntry::setAddress(_tree, _branches);

  utils::setStatusAndAddress(_tree, "", "run", &run, _branches);
  utils::setStatusAndAddress(_tree, "", "hltMenu", &hltMenu, _branches);
}

void
panda::Run::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  utils::book(_tree, "", "run", "", 'i', &run, _branches);
  utils::book(_tree, "", "hltMenu", "", 'i', &hltMenu, _branches);
}

void
panda::Run::init()
{
  run = 0;
  hltMenu = 0;
}

/* BEGIN CUSTOM */
/* END CUSTOM */
