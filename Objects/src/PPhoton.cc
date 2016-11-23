#include "../interface/PPhoton.h"

void
panda::PPhoton::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::array_data::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "chiso", _status, _branches);
  utils::setStatus(_tree, _name, "chworstiso", _status, _branches);
  utils::setStatus(_tree, _name, "chisoMax", _status, _branches);
  utils::setStatus(_tree, _name, "nhiso", _status, _branches);
  utils::setStatus(_tree, _name, "phiso", _status, _branches);
  utils::setStatus(_tree, _name, "ecaliso", _status, _branches);
  utils::setStatus(_tree, _name, "hcaliso", _status, _branches);
  utils::setStatus(_tree, _name, "sieie", _status, _branches);
  utils::setStatus(_tree, _name, "sipip", _status, _branches);
  utils::setStatus(_tree, _name, "hOverE", _status, _branches);
  utils::setStatus(_tree, _name, "geniso", _status, _branches);
  utils::setStatus(_tree, _name, "mipEnergy", _status, _branches);
  utils::setStatus(_tree, _name, "e33", _status, _branches);
  utils::setStatus(_tree, _name, "emax", _status, _branches);
  utils::setStatus(_tree, _name, "e2nd", _status, _branches);
  utils::setStatus(_tree, _name, "r9", _status, _branches);
  utils::setStatus(_tree, _name, "etaWidth", _status, _branches);
  utils::setStatus(_tree, _name, "phiWidth", _status, _branches);
  utils::setStatus(_tree, _name, "time", _status, _branches);
  utils::setStatus(_tree, _name, "timeSpan", _status, _branches);
  utils::setStatus(_tree, _name, "genMatchDR", _status, _branches);
  utils::setStatus(_tree, _name, "loose", _status, _branches);
  utils::setStatus(_tree, _name, "medium", _status, _branches);
  utils::setStatus(_tree, _name, "tight", _status, _branches);
  utils::setStatus(_tree, _name, "highpt", _status, _branches);
  utils::setStatus(_tree, _name, "pixelVeto", _status, _branches);
  utils::setStatus(_tree, _name, "csafeVeto", _status, _branches);
  utils::setStatus(_tree, _name, "matchL1", _status, _branches);
  utils::setStatus(_tree, _name, "superCluster_", _status, _branches);
}

void
panda::PPhoton::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "chiso", chiso, _branches);
  utils::setStatusAndAddress(_tree, _name, "chworstiso", chworstiso, _branches);
  utils::setStatusAndAddress(_tree, _name, "chisoMax", chisoMax, _branches);
  utils::setStatusAndAddress(_tree, _name, "nhiso", nhiso, _branches);
  utils::setStatusAndAddress(_tree, _name, "phiso", phiso, _branches);
  utils::setStatusAndAddress(_tree, _name, "ecaliso", ecaliso, _branches);
  utils::setStatusAndAddress(_tree, _name, "hcaliso", hcaliso, _branches);
  utils::setStatusAndAddress(_tree, _name, "sieie", sieie, _branches);
  utils::setStatusAndAddress(_tree, _name, "sipip", sipip, _branches);
  utils::setStatusAndAddress(_tree, _name, "hOverE", hOverE, _branches);
  utils::setStatusAndAddress(_tree, _name, "geniso", geniso, _branches);
  utils::setStatusAndAddress(_tree, _name, "mipEnergy", mipEnergy, _branches);
  utils::setStatusAndAddress(_tree, _name, "e33", e33, _branches);
  utils::setStatusAndAddress(_tree, _name, "emax", emax, _branches);
  utils::setStatusAndAddress(_tree, _name, "e2nd", e2nd, _branches);
  utils::setStatusAndAddress(_tree, _name, "r9", r9, _branches);
  utils::setStatusAndAddress(_tree, _name, "etaWidth", etaWidth, _branches);
  utils::setStatusAndAddress(_tree, _name, "phiWidth", phiWidth, _branches);
  utils::setStatusAndAddress(_tree, _name, "time", time, _branches);
  utils::setStatusAndAddress(_tree, _name, "timeSpan", timeSpan, _branches);
  utils::setStatusAndAddress(_tree, _name, "genMatchDR", genMatchDR, _branches);
  utils::setStatusAndAddress(_tree, _name, "loose", loose, _branches);
  utils::setStatusAndAddress(_tree, _name, "medium", medium, _branches);
  utils::setStatusAndAddress(_tree, _name, "tight", tight, _branches);
  utils::setStatusAndAddress(_tree, _name, "highpt", highpt, _branches);
  utils::setStatusAndAddress(_tree, _name, "pixelVeto", pixelVeto, _branches);
  utils::setStatusAndAddress(_tree, _name, "csafeVeto", csafeVeto, _branches);
  utils::setStatusAndAddress(_tree, _name, "matchL1", matchL1, _branches);
  utils::setStatusAndAddress(_tree, _name, "superCluster_", superCluster_, _branches);
}

void
panda::PPhoton::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "chiso", "[" + _name + ".size]", 'F', chiso, _branches);
  utils::book(_tree, _name, "chworstiso", "[" + _name + ".size]", 'F', chworstiso, _branches);
  utils::book(_tree, _name, "chisoMax", "[" + _name + ".size]", 'F', chisoMax, _branches);
  utils::book(_tree, _name, "nhiso", "[" + _name + ".size]", 'F', nhiso, _branches);
  utils::book(_tree, _name, "phiso", "[" + _name + ".size]", 'F', phiso, _branches);
  utils::book(_tree, _name, "ecaliso", "[" + _name + ".size]", 'F', ecaliso, _branches);
  utils::book(_tree, _name, "hcaliso", "[" + _name + ".size]", 'F', hcaliso, _branches);
  utils::book(_tree, _name, "sieie", "[" + _name + ".size]", 'F', sieie, _branches);
  utils::book(_tree, _name, "sipip", "[" + _name + ".size]", 'F', sipip, _branches);
  utils::book(_tree, _name, "hOverE", "[" + _name + ".size]", 'F', hOverE, _branches);
  utils::book(_tree, _name, "geniso", "[" + _name + ".size]", 'F', geniso, _branches);
  utils::book(_tree, _name, "mipEnergy", "[" + _name + ".size]", 'F', mipEnergy, _branches);
  utils::book(_tree, _name, "e33", "[" + _name + ".size]", 'F', e33, _branches);
  utils::book(_tree, _name, "emax", "[" + _name + ".size]", 'F', emax, _branches);
  utils::book(_tree, _name, "e2nd", "[" + _name + ".size]", 'F', e2nd, _branches);
  utils::book(_tree, _name, "r9", "[" + _name + ".size]", 'F', r9, _branches);
  utils::book(_tree, _name, "etaWidth", "[" + _name + ".size]", 'F', etaWidth, _branches);
  utils::book(_tree, _name, "phiWidth", "[" + _name + ".size]", 'F', phiWidth, _branches);
  utils::book(_tree, _name, "time", "[" + _name + ".size]", 'F', time, _branches);
  utils::book(_tree, _name, "timeSpan", "[" + _name + ".size]", 'F', timeSpan, _branches);
  utils::book(_tree, _name, "genMatchDR", "[" + _name + ".size]", 'F', genMatchDR, _branches);
  utils::book(_tree, _name, "loose", "[" + _name + ".size]", 'O', loose, _branches);
  utils::book(_tree, _name, "medium", "[" + _name + ".size]", 'O', medium, _branches);
  utils::book(_tree, _name, "tight", "[" + _name + ".size]", 'O', tight, _branches);
  utils::book(_tree, _name, "highpt", "[" + _name + ".size]", 'O', highpt, _branches);
  utils::book(_tree, _name, "pixelVeto", "[" + _name + ".size]", 'O', pixelVeto, _branches);
  utils::book(_tree, _name, "csafeVeto", "[" + _name + ".size]", 'O', csafeVeto, _branches);
  utils::book(_tree, _name, "matchL1", "[" + _name + ".size][nPhotonL1Objects]", 'O', matchL1, _branches);
  utils::book(_tree, _name, "superCluster_", "[" + _name + ".size]", 'i', superCluster_, _branches);
}

panda::PPhoton::PPhoton(char const* _name/* = ""*/) :
  PParticle(utils::Allocator<PPhoton>(), _name),
  chiso(gStore.getData(this).chiso[gStore.getIndex(this)]),
  chworstiso(gStore.getData(this).chworstiso[gStore.getIndex(this)]),
  chisoMax(gStore.getData(this).chisoMax[gStore.getIndex(this)]),
  nhiso(gStore.getData(this).nhiso[gStore.getIndex(this)]),
  phiso(gStore.getData(this).phiso[gStore.getIndex(this)]),
  ecaliso(gStore.getData(this).ecaliso[gStore.getIndex(this)]),
  hcaliso(gStore.getData(this).hcaliso[gStore.getIndex(this)]),
  sieie(gStore.getData(this).sieie[gStore.getIndex(this)]),
  sipip(gStore.getData(this).sipip[gStore.getIndex(this)]),
  hOverE(gStore.getData(this).hOverE[gStore.getIndex(this)]),
  geniso(gStore.getData(this).geniso[gStore.getIndex(this)]),
  mipEnergy(gStore.getData(this).mipEnergy[gStore.getIndex(this)]),
  e33(gStore.getData(this).e33[gStore.getIndex(this)]),
  emax(gStore.getData(this).emax[gStore.getIndex(this)]),
  e2nd(gStore.getData(this).e2nd[gStore.getIndex(this)]),
  r9(gStore.getData(this).r9[gStore.getIndex(this)]),
  etaWidth(gStore.getData(this).etaWidth[gStore.getIndex(this)]),
  phiWidth(gStore.getData(this).phiWidth[gStore.getIndex(this)]),
  time(gStore.getData(this).time[gStore.getIndex(this)]),
  timeSpan(gStore.getData(this).timeSpan[gStore.getIndex(this)]),
  genMatchDR(gStore.getData(this).genMatchDR[gStore.getIndex(this)]),
  loose(gStore.getData(this).loose[gStore.getIndex(this)]),
  medium(gStore.getData(this).medium[gStore.getIndex(this)]),
  tight(gStore.getData(this).tight[gStore.getIndex(this)]),
  highpt(gStore.getData(this).highpt[gStore.getIndex(this)]),
  pixelVeto(gStore.getData(this).pixelVeto[gStore.getIndex(this)]),
  csafeVeto(gStore.getData(this).csafeVeto[gStore.getIndex(this)]),
  matchL1(gStore.getData(this).matchL1[gStore.getIndex(this)]),
  superCluster_(gStore.getData(this).superCluster_[gStore.getIndex(this)])
{
}

panda::PPhoton::PPhoton(array_data& _data, UInt_t _idx) :
  PParticle(_data, _idx),
  chiso(_data.chiso[_idx]),
  chworstiso(_data.chworstiso[_idx]),
  chisoMax(_data.chisoMax[_idx]),
  nhiso(_data.nhiso[_idx]),
  phiso(_data.phiso[_idx]),
  ecaliso(_data.ecaliso[_idx]),
  hcaliso(_data.hcaliso[_idx]),
  sieie(_data.sieie[_idx]),
  sipip(_data.sipip[_idx]),
  hOverE(_data.hOverE[_idx]),
  geniso(_data.geniso[_idx]),
  mipEnergy(_data.mipEnergy[_idx]),
  e33(_data.e33[_idx]),
  emax(_data.emax[_idx]),
  e2nd(_data.e2nd[_idx]),
  r9(_data.r9[_idx]),
  etaWidth(_data.etaWidth[_idx]),
  phiWidth(_data.phiWidth[_idx]),
  time(_data.time[_idx]),
  timeSpan(_data.timeSpan[_idx]),
  genMatchDR(_data.genMatchDR[_idx]),
  loose(_data.loose[_idx]),
  medium(_data.medium[_idx]),
  tight(_data.tight[_idx]),
  highpt(_data.highpt[_idx]),
  pixelVeto(_data.pixelVeto[_idx]),
  csafeVeto(_data.csafeVeto[_idx]),
  matchL1(_data.matchL1[_idx]),
  superCluster_(_data.superCluster_[_idx])
{
}

panda::PPhoton::PPhoton(PPhoton const& _src) :
  PParticle(utils::Allocator<PPhoton>(), gStore.getName(&_src)),
  chiso(gStore.getData(this).chiso[gStore.getIndex(this)]),
  chworstiso(gStore.getData(this).chworstiso[gStore.getIndex(this)]),
  chisoMax(gStore.getData(this).chisoMax[gStore.getIndex(this)]),
  nhiso(gStore.getData(this).nhiso[gStore.getIndex(this)]),
  phiso(gStore.getData(this).phiso[gStore.getIndex(this)]),
  ecaliso(gStore.getData(this).ecaliso[gStore.getIndex(this)]),
  hcaliso(gStore.getData(this).hcaliso[gStore.getIndex(this)]),
  sieie(gStore.getData(this).sieie[gStore.getIndex(this)]),
  sipip(gStore.getData(this).sipip[gStore.getIndex(this)]),
  hOverE(gStore.getData(this).hOverE[gStore.getIndex(this)]),
  geniso(gStore.getData(this).geniso[gStore.getIndex(this)]),
  mipEnergy(gStore.getData(this).mipEnergy[gStore.getIndex(this)]),
  e33(gStore.getData(this).e33[gStore.getIndex(this)]),
  emax(gStore.getData(this).emax[gStore.getIndex(this)]),
  e2nd(gStore.getData(this).e2nd[gStore.getIndex(this)]),
  r9(gStore.getData(this).r9[gStore.getIndex(this)]),
  etaWidth(gStore.getData(this).etaWidth[gStore.getIndex(this)]),
  phiWidth(gStore.getData(this).phiWidth[gStore.getIndex(this)]),
  time(gStore.getData(this).time[gStore.getIndex(this)]),
  timeSpan(gStore.getData(this).timeSpan[gStore.getIndex(this)]),
  genMatchDR(gStore.getData(this).genMatchDR[gStore.getIndex(this)]),
  loose(gStore.getData(this).loose[gStore.getIndex(this)]),
  medium(gStore.getData(this).medium[gStore.getIndex(this)]),
  tight(gStore.getData(this).tight[gStore.getIndex(this)]),
  highpt(gStore.getData(this).highpt[gStore.getIndex(this)]),
  pixelVeto(gStore.getData(this).pixelVeto[gStore.getIndex(this)]),
  csafeVeto(gStore.getData(this).csafeVeto[gStore.getIndex(this)]),
  matchL1(gStore.getData(this).matchL1[gStore.getIndex(this)]),
  superCluster_(gStore.getData(this).superCluster_[gStore.getIndex(this)])
{
  PParticle::operator=(_src);

  chiso = _src.chiso;
  chworstiso = _src.chworstiso;
  chisoMax = _src.chisoMax;
  nhiso = _src.nhiso;
  phiso = _src.phiso;
  ecaliso = _src.ecaliso;
  hcaliso = _src.hcaliso;
  sieie = _src.sieie;
  sipip = _src.sipip;
  hOverE = _src.hOverE;
  geniso = _src.geniso;
  mipEnergy = _src.mipEnergy;
  e33 = _src.e33;
  emax = _src.emax;
  e2nd = _src.e2nd;
  r9 = _src.r9;
  etaWidth = _src.etaWidth;
  phiWidth = _src.phiWidth;
  time = _src.time;
  timeSpan = _src.timeSpan;
  genMatchDR = _src.genMatchDR;
  loose = _src.loose;
  medium = _src.medium;
  tight = _src.tight;
  highpt = _src.highpt;
  pixelVeto = _src.pixelVeto;
  csafeVeto = _src.csafeVeto;
  superCluster_ = _src.superCluster_;
}

panda::PPhoton::PPhoton(utils::AllocatorBase const& _allocator, char const* _name) :
  PParticle(_allocator, _name),
  chiso(gStore.getData(this).chiso[gStore.getIndex(this)]),
  chworstiso(gStore.getData(this).chworstiso[gStore.getIndex(this)]),
  chisoMax(gStore.getData(this).chisoMax[gStore.getIndex(this)]),
  nhiso(gStore.getData(this).nhiso[gStore.getIndex(this)]),
  phiso(gStore.getData(this).phiso[gStore.getIndex(this)]),
  ecaliso(gStore.getData(this).ecaliso[gStore.getIndex(this)]),
  hcaliso(gStore.getData(this).hcaliso[gStore.getIndex(this)]),
  sieie(gStore.getData(this).sieie[gStore.getIndex(this)]),
  sipip(gStore.getData(this).sipip[gStore.getIndex(this)]),
  hOverE(gStore.getData(this).hOverE[gStore.getIndex(this)]),
  geniso(gStore.getData(this).geniso[gStore.getIndex(this)]),
  mipEnergy(gStore.getData(this).mipEnergy[gStore.getIndex(this)]),
  e33(gStore.getData(this).e33[gStore.getIndex(this)]),
  emax(gStore.getData(this).emax[gStore.getIndex(this)]),
  e2nd(gStore.getData(this).e2nd[gStore.getIndex(this)]),
  r9(gStore.getData(this).r9[gStore.getIndex(this)]),
  etaWidth(gStore.getData(this).etaWidth[gStore.getIndex(this)]),
  phiWidth(gStore.getData(this).phiWidth[gStore.getIndex(this)]),
  time(gStore.getData(this).time[gStore.getIndex(this)]),
  timeSpan(gStore.getData(this).timeSpan[gStore.getIndex(this)]),
  genMatchDR(gStore.getData(this).genMatchDR[gStore.getIndex(this)]),
  loose(gStore.getData(this).loose[gStore.getIndex(this)]),
  medium(gStore.getData(this).medium[gStore.getIndex(this)]),
  tight(gStore.getData(this).tight[gStore.getIndex(this)]),
  highpt(gStore.getData(this).highpt[gStore.getIndex(this)]),
  pixelVeto(gStore.getData(this).pixelVeto[gStore.getIndex(this)]),
  csafeVeto(gStore.getData(this).csafeVeto[gStore.getIndex(this)]),
  matchL1(gStore.getData(this).matchL1[gStore.getIndex(this)]),
  superCluster_(gStore.getData(this).superCluster_[gStore.getIndex(this)])
{
}

panda::PPhoton::~PPhoton()
{
  gStore.free(this);
}

panda::PPhoton&
panda::PPhoton::operator=(PPhoton const& _src)
{
  PParticle::operator=(_src);

  chiso = _src.chiso;
  chworstiso = _src.chworstiso;
  chisoMax = _src.chisoMax;
  nhiso = _src.nhiso;
  phiso = _src.phiso;
  ecaliso = _src.ecaliso;
  hcaliso = _src.hcaliso;
  sieie = _src.sieie;
  sipip = _src.sipip;
  hOverE = _src.hOverE;
  geniso = _src.geniso;
  mipEnergy = _src.mipEnergy;
  e33 = _src.e33;
  emax = _src.emax;
  e2nd = _src.e2nd;
  r9 = _src.r9;
  etaWidth = _src.etaWidth;
  phiWidth = _src.phiWidth;
  time = _src.time;
  timeSpan = _src.timeSpan;
  genMatchDR = _src.genMatchDR;
  loose = _src.loose;
  medium = _src.medium;
  tight = _src.tight;
  highpt = _src.highpt;
  pixelVeto = _src.pixelVeto;
  csafeVeto = _src.csafeVeto;
  superCluster_ = _src.superCluster_;

  return *this;
}

void
panda::PPhoton::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "chiso", _status, _branches);
  utils::setStatus(_tree, name, "chworstiso", _status, _branches);
  utils::setStatus(_tree, name, "chisoMax", _status, _branches);
  utils::setStatus(_tree, name, "nhiso", _status, _branches);
  utils::setStatus(_tree, name, "phiso", _status, _branches);
  utils::setStatus(_tree, name, "ecaliso", _status, _branches);
  utils::setStatus(_tree, name, "hcaliso", _status, _branches);
  utils::setStatus(_tree, name, "sieie", _status, _branches);
  utils::setStatus(_tree, name, "sipip", _status, _branches);
  utils::setStatus(_tree, name, "hOverE", _status, _branches);
  utils::setStatus(_tree, name, "geniso", _status, _branches);
  utils::setStatus(_tree, name, "mipEnergy", _status, _branches);
  utils::setStatus(_tree, name, "e33", _status, _branches);
  utils::setStatus(_tree, name, "emax", _status, _branches);
  utils::setStatus(_tree, name, "e2nd", _status, _branches);
  utils::setStatus(_tree, name, "r9", _status, _branches);
  utils::setStatus(_tree, name, "etaWidth", _status, _branches);
  utils::setStatus(_tree, name, "phiWidth", _status, _branches);
  utils::setStatus(_tree, name, "time", _status, _branches);
  utils::setStatus(_tree, name, "timeSpan", _status, _branches);
  utils::setStatus(_tree, name, "genMatchDR", _status, _branches);
  utils::setStatus(_tree, name, "loose", _status, _branches);
  utils::setStatus(_tree, name, "medium", _status, _branches);
  utils::setStatus(_tree, name, "tight", _status, _branches);
  utils::setStatus(_tree, name, "highpt", _status, _branches);
  utils::setStatus(_tree, name, "pixelVeto", _status, _branches);
  utils::setStatus(_tree, name, "csafeVeto", _status, _branches);
  utils::setStatus(_tree, name, "matchL1", _status, _branches);
  utils::setStatus(_tree, name, "superCluster_", _status, _branches);
}

void
panda::PPhoton::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::setAddress(_tree, _branches);

  TString name(gStore.getName(this));

  utils::setStatusAndAddress(_tree, name, "chiso", &chiso, _branches);
  utils::setStatusAndAddress(_tree, name, "chworstiso", &chworstiso, _branches);
  utils::setStatusAndAddress(_tree, name, "chisoMax", &chisoMax, _branches);
  utils::setStatusAndAddress(_tree, name, "nhiso", &nhiso, _branches);
  utils::setStatusAndAddress(_tree, name, "phiso", &phiso, _branches);
  utils::setStatusAndAddress(_tree, name, "ecaliso", &ecaliso, _branches);
  utils::setStatusAndAddress(_tree, name, "hcaliso", &hcaliso, _branches);
  utils::setStatusAndAddress(_tree, name, "sieie", &sieie, _branches);
  utils::setStatusAndAddress(_tree, name, "sipip", &sipip, _branches);
  utils::setStatusAndAddress(_tree, name, "hOverE", &hOverE, _branches);
  utils::setStatusAndAddress(_tree, name, "geniso", &geniso, _branches);
  utils::setStatusAndAddress(_tree, name, "mipEnergy", &mipEnergy, _branches);
  utils::setStatusAndAddress(_tree, name, "e33", &e33, _branches);
  utils::setStatusAndAddress(_tree, name, "emax", &emax, _branches);
  utils::setStatusAndAddress(_tree, name, "e2nd", &e2nd, _branches);
  utils::setStatusAndAddress(_tree, name, "r9", &r9, _branches);
  utils::setStatusAndAddress(_tree, name, "etaWidth", &etaWidth, _branches);
  utils::setStatusAndAddress(_tree, name, "phiWidth", &phiWidth, _branches);
  utils::setStatusAndAddress(_tree, name, "time", &time, _branches);
  utils::setStatusAndAddress(_tree, name, "timeSpan", &timeSpan, _branches);
  utils::setStatusAndAddress(_tree, name, "genMatchDR", &genMatchDR, _branches);
  utils::setStatusAndAddress(_tree, name, "loose", &loose, _branches);
  utils::setStatusAndAddress(_tree, name, "medium", &medium, _branches);
  utils::setStatusAndAddress(_tree, name, "tight", &tight, _branches);
  utils::setStatusAndAddress(_tree, name, "highpt", &highpt, _branches);
  utils::setStatusAndAddress(_tree, name, "pixelVeto", &pixelVeto, _branches);
  utils::setStatusAndAddress(_tree, name, "csafeVeto", &csafeVeto, _branches);
  utils::setStatusAndAddress(_tree, name, "matchL1", matchL1, _branches);
  utils::setStatusAndAddress(_tree, name, "superCluster_", &superCluster_, _branches);
}

void
panda::PPhoton::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "chiso", "", 'F', &chiso, _branches);
  utils::book(_tree, name, "chworstiso", "", 'F', &chworstiso, _branches);
  utils::book(_tree, name, "chisoMax", "", 'F', &chisoMax, _branches);
  utils::book(_tree, name, "nhiso", "", 'F', &nhiso, _branches);
  utils::book(_tree, name, "phiso", "", 'F', &phiso, _branches);
  utils::book(_tree, name, "ecaliso", "", 'F', &ecaliso, _branches);
  utils::book(_tree, name, "hcaliso", "", 'F', &hcaliso, _branches);
  utils::book(_tree, name, "sieie", "", 'F', &sieie, _branches);
  utils::book(_tree, name, "sipip", "", 'F', &sipip, _branches);
  utils::book(_tree, name, "hOverE", "", 'F', &hOverE, _branches);
  utils::book(_tree, name, "geniso", "", 'F', &geniso, _branches);
  utils::book(_tree, name, "mipEnergy", "", 'F', &mipEnergy, _branches);
  utils::book(_tree, name, "e33", "", 'F', &e33, _branches);
  utils::book(_tree, name, "emax", "", 'F', &emax, _branches);
  utils::book(_tree, name, "e2nd", "", 'F', &e2nd, _branches);
  utils::book(_tree, name, "r9", "", 'F', &r9, _branches);
  utils::book(_tree, name, "etaWidth", "", 'F', &etaWidth, _branches);
  utils::book(_tree, name, "phiWidth", "", 'F', &phiWidth, _branches);
  utils::book(_tree, name, "time", "", 'F', &time, _branches);
  utils::book(_tree, name, "timeSpan", "", 'F', &timeSpan, _branches);
  utils::book(_tree, name, "genMatchDR", "", 'F', &genMatchDR, _branches);
  utils::book(_tree, name, "loose", "", 'O', &loose, _branches);
  utils::book(_tree, name, "medium", "", 'O', &medium, _branches);
  utils::book(_tree, name, "tight", "", 'O', &tight, _branches);
  utils::book(_tree, name, "highpt", "", 'O', &highpt, _branches);
  utils::book(_tree, name, "pixelVeto", "", 'O', &pixelVeto, _branches);
  utils::book(_tree, name, "csafeVeto", "", 'O', &csafeVeto, _branches);
  utils::book(_tree, name, "matchL1", "[nPhotonL1Objects]", 'O', matchL1, _branches);
  utils::book(_tree, name, "superCluster_", "", 'i', &superCluster_, _branches);
}

void
panda::PPhoton::init()
{
  PParticle::init();

  chiso = 0.;
  chworstiso = 0.;
  chisoMax = 0.;
  nhiso = 0.;
  phiso = 0.;
  ecaliso = 0.;
  hcaliso = 0.;
  sieie = 0.;
  sipip = 0.;
  hOverE = 0.;
  geniso = 0.;
  mipEnergy = 0.;
  e33 = 0.;
  emax = 0.;
  e2nd = 0.;
  r9 = 0.;
  etaWidth = 0.;
  phiWidth = 0.;
  time = 0.;
  timeSpan = 0.;
  genMatchDR = 0.;
  loose = false;
  medium = false;
  tight = false;
  highpt = false;
  pixelVeto = false;
  csafeVeto = false;
  for (auto& p0 : matchL1) p0 = false;
  superCluster_ = PSuperCluster::array_data::NMAX;
}


/* BEGIN CUSTOM */
/* END CUSTOM */
