#include "../interface/PMuon.h"

void
panda::PMuon::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::array_data::setStatus(_tree, _name, _status, _branches);
}

void
panda::PMuon::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::array_data::setAddress(_tree, _name, _branches);
}

void
panda::PMuon::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::array_data::book(_tree, _name, _branches);
}

panda::PMuon::PMuon(char const* _name/* = ""*/) :
  PLepton(utils::Allocator<PMuon>(), _name)
{
}

panda::PMuon::PMuon(array_data& _data, UInt_t _idx) :
  PLepton(_data, _idx)
{
}

panda::PMuon::PMuon(PMuon const& _src) :
  PLepton(utils::Allocator<PMuon>(), gStore.getName(&_src))
{
  PLepton::operator=(_src);
}

panda::PMuon::PMuon(utils::AllocatorBase const& _allocator, char const* _name) :
  PLepton(_allocator, _name)
{
}

panda::PMuon::~PMuon()
{
  gStore.free(this);
}

panda::PMuon&
panda::PMuon::operator=(PMuon const& _src)
{
  PLepton::operator=(_src);

  return *this;
}

void
panda::PMuon::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::setStatus(_tree, _status, _branches);

  TString name(gStore.getName(this));
}

void
panda::PMuon::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::setAddress(_tree, _branches);

  TString name(gStore.getName(this));
}

void
panda::PMuon::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::book(_tree, _branches);

  TString name(gStore.getName(this));
}

void
panda::PMuon::init()
{
  PLepton::init();
}


/* BEGIN CUSTOM */
/* END CUSTOM */
