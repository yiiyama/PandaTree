#include "../interface/PMETFilters.h"

panda::PMETFilters::PMETFilters(char const* _name/* = ""*/) :
  Singlet(_name)
{
}

panda::PMETFilters::PMETFilters(PMETFilters const& _src) :
  Singlet(_src.name_),
  cschalo(_src.cschalo),
  globalHalo16(_src.globalHalo16),
  hbhe(_src.hbhe),
  hbheIso(_src.hbheIso),
  ecalDeadCell(_src.ecalDeadCell),
  badsc(_src.badsc),
  badTrack(_src.badTrack),
  badMuonTrack(_src.badMuonTrack)
{
  cschalo = _src.cschalo;
  globalHalo16 = _src.globalHalo16;
  hbhe = _src.hbhe;
  hbheIso = _src.hbheIso;
  ecalDeadCell = _src.ecalDeadCell;
  badsc = _src.badsc;
  badTrack = _src.badTrack;
  badMuonTrack = _src.badMuonTrack;
}

panda::PMETFilters::~PMETFilters()
{
}

panda::PMETFilters&
panda::PMETFilters::operator=(PMETFilters const& _src)
{
  Singlet::operator=(_src);

  cschalo = _src.cschalo;
  globalHalo16 = _src.globalHalo16;
  hbhe = _src.hbhe;
  hbheIso = _src.hbheIso;
  ecalDeadCell = _src.ecalDeadCell;
  badsc = _src.badsc;
  badTrack = _src.badTrack;
  badMuonTrack = _src.badMuonTrack;

  return *this;
}

void
panda::PMETFilters::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  Singlet::setStatus(_tree, _status, _branches);

  utils::setStatus(_tree, name_, "cschalo", _status, _branches);
  utils::setStatus(_tree, name_, "globalHalo16", _status, _branches);
  utils::setStatus(_tree, name_, "hbhe", _status, _branches);
  utils::setStatus(_tree, name_, "hbheIso", _status, _branches);
  utils::setStatus(_tree, name_, "ecalDeadCell", _status, _branches);
  utils::setStatus(_tree, name_, "badsc", _status, _branches);
  utils::setStatus(_tree, name_, "badTrack", _status, _branches);
  utils::setStatus(_tree, name_, "badMuonTrack", _status, _branches);
}

void
panda::PMETFilters::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Singlet::setAddress(_tree, _branches, _setStatus);

  utils::setAddress(_tree, name_, "cschalo", &cschalo, _branches, _setStatus);
  utils::setAddress(_tree, name_, "globalHalo16", &globalHalo16, _branches, _setStatus);
  utils::setAddress(_tree, name_, "hbhe", &hbhe, _branches, _setStatus);
  utils::setAddress(_tree, name_, "hbheIso", &hbheIso, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ecalDeadCell", &ecalDeadCell, _branches, _setStatus);
  utils::setAddress(_tree, name_, "badsc", &badsc, _branches, _setStatus);
  utils::setAddress(_tree, name_, "badTrack", &badTrack, _branches, _setStatus);
  utils::setAddress(_tree, name_, "badMuonTrack", &badMuonTrack, _branches, _setStatus);
}

void
panda::PMETFilters::book(TTree& _tree, utils::BranchList const& _branches/* = {}*/)
{
  Singlet::book(_tree, _branches);

  utils::book(_tree, name_, "cschalo", "", 'O', &cschalo, _branches);
  utils::book(_tree, name_, "globalHalo16", "", 'O', &globalHalo16, _branches);
  utils::book(_tree, name_, "hbhe", "", 'O', &hbhe, _branches);
  utils::book(_tree, name_, "hbheIso", "", 'O', &hbheIso, _branches);
  utils::book(_tree, name_, "ecalDeadCell", "", 'O', &ecalDeadCell, _branches);
  utils::book(_tree, name_, "badsc", "", 'O', &badsc, _branches);
  utils::book(_tree, name_, "badTrack", "", 'O', &badTrack, _branches);
  utils::book(_tree, name_, "badMuonTrack", "", 'O', &badMuonTrack, _branches);
}

void
panda::PMETFilters::resetAddress(TTree& _tree)
{
  Singlet::resetAddress(_tree);

  utils::resetAddress(_tree, name_, "cschalo");
  utils::resetAddress(_tree, name_, "globalHalo16");
  utils::resetAddress(_tree, name_, "hbhe");
  utils::resetAddress(_tree, name_, "hbheIso");
  utils::resetAddress(_tree, name_, "ecalDeadCell");
  utils::resetAddress(_tree, name_, "badsc");
  utils::resetAddress(_tree, name_, "badTrack");
  utils::resetAddress(_tree, name_, "badMuonTrack");
}

void
panda::PMETFilters::init()
{
  Singlet::init();

  cschalo = false;
  globalHalo16 = false;
  hbhe = false;
  hbheIso = false;
  ecalDeadCell = false;
  badsc = false;
  badTrack = false;
  badMuonTrack = false;
}


/* BEGIN CUSTOM PMETFilters.cc.global */
/* END CUSTOM */
