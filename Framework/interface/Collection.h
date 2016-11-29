#ifndef PandaTree_Framework_Collection_h
#define PandaTree_Framework_Collection_h

#include "CollectionBase.h"
#include "Iterator.h"

#include <stdexcept>
#include <memory>

namespace panda {

  template<class T, class Base>
  class Collection : public Base {
  public:
    typedef Collection<T, Base> self_type;
    typedef T value_type;
    typedef value_type* pointer;
    typedef value_type const* const_pointer;
    typedef value_type& reference;
    typedef value_type const& const_reference;
    typedef utils::Iterator<self_type, false> iterator;
    typedef utils::Iterator<self_type, true> const_iterator;

    Collection(char const* name = "", UInt_t initialMax = 64);
    Collection(self_type const&);
    ~Collection();
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
    iterator end() { return iterator(addr_() + getData().nmax()); }
    //! Return an iterator pointing to the end of the array (invalid address)
    const_iterator end() const { return const_iterator(const_addr_() + getData().nmax()); }
    //! Reference to the first element
    reference front() { return operator[](0); }
    //! Reference to the first element
    const_reference front() const { return operator[](0); }
    //! Reference to the last element
    reference back() { return operator[](getData().nmax() - 1); }
    //! Reference to the last element
    const_reference back() const { return operator[](getData().nmax() - 1); }
    //! Copy the array contents.
    /*!
      If the new size is greater than nmax, data will be reallocated, making all references invalid.
    */
    void copy(self_type const&);
    void push_back(const_reference);
    reference create_back() { resize(CollectionBase::size_ + 1); return back(); }
    void resize(UInt_t size);

    ContainerElement::datastore& getData() override { return data; }
    ContainerElement::datastore const& getData() const override { return data; }
    ContainerElement& elemAt(UInt_t idx) override { return at(idx); }
    ContainerElement const& elemAt(UInt_t idx) const override { return at(idx); }

    typename value_type::datastore data{};

  protected:
    Collection(char const*, UInt_t, Bool_t dummy);

  private:
    void allocate_(UInt_t) override;
    void deallocate_() override;
    virtual void reallocate_(UInt_t);

    pointer addr_() const { return reinterpret_cast<pointer>(ContainerBase::array_); }
    const_pointer const_addr_() const { return reinterpret_cast<const_pointer>(ContainerBase::array_); }
  };

  template<class T, class Base>
  Collection<T, Base>::Collection(char const* _name/* = ""*/, UInt_t _initialMax/* = 64*/) :
    Base(_name, sizeof(T), kFALSE)
  {
    allocate_(_initialMax);
  }

  template<class T, class Base>
  Collection<T, Base>::Collection(self_type const& _src) :
    Collection(_src.ContainerBase::name_, _src.getData().nmax())
  {
    copy(_src);
  }

  /*protected*/
  template<class T, class Base>
  Collection<T, Base>::Collection(char const* _name, UInt_t _unitSize, Bool_t) :
    Base(_name, _unitSize, kFALSE)
  {
  }

  template<class T, class Base>
  Collection<T, Base>::~Collection()
  {
    if (ContainerBase::array_) {
      deallocate_();
      ContainerBase::array_ = 0;
    }
  }

  template<class T, class Base>
  typename Collection<T, Base>::reference
  Collection<T, Base>::at(UInt_t _idx)
  {
    if (_idx >= CollectionBase::size_)
      throw std::out_of_range((ContainerBase::name_ + "::at").Data());

    // Here we may be calling from a base class (when T0 <- T1, (Collection<T0>*)(&t1_array)->at(i) should properly point to the second *T1*, not T0),
    // which means we must shift by _idx * unitSize_ instead of _idx * sizeof(value_type).
    Char_t* p(ContainerBase::array_);
    p += _idx * ContainerBase::unitSize_;

    return *reinterpret_cast<pointer>(p);
  }

  template<class T, class Base>
  typename Collection<T, Base>::const_reference
  Collection<T, Base>::at(UInt_t _idx) const
  {
    if (_idx >= CollectionBase::size_)
      throw std::out_of_range((ContainerBase::name_ + "::at").Data());
  
    // Here we may be calling from a base class (when T0 <- T1, (Collection<T0>*)(&t1_array)->at(i) should properly point to the second *T1*, not T0),
    // which means we must shift by _idx * unitSize_ instead of _idx * sizeof(value_type).
    Char_t* p(ContainerBase::array_);
    p += _idx * ContainerBase::unitSize_;

    return *reinterpret_cast<const_pointer>(p);
  }

  template<class T, class Base>
  typename Collection<T, Base>::reference
  Collection<T, Base>::operator[](UInt_t _idx)
  {
    // Here we may be calling from a base class (when T0 <- T1, (Array<T0>*)(&t1_array)->at(i) should properly point to the second *T1*, not T0),
    // which means we must shift by _idx * unitSize_ instead of _idx * sizeof(value_type).
    Char_t* p(ContainerBase::array_);
    p += _idx * ContainerBase::unitSize_;

    return *reinterpret_cast<pointer>(p);
  }

  template<class T, class Base>
  typename Collection<T, Base>::const_reference
  Collection<T, Base>::operator[](UInt_t _idx) const
  {
    // Here we may be calling from a base class (when T0 <- T1, (Array<T0>*)(&t1_array)->at(i) should properly point to the second *T1*, not T0),
    // which means we must shift by _idx * unitSize_ instead of _idx * sizeof(value_type).
    Char_t* p(ContainerBase::array_);
    p += _idx * ContainerBase::unitSize_;

    return *reinterpret_cast<const_pointer>(p);
  }

  template<class T, class Base>
  void
  Collection<T, Base>::copy(self_type const& _src)
  {
    if (_src.ContainerBase::unitSize_ != ContainerBase::unitSize_)
      throw std::runtime_error((ContainerBase::name_ + "::copy incompatible array").Data());

    resize(_src.size_);
    
    for (unsigned iP(0); iP != CollectionBase::size_; ++iP)
      (*this)[iP] = _src[iP];

    setName(_src.name_);
  }

  template<class T, class Base>
  void
  Collection<T, Base>::push_back(const_reference _elem)
  {
    if (CollectionBase::size_ == getData().nmax()) {
      // reallocate elements with nmax *= 2
      // all references and pointers to data members and array elements will become invalid
      reallocate_(getData().nmax() * 2);
    }

    (*this)[CollectionBase::size_] = _elem;
    ++CollectionBase::size_;
  }

  template<class T, class Base>
  void
  Collection<T, Base>::resize(UInt_t _size)
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
  template<class T, class Base>
  void
  Collection<T, Base>::allocate_(UInt_t _nmax)
  {
    data.allocate(_nmax);

    ContainerBase::array_ = reinterpret_cast<Char_t*>(std::allocator<value_type>().allocate(data.nmax()));

    pointer p(addr_());
    for (unsigned iP(0); iP != data.nmax(); ++iP, ++p)
      new (p) value_type(data, iP);
  }

  /*private*/
  template<class T, class Base>
  void
  Collection<T, Base>::deallocate_()
  {
    std::allocator<value_type>().deallocate(reinterpret_cast<pointer>(ContainerBase::array_), data.nmax());
    data.deallocate();
  }

  /*private*/
  template<class T, class Base>
  void
  Collection<T, Base>::reallocate_(UInt_t _nmax)
  {
    // keep the copy of the pointers temporarily
    // tmpStore is not directly used but is linked from tmpArray
    auto tmpStore(data);
    pointer tmpArray(reinterpret_cast<pointer>(ContainerBase::array_));

    // allocate new space
    allocate_(_nmax);

    // copy old values
    for (unsigned iP(0); iP != CollectionBase::size_; ++iP)
      (*this)[iP] = tmpArray[iP];

    // deallocate old space
    std::allocator<value_type>().deallocate(tmpArray, tmpStore.nmax());
    tmpStore.deallocate();

    // update input and output pointers
    ContainerBase::updateAddress_();
  }

}

#endif
