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

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
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


    Float_t& rawPt;
    Float_t& eta;
    Float_t& phi;

    /* BEGIN CUSTOM SuperCluster.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    SuperCluster(ArrayBase*);

    void doSetStatus_(TTree&, TString const&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&, TString const&) const override;
    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&, TString const&) override;
    void doInit_() override;
    };

    typedef SuperCluster::array_type SuperClusterArray;
    typedef SuperCluster::collection_type SuperClusterCollection;
    typedef Ref<SuperCluster> SuperClusterRef;
    typedef RefVector<SuperCluster> SuperClusterRefVector;

  /* BEGIN CUSTOM SuperCluster.h.global */
  /* END CUSTOM */

  }

  #endif
