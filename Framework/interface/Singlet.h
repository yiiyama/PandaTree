#ifndef PandaTree_Framework_Singlet_h
#define PandaTree_Framework_Singlet_h

//! Base class for singlet objects.
/*!
  Singlet objects are owners of its data, in contrast to ContainerElement.
*/

#include "Object.h"

#include "TString.h"

namespace panda {

  class Singlet : public Object {
  public:
    Singlet(char const* name = "") : Object(), name_(name) {}
    Singlet(Singlet const& src) : Object(src), name_(src.name_) {}
    ~Singlet() {}
    Singlet& operator=(Singlet const& _src) { name_ = _src.name_; return *this; }

    char const* getName() const override { return name_; }
    void setName(char const* n) override { name_ = n; }

  protected:
    TString name_{};
  };

}

#endif
