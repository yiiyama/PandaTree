#include "../interface/PLepton.h"

void
panda::PLepton::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLeptonBase::array_data::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "chiso", _status, _branches);
  utils::setStatus(_tree, _name, "nhiso", _status, _branches);
  utils::setStatus(_tree, _name, "phoiso", _status, _branches);
  utils::setStatus(_tree, _name, "puiso", _status, _branches);
}

void
panda::PLepton::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLeptonBase::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "chiso", chiso, _branches);
  utils::setStatusAndAddress(_tree, _name, "nhiso", nhiso, _branches);
  utils::setStatusAndAddress(_tree, _name, "phoiso", phoiso, _branches);
  utils::setStatusAndAddress(_tree, _name, "puiso", puiso, _branches);
}

void
panda::PLepton::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLeptonBase::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "chiso", "[" + _name + ".size]", 'F', chiso, _branches);
  utils::book(_tree, _name, "nhiso", "[" + _name + ".size]", 'F', nhiso, _branches);
  utils::book(_tree, _name, "phoiso", "[" + _name + ".size]", 'F', phoiso, _branches);
  utils::book(_tree, _name, "puiso", "[" + _name + ".size]", 'F', puiso, _branches);
}

panda::PLepton::PLepton() :
  PLeptonBase(utils::Allocator<PLepton>()),
  chiso(gStore.getData(this).chiso[gStore.getIndex(this)]),
  nhiso(gStore.getData(this).nhiso[gStore.getIndex(this)]),
  phoiso(gStore.getData(this).phoiso[gStore.getIndex(this)]),
  puiso(gStore.getData(this).puiso[gStore.getIndex(this)])
{
}

panda::PLepton::PLepton(PLepton const& _src) :
  PLeptonBase(utils::Allocator<PLepton>()),
  chiso(gStore.getData(this).chiso[gStore.getIndex(this)]),
  nhiso(gStore.getData(this).nhiso[gStore.getIndex(this)]),
  phoiso(gStore.getData(this).phoiso[gStore.getIndex(this)]),
  puiso(gStore.getData(this).puiso[gStore.getIndex(this)])
{
  PLeptonBase::operator=(_src);

  chiso = _src.chiso;
  nhiso = _src.nhiso;
  phoiso = _src.phoiso;
  puiso = _src.puiso;
}

panda::PLepton::PLepton(array_data& _data, UInt_t _idx) :
  PLeptonBase(_data, _idx),
  chiso(_data.chiso[_idx]),
  nhiso(_data.nhiso[_idx]),
  phoiso(_data.phoiso[_idx]),
  puiso(_data.puiso[_idx])
{
}

panda::PLepton::PLepton(utils::AllocatorBase const& _allocator) :
  PLeptonBase(_allocator),
  chiso(gStore.getData(this).chiso[gStore.getIndex(this)]),
  nhiso(gStore.getData(this).nhiso[gStore.getIndex(this)]),
  phoiso(gStore.getData(this).phoiso[gStore.getIndex(this)]),
  puiso(gStore.getData(this).puiso[gStore.getIndex(this)])
{
}

panda::PLepton::~PLepton()
{
  gStore.free(this);
}

panda::PLepton&
panda::PLepton::operator=(PLepton const& _src)
{
  PLeptonBase::operator=(_src);

  chiso = _src.chiso;
  nhiso = _src.nhiso;
  phoiso = _src.phoiso;
  puiso = _src.puiso;

  return *this;
}

void
panda::PLepton::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLeptonBase::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "chiso", _status, _branches);
  utils::setStatus(_tree, _name, "nhiso", _status, _branches);
  utils::setStatus(_tree, _name, "phoiso", _status, _branches);
  utils::setStatus(_tree, _name, "puiso", _status, _branches);
}

void
panda::PLepton::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLeptonBase::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "chiso", &chiso, _branches);
  utils::setStatusAndAddress(_tree, _name, "nhiso", &nhiso, _branches);
  utils::setStatusAndAddress(_tree, _name, "phoiso", &phoiso, _branches);
  utils::setStatusAndAddress(_tree, _name, "puiso", &puiso, _branches);
}

void
panda::PLepton::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLeptonBase::book(_tree, _name, _branches);

  utils::book(_tree, _name, "chiso", "", 'F', &chiso, _branches);
  utils::book(_tree, _name, "nhiso", "", 'F', &nhiso, _branches);
  utils::book(_tree, _name, "phoiso", "", 'F', &phoiso, _branches);
  utils::book(_tree, _name, "puiso", "", 'F', &puiso, _branches);
}

void
panda::PLepton::init()
{
  PLeptonBase::init();

  chiso = 0.;
  nhiso = 0.;
  phoiso = 0.;
  puiso = 0.;
}

/* BEGIN CUSTOM */
/* END CUSTOM */
