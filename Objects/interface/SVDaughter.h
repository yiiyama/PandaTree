#ifndef PandaTree_Objects_SVDaughter_h
#define PandaTree_Objects_SVDaughter_h
#include "Constants.h"
#include "UnpackedPFCand.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class SVDaughter : public UnpackedPFCand {
  public:
    struct datastore : public UnpackedPFCand::datastore {
      datastore() : UnpackedPFCand::datastore() {}
      ~datastore() { deallocate(); }

      /* PFCandBase
      UChar_t* ptype{0};
      ContainerBase const* vertexContainer_{0};
      Short_t* vertex_{0}; ///< transient
      ContainerBase const* trackContainer_{0};
      Short_t* track_{0}; ///< transient
      Float_t* hCalFrac{0};
      */
      /* UnpackedPFCand
      Float_t* puppiW_{0};
      Float_t* puppiWNoLep_{0};
      */
      Float_t* dxySV{0};
      Float_t* dzSV{0};
      Float_t* rawPhi{0};
      Short_t* qtrk{0};
      Float_t* ptAxis{0};
      Float_t* plAxis{0};

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

    typedef Array<SVDaughter> array_type;
    typedef Collection<SVDaughter> collection_type;

    typedef UnpackedPFCand base_type;

    SVDaughter(char const* name = "");
    SVDaughter(SVDaughter const&);
    SVDaughter(datastore&, UInt_t idx);
    ~SVDaughter();
    SVDaughter& operator=(SVDaughter const&);

    static char const* typeName() { return "SVDaughter"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    /* PFCandBase
    UChar_t& ptype;
    Ref<RecoVertex> vertex;
    Ref<PackedTrack> track;
    Float_t& hCalFrac;
    */
    Float_t& dxySV;
    Float_t& dzSV;
    Float_t& rawPhi;
    Short_t& qtrk;
    Float_t& ptAxis;
    Float_t& plAxis;

  protected:
    /* UnpackedPFCand
    Float_t& puppiW_;
    Float_t& puppiWNoLep_;
    */

  public:
    /* BEGIN CUSTOM SVDaughter.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor(Bool_t recursive = kFALSE);

  protected:
    SVDaughter(ArrayBase*);

    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<SVDaughter> SVDaughterArray;
  typedef Collection<SVDaughter> SVDaughterCollection;
  typedef Ref<SVDaughter> SVDaughterRef;
  typedef RefVector<SVDaughter> SVDaughterRefVector;

  /* BEGIN CUSTOM SVDaughter.h.global */
  /* END CUSTOM */

}

#endif
