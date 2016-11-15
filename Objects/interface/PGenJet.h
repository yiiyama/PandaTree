#ifndef PandaTree_Objects_PGenJet_h
#define PandaTree_Objects_PGenJet_h
#include "Constants.h"
#include "PObject.h"
#include "../../Interface/interface/Container.h"

namespace panda {

  class PGenJet : public PObject {
  public:
    typedef Container<PGenJet, PObjectCollection> container_type;

    struct array_data : public PObject::array_data {
      array_data() : PObject::array_data() {}

      /* PObject
      Float_t pt[NMAX]{};
      Float_t eta[NMAX]{};
      Float_t phi[NMAX]{};
      */
      Int_t pdgid[NMAX]{};

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PGenJet();
    PGenJet(PGenJet const&);
    PGenJet(array_data&, UInt_t idx);
    ~PGenJet();
    PGenJet& operator=(PGenJet const&);

    void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, TString const&, utils::BranchList const& = {"*"}) override;

    void init() override;

    /* PObject
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    Int_t& pdgid;

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PGenJet(utils::AllocatorBase const&);
  };

  typedef PGenJet::container_type PGenJetCollection;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
