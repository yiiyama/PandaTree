#include "../interface/PTau.h"

void
panda::PTau::array_data::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLeptonBase::array_data::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "isoDeltaBetaCorr", _status, _branches);
}

void
panda::PTau::array_data::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLeptonBase::array_data::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "isoDeltaBetaCorr", isoDeltaBetaCorr, _branches);
}

void
panda::PTau::array_data::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLeptonBase::array_data::book(_tree, _name, _branches);

  utils::book(_tree, _name, "isoDeltaBetaCorr", "[" + _name + ".size]", 'F', isoDeltaBetaCorr, _branches);
}

panda::PTau::PTau() :
  PLeptonBase(utils::Allocator<PTau>()),
  isoDeltaBetaCorr(gStore.getData(this).isoDeltaBetaCorr[gStore.getIndex(this)])
{
}

panda::PTau::PTau(PTau const& _src) :
  PLeptonBase(utils::Allocator<PTau>()),
  isoDeltaBetaCorr(gStore.getData(this).isoDeltaBetaCorr[gStore.getIndex(this)])
{
  PLeptonBase::operator=(_src);

  isoDeltaBetaCorr = _src.isoDeltaBetaCorr;
}

panda::PTau::PTau(array_data& _data, UInt_t _idx) :
  PLeptonBase(_data, _idx),
  isoDeltaBetaCorr(_data.isoDeltaBetaCorr[_idx])
{
}

panda::PTau::PTau(utils::AllocatorBase const& _allocator) :
  PLeptonBase(_allocator),
  isoDeltaBetaCorr(gStore.getData(this).isoDeltaBetaCorr[gStore.getIndex(this)])
{
}

panda::PTau::~PTau()
{
  gStore.free(this);
}

panda::PTau&
panda::PTau::operator=(PTau const& _src)
{
  PLeptonBase::operator=(_src);

  isoDeltaBetaCorr = _src.isoDeltaBetaCorr;

  return *this;
}

void
panda::PTau::setStatus(TTree& _tree, TString const& _name, Bool_t _status, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLeptonBase::setStatus(_tree, _name, _status, _branches);

  utils::setStatus(_tree, _name, "isoDeltaBetaCorr", _status, _branches);
}

void
panda::PTau::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLeptonBase::setAddress(_tree, _name, _branches);

  utils::setStatusAndAddress(_tree, _name, "isoDeltaBetaCorr", &isoDeltaBetaCorr, _branches);
}

void
panda::PTau::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PLeptonBase::book(_tree, _name, _branches);

  utils::book(_tree, _name, "isoDeltaBetaCorr", "", 'F', &isoDeltaBetaCorr, _branches);
}

void
panda::PTau::init()
{
  PLeptonBase::init();

  isoDeltaBetaCorr = 0.;
}

/* BEGIN CUSTOM */
/* END CUSTOM */
