#include "../interface/PElectron.h"

void
panda::PElectron::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::array_data::setStatus(_tree, _name, _status, _branches);
}

void
panda::PElectron::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::array_data::setAddress(_tree, _name, _branches);
}

void
panda::PElectron::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::array_data::book(_tree, _name, _branches);
}

panda::PElectron::PElectron() :
  PLepton(utils::Allocator<PElectron>())
{
}

panda::PElectron::PElectron(PElectron const& _src) :
  PLepton(utils::Allocator<PElectron>())
{
  PLepton::operator=(_src);
}

panda::PElectron::PElectron(array_data& _data, UInt_t _idx) :
  PLepton(_data, _idx)
{
}

panda::PElectron::PElectron(utils::AllocatorBase const& _allocator) :
  PLepton(_allocator)
{
}

panda::PElectron::~PElectron()
{
  gStore.free(this);
}

panda::PElectron&
panda::PElectron::operator=(PElectron const& _src)
{
  PLepton::operator=(_src);

  return *this;
}

void
panda::PElectron::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::setStatus(_tree, _name, _status, _branches);
}

void
panda::PElectron::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::setAddress(_tree, _name, _branches);
}

void
panda::PElectron::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLepton::book(_tree, _name, _branches);
}

void
panda::PElectron::init()
{
  PLepton::init();
}

/* BEGIN CUSTOM */
/* END CUSTOM */
