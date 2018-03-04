#ifndef PandaTree_Objects_Muon_h
#define PandaTree_Objects_Muon_h
#include "Constants.h"
#include "Lepton.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class Muon : public Lepton {
  public:
    enum TriggerObject {
      fMu17Mu8FirstLeg,
      fMu17Mu8SecondLeg,
      fIsoMu22er,
      fIsoTkMu22er,
      fIsoMu24,
      fIsoTkMu24,
      fIsoMu27,
      fIsoTkMu27,
      fMu50,
      nTriggerObjects
    };

    static TString TriggerObjectName[nTriggerObjects];

    struct datastore : public Lepton::datastore {
      datastore() : Lepton::datastore() {}
      ~datastore() { deallocate(); }

      /* ParticleP
      Float_t* pt_{0};
      Float_t* eta_{0};
      Float_t* phi_{0};
      */
      /* Lepton
      Float_t* pfPt{0};
      Char_t* charge{0};
      Bool_t* loose{0};
      Bool_t* medium{0};
      Bool_t* tight{0};
      Bool_t* hltsafe{0};
      Float_t* chIso{0};
      Float_t* nhIso{0};
      Float_t* phIso{0};
      Float_t* puIso{0};
      Float_t* dxy{0};
      Float_t* dz{0};
      ContainerBase const* matchedPFContainer_{0};
      Short_t* matchedPF_{0};
      ContainerBase const* matchedGenContainer_{0};
      Short_t* matchedGen_{0};
      ContainerBase const* vertexContainer_{0};
      Short_t* vertex_{0};
      */
      Bool_t* soft{0};
      Bool_t* mediumBtoF{0};
      Bool_t* global{0};
      Bool_t* pf{0};
      Bool_t* tracker{0};
      Float_t* validFraction{0};
      UShort_t* nValidMuon{0};
      UShort_t* nValidPixel{0};
      UShort_t* trkLayersWithMmt{0};
      UShort_t* pixLayersWithMmt{0};
      UShort_t* nMatched{0};
      Float_t* normChi2{0};
      UShort_t* chi2LocalPosition{0};
      UShort_t* trkKink{0};
      Float_t* segmentCompatibility{0};
      Float_t* r03Iso{0};
      Bool_t (*triggerMatch)[nTriggerObjects]{0};

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

    typedef Array<Muon> array_type;
    typedef Collection<Muon> collection_type;

    typedef Lepton base_type;

    Muon(char const* name = "");
    Muon(Muon const&);
    Muon(datastore&, UInt_t idx);
    ~Muon();
    Muon& operator=(Muon const&);

    static char const* typeName() { return "Muon"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    double m() const override { return 1.05658e-1; }
    double combIso() const override { return chIso + std::max(nhIso + phIso - 0.5 * puIso, 0.); }

    /* Lepton
    Float_t& pfPt; ///< for E: Pt of the dR-closest PF candidate; for Mu: pfP4().pt()
    Char_t& charge;
    Bool_t& loose;
    Bool_t& medium;
    Bool_t& tight;
    Bool_t& hltsafe;
    Float_t& chIso;
    Float_t& nhIso;
    Float_t& phIso;
    Float_t& puIso;
    Float_t& dxy;
    Float_t& dz;
    Ref<PFCand> matchedPF;
    Ref<GenParticle> matchedGen;
    Ref<Vertex> vertex;
    */
    Bool_t& soft;
    Bool_t& mediumBtoF;
    Bool_t& global;
    Bool_t& pf;
    Bool_t& tracker;
    Float_t& validFraction;
    UShort_t& nValidMuon;
    UShort_t& nValidPixel;
    UShort_t& trkLayersWithMmt;
    UShort_t& pixLayersWithMmt;
    UShort_t& nMatched;
    Float_t& normChi2;
    UShort_t& chi2LocalPosition;
    UShort_t& trkKink;
    Float_t& segmentCompatibility;
    Float_t& r03Iso;
    Bool_t (&triggerMatch)[nTriggerObjects];

  protected:
    /* ParticleP
    Float_t& pt_;
    Float_t& eta_;
    Float_t& phi_;
    */

  public:
    /* BEGIN CUSTOM Muon.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor(Bool_t recursive = kFALSE);

  protected:
    Muon(ArrayBase*);

    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<Muon> MuonArray;
  typedef Collection<Muon> MuonCollection;
  typedef Ref<Muon> MuonRef;
  typedef RefVector<Muon> MuonRefVector;

  /* BEGIN CUSTOM Muon.h.global */
  /* END CUSTOM */

}

#endif
