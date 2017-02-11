#include "../interface/Photon.h"

void
panda::Photon::datastore::allocate(UInt_t _nmax)
{
  ParticleP::datastore::allocate(_nmax);

  chiso = new Float_t[nmax_];
  chisoWorst = new Float_t[nmax_];
  nhiso = new Float_t[nmax_];
  phoiso = new Float_t[nmax_];
  sieie = new Float_t[nmax_];
  sipip = new Float_t[nmax_];
  hOverE = new Float_t[nmax_];
  geniso = new Float_t[nmax_];
  mipEnergy = new Float_t[nmax_];
  e33 = new Float_t[nmax_];
  e4 = new Float_t[nmax_];
  eseed = new Float_t[nmax_];
  emax = new Float_t[nmax_];
  e2nd = new Float_t[nmax_];
  r9 = new Float_t[nmax_];
  etaWidth = new Float_t[nmax_];
  phiWidth = new Float_t[nmax_];
  time = new Float_t[nmax_];
  timeSpan = new Float_t[nmax_];
  loose = new Bool_t[nmax_];
  medium = new Bool_t[nmax_];
  tight = new Bool_t[nmax_];
  highpt = new Bool_t[nmax_];
  pixelVeto = new Bool_t[nmax_];
  csafeVeto = new Bool_t[nmax_];
  triggerMatch = new Bool_t[nmax_][nPhotonTriggerObjects];
  superCluster_ = new Int_t[nmax_];
  matchedGen_ = new Int_t[nmax_];
}

void
panda::Photon::datastore::deallocate()
{
  ParticleP::datastore::deallocate();

  delete [] chiso;
  chiso = 0;
  delete [] chisoWorst;
  chisoWorst = 0;
  delete [] nhiso;
  nhiso = 0;
  delete [] phoiso;
  phoiso = 0;
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
  delete [] e4;
  e4 = 0;
  delete [] eseed;
  eseed = 0;
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
  delete [] triggerMatch;
  triggerMatch = 0;
  delete [] superCluster_;
  superCluster_ = 0;
  delete [] matchedGen_;
  matchedGen_ = 0;
}

void
panda::Photon::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  ParticleP::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "chiso", _branches);
  utils::setStatus(_tree, _name, "chisoWorst", _branches);
  utils::setStatus(_tree, _name, "nhiso", _branches);
  utils::setStatus(_tree, _name, "phoiso", _branches);
  utils::setStatus(_tree, _name, "sieie", _branches);
  utils::setStatus(_tree, _name, "sipip", _branches);
  utils::setStatus(_tree, _name, "hOverE", _branches);
  utils::setStatus(_tree, _name, "geniso", _branches);
  utils::setStatus(_tree, _name, "mipEnergy", _branches);
  utils::setStatus(_tree, _name, "e33", _branches);
  utils::setStatus(_tree, _name, "e4", _branches);
  utils::setStatus(_tree, _name, "eseed", _branches);
  utils::setStatus(_tree, _name, "emax", _branches);
  utils::setStatus(_tree, _name, "e2nd", _branches);
  utils::setStatus(_tree, _name, "r9", _branches);
  utils::setStatus(_tree, _name, "etaWidth", _branches);
  utils::setStatus(_tree, _name, "phiWidth", _branches);
  utils::setStatus(_tree, _name, "time", _branches);
  utils::setStatus(_tree, _name, "timeSpan", _branches);
  utils::setStatus(_tree, _name, "loose", _branches);
  utils::setStatus(_tree, _name, "medium", _branches);
  utils::setStatus(_tree, _name, "tight", _branches);
  utils::setStatus(_tree, _name, "highpt", _branches);
  utils::setStatus(_tree, _name, "pixelVeto", _branches);
  utils::setStatus(_tree, _name, "csafeVeto", _branches);
  utils::setStatus(_tree, _name, "triggerMatch", _branches);
  utils::setStatus(_tree, _name, "superCluster_", _branches);
  utils::setStatus(_tree, _name, "matchedGen_", _branches);
}

panda::utils::BranchList
panda::Photon::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(ParticleP::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "chiso"));
  blist.push_back(utils::getStatus(_tree, _name, "chisoWorst"));
  blist.push_back(utils::getStatus(_tree, _name, "nhiso"));
  blist.push_back(utils::getStatus(_tree, _name, "phoiso"));
  blist.push_back(utils::getStatus(_tree, _name, "sieie"));
  blist.push_back(utils::getStatus(_tree, _name, "sipip"));
  blist.push_back(utils::getStatus(_tree, _name, "hOverE"));
  blist.push_back(utils::getStatus(_tree, _name, "geniso"));
  blist.push_back(utils::getStatus(_tree, _name, "mipEnergy"));
  blist.push_back(utils::getStatus(_tree, _name, "e33"));
  blist.push_back(utils::getStatus(_tree, _name, "e4"));
  blist.push_back(utils::getStatus(_tree, _name, "eseed"));
  blist.push_back(utils::getStatus(_tree, _name, "emax"));
  blist.push_back(utils::getStatus(_tree, _name, "e2nd"));
  blist.push_back(utils::getStatus(_tree, _name, "r9"));
  blist.push_back(utils::getStatus(_tree, _name, "etaWidth"));
  blist.push_back(utils::getStatus(_tree, _name, "phiWidth"));
  blist.push_back(utils::getStatus(_tree, _name, "time"));
  blist.push_back(utils::getStatus(_tree, _name, "timeSpan"));
  blist.push_back(utils::getStatus(_tree, _name, "loose"));
  blist.push_back(utils::getStatus(_tree, _name, "medium"));
  blist.push_back(utils::getStatus(_tree, _name, "tight"));
  blist.push_back(utils::getStatus(_tree, _name, "highpt"));
  blist.push_back(utils::getStatus(_tree, _name, "pixelVeto"));
  blist.push_back(utils::getStatus(_tree, _name, "csafeVeto"));
  blist.push_back(utils::getStatus(_tree, _name, "triggerMatch"));
  blist.push_back(utils::getStatus(_tree, _name, "superCluster_"));
  blist.push_back(utils::getStatus(_tree, _name, "matchedGen_"));

  return blist;
}

panda::utils::BranchList
panda::Photon::datastore::getBranchNames(TString const& _name) const
{
  utils::BranchList blist(ParticleP::datastore::getBranchNames(_name));

  blist.push_back(utils::BranchName("chiso").fullName(_name));
  blist.push_back(utils::BranchName("chisoWorst").fullName(_name));
  blist.push_back(utils::BranchName("nhiso").fullName(_name));
  blist.push_back(utils::BranchName("phoiso").fullName(_name));
  blist.push_back(utils::BranchName("sieie").fullName(_name));
  blist.push_back(utils::BranchName("sipip").fullName(_name));
  blist.push_back(utils::BranchName("hOverE").fullName(_name));
  blist.push_back(utils::BranchName("geniso").fullName(_name));
  blist.push_back(utils::BranchName("mipEnergy").fullName(_name));
  blist.push_back(utils::BranchName("e33").fullName(_name));
  blist.push_back(utils::BranchName("e4").fullName(_name));
  blist.push_back(utils::BranchName("eseed").fullName(_name));
  blist.push_back(utils::BranchName("emax").fullName(_name));
  blist.push_back(utils::BranchName("e2nd").fullName(_name));
  blist.push_back(utils::BranchName("r9").fullName(_name));
  blist.push_back(utils::BranchName("etaWidth").fullName(_name));
  blist.push_back(utils::BranchName("phiWidth").fullName(_name));
  blist.push_back(utils::BranchName("time").fullName(_name));
  blist.push_back(utils::BranchName("timeSpan").fullName(_name));
  blist.push_back(utils::BranchName("loose").fullName(_name));
  blist.push_back(utils::BranchName("medium").fullName(_name));
  blist.push_back(utils::BranchName("tight").fullName(_name));
  blist.push_back(utils::BranchName("highpt").fullName(_name));
  blist.push_back(utils::BranchName("pixelVeto").fullName(_name));
  blist.push_back(utils::BranchName("csafeVeto").fullName(_name));
  blist.push_back(utils::BranchName("triggerMatch").fullName(_name));
  blist.push_back(utils::BranchName("superCluster_").fullName(_name));
  blist.push_back(utils::BranchName("matchedGen_").fullName(_name));

  return blist;
}

void
panda::Photon::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleP::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "chiso", chiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chisoWorst", chisoWorst, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhiso", nhiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phoiso", phoiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sieie", sieie, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sipip", sipip, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hOverE", hOverE, _branches, _setStatus);
  utils::setAddress(_tree, _name, "geniso", geniso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mipEnergy", mipEnergy, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e33", e33, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e4", e4, _branches, _setStatus);
  utils::setAddress(_tree, _name, "eseed", eseed, _branches, _setStatus);
  utils::setAddress(_tree, _name, "emax", emax, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e2nd", e2nd, _branches, _setStatus);
  utils::setAddress(_tree, _name, "r9", r9, _branches, _setStatus);
  utils::setAddress(_tree, _name, "etaWidth", etaWidth, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phiWidth", phiWidth, _branches, _setStatus);
  utils::setAddress(_tree, _name, "time", time, _branches, _setStatus);
  utils::setAddress(_tree, _name, "timeSpan", timeSpan, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose", loose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "medium", medium, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight", tight, _branches, _setStatus);
  utils::setAddress(_tree, _name, "highpt", highpt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "pixelVeto", pixelVeto, _branches, _setStatus);
  utils::setAddress(_tree, _name, "csafeVeto", csafeVeto, _branches, _setStatus);
  utils::setAddress(_tree, _name, "triggerMatch", triggerMatch, _branches, _setStatus);
  utils::setAddress(_tree, _name, "superCluster_", superCluster_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedGen_", matchedGen_, _branches, _setStatus);
}

void
panda::Photon::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ParticleP::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "chiso", size, 'F', chiso, _branches);
  utils::book(_tree, _name, "chisoWorst", size, 'F', chisoWorst, _branches);
  utils::book(_tree, _name, "nhiso", size, 'F', nhiso, _branches);
  utils::book(_tree, _name, "phoiso", size, 'F', phoiso, _branches);
  utils::book(_tree, _name, "sieie", size, 'F', sieie, _branches);
  utils::book(_tree, _name, "sipip", size, 'F', sipip, _branches);
  utils::book(_tree, _name, "hOverE", size, 'F', hOverE, _branches);
  utils::book(_tree, _name, "geniso", size, 'F', geniso, _branches);
  utils::book(_tree, _name, "mipEnergy", size, 'F', mipEnergy, _branches);
  utils::book(_tree, _name, "e33", size, 'F', e33, _branches);
  utils::book(_tree, _name, "e4", size, 'F', e4, _branches);
  utils::book(_tree, _name, "eseed", size, 'F', eseed, _branches);
  utils::book(_tree, _name, "emax", size, 'F', emax, _branches);
  utils::book(_tree, _name, "e2nd", size, 'F', e2nd, _branches);
  utils::book(_tree, _name, "r9", size, 'F', r9, _branches);
  utils::book(_tree, _name, "etaWidth", size, 'F', etaWidth, _branches);
  utils::book(_tree, _name, "phiWidth", size, 'F', phiWidth, _branches);
  utils::book(_tree, _name, "time", size, 'F', time, _branches);
  utils::book(_tree, _name, "timeSpan", size, 'F', timeSpan, _branches);
  utils::book(_tree, _name, "loose", size, 'O', loose, _branches);
  utils::book(_tree, _name, "medium", size, 'O', medium, _branches);
  utils::book(_tree, _name, "tight", size, 'O', tight, _branches);
  utils::book(_tree, _name, "highpt", size, 'O', highpt, _branches);
  utils::book(_tree, _name, "pixelVeto", size, 'O', pixelVeto, _branches);
  utils::book(_tree, _name, "csafeVeto", size, 'O', csafeVeto, _branches);
  utils::book(_tree, _name, "triggerMatch", size + TString::Format("[%d]", nPhotonTriggerObjects), 'O', triggerMatch, _branches);
  utils::book(_tree, _name, "superCluster_", size, 'I', superCluster_, _branches);
  utils::book(_tree, _name, "matchedGen_", size, 'I', matchedGen_, _branches);
}

void
panda::Photon::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  ParticleP::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "chiso");
  utils::resetAddress(_tree, _name, "chisoWorst");
  utils::resetAddress(_tree, _name, "nhiso");
  utils::resetAddress(_tree, _name, "phoiso");
  utils::resetAddress(_tree, _name, "sieie");
  utils::resetAddress(_tree, _name, "sipip");
  utils::resetAddress(_tree, _name, "hOverE");
  utils::resetAddress(_tree, _name, "geniso");
  utils::resetAddress(_tree, _name, "mipEnergy");
  utils::resetAddress(_tree, _name, "e33");
  utils::resetAddress(_tree, _name, "e4");
  utils::resetAddress(_tree, _name, "eseed");
  utils::resetAddress(_tree, _name, "emax");
  utils::resetAddress(_tree, _name, "e2nd");
  utils::resetAddress(_tree, _name, "r9");
  utils::resetAddress(_tree, _name, "etaWidth");
  utils::resetAddress(_tree, _name, "phiWidth");
  utils::resetAddress(_tree, _name, "time");
  utils::resetAddress(_tree, _name, "timeSpan");
  utils::resetAddress(_tree, _name, "loose");
  utils::resetAddress(_tree, _name, "medium");
  utils::resetAddress(_tree, _name, "tight");
  utils::resetAddress(_tree, _name, "highpt");
  utils::resetAddress(_tree, _name, "pixelVeto");
  utils::resetAddress(_tree, _name, "csafeVeto");
  utils::resetAddress(_tree, _name, "triggerMatch");
  utils::resetAddress(_tree, _name, "superCluster_");
  utils::resetAddress(_tree, _name, "matchedGen_");
}

void
panda::Photon::datastore::resizeVectors_(UInt_t _size)
{
  ParticleP::datastore::resizeVectors_(_size);

}

panda::Photon::Photon(char const* _name/* = ""*/) :
  ParticleP(new PhotonArray(1, _name)),
  chiso(gStore.getData(this).chiso[0]),
  chisoWorst(gStore.getData(this).chisoWorst[0]),
  nhiso(gStore.getData(this).nhiso[0]),
  phoiso(gStore.getData(this).phoiso[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  geniso(gStore.getData(this).geniso[0]),
  mipEnergy(gStore.getData(this).mipEnergy[0]),
  e33(gStore.getData(this).e33[0]),
  e4(gStore.getData(this).e4[0]),
  eseed(gStore.getData(this).eseed[0]),
  emax(gStore.getData(this).emax[0]),
  e2nd(gStore.getData(this).e2nd[0]),
  r9(gStore.getData(this).r9[0]),
  etaWidth(gStore.getData(this).etaWidth[0]),
  phiWidth(gStore.getData(this).phiWidth[0]),
  time(gStore.getData(this).time[0]),
  timeSpan(gStore.getData(this).timeSpan[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  highpt(gStore.getData(this).highpt[0]),
  pixelVeto(gStore.getData(this).pixelVeto[0]),
  csafeVeto(gStore.getData(this).csafeVeto[0]),
  triggerMatch(gStore.getData(this).triggerMatch[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
}

panda::Photon::Photon(Photon const& _src) :
  ParticleP(new PhotonArray(1, gStore.getName(&_src))),
  chiso(gStore.getData(this).chiso[0]),
  chisoWorst(gStore.getData(this).chisoWorst[0]),
  nhiso(gStore.getData(this).nhiso[0]),
  phoiso(gStore.getData(this).phoiso[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  geniso(gStore.getData(this).geniso[0]),
  mipEnergy(gStore.getData(this).mipEnergy[0]),
  e33(gStore.getData(this).e33[0]),
  e4(gStore.getData(this).e4[0]),
  eseed(gStore.getData(this).eseed[0]),
  emax(gStore.getData(this).emax[0]),
  e2nd(gStore.getData(this).e2nd[0]),
  r9(gStore.getData(this).r9[0]),
  etaWidth(gStore.getData(this).etaWidth[0]),
  phiWidth(gStore.getData(this).phiWidth[0]),
  time(gStore.getData(this).time[0]),
  timeSpan(gStore.getData(this).timeSpan[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  highpt(gStore.getData(this).highpt[0]),
  pixelVeto(gStore.getData(this).pixelVeto[0]),
  csafeVeto(gStore.getData(this).csafeVeto[0]),
  triggerMatch(gStore.getData(this).triggerMatch[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
  ParticleP::operator=(_src);

  chiso = _src.chiso;
  chisoWorst = _src.chisoWorst;
  nhiso = _src.nhiso;
  phoiso = _src.phoiso;
  sieie = _src.sieie;
  sipip = _src.sipip;
  hOverE = _src.hOverE;
  geniso = _src.geniso;
  mipEnergy = _src.mipEnergy;
  e33 = _src.e33;
  e4 = _src.e4;
  eseed = _src.eseed;
  emax = _src.emax;
  e2nd = _src.e2nd;
  r9 = _src.r9;
  etaWidth = _src.etaWidth;
  phiWidth = _src.phiWidth;
  time = _src.time;
  timeSpan = _src.timeSpan;
  loose = _src.loose;
  medium = _src.medium;
  tight = _src.tight;
  highpt = _src.highpt;
  pixelVeto = _src.pixelVeto;
  csafeVeto = _src.csafeVeto;
  std::memcpy(triggerMatch, _src.triggerMatch, sizeof(Bool_t) * nPhotonTriggerObjects);
  superCluster = _src.superCluster;
  matchedGen = _src.matchedGen;
}

panda::Photon::Photon(datastore& _data, UInt_t _idx) :
  ParticleP(_data, _idx),
  chiso(_data.chiso[_idx]),
  chisoWorst(_data.chisoWorst[_idx]),
  nhiso(_data.nhiso[_idx]),
  phoiso(_data.phoiso[_idx]),
  sieie(_data.sieie[_idx]),
  sipip(_data.sipip[_idx]),
  hOverE(_data.hOverE[_idx]),
  geniso(_data.geniso[_idx]),
  mipEnergy(_data.mipEnergy[_idx]),
  e33(_data.e33[_idx]),
  e4(_data.e4[_idx]),
  eseed(_data.eseed[_idx]),
  emax(_data.emax[_idx]),
  e2nd(_data.e2nd[_idx]),
  r9(_data.r9[_idx]),
  etaWidth(_data.etaWidth[_idx]),
  phiWidth(_data.phiWidth[_idx]),
  time(_data.time[_idx]),
  timeSpan(_data.timeSpan[_idx]),
  loose(_data.loose[_idx]),
  medium(_data.medium[_idx]),
  tight(_data.tight[_idx]),
  highpt(_data.highpt[_idx]),
  pixelVeto(_data.pixelVeto[_idx]),
  csafeVeto(_data.csafeVeto[_idx]),
  triggerMatch(_data.triggerMatch[_idx]),
  superCluster(_data.superClusterContainer_, _data.superCluster_[_idx]),
  matchedGen(_data.matchedGenContainer_, _data.matchedGen_[_idx])
{
}

panda::Photon::Photon(ArrayBase* _array) :
  ParticleP(_array),
  chiso(gStore.getData(this).chiso[0]),
  chisoWorst(gStore.getData(this).chisoWorst[0]),
  nhiso(gStore.getData(this).nhiso[0]),
  phoiso(gStore.getData(this).phoiso[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  geniso(gStore.getData(this).geniso[0]),
  mipEnergy(gStore.getData(this).mipEnergy[0]),
  e33(gStore.getData(this).e33[0]),
  e4(gStore.getData(this).e4[0]),
  eseed(gStore.getData(this).eseed[0]),
  emax(gStore.getData(this).emax[0]),
  e2nd(gStore.getData(this).e2nd[0]),
  r9(gStore.getData(this).r9[0]),
  etaWidth(gStore.getData(this).etaWidth[0]),
  phiWidth(gStore.getData(this).phiWidth[0]),
  time(gStore.getData(this).time[0]),
  timeSpan(gStore.getData(this).timeSpan[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  highpt(gStore.getData(this).highpt[0]),
  pixelVeto(gStore.getData(this).pixelVeto[0]),
  csafeVeto(gStore.getData(this).csafeVeto[0]),
  triggerMatch(gStore.getData(this).triggerMatch[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0])
{
}

panda::Photon::~Photon()
{
  destructor();
  gStore.free(this);
}

void
panda::Photon::destructor()
{
  /* BEGIN CUSTOM Photon.cc.destructor */
  /* END CUSTOM */

  ParticleP::destructor();
}

panda::Photon&
panda::Photon::operator=(Photon const& _src)
{
  ParticleP::operator=(_src);

  chiso = _src.chiso;
  chisoWorst = _src.chisoWorst;
  nhiso = _src.nhiso;
  phoiso = _src.phoiso;
  sieie = _src.sieie;
  sipip = _src.sipip;
  hOverE = _src.hOverE;
  geniso = _src.geniso;
  mipEnergy = _src.mipEnergy;
  e33 = _src.e33;
  e4 = _src.e4;
  eseed = _src.eseed;
  emax = _src.emax;
  e2nd = _src.e2nd;
  r9 = _src.r9;
  etaWidth = _src.etaWidth;
  phiWidth = _src.phiWidth;
  time = _src.time;
  timeSpan = _src.timeSpan;
  loose = _src.loose;
  medium = _src.medium;
  tight = _src.tight;
  highpt = _src.highpt;
  pixelVeto = _src.pixelVeto;
  csafeVeto = _src.csafeVeto;
  std::memcpy(triggerMatch, _src.triggerMatch, sizeof(Bool_t) * nPhotonTriggerObjects);
  superCluster = _src.superCluster;
  matchedGen = _src.matchedGen;

  return *this;
}

void
panda::Photon::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleP::doSetAddress_(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "chiso", &chiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chisoWorst", &chisoWorst, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhiso", &nhiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phoiso", &phoiso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sieie", &sieie, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sipip", &sipip, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hOverE", &hOverE, _branches, _setStatus);
  utils::setAddress(_tree, _name, "geniso", &geniso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mipEnergy", &mipEnergy, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e33", &e33, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e4", &e4, _branches, _setStatus);
  utils::setAddress(_tree, _name, "eseed", &eseed, _branches, _setStatus);
  utils::setAddress(_tree, _name, "emax", &emax, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e2nd", &e2nd, _branches, _setStatus);
  utils::setAddress(_tree, _name, "r9", &r9, _branches, _setStatus);
  utils::setAddress(_tree, _name, "etaWidth", &etaWidth, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phiWidth", &phiWidth, _branches, _setStatus);
  utils::setAddress(_tree, _name, "time", &time, _branches, _setStatus);
  utils::setAddress(_tree, _name, "timeSpan", &timeSpan, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose", &loose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "medium", &medium, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight", &tight, _branches, _setStatus);
  utils::setAddress(_tree, _name, "highpt", &highpt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "pixelVeto", &pixelVeto, _branches, _setStatus);
  utils::setAddress(_tree, _name, "csafeVeto", &csafeVeto, _branches, _setStatus);
  utils::setAddress(_tree, _name, "triggerMatch", triggerMatch, _branches, _setStatus);
  utils::setAddress(_tree, _name, "superCluster_", gStore.getData(this).superCluster_, _branches, true);
  utils::setAddress(_tree, _name, "matchedGen_", gStore.getData(this).matchedGen_, _branches, true);
}

void
panda::Photon::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ParticleP::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "chiso", "", 'F', &chiso, _branches);
  utils::book(_tree, _name, "chisoWorst", "", 'F', &chisoWorst, _branches);
  utils::book(_tree, _name, "nhiso", "", 'F', &nhiso, _branches);
  utils::book(_tree, _name, "phoiso", "", 'F', &phoiso, _branches);
  utils::book(_tree, _name, "sieie", "", 'F', &sieie, _branches);
  utils::book(_tree, _name, "sipip", "", 'F', &sipip, _branches);
  utils::book(_tree, _name, "hOverE", "", 'F', &hOverE, _branches);
  utils::book(_tree, _name, "geniso", "", 'F', &geniso, _branches);
  utils::book(_tree, _name, "mipEnergy", "", 'F', &mipEnergy, _branches);
  utils::book(_tree, _name, "e33", "", 'F', &e33, _branches);
  utils::book(_tree, _name, "e4", "", 'F', &e4, _branches);
  utils::book(_tree, _name, "eseed", "", 'F', &eseed, _branches);
  utils::book(_tree, _name, "emax", "", 'F', &emax, _branches);
  utils::book(_tree, _name, "e2nd", "", 'F', &e2nd, _branches);
  utils::book(_tree, _name, "r9", "", 'F', &r9, _branches);
  utils::book(_tree, _name, "etaWidth", "", 'F', &etaWidth, _branches);
  utils::book(_tree, _name, "phiWidth", "", 'F', &phiWidth, _branches);
  utils::book(_tree, _name, "time", "", 'F', &time, _branches);
  utils::book(_tree, _name, "timeSpan", "", 'F', &timeSpan, _branches);
  utils::book(_tree, _name, "loose", "", 'O', &loose, _branches);
  utils::book(_tree, _name, "medium", "", 'O', &medium, _branches);
  utils::book(_tree, _name, "tight", "", 'O', &tight, _branches);
  utils::book(_tree, _name, "highpt", "", 'O', &highpt, _branches);
  utils::book(_tree, _name, "pixelVeto", "", 'O', &pixelVeto, _branches);
  utils::book(_tree, _name, "csafeVeto", "", 'O', &csafeVeto, _branches);
  utils::book(_tree, _name, "triggerMatch", TString::Format("[%d]", nPhotonTriggerObjects), 'O', triggerMatch, _branches);
  utils::book(_tree, _name, "superCluster_", "", 'I', gStore.getData(this).superCluster_, _branches);
  utils::book(_tree, _name, "matchedGen_", "", 'I', gStore.getData(this).matchedGen_, _branches);
}

void
panda::Photon::doReleaseTree_(TTree& _tree, TString const& _name)
{
  ParticleP::doReleaseTree_(_tree, _name);

  utils::resetAddress(_tree, _name, "chiso");
  utils::resetAddress(_tree, _name, "chisoWorst");
  utils::resetAddress(_tree, _name, "nhiso");
  utils::resetAddress(_tree, _name, "phoiso");
  utils::resetAddress(_tree, _name, "sieie");
  utils::resetAddress(_tree, _name, "sipip");
  utils::resetAddress(_tree, _name, "hOverE");
  utils::resetAddress(_tree, _name, "geniso");
  utils::resetAddress(_tree, _name, "mipEnergy");
  utils::resetAddress(_tree, _name, "e33");
  utils::resetAddress(_tree, _name, "e4");
  utils::resetAddress(_tree, _name, "eseed");
  utils::resetAddress(_tree, _name, "emax");
  utils::resetAddress(_tree, _name, "e2nd");
  utils::resetAddress(_tree, _name, "r9");
  utils::resetAddress(_tree, _name, "etaWidth");
  utils::resetAddress(_tree, _name, "phiWidth");
  utils::resetAddress(_tree, _name, "time");
  utils::resetAddress(_tree, _name, "timeSpan");
  utils::resetAddress(_tree, _name, "loose");
  utils::resetAddress(_tree, _name, "medium");
  utils::resetAddress(_tree, _name, "tight");
  utils::resetAddress(_tree, _name, "highpt");
  utils::resetAddress(_tree, _name, "pixelVeto");
  utils::resetAddress(_tree, _name, "csafeVeto");
  utils::resetAddress(_tree, _name, "triggerMatch");
  utils::resetAddress(_tree, _name, "superCluster_");
  utils::resetAddress(_tree, _name, "matchedGen_");
}

void
panda::Photon::doInit_()
{
  ParticleP::doInit_();

  chiso = 0.;
  chisoWorst = 0.;
  nhiso = 0.;
  phoiso = 0.;
  sieie = 0.;
  sipip = 0.;
  hOverE = 0.;
  geniso = 0.;
  mipEnergy = 0.;
  e33 = 0.;
  e4 = 0.;
  eseed = 0.;
  emax = 0.;
  e2nd = 0.;
  r9 = 0.;
  etaWidth = 0.;
  phiWidth = 0.;
  time = 0.;
  timeSpan = 0.;
  loose = false;
  medium = false;
  tight = false;
  highpt = false;
  pixelVeto = false;
  csafeVeto = false;
  for (auto& p0 : triggerMatch) p0 = false;
  superCluster.init();
  matchedGen.init();

  /* BEGIN CUSTOM Photon.cc.doInit_ */
  /* END CUSTOM */
}

/* BEGIN CUSTOM Photon.cc.global */
/* END CUSTOM */
