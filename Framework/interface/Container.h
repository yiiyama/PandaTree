#ifndef PandaTree_Framework_Container_h
#define PandaTree_Framework_Container_h

#include "ArrayBase.h"
#include "CollectionBase.h"
#include "Iterator.h"

#include <stdexcept>
#include <memory>
#include <type_traits>

/* #define IS_ARRAY typename std::enable_if<std::is_base_of<ArrayBase, B>::value>::type* = 0 */
/* #define IS_COLLECTION typename std::enable_if<std::is_base_of<CollectionBase, B>::value>::type* = 0 */

namespace panda {

  template<class E, class Base>
  class Container : public Base {
  public:
    typedef Container<E, Base> self_type;
    typedef E value_type;
    typedef value_type* pointer;
    typedef value_type const* const_pointer;
    typedef value_type& reference;
    typedef value_type const& const_reference;
    typedef utils::Iterator<self_type, false> iterator;
    typedef utils::Iterator<self_type, true> const_iterator;

    template<class B = Base>
    Container(UInt_t size, char const* name = "", typename std::enable_if<std::is_base_of<ArrayBase, B>::value>::type* = 0) : Base(name, sizeof(E), kFALSE) { allocate_(size); }
    template<class B = Base>
    Container(char const* name = "", UInt_t initialMax = 64, typename std::enable_if<std::is_base_of<CollectionBase, B>::value>::type* = 0) : Base(name, sizeof(E), kFALSE) { allocate_(initialMax); }
    
    template<class B = Base>
    Container(self_type const& src, typename std::enable_if<std::is_base_of<ArrayBase, B>::value>::type* = 0) : Container(src.getData().nmax(), src.ContainerBase::name_) { copy(src); }
    template<class B = Base>
    Container(self_type const& src, typename std::enable_if<std::is_base_of<CollectionBase, B>::value>::type* = 0) : Container(src.ContainerBase::name_, src.getData().nmax()) { copy(src); }
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
    void copy(self_type const&);

    template<class B = Base>
    typename std::enable_if<std::is_base_of<CollectionBase, B>::value>::type push_back(const_reference);
    template<class B = Base>
    typename std::enable_if<std::is_base_of<CollectionBase, B>::value, reference>::type create_back() { resize(max_() + 1); return back(); }
    template<class B = Base>
    typename std::enable_if<std::is_base_of<CollectionBase, B>::value>::type resize(UInt_t size);

    ContainerElement::datastore& getData() override { return data; }
    ContainerElement::datastore const& getData() const override { return data; }
    ContainerElement& elemAt(UInt_t idx) override { return at(idx); }
    ContainerElement const& elemAt(UInt_t idx) const override { return at(idx); }

    typename value_type::datastore data{};

  protected:
    Container(char const* name, UInt_t unitSize, Bool_t dummy) : Base(name, unitSize, kFALSE) {}

    template<class B = Base>
    typename std::enable_if<std::is_base_of<ArrayBase, B>::value, UInt_t>::type max_() const { return getData().nmax(); }
    template<class B = Base>
    typename std::enable_if<std::is_base_of<CollectionBase, B>::value, UInt_t>::type max_() const { return CollectionBase::size_; }

  private:
    void allocate_(UInt_t) override;
    void deallocate_() override;
    void reallocate_(UInt_t) override;

    pointer addr_() const { return reinterpret_cast<pointer>(ContainerBase::array_); }
    const_pointer const_addr_() const { return reinterpret_cast<const_pointer>(ContainerBase::array_); }
  };

  template<class E, class Base>
  Container<E, Base>::~Container()
  {
    if (ContainerBase::array_) {
      deallocate_();
      ContainerBase::array_ = 0;
    }
  }

  template<class E, class Base>
  typename Container<E, Base>::reference
  Container<E, Base>::at(UInt_t _idx)
  {
    if (_idx >= max_())
      throw std::out_of_range((ContainerBase::name_ + "::at").Data());

    // Here we may be calling from a base class (when E0 <- E1, (Container<E0>*)(&t1_array)->at(i) should properly point to the second *E1*, not E0),
    // which means we must shift by _idx * unitSize_ instead of _idx * sizeof(value_type).
    Char_t* p(ContainerBase::array_);
    p += _idx * ContainerBase::unitSize_;

    return *reinterpret_cast<pointer>(p);
  }

  template<class E, class Base>
  typename Container<E, Base>::const_reference
  Container<E, Base>::at(UInt_t _idx) const
  {
    if (_idx >= max_())
      throw std::out_of_range((ContainerBase::name_ + "::at").Data());
  
    // Here we may be calling from a base class (when E0 <- E1, (Container<E0>*)(&t1_array)->at(i) should properly point to the second *E1*, not E0),
    // which means we must shift by _idx * unitSize_ instead of _idx * sizeof(value_type).
    Char_t* p(ContainerBase::array_);
    p += _idx * ContainerBase::unitSize_;

    return *reinterpret_cast<const_pointer>(p);
  }

  template<class E, class Base>
  typename Container<E, Base>::reference
  Container<E, Base>::operator[](UInt_t _idx)
  {
    // Here we may be calling from a base class (when E0 <- E1, (Array<E0>*)(&t1_array)->at(i) should properly point to the second *E1*, not E0),
    // which means we must shift by _idx * unitSize_ instead of _idx * sizeof(value_type).
    Char_t* p(ContainerBase::array_);
    p += _idx * ContainerBase::unitSize_;

    return *reinterpret_cast<pointer>(p);
  }

  template<class E, class Base>
  typename Container<E, Base>::const_reference
  Container<E, Base>::operator[](UInt_t _idx) const
  {
    // Here we may be calling from a base class (when E0 <- E1, (Array<E0>*)(&t1_array)->at(i) should properly point to the second *E1*, not E0),
    // which means we must shift by _idx * unitSize_ instead of _idx * sizeof(value_type).
    Char_t* p(ContainerBase::array_);
    p += _idx * ContainerBase::unitSize_;

    return *reinterpret_cast<const_pointer>(p);
  }

  template<class E, class Base>
  void
  Container<E, Base>::copy(self_type const& _src)
  {
    if (_src.ContainerBase::unitSize_ != ContainerBase::unitSize_)
      throw std::runtime_error((ContainerBase::name_ + "::copy incompatible array").Data());

    if (std::is_base_of<ArrayBase, Base>::value) {
      if (_src.getData().nmax() != getData().nmax())
        reallocate_(_src.getData().nmax());
    }
    else if (std::is_base_of<CollectionBase, Base>::value) {
      resize(_src.size_);
    }
    
    for (unsigned iP(0); iP != max_(); ++iP)
      (*this)[iP] = _src[iP];

    setName(_src.name_);
  }

  template<class E, class Base>
  template<class B/* = Base*/>
  typename std::enable_if<std::is_base_of<CollectionBase, B>::value>::type
  Container<E, Base>::push_back(const_reference _elem)
  {
    if (max_() == getData().nmax()) {
      // reallocate elements with nmax *= 2
      // all references and pointers to data members and array elements will become invalid
      reallocate_(getData().nmax() * 2);
    }

    (*this)[CollectionBase::size_] = _elem;
    ++CollectionBase::size_;
  }

  template<class E, class Base>
  template<class B/* = Base*/>
  typename std::enable_if<std::is_base_of<CollectionBase, B>::value>::type
  Container<E, Base>::resize(UInt_t _size)
  {
    if (_size > getData().nmax()) {
      UInt_t nmax(getData().nmax());
      while (nmax < _size)
        nmax *= 2;

      reallocate_(nmax);
    }
  
    CollectionBase::size_ = _size;
  }

  /*private*/
  template<class E, class Base>
  void
  Container<E, Base>::allocate_(UInt_t _nmax)
  {
    data.allocate(_nmax);

    ContainerBase::array_ = reinterpret_cast<Char_t*>(std::allocator<value_type>().allocate(data.nmax()));

    pointer p(addr_());
    for (unsigned iP(0); iP != data.nmax(); ++iP, ++p)
      new (p) value_type(data, iP);
  }

  /*private*/
  template<class E, class Base>
  void
  Container<E, Base>::deallocate_()
  {
    std::allocator<value_type>().deallocate(reinterpret_cast<pointer>(ContainerBase::array_), data.nmax());
    data.deallocate();
  }

  /*private*/
  template<class E, class Base>
  void
  Container<E, Base>::reallocate_(UInt_t _nmax)
  {
    if (std::is_base_of<ArrayBase, Base>::value) {
      deallocate_();
      allocate_(_nmax);
    }
    else if (std::is_base_of<CollectionBase, Base>::value) {
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

}

#endif
