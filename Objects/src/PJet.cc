#include "../interface/PJet.h"

void
panda::PJet::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::array_data::setStatus(_tree, _name, _status, _branches);

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
  utils::setStatus(_tree, _name, "nConstituents", _status, _branches);
  utils::setStatus(_tree, _name, "constituents_", _status, _branches);
}

void
panda::PJet::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "rawPt", rawPt, _branches);
  utils::setStatusAndAddress(_tree, _name, "ptCorrUp", ptCorrUp, _branches);
  utils::setStatusAndAddress(_tree, _name, "ptCorrDown", ptCorrDown, _branches);
  utils::setStatusAndAddress(_tree, _name, "ptResCorr", ptResCorr, _branches);
  utils::setStatusAndAddress(_tree, _name, "phiResCorr", phiResCorr, _branches);
  utils::setStatusAndAddress(_tree, _name, "csv", csv, _branches);
  utils::setStatusAndAddress(_tree, _name, "qgl", qgl, _branches);
  utils::setStatusAndAddress(_tree, _name, "nhf", nhf, _branches);
  utils::setStatusAndAddress(_tree, _name, "chf", chf, _branches);
  utils::setStatusAndAddress(_tree, _name, "id", id, _branches);
  utils::setStatusAndAddress(_tree, _name, "nConstituents", nConstituents, _branches);
  utils::setStatusAndAddress(_tree, _name, "constituents_", constituents_, _branches);
}

void
panda::PJet::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "rawPt", "[" + _name + ".size]", 'F', rawPt, _branches);
  utils::book(_tree, _name, "ptCorrUp", "[" + _name + ".size]", 'F', ptCorrUp, _branches);
  utils::book(_tree, _name, "ptCorrDown", "[" + _name + ".size]", 'F', ptCorrDown, _branches);
  utils::book(_tree, _name, "ptResCorr", "[" + _name + ".size]", 'F', ptResCorr, _branches);
  utils::book(_tree, _name, "phiResCorr", "[" + _name + ".size]", 'F', phiResCorr, _branches);
  utils::book(_tree, _name, "csv", "[" + _name + ".size]", 'F', csv, _branches);
  utils::book(_tree, _name, "qgl", "[" + _name + ".size]", 'F', qgl, _branches);
  utils::book(_tree, _name, "nhf", "[" + _name + ".size]", 'F', nhf, _branches);
  utils::book(_tree, _name, "chf", "[" + _name + ".size]", 'F', chf, _branches);
  utils::book(_tree, _name, "id", "[" + _name + ".size]", 'i', id, _branches);
  utils::book(_tree, _name, "nConstituents", "[" + _name + ".size]", 'i', nConstituents, _branches);
  utils::book(_tree, _name, "constituents_", "[" + _name + ".size][128]", 'i', constituents_, _branches);
}

panda::PJet::PJet(char const* _name/* = ""*/) :
  PParticleM(utils::Allocator<PJet>(), _name),
  rawPt(gStore.getData(this).rawPt[gStore.getIndex(this)]),
  ptCorrUp(gStore.getData(this).ptCorrUp[gStore.getIndex(this)]),
  ptCorrDown(gStore.getData(this).ptCorrDown[gStore.getIndex(this)]),
  ptResCorr(gStore.getData(this).ptResCorr[gStore.getIndex(this)]),
  phiResCorr(gStore.getData(this).phiResCorr[gStore.getIndex(this)]),
  csv(gStore.getData(this).csv[gStore.getIndex(this)]),
  qgl(gStore.getData(this).qgl[gStore.getIndex(this)]),
  nhf(gStore.getData(this).nhf[gStore.getIndex(this)]),
  chf(gStore.getData(this).chf[gStore.getIndex(this)]),
  id(gStore.getData(this).id[gStore.getIndex(this)]),
  nConstituents(gStore.getData(this).nConstituents[gStore.getIndex(this)])
{
  UInt_t (&indices)[128](gStore.getData(this).constituents_[gStore.getIndex(this)]);
  constituents = reinterpret_cast<PPFCandRef*>(std::allocator<PPFCandRef>().allocate(128));
  unsigned r(0);
  for (UInt_t& idx : indices) {
    new (constituents + r) PPFCandRef(idx);
    ++r;
    }
}

panda::PJet::PJet(array_data& _data, UInt_t _idx) :
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
  nConstituents(_data.nConstituents[_idx])
{
  UInt_t (&indices)[128](gStore.getData(this).constituents_[gStore.getIndex(this)]);
  constituents = reinterpret_cast<PPFCandRef*>(std::allocator<PPFCandRef>().allocate(128));
  unsigned r(0);
  for (UInt_t& idx : indices) {
    new (constituents + r) PPFCandRef(idx);
    ++r;
    }
}

panda::PJet::PJet(PJet const& _src) :
  PParticleM(utils::Allocator<PJet>(), gStore.getName(&_src)),
  rawPt(gStore.getData(this).rawPt[gStore.getIndex(this)]),
  ptCorrUp(gStore.getData(this).ptCorrUp[gStore.getIndex(this)]),
  ptCorrDown(gStore.getData(this).ptCorrDown[gStore.getIndex(this)]),
  ptResCorr(gStore.getData(this).ptResCorr[gStore.getIndex(this)]),
  phiResCorr(gStore.getData(this).phiResCorr[gStore.getIndex(this)]),
  csv(gStore.getData(this).csv[gStore.getIndex(this)]),
  qgl(gStore.getData(this).qgl[gStore.getIndex(this)]),
  nhf(gStore.getData(this).nhf[gStore.getIndex(this)]),
  chf(gStore.getData(this).chf[gStore.getIndex(this)]),
  id(gStore.getData(this).id[gStore.getIndex(this)]),
  nConstituents(gStore.getData(this).nConstituents[gStore.getIndex(this)])
{
  UInt_t (&indices)[128](gStore.getData(this).constituents_[gStore.getIndex(this)]);
  constituents = reinterpret_cast<PPFCandRef*>(std::allocator<PPFCandRef>().allocate(128));
  unsigned r(0);
  for (UInt_t& idx : indices) {
    new (constituents + r) PPFCandRef(idx);
    ++r;
    }
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
  nConstituents = _src.nConstituents;
  for (UInt_t i0(0); i0 != 128; ++i0) {
    constituents[i0] = _src.constituents[i0];
  }
}

panda::PJet::PJet(utils::AllocatorBase const& _allocator, char const* _name) :
  PParticleM(_allocator, _name),
  rawPt(gStore.getData(this).rawPt[gStore.getIndex(this)]),
  ptCorrUp(gStore.getData(this).ptCorrUp[gStore.getIndex(this)]),
  ptCorrDown(gStore.getData(this).ptCorrDown[gStore.getIndex(this)]),
  ptResCorr(gStore.getData(this).ptResCorr[gStore.getIndex(this)]),
  phiResCorr(gStore.getData(this).phiResCorr[gStore.getIndex(this)]),
  csv(gStore.getData(this).csv[gStore.getIndex(this)]),
  qgl(gStore.getData(this).qgl[gStore.getIndex(this)]),
  nhf(gStore.getData(this).nhf[gStore.getIndex(this)]),
  chf(gStore.getData(this).chf[gStore.getIndex(this)]),
  id(gStore.getData(this).id[gStore.getIndex(this)]),
  nConstituents(gStore.getData(this).nConstituents[gStore.getIndex(this)])
{
  UInt_t (&indices)[128](gStore.getData(this).constituents_[gStore.getIndex(this)]);
  constituents = reinterpret_cast<PPFCandRef*>(std::allocator<PPFCandRef>().allocate(128));
  unsigned r(0);
  for (UInt_t& idx : indices) {
    new (constituents + r) PPFCandRef(idx);
    ++r;
    }
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
  nConstituents = _src.nConstituents;
  for (UInt_t i0(0); i0 != 128; ++i0) {
    constituents[i0] = _src.constituents[i0];
  }

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
  utils::setStatus(_tree, name, "nConstituents", _status, _branches);
  utils::setStatus(_tree, name, "constituents_", _status, _branches);
}

void
panda::PJet::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticleM::setAddress(_tree, _branches);

  TString name(gStore.getName(this));

  utils::setStatusAndAddress(_tree, name, "rawPt", &rawPt, _branches);
  utils::setStatusAndAddress(_tree, name, "ptCorrUp", &ptCorrUp, _branches);
  utils::setStatusAndAddress(_tree, name, "ptCorrDown", &ptCorrDown, _branches);
  utils::setStatusAndAddress(_tree, name, "ptResCorr", &ptResCorr, _branches);
  utils::setStatusAndAddress(_tree, name, "phiResCorr", &phiResCorr, _branches);
  utils::setStatusAndAddress(_tree, name, "csv", &csv, _branches);
  utils::setStatusAndAddress(_tree, name, "qgl", &qgl, _branches);
  utils::setStatusAndAddress(_tree, name, "nhf", &nhf, _branches);
  utils::setStatusAndAddress(_tree, name, "chf", &chf, _branches);
  utils::setStatusAndAddress(_tree, name, "id", &id, _branches);
  utils::setStatusAndAddress(_tree, name, "nConstituents", &nConstituents, _branches);
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
  utils::book(_tree, name, "nConstituents", "", 'i', &nConstituents, _branches);
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
  nConstituents = 0;
}

/* BEGIN CUSTOM */
/* END CUSTOM */
