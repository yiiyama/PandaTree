#include "../interface/Tau.h"

void
panda::Tau::datastore::allocate(UInt_t _nmax)
{
  ParticleM::datastore::allocate(_nmax);

  q = new Short_t[nmax_];
  decayMode = new Bool_t[nmax_];
  decayModeNew = new Bool_t[nmax_];
  iso = new Float_t[nmax_];
  isoDeltaBetaCorr = new Float_t[nmax_];
  matchedGen_ = new Int_t[nmax_];
}

void
panda::Tau::datastore::deallocate()
{
  ParticleM::datastore::deallocate();

  delete [] q;
  q = 0;
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
panda::Tau::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  ParticleM::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "q", _branches);
  utils::setStatus(_tree, _name, "decayMode", _branches);
  utils::setStatus(_tree, _name, "decayModeNew", _branches);
  utils::setStatus(_tree, _name, "iso", _branches);
  utils::setStatus(_tree, _name, "isoDeltaBetaCorr", _branches);
  utils::setStatus(_tree, _name, "matchedGen_", _branches);
}

panda::utils::BranchList
panda::Tau::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(ParticleM::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "q"));
  blist.push_back(utils::getStatus(_tree, _name, "decayMode"));
  blist.push_back(utils::getStatus(_tree, _name, "decayModeNew"));
  blist.push_back(utils::getStatus(_tree, _name, "iso"));
  blist.push_back(utils::getStatus(_tree, _name, "isoDeltaBetaCorr"));
  blist.push_back(utils::getStatus(_tree, _name, "matchedGen_"));

  return blist;
}

void
panda::Tau::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "q", q, _branches, _setStatus);
  utils::setAddress(_tree, _name, "decayMode", decayMode, _branches, _setStatus);
  utils::setAddress(_tree, _name, "decayModeNew", decayModeNew, _branches, _setStatus);
  utils::setAddress(_tree, _name, "iso", iso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "isoDeltaBetaCorr", isoDeltaBetaCorr, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedGen_", matchedGen_, _branches, _setStatus);
}

void
panda::Tau::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "q", size, 'S', q, _branches);
  utils::book(_tree, _name, "decayMode", size, 'O', decayMode, _branches);
  utils::book(_tree, _name, "decayModeNew", size, 'O', decayModeNew, _branches);
  utils::book(_tree, _name, "iso", size, 'F', iso, _branches);
  utils::book(_tree, _name, "isoDeltaBetaCorr", size, 'F', isoDeltaBetaCorr, _branches);
  utils::book(_tree, _name, "matchedGen_", size, 'I', matchedGen_, _branches);
}

void
panda::Tau::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  ParticleM::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "q");
  utils::resetAddress(_tree, _name, "decayMode");
  utils::resetAddress(_tree, _name, "decayModeNew");
  utils::resetAddress(_tree, _name, "iso");
  utils::resetAddress(_tree, _name, "isoDeltaBetaCorr");
  utils::resetAddress(_tree, _name, "matchedGen_");
}

void
panda::Tau::datastore::resizeVectors_(UInt_t _size)
{
  ParticleM::datastore::resizeVectors_(_size);

}

panda::Tau::Tau(char const* _name/* = ""*/) :
  ParticleM(new TauArray(1, _name)),
  q(gStore.getData(this).q[0]),
  decayMode(gStore.getData(this).decayMode[0]),
  decayModeNew(gStore.getData(this).decayModeNew[0]),
  iso(gStore.getData(this).iso[0]),
  isoDeltaBetaCorr(gStore.getData(this).isoDeltaBetaCorr[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
}

panda::Tau::Tau(datastore& _data, UInt_t _idx) :
  ParticleM(_data, _idx),
  q(_data.q[_idx]),
  decayMode(_data.decayMode[_idx]),
  decayModeNew(_data.decayModeNew[_idx]),
  iso(_data.iso[_idx]),
  isoDeltaBetaCorr(_data.isoDeltaBetaCorr[_idx]),
  matchedGen(_data.matchedGenContainer_, _data.matchedGen_[_idx])
{
}

panda::Tau::Tau(Tau const& _src) :
  ParticleM(new TauArray(1, gStore.getName(&_src))),
  q(gStore.getData(this).q[0]),
  decayMode(gStore.getData(this).decayMode[0]),
  decayModeNew(gStore.getData(this).decayModeNew[0]),
  iso(gStore.getData(this).iso[0]),
  isoDeltaBetaCorr(gStore.getData(this).isoDeltaBetaCorr[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
  ParticleM::operator=(_src);

  q = _src.q;
  decayMode = _src.decayMode;
  decayModeNew = _src.decayModeNew;
  iso = _src.iso;
  isoDeltaBetaCorr = _src.isoDeltaBetaCorr;
  matchedGen = _src.matchedGen;
}

panda::Tau::Tau(ArrayBase* _array) :
  ParticleM(_array),
  q(gStore.getData(this).q[0]),
  decayMode(gStore.getData(this).decayMode[0]),
  decayModeNew(gStore.getData(this).decayModeNew[0]),
  iso(gStore.getData(this).iso[0]),
  isoDeltaBetaCorr(gStore.getData(this).isoDeltaBetaCorr[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
}

panda::Tau::~Tau()
{
  destructor();
  gStore.free(this);
}

void
panda::Tau::destructor()
{
  /* BEGIN CUSTOM Tau.cc.destructor */
  /* END CUSTOM */

  ParticleM::destructor();
}

panda::Tau&
panda::Tau::operator=(Tau const& _src)
{
  ParticleM::operator=(_src);

  q = _src.q;
  decayMode = _src.decayMode;
  decayModeNew = _src.decayModeNew;
  iso = _src.iso;
  isoDeltaBetaCorr = _src.isoDeltaBetaCorr;
  matchedGen = _src.matchedGen;

  return *this;
}

void
panda::Tau::doSetStatus_(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  ParticleM::doSetStatus_(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "q", _branches);
  utils::setStatus(_tree, _name, "decayMode", _branches);
  utils::setStatus(_tree, _name, "decayModeNew", _branches);
  utils::setStatus(_tree, _name, "iso", _branches);
  utils::setStatus(_tree, _name, "isoDeltaBetaCorr", _branches);
  utils::setStatus(_tree, _name, "matchedGen_", _branches);
}

panda::utils::BranchList
panda::Tau::doGetStatus_(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(ParticleM::doGetStatus_(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "q"));
  blist.push_back(utils::getStatus(_tree, _name, "decayMode"));
  blist.push_back(utils::getStatus(_tree, _name, "decayModeNew"));
  blist.push_back(utils::getStatus(_tree, _name, "iso"));
  blist.push_back(utils::getStatus(_tree, _name, "isoDeltaBetaCorr"));
  blist.push_back(utils::getStatus(_tree, _name, "matchedGen_"));

  return blist;
}

void
panda::Tau::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::doSetAddress_(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "q", &q, _branches, _setStatus);
  utils::setAddress(_tree, _name, "decayMode", &decayMode, _branches, _setStatus);
  utils::setAddress(_tree, _name, "decayModeNew", &decayModeNew, _branches, _setStatus);
  utils::setAddress(_tree, _name, "iso", &iso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "isoDeltaBetaCorr", &isoDeltaBetaCorr, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedGen_", gStore.getData(this).matchedGen_, _branches, true);
}

void
panda::Tau::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ParticleM::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "q", "", 'S', &q, _branches);
  utils::book(_tree, _name, "decayMode", "", 'O', &decayMode, _branches);
  utils::book(_tree, _name, "decayModeNew", "", 'O', &decayModeNew, _branches);
  utils::book(_tree, _name, "iso", "", 'F', &iso, _branches);
  utils::book(_tree, _name, "isoDeltaBetaCorr", "", 'F', &isoDeltaBetaCorr, _branches);
  utils::book(_tree, _name, "matchedGen_", "", 'I', gStore.getData(this).matchedGen_, _branches);
}

void
panda::Tau::doReleaseTree_(TTree& _tree, TString const& _name)
{
  ParticleM::doReleaseTree_(_tree, _name);

  utils::resetAddress(_tree, _name, "q");
  utils::resetAddress(_tree, _name, "decayMode");
  utils::resetAddress(_tree, _name, "decayModeNew");
  utils::resetAddress(_tree, _name, "iso");
  utils::resetAddress(_tree, _name, "isoDeltaBetaCorr");
  utils::resetAddress(_tree, _name, "matchedGen_");
}

void
panda::Tau::doInit_()
{
  ParticleM::doInit_();

  q = 0;
  decayMode = false;
  decayModeNew = false;
  iso = 0.;
  isoDeltaBetaCorr = 0.;
  matchedGen.init();
}

/* BEGIN CUSTOM Tau.cc.global */
/* END CUSTOM */
