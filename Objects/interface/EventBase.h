#ifndef PandaTree_Objects_EventBase_h
#define PandaTree_Objects_EventBase_h
#include "../../Framework/interface/TreeEntry.h"
#include "Constants.h"
#include "HLTBits.h"
#include "Run.h"

namespace panda {

  class EventBase : public TreeEntry {
  public:
    EventBase();
    EventBase(EventBase const&);
    ~EventBase() {}
    EventBase& operator=(EventBase const&);

    HLTBits triggers = HLTBits("triggers");

    UInt_t runNumber{};
    UInt_t lumiNumber{};
    UInt_t eventNumber{};
    Bool_t isData{};
    Float_t weight{};

    static utils::BranchList getListOfBranches();

  protected:
    void doSetStatus_(TTree&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&) const override;
    utils::BranchList doGetBranchNames_() const override;
    void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus) override;
    void doBook_(TTree&, utils::BranchList const&) override;
    void doGetEntry_(TTree&, Long64_t) override;
    void doInit_() override;

  public:
    /* BEGIN CUSTOM EventBase.h.classdef */

    //! Current run object.
    Run run;

    //! Use to declare a trigger path to be used in the analysis. Returns a token for the path.
    /*!
     * Call this function before the event loop for each trigger you will be using. The return value
     * is an integer unique to the path, and can be passed to triggerFired() in the event loop to retrieve
     * the trigger decision of the event.
     *
     * \param path   HLT path
     */
    UInt_t registerTrigger(char const* path) { return run.registerTrigger(path); }

    //! Trigger decision of the event.
    /*!
     * Pass the trigger token returned by registerTrigger().
     *
     * \param token   Token returned by registerTrigger()
     */
    Bool_t triggerFired(UInt_t token) const;

    /* END CUSTOM */
  };

  /* BEGIN CUSTOM EventBase.h.global */
  /* END CUSTOM */

}

#endif
