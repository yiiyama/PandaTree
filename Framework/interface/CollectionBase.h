#ifndef PandaTree_Framework_CollectionBase_h
#define PandaTree_Framework_CollectionBase_h

#include "ContainerBase.h"

namespace panda {

  class CollectionBase : public ContainerBase {
  public:
    CollectionBase(CollectionBase const& src) : ContainerBase(src), size_(src.size_) {}
    ~CollectionBase() {}

    UInt_t size() const override { return size_; }    
    void init() override { clear(); }

    void resize(UInt_t);
    void clear() { size_ = 0; getData().resizeVectors_(0); }

  protected:
    CollectionBase(char const* name, UInt_t unitSize, Bool_t dummy) : ContainerBase(name, unitSize) {}

    void doSetStatus_(TTree&, Bool_t, utils::BranchList const&) override;
    void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus) override;
    void doBook_(TTree&, utils::BranchList const&) override;
    void doResetAddress_(TTree&) override;
    void doPrepareGetEntry_(Long64_t) override;

    UInt_t size_{0};
    UInt_t sizeIn_{0}; // set to input size address (to look ahead for size expansions)
    TBranch* sizeInBranch_{0};
  };

}

#endif
