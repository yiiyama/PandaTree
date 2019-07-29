#ifndef PandaTree_Objects_GenParticleBase_h
#define PandaTree_Objects_GenParticleBase_h
#include "Constants.h"
#include "Particle.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class GenParticleBase : public Particle {
  public:
    enum StatusFlag {
      kIsPrompt,
      kIsDecayedLeptonHadron,
      kIsTauDecayProduct,
      kIsPromptTauDecayProduct,
      kIsDirectTauDecayProduct,
      kIsDirectPromptTauDecayProduct,
      kIsDirectHadronDecayProduct,
      kIsHardProcess,
      kFromHardProcess,
      kIsHardProcessTauDecayProduct,
      kIsDirectHardProcessTauDecayProduct,
      kFromHardProcessBeforeFSR,
      kIsFirstCopy,
      kIsLastCopy,
      kIsLastCopyBeforeFSR,
      nStatusFlags
    };

    static TString StatusFlagName[nStatusFlags];

    struct datastore : public Particle::datastore {
      datastore() : Particle::datastore() {}
      ~datastore() { deallocate(); }

      Int_t* pdgid{0};
      Bool_t* finalState{0};
      Bool_t* miniaodPacked{0};
      UShort_t* statusFlags{0};
      ContainerBase const* parentContainer_{0};
      Short_t* parent_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
      utils::BranchList getBranchNames(TString const& = "") const override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<GenParticleBase> array_type;
    typedef Collection<GenParticleBase> collection_type;

    typedef Particle base_type;

    GenParticleBase(char const* name = "");
    GenParticleBase(GenParticleBase const&);
    GenParticleBase(datastore&, UInt_t idx);
    ~GenParticleBase();
    GenParticleBase& operator=(GenParticleBase const&);

    static char const* typeName() { return "GenParticleBase"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    bool testFlag(StatusFlag f) const { return ((statusFlags >> f) & 1) == 1; }

    Int_t& pdgid;
    Bool_t& finalState;
    Bool_t& miniaodPacked; ///< True if this came from a MINIAOD packed collection
    UShort_t& statusFlags;
    Ref<GenParticleBase> parent;

    /* BEGIN CUSTOM GenParticleBase.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor(Bool_t recursive = kFALSE);

  protected:
    GenParticleBase(ArrayBase*);

    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<GenParticleBase> GenParticleBaseArray;
  typedef Collection<GenParticleBase> GenParticleBaseCollection;
  typedef Ref<GenParticleBase> GenParticleBaseRef;
  typedef RefVector<GenParticleBase> GenParticleBaseRefVector;

  /* BEGIN CUSTOM GenParticleBase.h.global */
  /* END CUSTOM */

}

#endif
