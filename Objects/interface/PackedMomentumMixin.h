#ifndef PandaTree_Objects_PackedMomentumMixin_h
#define PandaTree_Objects_PackedMomentumMixin_h
#include "../../Framework/interface/Element.h"

namespace panda {

  class PackedMomentumMixin {
  public:
    struct datastore {
      UShort_t* packedPt{0};
      Short_t* packedEta{0};
      Short_t* packedPhi{0};
      UShort_t* packedM{0};
    };

    PackedMomentumMixin(datastore&, UInt_t idx);

    UShort_t& packedPt;
    Short_t& packedEta;
    Short_t& packedPhi;
    UShort_t& packedM;

    /* BEGIN CUSTOM PackedMomentumMixin.h.classdef */
  protected:
    void pack_();
    void unpack_() const;
    void setPtEtaPhiMPacked_(double pt, double eta, double phi, double m);
    void setXYZEPacked_(double px, double py, double pz, double e);

    mutable Double_t pt_{0.};
    mutable Double_t eta_{0.};
    mutable Double_t phi_{0.};
    mutable Double_t mass_{0.};
    mutable Bool_t unpacked_{kFALSE};
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();
  };
  /* BEGIN CUSTOM PackedMomentumMixin.h.global */
  /* END CUSTOM */

}

#endif
