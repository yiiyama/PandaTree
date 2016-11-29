#include "../interface/PMuon.h"

void
panda::PMuon::datastore::allocate(UInt_t _nmax)
{
  PLepton::datastore::allocate(_nmax);
}

void
panda::PMuon::datastore::deallocate()
{
  PLepton::datastore::deallocate();
}

void
panda::PMuon::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::datastore::setStatus(_tree, _name, _status, _branches);
}

void
panda::PMuon::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PLepton::datastore::setAddress(_tree, _name, _branches, _setStatus);
}

void
panda::PMuon::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PLepton::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));
}

void
panda::PMuon::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  PLepton::datastore::resetAddress(_tree, _name);
}

void
panda::PMuon::datastore::resizeVectors_(UInt_t _size)
{
  PLepton::datastore::resizeVectors_(_size);
}

panda::PMuon::PMuon(char const* _name/* = ""*/) :
  PLepton(new PMuonArray(1, _name))
{
}

panda::PMuon::PMuon(datastore& _data, UInt_t _idx) :
  PLepton(_data, _idx)
{
}

panda::PMuon::PMuon(PMuon const& _src) :
  PLepton(new PMuonArray(1, gStore.getName(&_src)))
{
  PLepton::operator=(_src);
}

panda::PMuon::PMuon(ArrayBase* _array) :
  PLepton(_array)
{
}

panda::PMuon::~PMuon()
{
  gStore.free(this);
}

panda::PMuon&
panda::PMuon::operator=(PMuon const& _src)
{
  PLepton::operator=(_src);

  return *this;
}

void
panda::PMuon::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));
}

void
panda::PMuon::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PLepton::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));
}

void
panda::PMuon::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::book(_tree, _branches);

  TString name(gStore.getName(this));
}

void
panda::PMuon::resetAddress(TTree& _tree)
{
  PLepton::resetAddress(_tree);

  TString name(gStore.getName(this));
}

void
panda::PMuon::init()
{
  PLepton::init();
}


/* BEGIN CUSTOM */
/* END CUSTOM */
