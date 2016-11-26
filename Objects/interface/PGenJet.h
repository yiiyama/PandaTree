#ifndef PandaTree_Objects_PGenJet_h
#define PandaTree_Objects_PGenJet_h
#include "Constants.h"
#include "PParticleM.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"

namespace panda {

  class PGenJet : public PParticleM {
  public:
    typedef Container<PGenJet, PParticleMCollection> PGenJetCollection;
    typedef Ref<PGenJetCollection> PGenJetRef;

    struct array_data : public PParticleM::array_data {
      static UInt_t const NMAX{64};

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

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PGenJet(char const* name = "");
    PGenJet(PGenJet const&);
    PGenJet(array_data&, UInt_t idx);
    ~PGenJet();
    PGenJet& operator=(PGenJet const&);

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

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PGenJet(utils::AllocatorBase const&, char const* name);
  };

  typedef PGenJet::PGenJetCollection PGenJetCollection;
  typedef PGenJet::PGenJetRef PGenJetRef;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
