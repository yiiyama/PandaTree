#ifndef PandaTree_Objects_CorrectedSecondaryVertex_h
#define PandaTree_Objects_CorrectedSecondaryVertex_h
#include "Constants.h"
#include "SecondaryVertex.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "Vertex.h"

namespace panda {

  class CorrectedSecondaryVertex : public SecondaryVertex {
  public:
    struct datastore : public SecondaryVertex::datastore {
      datastore() : SecondaryVertex::datastore() {}
      ~datastore() { deallocate(); }

      /* SecondaryVertex
      Float_t* x{0};
      Float_t* y{0};
      Float_t* z{0};
      UShort_t* ntrk{0};
      Float_t* ndof{0};
      Float_t* chi2{0};
      ContainerBase const* daughtersContainer_{0};
      std::vector<std::vector<Short_t>>* daughters_{0};
      Float_t* significance{0};
      Float_t* vtx3DVal{0};
      Float_t* vtx3DeVal{0};
      */
      Float_t* r{0};
      Float_t* rawPt{0};
      Float_t* rawEta{0};
      Float_t* rawPhi{0};
      Float_t* rawMass{0};
      Int_t* iPV{0};
      Float_t* drPV{0};
      Float_t* dzPV{0};
      Short_t* q{0};
      Float_t* chIso{0};
      Float_t* nhIso{0};
      Float_t* phIso{0};

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

    typedef Array<CorrectedSecondaryVertex> array_type;
    typedef Collection<CorrectedSecondaryVertex> collection_type;

    typedef SecondaryVertex base_type;

    CorrectedSecondaryVertex(char const* name = "");
    CorrectedSecondaryVertex(CorrectedSecondaryVertex const&);
    CorrectedSecondaryVertex(datastore&, UInt_t idx);
    ~CorrectedSecondaryVertex();
    CorrectedSecondaryVertex& operator=(CorrectedSecondaryVertex const&);

    static char const* typeName() { return "CorrectedSecondaryVertex"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    void setPV(VertexCollection const&);

    /* SecondaryVertex
    Float_t& x;
    Float_t& y;
    Float_t& z;
    UShort_t& ntrk;
    Float_t& ndof;
    Float_t& chi2;
    RefVector<PFCandBase> daughters;
    Float_t& significance;
    Float_t& vtx3DVal;
    Float_t& vtx3DeVal;
    */
    Float_t& r;
    Float_t& rawPt;
    Float_t& rawEta;
    Float_t& rawPhi;
    Float_t& rawMass;
    Int_t& iPV;
    Float_t& drPV;
    Float_t& dzPV;
    Short_t& q;
    Float_t& chIso;
    Float_t& nhIso;
    Float_t& phIso;

    /* BEGIN CUSTOM CorrectedSecondaryVertex.h.classdef */
    CorrectedSecondaryVertex& operator=(SecondaryVertex const&);
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor(Bool_t recursive = kFALSE);

  protected:
    CorrectedSecondaryVertex(ArrayBase*);

    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<CorrectedSecondaryVertex> CorrectedSecondaryVertexArray;
  typedef Collection<CorrectedSecondaryVertex> CorrectedSecondaryVertexCollection;
  typedef Ref<CorrectedSecondaryVertex> CorrectedSecondaryVertexRef;
  typedef RefVector<CorrectedSecondaryVertex> CorrectedSecondaryVertexRefVector;

  /* BEGIN CUSTOM CorrectedSecondaryVertex.h.global */
  /* END CUSTOM */

}

#endif
