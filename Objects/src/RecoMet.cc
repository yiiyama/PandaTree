#include "../interface/RecoMet.h"

panda::RecoMet::RecoMet(char const* _name/* = ""*/) :
  Met(_name)
{
}

panda::RecoMet::RecoMet(RecoMet const& _src) :
  Met(_src.name_),
  sumETRaw(_src.sumETRaw),
  ptCorrUp(_src.ptCorrUp),
  phiCorrUp(_src.phiCorrUp),
  ptCorrDown(_src.ptCorrDown),
  phiCorrDown(_src.phiCorrDown),
  ptUnclUp(_src.ptUnclUp),
  phiUnclUp(_src.phiUnclUp),
  ptUnclDown(_src.ptUnclDown),
  phiUnclDown(_src.phiUnclDown)
{
  sumETRaw = _src.sumETRaw;
  ptCorrUp = _src.ptCorrUp;
  phiCorrUp = _src.phiCorrUp;
  ptCorrDown = _src.ptCorrDown;
  phiCorrDown = _src.phiCorrDown;
  ptUnclUp = _src.ptUnclUp;
  phiUnclUp = _src.phiUnclUp;
  ptUnclDown = _src.ptUnclDown;
  phiUnclDown = _src.phiUnclDown;
}

panda::RecoMet::~RecoMet()
{
}

panda::RecoMet&
panda::RecoMet::operator=(RecoMet const& _src)
{
  Met::operator=(_src);

  sumETRaw = _src.sumETRaw;
  ptCorrUp = _src.ptCorrUp;
  phiCorrUp = _src.phiCorrUp;
  ptCorrDown = _src.ptCorrDown;
  phiCorrDown = _src.phiCorrDown;
  ptUnclUp = _src.ptUnclUp;
  phiUnclUp = _src.phiUnclUp;
  ptUnclDown = _src.ptUnclDown;
  phiUnclDown = _src.phiUnclDown;

  return *this;
}

void
panda::RecoMet::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  Met::setStatus(_tree, _status, _branches);

  utils::setStatus(_tree, name_, "sumETRaw", _status, _branches);
  utils::setStatus(_tree, name_, "ptCorrUp", _status, _branches);
  utils::setStatus(_tree, name_, "phiCorrUp", _status, _branches);
  utils::setStatus(_tree, name_, "ptCorrDown", _status, _branches);
  utils::setStatus(_tree, name_, "phiCorrDown", _status, _branches);
  utils::setStatus(_tree, name_, "ptUnclUp", _status, _branches);
  utils::setStatus(_tree, name_, "phiUnclUp", _status, _branches);
  utils::setStatus(_tree, name_, "ptUnclDown", _status, _branches);
  utils::setStatus(_tree, name_, "phiUnclDown", _status, _branches);
}

void
panda::RecoMet::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Met::setAddress(_tree, _branches, _setStatus);

  utils::setAddress(_tree, name_, "sumETRaw", &sumETRaw, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ptCorrUp", &ptCorrUp, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phiCorrUp", &phiCorrUp, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ptCorrDown", &ptCorrDown, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phiCorrDown", &phiCorrDown, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ptUnclUp", &ptUnclUp, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phiUnclUp", &phiUnclUp, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ptUnclDown", &ptUnclDown, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phiUnclDown", &phiUnclDown, _branches, _setStatus);
}

void
panda::RecoMet::book(TTree& _tree, utils::BranchList const& _branches/* = {}*/)
{
  Met::book(_tree, _branches);

  utils::book(_tree, name_, "sumETRaw", "", 'F', &sumETRaw, _branches);
  utils::book(_tree, name_, "ptCorrUp", "", 'F', &ptCorrUp, _branches);
  utils::book(_tree, name_, "phiCorrUp", "", 'F', &phiCorrUp, _branches);
  utils::book(_tree, name_, "ptCorrDown", "", 'F', &ptCorrDown, _branches);
  utils::book(_tree, name_, "phiCorrDown", "", 'F', &phiCorrDown, _branches);
  utils::book(_tree, name_, "ptUnclUp", "", 'F', &ptUnclUp, _branches);
  utils::book(_tree, name_, "phiUnclUp", "", 'F', &phiUnclUp, _branches);
  utils::book(_tree, name_, "ptUnclDown", "", 'F', &ptUnclDown, _branches);
  utils::book(_tree, name_, "phiUnclDown", "", 'F', &phiUnclDown, _branches);
}

void
panda::RecoMet::resetAddress(TTree& _tree)
{
  Met::resetAddress(_tree);

  utils::resetAddress(_tree, name_, "sumETRaw");
  utils::resetAddress(_tree, name_, "ptCorrUp");
  utils::resetAddress(_tree, name_, "phiCorrUp");
  utils::resetAddress(_tree, name_, "ptCorrDown");
  utils::resetAddress(_tree, name_, "phiCorrDown");
  utils::resetAddress(_tree, name_, "ptUnclUp");
  utils::resetAddress(_tree, name_, "phiUnclUp");
  utils::resetAddress(_tree, name_, "ptUnclDown");
  utils::resetAddress(_tree, name_, "phiUnclDown");
}

void
panda::RecoMet::init()
{
  Met::init();

  sumETRaw = 0.;
  ptCorrUp = 0.;
  phiCorrUp = 0.;
  ptCorrDown = 0.;
  phiCorrDown = 0.;
  ptUnclUp = 0.;
  phiUnclUp = 0.;
  ptUnclDown = 0.;
  phiUnclDown = 0.;
}

TVector2
panda::RecoMet::vCorr(int corr/* = 0*/) const
{
  if (corr == 0)
    return v();

  TVector2 vec;
  switch (corr) {
  case 1:
    vec.SetMagPhi(ptCorrUp, phiCorrUp);
    break;
  case -1:
    vec.SetMagPhi(ptCorrDown, phiCorrDown);
    break;
  }
  return vec;
}


/* BEGIN CUSTOM RecoMet.cc.global */
/* END CUSTOM */
