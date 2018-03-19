#include "../interface/Muon.h"

TString panda::Muon::TriggerObjectName[] = {
  "fMu17Mu8FirstLeg",
  "fMu17Mu8SecondLeg",
  "fIsoMu22er",
  "fIsoTkMu22er",
  "fIsoMu24",
  "fIsoTkMu24",
  "fIsoMu27",
  "fIsoTkMu27",
  "fMu50"
};
TString panda::Muon::SelectorName[] = {
  "kCutBasedIdLoose",
  "kCutBasedIdMedium",
  "kCutBasedIdMediumPrompt",
  "kCutBasedIdTight",
  "kCutBasedIdGlobalHighPt",
  "kCutBasedIdTrkHighPt",
  "kPFIsoVeryLoose",
  "kPFIsoLoose",
  "kPFIsoMedium",
  "kPFIsoTight",
  "kPFIsoVeryTight",
  "kTkIsoLoose",
  "kTkIsoTight",
  "kSoftCutBasedId",
  "kSoftMvaId",
  "kMvaLoose",
  "kMvaMedium",
  "kMvaTight",
  "kMiniIsoLoose",
  "kMiniIsoMedium",
  "kMiniIsoTight",
  "kMiniIsoVeryTight"
};

/*static*/
panda::utils::BranchList
panda::Muon::getListOfBranches()
{
  utils::BranchList blist;
  blist += Lepton::getListOfBranches();
  blist += {"soft", "selector", "global", "pf", "tracker", "standalone", "calo", "rpc", "gem", "me0", "validFraction", "nValidMuon", "nValidPixel", "trkLayersWithMmt", "pixLayersWithMmt", "nMatched", "normChi2", "chi2LocalPosition", "trkKink", "segmentCompatibility", "r03Iso", "triggerMatch"};
  return blist;
}

void
panda::Muon::datastore::allocate(UInt_t _nmax)
{
  Lepton::datastore::allocate(_nmax);

  soft = new Bool_t[nmax_];
  selector = new Bool_t[nmax_][nSelectors];
  global = new Bool_t[nmax_];
  pf = new Bool_t[nmax_];
  tracker = new Bool_t[nmax_];
  standalone = new Bool_t[nmax_];
  calo = new Bool_t[nmax_];
  rpc = new Bool_t[nmax_];
  gem = new Bool_t[nmax_];
  me0 = new Bool_t[nmax_];
  validFraction = new Float_t[nmax_];
  nValidMuon = new UShort_t[nmax_];
  nValidPixel = new UShort_t[nmax_];
  trkLayersWithMmt = new UShort_t[nmax_];
  pixLayersWithMmt = new UShort_t[nmax_];
  nMatched = new UShort_t[nmax_];
  normChi2 = new Float_t[nmax_];
  chi2LocalPosition = new UShort_t[nmax_];
  trkKink = new UShort_t[nmax_];
  segmentCompatibility = new Float_t[nmax_];
  r03Iso = new Float_t[nmax_];
  triggerMatch = new Bool_t[nmax_][nTriggerObjects];
}

void
panda::Muon::datastore::deallocate()
{
  Lepton::datastore::deallocate();

  delete [] soft;
  soft = 0;
  delete [] selector;
  selector = 0;
  delete [] global;
  global = 0;
  delete [] pf;
  pf = 0;
  delete [] tracker;
  tracker = 0;
  delete [] standalone;
  standalone = 0;
  delete [] calo;
  calo = 0;
  delete [] rpc;
  rpc = 0;
  delete [] gem;
  gem = 0;
  delete [] me0;
  me0 = 0;
  delete [] validFraction;
  validFraction = 0;
  delete [] nValidMuon;
  nValidMuon = 0;
  delete [] nValidPixel;
  nValidPixel = 0;
  delete [] trkLayersWithMmt;
  trkLayersWithMmt = 0;
  delete [] pixLayersWithMmt;
  pixLayersWithMmt = 0;
  delete [] nMatched;
  nMatched = 0;
  delete [] normChi2;
  normChi2 = 0;
  delete [] chi2LocalPosition;
  chi2LocalPosition = 0;
  delete [] trkKink;
  trkKink = 0;
  delete [] segmentCompatibility;
  segmentCompatibility = 0;
  delete [] r03Iso;
  r03Iso = 0;
  delete [] triggerMatch;
  triggerMatch = 0;
}

void
panda::Muon::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Lepton::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "soft", _branches);
  utils::setStatus(_tree, _name, "selector", _branches);
  utils::setStatus(_tree, _name, "global", _branches);
  utils::setStatus(_tree, _name, "pf", _branches);
  utils::setStatus(_tree, _name, "tracker", _branches);
  utils::setStatus(_tree, _name, "standalone", _branches);
  utils::setStatus(_tree, _name, "calo", _branches);
  utils::setStatus(_tree, _name, "rpc", _branches);
  utils::setStatus(_tree, _name, "gem", _branches);
  utils::setStatus(_tree, _name, "me0", _branches);
  utils::setStatus(_tree, _name, "validFraction", _branches);
  utils::setStatus(_tree, _name, "nValidMuon", _branches);
  utils::setStatus(_tree, _name, "nValidPixel", _branches);
  utils::setStatus(_tree, _name, "trkLayersWithMmt", _branches);
  utils::setStatus(_tree, _name, "pixLayersWithMmt", _branches);
  utils::setStatus(_tree, _name, "nMatched", _branches);
  utils::setStatus(_tree, _name, "normChi2", _branches);
  utils::setStatus(_tree, _name, "chi2LocalPosition", _branches);
  utils::setStatus(_tree, _name, "trkKink", _branches);
  utils::setStatus(_tree, _name, "segmentCompatibility", _branches);
  utils::setStatus(_tree, _name, "r03Iso", _branches);
  utils::setStatus(_tree, _name, "triggerMatch", _branches);
}

panda::utils::BranchList
panda::Muon::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Lepton::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "soft"));
  blist.push_back(utils::getStatus(_tree, _name, "selector"));
  blist.push_back(utils::getStatus(_tree, _name, "global"));
  blist.push_back(utils::getStatus(_tree, _name, "pf"));
  blist.push_back(utils::getStatus(_tree, _name, "tracker"));
  blist.push_back(utils::getStatus(_tree, _name, "standalone"));
  blist.push_back(utils::getStatus(_tree, _name, "calo"));
  blist.push_back(utils::getStatus(_tree, _name, "rpc"));
  blist.push_back(utils::getStatus(_tree, _name, "gem"));
  blist.push_back(utils::getStatus(_tree, _name, "me0"));
  blist.push_back(utils::getStatus(_tree, _name, "validFraction"));
  blist.push_back(utils::getStatus(_tree, _name, "nValidMuon"));
  blist.push_back(utils::getStatus(_tree, _name, "nValidPixel"));
  blist.push_back(utils::getStatus(_tree, _name, "trkLayersWithMmt"));
  blist.push_back(utils::getStatus(_tree, _name, "pixLayersWithMmt"));
  blist.push_back(utils::getStatus(_tree, _name, "nMatched"));
  blist.push_back(utils::getStatus(_tree, _name, "normChi2"));
  blist.push_back(utils::getStatus(_tree, _name, "chi2LocalPosition"));
  blist.push_back(utils::getStatus(_tree, _name, "trkKink"));
  blist.push_back(utils::getStatus(_tree, _name, "segmentCompatibility"));
  blist.push_back(utils::getStatus(_tree, _name, "r03Iso"));
  blist.push_back(utils::getStatus(_tree, _name, "triggerMatch"));

  return blist;
}

void
panda::Muon::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Lepton::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "soft", soft, _branches, _setStatus);
  utils::setAddress(_tree, _name, "selector", selector, _branches, _setStatus);
  utils::setAddress(_tree, _name, "global", global, _branches, _setStatus);
  utils::setAddress(_tree, _name, "pf", pf, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tracker", tracker, _branches, _setStatus);
  utils::setAddress(_tree, _name, "standalone", standalone, _branches, _setStatus);
  utils::setAddress(_tree, _name, "calo", calo, _branches, _setStatus);
  utils::setAddress(_tree, _name, "rpc", rpc, _branches, _setStatus);
  utils::setAddress(_tree, _name, "gem", gem, _branches, _setStatus);
  utils::setAddress(_tree, _name, "me0", me0, _branches, _setStatus);
  utils::setAddress(_tree, _name, "validFraction", validFraction, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nValidMuon", nValidMuon, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nValidPixel", nValidPixel, _branches, _setStatus);
  utils::setAddress(_tree, _name, "trkLayersWithMmt", trkLayersWithMmt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "pixLayersWithMmt", pixLayersWithMmt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nMatched", nMatched, _branches, _setStatus);
  utils::setAddress(_tree, _name, "normChi2", normChi2, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chi2LocalPosition", chi2LocalPosition, _branches, _setStatus);
  utils::setAddress(_tree, _name, "trkKink", trkKink, _branches, _setStatus);
  utils::setAddress(_tree, _name, "segmentCompatibility", segmentCompatibility, _branches, _setStatus);
  utils::setAddress(_tree, _name, "r03Iso", r03Iso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "triggerMatch", triggerMatch, _branches, _setStatus);
}

void
panda::Muon::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Lepton::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "soft", size, 'O', soft, _branches);
  utils::book(_tree, _name, "selector", size + TString::Format("[%d]", nSelectors), 'O', selector, _branches);
  utils::book(_tree, _name, "global", size, 'O', global, _branches);
  utils::book(_tree, _name, "pf", size, 'O', pf, _branches);
  utils::book(_tree, _name, "tracker", size, 'O', tracker, _branches);
  utils::book(_tree, _name, "standalone", size, 'O', standalone, _branches);
  utils::book(_tree, _name, "calo", size, 'O', calo, _branches);
  utils::book(_tree, _name, "rpc", size, 'O', rpc, _branches);
  utils::book(_tree, _name, "gem", size, 'O', gem, _branches);
  utils::book(_tree, _name, "me0", size, 'O', me0, _branches);
  utils::book(_tree, _name, "validFraction", size, 'F', validFraction, _branches);
  utils::book(_tree, _name, "nValidMuon", size, 's', nValidMuon, _branches);
  utils::book(_tree, _name, "nValidPixel", size, 's', nValidPixel, _branches);
  utils::book(_tree, _name, "trkLayersWithMmt", size, 's', trkLayersWithMmt, _branches);
  utils::book(_tree, _name, "pixLayersWithMmt", size, 's', pixLayersWithMmt, _branches);
  utils::book(_tree, _name, "nMatched", size, 's', nMatched, _branches);
  utils::book(_tree, _name, "normChi2", size, 'F', normChi2, _branches);
  utils::book(_tree, _name, "chi2LocalPosition", size, 's', chi2LocalPosition, _branches);
  utils::book(_tree, _name, "trkKink", size, 's', trkKink, _branches);
  utils::book(_tree, _name, "segmentCompatibility", size, 'F', segmentCompatibility, _branches);
  utils::book(_tree, _name, "r03Iso", size, 'F', r03Iso, _branches);
  utils::book(_tree, _name, "triggerMatch", size + TString::Format("[%d]", nTriggerObjects), 'O', triggerMatch, _branches);
}

void
panda::Muon::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Lepton::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "soft");
  utils::resetAddress(_tree, _name, "selector");
  utils::resetAddress(_tree, _name, "global");
  utils::resetAddress(_tree, _name, "pf");
  utils::resetAddress(_tree, _name, "tracker");
  utils::resetAddress(_tree, _name, "standalone");
  utils::resetAddress(_tree, _name, "calo");
  utils::resetAddress(_tree, _name, "rpc");
  utils::resetAddress(_tree, _name, "gem");
  utils::resetAddress(_tree, _name, "me0");
  utils::resetAddress(_tree, _name, "validFraction");
  utils::resetAddress(_tree, _name, "nValidMuon");
  utils::resetAddress(_tree, _name, "nValidPixel");
  utils::resetAddress(_tree, _name, "trkLayersWithMmt");
  utils::resetAddress(_tree, _name, "pixLayersWithMmt");
  utils::resetAddress(_tree, _name, "nMatched");
  utils::resetAddress(_tree, _name, "normChi2");
  utils::resetAddress(_tree, _name, "chi2LocalPosition");
  utils::resetAddress(_tree, _name, "trkKink");
  utils::resetAddress(_tree, _name, "segmentCompatibility");
  utils::resetAddress(_tree, _name, "r03Iso");
  utils::resetAddress(_tree, _name, "triggerMatch");
}

void
panda::Muon::datastore::resizeVectors_(UInt_t _size)
{
  Lepton::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::Muon::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return Muon::getListOfBranches().fullNames(_name);
}

panda::Muon::Muon(char const* _name/* = ""*/) :
  Lepton(new MuonArray(1, _name)),
  soft(gStore.getData(this).soft[0]),
  selector(gStore.getData(this).selector[0]),
  global(gStore.getData(this).global[0]),
  pf(gStore.getData(this).pf[0]),
  tracker(gStore.getData(this).tracker[0]),
  standalone(gStore.getData(this).standalone[0]),
  calo(gStore.getData(this).calo[0]),
  rpc(gStore.getData(this).rpc[0]),
  gem(gStore.getData(this).gem[0]),
  me0(gStore.getData(this).me0[0]),
  validFraction(gStore.getData(this).validFraction[0]),
  nValidMuon(gStore.getData(this).nValidMuon[0]),
  nValidPixel(gStore.getData(this).nValidPixel[0]),
  trkLayersWithMmt(gStore.getData(this).trkLayersWithMmt[0]),
  pixLayersWithMmt(gStore.getData(this).pixLayersWithMmt[0]),
  nMatched(gStore.getData(this).nMatched[0]),
  normChi2(gStore.getData(this).normChi2[0]),
  chi2LocalPosition(gStore.getData(this).chi2LocalPosition[0]),
  trkKink(gStore.getData(this).trkKink[0]),
  segmentCompatibility(gStore.getData(this).segmentCompatibility[0]),
  r03Iso(gStore.getData(this).r03Iso[0]),
  triggerMatch(gStore.getData(this).triggerMatch[0])
{
}

panda::Muon::Muon(Muon const& _src) :
  Lepton(new MuonArray(1, _src.getName())),
  soft(gStore.getData(this).soft[0]),
  selector(gStore.getData(this).selector[0]),
  global(gStore.getData(this).global[0]),
  pf(gStore.getData(this).pf[0]),
  tracker(gStore.getData(this).tracker[0]),
  standalone(gStore.getData(this).standalone[0]),
  calo(gStore.getData(this).calo[0]),
  rpc(gStore.getData(this).rpc[0]),
  gem(gStore.getData(this).gem[0]),
  me0(gStore.getData(this).me0[0]),
  validFraction(gStore.getData(this).validFraction[0]),
  nValidMuon(gStore.getData(this).nValidMuon[0]),
  nValidPixel(gStore.getData(this).nValidPixel[0]),
  trkLayersWithMmt(gStore.getData(this).trkLayersWithMmt[0]),
  pixLayersWithMmt(gStore.getData(this).pixLayersWithMmt[0]),
  nMatched(gStore.getData(this).nMatched[0]),
  normChi2(gStore.getData(this).normChi2[0]),
  chi2LocalPosition(gStore.getData(this).chi2LocalPosition[0]),
  trkKink(gStore.getData(this).trkKink[0]),
  segmentCompatibility(gStore.getData(this).segmentCompatibility[0]),
  r03Iso(gStore.getData(this).r03Iso[0]),
  triggerMatch(gStore.getData(this).triggerMatch[0])
{
  Lepton::operator=(_src);

  soft = _src.soft;
  std::memcpy(selector, _src.selector, sizeof(Bool_t) * nSelectors);
  global = _src.global;
  pf = _src.pf;
  tracker = _src.tracker;
  standalone = _src.standalone;
  calo = _src.calo;
  rpc = _src.rpc;
  gem = _src.gem;
  me0 = _src.me0;
  validFraction = _src.validFraction;
  nValidMuon = _src.nValidMuon;
  nValidPixel = _src.nValidPixel;
  trkLayersWithMmt = _src.trkLayersWithMmt;
  pixLayersWithMmt = _src.pixLayersWithMmt;
  nMatched = _src.nMatched;
  normChi2 = _src.normChi2;
  chi2LocalPosition = _src.chi2LocalPosition;
  trkKink = _src.trkKink;
  segmentCompatibility = _src.segmentCompatibility;
  r03Iso = _src.r03Iso;
  std::memcpy(triggerMatch, _src.triggerMatch, sizeof(Bool_t) * nTriggerObjects);
}

panda::Muon::Muon(datastore& _data, UInt_t _idx) :
  Lepton(_data, _idx),
  soft(_data.soft[_idx]),
  selector(_data.selector[_idx]),
  global(_data.global[_idx]),
  pf(_data.pf[_idx]),
  tracker(_data.tracker[_idx]),
  standalone(_data.standalone[_idx]),
  calo(_data.calo[_idx]),
  rpc(_data.rpc[_idx]),
  gem(_data.gem[_idx]),
  me0(_data.me0[_idx]),
  validFraction(_data.validFraction[_idx]),
  nValidMuon(_data.nValidMuon[_idx]),
  nValidPixel(_data.nValidPixel[_idx]),
  trkLayersWithMmt(_data.trkLayersWithMmt[_idx]),
  pixLayersWithMmt(_data.pixLayersWithMmt[_idx]),
  nMatched(_data.nMatched[_idx]),
  normChi2(_data.normChi2[_idx]),
  chi2LocalPosition(_data.chi2LocalPosition[_idx]),
  trkKink(_data.trkKink[_idx]),
  segmentCompatibility(_data.segmentCompatibility[_idx]),
  r03Iso(_data.r03Iso[_idx]),
  triggerMatch(_data.triggerMatch[_idx])
{
}

panda::Muon::Muon(ArrayBase* _array) :
  Lepton(_array),
  soft(gStore.getData(this).soft[0]),
  selector(gStore.getData(this).selector[0]),
  global(gStore.getData(this).global[0]),
  pf(gStore.getData(this).pf[0]),
  tracker(gStore.getData(this).tracker[0]),
  standalone(gStore.getData(this).standalone[0]),
  calo(gStore.getData(this).calo[0]),
  rpc(gStore.getData(this).rpc[0]),
  gem(gStore.getData(this).gem[0]),
  me0(gStore.getData(this).me0[0]),
  validFraction(gStore.getData(this).validFraction[0]),
  nValidMuon(gStore.getData(this).nValidMuon[0]),
  nValidPixel(gStore.getData(this).nValidPixel[0]),
  trkLayersWithMmt(gStore.getData(this).trkLayersWithMmt[0]),
  pixLayersWithMmt(gStore.getData(this).pixLayersWithMmt[0]),
  nMatched(gStore.getData(this).nMatched[0]),
  normChi2(gStore.getData(this).normChi2[0]),
  chi2LocalPosition(gStore.getData(this).chi2LocalPosition[0]),
  trkKink(gStore.getData(this).trkKink[0]),
  segmentCompatibility(gStore.getData(this).segmentCompatibility[0]),
  r03Iso(gStore.getData(this).r03Iso[0]),
  triggerMatch(gStore.getData(this).triggerMatch[0])
{
}

panda::Muon::~Muon()
{
  destructor();
}

void
panda::Muon::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM Muon.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    Lepton::destructor(kTRUE);
}

panda::Muon&
panda::Muon::operator=(Muon const& _src)
{
  Lepton::operator=(_src);

  soft = _src.soft;
  std::memcpy(selector, _src.selector, sizeof(Bool_t) * nSelectors);
  global = _src.global;
  pf = _src.pf;
  tracker = _src.tracker;
  standalone = _src.standalone;
  calo = _src.calo;
  rpc = _src.rpc;
  gem = _src.gem;
  me0 = _src.me0;
  validFraction = _src.validFraction;
  nValidMuon = _src.nValidMuon;
  nValidPixel = _src.nValidPixel;
  trkLayersWithMmt = _src.trkLayersWithMmt;
  pixLayersWithMmt = _src.pixLayersWithMmt;
  nMatched = _src.nMatched;
  normChi2 = _src.normChi2;
  chi2LocalPosition = _src.chi2LocalPosition;
  trkKink = _src.trkKink;
  segmentCompatibility = _src.segmentCompatibility;
  r03Iso = _src.r03Iso;
  std::memcpy(triggerMatch, _src.triggerMatch, sizeof(Bool_t) * nTriggerObjects);

  /* BEGIN CUSTOM Muon.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
panda::Muon::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  Lepton::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "soft", "", 'O', &soft, _branches);
  utils::book(_tree, _name, "selector", TString::Format("[%d]", nSelectors), 'O', selector, _branches);
  utils::book(_tree, _name, "global", "", 'O', &global, _branches);
  utils::book(_tree, _name, "pf", "", 'O', &pf, _branches);
  utils::book(_tree, _name, "tracker", "", 'O', &tracker, _branches);
  utils::book(_tree, _name, "standalone", "", 'O', &standalone, _branches);
  utils::book(_tree, _name, "calo", "", 'O', &calo, _branches);
  utils::book(_tree, _name, "rpc", "", 'O', &rpc, _branches);
  utils::book(_tree, _name, "gem", "", 'O', &gem, _branches);
  utils::book(_tree, _name, "me0", "", 'O', &me0, _branches);
  utils::book(_tree, _name, "validFraction", "", 'F', &validFraction, _branches);
  utils::book(_tree, _name, "nValidMuon", "", 's', &nValidMuon, _branches);
  utils::book(_tree, _name, "nValidPixel", "", 's', &nValidPixel, _branches);
  utils::book(_tree, _name, "trkLayersWithMmt", "", 's', &trkLayersWithMmt, _branches);
  utils::book(_tree, _name, "pixLayersWithMmt", "", 's', &pixLayersWithMmt, _branches);
  utils::book(_tree, _name, "nMatched", "", 's', &nMatched, _branches);
  utils::book(_tree, _name, "normChi2", "", 'F', &normChi2, _branches);
  utils::book(_tree, _name, "chi2LocalPosition", "", 's', &chi2LocalPosition, _branches);
  utils::book(_tree, _name, "trkKink", "", 's', &trkKink, _branches);
  utils::book(_tree, _name, "segmentCompatibility", "", 'F', &segmentCompatibility, _branches);
  utils::book(_tree, _name, "r03Iso", "", 'F', &r03Iso, _branches);
  utils::book(_tree, _name, "triggerMatch", TString::Format("[%d]", nTriggerObjects), 'O', triggerMatch, _branches);
}

void
panda::Muon::doInit_()
{
  Lepton::doInit_();

  soft = false;
  for (auto& p0 : selector) p0 = false;
  global = false;
  pf = false;
  tracker = false;
  standalone = false;
  calo = false;
  rpc = false;
  gem = false;
  me0 = false;
  validFraction = 0.;
  nValidMuon = 0;
  nValidPixel = 0;
  trkLayersWithMmt = 0;
  pixLayersWithMmt = 0;
  nMatched = 0;
  normChi2 = 0.;
  chi2LocalPosition = 0;
  trkKink = 0;
  segmentCompatibility = 0.;
  r03Iso = 0.;
  for (auto& p0 : triggerMatch) p0 = false;

  /* BEGIN CUSTOM Muon.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::Muon::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM Muon.cc.print */
  if (_level >= 3) {
    Muon::dump(_out);
    
    _out << "combIso = " << combIso() << std::endl;
    _out << "combRelIso = " << combIso() / pt() << std::endl;
  }
  else if (_level == 2) {
    Lepton::print(_out, _level);
    
    _out << "combIso = " << combIso() << std::endl;
    _out << "combRelIso = " << combIso() / pt() << std::endl;
  }
  else
    return;
  /* END CUSTOM */
}

void
panda::Muon::dump(std::ostream& _out/* = std::cout*/) const
{
  Lepton::dump(_out);

  _out << "soft = " << soft << std::endl;
  _out << "selector = " << selector << std::endl;
  _out << "global = " << global << std::endl;
  _out << "pf = " << pf << std::endl;
  _out << "tracker = " << tracker << std::endl;
  _out << "standalone = " << standalone << std::endl;
  _out << "calo = " << calo << std::endl;
  _out << "rpc = " << rpc << std::endl;
  _out << "gem = " << gem << std::endl;
  _out << "me0 = " << me0 << std::endl;
  _out << "validFraction = " << validFraction << std::endl;
  _out << "nValidMuon = " << nValidMuon << std::endl;
  _out << "nValidPixel = " << nValidPixel << std::endl;
  _out << "trkLayersWithMmt = " << trkLayersWithMmt << std::endl;
  _out << "pixLayersWithMmt = " << pixLayersWithMmt << std::endl;
  _out << "nMatched = " << nMatched << std::endl;
  _out << "normChi2 = " << normChi2 << std::endl;
  _out << "chi2LocalPosition = " << chi2LocalPosition << std::endl;
  _out << "trkKink = " << trkKink << std::endl;
  _out << "segmentCompatibility = " << segmentCompatibility << std::endl;
  _out << "r03Iso = " << r03Iso << std::endl;
  _out << "triggerMatch = " << triggerMatch << std::endl;
}


/* BEGIN CUSTOM Muon.cc.global */
/* END CUSTOM */
