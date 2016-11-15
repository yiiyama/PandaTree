#ifndef PandaTree_Objects_PTau_h
#define PandaTree_Objects_PTau_h
#include "Constants.h"
#include "PLeptonBase.h"
#include "../../Interface/interface/Container.h"

namespace panda {

  class PTau : public PLeptonBase {
  public:
    typedef Container<PTau, PLeptonBaseCollection> container_type;

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
      Float_t isoDeltaBetaCorr[NMAX]{};

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PTau();
    PTau(PTau const&);
    PTau(array_data&, UInt_t idx);
    ~PTau();
    PTau& operator=(PTau const&);

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
    Float_t& isoDeltaBetaCorr;

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PTau(utils::AllocatorBase const&);
  };

  typedef PTau::container_type PTauCollection;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
