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
    CollectionBase() = delete;
    CollectionBase(CollectionBase const& src) = delete;
    ~CollectionBase() {}

    Int_t getEntry(TTree&, Long64_t entry) final;
    Int_t fill(TTree&) final;
    void init() final { clear(); }
    UInt_t size() const final { return size_; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    //! Resize the container.
    /*!
     * If expanding, init() is invoked on all new elements.
     * If the new size is greater than nmax, data will be reallocated, making all references invalid.
     * 
     * \param size   New collection size.
     */
    void resize(UInt_t size);

    //! Pre-allocate space for the container.
    /*!
     * If the new size is greater than nmax, data will be reallocated, making all references invalid.
     * 
     * \param size   New collection allocation size.
     */
    void reserve(UInt_t size);

    //! Clear the container (set size = 0)
    void clear() { size_ = 0; getData().resizeVectors_(0); }

    //! Run a look-ahead of the entry to determine the collection resize.
    /*!
     * To read a collection of N objects, we must have more than N slots allocated in memory.
     * Since ROOT cannot automatically take care of resizing the array, we need to load the "size"
     * branch first and reallocate memory if necessary.
     *
     * \param tree    Tree to read the entry from.
     * \param entry   Entry number in the input tree.
     */
    void prepareGetEntry(TTree& tree, Long64_t entry);

    //! Check for address change before fill.
    void prepareFill(TTree&);

  protected:
    CollectionBase(char const* name, UInt_t unitSize, Bool_t dummy) : ContainerBase(name, unitSize) {}

    virtual void reallocate_(UInt_t) = 0;

  private:
    void doSetStatus_(TTree&, utils::BranchList const&) final;
    utils::BranchList doGetStatus_(TTree&) const final;
    void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus, Bool_t asInput) final;
    void doBook_(TTree&, utils::BranchList const&) final;

    //! Collection size
    UInt_t size_{0};

    //! Size information lookahead
    UInt_t sizeIn_{0};

    //! List of inputs
    /*!
     * Store a map of tree -> (size branch, in-sync flag). Size branch is for convenience
     * (don't have to GetBranch() at every call to getEntry) and the in-synch flag indicates
     * whether the tree has the most up-to-date branch addresses. The flag is reset at each
     * call to reallocate.
     */
    std::map<TTree*, std::pair<TBranch*, Bool_t>> inputs_;

    //! List of outputs
    /*!
     * When resize & reallocation happens, we need to update the addresses at the output trees too.
     */
    std::map<TTree*, Bool_t> outputs_{};
  };

}

#endif
