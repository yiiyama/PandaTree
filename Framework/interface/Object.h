#ifndef PandaTree_Interface_Object_h
#define PandaTree_Interface_Object_h

#include "TTree.h"
#include "TString.h"

#include <vector>
#include <map>

#include "IOUtils.h"

namespace panda {
  class Object {
  public:
    Object() {}
    Object(Object const&) {}
    virtual ~Object() {}
    Object& operator=(Object const&) { return *this; }

    virtual void init() {}
  };

  namespace utils {
    class AllocatorBase;
  }

  class ContainerElement : public Object {
  public:
    struct array_data {
      array_data() {}
      virtual ~array_data() {}

      virtual void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) {}
      virtual void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}) {}
      virtual void book(TTree&, TString const&, utils::BranchList const& = {"*"}) {}
    };

    ContainerElement() : Object() {}
    ContainerElement(ContainerElement const& src) : Object(src) {}
    ContainerElement(array_data&, UInt_t) {}
    virtual ~ContainerElement() {}
    ContainerElement& operator=(ContainerElement const&) { return *this; }

    virtual void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"}) {}
    virtual void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}) {}
    virtual void book(TTree&, TString const&, utils::BranchList const& = {"*"}) {}

  protected:
    // Ctor for singlet instantiation
    ContainerElement(utils::AllocatorBase const&);
  };

  class Singlet : public Object {
  public:
    Singlet() : Object() {}
    Singlet(TString const& n) : name_(n) {}
    Singlet(Singlet const& src) : Object(src), name_(src.name_) {}
    ~Singlet() {}
    Singlet& operator=(Singlet const& _src) { name_ = _src.name_; return *this; }

    void setName(TString const& n) { name_ = n; }
    virtual void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) {}
    virtual void setAddress(TTree&, utils::BranchList const& = {"*"}) {}
    virtual void book(TTree&, utils::BranchList const& = {"*"}) {}

  protected:
    TString name_{"object"};
  };

  namespace utils {
    class AllocatorBase {
    public:
      virtual ContainerElement::array_data* allocate() const = 0;
      virtual UInt_t nmax() const = 0;
      virtual size_t typeIndex() const = 0;
    };

    template<class O>
    class Allocator : public AllocatorBase {
    public:
      typedef typename O::array_data data_type;
      ContainerElement::array_data* allocate() const override { return new data_type; }
      UInt_t nmax() const override { return data_type::NMAX; }
      size_t typeIndex() const override { return typeid(O).hash_code(); }
    };

    class StoreManager {
    public:
      StoreManager() {}

      void assign(ContainerElement const*, AllocatorBase const&);
      void free(ContainerElement const*);

      template<class O> typename O::array_data& getData(O const*);
      template<class O> UInt_t getIndex(O const*);

    private:
      typedef std::vector<ContainerElement::array_data*> DataArray; // think of it as one long array
      typedef std::pair<DataArray*, UInt_t> Slot;      
      typedef std::pair<std::vector<ContainerElement const*>, DataArray> Assignments;

      // type index -> Assignments
      std::map<size_t, Assignments> dataStore_;
      // quick map to individual slot assignments
      std::map<ContainerElement const*, Slot> slots_;
    };

    template<class O>
    typename O::array_data&
    StoreManager::getData(O const* _element)
    {
      typedef typename O::array_data data_type;

      Slot& slot(slots_.at(_element));
      return *static_cast<data_type*>(slot.first->at(slot.second / data_type::NMAX));
    }

    template<class O>
    UInt_t
    StoreManager::getIndex(O const* _element)
    {
      typedef typename O::array_data data_type;

      Slot& slot(slots_.at(_element));
      return slot.second % data_type::NMAX;
    }
  }

  extern utils::StoreManager gStore;
}

#endif
