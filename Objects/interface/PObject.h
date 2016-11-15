#ifndef PandaTree_Objects_PObject_h
#define PandaTree_Objects_PObject_h
#include "Constants.h"
#include "../../Interface/interface/Object.h"
#include "../../Interface/interface/Container.h"

namespace panda {

  class PObject : public ContainerElement {
  public:
    typedef Container<PObject, Collection> container_type;

    struct array_data : public ContainerElement::array_data {
      static UInt_t const NMAX{256};

      array_data() : ContainerElement::array_data() {}

      Float_t pt[NMAX]{};
      Float_t eta[NMAX]{};
      Float_t phi[NMAX]{};

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PObject();
    PObject(PObject const&);
    PObject(array_data&, UInt_t idx);
    ~PObject();
    PObject& operator=(PObject const&);

    void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, TString const&, utils::BranchList const& = {"*"}) override;

    void init() override;

    LorentzVectorM p4() const { return LorentzVectorM(pt, eta, phi, m()); }
    TLorentzVector p4v() const { TLorentzVector p4; p4.SetPtEtaPhiM(pt, eta, phi, m()); return p4; }
    virtual double e() const { return pt * std::cosh(eta); }
    double p() const { return pt * std::cosh(eta); }
    double px() const { return pt * std::cos(phi); }
    double py() const { return pt * std::sin(phi); }
    double pz() const { return pt * std::sinh(eta); }
    virtual double m() const { return 0.; }
    double dEta(PObject const& p) const { return eta - p.eta; }
    double dPhi(PObject const& p) const { return TVector2::Phi_mpi_pi(phi - p.phi); }
    double dR2(PObject const& p) const { double d1(dEta(p)); double d2(dPhi(p)); return d1 * d1 + d2 * d2; }
    double dR(PObject const& p) const { return std::sqrt(dR2(p)); }

    Float_t& pt;
    Float_t& eta;
    Float_t& phi;

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PObject(utils::AllocatorBase const&);
  };

  typedef PObject::container_type PObjectCollection;

  /* BEGIN CUSTOM */
  inline
  bool sortPObjects(PObject* o1, PObject* o2)
  {
    return o1->pt > o2->pt;
  }
  /* END CUSTOM */

}

#endif
