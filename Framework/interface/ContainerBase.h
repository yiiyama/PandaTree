#ifndef PandaTree_Framework_ContainerBase_h
#define PandaTree_Framework_ContainerBase_h

#include "ContainerElement.h"
#include "IOUtils.h"

#include "TString.h"
#include "TTree.h"

#include <vector>
#include <functional>

namespace panda {

  class ContainerBase {
  public:
    ContainerBase(ContainerBase const& src) : name_(src.name_), unitSize_(src.unitSize_) {}
    virtual ~ContainerBase() {}

    char const* getName() const { return name_; }
    void setName(char const* name) { name_ = name; }

    virtual UInt_t size() const = 0;
    virtual void init() = 0;
    virtual ContainerElement::datastore& getData() = 0;
    virtual ContainerElement::datastore const& getData() const = 0;
    virtual ContainerElement& elemAt(UInt_t) = 0;
    virtual ContainerElement const& elemAt(UInt_t) const = 0;

    typedef std::function<bool(ContainerElement const&, ContainerElement const&)> Comparison;
    //! Sort the contents using a comparison function and returns an array of pre-sort indices
    /*!
      For example, if [p0, p1, p2] gets sorted to [p2, p0, p1], the returned array is [2, 0, 1]
    */
    virtual std::vector<UInt_t> sort(Comparison const&) = 0;

    //! Call SetBranchStatus on each branch of the tree.
    /*!
      Any branch that is not explicitly vetoed are included.
    */
    void setStatus(TTree&, Bool_t status, utils::BranchList const& = {});
    //! Call SetBranchAddress on each branch of the tree.
    /*!
      Any branch that is not explicitly vetoed are included.
    */
    void setAddress(TTree&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE);
    //! Call Branch() for all objects.
    /*!
      Any branch that is not explicitly vetoed are included.
    */
    void book(TTree&, utils::BranchList const& = {});
    void releaseTree(TTree&);

  protected:
    ContainerBase(char const* name, UInt_t unitSize) : name_(name), unitSize_(unitSize) {}

    virtual void allocate_(UInt_t) = 0;
    virtual void deallocate_() = 0;
    virtual void reallocate_(UInt_t) = 0;

    virtual void doSetStatus_(TTree&, Bool_t, utils::BranchList const&) = 0;
    virtual void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus) = 0;
    virtual void doBook_(TTree&, utils::BranchList const&) = 0;
    virtual void doResetAddress_(TTree&) = 0;

    void updateAddress_();

    TString name_;
    UInt_t const unitSize_;
    Char_t* array_{0};
    TTree* input_{0};
    std::vector<TTree*> outputs_{};
  };

}

#endif
