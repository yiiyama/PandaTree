#ifndef PandaTree_Objects_PFatJet_h
#define PandaTree_Objects_PFatJet_h
#include "Constants.h"
#include "PJet.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class PFatJet : public PJet {
  public:
    struct datastore : public PJet::datastore {
      datastore() : PJet::datastore() {}
      ~datastore() { deallocate(); }

      /* PParticle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      /* PParticleM
      Float_t* mass{0};
      */
      /* PJet
      Float_t* rawPt{0};
      Float_t* ptCorrUp{0};
      Float_t* ptCorrDown{0};
      Float_t* ptSmear{0};
      Float_t* ptSmearUp{0};
      Float_t* ptSmearDown{0};
      Float_t* csv{0};
      Float_t* qgl{0};
      Float_t* nhf{0};
      Float_t* chf{0};
      Bool_t* loose{0};
      Bool_t* tight{0};
      Bool_t* monojet{0};
      ContainerBase const* matchedGenJetContainer_{0};
      UInt_t* matchedGenJet_{0};
ContainerBase const* constituentsContainer_{0};      std::vector<std::vector<UInt_t>>* constituents_{0};
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
ContainerBase const* subjetsContainer_{0};      std::vector<std::vector<UInt_t>>* subjets_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef PJet base_type;
    typedef Array<PFatJet> array_type;
    typedef Collection<PFatJet> collection_type;

    PFatJet(char const* name = "");
    PFatJet(PFatJet const&);
    PFatJet(datastore&, UInt_t idx);
    ~PFatJet();
    PFatJet& operator=(PFatJet const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;
    void resetAddress(TTree&) override;

    void init() override;

    double get_ecf(int o_, int N_, int ib_) const;
    bool set_ecf(int o_, int N_, int ib_, float x_);

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* PParticleM
    Float_t& mass;
    */
    /* PJet
    Float_t& rawPt;
    Float_t& ptCorrUp;
    Float_t& ptCorrDown;
    Float_t& ptSmear;
    Float_t& ptSmearUp;
    Float_t& ptSmearDown;
    Float_t& csv;
    Float_t& qgl;
    Float_t& nhf;
    Float_t& chf;
    Bool_t& loose;
    Bool_t& tight;
    Bool_t& monojet;
    Ref<PGenJet> matchedGenJet;
    RefVector<PPFCand> constituents;
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
    RefVector<PJet> subjets;

    /* BEGIN CUSTOM PFatJet.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    PFatJet(ArrayBase*);
  };

  typedef PFatJet::array_type PFatJetArray;
  typedef PFatJet::collection_type PFatJetCollection;
  typedef Ref<PFatJet> PFatJetRef;
  typedef RefVector<PFatJet> PFatJetRefVector;

  /* BEGIN CUSTOM PFatJet.h.global */
  /* END CUSTOM */

}

#endif
