#include "../interface/PLeptonBase.h"

void
panda::PLeptonBase::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::array_data::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "q", _status, _branches);
  utils::setStatus(_tree, _name, "id", _status, _branches);
  utils::setStatus(_tree, _name, "iso", _status, _branches);
}

void
panda::PLeptonBase::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "q", q, _branches);
  utils::setStatusAndAddress(_tree, _name, "id", id, _branches);
  utils::setStatusAndAddress(_tree, _name, "iso", iso, _branches);
}

void
panda::PLeptonBase::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "q", "[" + _name + ".size]", 'I', q, _branches);
  utils::book(_tree, _name, "id", "[" + _name + ".size]", 'i', id, _branches);
  utils::book(_tree, _name, "iso", "[" + _name + ".size]", 'F', iso, _branches);
}

panda::PLeptonBase::PLeptonBase() :
  PObject(utils::Allocator<PLeptonBase>()),
  q(gStore.getData(this).q[gStore.getIndex(this)]),
  id(gStore.getData(this).id[gStore.getIndex(this)]),
  iso(gStore.getData(this).iso[gStore.getIndex(this)])
{
}

panda::PLeptonBase::PLeptonBase(PLeptonBase const& _src) :
  PObject(utils::Allocator<PLeptonBase>()),
  q(gStore.getData(this).q[gStore.getIndex(this)]),
  id(gStore.getData(this).id[gStore.getIndex(this)]),
  iso(gStore.getData(this).iso[gStore.getIndex(this)])
{
  PObject::operator=(_src);

  q = _src.q;
  id = _src.id;
  iso = _src.iso;
}

panda::PLeptonBase::PLeptonBase(array_data& _data, UInt_t _idx) :
  PObject(_data, _idx),
  q(_data.q[_idx]),
  id(_data.id[_idx]),
  iso(_data.iso[_idx])
{
}

panda::PLeptonBase::PLeptonBase(utils::AllocatorBase const& _allocator) :
  PObject(_allocator),
  q(gStore.getData(this).q[gStore.getIndex(this)]),
  id(gStore.getData(this).id[gStore.getIndex(this)]),
  iso(gStore.getData(this).iso[gStore.getIndex(this)])
{
}

panda::PLeptonBase::~PLeptonBase()
{
  gStore.free(this);
}

panda::PLeptonBase&
panda::PLeptonBase::operator=(PLeptonBase const& _src)
{
  PObject::operator=(_src);

  q = _src.q;
  id = _src.id;
  iso = _src.iso;

  return *this;
}

void
panda::PLeptonBase::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "q", _status, _branches);
  utils::setStatus(_tree, _name, "id", _status, _branches);
  utils::setStatus(_tree, _name, "iso", _status, _branches);
}

void
panda::PLeptonBase::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "q", &q, _branches);
  utils::setStatusAndAddress(_tree, _name, "id", &id, _branches);
  utils::setStatusAndAddress(_tree, _name, "iso", &iso, _branches);
}

void
panda::PLeptonBase::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::book(_tree, _name, _branches);

  utils::book(_tree, _name, "q", "", 'I', &q, _branches);
  utils::book(_tree, _name, "id", "", 'i', &id, _branches);
  utils::book(_tree, _name, "iso", "", 'F', &iso, _branches);
}

void
panda::PLeptonBase::init()
{
  PObject::init();

  q = 0;
  id = 0;
  iso = 0.;
}

/* BEGIN CUSTOM */
/* END CUSTOM */
