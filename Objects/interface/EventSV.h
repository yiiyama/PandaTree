#ifndef PandaTree_Objects_EventSV_h
#define PandaTree_Objects_EventSV_h
#include "EventBase.h"
#include "Constants.h"
#include "CorrectedSecondaryVertex.h"
#include "SVDaughter.h"
#include "Muon.h"
#include "UnpackedGenParticle.h"

namespace panda {

  class EventSV : public EventBase {
  public:
    EventSV();
    EventSV(EventSV const&);
    ~EventSV();
    EventSV& operator=(EventSV const&);

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    GenParticleBaseCollection const* genParticleCollection() const override { return &genParticles; }
    GenParticleBaseCollection* genParticleCollection() override { return &genParticles; }

    CorrectedSecondaryVertexCollection secondaryVertices = CorrectedSecondaryVertexCollection("secondaryVertices");
    SVDaughterCollection tracks = SVDaughterCollection("tracks");
    MuonCollection muons = MuonCollection("muons");
    UnpackedGenParticleCollection genParticles = UnpackedGenParticleCollection("genParticles");

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
    /* BEGIN CUSTOM EventSV.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM EventSV.h.global */
  /* END CUSTOM */

}

#endif
