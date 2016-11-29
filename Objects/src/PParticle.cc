#include "../interface/PParticle.h"

void
panda::PParticle::datastore::allocate(UInt_t _nmax)
{
  ContainerElement::datastore::allocate(_nmax);

  pt = new Float_t[nmax_];
  eta = new Float_t[nmax_];
  phi = new Float_t[nmax_];
}

void
panda::PParticle::datastore::deallocate()
{
  ContainerElement::datastore::deallocate();

  delete [] pt;
  pt = 0;
  delete [] eta;
  eta = 0;
  delete [] phi;
  phi = 0;
}

void
panda::PParticle::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "pt", _status, _branches);
  utils::setStatus(_tree, _name, "eta", _status, _branches);
  utils::setStatus(_tree, _name, "phi", _status, _branches);
}

void
panda::PParticle::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ContainerElement::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "pt", pt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "eta", eta, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phi", phi, _branches, _setStatus);
}

void
panda::PParticle::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ContainerElement::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "pt", size, 'F', pt, _branches);
  utils::book(_tree, _name, "eta", size, 'F', eta, _branches);
  utils::book(_tree, _name, "phi", size, 'F', phi, _branches);
}

void
panda::PParticle::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  ContainerElement::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "pt");
  utils::resetAddress(_tree, _name, "eta");
  utils::resetAddress(_tree, _name, "phi");
}

panda::PParticle::PParticle(char const* _name/* = ""*/) :
  ContainerElement(new PParticleArray(1, _name)),
  pt(gStore.getData(this).pt[0]),
  eta(gStore.getData(this).eta[0]),
  phi(gStore.getData(this).phi[0])
{
}

panda::PParticle::PParticle(datastore& _data, UInt_t _idx) :
  ContainerElement(_data, _idx),
  pt(_data.pt[_idx]),
  eta(_data.eta[_idx]),
  phi(_data.phi[_idx])
{
}

panda::PParticle::PParticle(PParticle const& _src) :
  ContainerElement(new PParticleArray(1, gStore.getName(&_src))),
  pt(gStore.getData(this).pt[0]),
  eta(gStore.getData(this).eta[0]),
  phi(gStore.getData(this).phi[0])
{
  ContainerElement::operator=(_src);

  pt = _src.pt;
  eta = _src.eta;
  phi = _src.phi;
}

panda::PParticle::PParticle(ArrayBase* _array) :
  ContainerElement(_array),
  pt(gStore.getData(this).pt[0]),
  eta(gStore.getData(this).eta[0]),
  phi(gStore.getData(this).phi[0])
{
}

panda::PParticle::~PParticle()
{
  gStore.free(this);
}

panda::PParticle&
panda::PParticle::operator=(PParticle const& _src)
{
  ContainerElement::operator=(_src);

  pt = _src.pt;
  eta = _src.eta;
  phi = _src.phi;

  return *this;
}

void
panda::PParticle::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "pt", _status, _branches);
  utils::setStatus(_tree, name, "eta", _status, _branches);
  utils::setStatus(_tree, name, "phi", _status, _branches);
}

void
panda::PParticle::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ContainerElement::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "pt", &pt, _branches, _setStatus);
  utils::setAddress(_tree, name, "eta", &eta, _branches, _setStatus);
  utils::setAddress(_tree, name, "phi", &phi, _branches, _setStatus);
}

void
panda::PParticle::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "pt", "", 'F', &pt, _branches);
  utils::book(_tree, name, "eta", "", 'F', &eta, _branches);
  utils::book(_tree, name, "phi", "", 'F', &phi, _branches);
}

void
panda::PParticle::resetAddress(TTree& _tree)
{
  ContainerElement::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "pt");
  utils::resetAddress(_tree, name, "eta");
  utils::resetAddress(_tree, name, "phi");
}

void
panda::PParticle::init()
{
  ContainerElement::init();

  pt = 0.;
  eta = 0.;
  phi = 0.;
}


/* BEGIN CUSTOM */
/* END CUSTOM */
