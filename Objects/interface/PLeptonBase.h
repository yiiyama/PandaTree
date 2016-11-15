#ifndef PandaTree_Objects_PLeptonBase_h
#define PandaTree_Objects_PLeptonBase_h
#include "Constants.h"
#include "PObject.h"
#include "../../Interface/interface/Container.h"

namespace panda {

  class PLeptonBase : public PObject {
  public:
    typedef Container<PLeptonBase, PObjectCollection> container_type;

    struct array_data : public PObject::array_data {
      array_data() : PObject::array_data() {}

      /* PObject
      Float_t pt[NMAX]{};
      Float_t eta[NMAX]{};
      Float_t phi[NMAX]{};
      */
      Int_t q[NMAX]{};
      UInt_t id[NMAX]{};
      Float_t iso[NMAX]{};

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PLeptonBase();
    PLeptonBase(PLeptonBase const&);
    PLeptonBase(array_data&, UInt_t idx);
    ~PLeptonBase();
    PLeptonBase& operator=(PLeptonBase const&);

    void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, TString const&, utils::BranchList const& = {"*"}) override;

    void init() override;

    /* PObject
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    Int_t& q;
    UInt_t& id;
    Float_t& iso;

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PLeptonBase(utils::AllocatorBase const&);
  };

  typedef PLeptonBase::container_type PLeptonBaseCollection;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
