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
panda::ParticleM::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Particle::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "mass", _branches);
}

void
panda::ParticleM::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "mass", mass, _branches, _setStatus);
}

void
panda::ParticleM::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Particle::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "mass", size, 'F', mass, _branches);
}

void
panda::ParticleM::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Particle::datastore::releaseTree(_tree, _name);

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
panda::ParticleM::doSetStatus_(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Particle::doSetStatus_(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "mass", _branches);
}

void
panda::ParticleM::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::doSetAddress_(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "mass", &mass, _branches, _setStatus);
}

void
panda::ParticleM::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  Particle::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "mass", "", 'F', &mass, _branches);
}

void
panda::ParticleM::doReleaseTree_(TTree& _tree, TString const& _name)
{
  Particle::doReleaseTree_(_tree, _name);

  utils::resetAddress(_tree, _name, "mass");
}

void
panda::ParticleM::doInit_()
{
  Particle::doInit_();

  mass = 0.;
}

void
panda::ParticleM::setXYZE(double px, double py, double pz, double e)
{
  pt = std::sqrt(px * px + py * py);
  double p(std::sqrt(px * px + py * py + pz * pz));
  eta = 0.5 * std::log((p + pz) / (p - pz));
  phi = std::atan2(py, px);
  mass = std::sqrt(e * e - p * p);
}


/* BEGIN CUSTOM ParticleM.cc.global */
/* END CUSTOM */
