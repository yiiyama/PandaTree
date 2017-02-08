#include "../interface/PackedParticle.h"

void
panda::PackedParticle::datastore::allocate(UInt_t _nmax)
{
  Particle::datastore::allocate(_nmax);

  packedPt_ = new UShort_t[nmax_];
  packedEta_ = new UShort_t[nmax_];
  packedPhi_ = new UShort_t[nmax_];
  packedM_ = new UShort_t[nmax_];
}

void
panda::PackedParticle::datastore::deallocate()
{
  Particle::datastore::deallocate();

  delete [] packedPt_;
  packedPt_ = 0;
  delete [] packedEta_;
  packedEta_ = 0;
  delete [] packedPhi_;
  packedPhi_ = 0;
  delete [] packedM_;
  packedM_ = 0;
}

void
panda::PackedParticle::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Particle::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "packedPt_", _branches);
  utils::setStatus(_tree, _name, "packedEta_", _branches);
  utils::setStatus(_tree, _name, "packedPhi_", _branches);
  utils::setStatus(_tree, _name, "packedM_", _branches);
}

panda::utils::BranchList
panda::PackedParticle::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Particle::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "packedPt_"));
  blist.push_back(utils::getStatus(_tree, _name, "packedEta_"));
  blist.push_back(utils::getStatus(_tree, _name, "packedPhi_"));
  blist.push_back(utils::getStatus(_tree, _name, "packedM_"));

  return blist;
}

void
panda::PackedParticle::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "packedPt_", packedPt_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedEta_", packedEta_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedPhi_", packedPhi_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedM_", packedM_, _branches, _setStatus);
}

void
panda::PackedParticle::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Particle::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "packedPt_", size, 's', packedPt_, _branches);
  utils::book(_tree, _name, "packedEta_", size, 's', packedEta_, _branches);
  utils::book(_tree, _name, "packedPhi_", size, 's', packedPhi_, _branches);
  utils::book(_tree, _name, "packedM_", size, 's', packedM_, _branches);
}

void
panda::PackedParticle::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Particle::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "packedPt_");
  utils::resetAddress(_tree, _name, "packedEta_");
  utils::resetAddress(_tree, _name, "packedPhi_");
  utils::resetAddress(_tree, _name, "packedM_");
}

void
panda::PackedParticle::datastore::resizeVectors_(UInt_t _size)
{
  Particle::datastore::resizeVectors_(_size);

}

panda::PackedParticle::PackedParticle(char const* _name/* = ""*/) :
  Particle(new PackedParticleArray(1, _name)),
  packedPt_(gStore.getData(this).packedPt_[0]),
  packedEta_(gStore.getData(this).packedEta_[0]),
  packedPhi_(gStore.getData(this).packedPhi_[0]),
  packedM_(gStore.getData(this).packedM_[0])
{
}

panda::PackedParticle::PackedParticle(PackedParticle const& _src) :
  Particle(new PackedParticleArray(1, gStore.getName(&_src))),
  packedPt_(gStore.getData(this).packedPt_[0]),
  packedEta_(gStore.getData(this).packedEta_[0]),
  packedPhi_(gStore.getData(this).packedPhi_[0]),
  packedM_(gStore.getData(this).packedM_[0])
{
  Particle::operator=(_src);

  packedPt_ = _src.packedPt_;
  packedEta_ = _src.packedEta_;
  packedPhi_ = _src.packedPhi_;
  packedM_ = _src.packedM_;
}

panda::PackedParticle::PackedParticle(datastore& _data, UInt_t _idx) :
  Particle(_data, _idx),
  packedPt_(_data.packedPt_[_idx]),
  packedEta_(_data.packedEta_[_idx]),
  packedPhi_(_data.packedPhi_[_idx]),
  packedM_(_data.packedM_[_idx])
{
}

panda::PackedParticle::PackedParticle(ArrayBase* _array) :
  Particle(_array),
  packedPt_(gStore.getData(this).packedPt_[0]),
  packedEta_(gStore.getData(this).packedEta_[0]),
  packedPhi_(gStore.getData(this).packedPhi_[0]),
  packedM_(gStore.getData(this).packedM_[0])
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

  packedPt_ = _src.packedPt_;
  packedEta_ = _src.packedEta_;
  packedPhi_ = _src.packedPhi_;
  packedM_ = _src.packedM_;

  return *this;
}

void
panda::PackedParticle::doSetStatus_(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Particle::doSetStatus_(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "packedPt_", _branches);
  utils::setStatus(_tree, _name, "packedEta_", _branches);
  utils::setStatus(_tree, _name, "packedPhi_", _branches);
  utils::setStatus(_tree, _name, "packedM_", _branches);
}

panda::utils::BranchList
panda::PackedParticle::doGetStatus_(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Particle::doGetStatus_(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "packedPt_"));
  blist.push_back(utils::getStatus(_tree, _name, "packedEta_"));
  blist.push_back(utils::getStatus(_tree, _name, "packedPhi_"));
  blist.push_back(utils::getStatus(_tree, _name, "packedM_"));

  return blist;
}

void
panda::PackedParticle::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::doSetAddress_(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "packedPt_", &packedPt_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedEta_", &packedEta_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedPhi_", &packedPhi_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedM_", &packedM_, _branches, _setStatus);
}

void
panda::PackedParticle::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  Particle::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "packedPt_", "", 's', &packedPt_, _branches);
  utils::book(_tree, _name, "packedEta_", "", 's', &packedEta_, _branches);
  utils::book(_tree, _name, "packedPhi_", "", 's', &packedPhi_, _branches);
  utils::book(_tree, _name, "packedM_", "", 's', &packedM_, _branches);
}

void
panda::PackedParticle::doReleaseTree_(TTree& _tree, TString const& _name)
{
  Particle::doReleaseTree_(_tree, _name);

  utils::resetAddress(_tree, _name, "packedPt_");
  utils::resetAddress(_tree, _name, "packedEta_");
  utils::resetAddress(_tree, _name, "packedPhi_");
  utils::resetAddress(_tree, _name, "packedM_");
}

void
panda::PackedParticle::doInit_()
{
  Particle::doInit_();

  packedPt_ = 0;
  packedEta_ = 0;
  packedPhi_ = 0;
  packedM_ = 0;

  /* BEGIN CUSTOM PackedParticle.cc.doInit_ */
  pt_ = 0.;
  eta_ = 0.;
  phi_ = 0.;
  mass_ = 0.;
  unpacked_ = kFALSE;
  /* END CUSTOM */
}


/* BEGIN CUSTOM PackedParticle.cc.global */
void
panda::PackedParticle::setPtEtaPhiM(double pt, double eta, double phi, double m)
{

}

void
panda::PackedParticle::setXYZE(double px, double py, double pz, double e)
{

}

void
panda::PackedParticle::unpack_() const
{

}
/* END CUSTOM */
