#ifndef PandaTree_Utils_PandaMerger_h
#define PandaTree_Utils_PandaMerger_h

#include "../../Framework/interface/IOUtils.h"

#include "TString.h"

#include <vector>
#include <functional>

namespace panda {

  class EventBase;
  class Event;
  class Run;

  //! Merge multiple panda files with optional skimming, slimming, and editing.
  class FileMerger {
  public:
    enum TreeType {
      kEvent,
      kRun,
      nTreeTypes
    };

    FileMerger() {}
    ~FileMerger() {}

    //! Add input paths.
    /*!
     * \param path  Path to input panda files. Wildcard is allowed.
     */
    void addInput(char const* path);

    //! Select branches to write.
    /*!
     * By default, branches in the input trees are copied.
     *
     * \param blist    Branch list (see BranchList syntax in README).
     * \param onRead   Apply the branch list on input (default false)
     * \param treeType Tree to apply the selection
     */
    void selectBranches(utils::BranchList const& blist, Bool_t onRead = kFALSE, TreeType treeType = kEvent);

    //! Run the merger.
    /*!
     * \param outPath   Output file name.
     * \param nEvents   The number of events to process (default -1 = process all).
     */
    void merge(char const* outPath, long nEvents = -1);

    typedef std::function<Bool_t(panda::Event&)> SkimFunction;

    //! Set the output event object (an Event will be created if nothing is set)
    void setOutEvent(EventBase*);

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
    utils::BranchList branchList_[nTreeTypes]{};
    Bool_t applyBranchListOnRead_[nTreeTypes]{};
    EventBase* outEvent_{0};
    Bool_t ownsOutEvent_{kFALSE};
    SkimFunction skimFunction_{};
  };

}

#endif
