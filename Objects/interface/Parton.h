#ifndef PandaTree_Objects_Parton_h
#define PandaTree_Objects_Parton_h
#include "Constants.h"
#include "ParticleM.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class Parton : public ParticleM {
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
      UInt_t* pdgid{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef ParticleM base_type;
    typedef Array<Parton> array_type;
    typedef Collection<Parton> collection_type;

    Parton(char const* name = "");
    Parton(Parton const&);
    Parton(datastore&, UInt_t idx);
    ~Parton();
    Parton& operator=(Parton const&);

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
    UInt_t& pdgid;

    /* BEGIN CUSTOM Parton.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    Parton(ArrayBase*);
  };

  typedef Parton::array_type PartonArray;
  typedef Parton::collection_type PartonCollection;
  typedef Ref<Parton> PartonRef;
  typedef RefVector<Parton> PartonRefVector;

  /* BEGIN CUSTOM Parton.h.global */
  /* END CUSTOM */

}

#endif
