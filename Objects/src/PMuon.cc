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

panda::PMuon::PMuon() :
  PLepton(utils::Allocator<PMuon>())
{
}

panda::PMuon::PMuon(PMuon const& _src) :
  PLepton(utils::Allocator<PMuon>())
{
  PLepton::operator=(_src);
}

panda::PMuon::PMuon(array_data& _data, UInt_t _idx) :
  PLepton(_data, _idx)
{
}

panda::PMuon::PMuon(utils::AllocatorBase const& _allocator) :
  PLepton(_allocator)
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
panda::PMuon::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::setStatus(_tree, _name, _status, _branches);
}

void
panda::PMuon::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::setAddress(_tree, _name, _branches);
}

void
panda::PMuon::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::book(_tree, _name, _branches);
}

void
panda::PMuon::init()
{
  PLepton::init();
}


/* BEGIN CUSTOM */
/* END CUSTOM */
