#ifndef PandaTree_Objects_Electron_h
#define PandaTree_Objects_Electron_h
#include "Constants.h"
#include "Lepton.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "SuperCluster.h"

namespace panda {

  class Electron : public Lepton {
  public:
    struct datastore : public Lepton::datastore {
      datastore() : Lepton::datastore() {}
      ~datastore() { deallocate(); }

      /* ParticleP
      Float_t* pt_{0};
      Float_t* eta_{0};
      Float_t* phi_{0};
      */
      /* Lepton
      Short_t* q{0};
      Bool_t* loose{0};
      Bool_t* medium{0};
      Bool_t* tight{0};
      Float_t* chiso{0};
      Float_t* nhiso{0};
      Float_t* phoiso{0};
      Float_t* puiso{0};
      ContainerBase const* matchedGenContainer_{0};
      Int_t* matchedGen_{0};
      */
      Bool_t* hltsafe{0};
      Float_t* chisoPh{0};
      Float_t* nhisoPh{0};
      Float_t* phisoPh{0};
      Float_t* ecaliso{0};
      Float_t* hcaliso{0};
      Float_t* isoPUOffset{0};
      Float_t* sieie{0};
      Float_t* sipip{0};
      Float_t* eseed{0};
      Float_t* hOverE{0};
      Bool_t* veto{0};
      Bool_t (*triggerMatch)[nElectronTriggerObjects]{0};
      ContainerBase const* superClusterContainer_{0};
      Int_t* superCluster_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<Electron> array_type;
    typedef Collection<Electron> collection_type;

    typedef Lepton base_type;

    Electron(char const* name = "");
    Electron(Electron const&);
    Electron(datastore&, UInt_t idx);
    ~Electron();
    Electron& operator=(Electron const&);

    double m() const override { return 5.109989e-4; }
    double combiso() const override { return chiso + std::max(nhiso + phoiso - isoPUOffset, Float_t(0.)); }

    /* ParticleP
    */
    /* Lepton
    Short_t& q;
    Bool_t& loose;
    Bool_t& medium;
    Bool_t& tight;
    Float_t& chiso;
    Float_t& nhiso;
    Float_t& phoiso;
    Float_t& puiso;
    */
    Bool_t& hltsafe;
    Float_t& chisoPh;
    Float_t& nhisoPh;
    Float_t& phisoPh;
    Float_t& ecaliso;
    Float_t& hcaliso;
    Float_t& isoPUOffset;
    Float_t& sieie;
    Float_t& sipip;
    Float_t& eseed;
    Float_t& hOverE;
    Bool_t& veto;
    Bool_t (&triggerMatch)[nElectronTriggerObjects];
  protected:
    /* ParticleP
    Float_t& pt_;
    Float_t& eta_;
    Float_t& phi_;
    */
    /* Lepton
    Ref<GenParticle> matchedGen;
    */
    Ref<SuperCluster> superCluster;

  public:
    /* BEGIN CUSTOM Electron.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    Electron(ArrayBase*);

    void doSetStatus_(TTree&, TString const&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&, TString const&) const override;
    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&, TString const&) override;
    void doInit_() override;
  };

  typedef Electron::array_type ElectronArray;
  typedef Electron::collection_type ElectronCollection;
  typedef Ref<Electron> ElectronRef;
  typedef RefVector<Electron> ElectronRefVector;

  /* BEGIN CUSTOM Electron.h.global */
  /* END CUSTOM */

}

#endif
