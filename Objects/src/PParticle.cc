#include "../interface/PParticle.h"

void
panda::PParticle::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::array_data::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "pt", _status, _branches);
  utils::setStatus(_tree, _name, "eta", _status, _branches);
  utils::setStatus(_tree, _name, "phi", _status, _branches);
}

void
panda::PParticle::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "pt", pt, _branches);
  utils::setStatusAndAddress(_tree, _name, "eta", eta, _branches);
  utils::setStatusAndAddress(_tree, _name, "phi", phi, _branches);
}

void
panda::PParticle::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "pt", "[" + _name + ".size]", 'F', pt, _branches);
  utils::book(_tree, _name, "eta", "[" + _name + ".size]", 'F', eta, _branches);
  utils::book(_tree, _name, "phi", "[" + _name + ".size]", 'F', phi, _branches);
}

panda::PParticle::PParticle(char const* _name/* = ""*/) :
  ContainerElement(utils::Allocator<PParticle>(), _name),
  pt(gStore.getData(this).pt[gStore.getIndex(this)]),
  eta(gStore.getData(this).eta[gStore.getIndex(this)]),
  phi(gStore.getData(this).phi[gStore.getIndex(this)])
{
}

panda::PParticle::PParticle(array_data& _data, UInt_t _idx) :
  ContainerElement(_data, _idx),
  pt(_data.pt[_idx]),
  eta(_data.eta[_idx]),
  phi(_data.phi[_idx])
{
}

panda::PParticle::PParticle(PParticle const& _src) :
  ContainerElement(utils::Allocator<PParticle>(), gStore.getName(&_src)),
  pt(gStore.getData(this).pt[gStore.getIndex(this)]),
  eta(gStore.getData(this).eta[gStore.getIndex(this)]),
  phi(gStore.getData(this).phi[gStore.getIndex(this)])
{
  ContainerElement::operator=(_src);

  pt = _src.pt;
  eta = _src.eta;
  phi = _src.phi;
}

panda::PParticle::PParticle(utils::AllocatorBase const& _allocator, char const* _name) :
  ContainerElement(_allocator, _name),
  pt(gStore.getData(this).pt[gStore.getIndex(this)]),
  eta(gStore.getData(this).eta[gStore.getIndex(this)]),
  phi(gStore.getData(this).phi[gStore.getIndex(this)])
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
panda::PParticle::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::setAddress(_tree, _branches);

  TString name(gStore.getName(this));

  utils::setStatusAndAddress(_tree, name, "pt", &pt, _branches);
  utils::setStatusAndAddress(_tree, name, "eta", &eta, _branches);
  utils::setStatusAndAddress(_tree, name, "phi", &phi, _branches);
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
panda::PParticle::init()
{
  ContainerElement::init();

  pt = 0.;
  eta = 0.;
  phi = 0.;
}


/* BEGIN CUSTOM */
/* END CUSTOM */
