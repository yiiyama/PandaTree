#ifndef panda_Objects_PParticleM_h
#define panda_Objects_PParticleM_h
#include "Constants.h"
#include "PParticle.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"

namespace panda {

  class PParticleM : public PParticle {
  public:
    struct datastore : public PParticle::datastore {
      datastore() : PParticle::datastore() {}
      ~datastore() { deallocate(); }

      /* PParticle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      Float_t* mass{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
    };

    typedef PParticle base_type;
    typedef Array<PParticleM> array_type;
    typedef Collection<PParticleM> collection_type;

    PParticleM(char const* name = "");
    PParticleM(PParticleM const&);
    PParticleM(datastore&, UInt_t idx);
    ~PParticleM();
    PParticleM& operator=(PParticleM const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;
    void resetAddress(TTree&) override;

    void init() override;

    double m() const override { return mass; }

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    Float_t& mass;

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PParticleM(ArrayBase*);
  };

  typedef PParticleM::array_type PParticleMArray;
  typedef PParticleM::collection_type PParticleMCollection;
  typedef Ref<PParticleM> PParticleMRef;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
