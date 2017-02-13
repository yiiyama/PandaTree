#include "../interface/Lepton.h"

/*static*/
panda::utils::BranchList
panda::Lepton::getListOfBranches()
{
  utils::BranchList blist;
  blist += ParticleP::getListOfBranches();
  blist += {"q", "loose", "medium", "tight", "chiso", "nhiso", "phoiso", "puiso", "matchedGen_"};
  return blist;
}

void
panda::Lepton::datastore::allocate(UInt_t _nmax)
{
  ParticleP::datastore::allocate(_nmax);

  q = new Short_t[nmax_];
  loose = new Bool_t[nmax_];
  medium = new Bool_t[nmax_];
  tight = new Bool_t[nmax_];
  chiso = new Float_t[nmax_];
  nhiso = new Float_t[nmax_];
  phoiso = new Float_t[nmax_];
  puiso = new Float_t[nmax_];
  matchedGen_ = new Short_t[nmax_];
}

void
panda::Lepton::datastore::deallocate()
{
  ParticleP::datastore::deallocate();

  delete [] q;
  q = 0;
  delete [] loose;
  loose = 0;
  delete [] medium;
  medium = 0;
  delete [] tight;
  tight = 0;
  delete [] chiso;
  chiso = 0;
  delete [] nhiso;
  nhiso = 0;
  delete [] phoiso;
  phoiso = 0;
  delete [] puiso;
  puiso = 0;
  delete [] matchedGen_;
  matchedGen_ = 0;
}

void
panda::Lepton::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  ParticleP::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "q", _branches);
  utils::setStatus(_tree, _name, "loose", _branches);
  utils::setStatus(_tree, _name, "medium", _branches);
  utils::setStatus(_tree, _name, "tight", _branches);
  utils::setStatus(_tree, _name, "chiso", _branches);
  utils::setStatus(_tree, _name, "nhiso", _branches);
  utils::setStatus(_tree, _name, "phoiso", _branches);
  utils::setStatus(_tree, _name, "puiso", _branches);
  utils::setStatus(_tree, _name, "matchedGen_", _branches);
}

panda::utils::BranchList
panda::Lepton::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(ParticleP::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "q"));
  blist.push_back(utils::getStatus(_tree, _name, "loose"));
  blist.push_back(utils::getStatus(_tree, _name, "medium"));
  blist.push_back(utils::getStatus(_tree, _name, "tight"));
  blist.push_back(utils::getStatus(_tree, _name, "chiso"));
  blist.push_back(utils::getStatus(_tree, _name, "nhiso"));
  blist.push_back(utils::getStatus(_tree, _name, "phoiso"));
  blist.push_back(utils::getStatus(_tree, _name, "puiso"));
  blist.push_back(utils::getStatus(_tree, _name, "matchedGen_"));

  return blist;
}

void
panda::Lepton::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleP::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "q", q, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose", loose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "medium", medium, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight", tight, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chiso", chiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhiso", nhiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phoiso", phoiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puiso", puiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedGen_", matchedGen_, _branches, _setStatus);
}

void
panda::Lepton::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ParticleP::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "q", size, 'S', q, _branches);
  utils::book(_tree, _name, "loose", size, 'O', loose, _branches);
  utils::book(_tree, _name, "medium", size, 'O', medium, _branches);
  utils::book(_tree, _name, "tight", size, 'O', tight, _branches);
  utils::book(_tree, _name, "chiso", size, 'F', chiso, _branches);
  utils::book(_tree, _name, "nhiso", size, 'F', nhiso, _branches);
  utils::book(_tree, _name, "phoiso", size, 'F', phoiso, _branches);
  utils::book(_tree, _name, "puiso", size, 'F', puiso, _branches);
  utils::book(_tree, _name, "matchedGen_", size, 'S', matchedGen_, _branches);
}

void
panda::Lepton::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  ParticleP::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "q");
  utils::resetAddress(_tree, _name, "loose");
  utils::resetAddress(_tree, _name, "medium");
  utils::resetAddress(_tree, _name, "tight");
  utils::resetAddress(_tree, _name, "chiso");
  utils::resetAddress(_tree, _name, "nhiso");
  utils::resetAddress(_tree, _name, "phoiso");
  utils::resetAddress(_tree, _name, "puiso");
  utils::resetAddress(_tree, _name, "matchedGen_");
}

void
panda::Lepton::datastore::resizeVectors_(UInt_t _size)
{
  ParticleP::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::Lepton::datastore::getBranchNames(TString const& _name) const
{
  return Lepton::getListOfBranches().fullNames(_name);
}

panda::Lepton::Lepton(char const* _name/* = ""*/) :
  ParticleP(new LeptonArray(1, _name)),
  q(gStore.getData(this).q[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  chiso(gStore.getData(this).chiso[0]),
  nhiso(gStore.getData(this).nhiso[0]),
  phoiso(gStore.getData(this).phoiso[0]),
  puiso(gStore.getData(this).puiso[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
}

panda::Lepton::Lepton(Lepton const& _src) :
  ParticleP(new LeptonArray(1, gStore.getName(&_src))),
  q(gStore.getData(this).q[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  chiso(gStore.getData(this).chiso[0]),
  nhiso(gStore.getData(this).nhiso[0]),
  phoiso(gStore.getData(this).phoiso[0]),
  puiso(gStore.getData(this).puiso[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
  ParticleP::operator=(_src);

  q = _src.q;
  loose = _src.loose;
  medium = _src.medium;
  tight = _src.tight;
  chiso = _src.chiso;
  nhiso = _src.nhiso;
  phoiso = _src.phoiso;
  puiso = _src.puiso;
  matchedGen = _src.matchedGen;
}

panda::Lepton::Lepton(datastore& _data, UInt_t _idx) :
  ParticleP(_data, _idx),
  q(_data.q[_idx]),
  loose(_data.loose[_idx]),
  medium(_data.medium[_idx]),
  tight(_data.tight[_idx]),
  chiso(_data.chiso[_idx]),
  nhiso(_data.nhiso[_idx]),
  phoiso(_data.phoiso[_idx]),
  puiso(_data.puiso[_idx]),
  matchedGen(_data.matchedGenContainer_, _data.matchedGen_[_idx])
{
}

panda::Lepton::Lepton(ArrayBase* _array) :
  ParticleP(_array),
  q(gStore.getData(this).q[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  chiso(gStore.getData(this).chiso[0]),
  nhiso(gStore.getData(this).nhiso[0]),
  phoiso(gStore.getData(this).phoiso[0]),
  puiso(gStore.getData(this).puiso[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
}

panda::Lepton::~Lepton()
{
  destructor();
  gStore.free(this);
}

void
panda::Lepton::destructor()
{
  /* BEGIN CUSTOM Lepton.cc.destructor */
  /* END CUSTOM */

  ParticleP::destructor();
}

panda::Lepton&
panda::Lepton::operator=(Lepton const& _src)
{
  ParticleP::operator=(_src);

  q = _src.q;
  loose = _src.loose;
  medium = _src.medium;
  tight = _src.tight;
  chiso = _src.chiso;
  nhiso = _src.nhiso;
  phoiso = _src.phoiso;
  puiso = _src.puiso;
  matchedGen = _src.matchedGen;

  return *this;
}

void
panda::Lepton::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleP::doSetAddress_(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "q", &q, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose", &loose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "medium", &medium, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight", &tight, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chiso", &chiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhiso", &nhiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phoiso", &phoiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puiso", &puiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedGen_", gStore.getData(this).matchedGen_, _branches, true);
}

void
panda::Lepton::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ParticleP::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "q", "", 'S', &q, _branches);
  utils::book(_tree, _name, "loose", "", 'O', &loose, _branches);
  utils::book(_tree, _name, "medium", "", 'O', &medium, _branches);
  utils::book(_tree, _name, "tight", "", 'O', &tight, _branches);
  utils::book(_tree, _name, "chiso", "", 'F', &chiso, _branches);
  utils::book(_tree, _name, "nhiso", "", 'F', &nhiso, _branches);
  utils::book(_tree, _name, "phoiso", "", 'F', &phoiso, _branches);
  utils::book(_tree, _name, "puiso", "", 'F', &puiso, _branches);
  utils::book(_tree, _name, "matchedGen_", "", 'S', gStore.getData(this).matchedGen_, _branches);
}

void
panda::Lepton::doReleaseTree_(TTree& _tree, TString const& _name)
{
  ParticleP::doReleaseTree_(_tree, _name);

  utils::resetAddress(_tree, _name, "q");
  utils::resetAddress(_tree, _name, "loose");
  utils::resetAddress(_tree, _name, "medium");
  utils::resetAddress(_tree, _name, "tight");
  utils::resetAddress(_tree, _name, "chiso");
  utils::resetAddress(_tree, _name, "nhiso");
  utils::resetAddress(_tree, _name, "phoiso");
  utils::resetAddress(_tree, _name, "puiso");
  utils::resetAddress(_tree, _name, "matchedGen_");
}

void
panda::Lepton::doInit_()
{
  ParticleP::doInit_();

  q = 0;
  loose = false;
  medium = false;
  tight = false;
  chiso = 0.;
  nhiso = 0.;
  phoiso = 0.;
  puiso = 0.;
  matchedGen.init();

  /* BEGIN CUSTOM Lepton.cc.doInit_ */
  /* END CUSTOM */
}


/* BEGIN CUSTOM Lepton.cc.global */
/* END CUSTOM */
