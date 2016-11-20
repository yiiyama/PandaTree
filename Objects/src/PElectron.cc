#include "../interface/PElectron.h"

void
panda::PElectron::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::array_data::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "chisoPh", _status, _branches);
  utils::setStatus(_tree, _name, "nhisoPh", _status, _branches);
  utils::setStatus(_tree, _name, "phisoPh", _status, _branches);
  utils::setStatus(_tree, _name, "ecaliso", _status, _branches);
  utils::setStatus(_tree, _name, "hcaliso", _status, _branches);
  utils::setStatus(_tree, _name, "sieie", _status, _branches);
  utils::setStatus(_tree, _name, "sipip", _status, _branches);
  utils::setStatus(_tree, _name, "hOverE", _status, _branches);
  utils::setStatus(_tree, _name, "veto", _status, _branches);
  utils::setStatus(_tree, _name, "superCluster_", _status, _branches);
}

void
panda::PElectron::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "chisoPh", chisoPh, _branches);
  utils::setStatusAndAddress(_tree, _name, "nhisoPh", nhisoPh, _branches);
  utils::setStatusAndAddress(_tree, _name, "phisoPh", phisoPh, _branches);
  utils::setStatusAndAddress(_tree, _name, "ecaliso", ecaliso, _branches);
  utils::setStatusAndAddress(_tree, _name, "hcaliso", hcaliso, _branches);
  utils::setStatusAndAddress(_tree, _name, "sieie", sieie, _branches);
  utils::setStatusAndAddress(_tree, _name, "sipip", sipip, _branches);
  utils::setStatusAndAddress(_tree, _name, "hOverE", hOverE, _branches);
  utils::setStatusAndAddress(_tree, _name, "veto", veto, _branches);
  utils::setStatusAndAddress(_tree, _name, "superCluster_", superCluster_, _branches);
}

void
panda::PElectron::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "chisoPh", "[" + _name + ".size]", 'F', chisoPh, _branches);
  utils::book(_tree, _name, "nhisoPh", "[" + _name + ".size]", 'F', nhisoPh, _branches);
  utils::book(_tree, _name, "phisoPh", "[" + _name + ".size]", 'F', phisoPh, _branches);
  utils::book(_tree, _name, "ecaliso", "[" + _name + ".size]", 'F', ecaliso, _branches);
  utils::book(_tree, _name, "hcaliso", "[" + _name + ".size]", 'F', hcaliso, _branches);
  utils::book(_tree, _name, "sieie", "[" + _name + ".size]", 'F', sieie, _branches);
  utils::book(_tree, _name, "sipip", "[" + _name + ".size]", 'F', sipip, _branches);
  utils::book(_tree, _name, "hOverE", "[" + _name + ".size]", 'F', hOverE, _branches);
  utils::book(_tree, _name, "veto", "[" + _name + ".size]", 'O', veto, _branches);
  utils::book(_tree, _name, "superCluster_", "[" + _name + ".size]", 'i', superCluster_, _branches);
}

panda::PElectron::PElectron() :
  PLepton(utils::Allocator<PElectron>()),
  chisoPh(gStore.getData(this).chisoPh[gStore.getIndex(this)]),
  nhisoPh(gStore.getData(this).nhisoPh[gStore.getIndex(this)]),
  phisoPh(gStore.getData(this).phisoPh[gStore.getIndex(this)]),
  ecaliso(gStore.getData(this).ecaliso[gStore.getIndex(this)]),
  hcaliso(gStore.getData(this).hcaliso[gStore.getIndex(this)]),
  sieie(gStore.getData(this).sieie[gStore.getIndex(this)]),
  sipip(gStore.getData(this).sipip[gStore.getIndex(this)]),
  hOverE(gStore.getData(this).hOverE[gStore.getIndex(this)]),
  veto(gStore.getData(this).veto[gStore.getIndex(this)]),
  superCluster_(gStore.getData(this).superCluster_[gStore.getIndex(this)])
{
}

panda::PElectron::PElectron(PElectron const& _src) :
  PLepton(utils::Allocator<PElectron>()),
  chisoPh(gStore.getData(this).chisoPh[gStore.getIndex(this)]),
  nhisoPh(gStore.getData(this).nhisoPh[gStore.getIndex(this)]),
  phisoPh(gStore.getData(this).phisoPh[gStore.getIndex(this)]),
  ecaliso(gStore.getData(this).ecaliso[gStore.getIndex(this)]),
  hcaliso(gStore.getData(this).hcaliso[gStore.getIndex(this)]),
  sieie(gStore.getData(this).sieie[gStore.getIndex(this)]),
  sipip(gStore.getData(this).sipip[gStore.getIndex(this)]),
  hOverE(gStore.getData(this).hOverE[gStore.getIndex(this)]),
  veto(gStore.getData(this).veto[gStore.getIndex(this)]),
  superCluster_(gStore.getData(this).superCluster_[gStore.getIndex(this)])
{
  PLepton::operator=(_src);

  chisoPh = _src.chisoPh;
  nhisoPh = _src.nhisoPh;
  phisoPh = _src.phisoPh;
  ecaliso = _src.ecaliso;
  hcaliso = _src.hcaliso;
  sieie = _src.sieie;
  sipip = _src.sipip;
  hOverE = _src.hOverE;
  veto = _src.veto;
  superCluster_ = _src.superCluster_;
}

panda::PElectron::PElectron(array_data& _data, UInt_t _idx) :
  PLepton(_data, _idx),
  chisoPh(_data.chisoPh[_idx]),
  nhisoPh(_data.nhisoPh[_idx]),
  phisoPh(_data.phisoPh[_idx]),
  ecaliso(_data.ecaliso[_idx]),
  hcaliso(_data.hcaliso[_idx]),
  sieie(_data.sieie[_idx]),
  sipip(_data.sipip[_idx]),
  hOverE(_data.hOverE[_idx]),
  veto(_data.veto[_idx]),
  superCluster_(_data.superCluster_[_idx])
{
}

panda::PElectron::PElectron(utils::AllocatorBase const& _allocator) :
  PLepton(_allocator),
  chisoPh(gStore.getData(this).chisoPh[gStore.getIndex(this)]),
  nhisoPh(gStore.getData(this).nhisoPh[gStore.getIndex(this)]),
  phisoPh(gStore.getData(this).phisoPh[gStore.getIndex(this)]),
  ecaliso(gStore.getData(this).ecaliso[gStore.getIndex(this)]),
  hcaliso(gStore.getData(this).hcaliso[gStore.getIndex(this)]),
  sieie(gStore.getData(this).sieie[gStore.getIndex(this)]),
  sipip(gStore.getData(this).sipip[gStore.getIndex(this)]),
  hOverE(gStore.getData(this).hOverE[gStore.getIndex(this)]),
  veto(gStore.getData(this).veto[gStore.getIndex(this)]),
  superCluster_(gStore.getData(this).superCluster_[gStore.getIndex(this)])
{
}

panda::PElectron::~PElectron()
{
  gStore.free(this);
}

panda::PElectron&
panda::PElectron::operator=(PElectron const& _src)
{
  PLepton::operator=(_src);

  chisoPh = _src.chisoPh;
  nhisoPh = _src.nhisoPh;
  phisoPh = _src.phisoPh;
  ecaliso = _src.ecaliso;
  hcaliso = _src.hcaliso;
  sieie = _src.sieie;
  sipip = _src.sipip;
  hOverE = _src.hOverE;
  veto = _src.veto;
  superCluster_ = _src.superCluster_;

  return *this;
}

void
panda::PElectron::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "chisoPh", _status, _branches);
  utils::setStatus(_tree, _name, "nhisoPh", _status, _branches);
  utils::setStatus(_tree, _name, "phisoPh", _status, _branches);
  utils::setStatus(_tree, _name, "ecaliso", _status, _branches);
  utils::setStatus(_tree, _name, "hcaliso", _status, _branches);
  utils::setStatus(_tree, _name, "sieie", _status, _branches);
  utils::setStatus(_tree, _name, "sipip", _status, _branches);
  utils::setStatus(_tree, _name, "hOverE", _status, _branches);
  utils::setStatus(_tree, _name, "veto", _status, _branches);
  utils::setStatus(_tree, _name, "superCluster_", _status, _branches);
}

void
panda::PElectron::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "chisoPh", &chisoPh, _branches);
  utils::setStatusAndAddress(_tree, _name, "nhisoPh", &nhisoPh, _branches);
  utils::setStatusAndAddress(_tree, _name, "phisoPh", &phisoPh, _branches);
  utils::setStatusAndAddress(_tree, _name, "ecaliso", &ecaliso, _branches);
  utils::setStatusAndAddress(_tree, _name, "hcaliso", &hcaliso, _branches);
  utils::setStatusAndAddress(_tree, _name, "sieie", &sieie, _branches);
  utils::setStatusAndAddress(_tree, _name, "sipip", &sipip, _branches);
  utils::setStatusAndAddress(_tree, _name, "hOverE", &hOverE, _branches);
  utils::setStatusAndAddress(_tree, _name, "veto", &veto, _branches);
  utils::setStatusAndAddress(_tree, _name, "superCluster_", &superCluster_, _branches);
}

void
panda::PElectron::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::book(_tree, _name, _branches);

  utils::book(_tree, _name, "chisoPh", "", 'F', &chisoPh, _branches);
  utils::book(_tree, _name, "nhisoPh", "", 'F', &nhisoPh, _branches);
  utils::book(_tree, _name, "phisoPh", "", 'F', &phisoPh, _branches);
  utils::book(_tree, _name, "ecaliso", "", 'F', &ecaliso, _branches);
  utils::book(_tree, _name, "hcaliso", "", 'F', &hcaliso, _branches);
  utils::book(_tree, _name, "sieie", "", 'F', &sieie, _branches);
  utils::book(_tree, _name, "sipip", "", 'F', &sipip, _branches);
  utils::book(_tree, _name, "hOverE", "", 'F', &hOverE, _branches);
  utils::book(_tree, _name, "veto", "", 'O', &veto, _branches);
  utils::book(_tree, _name, "superCluster_", "", 'i', &superCluster_, _branches);
}

void
panda::PElectron::init()
{
  PLepton::init();

  chisoPh = 0.;
  nhisoPh = 0.;
  phisoPh = 0.;
  ecaliso = 0.;
  hcaliso = 0.;
  sieie = 0.;
  sipip = 0.;
  hOverE = 0.;
  veto = false;
  superCluster_ = PSuperCluster::array_data::NMAX;
}


/* BEGIN CUSTOM */
/* END CUSTOM */
