#ifndef PandaTree_Framework_ArrayBase_h
#define PandaTree_Framework_ArrayBase_h

#include "ContainerBase.h"

namespace panda {

  class ArrayBase : public ContainerBase {
  public:
    ArrayBase(ArrayBase const& src) : ContainerBase(src) {}
    ~ArrayBase() {}

    UInt_t size() const override { return getData().nmax(); }

  private:
    void doSetStatus_(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void doSetAddress_(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, utils::BranchList const& = {"*"}) override;

  protected:
    ArrayBase(char const* name, UInt_t unitSize) : ContainerBase(name, unitSize) {}
  };

}

#endif
