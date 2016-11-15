#ifndef PandaTree_Objects_PLepton_h
#define PandaTree_Objects_PLepton_h
#include "Constants.h"
#include "PLeptonBase.h"
#include "../../Interface/interface/Container.h"

namespace panda {

  class PLepton : public PLeptonBase {
  public:
    typedef Container<PLepton, PLeptonBaseCollection> container_type;

    struct array_data : public PLeptonBase::array_data {
      array_data() : PLeptonBase::array_data() {}

      /* PObject
      Float_t pt[NMAX]{};
      Float_t eta[NMAX]{};
      Float_t phi[NMAX]{};
      */
      /* PLeptonBase
      Int_t q[NMAX]{};
      UInt_t id[NMAX]{};
      Float_t iso[NMAX]{};
      */
      Float_t chiso[NMAX]{};
      Float_t nhiso[NMAX]{};
      Float_t phoiso[NMAX]{};
      Float_t puiso[NMAX]{};

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PLepton();
    PLepton(PLepton const&);
    PLepton(array_data&, UInt_t idx);
    ~PLepton();
    PLepton& operator=(PLepton const&);

    void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, TString const&, utils::BranchList const& = {"*"}) override;

    void init() override;

    /* PObject
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* PLeptonBase
    Int_t& q;
    UInt_t& id;
    Float_t& iso;
    */
    Float_t& chiso;
    Float_t& nhiso;
    Float_t& phoiso;
    Float_t& puiso;

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PLepton(utils::AllocatorBase const&);
  };

  typedef PLepton::container_type PLeptonCollection;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
