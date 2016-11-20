#ifndef PandaTree_Objects_PPhoton_h
#define PandaTree_Objects_PPhoton_h
#include "Constants.h"
#include "PParticle.h"
#include "../../Interface/interface/Container.h"
#include "PSuperCluster.h"

namespace panda {

  class PPhoton : public PParticle {
  public:
    typedef Container<PPhoton, PParticleCollection> container_type;

    struct array_data : public PParticle::array_data {
      static UInt_t const NMAX{64};

      array_data() : PParticle::array_data() {}

      /* PParticle
      Float_t pt[NMAX]{};
      Float_t eta[NMAX]{};
      Float_t phi[NMAX]{};
      */
      Float_t chiso[NMAX]{};
      Float_t chworstiso[NMAX]{};
      Float_t chisoMax[NMAX]{};
      Float_t nhiso[NMAX]{};
      Float_t phiso[NMAX]{};
      Float_t ecaliso[NMAX]{};
      Float_t hcaliso[NMAX]{};
      Float_t sieie[NMAX]{};
      Float_t sipip[NMAX]{};
      Float_t hOverE[NMAX]{};
      Float_t geniso[NMAX]{};
      Float_t mipEnergy[NMAX]{};
      Float_t e33[NMAX]{};
      Float_t emax[NMAX]{};
      Float_t e2nd[NMAX]{};
      Float_t r9[NMAX]{};
      Float_t etaWidth[NMAX]{};
      Float_t phiWidth[NMAX]{};
      Float_t time[NMAX]{};
      Float_t timeSpan[NMAX]{};
      Float_t genMatchDR[NMAX]{};
      Bool_t loose[NMAX]{};
      Bool_t medium[NMAX]{};
      Bool_t tight[NMAX]{};
      Bool_t highpt[NMAX]{};
      Bool_t pixelVeto[NMAX]{};
      Bool_t csafeVeto[NMAX]{};
      Bool_t matchL1[NMAX][nPhotonL1Objects]{};
      UInt_t superCluster_[NMAX]{};

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PPhoton();
    PPhoton(PPhoton const&);
    PPhoton(array_data&, UInt_t idx);
    ~PPhoton();
    PPhoton& operator=(PPhoton const&);

    void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, TString const&, utils::BranchList const& = {"*"}) override;

    void init() override;

    bool isEB() const { return superCluster() ? std::abs(superCluster()->eta) < 1.4442 : false; }

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    Float_t& chiso;
    Float_t& chworstiso;
    Float_t& chisoMax;
    Float_t& nhiso;
    Float_t& phiso;
    Float_t& ecaliso;
    Float_t& hcaliso;
    Float_t& sieie;
    Float_t& sipip;
    Float_t& hOverE;
    Float_t& geniso;
    Float_t& mipEnergy;
    Float_t& e33;
    Float_t& emax;
    Float_t& e2nd;
    Float_t& r9;
    Float_t& etaWidth;
    Float_t& phiWidth;
    Float_t& time;
    Float_t& timeSpan;
    Float_t& genMatchDR;
    Bool_t& loose;
    Bool_t& medium;
    Bool_t& tight;
    Bool_t& highpt;
    Bool_t& pixelVeto;
    Bool_t& csafeVeto;
    Bool_t (&matchL1)[nPhotonL1Objects];
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
    PPhoton(utils::AllocatorBase const&);
  };

  typedef PPhoton::container_type PPhotonCollection;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
