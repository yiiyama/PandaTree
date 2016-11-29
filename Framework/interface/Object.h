#ifndef PandaTree_Framework_Object_h
#define PandaTree_Framework_Object_h

//! Object base class.
/*!
  Object is the base of all panda types. Its mere function is to define the interfaces of derived objects.
  Two different types of classes inherit from Object. ContainerElement is the base class of objects that
  are elements of containers (Array = fixed size and Collection = dynamic size). Singlet is the base class
  of all objects that are not in containers.
*/

#include "IOUtils.h"

#include "TTree.h"

namespace panda {

  class Object {
  public:
    Object() {}
    Object(Object const&) {}
    virtual ~Object() {}
    Object& operator=(Object const&) { return *this; }

    //! Set status of branches with names that correspond to the variables of this object.
    virtual void setStatus(TTree&, Bool_t enabled, utils::BranchList const& = {"*"}) {}
    //! Set address for the branches to the variables of this object.
    virtual void setAddress(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) {}
    //! Book new branches to the tree corresponding to the variables of this object.
    virtual void book(TTree&, utils::BranchList const& = {"*"}) {}
    //! Reset the branch pointer to unlink the branch from this object.
    virtual void resetAddress(TTree&) {}

    virtual void setName(char const*) {}
    virtual void init() {}
  };

}

#endif
