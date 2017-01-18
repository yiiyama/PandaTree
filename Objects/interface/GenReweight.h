#ifndef PandaTree_Objects_GenReweight_h
#define PandaTree_Objects_GenReweight_h
#include "Constants.h"
#include "../../Framework/interface/Singlet.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class GenReweight : public Singlet {
  public:
    GenReweight(char const* name = "");
    GenReweight(GenReweight const&);
    ~GenReweight();
    GenReweight& operator=(GenReweight const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;
    void resetAddress(TTree&) override;

    void init() override;

    Float_t r1f2DW{};
    Float_t r1f5DW{};
    Float_t r2f1DW{};
    Float_t r2f2DW{};
    Float_t r5f1DW{};
    Float_t r5f5DW{};
    Float_t pdfDW{};
    Float_t genParam[128]{};

    /* BEGIN CUSTOM GenReweight.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM GenReweight.h.global */
  /* END CUSTOM */

}

#endif
