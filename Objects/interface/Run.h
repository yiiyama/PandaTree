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

    //! Get the trigger index for the given token
    UInt_t getTriggerIndex(UInt_t token) const { return triggerIndices_.at(token); }

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

    //! Update trigger information
    void loadTriggerTable(TFile&);

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
    //! Switch to enable trigger loading
    Bool_t loadTrigger_{kFALSE};

    //! Cached menu number to detect menu change
    UInt_t hltMenuCache_{-1};

    //! List of registered paths
    std::vector<TString> registeredTriggers_{};

    //! List of indices of registered triggers in the current menu
    std::vector<UInt_t> triggerIndices_{};

    /* END CUSTOM */
  };

  /* BEGIN CUSTOM Run.h.global */
  /* END CUSTOM */

}

#endif
