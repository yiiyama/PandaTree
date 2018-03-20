#include "../interface/Electron.h"

TString panda::Electron::TriggerObjectName[] = {
  "fEl23El12FirstLeg",
  "fEl23El12SecondLeg",
  "fEl25Tight",
  "fEl27Loose",
  "fEl27Tight",
  "fEl35Tight",
  "fPh165HE10",
  "fPh175",
  "fPh200",
  "fPh36EBR9Iso"
};

/*static*/
panda::utils::BranchList
panda::Electron::getListOfBranches()
{
  utils::BranchList blist;
  blist += Lepton::getListOfBranches();
  blist += {"chIsoPh", "nhIsoPh", "phIsoPh", "ecalIso", "hcalIso", "trackIso", "isoPUOffset", "sieie", "sipip", "r9", "dEtaInSeed", "dPhiIn", "eseed", "hOverE", "ecalE", "trackP", "regPt", "smearedPt", "mvaVal", "nMissingHits", "veto", "hltsafe", "mvaWP90", "mvaWP80", "mvaWPLoose", "mvaIsoWP90", "mvaIsoWP80", "mvaIsoWPLoose", "conversionVeto", "tripleCharge", "triggerMatch", "superCluster_"};
  return blist;
}

void
panda::Electron::datastore::allocate(UInt_t _nmax)
{
  Lepton::datastore::allocate(_nmax);

  chIsoPh = new Float_t[nmax_];
  nhIsoPh = new Float_t[nmax_];
  phIsoPh = new Float_t[nmax_];
  ecalIso = new Float_t[nmax_];
  hcalIso = new Float_t[nmax_];
  trackIso = new Float_t[nmax_];
  isoPUOffset = new Float_t[nmax_];
  sieie = new Float_t[nmax_];
  sipip = new Float_t[nmax_];
  r9 = new Float_t[nmax_];
  dEtaInSeed = new Float_t[nmax_];
  dPhiIn = new Float_t[nmax_];
  eseed = new Float_t[nmax_];
  hOverE = new Float_t[nmax_];
  ecalE = new Float_t[nmax_];
  trackP = new Float_t[nmax_];
  regPt = new Float_t[nmax_];
  smearedPt = new Float_t[nmax_];
  mvaVal = new Float_t[nmax_];
  nMissingHits = new UShort_t[nmax_];
  veto = new Bool_t[nmax_];
  hltsafe = new Bool_t[nmax_];
  mvaWP90 = new Bool_t[nmax_];
  mvaWP80 = new Bool_t[nmax_];
  mvaWPLoose = new Bool_t[nmax_];
  mvaIsoWP90 = new Bool_t[nmax_];
  mvaIsoWP80 = new Bool_t[nmax_];
  mvaIsoWPLoose = new Bool_t[nmax_];
  conversionVeto = new Bool_t[nmax_];
  tripleCharge = new Bool_t[nmax_];
  triggerMatch = new Bool_t[nmax_][nTriggerObjects];
  superCluster_ = new Short_t[nmax_];
}

void
panda::Electron::datastore::deallocate()
{
  Lepton::datastore::deallocate();

  delete [] chIsoPh;
  chIsoPh = 0;
  delete [] nhIsoPh;
  nhIsoPh = 0;
  delete [] phIsoPh;
  phIsoPh = 0;
  delete [] ecalIso;
  ecalIso = 0;
  delete [] hcalIso;
  hcalIso = 0;
  delete [] trackIso;
  trackIso = 0;
  delete [] isoPUOffset;
  isoPUOffset = 0;
  delete [] sieie;
  sieie = 0;
  delete [] sipip;
  sipip = 0;
  delete [] r9;
  r9 = 0;
  delete [] dEtaInSeed;
  dEtaInSeed = 0;
  delete [] dPhiIn;
  dPhiIn = 0;
  delete [] eseed;
  eseed = 0;
  delete [] hOverE;
  hOverE = 0;
  delete [] ecalE;
  ecalE = 0;
  delete [] trackP;
  trackP = 0;
  delete [] regPt;
  regPt = 0;
  delete [] smearedPt;
  smearedPt = 0;
  delete [] mvaVal;
  mvaVal = 0;
  delete [] nMissingHits;
  nMissingHits = 0;
  delete [] veto;
  veto = 0;
  delete [] hltsafe;
  hltsafe = 0;
  delete [] mvaWP90;
  mvaWP90 = 0;
  delete [] mvaWP80;
  mvaWP80 = 0;
  delete [] mvaWPLoose;
  mvaWPLoose = 0;
  delete [] mvaIsoWP90;
  mvaIsoWP90 = 0;
  delete [] mvaIsoWP80;
  mvaIsoWP80 = 0;
  delete [] mvaIsoWPLoose;
  mvaIsoWPLoose = 0;
  delete [] conversionVeto;
  conversionVeto = 0;
  delete [] tripleCharge;
  tripleCharge = 0;
  delete [] triggerMatch;
  triggerMatch = 0;
  delete [] superCluster_;
  superCluster_ = 0;
}

void
panda::Electron::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Lepton::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "chIsoPh", _branches);
  utils::setStatus(_tree, _name, "nhIsoPh", _branches);
  utils::setStatus(_tree, _name, "phIsoPh", _branches);
  utils::setStatus(_tree, _name, "ecalIso", _branches);
  utils::setStatus(_tree, _name, "hcalIso", _branches);
  utils::setStatus(_tree, _name, "trackIso", _branches);
  utils::setStatus(_tree, _name, "isoPUOffset", _branches);
  utils::setStatus(_tree, _name, "sieie", _branches);
  utils::setStatus(_tree, _name, "sipip", _branches);
  utils::setStatus(_tree, _name, "r9", _branches);
  utils::setStatus(_tree, _name, "dEtaInSeed", _branches);
  utils::setStatus(_tree, _name, "dPhiIn", _branches);
  utils::setStatus(_tree, _name, "eseed", _branches);
  utils::setStatus(_tree, _name, "hOverE", _branches);
  utils::setStatus(_tree, _name, "ecalE", _branches);
  utils::setStatus(_tree, _name, "trackP", _branches);
  utils::setStatus(_tree, _name, "regPt", _branches);
  utils::setStatus(_tree, _name, "smearedPt", _branches);
  utils::setStatus(_tree, _name, "mvaVal", _branches);
  utils::setStatus(_tree, _name, "nMissingHits", _branches);
  utils::setStatus(_tree, _name, "veto", _branches);
  utils::setStatus(_tree, _name, "hltsafe", _branches);
  utils::setStatus(_tree, _name, "mvaWP90", _branches);
  utils::setStatus(_tree, _name, "mvaWP80", _branches);
  utils::setStatus(_tree, _name, "mvaWPLoose", _branches);
  utils::setStatus(_tree, _name, "mvaIsoWP90", _branches);
  utils::setStatus(_tree, _name, "mvaIsoWP80", _branches);
  utils::setStatus(_tree, _name, "mvaIsoWPLoose", _branches);
  utils::setStatus(_tree, _name, "conversionVeto", _branches);
  utils::setStatus(_tree, _name, "tripleCharge", _branches);
  utils::setStatus(_tree, _name, "triggerMatch", _branches);
  utils::setStatus(_tree, _name, "superCluster_", _branches);
}

panda::utils::BranchList
panda::Electron::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Lepton::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "chIsoPh"));
  blist.push_back(utils::getStatus(_tree, _name, "nhIsoPh"));
  blist.push_back(utils::getStatus(_tree, _name, "phIsoPh"));
  blist.push_back(utils::getStatus(_tree, _name, "ecalIso"));
  blist.push_back(utils::getStatus(_tree, _name, "hcalIso"));
  blist.push_back(utils::getStatus(_tree, _name, "trackIso"));
  blist.push_back(utils::getStatus(_tree, _name, "isoPUOffset"));
  blist.push_back(utils::getStatus(_tree, _name, "sieie"));
  blist.push_back(utils::getStatus(_tree, _name, "sipip"));
  blist.push_back(utils::getStatus(_tree, _name, "r9"));
  blist.push_back(utils::getStatus(_tree, _name, "dEtaInSeed"));
  blist.push_back(utils::getStatus(_tree, _name, "dPhiIn"));
  blist.push_back(utils::getStatus(_tree, _name, "eseed"));
  blist.push_back(utils::getStatus(_tree, _name, "hOverE"));
  blist.push_back(utils::getStatus(_tree, _name, "ecalE"));
  blist.push_back(utils::getStatus(_tree, _name, "trackP"));
  blist.push_back(utils::getStatus(_tree, _name, "regPt"));
  blist.push_back(utils::getStatus(_tree, _name, "smearedPt"));
  blist.push_back(utils::getStatus(_tree, _name, "mvaVal"));
  blist.push_back(utils::getStatus(_tree, _name, "nMissingHits"));
  blist.push_back(utils::getStatus(_tree, _name, "veto"));
  blist.push_back(utils::getStatus(_tree, _name, "hltsafe"));
  blist.push_back(utils::getStatus(_tree, _name, "mvaWP90"));
  blist.push_back(utils::getStatus(_tree, _name, "mvaWP80"));
  blist.push_back(utils::getStatus(_tree, _name, "mvaWPLoose"));
  blist.push_back(utils::getStatus(_tree, _name, "mvaIsoWP90"));
  blist.push_back(utils::getStatus(_tree, _name, "mvaIsoWP80"));
  blist.push_back(utils::getStatus(_tree, _name, "mvaIsoWPLoose"));
  blist.push_back(utils::getStatus(_tree, _name, "conversionVeto"));
  blist.push_back(utils::getStatus(_tree, _name, "tripleCharge"));
  blist.push_back(utils::getStatus(_tree, _name, "triggerMatch"));
  blist.push_back(utils::getStatus(_tree, _name, "superCluster_"));

  return blist;
}

void
panda::Electron::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Lepton::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "chIsoPh", chIsoPh, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhIsoPh", nhIsoPh, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phIsoPh", phIsoPh, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ecalIso", ecalIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hcalIso", hcalIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "trackIso", trackIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "isoPUOffset", isoPUOffset, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sieie", sieie, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sipip", sipip, _branches, _setStatus);
  utils::setAddress(_tree, _name, "r9", r9, _branches, _setStatus);
  utils::setAddress(_tree, _name, "dEtaInSeed", dEtaInSeed, _branches, _setStatus);
  utils::setAddress(_tree, _name, "dPhiIn", dPhiIn, _branches, _setStatus);
  utils::setAddress(_tree, _name, "eseed", eseed, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hOverE", hOverE, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ecalE", ecalE, _branches, _setStatus);
  utils::setAddress(_tree, _name, "trackP", trackP, _branches, _setStatus);
  utils::setAddress(_tree, _name, "regPt", regPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "smearedPt", smearedPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mvaVal", mvaVal, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nMissingHits", nMissingHits, _branches, _setStatus);
  utils::setAddress(_tree, _name, "veto", veto, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hltsafe", hltsafe, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mvaWP90", mvaWP90, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mvaWP80", mvaWP80, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mvaWPLoose", mvaWPLoose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mvaIsoWP90", mvaIsoWP90, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mvaIsoWP80", mvaIsoWP80, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mvaIsoWPLoose", mvaIsoWPLoose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "conversionVeto", conversionVeto, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tripleCharge", tripleCharge, _branches, _setStatus);
  utils::setAddress(_tree, _name, "triggerMatch", triggerMatch, _branches, _setStatus);
  utils::setAddress(_tree, _name, "superCluster_", superCluster_, _branches, _setStatus);
}

void
panda::Electron::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Lepton::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "chIsoPh", size, 'F', chIsoPh, _branches);
  utils::book(_tree, _name, "nhIsoPh", size, 'F', nhIsoPh, _branches);
  utils::book(_tree, _name, "phIsoPh", size, 'F', phIsoPh, _branches);
  utils::book(_tree, _name, "ecalIso", size, 'F', ecalIso, _branches);
  utils::book(_tree, _name, "hcalIso", size, 'F', hcalIso, _branches);
  utils::book(_tree, _name, "trackIso", size, 'F', trackIso, _branches);
  utils::book(_tree, _name, "isoPUOffset", size, 'F', isoPUOffset, _branches);
  utils::book(_tree, _name, "sieie", size, 'F', sieie, _branches);
  utils::book(_tree, _name, "sipip", size, 'F', sipip, _branches);
  utils::book(_tree, _name, "r9", size, 'F', r9, _branches);
  utils::book(_tree, _name, "dEtaInSeed", size, 'F', dEtaInSeed, _branches);
  utils::book(_tree, _name, "dPhiIn", size, 'F', dPhiIn, _branches);
  utils::book(_tree, _name, "eseed", size, 'F', eseed, _branches);
  utils::book(_tree, _name, "hOverE", size, 'F', hOverE, _branches);
  utils::book(_tree, _name, "ecalE", size, 'F', ecalE, _branches);
  utils::book(_tree, _name, "trackP", size, 'F', trackP, _branches);
  utils::book(_tree, _name, "regPt", size, 'F', regPt, _branches);
  utils::book(_tree, _name, "smearedPt", size, 'F', smearedPt, _branches);
  utils::book(_tree, _name, "mvaVal", size, 'F', mvaVal, _branches);
  utils::book(_tree, _name, "nMissingHits", size, 's', nMissingHits, _branches);
  utils::book(_tree, _name, "veto", size, 'O', veto, _branches);
  utils::book(_tree, _name, "hltsafe", size, 'O', hltsafe, _branches);
  utils::book(_tree, _name, "mvaWP90", size, 'O', mvaWP90, _branches);
  utils::book(_tree, _name, "mvaWP80", size, 'O', mvaWP80, _branches);
  utils::book(_tree, _name, "mvaWPLoose", size, 'O', mvaWPLoose, _branches);
  utils::book(_tree, _name, "mvaIsoWP90", size, 'O', mvaIsoWP90, _branches);
  utils::book(_tree, _name, "mvaIsoWP80", size, 'O', mvaIsoWP80, _branches);
  utils::book(_tree, _name, "mvaIsoWPLoose", size, 'O', mvaIsoWPLoose, _branches);
  utils::book(_tree, _name, "conversionVeto", size, 'O', conversionVeto, _branches);
  utils::book(_tree, _name, "tripleCharge", size, 'O', tripleCharge, _branches);
  utils::book(_tree, _name, "triggerMatch", size + TString::Format("[%d]", nTriggerObjects), 'O', triggerMatch, _branches);
  utils::book(_tree, _name, "superCluster_", size, 'S', superCluster_, _branches);
}

void
panda::Electron::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Lepton::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "chIsoPh");
  utils::resetAddress(_tree, _name, "nhIsoPh");
  utils::resetAddress(_tree, _name, "phIsoPh");
  utils::resetAddress(_tree, _name, "ecalIso");
  utils::resetAddress(_tree, _name, "hcalIso");
  utils::resetAddress(_tree, _name, "trackIso");
  utils::resetAddress(_tree, _name, "isoPUOffset");
  utils::resetAddress(_tree, _name, "sieie");
  utils::resetAddress(_tree, _name, "sipip");
  utils::resetAddress(_tree, _name, "r9");
  utils::resetAddress(_tree, _name, "dEtaInSeed");
  utils::resetAddress(_tree, _name, "dPhiIn");
  utils::resetAddress(_tree, _name, "eseed");
  utils::resetAddress(_tree, _name, "hOverE");
  utils::resetAddress(_tree, _name, "ecalE");
  utils::resetAddress(_tree, _name, "trackP");
  utils::resetAddress(_tree, _name, "regPt");
  utils::resetAddress(_tree, _name, "smearedPt");
  utils::resetAddress(_tree, _name, "mvaVal");
  utils::resetAddress(_tree, _name, "nMissingHits");
  utils::resetAddress(_tree, _name, "veto");
  utils::resetAddress(_tree, _name, "hltsafe");
  utils::resetAddress(_tree, _name, "mvaWP90");
  utils::resetAddress(_tree, _name, "mvaWP80");
  utils::resetAddress(_tree, _name, "mvaWPLoose");
  utils::resetAddress(_tree, _name, "mvaIsoWP90");
  utils::resetAddress(_tree, _name, "mvaIsoWP80");
  utils::resetAddress(_tree, _name, "mvaIsoWPLoose");
  utils::resetAddress(_tree, _name, "conversionVeto");
  utils::resetAddress(_tree, _name, "tripleCharge");
  utils::resetAddress(_tree, _name, "triggerMatch");
  utils::resetAddress(_tree, _name, "superCluster_");
}

void
panda::Electron::datastore::resizeVectors_(UInt_t _size)
{
  Lepton::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::Electron::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return Electron::getListOfBranches().fullNames(_name);
}

panda::Electron::Electron(char const* _name/* = ""*/) :
  Lepton(new ElectronArray(1, _name)),
  chIsoPh(gStore.getData(this).chIsoPh[0]),
  nhIsoPh(gStore.getData(this).nhIsoPh[0]),
  phIsoPh(gStore.getData(this).phIsoPh[0]),
  ecalIso(gStore.getData(this).ecalIso[0]),
  hcalIso(gStore.getData(this).hcalIso[0]),
  trackIso(gStore.getData(this).trackIso[0]),
  isoPUOffset(gStore.getData(this).isoPUOffset[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  r9(gStore.getData(this).r9[0]),
  dEtaInSeed(gStore.getData(this).dEtaInSeed[0]),
  dPhiIn(gStore.getData(this).dPhiIn[0]),
  eseed(gStore.getData(this).eseed[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  ecalE(gStore.getData(this).ecalE[0]),
  trackP(gStore.getData(this).trackP[0]),
  regPt(gStore.getData(this).regPt[0]),
  smearedPt(gStore.getData(this).smearedPt[0]),
  mvaVal(gStore.getData(this).mvaVal[0]),
  nMissingHits(gStore.getData(this).nMissingHits[0]),
  veto(gStore.getData(this).veto[0]),
  hltsafe(gStore.getData(this).hltsafe[0]),
  mvaWP90(gStore.getData(this).mvaWP90[0]),
  mvaWP80(gStore.getData(this).mvaWP80[0]),
  mvaWPLoose(gStore.getData(this).mvaWPLoose[0]),
  mvaIsoWP90(gStore.getData(this).mvaIsoWP90[0]),
  mvaIsoWP80(gStore.getData(this).mvaIsoWP80[0]),
  mvaIsoWPLoose(gStore.getData(this).mvaIsoWPLoose[0]),
  conversionVeto(gStore.getData(this).conversionVeto[0]),
  tripleCharge(gStore.getData(this).tripleCharge[0]),
  triggerMatch(gStore.getData(this).triggerMatch[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0])
{
}

panda::Electron::Electron(Electron const& _src) :
  Lepton(new ElectronArray(1, _src.getName())),
  chIsoPh(gStore.getData(this).chIsoPh[0]),
  nhIsoPh(gStore.getData(this).nhIsoPh[0]),
  phIsoPh(gStore.getData(this).phIsoPh[0]),
  ecalIso(gStore.getData(this).ecalIso[0]),
  hcalIso(gStore.getData(this).hcalIso[0]),
  trackIso(gStore.getData(this).trackIso[0]),
  isoPUOffset(gStore.getData(this).isoPUOffset[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  r9(gStore.getData(this).r9[0]),
  dEtaInSeed(gStore.getData(this).dEtaInSeed[0]),
  dPhiIn(gStore.getData(this).dPhiIn[0]),
  eseed(gStore.getData(this).eseed[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  ecalE(gStore.getData(this).ecalE[0]),
  trackP(gStore.getData(this).trackP[0]),
  regPt(gStore.getData(this).regPt[0]),
  smearedPt(gStore.getData(this).smearedPt[0]),
  mvaVal(gStore.getData(this).mvaVal[0]),
  nMissingHits(gStore.getData(this).nMissingHits[0]),
  veto(gStore.getData(this).veto[0]),
  hltsafe(gStore.getData(this).hltsafe[0]),
  mvaWP90(gStore.getData(this).mvaWP90[0]),
  mvaWP80(gStore.getData(this).mvaWP80[0]),
  mvaWPLoose(gStore.getData(this).mvaWPLoose[0]),
  mvaIsoWP90(gStore.getData(this).mvaIsoWP90[0]),
  mvaIsoWP80(gStore.getData(this).mvaIsoWP80[0]),
  mvaIsoWPLoose(gStore.getData(this).mvaIsoWPLoose[0]),
  conversionVeto(gStore.getData(this).conversionVeto[0]),
  tripleCharge(gStore.getData(this).tripleCharge[0]),
  triggerMatch(gStore.getData(this).triggerMatch[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0])
{
  Lepton::operator=(_src);

  chIsoPh = _src.chIsoPh;
  nhIsoPh = _src.nhIsoPh;
  phIsoPh = _src.phIsoPh;
  ecalIso = _src.ecalIso;
  hcalIso = _src.hcalIso;
  trackIso = _src.trackIso;
  isoPUOffset = _src.isoPUOffset;
  sieie = _src.sieie;
  sipip = _src.sipip;
  r9 = _src.r9;
  dEtaInSeed = _src.dEtaInSeed;
  dPhiIn = _src.dPhiIn;
  eseed = _src.eseed;
  hOverE = _src.hOverE;
  ecalE = _src.ecalE;
  trackP = _src.trackP;
  regPt = _src.regPt;
  smearedPt = _src.smearedPt;
  mvaVal = _src.mvaVal;
  nMissingHits = _src.nMissingHits;
  veto = _src.veto;
  hltsafe = _src.hltsafe;
  mvaWP90 = _src.mvaWP90;
  mvaWP80 = _src.mvaWP80;
  mvaWPLoose = _src.mvaWPLoose;
  mvaIsoWP90 = _src.mvaIsoWP90;
  mvaIsoWP80 = _src.mvaIsoWP80;
  mvaIsoWPLoose = _src.mvaIsoWPLoose;
  conversionVeto = _src.conversionVeto;
  tripleCharge = _src.tripleCharge;
  std::memcpy(triggerMatch, _src.triggerMatch, sizeof(Bool_t) * nTriggerObjects);
  superCluster = _src.superCluster;
}

panda::Electron::Electron(datastore& _data, UInt_t _idx) :
  Lepton(_data, _idx),
  chIsoPh(_data.chIsoPh[_idx]),
  nhIsoPh(_data.nhIsoPh[_idx]),
  phIsoPh(_data.phIsoPh[_idx]),
  ecalIso(_data.ecalIso[_idx]),
  hcalIso(_data.hcalIso[_idx]),
  trackIso(_data.trackIso[_idx]),
  isoPUOffset(_data.isoPUOffset[_idx]),
  sieie(_data.sieie[_idx]),
  sipip(_data.sipip[_idx]),
  r9(_data.r9[_idx]),
  dEtaInSeed(_data.dEtaInSeed[_idx]),
  dPhiIn(_data.dPhiIn[_idx]),
  eseed(_data.eseed[_idx]),
  hOverE(_data.hOverE[_idx]),
  ecalE(_data.ecalE[_idx]),
  trackP(_data.trackP[_idx]),
  regPt(_data.regPt[_idx]),
  smearedPt(_data.smearedPt[_idx]),
  mvaVal(_data.mvaVal[_idx]),
  nMissingHits(_data.nMissingHits[_idx]),
  veto(_data.veto[_idx]),
  hltsafe(_data.hltsafe[_idx]),
  mvaWP90(_data.mvaWP90[_idx]),
  mvaWP80(_data.mvaWP80[_idx]),
  mvaWPLoose(_data.mvaWPLoose[_idx]),
  mvaIsoWP90(_data.mvaIsoWP90[_idx]),
  mvaIsoWP80(_data.mvaIsoWP80[_idx]),
  mvaIsoWPLoose(_data.mvaIsoWPLoose[_idx]),
  conversionVeto(_data.conversionVeto[_idx]),
  tripleCharge(_data.tripleCharge[_idx]),
  triggerMatch(_data.triggerMatch[_idx]),
  superCluster(_data.superClusterContainer_, _data.superCluster_[_idx])
{
}

panda::Electron::Electron(ArrayBase* _array) :
  Lepton(_array),
  chIsoPh(gStore.getData(this).chIsoPh[0]),
  nhIsoPh(gStore.getData(this).nhIsoPh[0]),
  phIsoPh(gStore.getData(this).phIsoPh[0]),
  ecalIso(gStore.getData(this).ecalIso[0]),
  hcalIso(gStore.getData(this).hcalIso[0]),
  trackIso(gStore.getData(this).trackIso[0]),
  isoPUOffset(gStore.getData(this).isoPUOffset[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  r9(gStore.getData(this).r9[0]),
  dEtaInSeed(gStore.getData(this).dEtaInSeed[0]),
  dPhiIn(gStore.getData(this).dPhiIn[0]),
  eseed(gStore.getData(this).eseed[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  ecalE(gStore.getData(this).ecalE[0]),
  trackP(gStore.getData(this).trackP[0]),
  regPt(gStore.getData(this).regPt[0]),
  smearedPt(gStore.getData(this).smearedPt[0]),
  mvaVal(gStore.getData(this).mvaVal[0]),
  nMissingHits(gStore.getData(this).nMissingHits[0]),
  veto(gStore.getData(this).veto[0]),
  hltsafe(gStore.getData(this).hltsafe[0]),
  mvaWP90(gStore.getData(this).mvaWP90[0]),
  mvaWP80(gStore.getData(this).mvaWP80[0]),
  mvaWPLoose(gStore.getData(this).mvaWPLoose[0]),
  mvaIsoWP90(gStore.getData(this).mvaIsoWP90[0]),
  mvaIsoWP80(gStore.getData(this).mvaIsoWP80[0]),
  mvaIsoWPLoose(gStore.getData(this).mvaIsoWPLoose[0]),
  conversionVeto(gStore.getData(this).conversionVeto[0]),
  tripleCharge(gStore.getData(this).tripleCharge[0]),
  triggerMatch(gStore.getData(this).triggerMatch[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0])
{
}

panda::Electron::~Electron()
{
  destructor();
}

void
panda::Electron::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM Electron.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    Lepton::destructor(kTRUE);
}

panda::Electron&
panda::Electron::operator=(Electron const& _src)
{
  Lepton::operator=(_src);

  chIsoPh = _src.chIsoPh;
  nhIsoPh = _src.nhIsoPh;
  phIsoPh = _src.phIsoPh;
  ecalIso = _src.ecalIso;
  hcalIso = _src.hcalIso;
  trackIso = _src.trackIso;
  isoPUOffset = _src.isoPUOffset;
  sieie = _src.sieie;
  sipip = _src.sipip;
  r9 = _src.r9;
  dEtaInSeed = _src.dEtaInSeed;
  dPhiIn = _src.dPhiIn;
  eseed = _src.eseed;
  hOverE = _src.hOverE;
  ecalE = _src.ecalE;
  trackP = _src.trackP;
  regPt = _src.regPt;
  smearedPt = _src.smearedPt;
  mvaVal = _src.mvaVal;
  nMissingHits = _src.nMissingHits;
  veto = _src.veto;
  hltsafe = _src.hltsafe;
  mvaWP90 = _src.mvaWP90;
  mvaWP80 = _src.mvaWP80;
  mvaWPLoose = _src.mvaWPLoose;
  mvaIsoWP90 = _src.mvaIsoWP90;
  mvaIsoWP80 = _src.mvaIsoWP80;
  mvaIsoWPLoose = _src.mvaIsoWPLoose;
  conversionVeto = _src.conversionVeto;
  tripleCharge = _src.tripleCharge;
  std::memcpy(triggerMatch, _src.triggerMatch, sizeof(Bool_t) * nTriggerObjects);
  superCluster = _src.superCluster;

  /* BEGIN CUSTOM Electron.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
panda::Electron::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  Lepton::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "chIsoPh", "", 'F', &chIsoPh, _branches);
  utils::book(_tree, _name, "nhIsoPh", "", 'F', &nhIsoPh, _branches);
  utils::book(_tree, _name, "phIsoPh", "", 'F', &phIsoPh, _branches);
  utils::book(_tree, _name, "ecalIso", "", 'F', &ecalIso, _branches);
  utils::book(_tree, _name, "hcalIso", "", 'F', &hcalIso, _branches);
  utils::book(_tree, _name, "trackIso", "", 'F', &trackIso, _branches);
  utils::book(_tree, _name, "isoPUOffset", "", 'F', &isoPUOffset, _branches);
  utils::book(_tree, _name, "sieie", "", 'F', &sieie, _branches);
  utils::book(_tree, _name, "sipip", "", 'F', &sipip, _branches);
  utils::book(_tree, _name, "r9", "", 'F', &r9, _branches);
  utils::book(_tree, _name, "dEtaInSeed", "", 'F', &dEtaInSeed, _branches);
  utils::book(_tree, _name, "dPhiIn", "", 'F', &dPhiIn, _branches);
  utils::book(_tree, _name, "eseed", "", 'F', &eseed, _branches);
  utils::book(_tree, _name, "hOverE", "", 'F', &hOverE, _branches);
  utils::book(_tree, _name, "ecalE", "", 'F', &ecalE, _branches);
  utils::book(_tree, _name, "trackP", "", 'F', &trackP, _branches);
  utils::book(_tree, _name, "regPt", "", 'F', &regPt, _branches);
  utils::book(_tree, _name, "smearedPt", "", 'F', &smearedPt, _branches);
  utils::book(_tree, _name, "mvaVal", "", 'F', &mvaVal, _branches);
  utils::book(_tree, _name, "nMissingHits", "", 's', &nMissingHits, _branches);
  utils::book(_tree, _name, "veto", "", 'O', &veto, _branches);
  utils::book(_tree, _name, "hltsafe", "", 'O', &hltsafe, _branches);
  utils::book(_tree, _name, "mvaWP90", "", 'O', &mvaWP90, _branches);
  utils::book(_tree, _name, "mvaWP80", "", 'O', &mvaWP80, _branches);
  utils::book(_tree, _name, "mvaWPLoose", "", 'O', &mvaWPLoose, _branches);
  utils::book(_tree, _name, "mvaIsoWP90", "", 'O', &mvaIsoWP90, _branches);
  utils::book(_tree, _name, "mvaIsoWP80", "", 'O', &mvaIsoWP80, _branches);
  utils::book(_tree, _name, "mvaIsoWPLoose", "", 'O', &mvaIsoWPLoose, _branches);
  utils::book(_tree, _name, "conversionVeto", "", 'O', &conversionVeto, _branches);
  utils::book(_tree, _name, "tripleCharge", "", 'O', &tripleCharge, _branches);
  utils::book(_tree, _name, "triggerMatch", TString::Format("[%d]", nTriggerObjects), 'O', triggerMatch, _branches);
  utils::book(_tree, _name, "superCluster_", "", 'S', gStore.getData(this).superCluster_, _branches);
}

void
panda::Electron::doInit_()
{
  Lepton::doInit_();

  chIsoPh = 0.;
  nhIsoPh = 0.;
  phIsoPh = 0.;
  ecalIso = 0.;
  hcalIso = 0.;
  trackIso = 0.;
  isoPUOffset = 0.;
  sieie = 0.;
  sipip = 0.;
  r9 = 0.;
  dEtaInSeed = 0.;
  dPhiIn = 0.;
  eseed = 0.;
  hOverE = 0.;
  ecalE = 0.;
  trackP = 0.;
  regPt = 0.;
  smearedPt = 0.;
  mvaVal = 0.;
  nMissingHits = 0;
  veto = false;
  hltsafe = false;
  mvaWP90 = false;
  mvaWP80 = false;
  mvaWPLoose = false;
  mvaIsoWP90 = false;
  mvaIsoWP80 = false;
  mvaIsoWPLoose = false;
  conversionVeto = false;
  tripleCharge = false;
  for (auto& p0 : triggerMatch) p0 = false;
  superCluster.init();

  /* BEGIN CUSTOM Electron.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::Electron::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM Electron.cc.print */
  if (_level >= 3) {
    Electron::dump(_out);
    
    _out << "combIso = " << combIso() << std::endl;
    _out << "combRelIso = " << combIso() / pt() << std::endl;
  }
  else if (_level == 2) {
    Lepton::print(_out, _level);
    
    _out << "smearedPt = " << smearedPt << std::endl;
    _out << "regPt = " << regPt << std::endl;
    _out << "hltsafe = " << hltsafe << std::endl;
    _out << "veto = " << veto << std::endl;

    _out << "combIso = " << combIso() << std::endl;
    _out << "combRelIso = " << combIso() / pt() << std::endl;
  }
  else
    return;
  /* END CUSTOM */
}

void
panda::Electron::dump(std::ostream& _out/* = std::cout*/) const
{
  Lepton::dump(_out);

  _out << "chIsoPh = " << chIsoPh << std::endl;
  _out << "nhIsoPh = " << nhIsoPh << std::endl;
  _out << "phIsoPh = " << phIsoPh << std::endl;
  _out << "ecalIso = " << ecalIso << std::endl;
  _out << "hcalIso = " << hcalIso << std::endl;
  _out << "trackIso = " << trackIso << std::endl;
  _out << "isoPUOffset = " << isoPUOffset << std::endl;
  _out << "sieie = " << sieie << std::endl;
  _out << "sipip = " << sipip << std::endl;
  _out << "r9 = " << r9 << std::endl;
  _out << "dEtaInSeed = " << dEtaInSeed << std::endl;
  _out << "dPhiIn = " << dPhiIn << std::endl;
  _out << "eseed = " << eseed << std::endl;
  _out << "hOverE = " << hOverE << std::endl;
  _out << "ecalE = " << ecalE << std::endl;
  _out << "trackP = " << trackP << std::endl;
  _out << "regPt = " << regPt << std::endl;
  _out << "smearedPt = " << smearedPt << std::endl;
  _out << "mvaVal = " << mvaVal << std::endl;
  _out << "nMissingHits = " << nMissingHits << std::endl;
  _out << "veto = " << veto << std::endl;
  _out << "hltsafe = " << hltsafe << std::endl;
  _out << "mvaWP90 = " << mvaWP90 << std::endl;
  _out << "mvaWP80 = " << mvaWP80 << std::endl;
  _out << "mvaWPLoose = " << mvaWPLoose << std::endl;
  _out << "mvaIsoWP90 = " << mvaIsoWP90 << std::endl;
  _out << "mvaIsoWP80 = " << mvaIsoWP80 << std::endl;
  _out << "mvaIsoWPLoose = " << mvaIsoWPLoose << std::endl;
  _out << "conversionVeto = " << conversionVeto << std::endl;
  _out << "tripleCharge = " << tripleCharge << std::endl;
  _out << "triggerMatch = " << triggerMatch << std::endl;
  _out << "superCluster = " << superCluster << std::endl;
}


/* BEGIN CUSTOM Electron.cc.global */
/* END CUSTOM */
