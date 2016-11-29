#include "../interface/PJet.h"

void
panda::PJet::datastore::allocate(UInt_t _nmax)
{
  PParticleM::datastore::allocate(_nmax);

  rawPt = new Float_t[nmax_];
  ptCorrUp = new Float_t[nmax_];
  ptCorrDown = new Float_t[nmax_];
  ptResCorr = new Float_t[nmax_];
  phiResCorr = new Float_t[nmax_];
  csv = new Float_t[nmax_];
  qgl = new Float_t[nmax_];
  nhf = new Float_t[nmax_];
  chf = new Float_t[nmax_];
  id = new UInt_t[nmax_];
  constituents_ = new std::vector<std::vector<UInt_t>>(nmax_);
}

void
panda::PJet::datastore::deallocate()
{
  PParticleM::datastore::deallocate();

  delete [] rawPt;
  rawPt = 0;
  delete [] ptCorrUp;
  ptCorrUp = 0;
  delete [] ptCorrDown;
  ptCorrDown = 0;
  delete [] ptResCorr;
  ptResCorr = 0;
  delete [] phiResCorr;
  phiResCorr = 0;
  delete [] csv;
  csv = 0;
  delete [] qgl;
  qgl = 0;
  delete [] nhf;
  nhf = 0;
  delete [] chf;
  chf = 0;
  delete [] id;
  id = 0;
  delete constituents_;
  constituents_ = 0;
}

void
panda::PJet::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "rawPt", _status, _branches);
  utils::setStatus(_tree, _name, "ptCorrUp", _status, _branches);
  utils::setStatus(_tree, _name, "ptCorrDown", _status, _branches);
  utils::setStatus(_tree, _name, "ptResCorr", _status, _branches);
  utils::setStatus(_tree, _name, "phiResCorr", _status, _branches);
  utils::setStatus(_tree, _name, "csv", _status, _branches);
  utils::setStatus(_tree, _name, "qgl", _status, _branches);
  utils::setStatus(_tree, _name, "nhf", _status, _branches);
  utils::setStatus(_tree, _name, "chf", _status, _branches);
  utils::setStatus(_tree, _name, "id", _status, _branches);
  utils::setStatus(_tree, _name, "constituents_", _status, _branches);
}

void
panda::PJet::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "rawPt", rawPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptCorrUp", ptCorrUp, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptCorrDown", ptCorrDown, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptResCorr", ptResCorr, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phiResCorr", phiResCorr, _branches, _setStatus);
  utils::setAddress(_tree, _name, "csv", csv, _branches, _setStatus);
  utils::setAddress(_tree, _name, "qgl", qgl, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhf", nhf, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chf", chf, _branches, _setStatus);
  utils::setAddress(_tree, _name, "id", id, _branches, _setStatus);
  utils::setAddress(_tree, _name, "constituents_", &constituents_, _branches, _setStatus);
}

void
panda::PJet::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "rawPt", size, 'F', rawPt, _branches);
  utils::book(_tree, _name, "ptCorrUp", size, 'F', ptCorrUp, _branches);
  utils::book(_tree, _name, "ptCorrDown", size, 'F', ptCorrDown, _branches);
  utils::book(_tree, _name, "ptResCorr", size, 'F', ptResCorr, _branches);
  utils::book(_tree, _name, "phiResCorr", size, 'F', phiResCorr, _branches);
  utils::book(_tree, _name, "csv", size, 'F', csv, _branches);
  utils::book(_tree, _name, "qgl", size, 'F', qgl, _branches);
  utils::book(_tree, _name, "nhf", size, 'F', nhf, _branches);
  utils::book(_tree, _name, "chf", size, 'F', chf, _branches);
  utils::book(_tree, _name, "id", size, 'i', id, _branches);
  utils::book(_tree, _name, "constituents_", "std::vector<std::vector<UInt_t>>", &constituents_, _branches);
}

void
panda::PJet::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  PParticleM::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "rawPt");
  utils::resetAddress(_tree, _name, "ptCorrUp");
  utils::resetAddress(_tree, _name, "ptCorrDown");
  utils::resetAddress(_tree, _name, "ptResCorr");
  utils::resetAddress(_tree, _name, "phiResCorr");
  utils::resetAddress(_tree, _name, "csv");
  utils::resetAddress(_tree, _name, "qgl");
  utils::resetAddress(_tree, _name, "nhf");
  utils::resetAddress(_tree, _name, "chf");
  utils::resetAddress(_tree, _name, "id");
  utils::resetAddress(_tree, _name, "constituents_");
}

void
panda::PJet::datastore::resizeVectors_(UInt_t _size)
{
  PParticleM::datastore::resizeVectors_(_size);

  constituents_->resize(_size);
}

panda::PJet::PJet(char const* _name/* = ""*/) :
  PParticleM(new PJetArray(1, _name)),
  rawPt(gStore.getData(this).rawPt[0]),
  ptCorrUp(gStore.getData(this).ptCorrUp[0]),
  ptCorrDown(gStore.getData(this).ptCorrDown[0]),
  ptResCorr(gStore.getData(this).ptResCorr[0]),
  phiResCorr(gStore.getData(this).phiResCorr[0]),
  csv(gStore.getData(this).csv[0]),
  qgl(gStore.getData(this).qgl[0]),
  nhf(gStore.getData(this).nhf[0]),
  chf(gStore.getData(this).chf[0]),
  id(gStore.getData(this).id[0]),
  constituents((*gStore.getData(this).constituents_)[0])
{
}

panda::PJet::PJet(datastore& _data, UInt_t _idx) :
  PParticleM(_data, _idx),
  rawPt(_data.rawPt[_idx]),
  ptCorrUp(_data.ptCorrUp[_idx]),
  ptCorrDown(_data.ptCorrDown[_idx]),
  ptResCorr(_data.ptResCorr[_idx]),
  phiResCorr(_data.phiResCorr[_idx]),
  csv(_data.csv[_idx]),
  qgl(_data.qgl[_idx]),
  nhf(_data.nhf[_idx]),
  chf(_data.chf[_idx]),
  id(_data.id[_idx]),
  constituents((*_data.constituents_)[_idx])
{
}

panda::PJet::PJet(PJet const& _src) :
  PParticleM(new PJetArray(1, gStore.getName(&_src))),
  rawPt(gStore.getData(this).rawPt[0]),
  ptCorrUp(gStore.getData(this).ptCorrUp[0]),
  ptCorrDown(gStore.getData(this).ptCorrDown[0]),
  ptResCorr(gStore.getData(this).ptResCorr[0]),
  phiResCorr(gStore.getData(this).phiResCorr[0]),
  csv(gStore.getData(this).csv[0]),
  qgl(gStore.getData(this).qgl[0]),
  nhf(gStore.getData(this).nhf[0]),
  chf(gStore.getData(this).chf[0]),
  id(gStore.getData(this).id[0]),
  constituents((*gStore.getData(this).constituents_)[0])
{
  PParticleM::operator=(_src);

  rawPt = _src.rawPt;
  ptCorrUp = _src.ptCorrUp;
  ptCorrDown = _src.ptCorrDown;
  ptResCorr = _src.ptResCorr;
  phiResCorr = _src.phiResCorr;
  csv = _src.csv;
  qgl = _src.qgl;
  nhf = _src.nhf;
  chf = _src.chf;
  id = _src.id;
  constituents = _src.constituents;
}

panda::PJet::PJet(ArrayBase* _array) :
  PParticleM(_array),
  rawPt(gStore.getData(this).rawPt[0]),
  ptCorrUp(gStore.getData(this).ptCorrUp[0]),
  ptCorrDown(gStore.getData(this).ptCorrDown[0]),
  ptResCorr(gStore.getData(this).ptResCorr[0]),
  phiResCorr(gStore.getData(this).phiResCorr[0]),
  csv(gStore.getData(this).csv[0]),
  qgl(gStore.getData(this).qgl[0]),
  nhf(gStore.getData(this).nhf[0]),
  chf(gStore.getData(this).chf[0]),
  id(gStore.getData(this).id[0]),
  constituents((*gStore.getData(this).constituents_)[0])
{
}

panda::PJet::~PJet()
{
  gStore.free(this);
}

panda::PJet&
panda::PJet::operator=(PJet const& _src)
{
  PParticleM::operator=(_src);

  rawPt = _src.rawPt;
  ptCorrUp = _src.ptCorrUp;
  ptCorrDown = _src.ptCorrDown;
  ptResCorr = _src.ptResCorr;
  phiResCorr = _src.phiResCorr;
  csv = _src.csv;
  qgl = _src.qgl;
  nhf = _src.nhf;
  chf = _src.chf;
  id = _src.id;
  constituents = _src.constituents;

  return *this;
}

void
panda::PJet::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "rawPt", _status, _branches);
  utils::setStatus(_tree, name, "ptCorrUp", _status, _branches);
  utils::setStatus(_tree, name, "ptCorrDown", _status, _branches);
  utils::setStatus(_tree, name, "ptResCorr", _status, _branches);
  utils::setStatus(_tree, name, "phiResCorr", _status, _branches);
  utils::setStatus(_tree, name, "csv", _status, _branches);
  utils::setStatus(_tree, name, "qgl", _status, _branches);
  utils::setStatus(_tree, name, "nhf", _status, _branches);
  utils::setStatus(_tree, name, "chf", _status, _branches);
  utils::setStatus(_tree, name, "id", _status, _branches);
  utils::setStatus(_tree, name, "constituents_", _status, _branches);
}

void
panda::PJet::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticleM::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "rawPt", &rawPt, _branches, _setStatus);
  utils::setAddress(_tree, name, "ptCorrUp", &ptCorrUp, _branches, _setStatus);
  utils::setAddress(_tree, name, "ptCorrDown", &ptCorrDown, _branches, _setStatus);
  utils::setAddress(_tree, name, "ptResCorr", &ptResCorr, _branches, _setStatus);
  utils::setAddress(_tree, name, "phiResCorr", &phiResCorr, _branches, _setStatus);
  utils::setAddress(_tree, name, "csv", &csv, _branches, _setStatus);
  utils::setAddress(_tree, name, "qgl", &qgl, _branches, _setStatus);
  utils::setAddress(_tree, name, "nhf", &nhf, _branches, _setStatus);
  utils::setAddress(_tree, name, "chf", &chf, _branches, _setStatus);
  utils::setAddress(_tree, name, "id", &id, _branches, _setStatus);
  utils::setAddress(_tree, name, "constituents_", &constituents.indices(), _branches, true);
}

void
panda::PJet::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "rawPt", "", 'F', &rawPt, _branches);
  utils::book(_tree, name, "ptCorrUp", "", 'F', &ptCorrUp, _branches);
  utils::book(_tree, name, "ptCorrDown", "", 'F', &ptCorrDown, _branches);
  utils::book(_tree, name, "ptResCorr", "", 'F', &ptResCorr, _branches);
  utils::book(_tree, name, "phiResCorr", "", 'F', &phiResCorr, _branches);
  utils::book(_tree, name, "csv", "", 'F', &csv, _branches);
  utils::book(_tree, name, "qgl", "", 'F', &qgl, _branches);
  utils::book(_tree, name, "nhf", "", 'F', &nhf, _branches);
  utils::book(_tree, name, "chf", "", 'F', &chf, _branches);
  utils::book(_tree, name, "id", "", 'i', &id, _branches);
  utils::book(_tree, name, "constituents_", "std::vector<UInt_t>", &constituents.indices(), _branches);
}

void
panda::PJet::resetAddress(TTree& _tree)
{
  PParticleM::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "rawPt");
  utils::resetAddress(_tree, name, "ptCorrUp");
  utils::resetAddress(_tree, name, "ptCorrDown");
  utils::resetAddress(_tree, name, "ptResCorr");
  utils::resetAddress(_tree, name, "phiResCorr");
  utils::resetAddress(_tree, name, "csv");
  utils::resetAddress(_tree, name, "qgl");
  utils::resetAddress(_tree, name, "nhf");
  utils::resetAddress(_tree, name, "chf");
  utils::resetAddress(_tree, name, "id");
  utils::resetAddress(_tree, name, "constituents_");
}

void
panda::PJet::init()
{
  PParticleM::init();

  rawPt = 0.;
  ptCorrUp = 0.;
  ptCorrDown = 0.;
  ptResCorr = 0.;
  phiResCorr = 0.;
  csv = 0.;
  qgl = 0.;
  nhf = 0.;
  chf = 0.;
  id = 0;
  constituents.init();
}

/* BEGIN CUSTOM */
/* END CUSTOM */
