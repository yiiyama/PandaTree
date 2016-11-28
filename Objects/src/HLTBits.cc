#include "../interface/HLTBits.h"

panda::HLTBits::HLTBits(char const* _name/* = ""*/) :
  Singlet(_name)
{
}

panda::HLTBits::HLTBits(HLTBits const& _src) :
  Singlet(_src.name_)
{
}

panda::HLTBits::~HLTBits()
{
}

panda::HLTBits&
panda::HLTBits::operator=(HLTBits const& _src)
{
  Singlet::operator=(_src);


  return *this;
}

void
panda::HLTBits::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  Singlet::setStatus(_tree, _status, _branches);

  utils::setStatus(_tree, name_, "words", _status, _branches);
}

void
panda::HLTBits::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Singlet::setAddress(_tree, _branches, _setStatus);

  utils::setAddress(_tree, name_, "words", words, _branches, _setStatus);
}

void
panda::HLTBits::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  Singlet::book(_tree, _branches);

  utils::book(_tree, name_, "words", "[16]", 'i', words, _branches);
}

void
panda::HLTBits::init()
{
  Singlet::init();

  for (auto& p0 : words) p0 = 0;
}


/* BEGIN CUSTOM */
/* END CUSTOM */
