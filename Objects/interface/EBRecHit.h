#ifndef PandaTree_Objects_EBRecHit_h
#define PandaTree_Objects_EBRecHit_h
#include "Constants.h"
#include "../../Framework/interface/Element.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "SuperCluster.h"

namespace panda {

  class EBRecHit : public Element {
  public:
    struct datastore : public Element::datastore {
      datastore() : Element::datastore() {}
      ~datastore() { deallocate(); }

      Float_t* energy{0};
      Float_t* time{0};
      Float_t* timeError{0};
      Short_t* ieta{0};
      Short_t* iphi{0};
      ContainerBase const* superClusterContainer_{0};
      Short_t* superCluster_{0};

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

    typedef Array<EBRecHit> array_type;
    typedef Collection<EBRecHit> collection_type;

    typedef Element base_type;

    EBRecHit(char const* name = "");
    EBRecHit(EBRecHit const&);
    EBRecHit(datastore&, UInt_t idx);
    ~EBRecHit();
    EBRecHit& operator=(EBRecHit const&);

    static char const* typeName() { return "EBRecHit"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    Float_t& energy;
    Float_t& time;
    Float_t& timeError;
    Short_t& ieta;
    Short_t& iphi;
    Ref<SuperCluster> superCluster;

    /* BEGIN CUSTOM EBRecHit.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor() override;

  protected:
    EBRecHit(ArrayBase*);

    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<EBRecHit> EBRecHitArray;
  typedef Collection<EBRecHit> EBRecHitCollection;
  typedef Ref<EBRecHit> EBRecHitRef;
  typedef RefVector<EBRecHit> EBRecHitRefVector;

  /* BEGIN CUSTOM EBRecHit.h.global */
  /* END CUSTOM */

}

#endif
