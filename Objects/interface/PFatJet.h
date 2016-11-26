#ifndef PandaTree_Objects_PFatJet_h
#define PandaTree_Objects_PFatJet_h
#include "Constants.h"
#include "PJet.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"

namespace panda {

  class PFatJet : public PJet {
  public:
    typedef Container<PFatJet, PJetCollection> PFatJetCollection;
    typedef Ref<PFatJetCollection> PFatJetRef;

    struct array_data : public PJet::array_data {
      static UInt_t const NMAX{8};

      array_data() : PJet::array_data() {}

      /* PParticle
      Float_t pt[NMAX]{};
      Float_t eta[NMAX]{};
      Float_t phi[NMAX]{};
      */
      /* PParticleM
      Float_t mass[NMAX]{};
      */
      /* PJet
      Float_t rawPt[NMAX]{};
      Float_t ptCorrUp[NMAX]{};
      Float_t ptCorrDown[NMAX]{};
      Float_t ptResCorr[NMAX]{};
      Float_t phiResCorr[NMAX]{};
      Float_t csv[NMAX]{};
      Float_t qgl[NMAX]{};
      Float_t nhf[NMAX]{};
      Float_t chf[NMAX]{};
      UInt_t id[NMAX]{};
      UInt_t nConstituents[NMAX]{};
      UInt_t constituents_[NMAX][128]{};
      */
      Float_t tau1[NMAX]{};
      Float_t tau2[NMAX]{};
      Float_t tau3[NMAX]{};
      Float_t mSD[NMAX]{};
      Float_t tau1SD[NMAX]{};
      Float_t tau2SD[NMAX]{};
      Float_t tau3SD[NMAX]{};
      Float_t htt_mass[NMAX]{};
      Float_t htt_frec[NMAX]{};
      Float_t ecfs[NMAX][3][4][4]{};

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PFatJet(char const* name = "");
    PFatJet(PFatJet const&);
    PFatJet(array_data&, UInt_t idx);
    ~PFatJet();
    PFatJet& operator=(PFatJet const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;

    void init() override;

    float get_ecf(short o_, short N_, int ib_) const;
    int set_ecf(int o_, int N_, int ib_, float x_);

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* PParticleM
    Float_t& mass;
    */
    /* PJet
    Float_t& rawPt;
    Float_t& ptCorrUp;
    Float_t& ptCorrDown;
    Float_t& ptResCorr;
    Float_t& phiResCorr;
    Float_t& csv;
    Float_t& qgl;
    Float_t& nhf;
    Float_t& chf;
    UInt_t& id;
    UInt_t& nConstituents;
    PPFCandRef* constituents{}; // use as PPFCandRef[128]
    */
    Float_t& tau1;
    Float_t& tau2;
    Float_t& tau3;
    Float_t& mSD;
    Float_t& tau1SD;
    Float_t& tau2SD;
    Float_t& tau3SD;
    Float_t& htt_mass;
    Float_t& htt_frec;
    Float_t (&ecfs)[3][4][4];

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PFatJet(utils::AllocatorBase const&, char const* name);
  };

  typedef PFatJet::PFatJetCollection PFatJetCollection;
  typedef PFatJet::PFatJetRef PFatJetRef;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
