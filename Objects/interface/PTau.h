#ifndef PandaTree_Objects_PTau_h
#define PandaTree_Objects_PTau_h
#include "Constants.h"
#include "PParticleM.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Ref.h"

namespace panda {

  class PTau : public PParticleM {
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
      Text_t const** q{0};
      Bool_t* decayMode{0};
      Float_t* isoDeltaBetaCorr{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
    };

    typedef Array<PTau, PParticleM::array_type> array_type;
    typedef Collection<PTau, PParticleM::collection_type> collection_type;

    PTau(char const* name = "");
    PTau(PTau const&);
    PTau(datastore&, UInt_t idx);
    ~PTau();
    PTau& operator=(PTau const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;

    void init() override;

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* PParticleM
    Float_t& mass;
    */
    Text_t const*& q;
    Bool_t& decayMode;
    Float_t& isoDeltaBetaCorr;

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PTau(ArrayBase*);
  };

  typedef PTau::array_type PTauArray;
  typedef PTau::collection_type PTauCollection;
  typedef Ref<PTau> PTauRef;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
