#include "../interface/PTau.h"

void
panda::PTau::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::array_data::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "q", _status, _branches);
  utils::setStatus(_tree, _name, "decayMode", _status, _branches);
  utils::setStatus(_tree, _name, "isoDeltaBetaCorr", _status, _branches);
}

void
panda::PTau::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "q", q, _branches);
  utils::setStatusAndAddress(_tree, _name, "decayMode", decayMode, _branches);
  utils::setStatusAndAddress(_tree, _name, "isoDeltaBetaCorr", isoDeltaBetaCorr, _branches);
}

void
panda::PTau::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "q", "[" + _name + ".size]", 'C', q, _branches);
  utils::book(_tree, _name, "decayMode", "[" + _name + ".size]", 'O', decayMode, _branches);
  utils::book(_tree, _name, "isoDeltaBetaCorr", "[" + _name + ".size]", 'F', isoDeltaBetaCorr, _branches);
}

panda::PTau::PTau(char const* _name/* = ""*/) :
  PParticleM(utils::Allocator<PTau>(), _name),
  q(gStore.getData(this).q[gStore.getIndex(this)]),
  decayMode(gStore.getData(this).decayMode[gStore.getIndex(this)]),
  isoDeltaBetaCorr(gStore.getData(this).isoDeltaBetaCorr[gStore.getIndex(this)])
{
}

panda::PTau::PTau(array_data& _data, UInt_t _idx) :
  PParticleM(_data, _idx),
  q(_data.q[_idx]),
  decayMode(_data.decayMode[_idx]),
  isoDeltaBetaCorr(_data.isoDeltaBetaCorr[_idx])
{
}

panda::PTau::PTau(PTau const& _src) :
  PParticleM(utils::Allocator<PTau>(), gStore.getName(&_src)),
  q(gStore.getData(this).q[gStore.getIndex(this)]),
  decayMode(gStore.getData(this).decayMode[gStore.getIndex(this)]),
  isoDeltaBetaCorr(gStore.getData(this).isoDeltaBetaCorr[gStore.getIndex(this)])
{
  PParticleM::operator=(_src);

  q = _src.q;
  decayMode = _src.decayMode;
  isoDeltaBetaCorr = _src.isoDeltaBetaCorr;
}

panda::PTau::PTau(utils::AllocatorBase const& _allocator, char const* _name) :
  PParticleM(_allocator, _name),
  q(gStore.getData(this).q[gStore.getIndex(this)]),
  decayMode(gStore.getData(this).decayMode[gStore.getIndex(this)]),
  isoDeltaBetaCorr(gStore.getData(this).isoDeltaBetaCorr[gStore.getIndex(this)])
{
}

panda::PTau::~PTau()
{
  gStore.free(this);
}

panda::PTau&
panda::PTau::operator=(PTau const& _src)
{
  PParticleM::operator=(_src);

  q = _src.q;
  decayMode = _src.decayMode;
  isoDeltaBetaCorr = _src.isoDeltaBetaCorr;

  return *this;
}

void
panda::PTau::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "q", _status, _branches);
  utils::setStatus(_tree, name, "decayMode", _status, _branches);
  utils::setStatus(_tree, name, "isoDeltaBetaCorr", _status, _branches);
}

void
panda::PTau::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::setAddress(_tree, _branches);

  TString name(gStore.getName(this));

  utils::setStatusAndAddress(_tree, name, "q", &q, _branches);
  utils::setStatusAndAddress(_tree, name, "decayMode", &decayMode, _branches);
  utils::setStatusAndAddress(_tree, name, "isoDeltaBetaCorr", &isoDeltaBetaCorr, _branches);
}

void
panda::PTau::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "q", "", 'C', &q, _branches);
  utils::book(_tree, name, "decayMode", "", 'O', &decayMode, _branches);
  utils::book(_tree, name, "isoDeltaBetaCorr", "", 'F', &isoDeltaBetaCorr, _branches);
}

void
panda::PTau::init()
{
  PParticleM::init();

  q = 0;
  decayMode = false;
  isoDeltaBetaCorr = 0.;
}

/* BEGIN CUSTOM */
/* END CUSTOM */
