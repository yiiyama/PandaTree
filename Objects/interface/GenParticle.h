#ifndef PandaTree_Objects_GenParticle_h
#define PandaTree_Objects_GenParticle_h
#include "Constants.h"
#include "ParticleM.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class GenParticle : public ParticleM {
  public:
    struct datastore : public ParticleM::datastore {
      datastore() : ParticleM::datastore() {}
      ~datastore() { deallocate(); }

      /* Particle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      /* ParticleM
      Float_t* mass{0};
      */
      Int_t* pdgid{0};
      UShort_t* statusFlags{0};
      ContainerBase const* parentContainer_{0};
      UInt_t* parent_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef ParticleM base_type;
    typedef Array<GenParticle> array_type;
    typedef Collection<GenParticle> collection_type;

    GenParticle(char const* name = "");
    GenParticle(GenParticle const&);
    GenParticle(datastore&, UInt_t idx);
    ~GenParticle();
    GenParticle& operator=(GenParticle const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {}) override;
    void setAddress(TTree&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {}) override;
    void resetAddress(TTree&) override;

    void init() override;

    /* Particle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* ParticleM
    Float_t& mass;
    */
    Int_t& pdgid;
    UShort_t& statusFlags;
    Ref<GenParticle> parent;

    /* BEGIN CUSTOM GenParticle.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    GenParticle(ArrayBase*);
  };

  typedef GenParticle::array_type GenParticleArray;
  typedef GenParticle::collection_type GenParticleCollection;
  typedef Ref<GenParticle> GenParticleRef;
  typedef RefVector<GenParticle> GenParticleRefVector;

  /* BEGIN CUSTOM GenParticle.h.global */
  /* END CUSTOM */

}

#endif
