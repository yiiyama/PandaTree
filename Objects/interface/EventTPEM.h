#ifndef PandaTree_Objects_EventTPEM_h
#define PandaTree_Objects_EventTPEM_h
#include "EventTP.h"
#include "Constants.h"
#include "Electron.h"
#include "Muon.h"

namespace panda {

  class EventTPEM : public EventTP {
  public:
    EventTPEM();
    EventTPEM(EventTPEM const&);
    ~EventTPEM();
    EventTPEM& operator=(EventTPEM const&);

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    ElectronCollection tags = ElectronCollection("tags", 32);
    MuonCollection probes = MuonCollection("probes", 32);

    static utils::BranchList getListOfBranches(Bool_t direct = kFALSE);

  protected:
    void doSetStatus_(TTree&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&) const override;
    utils::BranchList doGetBranchNames_() const override;
    void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus) override;
    void doBook_(TTree&, utils::BranchList const&) override;
    void doGetEntry_(TTree&) override;
    void doInit_() override;
    void doUnlink_(TTree&) override;

  public:
    /* BEGIN CUSTOM EventTPEM.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM EventTPEM.h.global */
  /* END CUSTOM */

}

#endif
