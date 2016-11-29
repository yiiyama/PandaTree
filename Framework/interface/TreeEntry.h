#ifndef PandaTree_Interface_TreeEntry_h
#define PandaTree_Interface_TreeEntry_h

#include "IOUtils.h"

#include "TTree.h"

#include <vector>

namespace panda {

  class TreeEntry {
  public:
    TreeEntry() {}
    virtual ~TreeEntry() {}

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"});
    void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE);
    void book(TTree&, utils::BranchList const& = {"*"});
    void releaseTree(TTree&);

    Int_t getEntry(Long64_t);

    virtual void init() = 0;

    TTree* getInput() const { return input_; }

  protected:
    virtual void doSetStatus_(TTree&, Bool_t, utils::BranchList const&) = 0;
    virtual void doSetAddress_(TTree& tree, utils::BranchList const&, Bool_t setStatus) = 0;
    virtual void doBook_(TTree&, utils::BranchList const&) = 0;
    virtual void doReleaseTree_(TTree&) = 0;
    virtual void adjustCollectionSizes_() = 0;

    TTree* input_{0}; // set by setAddress
    std::vector<TBranch*> sizeBranches_{}; // branches in the input tree for object sizes
    std::vector<TTree*> outputs_{};
  };

}

#endif
