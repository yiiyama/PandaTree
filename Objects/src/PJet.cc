#include "../interface/PJet.h"

void
panda::PJet::datastore::allocate(UInt_t _nmax)
{
  PParticleM::datastore::allocate(_nmax);

  rawPt = new Float_t[nmax_];
  ptCorrUp = new Float_t[nmax_];
  ptCorrDown = new Float_t[nmax_];
  ptSmear = new Float_t[nmax_];
  ptSmearUp = new Float_t[nmax_];
  ptSmearDown = new Float_t[nmax_];
  csv = new Float_t[nmax_];
  nhf = new Float_t[nmax_];
  chf = new Float_t[nmax_];
  loose = new Bool_t[nmax_];
  tight = new Bool_t[nmax_];
  monojet = new Bool_t[nmax_];
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
  delete [] ptSmear;
  ptSmear = 0;
  delete [] ptSmearUp;
  ptSmearUp = 0;
  delete [] ptSmearDown;
  ptSmearDown = 0;
  delete [] csv;
  csv = 0;
  delete [] nhf;
  nhf = 0;
  delete [] chf;
  chf = 0;
  delete [] loose;
  loose = 0;
  delete [] tight;
  tight = 0;
  delete [] monojet;
  monojet = 0;
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
  utils::setStatus(_tree, _name, "ptSmear", _status, _branches);
  utils::setStatus(_tree, _name, "ptSmearUp", _status, _branches);
  utils::setStatus(_tree, _name, "ptSmearDown", _status, _branches);
  utils::setStatus(_tree, _name, "csv", _status, _branches);
  utils::setStatus(_tree, _name, "nhf", _status, _branches);
  utils::setStatus(_tree, _name, "chf", _status, _branches);
  utils::setStatus(_tree, _name, "loose", _status, _branches);
  utils::setStatus(_tree, _name, "tight", _status, _branches);
  utils::setStatus(_tree, _name, "monojet", _status, _branches);
  utils::setStatus(_tree, _name, "constituents_", _status, _branches);
}

void
panda::PJet::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "rawPt", rawPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptCorrUp", ptCorrUp, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptCorrDown", ptCorrDown, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptSmear", ptSmear, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptSmearUp", ptSmearUp, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptSmearDown", ptSmearDown, _branches, _setStatus);
  utils::setAddress(_tree, _name, "csv", csv, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhf", nhf, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chf", chf, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose", loose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight", tight, _branches, _setStatus);
  utils::setAddress(_tree, _name, "monojet", monojet, _branches, _setStatus);
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
  utils::book(_tree, _name, "ptSmear", size, 'F', ptSmear, _branches);
  utils::book(_tree, _name, "ptSmearUp", size, 'F', ptSmearUp, _branches);
  utils::book(_tree, _name, "ptSmearDown", size, 'F', ptSmearDown, _branches);
  utils::book(_tree, _name, "csv", size, 'F', csv, _branches);
  utils::book(_tree, _name, "nhf", size, 'F', nhf, _branches);
  utils::book(_tree, _name, "chf", size, 'F', chf, _branches);
  utils::book(_tree, _name, "loose", size, 'O', loose, _branches);
  utils::book(_tree, _name, "tight", size, 'O', tight, _branches);
  utils::book(_tree, _name, "monojet", size, 'O', monojet, _branches);
  utils::book(_tree, _name, "constituents_", "std::vector<std::vector<UInt_t>>", &constituents_, _branches);
}

void
panda::PJet::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  PParticleM::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "rawPt");
  utils::resetAddress(_tree, _name, "ptCorrUp");
  utils::resetAddress(_tree, _name, "ptCorrDown");
  utils::resetAddress(_tree, _name, "ptSmear");
  utils::resetAddress(_tree, _name, "ptSmearUp");
  utils::resetAddress(_tree, _name, "ptSmearDown");
  utils::resetAddress(_tree, _name, "csv");
  utils::resetAddress(_tree, _name, "nhf");
  utils::resetAddress(_tree, _name, "chf");
  utils::resetAddress(_tree, _name, "loose");
  utils::resetAddress(_tree, _name, "tight");
  utils::resetAddress(_tree, _name, "monojet");
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
  ptSmear(gStore.getData(this).ptSmear[0]),
  ptSmearUp(gStore.getData(this).ptSmearUp[0]),
  ptSmearDown(gStore.getData(this).ptSmearDown[0]),
  csv(gStore.getData(this).csv[0]),
  nhf(gStore.getData(this).nhf[0]),
  chf(gStore.getData(this).chf[0]),
  loose(gStore.getData(this).loose[0]),
  tight(gStore.getData(this).tight[0]),
  monojet(gStore.getData(this).monojet[0]),
  constituents((*gStore.getData(this).constituents_)[0])
{
}

panda::PJet::PJet(datastore& _data, UInt_t _idx) :
  PParticleM(_data, _idx),
  rawPt(_data.rawPt[_idx]),
  ptCorrUp(_data.ptCorrUp[_idx]),
  ptCorrDown(_data.ptCorrDown[_idx]),
  ptSmear(_data.ptSmear[_idx]),
  ptSmearUp(_data.ptSmearUp[_idx]),
  ptSmearDown(_data.ptSmearDown[_idx]),
  csv(_data.csv[_idx]),
  nhf(_data.nhf[_idx]),
  chf(_data.chf[_idx]),
  loose(_data.loose[_idx]),
  tight(_data.tight[_idx]),
  monojet(_data.monojet[_idx]),
  constituents((*_data.constituents_)[_idx])
{
}

panda::PJet::PJet(PJet const& _src) :
  PParticleM(new PJetArray(1, gStore.getName(&_src))),
  rawPt(gStore.getData(this).rawPt[0]),
  ptCorrUp(gStore.getData(this).ptCorrUp[0]),
  ptCorrDown(gStore.getData(this).ptCorrDown[0]),
  ptSmear(gStore.getData(this).ptSmear[0]),
  ptSmearUp(gStore.getData(this).ptSmearUp[0]),
  ptSmearDown(gStore.getData(this).ptSmearDown[0]),
  csv(gStore.getData(this).csv[0]),
  nhf(gStore.getData(this).nhf[0]),
  chf(gStore.getData(this).chf[0]),
  loose(gStore.getData(this).loose[0]),
  tight(gStore.getData(this).tight[0]),
  monojet(gStore.getData(this).monojet[0]),
  constituents((*gStore.getData(this).constituents_)[0])
{
  PParticleM::operator=(_src);

  rawPt = _src.rawPt;
  ptCorrUp = _src.ptCorrUp;
  ptCorrDown = _src.ptCorrDown;
  ptSmear = _src.ptSmear;
  ptSmearUp = _src.ptSmearUp;
  ptSmearDown = _src.ptSmearDown;
  csv = _src.csv;
  nhf = _src.nhf;
  chf = _src.chf;
  loose = _src.loose;
  tight = _src.tight;
  monojet = _src.monojet;
  constituents = _src.constituents;
}

panda::PJet::PJet(ArrayBase* _array) :
  PParticleM(_array),
  rawPt(gStore.getData(this).rawPt[0]),
  ptCorrUp(gStore.getData(this).ptCorrUp[0]),
  ptCorrDown(gStore.getData(this).ptCorrDown[0]),
  ptSmear(gStore.getData(this).ptSmear[0]),
  ptSmearUp(gStore.getData(this).ptSmearUp[0]),
  ptSmearDown(gStore.getData(this).ptSmearDown[0]),
  csv(gStore.getData(this).csv[0]),
  nhf(gStore.getData(this).nhf[0]),
  chf(gStore.getData(this).chf[0]),
  loose(gStore.getData(this).loose[0]),
  tight(gStore.getData(this).tight[0]),
  monojet(gStore.getData(this).monojet[0]),
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
  ptSmear = _src.ptSmear;
  ptSmearUp = _src.ptSmearUp;
  ptSmearDown = _src.ptSmearDown;
  csv = _src.csv;
  nhf = _src.nhf;
  chf = _src.chf;
  loose = _src.loose;
  tight = _src.tight;
  monojet = _src.monojet;
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
  utils::setStatus(_tree, name, "ptSmear", _status, _branches);
  utils::setStatus(_tree, name, "ptSmearUp", _status, _branches);
  utils::setStatus(_tree, name, "ptSmearDown", _status, _branches);
  utils::setStatus(_tree, name, "csv", _status, _branches);
  utils::setStatus(_tree, name, "nhf", _status, _branches);
  utils::setStatus(_tree, name, "chf", _status, _branches);
  utils::setStatus(_tree, name, "loose", _status, _branches);
  utils::setStatus(_tree, name, "tight", _status, _branches);
  utils::setStatus(_tree, name, "monojet", _status, _branches);
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
  utils::setAddress(_tree, name, "ptSmear", &ptSmear, _branches, _setStatus);
  utils::setAddress(_tree, name, "ptSmearUp", &ptSmearUp, _branches, _setStatus);
  utils::setAddress(_tree, name, "ptSmearDown", &ptSmearDown, _branches, _setStatus);
  utils::setAddress(_tree, name, "csv", &csv, _branches, _setStatus);
  utils::setAddress(_tree, name, "nhf", &nhf, _branches, _setStatus);
  utils::setAddress(_tree, name, "chf", &chf, _branches, _setStatus);
  utils::setAddress(_tree, name, "loose", &loose, _branches, _setStatus);
  utils::setAddress(_tree, name, "tight", &tight, _branches, _setStatus);
  utils::setAddress(_tree, name, "monojet", &monojet, _branches, _setStatus);
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
  utils::book(_tree, name, "ptSmear", "", 'F', &ptSmear, _branches);
  utils::book(_tree, name, "ptSmearUp", "", 'F', &ptSmearUp, _branches);
  utils::book(_tree, name, "ptSmearDown", "", 'F', &ptSmearDown, _branches);
  utils::book(_tree, name, "csv", "", 'F', &csv, _branches);
  utils::book(_tree, name, "nhf", "", 'F', &nhf, _branches);
  utils::book(_tree, name, "chf", "", 'F', &chf, _branches);
  utils::book(_tree, name, "loose", "", 'O', &loose, _branches);
  utils::book(_tree, name, "tight", "", 'O', &tight, _branches);
  utils::book(_tree, name, "monojet", "", 'O', &monojet, _branches);
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
  utils::resetAddress(_tree, name, "ptSmear");
  utils::resetAddress(_tree, name, "ptSmearUp");
  utils::resetAddress(_tree, name, "ptSmearDown");
  utils::resetAddress(_tree, name, "csv");
  utils::resetAddress(_tree, name, "nhf");
  utils::resetAddress(_tree, name, "chf");
  utils::resetAddress(_tree, name, "loose");
  utils::resetAddress(_tree, name, "tight");
  utils::resetAddress(_tree, name, "monojet");
  utils::resetAddress(_tree, name, "constituents_");
}

void
panda::PJet::init()
{
  PParticleM::init();

  rawPt = 0.;
  ptCorrUp = 0.;
  ptCorrDown = 0.;
  ptSmear = 0.;
  ptSmearUp = 0.;
  ptSmearDown = 0.;
  csv = 0.;
  nhf = 0.;
  chf = 0.;
  loose = false;
  tight = false;
  monojet = false;
  constituents.init();
}

/* BEGIN CUSTOM */
/* END CUSTOM */
