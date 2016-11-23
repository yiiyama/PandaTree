#ifndef PandaTree_Objects_PElectron_h
#define PandaTree_Objects_PElectron_h
#include "Constants.h"
#include "PLepton.h"
#include "../../Framework/interface/Container.h"
#include "PSuperCluster.h"

namespace panda {

  class PElectron : public PLepton {
  public:
    typedef Container<PElectron, PLeptonCollection> container_type;

    struct array_data : public PLepton::array_data {
      static UInt_t const NMAX{32};

      array_data() : PLepton::array_data() {}

      /* PParticle
      Float_t pt[NMAX]{};
      Float_t eta[NMAX]{};
      Float_t phi[NMAX]{};
      */
      /* PLepton
      Text_t const* q[NMAX]{};
      Bool_t loose[NMAX]{};
      Bool_t tight[NMAX]{};
      Float_t chiso[NMAX]{};
      Float_t nhiso[NMAX]{};
      Float_t phoiso[NMAX]{};
      Float_t puiso[NMAX]{};
      Bool_t tauDecay[NMAX]{};
      Bool_t hadDecay[NMAX]{};
      */
      Float_t chisoPh[NMAX]{};
      Float_t nhisoPh[NMAX]{};
      Float_t phisoPh[NMAX]{};
      Float_t ecaliso[NMAX]{};
      Float_t hcaliso[NMAX]{};
      Float_t isoPUOffset[NMAX]{};
      Float_t sieie[NMAX]{};
      Float_t sipip[NMAX]{};
      Float_t hOverE[NMAX]{};
      Bool_t veto[NMAX]{};
      UInt_t superCluster_[NMAX]{};

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PElectron(char const* name = "");
    PElectron(PElectron const&);
    PElectron(array_data&, UInt_t idx);
    ~PElectron();
    PElectron& operator=(PElectron const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;

    void init() override;

    double m() const override { return 5.109989e-4; }
    double combiso() const override { return chiso + std::max(nhiso + phoiso - isoPUOffset, Float_t(0.)); }
    bool isEB() const { return superCluster() ? std::abs(superCluster()->eta) < 1.4442 : false; }

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* PLepton
    Text_t const*& q;
    Bool_t& loose;
    Bool_t& tight;
    Float_t& chiso;
    Float_t& nhiso;
    Float_t& phoiso;
    Float_t& puiso;
    Bool_t& tauDecay;
    Bool_t& hadDecay;
    */
    Float_t& chisoPh;
    Float_t& nhisoPh;
    Float_t& phisoPh;
    Float_t& ecaliso;
    Float_t& hcaliso;
    Float_t& isoPUOffset;
    Float_t& sieie;
    Float_t& sipip;
    Float_t& hOverE;
    Bool_t& veto;
    PSuperCluster* superCluster() const
    { if (superClusterRef_ && superCluster_ < superClusterRef_->size()) return &(*superClusterRef_)[superCluster_]; else return 0; }
    void superCluster(PSuperCluster& p)
    { if (!superClusterRef_) return; for (superCluster_ = 0; superCluster_ != superClusterRef_->size(); ++superCluster_) if (&(*superClusterRef_)[superCluster_] == &p) return; superCluster_ = PSuperCluster::array_data::NMAX; }
    void superClusterRef(PSuperCluster::container_type& cont) { superClusterRef_ = &cont; }
  private:
    UInt_t& superCluster_;
    PSuperCluster::container_type* superClusterRef_{0};
  public:

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PElectron(utils::AllocatorBase const&, char const* name);
  };

  typedef PElectron::container_type PElectronCollection;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
