#ifndef PandaTree_Framework_ContainerBase_h
#define PandaTree_Framework_ContainerBase_h

#include "Element.h"
#include "IOUtils.h"

#include "TString.h"

#include <vector>
#include <functional>

namespace panda {
  //! Base class for all containers.
  /*!
   * Panda containers can be Array (fixed size) or Collection (dynamic size). Both inherit from ContainerBase.
   */
  class ContainerBase : public Object {
  public:
    ContainerBase() = delete;
    ContainerBase(ContainerBase const&) = delete;
    virtual ~ContainerBase() {}
    ContainerBase& operator=(ContainerBase const&) = delete;

    void setStatus(TTree&, utils::BranchList const& blist) final;
    utils::BranchList getStatus(TTree&) const final;
    utils::BranchList getBranchNames(Bool_t fullName = kTRUE) const final;
    void setAddress(TTree&, utils::BranchList const& blist = {"*"}, Bool_t setStatus = kTRUE) final;
    void book(TTree&, utils::BranchList const& blist = {"*"}) final;
    char const* getName() const final { return name_; }
    void setName(char const* name) final { name_ = name; }
    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    virtual UInt_t size() const = 0;
    virtual Element::datastore& getData() = 0;
    virtual Element::datastore const& getData() const = 0;
    virtual Element& elemAt(UInt_t) = 0;
    virtual Element const& elemAt(UInt_t) const = 0;

    typedef std::function<bool(Element const&, Element const&)> Comparison;
    //! Sort the contents using a comparison function and returns an array of pre-sort indices
    /*!
     * For example, if [p0, p1, p2] gets sorted to [p2, p0, p1], the returned array is [2, 0, 1]
     *
     * \param fct   A function that takes two Elements and returns true if the first element should come before the second in the sorted list.
    */
    virtual std::vector<UInt_t> sort(Comparison const& fct) = 0;

  protected:
    ContainerBase(char const* name, UInt_t unitSize) : name_(name), unitSize_(unitSize) {}

    virtual void doSetStatus_(TTree&, utils::BranchList const&) = 0;
    virtual utils::BranchList doGetStatus_(TTree&) const = 0;
    virtual void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus, Bool_t asInput) = 0;
    virtual void doBook_(TTree&, utils::BranchList const&) = 0;

    TString name_{""};
    UInt_t const unitSize_{0};
    Char_t* array_{0};
  };

}

#endif
