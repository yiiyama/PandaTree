#ifndef PandaTree_Objects_FatJet_h
#define PandaTree_Objects_FatJet_h
#include "Constants.h"
#include "Jet.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "MicroJet.h"

namespace panda {

  class FatJet : public Jet {
  public:
    struct datastore : public Jet::datastore {
      datastore() : Jet::datastore() {}
      ~datastore() { deallocate(); }

      /* Particle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      /* ParticleM
      Float_t* mass{0};
      */
      /* MicroJet
      Float_t* csv{0};
      Float_t* qgl{0};
      */
      /* Jet
      Float_t* rawPt{0};
      Float_t* ptCorrUp{0};
      Float_t* ptCorrDown{0};
      Float_t* ptSmear{0};
      Float_t* ptSmearUp{0};
      Float_t* ptSmearDown{0};
      Float_t* nhf{0};
      Float_t* chf{0};
      Float_t* puid{0};
      Bool_t* loose{0};
      Bool_t* tight{0};
      Bool_t* monojet{0};
      ContainerBase const* matchedGenJetContainer_{0};
      Int_t* matchedGenJet_{0};
ContainerBase const* constituentsContainer_{0};      std::vector<std::vector<Int_t>>* constituents_{0};
      */
      Float_t* tau1{0};
      Float_t* tau2{0};
      Float_t* tau3{0};
      Float_t* mSD{0};
      Float_t* tau1SD{0};
      Float_t* tau2SD{0};
      Float_t* tau3SD{0};
      Float_t* htt_mass{0};
      Float_t* htt_frec{0};
      Float_t (*ecfs)[3][4][4]{0};
ContainerBase const* subjetsContainer_{0};      std::vector<std::vector<Int_t>>* subjets_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Jet base_type;
    typedef Array<FatJet> array_type;
    typedef Collection<FatJet> collection_type;

    FatJet(char const* name = "");
    FatJet(FatJet const&);
    FatJet(datastore&, UInt_t idx);
    ~FatJet();
    FatJet& operator=(FatJet const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {}) override;
    void setAddress(TTree&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {}) override;
    void resetAddress(TTree&) override;

    void init() override;

    double get_ecf(int o_, int N_, int ib_) const;
    bool set_ecf(int o_, int N_, int ib_, float x_);

    /* Particle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* ParticleM
    Float_t& mass;
    */
    /* MicroJet
    Float_t& csv;
    Float_t& qgl;
    */
    /* Jet
    Float_t& rawPt;
    Float_t& ptCorrUp;
    Float_t& ptCorrDown;
    Float_t& ptSmear;
    Float_t& ptSmearUp;
    Float_t& ptSmearDown;
    Float_t& nhf;
    Float_t& chf;
    Float_t& puid;
    Bool_t& loose;
    Bool_t& tight;
    Bool_t& monojet;
    Ref<GenJet> matchedGenJet;
    RefVector<PFCand> constituents;
    */
    Float_t& tau1;
    Float_t& tau2;
    Float_t& tau3;
    Float_t& mSD;
    Float_t& tau1SD;
    Float_t& tau2SD;
    Float_t& tau3SD;
    Float_t& htt_mass;
    Float_t& htt_frec;
    Float_t (&ecfs)[3][4][4];
    RefVector<MicroJet> subjets;

    /* BEGIN CUSTOM FatJet.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    FatJet(ArrayBase*);
  };

  typedef FatJet::array_type FatJetArray;
  typedef FatJet::collection_type FatJetCollection;
  typedef Ref<FatJet> FatJetRef;
  typedef RefVector<FatJet> FatJetRefVector;

  /* BEGIN CUSTOM FatJet.h.global */
  /* END CUSTOM */

}

#endif
