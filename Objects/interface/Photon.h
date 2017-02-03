#ifndef PandaTree_Objects_Photon_h
#define PandaTree_Objects_Photon_h
#include "Constants.h"
#include "Particle.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "SuperCluster.h"
#include "GenParticle.h"

namespace panda {

  class Photon : public Particle {
  public:
    struct datastore : public Particle::datastore {
      datastore() : Particle::datastore() {}
      ~datastore() { deallocate(); }

      /* Particle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
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
      Float_t* eseed{0};
      Float_t* emax{0};
      Float_t* e2nd{0};
      Float_t* r9{0};
      Float_t* etaWidth{0};
      Float_t* phiWidth{0};
      Float_t* time{0};
      Float_t* timeSpan{0};
      Bool_t* loose{0};
      Bool_t* medium{0};
      Bool_t* tight{0};
      Bool_t* highpt{0};
      Bool_t* pixelVeto{0};
      Bool_t* csafeVeto{0};
      Bool_t (*triggerMatch)[nPhotonTriggerObjects]{0};
      ContainerBase const* superClusterContainer_{0};
      Int_t* superCluster_{0};
      ContainerBase const* matchedGenContainer_{0};
      Int_t* matchedGen_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<Photon> array_type;
    typedef Collection<Photon> collection_type;

    typedef Particle base_type;

    Photon(char const* name = "");
    Photon(Photon const&);
    Photon(datastore&, UInt_t idx);
    ~Photon();
    Photon& operator=(Photon const&);


    /* Particle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
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
    Float_t& eseed;
    Float_t& emax;
    Float_t& e2nd;
    Float_t& r9;
    Float_t& etaWidth;
    Float_t& phiWidth;
    Float_t& time;
    Float_t& timeSpan;
    Bool_t& loose;
    Bool_t& medium;
    Bool_t& tight;
    Bool_t& highpt;
    Bool_t& pixelVeto;
    Bool_t& csafeVeto;
    Bool_t (&triggerMatch)[nPhotonTriggerObjects];
    Ref<SuperCluster> superCluster;
    Ref<GenParticle> matchedGen;

    /* BEGIN CUSTOM Photon.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    Photon(ArrayBase*);

    void doSetStatus_(TTree&, TString const&, utils::BranchList const&) override;
    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&, TString const&) override;
    void doInit_() override;
    };

    typedef Photon::array_type PhotonArray;
    typedef Photon::collection_type PhotonCollection;
    typedef Ref<Photon> PhotonRef;
    typedef RefVector<Photon> PhotonRefVector;

  /* BEGIN CUSTOM Photon.h.global */
  /* END CUSTOM */

  }

  #endif
