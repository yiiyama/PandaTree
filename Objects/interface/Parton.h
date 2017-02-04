#ifndef PandaTree_Objects_Parton_h
#define PandaTree_Objects_Parton_h
#include "Constants.h"
#include "ParticleM.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
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
      Int_t* pdgid{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<Parton> array_type;
    typedef Collection<Parton> collection_type;

    typedef ParticleM base_type;

    Parton(char const* name = "");
    Parton(Parton const&);
    Parton(datastore&, UInt_t idx);
    ~Parton();
    Parton& operator=(Parton const&);


    /* Particle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* ParticleM
    Float_t& mass;
    */
    Int_t& pdgid;

    /* BEGIN CUSTOM Parton.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    Parton(ArrayBase*);

    void doSetStatus_(TTree&, TString const&, utils::BranchList const&) override;
    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&, TString const&) override;
    void doInit_() override;
    };

    typedef Parton::array_type PartonArray;
    typedef Parton::collection_type PartonCollection;
    typedef Ref<Parton> PartonRef;
    typedef RefVector<Parton> PartonRefVector;

  /* BEGIN CUSTOM Parton.h.global */
  /* END CUSTOM */

  }

  #endif
