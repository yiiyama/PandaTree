#include "../interface/MET.h"

panda::MET::MET(char const* _name/* = ""*/) :
  Singlet(_name)
{
}

panda::MET::MET(MET const& _src) :
  Singlet(_src.name_),
  pt(_src.pt),
  phi(_src.phi)
{
  pt = _src.pt;
  phi = _src.phi;
}

panda::MET::~MET()
{
}

panda::MET&
panda::MET::operator=(MET const& _src)
{
  Singlet::operator=(_src);

  pt = _src.pt;
  phi = _src.phi;

  return *this;
}

void
panda::MET::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  Singlet::setStatus(_tree, _status, _branches);

  utils::setStatus(_tree, name_, "pt", _status, _branches);
  utils::setStatus(_tree, name_, "phi", _status, _branches);
}

void
panda::MET::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Singlet::setAddress(_tree, _branches, _setStatus);

  utils::setAddress(_tree, name_, "pt", &pt, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phi", &phi, _branches, _setStatus);
}

void
panda::MET::book(TTree& _tree, utils::BranchList const& _branches/* = {}*/)
{
  Singlet::book(_tree, _branches);

  utils::book(_tree, name_, "pt", "", 'F', &pt, _branches);
  utils::book(_tree, name_, "phi", "", 'F', &phi, _branches);
}

void
panda::MET::resetAddress(TTree& _tree)
{
  Singlet::resetAddress(_tree);

  utils::resetAddress(_tree, name_, "pt");
  utils::resetAddress(_tree, name_, "phi");
}

void
panda::MET::init()
{
  Singlet::init();

  pt = 0.;
  phi = 0.;
}


/* BEGIN CUSTOM MET.cc.global */
/* END CUSTOM */
