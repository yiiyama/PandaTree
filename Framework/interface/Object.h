#ifndef PandaTree_Framework_Object_h
#define PandaTree_Framework_Object_h

#include "IOUtils.h"
#include "TTree.h"
#include <iostream>

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
     * \param tree
     * \param blist   List of branches. The status of a branch is set to true (false) if BranchName::in(blist) (BranchName::vetoed(blist)) evaluates to true for the branch.
     */
    virtual void setStatus(TTree& tree, utils::BranchList const&) {}

    //! Get status of branches in the tree
    virtual utils::BranchList getStatus(TTree&) const { return utils::BranchList(); }

    //! Get the full list of branch names
    virtual utils::BranchList getBranchNames(Bool_t fullName = kTRUE) const { return utils::BranchList(); }

    //! Bind the tree branches to the elements of this object.
    /*!
     * \param tree
     * \param blist      List of branches to bind. Vetoed or unmentioned branches are not bound.
     * \param setStatus  If true, set the status of the branch to true before binding.
     */
    virtual void setAddress(TTree& tree, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) {}

    //! Book new branches bound to this object on the tree.
    /*!
     * \param tree
     * \param blist   List of branches to book. Vetoed or unmentioned branches are not booked.
     */
    virtual void book(TTree& tree, utils::BranchList const& = {"*"}) {}

    //! Read an entry from an input tree.
    /*!
     * \param tree    Tree to get the entry from.
     * \param entry   Entry number in the input tree.
    */
    virtual Int_t getEntry(TTree& tree, Long64_t entry) { init(); return tree.GetEntry(entry); }

    //! Fill a tree.
    /*!
     * In most of the objects this will just call tree.Fill(). The function takes care of the semi-rare
     * case of internal address change after the call to book().
     *
     * \param tree
     */
    virtual Int_t fill(TTree& tree) { return tree.Fill(); }

    //! Reset the object state.
    virtual void init() {}

    //! Name of this object.
    virtual char const* getName() const { return ""; }

    //! Set object name.
    virtual void setName(char const*) {}

    //! Print the object content.
    virtual void print(std::ostream& = std::cout) const {}
  };

}

#endif
