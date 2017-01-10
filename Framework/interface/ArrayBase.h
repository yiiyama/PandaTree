#ifndef PandaTree_Framework_ArrayBase_h
#define PandaTree_Framework_ArrayBase_h

#include "ContainerBase.h"

namespace panda {

  class ArrayBase : public ContainerBase {
  public:
    ArrayBase(ArrayBase const& src) : ContainerBase(src) {}
    ~ArrayBase() {}

    UInt_t size() const override { return getData().nmax(); }
    void init() override;

  protected:
    ArrayBase(char const* name, UInt_t unitSize, Bool_t dummy) : ContainerBase(name, unitSize) {}

    void doSetStatus_(TTree&, Bool_t, utils::BranchList const&) override;
    void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus) override;
    void doBook_(TTree&, utils::BranchList const&) override;
    void doResetAddress_(TTree&) override;
    void doPrepareGetEntry_(Long64_t) override {}
  };

}

#endif
