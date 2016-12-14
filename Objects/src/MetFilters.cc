#include "../interface/MetFilters.h"

panda::MetFilters::MetFilters(char const* _name/* = ""*/) :
  Singlet(_name)
{
}

panda::MetFilters::MetFilters(MetFilters const& _src) :
  Singlet(_src.name_),
  globalHalo16(_src.globalHalo16),
  hbhe(_src.hbhe),
  hbheIso(_src.hbheIso),
  ecalDeadCell(_src.ecalDeadCell),
  badsc(_src.badsc),
  badTrack(_src.badTrack),
  badMuonTrack(_src.badMuonTrack)
{
  globalHalo16 = _src.globalHalo16;
  hbhe = _src.hbhe;
  hbheIso = _src.hbheIso;
  ecalDeadCell = _src.ecalDeadCell;
  badsc = _src.badsc;
  badTrack = _src.badTrack;
  badMuonTrack = _src.badMuonTrack;
}

panda::MetFilters::~MetFilters()
{
}

panda::MetFilters&
panda::MetFilters::operator=(MetFilters const& _src)
{
  Singlet::operator=(_src);

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
panda::MetFilters::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  Singlet::setStatus(_tree, _status, _branches);

  utils::setStatus(_tree, name_, "globalHalo16", _status, _branches);
  utils::setStatus(_tree, name_, "hbhe", _status, _branches);
  utils::setStatus(_tree, name_, "hbheIso", _status, _branches);
  utils::setStatus(_tree, name_, "ecalDeadCell", _status, _branches);
  utils::setStatus(_tree, name_, "badsc", _status, _branches);
  utils::setStatus(_tree, name_, "badTrack", _status, _branches);
  utils::setStatus(_tree, name_, "badMuonTrack", _status, _branches);
}

void
panda::MetFilters::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Singlet::setAddress(_tree, _branches, _setStatus);

  utils::setAddress(_tree, name_, "globalHalo16", &globalHalo16, _branches, _setStatus);
  utils::setAddress(_tree, name_, "hbhe", &hbhe, _branches, _setStatus);
  utils::setAddress(_tree, name_, "hbheIso", &hbheIso, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ecalDeadCell", &ecalDeadCell, _branches, _setStatus);
  utils::setAddress(_tree, name_, "badsc", &badsc, _branches, _setStatus);
  utils::setAddress(_tree, name_, "badTrack", &badTrack, _branches, _setStatus);
  utils::setAddress(_tree, name_, "badMuonTrack", &badMuonTrack, _branches, _setStatus);
}

void
panda::MetFilters::book(TTree& _tree, utils::BranchList const& _branches/* = {}*/)
{
  Singlet::book(_tree, _branches);

  utils::book(_tree, name_, "globalHalo16", "", 'O', &globalHalo16, _branches);
  utils::book(_tree, name_, "hbhe", "", 'O', &hbhe, _branches);
  utils::book(_tree, name_, "hbheIso", "", 'O', &hbheIso, _branches);
  utils::book(_tree, name_, "ecalDeadCell", "", 'O', &ecalDeadCell, _branches);
  utils::book(_tree, name_, "badsc", "", 'O', &badsc, _branches);
  utils::book(_tree, name_, "badTrack", "", 'O', &badTrack, _branches);
  utils::book(_tree, name_, "badMuonTrack", "", 'O', &badMuonTrack, _branches);
}

void
panda::MetFilters::resetAddress(TTree& _tree)
{
  Singlet::resetAddress(_tree);

  utils::resetAddress(_tree, name_, "globalHalo16");
  utils::resetAddress(_tree, name_, "hbhe");
  utils::resetAddress(_tree, name_, "hbheIso");
  utils::resetAddress(_tree, name_, "ecalDeadCell");
  utils::resetAddress(_tree, name_, "badsc");
  utils::resetAddress(_tree, name_, "badTrack");
  utils::resetAddress(_tree, name_, "badMuonTrack");
}

void
panda::MetFilters::init()
{
  Singlet::init();

  globalHalo16 = false;
  hbhe = false;
  hbheIso = false;
  ecalDeadCell = false;
  badsc = false;
  badTrack = false;
  badMuonTrack = false;
}


/* BEGIN CUSTOM MetFilters.cc.global */
/* END CUSTOM */
