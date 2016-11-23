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

    virtual void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) {}
    virtual void setAddress(TTree&, utils::BranchList const& = {"*"}) {}
    virtual void book(TTree&, utils::BranchList const& = {"*"}) {}

    virtual void setName(char const*) {}
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
    ContainerElement(array_data&, UInt_t) {}
    ContainerElement(ContainerElement const& src) : Object(src) {}
    ~ContainerElement() {}
    ContainerElement& operator=(ContainerElement const&) { return *this; }

    void setName(char const*) override;

  protected:
    // Ctor for singlet instantiation
    ContainerElement(utils::AllocatorBase const&, char const* name);
  };

  class Singlet : public Object {
  public:
    Singlet(char const* name = "") : Object(), name_(name) {}
    Singlet(Singlet const& src) : Object(src), name_(src.name_) {}
    ~Singlet() {}
    Singlet& operator=(Singlet const& _src) { name_ = _src.name_; return *this; }

    void setName(char const* n) override { name_ = n; }

  protected:
    TString name_{};
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

      void assign(ContainerElement const*, AllocatorBase const&, char const* name = "");
      void free(ContainerElement const*);

      template<class O> typename O::array_data& getData(O const*);
      template<class O> UInt_t getIndex(O const*);
      char const* getName(ContainerElement const*);
      void setName(ContainerElement const* elem, char const* name) { names_[elem] = name; }

    private:
      typedef std::vector<ContainerElement::array_data*> DataArray; // think of it as one long array
      typedef std::pair<DataArray*, UInt_t> Slot; // array and index
      typedef std::pair<std::vector<ContainerElement const*>, DataArray> Assignments;

      // type index -> Assignments
      std::map<size_t, Assignments> dataStore_;
      // quick map to individual slot assignments
      std::map<ContainerElement const*, Slot> slots_;
      // names of named instances
      std::map<ContainerElement const*, TString> names_;
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
