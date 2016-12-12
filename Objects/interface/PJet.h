#ifndef PandaTree_Objects_PJet_h
#define PandaTree_Objects_PJet_h
#include "Constants.h"
#include "PMicroJet.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "PGenJet.h"

namespace panda {

  class PJet : public PMicroJet {
  public:
    struct datastore : public PMicroJet::datastore {
      datastore() : PMicroJet::datastore() {}
      ~datastore() { deallocate(); }

      /* PParticle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      /* PParticleM
      Float_t* mass{0};
      */
      /* PMicroJet
      Float_t* csv{0};
      Float_t* qgl{0};
ContainerBase const* constituentsContainer_{0};      std::vector<std::vector<UInt_t>>* constituents_{0};
      */
      Float_t* rawPt{0};
      Float_t* ptCorrUp{0};
      Float_t* ptCorrDown{0};
      Float_t* ptSmear{0};
      Float_t* ptSmearUp{0};
      Float_t* ptSmearDown{0};
      Float_t* nhf{0};
      Float_t* chf{0};
      Bool_t* loose{0};
      Bool_t* tight{0};
      Bool_t* monojet{0};
      ContainerBase const* matchedGenJetContainer_{0};
      UInt_t* matchedGenJet_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef PMicroJet base_type;
    typedef Array<PJet> array_type;
    typedef Collection<PJet> collection_type;

    PJet(char const* name = "");
    PJet(PJet const&);
    PJet(datastore&, UInt_t idx);
    ~PJet();
    PJet& operator=(PJet const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {}) override;
    void setAddress(TTree&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {}) override;
    void resetAddress(TTree&) override;

    void init() override;

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* PParticleM
    Float_t& mass;
    */
    /* PMicroJet
    Float_t& csv;
    Float_t& qgl;
    RefVector<PPFCand> constituents;
    */
    Float_t& rawPt;
    Float_t& ptCorrUp;
    Float_t& ptCorrDown;
    Float_t& ptSmear;
    Float_t& ptSmearUp;
    Float_t& ptSmearDown;
    Float_t& nhf;
    Float_t& chf;
    Bool_t& loose;
    Bool_t& tight;
    Bool_t& monojet;
    Ref<PGenJet> matchedGenJet;

    /* BEGIN CUSTOM PJet.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    PJet(ArrayBase*);
  };

  typedef PJet::array_type PJetArray;
  typedef PJet::collection_type PJetCollection;
  typedef Ref<PJet> PJetRef;
  typedef RefVector<PJet> PJetRefVector;

  /* BEGIN CUSTOM PJet.h.global */
  /* END CUSTOM */

}

#endif
