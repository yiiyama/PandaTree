#ifndef PandaTree_Objects_PackedParticle_h
#define PandaTree_Objects_PackedParticle_h
#include "Constants.h"
#include "Particle.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class PackedParticle : public Particle {
  public:
    struct datastore : public Particle::datastore {
      datastore() : Particle::datastore() {}
      ~datastore() { deallocate(); }

      UShort_t* packedPt{0};
      Short_t* packedEta{0};
      Short_t* packedPhi{0};
      UShort_t* packedM{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
      utils::BranchList getBranchNames(TString const&) const override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<PackedParticle> array_type;
    typedef Collection<PackedParticle> collection_type;

    typedef Particle base_type;

    PackedParticle(char const* name = "");
    PackedParticle(PackedParticle const&);
    PackedParticle(datastore&, UInt_t idx);
    ~PackedParticle();
    PackedParticle& operator=(PackedParticle const&);

    double pt() const override { unpack_(); return pt_; }
    double eta() const override { unpack_(); return eta_; }
    double phi() const override { unpack_(); return phi_; }
    double m() const override { unpack_(); return mass_; }
    void setPtEtaPhiM(double pt, double eta, double phi, double m) override;
    void setXYZE(double px, double py, double pz, double e) override;

    UShort_t& packedPt;
    Short_t& packedEta;
    Short_t& packedPhi;
    UShort_t& packedM;

    /* BEGIN CUSTOM PackedParticle.h.classdef */
  protected:
    void pack_();
    void unpack_() const;
    virtual void packMore_() {}
    virtual void unpackMore_() const {}

    mutable Double_t pt_{0.};
    mutable Double_t eta_{0.};
    mutable Double_t phi_{0.};
    mutable Double_t mass_{0.};
    mutable Bool_t unpacked_{kFALSE};

  public:
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor() override;

  protected:
    PackedParticle(ArrayBase*);

    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&, TString const&) override;
    void doInit_() override;
  };

  typedef Array<PackedParticle> PackedParticleArray;
  typedef Collection<PackedParticle> PackedParticleCollection;
  typedef Ref<PackedParticle> PackedParticleRef;
  typedef RefVector<PackedParticle> PackedParticleRefVector;

  /* BEGIN CUSTOM PackedParticle.h.global */
  class PackingHelper {
  public:
    PackingHelper();

    static PackingHelper const& singleton() { static PackingHelper helper; return helper; }

    UShort_t packUnbound(Double_t) const;
    Double_t unpackUnbound(UShort_t) const;
    Char_t pack8LogBound(Double_t, Double_t min, Double_t max, UChar_t baseminus1) const;
    Double_t unpack8LogBound(Char_t, Double_t min, Double_t max, UChar_t baseminus1) const;

  private:
    UInt_t mantissatable[2048];
    UInt_t exponenttable[64];
    UShort_t offsettable[64];
    UShort_t basetable[512];
    UChar_t shifttable[512];
  };

  /* END CUSTOM */

}

#endif
