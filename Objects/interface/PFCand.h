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
      UShort_t* packedPt{0};
      Short_t* packedPhi{0};
      UShort_t* packedM{0};
      */
      Short_t* packedEta{0};
      Char_t* packedPuppiW{0};
      Char_t* packedPuppiWNoLepDiff{0};
      UChar_t* ptype{0};

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

    static int q_[nPTypes];
    static int pdgId_[nPTypes];

    double puppiW() const { unpack_(); return puppiW_; }
    double puppiWNoLep() const { unpack_(); return puppiWNoLep_; }
    void setPuppiW(double w, double wnl);
    TLorentzVector puppiP4() const { TLorentzVector p4; p4.SetPtEtaPhiM(pt() * puppiW(), eta(), phi(), m() * puppiW()); return p4; }
    TLorentzVector puppiNoLepP4() const { TLorentzVector p4; p4.SetPtEtaPhiM(pt() * puppiWNoLep(), eta(), phi(), m() * puppiWNoLep()); return p4; }
    int q() const { return q_[ptype]; }
    int pdgId() const { return pdgId_[ptype]; }

    /* PackedParticle
    UShort_t& packedPt;
    Short_t& packedPhi;
    UShort_t& packedM;
    */
    Short_t& packedEta;
    Char_t& packedPuppiW;
    Char_t& packedPuppiWNoLepDiff;
    UChar_t& ptype;

    /* BEGIN CUSTOM PFCand.h.classdef */
  protected:
    void pack_() override;
    void unpack_() const override;

    mutable double puppiW_{0.};
    mutable double puppiWNoLep_{0.};

  public:
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
