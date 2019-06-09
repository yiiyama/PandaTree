#include "../interface/PtEtaPhiMMixin.h"

panda::PtEtaPhiMMixin::PtEtaPhiMMixin(datastore& _data, UInt_t _idx) :
  pt_(_data.pt_[_idx]),
  eta_(_data.eta_[_idx]),
  phi_(_data.phi_[_idx]),
  mass_(_data.mass_[_idx])
{
}

/* BEGIN CUSTOM PtEtaPhiMMixin.cc.global */
/* END CUSTOM */
