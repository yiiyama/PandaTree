#include "../interface/CorrectedSecondaryVertex.h"

/*static*/
panda::utils::BranchList
panda::CorrectedSecondaryVertex::getListOfBranches()
{
  utils::BranchList blist;
  blist += SecondaryVertex::getListOfBranches();
  blist += {"r", "rawPt", "rawEta", "rawPhi", "rawMass", "iPV", "drPV", "dzPV", "q", "chIso", "nhIso", "phIso"};
  return blist;
}

void
panda::CorrectedSecondaryVertex::datastore::allocate(UInt_t _nmax)
{
  SecondaryVertex::datastore::allocate(_nmax);

  r = new Float_t[nmax_];
  rawPt = new Float_t[nmax_];
  rawEta = new Float_t[nmax_];
  rawPhi = new Float_t[nmax_];
  rawMass = new Float_t[nmax_];
  iPV = new Int_t[nmax_];
  drPV = new Float_t[nmax_];
  dzPV = new Float_t[nmax_];
  q = new Short_t[nmax_];
  chIso = new Float_t[nmax_];
  nhIso = new Float_t[nmax_];
  phIso = new Float_t[nmax_];
}

void
panda::CorrectedSecondaryVertex::datastore::deallocate()
{
  SecondaryVertex::datastore::deallocate();

  delete [] r;
  r = 0;
  delete [] rawPt;
  rawPt = 0;
  delete [] rawEta;
  rawEta = 0;
  delete [] rawPhi;
  rawPhi = 0;
  delete [] rawMass;
  rawMass = 0;
  delete [] iPV;
  iPV = 0;
  delete [] drPV;
  drPV = 0;
  delete [] dzPV;
  dzPV = 0;
  delete [] q;
  q = 0;
  delete [] chIso;
  chIso = 0;
  delete [] nhIso;
  nhIso = 0;
  delete [] phIso;
  phIso = 0;
}

void
panda::CorrectedSecondaryVertex::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  SecondaryVertex::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "r", _branches);
  utils::setStatus(_tree, _name, "rawPt", _branches);
  utils::setStatus(_tree, _name, "rawEta", _branches);
  utils::setStatus(_tree, _name, "rawPhi", _branches);
  utils::setStatus(_tree, _name, "rawMass", _branches);
  utils::setStatus(_tree, _name, "iPV", _branches);
  utils::setStatus(_tree, _name, "drPV", _branches);
  utils::setStatus(_tree, _name, "dzPV", _branches);
  utils::setStatus(_tree, _name, "q", _branches);
  utils::setStatus(_tree, _name, "chIso", _branches);
  utils::setStatus(_tree, _name, "nhIso", _branches);
  utils::setStatus(_tree, _name, "phIso", _branches);
}

panda::utils::BranchList
panda::CorrectedSecondaryVertex::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(SecondaryVertex::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "r"));
  blist.push_back(utils::getStatus(_tree, _name, "rawPt"));
  blist.push_back(utils::getStatus(_tree, _name, "rawEta"));
  blist.push_back(utils::getStatus(_tree, _name, "rawPhi"));
  blist.push_back(utils::getStatus(_tree, _name, "rawMass"));
  blist.push_back(utils::getStatus(_tree, _name, "iPV"));
  blist.push_back(utils::getStatus(_tree, _name, "drPV"));
  blist.push_back(utils::getStatus(_tree, _name, "dzPV"));
  blist.push_back(utils::getStatus(_tree, _name, "q"));
  blist.push_back(utils::getStatus(_tree, _name, "chIso"));
  blist.push_back(utils::getStatus(_tree, _name, "nhIso"));
  blist.push_back(utils::getStatus(_tree, _name, "phIso"));

  return blist;
}

void
panda::CorrectedSecondaryVertex::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  SecondaryVertex::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "r", r, _branches, _setStatus);
  utils::setAddress(_tree, _name, "rawPt", rawPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "rawEta", rawEta, _branches, _setStatus);
  utils::setAddress(_tree, _name, "rawPhi", rawPhi, _branches, _setStatus);
  utils::setAddress(_tree, _name, "rawMass", rawMass, _branches, _setStatus);
  utils::setAddress(_tree, _name, "iPV", iPV, _branches, _setStatus);
  utils::setAddress(_tree, _name, "drPV", drPV, _branches, _setStatus);
  utils::setAddress(_tree, _name, "dzPV", dzPV, _branches, _setStatus);
  utils::setAddress(_tree, _name, "q", q, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chIso", chIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhIso", nhIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phIso", phIso, _branches, _setStatus);
}

void
panda::CorrectedSecondaryVertex::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  SecondaryVertex::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "r", size, 'F', r, _branches);
  utils::book(_tree, _name, "rawPt", size, 'F', rawPt, _branches);
  utils::book(_tree, _name, "rawEta", size, 'F', rawEta, _branches);
  utils::book(_tree, _name, "rawPhi", size, 'F', rawPhi, _branches);
  utils::book(_tree, _name, "rawMass", size, 'F', rawMass, _branches);
  utils::book(_tree, _name, "iPV", size, 'I', iPV, _branches);
  utils::book(_tree, _name, "drPV", size, 'F', drPV, _branches);
  utils::book(_tree, _name, "dzPV", size, 'F', dzPV, _branches);
  utils::book(_tree, _name, "q", size, 'S', q, _branches);
  utils::book(_tree, _name, "chIso", size, 'F', chIso, _branches);
  utils::book(_tree, _name, "nhIso", size, 'F', nhIso, _branches);
  utils::book(_tree, _name, "phIso", size, 'F', phIso, _branches);
}

void
panda::CorrectedSecondaryVertex::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  SecondaryVertex::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "r");
  utils::resetAddress(_tree, _name, "rawPt");
  utils::resetAddress(_tree, _name, "rawEta");
  utils::resetAddress(_tree, _name, "rawPhi");
  utils::resetAddress(_tree, _name, "rawMass");
  utils::resetAddress(_tree, _name, "iPV");
  utils::resetAddress(_tree, _name, "drPV");
  utils::resetAddress(_tree, _name, "dzPV");
  utils::resetAddress(_tree, _name, "q");
  utils::resetAddress(_tree, _name, "chIso");
  utils::resetAddress(_tree, _name, "nhIso");
  utils::resetAddress(_tree, _name, "phIso");
}

void
panda::CorrectedSecondaryVertex::datastore::resizeVectors_(UInt_t _size)
{
  SecondaryVertex::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::CorrectedSecondaryVertex::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return CorrectedSecondaryVertex::getListOfBranches().fullNames(_name);
}

panda::CorrectedSecondaryVertex::CorrectedSecondaryVertex(char const* _name/* = ""*/) :
  SecondaryVertex(new CorrectedSecondaryVertexArray(1, _name)),
  r(gStore.getData(this).r[0]),
  rawPt(gStore.getData(this).rawPt[0]),
  rawEta(gStore.getData(this).rawEta[0]),
  rawPhi(gStore.getData(this).rawPhi[0]),
  rawMass(gStore.getData(this).rawMass[0]),
  iPV(gStore.getData(this).iPV[0]),
  drPV(gStore.getData(this).drPV[0]),
  dzPV(gStore.getData(this).dzPV[0]),
  q(gStore.getData(this).q[0]),
  chIso(gStore.getData(this).chIso[0]),
  nhIso(gStore.getData(this).nhIso[0]),
  phIso(gStore.getData(this).phIso[0])
{
}

panda::CorrectedSecondaryVertex::CorrectedSecondaryVertex(CorrectedSecondaryVertex const& _src) :
  SecondaryVertex(new CorrectedSecondaryVertexArray(1, _src.getName())),
  r(gStore.getData(this).r[0]),
  rawPt(gStore.getData(this).rawPt[0]),
  rawEta(gStore.getData(this).rawEta[0]),
  rawPhi(gStore.getData(this).rawPhi[0]),
  rawMass(gStore.getData(this).rawMass[0]),
  iPV(gStore.getData(this).iPV[0]),
  drPV(gStore.getData(this).drPV[0]),
  dzPV(gStore.getData(this).dzPV[0]),
  q(gStore.getData(this).q[0]),
  chIso(gStore.getData(this).chIso[0]),
  nhIso(gStore.getData(this).nhIso[0]),
  phIso(gStore.getData(this).phIso[0])
{
  operator=(_src);
}

panda::CorrectedSecondaryVertex::CorrectedSecondaryVertex(datastore& _data, UInt_t _idx) :
  SecondaryVertex(_data, _idx),
  r(_data.r[_idx]),
  rawPt(_data.rawPt[_idx]),
  rawEta(_data.rawEta[_idx]),
  rawPhi(_data.rawPhi[_idx]),
  rawMass(_data.rawMass[_idx]),
  iPV(_data.iPV[_idx]),
  drPV(_data.drPV[_idx]),
  dzPV(_data.dzPV[_idx]),
  q(_data.q[_idx]),
  chIso(_data.chIso[_idx]),
  nhIso(_data.nhIso[_idx]),
  phIso(_data.phIso[_idx])
{
}

panda::CorrectedSecondaryVertex::CorrectedSecondaryVertex(ArrayBase* _array) :
  SecondaryVertex(_array),
  r(gStore.getData(this).r[0]),
  rawPt(gStore.getData(this).rawPt[0]),
  rawEta(gStore.getData(this).rawEta[0]),
  rawPhi(gStore.getData(this).rawPhi[0]),
  rawMass(gStore.getData(this).rawMass[0]),
  iPV(gStore.getData(this).iPV[0]),
  drPV(gStore.getData(this).drPV[0]),
  dzPV(gStore.getData(this).dzPV[0]),
  q(gStore.getData(this).q[0]),
  chIso(gStore.getData(this).chIso[0]),
  nhIso(gStore.getData(this).nhIso[0]),
  phIso(gStore.getData(this).phIso[0])
{
}

panda::CorrectedSecondaryVertex::~CorrectedSecondaryVertex()
{
  destructor();
}

void
panda::CorrectedSecondaryVertex::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM CorrectedSecondaryVertex.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    SecondaryVertex::destructor(kTRUE);
}

panda::CorrectedSecondaryVertex&
panda::CorrectedSecondaryVertex::operator=(CorrectedSecondaryVertex const& _src)
{
  SecondaryVertex::operator=(_src);

  r = _src.r;
  rawPt = _src.rawPt;
  rawEta = _src.rawEta;
  rawPhi = _src.rawPhi;
  rawMass = _src.rawMass;
  iPV = _src.iPV;
  drPV = _src.drPV;
  dzPV = _src.dzPV;
  q = _src.q;
  chIso = _src.chIso;
  nhIso = _src.nhIso;
  phIso = _src.phIso;

  /* BEGIN CUSTOM CorrectedSecondaryVertex.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
panda::CorrectedSecondaryVertex::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  SecondaryVertex::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "r", "", 'F', &r, _branches);
  utils::book(_tree, _name, "rawPt", "", 'F', &rawPt, _branches);
  utils::book(_tree, _name, "rawEta", "", 'F', &rawEta, _branches);
  utils::book(_tree, _name, "rawPhi", "", 'F', &rawPhi, _branches);
  utils::book(_tree, _name, "rawMass", "", 'F', &rawMass, _branches);
  utils::book(_tree, _name, "iPV", "", 'I', &iPV, _branches);
  utils::book(_tree, _name, "drPV", "", 'F', &drPV, _branches);
  utils::book(_tree, _name, "dzPV", "", 'F', &dzPV, _branches);
  utils::book(_tree, _name, "q", "", 'S', &q, _branches);
  utils::book(_tree, _name, "chIso", "", 'F', &chIso, _branches);
  utils::book(_tree, _name, "nhIso", "", 'F', &nhIso, _branches);
  utils::book(_tree, _name, "phIso", "", 'F', &phIso, _branches);
}

void
panda::CorrectedSecondaryVertex::doInit_()
{
  SecondaryVertex::doInit_();

  r = 0.;
  rawPt = 0.;
  rawEta = 0.;
  rawPhi = 0.;
  rawMass = 0.;
  iPV = 0;
  drPV = 0.;
  dzPV = 0.;
  q = 0;
  chIso = 0.;
  nhIso = 0.;
  phIso = 0.;

  /* BEGIN CUSTOM CorrectedSecondaryVertex.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::CorrectedSecondaryVertex::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM CorrectedSecondaryVertex.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::CorrectedSecondaryVertex::dump(std::ostream& _out/* = std::cout*/) const
{
  SecondaryVertex::dump(_out);

  _out << "r = " << r << std::endl;
  _out << "rawPt = " << rawPt << std::endl;
  _out << "rawEta = " << rawEta << std::endl;
  _out << "rawPhi = " << rawPhi << std::endl;
  _out << "rawMass = " << rawMass << std::endl;
  _out << "iPV = " << iPV << std::endl;
  _out << "drPV = " << drPV << std::endl;
  _out << "dzPV = " << dzPV << std::endl;
  _out << "q = " << q << std::endl;
  _out << "chIso = " << chIso << std::endl;
  _out << "nhIso = " << nhIso << std::endl;
  _out << "phIso = " << phIso << std::endl;
}


/* BEGIN CUSTOM CorrectedSecondaryVertex.cc.global */
#include "../interface/PFCandBase.h"

panda::CorrectedSecondaryVertex&
panda::CorrectedSecondaryVertex::operator=(SecondaryVertex const& _rhs)
{
  SecondaryVertex::operator=(_rhs);
  
  r = std::sqrt(_rhs.x * _rhs.x + _rhs.y * _rhs.y);
  rawPt = _rhs.pt();
  rawEta = _rhs.eta();
  rawPhi = _rhs.phi();
  rawMass = _rhs.m();

  TLorentzVector p;
  
  for (auto&& trackref : _rhs.daughters) {
    auto& track(*trackref);
    q += track.q();

    double pt(track.pt());
    double zoff(std::abs(z - track.vertex->z + track.track->dz()));
    double phioff(zoff * pt / track.pz() / (pt / 3.8 / 2.9979e-3) * (-track.q()));

    TLorentzVector ptrack;
    ptrack.SetPtEtaPhiM(pt, track.eta(), track.phi() + phioff, track.m());
    p += ptrack;
  }

  pt_ = p.Pt();
  eta_ = p.Eta();
  phi_ = p.Phi();
  mass_ = p.M();

  return *this;
}

void
panda::CorrectedSecondaryVertex::setPV(VertexCollection const& _vertices)
{
  iPV = -1;
  drPV = 0.;
  dzPV = 0.;

  auto pos(position());
  auto unitP(p4().Vect().Unit());

  double minPVD(-1.);
  TVector3 dxTimesP;

  for (unsigned iV(0); iV != _vertices.size(); ++iV) {
    auto& pv(_vertices[iV]);

    auto fromPV(pos - pv.position());
    auto cross(fromPV.Cross(unitP));
    double pvd(cross.Mag());
    if (minPVD < 0. || pvd < minPVD) {
      iPV = iV;
      minPVD = pvd;
      dxTimesP = cross;
    }
  }

  if (iPV >= 0) {
    auto pca(unitP.Cross(dxTimesP));
    drPV = pca.Perp();
    dzPV = pca.Z();
  }
}
/* END CUSTOM */
