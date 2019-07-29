#ifndef PandaTree_Objects_UnpackedPFCand_h
#define PandaTree_Objects_UnpackedPFCand_h
#include "Constants.h"
#include "PFCandBase.h"
#include "PtEtaPhiMMixin.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class PFCand;

  class UnpackedPFCand : public PFCandBase, public PtEtaPhiMMixin {
  public:
    struct datastore : public PFCandBase::datastore, public PtEtaPhiMMixin::datastore {
      datastore() : PFCandBase::datastore(), PtEtaPhiMMixin::datastore() {}
      ~datastore() { deallocate(); }

      /* PFCandBase
      UChar_t* ptype{0};
      ContainerBase const* vertexContainer_{0};
      Short_t* vertex_{0}; ///< transient
      ContainerBase const* trackContainer_{0};
      Short_t* track_{0}; ///< transient
      Float_t* hCalFrac{0};
      */
      /* PtEtaPhiMMixin
      Float_t* pt_{0};
      Float_t* eta_{0};
      Float_t* phi_{0};
      Float_t* mass_{0};
      */
      Float_t* puppiW_{0};
      Float_t* puppiWNoLep_{0};

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

    typedef Array<UnpackedPFCand> array_type;
    typedef Collection<UnpackedPFCand> collection_type;

    typedef PFCandBase base_type;

    UnpackedPFCand(char const* name = "");
    UnpackedPFCand(UnpackedPFCand const&);
    UnpackedPFCand(datastore&, UInt_t idx);
    ~UnpackedPFCand();
    UnpackedPFCand& operator=(UnpackedPFCand const&);

    static char const* typeName() { return "UnpackedPFCand"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    double pt() const override { return pt_; }
    double eta() const override { return eta_; }
    double phi() const override { return phi_; }
    double m() const override { return mass_; }
    void setPtEtaPhiM(double pt, double eta, double phi, double m) override;
    void setXYZE(double px, double py, double pz, double e) override;
    double puppiW() const override { return puppiW_; }
    double puppiWNoLep() const override { return puppiWNoLep_; }
    void setPuppiW(double w, double wnl) override { puppiW_ = w; puppiWNoLep_ = wnl; }

    /* PFCandBase
    UChar_t& ptype;
    Ref<RecoVertex> vertex;
    Ref<PackedTrack> track;
    Float_t& hCalFrac;
    */

  protected:
    /* PtEtaPhiMMixin
    Float_t& pt_;
    Float_t& eta_;
    Float_t& phi_;
    Float_t& mass_;
    */
    Float_t& puppiW_;
    Float_t& puppiWNoLep_;

  public:
    /* BEGIN CUSTOM UnpackedPFCand.h.classdef */
    UnpackedPFCand& operator=(PFCand const&);
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor(Bool_t recursive = kFALSE);

  protected:
    UnpackedPFCand(ArrayBase*);

    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<UnpackedPFCand> UnpackedPFCandArray;
  typedef Collection<UnpackedPFCand> UnpackedPFCandCollection;
  typedef Ref<UnpackedPFCand> UnpackedPFCandRef;
  typedef RefVector<UnpackedPFCand> UnpackedPFCandRefVector;

  /* BEGIN CUSTOM UnpackedPFCand.h.global */
  /* END CUSTOM */

}

#endif
