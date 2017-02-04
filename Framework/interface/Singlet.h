#ifndef PandaTree_Framework_Singlet_h
#define PandaTree_Framework_Singlet_h

#include "Object.h"

#include "TString.h"

#include <vector>

namespace panda {

  //! Base class for singlet objects.
  /*!
   * Singlet objects are owners of their data, in contrast to Element.
   */
  class Singlet : public Object {
  public:
    Singlet(char const* name = "") : Object(), name_(name) {}
    Singlet(Singlet const& src) : Object(src), name_(src.name_) {}
    ~Singlet() {}
    Singlet& operator=(Singlet const& _src) { name_ = _src.name_; return *this; }

    void setStatus(TTree&, utils::BranchList const& blist) final;
    UInt_t setAddress(TTree&, utils::BranchList const& blist = {"*"}, Bool_t setStatus = kTRUE) final;
    void book(TTree&, utils::BranchList const& blist = {"*"}) final;
    TTree* getInput(UInt_t treeIdx = 0) const final { return inputs_.at(treeIdx); }
    void releaseTree(TTree&) final;
    void init() final { doInit_(); }
    char const* getName() const final { return name_; }
    void setName(char const* n) final { name_ = n; }

  protected:
    virtual void doSetStatus_(TTree&, utils::BranchList const&) {}
    virtual void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus) {}
    virtual void doBook_(TTree&, utils::BranchList const&) {}
    virtual void doReleaseTree_(TTree&) {}
    virtual void doInit_() {}

    TString name_{};
    std::vector<TTree*> inputs_{};
  };

}

#endif
