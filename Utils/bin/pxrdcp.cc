#include "PandaTree/Framework/interface/IOUtils.h"
#include "PandaTree/Objects/interface/Event.h"
#include "PandaTree/Objects/interface/Run.h"

#include "TFile.h"
#include "TTree.h"
#include "TKey.h"
#include "TString.h"
#include "TObjArray.h"
#include "TSystem.h"

#include <iostream>

void
copyTree(TTree& _tree, panda::utils::BranchList const& _blist, TFile& _outputFile)
{
  for (auto& bname : _blist) {
    TString name(bname);
    if (bname.isVeto())
      name = name(1, name.Length());

    if (!_tree.GetBranch(name))
      continue;

    _tree.SetBranchStatus(name, !bname.isVeto());
  }

  _outputFile.cd();
  auto* clone(_tree.CloneTree(-1, "fast"));
  clone->Write();
  delete clone;
}

int
main(int _argc, char const* _argv[])
{
  int narg(_argc - 1);
  char const** argv(0);
  bool force(false);

  if (narg > 0) {
    if (std::strcmp(_argv[1], "-f") == 0) {
      force = true;
      --narg;
      argv = &_argv[2];
    }
    else
      argv = &_argv[1];
  }

  if (narg < 2) {
    std::cerr << "Usage: pxrdcp [-f] SOURCE OUTPUT [BRANCHES [-r|--run BRANCHES]]" << std::endl;
    return 1;
  }

  auto* source(TFile::Open(*argv));
  if (!source || source->IsZombie()) {
    std::cerr << "Failed to open source " << *argv << std::endl;
    return 1;
  }
  
  auto* eventTree(static_cast<TTree*>(source->Get("events")));
  if (!eventTree) {
    std::cerr << "Source file " << *argv << " is not a panda file." << std::endl;
    return 1;
  }

  auto* runTree(static_cast<TTree*>(source->Get("runs")));

  --narg;
  ++argv;

  FileStat_t stat;
  if (gSystem->GetPathInfo(*argv, stat) == 0 && !force) {
    std::cerr << "Target file " << *argv << " already exists." << std::endl;
    return 1;
  }

  auto* outputFile(TFile::Open(*argv, "recreate"));

  panda::utils::BranchList blist(panda::Event::getListOfBranches());

  while (--narg != 0) {
    TString arg(*(++argv));

    if (arg == "-r" || arg == "--run") {
      copyTree(*eventTree, blist, *outputFile);
      delete eventTree;
      eventTree = 0;

      if (runTree)
        blist = panda::Run::getListOfBranches();

      continue;
    }

    blist.emplace_back(arg);
  }

  if (eventTree) {
    copyTree(*eventTree, blist, *outputFile);
    blist = {"*"};
  }
  
  if (runTree)
    copyTree(*runTree, blist, *outputFile);

  // find the latest keys and copy

  TObjArray keys;
  for (auto* keyobj : *source->GetListOfKeys()) {
    TString name(keyobj->GetName());
    if (name == "events" || name == "runs")
      continue;

    auto* key(static_cast<TKey*>(keyobj));
    auto* old(static_cast<TKey*>(keys.FindObject(name)));
    if (old && old->GetCycle() < key->GetCycle())
      keys.Remove(old);

    keys.Add(keyobj);
  }

  for (auto* keyobj : keys) {
    auto* obj(static_cast<TKey*>(keyobj)->ReadObj());
    outputFile->cd();
    obj->Write();
    delete obj;
  }

  delete outputFile;
  delete source;

  return 0;
}
