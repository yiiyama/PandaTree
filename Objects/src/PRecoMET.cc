#include "../interface/PRecoMET.h"

panda::PRecoMET::PRecoMET(char const* _name/* = ""*/) :
  PMET(_name)
{
}

panda::PRecoMET::PRecoMET(PRecoMET const& _src) :
  PMET(_src.name_),
  sumETRaw(_src.sumETRaw),
  raw_pt(_src.raw_pt),
  raw_phi(_src.raw_phi),
  calo_pt(_src.calo_pt),
  calo_phi(_src.calo_phi),
  noMu_pt(_src.noMu_pt),
  noMu_phi(_src.noMu_phi),
  noHF_pt(_src.noHF_pt),
  noHF_phi(_src.noHF_phi),
  trk_pt(_src.trk_pt),
  trk_phi(_src.trk_phi),
  neutral_pt(_src.neutral_pt),
  neutral_phi(_src.neutral_phi),
  photon_pt(_src.photon_pt),
  photon_phi(_src.photon_phi),
  hf_pt(_src.hf_pt),
  hf_phi(_src.hf_phi),
  ptCorrUp(_src.ptCorrUp),
  phiCorrUp(_src.phiCorrUp),
  ptCorrDown(_src.ptCorrDown),
  phiCorrDown(_src.phiCorrDown),
  ptJetRes(_src.ptJetRes),
  phiJetRes(_src.phiJetRes),
  ptUnclUp(_src.ptUnclUp),
  phiUnclUp(_src.phiUnclUp),
  ptUnclDown(_src.ptUnclDown),
  phiUnclDown(_src.phiUnclDown)
{
}

panda::PRecoMET::~PRecoMET()
{
}

panda::PRecoMET&
panda::PRecoMET::operator=(PRecoMET const& _src)
{
  PMET::operator=(_src);

  sumETRaw = _src.sumETRaw;
  raw_pt = _src.raw_pt;
  raw_phi = _src.raw_phi;
  calo_pt = _src.calo_pt;
  calo_phi = _src.calo_phi;
  noMu_pt = _src.noMu_pt;
  noMu_phi = _src.noMu_phi;
  noHF_pt = _src.noHF_pt;
  noHF_phi = _src.noHF_phi;
  trk_pt = _src.trk_pt;
  trk_phi = _src.trk_phi;
  neutral_pt = _src.neutral_pt;
  neutral_phi = _src.neutral_phi;
  photon_pt = _src.photon_pt;
  photon_phi = _src.photon_phi;
  hf_pt = _src.hf_pt;
  hf_phi = _src.hf_phi;
  ptCorrUp = _src.ptCorrUp;
  phiCorrUp = _src.phiCorrUp;
  ptCorrDown = _src.ptCorrDown;
  phiCorrDown = _src.phiCorrDown;
  ptJetRes = _src.ptJetRes;
  phiJetRes = _src.phiJetRes;
  ptUnclUp = _src.ptUnclUp;
  phiUnclUp = _src.phiUnclUp;
  ptUnclDown = _src.ptUnclDown;
  phiUnclDown = _src.phiUnclDown;

  return *this;
}

void
panda::PRecoMET::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PMET::setStatus(_tree, _status, _branches);

  utils::setStatus(_tree, name_, "sumETRaw", _status, _branches);
  utils::setStatus(_tree, name_, "raw_pt", _status, _branches);
  utils::setStatus(_tree, name_, "raw_phi", _status, _branches);
  utils::setStatus(_tree, name_, "calo_pt", _status, _branches);
  utils::setStatus(_tree, name_, "calo_phi", _status, _branches);
  utils::setStatus(_tree, name_, "noMu_pt", _status, _branches);
  utils::setStatus(_tree, name_, "noMu_phi", _status, _branches);
  utils::setStatus(_tree, name_, "noHF_pt", _status, _branches);
  utils::setStatus(_tree, name_, "noHF_phi", _status, _branches);
  utils::setStatus(_tree, name_, "trk_pt", _status, _branches);
  utils::setStatus(_tree, name_, "trk_phi", _status, _branches);
  utils::setStatus(_tree, name_, "neutral_pt", _status, _branches);
  utils::setStatus(_tree, name_, "neutral_phi", _status, _branches);
  utils::setStatus(_tree, name_, "photon_pt", _status, _branches);
  utils::setStatus(_tree, name_, "photon_phi", _status, _branches);
  utils::setStatus(_tree, name_, "hf_pt", _status, _branches);
  utils::setStatus(_tree, name_, "hf_phi", _status, _branches);
  utils::setStatus(_tree, name_, "ptCorrUp", _status, _branches);
  utils::setStatus(_tree, name_, "phiCorrUp", _status, _branches);
  utils::setStatus(_tree, name_, "ptCorrDown", _status, _branches);
  utils::setStatus(_tree, name_, "phiCorrDown", _status, _branches);
  utils::setStatus(_tree, name_, "ptJetRes", _status, _branches);
  utils::setStatus(_tree, name_, "phiJetRes", _status, _branches);
  utils::setStatus(_tree, name_, "ptUnclUp", _status, _branches);
  utils::setStatus(_tree, name_, "phiUnclUp", _status, _branches);
  utils::setStatus(_tree, name_, "ptUnclDown", _status, _branches);
  utils::setStatus(_tree, name_, "phiUnclDown", _status, _branches);
}

void
panda::PRecoMET::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PMET::setAddress(_tree, _branches);

  utils::setStatusAndAddress(_tree, name_, "sumETRaw", &sumETRaw, _branches);
  utils::setStatusAndAddress(_tree, name_, "raw_pt", &raw_pt, _branches);
  utils::setStatusAndAddress(_tree, name_, "raw_phi", &raw_phi, _branches);
  utils::setStatusAndAddress(_tree, name_, "calo_pt", &calo_pt, _branches);
  utils::setStatusAndAddress(_tree, name_, "calo_phi", &calo_phi, _branches);
  utils::setStatusAndAddress(_tree, name_, "noMu_pt", &noMu_pt, _branches);
  utils::setStatusAndAddress(_tree, name_, "noMu_phi", &noMu_phi, _branches);
  utils::setStatusAndAddress(_tree, name_, "noHF_pt", &noHF_pt, _branches);
  utils::setStatusAndAddress(_tree, name_, "noHF_phi", &noHF_phi, _branches);
  utils::setStatusAndAddress(_tree, name_, "trk_pt", &trk_pt, _branches);
  utils::setStatusAndAddress(_tree, name_, "trk_phi", &trk_phi, _branches);
  utils::setStatusAndAddress(_tree, name_, "neutral_pt", &neutral_pt, _branches);
  utils::setStatusAndAddress(_tree, name_, "neutral_phi", &neutral_phi, _branches);
  utils::setStatusAndAddress(_tree, name_, "photon_pt", &photon_pt, _branches);
  utils::setStatusAndAddress(_tree, name_, "photon_phi", &photon_phi, _branches);
  utils::setStatusAndAddress(_tree, name_, "hf_pt", &hf_pt, _branches);
  utils::setStatusAndAddress(_tree, name_, "hf_phi", &hf_phi, _branches);
  utils::setStatusAndAddress(_tree, name_, "ptCorrUp", &ptCorrUp, _branches);
  utils::setStatusAndAddress(_tree, name_, "phiCorrUp", &phiCorrUp, _branches);
  utils::setStatusAndAddress(_tree, name_, "ptCorrDown", &ptCorrDown, _branches);
  utils::setStatusAndAddress(_tree, name_, "phiCorrDown", &phiCorrDown, _branches);
  utils::setStatusAndAddress(_tree, name_, "ptJetRes", &ptJetRes, _branches);
  utils::setStatusAndAddress(_tree, name_, "phiJetRes", &phiJetRes, _branches);
  utils::setStatusAndAddress(_tree, name_, "ptUnclUp", &ptUnclUp, _branches);
  utils::setStatusAndAddress(_tree, name_, "phiUnclUp", &phiUnclUp, _branches);
  utils::setStatusAndAddress(_tree, name_, "ptUnclDown", &ptUnclDown, _branches);
  utils::setStatusAndAddress(_tree, name_, "phiUnclDown", &phiUnclDown, _branches);
}

void
panda::PRecoMET::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PMET::book(_tree, _branches);

  utils::book(_tree, name_, "sumETRaw", "", 'F', &sumETRaw, _branches);
  utils::book(_tree, name_, "raw_pt", "", 'F', &raw_pt, _branches);
  utils::book(_tree, name_, "raw_phi", "", 'F', &raw_phi, _branches);
  utils::book(_tree, name_, "calo_pt", "", 'F', &calo_pt, _branches);
  utils::book(_tree, name_, "calo_phi", "", 'F', &calo_phi, _branches);
  utils::book(_tree, name_, "noMu_pt", "", 'F', &noMu_pt, _branches);
  utils::book(_tree, name_, "noMu_phi", "", 'F', &noMu_phi, _branches);
  utils::book(_tree, name_, "noHF_pt", "", 'F', &noHF_pt, _branches);
  utils::book(_tree, name_, "noHF_phi", "", 'F', &noHF_phi, _branches);
  utils::book(_tree, name_, "trk_pt", "", 'F', &trk_pt, _branches);
  utils::book(_tree, name_, "trk_phi", "", 'F', &trk_phi, _branches);
  utils::book(_tree, name_, "neutral_pt", "", 'F', &neutral_pt, _branches);
  utils::book(_tree, name_, "neutral_phi", "", 'F', &neutral_phi, _branches);
  utils::book(_tree, name_, "photon_pt", "", 'F', &photon_pt, _branches);
  utils::book(_tree, name_, "photon_phi", "", 'F', &photon_phi, _branches);
  utils::book(_tree, name_, "hf_pt", "", 'F', &hf_pt, _branches);
  utils::book(_tree, name_, "hf_phi", "", 'F', &hf_phi, _branches);
  utils::book(_tree, name_, "ptCorrUp", "", 'F', &ptCorrUp, _branches);
  utils::book(_tree, name_, "phiCorrUp", "", 'F', &phiCorrUp, _branches);
  utils::book(_tree, name_, "ptCorrDown", "", 'F', &ptCorrDown, _branches);
  utils::book(_tree, name_, "phiCorrDown", "", 'F', &phiCorrDown, _branches);
  utils::book(_tree, name_, "ptJetRes", "", 'F', &ptJetRes, _branches);
  utils::book(_tree, name_, "phiJetRes", "", 'F', &phiJetRes, _branches);
  utils::book(_tree, name_, "ptUnclUp", "", 'F', &ptUnclUp, _branches);
  utils::book(_tree, name_, "phiUnclUp", "", 'F', &phiUnclUp, _branches);
  utils::book(_tree, name_, "ptUnclDown", "", 'F', &ptUnclDown, _branches);
  utils::book(_tree, name_, "phiUnclDown", "", 'F', &phiUnclDown, _branches);
}

void
panda::PRecoMET::init()
{
  PMET::init();

  sumETRaw = 0.;
  raw_pt = 0.;
  raw_phi = 0.;
  calo_pt = 0.;
  calo_phi = 0.;
  noMu_pt = 0.;
  noMu_phi = 0.;
  noHF_pt = 0.;
  noHF_phi = 0.;
  trk_pt = 0.;
  trk_phi = 0.;
  neutral_pt = 0.;
  neutral_phi = 0.;
  photon_pt = 0.;
  photon_phi = 0.;
  hf_pt = 0.;
  hf_phi = 0.;
  ptCorrUp = 0.;
  phiCorrUp = 0.;
  ptCorrDown = 0.;
  phiCorrDown = 0.;
  ptJetRes = 0.;
  phiJetRes = 0.;
  ptUnclUp = 0.;
  phiUnclUp = 0.;
  ptUnclDown = 0.;
  phiUnclDown = 0.;
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


/* BEGIN CUSTOM */
/* END CUSTOM */
