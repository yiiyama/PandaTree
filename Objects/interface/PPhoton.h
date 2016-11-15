#ifndef PandaTree_Objects_PPhoton_h
#define PandaTree_Objects_PPhoton_h
#include "Constants.h"
#include "PObject.h"
#include "../../Interface/interface/Container.h"

namespace panda {

  class PPhoton : public PObject {
  public:
    typedef Container<PPhoton, PObjectCollection> container_type;

    struct array_data : public PObject::array_data {
      array_data() : PObject::array_data() {}

      /* PObject
      Float_t pt[NMAX]{};
      Float_t eta[NMAX]{};
      Float_t phi[NMAX]{};
      */
      UInt_t id[NMAX]{};
      Float_t iso[NMAX]{};

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PPhoton();
    PPhoton(PPhoton const&);
    PPhoton(array_data&, UInt_t idx);
    ~PPhoton();
    PPhoton& operator=(PPhoton const&);

    void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, TString const&, utils::BranchList const& = {"*"}) override;

    void init() override;

    /* PObject
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    UInt_t& id;
    Float_t& iso;

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PPhoton(utils::AllocatorBase const&);
  };

  typedef PPhoton::container_type PPhotonCollection;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
