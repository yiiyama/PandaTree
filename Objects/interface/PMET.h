#ifndef PandaTree_Objects_PMET_h
#define PandaTree_Objects_PMET_h
#include "Constants.h"
#include "../../Interface/interface/Object.h"
#include "../../Interface/interface/Container.h"

namespace panda {

  class PMET : public Singlet {
  public:
    PMET();
    PMET(PMET const&);
    PMET(TString const& name);
    ~PMET();
    PMET& operator=(PMET const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;

    void init() override;

    virtual TVector2 v() const { TVector2 vec; vec.SetMagPhi(pt, phi); return vec; }

    Float_t pt{};
    Float_t phi{};
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

    /* BEGIN CUSTOM */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
