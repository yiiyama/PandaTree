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

      UShort_t* packedPt_{0};
      UShort_t* packedEta_{0};
      UShort_t* packedPhi_{0};
      UShort_t* packedM_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
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

    double pt() const { unpack_(); return pt_; }
    double eta() const { unpack_(); return eta_; }
    double phi() const { unpack_(); return phi_; }
    double m() const { unpack_(); return mass_; }
    void setPtEtaPhiM(double pt, double eta, double phi, double m);
    void setXYZE(double px, double py, double pz, double e);

  protected:
    UShort_t& packedPt_;
    UShort_t& packedEta_;
    UShort_t& packedPhi_;
    UShort_t& packedM_;

  public:
    /* BEGIN CUSTOM PackedParticle.h.classdef */
  protected:
    void unpack_() const;
    Double_t pt_{0.};
    Double_t eta_{0.};
    Double_t phi_{0.};
    Double_t mass_{0.};
    Bool_t unpacked_{kFALSE};

  public:
    /* END CUSTOM */

    void destructor() override;

  protected:
    PackedParticle(ArrayBase*);

    void doSetStatus_(TTree&, TString const&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&, TString const&) const override;
    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&, TString const&) override;
    void doInit_() override;
  };

  typedef PackedParticle::array_type PackedParticleArray;
  typedef PackedParticle::collection_type PackedParticleCollection;
  typedef Ref<PackedParticle> PackedParticleRef;
  typedef RefVector<PackedParticle> PackedParticleRefVector;

  /* BEGIN CUSTOM PackedParticle.h.global */
  /* END CUSTOM */

}

#endif
