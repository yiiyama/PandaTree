#include "../interface/PRecoMET.h"

panda::PRecoMET::PRecoMET(char const* _name/* = ""*/) :
  PMET(_name)
{
}

panda::PRecoMET::PRecoMET(PRecoMET const& _src) :
  PMET(_src.name_),
  sumETRaw(_src.sumETRaw),
  ptCorrUp(_src.ptCorrUp),
  phiCorrUp(_src.phiCorrUp),
  ptCorrDown(_src.ptCorrDown),
  phiCorrDown(_src.phiCorrDown),
  ptUnclUp(_src.ptUnclUp),
  phiUnclUp(_src.phiUnclUp),
  ptUnclDown(_src.ptUnclDown),
  phiUnclDown(_src.phiUnclDown),
  ptSmear(_src.ptSmear),
  phiSmear(_src.phiSmear),
  ptSmearUp(_src.ptSmearUp),
  phiSmearUp(_src.phiSmearUp),
  ptSmearDown(_src.ptSmearDown),
  phiSmearDown(_src.phiSmearDown)
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
  ptSmear = _src.ptSmear;
  phiSmear = _src.phiSmear;
  ptSmearUp = _src.ptSmearUp;
  phiSmearUp = _src.phiSmearUp;
  ptSmearDown = _src.ptSmearDown;
  phiSmearDown = _src.phiSmearDown;
}

panda::PRecoMET::~PRecoMET()
{
}

panda::PRecoMET&
panda::PRecoMET::operator=(PRecoMET const& _src)
{
  PMET::operator=(_src);

  sumETRaw = _src.sumETRaw;
  ptCorrUp = _src.ptCorrUp;
  phiCorrUp = _src.phiCorrUp;
  ptCorrDown = _src.ptCorrDown;
  phiCorrDown = _src.phiCorrDown;
  ptUnclUp = _src.ptUnclUp;
  phiUnclUp = _src.phiUnclUp;
  ptUnclDown = _src.ptUnclDown;
  phiUnclDown = _src.phiUnclDown;
  ptSmear = _src.ptSmear;
  phiSmear = _src.phiSmear;
  ptSmearUp = _src.ptSmearUp;
  phiSmearUp = _src.phiSmearUp;
  ptSmearDown = _src.ptSmearDown;
  phiSmearDown = _src.phiSmearDown;

  return *this;
}

void
panda::PRecoMET::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  PMET::setStatus(_tree, _status, _branches);

  utils::setStatus(_tree, name_, "sumETRaw", _status, _branches);
  utils::setStatus(_tree, name_, "ptCorrUp", _status, _branches);
  utils::setStatus(_tree, name_, "phiCorrUp", _status, _branches);
  utils::setStatus(_tree, name_, "ptCorrDown", _status, _branches);
  utils::setStatus(_tree, name_, "phiCorrDown", _status, _branches);
  utils::setStatus(_tree, name_, "ptUnclUp", _status, _branches);
  utils::setStatus(_tree, name_, "phiUnclUp", _status, _branches);
  utils::setStatus(_tree, name_, "ptUnclDown", _status, _branches);
  utils::setStatus(_tree, name_, "phiUnclDown", _status, _branches);
  utils::setStatus(_tree, name_, "ptSmear", _status, _branches);
  utils::setStatus(_tree, name_, "phiSmear", _status, _branches);
  utils::setStatus(_tree, name_, "ptSmearUp", _status, _branches);
  utils::setStatus(_tree, name_, "phiSmearUp", _status, _branches);
  utils::setStatus(_tree, name_, "ptSmearDown", _status, _branches);
  utils::setStatus(_tree, name_, "phiSmearDown", _status, _branches);
}

void
panda::PRecoMET::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PMET::setAddress(_tree, _branches, _setStatus);

  utils::setAddress(_tree, name_, "sumETRaw", &sumETRaw, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ptCorrUp", &ptCorrUp, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phiCorrUp", &phiCorrUp, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ptCorrDown", &ptCorrDown, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phiCorrDown", &phiCorrDown, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ptUnclUp", &ptUnclUp, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phiUnclUp", &phiUnclUp, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ptUnclDown", &ptUnclDown, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phiUnclDown", &phiUnclDown, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ptSmear", &ptSmear, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phiSmear", &phiSmear, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ptSmearUp", &ptSmearUp, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phiSmearUp", &phiSmearUp, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ptSmearDown", &ptSmearDown, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phiSmearDown", &phiSmearDown, _branches, _setStatus);
}

void
panda::PRecoMET::book(TTree& _tree, utils::BranchList const& _branches/* = {}*/)
{
  PMET::book(_tree, _branches);

  utils::book(_tree, name_, "sumETRaw", "", 'F', &sumETRaw, _branches);
  utils::book(_tree, name_, "ptCorrUp", "", 'F', &ptCorrUp, _branches);
  utils::book(_tree, name_, "phiCorrUp", "", 'F', &phiCorrUp, _branches);
  utils::book(_tree, name_, "ptCorrDown", "", 'F', &ptCorrDown, _branches);
  utils::book(_tree, name_, "phiCorrDown", "", 'F', &phiCorrDown, _branches);
  utils::book(_tree, name_, "ptUnclUp", "", 'F', &ptUnclUp, _branches);
  utils::book(_tree, name_, "phiUnclUp", "", 'F', &phiUnclUp, _branches);
  utils::book(_tree, name_, "ptUnclDown", "", 'F', &ptUnclDown, _branches);
  utils::book(_tree, name_, "phiUnclDown", "", 'F', &phiUnclDown, _branches);
  utils::book(_tree, name_, "ptSmear", "", 'F', &ptSmear, _branches);
  utils::book(_tree, name_, "phiSmear", "", 'F', &phiSmear, _branches);
  utils::book(_tree, name_, "ptSmearUp", "", 'F', &ptSmearUp, _branches);
  utils::book(_tree, name_, "phiSmearUp", "", 'F', &phiSmearUp, _branches);
  utils::book(_tree, name_, "ptSmearDown", "", 'F', &ptSmearDown, _branches);
  utils::book(_tree, name_, "phiSmearDown", "", 'F', &phiSmearDown, _branches);
}

void
panda::PRecoMET::resetAddress(TTree& _tree)
{
  PMET::resetAddress(_tree);

  utils::resetAddress(_tree, name_, "sumETRaw");
  utils::resetAddress(_tree, name_, "ptCorrUp");
  utils::resetAddress(_tree, name_, "phiCorrUp");
  utils::resetAddress(_tree, name_, "ptCorrDown");
  utils::resetAddress(_tree, name_, "phiCorrDown");
  utils::resetAddress(_tree, name_, "ptUnclUp");
  utils::resetAddress(_tree, name_, "phiUnclUp");
  utils::resetAddress(_tree, name_, "ptUnclDown");
  utils::resetAddress(_tree, name_, "phiUnclDown");
  utils::resetAddress(_tree, name_, "ptSmear");
  utils::resetAddress(_tree, name_, "phiSmear");
  utils::resetAddress(_tree, name_, "ptSmearUp");
  utils::resetAddress(_tree, name_, "phiSmearUp");
  utils::resetAddress(_tree, name_, "ptSmearDown");
  utils::resetAddress(_tree, name_, "phiSmearDown");
}

void
panda::PRecoMET::init()
{
  PMET::init();

  sumETRaw = 0.;
  ptCorrUp = 0.;
  phiCorrUp = 0.;
  ptCorrDown = 0.;
  phiCorrDown = 0.;
  ptUnclUp = 0.;
  phiUnclUp = 0.;
  ptUnclDown = 0.;
  phiUnclDown = 0.;
  ptSmear = 0.;
  phiSmear = 0.;
  ptSmearUp = 0.;
  phiSmearUp = 0.;
  ptSmearDown = 0.;
  phiSmearDown = 0.;
}

TVector2
panda::PRecoMET::vCorr(int corr/* = 0*/) const
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


/* BEGIN CUSTOM PRecoMET.cc.global */
/* END CUSTOM */
