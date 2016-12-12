#include "../interface/ParticleM.h"

void
panda::ParticleM::datastore::allocate(UInt_t _nmax)
{
  Particle::datastore::allocate(_nmax);

  mass = new Float_t[nmax_];
}

void
panda::ParticleM::datastore::deallocate()
{
  Particle::datastore::deallocate();

  delete [] mass;
  mass = 0;
}

void
panda::ParticleM::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  Particle::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "mass", _status, _branches);
}

void
panda::ParticleM::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "mass", mass, _branches, _setStatus);
}

void
panda::ParticleM::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Particle::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "mass", size, 'F', mass, _branches);
}

void
panda::ParticleM::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  Particle::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "mass");
}

void
panda::ParticleM::datastore::resizeVectors_(UInt_t _size)
{
  Particle::datastore::resizeVectors_(_size);

}

panda::ParticleM::ParticleM(char const* _name/* = ""*/) :
  Particle(new ParticleMArray(1, _name)),
  mass(gStore.getData(this).mass[0])
{
}

panda::ParticleM::ParticleM(datastore& _data, UInt_t _idx) :
  Particle(_data, _idx),
  mass(_data.mass[_idx])
{
}

panda::ParticleM::ParticleM(ParticleM const& _src) :
  Particle(new ParticleMArray(1, gStore.getName(&_src))),
  mass(gStore.getData(this).mass[0])
{
  Particle::operator=(_src);

  mass = _src.mass;
}

panda::ParticleM::ParticleM(ArrayBase* _array) :
  Particle(_array),
  mass(gStore.getData(this).mass[0])
{
}

panda::ParticleM::~ParticleM()
{
  destructor();
  gStore.free(this);
}

void
panda::ParticleM::destructor()
{
  /* BEGIN CUSTOM ParticleM.cc.destructor */
  /* END CUSTOM */

  Particle::destructor();
}

panda::ParticleM&
panda::ParticleM::operator=(ParticleM const& _src)
{
  Particle::operator=(_src);

  mass = _src.mass;

  return *this;
}

void
panda::ParticleM::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  Particle::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "mass", _status, _branches);
}

void
panda::ParticleM::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "mass", &mass, _branches, _setStatus);
}

void
panda::ParticleM::book(TTree& _tree, utils::BranchList const& _branches/* = {}*/)
{
  Particle::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "mass", "", 'F', &mass, _branches);
}

void
panda::ParticleM::resetAddress(TTree& _tree)
{
  Particle::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "mass");
}

void
panda::ParticleM::init()
{
  Particle::init();

  mass = 0.;
}


/* BEGIN CUSTOM ParticleM.cc.global */
/* END CUSTOM */
