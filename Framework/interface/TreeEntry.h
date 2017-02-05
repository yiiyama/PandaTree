#ifndef PandaTree_Interface_TreeEntry_h
#define PandaTree_Interface_TreeEntry_h

#include "IOUtils.h"
#include "Object.h"

#include "TTree.h"

#include <vector>

namespace panda {

  class CollectionBase;

  //! Base class for objects representing one full entry of a tree (e.g. Event).
  /*!
   * A derived class of TreeEntry typically owns multiple Singlets, Containers, as well as its own primitive branches.
   */
  class TreeEntry : public Object {
  public:
    TreeEntry(char const* name) : name_(name) {}
    virtual ~TreeEntry() {}

    void setStatus(TTree&, utils::BranchList const& blist) final;
    utils::BranchList getStatus(TTree&) const final;
    UInt_t setAddress(TTree&, utils::BranchList const& blist = {"*"}, Bool_t setStatus = kTRUE) final;
    void book(TTree&, utils::BranchList const& blist = {"*"}) final;
    Int_t getEntry(Long64_t entry, UInt_t treeIdx = 0) final;
    TTree* getInput(UInt_t treeIdx = 0) const final { return inputs_.at(treeIdx); }
    void releaseTree(TTree&) final;
    void init() final;
    char const* getName() const final { return name_; }
    void setName(char const* name) final { name_ = name; }

  protected:
    virtual void doSetStatus_(TTree&, utils::BranchList const&) = 0;
    virtual utils::BranchList doGetStatus_(TTree&) const = 0;
    virtual void doSetAddress_(TTree& tree, utils::BranchList const&, Bool_t setStatus) = 0;
    virtual void doBook_(TTree&, utils::BranchList const&) = 0;
    virtual void doReleaseTree_(TTree&) = 0;
    virtual void doInit_() = 0;

    TString name_{};

    std::vector<TTree*> inputs_{}; //!< list of bound inputs
    UInt_t currentInputIdx_{0xffffffff}; //!< index of current input tree
    std::vector<std::vector<UInt_t>> collInputTokens_{}; //!< list of input tokens for collection branches

    std::vector<Object*> objects_{}; //!< list of object branches (containers and singlets)
    std::vector<CollectionBase*> collections_{}; //!< list of collections (overlaps with objects_)
  };

}

#endif
