#ifndef PandaTree_Interface_TreeEntry_h
#define PandaTree_Interface_TreeEntry_h

#include "IOUtils.h"
#include "Object.h"

#include "TTree.h"

#include <vector>

namespace panda {

  class CollectionBase;

  class TreeEntry : public Object {
  public:
    TreeEntry(char const* name) : name_(name) {}
    virtual ~TreeEntry() {}

    void setStatus(TTree&, utils::BranchList const& blist) final;
    UInt_t setAddress(TTree&, utils::BranchList const& blist = {"*"}, Bool_t setStatus = kTRUE) final;
    void book(TTree&, utils::BranchList const& blist = {"*"}) final;
    void releaseTree(TTree&) final;
    void init() final;
    char const* getName() const final { return name_; }
    void setName(char const* name) final { name_ = name; }
    
    //! Read an entry from the input tree.
    /*!
     * \param entry     Entry number
     * \param treeIdx   Serial number of the input tree (default 0).
     */
    Int_t getEntry(Long64_t entry, UInt_t treeIdx = 0);

    TTree* getInput(UInt_t treeIdx = 0) const { return inputs_.at(treeIdx); }

  protected:
    virtual void doSetStatus_(TTree&, utils::BranchList const&) {}
    virtual void doSetAddress_(TTree& tree, utils::BranchList const&, Bool_t setStatus) {}
    virtual void doBook_(TTree&, utils::BranchList const&) {}
    virtual void doReleaseTree_(TTree&) {}
    virtual void doInit_() {}

    TString name_{};

    std::vector<TTree*> inputs_{}; //!< list of bound inputs
    TTree* currentInput_{0}; //!< current input tree
    std::vector<TTree*> outputs_{}; //!< list of bound outputs
    std::vector<std::vector<UInt_t>> collInputTokens_{}; //!< list of input tokens for object branches

    std::vector<Object*> objects_{}; //!< list of object branches (containers and singlets)
    std::vector<CollectionBase*> collections_{}; //!< list of collections (overlaps with objects_)
  };

}

#endif
