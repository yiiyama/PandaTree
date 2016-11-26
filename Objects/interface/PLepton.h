#ifndef PandaTree_Objects_PLepton_h
#define PandaTree_Objects_PLepton_h
#include "Constants.h"
#include "PParticle.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"

namespace panda {

  class PLepton : public PParticle {
  public:
    typedef Container<PLepton, PParticleCollection> PLeptonCollection;
    typedef Ref<PLeptonCollection> PLeptonRef;

    struct array_data : public PParticle::array_data {
      static UInt_t const NMAX{32};

      array_data() : PParticle::array_data() {}

      /* PParticle
      Float_t pt[NMAX]{};
      Float_t eta[NMAX]{};
      Float_t phi[NMAX]{};
      */
      Text_t const* q[NMAX]{};
      Bool_t loose[NMAX]{};
      Bool_t tight[NMAX]{};
      Float_t chiso[NMAX]{};
      Float_t nhiso[NMAX]{};
      Float_t phoiso[NMAX]{};
      Float_t puiso[NMAX]{};
      Bool_t tauDecay[NMAX]{};
      Bool_t hadDecay[NMAX]{};

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PLepton(char const* name = "");
    PLepton(PLepton const&);
    PLepton(array_data&, UInt_t idx);
    ~PLepton();
    PLepton& operator=(PLepton const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;

    void init() override;

    virtual double combiso() const { return 0.; }

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    Text_t const*& q;
    Bool_t& loose;
    Bool_t& tight;
    Float_t& chiso;
    Float_t& nhiso;
    Float_t& phoiso;
    Float_t& puiso;
    Bool_t& tauDecay;
    Bool_t& hadDecay;

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PLepton(utils::AllocatorBase const&, char const* name);
  };

  typedef PLepton::PLeptonCollection PLeptonCollection;
  typedef PLepton::PLeptonRef PLeptonRef;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
