#ifndef PandaTree_Framework_ArrayBase_h
#define PandaTree_Framework_ArrayBase_h

#include "ContainerBase.h"

namespace panda {

  //! Base class for fixed-size containers.
  /*!
    Panda containers can be fixed-size (Array) or dynamic-size (Collection). Fixed-size containers
    are similar to C arrays, and are more light weight and faster to use.
   */
  class ArrayBase : public ContainerBase {
  public:
    ArrayBase(ArrayBase const& src) : ContainerBase(src) {}
    ~ArrayBase() {}

    //! Return the (fixed) size of this array.
    UInt_t size() const override { return getData().nmax(); }

    void init() override;

  protected:
    ArrayBase(char const* name, UInt_t unitSize, Bool_t dummy) : ContainerBase(name, unitSize) {}

    void doSetStatus_(TTree&, utils::BranchList const&) override;
    void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus, Bool_t asInput = kTRUE) override;
    void doBook_(TTree&, utils::BranchList const&) override;
    void doResetAddress_(TTree&) override;
  };

}

#endif
