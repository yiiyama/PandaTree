#include "../interface/PSuperCluster.h"

void
panda::PSuperCluster::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::array_data::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "rawPt", _status, _branches);
  utils::setStatus(_tree, _name, "eta", _status, _branches);
  utils::setStatus(_tree, _name, "phi", _status, _branches);
}

void
panda::PSuperCluster::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "rawPt", rawPt, _branches);
  utils::setStatusAndAddress(_tree, _name, "eta", eta, _branches);
  utils::setStatusAndAddress(_tree, _name, "phi", phi, _branches);
}

void
panda::PSuperCluster::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "rawPt", "[" + _name + ".size]", 'F', rawPt, _branches);
  utils::book(_tree, _name, "eta", "[" + _name + ".size]", 'F', eta, _branches);
  utils::book(_tree, _name, "phi", "[" + _name + ".size]", 'F', phi, _branches);
}

panda::PSuperCluster::PSuperCluster() :
  ContainerElement(utils::Allocator<PSuperCluster>()),
  rawPt(gStore.getData(this).rawPt[gStore.getIndex(this)]),
  eta(gStore.getData(this).eta[gStore.getIndex(this)]),
  phi(gStore.getData(this).phi[gStore.getIndex(this)])
{
}

panda::PSuperCluster::PSuperCluster(PSuperCluster const& _src) :
  ContainerElement(utils::Allocator<PSuperCluster>()),
  rawPt(gStore.getData(this).rawPt[gStore.getIndex(this)]),
  eta(gStore.getData(this).eta[gStore.getIndex(this)]),
  phi(gStore.getData(this).phi[gStore.getIndex(this)])
{
  ContainerElement::operator=(_src);

  rawPt = _src.rawPt;
  eta = _src.eta;
  phi = _src.phi;
}

panda::PSuperCluster::PSuperCluster(array_data& _data, UInt_t _idx) :
  ContainerElement(_data, _idx),
  rawPt(_data.rawPt[_idx]),
  eta(_data.eta[_idx]),
  phi(_data.phi[_idx])
{
}

panda::PSuperCluster::PSuperCluster(utils::AllocatorBase const& _allocator) :
  ContainerElement(_allocator),
  rawPt(gStore.getData(this).rawPt[gStore.getIndex(this)]),
  eta(gStore.getData(this).eta[gStore.getIndex(this)]),
  phi(gStore.getData(this).phi[gStore.getIndex(this)])
{
}

panda::PSuperCluster::~PSuperCluster()
{
  gStore.free(this);
}

panda::PSuperCluster&
panda::PSuperCluster::operator=(PSuperCluster const& _src)
{
  ContainerElement::operator=(_src);

  rawPt = _src.rawPt;
  eta = _src.eta;
  phi = _src.phi;

  return *this;
}

void
panda::PSuperCluster::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "rawPt", _status, _branches);
  utils::setStatus(_tree, _name, "eta", _status, _branches);
  utils::setStatus(_tree, _name, "phi", _status, _branches);
}

void
panda::PSuperCluster::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "rawPt", &rawPt, _branches);
  utils::setStatusAndAddress(_tree, _name, "eta", &eta, _branches);
  utils::setStatusAndAddress(_tree, _name, "phi", &phi, _branches);
}

void
panda::PSuperCluster::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::book(_tree, _name, _branches);

  utils::book(_tree, _name, "rawPt", "", 'F', &rawPt, _branches);
  utils::book(_tree, _name, "eta", "", 'F', &eta, _branches);
  utils::book(_tree, _name, "phi", "", 'F', &phi, _branches);
}

void
panda::PSuperCluster::init()
{
  ContainerElement::init();

  rawPt = 0.;
  eta = 0.;
  phi = 0.;
}

/* BEGIN CUSTOM */
/* END CUSTOM */
