#ifndef PandaTree_Objects_PJet_h
#define PandaTree_Objects_PJet_h
#include "Constants.h"
#include "PParticleM.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Ref.h"
#include "PPFCand.h"

namespace panda {

  class PJet : public PParticleM {
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
      Float_t* rawPt{0};
      Float_t* ptCorrUp{0};
      Float_t* ptCorrDown{0};
      Float_t* ptResCorr{0};
      Float_t* phiResCorr{0};
      Float_t* csv{0};
      Float_t* qgl{0};
      Float_t* nhf{0};
      Float_t* chf{0};
      UInt_t* id{0};
      UInt_t* nConstituents{0};
      UInt_t (*constituents_)[128]{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
    };

    typedef Array<PJet, PParticleM::array_type> array_type;
    typedef Collection<PJet, PParticleM::collection_type> collection_type;

    PJet(char const* name = "");
    PJet(PJet const&);
    PJet(datastore&, UInt_t idx);
    ~PJet();
    PJet& operator=(PJet const&);

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
    Float_t& rawPt;
    Float_t& ptCorrUp;
    Float_t& ptCorrDown;
    Float_t& ptResCorr;
    Float_t& phiResCorr;
    Float_t& csv;
    Float_t& qgl;
    Float_t& nhf;
    Float_t& chf;
    UInt_t& id;
    UInt_t& nConstituents;
    PPFCandRef constituents[128]{};

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PJet(ArrayBase*);
  };

  typedef PJet::array_type PJetArray;
  typedef PJet::collection_type PJetCollection;
  typedef Ref<PJet> PJetRef;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
