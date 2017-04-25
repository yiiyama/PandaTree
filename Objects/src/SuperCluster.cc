#include "../interface/SuperCluster.h"

/*static*/
panda::utils::BranchList
panda::SuperCluster::getListOfBranches()
{
  utils::BranchList blist;
  blist += {"rawPt", "eta", "phi", "sieie", "sipip", "e2e9", "emax", "e2nd", "e4", "time", "timeSpan", "trackIso", "mipEnergy", "mipChi2", "mipSlope", "mipIntercept", "mipNhits"};
  return blist;
}

void
panda::SuperCluster::datastore::allocate(UInt_t _nmax)
{
  Element::datastore::allocate(_nmax);

  rawPt = new Float_t[nmax_];
  eta = new Float_t[nmax_];
  phi = new Float_t[nmax_];
  sieie = new Float_t[nmax_];
  sipip = new Float_t[nmax_];
  e2e9 = new Float_t[nmax_];
  emax = new Float_t[nmax_];
  e2nd = new Float_t[nmax_];
  e4 = new Float_t[nmax_];
  time = new Float_t[nmax_];
  timeSpan = new Float_t[nmax_];
  trackIso = new Float_t[nmax_];
  mipEnergy = new Float_t[nmax_];
  mipChi2 = new Float_t[nmax_];
  mipSlope = new Float_t[nmax_];
  mipIntercept = new Float_t[nmax_];
  mipNhits = new Float_t[nmax_];
}

void
panda::SuperCluster::datastore::deallocate()
{
  Element::datastore::deallocate();

  delete [] rawPt;
  rawPt = 0;
  delete [] eta;
  eta = 0;
  delete [] phi;
  phi = 0;
  delete [] sieie;
  sieie = 0;
  delete [] sipip;
  sipip = 0;
  delete [] e2e9;
  e2e9 = 0;
  delete [] emax;
  emax = 0;
  delete [] e2nd;
  e2nd = 0;
  delete [] e4;
  e4 = 0;
  delete [] time;
  time = 0;
  delete [] timeSpan;
  timeSpan = 0;
  delete [] trackIso;
  trackIso = 0;
  delete [] mipEnergy;
  mipEnergy = 0;
  delete [] mipChi2;
  mipChi2 = 0;
  delete [] mipSlope;
  mipSlope = 0;
  delete [] mipIntercept;
  mipIntercept = 0;
  delete [] mipNhits;
  mipNhits = 0;
}

void
panda::SuperCluster::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Element::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "rawPt", _branches);
  utils::setStatus(_tree, _name, "eta", _branches);
  utils::setStatus(_tree, _name, "phi", _branches);
  utils::setStatus(_tree, _name, "sieie", _branches);
  utils::setStatus(_tree, _name, "sipip", _branches);
  utils::setStatus(_tree, _name, "e2e9", _branches);
  utils::setStatus(_tree, _name, "emax", _branches);
  utils::setStatus(_tree, _name, "e2nd", _branches);
  utils::setStatus(_tree, _name, "e4", _branches);
  utils::setStatus(_tree, _name, "time", _branches);
  utils::setStatus(_tree, _name, "timeSpan", _branches);
  utils::setStatus(_tree, _name, "trackIso", _branches);
  utils::setStatus(_tree, _name, "mipEnergy", _branches);
  utils::setStatus(_tree, _name, "mipChi2", _branches);
  utils::setStatus(_tree, _name, "mipSlope", _branches);
  utils::setStatus(_tree, _name, "mipIntercept", _branches);
  utils::setStatus(_tree, _name, "mipNhits", _branches);
}

panda::utils::BranchList
panda::SuperCluster::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Element::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "rawPt"));
  blist.push_back(utils::getStatus(_tree, _name, "eta"));
  blist.push_back(utils::getStatus(_tree, _name, "phi"));
  blist.push_back(utils::getStatus(_tree, _name, "sieie"));
  blist.push_back(utils::getStatus(_tree, _name, "sipip"));
  blist.push_back(utils::getStatus(_tree, _name, "e2e9"));
  blist.push_back(utils::getStatus(_tree, _name, "emax"));
  blist.push_back(utils::getStatus(_tree, _name, "e2nd"));
  blist.push_back(utils::getStatus(_tree, _name, "e4"));
  blist.push_back(utils::getStatus(_tree, _name, "time"));
  blist.push_back(utils::getStatus(_tree, _name, "timeSpan"));
  blist.push_back(utils::getStatus(_tree, _name, "trackIso"));
  blist.push_back(utils::getStatus(_tree, _name, "mipEnergy"));
  blist.push_back(utils::getStatus(_tree, _name, "mipChi2"));
  blist.push_back(utils::getStatus(_tree, _name, "mipSlope"));
  blist.push_back(utils::getStatus(_tree, _name, "mipIntercept"));
  blist.push_back(utils::getStatus(_tree, _name, "mipNhits"));

  return blist;
}

void
panda::SuperCluster::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Element::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "rawPt", rawPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "eta", eta, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phi", phi, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sieie", sieie, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sipip", sipip, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e2e9", e2e9, _branches, _setStatus);
  utils::setAddress(_tree, _name, "emax", emax, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e2nd", e2nd, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e4", e4, _branches, _setStatus);
  utils::setAddress(_tree, _name, "time", time, _branches, _setStatus);
  utils::setAddress(_tree, _name, "timeSpan", timeSpan, _branches, _setStatus);
  utils::setAddress(_tree, _name, "trackIso", trackIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mipEnergy", mipEnergy, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mipChi2", mipChi2, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mipSlope", mipSlope, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mipIntercept", mipIntercept, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mipNhits", mipNhits, _branches, _setStatus);
}

void
panda::SuperCluster::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Element::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "rawPt", size, 'F', rawPt, _branches);
  utils::book(_tree, _name, "eta", size, 'F', eta, _branches);
  utils::book(_tree, _name, "phi", size, 'F', phi, _branches);
  utils::book(_tree, _name, "sieie", size, 'F', sieie, _branches);
  utils::book(_tree, _name, "sipip", size, 'F', sipip, _branches);
  utils::book(_tree, _name, "e2e9", size, 'F', e2e9, _branches);
  utils::book(_tree, _name, "emax", size, 'F', emax, _branches);
  utils::book(_tree, _name, "e2nd", size, 'F', e2nd, _branches);
  utils::book(_tree, _name, "e4", size, 'F', e4, _branches);
  utils::book(_tree, _name, "time", size, 'F', time, _branches);
  utils::book(_tree, _name, "timeSpan", size, 'F', timeSpan, _branches);
  utils::book(_tree, _name, "trackIso", size, 'F', trackIso, _branches);
  utils::book(_tree, _name, "mipEnergy", size, 'F', mipEnergy, _branches);
  utils::book(_tree, _name, "mipChi2", size, 'F', mipChi2, _branches);
  utils::book(_tree, _name, "mipSlope", size, 'F', mipSlope, _branches);
  utils::book(_tree, _name, "mipIntercept", size, 'F', mipIntercept, _branches);
  utils::book(_tree, _name, "mipNhits", size, 'F', mipNhits, _branches);
}

void
panda::SuperCluster::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Element::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "rawPt");
  utils::resetAddress(_tree, _name, "eta");
  utils::resetAddress(_tree, _name, "phi");
  utils::resetAddress(_tree, _name, "sieie");
  utils::resetAddress(_tree, _name, "sipip");
  utils::resetAddress(_tree, _name, "e2e9");
  utils::resetAddress(_tree, _name, "emax");
  utils::resetAddress(_tree, _name, "e2nd");
  utils::resetAddress(_tree, _name, "e4");
  utils::resetAddress(_tree, _name, "time");
  utils::resetAddress(_tree, _name, "timeSpan");
  utils::resetAddress(_tree, _name, "trackIso");
  utils::resetAddress(_tree, _name, "mipEnergy");
  utils::resetAddress(_tree, _name, "mipChi2");
  utils::resetAddress(_tree, _name, "mipSlope");
  utils::resetAddress(_tree, _name, "mipIntercept");
  utils::resetAddress(_tree, _name, "mipNhits");
}

void
panda::SuperCluster::datastore::resizeVectors_(UInt_t _size)
{
  Element::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::SuperCluster::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return SuperCluster::getListOfBranches().fullNames(_name);
}

panda::SuperCluster::SuperCluster(char const* _name/* = ""*/) :
  Element(new SuperClusterArray(1, _name)),
  rawPt(gStore.getData(this).rawPt[0]),
  eta(gStore.getData(this).eta[0]),
  phi(gStore.getData(this).phi[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  e2e9(gStore.getData(this).e2e9[0]),
  emax(gStore.getData(this).emax[0]),
  e2nd(gStore.getData(this).e2nd[0]),
  e4(gStore.getData(this).e4[0]),
  time(gStore.getData(this).time[0]),
  timeSpan(gStore.getData(this).timeSpan[0]),
  trackIso(gStore.getData(this).trackIso[0]),
  mipEnergy(gStore.getData(this).mipEnergy[0]),
  mipChi2(gStore.getData(this).mipChi2[0]),
  mipSlope(gStore.getData(this).mipSlope[0]),
  mipIntercept(gStore.getData(this).mipIntercept[0]),
  mipNhits(gStore.getData(this).mipNhits[0])
{
}

panda::SuperCluster::SuperCluster(SuperCluster const& _src) :
  Element(new SuperClusterArray(1, gStore.getName(&_src))),
  rawPt(gStore.getData(this).rawPt[0]),
  eta(gStore.getData(this).eta[0]),
  phi(gStore.getData(this).phi[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  e2e9(gStore.getData(this).e2e9[0]),
  emax(gStore.getData(this).emax[0]),
  e2nd(gStore.getData(this).e2nd[0]),
  e4(gStore.getData(this).e4[0]),
  time(gStore.getData(this).time[0]),
  timeSpan(gStore.getData(this).timeSpan[0]),
  trackIso(gStore.getData(this).trackIso[0]),
  mipEnergy(gStore.getData(this).mipEnergy[0]),
  mipChi2(gStore.getData(this).mipChi2[0]),
  mipSlope(gStore.getData(this).mipSlope[0]),
  mipIntercept(gStore.getData(this).mipIntercept[0]),
  mipNhits(gStore.getData(this).mipNhits[0])
{
  Element::operator=(_src);

  rawPt = _src.rawPt;
  eta = _src.eta;
  phi = _src.phi;
  sieie = _src.sieie;
  sipip = _src.sipip;
  e2e9 = _src.e2e9;
  emax = _src.emax;
  e2nd = _src.e2nd;
  e4 = _src.e4;
  time = _src.time;
  timeSpan = _src.timeSpan;
  trackIso = _src.trackIso;
  mipEnergy = _src.mipEnergy;
  mipChi2 = _src.mipChi2;
  mipSlope = _src.mipSlope;
  mipIntercept = _src.mipIntercept;
  mipNhits = _src.mipNhits;
}

panda::SuperCluster::SuperCluster(datastore& _data, UInt_t _idx) :
  Element(_data, _idx),
  rawPt(_data.rawPt[_idx]),
  eta(_data.eta[_idx]),
  phi(_data.phi[_idx]),
  sieie(_data.sieie[_idx]),
  sipip(_data.sipip[_idx]),
  e2e9(_data.e2e9[_idx]),
  emax(_data.emax[_idx]),
  e2nd(_data.e2nd[_idx]),
  e4(_data.e4[_idx]),
  time(_data.time[_idx]),
  timeSpan(_data.timeSpan[_idx]),
  trackIso(_data.trackIso[_idx]),
  mipEnergy(_data.mipEnergy[_idx]),
  mipChi2(_data.mipChi2[_idx]),
  mipSlope(_data.mipSlope[_idx]),
  mipIntercept(_data.mipIntercept[_idx]),
  mipNhits(_data.mipNhits[_idx])
{
}

panda::SuperCluster::SuperCluster(ArrayBase* _array) :
  Element(_array),
  rawPt(gStore.getData(this).rawPt[0]),
  eta(gStore.getData(this).eta[0]),
  phi(gStore.getData(this).phi[0]),
  sieie(gStore.getData(this).sieie[0]),
  sipip(gStore.getData(this).sipip[0]),
  e2e9(gStore.getData(this).e2e9[0]),
  emax(gStore.getData(this).emax[0]),
  e2nd(gStore.getData(this).e2nd[0]),
  e4(gStore.getData(this).e4[0]),
  time(gStore.getData(this).time[0]),
  timeSpan(gStore.getData(this).timeSpan[0]),
  trackIso(gStore.getData(this).trackIso[0]),
  mipEnergy(gStore.getData(this).mipEnergy[0]),
  mipChi2(gStore.getData(this).mipChi2[0]),
  mipSlope(gStore.getData(this).mipSlope[0]),
  mipIntercept(gStore.getData(this).mipIntercept[0]),
  mipNhits(gStore.getData(this).mipNhits[0])
{
}

panda::SuperCluster::~SuperCluster()
{
  destructor();
  gStore.free(this);
}

void
panda::SuperCluster::destructor()
{
  /* BEGIN CUSTOM SuperCluster.cc.destructor */
  /* END CUSTOM */

  Element::destructor();
}

panda::SuperCluster&
panda::SuperCluster::operator=(SuperCluster const& _src)
{
  rawPt = _src.rawPt;
  eta = _src.eta;
  phi = _src.phi;
  sieie = _src.sieie;
  sipip = _src.sipip;
  e2e9 = _src.e2e9;
  emax = _src.emax;
  e2nd = _src.e2nd;
  e4 = _src.e4;
  time = _src.time;
  timeSpan = _src.timeSpan;
  trackIso = _src.trackIso;
  mipEnergy = _src.mipEnergy;
  mipChi2 = _src.mipChi2;
  mipSlope = _src.mipSlope;
  mipIntercept = _src.mipIntercept;
  mipNhits = _src.mipNhits;

  return *this;
}

void
panda::SuperCluster::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  utils::setAddress(_tree, _name, "rawPt", &rawPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "eta", &eta, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phi", &phi, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sieie", &sieie, _branches, _setStatus);
  utils::setAddress(_tree, _name, "sipip", &sipip, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e2e9", &e2e9, _branches, _setStatus);
  utils::setAddress(_tree, _name, "emax", &emax, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e2nd", &e2nd, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e4", &e4, _branches, _setStatus);
  utils::setAddress(_tree, _name, "time", &time, _branches, _setStatus);
  utils::setAddress(_tree, _name, "timeSpan", &timeSpan, _branches, _setStatus);
  utils::setAddress(_tree, _name, "trackIso", &trackIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mipEnergy", &mipEnergy, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mipChi2", &mipChi2, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mipSlope", &mipSlope, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mipIntercept", &mipIntercept, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mipNhits", &mipNhits, _branches, _setStatus);
}

void
panda::SuperCluster::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  utils::book(_tree, _name, "rawPt", "", 'F', &rawPt, _branches);
  utils::book(_tree, _name, "eta", "", 'F', &eta, _branches);
  utils::book(_tree, _name, "phi", "", 'F', &phi, _branches);
  utils::book(_tree, _name, "sieie", "", 'F', &sieie, _branches);
  utils::book(_tree, _name, "sipip", "", 'F', &sipip, _branches);
  utils::book(_tree, _name, "e2e9", "", 'F', &e2e9, _branches);
  utils::book(_tree, _name, "emax", "", 'F', &emax, _branches);
  utils::book(_tree, _name, "e2nd", "", 'F', &e2nd, _branches);
  utils::book(_tree, _name, "e4", "", 'F', &e4, _branches);
  utils::book(_tree, _name, "time", "", 'F', &time, _branches);
  utils::book(_tree, _name, "timeSpan", "", 'F', &timeSpan, _branches);
  utils::book(_tree, _name, "trackIso", "", 'F', &trackIso, _branches);
  utils::book(_tree, _name, "mipEnergy", "", 'F', &mipEnergy, _branches);
  utils::book(_tree, _name, "mipChi2", "", 'F', &mipChi2, _branches);
  utils::book(_tree, _name, "mipSlope", "", 'F', &mipSlope, _branches);
  utils::book(_tree, _name, "mipIntercept", "", 'F', &mipIntercept, _branches);
  utils::book(_tree, _name, "mipNhits", "", 'F', &mipNhits, _branches);
}

void
panda::SuperCluster::doInit_()
{
  rawPt = 0.;
  eta = 0.;
  phi = 0.;
  sieie = 0.;
  sipip = 0.;
  e2e9 = 0.;
  emax = 0.;
  e2nd = 0.;
  e4 = 0.;
  time = 0.;
  timeSpan = 0.;
  trackIso = 0.;
  mipEnergy = 0.;
  mipChi2 = 0.;
  mipSlope = 0.;
  mipIntercept = 0.;
  mipNhits = 0.;

  /* BEGIN CUSTOM SuperCluster.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::SuperCluster::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM SuperCluster.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::SuperCluster::dump(std::ostream& _out/* = std::cout*/) const
{
  _out << "rawPt = " << rawPt << std::endl;
  _out << "eta = " << eta << std::endl;
  _out << "phi = " << phi << std::endl;
  _out << "sieie = " << sieie << std::endl;
  _out << "sipip = " << sipip << std::endl;
  _out << "e2e9 = " << e2e9 << std::endl;
  _out << "emax = " << emax << std::endl;
  _out << "e2nd = " << e2nd << std::endl;
  _out << "e4 = " << e4 << std::endl;
  _out << "time = " << time << std::endl;
  _out << "timeSpan = " << timeSpan << std::endl;
  _out << "trackIso = " << trackIso << std::endl;
  _out << "mipEnergy = " << mipEnergy << std::endl;
  _out << "mipChi2 = " << mipChi2 << std::endl;
  _out << "mipSlope = " << mipSlope << std::endl;
  _out << "mipIntercept = " << mipIntercept << std::endl;
  _out << "mipNhits = " << mipNhits << std::endl;
}

/* BEGIN CUSTOM SuperCluster.cc.global */
/* END CUSTOM */
