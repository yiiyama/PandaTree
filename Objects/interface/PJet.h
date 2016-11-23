#ifndef PandaTree_Objects_PJet_h
#define PandaTree_Objects_PJet_h
#include "Constants.h"
#include "PParticleM.h"
#include "../../Framework/interface/Container.h"
#include "PPFCand.h"

namespace panda {

  class PJet : public PParticleM {
  public:
    typedef Container<PJet, PParticleMCollection> container_type;

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

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PJet(char const* name = "");
    PJet(PJet const&);
    PJet(array_data&, UInt_t idx);
    ~PJet();
    PJet& operator=(PJet const&);

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
    PPFCand* constituents(UInt_t i) const
    { if (constituentsRef_ && constituents_[i] < constituentsRef_->size()) return &(*constituentsRef_)[constituents_[i]]; else return 0; }
    void constituents(UInt_t i, PPFCand& p)
    { if (!constituentsRef_) return; for (constituents_[i] = 0; constituents_[i] != constituentsRef_->size(); ++constituents_[i]) if (&(*constituentsRef_)[constituents_[i]] == &p) return; constituents_[i] = PPFCand::array_data::NMAX; }
    void constituentsRef(PPFCand::container_type& cont) { constituentsRef_ = &cont; }
  private:
    UInt_t (&constituents_)[128];
    PPFCand::container_type* constituentsRef_{0};
  public:

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PJet(utils::AllocatorBase const&, char const* name);
  };

  typedef PJet::container_type PJetCollection;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
