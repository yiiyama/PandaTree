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
  categories = _src.categories;
  max = _src.max;

  return *this;
}

void
panda::Recoil::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::setStatus(_tree, name_, "categories", _branches);
  utils::setStatus(_tree, name_, "max", _branches);
}

panda::utils::BranchList
panda::Recoil::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;

  blist.push_back(utils::getStatus(_tree, name_, "categories"));
  blist.push_back(utils::getStatus(_tree, name_, "max"));

  return blist;
}

void
panda::Recoil::doSetAddress_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  utils::setAddress(_tree, name_, "categories", &categories, _branches, _setStatus);
  utils::setAddress(_tree, name_, "max", &max, _branches, _setStatus);
}

void
panda::Recoil::doBook_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  utils::book(_tree, name_, "categories", "", 'i', &categories, _branches);
  utils::book(_tree, name_, "max", "", 'F', &max, _branches);
}

void
panda::Recoil::doReleaseTree_(TTree& _tree)
{
  utils::resetAddress(_tree, name_, "categories");
  utils::resetAddress(_tree, name_, "max");
}

void
panda::Recoil::doInit_()
{
  categories = 0;
  max = 0.;

  /* BEGIN CUSTOM Recoil.cc.doInit_ */
  /* END CUSTOM */
}

/* BEGIN CUSTOM Recoil.cc.global */
/* END CUSTOM */
