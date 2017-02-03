#ifndef PandaTree_Utils_PandaMerger_h
#define PandaTree_Utils_PandaMerger_h

#include "../../Framework/interface/IOUtils.h"

#include "TString.h"

#include <vector>
#include <functional>

namespace panda {

  class Event;
  class Run;

  //! Merge multiple panda files with optional skimming, slimming, and editing.
  class FileMerger {
  public:
    FileMerger() {}
    ~FileMerger() {}

    //! Add input paths.
    /*!
     * \param path  Path to input panda files. Wildcard allowed.
     */
    void addInput(char const* path);

    //! Select branches to write.
    /*!
     * \param blist    Branch list (see BranchList syntax in README).
     * \param onRead   Apply the branch list on input (default false)
     */
    void selectBranches(utils::BranchList const& blist, Bool_t onRead = kFALSE);

    //! Run the merger.
    /*!
     * \param outPath   Output file name.
     * \param nEvents   The number of events to process (default -1 = process all).
     */
    void merge(char const* outPath, long nEvents = -1);

    typedef std::function<Bool_t(panda::Event&)> SkimFunction;

    //! Introduce a skim.
    /*!
     * SkimFunction is any callable object (functions or classes with operator())
     * that can take panda::Event& as an argument and return a bool.
     *
     * \param skim   Skim function.
     */
    void setSkim(SkimFunction const& skim) { skimFunction_ = skim; }

  private:
    std::vector<TString> paths_{};
    utils::BranchList branchList_{{"*"}};
    Bool_t applyBranchListOnRead_{kFALSE};
    SkimFunction skimFunction_{};
  };

}

#endif
