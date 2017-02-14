#include "../interface/Electron.h"

/*static*/
panda::utils::BranchList
panda::Electron::getListOfBranches()
{
  utils::BranchList blist;
  blist += Lepton::getListOfBranches();
  blist += {"hltsafe", "chisoPh", "nhisoPh", "phisoPh", "ecaliso", "hcaliso", "isoPUOffset", "sieie", "sipip", "eseed", "hOverE", "rawPt", "regPt", "veto", "triggerMatch", "superCluster_"};
  return blist;
}

void
panda::Electron::datastore::allocate(UInt_t _nmax)
{
  Lepton::datastore::allocate(_nmax);

  hltsafe = new Bool_t[nmax_];
  chisoPh = new Float_t[nmax_];
  nhisoPh = new Float_t[nmax_];
  phisoPh = new Float_t[nmax_];
  ecaliso = new Float_t[nmax_];
  hcaliso = new Float_t[nmax_];
  isoPUOffset = new Float_t[nmax_];
  sieie = new Float_t[nmax_];
  sipip = new Float_t[nmax_];
  eseed = new Float_t[nmax_];
  hOverE = new Float_t[nmax_];
  rawPt = new Float_t[nmax_];
  regPt = new Float_t[nmax_];
  veto = new Bool_t[nmax_];
  triggerMatch = new Bool_t[nmax_][nElectronTriggerObjects];
  superCluster_ = new Short_t[nmax_];
}

void
panda::Electron::datastore::deallocate()
{
  Lepton::datastore::deallocate();

  delete [] hltsafe;
  hltsafe = 0;
  delete [] chisoPh;
  chisoPh = 0;
  delete [] nhisoPh;
  nhisoPh = 0;
  delete [] phisoPh;
  phisoPh = 0;
  delete [] ecaliso;
  ecaliso = 0;
  delete [] hcaliso;
  hcaliso = 0;
  delete [] isoPUOffset;
  isoPUOffset = 0;
  delete [] sieie;
  sieie = 0;
  delete [] sipip;
  sipip = 0;
  delete [] eseed;
  eseed = 0;
  delete [] hOverE;
  hOverE = 0;
  delete [] rawPt;
  rawPt = 0;
  delete [] regPt;
  regPt = 0;
  delete [] veto;
  veto = 0;
  delete [] triggerMatch;
  triggerMatch = 0;
  delete [] superCluster_;
  superCluster_ = 0;
}

void
panda::Electron::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Lepton::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "hltsafe", _branches);
  utils::setStatus(_tree, _name, "chisoPh", _branches);
  utils::setStatus(_tree, _name, "nhisoPh", _branches);
  utils::setStatus(_tree, _name, "phisoPh", _branches);
  utils::setStatus(_tree, _name, "ecaliso", _branches);
  utils::setStatus(_tree, _name, "hcaliso", _branches);
  utils::setStatus(_tree, _name, "isoPUOffset", _branches);
  utils::setStatus(_tree, _name, "sieie", _branches);
  utils::setStatus(_tree, _name, "sipip", _branches);
  utils::setStatus(_tree, _name, "eseed", _branches);
  utils::setStatus(_tree, _name, "hOverE", _branches);
  utils::setStatus(_tree, _name, "rawPt", _branches);
  utils::setStatus(_tree, _name, "regPt", _branches);
  utils::setStatus(_tree, _name, "veto", _branches);
  utils::setStatus(_tree, _name, "triggerMatch", _branches);
  utils::setStatus(_tree, _name, "superCluster_", _branches);
}

panda::utils::BranchList
panda::Electron::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Lepton::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "hltsafe"));
  blist.push_back(utils::getStatus(_tree, _name, "chisoPh"));
  blist.push_back(utils::getStatus(_tree, _name, "nhisoPh"));
  blist.push_back(utils::getStatus(_tree, _name, "phisoPh"));
  blist.push_back(utils::getStatus(_tree, _name, "ecaliso"));
  blist.push_back(utils::getStatus(_tree, _name, "hcaliso"));
  blist.push_back(utils::getStatus(_tree, _name, "isoPUOffset"));
  blist.push_back(utils::getStatus(_tree, _name, "sieie"));
  blist.push_back(utils::getStatus(_tree, _name, "sipip"));
  blist.push_back(utils::getStatus(_tree, _name, "eseed"));
  blist.push_back(utils::getStatus(_tree, _name, "hOverE"));
  blist.push_back(utils::getStatus(_tree, _name, "rawPt"));
  blist.push_back(utils::getStatus(_tree, _name, "regPt"));
  blist.push_back(utils::getStatus(_tree, _name, "veto"));
  blist.push_back(utils::getStatus(_tree, _name, "triggerMatch"));
  blist.push_back(utils::getStatus(_tree, _name, "superCluster_"));

  return blist;
}

void
panda::Electron::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Lepton::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "hltsafe", hltsafe, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chisoPh", chisoPh, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhisoPh", nhisoPh, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phisoPh", phisoPh, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ecaliso", ecaliso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hcaliso", hcaliso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "isoPUOffset", isoPUOffset, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sieie", sieie, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sipip", sipip, _branches, _setStatus);
  utils::setAddress(_tree, _name, "eseed", eseed, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hOverE", hOverE, _branches, _setStatus);
  utils::setAddress(_tree, _name, "rawPt", rawPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "regPt", regPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "veto", veto, _branches, _setStatus);
  utils::setAddress(_tree, _name, "triggerMatch", triggerMatch, _branches, _setStatus);
  utils::setAddress(_tree, _name, "superCluster_", superCluster_, _branches, _setStatus);
}

void
panda::Electron::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Lepton::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "hltsafe", size, 'O', hltsafe, _branches);
  utils::book(_tree, _name, "chisoPh", size, 'F', chisoPh, _branches);
  utils::book(_tree, _name, "nhisoPh", size, 'F', nhisoPh, _branches);
  utils::book(_tree, _name, "phisoPh", size, 'F', phisoPh, _branches);
  utils::book(_tree, _name, "ecaliso", size, 'F', ecaliso, _branches);
  utils::book(_tree, _name, "hcaliso", size, 'F', hcaliso, _branches);
  utils::book(_tree, _name, "isoPUOffset", size, 'F', isoPUOffset, _branches);
  utils::book(_tree, _name, "sieie", size, 'F', sieie, _branches);
  utils::book(_tree, _name, "sipip", size, 'F', sipip, _branches);
  utils::book(_tree, _name, "eseed", size, 'F', eseed, _branches);
  utils::book(_tree, _name, "hOverE", size, 'F', hOverE, _branches);
  utils::book(_tree, _name, "rawPt", size, 'F', rawPt, _branches);
  utils::book(_tree, _name, "regPt", size, 'F', regPt, _branches);
  utils::book(_tree, _name, "veto", size, 'O', veto, _branches);
  utils::book(_tree, _name, "triggerMatch", size + TString::Format("[%d]", nElectronTriggerObjects), 'O', triggerMatch, _branches);
  utils::book(_tree, _name, "superCluster_", size, 'S', superCluster_, _branches);
}

void
panda::Electron::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Lepton::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "hltsafe");
  utils::resetAddress(_tree, _name, "chisoPh");
  utils::resetAddress(_tree, _name, "nhisoPh");
  utils::resetAddress(_tree, _name, "phisoPh");
  utils::resetAddress(_tree, _name, "ecaliso");
  utils::resetAddress(_tree, _name, "hcaliso");
  utils::resetAddress(_tree, _name, "isoPUOffset");
  utils::resetAddress(_tree, _name, "sieie");
  utils::resetAddress(_tree, _name, "sipip");
  utils::resetAddress(_tree, _name, "eseed");
  utils::resetAddress(_tree, _name, "hOverE");
  utils::resetAddress(_tree, _name, "rawPt");
  utils::resetAddress(_tree, _name, "regPt");
  utils::resetAddress(_tree, _name, "veto");
  utils::resetAddress(_tree, _name, "triggerMatch");
  utils::resetAddress(_tree, _name, "superCluster_");
}

void
panda::Electron::datastore::resizeVectors_(UInt_t _size)
{
  Lepton::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::Electron::datastore::getBranchNames(TString const& _name) const
{
  return Electron::getListOfBranches().fullNames(_name);
}

panda::Electron::Electron(char const* _name/* = ""*/) :
  Lepton(new ElectronArray(1, _name)),
  hltsafe(gStore.getData(this).hltsafe[0]),
  chisoPh(gStore.getData(this).chisoPh[0]),
  nhisoPh(gStore.getData(this).nhisoPh[0]),
  phisoPh(gStore.getData(this).phisoPh[0]),
  ecaliso(gStore.getData(this).ecaliso[0]),
  hcaliso(gStore.getData(this).hcaliso[0]),
  isoPUOffset(gStore.getData(this).isoPUOffset[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  eseed(gStore.getData(this).eseed[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  rawPt(gStore.getData(this).rawPt[0]),
  regPt(gStore.getData(this).regPt[0]),
  veto(gStore.getData(this).veto[0]),
  triggerMatch(gStore.getData(this).triggerMatch[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0])
{
}

panda::Electron::Electron(Electron const& _src) :
  Lepton(new ElectronArray(1, gStore.getName(&_src))),
  hltsafe(gStore.getData(this).hltsafe[0]),
  chisoPh(gStore.getData(this).chisoPh[0]),
  nhisoPh(gStore.getData(this).nhisoPh[0]),
  phisoPh(gStore.getData(this).phisoPh[0]),
  ecaliso(gStore.getData(this).ecaliso[0]),
  hcaliso(gStore.getData(this).hcaliso[0]),
  isoPUOffset(gStore.getData(this).isoPUOffset[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  eseed(gStore.getData(this).eseed[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  rawPt(gStore.getData(this).rawPt[0]),
  regPt(gStore.getData(this).regPt[0]),
  veto(gStore.getData(this).veto[0]),
  triggerMatch(gStore.getData(this).triggerMatch[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0])
{
  Lepton::operator=(_src);

  hltsafe = _src.hltsafe;
  chisoPh = _src.chisoPh;
  nhisoPh = _src.nhisoPh;
  phisoPh = _src.phisoPh;
  ecaliso = _src.ecaliso;
  hcaliso = _src.hcaliso;
  isoPUOffset = _src.isoPUOffset;
  sieie = _src.sieie;
  sipip = _src.sipip;
  eseed = _src.eseed;
  hOverE = _src.hOverE;
  rawPt = _src.rawPt;
  regPt = _src.regPt;
  veto = _src.veto;
  std::memcpy(triggerMatch, _src.triggerMatch, sizeof(Bool_t) * nElectronTriggerObjects);
  superCluster = _src.superCluster;
}

panda::Electron::Electron(datastore& _data, UInt_t _idx) :
  Lepton(_data, _idx),
  hltsafe(_data.hltsafe[_idx]),
  chisoPh(_data.chisoPh[_idx]),
  nhisoPh(_data.nhisoPh[_idx]),
  phisoPh(_data.phisoPh[_idx]),
  ecaliso(_data.ecaliso[_idx]),
  hcaliso(_data.hcaliso[_idx]),
  isoPUOffset(_data.isoPUOffset[_idx]),
  sieie(_data.sieie[_idx]),
  sipip(_data.sipip[_idx]),
  eseed(_data.eseed[_idx]),
  hOverE(_data.hOverE[_idx]),
  rawPt(_data.rawPt[_idx]),
  regPt(_data.regPt[_idx]),
  veto(_data.veto[_idx]),
  triggerMatch(_data.triggerMatch[_idx]),
  superCluster(_data.superClusterContainer_, _data.superCluster_[_idx])
{
}

panda::Electron::Electron(ArrayBase* _array) :
  Lepton(_array),
  hltsafe(gStore.getData(this).hltsafe[0]),
  chisoPh(gStore.getData(this).chisoPh[0]),
  nhisoPh(gStore.getData(this).nhisoPh[0]),
  phisoPh(gStore.getData(this).phisoPh[0]),
  ecaliso(gStore.getData(this).ecaliso[0]),
  hcaliso(gStore.getData(this).hcaliso[0]),
  isoPUOffset(gStore.getData(this).isoPUOffset[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  eseed(gStore.getData(this).eseed[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  rawPt(gStore.getData(this).rawPt[0]),
  regPt(gStore.getData(this).regPt[0]),
  veto(gStore.getData(this).veto[0]),
  triggerMatch(gStore.getData(this).triggerMatch[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0])
{
}

panda::Electron::~Electron()
{
  destructor();
  gStore.free(this);
}

void
panda::Electron::destructor()
{
  /* BEGIN CUSTOM Electron.cc.destructor */
  /* END CUSTOM */

  Lepton::destructor();
}

panda::Electron&
panda::Electron::operator=(Electron const& _src)
{
  Lepton::operator=(_src);

  hltsafe = _src.hltsafe;
  chisoPh = _src.chisoPh;
  nhisoPh = _src.nhisoPh;
  phisoPh = _src.phisoPh;
  ecaliso = _src.ecaliso;
  hcaliso = _src.hcaliso;
  isoPUOffset = _src.isoPUOffset;
  sieie = _src.sieie;
  sipip = _src.sipip;
  eseed = _src.eseed;
  hOverE = _src.hOverE;
  rawPt = _src.rawPt;
  regPt = _src.regPt;
  veto = _src.veto;
  std::memcpy(triggerMatch, _src.triggerMatch, sizeof(Bool_t) * nElectronTriggerObjects);
  superCluster = _src.superCluster;

  return *this;
}

void
panda::Electron::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Lepton::doSetAddress_(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "hltsafe", &hltsafe, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chisoPh", &chisoPh, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhisoPh", &nhisoPh, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phisoPh", &phisoPh, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ecaliso", &ecaliso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hcaliso", &hcaliso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "isoPUOffset", &isoPUOffset, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sieie", &sieie, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sipip", &sipip, _branches, _setStatus);
  utils::setAddress(_tree, _name, "eseed", &eseed, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hOverE", &hOverE, _branches, _setStatus);
  utils::setAddress(_tree, _name, "rawPt", &rawPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "regPt", &regPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "veto", &veto, _branches, _setStatus);
  utils::setAddress(_tree, _name, "triggerMatch", triggerMatch, _branches, _setStatus);
  utils::setAddress(_tree, _name, "superCluster_", gStore.getData(this).superCluster_, _branches, true);
}

void
panda::Electron::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  Lepton::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "hltsafe", "", 'O', &hltsafe, _branches);
  utils::book(_tree, _name, "chisoPh", "", 'F', &chisoPh, _branches);
  utils::book(_tree, _name, "nhisoPh", "", 'F', &nhisoPh, _branches);
  utils::book(_tree, _name, "phisoPh", "", 'F', &phisoPh, _branches);
  utils::book(_tree, _name, "ecaliso", "", 'F', &ecaliso, _branches);
  utils::book(_tree, _name, "hcaliso", "", 'F', &hcaliso, _branches);
  utils::book(_tree, _name, "isoPUOffset", "", 'F', &isoPUOffset, _branches);
  utils::book(_tree, _name, "sieie", "", 'F', &sieie, _branches);
  utils::book(_tree, _name, "sipip", "", 'F', &sipip, _branches);
  utils::book(_tree, _name, "eseed", "", 'F', &eseed, _branches);
  utils::book(_tree, _name, "hOverE", "", 'F', &hOverE, _branches);
  utils::book(_tree, _name, "rawPt", "", 'F', &rawPt, _branches);
  utils::book(_tree, _name, "regPt", "", 'F', &regPt, _branches);
  utils::book(_tree, _name, "veto", "", 'O', &veto, _branches);
  utils::book(_tree, _name, "triggerMatch", TString::Format("[%d]", nElectronTriggerObjects), 'O', triggerMatch, _branches);
  utils::book(_tree, _name, "superCluster_", "", 'S', gStore.getData(this).superCluster_, _branches);
}

void
panda::Electron::doReleaseTree_(TTree& _tree, TString const& _name)
{
  Lepton::doReleaseTree_(_tree, _name);

  utils::resetAddress(_tree, _name, "hltsafe");
  utils::resetAddress(_tree, _name, "chisoPh");
  utils::resetAddress(_tree, _name, "nhisoPh");
  utils::resetAddress(_tree, _name, "phisoPh");
  utils::resetAddress(_tree, _name, "ecaliso");
  utils::resetAddress(_tree, _name, "hcaliso");
  utils::resetAddress(_tree, _name, "isoPUOffset");
  utils::resetAddress(_tree, _name, "sieie");
  utils::resetAddress(_tree, _name, "sipip");
  utils::resetAddress(_tree, _name, "eseed");
  utils::resetAddress(_tree, _name, "hOverE");
  utils::resetAddress(_tree, _name, "rawPt");
  utils::resetAddress(_tree, _name, "regPt");
  utils::resetAddress(_tree, _name, "veto");
  utils::resetAddress(_tree, _name, "triggerMatch");
  utils::resetAddress(_tree, _name, "superCluster_");
}

void
panda::Electron::doInit_()
{
  Lepton::doInit_();

  hltsafe = false;
  chisoPh = 0.;
  nhisoPh = 0.;
  phisoPh = 0.;
  ecaliso = 0.;
  hcaliso = 0.;
  isoPUOffset = 0.;
  sieie = 0.;
  sipip = 0.;
  eseed = 0.;
  hOverE = 0.;
  rawPt = 0.;
  regPt = 0.;
  veto = false;
  for (auto& p0 : triggerMatch) p0 = false;
  superCluster.init();

  /* BEGIN CUSTOM Electron.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::Electron::print(std::ostream& _out/* = std::cout*/) const
{
  /* BEGIN CUSTOM Electron.cc.print */
  /* END CUSTOM */
}


/* BEGIN CUSTOM Electron.cc.global */
/* END CUSTOM */
