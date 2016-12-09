#include "../interface/PElectron.h"

void
panda::PElectron::datastore::allocate(UInt_t _nmax)
{
  PLepton::datastore::allocate(_nmax);

  chisoPh = new Float_t[nmax_];
  nhisoPh = new Float_t[nmax_];
  phisoPh = new Float_t[nmax_];
  ecaliso = new Float_t[nmax_];
  hcaliso = new Float_t[nmax_];
  isoPUOffset = new Float_t[nmax_];
  sieie = new Float_t[nmax_];
  sipip = new Float_t[nmax_];
  hOverE = new Float_t[nmax_];
  veto = new Bool_t[nmax_];
  matchHLT = new Bool_t[nmax_][nElectronHLTObjects];
  superCluster_ = new UInt_t[nmax_];
}

void
panda::PElectron::datastore::deallocate()
{
  PLepton::datastore::deallocate();

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
  delete [] hOverE;
  hOverE = 0;
  delete [] veto;
  veto = 0;
  delete [] matchHLT;
  matchHLT = 0;
  delete [] superCluster_;
  superCluster_ = 0;
}

void
panda::PElectron::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::datastore::setStatus(_tree, _name, _status, _branches);

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
  utils::setStatus(_tree, _name, "matchHLT", _status, _branches);
  utils::setStatus(_tree, _name, "superCluster_", _status, _branches);
}

void
panda::PElectron::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PLepton::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "chisoPh", chisoPh, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhisoPh", nhisoPh, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phisoPh", phisoPh, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ecaliso", ecaliso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hcaliso", hcaliso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "isoPUOffset", isoPUOffset, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sieie", sieie, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sipip", sipip, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hOverE", hOverE, _branches, _setStatus);
  utils::setAddress(_tree, _name, "veto", veto, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchHLT", matchHLT, _branches, _setStatus);
  utils::setAddress(_tree, _name, "superCluster_", superCluster_, _branches, _setStatus);
}

void
panda::PElectron::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PLepton::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "chisoPh", size, 'F', chisoPh, _branches);
  utils::book(_tree, _name, "nhisoPh", size, 'F', nhisoPh, _branches);
  utils::book(_tree, _name, "phisoPh", size, 'F', phisoPh, _branches);
  utils::book(_tree, _name, "ecaliso", size, 'F', ecaliso, _branches);
  utils::book(_tree, _name, "hcaliso", size, 'F', hcaliso, _branches);
  utils::book(_tree, _name, "isoPUOffset", size, 'F', isoPUOffset, _branches);
  utils::book(_tree, _name, "sieie", size, 'F', sieie, _branches);
  utils::book(_tree, _name, "sipip", size, 'F', sipip, _branches);
  utils::book(_tree, _name, "hOverE", size, 'F', hOverE, _branches);
  utils::book(_tree, _name, "veto", size, 'O', veto, _branches);
  utils::book(_tree, _name, "matchHLT", size + "[nElectronHLTObjects]", 'O', matchHLT, _branches);
  utils::book(_tree, _name, "superCluster_", size, 'i', superCluster_, _branches);
}

void
panda::PElectron::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  PLepton::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "chisoPh");
  utils::resetAddress(_tree, _name, "nhisoPh");
  utils::resetAddress(_tree, _name, "phisoPh");
  utils::resetAddress(_tree, _name, "ecaliso");
  utils::resetAddress(_tree, _name, "hcaliso");
  utils::resetAddress(_tree, _name, "isoPUOffset");
  utils::resetAddress(_tree, _name, "sieie");
  utils::resetAddress(_tree, _name, "sipip");
  utils::resetAddress(_tree, _name, "hOverE");
  utils::resetAddress(_tree, _name, "veto");
  utils::resetAddress(_tree, _name, "matchHLT");
  utils::resetAddress(_tree, _name, "superCluster_");
}

void
panda::PElectron::datastore::resizeVectors_(UInt_t _size)
{
  PLepton::datastore::resizeVectors_(_size);

}

panda::PElectron::PElectron(char const* _name/* = ""*/) :
  PLepton(new PElectronArray(1, _name)),
  chisoPh(gStore.getData(this).chisoPh[0]),
  nhisoPh(gStore.getData(this).nhisoPh[0]),
  phisoPh(gStore.getData(this).phisoPh[0]),
  ecaliso(gStore.getData(this).ecaliso[0]),
  hcaliso(gStore.getData(this).hcaliso[0]),
  isoPUOffset(gStore.getData(this).isoPUOffset[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  veto(gStore.getData(this).veto[0]),
  matchHLT(gStore.getData(this).matchHLT[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0])
{
}

panda::PElectron::PElectron(datastore& _data, UInt_t _idx) :
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
  matchHLT(_data.matchHLT[_idx]),
  superCluster(_data.superClusterContainer_, _data.superCluster_[_idx])
{
}

panda::PElectron::PElectron(PElectron const& _src) :
  PLepton(new PElectronArray(1, gStore.getName(&_src))),
  chisoPh(gStore.getData(this).chisoPh[0]),
  nhisoPh(gStore.getData(this).nhisoPh[0]),
  phisoPh(gStore.getData(this).phisoPh[0]),
  ecaliso(gStore.getData(this).ecaliso[0]),
  hcaliso(gStore.getData(this).hcaliso[0]),
  isoPUOffset(gStore.getData(this).isoPUOffset[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  veto(gStore.getData(this).veto[0]),
  matchHLT(gStore.getData(this).matchHLT[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0])
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
  std::memcpy(matchHLT, _src.matchHLT, sizeof(Bool_t) * nElectronHLTObjects);
  superCluster = _src.superCluster;
}

panda::PElectron::PElectron(ArrayBase* _array) :
  PLepton(_array),
  chisoPh(gStore.getData(this).chisoPh[0]),
  nhisoPh(gStore.getData(this).nhisoPh[0]),
  phisoPh(gStore.getData(this).phisoPh[0]),
  ecaliso(gStore.getData(this).ecaliso[0]),
  hcaliso(gStore.getData(this).hcaliso[0]),
  isoPUOffset(gStore.getData(this).isoPUOffset[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  hOverE(gStore.getData(this).hOverE[0]),
  veto(gStore.getData(this).veto[0]),
  matchHLT(gStore.getData(this).matchHLT[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0])
{
}

panda::PElectron::~PElectron()
{
  destructor();
  gStore.free(this);
}

void
panda::PElectron::destructor()
{
  /* BEGIN CUSTOM PElectron.cc.destructor */
  /* END CUSTOM */

  PLepton::destructor();
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
  std::memcpy(matchHLT, _src.matchHLT, sizeof(Bool_t) * nElectronHLTObjects);
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
  utils::setStatus(_tree, name, "matchHLT", _status, _branches);
  utils::setStatus(_tree, name, "superCluster_", _status, _branches);
}

void
panda::PElectron::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PLepton::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "chisoPh", &chisoPh, _branches, _setStatus);
  utils::setAddress(_tree, name, "nhisoPh", &nhisoPh, _branches, _setStatus);
  utils::setAddress(_tree, name, "phisoPh", &phisoPh, _branches, _setStatus);
  utils::setAddress(_tree, name, "ecaliso", &ecaliso, _branches, _setStatus);
  utils::setAddress(_tree, name, "hcaliso", &hcaliso, _branches, _setStatus);
  utils::setAddress(_tree, name, "isoPUOffset", &isoPUOffset, _branches, _setStatus);
  utils::setAddress(_tree, name, "sieie", &sieie, _branches, _setStatus);
  utils::setAddress(_tree, name, "sipip", &sipip, _branches, _setStatus);
  utils::setAddress(_tree, name, "hOverE", &hOverE, _branches, _setStatus);
  utils::setAddress(_tree, name, "veto", &veto, _branches, _setStatus);
  utils::setAddress(_tree, name, "matchHLT", matchHLT, _branches, _setStatus);
  utils::setAddress(_tree, name, "superCluster_", gStore.getData(this).superCluster_, _branches, true);
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
  utils::book(_tree, name, "matchHLT", "[nElectronHLTObjects]", 'O', matchHLT, _branches);
  utils::book(_tree, name, "superCluster_", "", 'i', gStore.getData(this).superCluster_, _branches);
}

void
panda::PElectron::resetAddress(TTree& _tree)
{
  PLepton::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "chisoPh");
  utils::resetAddress(_tree, name, "nhisoPh");
  utils::resetAddress(_tree, name, "phisoPh");
  utils::resetAddress(_tree, name, "ecaliso");
  utils::resetAddress(_tree, name, "hcaliso");
  utils::resetAddress(_tree, name, "isoPUOffset");
  utils::resetAddress(_tree, name, "sieie");
  utils::resetAddress(_tree, name, "sipip");
  utils::resetAddress(_tree, name, "hOverE");
  utils::resetAddress(_tree, name, "veto");
  utils::resetAddress(_tree, name, "matchHLT");
  utils::resetAddress(_tree, name, "superCluster_");
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
  for (auto& p0 : matchHLT) p0 = false;
  superCluster.init();
}


/* BEGIN CUSTOM PElectron.cc.global */
/* END CUSTOM */
