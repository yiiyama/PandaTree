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

    void clear() { size_ = 0; }

  private:
    void doSetStatus_(TTree&, Bool_t, utils::BranchList const&) override;
    void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus) override;
    void doBook_(TTree&, utils::BranchList const&) override;
    void doResetAddress_(TTree&) override;

  protected:
    CollectionBase(char const* name, UInt_t unitSize, Bool_t dummy) : ContainerBase(name, unitSize) {}

    UInt_t size_{0};
  };

}

#endif
