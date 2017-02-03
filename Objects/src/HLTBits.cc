#include "../interface/HLTBits.h"

panda::HLTBits::HLTBits(char const* _name/* = ""*/) :
  Singlet(_name)
{
}

panda::HLTBits::HLTBits(HLTBits const& _src) :
  Singlet(_src.name_),
  size_(_src.size_)
{
  std::memcpy(words, _src.words, sizeof(UInt_t) * 16);
  size_ = _src.size_;
}

panda::HLTBits::~HLTBits()
{
}

panda::HLTBits&
panda::HLTBits::operator=(HLTBits const& _src)
{
  Singlet::operator=(_src);

  std::memcpy(words, _src.words, sizeof(UInt_t) * 16);
  size_ = _src.size_;

  return *this;
}

void
panda::HLTBits::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  Singlet::doSetStatus_(_tree, _branches);

  utils::setStatus(_tree, name_, "words", _branches);
  utils::setStatus(_tree, name_, "size_", _branches);
}

void
panda::HLTBits::doSetAddress_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Singlet::doSetAddress_(_tree, _branches, _setStatus);

  utils::setAddress(_tree, name_, "words", words, _branches, _setStatus);
  utils::setAddress(_tree, name_, "size_", &size_, _branches, _setStatus);
}

void
panda::HLTBits::doBook_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  Singlet::doBook_(_tree, _branches);

  utils::book(_tree, name_, "words", TString::Format("[16]"), 'i', words, _branches);
  utils::book(_tree, name_, "size_", "", 'i', &size_, _branches);
}

void
panda::HLTBits::doReleaseTree_(TTree& _tree)
{
  Singlet::doReleaseTree_(_tree);

  utils::resetAddress(_tree, name_, "words");
  utils::resetAddress(_tree, name_, "size_");
}

void
panda::HLTBits::doInit_()
{
  Singlet::doInit_();

  for (auto& p0 : words) p0 = 0;
  size_ = 512;
}


/* BEGIN CUSTOM HLTBits.cc.global */
/* END CUSTOM */
