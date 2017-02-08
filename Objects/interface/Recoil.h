#ifndef PandaTree_Objects_Recoil_h
#define PandaTree_Objects_Recoil_h
#include "Constants.h"
#include "../../Framework/interface/Singlet.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class Recoil : public Singlet {
  public:
    typedef Singlet base_type;

    Recoil(char const* name = "");
    Recoil(Recoil const&);
    ~Recoil();
    Recoil& operator=(Recoil const&);

    UInt_t categories{};
    Float_t max{};
  protected:

  public:
    /* BEGIN CUSTOM Recoil.h.classdef */
    /* END CUSTOM */

  protected:
    void doSetStatus_(TTree&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&) const override;
    void doSetAddress_(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&) override;
    void doInit_() override;
  };

  /* BEGIN CUSTOM Recoil.h.global */
  /* END CUSTOM */

}

#endif
