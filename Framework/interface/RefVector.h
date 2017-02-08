#ifndef PandaTree_Framework_RefVector_h
#define PandaTree_Framework_RefVector_h

#include "ContainerBase.h"
#include "Ref.h"

#include <stdexcept>
#include <vector>

namespace panda {

  //! A vector of references to elements in a container.
  /*!
   * The vector version of Ref, where the container is shared between the elements (individual refs).
   * A vector of index integers, instead of a single integer, is written to the tree.
   */
  template<class E>
  class RefVector {
  public:
    typedef RefVector<E> self_type;
    typedef E value_type;
    typedef std::vector<Int_t> Indices;

    //! Default constructor.
    RefVector() {}
    //! Standard constructor.
    /*!
     * The container must be a derived class of Array<E> or Collection<E>. There is no protection against
     * assigning a wrong type of container.
     */
    RefVector(ContainerBase const*& c, Indices& indices) : container_(&c), indices_(&indices) {}
    //! Copy constructor.
    RefVector(self_type const& orig) : container_(orig.container_), indices_(orig.indices_) {}
    //! Set the index.
    void setIndices(Indices& indices) { indices_ = &indices; }
    //! Set the container (an Array or a Collection).
    /*!
     * The container must be a derived class of Array<E> or Collection<E>. There is no protection against
     * assigning a wrong type of container.
     */
    void setContainer(ContainerBase const*& c) { container_ = &c; }
    //! Size of the vector.
    UInt_t size() const;
    //! Element (ref) accessor.
    Ref<value_type> at(UInt_t) const;
    //! Object accessor.
    value_type const& objAt(UInt_t) const;
    //! Assignment operator
    self_type& operator=(self_type const&);
    //! Setter function
    /*!
     * Pass a value_type object after the container is set.
     * If the object is found in the collector, pushes the index value.
     */
    void push_back(value_type const&);
    //! Setter function
    /*!
     * Pushes back a ref if the container is common.
     */
    void push_back(Ref<E> const&);
    //! Clear operation.
    void clear() { if (indices_) indices_->clear(); }
    //! Initializer
    /*!
     * Invalidates the index by setting it to 0xffffffff.
     */
    void init() { clear(); }
    //! Accessor to indices
    /*!
     * Throws a runtime_error if indices is NULL.
     */
    Indices*& indices();
    //! Accessor to container
    /*!
     * Throws a runtime_error if container is not valid.
     */
    ContainerBase const* container() const;

    //! "pointer" wrapper for Ref
    class RefHolder {
    public:
      RefHolder(ContainerBase const*& c, Int_t& idx) : ref_(c, idx) {}
      Ref<E> const& operator*() const { return ref_; }
      Ref<E> const* operator->() const { return &ref_; }
    private:
      Ref<E> ref_;
    };

    //! const iterator
    class RefVectorIterator {
      friend class RefVector<E>;
    public:
      RefVectorIterator() {}
      RefVectorIterator(RefVectorIterator const& it) : refvector_(it.refvector_), itr_(it.itr_) {}
      RefVectorIterator& operator++() { ++itr_; return *this; }
      RefVectorIterator operator++(int) { auto copy(*this); ++itr_; return copy; }
      RefVectorIterator& operator--() { --itr_; return *this; }
      RefVectorIterator operator--(int) { auto copy(*this); --itr_; return copy; }
      RefVectorIterator& operator+=(int n) { itr_ += n; return *this; }
      RefVectorIterator& operator-=(int n) { itr_ -= n; return *this; }
      RefVectorIterator operator+(int n) const { auto copy(*this); return (copy += n); }
      RefVectorIterator operator-(int n) const { auto copy(*this); return (copy -= n); }
      bool operator==(RefVectorIterator const& rhs) const { return itr_ == rhs.itr_; }
      bool operator!=(RefVectorIterator const& rhs) const { return itr_ != rhs.itr_; }
      Ref<E> operator*() const { return Ref<E>(refvector_->container_, *itr_); }
      RefVector<E>::RefHolder operator->() const { return RefVector<E>::RefHolder(refvector_->container_, *itr_); }

    private:
      RefVectorIterator(RefVector<E> const& v, Indices::const_iterator const& i) : refvector_(&v), itr_(i) {}

      RefVector<E> const* refvector_{0};
      Indices::const_iterator itr_{};
    };

    friend class RefVectorIterator;
    typedef RefVectorIterator const_iterator;
    typedef const_iterator iterator;

    const_iterator begin() const { return const_iterator(*this, indices_->begin()); }
    iterator begin() { return iterator(*this, indices_->begin()); }
    const_iterator end() const { return const_iterator(*this, indices_->end()); }
    iterator end() { return iterator(*this, indices_->end()); }

  private:
    ContainerBase const** container_{0};
    Indices* indices_{0};
  };

  template<class E>
  UInt_t
  RefVector<E>::size() const
  {
    if (!indices_)
      return 0;
    return indices_->size();
  }

  template<class E>
  Ref<E>
  RefVector<E>::at(UInt_t _i) const
  {
    if (!container_ || !indices_)
      throw std::runtime_error("at() called on an invalid RefVector");

    return Ref<E>(*container_, indices_->at(_i));
  }

  template<class E>
  E const&
  RefVector<E>::objAt(UInt_t _i) const
  {
    if (!container_ || !(*container_) || !indices_)
      throw std::runtime_error("at() called on an invalid RefVector");

    return static_cast<E const&>((*container_)->elemAt(indices_->at(_i)));
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
        indices_ = 0;
    }
    else if (_rhs.indices_)
      throw std::runtime_error("Cannot copy a valid RefVector to an invalid RefVector");

    return *this;
  }

  template<class E>
  void
  RefVector<E>::push_back(value_type const& _obj)
  {
    if (!container_ || !(*container_) || !indices_)
      throw std::runtime_error("Cannot push to an invalid RefVector");

    for (UInt_t idx(0); idx != (*container_)->size(); ++idx) {
      if (&(*container_)->elemAt(idx) == &_obj) {
        indices_->push_back(Int_t(idx));
        return;
      }
    }

    throw std::runtime_error("Pushing an object not in referenced collection");
  }
  
  template<class E>
  void
  RefVector<E>::push_back(Ref<E> const& _ref)
  {
    if (!container_ || !indices_)
      throw std::runtime_error("Cannot push to an invalid RefVector");

    if (_ref.container() != *container_)
      throw std::runtime_error("Pushing a ref of a wrong object");

    indices_->push_back(_ref.idx());
  }

  template<class E>
  std::vector<Int_t>*&
  RefVector<E>::indices()
  {
    if (!indices_)
      throw std::runtime_error("Invalid indices ref");

    return indices_;
  }

  template<class E>
  ContainerBase const*
  RefVector<E>::container() const
  {
    if (!container_)
      throw std::runtime_error("Invalid container ref");

    return *container_;
  }

}

#endif
