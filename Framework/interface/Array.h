#ifndef PandaTree_Framework_Array_h
#define PandaTree_Framework_Array_h

#include "ArrayBase.h"
#include "Iterator.h"

#include <stdexcept>
#include <memory>

namespace panda {

  template<class T, class Base>
  class Array : public Base {
  public:
    typedef Array<T, Base> self_type;
    typedef T value_type;
    typedef value_type* pointer;
    typedef value_type const* const_pointer;
    typedef value_type& reference;
    typedef value_type const& const_reference;
    typedef utils::Iterator<self_type, false> iterator;
    typedef utils::Iterator<self_type, true> const_iterator;

    Array(UInt_t size, char const* name = "");
    Array(self_type const&);
    ~Array();
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
      If the size changes, data will be reallocated, making all references invalid.
      Pointers in input/output tree branches are automatically updated.
    */
    void copy(self_type const&);

    void init() override;
    ContainerElement::datastore& getData() override { return data; }
    ContainerElement::datastore const& getData() const override { return data; }
    ContainerElement& elemAt(UInt_t idx) override { return at(idx); }
    ContainerElement const& elemAt(UInt_t idx) const override { return at(idx); }

    typename value_type::datastore data{};

  protected:
    Array(char const*, UInt_t);

  private:
    void allocate_(UInt_t) override;
    void deallocate_() override;

    pointer addr_() const { return reinterpret_cast<pointer>(ContainerBase::array_); }
    const_pointer const_addr_() const { return reinterpret_cast<const_pointer>(ContainerBase::array_); }
  };

  template<class T, class Base>
  Array<T, Base>::Array(UInt_t _size, char const* _name/* = ""*/) :
    Base(_name, sizeof(value_type))
  {
    allocate_(_size);
  }

  template<class T, class Base>
  Array<T, Base>::Array(self_type const& _src) :
    Array<T, Base>::Array(_src.getData().nmax(), _src.ContainerBase::name_)
  {
    copy(_src);
  }

  /*protected*/
  template<class T, class Base>
  Array<T, Base>::Array(char const* _name, UInt_t _unitSize) :
    Base(_name, _unitSize)
  {
  }

  template<class T, class Base>
  Array<T, Base>::~Array()
  {
    if (ContainerBase::array_) {
      deallocate_();
      ContainerBase::array_ = 0;
    }
  }

  template<class T, class Base>
  typename Array<T, Base>::reference
  Array<T, Base>::at(UInt_t _idx)
  {
    if (_idx >= getData().nmax())
      throw std::out_of_range((ContainerBase::name_ + "::at").Data());

    // Here we may be calling from a base class (when T0 <- T1, (Array<T0>*)(&t1_array)->at(i) should properly point to the second *T1*, not T0),
    // which means we must shift by _idx * unitSize_ instead of _idx * sizeof(value_type).
    Char_t* p(ContainerBase::array_);
    p += _idx * ContainerBase::unitSize_;

    return *reinterpret_cast<pointer>(p);
  }

  template<class T, class Base>
  typename Array<T, Base>::const_reference
  Array<T, Base>::at(UInt_t _idx) const
  {
    if (_idx >= getData().nmax())
      throw std::out_of_range((ContainerBase::name_ + "::at").Data());
  
    // Here we may be calling from a base class (when T0 <- T1, (Array<T0>*)(&t1_array)->at(i) should properly point to the second *T1*, not T0),
    // which means we must shift by _idx * unitSize_ instead of _idx * sizeof(value_type).
    Char_t* p(ContainerBase::array_);
    p += _idx * ContainerBase::unitSize_;

    return *reinterpret_cast<const_pointer>(p);
  }

  template<class T, class Base>
  typename Array<T, Base>::reference
  Array<T, Base>::operator[](UInt_t _idx)
  {
    // Here we may be calling from a base class (when T0 <- T1, (Array<T0>*)(&t1_array)->at(i) should properly point to the second *T1*, not T0),
    // which means we must shift by _idx * unitSize_ instead of _idx * sizeof(value_type).
    Char_t* p(ContainerBase::array_);
    p += _idx * ContainerBase::unitSize_;

    return *reinterpret_cast<pointer>(p);
  }

  template<class T, class Base>
  typename Array<T, Base>::const_reference
  Array<T, Base>::operator[](UInt_t _idx) const
  {
    // Here we may be calling from a base class (when T0 <- T1, (Array<T0>*)(&t1_array)->at(i) should properly point to the second *T1*, not T0),
    // which means we must shift by _idx * unitSize_ instead of _idx * sizeof(value_type).
    Char_t* p(ContainerBase::array_);
    p += _idx * ContainerBase::unitSize_;

    return *reinterpret_cast<const_pointer>(p);
  }

  template<class T, class Base>
  void
  Array<T, Base>::copy(self_type const& _src)
  {
    if (_src.ContainerBase::unitSize_ != ContainerBase::unitSize_)
      throw std::runtime_error((ContainerBase::name_ + "::copy incompatible array").Data());

    if (_src.getData().nmax() != getData().nmax()) {
      deallocate_();
      allocate_(_src.getData().nmax());
      ContainerBase::updateAddress_();
    }
    
    for (unsigned iP(0); iP != getData().nmax(); ++iP)
      (*this)[iP] = _src[iP];

    setName(_src.name_);
  }

  template<class T, class Base>
  void
  Array<T, Base>::init()
  {
    for (unsigned iP(0); iP != getData().nmax(); ++iP)
      (*this)[iP].init();
  }

  /*private*/
  template<class T, class Base>
  void
  Array<T, Base>::allocate_(UInt_t _size)
  {
    data.allocate(_size);

    ContainerBase::array_ = reinterpret_cast<Char_t*>(std::allocator<value_type>().allocate(data.nmax()));

    // Here we are sure that T is the true object type in the array - can iterate using T*
    pointer p(addr_());
    for (unsigned iP(0); iP != data.nmax(); ++iP, ++p)
      new (p) value_type(data, iP);
  }

  /*private*/
  template<class T, class Base>
  void
  Array<T, Base>::deallocate_()
  {
    std::allocator<value_type>().deallocate(reinterpret_cast<pointer>(ContainerBase::array_), data.nmax());
    data.deallocate();
  }

}

#endif
