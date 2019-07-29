#ifndef PandaTree_Objects_SecondaryVertex_h
#define PandaTree_Objects_SecondaryVertex_h
#include "Constants.h"
#include "ParticleM.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "PFCandBase.h"

namespace panda {

  class SecondaryVertex : public ParticleM {
  public:
    struct datastore : public ParticleM::datastore {
      datastore() : ParticleM::datastore() {}
      ~datastore() { deallocate(); }

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

    typedef Array<SecondaryVertex> array_type;
    typedef Collection<SecondaryVertex> collection_type;

    typedef ParticleM base_type;

    SecondaryVertex(char const* name = "");
    SecondaryVertex(SecondaryVertex const&);
    SecondaryVertex(datastore&, UInt_t idx);
    ~SecondaryVertex();
    SecondaryVertex& operator=(SecondaryVertex const&);

    static char const* typeName() { return "SecondaryVertex"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    TVector3 position() const { return TVector3(x, y, z); }
    double normChi2() const { return ndof != 0. ? chi2 / ndof : chi2 * 1.e+6; }

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

    /* BEGIN CUSTOM SecondaryVertex.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor(Bool_t recursive = kFALSE);

  protected:
    SecondaryVertex(ArrayBase*);

    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<SecondaryVertex> SecondaryVertexArray;
  typedef Collection<SecondaryVertex> SecondaryVertexCollection;
  typedef Ref<SecondaryVertex> SecondaryVertexRef;
  typedef RefVector<SecondaryVertex> SecondaryVertexRefVector;

  /* BEGIN CUSTOM SecondaryVertex.h.global */
  /* END CUSTOM */

}

#endif
