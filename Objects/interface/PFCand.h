#ifndef PandaTree_Objects_PFCand_h
#define PandaTree_Objects_PFCand_h
#include "Constants.h"
#include "PFCandBase.h"
#include "PackedMomentumMixin.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class UnpackedPFCand;

  class PFCand : public PFCandBase, public PackedMomentumMixin {
  public:
    struct datastore : public PFCandBase::datastore, public PackedMomentumMixin::datastore {
      datastore() : PFCandBase::datastore(), PackedMomentumMixin::datastore() {}
      ~datastore() { deallocate(); }

      /* PFCandBase
      UChar_t* ptype{0};
      ContainerBase const* vertexContainer_{0};
      Short_t* vertex_{0}; ///< transient
      ContainerBase const* trackContainer_{0};
      Short_t* track_{0}; ///< transient
      Float_t* hCalFrac{0};
      */
      /* PackedMomentumMixin
      UShort_t* packedPt{0};
      Short_t* packedEta{0};
      Short_t* packedPhi{0};
      UShort_t* packedM{0};
      */
      Char_t* packedPuppiW{0};
      Char_t* packedPuppiWNoLepDiff{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
      utils::BranchList getBranchNames(TString const& = "") const override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<PFCand> array_type;
    typedef Collection<PFCand> collection_type;

    typedef PFCandBase base_type;

    PFCand(char const* name = "");
    PFCand(PFCand const&);
    PFCand(datastore&, UInt_t idx);
    ~PFCand();
    PFCand& operator=(PFCand const&);

    static char const* typeName() { return "PFCand"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    double pt() const override { unpack_(); return pt_; }
    double eta() const override { unpack_(); return eta_; }
    double phi() const override { unpack_(); return phi_; }
    double m() const override { unpack_(); return mass_; }
    void setPtEtaPhiM(double pt, double eta, double phi, double m) override { setPtEtaPhiMPacked_(pt, eta, phi, m); }
    void setXYZE(double px, double py, double pz, double e) override { setXYZEPacked_(px, py, pz, e); }
    double puppiW() const override { unpackWeights_(); return puppiW_; }
    double puppiWNoLep() const override { unpackWeights_(); return puppiWNoLep_; }
    void setPuppiW(double w, double wnl) override { puppiW_ = w; puppiWNoLep_ = wnl; packWeights_(); }

    /* PFCandBase
    UChar_t& ptype;
    Ref<RecoVertex> vertex;
    Ref<PackedTrack> track;
    Float_t& hCalFrac;
    */
    /* PackedMomentumMixin
    UShort_t& packedPt;
    Short_t& packedEta;
    Short_t& packedPhi;
    UShort_t& packedM;
    */
    Char_t& packedPuppiW;
    Char_t& packedPuppiWNoLepDiff;

    /* BEGIN CUSTOM PFCand.h.classdef */
  protected:
    void packWeights_();
    void unpackWeights_() const;

    mutable double puppiW_{0.};
    mutable double puppiWNoLep_{0.};
    
  public:
    PFCand& operator=(UnpackedPFCand const&);
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor(Bool_t recursive = kFALSE);

  protected:
    PFCand(ArrayBase*);

    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<PFCand> PFCandArray;
  typedef Collection<PFCand> PFCandCollection;
  typedef Ref<PFCand> PFCandRef;
  typedef RefVector<PFCand> PFCandRefVector;

  /* BEGIN CUSTOM PFCand.h.global */
  /* END CUSTOM */

}

#endif
