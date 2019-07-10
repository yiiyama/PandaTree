#include "../interface/PtEtaPhiMixin.h"

/*static*/
panda::utils::BranchList
panda::PtEtaPhiMixin::getListOfBranches()
{
  utils::BranchList blist;
  blist += {"pt_", "eta_", "phi_"};
  return blist;
}

panda::PtEtaPhiMixin::PtEtaPhiMixin(datastore& _data, UInt_t _idx) :
  pt_(_data.pt_[_idx]),
  eta_(_data.eta_[_idx]),
  phi_(_data.phi_[_idx])
{
}

/* BEGIN CUSTOM PtEtaPhiMixin.cc.global */
/* END CUSTOM */
