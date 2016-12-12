#include "../interface/GenParticle.h"

void
panda::GenParticle::datastore::allocate(UInt_t _nmax)
{
  ParticleM::datastore::allocate(_nmax);

  pdgid = new Int_t[nmax_];
  parent_ = new UInt_t[nmax_];
}

void
panda::GenParticle::datastore::deallocate()
{
  ParticleM::datastore::deallocate();

  delete [] pdgid;
  pdgid = 0;
  delete [] parent_;
  parent_ = 0;
}

void
panda::GenParticle::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  ParticleM::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "pdgid", _status, _branches);
  utils::setStatus(_tree, _name, "parent_", _status, _branches);
}

void
panda::GenParticle::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "pdgid", pdgid, _branches, _setStatus);
  utils::setAddress(_tree, _name, "parent_", parent_, _branches, _setStatus);
}

void
panda::GenParticle::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "pdgid", size, 'I', pdgid, _branches);
  utils::book(_tree, _name, "parent_", size, 'i', parent_, _branches);
}

void
panda::GenParticle::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  ParticleM::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "pdgid");
  utils::resetAddress(_tree, _name, "parent_");
}

void
panda::GenParticle::datastore::resizeVectors_(UInt_t _size)
{
  ParticleM::datastore::resizeVectors_(_size);

}

panda::GenParticle::GenParticle(char const* _name/* = ""*/) :
  ParticleM(new GenParticleArray(1, _name)),
  pdgid(gStore.getData(this).pdgid[0]),
  parent(gStore.getData(this).parentContainer_, gStore.getData(this).parent_[0])
{
}

panda::GenParticle::GenParticle(datastore& _data, UInt_t _idx) :
  ParticleM(_data, _idx),
  pdgid(_data.pdgid[_idx]),
  parent(_data.parentContainer_, _data.parent_[_idx])
{
}

panda::GenParticle::GenParticle(GenParticle const& _src) :
  ParticleM(new GenParticleArray(1, gStore.getName(&_src))),
  pdgid(gStore.getData(this).pdgid[0]),
  parent(gStore.getData(this).parentContainer_, gStore.getData(this).parent_[0])
{
  ParticleM::operator=(_src);

  pdgid = _src.pdgid;
  parent = _src.parent;
}

panda::GenParticle::GenParticle(ArrayBase* _array) :
  ParticleM(_array),
  pdgid(gStore.getData(this).pdgid[0]),
  parent(gStore.getData(this).parentContainer_, gStore.getData(this).parent_[0])
{
}

panda::GenParticle::~GenParticle()
{
  destructor();
  gStore.free(this);
}

void
panda::GenParticle::destructor()
{
  /* BEGIN CUSTOM GenParticle.cc.destructor */
  /* END CUSTOM */

  ParticleM::destructor();
}

panda::GenParticle&
panda::GenParticle::operator=(GenParticle const& _src)
{
  ParticleM::operator=(_src);

  pdgid = _src.pdgid;
  parent = _src.parent;

  return *this;
}

void
panda::GenParticle::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  ParticleM::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "pdgid", _status, _branches);
  utils::setStatus(_tree, name, "parent_", _status, _branches);
}

void
panda::GenParticle::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "pdgid", &pdgid, _branches, _setStatus);
  utils::setAddress(_tree, name, "parent_", gStore.getData(this).parent_, _branches, true);
}

void
panda::GenParticle::book(TTree& _tree, utils::BranchList const& _branches/* = {}*/)
{
  ParticleM::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "pdgid", "", 'I', &pdgid, _branches);
  utils::book(_tree, name, "parent_", "", 'i', gStore.getData(this).parent_, _branches);
}

void
panda::GenParticle::resetAddress(TTree& _tree)
{
  ParticleM::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "pdgid");
  utils::resetAddress(_tree, name, "parent_");
}

void
panda::GenParticle::init()
{
  ParticleM::init();

  pdgid = 0;
  parent.init();
}

/* BEGIN CUSTOM GenParticle.cc.global */
/* END CUSTOM */
