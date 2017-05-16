#ifndef PandaTree_Objects_Run_h
#define PandaTree_Objects_Run_h
#include "../../Framework/interface/TreeEntry.h"
#include "Constants.h"
#include "TList.h"

namespace panda {

  class Run : public TreeEntry {
  public:
    Run();
    Run(Run const&);
    ~Run();
    Run& operator=(Run const&);

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    UInt_t runNumber{};
    UInt_t hltMenu{};
    UShort_t hltSize{}; // transient

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
    /* BEGIN CUSTOM Run.h.classdef */

    //! Set the trigger loading switch
    void setLoadTrigger(Bool_t l = kTRUE);

    //! See description on Event::registerTrigger
    UInt_t registerTrigger(char const* path);

    //! Get the registered path name for the token
    /*!
     * Returns an empty string for an invalid token.
     */
    char const* getRegisteredPath(UInt_t token) const;

    //! Get the trigger index for the given token
    UInt_t getTriggerIndex(UInt_t token) const;

    //! Current trigger menu name
    /*!
     * Throws an exception if trigger menu is not set.
     */
    char const* triggerMenu() const;

    //! Get the full trigger path list.
    /*!
     * Throws an exception if trigger menu is not set.
     */
    std::vector<TString> const& triggerPaths() const;

    //! Size of current trigger menu
    /*!
     * Throws an exception if trigger menu is not set.
     */
    UInt_t triggerSize() const { return triggerPaths().size(); }

    //! Check for updates
    void findEntry(TTree& runTree, UInt_t runNumber);

    //! Reset inputTree_, inputTreeNumber_, and hltMenuCache_
    void resetCache();

    struct HLTTreeEntry {
      ~HLTTreeEntry() { destroy(); }
      void create() {
        menu = new TString;
        paths = new std::vector<TString>;
      }
      void destroy() {
        delete menu;
        delete paths;
        menu = 0;
        paths = 0;
      }

      //! Current menu name
      TString* menu{0};
      //! Current full menu
      std::vector<TString>* paths{0};
    } hlt;

  private:

    //! Helper class for cleaning up runTrees_
    /*!
      See CollectionBase for details.
     */
    class TreePointerCleaner : public TObject {
    public:
      TreePointerCleaner(Run*, TTree*);
      ~TreePointerCleaner(); //! called in TTree destructor when UserInfo list is deleted

      char const* GetName() const override { return run_->getName(); }
      
      Run* getRun() const { return run_; }
    private:
      Run* run_;
      TTree* tree_;
    };

    friend class TreePointerCleaner;

    //! Update trigger information
    void updateTriggerTable_(TTree& _tree);

    //! Switch to enable trigger loading
    Bool_t loadTrigger_{kFALSE};

    //! List of registered paths
    std::vector<TString> registeredTriggers_{};

    //! List of indices of registered triggers in the current menu
    std::vector<UInt_t> triggerIndices_{};

    //! Current input tree (used in updateTriggerTable_ to detect input file change)
    /*!
      Unlike CollectionBase and EventBase, Run does not carry pointers to multiple input trees.
      If we want to be able to handle multiple trees, we will need to vectorize the "hlt" data member.
    */
    TTree* inputTree_{0};

    //! Current input tree number
    Int_t inputTreeNumber_{-1};

    //! Cached menu number to detect menu change
    UInt_t hltMenuCache_{0xffffffff};

    /* END CUSTOM */
  };

  /* BEGIN CUSTOM Run.h.global */
  /* END CUSTOM */

}

#endif
