#ifndef PandaTree_Objects_Jet_h
#define PandaTree_Objects_Jet_h
#include "Constants.h"
#include "MicroJet.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "GenJet.h"
#include "PFCand.h"

namespace panda {

  class Jet : public MicroJet {
  public:
    struct datastore : public MicroJet::datastore {
      datastore() : MicroJet::datastore() {}
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

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef MicroJet base_type;
    typedef Array<Jet> array_type;
    typedef Collection<Jet> collection_type;

    Jet(char const* name = "");
    Jet(Jet const&);
    Jet(datastore&, UInt_t idx);
    ~Jet();
    Jet& operator=(Jet const&);

    void setStatus(TTree&, utils::BranchList const& = {"*"}) override;
    UInt_t setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    UInt_t book(TTree&, utils::BranchList const& = {"*"}) override;
    void releaseTree(TTree&) override;

    void init() override;

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

    /* BEGIN CUSTOM Jet.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    Jet(ArrayBase*);
  };

  typedef Jet::array_type JetArray;
  typedef Jet::collection_type JetCollection;
  typedef Ref<Jet> JetRef;
  typedef RefVector<Jet> JetRefVector;

  /* BEGIN CUSTOM Jet.h.global */
  /* END CUSTOM */

}

#endif
