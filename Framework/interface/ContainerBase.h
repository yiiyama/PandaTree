#ifndef PandaTree_Framework_ContainerBase_h
#define PandaTree_Framework_ContainerBase_h

#include "ContainerElement.h"
#include "IOUtils.h"

#include "TString.h"
#include "TTree.h"

#include <vector>
#include <functional>

namespace panda {
  //! Base class for all containers.
  /*!
   * Panda containers can be Array (fixed size) or Collection (dynamic size). Both inherit from ContainerBase.
   */
  class ContainerBase : public Object {
  public:
    ContainerBase(ContainerBase const& src) : name_(src.name_), unitSize_(src.unitSize_) {}
    virtual ~ContainerBase() {}

    //! Name of this container
    char const* getName() const override { return name_; }

    //! Set the name of this container
    void setName(char const* name) override { name_ = name; }

    virtual UInt_t size() const = 0;
    virtual ContainerElement::datastore& getData() = 0;
    virtual ContainerElement::datastore const& getData() const = 0;
    virtual ContainerElement& elemAt(UInt_t) = 0;
    virtual ContainerElement const& elemAt(UInt_t) const = 0;

    typedef std::function<bool(ContainerElement const&, ContainerElement const&)> Comparison;
    //! Sort the contents using a comparison function and returns an array of pre-sort indices
    /*!
     * For example, if [p0, p1, p2] gets sorted to [p2, p0, p1], the returned array is [2, 0, 1]
     *
     * \param fct   A function that takes two ContainerElements and returns true if the first element should come before the second in the sorted list.
    */
    virtual std::vector<UInt_t> sort(Comparison const& fct) = 0;

    //! Call SetBranchStatus on each branch of the tree.
    /*!
     * Sets the status of the branch to true (branch is in the list) or false (branch is vetoed in the list).
     * Branches not mentioned in the branch list are untouched.
     *
     * \param blist   List of branches. The status of a branch is set to true (false) if BranchName::in(blist) (BranchName::vetoed(blist)) evaluates to true for the branch.
    */
    void setStatus(TTree&, utils::BranchList const& blist) override;
    //! Bind the tree branches to the elements of this container.
    /*!
     * \param blist      List of branches to bind. Vetoed or unmentioned branches are not bound.
     * \param setStatus  If true, set the status of the branch to true before binding.
     * \return Token (serial number) of the input tree
    */
    UInt_t setAddress(TTree&, utils::BranchList const& blist = {"*"}, Bool_t setStatus = kTRUE) override;
    //! Call Branch() for all objects.
    /*!
      Any branch that is not explicitly vetoed are included.
    */
    UInt_t book(TTree&, utils::BranchList const& blist = {"*"}) override;

    void releaseTree(TTree&) override;

    /*!
      Called when using the container as a standalone input
    */
    virtual Int_t getEntry(Long64_t, UInt_t = 0);

  protected:
    ContainerBase(char const* name, UInt_t unitSize) : name_(name), unitSize_(unitSize) {}

    virtual void allocate_(UInt_t) = 0;
    virtual void deallocate_() = 0;
    virtual void reallocate_(UInt_t) = 0;

    virtual void doSetStatus_(TTree&, utils::BranchList const&) = 0;
    virtual void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus, Bool_t asInput = kTRUE) = 0;
    virtual void doBook_(TTree&, utils::BranchList const&) = 0;
    virtual void doResetAddress_(TTree&) = 0;

    void updateAddress_();

    TString name_;
    UInt_t const unitSize_;
    Char_t* array_{0};
    std::vector<TTree*> inputs_{};
    std::vector<TTree*> outputs_{};
  };

}

#endif
