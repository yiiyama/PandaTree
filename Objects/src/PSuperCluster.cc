#include "../interface/PSuperCluster.h"

void
panda::PSuperCluster::datastore::allocate(UInt_t _nmax)
{
  ContainerElement::datastore::allocate(_nmax);

  rawPt = new Float_t[nmax_];
  eta = new Float_t[nmax_];
  phi = new Float_t[nmax_];
}

void
panda::PSuperCluster::datastore::deallocate()
{
  ContainerElement::datastore::deallocate();

  delete [] rawPt;
  rawPt = 0;
  delete [] eta;
  eta = 0;
  delete [] phi;
  phi = 0;
}

void
panda::PSuperCluster::datastore::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::datastore::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "rawPt", _status, _branches);
  utils::setStatus(_tree, _name, "eta", _status, _branches);
  utils::setStatus(_tree, _name, "phi", _status, _branches);
}

void
panda::PSuperCluster::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ContainerElement::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "rawPt", rawPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "eta", eta, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phi", phi, _branches, _setStatus);
}

void
panda::PSuperCluster::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ContainerElement::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "rawPt", size, 'F', rawPt, _branches);
  utils::book(_tree, _name, "eta", size, 'F', eta, _branches);
  utils::book(_tree, _name, "phi", size, 'F', phi, _branches);
}

void
panda::PSuperCluster::datastore::resetAddress(TTree& _tree, TString const& _name)
{
  ContainerElement::datastore::resetAddress(_tree, _name);

  utils::resetAddress(_tree, _name, "rawPt");
  utils::resetAddress(_tree, _name, "eta");
  utils::resetAddress(_tree, _name, "phi");
}

void
panda::PSuperCluster::datastore::resizeVectors_(UInt_t _size)
{
  ContainerElement::datastore::resizeVectors_(_size);

}

panda::PSuperCluster::PSuperCluster(char const* _name/* = ""*/) :
  ContainerElement(new PSuperClusterArray(1, _name)),
  rawPt(gStore.getData(this).rawPt[0]),
  eta(gStore.getData(this).eta[0]),
  phi(gStore.getData(this).phi[0])
{
}

panda::PSuperCluster::PSuperCluster(datastore& _data, UInt_t _idx) :
  ContainerElement(_data, _idx),
  rawPt(_data.rawPt[_idx]),
  eta(_data.eta[_idx]),
  phi(_data.phi[_idx])
{
}

panda::PSuperCluster::PSuperCluster(PSuperCluster const& _src) :
  ContainerElement(new PSuperClusterArray(1, gStore.getName(&_src))),
  rawPt(gStore.getData(this).rawPt[0]),
  eta(gStore.getData(this).eta[0]),
  phi(gStore.getData(this).phi[0])
{
  ContainerElement::operator=(_src);

  rawPt = _src.rawPt;
  eta = _src.eta;
  phi = _src.phi;
}

panda::PSuperCluster::PSuperCluster(ArrayBase* _array) :
  ContainerElement(_array),
  rawPt(gStore.getData(this).rawPt[0]),
  eta(gStore.getData(this).eta[0]),
  phi(gStore.getData(this).phi[0])
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
panda::PSuperCluster::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));

  utils::setStatus(_tree, name, "rawPt", _status, _branches);
  utils::setStatus(_tree, name, "eta", _status, _branches);
  utils::setStatus(_tree, name, "phi", _status, _branches);
}

void
panda::PSuperCluster::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ContainerElement::setAddress(_tree, _branches, _setStatus);

  TString name(gStore.getName(this));

  utils::setAddress(_tree, name, "rawPt", &rawPt, _branches, _setStatus);
  utils::setAddress(_tree, name, "eta", &eta, _branches, _setStatus);
  utils::setAddress(_tree, name, "phi", &phi, _branches, _setStatus);
}

void
panda::PSuperCluster::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  ContainerElement::book(_tree, _branches);

  TString name(gStore.getName(this));

  utils::book(_tree, name, "rawPt", "", 'F', &rawPt, _branches);
  utils::book(_tree, name, "eta", "", 'F', &eta, _branches);
  utils::book(_tree, name, "phi", "", 'F', &phi, _branches);
}

void
panda::PSuperCluster::resetAddress(TTree& _tree)
{
  ContainerElement::resetAddress(_tree);

  TString name(gStore.getName(this));

  utils::resetAddress(_tree, name, "rawPt");
  utils::resetAddress(_tree, name, "eta");
  utils::resetAddress(_tree, name, "phi");
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
