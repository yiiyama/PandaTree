#include "../interface/PLepton.h"

void
panda::PLepton::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::array_data::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "q", _status, _branches);
  utils::setStatus(_tree, _name, "loose", _status, _branches);
  utils::setStatus(_tree, _name, "tight", _status, _branches);
  utils::setStatus(_tree, _name, "chiso", _status, _branches);
  utils::setStatus(_tree, _name, "nhiso", _status, _branches);
  utils::setStatus(_tree, _name, "phoiso", _status, _branches);
  utils::setStatus(_tree, _name, "puiso", _status, _branches);
  utils::setStatus(_tree, _name, "tauDecay", _status, _branches);
  utils::setStatus(_tree, _name, "hadDecay", _status, _branches);
}

void
panda::PLepton::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "q", q, _branches);
  utils::setStatusAndAddress(_tree, _name, "loose", loose, _branches);
  utils::setStatusAndAddress(_tree, _name, "tight", tight, _branches);
  utils::setStatusAndAddress(_tree, _name, "chiso", chiso, _branches);
  utils::setStatusAndAddress(_tree, _name, "nhiso", nhiso, _branches);
  utils::setStatusAndAddress(_tree, _name, "phoiso", phoiso, _branches);
  utils::setStatusAndAddress(_tree, _name, "puiso", puiso, _branches);
  utils::setStatusAndAddress(_tree, _name, "tauDecay", tauDecay, _branches);
  utils::setStatusAndAddress(_tree, _name, "hadDecay", hadDecay, _branches);
}

void
panda::PLepton::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "q", "[" + _name + ".size]", 'C', q, _branches);
  utils::book(_tree, _name, "loose", "[" + _name + ".size]", 'O', loose, _branches);
  utils::book(_tree, _name, "tight", "[" + _name + ".size]", 'O', tight, _branches);
  utils::book(_tree, _name, "chiso", "[" + _name + ".size]", 'F', chiso, _branches);
  utils::book(_tree, _name, "nhiso", "[" + _name + ".size]", 'F', nhiso, _branches);
  utils::book(_tree, _name, "phoiso", "[" + _name + ".size]", 'F', phoiso, _branches);
  utils::book(_tree, _name, "puiso", "[" + _name + ".size]", 'F', puiso, _branches);
  utils::book(_tree, _name, "tauDecay", "[" + _name + ".size]", 'O', tauDecay, _branches);
  utils::book(_tree, _name, "hadDecay", "[" + _name + ".size]", 'O', hadDecay, _branches);
}

panda::PLepton::PLepton(char const* _name/* = ""*/) :
  PParticle(utils::Allocator<PLepton>(), _name),
  q(gStore.getData(this).q[gStore.getIndex(this)]),
  loose(gStore.getData(this).loose[gStore.getIndex(this)]),
  tight(gStore.getData(this).tight[gStore.getIndex(this)]),
  chiso(gStore.getData(this).chiso[gStore.getIndex(this)]),
  nhiso(gStore.getData(this).nhiso[gStore.getIndex(this)]),
  phoiso(gStore.getData(this).phoiso[gStore.getIndex(this)]),
  puiso(gStore.getData(this).puiso[gStore.getIndex(this)]),
  tauDecay(gStore.getData(this).tauDecay[gStore.getIndex(this)]),
  hadDecay(gStore.getData(this).hadDecay[gStore.getIndex(this)])
{
}

panda::PLepton::PLepton(array_data& _data, UInt_t _idx) :
  PParticle(_data, _idx),
  q(_data.q[_idx]),
  loose(_data.loose[_idx]),
  tight(_data.tight[_idx]),
  chiso(_data.chiso[_idx]),
  nhiso(_data.nhiso[_idx]),
  phoiso(_data.phoiso[_idx]),
  puiso(_data.puiso[_idx]),
  tauDecay(_data.tauDecay[_idx]),
  hadDecay(_data.hadDecay[_idx])
{
}

panda::PLepton::PLepton(PLepton const& _src) :
  PParticle(utils::Allocator<PLepton>(), gStore.getName(&_src)),
  q(gStore.getData(this).q[gStore.getIndex(this)]),
  loose(gStore.getData(this).loose[gStore.getIndex(this)]),
  tight(gStore.getData(this).tight[gStore.getIndex(this)]),
  chiso(gStore.getData(this).chiso[gStore.getIndex(this)]),
  nhiso(gStore.getData(this).nhiso[gStore.getIndex(this)]),
  phoiso(gStore.getData(this).phoiso[gStore.getIndex(this)]),
  puiso(gStore.getData(this).puiso[gStore.getIndex(this)]),
  tauDecay(gStore.getData(this).tauDecay[gStore.getIndex(this)]),
  hadDecay(gStore.getData(this).hadDecay[gStore.getIndex(this)])
{
  PParticle::operator=(_src);

  q = _src.q;
  loose = _src.loose;
  tight = _src.tight;
  chiso = _src.chiso;
  nhiso = _src.nhiso;
  phoiso = _src.phoiso;
  puiso = _src.puiso;
  tauDecay = _src.tauDecay;
  hadDecay = _src.hadDecay;
}

panda::PLepton::PLepton(utils::AllocatorBase const& _allocator, char const* _name) :
  PParticle(_allocator, _name),
  q(gStore.getData(this).q[gStore.getIndex(this)]),
  loose(gStore.getData(this).loose[gStore.getIndex(this)]),
  tight(gStore.getData(this).tight[gStore.getIndex(this)]),
  chiso(gStore.getData(this).chiso[gStore.getIndex(this)]),
  nhiso(gStore.getData(this).nhiso[gStore.getIndex(this)]),
  phoiso(gStore.getData(this).phoiso[gStore.getIndex(this)]),
  puiso(gStore.getData(this).puiso[gStore.getIndex(this)]),
  tauDecay(gStore.getData(this).tauDecay[gStore.getIndex(this)]),
  hadDecay(gStore.getData(this).hadDecay[gStore.getIndex(this)])
{
}

panda::PLepton::~PLepton()
{
  gStore.free(this);
}

panda::PLepton&
panda::PLepton::operator=(PLepton const& _src)
{
  PParticle::operator=(_src);

  q = _src.q;
  loose = _src.loose;
  tight = _src.tight;
  chiso = _src.chiso;
  nhiso = _src.nhiso;
  phoiso = _src.phoiso;
  puiso = _src.puiso;
  tauDecay = _src.tauDecay;
  hadDecay = _src.hadDecay;

  return *this;
}

void
panda::PLepton::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "q", _status, _branches);
  utils::setStatus(_tree, name, "loose", _status, _branches);
  utils::setStatus(_tree, name, "tight", _status, _branches);
  utils::setStatus(_tree, name, "chiso", _status, _branches);
  utils::setStatus(_tree, name, "nhiso", _status, _branches);
  utils::setStatus(_tree, name, "phoiso", _status, _branches);
  utils::setStatus(_tree, name, "puiso", _status, _branches);
  utils::setStatus(_tree, name, "tauDecay", _status, _branches);
  utils::setStatus(_tree, name, "hadDecay", _status, _branches);
}

void
panda::PLepton::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::setAddress(_tree, _branches);

  TString name(gStore.getName(this));

  utils::setStatusAndAddress(_tree, name, "q", &q, _branches);
  utils::setStatusAndAddress(_tree, name, "loose", &loose, _branches);
  utils::setStatusAndAddress(_tree, name, "tight", &tight, _branches);
  utils::setStatusAndAddress(_tree, name, "chiso", &chiso, _branches);
  utils::setStatusAndAddress(_tree, name, "nhiso", &nhiso, _branches);
  utils::setStatusAndAddress(_tree, name, "phoiso", &phoiso, _branches);
  utils::setStatusAndAddress(_tree, name, "puiso", &puiso, _branches);
  utils::setStatusAndAddress(_tree, name, "tauDecay", &tauDecay, _branches);
  utils::setStatusAndAddress(_tree, name, "hadDecay", &hadDecay, _branches);
}

void
panda::PLepton::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "q", "", 'C', &q, _branches);
  utils::book(_tree, name, "loose", "", 'O', &loose, _branches);
  utils::book(_tree, name, "tight", "", 'O', &tight, _branches);
  utils::book(_tree, name, "chiso", "", 'F', &chiso, _branches);
  utils::book(_tree, name, "nhiso", "", 'F', &nhiso, _branches);
  utils::book(_tree, name, "phoiso", "", 'F', &phoiso, _branches);
  utils::book(_tree, name, "puiso", "", 'F', &puiso, _branches);
  utils::book(_tree, name, "tauDecay", "", 'O', &tauDecay, _branches);
  utils::book(_tree, name, "hadDecay", "", 'O', &hadDecay, _branches);
}

void
panda::PLepton::init()
{
  PParticle::init();

  q = 0;
  loose = false;
  tight = false;
  chiso = 0.;
  nhiso = 0.;
  phoiso = 0.;
  puiso = 0.;
  tauDecay = false;
  hadDecay = false;
}


/* BEGIN CUSTOM */
/* END CUSTOM */
