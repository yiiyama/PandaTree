#include "../interface/FileMerger.h"
#include "../../Objects/interface/Event.h"
#include "../../Objects/interface/Run.h"

#include "TFile.h"
#include "TSystem.h"
#include "TRegexp.h"

#include <iostream>

void
panda::FileMerger::addInput(char const* _path)
{
  // Implementation from TChain::Add

  TString basename(_path);

  // case with one single file
  if (!basename.MaybeWildcard()) {
    if (printLevel_ >= 1)
      std::cout << " " << basename << std::endl;
    paths_.push_back(basename);
    return;
  }
 
  // wildcarding used in name

  Int_t slashpos = basename.Last('/');
  TString directory;
  if (slashpos>=0) {
    directory = basename(0,slashpos); // Copy the directory name
    basename.Remove(0,slashpos+1);      // and remove it from basename
  } else {
    directory = gSystem->UnixPathName(gSystem->WorkingDirectory());
  }
 
  const char *file;
  const char *epath = gSystem->ExpandPathName(directory.Data());
  void *dir = gSystem->OpenDirectory(epath);
  delete [] epath;
  if (dir) {
    TRegexp re(basename,kTRUE);
    while ((file = gSystem->GetDirEntry(dir))) {
      if (!strcmp(file,".") || !strcmp(file,"..")) continue;
      TString s = file;
      if ( (basename!=file) && s.Index(re) == kNPOS) continue;
      if (printLevel_ >= 1)
        std::cout << " " << directory << "/" << s << std::endl;
      paths_.push_back(directory + "/" + s);
    }
    gSystem->FreeDirectory(dir);
  }
}

void
panda::FileMerger::selectBranches(utils::BranchList const& _blist, Bool_t _onRead/* = kFALSE*/, TreeType _ttype/* = kEvent*/)
{
  branchList_[_ttype] = _blist;
  applyBranchListOnRead_[_ttype] = _onRead;
}

unsigned
panda::FileMerger::merge(char const* _outPath, long _nEvents/* = -1*/)
{
  auto* outputFile(TFile::Open(_outPath, "recreate"));
  if (!outputFile || outputFile->IsZombie())
    throw std::runtime_error("Invalid path");

  // same run can appear in multiple files
  // assuming everything except the hlt index pointer is identical between these entries
  // we save the first occurence (file index, entry number) and read them out later
  // (currently Run only has the run number and HLT index, so this is a total overkill)
  std::map<UInt_t, std::pair<unsigned, long>> runSources{};
  utils::BranchList runBranches;
  std::map<UInt_t, unsigned> runToMenuMap{};
  std::vector<TString> hltMenuList{};
  std::vector<std::vector<TString>> hltPathsList{};

  panda::Event* inEvent(0);

  // will book only at the first valid input
  TTree* outEventTree(0);
  if (!outEvent_) {
    outEvent_ = new panda::Event;
    ownsOutEvent_ = true;
    inEvent = static_cast<panda::Event*>(outEvent_);
  }
  else {
    // if the output event object is passed from outside, we cannot assume that it's a panda::Event
    inEvent = new panda::Event;
  }

  inEvent->run.hlt.create();

  // loop over files to
  // . fill events (simple)
  // . collect run info
  // . collect hlt info

  long nTotal(0);
  long nWritten(0);

  for (unsigned iS(0); iS != paths_.size(); ++iS) {
    auto& path(paths_[iS]);

    if (printLevel_ >= 2)
      std::cout << "Opening " << path << std::endl;

    auto* source(TFile::Open(path));
    if (!source || source->IsZombie()) {
      std::cerr << "Skipping file " << path << std::endl;
      delete source;
      continue;
    }

    auto* inEventTree(static_cast<TTree*>(source->Get("events")));
    if (!inEventTree) {
      std::cerr << "File " << path << " is not a valid input" << std::endl;
      throw std::runtime_error("events");
    }

    if (!outEventTree) {
      // pick up everything that is not events, runs, or hlt

      std::set<TString> keyNames;
      for (auto* key : *source->GetListOfKeys()) {
        TString keyName(key->GetName());

        if (keyNames.count(keyName) != 0)
          continue;

        if (keyName == "events" || keyName == "runs" || keyName == "hlt")
          continue;

        keyNames.insert(keyName);

        outputFile->cd();
        auto* obj(source->Get(keyName));
        obj->Write();
        delete obj;
      }

      // list of branches in the original tree filtered by branchList_
      auto blist(inEvent->getStatus(*inEventTree));
      blist += branchList_[kEvent];

      outputFile->cd();
      outEventTree = new TTree("events", "Events");
      outEvent_->book(*outEventTree, blist);
    }

    // fill events
    if (applyBranchListOnRead_[kEvent]) {
      utils::BranchList blist({"*"});
      blist += branchList_[kEvent];
      inEvent->setAddress(*inEventTree, blist, true);
    }
    else
      inEvent->setAddress(*inEventTree);

    std::set<UInt_t> savedRuns;

    if (printLevel_ >= 3)
      std::cout << "Processing events" << std::endl;
    
    long iEntry(0);
    while (nTotal != _nEvents && inEvent->getEntry(iEntry++) > 0) {
      switch (printLevel_) {
      case 0:
        break;
      case 1:
        if (nTotal % 100000 != 0)
          break;
      case 2:
        if (nTotal % 1000 != 0)
          break;
      case 3:
        if (nTotal % 10 != 0)
          break;
      default:
        std::cout << "\rProcessed " << nTotal << " events";
        std::cout.flush();
      }

      ++nTotal;

      if (skimFunction_ && !skimFunction_(*inEvent))
        continue;

      // If outEvent is supplied externally, values from the inEvent must be copied within the skimFunction
      outEventTree->Fill();
      ++nWritten;

      savedRuns.insert(inEvent->runNumber);
    }

    inEvent->releaseTree(*inEventTree)

    // inEvent->run was not used during the event loop because no trigger information was requested
    // Now we process the runs

    auto* inRunTree(static_cast<TTree*>(source->Get("runs")));

    if (printLevel_ >= 3)
      std::cout << "Run tree found" << std::endl;

    if (inRunTree) {
      // collect HLT and run info
      
      auto& run(inEvent->run);

      if (runBranches.size() == 0) {
        runBranches = run.getStatus(*inRunTree);
        runBranches += branchList_[kRun];
      }

      if (applyBranchListOnRead_[kRun])
        run.setAddress(*inRunTree, branchList_[kRun]);
      else
        run.setAddress(*inRunTree);

      auto* inHLTTree(static_cast<TTree*>(source->Get("hlt")));

      if (inHLTTree) {
        if (printLevel_ >= 3)
          std::cout << "HLT tree found" << std::endl;

        inHLTTree->SetBranchAddress("menu", &run.hlt.menu);
        inHLTTree->SetBranchAddress("paths", &run.hlt.paths);
      }

      if (printLevel_ >= 3)
        std::cout << "Processing runs" << std::endl;

      iEntry = 0;
      while (run.getEntry(iEntry++) > 0) {
        if (savedRuns.count(run.runNumber) == 0)
          continue;

        if (runSources.count(run.runNumber) == 0)
          runSources.emplace(run.runNumber, std::make_pair(iS, iEntry - 1));

        if (inHLTTree) {
          inHLTTree->GetEntry(run.hltMenu);

          auto mItr(std::find(hltMenuList.begin(), hltMenuList.end(), *hltMenu));
          if (mItr == hltMenuList.end()) {
            hltMenuList.push_back(*hltMenu);
            hltPathsList.emplace_back(hltPaths->begin(), hltPaths->end());
          }

          unsigned menuId(mItr - hltMenuList.begin());

          auto hltItr(runToMenuMap.find(run.runNumber));
          if (hltItr == runToMenuMap.end())
            runToMenuMap.emplace(run.runNumber, menuId);
          else if (hltItr->second != menuId) {
            std::cerr << "Inconsistent HLT menu found for run " << run.runNumber << " in file " << path << std::endl;
            throw std::runtime_error("HLT");
          }
        }
      }

      run.releaseTree(*inRunTree);
    }
    else if (runSources.size() != 0) {
      std::cerr << "Run tree missing in file " << path << std::endl;
      throw std::runtime_error("runs");
    }

    delete source;

    if (printLevel_ >= 2)
      std::cout << "Closed " << path << std::endl;
  }

  std::cout << "Number of events in : " << nTotal << std::endl;
  std::cout << "Number of events out: " << nWritten << std::endl;

  if (outEventTree) {
    outputFile->cd();
    outEventTree->Write();
    outEvent_->releaseTree(*outEventTree);
    delete outEventTree;
  }

  if (runSources.size() != 0) {
    auto& run(inEvent_->run);

    outputFile->cd();
    TTree* outRunTree(new TTree("runs", "Runs"));
    run.book(*outRunTree, runBranches);

    for (auto& runSource : runSources) {
      auto* source(TFile::Open(paths_[runSource.second.first]));

      auto* inRunTree(static_cast<TTree*>(source->Get("runs")));
      run.setAddress(*inRunTree);

      inRunTree->GetEntry(runSource.second.second);

      if (runToMenuMap.size() != 0)
        run.hltMenu = runToMenuMap[runSource.first];

      outRunTree->Fill();

      run.releaseTree(*inRunTree);
      delete source;
    }

    outputFile->cd();
    outRunTree->Write();

    run.releaseTree(*outRunTree);

    delete outRunTree;

    if (runToMenuMap.size() != 0) {
      outputFile->cd();
      TTree* outHLTTree(new TTree("hlt", "HLT"));

      outHLTTree->Branch("menu", "TString", &run.hlt.menu);
      outHLTTree->Branch("paths", "std::vector<TString>", &run.hlt.paths);

      for (unsigned iH(0); iH != hltMenuList.size(); ++iH) {
        *hltMenu = hltMenuList[iH];
        auto& paths(hltPathsList[iH]);
        hltPaths->assign(paths.begin(), paths.end());

        outHLTTree->Fill();
      }

      outputFile->cd();
      outHLTTree->Write();

      delete outHLTTree;
    }
  }

  delete outputFile;

  if (ownsOutEvent_) {
    delete outEvent_;
    outEvent_ = 0;
    ownsOutEvent_ = false;
  }
  else
    delete inEvent;

  return nWritten;
}

void
panda::FileMerger::setOutEvent(panda::EventBase* _evt)
{
  if (ownsOutEvent_)
    delete outEvent_;

  outEvent_ = _evt;
  ownsOutEvent_ = false;
}
