#ifndef PandaTree_Framework_Container_h
#define PandaTree_Framework_Container_h

#include "ArrayBase.h"
#include "CollectionBase.h"
#include "Iterator.h"

#include <stdexcept>
#include <memory>
#include <type_traits>

namespace panda {

  template<class E, Bool_t FIXED>
  class Container : public std::conditional<FIXED, typename E::base_type::array_type, typename E::base_type::collection_type>::type {
  public:
    typedef Container<E, FIXED> self_type;
    typedef typename std::conditional<FIXED, typename E::base_type::array_type, typename E::base_type::collection_type>::type base_type;
    typedef E value_type;
    typedef value_type* pointer;
    typedef value_type const* const_pointer;
    typedef value_type& reference;
    typedef value_type const& const_reference;
    typedef utils::Iterator<self_type, false> iterator;
    typedef utils::Iterator<self_type, true> const_iterator;

    template<Bool_t T = FIXED>
    Container(typename std::enable_if<T, UInt_t>::type size, char const* name = "") : base_type(name, sizeof(E), kFALSE) { allocate_(size); }
    template<Bool_t T = FIXED>
    Container(char const* name = "", typename std::enable_if<!T, UInt_t>::type initialMax = 64) : base_type(name, sizeof(E), kFALSE) { allocate_(initialMax); }
    
    template<Bool_t T = FIXED>
    Container(typename std::enable_if<T, self_type>::type const& src) : Container(src.getData().nmax(), src.ContainerBase::name_) { copy(src); }
    template<Bool_t T = FIXED>
    Container(typename std::enable_if<!T, self_type>::type const& src) : Container(src.ContainerBase::name_, src.getData().nmax()) { copy(src); }
    ~Container();
    self_type& operator=(self_type const& rhs) { copy(rhs); return *this; }

    //! Element accessor with range check
    reference at(UInt_t idx);
    //! Element accessor with range check
    const_reference at(UInt_t idx) const;
    //! Element accessor with no range check
    reference operator[](UInt_t);
    //! Element accessor with no range check
    const_reference operator[](UInt_t) const;
    //! Return an iterator pointing to the first element
    iterator begin() { return iterator(addr_(), ContainerBase::unitSize_); }
    //! Return an iterator pointing to the first element
    const_iterator begin() const { return const_iterator(const_addr_(), ContainerBase::unitSize_); }
    //! Return an iterator pointing to the end of the array (invalid address)
    iterator end() { return iterator(addr_() + max_(), ContainerBase::unitSize_); }
    //! Return an iterator pointing to the end of the array (invalid address)
    const_iterator end() const { return const_iterator(const_addr_() + max_(), ContainerBase::unitSize_); }
    //! Reference to the first element
    reference front() { return operator[](0); }
    //! Reference to the first element
    const_reference front() const { return operator[](0); }
    //! Reference to the last element
    reference back() { return operator[](max_() - 1); }
    //! Reference to the last element
    const_reference back() const { return operator[](max_() - 1); }
    //! Copy the array contents.
    /*!
      If the new size is greater than nmax, data will be reallocated, making all references invalid.
    */
    template<Bool_t T = FIXED>
    typename std::enable_if<T>::type copy(self_type const&);
    template<Bool_t T = FIXED>
    typename std::enable_if<!T>::type copy(self_type const&);

    template<Bool_t T = FIXED>
    typename std::enable_if<!T>::type push_back(const_reference);
    template<Bool_t T = FIXED>
    typename std::enable_if<!T, reference>::type create_back() { resize(max_() + 1); return back(); }

    ContainerElement::datastore& getData() override { return data; }
    ContainerElement::datastore const& getData() const override { return data; }
    ContainerElement& elemAt(UInt_t idx) override { return at(idx); }
    ContainerElement const& elemAt(UInt_t idx) const override { return at(idx); }

    typename value_type::datastore data{};

  protected:
    Container(char const* name, UInt_t unitSize, Bool_t dummy) : base_type(name, unitSize, kFALSE) {}

    void allocate_(UInt_t) override;
    void deallocate_() override;
    void reallocate_(UInt_t) override;

  private:
    template<Bool_t T = FIXED>
    typename std::enable_if<T, UInt_t>::type max_() const { return getData().nmax(); }
    template<Bool_t T = FIXED>
    typename std::enable_if<!T, UInt_t>::type max_() const { return CollectionBase::size_; }
    pointer addr_() const { return reinterpret_cast<pointer>(ContainerBase::array_); }
    const_pointer const_addr_() const { return reinterpret_cast<const_pointer>(ContainerBase::array_); }
  };

  template<class E, Bool_t FIXED>
  Container<E, FIXED>::~Container()
  {
    if (ContainerBase::array_) {
      deallocate_();
      ContainerBase::array_ = 0;
    }
  }

  template<class E, Bool_t FIXED>
  typename Container<E, FIXED>::reference
  Container<E, FIXED>::at(UInt_t _idx)
  {
    if (_idx >= max_())
      throw std::out_of_range((ContainerBase::name_ + "::at").Data());

    // Here we may be calling from a base class (when E0 <- E1, (Container<E0>*)(&t1_array)->at(i) should properly point to the second *E1*, not E0),
    // which means we must shift by _idx * unitSize_ instead of _idx * sizeof(value_type).
    Char_t* p(ContainerBase::array_);
    p += _idx * ContainerBase::unitSize_;

    return *reinterpret_cast<pointer>(p);
  }

  template<class E, Bool_t FIXED>
  typename Container<E, FIXED>::const_reference
  Container<E, FIXED>::at(UInt_t _idx) const
  {
    if (_idx >= max_())
      throw std::out_of_range((ContainerBase::name_ + "::at").Data());
  
    // Here we may be calling from a base class (when E0 <- E1, (Container<E0>*)(&t1_array)->at(i) should properly point to the second *E1*, not E0),
    // which means we must shift by _idx * unitSize_ instead of _idx * sizeof(value_type).
    Char_t* p(ContainerBase::array_);
    p += _idx * ContainerBase::unitSize_;

    return *reinterpret_cast<const_pointer>(p);
  }

  template<class E, Bool_t FIXED>
  typename Container<E, FIXED>::reference
  Container<E, FIXED>::operator[](UInt_t _idx)
  {
    // Here we may be calling from a base class (when E0 <- E1, (Array<E0>*)(&t1_array)->at(i) should properly point to the second *E1*, not E0),
    // which means we must shift by _idx * unitSize_ instead of _idx * sizeof(value_type).
    Char_t* p(ContainerBase::array_);
    p += _idx * ContainerBase::unitSize_;

    return *reinterpret_cast<pointer>(p);
  }

  template<class E, Bool_t FIXED>
  typename Container<E, FIXED>::const_reference
  Container<E, FIXED>::operator[](UInt_t _idx) const
  {
    // Here we may be calling from a base class (when E0 <- E1, (Array<E0>*)(&t1_array)->at(i) should properly point to the second *E1*, not E0),
    // which means we must shift by _idx * unitSize_ instead of _idx * sizeof(value_type).
    Char_t* p(ContainerBase::array_);
    p += _idx * ContainerBase::unitSize_;

    return *reinterpret_cast<const_pointer>(p);
  }

  template<class E, Bool_t FIXED>
  template<Bool_t T/* = FIXED*/>
  typename std::enable_if<T>::type
  Container<E, FIXED>::copy(self_type const& _src)
  {
    if (_src.ContainerBase::unitSize_ != ContainerBase::unitSize_)
      throw std::runtime_error((ContainerBase::name_ + "::copy incompatible array").Data());

    if (_src.getData().nmax() != getData().nmax())
      reallocate_(_src.getData().nmax());
    
    for (unsigned iP(0); iP != max_(); ++iP)
      (*this)[iP] = _src[iP];

    setName(_src.name_);
  }

  template<class E, Bool_t FIXED>
  template<Bool_t T/* = FIXED*/>
  typename std::enable_if<!T>::type
  Container<E, FIXED>::copy(self_type const& _src)
  {
    if (_src.ContainerBase::unitSize_ != ContainerBase::unitSize_)
      throw std::runtime_error((ContainerBase::name_ + "::copy incompatible array").Data());

    resize(_src.size_);
    
    for (unsigned iP(0); iP != max_(); ++iP)
      (*this)[iP] = _src[iP];

    setName(_src.name_);
  }

  template<class E, Bool_t FIXED>
  template<Bool_t T/* = FIXED*/>
  typename std::enable_if<!T>::type
  Container<E, FIXED>::push_back(const_reference _elem)
  {
    if (max_() == getData().nmax()) {
      // reallocate elements with nmax *= 2
      // all references and pointers to data members and array elements will become invalid
      reallocate_(getData().nmax() * 2);
    }

    (*this)[CollectionBase::size_] = _elem;
    ++CollectionBase::size_;
  }

  /*private*/
  template<class E, Bool_t FIXED>
  void
  Container<E, FIXED>::allocate_(UInt_t _nmax)
  {
    data.allocate(_nmax);

    ContainerBase::array_ = reinterpret_cast<Char_t*>(std::allocator<value_type>().allocate(data.nmax()));

    pointer p(addr_());
    for (unsigned iP(0); iP != data.nmax(); ++iP, ++p)
      new (p) value_type(data, iP);
  }

  /*private*/
  template<class E, Bool_t FIXED>
  void
  Container<E, FIXED>::deallocate_()
  {
    std::allocator<value_type>().deallocate(reinterpret_cast<pointer>(ContainerBase::array_), data.nmax());
    data.deallocate();
  }

  /*private*/
  template<class E, Bool_t FIXED>
  void
  Container<E, FIXED>::reallocate_(UInt_t _nmax)
  {
    if (FIXED) {
      deallocate_();
      allocate_(_nmax);
    }
    else {
      // keep the copy of the pointers temporarily
      // tmpStore is not directly used but is linked from tmpArray
      auto tmpStore(data);
      pointer tmpArray(reinterpret_cast<pointer>(ContainerBase::array_));

      // allocate new space
      allocate_(_nmax);

      // copy old values
      for (unsigned iP(0); iP != max_(); ++iP)
        (*this)[iP] = tmpArray[iP];

      // deallocate old space
      std::allocator<value_type>().deallocate(tmpArray, tmpStore.nmax());
      tmpStore.deallocate();
    }

    // update input and output pointers
    ContainerBase::updateAddress_();
  }

  template<class E>
  using Array = Container<E, kTRUE>;

  template<class E>
  using Collection = Container<E, kFALSE>;

}

#endif
