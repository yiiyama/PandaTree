#include "../interface/PackedMomentumMixin.h"

/*static*/
panda::utils::BranchList
panda::PackedMomentumMixin::getListOfBranches()
{
  utils::BranchList blist;
  blist += {"packedPt", "packedEta", "packedPhi", "packedM"};
  return blist;
}

panda::PackedMomentumMixin::PackedMomentumMixin(datastore& _data, UInt_t _idx) :
  packedPt(_data.packedPt[_idx]),
  packedEta(_data.packedEta[_idx]),
  packedPhi(_data.packedPhi[_idx]),
  packedM(_data.packedM[_idx])
{
}

/* BEGIN CUSTOM PackedMomentumMixin.cc.global */
#include "../interface/PackingHelper.h"

void
panda::PackedMomentumMixin::pack_()
{
  packedPt = PackingHelper::singleton().packUnbound(pt_);
  packedEta = std::round(eta_ / 6.0f * std::numeric_limits<Short_t>::max());
  packedPhi = std::round(phi_/3.2f*std::numeric_limits<Short_t>::max());
  packedM = PackingHelper::singleton().packUnbound(mass_);
}

void
panda::PackedMomentumMixin::unpack_() const
{
  if (unpacked_)
    return;

  pt_ = PackingHelper::singleton().unpackUnbound(packedPt);
  // shift particle phi to break degeneracies in angular separations
  // plus introduce a pseudo-random sign of the shift
  double shift(pt_ < 1. ? 0.1 * pt_ : 0.1 / pt_);
  double sign((int(pt_ * 10.) % 2 == 0) ? 1 : -1);
  phi_ = (packedPhi + sign * shift) * 3.2f / std::numeric_limits<Short_t>::max();
  mass_ = PackingHelper::singleton().unpackUnbound(packedM);
  eta_ = packedEta * 6.0f / std::numeric_limits<Short_t>::max();

  unpacked_ = true;
}

void
panda::PackedMomentumMixin::setPtEtaPhiMPacked_(double pt, double eta, double phi, double m)
{
  pt_ = pt;
  eta_ = eta;
  phi_ = phi;
  mass_ = m;
  unpacked_ = true;
  pack_();
}

void
panda::PackedMomentumMixin::setXYZEPacked_(double px, double py, double pz, double e)
{
  pt_ = std::sqrt(px * px + py * py);
  double p(std::sqrt(px * px + py * py + pz * pz));
  eta_ = 0.5 * std::log((p + pz) / (p - pz));
  phi_ = std::atan2(py, px);
  mass_ = std::sqrt(e * e - p * p);
  unpacked_ = true;
  pack_();
}
/* END CUSTOM */
