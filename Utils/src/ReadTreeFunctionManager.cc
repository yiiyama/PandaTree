#ifndef PandaTree_Objects_ReadTreeFunctionManager_h
#define PandaTree_Objects_ReadTreeFunctionManager_h

// This standalone class allows you to unpack interactively instead of relying on tabulated info.
// After compiling PandaAnalysis using scram, you can call the following in CINT:
//   #include "PandaTree/Utils/src/ReadTreeFunctionManager.cc"
// and then perform a TTree Draw or Scan e.g.
//   events->Scan("panda::rtfm::up(genParticles.packedPt)")
// This is the analog of panda::PackingHelper::unpackUnbound
// For the analog of panda::PackingHelper::unpack8LogBound, use panda::rtfm::up8(...)
// For phi, use panda::rtfm::upPhi(packedPhi,packedPt)
// For eta, use panda::rtfm::upEta(packedEta)

#include "Rtypes.h"
#include <cmath>
#include <limits>

namespace panda {
  class ReadTreeFunctionManager {
  public:
    ReadTreeFunctionManager();

    static Double_t up(UShort_t p);
    static Double_t upEta(UShort_t packedEta);
    static Double_t upPhi(UShort_t packedPhi, UShort_t packedPt);
    static Double_t up8(Char_t, Double_t min=-2, Double_t max=0, UChar_t baseminus1=64);
  };
  typedef ReadTreeFunctionManager rtfm;
}

Double_t
panda::ReadTreeFunctionManager::up(UShort_t p)
// use for pt
{
  if(p==0) return 0;
  union {
    float flt;
    uint32_t i32;
  } conv;

  UShort_t offset;
  UInt_t mantissa,exponent;
  Int_t i;
  
  // set offset
  if(p>>10 == 0 || p>>10 == 32) offset=0;
  else                          offset=1024;
  
  // set mantissa
  i=offset+(p&0x3ff);
  unsigned m = (i<<13);
  unsigned e = 0;
  while ((m & 0x00800000) == 0) { // While not normalized
    e -= 0x00800000; // Decrement exponent (1<<23)
    m <<= 1; // Shift mantissa
  }
  m &= ~0x00800000; // Clear leading 1 bit
  e += 0x38800000; // Adjust bias ((127-14)<<23)
  mantissa = m | e; 
  
  // set exponent
  i=p>>10;
  if(i==0)
    exponent=0;
  else if(i<=30)
    exponent = (i<<23);
  else if(i==32)
    exponent = 0x47800000;
  else if(i==33)
    exponent = 0x80000000u;
  else if(i<=62)
    exponent = 0x80000000u | ((i - 32) << 23);
  else if(i==63)
    exponent = 0xC7800000;
  
  conv.i32 = mantissa+exponent;
  return conv.flt;
}

Double_t
panda::ReadTreeFunctionManager::up8(Char_t i, Double_t min, Double_t max, UChar_t baseminus1)
// use for panda::PFCand::packedPuppiW
{
  if (baseminus1 > 127)
    baseminus1 = 127;

  double l;
  if (std::abs(i) == baseminus1)
    l = max;
  else
    l = min + std::abs(i) * (max - min) / baseminus1;

  double val(std::exp(l));
  if (i < 0)
    return -val;
  else
    return val;
}
Double_t
panda::ReadTreeFunctionManager::upPhi(UShort_t packedPhi, UShort_t packedPt) {
  double pt_ = up(packedPt);
  double shift(pt_ < 1. ? 0.1 * pt_ : 0.1 / pt_);
  double sign((int(pt_ * 10.) % 2 == 0) ? 1 : -1);
  double phi_ = (packedPhi + sign * shift) * 3.2f / std::numeric_limits<Short_t>::max();
  return phi_;
}
Double_t
panda::ReadTreeFunctionManager::upEta(UShort_t packedEta) {
  double eta_ = packedEta * 6.0f / std::numeric_limits<Short_t>::max();
  return eta_;
}
#endif
