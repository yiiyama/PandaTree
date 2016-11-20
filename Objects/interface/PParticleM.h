#ifndef PandaTree_Objects_PParticleM_h
#define PandaTree_Objects_PParticleM_h
#include "Constants.h"
#include "PParticle.h"
#include "../../Interface/interface/Container.h"

namespace panda {

  class PParticleM : public PParticle {
  public:
    typedef Container<PParticleM, PParticleCollection> container_type;

    struct array_data : public PParticle::array_data {
      static UInt_t const NMAX{256};

      array_data() : PParticle::array_data() {}

      /* PParticle
      Float_t pt[NMAX]{};
      Float_t eta[NMAX]{};
      Float_t phi[NMAX]{};
      */
      Float_t mass[NMAX]{};

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PParticleM();
    PParticleM(PParticleM const&);
    PParticleM(array_data&, UInt_t idx);
    ~PParticleM();
    PParticleM& operator=(PParticleM const&);

    void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, TString const&, utils::BranchList const& = {"*"}) override;

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
    PParticleM(utils::AllocatorBase const&);
  };

  typedef PParticleM::container_type PParticleMCollection;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
