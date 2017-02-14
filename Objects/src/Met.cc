#include "../interface/Met.h"

/*static*/
panda::utils::BranchList
panda::Met::getListOfBranches()
{
  utils::BranchList blist;
  blist += {"pt", "phi"};
  return blist;
}

panda::Met::Met(char const* _name/* = ""*/) :
  Singlet(_name)
{
}

panda::Met::Met(Met const& _src) :
  Singlet(_src.name_),
  pt(_src.pt),
  phi(_src.phi)
{
  pt = _src.pt;
  phi = _src.phi;
}

panda::Met::~Met()
{
}

panda::Met&
panda::Met::operator=(Met const& _src)
{
  pt = _src.pt;
  phi = _src.phi;

  return *this;
}

void
panda::Met::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::setStatus(_tree, name_, "pt", _branches);
  utils::setStatus(_tree, name_, "phi", _branches);
}

panda::utils::BranchList
panda::Met::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;

  blist.push_back(utils::getStatus(_tree, name_, "pt"));
  blist.push_back(utils::getStatus(_tree, name_, "phi"));

  return blist;
}

void
panda::Met::doSetAddress_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  utils::setAddress(_tree, name_, "pt", &pt, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phi", &phi, _branches, _setStatus);
}

void
panda::Met::doBook_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  utils::book(_tree, name_, "pt", "", 'F', &pt, _branches);
  utils::book(_tree, name_, "phi", "", 'F', &phi, _branches);
}

void
panda::Met::doReleaseTree_(TTree& _tree)
{
  utils::resetAddress(_tree, name_, "pt");
  utils::resetAddress(_tree, name_, "phi");
}

void
panda::Met::doInit_()
{
  pt = 0.;
  phi = 0.;

  /* BEGIN CUSTOM Met.cc.doInit_ */
  /* END CUSTOM */
}

panda::utils::BranchList
panda::Met::doGetBranchNames_() const
{
  return getListOfBranches().fullNames(name_);
}

void
panda::Met::print(std::ostream& _out/* = std::cout*/) const
{
  /* BEGIN CUSTOM Met.cc.print */
  /* END CUSTOM */
}


/* BEGIN CUSTOM Met.cc.global */
/* END CUSTOM */
