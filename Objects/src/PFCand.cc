#include "../interface/PFCand.h"

void
panda::PFCand::datastore::allocate(UInt_t _nmax)
{
  ParticleM::datastore::allocate(_nmax);

  q = new Short_t[nmax_];
  puppiW = new Float_t[nmax_];
  puppiWNoLep = new Float_t[nmax_];
  pftype = new Int_t[nmax_];
}

void
panda::PFCand::datastore::deallocate()
{
  ParticleM::datastore::deallocate();

  delete [] q;
  q = 0;
  delete [] puppiW;
  puppiW = 0;
  delete [] puppiWNoLep;
  puppiWNoLep = 0;
  delete [] pftype;
  pftype = 0;
}

void
panda::PFCand::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ParticleM::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "q", _branches);
  utils::setStatus(_tree, _name, "puppiW", _branches);
  utils::setStatus(_tree, _name, "puppiWNoLep", _branches);
  utils::setStatus(_tree, _name, "pftype", _branches);
}

void
panda::PFCand::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "q", q, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puppiW", puppiW, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puppiWNoLep", puppiWNoLep, _branches, _setStatus);
  utils::setAddress(_tree, _name, "pftype", pftype, _branches, _setStatus);
}

void
panda::PFCand::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "q", size, 'S', q, _branches);
  utils::book(_tree, _name, "puppiW", size, 'F', puppiW, _branches);
  utils::book(_tree, _name, "puppiWNoLep", size, 'F', puppiWNoLep, _branches);
  utils::book(_tree, _name, "pftype", size, 'I', pftype, _branches);
}

void
panda::PFCand::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  ParticleM::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "q");
  utils::resetAddress(_tree, _name, "puppiW");
  utils::resetAddress(_tree, _name, "puppiWNoLep");
  utils::resetAddress(_tree, _name, "pftype");
}

void
panda::PFCand::datastore::resizeVectors_(UInt_t _size)
{
  ParticleM::datastore::resizeVectors_(_size);

}

panda::PFCand::PFCand(char const* _name/* = ""*/) :
  ParticleM(new PFCandArray(1, _name)),
  q(gStore.getData(this).q[0]),
  puppiW(gStore.getData(this).puppiW[0]),
  puppiWNoLep(gStore.getData(this).puppiWNoLep[0]),
  pftype(gStore.getData(this).pftype[0])
{
}

panda::PFCand::PFCand(datastore& _data, UInt_t _idx) :
  ParticleM(_data, _idx),
  q(_data.q[_idx]),
  puppiW(_data.puppiW[_idx]),
  puppiWNoLep(_data.puppiWNoLep[_idx]),
  pftype(_data.pftype[_idx])
{
}

panda::PFCand::PFCand(PFCand const& _src) :
  ParticleM(new PFCandArray(1, gStore.getName(&_src))),
  q(gStore.getData(this).q[0]),
  puppiW(gStore.getData(this).puppiW[0]),
  puppiWNoLep(gStore.getData(this).puppiWNoLep[0]),
  pftype(gStore.getData(this).pftype[0])
{
  ParticleM::operator=(_src);

  q = _src.q;
  puppiW = _src.puppiW;
  puppiWNoLep = _src.puppiWNoLep;
  pftype = _src.pftype;
}

panda::PFCand::PFCand(ArrayBase* _array) :
  ParticleM(_array),
  q(gStore.getData(this).q[0]),
  puppiW(gStore.getData(this).puppiW[0]),
  puppiWNoLep(gStore.getData(this).puppiWNoLep[0]),
  pftype(gStore.getData(this).pftype[0])
{
}

panda::PFCand::~PFCand()
{
  destructor();
  gStore.free(this);
}

void
panda::PFCand::destructor()
{
  /* BEGIN CUSTOM PFCand.cc.destructor */
  /* END CUSTOM */

  ParticleM::destructor();
}

panda::PFCand&
panda::PFCand::operator=(PFCand const& _src)
{
  ParticleM::operator=(_src);

  q = _src.q;
  puppiW = _src.puppiW;
  puppiWNoLep = _src.puppiWNoLep;
  pftype = _src.pftype;

  return *this;
}

void
panda::PFCand::setStatus(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  ParticleM::setStatus(_tree, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "q", _branches);
  utils::setStatus(_tree, name, "puppiW", _branches);
  utils::setStatus(_tree, name, "puppiWNoLep", _branches);
  utils::setStatus(_tree, name, "pftype", _branches);
}

UInt_t
panda::PFCand::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "q", &q, _branches, _setStatus);
  utils::setAddress(_tree, name, "puppiW", &puppiW, _branches, _setStatus);
  utils::setAddress(_tree, name, "puppiWNoLep", &puppiWNoLep, _branches, _setStatus);
  utils::setAddress(_tree, name, "pftype", &pftype, _branches, _setStatus);

  return -1;
}

UInt_t
panda::PFCand::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  ParticleM::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "q", "", 'S', &q, _branches);
  utils::book(_tree, name, "puppiW", "", 'F', &puppiW, _branches);
  utils::book(_tree, name, "puppiWNoLep", "", 'F', &puppiWNoLep, _branches);
  utils::book(_tree, name, "pftype", "", 'I', &pftype, _branches);

  return -1;
}

void
panda::PFCand::releaseTree(TTree& _tree)
{
  ParticleM::releaseTree(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "q");
  utils::resetAddress(_tree, name, "puppiW");
  utils::resetAddress(_tree, name, "puppiWNoLep");
  utils::resetAddress(_tree, name, "pftype");
}

void
panda::PFCand::init()
{
  ParticleM::init();

  q = 0;
  puppiW = 0.;
  puppiWNoLep = 0.;
  pftype = 0;
}


/* BEGIN CUSTOM PFCand.cc.global */
/* END CUSTOM */
