#include "../interface/PFatJet.h"

void
panda::PFatJet::datastore::allocate(UInt_t _nmax)
{
  PJet::datastore::allocate(_nmax);

  tau1 = new Float_t[nmax_];
  tau2 = new Float_t[nmax_];
  tau3 = new Float_t[nmax_];
  mSD = new Float_t[nmax_];
  tau1SD = new Float_t[nmax_];
  tau2SD = new Float_t[nmax_];
  tau3SD = new Float_t[nmax_];
  htt_mass = new Float_t[nmax_];
  htt_frec = new Float_t[nmax_];
  ecfs = new Float_t[nmax_][3][4][4];
  subjets_ = new std::vector<std::vector<UInt_t>>(nmax_);
}

void
panda::PFatJet::datastore::deallocate()
{
  PJet::datastore::deallocate();

  delete [] tau1;
  tau1 = 0;
  delete [] tau2;
  tau2 = 0;
  delete [] tau3;
  tau3 = 0;
  delete [] mSD;
  mSD = 0;
  delete [] tau1SD;
  tau1SD = 0;
  delete [] tau2SD;
  tau2SD = 0;
  delete [] tau3SD;
  tau3SD = 0;
  delete [] htt_mass;
  htt_mass = 0;
  delete [] htt_frec;
  htt_frec = 0;
  delete [] ecfs;
  ecfs = 0;
  delete subjets_;
  subjets_ = 0;
}

void
panda::PFatJet::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PJet::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "tau1", _status, _branches);
  utils::setStatus(_tree, _name, "tau2", _status, _branches);
  utils::setStatus(_tree, _name, "tau3", _status, _branches);
  utils::setStatus(_tree, _name, "mSD", _status, _branches);
  utils::setStatus(_tree, _name, "tau1SD", _status, _branches);
  utils::setStatus(_tree, _name, "tau2SD", _status, _branches);
  utils::setStatus(_tree, _name, "tau3SD", _status, _branches);
  utils::setStatus(_tree, _name, "htt_mass", _status, _branches);
  utils::setStatus(_tree, _name, "htt_frec", _status, _branches);
  utils::setStatus(_tree, _name, "ecfs", _status, _branches);
  utils::setStatus(_tree, _name, "subjets_", _status, _branches);
}

void
panda::PFatJet::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PJet::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "tau1", tau1, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tau2", tau2, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tau3", tau3, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mSD", mSD, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tau1SD", tau1SD, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tau2SD", tau2SD, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tau3SD", tau3SD, _branches, _setStatus);
  utils::setAddress(_tree, _name, "htt_mass", htt_mass, _branches, _setStatus);
  utils::setAddress(_tree, _name, "htt_frec", htt_frec, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ecfs", ecfs, _branches, _setStatus);
  utils::setAddress(_tree, _name, "subjets_", &subjets_, _branches, _setStatus);
}

void
panda::PFatJet::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PJet::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "tau1", size, 'F', tau1, _branches);
  utils::book(_tree, _name, "tau2", size, 'F', tau2, _branches);
  utils::book(_tree, _name, "tau3", size, 'F', tau3, _branches);
  utils::book(_tree, _name, "mSD", size, 'F', mSD, _branches);
  utils::book(_tree, _name, "tau1SD", size, 'F', tau1SD, _branches);
  utils::book(_tree, _name, "tau2SD", size, 'F', tau2SD, _branches);
  utils::book(_tree, _name, "tau3SD", size, 'F', tau3SD, _branches);
  utils::book(_tree, _name, "htt_mass", size, 'F', htt_mass, _branches);
  utils::book(_tree, _name, "htt_frec", size, 'F', htt_frec, _branches);
  utils::book(_tree, _name, "ecfs", size + "[3][4][4]", 'F', ecfs, _branches);
  utils::book(_tree, _name, "subjets_", "std::vector<std::vector<UInt_t>>", &subjets_, _branches);
}

void
panda::PFatJet::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  PJet::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "tau1");
  utils::resetAddress(_tree, _name, "tau2");
  utils::resetAddress(_tree, _name, "tau3");
  utils::resetAddress(_tree, _name, "mSD");
  utils::resetAddress(_tree, _name, "tau1SD");
  utils::resetAddress(_tree, _name, "tau2SD");
  utils::resetAddress(_tree, _name, "tau3SD");
  utils::resetAddress(_tree, _name, "htt_mass");
  utils::resetAddress(_tree, _name, "htt_frec");
  utils::resetAddress(_tree, _name, "ecfs");
  utils::resetAddress(_tree, _name, "subjets_");
}

void
panda::PFatJet::datastore::resizeVectors_(UInt_t _size)
{
  PJet::datastore::resizeVectors_(_size);

  subjets_->resize(_size);
}

panda::PFatJet::PFatJet(char const* _name/* = ""*/) :
  PJet(new PFatJetArray(1, _name)),
  tau1(gStore.getData(this).tau1[0]),
  tau2(gStore.getData(this).tau2[0]),
  tau3(gStore.getData(this).tau3[0]),
  mSD(gStore.getData(this).mSD[0]),
  tau1SD(gStore.getData(this).tau1SD[0]),
  tau2SD(gStore.getData(this).tau2SD[0]),
  tau3SD(gStore.getData(this).tau3SD[0]),
  htt_mass(gStore.getData(this).htt_mass[0]),
  htt_frec(gStore.getData(this).htt_frec[0]),
  ecfs(gStore.getData(this).ecfs[0]),
  subjets(gStore.getData(this).subjetsContainer_, (*gStore.getData(this).subjets_)[0])
{
}

panda::PFatJet::PFatJet(datastore& _data, UInt_t _idx) :
  PJet(_data, _idx),
  tau1(_data.tau1[_idx]),
  tau2(_data.tau2[_idx]),
  tau3(_data.tau3[_idx]),
  mSD(_data.mSD[_idx]),
  tau1SD(_data.tau1SD[_idx]),
  tau2SD(_data.tau2SD[_idx]),
  tau3SD(_data.tau3SD[_idx]),
  htt_mass(_data.htt_mass[_idx]),
  htt_frec(_data.htt_frec[_idx]),
  ecfs(_data.ecfs[_idx]),
  subjets(_data.subjetsContainer_, (*_data.subjets_)[_idx])
{
}

panda::PFatJet::PFatJet(PFatJet const& _src) :
  PJet(new PFatJetArray(1, gStore.getName(&_src))),
  tau1(gStore.getData(this).tau1[0]),
  tau2(gStore.getData(this).tau2[0]),
  tau3(gStore.getData(this).tau3[0]),
  mSD(gStore.getData(this).mSD[0]),
  tau1SD(gStore.getData(this).tau1SD[0]),
  tau2SD(gStore.getData(this).tau2SD[0]),
  tau3SD(gStore.getData(this).tau3SD[0]),
  htt_mass(gStore.getData(this).htt_mass[0]),
  htt_frec(gStore.getData(this).htt_frec[0]),
  ecfs(gStore.getData(this).ecfs[0]),
  subjets(gStore.getData(this).subjetsContainer_, (*gStore.getData(this).subjets_)[0])
{
  PJet::operator=(_src);

  tau1 = _src.tau1;
  tau2 = _src.tau2;
  tau3 = _src.tau3;
  mSD = _src.mSD;
  tau1SD = _src.tau1SD;
  tau2SD = _src.tau2SD;
  tau3SD = _src.tau3SD;
  htt_mass = _src.htt_mass;
  htt_frec = _src.htt_frec;
  std::memcpy(ecfs, _src.ecfs, sizeof(Float_t) * 3 * 4 * 4);
  subjets = _src.subjets;
}

panda::PFatJet::PFatJet(ArrayBase* _array) :
  PJet(_array),
  tau1(gStore.getData(this).tau1[0]),
  tau2(gStore.getData(this).tau2[0]),
  tau3(gStore.getData(this).tau3[0]),
  mSD(gStore.getData(this).mSD[0]),
  tau1SD(gStore.getData(this).tau1SD[0]),
  tau2SD(gStore.getData(this).tau2SD[0]),
  tau3SD(gStore.getData(this).tau3SD[0]),
  htt_mass(gStore.getData(this).htt_mass[0]),
  htt_frec(gStore.getData(this).htt_frec[0]),
  ecfs(gStore.getData(this).ecfs[0]),
  subjets(gStore.getData(this).subjetsContainer_, (*gStore.getData(this).subjets_)[0])
{
}

panda::PFatJet::~PFatJet()
{
  destructor();
  gStore.free(this);
}

void
panda::PFatJet::destructor()
{
  /* BEGIN CUSTOM PFatJet.cc.destructor */
  /* END CUSTOM */

  PJet::destructor();
}

panda::PFatJet&
panda::PFatJet::operator=(PFatJet const& _src)
{
  PJet::operator=(_src);

  tau1 = _src.tau1;
  tau2 = _src.tau2;
  tau3 = _src.tau3;
  mSD = _src.mSD;
  tau1SD = _src.tau1SD;
  tau2SD = _src.tau2SD;
  tau3SD = _src.tau3SD;
  htt_mass = _src.htt_mass;
  htt_frec = _src.htt_frec;
  std::memcpy(ecfs, _src.ecfs, sizeof(Float_t) * 3 * 4 * 4);
  subjets = _src.subjets;

  return *this;
}

void
panda::PFatJet::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PJet::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "tau1", _status, _branches);
  utils::setStatus(_tree, name, "tau2", _status, _branches);
  utils::setStatus(_tree, name, "tau3", _status, _branches);
  utils::setStatus(_tree, name, "mSD", _status, _branches);
  utils::setStatus(_tree, name, "tau1SD", _status, _branches);
  utils::setStatus(_tree, name, "tau2SD", _status, _branches);
  utils::setStatus(_tree, name, "tau3SD", _status, _branches);
  utils::setStatus(_tree, name, "htt_mass", _status, _branches);
  utils::setStatus(_tree, name, "htt_frec", _status, _branches);
  utils::setStatus(_tree, name, "ecfs", _status, _branches);
  utils::setStatus(_tree, name, "subjets_", _status, _branches);
}

void
panda::PFatJet::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PJet::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "tau1", &tau1, _branches, _setStatus);
  utils::setAddress(_tree, name, "tau2", &tau2, _branches, _setStatus);
  utils::setAddress(_tree, name, "tau3", &tau3, _branches, _setStatus);
  utils::setAddress(_tree, name, "mSD", &mSD, _branches, _setStatus);
  utils::setAddress(_tree, name, "tau1SD", &tau1SD, _branches, _setStatus);
  utils::setAddress(_tree, name, "tau2SD", &tau2SD, _branches, _setStatus);
  utils::setAddress(_tree, name, "tau3SD", &tau3SD, _branches, _setStatus);
  utils::setAddress(_tree, name, "htt_mass", &htt_mass, _branches, _setStatus);
  utils::setAddress(_tree, name, "htt_frec", &htt_frec, _branches, _setStatus);
  utils::setAddress(_tree, name, "ecfs", ecfs, _branches, _setStatus);
  utils::setAddress(_tree, name, "subjets_", &subjets.indices(), _branches, true);
}

void
panda::PFatJet::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PJet::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "tau1", "", 'F', &tau1, _branches);
  utils::book(_tree, name, "tau2", "", 'F', &tau2, _branches);
  utils::book(_tree, name, "tau3", "", 'F', &tau3, _branches);
  utils::book(_tree, name, "mSD", "", 'F', &mSD, _branches);
  utils::book(_tree, name, "tau1SD", "", 'F', &tau1SD, _branches);
  utils::book(_tree, name, "tau2SD", "", 'F', &tau2SD, _branches);
  utils::book(_tree, name, "tau3SD", "", 'F', &tau3SD, _branches);
  utils::book(_tree, name, "htt_mass", "", 'F', &htt_mass, _branches);
  utils::book(_tree, name, "htt_frec", "", 'F', &htt_frec, _branches);
  utils::book(_tree, name, "ecfs", "[3][4][4]", 'F', ecfs, _branches);
  utils::book(_tree, name, "subjets_", "std::vector<UInt_t>", &subjets.indices(), _branches);
}

void
panda::PFatJet::resetAddress(TTree& _tree)
{
  PJet::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "tau1");
  utils::resetAddress(_tree, name, "tau2");
  utils::resetAddress(_tree, name, "tau3");
  utils::resetAddress(_tree, name, "mSD");
  utils::resetAddress(_tree, name, "tau1SD");
  utils::resetAddress(_tree, name, "tau2SD");
  utils::resetAddress(_tree, name, "tau3SD");
  utils::resetAddress(_tree, name, "htt_mass");
  utils::resetAddress(_tree, name, "htt_frec");
  utils::resetAddress(_tree, name, "ecfs");
  utils::resetAddress(_tree, name, "subjets_");
}

void
panda::PFatJet::init()
{
  PJet::init();

  tau1 = 0.;
  tau2 = 0.;
  tau3 = 0.;
  mSD = 0.;
  tau1SD = -1.;
  tau2SD = -1.;
  tau3SD = -1.;
  htt_mass = 0.;
  htt_frec = 0.;
  for (auto& p0 : ecfs) for (auto& p1 : p0) for (auto& p2 : p1) p2 = 0.;
  subjets.init();
}

double
panda::PFatJet::get_ecf(int o_, int N_, int ib_) const
{
  if (o_<1 || o_>3 || N_<1 || N_>4 || ib_<0 || ib_>3) 
    return -1.;
  return ecfs[o_-1][N_-1][ib_];
}

bool
panda::PFatJet::set_ecf(int o_, int N_, int ib_, float x_)
{
  if (o_<1 || o_>3 || N_<1 || N_>4 || ib_<0 || ib_>3) 
    return false;
  ecfs[o_-1][N_-1][ib_] = x_;
  return true;
}


/* BEGIN CUSTOM PFatJet.cc.global */
/* END CUSTOM */
