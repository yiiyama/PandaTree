#ifndef PandaTree_Objects_HLTObject_h
#define PandaTree_Objects_HLTObject_h
#include "Constants.h"
#include "ParticleP.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class HLTObject : public ParticleP {
  public:
    struct datastore : public ParticleP::datastore {
      datastore() : ParticleP::datastore() {}
      ~datastore() { deallocate(); }

      /* ParticleP
      Float_t* pt_{0};
      Float_t* eta_{0};
      Float_t* phi_{0};
      */
      std::vector<std::vector<UShort_t>>* filters{0};

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

    typedef Array<HLTObject> array_type;
    typedef Collection<HLTObject> collection_type;

    typedef ParticleP base_type;

    HLTObject(char const* name = "");
    HLTObject(HLTObject const&);
    HLTObject(datastore&, UInt_t idx);
    ~HLTObject();
    HLTObject& operator=(HLTObject const&);

    static char const* typeName() { return "HLTObject"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    std::vector<UShort_t>* filters;

  protected:
    /* ParticleP
    Float_t& pt_;
    Float_t& eta_;
    Float_t& phi_;
    */

  public:
    /* BEGIN CUSTOM HLTObject.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor(Bool_t recursive = kFALSE);

  protected:
    HLTObject(ArrayBase*);

    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<HLTObject> HLTObjectArray;
  typedef Collection<HLTObject> HLTObjectCollection;
  typedef Ref<HLTObject> HLTObjectRef;
  typedef RefVector<HLTObject> HLTObjectRefVector;

  /* BEGIN CUSTOM HLTObject.h.global */
  /* END CUSTOM */

}

#endif
