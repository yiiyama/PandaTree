#include "../interface/Run.h"

panda::Run::Run() :
  TreeEntry()
{
}

panda::Run::Run(Run const& _src) :
  TreeEntry(_src),
  runNumber(_src.runNumber),
  hltMenu(_src.hltMenu),
  hltSize(_src.hltSize)
{

  /* BEGIN CUSTOM Run.cc.copy_ctor */
  loadTrigger_ = _src.loadTrigger_;
  registeredTriggers_ = _src.registeredTriggers_;
  triggerIndices_ = _src.triggerIndices_;

  if (_src.hlt.menu) {
    hlt.create();
    *hlt.menu = *_src.hlt.menu;
    hlt.paths->assign(_src.hlt.paths->begin(), _src.hlt.paths->end());
  }
  /* END CUSTOM */
}

panda::Run&
panda::Run::operator=(Run const& _src)
{
  TreeEntry::operator=(_src);

  /* BEGIN CUSTOM Run.cc.operator= */
  loadTrigger_ = _src.loadTrigger_;
  registeredTriggers_ = _src.registeredTriggers_;
  triggerIndices_ = _src.triggerIndices_;

  if (!hlt.menu && _src.hlt.menu)
    hlt.create();

  if (hlt.menu && *_src.hlt.menu != *hlt.menu) {
    *hlt.menu = *_src.hlt.menu;
    hlt.paths->assign(_src.hlt.paths->begin(), _src.hlt.paths->end());
  }
  /* END CUSTOM */

  runNumber = _src.runNumber;
  hltMenu = _src.hltMenu;
  hltSize = _src.hltSize;

  return *this;
}


void
panda::Run::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM Run.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::Run::dump(std::ostream& _out/* = std::cout*/) const
{
  _out << "runNumber = " << runNumber << std::endl;
  _out << "hltMenu = " << hltMenu << std::endl;
  _out << "hltSize = " << hltSize << std::endl;

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
panda::Run::doGetEntry_(TTree& _tree, Long64_t _entry)
{
  /* BEGIN CUSTOM Run.cc.doGetEntry_ */
  /* END CUSTOM */
}

void
panda::Run::doInit_()
{
  runNumber = 0;
  hltMenu = 0;
  hltSize = 0;
  /* BEGIN CUSTOM Run.cc.doInit_ */
  /* END CUSTOM */
}


/* BEGIN CUSTOM Run.cc.global */

#include "TFile.h"
#include "TKey.h"

void
panda::Run::setLoadTrigger(Bool_t _l/* = kTRUE*/)
{
  loadTrigger_ = _l;
  if (!_l) {
    hlt.destroy();
  }
}

UInt_t
panda::Run::registerTrigger(char const* _path)
{
  loadTrigger_ = true;

  TString path(_path);
  path += "_v";

  auto itr(std::find(registeredTriggers_.begin(), registeredTriggers_.end(), path));
  if (itr == registeredTriggers_.end()) {
    registeredTriggers_.push_back(path);

    // need to update the input
    hlt.destroy();

    return registeredTriggers_.size() - 1;
  }
  else
    return itr -registeredTriggers_.begin();
}

char const*
panda::Run::triggerMenu() const
{
  if (!hlt.menu)
    throw std::runtime_error("Trigger menu is not read from the input.");

  return *hlt.menu;
}

std::vector<TString> const&
panda::Run::triggerPaths() const
{
  if (!hlt.paths)
    throw std::runtime_error("Trigger menu is not read from the input.");

  return *hlt.paths;
}

void
panda::Run::update(UInt_t _runNumber, TTree& _eventTree)
{
  bool needRead(false);

  if (_runNumber != runNumber) {
    // gets overwritten again later, but if !loadTrigger_ this is the only place to set run number
    runNumber = _runNumber;
    needRead = true;
  }

  if (!loadTrigger_)
    return;

  if (!hlt.menu)
    needRead = true;

  if (!needRead)
    return;

  auto* inputFile(_eventTree.GetCurrentFile());
  if (!inputFile)
    return;

  // read out runs and hlt trees (using GetKey to create a "fresh" object - Get can fetch an in-memory object that may already be in use)
  auto* key(inputFile->GetKey("runs"));
  if (!key) {
    std::cerr << "File " << inputFile->GetName() << " does not have a run tree" << std::endl;
    throw std::runtime_error("InputError");
  }
  auto* runTree(static_cast<TTree*>(key->ReadObj()));

  setAddress(*runTree);

  long iEntry(0);
  while (runTree->GetEntry(iEntry++) > 0) {
    if (runNumber == _runNumber)
      break;
  }
  if (iEntry == runTree->GetEntries()+1) {
    std::cerr << "Run " << _runNumber << " not found in " << inputFile->GetName() << std::endl;
    throw std::runtime_error("InputError");
  }

  delete runTree;

  key = inputFile->GetKey("hlt");
  if (!key) {
    std::cerr << "File " << inputFile->GetName() << " does not have an hlt tree" << std::endl;
    throw std::runtime_error("InputError");
  }
  auto* hltTree(static_cast<TTree*>(key->ReadObj()));

  if (!hlt.menu)
    hlt.create();

  hltTree->SetBranchAddress("menu", &hlt.menu);
  hltTree->SetBranchAddress("paths", &hlt.paths);

  if (hltTree->GetEntry(hltMenu) <= 0) {
    std::cerr << "Failed to read HLT menu " << hltMenu << " from " << inputFile->GetName() << std::endl;
    throw std::runtime_error("InputError");
  }

  delete hltTree;

  triggerIndices_.clear();
  // for each registered path, find the matching trigger in the given menu
  for (auto& path : registeredTriggers_) {
    unsigned iT(0);
    for (; iT != hlt.paths->size(); ++iT) {
      if ((*hlt.paths)[iT].BeginsWith(path)) {
        triggerIndices_.push_back(iT);
        break;
      }
    }
    if (iT == hlt.paths->size())
      triggerIndices_.push_back(-1);
  }
}

/* END CUSTOM */
