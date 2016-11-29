#include "../interface/PTau.h"

void
panda::PTau::datastore::allocate(UInt_t _nmax)
{
  PParticleM::datastore::allocate(_nmax);

  q = new Text_t const*[nmax_];
  decayMode = new Bool_t[nmax_];
  isoDeltaBetaCorr = new Float_t[nmax_];
}

void
panda::PTau::datastore::deallocate()
{
  PParticleM::datastore::deallocate();

  delete [] q;
  q = 0;
  delete [] decayMode;
  decayMode = 0;
  delete [] isoDeltaBetaCorr;
  isoDeltaBetaCorr = 0;
}

void
panda::PTau::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "q", _status, _branches);
  utils::setStatus(_tree, _name, "decayMode", _status, _branches);
  utils::setStatus(_tree, _name, "isoDeltaBetaCorr", _status, _branches);
}

void
panda::PTau::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "q", q, _branches, _setStatus);
  utils::setAddress(_tree, _name, "decayMode", decayMode, _branches, _setStatus);
  utils::setAddress(_tree, _name, "isoDeltaBetaCorr", isoDeltaBetaCorr, _branches, _setStatus);
}

void
panda::PTau::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "q", size, 'C', q, _branches);
  utils::book(_tree, _name, "decayMode", size, 'O', decayMode, _branches);
  utils::book(_tree, _name, "isoDeltaBetaCorr", size, 'F', isoDeltaBetaCorr, _branches);
}

void
panda::PTau::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  PParticleM::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "q");
  utils::resetAddress(_tree, _name, "decayMode");
  utils::resetAddress(_tree, _name, "isoDeltaBetaCorr");
}

void
panda::PTau::datastore::resizeVectors_(UInt_t _size)
{
  PParticleM::datastore::resizeVectors_(_size);

}

panda::PTau::PTau(char const* _name/* = ""*/) :
  PParticleM(new PTauArray(1, _name)),
  q(gStore.getData(this).q[0]),
  decayMode(gStore.getData(this).decayMode[0]),
  isoDeltaBetaCorr(gStore.getData(this).isoDeltaBetaCorr[0])
{
}

panda::PTau::PTau(datastore& _data, UInt_t _idx) :
  PParticleM(_data, _idx),
  q(_data.q[_idx]),
  decayMode(_data.decayMode[_idx]),
  isoDeltaBetaCorr(_data.isoDeltaBetaCorr[_idx])
{
}

panda::PTau::PTau(PTau const& _src) :
  PParticleM(new PTauArray(1, gStore.getName(&_src))),
  q(gStore.getData(this).q[0]),
  decayMode(gStore.getData(this).decayMode[0]),
  isoDeltaBetaCorr(gStore.getData(this).isoDeltaBetaCorr[0])
{
  PParticleM::operator=(_src);

  q = _src.q;
  decayMode = _src.decayMode;
  isoDeltaBetaCorr = _src.isoDeltaBetaCorr;
}

panda::PTau::PTau(ArrayBase* _array) :
  PParticleM(_array),
  q(gStore.getData(this).q[0]),
  decayMode(gStore.getData(this).decayMode[0]),
  isoDeltaBetaCorr(gStore.getData(this).isoDeltaBetaCorr[0])
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
panda::PTau::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticleM::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "q", &q, _branches, _setStatus);
  utils::setAddress(_tree, name, "decayMode", &decayMode, _branches, _setStatus);
  utils::setAddress(_tree, name, "isoDeltaBetaCorr", &isoDeltaBetaCorr, _branches, _setStatus);
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
panda::PTau::resetAddress(TTree& _tree)
{
  PParticleM::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "q");
  utils::resetAddress(_tree, name, "decayMode");
  utils::resetAddress(_tree, name, "isoDeltaBetaCorr");
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
