#include "../interface/PGenJet.h"

void
panda::PGenJet::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::array_data::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "pdgid", _status, _branches);
}

void
panda::PGenJet::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "pdgid", pdgid, _branches);
}

void
panda::PGenJet::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "pdgid", "[" + _name + ".size]", 'I', pdgid, _branches);
}

panda::PGenJet::PGenJet() :
  PParticleM(utils::Allocator<PGenJet>()),
  pdgid(gStore.getData(this).pdgid[gStore.getIndex(this)])
{
}

panda::PGenJet::PGenJet(PGenJet const& _src) :
  PParticleM(utils::Allocator<PGenJet>()),
  pdgid(gStore.getData(this).pdgid[gStore.getIndex(this)])
{
  PParticleM::operator=(_src);

  pdgid = _src.pdgid;
}

panda::PGenJet::PGenJet(array_data& _data, UInt_t _idx) :
  PParticleM(_data, _idx),
  pdgid(_data.pdgid[_idx])
{
}

panda::PGenJet::PGenJet(utils::AllocatorBase const& _allocator) :
  PParticleM(_allocator),
  pdgid(gStore.getData(this).pdgid[gStore.getIndex(this)])
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
panda::PGenJet::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "pdgid", _status, _branches);
}

void
panda::PGenJet::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "pdgid", &pdgid, _branches);
}

void
panda::PGenJet::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::book(_tree, _name, _branches);

  utils::book(_tree, _name, "pdgid", "", 'I', &pdgid, _branches);
}

void
panda::PGenJet::init()
{
  PParticleM::init();

  pdgid = 0;
}

/* BEGIN CUSTOM */
/* END CUSTOM */
