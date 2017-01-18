#ifndef PandaTree_Objects_Recoil_h
#define PandaTree_Objects_Recoil_h
#include "Constants.h"
#include "../../Framework/interface/Singlet.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class Recoil : public Singlet {
  public:
    Recoil(char const* name = "");
    Recoil(Recoil const&);
    ~Recoil();
    Recoil& operator=(Recoil const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;
    void resetAddress(TTree&) override;

    void init() override;

    UInt_t categories{};
    Float_t max{};

    /* BEGIN CUSTOM Recoil.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM Recoil.h.global */
  /* END CUSTOM */

}

#endif
