#include "../interface/Recoil.h"

panda::Recoil::Recoil(char const* _name/* = ""*/) :
  Singlet(_name)
{
}

panda::Recoil::Recoil(Recoil const& _src) :
  Singlet(_src.name_),
  categories(_src.categories),
  max(_src.max)
{
  categories = _src.categories;
  max = _src.max;
}

panda::Recoil::~Recoil()
{
}

panda::Recoil&
panda::Recoil::operator=(Recoil const& _src)
{
  Singlet::operator=(_src);

  categories = _src.categories;
  max = _src.max;

  return *this;
}

void
panda::Recoil::setStatus(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  Singlet::setStatus(_tree, _branches);

  utils::setStatus(_tree, name_, "categories", _branches);
  utils::setStatus(_tree, name_, "max", _branches);
}

UInt_t
panda::Recoil::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Singlet::setAddress(_tree, _branches, _setStatus);

  utils::setAddress(_tree, name_, "categories", &categories, _branches, _setStatus);
  utils::setAddress(_tree, name_, "max", &max, _branches, _setStatus);

  return -1;
}

UInt_t
panda::Recoil::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  Singlet::book(_tree, _branches);

  utils::book(_tree, name_, "categories", "", 'i', &categories, _branches);
  utils::book(_tree, name_, "max", "", 'F', &max, _branches);

  return -1;
}

void
panda::Recoil::releaseTree(TTree& _tree)
{
  Singlet::releaseTree(_tree);

  utils::resetAddress(_tree, name_, "categories");
  utils::resetAddress(_tree, name_, "max");
}

void
panda::Recoil::init()
{
  Singlet::init();

  categories = 0;
  max = 0.;
}

/* BEGIN CUSTOM Recoil.cc.global */
/* END CUSTOM */
