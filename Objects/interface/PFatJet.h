#ifndef PandaTree_Objects_PFatJet_h
#define PandaTree_Objects_PFatJet_h
#include "Constants.h"
#include "PJet.h"
#include "../../Interface/interface/Container.h"

namespace panda {

  class PFatJet : public PJet {
  public:
    typedef Container<PFatJet, PJetCollection> container_type;

    struct array_data : public PJet::array_data {
      array_data() : PJet::array_data() {}

      /* PObject
      Float_t pt[NMAX]{};
      Float_t eta[NMAX]{};
      Float_t phi[NMAX]{};
      */
      /* PJet
      Float_t rawPt[NMAX]{};
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

    PFatJet();
    PFatJet(PFatJet const&);
    PFatJet(array_data&, UInt_t idx);
    ~PFatJet();
    PFatJet& operator=(PFatJet const&);

    void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, TString const&, utils::BranchList const& = {"*"}) override;

    void init() override;

    float get_ecf(short o_, short N_, int ib_) const;
    int set_ecf(int o_, int N_, int ib_, float x_);

    /* PObject
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* PJet
    Float_t& rawPt;
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
    PFatJet(utils::AllocatorBase const&);
  };

  typedef PFatJet::container_type PFatJetCollection;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
