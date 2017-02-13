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
    struct datastore : public Lepton::datastore {
      datastore() : Lepton::datastore() {}
      ~datastore() { deallocate(); }

      /* ParticleP
      Float_t* pt_{0};
      Float_t* eta_{0};
      Float_t* phi_{0};
      */
      /* Lepton
      Short_t* q{0};
      Bool_t* loose{0};
      Bool_t* medium{0};
      Bool_t* tight{0};
      Float_t* chiso{0};
      Float_t* nhiso{0};
      Float_t* phoiso{0};
      Float_t* puiso{0};
      ContainerBase const* matchedGenContainer_{0};
      Int_t* matchedGen_{0};
      */
      Bool_t* mediumBtoF{0};
      Bool_t (*triggerMatch)[nMuonTriggerObjects]{0};

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

    typedef Array<Muon> array_type;
    typedef Collection<Muon> collection_type;

    typedef Lepton base_type;

    Muon(char const* name = "");
    Muon(Muon const&);
    Muon(datastore&, UInt_t idx);
    ~Muon();
    Muon& operator=(Muon const&);

    double m() const override { return 1.05658e-2; }
    double combiso() const override { return chiso + std::max(nhiso + phoiso - 0.5 * puiso, 0.); }

    /* Lepton
    Short_t& q;
    Bool_t& loose;
    Bool_t& medium;
    Bool_t& tight;
    Float_t& chiso;
    Float_t& nhiso;
    Float_t& phoiso;
    Float_t& puiso;
    Ref<GenParticle> matchedGen;
    */
    Bool_t& mediumBtoF;
    Bool_t (&triggerMatch)[nMuonTriggerObjects];

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

    void destructor() override;

  protected:
    Muon(ArrayBase*);

    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&, TString const&) override;
    void doInit_() override;
  };

  typedef Muon::array_type MuonArray;
  typedef Muon::collection_type MuonCollection;
  typedef Ref<Muon> MuonRef;
  typedef RefVector<Muon> MuonRefVector;

  /* BEGIN CUSTOM Muon.h.global */
  /* END CUSTOM */

}

#endif
