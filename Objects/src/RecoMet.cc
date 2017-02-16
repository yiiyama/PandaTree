#include "../interface/RecoMet.h"

/*static*/
panda::utils::BranchList
panda::RecoMet::getListOfBranches()
{
  utils::BranchList blist;
  blist += Met::getListOfBranches();
  blist += {"sumETRaw", "ptCorrUp", "phiCorrUp", "ptCorrDown", "phiCorrDown", "ptUnclUp", "phiUnclUp", "ptUnclDown", "phiUnclDown"};
  return blist;
}

panda::RecoMet::RecoMet(char const* _name/* = ""*/) :
  Met(_name)
{
}

panda::RecoMet::RecoMet(RecoMet const& _src) :
  Met(_src.name_),
  sumETRaw(_src.sumETRaw),
  ptCorrUp(_src.ptCorrUp),
  phiCorrUp(_src.phiCorrUp),
  ptCorrDown(_src.ptCorrDown),
  phiCorrDown(_src.phiCorrDown),
  ptUnclUp(_src.ptUnclUp),
  phiUnclUp(_src.phiUnclUp),
  ptUnclDown(_src.ptUnclDown),
  phiUnclDown(_src.phiUnclDown)
{
  sumETRaw = _src.sumETRaw;
  ptCorrUp = _src.ptCorrUp;
  phiCorrUp = _src.phiCorrUp;
  ptCorrDown = _src.ptCorrDown;
  phiCorrDown = _src.phiCorrDown;
  ptUnclUp = _src.ptUnclUp;
  phiUnclUp = _src.phiUnclUp;
  ptUnclDown = _src.ptUnclDown;
  phiUnclDown = _src.phiUnclDown;
}

panda::RecoMet::~RecoMet()
{
}

panda::RecoMet&
panda::RecoMet::operator=(RecoMet const& _src)
{
  Met::operator=(_src);

  sumETRaw = _src.sumETRaw;
  ptCorrUp = _src.ptCorrUp;
  phiCorrUp = _src.phiCorrUp;
  ptCorrDown = _src.ptCorrDown;
  phiCorrDown = _src.phiCorrDown;
  ptUnclUp = _src.ptUnclUp;
  phiUnclUp = _src.phiUnclUp;
  ptUnclDown = _src.ptUnclDown;
  phiUnclDown = _src.phiUnclDown;

  return *this;
}

void
panda::RecoMet::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  Met::doSetStatus_(_tree, _branches);

  utils::setStatus(_tree, name_, "sumETRaw", _branches);
  utils::setStatus(_tree, name_, "ptCorrUp", _branches);
  utils::setStatus(_tree, name_, "phiCorrUp", _branches);
  utils::setStatus(_tree, name_, "ptCorrDown", _branches);
  utils::setStatus(_tree, name_, "phiCorrDown", _branches);
  utils::setStatus(_tree, name_, "ptUnclUp", _branches);
  utils::setStatus(_tree, name_, "phiUnclUp", _branches);
  utils::setStatus(_tree, name_, "ptUnclDown", _branches);
  utils::setStatus(_tree, name_, "phiUnclDown", _branches);
}

panda::utils::BranchList
panda::RecoMet::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist(Met::doGetStatus_(_tree));

  blist.push_back(utils::getStatus(_tree, name_, "sumETRaw"));
  blist.push_back(utils::getStatus(_tree, name_, "ptCorrUp"));
  blist.push_back(utils::getStatus(_tree, name_, "phiCorrUp"));
  blist.push_back(utils::getStatus(_tree, name_, "ptCorrDown"));
  blist.push_back(utils::getStatus(_tree, name_, "phiCorrDown"));
  blist.push_back(utils::getStatus(_tree, name_, "ptUnclUp"));
  blist.push_back(utils::getStatus(_tree, name_, "phiUnclUp"));
  blist.push_back(utils::getStatus(_tree, name_, "ptUnclDown"));
  blist.push_back(utils::getStatus(_tree, name_, "phiUnclDown"));

  return blist;
}

void
panda::RecoMet::doSetAddress_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Met::doSetAddress_(_tree, _branches, _setStatus);

  utils::setAddress(_tree, name_, "sumETRaw", &sumETRaw, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ptCorrUp", &ptCorrUp, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phiCorrUp", &phiCorrUp, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ptCorrDown", &ptCorrDown, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phiCorrDown", &phiCorrDown, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ptUnclUp", &ptUnclUp, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phiUnclUp", &phiUnclUp, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ptUnclDown", &ptUnclDown, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phiUnclDown", &phiUnclDown, _branches, _setStatus);
}

void
panda::RecoMet::doBook_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  Met::doBook_(_tree, _branches);

  utils::book(_tree, name_, "sumETRaw", "", 'F', &sumETRaw, _branches);
  utils::book(_tree, name_, "ptCorrUp", "", 'F', &ptCorrUp, _branches);
  utils::book(_tree, name_, "phiCorrUp", "", 'F', &phiCorrUp, _branches);
  utils::book(_tree, name_, "ptCorrDown", "", 'F', &ptCorrDown, _branches);
  utils::book(_tree, name_, "phiCorrDown", "", 'F', &phiCorrDown, _branches);
  utils::book(_tree, name_, "ptUnclUp", "", 'F', &ptUnclUp, _branches);
  utils::book(_tree, name_, "phiUnclUp", "", 'F', &phiUnclUp, _branches);
  utils::book(_tree, name_, "ptUnclDown", "", 'F', &ptUnclDown, _branches);
  utils::book(_tree, name_, "phiUnclDown", "", 'F', &phiUnclDown, _branches);
}

void
panda::RecoMet::doReleaseTree_(TTree& _tree)
{
  Met::doReleaseTree_(_tree);

  utils::resetAddress(_tree, name_, "sumETRaw");
  utils::resetAddress(_tree, name_, "ptCorrUp");
  utils::resetAddress(_tree, name_, "phiCorrUp");
  utils::resetAddress(_tree, name_, "ptCorrDown");
  utils::resetAddress(_tree, name_, "phiCorrDown");
  utils::resetAddress(_tree, name_, "ptUnclUp");
  utils::resetAddress(_tree, name_, "phiUnclUp");
  utils::resetAddress(_tree, name_, "ptUnclDown");
  utils::resetAddress(_tree, name_, "phiUnclDown");
}

void
panda::RecoMet::doInit_()
{
  Met::doInit_();

  sumETRaw = 0.;
  ptCorrUp = 0.;
  phiCorrUp = 0.;
  ptCorrDown = 0.;
  phiCorrDown = 0.;
  ptUnclUp = 0.;
  phiUnclUp = 0.;
  ptUnclDown = 0.;
  phiUnclDown = 0.;

  /* BEGIN CUSTOM RecoMet.cc.doInit_ */
  /* END CUSTOM */
}

panda::utils::BranchList
panda::RecoMet::doGetBranchNames_(Bool_t _fullName) const
{
  if (_fullName)
    return getListOfBranches().fullNames(name_);
  else
    return getListOfBranches().fullNames();
}

void
panda::RecoMet::print(std::ostream& _out/* = std::cout*/) const
{
  /* BEGIN CUSTOM RecoMet.cc.print */
  /* END CUSTOM */
}

TVector2
panda::RecoMet::vCorr(int corr/* = 0*/) const
{
  if (corr == 0)
    return v();

  TVector2 vec;
  switch (corr) {
  case 1:
    vec.SetMagPhi(ptCorrUp, phiCorrUp);
    break;
  case -1:
    vec.SetMagPhi(ptCorrDown, phiCorrDown);
    break;
  }
  return vec;
}


/* BEGIN CUSTOM RecoMet.cc.global */
/* END CUSTOM */
