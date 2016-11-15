#include "../interface/PFatJet.h"

void
panda::PFatJet::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PJet::array_data::setStatus(_tree, _name, _status, _branches);

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
}

void
panda::PFatJet::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PJet::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "tau1", tau1, _branches);
  utils::setStatusAndAddress(_tree, _name, "tau2", tau2, _branches);
  utils::setStatusAndAddress(_tree, _name, "tau3", tau3, _branches);
  utils::setStatusAndAddress(_tree, _name, "mSD", mSD, _branches);
  utils::setStatusAndAddress(_tree, _name, "tau1SD", tau1SD, _branches);
  utils::setStatusAndAddress(_tree, _name, "tau2SD", tau2SD, _branches);
  utils::setStatusAndAddress(_tree, _name, "tau3SD", tau3SD, _branches);
  utils::setStatusAndAddress(_tree, _name, "htt_mass", htt_mass, _branches);
  utils::setStatusAndAddress(_tree, _name, "htt_frec", htt_frec, _branches);
  utils::setStatusAndAddress(_tree, _name, "ecfs", ecfs, _branches);
}

void
panda::PFatJet::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PJet::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "tau1", "[" + _name + ".size]", 'F', tau1, _branches);
  utils::book(_tree, _name, "tau2", "[" + _name + ".size]", 'F', tau2, _branches);
  utils::book(_tree, _name, "tau3", "[" + _name + ".size]", 'F', tau3, _branches);
  utils::book(_tree, _name, "mSD", "[" + _name + ".size]", 'F', mSD, _branches);
  utils::book(_tree, _name, "tau1SD", "[" + _name + ".size]", 'F', tau1SD, _branches);
  utils::book(_tree, _name, "tau2SD", "[" + _name + ".size]", 'F', tau2SD, _branches);
  utils::book(_tree, _name, "tau3SD", "[" + _name + ".size]", 'F', tau3SD, _branches);
  utils::book(_tree, _name, "htt_mass", "[" + _name + ".size]", 'F', htt_mass, _branches);
  utils::book(_tree, _name, "htt_frec", "[" + _name + ".size]", 'F', htt_frec, _branches);
  utils::book(_tree, _name, "ecfs", "[" + _name + ".size][3][4][4]", 'F', ecfs, _branches);
}

panda::PFatJet::PFatJet() :
  PJet(utils::Allocator<PFatJet>()),
  tau1(gStore.getData(this).tau1[gStore.getIndex(this)]),
  tau2(gStore.getData(this).tau2[gStore.getIndex(this)]),
  tau3(gStore.getData(this).tau3[gStore.getIndex(this)]),
  mSD(gStore.getData(this).mSD[gStore.getIndex(this)]),
  tau1SD(gStore.getData(this).tau1SD[gStore.getIndex(this)]),
  tau2SD(gStore.getData(this).tau2SD[gStore.getIndex(this)]),
  tau3SD(gStore.getData(this).tau3SD[gStore.getIndex(this)]),
  htt_mass(gStore.getData(this).htt_mass[gStore.getIndex(this)]),
  htt_frec(gStore.getData(this).htt_frec[gStore.getIndex(this)]),
  ecfs(gStore.getData(this).ecfs[gStore.getIndex(this)])
{
}

panda::PFatJet::PFatJet(PFatJet const& _src) :
  PJet(utils::Allocator<PFatJet>()),
  tau1(gStore.getData(this).tau1[gStore.getIndex(this)]),
  tau2(gStore.getData(this).tau2[gStore.getIndex(this)]),
  tau3(gStore.getData(this).tau3[gStore.getIndex(this)]),
  mSD(gStore.getData(this).mSD[gStore.getIndex(this)]),
  tau1SD(gStore.getData(this).tau1SD[gStore.getIndex(this)]),
  tau2SD(gStore.getData(this).tau2SD[gStore.getIndex(this)]),
  tau3SD(gStore.getData(this).tau3SD[gStore.getIndex(this)]),
  htt_mass(gStore.getData(this).htt_mass[gStore.getIndex(this)]),
  htt_frec(gStore.getData(this).htt_frec[gStore.getIndex(this)]),
  ecfs(gStore.getData(this).ecfs[gStore.getIndex(this)])
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
}

panda::PFatJet::PFatJet(array_data& _data, UInt_t _idx) :
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
  ecfs(_data.ecfs[_idx])
{
}

panda::PFatJet::PFatJet(utils::AllocatorBase const& _allocator) :
  PJet(_allocator),
  tau1(gStore.getData(this).tau1[gStore.getIndex(this)]),
  tau2(gStore.getData(this).tau2[gStore.getIndex(this)]),
  tau3(gStore.getData(this).tau3[gStore.getIndex(this)]),
  mSD(gStore.getData(this).mSD[gStore.getIndex(this)]),
  tau1SD(gStore.getData(this).tau1SD[gStore.getIndex(this)]),
  tau2SD(gStore.getData(this).tau2SD[gStore.getIndex(this)]),
  tau3SD(gStore.getData(this).tau3SD[gStore.getIndex(this)]),
  htt_mass(gStore.getData(this).htt_mass[gStore.getIndex(this)]),
  htt_frec(gStore.getData(this).htt_frec[gStore.getIndex(this)]),
  ecfs(gStore.getData(this).ecfs[gStore.getIndex(this)])
{
}

panda::PFatJet::~PFatJet()
{
  gStore.free(this);
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

  return *this;
}

void
panda::PFatJet::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PJet::setStatus(_tree, _name, _status, _branches);

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
}

void
panda::PFatJet::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PJet::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "tau1", &tau1, _branches);
  utils::setStatusAndAddress(_tree, _name, "tau2", &tau2, _branches);
  utils::setStatusAndAddress(_tree, _name, "tau3", &tau3, _branches);
  utils::setStatusAndAddress(_tree, _name, "mSD", &mSD, _branches);
  utils::setStatusAndAddress(_tree, _name, "tau1SD", &tau1SD, _branches);
  utils::setStatusAndAddress(_tree, _name, "tau2SD", &tau2SD, _branches);
  utils::setStatusAndAddress(_tree, _name, "tau3SD", &tau3SD, _branches);
  utils::setStatusAndAddress(_tree, _name, "htt_mass", &htt_mass, _branches);
  utils::setStatusAndAddress(_tree, _name, "htt_frec", &htt_frec, _branches);
  utils::setStatusAndAddress(_tree, _name, "ecfs", ecfs, _branches);
}

void
panda::PFatJet::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PJet::book(_tree, _name, _branches);

  utils::book(_tree, _name, "tau1", "", 'F', &tau1, _branches);
  utils::book(_tree, _name, "tau2", "", 'F', &tau2, _branches);
  utils::book(_tree, _name, "tau3", "", 'F', &tau3, _branches);
  utils::book(_tree, _name, "mSD", "", 'F', &mSD, _branches);
  utils::book(_tree, _name, "tau1SD", "", 'F', &tau1SD, _branches);
  utils::book(_tree, _name, "tau2SD", "", 'F', &tau2SD, _branches);
  utils::book(_tree, _name, "tau3SD", "", 'F', &tau3SD, _branches);
  utils::book(_tree, _name, "htt_mass", "", 'F', &htt_mass, _branches);
  utils::book(_tree, _name, "htt_frec", "", 'F', &htt_frec, _branches);
  utils::book(_tree, _name, "ecfs", "[3][4][4]", 'F', ecfs, _branches);
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
}

float
panda::PFatJet::get_ecf(short o_, short N_, int ib_) const
{
  if (o_<1 || o_>3 || N_<1 || N_>4 || ib_<0 || ib_>3) 
    return -1;
  return ecfs[o_-1][N_-1][ib_];
}

int
panda::PFatJet::set_ecf(int o_, int N_, int ib_, float x_)
{
  if (o_<1 || o_>3 || N_<1 || N_>4 || ib_<0 || ib_>3) 
    return 1;
  ecfs[o_-1][N_-1][ib_] = x_;
  return 0;
}


/* BEGIN CUSTOM */
/* END CUSTOM */
