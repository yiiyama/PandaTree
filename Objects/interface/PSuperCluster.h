#ifndef PandaTree_Objects_PSuperCluster_h
#define PandaTree_Objects_PSuperCluster_h
#include "Constants.h"
#include "../../Framework/interface/Object.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"

namespace panda {

  class PSuperCluster : public ContainerElement {
  public:
    typedef Container<PSuperCluster, Collection> PSuperClusterCollection;
    typedef Ref<PSuperClusterCollection> PSuperClusterRef;

    struct array_data : public ContainerElement::array_data {
      static UInt_t const NMAX{128};

      array_data() : ContainerElement::array_data() {}

      Float_t rawPt[NMAX]{};
      Float_t eta[NMAX]{};
      Float_t phi[NMAX]{};

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PSuperCluster(char const* name = "");
    PSuperCluster(PSuperCluster const&);
    PSuperCluster(array_data&, UInt_t idx);
    ~PSuperCluster();
    PSuperCluster& operator=(PSuperCluster const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;

    void init() override;

    Float_t& rawPt;
    Float_t& eta;
    Float_t& phi;

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PSuperCluster(utils::AllocatorBase const&, char const* name);
  };

  typedef PSuperCluster::PSuperClusterCollection PSuperClusterCollection;
  typedef PSuperCluster::PSuperClusterRef PSuperClusterRef;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
