#include "../interface/PObject.h"

void
panda::PObject::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::array_data::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "pt", _status, _branches);
  utils::setStatus(_tree, _name, "eta", _status, _branches);
  utils::setStatus(_tree, _name, "phi", _status, _branches);
}

void
panda::PObject::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "pt", pt, _branches);
  utils::setStatusAndAddress(_tree, _name, "eta", eta, _branches);
  utils::setStatusAndAddress(_tree, _name, "phi", phi, _branches);
}

void
panda::PObject::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "pt", "[" + _name + ".size]", 'F', pt, _branches);
  utils::book(_tree, _name, "eta", "[" + _name + ".size]", 'F', eta, _branches);
  utils::book(_tree, _name, "phi", "[" + _name + ".size]", 'F', phi, _branches);
}

panda::PObject::PObject() :
  ContainerElement(utils::Allocator<PObject>()),
  pt(gStore.getData(this).pt[gStore.getIndex(this)]),
  eta(gStore.getData(this).eta[gStore.getIndex(this)]),
  phi(gStore.getData(this).phi[gStore.getIndex(this)])
{
}

panda::PObject::PObject(PObject const& _src) :
  ContainerElement(utils::Allocator<PObject>()),
  pt(gStore.getData(this).pt[gStore.getIndex(this)]),
  eta(gStore.getData(this).eta[gStore.getIndex(this)]),
  phi(gStore.getData(this).phi[gStore.getIndex(this)])
{
  ContainerElement::operator=(_src);

  pt = _src.pt;
  eta = _src.eta;
  phi = _src.phi;
}

panda::PObject::PObject(array_data& _data, UInt_t _idx) :
  ContainerElement(_data, _idx),
  pt(_data.pt[_idx]),
  eta(_data.eta[_idx]),
  phi(_data.phi[_idx])
{
}

panda::PObject::PObject(utils::AllocatorBase const& _allocator) :
  ContainerElement(_allocator),
  pt(gStore.getData(this).pt[gStore.getIndex(this)]),
  eta(gStore.getData(this).eta[gStore.getIndex(this)]),
  phi(gStore.getData(this).phi[gStore.getIndex(this)])
{
}

panda::PObject::~PObject()
{
  gStore.free(this);
}

panda::PObject&
panda::PObject::operator=(PObject const& _src)
{
  ContainerElement::operator=(_src);

  pt = _src.pt;
  eta = _src.eta;
  phi = _src.phi;

  return *this;
}

void
panda::PObject::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "pt", _status, _branches);
  utils::setStatus(_tree, _name, "eta", _status, _branches);
  utils::setStatus(_tree, _name, "phi", _status, _branches);
}

void
panda::PObject::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "pt", &pt, _branches);
  utils::setStatusAndAddress(_tree, _name, "eta", &eta, _branches);
  utils::setStatusAndAddress(_tree, _name, "phi", &phi, _branches);
}

void
panda::PObject::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::book(_tree, _name, _branches);

  utils::book(_tree, _name, "pt", "", 'F', &pt, _branches);
  utils::book(_tree, _name, "eta", "", 'F', &eta, _branches);
  utils::book(_tree, _name, "phi", "", 'F', &phi, _branches);
}

void
panda::PObject::init()
{
  ContainerElement::init();

  pt = 0.;
  eta = 0.;
  phi = 0.;
}


/* BEGIN CUSTOM */
/* END CUSTOM */
