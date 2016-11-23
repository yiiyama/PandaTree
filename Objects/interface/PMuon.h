#ifndef PandaTree_Objects_PMuon_h
#define PandaTree_Objects_PMuon_h
#include "Constants.h"
#include "PLepton.h"
#include "../../Framework/interface/Container.h"

namespace panda {

  class PMuon : public PLepton {
  public:
    typedef Container<PMuon, PLeptonCollection> container_type;

    struct array_data : public PLepton::array_data {
      static UInt_t const NMAX{32};

      array_data() : PLepton::array_data() {}

      /* PParticle
      Float_t pt[NMAX]{};
      Float_t eta[NMAX]{};
      Float_t phi[NMAX]{};
      */
      /* PLepton
      Text_t const* q[NMAX]{};
      Bool_t loose[NMAX]{};
      Bool_t tight[NMAX]{};
      Float_t chiso[NMAX]{};
      Float_t nhiso[NMAX]{};
      Float_t phoiso[NMAX]{};
      Float_t puiso[NMAX]{};
      Bool_t tauDecay[NMAX]{};
      Bool_t hadDecay[NMAX]{};
      */

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PMuon(char const* name = "");
    PMuon(PMuon const&);
    PMuon(array_data&, UInt_t idx);
    ~PMuon();
    PMuon& operator=(PMuon const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;

    void init() override;

    double m() const override { return 1.05658e-2; }
    double combiso() const override { return chiso + std::max(nhiso + phoiso - 0.5 * puiso, 0.); }

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* PLepton
    Text_t const*& q;
    Bool_t& loose;
    Bool_t& tight;
    Float_t& chiso;
    Float_t& nhiso;
    Float_t& phoiso;
    Float_t& puiso;
    Bool_t& tauDecay;
    Bool_t& hadDecay;
    */

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PMuon(utils::AllocatorBase const&, char const* name);
  };

  typedef PMuon::container_type PMuonCollection;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
