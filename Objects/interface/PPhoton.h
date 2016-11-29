#ifndef PandaTree_Objects_PPhoton_h
#define PandaTree_Objects_PPhoton_h
#include "Constants.h"
#include "PParticle.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "PSuperCluster.h"

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
      Float_t* chiso{0};
      Float_t* chworstiso{0};
      Float_t* chisoMax{0};
      Float_t* nhiso{0};
      Float_t* phiso{0};
      Float_t* ecaliso{0};
      Float_t* hcaliso{0};
      Float_t* sieie{0};
      Float_t* sipip{0};
      Float_t* hOverE{0};
      Float_t* geniso{0};
      Float_t* mipEnergy{0};
      Float_t* e33{0};
      Float_t* emax{0};
      Float_t* e2nd{0};
      Float_t* r9{0};
      Float_t* etaWidth{0};
      Float_t* phiWidth{0};
      Float_t* time{0};
      Float_t* timeSpan{0};
      Float_t* genMatchDR{0};
      Bool_t* loose{0};
      Bool_t* medium{0};
      Bool_t* tight{0};
      Bool_t* highpt{0};
      Bool_t* pixelVeto{0};
      Bool_t* csafeVeto{0};
      Bool_t (*matchL1)[nPhotonL1Objects]{0};
      UInt_t* superCluster_{0};
      std::vector<TString>* text{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
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

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;
    void resetAddress(TTree&) override;

    void init() override;

    bool isEB() const { return superCluster.isValid() ? std::abs(superCluster->eta) < 1.4442 : false; }

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    Float_t& chiso;
    Float_t& chworstiso;
    Float_t& chisoMax;
    Float_t& nhiso;
    Float_t& phiso;
    Float_t& ecaliso;
    Float_t& hcaliso;
    Float_t& sieie;
    Float_t& sipip;
    Float_t& hOverE;
    Float_t& geniso;
    Float_t& mipEnergy;
    Float_t& e33;
    Float_t& emax;
    Float_t& e2nd;
    Float_t& r9;
    Float_t& etaWidth;
    Float_t& phiWidth;
    Float_t& time;
    Float_t& timeSpan;
    Float_t& genMatchDR;
    Bool_t& loose;
    Bool_t& medium;
    Bool_t& tight;
    Bool_t& highpt;
    Bool_t& pixelVeto;
    Bool_t& csafeVeto;
    Bool_t (&matchL1)[nPhotonL1Objects];
    Ref<PSuperCluster> superCluster;
    TString* text;

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PPhoton(ArrayBase*);
  };

  typedef PPhoton::array_type PPhotonArray;
  typedef PPhoton::collection_type PPhotonCollection;
  typedef Ref<PPhoton> PPhotonRef;
  typedef RefVector<PPhoton> PPhotonRefVector;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
