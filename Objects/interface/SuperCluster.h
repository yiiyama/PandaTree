#ifndef PandaTree_Objects_SuperCluster_h
#define PandaTree_Objects_SuperCluster_h
#include "Constants.h"
#include "../../Framework/interface/ContainerElement.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class SuperCluster : public ContainerElement {
  public:
    struct datastore : public ContainerElement::datastore {
      datastore() : ContainerElement::datastore() {}
      ~datastore() { deallocate(); }

      Float_t* rawPt{0};
      Float_t* eta{0};
      Float_t* phi{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef ContainerElement base_type;
    typedef Array<SuperCluster> array_type;
    typedef Collection<SuperCluster> collection_type;

    SuperCluster(char const* name = "");
    SuperCluster(SuperCluster const&);
    SuperCluster(datastore&, UInt_t idx);
    ~SuperCluster();
    SuperCluster& operator=(SuperCluster const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;
    void resetAddress(TTree&) override;

    void init() override;

    Float_t& rawPt;
    Float_t& eta;
    Float_t& phi;

    /* BEGIN CUSTOM SuperCluster.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    SuperCluster(ArrayBase*);
  };

  typedef SuperCluster::array_type SuperClusterArray;
  typedef SuperCluster::collection_type SuperClusterCollection;
  typedef Ref<SuperCluster> SuperClusterRef;
  typedef RefVector<SuperCluster> SuperClusterRefVector;

  /* BEGIN CUSTOM SuperCluster.h.global */
  /* END CUSTOM */

}

#endif
