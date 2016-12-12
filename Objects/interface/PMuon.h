#ifndef PandaTree_Objects_PMuon_h
#define PandaTree_Objects_PMuon_h
#include "Constants.h"
#include "PLepton.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class PMuon : public PLepton {
  public:
    struct datastore : public PLepton::datastore {
      datastore() : PLepton::datastore() {}
      ~datastore() { deallocate(); }

      /* PParticle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      /* PLepton
      Short_t* q{0};
      Bool_t* loose{0};
      Bool_t* medium{0};
      Bool_t* tight{0};
      Float_t* chiso{0};
      Float_t* nhiso{0};
      Float_t* phoiso{0};
      Float_t* puiso{0};
      Bool_t* tauDecay{0};
      Bool_t* hadDecay{0};
      ContainerBase const* matchedGenContainer_{0};
      UInt_t* matchedGen_{0};
      */
      Bool_t (*matchHLT)[nMuonHLTObjects]{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef PLepton base_type;
    typedef Array<PMuon> array_type;
    typedef Collection<PMuon> collection_type;

    PMuon(char const* name = "");
    PMuon(PMuon const&);
    PMuon(datastore&, UInt_t idx);
    ~PMuon();
    PMuon& operator=(PMuon const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {}) override;
    void setAddress(TTree&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {}) override;
    void resetAddress(TTree&) override;

    void init() override;

    double m() const override { return 1.05658e-2; }
    double combiso() const override { return chiso + std::max(nhiso + phoiso - 0.5 * puiso, 0.); }

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* PLepton
    Short_t& q;
    Bool_t& loose;
    Bool_t& medium;
    Bool_t& tight;
    Float_t& chiso;
    Float_t& nhiso;
    Float_t& phoiso;
    Float_t& puiso;
    Bool_t& tauDecay;
    Bool_t& hadDecay;
    Ref<PGenParticle> matchedGen;
    */
    Bool_t (&matchHLT)[nMuonHLTObjects];

    /* BEGIN CUSTOM PMuon.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    PMuon(ArrayBase*);
  };

  typedef PMuon::array_type PMuonArray;
  typedef PMuon::collection_type PMuonCollection;
  typedef Ref<PMuon> PMuonRef;
  typedef RefVector<PMuon> PMuonRefVector;

  /* BEGIN CUSTOM PMuon.h.global */
  /* END CUSTOM */

}

#endif
