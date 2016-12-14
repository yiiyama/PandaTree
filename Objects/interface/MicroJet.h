#ifndef PandaTree_Objects_MicroJet_h
#define PandaTree_Objects_MicroJet_h
#include "Constants.h"
#include "ParticleM.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class MicroJet : public ParticleM {
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
      Float_t* csv{0};
      Float_t* qgl{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef ParticleM base_type;
    typedef Array<MicroJet> array_type;
    typedef Collection<MicroJet> collection_type;

    MicroJet(char const* name = "");
    MicroJet(MicroJet const&);
    MicroJet(datastore&, UInt_t idx);
    ~MicroJet();
    MicroJet& operator=(MicroJet const&);

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
    Float_t& csv;
    Float_t& qgl;

    /* BEGIN CUSTOM MicroJet.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    MicroJet(ArrayBase*);
  };

  typedef MicroJet::array_type MicroJetArray;
  typedef MicroJet::collection_type MicroJetCollection;
  typedef Ref<MicroJet> MicroJetRef;
  typedef RefVector<MicroJet> MicroJetRefVector;

  /* BEGIN CUSTOM MicroJet.h.global */
  /* END CUSTOM */

}

#endif
