#ifndef PandaTree_Objects_PSuperCluster_h
#define PandaTree_Objects_PSuperCluster_h
#include "Constants.h"
#include "../../Interface/interface/Object.h"
#include "../../Interface/interface/Container.h"

namespace panda {

  class PSuperCluster : public ContainerElement {
  public:
    typedef Container<PSuperCluster, Collection> container_type;

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

    PSuperCluster();
    PSuperCluster(PSuperCluster const&);
    PSuperCluster(array_data&, UInt_t idx);
    ~PSuperCluster();
    PSuperCluster& operator=(PSuperCluster const&);

    void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, TString const&, utils::BranchList const& = {"*"}) override;

    void init() override;

    Float_t& rawPt;
    Float_t& eta;
    Float_t& phi;

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PSuperCluster(utils::AllocatorBase const&);
  };

  typedef PSuperCluster::container_type PSuperClusterCollection;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
