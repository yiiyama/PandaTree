#ifndef PandaTree_Objects_PMicroJet_h
#define PandaTree_Objects_PMicroJet_h
#include "Constants.h"
#include "PParticleM.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "PPFCand.h"

namespace panda {

  class PMicroJet : public PParticleM {
  public:
    struct datastore : public PParticleM::datastore {
      datastore() : PParticleM::datastore() {}
      ~datastore() { deallocate(); }

      /* PParticle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      /* PParticleM
      Float_t* mass{0};
      */
      Float_t* csv{0};
      Float_t* qgl{0};
ContainerBase const* constituentsContainer_{0};      std::vector<std::vector<UInt_t>>* constituents_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef PParticleM base_type;
    typedef Array<PMicroJet> array_type;
    typedef Collection<PMicroJet> collection_type;

    PMicroJet(char const* name = "");
    PMicroJet(PMicroJet const&);
    PMicroJet(datastore&, UInt_t idx);
    ~PMicroJet();
    PMicroJet& operator=(PMicroJet const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;
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
    Float_t& csv;
    Float_t& qgl;
    RefVector<PPFCand> constituents;

    /* BEGIN CUSTOM PMicroJet.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    PMicroJet(ArrayBase*);
  };

  typedef PMicroJet::array_type PMicroJetArray;
  typedef PMicroJet::collection_type PMicroJetCollection;
  typedef Ref<PMicroJet> PMicroJetRef;
  typedef RefVector<PMicroJet> PMicroJetRefVector;

  /* BEGIN CUSTOM PMicroJet.h.global */
  /* END CUSTOM */

}

#endif
