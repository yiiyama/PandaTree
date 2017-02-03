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
    typedef Singlet base_type;

    GenReweight(char const* name = "");
    GenReweight(GenReweight const&);
    ~GenReweight();
    GenReweight& operator=(GenReweight const&);


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

  protected:
    void doSetStatus_(TTree&, utils::BranchList const&) override;
    void doSetAddress_(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&) override;
    void doInit_() override;
    };

  /* BEGIN CUSTOM GenReweight.h.global */
  /* END CUSTOM */

  }

  #endif
