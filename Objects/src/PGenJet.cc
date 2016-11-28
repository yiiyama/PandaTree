#include "../interface/PGenJet.h"

void
panda::PGenJet::datastore::allocate(UInt_t _nmax)
{
  PParticleM::datastore::allocate(_nmax);

  pdgid = new Int_t[nmax_];
}

void
panda::PGenJet::datastore::deallocate()
{
  PParticleM::datastore::deallocate();

  delete [] pdgid;
  pdgid = 0;
}

void
panda::PGenJet::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "pdgid", _status, _branches);
}

void
panda::PGenJet::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "pdgid", pdgid, _branches, _setStatus);
}

void
panda::PGenJet::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "pdgid", size, 'I', pdgid, _branches);
}

panda::PGenJet::PGenJet(char const* _name/* = ""*/) :
  PParticleM(new PGenJetArray(1, _name)),
  pdgid(gStore.getData(this).pdgid[0])
{
}

panda::PGenJet::PGenJet(datastore& _data, UInt_t _idx) :
  PParticleM(_data, _idx),
  pdgid(_data.pdgid[_idx])
{
}

panda::PGenJet::PGenJet(PGenJet const& _src) :
  PParticleM(new PGenJetArray(1, gStore.getName(&_src))),
  pdgid(gStore.getData(this).pdgid[0])
{
  PParticleM::operator=(_src);


  pdgid = _src.pdgid;
}

panda::PGenJet::PGenJet(ArrayBase* _array) :
  PParticleM(_array),
  pdgid(gStore.getData(this).pdgid[0])
{
}

panda::PGenJet::~PGenJet()
{
  gStore.free(this);
}

panda::PGenJet&
panda::PGenJet::operator=(PGenJet const& _src)
{
  PParticleM::operator=(_src);

  pdgid = _src.pdgid;

  return *this;
}

void
panda::PGenJet::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "pdgid", _status, _branches);
}

void
panda::PGenJet::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticleM::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "pdgid", &pdgid, _branches, _setStatus);
}

void
panda::PGenJet::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "pdgid", "", 'I', &pdgid, _branches);
}

void
panda::PGenJet::init()
{
  PParticleM::init();

  pdgid = 0;
}

/* BEGIN CUSTOM */
/* END CUSTOM */
