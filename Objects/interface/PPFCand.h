#ifndef PandaTree_Objects_PPFCand_h
#define PandaTree_Objects_PPFCand_h
#include "Constants.h"
#include "PParticleM.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class PPFCand : public PParticleM {
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
      Short_t* q{0};
      Float_t* puppiW{0};
      Float_t* puppiWNoLep{0};
      Int_t* pftype{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef PParticleM base_type;
    typedef Array<PPFCand> array_type;
    typedef Collection<PPFCand> collection_type;

    PPFCand(char const* name = "");
    PPFCand(PPFCand const&);
    PPFCand(datastore&, UInt_t idx);
    ~PPFCand();
    PPFCand& operator=(PPFCand const&);

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
    Short_t& q;
    Float_t& puppiW;
    Float_t& puppiWNoLep;
    Int_t& pftype;

    /* BEGIN CUSTOM PPFCand.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    PPFCand(ArrayBase*);
  };

  typedef PPFCand::array_type PPFCandArray;
  typedef PPFCand::collection_type PPFCandCollection;
  typedef Ref<PPFCand> PPFCandRef;
  typedef RefVector<PPFCand> PPFCandRefVector;

  /* BEGIN CUSTOM PPFCand.h.global */
  /* END CUSTOM */

}

#endif
