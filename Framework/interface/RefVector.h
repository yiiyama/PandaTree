#ifndef PandaTree_Framework_RefVector_h
#define PandaTree_Framework_RefVector_h

//! A vector of references to elements in a container.
/*!
  The vector version of Ref, where the collection is shared between the elements (individual refs).
  A vector of index integers, instead of a single integer, is written to the tree.
*/

#include "ContainerBase.h"
#include "Ref.h"

#include <stdexcept>
#include <type_traits>
#include <vector>

namespace panda {

  template<class E>
  class RefVector {
  public:
    typedef RefVector<E> self_type;
    typedef E value_type;
    typedef typename E::array_type array_type;
    typedef typename E::collection_type collection_type;
    typedef std::vector<UInt_t> Indices;

    //! Default constructor.
    RefVector() {}
    //! Standard constructor. 
    /*!
      The argument idx must not go out of the scope before this object is destroyed.
    */
    RefVector(Indices& indices) : indices_(&indices) {}
    //! Constructor with array container.
    RefVector(Indices& indices, array_type const& c) : indices_(&indices), container_(&c) {}
    //! Constructor with collection container.
    RefVector(Indices& indices, collection_type const& c) : indices_(&indices), container_(&c) {}
    //! Copy constructor.
    RefVector(self_type const& orig) : indices_(orig.indices_), container_(orig.container_) {}
    //! Set the index.
    void setIndices(Indices& indices) { indices_ = &indices; }
    //! Set the container (an Array or a Collection).
    void setContainer(array_type const& c) { container_ = &c; }
    //! Set the container (an Array or a Collection).
    void setContainer(collection_type const& c) { container_ = &c; }
    //! Element (ref) accessor.
    Ref<value_type> at(UInt_t) const;
    //! Object accessor.
    value_type const& objAt(UInt_t) const;
    //! Assignment operator
    self_type& operator=(self_type const&);
    //! Setter function
    /*!
      Pass a value_type object after the container is set.
      If the object is found in the collector, pushes the index value.
    */
    void push_back(value_type const&);
    //! Setter function
    /*!
      Pushes back a ref if the container is common.
    */
    void push_back(Ref<E> const&);
    //! Clear operation.
    void clear() { if (indices_) indices_->clear(); }
    //! Initializer
    /*!
      Invalidates the index by setting it to 0xffffffff.
    */
    void init() { clear(); }
    //! Accessor to indices
    /*!
      Throws a runtime_error if indices is NULL.
    */
    Indices*& indices();

  private:
    ContainerBase const* container_{0};
    Indices* indices_{0};
  };

  template<class E>
  Ref<E>
  RefVector<E>::at(UInt_t _i) const
  {
    if (!container_ || !indices_)
      throw std::runtime_error("at() called on an invalid RefVector");

    return Ref<E>(indices_->at(_i), *container_);
  }

  template<class E>
  E const&
  RefVector<E>::objAt(UInt_t _i) const
  {
    if (!container_ || !indices_)
      throw std::runtime_error("at() called on an invalid RefVector");

    return static_cast<E const&>(container_->elemAt(indices_->at(_i)));
  }

  template<class E>
  RefVector<E>&
  RefVector<E>::operator=(self_type const& _rhs)
  {
    container_ = _rhs.container_;
    if (indices_) {
      if (_rhs.indices_)
        indices_->assign(_rhs.indices_->begin(), _rhs.indices_->end());
      else
        indices_->clear();
    }
    return *this;
  }

  template<class E>
  void
  RefVector<E>::push_back(value_type const& _obj)
  {
    if (!container_ || !indices_)
      throw std::runtime_error("Cannot push to an invalid RefVector");

    for (unsigned idx(0); idx != container_->size(); ++idx) {
      if (&container_->elemAt(idx) == &_obj) {
        indices_->push_back(idx);
        return;
      }
    }
  }
  
  template<class E>
  void
  RefVector<E>::push_back(Ref<E> const& _ref)
  {
    if (!container_ || !indices_)
      throw std::runtime_error("Cannot push to an invalid RefVector");

    if (_ref.container() != container_)
      throw std::runtime_error("Pushing a ref of a wrong object");

    indices_->push_back(_ref.idx());
  }

  template<class E>
  std::vector<UInt_t>*&
  RefVector<E>::indices()
  {
    if (!indices_)
      throw std::runtime_error("Invalid indices ref");

    return indices_;
  }

}

#endif
