#include "../interface/ParticleM.h"

/*static*/
panda::utils::BranchList
panda::ParticleM::getListOfBranches()
{
  utils::BranchList blist;
  blist += Particle::getListOfBranches();
  blist += {"pt_", "eta_", "phi_", "mass_"};
  return blist;
}

void
panda::ParticleM::datastore::allocate(UInt_t _nmax)
{
  Particle::datastore::allocate(_nmax);

  pt_ = new Float_t[nmax_];
  eta_ = new Float_t[nmax_];
  phi_ = new Float_t[nmax_];
  mass_ = new Float_t[nmax_];
}

void
panda::ParticleM::datastore::deallocate()
{
  Particle::datastore::deallocate();

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
panda::ParticleM::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Particle::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "pt_", _branches);
  utils::setStatus(_tree, _name, "eta_", _branches);
  utils::setStatus(_tree, _name, "phi_", _branches);
  utils::setStatus(_tree, _name, "mass_", _branches);
}

panda::utils::BranchList
panda::ParticleM::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Particle::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "pt_"));
  blist.push_back(utils::getStatus(_tree, _name, "eta_"));
  blist.push_back(utils::getStatus(_tree, _name, "phi_"));
  blist.push_back(utils::getStatus(_tree, _name, "mass_"));

  return blist;
}

void
panda::ParticleM::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "pt_", pt_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "eta_", eta_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phi_", phi_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mass_", mass_, _branches, _setStatus);
}

void
panda::ParticleM::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Particle::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "pt_", size, 'F', pt_, _branches);
  utils::book(_tree, _name, "eta_", size, 'F', eta_, _branches);
  utils::book(_tree, _name, "phi_", size, 'F', phi_, _branches);
  utils::book(_tree, _name, "mass_", size, 'F', mass_, _branches);
}

void
panda::ParticleM::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Particle::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "pt_");
  utils::resetAddress(_tree, _name, "eta_");
  utils::resetAddress(_tree, _name, "phi_");
  utils::resetAddress(_tree, _name, "mass_");
}

void
panda::ParticleM::datastore::resizeVectors_(UInt_t _size)
{
  Particle::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::ParticleM::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return ParticleM::getListOfBranches().fullNames(_name);
}

panda::ParticleM::ParticleM(char const* _name/* = ""*/) :
  Particle(new ParticleMArray(1, _name)),
  pt_(gStore.getData(this).pt_[0]),
  eta_(gStore.getData(this).eta_[0]),
  phi_(gStore.getData(this).phi_[0]),
  mass_(gStore.getData(this).mass_[0])
{
}

panda::ParticleM::ParticleM(ParticleM const& _src) :
  Particle(new ParticleMArray(1, _src.getName())),
  pt_(gStore.getData(this).pt_[0]),
  eta_(gStore.getData(this).eta_[0]),
  phi_(gStore.getData(this).phi_[0]),
  mass_(gStore.getData(this).mass_[0])
{
  Particle::operator=(_src);

  pt_ = _src.pt_;
  eta_ = _src.eta_;
  phi_ = _src.phi_;
  mass_ = _src.mass_;
}

panda::ParticleM::ParticleM(datastore& _data, UInt_t _idx) :
  Particle(_data, _idx),
  pt_(_data.pt_[_idx]),
  eta_(_data.eta_[_idx]),
  phi_(_data.phi_[_idx]),
  mass_(_data.mass_[_idx])
{
}

panda::ParticleM::ParticleM(ArrayBase* _array) :
  Particle(_array),
  pt_(gStore.getData(this).pt_[0]),
  eta_(gStore.getData(this).eta_[0]),
  phi_(gStore.getData(this).phi_[0]),
  mass_(gStore.getData(this).mass_[0])
{
}

panda::ParticleM::~ParticleM()
{
  destructor();
}

void
panda::ParticleM::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM ParticleM.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    Particle::destructor(kTRUE);
}

panda::ParticleM&
panda::ParticleM::operator=(ParticleM const& _src)
{
  Particle::operator=(_src);

  pt_ = _src.pt_;
  eta_ = _src.eta_;
  phi_ = _src.phi_;
  mass_ = _src.mass_;

  /* BEGIN CUSTOM ParticleM.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
panda::ParticleM::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  Particle::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "pt_", "", 'F', &pt_, _branches);
  utils::book(_tree, _name, "eta_", "", 'F', &eta_, _branches);
  utils::book(_tree, _name, "phi_", "", 'F', &phi_, _branches);
  utils::book(_tree, _name, "mass_", "", 'F', &mass_, _branches);
}

void
panda::ParticleM::doInit_()
{
  Particle::doInit_();

  pt_ = 0.;
  eta_ = 0.;
  phi_ = 0.;
  mass_ = 0.;

  /* BEGIN CUSTOM ParticleM.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::ParticleM::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM ParticleM.cc.print */
  ParticleM::dump(_out);
  /* END CUSTOM */
}

void
panda::ParticleM::dump(std::ostream& _out/* = std::cout*/) const
{
  Particle::dump(_out);

  _out << "pt_ = " << pt_ << std::endl;
  _out << "eta_ = " << eta_ << std::endl;
  _out << "phi_ = " << phi_ << std::endl;
  _out << "mass_ = " << mass_ << std::endl;
}

void
panda::ParticleM::setPtEtaPhiM(double pt, double eta, double phi, double m)
{
  pt_ = pt;
  eta_ = eta;
  phi_ = phi;
  mass_ = m;
}

void
panda::ParticleM::setXYZE(double px, double py, double pz, double e)
{
  pt_ = std::sqrt(px * px + py * py);
  double p(std::sqrt(px * px + py * py + pz * pz));
  eta_ = 0.5 * std::log((p + pz) / (p - pz));
  phi_ = std::atan2(py, px);
  mass_ = std::sqrt(e * e - p * p);
}


/* BEGIN CUSTOM ParticleM.cc.global */
/* END CUSTOM */
