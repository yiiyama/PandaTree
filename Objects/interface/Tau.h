#ifndef PandaTree_Objects_Tau_h
#define PandaTree_Objects_Tau_h
#include "Constants.h"
#include "ParticleM.h"
#include "../../Framework/interface/Container.h"
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
      Bool_t* baseline{0};
      Bool_t* decayMode{0};
      Bool_t* decayModeNew{0};
      Float_t* iso{0};
      Float_t* isoDeltaBetaCorr{0};
      ContainerBase const* matchedGenContainer_{0};
      UInt_t* matchedGen_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef ParticleM base_type;
    typedef Array<Tau> array_type;
    typedef Collection<Tau> collection_type;

    Tau(char const* name = "");
    Tau(Tau const&);
    Tau(datastore&, UInt_t idx);
    ~Tau();
    Tau& operator=(Tau const&);

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
    Short_t& q;
    Bool_t& baseline;
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
  };

  typedef Tau::array_type TauArray;
  typedef Tau::collection_type TauCollection;
  typedef Ref<Tau> TauRef;
  typedef RefVector<Tau> TauRefVector;

  /* BEGIN CUSTOM Tau.h.global */
  /* END CUSTOM */

}

#endif
