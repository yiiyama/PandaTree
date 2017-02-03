#include "../interface/GenJet.h"

void
panda::GenJet::datastore::allocate(UInt_t _nmax)
{
  ParticleM::datastore::allocate(_nmax);

  pdgid = new UShort_t[nmax_];
}

void
panda::GenJet::datastore::deallocate()
{
  ParticleM::datastore::deallocate();

  delete [] pdgid;
  pdgid = 0;
}

void
panda::GenJet::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ParticleM::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "pdgid", _branches);
}

void
panda::GenJet::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "pdgid", pdgid, _branches, _setStatus);
}

void
panda::GenJet::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "pdgid", size, 's', pdgid, _branches);
}

void
panda::GenJet::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  ParticleM::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "pdgid");
}

void
panda::GenJet::datastore::resizeVectors_(UInt_t _size)
{
  ParticleM::datastore::resizeVectors_(_size);

}

panda::GenJet::GenJet(char const* _name/* = ""*/) :
  ParticleM(new GenJetArray(1, _name)),
  pdgid(gStore.getData(this).pdgid[0])
{
}

panda::GenJet::GenJet(datastore& _data, UInt_t _idx) :
  ParticleM(_data, _idx),
  pdgid(_data.pdgid[_idx])
{
}

panda::GenJet::GenJet(GenJet const& _src) :
  ParticleM(new GenJetArray(1, gStore.getName(&_src))),
  pdgid(gStore.getData(this).pdgid[0])
{
  ParticleM::operator=(_src);

  pdgid = _src.pdgid;
}

panda::GenJet::GenJet(ArrayBase* _array) :
  ParticleM(_array),
  pdgid(gStore.getData(this).pdgid[0])
{
}

panda::GenJet::~GenJet()
{
  destructor();
  gStore.free(this);
}

void
panda::GenJet::destructor()
{
  /* BEGIN CUSTOM GenJet.cc.destructor */
  /* END CUSTOM */

  ParticleM::destructor();
}

panda::GenJet&
panda::GenJet::operator=(GenJet const& _src)
{
  ParticleM::operator=(_src);

  pdgid = _src.pdgid;

  return *this;
}

void
panda::GenJet::setStatus(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  ParticleM::setStatus(_tree, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "pdgid", _branches);
}

UInt_t
panda::GenJet::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "pdgid", &pdgid, _branches, _setStatus);

  return -1;
}

UInt_t
panda::GenJet::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  ParticleM::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "pdgid", "", 's', &pdgid, _branches);

  return -1;
}

void
panda::GenJet::releaseTree(TTree& _tree)
{
  ParticleM::releaseTree(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "pdgid");
}

void
panda::GenJet::init()
{
  ParticleM::init();

  pdgid = 0;
}

/* BEGIN CUSTOM GenJet.cc.global */
/* END CUSTOM */
