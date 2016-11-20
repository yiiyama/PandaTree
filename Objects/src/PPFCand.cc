#include "../interface/PPFCand.h"

void
panda::PPFCand::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::array_data::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "q", _status, _branches);
  utils::setStatus(_tree, _name, "weight", _status, _branches);
  utils::setStatus(_tree, _name, "pftype", _status, _branches);
}

void
panda::PPFCand::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "q", q, _branches);
  utils::setStatusAndAddress(_tree, _name, "weight", weight, _branches);
  utils::setStatusAndAddress(_tree, _name, "pftype", pftype, _branches);
}

void
panda::PPFCand::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "q", "[" + _name + ".size]", 'F', q, _branches);
  utils::book(_tree, _name, "weight", "[" + _name + ".size]", 'F', weight, _branches);
  utils::book(_tree, _name, "pftype", "[" + _name + ".size]", 'I', pftype, _branches);
}

panda::PPFCand::PPFCand() :
  PParticleM(utils::Allocator<PPFCand>()),
  q(gStore.getData(this).q[gStore.getIndex(this)]),
  weight(gStore.getData(this).weight[gStore.getIndex(this)]),
  pftype(gStore.getData(this).pftype[gStore.getIndex(this)])
{
}

panda::PPFCand::PPFCand(PPFCand const& _src) :
  PParticleM(utils::Allocator<PPFCand>()),
  q(gStore.getData(this).q[gStore.getIndex(this)]),
  weight(gStore.getData(this).weight[gStore.getIndex(this)]),
  pftype(gStore.getData(this).pftype[gStore.getIndex(this)])
{
  PParticleM::operator=(_src);

  q = _src.q;
  weight = _src.weight;
  pftype = _src.pftype;
}

panda::PPFCand::PPFCand(array_data& _data, UInt_t _idx) :
  PParticleM(_data, _idx),
  q(_data.q[_idx]),
  weight(_data.weight[_idx]),
  pftype(_data.pftype[_idx])
{
}

panda::PPFCand::PPFCand(utils::AllocatorBase const& _allocator) :
  PParticleM(_allocator),
  q(gStore.getData(this).q[gStore.getIndex(this)]),
  weight(gStore.getData(this).weight[gStore.getIndex(this)]),
  pftype(gStore.getData(this).pftype[gStore.getIndex(this)])
{
}

panda::PPFCand::~PPFCand()
{
  gStore.free(this);
}

panda::PPFCand&
panda::PPFCand::operator=(PPFCand const& _src)
{
  PParticleM::operator=(_src);

  q = _src.q;
  weight = _src.weight;
  pftype = _src.pftype;

  return *this;
}

void
panda::PPFCand::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "q", _status, _branches);
  utils::setStatus(_tree, _name, "weight", _status, _branches);
  utils::setStatus(_tree, _name, "pftype", _status, _branches);
}

void
panda::PPFCand::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "q", &q, _branches);
  utils::setStatusAndAddress(_tree, _name, "weight", &weight, _branches);
  utils::setStatusAndAddress(_tree, _name, "pftype", &pftype, _branches);
}

void
panda::PPFCand::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::book(_tree, _name, _branches);

  utils::book(_tree, _name, "q", "", 'F', &q, _branches);
  utils::book(_tree, _name, "weight", "", 'F', &weight, _branches);
  utils::book(_tree, _name, "pftype", "", 'I', &pftype, _branches);
}

void
panda::PPFCand::init()
{
  PParticleM::init();

  q = 0.;
  weight = 0.;
  pftype = 0;
}

/* BEGIN CUSTOM */
/* END CUSTOM */
