#include "../interface/Particle.h"

void
panda::Particle::datastore::allocate(UInt_t _nmax)
{
  Element::datastore::allocate(_nmax);

  pt = new Float_t[nmax_];
  eta = new Float_t[nmax_];
  phi = new Float_t[nmax_];
}

void
panda::Particle::datastore::deallocate()
{
  Element::datastore::deallocate();

  delete [] pt;
  pt = 0;
  delete [] eta;
  eta = 0;
  delete [] phi;
  phi = 0;
}

void
panda::Particle::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Element::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "pt", _branches);
  utils::setStatus(_tree, _name, "eta", _branches);
  utils::setStatus(_tree, _name, "phi", _branches);
}

void
panda::Particle::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Element::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "pt", pt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "eta", eta, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phi", phi, _branches, _setStatus);
}

void
panda::Particle::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Element::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "pt", size, 'F', pt, _branches);
  utils::book(_tree, _name, "eta", size, 'F', eta, _branches);
  utils::book(_tree, _name, "phi", size, 'F', phi, _branches);
}

void
panda::Particle::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Element::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "pt");
  utils::resetAddress(_tree, _name, "eta");
  utils::resetAddress(_tree, _name, "phi");
}

void
panda::Particle::datastore::resizeVectors_(UInt_t _size)
{
  Element::datastore::resizeVectors_(_size);

}

panda::Particle::Particle(char const* _name/* = ""*/) :
  Element(new ParticleArray(1, _name)),
  pt(gStore.getData(this).pt[0]),
  eta(gStore.getData(this).eta[0]),
  phi(gStore.getData(this).phi[0])
{
}

panda::Particle::Particle(datastore& _data, UInt_t _idx) :
  Element(_data, _idx),
  pt(_data.pt[_idx]),
  eta(_data.eta[_idx]),
  phi(_data.phi[_idx])
{
}

panda::Particle::Particle(Particle const& _src) :
  Element(new ParticleArray(1, gStore.getName(&_src))),
  pt(gStore.getData(this).pt[0]),
  eta(gStore.getData(this).eta[0]),
  phi(gStore.getData(this).phi[0])
{
  Element::operator=(_src);

  pt = _src.pt;
  eta = _src.eta;
  phi = _src.phi;
}

panda::Particle::Particle(ArrayBase* _array) :
  Element(_array),
  pt(gStore.getData(this).pt[0]),
  eta(gStore.getData(this).eta[0]),
  phi(gStore.getData(this).phi[0])
{
}

panda::Particle::~Particle()
{
  destructor();
  gStore.free(this);
}

void
panda::Particle::destructor()
{
  /* BEGIN CUSTOM Particle.cc.destructor */
  /* END CUSTOM */

  Element::destructor();
}

panda::Particle&
panda::Particle::operator=(Particle const& _src)
{
  Element::operator=(_src);

  pt = _src.pt;
  eta = _src.eta;
  phi = _src.phi;

  return *this;
}

void
panda::Particle::doSetStatus_(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Element::doSetStatus_(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "pt", _branches);
  utils::setStatus(_tree, _name, "eta", _branches);
  utils::setStatus(_tree, _name, "phi", _branches);
}

void
panda::Particle::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Element::doSetAddress_(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "pt", &pt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "eta", &eta, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phi", &phi, _branches, _setStatus);
}

void
panda::Particle::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  Element::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "pt", "", 'F', &pt, _branches);
  utils::book(_tree, _name, "eta", "", 'F', &eta, _branches);
  utils::book(_tree, _name, "phi", "", 'F', &phi, _branches);
}

void
panda::Particle::doReleaseTree_(TTree& _tree, TString const& _name)
{
  Element::doReleaseTree_(_tree, _name);

  utils::resetAddress(_tree, _name, "pt");
  utils::resetAddress(_tree, _name, "eta");
  utils::resetAddress(_tree, _name, "phi");
}

void
panda::Particle::doInit_()
{
  Element::doInit_();

  pt = 0.;
  eta = 0.;
  phi = 0.;
}

void
panda::Particle::setXYZE(double px, double py, double pz, double)
{
  pt = std::sqrt(px * px + py * py);
  double p(std::sqrt(px * px + py * py + pz * pz));
  eta = 0.5 * std::log((p + pz) / (p - pz));
  phi = std::atan2(py, px);
}


/* BEGIN CUSTOM Particle.cc.global */
/* END CUSTOM */
