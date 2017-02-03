#ifndef PandaTree_Framework_CollectionBase_h
#define PandaTree_Framework_CollectionBase_h

#include "ContainerBase.h"

#include <vector>
#include <utility>

namespace panda {

  //! Base class for dynamic-size containers.
  /*!
    Panda containers can be fixed-size (Array) or dynamic-size (Collection). Dynaic-size containers
    are similar to std::vectors.
   */
  class CollectionBase : public ContainerBase {
  public:
    CollectionBase(CollectionBase const& src) : ContainerBase(src), size_(src.size_) {}
    ~CollectionBase() {}

    //! Return the current size of the container.
    UInt_t size() const override { return size_; }

    void init() override { clear(); }

    //! Resize the container.
    /*!
      If expanding, init() is invoked on all new elements.

      \param size   New collection size.
    */
    void resize(UInt_t size);

    void clear() { size_ = 0; getData().resizeVectors_(0); }

    /*!
      Run a look-ahead of the entry to determine the collection resize
    */
    void prepareGetEntry(Long64_t, UInt_t treeIdx = 0);

    Int_t getEntry(Long64_t, UInt_t = 0) override;

  protected:
    CollectionBase(char const* name, UInt_t unitSize, Bool_t dummy) : ContainerBase(name, unitSize) {}

    void doSetStatus_(TTree&, utils::BranchList const&) override;
    void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus, Bool_t asInput = kTRUE) override;
    void doBook_(TTree&, utils::BranchList const&) override;
    void doResetAddress_(TTree&) override;

    UInt_t size_{0};

    //! Size information lookahead
    /*!
     * Collection size must be prefetched (in doPrepareGetEntry) to expand the collection in memory if necessary.
     * For each input tree, we keep the branch for size and its bound integer.
     */
    std::vector<std::pair<TBranch*, UInt_t>> sizeIn_{};
  };

}

#endif
