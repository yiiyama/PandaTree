#ifndef PandaTree_Objects_PFCandBase_h
#define PandaTree_Objects_PFCandBase_h
#include "Constants.h"
#include "Particle.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "RecoVertex.h"
#include "PackedTrack.h"

namespace panda {

  class PFCandBase : public Particle {
  public:
    enum PType {
      hp,
      hm,
      ep,
      em,
      mup,
      mum,
      gamma,
      h0,
      h_HF,
      egamma_HF,
      Xp,
      Xm,
      X,
      nPTypes
    };

    static TString PTypeName[nPTypes];

    static int const q_[nPTypes];
    static int const pdgId_[nPTypes];

    struct datastore : public Particle::datastore {
      datastore() : Particle::datastore() {}
      ~datastore() { deallocate(); }

      UChar_t* ptype{0};
      ContainerBase const* vertexContainer_{0};
      Short_t* vertex_{0}; ///< transient
      ContainerBase const* trackContainer_{0};
      Short_t* track_{0}; ///< transient
      Float_t* hCalFrac{0};

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

    typedef Array<PFCandBase> array_type;
    typedef Collection<PFCandBase> collection_type;

    typedef Particle base_type;

    PFCandBase(datastore&, UInt_t idx);
    ~PFCandBase();
    PFCandBase& operator=(PFCandBase const&);

    static char const* typeName() { return "PFCandBase"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    virtual double puppiW() const = 0;
    virtual double puppiWNoLep() const = 0;
    virtual void setPuppiW(double w, double wnl) = 0;
    TLorentzVector puppiP4() const { TLorentzVector p4; p4.SetPtEtaPhiM(pt() * puppiW(), eta(), phi(), m() * puppiW()); return p4; }
    TLorentzVector puppiNoLepP4() const { TLorentzVector p4; p4.SetPtEtaPhiM(pt() * puppiWNoLep(), eta(), phi(), m() * puppiWNoLep()); return p4; }
    int q() const { return q_[ptype]; }
    int pdgId() const { return pdgId_[ptype]; }
    TVector3 pca() const;
    double dxy(TVector3 const&) const;
    double dz(TVector3 const&) const;

    UChar_t& ptype;
    Ref<RecoVertex> vertex;
    Ref<PackedTrack> track;
    Float_t& hCalFrac;

    /* BEGIN CUSTOM PFCandBase.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor(Bool_t recursive = kFALSE);

  protected:
    PFCandBase(ArrayBase*);

    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<PFCandBase> PFCandBaseArray;
  typedef Collection<PFCandBase> PFCandBaseCollection;
  typedef Ref<PFCandBase> PFCandBaseRef;
  typedef RefVector<PFCandBase> PFCandBaseRefVector;

  /* BEGIN CUSTOM PFCandBase.h.global */
  /* END CUSTOM */

}

#endif
