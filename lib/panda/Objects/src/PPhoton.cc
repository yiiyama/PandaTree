#include "../interface/PPhoton.h"

void
panda::PPhoton::datastore::allocate(UInt_t _nmax)
{
  PParticle::datastore::allocate(_nmax);

  chiso = new Float_t[nmax_];
  chworstiso = new Float_t[nmax_];
  chisoMax = new Float_t[nmax_];
  nhiso = new Float_t[nmax_];
  phiso = new Float_t[nmax_];
  ecaliso = new Float_t[nmax_];
  hcaliso = new Float_t[nmax_];
  sieie = new Float_t[nmax_];
  sipip = new Float_t[nmax_];
  hOverE = new Float_t[nmax_];
  geniso = new Float_t[nmax_];
  mipEnergy = new Float_t[nmax_];
  e33 = new Float_t[nmax_];
  emax = new Float_t[nmax_];
  e2nd = new Float_t[nmax_];
  r9 = new Float_t[nmax_];
  etaWidth = new Float_t[nmax_];
  phiWidth = new Float_t[nmax_];
  time = new Float_t[nmax_];
  timeSpan = new Float_t[nmax_];
  genMatchDR = new Float_t[nmax_];
  loose = new Bool_t[nmax_];
  medium = new Bool_t[nmax_];
  tight = new Bool_t[nmax_];
  highpt = new Bool_t[nmax_];
  pixelVeto = new Bool_t[nmax_];
  csafeVeto = new Bool_t[nmax_];
  matchL1 = new Bool_t[nmax_][nPhotonL1Objects];
  superCluster_ = new UInt_t[nmax_];
}

void
panda::PPhoton::datastore::deallocate()
{
  PParticle::datastore::deallocate();

  delete [] chiso;
  chiso = 0;
  delete [] chworstiso;
  chworstiso = 0;
  delete [] chisoMax;
  chisoMax = 0;
  delete [] nhiso;
  nhiso = 0;
  delete [] phiso;
  phiso = 0;
  delete [] ecaliso;
  ecaliso = 0;
  delete [] hcaliso;
  hcaliso = 0;
  delete [] sieie;
  sieie = 0;
  delete [] sipip;
  sipip = 0;
  delete [] hOverE;
  hOverE = 0;
  delete [] geniso;
  geniso = 0;
  delete [] mipEnergy;
  mipEnergy = 0;
  delete [] e33;
  e33 = 0;
  delete [] emax;
  emax = 0;
  delete [] e2nd;
  e2nd = 0;
  delete [] r9;
  r9 = 0;
  delete [] etaWidth;
  etaWidth = 0;
  delete [] phiWidth;
  phiWidth = 0;
  delete [] time;
  time = 0;
  delete [] timeSpan;
  timeSpan = 0;
  delete [] genMatchDR;
  genMatchDR = 0;
  delete [] loose;
  loose = 0;
  delete [] medium;
  medium = 0;
  delete [] tight;
  tight = 0;
  delete [] highpt;
  highpt = 0;
  delete [] pixelVeto;
  pixelVeto = 0;
  delete [] csafeVeto;
  csafeVeto = 0;
  delete [] matchL1;
  matchL1 = 0;
  delete [] superCluster_;
  superCluster_ = 0;
}

void
panda::PPhoton::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PParticle::datastore::setStatus(_tree, _name, _status, _branches);

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
panda::PPhoton::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticle::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "chiso", chiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chworstiso", chworstiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chisoMax", chisoMax, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhiso", nhiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phiso", phiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ecaliso", ecaliso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hcaliso", hcaliso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sieie", sieie, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sipip", sipip, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hOverE", hOverE, _branches, _setStatus);
  utils::setAddress(_tree, _name, "geniso", geniso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mipEnergy", mipEnergy, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e33", e33, _branches, _setStatus);
  utils::setAddress(_tree, _name, "emax", emax, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e2nd", e2nd, _branches, _setStatus);
  utils::setAddress(_tree, _name, "r9", r9, _branches, _setStatus);
  utils::setAddress(_tree, _name, "etaWidth", etaWidth, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phiWidth", phiWidth, _branches, _setStatus);
  utils::setAddress(_tree, _name, "time", time, _branches, _setStatus);
  utils::setAddress(_tree, _name, "timeSpan", timeSpan, _branches, _setStatus);
  utils::setAddress(_tree, _name, "genMatchDR", genMatchDR, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose", loose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "medium", medium, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight", tight, _branches, _setStatus);
  utils::setAddress(_tree, _name, "highpt", highpt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "pixelVeto", pixelVeto, _branches, _setStatus);
  utils::setAddress(_tree, _name, "csafeVeto", csafeVeto, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchL1", matchL1, _branches, _setStatus);
  utils::setAddress(_tree, _name, "superCluster_", superCluster_, _branches, _setStatus);
}

void
panda::PPhoton::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PParticle::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "chiso", size, 'F', chiso, _branches);
  utils::book(_tree, _name, "chworstiso", size, 'F', chworstiso, _branches);
  utils::book(_tree, _name, "chisoMax", size, 'F', chisoMax, _branches);
  utils::book(_tree, _name, "nhiso", size, 'F', nhiso, _branches);
  utils::book(_tree, _name, "phiso", size, 'F', phiso, _branches);
  utils::book(_tree, _name, "ecaliso", size, 'F', ecaliso, _branches);
  utils::book(_tree, _name, "hcaliso", size, 'F', hcaliso, _branches);
  utils::book(_tree, _name, "sieie", size, 'F', sieie, _branches);
  utils::book(_tree, _name, "sipip", size, 'F', sipip, _branches);
  utils::book(_tree, _name, "hOverE", size, 'F', hOverE, _branches);
  utils::book(_tree, _name, "geniso", size, 'F', geniso, _branches);
  utils::book(_tree, _name, "mipEnergy", size, 'F', mipEnergy, _branches);
  utils::book(_tree, _name, "e33", size, 'F', e33, _branches);
  utils::book(_tree, _name, "emax", size, 'F', emax, _branches);
  utils::book(_tree, _name, "e2nd", size, 'F', e2nd, _branches);
  utils::book(_tree, _name, "r9", size, 'F', r9, _branches);
  utils::book(_tree, _name, "etaWidth", size, 'F', etaWidth, _branches);
  utils::book(_tree, _name, "phiWidth", size, 'F', phiWidth, _branches);
  utils::book(_tree, _name, "time", size, 'F', time, _branches);
  utils::book(_tree, _name, "timeSpan", size, 'F', timeSpan, _branches);
  utils::book(_tree, _name, "genMatchDR", size, 'F', genMatchDR, _branches);
  utils::book(_tree, _name, "loose", size, 'O', loose, _branches);
  utils::book(_tree, _name, "medium", size, 'O', medium, _branches);
  utils::book(_tree, _name, "tight", size, 'O', tight, _branches);
  utils::book(_tree, _name, "highpt", size, 'O', highpt, _branches);
  utils::book(_tree, _name, "pixelVeto", size, 'O', pixelVeto, _branches);
  utils::book(_tree, _name, "csafeVeto", size, 'O', csafeVeto, _branches);
  utils::book(_tree, _name, "matchL1", size + "[nPhotonL1Objects]", 'O', matchL1, _branches);
  utils::book(_tree, _name, "superCluster_", size, 'i', superCluster_, _branches);
}

void
panda::PPhoton::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  PParticle::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "chiso");
  utils::resetAddress(_tree, _name, "chworstiso");
  utils::resetAddress(_tree, _name, "chisoMax");
  utils::resetAddress(_tree, _name, "nhiso");
  utils::resetAddress(_tree, _name, "phiso");
  utils::resetAddress(_tree, _name, "ecaliso");
  utils::resetAddress(_tree, _name, "hcaliso");
  utils::resetAddress(_tree, _name, "sieie");
  utils::resetAddress(_tree, _name, "sipip");
  utils::resetAddress(_tree, _name, "hOverE");
  utils::resetAddress(_tree, _name, "geniso");
  utils::resetAddress(_tree, _name, "mipEnergy");
  utils::resetAddress(_tree, _name, "e33");
  utils::resetAddress(_tree, _name, "emax");
  utils::resetAddress(_tree, _name, "e2nd");
  utils::resetAddress(_tree, _name, "r9");
  utils::resetAddress(_tree, _name, "etaWidth");
  utils::resetAddress(_tree, _name, "phiWidth");
  utils::resetAddress(_tree, _name, "time");
  utils::resetAddress(_tree, _name, "timeSpan");
  utils::resetAddress(_tree, _name, "genMatchDR");
  utils::resetAddress(_tree, _name, "loose");
  utils::resetAddress(_tree, _name, "medium");
  utils::resetAddress(_tree, _name, "tight");
  utils::resetAddress(_tree, _name, "highpt");
  utils::resetAddress(_tree, _name, "pixelVeto");
  utils::resetAddress(_tree, _name, "csafeVeto");
  utils::resetAddress(_tree, _name, "matchL1");
  utils::resetAddress(_tree, _name, "superCluster_");
}

panda::PPhoton::PPhoton(char const* _name/* = ""*/) :
  PParticle(new PPhotonArray(1, _name)),
  chiso(gStore.getData(this).chiso[0]),
  chworstiso(gStore.getData(this).chworstiso[0]),
  chisoMax(gStore.getData(this).chisoMax[0]),
  nhiso(gStore.getData(this).nhiso[0]),
  phiso(gStore.getData(this).phiso[0]),
  ecaliso(gStore.getData(this).ecaliso[0]),
  hcaliso(gStore.getData(this).hcaliso[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  geniso(gStore.getData(this).geniso[0]),
  mipEnergy(gStore.getData(this).mipEnergy[0]),
  e33(gStore.getData(this).e33[0]),
  emax(gStore.getData(this).emax[0]),
  e2nd(gStore.getData(this).e2nd[0]),
  r9(gStore.getData(this).r9[0]),
  etaWidth(gStore.getData(this).etaWidth[0]),
  phiWidth(gStore.getData(this).phiWidth[0]),
  time(gStore.getData(this).time[0]),
  timeSpan(gStore.getData(this).timeSpan[0]),
  genMatchDR(gStore.getData(this).genMatchDR[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  highpt(gStore.getData(this).highpt[0]),
  pixelVeto(gStore.getData(this).pixelVeto[0]),
  csafeVeto(gStore.getData(this).csafeVeto[0]),
  matchL1(gStore.getData(this).matchL1[0]),
  superCluster(gStore.getData(this).superCluster_[0])
{
}

panda::PPhoton::PPhoton(datastore& _data, UInt_t _idx) :
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
  superCluster(_data.superCluster_[_idx])
{
}

panda::PPhoton::PPhoton(PPhoton const& _src) :
  PParticle(new PPhotonArray(1, gStore.getName(&_src))),
  chiso(gStore.getData(this).chiso[0]),
  chworstiso(gStore.getData(this).chworstiso[0]),
  chisoMax(gStore.getData(this).chisoMax[0]),
  nhiso(gStore.getData(this).nhiso[0]),
  phiso(gStore.getData(this).phiso[0]),
  ecaliso(gStore.getData(this).ecaliso[0]),
  hcaliso(gStore.getData(this).hcaliso[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  geniso(gStore.getData(this).geniso[0]),
  mipEnergy(gStore.getData(this).mipEnergy[0]),
  e33(gStore.getData(this).e33[0]),
  emax(gStore.getData(this).emax[0]),
  e2nd(gStore.getData(this).e2nd[0]),
  r9(gStore.getData(this).r9[0]),
  etaWidth(gStore.getData(this).etaWidth[0]),
  phiWidth(gStore.getData(this).phiWidth[0]),
  time(gStore.getData(this).time[0]),
  timeSpan(gStore.getData(this).timeSpan[0]),
  genMatchDR(gStore.getData(this).genMatchDR[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  highpt(gStore.getData(this).highpt[0]),
  pixelVeto(gStore.getData(this).pixelVeto[0]),
  csafeVeto(gStore.getData(this).csafeVeto[0]),
  matchL1(gStore.getData(this).matchL1[0]),
  superCluster(gStore.getData(this).superCluster_[0])
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
  superCluster = _src.superCluster;
}

panda::PPhoton::PPhoton(ArrayBase* _array) :
  PParticle(_array),
  chiso(gStore.getData(this).chiso[0]),
  chworstiso(gStore.getData(this).chworstiso[0]),
  chisoMax(gStore.getData(this).chisoMax[0]),
  nhiso(gStore.getData(this).nhiso[0]),
  phiso(gStore.getData(this).phiso[0]),
  ecaliso(gStore.getData(this).ecaliso[0]),
  hcaliso(gStore.getData(this).hcaliso[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  geniso(gStore.getData(this).geniso[0]),
  mipEnergy(gStore.getData(this).mipEnergy[0]),
  e33(gStore.getData(this).e33[0]),
  emax(gStore.getData(this).emax[0]),
  e2nd(gStore.getData(this).e2nd[0]),
  r9(gStore.getData(this).r9[0]),
  etaWidth(gStore.getData(this).etaWidth[0]),
  phiWidth(gStore.getData(this).phiWidth[0]),
  time(gStore.getData(this).time[0]),
  timeSpan(gStore.getData(this).timeSpan[0]),
  genMatchDR(gStore.getData(this).genMatchDR[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  highpt(gStore.getData(this).highpt[0]),
  pixelVeto(gStore.getData(this).pixelVeto[0]),
  csafeVeto(gStore.getData(this).csafeVeto[0]),
  matchL1(gStore.getData(this).matchL1[0]),
  superCluster(gStore.getData(this).superCluster_[0])
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
  superCluster = _src.superCluster;

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
panda::PPhoton::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PParticle::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "chiso", &chiso, _branches, _setStatus);
  utils::setAddress(_tree, name, "chworstiso", &chworstiso, _branches, _setStatus);
  utils::setAddress(_tree, name, "chisoMax", &chisoMax, _branches, _setStatus);
  utils::setAddress(_tree, name, "nhiso", &nhiso, _branches, _setStatus);
  utils::setAddress(_tree, name, "phiso", &phiso, _branches, _setStatus);
  utils::setAddress(_tree, name, "ecaliso", &ecaliso, _branches, _setStatus);
  utils::setAddress(_tree, name, "hcaliso", &hcaliso, _branches, _setStatus);
  utils::setAddress(_tree, name, "sieie", &sieie, _branches, _setStatus);
  utils::setAddress(_tree, name, "sipip", &sipip, _branches, _setStatus);
  utils::setAddress(_tree, name, "hOverE", &hOverE, _branches, _setStatus);
  utils::setAddress(_tree, name, "geniso", &geniso, _branches, _setStatus);
  utils::setAddress(_tree, name, "mipEnergy", &mipEnergy, _branches, _setStatus);
  utils::setAddress(_tree, name, "e33", &e33, _branches, _setStatus);
  utils::setAddress(_tree, name, "emax", &emax, _branches, _setStatus);
  utils::setAddress(_tree, name, "e2nd", &e2nd, _branches, _setStatus);
  utils::setAddress(_tree, name, "r9", &r9, _branches, _setStatus);
  utils::setAddress(_tree, name, "etaWidth", &etaWidth, _branches, _setStatus);
  utils::setAddress(_tree, name, "phiWidth", &phiWidth, _branches, _setStatus);
  utils::setAddress(_tree, name, "time", &time, _branches, _setStatus);
  utils::setAddress(_tree, name, "timeSpan", &timeSpan, _branches, _setStatus);
  utils::setAddress(_tree, name, "genMatchDR", &genMatchDR, _branches, _setStatus);
  utils::setAddress(_tree, name, "loose", &loose, _branches, _setStatus);
  utils::setAddress(_tree, name, "medium", &medium, _branches, _setStatus);
  utils::setAddress(_tree, name, "tight", &tight, _branches, _setStatus);
  utils::setAddress(_tree, name, "highpt", &highpt, _branches, _setStatus);
  utils::setAddress(_tree, name, "pixelVeto", &pixelVeto, _branches, _setStatus);
  utils::setAddress(_tree, name, "csafeVeto", &csafeVeto, _branches, _setStatus);
  utils::setAddress(_tree, name, "matchL1", matchL1, _branches, _setStatus);
  utils::setAddress(_tree, name, "superCluster_", &superCluster.idx(), _branches, true);
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
  utils::book(_tree, name, "superCluster_", "", 'i', &superCluster.idx(), _branches);
}

void
panda::PPhoton::resetAddress(TTree& _tree)
{
  PParticle::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "chiso");
  utils::resetAddress(_tree, name, "chworstiso");
  utils::resetAddress(_tree, name, "chisoMax");
  utils::resetAddress(_tree, name, "nhiso");
  utils::resetAddress(_tree, name, "phiso");
  utils::resetAddress(_tree, name, "ecaliso");
  utils::resetAddress(_tree, name, "hcaliso");
  utils::resetAddress(_tree, name, "sieie");
  utils::resetAddress(_tree, name, "sipip");
  utils::resetAddress(_tree, name, "hOverE");
  utils::resetAddress(_tree, name, "geniso");
  utils::resetAddress(_tree, name, "mipEnergy");
  utils::resetAddress(_tree, name, "e33");
  utils::resetAddress(_tree, name, "emax");
  utils::resetAddress(_tree, name, "e2nd");
  utils::resetAddress(_tree, name, "r9");
  utils::resetAddress(_tree, name, "etaWidth");
  utils::resetAddress(_tree, name, "phiWidth");
  utils::resetAddress(_tree, name, "time");
  utils::resetAddress(_tree, name, "timeSpan");
  utils::resetAddress(_tree, name, "genMatchDR");
  utils::resetAddress(_tree, name, "loose");
  utils::resetAddress(_tree, name, "medium");
  utils::resetAddress(_tree, name, "tight");
  utils::resetAddress(_tree, name, "highpt");
  utils::resetAddress(_tree, name, "pixelVeto");
  utils::resetAddress(_tree, name, "csafeVeto");
  utils::resetAddress(_tree, name, "matchL1");
  utils::resetAddress(_tree, name, "superCluster_");
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
  superCluster.init();
}


/* BEGIN CUSTOM */
/* END CUSTOM */
