#ifndef PandaTree_Objects_PPFCand_h
#define PandaTree_Objects_PPFCand_h
#include "Constants.h"
#include "PObject.h"
#include "../../Interface/interface/Container.h"

namespace panda {

  class PPFCand : public PObject {
  public:
    typedef Container<PPFCand, PObjectCollection> container_type;

    struct array_data : public PObject::array_data {
      array_data() : PObject::array_data() {}

      /* PObject
      Float_t pt[NMAX]{};
      Float_t eta[NMAX]{};
      Float_t phi[NMAX]{};
      */
      Float_t e[NMAX]{};
      Float_t q[NMAX]{};
      Float_t weight[NMAX]{};
      Int_t pftype[NMAX]{};

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PPFCand();
    PPFCand(PPFCand const&);
    PPFCand(array_data&, UInt_t idx);
    ~PPFCand();
    PPFCand& operator=(PPFCand const&);

    void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, TString const&, utils::BranchList const& = {"*"}) override;

    void init() override;

    /* PObject
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    Float_t& e;
    Float_t& q;
    Float_t& weight;
    Int_t& pftype;

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PPFCand(utils::AllocatorBase const&);
  };

  typedef PPFCand::container_type PPFCandCollection;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
