#include "../interface/Muon.h"

void
panda::Muon::datastore::allocate(UInt_t _nmax)
{
  Lepton::datastore::allocate(_nmax);

  triggerMatch = new Bool_t[nmax_][nMuonTriggerObjects];
}

void
panda::Muon::datastore::deallocate()
{
  Lepton::datastore::deallocate();

  delete [] triggerMatch;
  triggerMatch = 0;
}

void
panda::Muon::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Lepton::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "triggerMatch", _branches);
}

panda::utils::BranchList
panda::Muon::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Lepton::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "triggerMatch"));

  return blist;
}

void
panda::Muon::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Lepton::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "triggerMatch", triggerMatch, _branches, _setStatus);
}

void
panda::Muon::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Lepton::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "triggerMatch", size + TString::Format("[%d]", nMuonTriggerObjects), 'O', triggerMatch, _branches);
}

void
panda::Muon::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Lepton::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "triggerMatch");
}

void
panda::Muon::datastore::resizeVectors_(UInt_t _size)
{
  Lepton::datastore::resizeVectors_(_size);

}

panda::Muon::Muon(char const* _name/* = ""*/) :
  Lepton(new MuonArray(1, _name)),
  triggerMatch(gStore.getData(this).triggerMatch[0])
{
}

panda::Muon::Muon(datastore& _data, UInt_t _idx) :
  Lepton(_data, _idx),
  triggerMatch(_data.triggerMatch[_idx])
{
}

panda::Muon::Muon(Muon const& _src) :
  Lepton(new MuonArray(1, gStore.getName(&_src))),
  triggerMatch(gStore.getData(this).triggerMatch[0])
{
  Lepton::operator=(_src);

  std::memcpy(triggerMatch, _src.triggerMatch, sizeof(Bool_t) * nMuonTriggerObjects);
}

panda::Muon::Muon(ArrayBase* _array) :
  Lepton(_array),
  triggerMatch(gStore.getData(this).triggerMatch[0])
{
}

panda::Muon::~Muon()
{
  destructor();
  gStore.free(this);
}

void
panda::Muon::destructor()
{
  /* BEGIN CUSTOM Muon.cc.destructor */
  /* END CUSTOM */

  Lepton::destructor();
}

panda::Muon&
panda::Muon::operator=(Muon const& _src)
{
  Lepton::operator=(_src);

  std::memcpy(triggerMatch, _src.triggerMatch, sizeof(Bool_t) * nMuonTriggerObjects);

  return *this;
}

void
panda::Muon::doSetStatus_(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Lepton::doSetStatus_(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "triggerMatch", _branches);
}

panda::utils::BranchList
panda::Muon::doGetStatus_(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Lepton::doGetStatus_(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "triggerMatch"));

  return blist;
}

void
panda::Muon::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Lepton::doSetAddress_(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "triggerMatch", triggerMatch, _branches, _setStatus);
}

void
panda::Muon::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  Lepton::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "triggerMatch", TString::Format("[%d]", nMuonTriggerObjects), 'O', triggerMatch, _branches);
}

void
panda::Muon::doReleaseTree_(TTree& _tree, TString const& _name)
{
  Lepton::doReleaseTree_(_tree, _name);

  utils::resetAddress(_tree, _name, "triggerMatch");
}

void
panda::Muon::doInit_()
{
  Lepton::doInit_();

  for (auto& p0 : triggerMatch) p0 = false;
}


/* BEGIN CUSTOM Muon.cc.global */
/* END CUSTOM */
