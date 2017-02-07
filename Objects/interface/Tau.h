#ifndef PandaTree_Objects_Tau_h
#define PandaTree_Objects_Tau_h
#include "Constants.h"
#include "ParticleM.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "GenParticle.h"

namespace panda {

  class Tau : public ParticleM {
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
      Short_t* q{0};
      Bool_t* decayMode{0};
      Bool_t* decayModeNew{0};
      Float_t* iso{0};
      Float_t* isoDeltaBetaCorr{0};
      ContainerBase const* matchedGenContainer_{0};
      Int_t* matchedGen_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<Tau> array_type;
    typedef Collection<Tau> collection_type;

    typedef ParticleM base_type;

    Tau(char const* name = "");
    Tau(Tau const&);
    Tau(datastore&, UInt_t idx);
    ~Tau();
    Tau& operator=(Tau const&);


    /* Particle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* ParticleM
    Float_t& mass;
    */
    Short_t& q;
    Bool_t& decayMode;
    Bool_t& decayModeNew;
    Float_t& iso;
    Float_t& isoDeltaBetaCorr;
    Ref<GenParticle> matchedGen;

    /* BEGIN CUSTOM Tau.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    Tau(ArrayBase*);

    void doSetStatus_(TTree&, TString const&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&, TString const&) const override;
    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&, TString const&) override;
    void doInit_() override;
  };

  typedef Tau::array_type TauArray;
  typedef Tau::collection_type TauCollection;
  typedef Ref<Tau> TauRef;
  typedef RefVector<Tau> TauRefVector;

  /* BEGIN CUSTOM Tau.h.global */
  /* END CUSTOM */

}

#endif
