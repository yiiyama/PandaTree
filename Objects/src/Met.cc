#include "../interface/Met.h"

panda::Met::Met(char const* _name/* = ""*/) :
  Singlet(_name)
{
}

panda::Met::Met(Met const& _src) :
  Singlet(_src.name_),
  pt(_src.pt),
  phi(_src.phi)
{
  pt = _src.pt;
  phi = _src.phi;
}

panda::Met::~Met()
{
}

panda::Met&
panda::Met::operator=(Met const& _src)
{
  Singlet::operator=(_src);

  pt = _src.pt;
  phi = _src.phi;

  return *this;
}

void
panda::Met::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  Singlet::doSetStatus_(_tree, _branches);

  utils::setStatus(_tree, name_, "pt", _branches);
  utils::setStatus(_tree, name_, "phi", _branches);
}

void
panda::Met::doSetAddress_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Singlet::doSetAddress_(_tree, _branches, _setStatus);

  utils::setAddress(_tree, name_, "pt", &pt, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phi", &phi, _branches, _setStatus);
}

void
panda::Met::doBook_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  Singlet::doBook_(_tree, _branches);

  utils::book(_tree, name_, "pt", "", 'F', &pt, _branches);
  utils::book(_tree, name_, "phi", "", 'F', &phi, _branches);
}

void
panda::Met::doReleaseTree_(TTree& _tree)
{
  Singlet::doReleaseTree_(_tree);

  utils::resetAddress(_tree, name_, "pt");
  utils::resetAddress(_tree, name_, "phi");
}

void
panda::Met::doInit_()
{
  Singlet::doInit_();

  pt = 0.;
  phi = 0.;
}


/* BEGIN CUSTOM Met.cc.global */
/* END CUSTOM */
