#include "../interface/PackedParticle.h"

void
panda::PackedParticle::datastore::allocate(UInt_t _nmax)
{
  Particle::datastore::allocate(_nmax);

  packedPt = new UShort_t[nmax_];
  packedPhi = new Short_t[nmax_];
  packedM = new UShort_t[nmax_];
}

void
panda::PackedParticle::datastore::deallocate()
{
  Particle::datastore::deallocate();

  delete [] packedPt;
  packedPt = 0;
  delete [] packedPhi;
  packedPhi = 0;
  delete [] packedM;
  packedM = 0;
}

void
panda::PackedParticle::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Particle::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "packedPt", _branches);
  utils::setStatus(_tree, _name, "packedPhi", _branches);
  utils::setStatus(_tree, _name, "packedM", _branches);
}

panda::utils::BranchList
panda::PackedParticle::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Particle::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "packedPt"));
  blist.push_back(utils::getStatus(_tree, _name, "packedPhi"));
  blist.push_back(utils::getStatus(_tree, _name, "packedM"));

  return blist;
}

void
panda::PackedParticle::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "packedPt", packedPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedPhi", packedPhi, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedM", packedM, _branches, _setStatus);
}

void
panda::PackedParticle::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Particle::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "packedPt", size, 's', packedPt, _branches);
  utils::book(_tree, _name, "packedPhi", size, 'S', packedPhi, _branches);
  utils::book(_tree, _name, "packedM", size, 's', packedM, _branches);
}

void
panda::PackedParticle::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Particle::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "packedPt");
  utils::resetAddress(_tree, _name, "packedPhi");
  utils::resetAddress(_tree, _name, "packedM");
}

void
panda::PackedParticle::datastore::resizeVectors_(UInt_t _size)
{
  Particle::datastore::resizeVectors_(_size);

}

panda::PackedParticle::PackedParticle(char const* _name/* = ""*/) :
  Particle(new PackedParticleArray(1, _name)),
  packedPt(gStore.getData(this).packedPt[0]),
  packedPhi(gStore.getData(this).packedPhi[0]),
  packedM(gStore.getData(this).packedM[0])
{
}

panda::PackedParticle::PackedParticle(PackedParticle const& _src) :
  Particle(new PackedParticleArray(1, gStore.getName(&_src))),
  packedPt(gStore.getData(this).packedPt[0]),
  packedPhi(gStore.getData(this).packedPhi[0]),
  packedM(gStore.getData(this).packedM[0])
{
  Particle::operator=(_src);

  packedPt = _src.packedPt;
  packedPhi = _src.packedPhi;
  packedM = _src.packedM;
}

panda::PackedParticle::PackedParticle(datastore& _data, UInt_t _idx) :
  Particle(_data, _idx),
  packedPt(_data.packedPt[_idx]),
  packedPhi(_data.packedPhi[_idx]),
  packedM(_data.packedM[_idx])
{
}

panda::PackedParticle::PackedParticle(ArrayBase* _array) :
  Particle(_array),
  packedPt(gStore.getData(this).packedPt[0]),
  packedPhi(gStore.getData(this).packedPhi[0]),
  packedM(gStore.getData(this).packedM[0])
{
}

panda::PackedParticle::~PackedParticle()
{
  destructor();
  gStore.free(this);
}

void
panda::PackedParticle::destructor()
{
  /* BEGIN CUSTOM PackedParticle.cc.destructor */
  /* END CUSTOM */

  Particle::destructor();
}

panda::PackedParticle&
panda::PackedParticle::operator=(PackedParticle const& _src)
{
  Particle::operator=(_src);

  packedPt = _src.packedPt;
  packedPhi = _src.packedPhi;
  packedM = _src.packedM;

  return *this;
}

void
panda::PackedParticle::doSetStatus_(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Particle::doSetStatus_(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "packedPt", _branches);
  utils::setStatus(_tree, _name, "packedPhi", _branches);
  utils::setStatus(_tree, _name, "packedM", _branches);
}

panda::utils::BranchList
panda::PackedParticle::doGetStatus_(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Particle::doGetStatus_(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "packedPt"));
  blist.push_back(utils::getStatus(_tree, _name, "packedPhi"));
  blist.push_back(utils::getStatus(_tree, _name, "packedM"));

  return blist;
}

void
panda::PackedParticle::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::doSetAddress_(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "packedPt", &packedPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedPhi", &packedPhi, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedM", &packedM, _branches, _setStatus);
}

void
panda::PackedParticle::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  Particle::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "packedPt", "", 's', &packedPt, _branches);
  utils::book(_tree, _name, "packedPhi", "", 'S', &packedPhi, _branches);
  utils::book(_tree, _name, "packedM", "", 's', &packedM, _branches);
}

void
panda::PackedParticle::doReleaseTree_(TTree& _tree, TString const& _name)
{
  Particle::doReleaseTree_(_tree, _name);

  utils::resetAddress(_tree, _name, "packedPt");
  utils::resetAddress(_tree, _name, "packedPhi");
  utils::resetAddress(_tree, _name, "packedM");
}

void
panda::PackedParticle::doInit_()
{
  Particle::doInit_();

  packedPt = 0;
  packedPhi = 0;
  packedM = 0;

  /* BEGIN CUSTOM PackedParticle.cc.doInit_ */
  pt_ = 0.;
  eta_ = 0.;
  phi_ = 0.;
  mass_ = 0.;
  unpacked_ = kFALSE;
  /* END CUSTOM */
}


/* BEGIN CUSTOM PackedParticle.cc.global */

panda::PackingHelper::PackingHelper()
{
  // ==== mantissatable ===
  // -- zero --
  mantissatable[0] = 0;
  // -- denorm --
  for (unsigned int i = 1; i <= 1023; ++i) {
    unsigned int m =(i<<13), e=0;
    while(!(m&0x00800000)){ // While not normalized
      e-=0x00800000; // Decrement exponent (1<<23)
      m<<=1; // Shift mantissa
    }
    m&=~0x00800000; // Clear leading 1 bit
    e+= 0x38800000; // Adjust bias ((127-14)<<23)
    mantissatable[i] = m | e; 
  }
  // -- norm --
  for (unsigned int i = 1024; i <= 2047; ++i) {
    mantissatable[i] = 0x38000000 + ((i-1024)<<13);
  }
  // ==== exponenttable ===
  exponenttable[0] = 0;
  for (unsigned int i = 1; i <= 30; ++i) exponenttable[i] = i<<23;
  exponenttable[31] = 0x47800000;
  exponenttable[32] = 0x80000000u;
  for (unsigned int i = 33; i <= 62; ++i) exponenttable[i] = 0x80000000u | ((i-32)<<23);
  exponenttable[63] = 0xC7800000;
 
  // ==== offsettable ====
  for (unsigned int i = 0; i <= 63; ++i) offsettable[i] = ((i == 0 || i == 32) ? 0 : 1024);

  for (unsigned i=0; i<256; ++i){
    int e = int(i)-127;
    if(e<-24){ // Very small numbers map to zero
      basetable[i|0x000]=0x0000;
      basetable[i|0x100]=0x8000;
      shifttable[i|0x000]=24;
      shifttable[i|0x100]=24;
    }
    else if(e<-14){ // Small numbers map to denorms
      basetable[i|0x000]=(0x0400>>(-e-14));
      basetable[i|0x100]=(0x0400>>(-e-14)) | 0x8000;
      shifttable[i|0x000]=-e-1;
      shifttable[i|0x100]=-e-1;
    }
    else if(e<=15){ // Normal numbers just lose precision
      basetable[i|0x000]=((e+15)<<10);
      basetable[i|0x100]=((e+15)<<10) | 0x8000;
      shifttable[i|0x000]=13;
      shifttable[i|0x100]=13;
    }
    else if(e<128){ // Large numbers map to Infinity
      basetable[i|0x000]=0x7C00;
      basetable[i|0x100]=0xFC00;
      shifttable[i|0x000]=24;
      shifttable[i|0x100]=24;
    }
    else{ // Infinity and NaN's stay Infinity and NaN's
      basetable[i|0x000]=0x7C00;
      basetable[i|0x100]=0xFC00;
      shifttable[i|0x000]=13;
      shifttable[i|0x100]=13;
    }
  }
}

UShort_t
panda::PackingHelper::packUnbound(Double_t x)
{
  // Implementation copied from DataFormats/PatCandidates/interface/libminifloat.h
  // float32to16

  union {
    float flt;
    uint32_t i32;
  } conv;

  conv.flt = x;
  uint8_t shift = shifttable[(conv.i32>>23)&0x1ff];
  if (shift == 13) {
    uint16_t base2 = (conv.i32&0x007fffff)>>12;
    uint16_t base = base2 >> 1;
    if (((base2 & 1) != 0) && (base < 1023)) base++;
    return basetable[(conv.i32>>23)&0x1ff]+base; 
  }
  else {
    return basetable[(conv.i32>>23)&0x1ff]+((conv.i32&0x007fffff)>>shifttable[(conv.i32>>23)&0x1ff]);
  }
}

Double_t
panda::PackingHelper::unpackUnbound(UShort_t p)
{
  union {
    float flt;
    uint32_t i32;
  } conv;

  conv.i32 = mantissatable[offsettable[p>>10]+(p&0x3ff)]+exponenttable[p>>10];
  return conv.flt;
}

namespace panda {
  PackingHelper packingHelper;
}

/*static*/
void
panda::PackedParticle::setPtEtaPhiM(double pt, double eta, double phi, double m)
{
  pt_ = pt;
  eta_ = eta;
  phi_ = phi;
  mass_ = m;
  unpacked_ = true;
  pack_();
}

void
panda::PackedParticle::setXYZE(double px, double py, double pz, double e)
{
  pt_ = std::sqrt(px * px + py * py);
  double p(std::sqrt(px * px + py * py + pz * pz));
  eta_ = 0.5 * std::log((p + pz) / (p - pz));
  phi_ = std::atan2(py, px);
  mass_ = std::sqrt(e * e - p * p);
  unpacked_ = true;
  pack_();
}

void
panda::PackedParticle::pack_()
{
  packedPt = packingHelper.packUnbound(pt_);
  packedPhi = std::round(phi_/3.2f*std::numeric_limits<Short_t>::max());
  packedM = packingHelper.packUnbound(pt_);
  packEta_();
}

void
panda::PackedParticle::unpack_() const
{
  if (unpacked_)
    return;

  pt_ = packingHelper.unpackUnbound(packedPt);
  // shift particle phi to break degeneracies in angular separations
  // plus introduce a pseudo-random sign of the shift
  double shift(pt_ < 1. ? 0.1 * pt_ : 0.1 / pt_);
  double sign((int(pt_ * 10.) % 2 == 0) ? 1 : -1);
  phi_ = (packedPhi + sign * shift) * 3.2f / std::numeric_limits<Short_t>::max();
  mass_ = packingHelper.unpackUnbound(packedM);
  unpackEta_();

  unpacked_ = true;
}
/* END CUSTOM */
