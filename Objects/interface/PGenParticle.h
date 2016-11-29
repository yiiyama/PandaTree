#ifndef PandaTree_Objects_PGenParticle_h
#define PandaTree_Objects_PGenParticle_h
#include "Constants.h"
#include "PParticleM.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class PGenParticle : public PParticleM {
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
      Int_t* pdgid{0};
      UInt_t* parent_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef PParticleM base_type;
    typedef Array<PGenParticle> array_type;
    typedef Collection<PGenParticle> collection_type;

    PGenParticle(char const* name = "");
    PGenParticle(PGenParticle const&);
    PGenParticle(datastore&, UInt_t idx);
    ~PGenParticle();
    PGenParticle& operator=(PGenParticle const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;
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
    Int_t& pdgid;
    Ref<PGenParticle> parent;

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PGenParticle(ArrayBase*);
  };

  typedef PGenParticle::array_type PGenParticleArray;
  typedef PGenParticle::collection_type PGenParticleCollection;
  typedef Ref<PGenParticle> PGenParticleRef;
  typedef RefVector<PGenParticle> PGenParticleRefVector;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
