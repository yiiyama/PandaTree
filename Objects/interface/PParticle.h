#ifndef PandaTree_Objects_PParticle_h
#define PandaTree_Objects_PParticle_h
#include "Constants.h"
#include "../../Framework/interface/ContainerElement.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class PParticle : public ContainerElement {
  public:
    struct datastore : public ContainerElement::datastore {
      datastore() : ContainerElement::datastore() {}
      ~datastore() { deallocate(); }

      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef ContainerElement base_type;
    typedef Array<PParticle> array_type;
    typedef Collection<PParticle> collection_type;

    PParticle(char const* name = "");
    PParticle(PParticle const&);
    PParticle(datastore&, UInt_t idx);
    ~PParticle();
    PParticle& operator=(PParticle const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;
    void resetAddress(TTree&) override;

    void init() override;

    LorentzVectorM p4() const { return LorentzVectorM(pt, eta, phi, m()); }
    TLorentzVector p4v() const { TLorentzVector p4; p4.SetPtEtaPhiM(pt, eta, phi, m()); return p4; }
    double e() const { return std::sqrt(std::pow(pt * std::cosh(eta), 2.) + m() * m()); }
    double p() const { return pt * std::cosh(eta); }
    double px() const { return pt * std::cos(phi); }
    double py() const { return pt * std::sin(phi); }
    double pz() const { return pt * std::sinh(eta); }
    virtual double m() const { return 0.; }
    double dEta(PParticle const& p) const { return eta - p.eta; }
    double dPhi(PParticle const& p) const { return TVector2::Phi_mpi_pi(phi - p.phi); }
    double dR2(PParticle const& p) const { double d1(dEta(p)); double d2(dPhi(p)); return d1 * d1 + d2 * d2; }
    double dR(PParticle const& p) const { return std::sqrt(dR2(p)); }

    Float_t& pt;
    Float_t& eta;
    Float_t& phi;

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PParticle(ArrayBase*);
  };

  typedef PParticle::array_type PParticleArray;
  typedef PParticle::collection_type PParticleCollection;
  typedef Ref<PParticle> PParticleRef;
  typedef RefVector<PParticle> PParticleRefVector;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
