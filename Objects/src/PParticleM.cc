#include "../interface/PParticleM.h"

void
panda::PParticleM::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::array_data::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "mass", _status, _branches);
}

void
panda::PParticleM::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "mass", mass, _branches);
}

void
panda::PParticleM::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "mass", "[" + _name + ".size]", 'F', mass, _branches);
}

panda::PParticleM::PParticleM() :
  PParticle(utils::Allocator<PParticleM>()),
  mass(gStore.getData(this).mass[gStore.getIndex(this)])
{
}

panda::PParticleM::PParticleM(PParticleM const& _src) :
  PParticle(utils::Allocator<PParticleM>()),
  mass(gStore.getData(this).mass[gStore.getIndex(this)])
{
  PParticle::operator=(_src);

  mass = _src.mass;
}

panda::PParticleM::PParticleM(array_data& _data, UInt_t _idx) :
  PParticle(_data, _idx),
  mass(_data.mass[_idx])
{
}

panda::PParticleM::PParticleM(utils::AllocatorBase const& _allocator) :
  PParticle(_allocator),
  mass(gStore.getData(this).mass[gStore.getIndex(this)])
{
}

panda::PParticleM::~PParticleM()
{
  gStore.free(this);
}

panda::PParticleM&
panda::PParticleM::operator=(PParticleM const& _src)
{
  PParticle::operator=(_src);

  mass = _src.mass;

  return *this;
}

void
panda::PParticleM::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "mass", _status, _branches);
}

void
panda::PParticleM::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "mass", &mass, _branches);
}

void
panda::PParticleM::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::book(_tree, _name, _branches);

  utils::book(_tree, _name, "mass", "", 'F', &mass, _branches);
}

void
panda::PParticleM::init()
{
  PParticle::init();

  mass = 0.;
}


/* BEGIN CUSTOM */
/* END CUSTOM */
