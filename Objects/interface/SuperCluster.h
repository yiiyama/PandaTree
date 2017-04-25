#ifndef PandaTree_Objects_SuperCluster_h
#define PandaTree_Objects_SuperCluster_h
#include "Constants.h"
#include "../../Framework/interface/Element.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class SuperCluster : public Element {
  public:
    struct datastore : public Element::datastore {
      datastore() : Element::datastore() {}
      ~datastore() { deallocate(); }

      Float_t* rawPt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      Float_t* sieie{0};
      Float_t* sipip{0};
      Float_t* e2e9{0};
      Float_t* emax{0};
      Float_t* e2nd{0};
      Float_t* e4{0};
      Float_t* time{0};
      Float_t* timeSpan{0};
      Float_t* trackIso{0};
      Float_t* mipEnergy{0};
      Float_t* mipChi2{0};
      Float_t* mipSlope{0};
      Float_t* mipIntercept{0};
      Float_t* mipNhits{0};

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

    typedef Array<SuperCluster> array_type;
    typedef Collection<SuperCluster> collection_type;

    typedef Element base_type;

    SuperCluster(char const* name = "");
    SuperCluster(SuperCluster const&);
    SuperCluster(datastore&, UInt_t idx);
    ~SuperCluster();
    SuperCluster& operator=(SuperCluster const&);

    static char const* typeName() { return "SuperCluster"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    Float_t& rawPt;
    Float_t& eta;
    Float_t& phi;
    Float_t& sieie;
    Float_t& sipip;
    Float_t& e2e9;
    Float_t& emax;
    Float_t& e2nd;
    Float_t& e4;
    Float_t& time;
    Float_t& timeSpan;
    Float_t& trackIso;
    Float_t& mipEnergy;
    Float_t& mipChi2;
    Float_t& mipSlope;
    Float_t& mipIntercept;
    Float_t& mipNhits;

    /* BEGIN CUSTOM SuperCluster.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor() override;

  protected:
    SuperCluster(ArrayBase*);

    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<SuperCluster> SuperClusterArray;
  typedef Collection<SuperCluster> SuperClusterCollection;
  typedef Ref<SuperCluster> SuperClusterRef;
  typedef RefVector<SuperCluster> SuperClusterRefVector;

  /* BEGIN CUSTOM SuperCluster.h.global */
  /* END CUSTOM */

}

#endif
