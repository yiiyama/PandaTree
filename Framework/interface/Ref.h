#ifndef PandaTree_Interface_Ref_h
#define PandaTree_Interface_Ref_h

//! A reference to an element in a container.
/*!
  A Ref consists of a pointer to a collection and an integer that acts as the index to the element referred to.
  The index integer is supplied by the holder of the Ref during construction. At read time, the holder of the
  Ref is responsible for instructing the Ref to point to a specific index in the given collection. At write time,
  the Ref can be passed a pointer to the element to point to, using the operator=. The Ref object will find the
  proper index internally.
  The class has pointer-like operators (-> and *) to make the implementation details transparent to users.
*/

#include "Container.h"
#include <stdexcept>

namespace panda {
  template<class container_type>
  class Ref {
  public:
    typedef Ref<container_type> self_type;
    typedef typename container_type::value_type value_type;
    //! Standard constructor. 
    /*!
      The argument idx must not go out of the scope before this object is destroyed.
    */
    Ref(UInt_t& idx) : idx(idx) {}
    //! Copy constructor.
    Ref(self_type const& orig) : idx(orig.idx), container_(orig.container_) {}
    //! Set the container (an Array or a Collection).
    void setContainer(container_type const& container) { container_ = &container; idx = -1; }
    //! The arrow operator.
    /*!
      Returns a null pointer if the container is not set or the index points to an invalid location.
    */
    value_type const* operator->() const;
    //! The dereference operator.
    /*!
      Throws an invalid_argument exception if the reference is invalid.
    */
    value_type const& operator*() const;
    //! Setter function
    /*!
      Pass a pointer to a value_type object on the right hand side after the container is set.
      If the object is found in the collector, sets the index value.
    */
    self_type& operator=(value_type const*);
    //! Copy assignment
    /*!
      idx is copied by value. Change in the right-hand-side index value after the assignment
      is not reflected to the left-hand-side index.
    */
    self_type& operator=(self_type const&);
    //! Initializer
    /*!
      Invalidates the index by setting it to 0xffffffff.
    */
    bool isValid() const { return container_ && idx <= container_->size(); }
    void init() { idx = -1; }

    UInt_t& idx;

  private:
    container_type const* container_{0};
  };

  template<class container_type>
  typename container_type::value_type const*
  Ref<container_type>::operator->() const
  {
    if (!container_)
      return 0;

    return &container_->at(idx);
  }

  template<class container_type>
  typename container_type::value_type const&
  Ref<container_type>::operator*() const
  {
    if (!container_)
      return std::invalid_argument("Dereference of a null container");

    return container_->at(idx);
  }
  
  template<class container_type>
  Ref<container_type>&
  Ref<container_type>::operator=(value_type const* _rhs)
  {
    if (!_rhs) {
      container_ = 0;
      idx = -1;
    }

    if (!container_)
      return *this;

    for (idx = 0; idx != container_->size(); ++idx) {
      if (&container_[idx] == _rhs)
        return *this;
    }

    idx = -1;
    return *this;
  }

  template<class container_type>
  Ref<container_type>&
  Ref<container_type>::operator=(self_type const& _rhs)
  {
    container_ = _rhs.container_;
    idx = _rhs.idx;
    return *this;
  }
}

#endif
