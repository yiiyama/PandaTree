#include "../interface/XPhoton.h"

/*static*/
double panda::XPhoton::chIsoCuts[2][2][4]{{{3.32, 1.37, 0.76, 5.0}, {1.97, 1.10, 0.56, 5.0}},                  {{1.295, 0.441, 0.202, 5.0}, {1.011, 0.442, 0.034, 5.0}}};
/*static*/
double panda::XPhoton::nhIsoCuts[2][2][4]{{{1.92, 1.06, 0.97, 100000.}, {11.86, 2.69, 2.09, 100000.}},         {{10.910, 2.725, 0.264, 100000.}, {5.931, 1.715, 0.586, 100000.}}};
/*static*/
double panda::XPhoton::phIsoCuts[2][2][4]{{{0.81, 0.28, 0.08, 2.75}, {0.83, 0.39, 0.16, 2.00}},                {{3.630, 2.571, 2.362, 2.75}, {6.641, 3.863, 2.617, 2.00}}};
/*static*/
double panda::XPhoton::sieieCuts[2][2][4]{{{0.0102, 0.0102, 0.0100, 0.0105}, {0.0274, 0.0268, 0.0268, 0.028}}, {{0.01031, 0.01022, 0.00994, 0.0105}, {0.03013, 0.03001, 0.03000, 0.028}}};
/*static*/
double panda::XPhoton::hOverECuts[2][2][4]{{{0.05, 0.05, 0.05, 0.05}, {0.05, 0.05, 0.05, 0.05}},               {{0.0597, 0.0396, 0.0269, 0.05}, {0.0481, 0.0219, 0.0213, 0.05}}};

/*static*/
panda::utils::BranchList
panda::XPhoton::getListOfBranches()
{
  utils::BranchList blist;
  blist += Photon::getListOfBranches();
  blist += {"scEta", "scRawPt", "chIsoS15", "nhIsoS15", "phIsoS15", "chIsoZG", "nhIsoZG", "phIsoZG", "e4", "isEB", "loose15", "medium15", "tight15", "mediumZG", "mediumZGMax", "matchedGenId"};
  return blist;
}

void
panda::XPhoton::datastore::allocate(UInt_t _nmax)
{
  Photon::datastore::allocate(_nmax);

  scEta = new Float_t[nmax_];
  scRawPt = new Float_t[nmax_];
  chIsoS15 = new Float_t[nmax_];
  nhIsoS15 = new Float_t[nmax_];
  phIsoS15 = new Float_t[nmax_];
  chIsoZG = new Float_t[nmax_];
  nhIsoZG = new Float_t[nmax_];
  phIsoZG = new Float_t[nmax_];
  e4 = new Float_t[nmax_];
  isEB = new Bool_t[nmax_];
  loose15 = new Bool_t[nmax_];
  medium15 = new Bool_t[nmax_];
  tight15 = new Bool_t[nmax_];
  mediumZG = new Bool_t[nmax_];
  mediumZGMax = new Bool_t[nmax_];
  matchedGenId = new Int_t[nmax_];
}

void
panda::XPhoton::datastore::deallocate()
{
  Photon::datastore::deallocate();

  delete [] scEta;
  scEta = 0;
  delete [] scRawPt;
  scRawPt = 0;
  delete [] chIsoS15;
  chIsoS15 = 0;
  delete [] nhIsoS15;
  nhIsoS15 = 0;
  delete [] phIsoS15;
  phIsoS15 = 0;
  delete [] chIsoZG;
  chIsoZG = 0;
  delete [] nhIsoZG;
  nhIsoZG = 0;
  delete [] phIsoZG;
  phIsoZG = 0;
  delete [] e4;
  e4 = 0;
  delete [] isEB;
  isEB = 0;
  delete [] loose15;
  loose15 = 0;
  delete [] medium15;
  medium15 = 0;
  delete [] tight15;
  tight15 = 0;
  delete [] mediumZG;
  mediumZG = 0;
  delete [] mediumZGMax;
  mediumZGMax = 0;
  delete [] matchedGenId;
  matchedGenId = 0;
}

void
panda::XPhoton::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Photon::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "scEta", _branches);
  utils::setStatus(_tree, _name, "scRawPt", _branches);
  utils::setStatus(_tree, _name, "chIsoS15", _branches);
  utils::setStatus(_tree, _name, "nhIsoS15", _branches);
  utils::setStatus(_tree, _name, "phIsoS15", _branches);
  utils::setStatus(_tree, _name, "chIsoZG", _branches);
  utils::setStatus(_tree, _name, "nhIsoZG", _branches);
  utils::setStatus(_tree, _name, "phIsoZG", _branches);
  utils::setStatus(_tree, _name, "e4", _branches);
  utils::setStatus(_tree, _name, "isEB", _branches);
  utils::setStatus(_tree, _name, "loose15", _branches);
  utils::setStatus(_tree, _name, "medium15", _branches);
  utils::setStatus(_tree, _name, "tight15", _branches);
  utils::setStatus(_tree, _name, "mediumZG", _branches);
  utils::setStatus(_tree, _name, "mediumZGMax", _branches);
  utils::setStatus(_tree, _name, "matchedGenId", _branches);
}

panda::utils::BranchList
panda::XPhoton::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Photon::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "scEta"));
  blist.push_back(utils::getStatus(_tree, _name, "scRawPt"));
  blist.push_back(utils::getStatus(_tree, _name, "chIsoS15"));
  blist.push_back(utils::getStatus(_tree, _name, "nhIsoS15"));
  blist.push_back(utils::getStatus(_tree, _name, "phIsoS15"));
  blist.push_back(utils::getStatus(_tree, _name, "chIsoZG"));
  blist.push_back(utils::getStatus(_tree, _name, "nhIsoZG"));
  blist.push_back(utils::getStatus(_tree, _name, "phIsoZG"));
  blist.push_back(utils::getStatus(_tree, _name, "e4"));
  blist.push_back(utils::getStatus(_tree, _name, "isEB"));
  blist.push_back(utils::getStatus(_tree, _name, "loose15"));
  blist.push_back(utils::getStatus(_tree, _name, "medium15"));
  blist.push_back(utils::getStatus(_tree, _name, "tight15"));
  blist.push_back(utils::getStatus(_tree, _name, "mediumZG"));
  blist.push_back(utils::getStatus(_tree, _name, "mediumZGMax"));
  blist.push_back(utils::getStatus(_tree, _name, "matchedGenId"));

  return blist;
}

void
panda::XPhoton::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Photon::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "scEta", scEta, _branches, _setStatus);
  utils::setAddress(_tree, _name, "scRawPt", scRawPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chIsoS15", chIsoS15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhIsoS15", nhIsoS15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phIsoS15", phIsoS15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chIsoZG", chIsoZG, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhIsoZG", nhIsoZG, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phIsoZG", phIsoZG, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e4", e4, _branches, _setStatus);
  utils::setAddress(_tree, _name, "isEB", isEB, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose15", loose15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "medium15", medium15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight15", tight15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mediumZG", mediumZG, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mediumZGMax", mediumZGMax, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedGenId", matchedGenId, _branches, _setStatus);
}

void
panda::XPhoton::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Photon::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "scEta", size, 'F', scEta, _branches);
  utils::book(_tree, _name, "scRawPt", size, 'F', scRawPt, _branches);
  utils::book(_tree, _name, "chIsoS15", size, 'F', chIsoS15, _branches);
  utils::book(_tree, _name, "nhIsoS15", size, 'F', nhIsoS15, _branches);
  utils::book(_tree, _name, "phIsoS15", size, 'F', phIsoS15, _branches);
  utils::book(_tree, _name, "chIsoZG", size, 'F', chIsoZG, _branches);
  utils::book(_tree, _name, "nhIsoZG", size, 'F', nhIsoZG, _branches);
  utils::book(_tree, _name, "phIsoZG", size, 'F', phIsoZG, _branches);
  utils::book(_tree, _name, "e4", size, 'F', e4, _branches);
  utils::book(_tree, _name, "isEB", size, 'O', isEB, _branches);
  utils::book(_tree, _name, "loose15", size, 'O', loose15, _branches);
  utils::book(_tree, _name, "medium15", size, 'O', medium15, _branches);
  utils::book(_tree, _name, "tight15", size, 'O', tight15, _branches);
  utils::book(_tree, _name, "mediumZG", size, 'O', mediumZG, _branches);
  utils::book(_tree, _name, "mediumZGMax", size, 'O', mediumZGMax, _branches);
  utils::book(_tree, _name, "matchedGenId", size, 'I', matchedGenId, _branches);
}

void
panda::XPhoton::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Photon::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "scEta");
  utils::resetAddress(_tree, _name, "scRawPt");
  utils::resetAddress(_tree, _name, "chIsoS15");
  utils::resetAddress(_tree, _name, "nhIsoS15");
  utils::resetAddress(_tree, _name, "phIsoS15");
  utils::resetAddress(_tree, _name, "chIsoZG");
  utils::resetAddress(_tree, _name, "nhIsoZG");
  utils::resetAddress(_tree, _name, "phIsoZG");
  utils::resetAddress(_tree, _name, "e4");
  utils::resetAddress(_tree, _name, "isEB");
  utils::resetAddress(_tree, _name, "loose15");
  utils::resetAddress(_tree, _name, "medium15");
  utils::resetAddress(_tree, _name, "tight15");
  utils::resetAddress(_tree, _name, "mediumZG");
  utils::resetAddress(_tree, _name, "mediumZGMax");
  utils::resetAddress(_tree, _name, "matchedGenId");
}

void
panda::XPhoton::datastore::resizeVectors_(UInt_t _size)
{
  Photon::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::XPhoton::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return XPhoton::getListOfBranches().fullNames(_name);
}

panda::XPhoton::XPhoton(char const* _name/* = ""*/) :
  Photon(new XPhotonArray(1, _name)),
  scEta(gStore.getData(this).scEta[0]),
  scRawPt(gStore.getData(this).scRawPt[0]),
  chIsoS15(gStore.getData(this).chIsoS15[0]),
  nhIsoS15(gStore.getData(this).nhIsoS15[0]),
  phIsoS15(gStore.getData(this).phIsoS15[0]),
  chIsoZG(gStore.getData(this).chIsoZG[0]),
  nhIsoZG(gStore.getData(this).nhIsoZG[0]),
  phIsoZG(gStore.getData(this).phIsoZG[0]),
  e4(gStore.getData(this).e4[0]),
  isEB(gStore.getData(this).isEB[0]),
  loose15(gStore.getData(this).loose15[0]),
  medium15(gStore.getData(this).medium15[0]),
  tight15(gStore.getData(this).tight15[0]),
  mediumZG(gStore.getData(this).mediumZG[0]),
  mediumZGMax(gStore.getData(this).mediumZGMax[0]),
  matchedGenId(gStore.getData(this).matchedGenId[0])
{
}

panda::XPhoton::XPhoton(XPhoton const& _src) :
  Photon(new XPhotonArray(1, _src.getName())),
  scEta(gStore.getData(this).scEta[0]),
  scRawPt(gStore.getData(this).scRawPt[0]),
  chIsoS15(gStore.getData(this).chIsoS15[0]),
  nhIsoS15(gStore.getData(this).nhIsoS15[0]),
  phIsoS15(gStore.getData(this).phIsoS15[0]),
  chIsoZG(gStore.getData(this).chIsoZG[0]),
  nhIsoZG(gStore.getData(this).nhIsoZG[0]),
  phIsoZG(gStore.getData(this).phIsoZG[0]),
  e4(gStore.getData(this).e4[0]),
  isEB(gStore.getData(this).isEB[0]),
  loose15(gStore.getData(this).loose15[0]),
  medium15(gStore.getData(this).medium15[0]),
  tight15(gStore.getData(this).tight15[0]),
  mediumZG(gStore.getData(this).mediumZG[0]),
  mediumZGMax(gStore.getData(this).mediumZGMax[0]),
  matchedGenId(gStore.getData(this).matchedGenId[0])
{
  Photon::operator=(_src);

  scEta = _src.scEta;
  scRawPt = _src.scRawPt;
  chIsoS15 = _src.chIsoS15;
  nhIsoS15 = _src.nhIsoS15;
  phIsoS15 = _src.phIsoS15;
  chIsoZG = _src.chIsoZG;
  nhIsoZG = _src.nhIsoZG;
  phIsoZG = _src.phIsoZG;
  e4 = _src.e4;
  isEB = _src.isEB;
  loose15 = _src.loose15;
  medium15 = _src.medium15;
  tight15 = _src.tight15;
  mediumZG = _src.mediumZG;
  mediumZGMax = _src.mediumZGMax;
  matchedGenId = _src.matchedGenId;
}

panda::XPhoton::XPhoton(datastore& _data, UInt_t _idx) :
  Photon(_data, _idx),
  scEta(_data.scEta[_idx]),
  scRawPt(_data.scRawPt[_idx]),
  chIsoS15(_data.chIsoS15[_idx]),
  nhIsoS15(_data.nhIsoS15[_idx]),
  phIsoS15(_data.phIsoS15[_idx]),
  chIsoZG(_data.chIsoZG[_idx]),
  nhIsoZG(_data.nhIsoZG[_idx]),
  phIsoZG(_data.phIsoZG[_idx]),
  e4(_data.e4[_idx]),
  isEB(_data.isEB[_idx]),
  loose15(_data.loose15[_idx]),
  medium15(_data.medium15[_idx]),
  tight15(_data.tight15[_idx]),
  mediumZG(_data.mediumZG[_idx]),
  mediumZGMax(_data.mediumZGMax[_idx]),
  matchedGenId(_data.matchedGenId[_idx])
{
}

panda::XPhoton::XPhoton(ArrayBase* _array) :
  Photon(_array),
  scEta(gStore.getData(this).scEta[0]),
  scRawPt(gStore.getData(this).scRawPt[0]),
  chIsoS15(gStore.getData(this).chIsoS15[0]),
  nhIsoS15(gStore.getData(this).nhIsoS15[0]),
  phIsoS15(gStore.getData(this).phIsoS15[0]),
  chIsoZG(gStore.getData(this).chIsoZG[0]),
  nhIsoZG(gStore.getData(this).nhIsoZG[0]),
  phIsoZG(gStore.getData(this).phIsoZG[0]),
  e4(gStore.getData(this).e4[0]),
  isEB(gStore.getData(this).isEB[0]),
  loose15(gStore.getData(this).loose15[0]),
  medium15(gStore.getData(this).medium15[0]),
  tight15(gStore.getData(this).tight15[0]),
  mediumZG(gStore.getData(this).mediumZG[0]),
  mediumZGMax(gStore.getData(this).mediumZGMax[0]),
  matchedGenId(gStore.getData(this).matchedGenId[0])
{
}

panda::XPhoton::~XPhoton()
{
  destructor();
}

void
panda::XPhoton::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM XPhoton.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    Photon::destructor(kTRUE);
}

panda::XPhoton&
panda::XPhoton::operator=(XPhoton const& _src)
{
  Photon::operator=(_src);

  scEta = _src.scEta;
  scRawPt = _src.scRawPt;
  chIsoS15 = _src.chIsoS15;
  nhIsoS15 = _src.nhIsoS15;
  phIsoS15 = _src.phIsoS15;
  chIsoZG = _src.chIsoZG;
  nhIsoZG = _src.nhIsoZG;
  phIsoZG = _src.phIsoZG;
  e4 = _src.e4;
  isEB = _src.isEB;
  loose15 = _src.loose15;
  medium15 = _src.medium15;
  tight15 = _src.tight15;
  mediumZG = _src.mediumZG;
  mediumZGMax = _src.mediumZGMax;
  matchedGenId = _src.matchedGenId;

  /* BEGIN CUSTOM XPhoton.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
panda::XPhoton::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Photon::doSetAddress_(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "scEta", &scEta, _branches, _setStatus);
  utils::setAddress(_tree, _name, "scRawPt", &scRawPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chIsoS15", &chIsoS15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhIsoS15", &nhIsoS15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phIsoS15", &phIsoS15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chIsoZG", &chIsoZG, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhIsoZG", &nhIsoZG, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phIsoZG", &phIsoZG, _branches, _setStatus);
  utils::setAddress(_tree, _name, "e4", &e4, _branches, _setStatus);
  utils::setAddress(_tree, _name, "isEB", &isEB, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose15", &loose15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "medium15", &medium15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight15", &tight15, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mediumZG", &mediumZG, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mediumZGMax", &mediumZGMax, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedGenId", &matchedGenId, _branches, _setStatus);
}

void
panda::XPhoton::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  Photon::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "scEta", "", 'F', &scEta, _branches);
  utils::book(_tree, _name, "scRawPt", "", 'F', &scRawPt, _branches);
  utils::book(_tree, _name, "chIsoS15", "", 'F', &chIsoS15, _branches);
  utils::book(_tree, _name, "nhIsoS15", "", 'F', &nhIsoS15, _branches);
  utils::book(_tree, _name, "phIsoS15", "", 'F', &phIsoS15, _branches);
  utils::book(_tree, _name, "chIsoZG", "", 'F', &chIsoZG, _branches);
  utils::book(_tree, _name, "nhIsoZG", "", 'F', &nhIsoZG, _branches);
  utils::book(_tree, _name, "phIsoZG", "", 'F', &phIsoZG, _branches);
  utils::book(_tree, _name, "e4", "", 'F', &e4, _branches);
  utils::book(_tree, _name, "isEB", "", 'O', &isEB, _branches);
  utils::book(_tree, _name, "loose15", "", 'O', &loose15, _branches);
  utils::book(_tree, _name, "medium15", "", 'O', &medium15, _branches);
  utils::book(_tree, _name, "tight15", "", 'O', &tight15, _branches);
  utils::book(_tree, _name, "mediumZG", "", 'O', &mediumZG, _branches);
  utils::book(_tree, _name, "mediumZGMax", "", 'O', &mediumZGMax, _branches);
  utils::book(_tree, _name, "matchedGenId", "", 'I', &matchedGenId, _branches);
}

void
panda::XPhoton::doInit_()
{
  Photon::doInit_();

  scEta = 0.;
  scRawPt = 0.;
  chIsoS15 = 0.;
  nhIsoS15 = 0.;
  phIsoS15 = 0.;
  chIsoZG = 0.;
  nhIsoZG = 0.;
  phIsoZG = 0.;
  e4 = 0.;
  isEB = false;
  loose15 = false;
  medium15 = false;
  tight15 = false;
  mediumZG = false;
  mediumZGMax = false;
  matchedGenId = 0;

  /* BEGIN CUSTOM XPhoton.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::XPhoton::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM XPhoton.cc.print */
  if (_level >= 3) {
    XPhoton::dump(_out);
  }
  else if (_level == 2) {
    Photon::print(_out, _level);

    _out << "scEta = " << scEta << std::endl;
    _out << "scRawPt = " << scRawPt << std::endl;
    _out << "chIsoS15 = " << chIsoS15 << std::endl;
    _out << "nhIsoS15 = " << nhIsoS15 << std::endl;
    _out << "phIsoS15 = " << phIsoS15 << std::endl;
    _out << "e4 = " << e4 << std::endl;
    _out << "isEB = " << isEB << std::endl;
  }
  else
    return;
  /* END CUSTOM */
}

void
panda::XPhoton::dump(std::ostream& _out/* = std::cout*/) const
{
  Photon::dump(_out);

  _out << "scEta = " << scEta << std::endl;
  _out << "scRawPt = " << scRawPt << std::endl;
  _out << "chIsoS15 = " << chIsoS15 << std::endl;
  _out << "nhIsoS15 = " << nhIsoS15 << std::endl;
  _out << "phIsoS15 = " << phIsoS15 << std::endl;
  _out << "chIsoZG = " << chIsoZG << std::endl;
  _out << "nhIsoZG = " << nhIsoZG << std::endl;
  _out << "phIsoZG = " << phIsoZG << std::endl;
  _out << "e4 = " << e4 << std::endl;
  _out << "isEB = " << isEB << std::endl;
  _out << "loose15 = " << loose15 << std::endl;
  _out << "medium15 = " << medium15 << std::endl;
  _out << "tight15 = " << tight15 << std::endl;
  _out << "mediumZG = " << mediumZG << std::endl;
  _out << "mediumZGMax = " << mediumZGMax << std::endl;
  _out << "matchedGenId = " << matchedGenId << std::endl;
}


/* BEGIN CUSTOM XPhoton.cc.global */
/* END CUSTOM */
