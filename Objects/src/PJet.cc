#include "../interface/PJet.h"

void
panda::PJet::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::array_data::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "rawPt", _status, _branches);
  utils::setStatus(_tree, _name, "csv", _status, _branches);
  utils::setStatus(_tree, _name, "qgl", _status, _branches);
  utils::setStatus(_tree, _name, "nhf", _status, _branches);
  utils::setStatus(_tree, _name, "chf", _status, _branches);
  utils::setStatus(_tree, _name, "id", _status, _branches);
  utils::setStatus(_tree, _name, "constituents_", _status, _branches);
}

void
panda::PJet::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "rawPt", rawPt, _branches);
  utils::setStatusAndAddress(_tree, _name, "csv", csv, _branches);
  utils::setStatusAndAddress(_tree, _name, "qgl", qgl, _branches);
  utils::setStatusAndAddress(_tree, _name, "nhf", nhf, _branches);
  utils::setStatusAndAddress(_tree, _name, "chf", chf, _branches);
  utils::setStatusAndAddress(_tree, _name, "id", id, _branches);
  utils::setStatusAndAddress(_tree, _name, "constituents_", constituents_, _branches);
}

void
panda::PJet::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "rawPt", "[" + _name + ".size]", 'F', rawPt, _branches);
  utils::book(_tree, _name, "csv", "[" + _name + ".size]", 'F', csv, _branches);
  utils::book(_tree, _name, "qgl", "[" + _name + ".size]", 'F', qgl, _branches);
  utils::book(_tree, _name, "nhf", "[" + _name + ".size]", 'F', nhf, _branches);
  utils::book(_tree, _name, "chf", "[" + _name + ".size]", 'F', chf, _branches);
  utils::book(_tree, _name, "id", "[" + _name + ".size]", 'i', id, _branches);
  utils::book(_tree, _name, "constituents_", "[" + _name + ".size][128]", 'i', constituents_, _branches);
}

panda::PJet::PJet() :
  PObject(utils::Allocator<PJet>()),
  rawPt(gStore.getData(this).rawPt[gStore.getIndex(this)]),
  csv(gStore.getData(this).csv[gStore.getIndex(this)]),
  qgl(gStore.getData(this).qgl[gStore.getIndex(this)]),
  nhf(gStore.getData(this).nhf[gStore.getIndex(this)]),
  chf(gStore.getData(this).chf[gStore.getIndex(this)]),
  id(gStore.getData(this).id[gStore.getIndex(this)]),
  constituents_(gStore.getData(this).constituents_[gStore.getIndex(this)])
{
}

panda::PJet::PJet(PJet const& _src) :
  PObject(utils::Allocator<PJet>()),
  rawPt(gStore.getData(this).rawPt[gStore.getIndex(this)]),
  csv(gStore.getData(this).csv[gStore.getIndex(this)]),
  qgl(gStore.getData(this).qgl[gStore.getIndex(this)]),
  nhf(gStore.getData(this).nhf[gStore.getIndex(this)]),
  chf(gStore.getData(this).chf[gStore.getIndex(this)]),
  id(gStore.getData(this).id[gStore.getIndex(this)]),
  constituents_(gStore.getData(this).constituents_[gStore.getIndex(this)])
{
  PObject::operator=(_src);

  rawPt = _src.rawPt;
  csv = _src.csv;
  qgl = _src.qgl;
  nhf = _src.nhf;
  chf = _src.chf;
  id = _src.id;
}

panda::PJet::PJet(array_data& _data, UInt_t _idx) :
  PObject(_data, _idx),
  rawPt(_data.rawPt[_idx]),
  csv(_data.csv[_idx]),
  qgl(_data.qgl[_idx]),
  nhf(_data.nhf[_idx]),
  chf(_data.chf[_idx]),
  id(_data.id[_idx]),
  constituents_(_data.constituents_[_idx])
{
}

panda::PJet::PJet(utils::AllocatorBase const& _allocator) :
  PObject(_allocator),
  rawPt(gStore.getData(this).rawPt[gStore.getIndex(this)]),
  csv(gStore.getData(this).csv[gStore.getIndex(this)]),
  qgl(gStore.getData(this).qgl[gStore.getIndex(this)]),
  nhf(gStore.getData(this).nhf[gStore.getIndex(this)]),
  chf(gStore.getData(this).chf[gStore.getIndex(this)]),
  id(gStore.getData(this).id[gStore.getIndex(this)]),
  constituents_(gStore.getData(this).constituents_[gStore.getIndex(this)])
{
}

panda::PJet::~PJet()
{
  gStore.free(this);
}

panda::PJet&
panda::PJet::operator=(PJet const& _src)
{
  PObject::operator=(_src);

  rawPt = _src.rawPt;
  csv = _src.csv;
  qgl = _src.qgl;
  nhf = _src.nhf;
  chf = _src.chf;
  id = _src.id;

  return *this;
}

void
panda::PJet::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "rawPt", _status, _branches);
  utils::setStatus(_tree, _name, "csv", _status, _branches);
  utils::setStatus(_tree, _name, "qgl", _status, _branches);
  utils::setStatus(_tree, _name, "nhf", _status, _branches);
  utils::setStatus(_tree, _name, "chf", _status, _branches);
  utils::setStatus(_tree, _name, "id", _status, _branches);
  utils::setStatus(_tree, _name, "constituents_", _status, _branches);
}

void
panda::PJet::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "rawPt", &rawPt, _branches);
  utils::setStatusAndAddress(_tree, _name, "csv", &csv, _branches);
  utils::setStatusAndAddress(_tree, _name, "qgl", &qgl, _branches);
  utils::setStatusAndAddress(_tree, _name, "nhf", &nhf, _branches);
  utils::setStatusAndAddress(_tree, _name, "chf", &chf, _branches);
  utils::setStatusAndAddress(_tree, _name, "id", &id, _branches);
  utils::setStatusAndAddress(_tree, _name, "constituents_", constituents_, _branches);
}

void
panda::PJet::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::book(_tree, _name, _branches);

  utils::book(_tree, _name, "rawPt", "", 'F', &rawPt, _branches);
  utils::book(_tree, _name, "csv", "", 'F', &csv, _branches);
  utils::book(_tree, _name, "qgl", "", 'F', &qgl, _branches);
  utils::book(_tree, _name, "nhf", "", 'F', &nhf, _branches);
  utils::book(_tree, _name, "chf", "", 'F', &chf, _branches);
  utils::book(_tree, _name, "id", "", 'i', &id, _branches);
  utils::book(_tree, _name, "constituents_", "[128]", 'i', constituents_, _branches);
}

void
panda::PJet::init()
{
  PObject::init();

  rawPt = 0.;
  csv = 0.;
  qgl = 0.;
  nhf = 0.;
  chf = 0.;
  id = 0;
  for (auto& p0 : constituents_) p0 = PPFCand::array_data::NMAX;
}

/* BEGIN CUSTOM */
/* END CUSTOM */
