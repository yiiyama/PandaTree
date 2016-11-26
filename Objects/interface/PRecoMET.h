#ifndef PandaTree_Objects_PRecoMET_h
#define PandaTree_Objects_PRecoMET_h
#include "Constants.h"
#include "PMET.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"

namespace panda {

  class PRecoMET : public PMET {
  public:
    PRecoMET(char const* name = "");
    PRecoMET(PRecoMET const&);
    ~PRecoMET();
    PRecoMET& operator=(PRecoMET const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;

    void init() override;

    virtual TVector2 vCorr(int corr = 0) const;

    /* PMET
    Float_t pt{};
    Float_t phi{};
    */
    Float_t sumETRaw{};
    Float_t raw_pt{};
    Float_t raw_phi{};
    Float_t calo_pt{};
    Float_t calo_phi{};
    Float_t noMu_pt{};
    Float_t noMu_phi{};
    Float_t noHF_pt{};
    Float_t noHF_phi{};
    Float_t trk_pt{};
    Float_t trk_phi{};
    Float_t neutral_pt{};
    Float_t neutral_phi{};
    Float_t photon_pt{};
    Float_t photon_phi{};
    Float_t hf_pt{};
    Float_t hf_phi{};
    Float_t ptCorrUp{};
    Float_t phiCorrUp{};
    Float_t ptCorrDown{};
    Float_t phiCorrDown{};
    Float_t ptJetRes{};
    Float_t phiJetRes{};
    Float_t ptUnclUp{};
    Float_t phiUnclUp{};
    Float_t ptUnclDown{};
    Float_t phiUnclDown{};

    /* BEGIN CUSTOM */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
