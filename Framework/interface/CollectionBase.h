#ifndef PandaTree_Framework_CollectionBase_h
#define PandaTree_Framework_CollectionBase_h

#include "ContainerBase.h"

#include <vector>
#include <utility>

namespace panda {

  //! Base class for dynamic-size containers.
  /*!
   * Panda containers can be fixed-size (Array) or dynamic-size (Collection). Dynaic-size containers
   * are similar to std::vectors.
   */
  class CollectionBase : public ContainerBase {
  public:
    CollectionBase(CollectionBase const& src) : ContainerBase(src), size_(src.size_) {}
    ~CollectionBase() {}

    Int_t getEntry(Long64_t entry, UInt_t = 0) final;
    void init() final { clear(); }
    UInt_t size() const final { return size_; }

    //! Resize the container.
    /*!
     * If expanding, init() is invoked on all new elements.
     * If the new size is greater than nmax, data will be reallocated, making all references invalid.
     * 
     * \param size   New collection size.
     */
    void resize(UInt_t size);

    //! Clear the container (set size = 0)
    void clear() { size_ = 0; getData().resizeVectors_(0); }

    //! Run a look-ahead of the entry to determine the collection resize.
    /*!
     * To read a collection of N objects, we must have more than N slots allocated in memory.
     * Since ROOT cannot automatically take care of resizing the array, we need to load the "size"
     * branch first and reallocate memory if necessary.
     *
     * \param entry   Entry number in the input tree.
     * \param treeIdx Input tree ID (as returned by setAddress).
     */
    void prepareGetEntry(Long64_t entry, UInt_t treeIdx = 0);

  protected:
    CollectionBase(char const* name, UInt_t unitSize, Bool_t dummy) : ContainerBase(name, unitSize) {}

    void doSetStatus_(TTree&, utils::BranchList const&) final;
    void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus, Bool_t asInput) final;
    void doBook_(TTree&, utils::BranchList const&) final;
    void doReleaseTree_(TTree&) final;

    virtual void reallocate_(UInt_t) = 0;

    //! Collection size
    UInt_t size_{0};

    //! Size information lookahead
    /*!
     * Collection size must be prefetched (in doPrepareGetEntry) to expand the collection in memory if necessary.
     * For each input tree, we keep the branch for size and its bound integer.
     */
    std::vector<std::pair<TBranch*, UInt_t>> sizeIn_{};

    //! List of bound outputs
    /*!
     * When resize & reallocation happens, we need to update the addresses at the output trees too.
     */
    std::vector<TTree*> outputs_{};
  };

}

#endif
