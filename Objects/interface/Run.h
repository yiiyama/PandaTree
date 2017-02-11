#ifndef PandaTree_Objects_Run_h
#define PandaTree_Objects_Run_h
#include "../../Framework/interface/TreeEntry.h"
#include "Constants.h"

namespace panda {

  class Run : public TreeEntry {
  public:
    Run();
    Run(Run const&);
    ~Run() {}
    Run& operator=(Run const&);

    UInt_t runNumber{};
    UInt_t hltMenu{};

  protected:
    void doSetStatus_(TTree&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&) const override;
    utils::BranchList doGetBranchNames_() const override;
    void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus) override;
    void doBook_(TTree&, utils::BranchList const&) override;
    void doReleaseTree_(TTree&) override;
    void doInit_() override;

  public:
    /* BEGIN CUSTOM Run.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM Run.h.global */
  /* END CUSTOM */

}

#endif
