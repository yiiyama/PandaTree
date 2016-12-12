#include "../interface/MicroJet.h"

void
panda::MicroJet::datastore::allocate(UInt_t _nmax)
{
  ParticleM::datastore::allocate(_nmax);

  csv = new Float_t[nmax_];
  qgl = new Float_t[nmax_];
  constituents_ = new std::vector<std::vector<UInt_t>>(nmax_);
}

void
panda::MicroJet::datastore::deallocate()
{
  ParticleM::datastore::deallocate();

  delete [] csv;
  csv = 0;
  delete [] qgl;
  qgl = 0;
  delete constituents_;
  constituents_ = 0;
}

void
panda::MicroJet::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  ParticleM::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "csv", _status, _branches);
  utils::setStatus(_tree, _name, "qgl", _status, _branches);
  utils::setStatus(_tree, _name, "constituents_", _status, _branches);
}

void
panda::MicroJet::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "csv", csv, _branches, _setStatus);
  utils::setAddress(_tree, _name, "qgl", qgl, _branches, _setStatus);
  utils::setAddress(_tree, _name, "constituents_", &constituents_, _branches, _setStatus);
}

void
panda::MicroJet::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "csv", size, 'F', csv, _branches);
  utils::book(_tree, _name, "qgl", size, 'F', qgl, _branches);
  utils::book(_tree, _name, "constituents_", "std::vector<std::vector<UInt_t>>", &constituents_, _branches);
}

void
panda::MicroJet::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  ParticleM::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "csv");
  utils::resetAddress(_tree, _name, "qgl");
  utils::resetAddress(_tree, _name, "constituents_");
}

void
panda::MicroJet::datastore::resizeVectors_(UInt_t _size)
{
  ParticleM::datastore::resizeVectors_(_size);

  constituents_->resize(_size);
}

panda::MicroJet::MicroJet(char const* _name/* = ""*/) :
  ParticleM(new MicroJetArray(1, _name)),
  csv(gStore.getData(this).csv[0]),
  qgl(gStore.getData(this).qgl[0]),
  constituents(gStore.getData(this).constituentsContainer_, (*gStore.getData(this).constituents_)[0])
{
}

panda::MicroJet::MicroJet(datastore& _data, UInt_t _idx) :
  ParticleM(_data, _idx),
  csv(_data.csv[_idx]),
  qgl(_data.qgl[_idx]),
  constituents(_data.constituentsContainer_, (*_data.constituents_)[_idx])
{
}

panda::MicroJet::MicroJet(MicroJet const& _src) :
  ParticleM(new MicroJetArray(1, gStore.getName(&_src))),
  csv(gStore.getData(this).csv[0]),
  qgl(gStore.getData(this).qgl[0]),
  constituents(gStore.getData(this).constituentsContainer_, (*gStore.getData(this).constituents_)[0])
{
  ParticleM::operator=(_src);

  csv = _src.csv;
  qgl = _src.qgl;
  constituents = _src.constituents;
}

panda::MicroJet::MicroJet(ArrayBase* _array) :
  ParticleM(_array),
  csv(gStore.getData(this).csv[0]),
  qgl(gStore.getData(this).qgl[0]),
  constituents(gStore.getData(this).constituentsContainer_, (*gStore.getData(this).constituents_)[0])
{
}

panda::MicroJet::~MicroJet()
{
  destructor();
  gStore.free(this);
}

void
panda::MicroJet::destructor()
{
  /* BEGIN CUSTOM MicroJet.cc.destructor */
  /* END CUSTOM */

  ParticleM::destructor();
}

panda::MicroJet&
panda::MicroJet::operator=(MicroJet const& _src)
{
  ParticleM::operator=(_src);

  csv = _src.csv;
  qgl = _src.qgl;
  constituents = _src.constituents;

  return *this;
}

void
panda::MicroJet::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  ParticleM::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "csv", _status, _branches);
  utils::setStatus(_tree, name, "qgl", _status, _branches);
  utils::setStatus(_tree, name, "constituents_", _status, _branches);
}

void
panda::MicroJet::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "csv", &csv, _branches, _setStatus);
  utils::setAddress(_tree, name, "qgl", &qgl, _branches, _setStatus);
  utils::setAddress(_tree, name, "constituents_", &constituents.indices(), _branches, true);
}

void
panda::MicroJet::book(TTree& _tree, utils::BranchList const& _branches/* = {}*/)
{
  ParticleM::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "csv", "", 'F', &csv, _branches);
  utils::book(_tree, name, "qgl", "", 'F', &qgl, _branches);
  utils::book(_tree, name, "constituents_", "std::vector<UInt_t>", &constituents.indices(), _branches);
}

void
panda::MicroJet::resetAddress(TTree& _tree)
{
  ParticleM::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "csv");
  utils::resetAddress(_tree, name, "qgl");
  utils::resetAddress(_tree, name, "constituents_");
}

void
panda::MicroJet::init()
{
  ParticleM::init();

  csv = 0.;
  qgl = 0.;
  constituents.init();
}

/* BEGIN CUSTOM MicroJet.cc.global */
/* END CUSTOM */
