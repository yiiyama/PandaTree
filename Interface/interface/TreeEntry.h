#ifndef PandaTree_Interface_TreeEntry_h
#define PandaTree_Interface_TreeEntry_h

#include "TTree.h"
#include "TString.h"

#include "IOUtils.h"

namespace panda {

  class TreeEntry {
  public:
    TreeEntry() {}
    virtual ~TreeEntry() {}

    virtual void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) = 0;
    virtual void setAddress(TTree& tree, utils::BranchList const& = {"*"}) { input_ = &tree; }
    virtual void book(TTree&, utils::BranchList const& = {"*"}) = 0;

    virtual void init() = 0;

    TTree* getInput() const { return input_; }

  protected:
    TTree* input_{0}; // set by setAddress
  };

}

#endif
