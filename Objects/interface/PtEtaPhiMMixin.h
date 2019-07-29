#ifndef PandaTree_Objects_PtEtaPhiMMixin_h
#define PandaTree_Objects_PtEtaPhiMMixin_h
#include "../../Framework/interface/Element.h"

namespace panda {

  class PtEtaPhiMMixin {
  public:
    struct datastore {
      Float_t* pt_{0};
      Float_t* eta_{0};
      Float_t* phi_{0};
      Float_t* mass_{0};
    };

    PtEtaPhiMMixin(datastore&, UInt_t idx);

  protected:
    Float_t& pt_;
    Float_t& eta_;
    Float_t& phi_;
    Float_t& mass_;

    /* BEGIN CUSTOM PtEtaPhiMMixin.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();
  };
  /* BEGIN CUSTOM PtEtaPhiMMixin.h.global */
  /* END CUSTOM */

}

#endif
