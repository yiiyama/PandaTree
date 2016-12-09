#include "../interface/PParticleM.h"

void
panda::PParticleM::datastore::allocate(UInt_t _nmax)
{
  PParticle::datastore::allocate(_nmax);

  mass = new Float_t[nmax_];
}

void
panda::PParticleM::datastore::deallocate()
{
  PParticle::datastore::deallocate();

  delete [] mass;
  mass = 0;
}

void
panda::PParticleM::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "mass", _status, _branches);
}

void
panda::PParticleM::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticle::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "mass", mass, _branches, _setStatus);
}

void
panda::PParticleM::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PParticle::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "mass", size, 'F', mass, _branches);
}

void
panda::PParticleM::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  PParticle::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "mass");
}

void
panda::PParticleM::datastore::resizeVectors_(UInt_t _size)
{
  PParticle::datastore::resizeVectors_(_size);

}

panda::PParticleM::PParticleM(char const* _name/* = ""*/) :
  PParticle(new PParticleMArray(1, _name)),
  mass(gStore.getData(this).mass[0])
{
}

panda::PParticleM::PParticleM(datastore& _data, UInt_t _idx) :
  PParticle(_data, _idx),
  mass(_data.mass[_idx])
{
}

panda::PParticleM::PParticleM(PParticleM const& _src) :
  PParticle(new PParticleMArray(1, gStore.getName(&_src))),
  mass(gStore.getData(this).mass[0])
{
  PParticle::operator=(_src);

  mass = _src.mass;
}

panda::PParticleM::PParticleM(ArrayBase* _array) :
  PParticle(_array),
  mass(gStore.getData(this).mass[0])
{
}

panda::PParticleM::~PParticleM()
{
  destructor();
  gStore.free(this);
}

void
panda::PParticleM::destructor()
{
  /* BEGIN CUSTOM PParticleM.cc.destructor */
  /* END CUSTOM */

  PParticle::destructor();
}

panda::PParticleM&
panda::PParticleM::operator=(PParticleM const& _src)
{
  PParticle::operator=(_src);

  mass = _src.mass;

  return *this;
}

void
panda::PParticleM::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "mass", _status, _branches);
}

void
panda::PParticleM::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticle::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "mass", &mass, _branches, _setStatus);
}

void
panda::PParticleM::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "mass", "", 'F', &mass, _branches);
}

void
panda::PParticleM::resetAddress(TTree& _tree)
{
  PParticle::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "mass");
}

void
panda::PParticleM::init()
{
  PParticle::init();

  mass = 0.;
}


/* BEGIN CUSTOM PParticleM.cc.global */
/* END CUSTOM */
