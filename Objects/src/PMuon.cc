#include "../interface/PMuon.h"

void
panda::PMuon::datastore::allocate(UInt_t _nmax)
{
  PLepton::datastore::allocate(_nmax);

  matchHLT = new Bool_t[nmax_][nMuonHLTObjects];
}

void
panda::PMuon::datastore::deallocate()
{
  PLepton::datastore::deallocate();

  delete [] matchHLT;
  matchHLT = 0;
}

void
panda::PMuon::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "matchHLT", _status, _branches);
}

void
panda::PMuon::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PLepton::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "matchHLT", matchHLT, _branches, _setStatus);
}

void
panda::PMuon::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PLepton::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "matchHLT", size + "[nMuonHLTObjects]", 'O', matchHLT, _branches);
}

void
panda::PMuon::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  PLepton::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "matchHLT");
}

void
panda::PMuon::datastore::resizeVectors_(UInt_t _size)
{
  PLepton::datastore::resizeVectors_(_size);

}

panda::PMuon::PMuon(char const* _name/* = ""*/) :
  PLepton(new PMuonArray(1, _name)),
  matchHLT(gStore.getData(this).matchHLT[0])
{
}

panda::PMuon::PMuon(datastore& _data, UInt_t _idx) :
  PLepton(_data, _idx),
  matchHLT(_data.matchHLT[_idx])
{
}

panda::PMuon::PMuon(PMuon const& _src) :
  PLepton(new PMuonArray(1, gStore.getName(&_src))),
  matchHLT(gStore.getData(this).matchHLT[0])
{
  PLepton::operator=(_src);

  std::memcpy(matchHLT, _src.matchHLT, sizeof(Bool_t) * nMuonHLTObjects);
}

panda::PMuon::PMuon(ArrayBase* _array) :
  PLepton(_array),
  matchHLT(gStore.getData(this).matchHLT[0])
{
}

panda::PMuon::~PMuon()
{
  destructor();
  gStore.free(this);
}

void
panda::PMuon::destructor()
{
  /* BEGIN CUSTOM PMuon.cc.destructor */
  /* END CUSTOM */

  PLepton::destructor();
}

panda::PMuon&
panda::PMuon::operator=(PMuon const& _src)
{
  PLepton::operator=(_src);

  std::memcpy(matchHLT, _src.matchHLT, sizeof(Bool_t) * nMuonHLTObjects);

  return *this;
}

void
panda::PMuon::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "matchHLT", _status, _branches);
}

void
panda::PMuon::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PLepton::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "matchHLT", matchHLT, _branches, _setStatus);
}

void
panda::PMuon::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "matchHLT", "[nMuonHLTObjects]", 'O', matchHLT, _branches);
}

void
panda::PMuon::resetAddress(TTree& _tree)
{
  PLepton::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "matchHLT");
}

void
panda::PMuon::init()
{
  PLepton::init();

  for (auto& p0 : matchHLT) p0 = false;
}


/* BEGIN CUSTOM PMuon.cc.global */
/* END CUSTOM */
