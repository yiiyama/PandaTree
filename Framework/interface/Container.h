#ifndef PandaTree_Interface_Container_h
#define PandaTree_Interface_Container_h

#include "IOUtils.h"

#include "TString.h"
#include "TTree.h"

#include <stdexcept>
#include <algorithm>

namespace panda {

  template<Bool_t F>
  class BaseContainer {
  public:
    typedef BaseContainer<F> self_type;
    typedef self_type base_type;

    static const Bool_t FIXED{F};

    BaseContainer(TString const& name = "") : name_(name) {}
    BaseContainer(self_type const& src) : name_(src.name_) {}
    virtual ~BaseContainer() {}
    self_type& operator=(self_type const& rhs) { name_ = rhs.name_; return *this; }

    void setName(TString const& name) { name_ = name; }

    UInt_t size() const { return size_; }

  protected:
    BaseContainer(TString const& name, Bool_t) : name_(name) {}

    TString name_;
    UInt_t size_{0};
    Char_t* array_{0};
  };

  typedef BaseContainer<kTRUE> Array;
  typedef BaseContainer<kFALSE> Collection;

  template<class T, class B>
  class Container : public B {
  public:
    typedef typename B::base_type base_type;
    typedef Container<T, B> self_type;
    typedef Container<T, B> container_type;
    typedef T value_type;
    typedef value_type* pointer;
    typedef value_type const* const_pointer;
    typedef value_type& reference;
    typedef value_type const& const_reference;

    class const_iterator;

    class iterator {
      friend class Container<T, B>;
      friend class const_iterator;

    public:
      iterator() {}
      iterator& operator++() { shiftPtr(1); return *this; }
      iterator operator++(int) { auto itr(*this); shiftPtr(1); return itr; }
      iterator& operator--() { shiftPtr(-1); return *this; }
      iterator operator--(int) { auto itr(*this); shiftPtr(-1); return itr; }
      iterator& operator+=(int n) { shiftPtr(n); return *this; }
      iterator& operator-=(int n) { shiftPtr(-n); return *this; }
      iterator operator+(int n) { auto itr(*this); itr += n; return itr; }
      iterator operator-(int n) { auto itr(*this); itr -= n; return itr; }
      bool operator==(iterator const& rhs) { return ptr == rhs.ptr; }
      bool operator!=(iterator const& rhs) { return ptr != rhs.ptr; }
      reference operator*() { return *ptr; }
      pointer operator->() { return ptr; }

    private:
      iterator(void* p) : ptr(static_cast<pointer>(p)) {}

      void shiftPtr(Int_t shift) { reinterpret_cast<char*&>(ptr) += sizeof(value_type) * shift; }

      pointer ptr{0};
    };

    class const_iterator {
      friend class Container<T, B>;

    public:
      const_iterator() {}
      const_iterator(iterator const& it) : ptr(it.ptr) {}
      self_type& operator++() { shiftPtr(1); return *this; }
      self_type operator++(int) { auto itr(*this); shiftPtr(1); return itr; }
      self_type& operator--() { shiftPtr(-1); return *this; }
      self_type operator--(int) { auto itr(*this); shiftPtr(-1); return itr; }
      self_type& operator+=(int n) { shiftPtr(n); return *this; }
      self_type& operator-=(int n) { shiftPtr(-n); return *this; }
      self_type operator+(int n) { auto itr(*this); itr += n; return itr; }
      self_type operator-(int n) { auto itr(*this); itr -= n; return itr; }
      bool operator==(const_iterator const& rhs) { return ptr == rhs.ptr; }
      bool operator==(iterator const& rhs) { return ptr == rhs.ptr; }
      bool operator!=(const_iterator const& rhs) { return ptr != rhs.ptr; }
      bool operator!=(iterator const& rhs) { return ptr != rhs.ptr; }
      const_reference operator*() { return *ptr; }
      const_pointer operator->() { return ptr; }

    private:
      const_iterator(void* p) : ptr(static_cast<pointer>(p)) {}

      void shiftPtr(Int_t shift) { reinterpret_cast<char const*&>(ptr) += sizeof(value_type) * shift; }

      pointer ptr{0};
    };

    static const Bool_t FIXED{base_type::FIXED};

    Container(TString const& name = "");
    Container(self_type const&);
    ~Container();
    self_type& operator=(self_type const&);

    reference at(UInt_t idx);
    const_reference at(UInt_t idx) const;
    reference operator[](UInt_t);
    const_reference operator[](UInt_t) const;
    iterator begin() { return iterator(this->base_type::array_); }
    const_iterator begin() const { return const_iterator(this->base_type::array_); }
    iterator end() { return iterator(this->base_type::array_ + sizeof(value_type) * this->base_type::size_); }
    const_iterator end() const { return const_iterator(this->base_type::array_ + sizeof(value_type) * this->base_type::size_); }
    reference front() { return operator[](0); }
    const_reference front() const { return operator[](0); }
    reference back() { return operator[](this->base_type::size_ - 1); }
    const_reference back() const { return operator[](this->base_type::size_ - 1); }
    void push_back(const_reference);
    reference create_back() { resize(this->base_type::size_ + 1); return back(); }
    void copy(self_type const& source) { clear(); for (auto& s : source) push_back(s); }
    void resize(UInt_t size);
    void init();
    void clear();

    virtual void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"});
    virtual void setAddress(TTree&, utils::BranchList const& = {"*"});
    virtual void book(TTree&, utils::BranchList const& = {"*"});

    typename value_type::array_data data{};

  protected:
    Container(TString const&, Bool_t);
  };

  template<class T, class B>
  Container<T, B>::Container(TString const& _name) :
    B(_name, kFALSE)
  {
    this->base_type::array_ = reinterpret_cast<Char_t*>(std::allocator<value_type>().allocate(data.NMAX));
    Char_t* p(this->base_type::array_);
    for (unsigned iP(0); iP != data.NMAX; ++iP) {
      new (reinterpret_cast<pointer>(p)) value_type(data, iP);
      p += sizeof(value_type);
    }

    if (FIXED)
      this->base_type::size_ = data.NMAX;
  }

  template<class T, class B>
  Container<T, B>::Container(self_type const& _src) :
    B(_src.base_type::name_, kFALSE)
  {
    this->base_type::array_ = reinterpret_cast<Char_t*>(std::allocator<value_type>().allocate(data.NMAX));
    Char_t* p(this->base_type::array_);
    for (unsigned iP(0); iP != data.NMAX; ++iP) {
      new (reinterpret_cast<pointer>(p)) value_type(data, iP);
      reinterpret_cast<pointer>(p)->operator=(_src[iP]);
      p += sizeof(value_type);
    }

    if (FIXED)
      this->base_type::size_ = data.NMAX;
  }

  /*protected*/
  template<class T, class B>
  Container<T, B>::Container(TString const& _name, Bool_t) :
    B(_name, kFALSE)
  {
  }

  template<class T, class B>
  Container<T, B>::~Container()
  {
    if (this->base_type::array_) {
      std::allocator<value_type>().deallocate(reinterpret_cast<pointer>(this->base_type::array_), data.NMAX);
      this->base_type::array_ = 0;
    }
  }

  template<class T, class B>
  Container<T, B>&
  Container<T, B>::operator=(self_type const& _rhs)
  {
    this->base_type::operator=(_rhs);

    Char_t* p(this->base_type::array_);
    for (unsigned iP(0); iP != data.NMAX; ++iP) {
      reinterpret_cast<pointer>(p)->operator=(_rhs[iP]);
      p += sizeof(value_type);
    }

    return *this;
  }

  template<class T, class B>
  typename Container<T, B>::reference
  Container<T, B>::at(UInt_t _idx)
  {
    if (_idx >= this->base_type::size_)
      throw std::out_of_range((this->base_type::name_ + "::at").Data());

    Char_t* p(this->base_type::array_);
    p += _idx * sizeof(value_type);

    return *reinterpret_cast<pointer>(p);
  }

  template<class T, class B>
  typename Container<T, B>::const_reference
  Container<T, B>::at(UInt_t _idx) const
  {
    if (_idx >= this->base_type::size_)
      throw std::out_of_range((this->base_type::name_ + "::at").Data());
  
    Char_t* p(this->base_type::array_);
    p += _idx * sizeof(value_type);

    return *reinterpret_cast<const_pointer>(p);
  }

  template<class T, class B>
  typename Container<T, B>::reference
  Container<T, B>::operator[](UInt_t _idx)
  {
    Char_t* p(this->base_type::array_);
    p += _idx * sizeof(value_type);

    return *reinterpret_cast<pointer>(p);
  }

  template<class T, class B>
  typename Container<T, B>::const_reference
  Container<T, B>::operator[](UInt_t _idx) const
  {
    Char_t* p(this->base_type::array_);
    p += _idx * sizeof(value_type);

    return *reinterpret_cast<const_pointer>(p);
  }

  template<class T, class B>
  void
  Container<T, B>::push_back(const_reference _elem)
  {
    if (FIXED)
      throw std::domain_error((this->base_type::name_ + "::push_back").Data());

    if (this->base_type::size_ == data.NMAX)
      throw std::length_error((this->base_type::name_ + "::push_back").Data());

    (*this)[this->base_type::size_] = _elem;
    ++this->base_type::size_;
  }

  template<class T, class B>
  void
  Container<T, B>::resize(UInt_t _size)
  {
    if (FIXED)
      throw std::domain_error((this->base_type::name_ + "::resize").Data());

    if (_size > data.NMAX)
      throw std::length_error((this->base_type::name_ + "::resize").Data());
  
    this->base_type::size_ = _size;
  }

  template<class T, class B>
  void
  Container<T, B>::init()
  {
    if (FIXED) {
      for (iterator itr(begin()); itr != end(); ++itr)
        itr->init();
    }
    else
      clear();
  }

  template<class T, class B>
  void
  Container<T, B>::clear()
  {
    if (FIXED)
      throw std::domain_error((this->base_type::name_ + "::clear").Data());

    this->base_type::size_ = 0;
  }

  template<class T, class B>
  void
  Container<T, B>::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
  {
    if (!_tree.GetBranch(this->base_type::name_ + ".size"))
      return;

    if (!FIXED) {
      if (_status || utils::BranchName("size").in(_branches))
        _tree.SetBranchStatus(this->base_type::name_ + ".size", _status);
    }

    data.setStatus(_tree, this->base_type::name_, _status, _branches);
  }

  template<class T, class B>
  void
  Container<T, B>::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
  {
    if (!FIXED)
      utils::setStatusAndAddress(_tree, this->base_type::name_, "size", &this->base_type::size_, {"size"});
  
    data.setAddress(_tree, this->base_type::name_, _branches);
  }

  template<class T, class B>
  void
  Container<T, B>::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
  {
    if (!utils::BranchName(this->base_type::name_).in(_branches))
      return;

    if (!FIXED)
      _tree.Branch(this->base_type::name_ + ".size", &this->base_type::size_, "size/i");

    data.book(_tree, this->base_type::name_, _branches);
  }

}

#endif
