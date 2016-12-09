#ifndef PandaTree_Objects_PSuperCluster_h
#define PandaTree_Objects_PSuperCluster_h
#include "Constants.h"
#include "../../Framework/interface/ContainerElement.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class PSuperCluster : public ContainerElement {
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
    typedef Array<PSuperCluster> array_type;
    typedef Collection<PSuperCluster> collection_type;

    PSuperCluster(char const* name = "");
    PSuperCluster(PSuperCluster const&);
    PSuperCluster(datastore&, UInt_t idx);
    ~PSuperCluster();
    PSuperCluster& operator=(PSuperCluster const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;
    void resetAddress(TTree&) override;

    void init() override;

    Float_t& rawPt;
    Float_t& eta;
    Float_t& phi;

    /* BEGIN CUSTOM PSuperCluster.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    PSuperCluster(ArrayBase*);
  };

  typedef PSuperCluster::array_type PSuperClusterArray;
  typedef PSuperCluster::collection_type PSuperClusterCollection;
  typedef Ref<PSuperCluster> PSuperClusterRef;
  typedef RefVector<PSuperCluster> PSuperClusterRefVector;

  /* BEGIN CUSTOM PSuperCluster.h.global */
  /* END CUSTOM */

}

#endif
