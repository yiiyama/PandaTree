#ifndef PandaTree_Objects_PLepton_h
#define PandaTree_Objects_PLepton_h
#include "Constants.h"
#include "PParticle.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "PGenParticle.h"

namespace panda {

  class PLepton : public PParticle {
  public:
    struct datastore : public PParticle::datastore {
      datastore() : PParticle::datastore() {}
      ~datastore() { deallocate(); }

      /* PParticle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      Short_t* q{0};
      Bool_t* loose{0};
      Bool_t* medium{0};
      Bool_t* tight{0};
      Float_t* chiso{0};
      Float_t* nhiso{0};
      Float_t* phoiso{0};
      Float_t* puiso{0};
      Bool_t* tauDecay{0};
      Bool_t* hadDecay{0};
      ContainerBase const* matchedGenContainer_{0};
      UInt_t* matchedGen_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef PParticle base_type;
    typedef Array<PLepton> array_type;
    typedef Collection<PLepton> collection_type;

    PLepton(char const* name = "");
    PLepton(PLepton const&);
    PLepton(datastore&, UInt_t idx);
    ~PLepton();
    PLepton& operator=(PLepton const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;
    void resetAddress(TTree&) override;

    void init() override;

    virtual double combiso() const { return 0.; }

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    Short_t& q;
    Bool_t& loose;
    Bool_t& medium;
    Bool_t& tight;
    Float_t& chiso;
    Float_t& nhiso;
    Float_t& phoiso;
    Float_t& puiso;
    Bool_t& tauDecay;
    Bool_t& hadDecay;
    Ref<PGenParticle> matchedGen;

    /* BEGIN CUSTOM PLepton.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    PLepton(ArrayBase*);
  };

  typedef PLepton::array_type PLeptonArray;
  typedef PLepton::collection_type PLeptonCollection;
  typedef Ref<PLepton> PLeptonRef;
  typedef RefVector<PLepton> PLeptonRefVector;

  /* BEGIN CUSTOM PLepton.h.global */
  /* END CUSTOM */

}

#endif
