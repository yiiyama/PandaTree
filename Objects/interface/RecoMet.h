#ifndef PandaTree_Objects_RecoMet_h
#define PandaTree_Objects_RecoMet_h
#include "Constants.h"
#include "Met.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class RecoMet : public Met {
  public:
    RecoMet(char const* name = "");
    RecoMet(RecoMet const&);
    ~RecoMet();
    RecoMet& operator=(RecoMet const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {}) override;
    void setAddress(TTree&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {}) override;
    void resetAddress(TTree&) override;

    void init() override;

    virtual TVector2 vCorr(int corr = 0) const;

    /* Met
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

    /* BEGIN CUSTOM RecoMet.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM RecoMet.h.global */
  /* END CUSTOM */

}

#endif
