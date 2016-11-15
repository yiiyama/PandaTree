#ifndef PandaTree_Objects_PMuon_h
#define PandaTree_Objects_PMuon_h
#include "Constants.h"
#include "PLepton.h"
#include "../../Interface/interface/Container.h"

namespace panda {

  class PMuon : public PLepton {
  public:
    typedef Container<PMuon, PLeptonCollection> container_type;

    struct array_data : public PLepton::array_data {
      array_data() : PLepton::array_data() {}

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
      /* PLepton
      Float_t chiso[NMAX]{};
      Float_t nhiso[NMAX]{};
      Float_t phoiso[NMAX]{};
      Float_t puiso[NMAX]{};
      */

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PMuon();
    PMuon(PMuon const&);
    PMuon(array_data&, UInt_t idx);
    ~PMuon();
    PMuon& operator=(PMuon const&);

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
    /* PLepton
    Float_t& chiso;
    Float_t& nhiso;
    Float_t& phoiso;
    Float_t& puiso;
    */

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PMuon(utils::AllocatorBase const&);
  };

  typedef PMuon::container_type PMuonCollection;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
