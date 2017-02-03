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

    //! Set status of branches to true (matching branch) or false (vetoed branch)
    /*!
     * Sets the status of the branch to true (branch is in the list) or false (branch is vetoed in the list).
     * Branches not mentioned in the branch list are untouched.
     *
     * \param blist   List of branches. The status of a branch is set to true (false) if BranchName::in(blist) (BranchName::vetoed(blist)) evaluates to true for the branch.
     */
    void setStatus(TTree&, utils::BranchList const& blist) override;

    //! Bind the tree to this object.
    /*!
     * \param blist      List of branches to bind. Vetoed or unmentioned branches are not bound.
     * \param setStatus  If true, set the status of the branch to true before binding.
     * \return Token (serial number) of the input tree
     */
    UInt_t setAddress(TTree&, utils::BranchList const& blist = {"*"}, Bool_t setStatus = kTRUE) override;

    //! Create branches bound to this object on the tree.
    /*!
     * \param blist      List of branches to bind. Vetoed or unmentioned branches are not created.
     * \return Token (seral number) of the booked tree
     */
    UInt_t book(TTree&, utils::BranchList const& blist = {"*"}) override;

    //! Unbind a tree.
    void releaseTree(TTree&) override;

    char const* getName() const override { return name_; }
    void setName(char const* name) override { name_ = name; }

    //! Read an entry from the input tree.
    /*!
     * \param entry     Entry number
     * \param treeIdx   Serial number of the input tree (default 0).
     */
    Int_t getEntry(Long64_t entry, UInt_t treeIdx = 0);

    TTree* getInput(UInt_t treeIdx = 0) const { return inputs_.at(treeIdx); }

  protected:
    virtual void doSetStatus_(TTree&, utils::BranchList const&) {};
    virtual void doSetAddress_(TTree& tree, utils::BranchList const&, Bool_t setStatus) = 0;
    virtual void doBook_(TTree&, utils::BranchList const&) = 0;
    virtual void doReleaseTree_(TTree&) = 0;

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
