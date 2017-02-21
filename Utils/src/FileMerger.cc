#include "../interface/FileMerger.h"
#include "../../Objects/interface/Event.h"
#include "../../Objects/interface/Run.h"

#include "TFile.h"
#include "TSystem.h"
#include "TRegexp.h"
#include "TError.h"
#include "TEntryList.h"

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

  panda::Event inEvent;

  // will book only at the first valid input
  TTree* outEventTree(0);
  if (!extOutEvent_) {
    if (printLevel_ >= 2)
      std::cout << "Using the default output event" << std::endl;
    outEvent_ = &inEvent;
  }

  inEvent.run.hlt.create();

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

    TFile* source(0);

    if (timeout_ > 0) {
      // silence the TFile error message
      auto originalErrorIgnoreLevel(gErrorIgnoreLevel);
      gErrorIgnoreLevel = kError + 1;

      unsigned const tryEvery(30);
      for (unsigned iAtt(0); iAtt <= timeout_ / tryEvery; ++iAtt) {
        source = TFile::Open(path);
        if (source) {
          if (!source->IsZombie())
            break;
          delete source;
        }

        gSystem->Sleep(tryEvery * 1000.);
      }

      if (!source || source->IsZombie())
        std::cerr << "Timeout while attempting to open " << path << std::endl;

      gErrorIgnoreLevel = originalErrorIgnoreLevel;
    }
    else
      source = TFile::Open(path);

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

    if (eventSelection_ != "") {
      inEventTree->Draw(">>elist", eventSelection_, "entrylist");
      auto* elist(static_cast<TEntryList*>(gDirectory->Get("elist")));
      if (elist)
        inEventTree->SetEntryList(elist);
      else
        std::cerr << "Failed to compile event selection " << eventSelection_ << std::endl;
    }

    if (printLevel_ >= 2) {
      std::cout << "Event tree has " << inEventTree->GetEntries();
      if (inEventTree->GetEntryList())
        std::cout << " (" << inEventTree->GetEntryList()->GetN() << " selected)";
      std::cout << " events" << std::endl;
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
        TObject* clone(0);
        if (obj->InheritsFrom(TTree::Class())) {
          // if the obj is a tree, a simple clone will only copy the keys but not the tree data
          clone = static_cast<TTree*>(obj)->CloneTree(-1, "fast");
        }
        else
          clone = outputFile->CloneObject(obj);

        clone->Write();
        delete clone;
        delete obj;
      }

      // list of branches in the original tree filtered by branchList_
      auto blist(inEvent.getStatus(*inEventTree));
      blist += branchList_[kEvent];

      if (printLevel_ >= 2)
        std::cout << "Creating output event tree" << std::endl;
      if (printLevel_ >= 3)
        std::cout << blist << std::endl;

      outputFile->cd();
      outEventTree = new TTree("events", "Events");
      outEvent_->book(*outEventTree, blist);
    }

    if (printLevel_ >= 2)
      std::cout << "Binding input" << std::endl;

    // fill events
    if (applyBranchListOnRead_[kEvent]) {
      utils::BranchList blist({"*"});
      blist += branchList_[kEvent];
      inEvent.setAddress(*inEventTree, blist, true);
    }
    else
      inEvent.setAddress(*inEventTree);

    auto* inRunTree(static_cast<TTree*>(source->Get("runs")));

    std::set<UInt_t> savedRuns;

    if (printLevel_ >= 3)
      std::cout << "Processing events" << std::endl;

    if (eventSelection_ == "" && !skimFunction_) {
      // No event selection whatsoever; just copying entries one-to-one.
      // We can speed up the copy in this case by simply copying the baskets without decompression

      outEventTree->CopyEntries(inEventTree, -1, "fast");
      nTotal += inEventTree->GetEntries();
      nWritten += inEventTree->GetEntries();

      if (printLevel_ > 0)
        (std::cout << "\rProcessed " << nTotal << " events").flush();

      if (inRunTree) {
        // All runs are saved - just read the full list of runs from the runs tree

        auto& run(inEvent.run);
        run.setAddress(*inRunTree, {"runNumber"});
        long iEntry(0);
        while (inRunTree->GetEntry(iEntry++) > 0)
          savedRuns.insert(run.runNumber);

        inRunTree->ResetBranchAddresses();
      }
    }
    else {
      // Some sort of event selection exists. Need to unpack and process each event.

      long iEntry(0);
      while (nTotal != _nEvents && inEvent.getEntry(*inEventTree, inEventTree->GetEntryNumber(iEntry++)) > 0) {
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
          (std::cout << "\rProcessed " << nTotal << " events").flush();
        }
  
        ++nTotal;
  
        if (skimFunction_ && !skimFunction_(inEvent))
          continue;
  
        // If outEvent is supplied externally, values from the inEvent must be copied within the skimFunction
        outEvent_->fill(*outEventTree);
        ++nWritten;
  
        savedRuns.insert(inEvent.runNumber);
      }
    }

    if (printLevel_ >= 2)
      std::cout << std::endl;

    if (inRunTree) {
      // inEvent.run was not used during the event loop because no trigger information was requested
      // Now we process the runs

      // collect HLT and run info

      if (printLevel_ >= 3)
        std::cout << "Run tree found" << std::endl;
      
      auto& run(inEvent.run);

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

      long iEntry(0);
      while (run.getEntry(*inRunTree, iEntry++) > 0) {
        if (savedRuns.count(run.runNumber) == 0)
          continue;

        if (printLevel_ >= 3)
          std::cout << " run " << run.runNumber << std::endl;

        if (runSources.count(run.runNumber) == 0)
          runSources.emplace(run.runNumber, std::make_pair(iS, iEntry - 1));

        if (inHLTTree) {
          inHLTTree->GetEntry(run.hltMenu);

          if (printLevel_ >= 3)
            std::cout << "  HLT menu name " << *run.hlt.menu << std::endl;

          auto mItr(std::find(hltMenuList.begin(), hltMenuList.end(), *run.hlt.menu));
          unsigned menuId(0);
          if (mItr == hltMenuList.end()) {
            hltMenuList.push_back(*run.hlt.menu);
            hltPathsList.emplace_back(run.hlt.paths->begin(), run.hlt.paths->end());
            menuId = hltMenuList.size() - 1;
          }
          else
            menuId = mItr - hltMenuList.begin();

          auto hltItr(runToMenuMap.find(run.runNumber));
          if (hltItr == runToMenuMap.end())
            runToMenuMap.emplace(run.runNumber, menuId);
          else if (hltItr->second != menuId) {
            std::cerr << hltItr->second << " " << menuId << std::endl;
            std::cerr << "Inconsistent HLT menu found for run " << run.runNumber << " in file " << path << std::endl;
            throw std::runtime_error("HLT");
          }
        }
      }
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
    delete outEventTree;
  }

  if (runSources.size() != 0) {
    auto& run(inEvent.run);

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

      run.fill(*outRunTree);

      delete source;
    }

    outputFile->cd();
    outRunTree->Write();

    delete outRunTree;

    if (runToMenuMap.size() != 0) {
      outputFile->cd();
      TTree* outHLTTree(new TTree("hlt", "HLT"));

      outHLTTree->Branch("menu", "TString", &run.hlt.menu);
      outHLTTree->Branch("paths", "std::vector<TString>", &run.hlt.paths);

      for (unsigned iH(0); iH != hltMenuList.size(); ++iH) {
        *run.hlt.menu = hltMenuList[iH];
        auto& paths(hltPathsList[iH]);
        run.hlt.paths->assign(paths.begin(), paths.end());

        outHLTTree->Fill();
      }

      outputFile->cd();
      outHLTTree->Write();

      delete outHLTTree;
    }
  }

  delete outputFile;

  if (!extOutEvent_)
    outEvent_ = 0;

  return nWritten;
}

void
panda::FileMerger::setOutEvent(panda::EventBase* _evt)
{
  outEvent_ = _evt;
  if (_evt) {
    extOutEvent_ = true;
  }
  else
    extOutEvent_ = false;
}
