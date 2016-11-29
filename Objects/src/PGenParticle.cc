#include "../interface/PGenParticle.h"

void
panda::PGenParticle::datastore::allocate(UInt_t _nmax)
{
  PParticleM::datastore::allocate(_nmax);

  pdgid = new Int_t[nmax_];
  parent_ = new UInt_t[nmax_];
}

void
panda::PGenParticle::datastore::deallocate()
{
  PParticleM::datastore::deallocate();

  delete [] pdgid;
  pdgid = 0;
  delete [] parent_;
  parent_ = 0;
}

void
panda::PGenParticle::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "pdgid", _status, _branches);
  utils::setStatus(_tree, _name, "parent_", _status, _branches);
}

void
panda::PGenParticle::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "pdgid", pdgid, _branches, _setStatus);
  utils::setAddress(_tree, _name, "parent_", parent_, _branches, _setStatus);
}

void
panda::PGenParticle::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "pdgid", size, 'I', pdgid, _branches);
  utils::book(_tree, _name, "parent_", size, 'i', parent_, _branches);
}

void
panda::PGenParticle::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  PParticleM::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "pdgid");
  utils::resetAddress(_tree, _name, "parent_");
}

void
panda::PGenParticle::datastore::resizeVectors_(UInt_t _size)
{
  PParticleM::datastore::resizeVectors_(_size);

}

panda::PGenParticle::PGenParticle(char const* _name/* = ""*/) :
  PParticleM(new PGenParticleArray(1, _name)),
  pdgid(gStore.getData(this).pdgid[0]),
  parent(gStore.getData(this).parent_[0])
{
}

panda::PGenParticle::PGenParticle(datastore& _data, UInt_t _idx) :
  PParticleM(_data, _idx),
  pdgid(_data.pdgid[_idx]),
  parent(_data.parent_[_idx])
{
}

panda::PGenParticle::PGenParticle(PGenParticle const& _src) :
  PParticleM(new PGenParticleArray(1, gStore.getName(&_src))),
  pdgid(gStore.getData(this).pdgid[0]),
  parent(gStore.getData(this).parent_[0])
{
  PParticleM::operator=(_src);

  pdgid = _src.pdgid;
  parent = _src.parent;
}

panda::PGenParticle::PGenParticle(ArrayBase* _array) :
  PParticleM(_array),
  pdgid(gStore.getData(this).pdgid[0]),
  parent(gStore.getData(this).parent_[0])
{
}

panda::PGenParticle::~PGenParticle()
{
  gStore.free(this);
}

panda::PGenParticle&
panda::PGenParticle::operator=(PGenParticle const& _src)
{
  PParticleM::operator=(_src);

  pdgid = _src.pdgid;
  parent = _src.parent;

  return *this;
}

void
panda::PGenParticle::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "pdgid", _status, _branches);
  utils::setStatus(_tree, name, "parent_", _status, _branches);
}

void
panda::PGenParticle::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticleM::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "pdgid", &pdgid, _branches, _setStatus);
  utils::setAddress(_tree, name, "parent_", gStore.getData(this).parent_, _branches, true);
}

void
panda::PGenParticle::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "pdgid", "", 'I', &pdgid, _branches);
  utils::book(_tree, name, "parent_", "", 'i', gStore.getData(this).parent_, _branches);
}

void
panda::PGenParticle::resetAddress(TTree& _tree)
{
  PParticleM::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "pdgid");
  utils::resetAddress(_tree, name, "parent_");
}

void
panda::PGenParticle::init()
{
  PParticleM::init();

  pdgid = 0;
  parent.init();
}

/* BEGIN CUSTOM */
/* END CUSTOM */
