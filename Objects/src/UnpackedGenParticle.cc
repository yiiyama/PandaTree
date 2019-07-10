#include "../interface/UnpackedGenParticle.h"

/*static*/
panda::utils::BranchList
panda::UnpackedGenParticle::getListOfBranches()
{
  utils::BranchList blist;
  blist += GenParticleBase::getListOfBranches();
  blist += PtEtaPhiMMixin::getListOfBranches();
  return blist;
}

void
panda::UnpackedGenParticle::datastore::allocate(UInt_t _nmax)
{
  GenParticleBase::datastore::allocate(_nmax);

  pt_ = new Float_t[nmax_];
  eta_ = new Float_t[nmax_];
  phi_ = new Float_t[nmax_];
  mass_ = new Float_t[nmax_];
}

void
panda::UnpackedGenParticle::datastore::deallocate()
{
  GenParticleBase::datastore::deallocate();

  delete [] pt_;
  pt_ = 0;
  delete [] eta_;
  eta_ = 0;
  delete [] phi_;
  phi_ = 0;
  delete [] mass_;
  mass_ = 0;
}

void
panda::UnpackedGenParticle::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  GenParticleBase::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "pt_", _branches);
  utils::setStatus(_tree, _name, "eta_", _branches);
  utils::setStatus(_tree, _name, "phi_", _branches);
  utils::setStatus(_tree, _name, "mass_", _branches);
}

panda::utils::BranchList
panda::UnpackedGenParticle::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(GenParticleBase::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "pt_"));
  blist.push_back(utils::getStatus(_tree, _name, "eta_"));
  blist.push_back(utils::getStatus(_tree, _name, "phi_"));
  blist.push_back(utils::getStatus(_tree, _name, "mass_"));

  return blist;
}

void
panda::UnpackedGenParticle::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  GenParticleBase::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "pt_", pt_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "eta_", eta_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phi_", phi_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mass_", mass_, _branches, _setStatus);
}

void
panda::UnpackedGenParticle::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  GenParticleBase::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "pt_", size, 'F', pt_, _branches);
  utils::book(_tree, _name, "eta_", size, 'F', eta_, _branches);
  utils::book(_tree, _name, "phi_", size, 'F', phi_, _branches);
  utils::book(_tree, _name, "mass_", size, 'F', mass_, _branches);
}

void
panda::UnpackedGenParticle::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  GenParticleBase::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "pt_");
  utils::resetAddress(_tree, _name, "eta_");
  utils::resetAddress(_tree, _name, "phi_");
  utils::resetAddress(_tree, _name, "mass_");
}

void
panda::UnpackedGenParticle::datastore::resizeVectors_(UInt_t _size)
{
  GenParticleBase::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::UnpackedGenParticle::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return UnpackedGenParticle::getListOfBranches().fullNames(_name);
}

panda::UnpackedGenParticle::UnpackedGenParticle(char const* _name/* = ""*/) :
  GenParticleBase(new UnpackedGenParticleArray(1, _name)),
  PtEtaPhiMMixin(gStore.getData(this), 0)
{
}

panda::UnpackedGenParticle::UnpackedGenParticle(UnpackedGenParticle const& _src) :
  GenParticleBase(new UnpackedGenParticleArray(1, _src.getName())),
  PtEtaPhiMMixin(gStore.getData(this), 0)
{
  operator=(_src);
}

panda::UnpackedGenParticle::UnpackedGenParticle(datastore& _data, UInt_t _idx) :
  GenParticleBase(_data, _idx),
  PtEtaPhiMMixin(_data, _idx)
{
}

panda::UnpackedGenParticle::UnpackedGenParticle(ArrayBase* _array) :
  GenParticleBase(_array),
  PtEtaPhiMMixin(gStore.getData(this), 0)
{
}

panda::UnpackedGenParticle::~UnpackedGenParticle()
{
  destructor();
}

void
panda::UnpackedGenParticle::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM UnpackedGenParticle.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    GenParticleBase::destructor(kTRUE);
}

panda::UnpackedGenParticle&
panda::UnpackedGenParticle::operator=(UnpackedGenParticle const& _src)
{
  GenParticleBase::operator=(_src);

  pt_ = _src.pt_;
  eta_ = _src.eta_;
  phi_ = _src.phi_;
  mass_ = _src.mass_;

  /* BEGIN CUSTOM UnpackedGenParticle.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
panda::UnpackedGenParticle::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  GenParticleBase::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "pt_", "", 'F', &pt_, _branches);
  utils::book(_tree, _name, "eta_", "", 'F', &eta_, _branches);
  utils::book(_tree, _name, "phi_", "", 'F', &phi_, _branches);
  utils::book(_tree, _name, "mass_", "", 'F', &mass_, _branches);
}

void
panda::UnpackedGenParticle::doInit_()
{
  GenParticleBase::doInit_();

  pt_ = 0.;
  eta_ = 0.;
  phi_ = 0.;
  mass_ = 0.;

  /* BEGIN CUSTOM UnpackedGenParticle.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::UnpackedGenParticle::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM UnpackedGenParticle.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::UnpackedGenParticle::dump(std::ostream& _out/* = std::cout*/) const
{
  GenParticleBase::dump(_out);

  _out << "pt_ = " << pt_ << std::endl;
  _out << "eta_ = " << eta_ << std::endl;
  _out << "phi_ = " << phi_ << std::endl;
  _out << "mass_ = " << mass_ << std::endl;
}

void
panda::UnpackedGenParticle::setPtEtaPhiM(double pt, double eta, double phi, double m)
{
  pt_ = pt;
  eta_ = eta;
  phi_ = phi;
  mass_ = m;
}

void
panda::UnpackedGenParticle::setXYZE(double px, double py, double pz, double e)
{
  pt_ = std::sqrt(px * px + py * py);
  double p(std::sqrt(px * px + py * py + pz * pz));
  eta_ = 0.5 * std::log((p + pz) / (p - pz));
  phi_ = std::atan2(py, px);
  mass_ = std::sqrt(e * e - p * p);
}


/* BEGIN CUSTOM UnpackedGenParticle.cc.global */
#include "../interface/GenParticle.h"

panda::UnpackedGenParticle&
panda::UnpackedGenParticle::operator=(GenParticle const& _rhs)
{
  GenParticleBase::operator=(static_cast<GenParticleBase const&>(_rhs));
  setPtEtaPhiM(_rhs.pt(), _rhs.eta(), _rhs.phi(), _rhs.m());

  return *this;
}
/* END CUSTOM */
