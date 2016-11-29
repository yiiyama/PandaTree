#ifndef PandaTree_Objects_PFatJet_h
#define PandaTree_Objects_PFatJet_h
#include "Constants.h"
#include "PJet.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class PFatJet : public PJet {
  public:
    struct datastore : public PJet::datastore {
      datastore() : PJet::datastore() {}
      ~datastore() { deallocate(); }

      /* PParticle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      /* PParticleM
      Float_t* mass{0};
      */
      /* PJet
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
      std::vector<std::vector<UInt_t>>* constituents_{0};
      */
      Float_t* tau1{0};
      Float_t* tau2{0};
      Float_t* tau3{0};
      Float_t* mSD{0};
      Float_t* tau1SD{0};
      Float_t* tau2SD{0};
      Float_t* tau3SD{0};
      Float_t* htt_mass{0};
      Float_t* htt_frec{0};
      Float_t (*ecfs)[3][4][4]{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef PJet base_type;
    typedef Array<PFatJet> array_type;
    typedef Collection<PFatJet> collection_type;

    PFatJet(char const* name = "");
    PFatJet(PFatJet const&);
    PFatJet(datastore&, UInt_t idx);
    ~PFatJet();
    PFatJet& operator=(PFatJet const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;
    void resetAddress(TTree&) override;

    void init() override;

    float get_ecf(short o_, short N_, int ib_) const;
    int set_ecf(int o_, int N_, int ib_, float x_);

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* PParticleM
    Float_t& mass;
    */
    /* PJet
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
    RefVector<PPFCand> constituents;
    */
    Float_t& tau1;
    Float_t& tau2;
    Float_t& tau3;
    Float_t& mSD;
    Float_t& tau1SD;
    Float_t& tau2SD;
    Float_t& tau3SD;
    Float_t& htt_mass;
    Float_t& htt_frec;
    Float_t (&ecfs)[3][4][4];

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PFatJet(ArrayBase*);
  };

  typedef PFatJet::array_type PFatJetArray;
  typedef PFatJet::collection_type PFatJetCollection;
  typedef Ref<PFatJet> PFatJetRef;
  typedef RefVector<PFatJet> PFatJetRefVector;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
