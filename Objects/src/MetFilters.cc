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
panda::MetFilters::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::setStatus(_tree, name_, "globalHalo16", _branches);
  utils::setStatus(_tree, name_, "hbhe", _branches);
  utils::setStatus(_tree, name_, "hbheIso", _branches);
  utils::setStatus(_tree, name_, "ecalDeadCell", _branches);
  utils::setStatus(_tree, name_, "badsc", _branches);
  utils::setStatus(_tree, name_, "badTrack", _branches);
  utils::setStatus(_tree, name_, "badMuonTrack", _branches);
}

panda::utils::BranchList
panda::MetFilters::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;

  blist.push_back(utils::getStatus(_tree, name_, "globalHalo16"));
  blist.push_back(utils::getStatus(_tree, name_, "hbhe"));
  blist.push_back(utils::getStatus(_tree, name_, "hbheIso"));
  blist.push_back(utils::getStatus(_tree, name_, "ecalDeadCell"));
  blist.push_back(utils::getStatus(_tree, name_, "badsc"));
  blist.push_back(utils::getStatus(_tree, name_, "badTrack"));
  blist.push_back(utils::getStatus(_tree, name_, "badMuonTrack"));

  return blist;
}

panda::utils::BranchList
panda::MetFilters::doGetBranchNames_() const
{
  utils::BranchList blist;

  blist.push_back(utils::BranchName("globalHalo16").fullName(name_));
  blist.push_back(utils::BranchName("hbhe").fullName(name_));
  blist.push_back(utils::BranchName("hbheIso").fullName(name_));
  blist.push_back(utils::BranchName("ecalDeadCell").fullName(name_));
  blist.push_back(utils::BranchName("badsc").fullName(name_));
  blist.push_back(utils::BranchName("badTrack").fullName(name_));
  blist.push_back(utils::BranchName("badMuonTrack").fullName(name_));

  return blist;
}

void
panda::MetFilters::doSetAddress_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  utils::setAddress(_tree, name_, "globalHalo16", &globalHalo16, _branches, _setStatus);
  utils::setAddress(_tree, name_, "hbhe", &hbhe, _branches, _setStatus);
  utils::setAddress(_tree, name_, "hbheIso", &hbheIso, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ecalDeadCell", &ecalDeadCell, _branches, _setStatus);
  utils::setAddress(_tree, name_, "badsc", &badsc, _branches, _setStatus);
  utils::setAddress(_tree, name_, "badTrack", &badTrack, _branches, _setStatus);
  utils::setAddress(_tree, name_, "badMuonTrack", &badMuonTrack, _branches, _setStatus);
}

void
panda::MetFilters::doBook_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  utils::book(_tree, name_, "globalHalo16", "", 'O', &globalHalo16, _branches);
  utils::book(_tree, name_, "hbhe", "", 'O', &hbhe, _branches);
  utils::book(_tree, name_, "hbheIso", "", 'O', &hbheIso, _branches);
  utils::book(_tree, name_, "ecalDeadCell", "", 'O', &ecalDeadCell, _branches);
  utils::book(_tree, name_, "badsc", "", 'O', &badsc, _branches);
  utils::book(_tree, name_, "badTrack", "", 'O', &badTrack, _branches);
  utils::book(_tree, name_, "badMuonTrack", "", 'O', &badMuonTrack, _branches);
}

void
panda::MetFilters::doReleaseTree_(TTree& _tree)
{
  utils::resetAddress(_tree, name_, "globalHalo16");
  utils::resetAddress(_tree, name_, "hbhe");
  utils::resetAddress(_tree, name_, "hbheIso");
  utils::resetAddress(_tree, name_, "ecalDeadCell");
  utils::resetAddress(_tree, name_, "badsc");
  utils::resetAddress(_tree, name_, "badTrack");
  utils::resetAddress(_tree, name_, "badMuonTrack");
}

void
panda::MetFilters::doInit_()
{
  globalHalo16 = false;
  hbhe = false;
  hbheIso = false;
  ecalDeadCell = false;
  badsc = false;
  badTrack = false;
  badMuonTrack = false;

  /* BEGIN CUSTOM MetFilters.cc.doInit_ */
  /* END CUSTOM */
}


/* BEGIN CUSTOM MetFilters.cc.global */
/* END CUSTOM */
