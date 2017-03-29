#ifndef PandaTree_Objects_XPhoton_h
#define PandaTree_Objects_XPhoton_h
#include "Constants.h"
#include "Photon.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class XPhoton : public Photon {
  public:
    static double chIsoCuts[2][2][4];
    static double nhIsoCuts[2][2][4];
    static double phIsoCuts[2][2][4];
    static double sieieCuts[2][2][4];
    static double hOverECuts[2][2][4];

    struct datastore : public Photon::datastore {
      datastore() : Photon::datastore() {}
      ~datastore() { deallocate(); }

      /* ParticleP
      Float_t* pt_{0};
      Float_t* eta_{0};
      Float_t* phi_{0};
      */
      /* Photon
      Float_t* pfPt{0};
      Float_t* chIso{0};
      Float_t* chIsoMax{0};
      Float_t* nhIso{0};
      Float_t* phIso{0};
      Float_t* sieie{0};
      Float_t* sipip{0};
      Float_t* hOverE{0};
      Float_t* genIso{0};
      Float_t* mipEnergy{0};
      Float_t* emax{0};
      Float_t* e2nd{0};
      Float_t* eleft{0};
      Float_t* eright{0};
      Float_t* etop{0};
      Float_t* ebottom{0};
      Float_t* r9{0};
      Float_t* etaWidth{0};
      Float_t* phiWidth{0};
      Float_t* time{0};
      Float_t* timeSpan{0};
      Float_t* rawPt{0};
      Float_t* regPt{0};
      Float_t* originalPt{0};
      Bool_t* loose{0};
      Bool_t* medium{0};
      Bool_t* tight{0};
      Bool_t* highpt{0};
      Bool_t* pixelVeto{0};
      Bool_t* csafeVeto{0};
      Bool_t (*triggerMatch)[nTriggerObjects]{0};
      ContainerBase const* superClusterContainer_{0};
      Short_t* superCluster_{0};
      ContainerBase const* matchedGenContainer_{0};
      Short_t* matchedGen_{0};
      */
      Float_t* scEta{0};
      Float_t* scRawPt{0};
      Float_t* chIsoS15{0};
      Float_t* nhIsoS15{0};
      Float_t* phIsoS15{0};
      Float_t* e4{0};
      Bool_t* isEB{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
      utils::BranchList getBranchNames(TString const& = "") const override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<XPhoton> array_type;
    typedef Collection<XPhoton> collection_type;

    typedef Photon base_type;

    XPhoton(char const* name = "");
    XPhoton(XPhoton const&);
    XPhoton(datastore&, UInt_t idx);
    ~XPhoton();
    XPhoton& operator=(XPhoton const&);

    static char const* typeName() { return "XPhoton"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    bool passCHIso(UInt_t wp) const { return chIso < chIsoCuts[1][isEB ? 0 : 1][wp]; }
    bool passNHIso(UInt_t wp) const { return nhIso < nhIsoCuts[1][isEB ? 0 : 1][wp]; }
    bool passPhIso(UInt_t wp) const { return phIso < phIsoCuts[1][isEB ? 0 : 1][wp]; }
    bool passSieie(UInt_t wp, UInt_t era) const { return sieie < sieieCuts[era][isEB ? 0 : 1][wp]; }
    bool passHOverE(UInt_t wp, UInt_t era) const { return hOverE < hOverECuts[era][isEB ? 0 : 1][wp]; }
    bool passCHIsoS15(UInt_t wp) const { return chIsoS15 < chIsoCuts[0][isEB ? 0 : 1][wp]; }
    bool passNHIsoS15(UInt_t wp) const { return nhIsoS15 < nhIsoCuts[0][isEB ? 0 : 1][wp]; }
    bool passPhIsoS15(UInt_t wp) const { return phIsoS15 < phIsoCuts[0][isEB ? 0 : 1][wp]; }

    /* Photon
    Float_t& pfPt; // Pt of the dR-closest PF candidate
    Float_t& chIso;
    Float_t& chIsoMax;
    Float_t& nhIso;
    Float_t& phIso;
    Float_t& sieie;
    Float_t& sipip;
    Float_t& hOverE;
    Float_t& genIso;
    Float_t& mipEnergy;
    Float_t& emax;
    Float_t& e2nd;
    Float_t& eleft;
    Float_t& eright;
    Float_t& etop;
    Float_t& ebottom;
    Float_t& r9;
    Float_t& etaWidth;
    Float_t& phiWidth;
    Float_t& time;
    Float_t& timeSpan;
    Float_t& rawPt;
    Float_t& regPt;
    Float_t& originalPt;
    Bool_t& loose;
    Bool_t& medium;
    Bool_t& tight;
    Bool_t& highpt;
    Bool_t& pixelVeto;
    Bool_t& csafeVeto;
    Bool_t (&triggerMatch)[nTriggerObjects];
    Ref<SuperCluster> superCluster;
    Ref<GenParticle> matchedGen;
    */
    Float_t& scEta;
    Float_t& scRawPt;
    Float_t& chIsoS15;
    Float_t& nhIsoS15;
    Float_t& phIsoS15;
    Float_t& e4;
    Bool_t& isEB;

  protected:
    /* ParticleP
    Float_t& pt_;
    Float_t& eta_;
    Float_t& phi_;
    */

  public:
    /* BEGIN CUSTOM XPhoton.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor() override;

  protected:
    XPhoton(ArrayBase*);

    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<XPhoton> XPhotonArray;
  typedef Collection<XPhoton> XPhotonCollection;
  typedef Ref<XPhoton> XPhotonRef;
  typedef RefVector<XPhoton> XPhotonRefVector;

  /* BEGIN CUSTOM XPhoton.h.global */
  /* END CUSTOM */

}

#endif
