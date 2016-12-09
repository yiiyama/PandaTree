#include "../interface/PTau.h"

void
panda::PTau::datastore::allocate(UInt_t _nmax)
{
  PParticleM::datastore::allocate(_nmax);

  q = new Short_t[nmax_];
  baseline = new Bool_t[nmax_];
  decayMode = new Bool_t[nmax_];
  decayModeNew = new Bool_t[nmax_];
  iso = new Float_t[nmax_];
  isoDeltaBetaCorr = new Float_t[nmax_];
  matchedGen_ = new UInt_t[nmax_];
}

void
panda::PTau::datastore::deallocate()
{
  PParticleM::datastore::deallocate();

  delete [] q;
  q = 0;
  delete [] baseline;
  baseline = 0;
  delete [] decayMode;
  decayMode = 0;
  delete [] decayModeNew;
  decayModeNew = 0;
  delete [] iso;
  iso = 0;
  delete [] isoDeltaBetaCorr;
  isoDeltaBetaCorr = 0;
  delete [] matchedGen_;
  matchedGen_ = 0;
}

void
panda::PTau::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "q", _status, _branches);
  utils::setStatus(_tree, _name, "baseline", _status, _branches);
  utils::setStatus(_tree, _name, "decayMode", _status, _branches);
  utils::setStatus(_tree, _name, "decayModeNew", _status, _branches);
  utils::setStatus(_tree, _name, "iso", _status, _branches);
  utils::setStatus(_tree, _name, "isoDeltaBetaCorr", _status, _branches);
  utils::setStatus(_tree, _name, "matchedGen_", _status, _branches);
}

void
panda::PTau::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "q", q, _branches, _setStatus);
  utils::setAddress(_tree, _name, "baseline", baseline, _branches, _setStatus);
  utils::setAddress(_tree, _name, "decayMode", decayMode, _branches, _setStatus);
  utils::setAddress(_tree, _name, "decayModeNew", decayModeNew, _branches, _setStatus);
  utils::setAddress(_tree, _name, "iso", iso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "isoDeltaBetaCorr", isoDeltaBetaCorr, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedGen_", matchedGen_, _branches, _setStatus);
}

void
panda::PTau::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "q", size, 'S', q, _branches);
  utils::book(_tree, _name, "baseline", size, 'O', baseline, _branches);
  utils::book(_tree, _name, "decayMode", size, 'O', decayMode, _branches);
  utils::book(_tree, _name, "decayModeNew", size, 'O', decayModeNew, _branches);
  utils::book(_tree, _name, "iso", size, 'F', iso, _branches);
  utils::book(_tree, _name, "isoDeltaBetaCorr", size, 'F', isoDeltaBetaCorr, _branches);
  utils::book(_tree, _name, "matchedGen_", size, 'i', matchedGen_, _branches);
}

void
panda::PTau::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  PParticleM::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "q");
  utils::resetAddress(_tree, _name, "baseline");
  utils::resetAddress(_tree, _name, "decayMode");
  utils::resetAddress(_tree, _name, "decayModeNew");
  utils::resetAddress(_tree, _name, "iso");
  utils::resetAddress(_tree, _name, "isoDeltaBetaCorr");
  utils::resetAddress(_tree, _name, "matchedGen_");
}

void
panda::PTau::datastore::resizeVectors_(UInt_t _size)
{
  PParticleM::datastore::resizeVectors_(_size);

}

panda::PTau::PTau(char const* _name/* = ""*/) :
  PParticleM(new PTauArray(1, _name)),
  q(gStore.getData(this).q[0]),
  baseline(gStore.getData(this).baseline[0]),
  decayMode(gStore.getData(this).decayMode[0]),
  decayModeNew(gStore.getData(this).decayModeNew[0]),
  iso(gStore.getData(this).iso[0]),
  isoDeltaBetaCorr(gStore.getData(this).isoDeltaBetaCorr[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
}

panda::PTau::PTau(datastore& _data, UInt_t _idx) :
  PParticleM(_data, _idx),
  q(_data.q[_idx]),
  baseline(_data.baseline[_idx]),
  decayMode(_data.decayMode[_idx]),
  decayModeNew(_data.decayModeNew[_idx]),
  iso(_data.iso[_idx]),
  isoDeltaBetaCorr(_data.isoDeltaBetaCorr[_idx]),
  matchedGen(_data.matchedGenContainer_, _data.matchedGen_[_idx])
{
}

panda::PTau::PTau(PTau const& _src) :
  PParticleM(new PTauArray(1, gStore.getName(&_src))),
  q(gStore.getData(this).q[0]),
  baseline(gStore.getData(this).baseline[0]),
  decayMode(gStore.getData(this).decayMode[0]),
  decayModeNew(gStore.getData(this).decayModeNew[0]),
  iso(gStore.getData(this).iso[0]),
  isoDeltaBetaCorr(gStore.getData(this).isoDeltaBetaCorr[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
  PParticleM::operator=(_src);

  q = _src.q;
  baseline = _src.baseline;
  decayMode = _src.decayMode;
  decayModeNew = _src.decayModeNew;
  iso = _src.iso;
  isoDeltaBetaCorr = _src.isoDeltaBetaCorr;
  matchedGen = _src.matchedGen;
}

panda::PTau::PTau(ArrayBase* _array) :
  PParticleM(_array),
  q(gStore.getData(this).q[0]),
  baseline(gStore.getData(this).baseline[0]),
  decayMode(gStore.getData(this).decayMode[0]),
  decayModeNew(gStore.getData(this).decayModeNew[0]),
  iso(gStore.getData(this).iso[0]),
  isoDeltaBetaCorr(gStore.getData(this).isoDeltaBetaCorr[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
}

panda::PTau::~PTau()
{
  destructor();
  gStore.free(this);
}

void
panda::PTau::destructor()
{
  /* BEGIN CUSTOM PTau.cc.destructor */
  /* END CUSTOM */

  PParticleM::destructor();
}

panda::PTau&
panda::PTau::operator=(PTau const& _src)
{
  PParticleM::operator=(_src);

  q = _src.q;
  baseline = _src.baseline;
  decayMode = _src.decayMode;
  decayModeNew = _src.decayModeNew;
  iso = _src.iso;
  isoDeltaBetaCorr = _src.isoDeltaBetaCorr;
  matchedGen = _src.matchedGen;

  return *this;
}

void
panda::PTau::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "q", _status, _branches);
  utils::setStatus(_tree, name, "baseline", _status, _branches);
  utils::setStatus(_tree, name, "decayMode", _status, _branches);
  utils::setStatus(_tree, name, "decayModeNew", _status, _branches);
  utils::setStatus(_tree, name, "iso", _status, _branches);
  utils::setStatus(_tree, name, "isoDeltaBetaCorr", _status, _branches);
  utils::setStatus(_tree, name, "matchedGen_", _status, _branches);
}

void
panda::PTau::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticleM::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "q", &q, _branches, _setStatus);
  utils::setAddress(_tree, name, "baseline", &baseline, _branches, _setStatus);
  utils::setAddress(_tree, name, "decayMode", &decayMode, _branches, _setStatus);
  utils::setAddress(_tree, name, "decayModeNew", &decayModeNew, _branches, _setStatus);
  utils::setAddress(_tree, name, "iso", &iso, _branches, _setStatus);
  utils::setAddress(_tree, name, "isoDeltaBetaCorr", &isoDeltaBetaCorr, _branches, _setStatus);
  utils::setAddress(_tree, name, "matchedGen_", gStore.getData(this).matchedGen_, _branches, true);
}

void
panda::PTau::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "q", "", 'S', &q, _branches);
  utils::book(_tree, name, "baseline", "", 'O', &baseline, _branches);
  utils::book(_tree, name, "decayMode", "", 'O', &decayMode, _branches);
  utils::book(_tree, name, "decayModeNew", "", 'O', &decayModeNew, _branches);
  utils::book(_tree, name, "iso", "", 'F', &iso, _branches);
  utils::book(_tree, name, "isoDeltaBetaCorr", "", 'F', &isoDeltaBetaCorr, _branches);
  utils::book(_tree, name, "matchedGen_", "", 'i', gStore.getData(this).matchedGen_, _branches);
}

void
panda::PTau::resetAddress(TTree& _tree)
{
  PParticleM::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "q");
  utils::resetAddress(_tree, name, "baseline");
  utils::resetAddress(_tree, name, "decayMode");
  utils::resetAddress(_tree, name, "decayModeNew");
  utils::resetAddress(_tree, name, "iso");
  utils::resetAddress(_tree, name, "isoDeltaBetaCorr");
  utils::resetAddress(_tree, name, "matchedGen_");
}

void
panda::PTau::init()
{
  PParticleM::init();

  q = 0;
  baseline = false;
  decayMode = false;
  decayModeNew = false;
  iso = 0.;
  isoDeltaBetaCorr = 0.;
  matchedGen.init();
}

/* BEGIN CUSTOM PTau.cc.global */
/* END CUSTOM */
