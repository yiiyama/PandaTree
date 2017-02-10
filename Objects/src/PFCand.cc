#include "../interface/PFCand.h"

/*static*/
int panda::PFCand::q_[nPTypes] = {1, -1, 1, -1, 1, -1, 0, 0, 0, 0, 1, -1, 0};
/*static*/
int panda::PFCand::pdgId_[nPTypes] = {211, -211, -11, 11, -13, 13, 22, 130, 1, 2, 0, 0, 0};

void
panda::PFCand::datastore::allocate(UInt_t _nmax)
{
  PackedParticle::datastore::allocate(_nmax);

  packedEta = new Short_t[nmax_];
  packedPuppiW = new Char_t[nmax_];
  packedPuppiWNoLepDiff = new Char_t[nmax_];
  ptype = new UChar_t[nmax_];
}

void
panda::PFCand::datastore::deallocate()
{
  PackedParticle::datastore::deallocate();

  delete [] packedEta;
  packedEta = 0;
  delete [] packedPuppiW;
  packedPuppiW = 0;
  delete [] packedPuppiWNoLepDiff;
  packedPuppiWNoLepDiff = 0;
  delete [] ptype;
  ptype = 0;
}

void
panda::PFCand::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  PackedParticle::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "packedEta", _branches);
  utils::setStatus(_tree, _name, "packedPuppiW", _branches);
  utils::setStatus(_tree, _name, "packedPuppiWNoLepDiff", _branches);
  utils::setStatus(_tree, _name, "ptype", _branches);
}

panda::utils::BranchList
panda::PFCand::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(PackedParticle::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "packedEta"));
  blist.push_back(utils::getStatus(_tree, _name, "packedPuppiW"));
  blist.push_back(utils::getStatus(_tree, _name, "packedPuppiWNoLepDiff"));
  blist.push_back(utils::getStatus(_tree, _name, "ptype"));

  return blist;
}

void
panda::PFCand::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PackedParticle::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "packedEta", packedEta, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedPuppiW", packedPuppiW, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedPuppiWNoLepDiff", packedPuppiWNoLepDiff, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptype", ptype, _branches, _setStatus);
}

void
panda::PFCand::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PackedParticle::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "packedEta", size, 'S', packedEta, _branches);
  utils::book(_tree, _name, "packedPuppiW", size, 'B', packedPuppiW, _branches);
  utils::book(_tree, _name, "packedPuppiWNoLepDiff", size, 'B', packedPuppiWNoLepDiff, _branches);
  utils::book(_tree, _name, "ptype", size, 'b', ptype, _branches);
}

void
panda::PFCand::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  PackedParticle::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "packedEta");
  utils::resetAddress(_tree, _name, "packedPuppiW");
  utils::resetAddress(_tree, _name, "packedPuppiWNoLepDiff");
  utils::resetAddress(_tree, _name, "ptype");
}

void
panda::PFCand::datastore::resizeVectors_(UInt_t _size)
{
  PackedParticle::datastore::resizeVectors_(_size);

}

panda::PFCand::PFCand(char const* _name/* = ""*/) :
  PackedParticle(new PFCandArray(1, _name)),
  packedEta(gStore.getData(this).packedEta[0]),
  packedPuppiW(gStore.getData(this).packedPuppiW[0]),
  packedPuppiWNoLepDiff(gStore.getData(this).packedPuppiWNoLepDiff[0]),
  ptype(gStore.getData(this).ptype[0])
{
}

panda::PFCand::PFCand(PFCand const& _src) :
  PackedParticle(new PFCandArray(1, gStore.getName(&_src))),
  packedEta(gStore.getData(this).packedEta[0]),
  packedPuppiW(gStore.getData(this).packedPuppiW[0]),
  packedPuppiWNoLepDiff(gStore.getData(this).packedPuppiWNoLepDiff[0]),
  ptype(gStore.getData(this).ptype[0])
{
  PackedParticle::operator=(_src);

  packedEta = _src.packedEta;
  packedPuppiW = _src.packedPuppiW;
  packedPuppiWNoLepDiff = _src.packedPuppiWNoLepDiff;
  ptype = _src.ptype;
}

panda::PFCand::PFCand(datastore& _data, UInt_t _idx) :
  PackedParticle(_data, _idx),
  packedEta(_data.packedEta[_idx]),
  packedPuppiW(_data.packedPuppiW[_idx]),
  packedPuppiWNoLepDiff(_data.packedPuppiWNoLepDiff[_idx]),
  ptype(_data.ptype[_idx])
{
}

panda::PFCand::PFCand(ArrayBase* _array) :
  PackedParticle(_array),
  packedEta(gStore.getData(this).packedEta[0]),
  packedPuppiW(gStore.getData(this).packedPuppiW[0]),
  packedPuppiWNoLepDiff(gStore.getData(this).packedPuppiWNoLepDiff[0]),
  ptype(gStore.getData(this).ptype[0])
{
}

panda::PFCand::~PFCand()
{
  destructor();
  gStore.free(this);
}

void
panda::PFCand::destructor()
{
  /* BEGIN CUSTOM PFCand.cc.destructor */
  /* END CUSTOM */

  PackedParticle::destructor();
}

panda::PFCand&
panda::PFCand::operator=(PFCand const& _src)
{
  PackedParticle::operator=(_src);

  packedEta = _src.packedEta;
  packedPuppiW = _src.packedPuppiW;
  packedPuppiWNoLepDiff = _src.packedPuppiWNoLepDiff;
  ptype = _src.ptype;

  return *this;
}

void
panda::PFCand::doSetStatus_(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  PackedParticle::doSetStatus_(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "packedEta", _branches);
  utils::setStatus(_tree, _name, "packedPuppiW", _branches);
  utils::setStatus(_tree, _name, "packedPuppiWNoLepDiff", _branches);
  utils::setStatus(_tree, _name, "ptype", _branches);
}

panda::utils::BranchList
panda::PFCand::doGetStatus_(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(PackedParticle::doGetStatus_(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "packedEta"));
  blist.push_back(utils::getStatus(_tree, _name, "packedPuppiW"));
  blist.push_back(utils::getStatus(_tree, _name, "packedPuppiWNoLepDiff"));
  blist.push_back(utils::getStatus(_tree, _name, "ptype"));

  return blist;
}

void
panda::PFCand::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PackedParticle::doSetAddress_(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "packedEta", &packedEta, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedPuppiW", &packedPuppiW, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedPuppiWNoLepDiff", &packedPuppiWNoLepDiff, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptype", &ptype, _branches, _setStatus);
}

void
panda::PFCand::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PackedParticle::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "packedEta", "", 'S', &packedEta, _branches);
  utils::book(_tree, _name, "packedPuppiW", "", 'B', &packedPuppiW, _branches);
  utils::book(_tree, _name, "packedPuppiWNoLepDiff", "", 'B', &packedPuppiWNoLepDiff, _branches);
  utils::book(_tree, _name, "ptype", "", 'b', &ptype, _branches);
}

void
panda::PFCand::doReleaseTree_(TTree& _tree, TString const& _name)
{
  PackedParticle::doReleaseTree_(_tree, _name);

  utils::resetAddress(_tree, _name, "packedEta");
  utils::resetAddress(_tree, _name, "packedPuppiW");
  utils::resetAddress(_tree, _name, "packedPuppiWNoLepDiff");
  utils::resetAddress(_tree, _name, "ptype");
}

void
panda::PFCand::doInit_()
{
  PackedParticle::doInit_();

  packedEta = 0;
  packedPuppiW = 0;
  packedPuppiWNoLepDiff = 0;
  ptype = 0;

  /* BEGIN CUSTOM PFCand.cc.doInit_ */
  /* END CUSTOM */
}


/* BEGIN CUSTOM PFCand.cc.global */
namespace panda {
  extern PackingHelper packingHelper;
}

void
panda::PFCand::pack_()
{
  packedPt = packingHelper.packUnbound(pt_);
  packedPhi = std::round(phi_/3.2f*std::numeric_limits<Short_t>::max());
  packedM = packingHelper.packUnbound(pt_);
  packedEta = std::round(eta_ / 6.0f * std::numeric_limits<Short_t>::max());

  packedPuppiW = packingHelper.pack8LogBound((puppiW_ - 0.5) * 2., -2., 0., 64);
  packedPuppiWNoLepDiff = packingHelper.pack8LogBound((puppiWNoLep_ - 0.5) * 2., -2., 0., 64) - packedPuppiW;
}

void
panda::PFCand::unpack_() const
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
  eta_ = packedEta * 6.0f / std::numeric_limits<Short_t>::max();

  puppiW_ = packingHelper.unpack8LogBound(packedPuppiW, -2., 0., 64) * 0.5 + 0.5;
  puppiWNoLep_ = packingHelper.unpack8LogBound(packedPuppiWNoLepDiff + packedPuppiW, -2., 0., 64) * 0.5 + 0.5;

  unpacked_ = true;
}

void
panda::PFCand::setPuppiW(double w, double wnl)
{
  puppiW_ = w;
  packedPuppiW = packingHelper.pack8LogBound((puppiW_ - 0.5) * 2., -2., 0., 64);
  puppiWNoLep_ = wnl;
  packedPuppiWNoLepDiff = packingHelper.pack8LogBound((puppiWNoLep_ - 0.5) * 2., -2., 0., 64) - packedPuppiW;
}
/* END CUSTOM */
