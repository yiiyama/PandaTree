#ifndef PandaTree_Objects_PJet_h
#define PandaTree_Objects_PJet_h
#include "Constants.h"
#include "PObject.h"
#include "../../Interface/interface/Container.h"
#include "PPFCand.h"

namespace panda {

  class PJet : public PObject {
  public:
    typedef Container<PJet, PObjectCollection> container_type;

    struct array_data : public PObject::array_data {
      array_data() : PObject::array_data() {}

      /* PObject
      Float_t pt[NMAX]{};
      Float_t eta[NMAX]{};
      Float_t phi[NMAX]{};
      */
      Float_t rawPt[NMAX]{};
      Float_t csv[NMAX]{};
      Float_t qgl[NMAX]{};
      Float_t nhf[NMAX]{};
      Float_t chf[NMAX]{};
      UInt_t id[NMAX]{};
      UInt_t nConstituents[NMAX]{};
      UInt_t constituents_[NMAX][128]{};

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PJet();
    PJet(PJet const&);
    PJet(array_data&, UInt_t idx);
    ~PJet();
    PJet& operator=(PJet const&);

    void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, TString const&, utils::BranchList const& = {"*"}) override;

    void init() override;

    /* PObject
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    Float_t& rawPt;
    Float_t& csv;
    Float_t& qgl;
    Float_t& nhf;
    Float_t& chf;
    UInt_t& id;
    UInt_t& nConstituents;
    PPFCand* constituents(UInt_t i) const
    { if (constituentsRef_ && constituents_[i] < constituentsRef_->size()) return &(*constituentsRef_)[constituents_[i]]; else return 0; }
    void constituents(UInt_t i, PPFCand& p)
    { if (!constituentsRef_) return; for (constituents_[i] = 0; constituents_[i] != constituentsRef_->size(); ++constituents_[i]) if (&(*constituentsRef_)[constituents_[i]] == &p) return; constituents_[i] = PPFCand::array_data::NMAX; }
    void constituentsRef(PPFCand::container_type& cont) { constituentsRef_ = &cont; }
  private:
    UInt_t (&constituents_)[128];
    PPFCand::container_type* constituentsRef_{0};
  public:

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PJet(utils::AllocatorBase const&);
  };

  typedef PJet::container_type PJetCollection;

  /* BEGIN CUSTOM */
  inline
  bool SortPJetByCSV(PJet *o1, PJet *o2)
  {
    return o1->csv > o2->csv;
  }
  /* END CUSTOM */

}

#endif
