#ifndef PandaTree_Objects_PRecoMET_h
#define PandaTree_Objects_PRecoMET_h
#include "Constants.h"
#include "PMET.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class PRecoMET : public PMET {
  public:
    PRecoMET(char const* name = "");
    PRecoMET(PRecoMET const&);
    ~PRecoMET();
    PRecoMET& operator=(PRecoMET const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;
    void resetAddress(TTree&) override;

    void init() override;

    virtual TVector2 vCorr(int corr = 0) const;

    /* PMET
    Float_t pt{};
    Float_t phi{};
    */
    Float_t sumETRaw{};
    Float_t ptCorrUp{};
    Float_t phiCorrUp{};
    Float_t ptCorrDown{};
    Float_t phiCorrDown{};
    Float_t ptUnclUp{};
    Float_t phiUnclUp{};
    Float_t ptUnclDown{};
    Float_t phiUnclDown{};
    Float_t ptSmear{};
    Float_t phiSmear{};
    Float_t ptSmearUp{};
    Float_t phiSmearUp{};
    Float_t ptSmearDown{};
    Float_t phiSmearDown{};

    /* BEGIN CUSTOM PRecoMET.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM PRecoMET.h.global */
  /* END CUSTOM */

}

#endif
