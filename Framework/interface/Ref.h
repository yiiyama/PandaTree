#ifndef PandaTree_Framework_Ref_h
#define PandaTree_Framework_Ref_h

#include "ContainerBase.h"

#include <stdexcept>
#include <type_traits>

namespace panda {

  //! A reference to an element in a container.
  /*!
   * A Ref consists of a pointer reference to a collection and an integer that acts as the index to the element referred to.
   * The references are supplied by the holder of the Ref during construction. At read time, the holder of the
   * Ref is responsible for instructing the Ref to point to a specific index in the given collection. At write time,
   * the Ref can be passed a pointer to the element to point to, using the operator=. The Ref object will find the
   * proper index internally.
   * The class has pointer-like operators (-> and *) to make the implementation details transparent to users.
   */
  template<class E, Bool_t is_const>
  class RefT {
  public:
    typedef RefT<E, is_const> self_type;
    typedef E value_type;
    typedef typename std::conditional<is_const, Short_t const, Short_t>::type index_type;

    //! Default constructor.
    RefT() {}
    //! Standard constructor.
    /*!
     * The container must be a derived class of Array<E> or Collection<E>. There is no protection against
     * assigning a wrong type of container.
     */
    RefT(ContainerBase const*& c, index_type& idx) : container_(&c), idx_(&idx) {}
    //! Copy constructor.
    RefT(self_type const& orig) : container_(orig.container_), idx_(orig.idx_) {}
    //! Set the index.
    void setIndex(index_type& idx) { idx_ = &idx; }
    //! Set the container.
    /*!
     * The container must be a derived class of Array<E> or Collection<E>. There is no protection against
     * assigning a wrong type of container.
     */
    void setContainer(ContainerBase const*& c) { container_ = &c; }
    //! The arrow operator.
    /*!
     * Returns a null pointer if the container is not set or the index points to an invalid location.
     */
    value_type const* operator->() const;
    //! The dereference operator.
    /*!
     * Throws an invalid_argument exception if the reference is invalid.
     */
    value_type const& operator*() const;
    //! Setter function
    /*!
     * Pass a pointer to a value_type object on the right hand side after the container is set.
     * If the object is found in the collector, sets the index value.
     */
    template<Bool_t C = is_const>
    typename std::enable_if<!C, self_type&>::type operator=(value_type const*);
    //! Copy assignment
    /*!
     * idx is copied by value. Change in the right-hand-side index value after the assignment
     * is not reflected to the left-hand-side index.
     */
    template<Bool_t C = is_const>
    typename std::enable_if<!C, self_type&>::type operator=(self_type const&);
    //! Validity check. Both container and idx must be valid, and idx must not be 0xffffffff.
    bool isValid() const { return container_ && *container_ && idx_ && (*idx_) < (*container_)->size(); }
    //! Initializer
    /*!
     * Invalidates the index by setting it to 0xffffffff.
     */
    template<Bool_t C = is_const>
    typename std::enable_if<!C>::type init() { if (idx_) (*idx_) = -1; }
    //! Accessor to idx
    /*!
     * Throws a runtime_error if idx is not valid.
     */
    template<Bool_t C = is_const>
    typename std::enable_if<!C, Short_t&>::type idx();
    //! Accessor to container
    /*!
     * Throws a runtime_error if container is not valid.
     */
    ContainerBase const* container() const;
    //! Pointer to object
    value_type const* get() const { return operator->(); }

  private:
    ContainerBase const** container_{0};
    index_type* idx_{0};
  };

  template<class E, Bool_t is_const>
  E const*
  RefT<E, is_const>::operator->() const
  {
    if (!container_ || !(*container_) || !idx_ || (*idx_) < 0)
      return 0;

    return &static_cast<E const&>((*container_)->elemAt(*idx_));
  }

  template<class E, Bool_t is_const>
  E const&
  RefT<E, is_const>::operator*() const
  {
    if (!container_ || !(*container_) || !idx_ || (*idx_) < 0)
      throw std::runtime_error("Dereferencing an invalid Ref");

    return static_cast<E const&>((*container_)->elemAt(*idx_));
  }
  
  template<class E, Bool_t is_const>
  template<Bool_t C/* = is_const*/>
  typename std::enable_if<!C, RefT<E, is_const>&>::type
  RefT<E, is_const>::operator=(value_type const* _rhs)
  {
    if (!_rhs) {
      container_ = 0;
      idx_ = 0;
    }

    if (!container_ || !(*container_) || !idx_)
      return *this;

    for ((*idx_) = 0; (*idx_) != Short_t((*container_)->size()); ++(*idx_)) {
      if (&(*container_)->elemAt(*idx_) == _rhs)
        return *this;
    }

    (*idx_) = -1;
    return *this;
  }

  template<class E, Bool_t is_const>
  template<Bool_t C/* = is_const*/>
  typename std::enable_if<!C, RefT<E, is_const>&>::type
  RefT<E, is_const>::operator=(self_type const& _rhs)
  {
    container_ = _rhs.container_;
    if (idx_) {
      if (_rhs.idx_)
        (*idx_) = (*_rhs.idx_);
      else
        (*idx_) = -1;
    }
    return *this;
  }

  template<class E, Bool_t is_const>
  template<Bool_t C/* = is_const*/>
  typename std::enable_if<!C, Short_t&>::type
  RefT<E, is_const>::idx()
  {
    if (!idx_)
      throw std::runtime_error("Invalid index ref");

    return *idx_;
  }

  template<class E, Bool_t is_const>
  ContainerBase const*
  RefT<E, is_const>::container() const
  {
    if (!container_)
      throw std::runtime_error("Invalid container ref");

    return *container_;
  }

  template<class E>
  using Ref = RefT<E, kFALSE>;

  template<class E>
  using ConstRef = RefT<E, kTRUE>;
}

#endif
