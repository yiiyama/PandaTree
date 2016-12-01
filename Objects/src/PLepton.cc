#include "../interface/PLepton.h"

void
panda::PLepton::datastore::allocate(UInt_t _nmax)
{
  PParticle::datastore::allocate(_nmax);

  q = new Short_t[nmax_];
  loose = new Bool_t[nmax_];
  medium = new Bool_t[nmax_];
  tight = new Bool_t[nmax_];
  chiso = new Float_t[nmax_];
  nhiso = new Float_t[nmax_];
  phoiso = new Float_t[nmax_];
  puiso = new Float_t[nmax_];
  tauDecay = new Bool_t[nmax_];
  hadDecay = new Bool_t[nmax_];
}

void
panda::PLepton::datastore::deallocate()
{
  PParticle::datastore::deallocate();

  delete [] q;
  q = 0;
  delete [] loose;
  loose = 0;
  delete [] medium;
  medium = 0;
  delete [] tight;
  tight = 0;
  delete [] chiso;
  chiso = 0;
  delete [] nhiso;
  nhiso = 0;
  delete [] phoiso;
  phoiso = 0;
  delete [] puiso;
  puiso = 0;
  delete [] tauDecay;
  tauDecay = 0;
  delete [] hadDecay;
  hadDecay = 0;
}

void
panda::PLepton::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "q", _status, _branches);
  utils::setStatus(_tree, _name, "loose", _status, _branches);
  utils::setStatus(_tree, _name, "medium", _status, _branches);
  utils::setStatus(_tree, _name, "tight", _status, _branches);
  utils::setStatus(_tree, _name, "chiso", _status, _branches);
  utils::setStatus(_tree, _name, "nhiso", _status, _branches);
  utils::setStatus(_tree, _name, "phoiso", _status, _branches);
  utils::setStatus(_tree, _name, "puiso", _status, _branches);
  utils::setStatus(_tree, _name, "tauDecay", _status, _branches);
  utils::setStatus(_tree, _name, "hadDecay", _status, _branches);
}

void
panda::PLepton::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticle::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "q", q, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose", loose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "medium", medium, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight", tight, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chiso", chiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhiso", nhiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phoiso", phoiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puiso", puiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tauDecay", tauDecay, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hadDecay", hadDecay, _branches, _setStatus);
}

void
panda::PLepton::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PParticle::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "q", size, 'S', q, _branches);
  utils::book(_tree, _name, "loose", size, 'O', loose, _branches);
  utils::book(_tree, _name, "medium", size, 'O', medium, _branches);
  utils::book(_tree, _name, "tight", size, 'O', tight, _branches);
  utils::book(_tree, _name, "chiso", size, 'F', chiso, _branches);
  utils::book(_tree, _name, "nhiso", size, 'F', nhiso, _branches);
  utils::book(_tree, _name, "phoiso", size, 'F', phoiso, _branches);
  utils::book(_tree, _name, "puiso", size, 'F', puiso, _branches);
  utils::book(_tree, _name, "tauDecay", size, 'O', tauDecay, _branches);
  utils::book(_tree, _name, "hadDecay", size, 'O', hadDecay, _branches);
}

void
panda::PLepton::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  PParticle::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "q");
  utils::resetAddress(_tree, _name, "loose");
  utils::resetAddress(_tree, _name, "medium");
  utils::resetAddress(_tree, _name, "tight");
  utils::resetAddress(_tree, _name, "chiso");
  utils::resetAddress(_tree, _name, "nhiso");
  utils::resetAddress(_tree, _name, "phoiso");
  utils::resetAddress(_tree, _name, "puiso");
  utils::resetAddress(_tree, _name, "tauDecay");
  utils::resetAddress(_tree, _name, "hadDecay");
}

void
panda::PLepton::datastore::resizeVectors_(UInt_t _size)
{
  PParticle::datastore::resizeVectors_(_size);

}

panda::PLepton::PLepton(char const* _name/* = ""*/) :
  PParticle(new PLeptonArray(1, _name)),
  q(gStore.getData(this).q[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  chiso(gStore.getData(this).chiso[0]),
  nhiso(gStore.getData(this).nhiso[0]),
  phoiso(gStore.getData(this).phoiso[0]),
  puiso(gStore.getData(this).puiso[0]),
  tauDecay(gStore.getData(this).tauDecay[0]),
  hadDecay(gStore.getData(this).hadDecay[0])
{
}

panda::PLepton::PLepton(datastore& _data, UInt_t _idx) :
  PParticle(_data, _idx),
  q(_data.q[_idx]),
  loose(_data.loose[_idx]),
  medium(_data.medium[_idx]),
  tight(_data.tight[_idx]),
  chiso(_data.chiso[_idx]),
  nhiso(_data.nhiso[_idx]),
  phoiso(_data.phoiso[_idx]),
  puiso(_data.puiso[_idx]),
  tauDecay(_data.tauDecay[_idx]),
  hadDecay(_data.hadDecay[_idx])
{
}

panda::PLepton::PLepton(PLepton const& _src) :
  PParticle(new PLeptonArray(1, gStore.getName(&_src))),
  q(gStore.getData(this).q[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  chiso(gStore.getData(this).chiso[0]),
  nhiso(gStore.getData(this).nhiso[0]),
  phoiso(gStore.getData(this).phoiso[0]),
  puiso(gStore.getData(this).puiso[0]),
  tauDecay(gStore.getData(this).tauDecay[0]),
  hadDecay(gStore.getData(this).hadDecay[0])
{
  PParticle::operator=(_src);

  q = _src.q;
  loose = _src.loose;
  medium = _src.medium;
  tight = _src.tight;
  chiso = _src.chiso;
  nhiso = _src.nhiso;
  phoiso = _src.phoiso;
  puiso = _src.puiso;
  tauDecay = _src.tauDecay;
  hadDecay = _src.hadDecay;
}

panda::PLepton::PLepton(ArrayBase* _array) :
  PParticle(_array),
  q(gStore.getData(this).q[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  chiso(gStore.getData(this).chiso[0]),
  nhiso(gStore.getData(this).nhiso[0]),
  phoiso(gStore.getData(this).phoiso[0]),
  puiso(gStore.getData(this).puiso[0]),
  tauDecay(gStore.getData(this).tauDecay[0]),
  hadDecay(gStore.getData(this).hadDecay[0])
{
}

panda::PLepton::~PLepton()
{
  gStore.free(this);
}

panda::PLepton&
panda::PLepton::operator=(PLepton const& _src)
{
  PParticle::operator=(_src);

  q = _src.q;
  loose = _src.loose;
  medium = _src.medium;
  tight = _src.tight;
  chiso = _src.chiso;
  nhiso = _src.nhiso;
  phoiso = _src.phoiso;
  puiso = _src.puiso;
  tauDecay = _src.tauDecay;
  hadDecay = _src.hadDecay;

  return *this;
}

void
panda::PLepton::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "q", _status, _branches);
  utils::setStatus(_tree, name, "loose", _status, _branches);
  utils::setStatus(_tree, name, "medium", _status, _branches);
  utils::setStatus(_tree, name, "tight", _status, _branches);
  utils::setStatus(_tree, name, "chiso", _status, _branches);
  utils::setStatus(_tree, name, "nhiso", _status, _branches);
  utils::setStatus(_tree, name, "phoiso", _status, _branches);
  utils::setStatus(_tree, name, "puiso", _status, _branches);
  utils::setStatus(_tree, name, "tauDecay", _status, _branches);
  utils::setStatus(_tree, name, "hadDecay", _status, _branches);
}

void
panda::PLepton::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticle::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "q", &q, _branches, _setStatus);
  utils::setAddress(_tree, name, "loose", &loose, _branches, _setStatus);
  utils::setAddress(_tree, name, "medium", &medium, _branches, _setStatus);
  utils::setAddress(_tree, name, "tight", &tight, _branches, _setStatus);
  utils::setAddress(_tree, name, "chiso", &chiso, _branches, _setStatus);
  utils::setAddress(_tree, name, "nhiso", &nhiso, _branches, _setStatus);
  utils::setAddress(_tree, name, "phoiso", &phoiso, _branches, _setStatus);
  utils::setAddress(_tree, name, "puiso", &puiso, _branches, _setStatus);
  utils::setAddress(_tree, name, "tauDecay", &tauDecay, _branches, _setStatus);
  utils::setAddress(_tree, name, "hadDecay", &hadDecay, _branches, _setStatus);
}

void
panda::PLepton::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "q", "", 'S', &q, _branches);
  utils::book(_tree, name, "loose", "", 'O', &loose, _branches);
  utils::book(_tree, name, "medium", "", 'O', &medium, _branches);
  utils::book(_tree, name, "tight", "", 'O', &tight, _branches);
  utils::book(_tree, name, "chiso", "", 'F', &chiso, _branches);
  utils::book(_tree, name, "nhiso", "", 'F', &nhiso, _branches);
  utils::book(_tree, name, "phoiso", "", 'F', &phoiso, _branches);
  utils::book(_tree, name, "puiso", "", 'F', &puiso, _branches);
  utils::book(_tree, name, "tauDecay", "", 'O', &tauDecay, _branches);
  utils::book(_tree, name, "hadDecay", "", 'O', &hadDecay, _branches);
}

void
panda::PLepton::resetAddress(TTree& _tree)
{
  PParticle::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "q");
  utils::resetAddress(_tree, name, "loose");
  utils::resetAddress(_tree, name, "medium");
  utils::resetAddress(_tree, name, "tight");
  utils::resetAddress(_tree, name, "chiso");
  utils::resetAddress(_tree, name, "nhiso");
  utils::resetAddress(_tree, name, "phoiso");
  utils::resetAddress(_tree, name, "puiso");
  utils::resetAddress(_tree, name, "tauDecay");
  utils::resetAddress(_tree, name, "hadDecay");
}

void
panda::PLepton::init()
{
  PParticle::init();

  q = 0;
  loose = false;
  medium = false;
  tight = false;
  chiso = 0.;
  nhiso = 0.;
  phoiso = 0.;
  puiso = 0.;
  tauDecay = false;
  hadDecay = false;
}


/* BEGIN CUSTOM */
/* END CUSTOM */
