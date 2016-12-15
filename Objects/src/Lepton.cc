#include "../interface/Lepton.h"

void
panda::Lepton::datastore::allocate(UInt_t _nmax)
{
  Particle::datastore::allocate(_nmax);

  q = new Short_t[nmax_];
  loose = new Bool_t[nmax_];
  medium = new Bool_t[nmax_];
  tight = new Bool_t[nmax_];
  chiso = new Float_t[nmax_];
  nhiso = new Float_t[nmax_];
  phoiso = new Float_t[nmax_];
  puiso = new Float_t[nmax_];
  matchedGen_ = new Int_t[nmax_];
}

void
panda::Lepton::datastore::deallocate()
{
  Particle::datastore::deallocate();

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
  delete [] matchedGen_;
  matchedGen_ = 0;
}

void
panda::Lepton::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  Particle::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "q", _status, _branches);
  utils::setStatus(_tree, _name, "loose", _status, _branches);
  utils::setStatus(_tree, _name, "medium", _status, _branches);
  utils::setStatus(_tree, _name, "tight", _status, _branches);
  utils::setStatus(_tree, _name, "chiso", _status, _branches);
  utils::setStatus(_tree, _name, "nhiso", _status, _branches);
  utils::setStatus(_tree, _name, "phoiso", _status, _branches);
  utils::setStatus(_tree, _name, "puiso", _status, _branches);
  utils::setStatus(_tree, _name, "matchedGen_", _status, _branches);
}

void
panda::Lepton::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "q", q, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose", loose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "medium", medium, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight", tight, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chiso", chiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhiso", nhiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phoiso", phoiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puiso", puiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedGen_", matchedGen_, _branches, _setStatus);
}

void
panda::Lepton::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Particle::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "q", size, 'S', q, _branches);
  utils::book(_tree, _name, "loose", size, 'O', loose, _branches);
  utils::book(_tree, _name, "medium", size, 'O', medium, _branches);
  utils::book(_tree, _name, "tight", size, 'O', tight, _branches);
  utils::book(_tree, _name, "chiso", size, 'F', chiso, _branches);
  utils::book(_tree, _name, "nhiso", size, 'F', nhiso, _branches);
  utils::book(_tree, _name, "phoiso", size, 'F', phoiso, _branches);
  utils::book(_tree, _name, "puiso", size, 'F', puiso, _branches);
  utils::book(_tree, _name, "matchedGen_", size, 'I', matchedGen_, _branches);
}

void
panda::Lepton::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  Particle::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "q");
  utils::resetAddress(_tree, _name, "loose");
  utils::resetAddress(_tree, _name, "medium");
  utils::resetAddress(_tree, _name, "tight");
  utils::resetAddress(_tree, _name, "chiso");
  utils::resetAddress(_tree, _name, "nhiso");
  utils::resetAddress(_tree, _name, "phoiso");
  utils::resetAddress(_tree, _name, "puiso");
  utils::resetAddress(_tree, _name, "matchedGen_");
}

void
panda::Lepton::datastore::resizeVectors_(UInt_t _size)
{
  Particle::datastore::resizeVectors_(_size);

}

panda::Lepton::Lepton(char const* _name/* = ""*/) :
  Particle(new LeptonArray(1, _name)),
  q(gStore.getData(this).q[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  chiso(gStore.getData(this).chiso[0]),
  nhiso(gStore.getData(this).nhiso[0]),
  phoiso(gStore.getData(this).phoiso[0]),
  puiso(gStore.getData(this).puiso[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
}

panda::Lepton::Lepton(datastore& _data, UInt_t _idx) :
  Particle(_data, _idx),
  q(_data.q[_idx]),
  loose(_data.loose[_idx]),
  medium(_data.medium[_idx]),
  tight(_data.tight[_idx]),
  chiso(_data.chiso[_idx]),
  nhiso(_data.nhiso[_idx]),
  phoiso(_data.phoiso[_idx]),
  puiso(_data.puiso[_idx]),
  matchedGen(_data.matchedGenContainer_, _data.matchedGen_[_idx])
{
}

panda::Lepton::Lepton(Lepton const& _src) :
  Particle(new LeptonArray(1, gStore.getName(&_src))),
  q(gStore.getData(this).q[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  chiso(gStore.getData(this).chiso[0]),
  nhiso(gStore.getData(this).nhiso[0]),
  phoiso(gStore.getData(this).phoiso[0]),
  puiso(gStore.getData(this).puiso[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
  Particle::operator=(_src);

  q = _src.q;
  loose = _src.loose;
  medium = _src.medium;
  tight = _src.tight;
  chiso = _src.chiso;
  nhiso = _src.nhiso;
  phoiso = _src.phoiso;
  puiso = _src.puiso;
  matchedGen = _src.matchedGen;
}

panda::Lepton::Lepton(ArrayBase* _array) :
  Particle(_array),
  q(gStore.getData(this).q[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  chiso(gStore.getData(this).chiso[0]),
  nhiso(gStore.getData(this).nhiso[0]),
  phoiso(gStore.getData(this).phoiso[0]),
  puiso(gStore.getData(this).puiso[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
}

panda::Lepton::~Lepton()
{
  destructor();
  gStore.free(this);
}

void
panda::Lepton::destructor()
{
  /* BEGIN CUSTOM Lepton.cc.destructor */
  /* END CUSTOM */

  Particle::destructor();
}

panda::Lepton&
panda::Lepton::operator=(Lepton const& _src)
{
  Particle::operator=(_src);

  q = _src.q;
  loose = _src.loose;
  medium = _src.medium;
  tight = _src.tight;
  chiso = _src.chiso;
  nhiso = _src.nhiso;
  phoiso = _src.phoiso;
  puiso = _src.puiso;
  matchedGen = _src.matchedGen;

  return *this;
}

void
panda::Lepton::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  Particle::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "q", _status, _branches);
  utils::setStatus(_tree, name, "loose", _status, _branches);
  utils::setStatus(_tree, name, "medium", _status, _branches);
  utils::setStatus(_tree, name, "tight", _status, _branches);
  utils::setStatus(_tree, name, "chiso", _status, _branches);
  utils::setStatus(_tree, name, "nhiso", _status, _branches);
  utils::setStatus(_tree, name, "phoiso", _status, _branches);
  utils::setStatus(_tree, name, "puiso", _status, _branches);
  utils::setStatus(_tree, name, "matchedGen_", _status, _branches);
}

void
panda::Lepton::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "q", &q, _branches, _setStatus);
  utils::setAddress(_tree, name, "loose", &loose, _branches, _setStatus);
  utils::setAddress(_tree, name, "medium", &medium, _branches, _setStatus);
  utils::setAddress(_tree, name, "tight", &tight, _branches, _setStatus);
  utils::setAddress(_tree, name, "chiso", &chiso, _branches, _setStatus);
  utils::setAddress(_tree, name, "nhiso", &nhiso, _branches, _setStatus);
  utils::setAddress(_tree, name, "phoiso", &phoiso, _branches, _setStatus);
  utils::setAddress(_tree, name, "puiso", &puiso, _branches, _setStatus);
  utils::setAddress(_tree, name, "matchedGen_", gStore.getData(this).matchedGen_, _branches, true);
}

void
panda::Lepton::book(TTree& _tree, utils::BranchList const& _branches/* = {}*/)
{
  Particle::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "q", "", 'S', &q, _branches);
  utils::book(_tree, name, "loose", "", 'O', &loose, _branches);
  utils::book(_tree, name, "medium", "", 'O', &medium, _branches);
  utils::book(_tree, name, "tight", "", 'O', &tight, _branches);
  utils::book(_tree, name, "chiso", "", 'F', &chiso, _branches);
  utils::book(_tree, name, "nhiso", "", 'F', &nhiso, _branches);
  utils::book(_tree, name, "phoiso", "", 'F', &phoiso, _branches);
  utils::book(_tree, name, "puiso", "", 'F', &puiso, _branches);
  utils::book(_tree, name, "matchedGen_", "", 'I', gStore.getData(this).matchedGen_, _branches);
}

void
panda::Lepton::resetAddress(TTree& _tree)
{
  Particle::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "q");
  utils::resetAddress(_tree, name, "loose");
  utils::resetAddress(_tree, name, "medium");
  utils::resetAddress(_tree, name, "tight");
  utils::resetAddress(_tree, name, "chiso");
  utils::resetAddress(_tree, name, "nhiso");
  utils::resetAddress(_tree, name, "phoiso");
  utils::resetAddress(_tree, name, "puiso");
  utils::resetAddress(_tree, name, "matchedGen_");
}

void
panda::Lepton::init()
{
  Particle::init();

  q = 0;
  loose = false;
  medium = false;
  tight = false;
  chiso = 0.;
  nhiso = 0.;
  phoiso = 0.;
  puiso = 0.;
  matchedGen.init();
}


/* BEGIN CUSTOM Lepton.cc.global */
/* END CUSTOM */
