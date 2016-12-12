#ifndef PandaTree_Objects_GenJet_h
#define PandaTree_Objects_GenJet_h
#include "Constants.h"
#include "ParticleM.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class GenJet : public ParticleM {
  public:
    struct datastore : public ParticleM::datastore {
      datastore() : ParticleM::datastore() {}
      ~datastore() { deallocate(); }

      /* Particle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      /* ParticleM
      Float_t* mass{0};
      */
      Int_t* pdgid{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef ParticleM base_type;
    typedef Array<GenJet> array_type;
    typedef Collection<GenJet> collection_type;

    GenJet(char const* name = "");
    GenJet(GenJet const&);
    GenJet(datastore&, UInt_t idx);
    ~GenJet();
    GenJet& operator=(GenJet const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {}) override;
    void setAddress(TTree&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {}) override;
    void resetAddress(TTree&) override;

    void init() override;

    /* Particle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* ParticleM
    Float_t& mass;
    */
    Int_t& pdgid;

    /* BEGIN CUSTOM GenJet.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    GenJet(ArrayBase*);
  };

  typedef GenJet::array_type GenJetArray;
  typedef GenJet::collection_type GenJetCollection;
  typedef Ref<GenJet> GenJetRef;
  typedef RefVector<GenJet> GenJetRefVector;

  /* BEGIN CUSTOM GenJet.h.global */
  /* END CUSTOM */

}

#endif
