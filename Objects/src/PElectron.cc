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
  utils::setStatus(_tree, _name, "isoPUOffset", _status, _branches);
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
  utils::setStatusAndAddress(_tree, _name, "isoPUOffset", isoPUOffset, _branches);
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
  utils::book(_tree, _name, "isoPUOffset", "[" + _name + ".size]", 'F', isoPUOffset, _branches);
  utils::book(_tree, _name, "sieie", "[" + _name + ".size]", 'F', sieie, _branches);
  utils::book(_tree, _name, "sipip", "[" + _name + ".size]", 'F', sipip, _branches);
  utils::book(_tree, _name, "hOverE", "[" + _name + ".size]", 'F', hOverE, _branches);
  utils::book(_tree, _name, "veto", "[" + _name + ".size]", 'O', veto, _branches);
  utils::book(_tree, _name, "superCluster_", "[" + _name + ".size]", 'i', superCluster_, _branches);
}

panda::PElectron::PElectron(char const* _name/* = ""*/) :
  PLepton(utils::Allocator<PElectron>(), _name),
  chisoPh(gStore.getData(this).chisoPh[gStore.getIndex(this)]),
  nhisoPh(gStore.getData(this).nhisoPh[gStore.getIndex(this)]),
  phisoPh(gStore.getData(this).phisoPh[gStore.getIndex(this)]),
  ecaliso(gStore.getData(this).ecaliso[gStore.getIndex(this)]),
  hcaliso(gStore.getData(this).hcaliso[gStore.getIndex(this)]),
  isoPUOffset(gStore.getData(this).isoPUOffset[gStore.getIndex(this)]),
  sieie(gStore.getData(this).sieie[gStore.getIndex(this)]),
  sipip(gStore.getData(this).sipip[gStore.getIndex(this)]),
  hOverE(gStore.getData(this).hOverE[gStore.getIndex(this)]),
  veto(gStore.getData(this).veto[gStore.getIndex(this)]),
  superCluster(gStore.getData(this).superCluster_[gStore.getIndex(this)])
{
}

panda::PElectron::PElectron(array_data& _data, UInt_t _idx) :
  PLepton(_data, _idx),
  chisoPh(_data.chisoPh[_idx]),
  nhisoPh(_data.nhisoPh[_idx]),
  phisoPh(_data.phisoPh[_idx]),
  ecaliso(_data.ecaliso[_idx]),
  hcaliso(_data.hcaliso[_idx]),
  isoPUOffset(_data.isoPUOffset[_idx]),
  sieie(_data.sieie[_idx]),
  sipip(_data.sipip[_idx]),
  hOverE(_data.hOverE[_idx]),
  veto(_data.veto[_idx]),
  superCluster(_data.superCluster_[_idx])
{
}

panda::PElectron::PElectron(PElectron const& _src) :
  PLepton(utils::Allocator<PElectron>(), gStore.getName(&_src)),
  chisoPh(gStore.getData(this).chisoPh[gStore.getIndex(this)]),
  nhisoPh(gStore.getData(this).nhisoPh[gStore.getIndex(this)]),
  phisoPh(gStore.getData(this).phisoPh[gStore.getIndex(this)]),
  ecaliso(gStore.getData(this).ecaliso[gStore.getIndex(this)]),
  hcaliso(gStore.getData(this).hcaliso[gStore.getIndex(this)]),
  isoPUOffset(gStore.getData(this).isoPUOffset[gStore.getIndex(this)]),
  sieie(gStore.getData(this).sieie[gStore.getIndex(this)]),
  sipip(gStore.getData(this).sipip[gStore.getIndex(this)]),
  hOverE(gStore.getData(this).hOverE[gStore.getIndex(this)]),
  veto(gStore.getData(this).veto[gStore.getIndex(this)]),
  superCluster(gStore.getData(this).superCluster_[gStore.getIndex(this)])
{
  PLepton::operator=(_src);

  chisoPh = _src.chisoPh;
  nhisoPh = _src.nhisoPh;
  phisoPh = _src.phisoPh;
  ecaliso = _src.ecaliso;
  hcaliso = _src.hcaliso;
  isoPUOffset = _src.isoPUOffset;
  sieie = _src.sieie;
  sipip = _src.sipip;
  hOverE = _src.hOverE;
  veto = _src.veto;
  superCluster = _src.superCluster;
}

panda::PElectron::PElectron(utils::AllocatorBase const& _allocator, char const* _name) :
  PLepton(_allocator, _name),
  chisoPh(gStore.getData(this).chisoPh[gStore.getIndex(this)]),
  nhisoPh(gStore.getData(this).nhisoPh[gStore.getIndex(this)]),
  phisoPh(gStore.getData(this).phisoPh[gStore.getIndex(this)]),
  ecaliso(gStore.getData(this).ecaliso[gStore.getIndex(this)]),
  hcaliso(gStore.getData(this).hcaliso[gStore.getIndex(this)]),
  isoPUOffset(gStore.getData(this).isoPUOffset[gStore.getIndex(this)]),
  sieie(gStore.getData(this).sieie[gStore.getIndex(this)]),
  sipip(gStore.getData(this).sipip[gStore.getIndex(this)]),
  hOverE(gStore.getData(this).hOverE[gStore.getIndex(this)]),
  veto(gStore.getData(this).veto[gStore.getIndex(this)]),
  superCluster(gStore.getData(this).superCluster_[gStore.getIndex(this)])
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
  isoPUOffset = _src.isoPUOffset;
  sieie = _src.sieie;
  sipip = _src.sipip;
  hOverE = _src.hOverE;
  veto = _src.veto;
  superCluster = _src.superCluster;

  return *this;
}

void
panda::PElectron::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "chisoPh", _status, _branches);
  utils::setStatus(_tree, name, "nhisoPh", _status, _branches);
  utils::setStatus(_tree, name, "phisoPh", _status, _branches);
  utils::setStatus(_tree, name, "ecaliso", _status, _branches);
  utils::setStatus(_tree, name, "hcaliso", _status, _branches);
  utils::setStatus(_tree, name, "isoPUOffset", _status, _branches);
  utils::setStatus(_tree, name, "sieie", _status, _branches);
  utils::setStatus(_tree, name, "sipip", _status, _branches);
  utils::setStatus(_tree, name, "hOverE", _status, _branches);
  utils::setStatus(_tree, name, "veto", _status, _branches);
  utils::setStatus(_tree, name, "superCluster_", _status, _branches);
}

void
panda::PElectron::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::setAddress(_tree, _branches);

  TString name(gStore.getName(this));

  utils::setStatusAndAddress(_tree, name, "chisoPh", &chisoPh, _branches);
  utils::setStatusAndAddress(_tree, name, "nhisoPh", &nhisoPh, _branches);
  utils::setStatusAndAddress(_tree, name, "phisoPh", &phisoPh, _branches);
  utils::setStatusAndAddress(_tree, name, "ecaliso", &ecaliso, _branches);
  utils::setStatusAndAddress(_tree, name, "hcaliso", &hcaliso, _branches);
  utils::setStatusAndAddress(_tree, name, "isoPUOffset", &isoPUOffset, _branches);
  utils::setStatusAndAddress(_tree, name, "sieie", &sieie, _branches);
  utils::setStatusAndAddress(_tree, name, "sipip", &sipip, _branches);
  utils::setStatusAndAddress(_tree, name, "hOverE", &hOverE, _branches);
  utils::setStatusAndAddress(_tree, name, "veto", &veto, _branches);
  utils::setStatusAndAddress(_tree, name, "superCluster_", &superCluster.idx, _branches);
}

void
panda::PElectron::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "chisoPh", "", 'F', &chisoPh, _branches);
  utils::book(_tree, name, "nhisoPh", "", 'F', &nhisoPh, _branches);
  utils::book(_tree, name, "phisoPh", "", 'F', &phisoPh, _branches);
  utils::book(_tree, name, "ecaliso", "", 'F', &ecaliso, _branches);
  utils::book(_tree, name, "hcaliso", "", 'F', &hcaliso, _branches);
  utils::book(_tree, name, "isoPUOffset", "", 'F', &isoPUOffset, _branches);
  utils::book(_tree, name, "sieie", "", 'F', &sieie, _branches);
  utils::book(_tree, name, "sipip", "", 'F', &sipip, _branches);
  utils::book(_tree, name, "hOverE", "", 'F', &hOverE, _branches);
  utils::book(_tree, name, "veto", "", 'O', &veto, _branches);
  utils::book(_tree, name, "superCluster_", "", 'i', &superCluster.idx, _branches);
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
  isoPUOffset = 0.;
  sieie = 0.;
  sipip = 0.;
  hOverE = 0.;
  veto = false;
  superCluster.init();
}


/* BEGIN CUSTOM */
/* END CUSTOM */
