#include "../interface/HLTBits.h"

/*static*/
panda::utils::BranchList
panda::HLTBits::getListOfBranches()
{
  utils::BranchList blist;
  blist += {"words"};
  return blist;
}

panda::HLTBits::HLTBits(char const* _name/* = ""*/) :
  Singlet(_name)
{
}

panda::HLTBits::HLTBits(HLTBits const& _src) :
  Singlet(_src.name_)
{
  std::memcpy(words, _src.words, sizeof(ULong64_t) * 16);
}

panda::HLTBits::~HLTBits()
{
}

panda::HLTBits&
panda::HLTBits::operator=(HLTBits const& _src)
{
  std::memcpy(words, _src.words, sizeof(ULong64_t) * 16);

  return *this;
}

void
panda::HLTBits::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::setStatus(_tree, name_, "words", _branches);
}

panda::utils::BranchList
panda::HLTBits::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;

  blist.push_back(utils::getStatus(_tree, name_, "words"));

  return blist;
}

void
panda::HLTBits::doSetAddress_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  utils::setAddress(_tree, name_, "words", words, _branches, _setStatus);
}

void
panda::HLTBits::doBook_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  utils::book(_tree, name_, "words", TString::Format("[16]"), 'l', words, _branches);
}

void
panda::HLTBits::doReleaseTree_(TTree& _tree)
{
  utils::resetAddress(_tree, name_, "words");
}

void
panda::HLTBits::doInit_()
{
  for (auto& p0 : words) p0 = 0;

  /* BEGIN CUSTOM HLTBits.cc.doInit_ */
  /* END CUSTOM */
}

panda::utils::BranchList
panda::HLTBits::doGetBranchNames_() const
{
  return getListOfBranches().fullNames(name_);
}

void
panda::HLTBits::print(std::ostream& _out/* = std::cout*/) const
{
  /* BEGIN CUSTOM HLTBits.cc.print */
  /* END CUSTOM */
}


/* BEGIN CUSTOM HLTBits.cc.global */
/* END CUSTOM */
