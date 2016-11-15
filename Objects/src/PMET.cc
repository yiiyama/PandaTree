#include "../interface/PMET.h"

panda::PMET::PMET() :
  Singlet()
{
}

panda::PMET::PMET(PMET const& _src) :
  Singlet(_src.name_),
  pt(_src.pt),
  phi(_src.phi),
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
  hf_phi(_src.hf_phi)
{
}

panda::PMET::PMET(TString const& _name) :
  Singlet(_name)
{
}

panda::PMET::~PMET()
{
}

panda::PMET&
panda::PMET::operator=(PMET const& _src)
{
  Singlet::operator=(_src);

  pt = _src.pt;
  phi = _src.phi;
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

  return *this;
}

void
panda::PMET::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  Singlet::setStatus(_tree, _status, _branches);

  utils::setStatus(_tree, name_, "pt", _status, _branches);
  utils::setStatus(_tree, name_, "phi", _status, _branches);
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
}

void
panda::PMET::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  Singlet::setAddress(_tree, _branches);

  utils::setStatusAndAddress(_tree, name_, "pt", &pt, _branches);
  utils::setStatusAndAddress(_tree, name_, "phi", &phi, _branches);
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
}

void
panda::PMET::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  Singlet::book(_tree, _branches);

  utils::book(_tree, name_, "pt", "", 'F', &pt, _branches);
  utils::book(_tree, name_, "phi", "", 'F', &phi, _branches);
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
}

void
panda::PMET::init()
{
  Singlet::init();

  pt = 0.;
  phi = 0.;
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
}


/* BEGIN CUSTOM */
/* END CUSTOM */
