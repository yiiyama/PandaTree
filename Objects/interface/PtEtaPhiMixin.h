#ifndef PandaTree_Objects_PtEtaPhiMixin_h
#define PandaTree_Objects_PtEtaPhiMixin_h
#include "../../Framework/interface/Element.h"

namespace panda {

  class PtEtaPhiMixin {
  public:
    struct datastore {
      Float_t* pt_{0};
      Float_t* eta_{0};
      Float_t* phi_{0};
    };

    PtEtaPhiMixin(datastore&, UInt_t idx);

  protected:
    Float_t& pt_;
    Float_t& eta_;
    Float_t& phi_;

    /* BEGIN CUSTOM PtEtaPhiMixin.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();
  };
  /* BEGIN CUSTOM PtEtaPhiMixin.h.global */
  /* END CUSTOM */

}

#endif
