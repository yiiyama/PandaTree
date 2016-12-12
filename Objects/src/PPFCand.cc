#include "../interface/PPFCand.h"

void
panda::PPFCand::datastore::allocate(UInt_t _nmax)
{
  PParticleM::datastore::allocate(_nmax);

  q = new Short_t[nmax_];
  puppiW = new Float_t[nmax_];
  puppiWNoLep = new Float_t[nmax_];
  pftype = new Int_t[nmax_];
}

void
panda::PPFCand::datastore::deallocate()
{
  PParticleM::datastore::deallocate();

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
panda::PPFCand::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  PParticleM::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "q", _status, _branches);
  utils::setStatus(_tree, _name, "puppiW", _status, _branches);
  utils::setStatus(_tree, _name, "puppiWNoLep", _status, _branches);
  utils::setStatus(_tree, _name, "pftype", _status, _branches);
}

void
panda::PPFCand::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "q", q, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puppiW", puppiW, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puppiWNoLep", puppiWNoLep, _branches, _setStatus);
  utils::setAddress(_tree, _name, "pftype", pftype, _branches, _setStatus);
}

void
panda::PPFCand::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "q", size, 'S', q, _branches);
  utils::book(_tree, _name, "puppiW", size, 'F', puppiW, _branches);
  utils::book(_tree, _name, "puppiWNoLep", size, 'F', puppiWNoLep, _branches);
  utils::book(_tree, _name, "pftype", size, 'I', pftype, _branches);
}

void
panda::PPFCand::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  PParticleM::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "q");
  utils::resetAddress(_tree, _name, "puppiW");
  utils::resetAddress(_tree, _name, "puppiWNoLep");
  utils::resetAddress(_tree, _name, "pftype");
}

void
panda::PPFCand::datastore::resizeVectors_(UInt_t _size)
{
  PParticleM::datastore::resizeVectors_(_size);

}

panda::PPFCand::PPFCand(char const* _name/* = ""*/) :
  PParticleM(new PPFCandArray(1, _name)),
  q(gStore.getData(this).q[0]),
  puppiW(gStore.getData(this).puppiW[0]),
  puppiWNoLep(gStore.getData(this).puppiWNoLep[0]),
  pftype(gStore.getData(this).pftype[0])
{
}

panda::PPFCand::PPFCand(datastore& _data, UInt_t _idx) :
  PParticleM(_data, _idx),
  q(_data.q[_idx]),
  puppiW(_data.puppiW[_idx]),
  puppiWNoLep(_data.puppiWNoLep[_idx]),
  pftype(_data.pftype[_idx])
{
}

panda::PPFCand::PPFCand(PPFCand const& _src) :
  PParticleM(new PPFCandArray(1, gStore.getName(&_src))),
  q(gStore.getData(this).q[0]),
  puppiW(gStore.getData(this).puppiW[0]),
  puppiWNoLep(gStore.getData(this).puppiWNoLep[0]),
  pftype(gStore.getData(this).pftype[0])
{
  PParticleM::operator=(_src);

  q = _src.q;
  puppiW = _src.puppiW;
  puppiWNoLep = _src.puppiWNoLep;
  pftype = _src.pftype;
}

panda::PPFCand::PPFCand(ArrayBase* _array) :
  PParticleM(_array),
  q(gStore.getData(this).q[0]),
  puppiW(gStore.getData(this).puppiW[0]),
  puppiWNoLep(gStore.getData(this).puppiWNoLep[0]),
  pftype(gStore.getData(this).pftype[0])
{
}

panda::PPFCand::~PPFCand()
{
  destructor();
  gStore.free(this);
}

void
panda::PPFCand::destructor()
{
  /* BEGIN CUSTOM PPFCand.cc.destructor */
  /* END CUSTOM */

  PParticleM::destructor();
}

panda::PPFCand&
panda::PPFCand::operator=(PPFCand const& _src)
{
  PParticleM::operator=(_src);

  q = _src.q;
  puppiW = _src.puppiW;
  puppiWNoLep = _src.puppiWNoLep;
  pftype = _src.pftype;

  return *this;
}

void
panda::PPFCand::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  PParticleM::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "q", _status, _branches);
  utils::setStatus(_tree, name, "puppiW", _status, _branches);
  utils::setStatus(_tree, name, "puppiWNoLep", _status, _branches);
  utils::setStatus(_tree, name, "pftype", _status, _branches);
}

void
panda::PPFCand::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticleM::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "q", &q, _branches, _setStatus);
  utils::setAddress(_tree, name, "puppiW", &puppiW, _branches, _setStatus);
  utils::setAddress(_tree, name, "puppiWNoLep", &puppiWNoLep, _branches, _setStatus);
  utils::setAddress(_tree, name, "pftype", &pftype, _branches, _setStatus);
}

void
panda::PPFCand::book(TTree& _tree, utils::BranchList const& _branches/* = {}*/)
{
  PParticleM::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "q", "", 'S', &q, _branches);
  utils::book(_tree, name, "puppiW", "", 'F', &puppiW, _branches);
  utils::book(_tree, name, "puppiWNoLep", "", 'F', &puppiWNoLep, _branches);
  utils::book(_tree, name, "pftype", "", 'I', &pftype, _branches);
}

void
panda::PPFCand::resetAddress(TTree& _tree)
{
  PParticleM::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "q");
  utils::resetAddress(_tree, name, "puppiW");
  utils::resetAddress(_tree, name, "puppiWNoLep");
  utils::resetAddress(_tree, name, "pftype");
}

void
panda::PPFCand::init()
{
  PParticleM::init();

  q = 0;
  puppiW = 0.;
  puppiWNoLep = 0.;
  pftype = 0;
}

/* BEGIN CUSTOM PPFCand.cc.global */
/* END CUSTOM */
