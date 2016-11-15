#include "../interface/PGenParticle.h"

void
panda::PGenParticle::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::array_data::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "pdgid", _status, _branches);
  utils::setStatus(_tree, _name, "parent_", _status, _branches);
}

void
panda::PGenParticle::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "pdgid", pdgid, _branches);
  utils::setStatusAndAddress(_tree, _name, "parent_", parent_, _branches);
}

void
panda::PGenParticle::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "pdgid", "[" + _name + ".size]", 'I', pdgid, _branches);
  utils::book(_tree, _name, "parent_", "[" + _name + ".size]", 'i', parent_, _branches);
}

panda::PGenParticle::PGenParticle() :
  PObject(utils::Allocator<PGenParticle>()),
  pdgid(gStore.getData(this).pdgid[gStore.getIndex(this)]),
  parent_(gStore.getData(this).parent_[gStore.getIndex(this)])
{
}

panda::PGenParticle::PGenParticle(PGenParticle const& _src) :
  PObject(utils::Allocator<PGenParticle>()),
  pdgid(gStore.getData(this).pdgid[gStore.getIndex(this)]),
  parent_(gStore.getData(this).parent_[gStore.getIndex(this)])
{
  PObject::operator=(_src);

  pdgid = _src.pdgid;
  parent_ = _src.parent_;
}

panda::PGenParticle::PGenParticle(array_data& _data, UInt_t _idx) :
  PObject(_data, _idx),
  pdgid(_data.pdgid[_idx]),
  parent_(_data.parent_[_idx])
{
}

panda::PGenParticle::PGenParticle(utils::AllocatorBase const& _allocator) :
  PObject(_allocator),
  pdgid(gStore.getData(this).pdgid[gStore.getIndex(this)]),
  parent_(gStore.getData(this).parent_[gStore.getIndex(this)])
{
}

panda::PGenParticle::~PGenParticle()
{
  gStore.free(this);
}

panda::PGenParticle&
panda::PGenParticle::operator=(PGenParticle const& _src)
{
  PObject::operator=(_src);

  pdgid = _src.pdgid;
  parent_ = _src.parent_;

  return *this;
}

void
panda::PGenParticle::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "pdgid", _status, _branches);
  utils::setStatus(_tree, _name, "parent_", _status, _branches);
}

void
panda::PGenParticle::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "pdgid", &pdgid, _branches);
  utils::setStatusAndAddress(_tree, _name, "parent_", &parent_, _branches);
}

void
panda::PGenParticle::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::book(_tree, _name, _branches);

  utils::book(_tree, _name, "pdgid", "", 'I', &pdgid, _branches);
  utils::book(_tree, _name, "parent_", "", 'i', &parent_, _branches);
}

void
panda::PGenParticle::init()
{
  PObject::init();

  pdgid = 0;
  parent_ = PGenParticle::array_data::NMAX;
}

/* BEGIN CUSTOM */
/* END CUSTOM */
