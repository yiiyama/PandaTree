#include "../interface/PPFCand.h"

void
panda::PPFCand::datastore::allocate(UInt_t _nmax)
{
  PParticleM::datastore::allocate(_nmax);

  q = new Float_t[nmax_];
  weight = new Float_t[nmax_];
  pftype = new Int_t[nmax_];
}

void
panda::PPFCand::datastore::deallocate()
{
  PParticleM::datastore::deallocate();

  delete [] q;
  q = 0;
  delete [] weight;
  weight = 0;
  delete [] pftype;
  pftype = 0;
}

void
panda::PPFCand::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "q", _status, _branches);
  utils::setStatus(_tree, _name, "weight", _status, _branches);
  utils::setStatus(_tree, _name, "pftype", _status, _branches);
}

void
panda::PPFCand::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "q", q, _branches, _setStatus);
  utils::setAddress(_tree, _name, "weight", weight, _branches, _setStatus);
  utils::setAddress(_tree, _name, "pftype", pftype, _branches, _setStatus);
}

void
panda::PPFCand::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "q", size, 'F', q, _branches);
  utils::book(_tree, _name, "weight", size, 'F', weight, _branches);
  utils::book(_tree, _name, "pftype", size, 'I', pftype, _branches);
}

panda::PPFCand::PPFCand(char const* _name/* = ""*/) :
  PParticleM(new PPFCandArray(1, _name)),
  q(gStore.getData(this).q[0]),
  weight(gStore.getData(this).weight[0]),
  pftype(gStore.getData(this).pftype[0])
{
}

panda::PPFCand::PPFCand(datastore& _data, UInt_t _idx) :
  PParticleM(_data, _idx),
  q(_data.q[_idx]),
  weight(_data.weight[_idx]),
  pftype(_data.pftype[_idx])
{
}

panda::PPFCand::PPFCand(PPFCand const& _src) :
  PParticleM(new PPFCandArray(1, gStore.getName(&_src))),
  q(gStore.getData(this).q[0]),
  weight(gStore.getData(this).weight[0]),
  pftype(gStore.getData(this).pftype[0])
{
  PParticleM::operator=(_src);


  q = _src.q;
  weight = _src.weight;
  pftype = _src.pftype;
}

panda::PPFCand::PPFCand(ArrayBase* _array) :
  PParticleM(_array),
  q(gStore.getData(this).q[0]),
  weight(gStore.getData(this).weight[0]),
  pftype(gStore.getData(this).pftype[0])
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
panda::PPFCand::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "q", _status, _branches);
  utils::setStatus(_tree, name, "weight", _status, _branches);
  utils::setStatus(_tree, name, "pftype", _status, _branches);
}

void
panda::PPFCand::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticleM::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "q", &q, _branches, _setStatus);
  utils::setAddress(_tree, name, "weight", &weight, _branches, _setStatus);
  utils::setAddress(_tree, name, "pftype", &pftype, _branches, _setStatus);
}

void
panda::PPFCand::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "q", "", 'F', &q, _branches);
  utils::book(_tree, name, "weight", "", 'F', &weight, _branches);
  utils::book(_tree, name, "pftype", "", 'I', &pftype, _branches);
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
