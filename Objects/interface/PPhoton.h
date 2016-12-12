#ifndef PandaTree_Objects_PPhoton_h
#define PandaTree_Objects_PPhoton_h
#include "Constants.h"
#include "PParticle.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "PSuperCluster.h"
#include "PGenParticle.h"

namespace panda {

  class PPhoton : public PParticle {
  public:
    struct datastore : public PParticle::datastore {
      datastore() : PParticle::datastore() {}
      ~datastore() { deallocate(); }

      /* PParticle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      Float_t* scRawPt{0};
      Float_t* chiso{0};
      Float_t* chisoWorst{0};
      Float_t* nhiso{0};
      Float_t* phoiso{0};
      Float_t* sieie{0};
      Float_t* sipip{0};
      Float_t* hOverE{0};
      Float_t* geniso{0};
      Float_t* mipEnergy{0};
      Float_t* e33{0};
      Float_t* e4{0};
      Float_t* emax{0};
      Float_t* e2nd{0};
      Float_t* r9{0};
      Float_t* etaWidth{0};
      Float_t* phiWidth{0};
      Float_t* time{0};
      Float_t* timeSpan{0};
      Float_t* genMatchDR{0};
      Bool_t* isEB{0};
      Bool_t* loose{0};
      Bool_t* medium{0};
      Bool_t* tight{0};
      Bool_t* highpt{0};
      Bool_t* pixelVeto{0};
      Bool_t* csafeVeto{0};
      Bool_t (*matchL1)[nPhotonL1Objects]{0};
      Bool_t (*matchHLT)[nPhotonHLTObjects]{0};
      ContainerBase const* superClusterContainer_{0};
      UInt_t* superCluster_{0};
      ContainerBase const* matchedGenContainer_{0};
      UInt_t* matchedGen_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef PParticle base_type;
    typedef Array<PPhoton> array_type;
    typedef Collection<PPhoton> collection_type;

    PPhoton(char const* name = "");
    PPhoton(PPhoton const&);
    PPhoton(datastore&, UInt_t idx);
    ~PPhoton();
    PPhoton& operator=(PPhoton const&);

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
    Float_t& scRawPt;
    Float_t& chiso;
    Float_t& chisoWorst;
    Float_t& nhiso;
    Float_t& phoiso;
    Float_t& sieie;
    Float_t& sipip;
    Float_t& hOverE;
    Float_t& geniso;
    Float_t& mipEnergy;
    Float_t& e33;
    Float_t& e4;
    Float_t& emax;
    Float_t& e2nd;
    Float_t& r9;
    Float_t& etaWidth;
    Float_t& phiWidth;
    Float_t& time;
    Float_t& timeSpan;
    Float_t& genMatchDR;
    Bool_t& isEB;
    Bool_t& loose;
    Bool_t& medium;
    Bool_t& tight;
    Bool_t& highpt;
    Bool_t& pixelVeto;
    Bool_t& csafeVeto;
    Bool_t (&matchL1)[nPhotonL1Objects];
    Bool_t (&matchHLT)[nPhotonHLTObjects];
    Ref<PSuperCluster> superCluster;
    Ref<PGenParticle> matchedGen;

    /* BEGIN CUSTOM PPhoton.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    PPhoton(ArrayBase*);
  };

  typedef PPhoton::array_type PPhotonArray;
  typedef PPhoton::collection_type PPhotonCollection;
  typedef Ref<PPhoton> PPhotonRef;
  typedef RefVector<PPhoton> PPhotonRefVector;

  /* BEGIN CUSTOM PPhoton.h.global */
  /* END CUSTOM */

}

#endif
