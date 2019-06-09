#ifndef PandaTree_Objects_GenParticle_h
#define PandaTree_Objects_GenParticle_h
#include "Constants.h"
#include "GenParticleBase.h"
#include "PackedMomentumMixin.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class UnpackedGenParticle;

  class GenParticle : public GenParticleBase, public PackedMomentumMixin {
  public:
    struct datastore : public GenParticleBase::datastore, public PackedMomentumMixin::datastore {
      datastore() : GenParticleBase::datastore(), PackedMomentumMixin::datastore() {}
      ~datastore() { deallocate(); }

      /* GenParticleBase
      Int_t* pdgid{0};
      Bool_t* finalState{0};
      Bool_t* miniaodPacked{0};
      UShort_t* statusFlags{0};
      ContainerBase const* parentContainer_{0};
      Short_t* parent_{0};
      */
      /* PackedMomentumMixin
      UShort_t* packedPt{0};
      Short_t* packedEta{0};
      Short_t* packedPhi{0};
      UShort_t* packedM{0};
      */

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

    typedef Array<GenParticle> array_type;
    typedef Collection<GenParticle> collection_type;

    typedef GenParticleBase base_type;

    GenParticle(char const* name = "");
    GenParticle(GenParticle const&);
    GenParticle(datastore&, UInt_t idx);
    ~GenParticle();
    GenParticle& operator=(GenParticle const&);

    static char const* typeName() { return "GenParticle"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    double pt() const override { unpack_(); return pt_; }
    double eta() const override { unpack_(); return eta_; }
    double phi() const override { unpack_(); return phi_; }
    double m() const override { unpack_(); return mass_; }
    void setPtEtaPhiM(double pt, double eta, double phi, double m) override;
    void setXYZE(double px, double py, double pz, double e) override;

    /* GenParticleBase
    Int_t& pdgid;
    Bool_t& finalState;
    Bool_t& miniaodPacked; ///< True if this came from a MINIAOD packed collection
    UShort_t& statusFlags;
    Ref<GenParticleBase> parent;
    */
    /* PackedMomentumMixin
    UShort_t& packedPt;
    Short_t& packedEta;
    Short_t& packedPhi;
    UShort_t& packedM;
    */

    /* BEGIN CUSTOM GenParticle.h.classdef */
    GenParticle& operator=(UnpackedGenParticle const&);
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor(Bool_t recursive = kFALSE);

  protected:
    GenParticle(ArrayBase*);

    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<GenParticle> GenParticleArray;
  typedef Collection<GenParticle> GenParticleCollection;
  typedef Ref<GenParticle> GenParticleRef;
  typedef RefVector<GenParticle> GenParticleRefVector;

  /* BEGIN CUSTOM GenParticle.h.global */
  /* END CUSTOM */

}

#endif
