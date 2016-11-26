#ifndef PandaTree_Objects_PTau_h
#define PandaTree_Objects_PTau_h
#include "Constants.h"
#include "PParticleM.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"

namespace panda {

  class PTau : public PParticleM {
  public:
    typedef Container<PTau, PParticleMCollection> PTauCollection;
    typedef Ref<PTauCollection> PTauRef;

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
      Text_t const* q[NMAX]{};
      Bool_t decayMode[NMAX]{};
      Float_t isoDeltaBetaCorr[NMAX]{};

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PTau(char const* name = "");
    PTau(PTau const&);
    PTau(array_data&, UInt_t idx);
    ~PTau();
    PTau& operator=(PTau const&);

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
    Text_t const*& q;
    Bool_t& decayMode;
    Float_t& isoDeltaBetaCorr;

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PTau(utils::AllocatorBase const&, char const* name);
  };

  typedef PTau::PTauCollection PTauCollection;
  typedef PTau::PTauRef PTauRef;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
