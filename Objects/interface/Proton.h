#ifndef PandaTree_Objects_Proton_h
#define PandaTree_Objects_Proton_h
#include "Constants.h"
#include "../../Framework/interface/Element.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class Proton : public Element {
  public:
    struct datastore : public Element::datastore {
      datastore() : Element::datastore() {}
      ~datastore() { deallocate(); }

      Float_t* x{0};
      Float_t* xUnc{0};
      Float_t* y{0};
      Float_t* yUnc{0};
      Int_t* rpId{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
      utils::BranchList getBranchNames(TString const& = "") const override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<Proton> array_type;
    typedef Collection<Proton> collection_type;

    typedef Element base_type;

    Proton(char const* name = "");
    Proton(Proton const&);
    Proton(datastore&, UInt_t idx);
    ~Proton();
    Proton& operator=(Proton const&);

    static char const* typeName() { return "Proton"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    Float_t& x;
    Float_t& xUnc;
    Float_t& y;
    Float_t& yUnc;
    Int_t& rpId;

    /* BEGIN CUSTOM Proton.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor(Bool_t recursive = kFALSE);

  protected:
    Proton(ArrayBase*);

    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<Proton> ProtonArray;
  typedef Collection<Proton> ProtonCollection;
  typedef Ref<Proton> ProtonRef;
  typedef RefVector<Proton> ProtonRefVector;

  /* BEGIN CUSTOM Proton.h.global */
  /* END CUSTOM */

}

#endif
