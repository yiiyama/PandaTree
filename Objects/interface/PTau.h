#ifndef PandaTree_Objects_PTau_h
#define PandaTree_Objects_PTau_h
#include "Constants.h"
#include "PParticleM.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "PGenParticle.h"

namespace panda {

  class PTau : public PParticleM {
  public:
    struct datastore : public PParticleM::datastore {
      datastore() : PParticleM::datastore() {}
      ~datastore() { deallocate(); }

      /* PParticle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      /* PParticleM
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

    typedef PParticleM base_type;
    typedef Array<PTau> array_type;
    typedef Collection<PTau> collection_type;

    PTau(char const* name = "");
    PTau(PTau const&);
    PTau(datastore&, UInt_t idx);
    ~PTau();
    PTau& operator=(PTau const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {}) override;
    void setAddress(TTree&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {}) override;
    void resetAddress(TTree&) override;

    void init() override;

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* PParticleM
    Float_t& mass;
    */
    Short_t& q;
    Bool_t& baseline;
    Bool_t& decayMode;
    Bool_t& decayModeNew;
    Float_t& iso;
    Float_t& isoDeltaBetaCorr;
    Ref<PGenParticle> matchedGen;

    /* BEGIN CUSTOM PTau.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    PTau(ArrayBase*);
  };

  typedef PTau::array_type PTauArray;
  typedef PTau::collection_type PTauCollection;
  typedef Ref<PTau> PTauRef;
  typedef RefVector<PTau> PTauRefVector;

  /* BEGIN CUSTOM PTau.h.global */
  /* END CUSTOM */

}

#endif
