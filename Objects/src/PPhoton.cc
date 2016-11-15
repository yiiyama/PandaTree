#include "../interface/PPhoton.h"

void
panda::PPhoton::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::array_data::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "id", _status, _branches);
  utils::setStatus(_tree, _name, "iso", _status, _branches);
}

void
panda::PPhoton::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "id", id, _branches);
  utils::setStatusAndAddress(_tree, _name, "iso", iso, _branches);
}

void
panda::PPhoton::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "id", "[" + _name + ".size]", 'i', id, _branches);
  utils::book(_tree, _name, "iso", "[" + _name + ".size]", 'F', iso, _branches);
}

panda::PPhoton::PPhoton() :
  PObject(utils::Allocator<PPhoton>()),
  id(gStore.getData(this).id[gStore.getIndex(this)]),
  iso(gStore.getData(this).iso[gStore.getIndex(this)])
{
}

panda::PPhoton::PPhoton(PPhoton const& _src) :
  PObject(utils::Allocator<PPhoton>()),
  id(gStore.getData(this).id[gStore.getIndex(this)]),
  iso(gStore.getData(this).iso[gStore.getIndex(this)])
{
  PObject::operator=(_src);

  id = _src.id;
  iso = _src.iso;
}

panda::PPhoton::PPhoton(array_data& _data, UInt_t _idx) :
  PObject(_data, _idx),
  id(_data.id[_idx]),
  iso(_data.iso[_idx])
{
}

panda::PPhoton::PPhoton(utils::AllocatorBase const& _allocator) :
  PObject(_allocator),
  id(gStore.getData(this).id[gStore.getIndex(this)]),
  iso(gStore.getData(this).iso[gStore.getIndex(this)])
{
}

panda::PPhoton::~PPhoton()
{
  gStore.free(this);
}

panda::PPhoton&
panda::PPhoton::operator=(PPhoton const& _src)
{
  PObject::operator=(_src);

  id = _src.id;
  iso = _src.iso;

  return *this;
}

void
panda::PPhoton::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "id", _status, _branches);
  utils::setStatus(_tree, _name, "iso", _status, _branches);
}

void
panda::PPhoton::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "id", &id, _branches);
  utils::setStatusAndAddress(_tree, _name, "iso", &iso, _branches);
}

void
panda::PPhoton::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PObject::book(_tree, _name, _branches);

  utils::book(_tree, _name, "id", "", 'i', &id, _branches);
  utils::book(_tree, _name, "iso", "", 'F', &iso, _branches);
}

void
panda::PPhoton::init()
{
  PObject::init();

  id = 0;
  iso = 0.;
}

/* BEGIN CUSTOM */
/* END CUSTOM */
