#ifndef PandaTree_Objects_EventAnalysis_h
#define PandaTree_Objects_EventAnalysis_h
#include "Event.h"
#include "Constants.h"
#include "UnpackedGenParticle.h"

namespace panda {

  class EventAnalysis : public Event {
  public:
    EventAnalysis();
    EventAnalysis(EventAnalysis const&);
    ~EventAnalysis();
    EventAnalysis& operator=(EventAnalysis const&);

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    UnpackedGenParticleCollection genParticlesU = UnpackedGenParticleCollection("genParticlesU", 256);

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
    /* BEGIN CUSTOM EventAnalysis.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM EventAnalysis.h.global */
  /* END CUSTOM */

}

#endif
