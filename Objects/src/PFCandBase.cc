#include "../interface/PFCandBase.h"

TString panda::PFCandBase::PTypeName[] = {
  "hp",
  "hm",
  "ep",
  "em",
  "mup",
  "mum",
  "gamma",
  "h0",
  "h_HF",
  "egamma_HF",
  "Xp",
  "Xm",
  "X"
};

/*static*/
int const panda::PFCandBase::q_[nPTypes] = {1, -1, 1, -1, 1, -1, 0, 0, 0, 0, 1, -1, 0};
/*static*/
int const panda::PFCandBase::pdgId_[nPTypes] = {211, -211, -11, 11, -13, 13, 22, 130, 1, 2, 0, 0, 0};

/*static*/
panda::utils::BranchList
panda::PFCandBase::getListOfBranches()
{
  utils::BranchList blist;
  blist += Particle::getListOfBranches();
  blist += {"ptype", "hCalFrac"};
  return blist;
}

void
panda::PFCandBase::datastore::allocate(UInt_t _nmax)
{
  Particle::datastore::allocate(_nmax);

  ptype = new UChar_t[nmax_];
  vertex_ = new Short_t[nmax_];
  track_ = new Short_t[nmax_];
  hCalFrac = new Float_t[nmax_];
}

void
panda::PFCandBase::datastore::deallocate()
{
  Particle::datastore::deallocate();

  delete [] ptype;
  ptype = 0;
  delete [] vertex_;
  vertex_ = 0;
  delete [] track_;
  track_ = 0;
  delete [] hCalFrac;
  hCalFrac = 0;
}

void
panda::PFCandBase::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Particle::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "ptype", _branches);
  utils::setStatus(_tree, _name, "hCalFrac", _branches);
}

panda::utils::BranchList
panda::PFCandBase::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Particle::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "ptype"));
  blist.push_back(utils::getStatus(_tree, _name, "hCalFrac"));

  return blist;
}

void
panda::PFCandBase::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "ptype", ptype, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hCalFrac", hCalFrac, _branches, _setStatus);
}

void
panda::PFCandBase::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Particle::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "ptype", size, 'b', ptype, _branches);
  utils::book(_tree, _name, "hCalFrac", size, 'F', hCalFrac, _branches);
}

void
panda::PFCandBase::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Particle::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "ptype");
  utils::resetAddress(_tree, _name, "hCalFrac");
}

void
panda::PFCandBase::datastore::resizeVectors_(UInt_t _size)
{
  Particle::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::PFCandBase::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return PFCandBase::getListOfBranches().fullNames(_name);
}

panda::PFCandBase::PFCandBase(datastore& _data, UInt_t _idx) :
  Particle(_data, _idx),
  ptype(_data.ptype[_idx]),
  vertex(_data.vertexContainer_, _data.vertex_[_idx]),
  track(_data.trackContainer_, _data.track_[_idx]),
  hCalFrac(_data.hCalFrac[_idx])
{
}

panda::PFCandBase::PFCandBase(ArrayBase* _array) :
  Particle(_array),
  ptype(gStore.getData(this).ptype[0]),
  vertex(gStore.getData(this).vertexContainer_, gStore.getData(this).vertex_[0]),
  track(gStore.getData(this).trackContainer_, gStore.getData(this).track_[0]),
  hCalFrac(gStore.getData(this).hCalFrac[0])
{
}

panda::PFCandBase::~PFCandBase()
{
  destructor();
}

void
panda::PFCandBase::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM PFCandBase.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    Particle::destructor(kTRUE);
}

panda::PFCandBase&
panda::PFCandBase::operator=(PFCandBase const& _src)
{
  Particle::operator=(_src);

  ptype = _src.ptype;
  vertex = _src.vertex;
  track = _src.track;
  hCalFrac = _src.hCalFrac;

  /* BEGIN CUSTOM PFCandBase.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
panda::PFCandBase::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  Particle::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "ptype", "", 'b', &ptype, _branches);
  utils::book(_tree, _name, "hCalFrac", "", 'F', &hCalFrac, _branches);
}

void
panda::PFCandBase::doInit_()
{
  Particle::doInit_();

  ptype = 0;
  vertex.init();
  track.init();
  hCalFrac = 0.;

  /* BEGIN CUSTOM PFCandBase.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::PFCandBase::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM PFCandBase.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::PFCandBase::dump(std::ostream& _out/* = std::cout*/) const
{
  Particle::dump(_out);

  _out << "ptype = " << static_cast<const UInt_t>(ptype) << std::endl;
  _out << "vertex = " << vertex << std::endl;
  _out << "track = " << track << std::endl;
  _out << "hCalFrac = " << hCalFrac << std::endl;
}


/* BEGIN CUSTOM PFCandBase.cc.global */
TVector3
panda::PFCandBase::pca() const
{
  if (!vertex.isValid() || !track.isValid())
    return TVector3();

  double trkPhi(phi() + track->dPhi());

  // dir(pca - pv) is perpendicular to trkPhi by definition
  // -> relation between pca and pv simplifies

  return TVector3(vertex->x - track->dxy() * std::sin(trkPhi), vertex->y + track->dxy() * std::cos(trkPhi), vertex->z + track->dz());
}

double
panda::PFCandBase::dxy(TVector3 const& point) const
{
  if (!vertex.isValid() || !track.isValid())
    return 0.;

  auto ref(pca());

  double trkPhi(phi() + track->dPhi());

  return -(ref.X() - point.X()) * std::sin(trkPhi) + (ref.Y() - point.Y()) * std::cos(trkPhi);
}

double
panda::PFCandBase::dz(TVector3 const& point) const
{
  if (!vertex.isValid() || !track.isValid())
    return 0.;

  auto ref(pca());

  double trkPhi(phi() + track->dPhi());

  return (ref.Z() - point.Z()) - ((ref.X() - point.X()) * std::cos(trkPhi) + (ref.Y() - point.Y()) * std::sin(trkPhi)) * pz() / pt();
}

/* END CUSTOM */
