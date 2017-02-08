#ifndef PandaTree_Objects_PFCand_h
#define PandaTree_Objects_PFCand_h
#include "Constants.h"
#include "PackedParticle.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class PFCand : public PackedParticle {
  public:
    struct datastore : public PackedParticle::datastore {
      datastore() : PackedParticle::datastore() {}
      ~datastore() { deallocate(); }

      /* PackedParticle
      UShort_t* packedPt_{0};
      UShort_t* packedEta_{0};
      UShort_t* packedPhi_{0};
      UShort_t* packedM_{0};
      */
      Short_t* q{0};
      Float_t* puppiW{0};
      Float_t* puppiWNoLep{0};
      Int_t* pftype{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<PFCand> array_type;
    typedef Collection<PFCand> collection_type;

    typedef PackedParticle base_type;

    PFCand(char const* name = "");
    PFCand(PFCand const&);
    PFCand(datastore&, UInt_t idx);
    ~PFCand();
    PFCand& operator=(PFCand const&);

    TLorentzVector puppiP4() const { TLorentzVector p4; p4.SetPtEtaPhiM(pt() * puppiW, eta(), phi(), m() * puppiW); return p4; }
    TLorentzVector puppiNoLepP4() const { TLorentzVector p4; p4.SetPtEtaPhiM(pt() * puppiWNoLep, eta(), phi(), m() * puppiWNoLep); return p4; }

    /* PackedParticle
    */
    Short_t& q;
    Float_t& puppiW;
    Float_t& puppiWNoLep;
    Int_t& pftype;
  protected:
    /* PackedParticle
    UShort_t& packedPt_;
    UShort_t& packedEta_;
    UShort_t& packedPhi_;
    UShort_t& packedM_;
    */

  public:
    /* BEGIN CUSTOM PFCand.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    PFCand(ArrayBase*);

    void doSetStatus_(TTree&, TString const&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&, TString const&) const override;
    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&, TString const&) override;
    void doInit_() override;
  };

  typedef PFCand::array_type PFCandArray;
  typedef PFCand::collection_type PFCandCollection;
  typedef Ref<PFCand> PFCandRef;
  typedef RefVector<PFCand> PFCandRefVector;

  /* BEGIN CUSTOM PFCand.h.global */
  /* END CUSTOM */

}

#endif
