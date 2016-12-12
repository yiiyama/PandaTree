#include "../interface/PMicroJet.h"

void
panda::PMicroJet::datastore::allocate(UInt_t _nmax)
{
  PParticleM::datastore::allocate(_nmax);

  csv = new Float_t[nmax_];
  qgl = new Float_t[nmax_];
  constituents_ = new std::vector<std::vector<UInt_t>>(nmax_);
}

void
panda::PMicroJet::datastore::deallocate()
{
  PParticleM::datastore::deallocate();

  delete [] csv;
  csv = 0;
  delete [] qgl;
  qgl = 0;
  delete constituents_;
  constituents_ = 0;
}

void
panda::PMicroJet::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  PParticleM::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "csv", _status, _branches);
  utils::setStatus(_tree, _name, "qgl", _status, _branches);
  utils::setStatus(_tree, _name, "constituents_", _status, _branches);
}

void
panda::PMicroJet::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "csv", csv, _branches, _setStatus);
  utils::setAddress(_tree, _name, "qgl", qgl, _branches, _setStatus);
  utils::setAddress(_tree, _name, "constituents_", &constituents_, _branches, _setStatus);
}

void
panda::PMicroJet::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "csv", size, 'F', csv, _branches);
  utils::book(_tree, _name, "qgl", size, 'F', qgl, _branches);
  utils::book(_tree, _name, "constituents_", "std::vector<std::vector<UInt_t>>", &constituents_, _branches);
}

void
panda::PMicroJet::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  PParticleM::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "csv");
  utils::resetAddress(_tree, _name, "qgl");
  utils::resetAddress(_tree, _name, "constituents_");
}

void
panda::PMicroJet::datastore::resizeVectors_(UInt_t _size)
{
  PParticleM::datastore::resizeVectors_(_size);

  constituents_->resize(_size);
}

panda::PMicroJet::PMicroJet(char const* _name/* = ""*/) :
  PParticleM(new PMicroJetArray(1, _name)),
  csv(gStore.getData(this).csv[0]),
  qgl(gStore.getData(this).qgl[0]),
  constituents(gStore.getData(this).constituentsContainer_, (*gStore.getData(this).constituents_)[0])
{
}

panda::PMicroJet::PMicroJet(datastore& _data, UInt_t _idx) :
  PParticleM(_data, _idx),
  csv(_data.csv[_idx]),
  qgl(_data.qgl[_idx]),
  constituents(_data.constituentsContainer_, (*_data.constituents_)[_idx])
{
}

panda::PMicroJet::PMicroJet(PMicroJet const& _src) :
  PParticleM(new PMicroJetArray(1, gStore.getName(&_src))),
  csv(gStore.getData(this).csv[0]),
  qgl(gStore.getData(this).qgl[0]),
  constituents(gStore.getData(this).constituentsContainer_, (*gStore.getData(this).constituents_)[0])
{
  PParticleM::operator=(_src);

  csv = _src.csv;
  qgl = _src.qgl;
  constituents = _src.constituents;
}

panda::PMicroJet::PMicroJet(ArrayBase* _array) :
  PParticleM(_array),
  csv(gStore.getData(this).csv[0]),
  qgl(gStore.getData(this).qgl[0]),
  constituents(gStore.getData(this).constituentsContainer_, (*gStore.getData(this).constituents_)[0])
{
}

panda::PMicroJet::~PMicroJet()
{
  destructor();
  gStore.free(this);
}

void
panda::PMicroJet::destructor()
{
  /* BEGIN CUSTOM PMicroJet.cc.destructor */
  /* END CUSTOM */

  PParticleM::destructor();
}

panda::PMicroJet&
panda::PMicroJet::operator=(PMicroJet const& _src)
{
  PParticleM::operator=(_src);

  csv = _src.csv;
  qgl = _src.qgl;
  constituents = _src.constituents;

  return *this;
}

void
panda::PMicroJet::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  PParticleM::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "csv", _status, _branches);
  utils::setStatus(_tree, name, "qgl", _status, _branches);
  utils::setStatus(_tree, name, "constituents_", _status, _branches);
}

void
panda::PMicroJet::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticleM::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "csv", &csv, _branches, _setStatus);
  utils::setAddress(_tree, name, "qgl", &qgl, _branches, _setStatus);
  utils::setAddress(_tree, name, "constituents_", &constituents.indices(), _branches, true);
}

void
panda::PMicroJet::book(TTree& _tree, utils::BranchList const& _branches/* = {}*/)
{
  PParticleM::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "csv", "", 'F', &csv, _branches);
  utils::book(_tree, name, "qgl", "", 'F', &qgl, _branches);
  utils::book(_tree, name, "constituents_", "std::vector<UInt_t>", &constituents.indices(), _branches);
}

void
panda::PMicroJet::resetAddress(TTree& _tree)
{
  PParticleM::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "csv");
  utils::resetAddress(_tree, name, "qgl");
  utils::resetAddress(_tree, name, "constituents_");
}

void
panda::PMicroJet::init()
{
  PParticleM::init();

  csv = 0.;
  qgl = 0.;
  constituents.init();
}

/* BEGIN CUSTOM PMicroJet.cc.global */
/* END CUSTOM */
