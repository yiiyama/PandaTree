#ifndef PandaTree_Objects_PGenParticle_h
#define PandaTree_Objects_PGenParticle_h
#include "Constants.h"
#include "PParticleM.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "PGenParticle.h"

namespace panda {

  class PGenParticle : public PParticleM {
  public:
    typedef Container<PGenParticle, PParticleMCollection> PGenParticleCollection;
    typedef Ref<PGenParticleCollection> PGenParticleRef;

    struct array_data : public PParticleM::array_data {
      static UInt_t const NMAX{256};

      array_data() : PParticleM::array_data() {}

      /* PParticle
      Float_t pt[NMAX]{};
      Float_t eta[NMAX]{};
      Float_t phi[NMAX]{};
      */
      /* PParticleM
      Float_t mass[NMAX]{};
      */
      Int_t pdgid[NMAX]{};
      UInt_t parent_[NMAX]{};

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PGenParticle(char const* name = "");
    PGenParticle(PGenParticle const&);
    PGenParticle(array_data&, UInt_t idx);
    ~PGenParticle();
    PGenParticle& operator=(PGenParticle const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;

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
    PGenParticleRef parent;

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PGenParticle(utils::AllocatorBase const&, char const* name);
  };

  typedef PGenParticle::PGenParticleCollection PGenParticleCollection;
  typedef PGenParticle::PGenParticleRef PGenParticleRef;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
