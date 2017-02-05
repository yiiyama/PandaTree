#ifndef PandaTree_Framework_Object_h
#define PandaTree_Framework_Object_h

#include "IOUtils.h"

class TTree;

namespace panda {

  //! Object base class.
  /*!
   * Object is the base of all panda types. Its mere function is to define the interfaces of derived classes.
   * Four different types of classes inherit from Object. Element is the base class of objects that
   * are elements of containers (Array = fixed size and Collection = dynamic size). Singlet is the base class
   * of all objects that are not in containers. The containers themselves also inherit from Object. The fourth
   * derived class is TreeEntry, which represents one full entry in a TTree (e.g. Event).
   */
  class Object {
  public:
    Object() {}
    Object(Object const&) {}
    virtual ~Object() {}
    Object& operator=(Object const&) { return *this; }

    //! Set status of branches to true (matching branch) or false (vetoed branch)
    /*!
     * Sets the status of the branch to true (branch is in the list) or false (branch is vetoed in the list).
     * Branches not mentioned in the branch list are untouched.
     *
     * \param blist   List of branches. The status of a branch is set to true (false) if BranchName::in(blist) (BranchName::vetoed(blist)) evaluates to true for the branch.
    */
    virtual void setStatus(TTree&, utils::BranchList const&) {}

    //! Get status of branches in the tree
    virtual utils::BranchList getStatus(TTree&) const { return utils::BranchList(); }

    //! Bind the tree branches to the elements of this object.
    /*!
     * \param blist      List of branches to bind. Vetoed or unmentioned branches are not bound.
     * \param setStatus  If true, set the status of the branch to true before binding.
     * \return Token (serial number) of the input tree.
    */
    virtual UInt_t setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) { return -1; }

    //! Book new branches bound to this object on the tree.
    /*!
     * \param blist   List of branches to book. Vetoed or unmentioned branches are not booked.
    */
    virtual void book(TTree&, utils::BranchList const& = {"*"}) {}

    //! Read an entry from an input tree.
    /*!
      \param entry   Entry number in the input tree.
      \param treeIdx Token for the input tree as returned by setAddress().
    */
    virtual Int_t getEntry(Long64_t entry, UInt_t treeIdx = 0);

    //! Get the input tree identified by the token.
    /*!
     * \param treeIdx Token for the input tree as returned by setAddress().
     */
    virtual TTree* getInput(UInt_t treeIdx = 0) const { return 0; }

    //! Unbind the tree.
    virtual void releaseTree(TTree&) {}

    //! Reset the object state.
    virtual void init() {}

    //! Name of this object.
    virtual char const* getName() const { return ""; }

    //! Set object name.
    virtual void setName(char const*) {}
  };

}

#endif
