#ifndef PandaTree_Objects_Met_h
#define PandaTree_Objects_Met_h
#include "Constants.h"
#include "../../Framework/interface/Singlet.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class Met : public Singlet {
  public:
    Met(char const* name = "");
    Met(Met const&);
    ~Met();
    Met& operator=(Met const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;
    void resetAddress(TTree&) override;

    void init() override;

    virtual TVector2 v() const { TVector2 vec; vec.SetMagPhi(pt, phi); return vec; }
    void setXY(double x, double y) { pt = std::sqrt(x * x + y * y); phi = std::atan2(y, x); }

    Float_t pt{};
    Float_t phi{};

    /* BEGIN CUSTOM Met.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM Met.h.global */
  /* END CUSTOM */

}

#endif
