#include "../interface/PFCand.h"

/*static*/
panda::utils::BranchList
panda::PFCand::getListOfBranches()
{
  utils::BranchList blist;
  blist += PFCandBase::getListOfBranches();
  blist += PackedMomentumMixin::getListOfBranches();
  blist += {"packedPuppiW", "packedPuppiWNoLepDiff"};
  return blist;
}

void
panda::PFCand::datastore::allocate(UInt_t _nmax)
{
  PFCandBase::datastore::allocate(_nmax);

  packedPt = new UShort_t[nmax_];
  packedEta = new Short_t[nmax_];
  packedPhi = new Short_t[nmax_];
  packedM = new UShort_t[nmax_];
  packedPuppiW = new Char_t[nmax_];
  packedPuppiWNoLepDiff = new Char_t[nmax_];
}

void
panda::PFCand::datastore::deallocate()
{
  PFCandBase::datastore::deallocate();

  delete [] packedPt;
  packedPt = 0;
  delete [] packedEta;
  packedEta = 0;
  delete [] packedPhi;
  packedPhi = 0;
  delete [] packedM;
  packedM = 0;
  delete [] packedPuppiW;
  packedPuppiW = 0;
  delete [] packedPuppiWNoLepDiff;
  packedPuppiWNoLepDiff = 0;
}

void
panda::PFCand::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  PFCandBase::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "packedPt", _branches);
  utils::setStatus(_tree, _name, "packedEta", _branches);
  utils::setStatus(_tree, _name, "packedPhi", _branches);
  utils::setStatus(_tree, _name, "packedM", _branches);
  utils::setStatus(_tree, _name, "packedPuppiW", _branches);
  utils::setStatus(_tree, _name, "packedPuppiWNoLepDiff", _branches);
}

panda::utils::BranchList
panda::PFCand::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(PFCandBase::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "packedPt"));
  blist.push_back(utils::getStatus(_tree, _name, "packedEta"));
  blist.push_back(utils::getStatus(_tree, _name, "packedPhi"));
  blist.push_back(utils::getStatus(_tree, _name, "packedM"));
  blist.push_back(utils::getStatus(_tree, _name, "packedPuppiW"));
  blist.push_back(utils::getStatus(_tree, _name, "packedPuppiWNoLepDiff"));

  return blist;
}

void
panda::PFCand::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PFCandBase::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "packedPt", packedPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedEta", packedEta, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedPhi", packedPhi, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedM", packedM, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedPuppiW", packedPuppiW, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedPuppiWNoLepDiff", packedPuppiWNoLepDiff, _branches, _setStatus);
}

void
panda::PFCand::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PFCandBase::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "packedPt", size, 's', packedPt, _branches);
  utils::book(_tree, _name, "packedEta", size, 'S', packedEta, _branches);
  utils::book(_tree, _name, "packedPhi", size, 'S', packedPhi, _branches);
  utils::book(_tree, _name, "packedM", size, 's', packedM, _branches);
  utils::book(_tree, _name, "packedPuppiW", size, 'B', packedPuppiW, _branches);
  utils::book(_tree, _name, "packedPuppiWNoLepDiff", size, 'B', packedPuppiWNoLepDiff, _branches);
}

void
panda::PFCand::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  PFCandBase::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "packedPt");
  utils::resetAddress(_tree, _name, "packedEta");
  utils::resetAddress(_tree, _name, "packedPhi");
  utils::resetAddress(_tree, _name, "packedM");
  utils::resetAddress(_tree, _name, "packedPuppiW");
  utils::resetAddress(_tree, _name, "packedPuppiWNoLepDiff");
}

void
panda::PFCand::datastore::resizeVectors_(UInt_t _size)
{
  PFCandBase::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::PFCand::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return PFCand::getListOfBranches().fullNames(_name);
}

panda::PFCand::PFCand(char const* _name/* = ""*/) :
  PFCandBase(new PFCandArray(1, _name)),
  PackedMomentumMixin(gStore.getData(this), 0),
  packedPuppiW(gStore.getData(this).packedPuppiW[0]),
  packedPuppiWNoLepDiff(gStore.getData(this).packedPuppiWNoLepDiff[0])
{
}

panda::PFCand::PFCand(PFCand const& _src) :
  PFCandBase(new PFCandArray(1, _src.getName())),
  PackedMomentumMixin(gStore.getData(this), 0),
  packedPuppiW(gStore.getData(this).packedPuppiW[0]),
  packedPuppiWNoLepDiff(gStore.getData(this).packedPuppiWNoLepDiff[0])
{
  operator=(_src);
}

panda::PFCand::PFCand(datastore& _data, UInt_t _idx) :
  PFCandBase(_data, _idx),
  PackedMomentumMixin(_data, _idx),
  packedPuppiW(_data.packedPuppiW[_idx]),
  packedPuppiWNoLepDiff(_data.packedPuppiWNoLepDiff[_idx])
{
}

panda::PFCand::PFCand(ArrayBase* _array) :
  PFCandBase(_array),
  PackedMomentumMixin(gStore.getData(this), 0),
  packedPuppiW(gStore.getData(this).packedPuppiW[0]),
  packedPuppiWNoLepDiff(gStore.getData(this).packedPuppiWNoLepDiff[0])
{
}

panda::PFCand::~PFCand()
{
  destructor();
}

void
panda::PFCand::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM PFCand.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    PFCandBase::destructor(kTRUE);
}

panda::PFCand&
panda::PFCand::operator=(PFCand const& _src)
{
  PFCandBase::operator=(_src);

  packedPt = _src.packedPt;
  packedEta = _src.packedEta;
  packedPhi = _src.packedPhi;
  packedM = _src.packedM;
  packedPuppiW = _src.packedPuppiW;
  packedPuppiWNoLepDiff = _src.packedPuppiWNoLepDiff;

  /* BEGIN CUSTOM PFCand.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
panda::PFCand::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PFCandBase::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "packedPt", "", 's', &packedPt, _branches);
  utils::book(_tree, _name, "packedEta", "", 'S', &packedEta, _branches);
  utils::book(_tree, _name, "packedPhi", "", 'S', &packedPhi, _branches);
  utils::book(_tree, _name, "packedM", "", 's', &packedM, _branches);
  utils::book(_tree, _name, "packedPuppiW", "", 'B', &packedPuppiW, _branches);
  utils::book(_tree, _name, "packedPuppiWNoLepDiff", "", 'B', &packedPuppiWNoLepDiff, _branches);
}

void
panda::PFCand::doInit_()
{
  PFCandBase::doInit_();

  packedPt = 0;
  packedEta = 0;
  packedPhi = 0;
  packedM = 0;
  packedPuppiW = 0;
  packedPuppiWNoLepDiff = 0;

  /* BEGIN CUSTOM PFCand.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::PFCand::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM PFCand.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::PFCand::dump(std::ostream& _out/* = std::cout*/) const
{
  PFCandBase::dump(_out);

  _out << "packedPt = " << packedPt << std::endl;
  _out << "packedEta = " << packedEta << std::endl;
  _out << "packedPhi = " << packedPhi << std::endl;
  _out << "packedM = " << packedM << std::endl;
  _out << "packedPuppiW = " << static_cast<const Int_t>(packedPuppiW) << std::endl;
  _out << "packedPuppiWNoLepDiff = " << static_cast<const Int_t>(packedPuppiWNoLepDiff) << std::endl;
}


/* BEGIN CUSTOM PFCand.cc.global */
#include "../interface/PackingHelper.h"

void
panda::PFCand::packWeights_()
{
  packedPuppiW = PackingHelper::singleton().pack8LogBound((puppiW_ - 0.5) * 2., -2., 0., 64);
  packedPuppiWNoLepDiff = PackingHelper::singleton().pack8LogBound((puppiWNoLep_ - 0.5) * 2., -2., 0., 64) - packedPuppiW;
}

void
panda::PFCand::unpackWeights_() const
{
  puppiW_ = PackingHelper::singleton().unpack8LogBound(packedPuppiW, -2., 0., 64) * 0.5 + 0.5;
  puppiWNoLep_ = PackingHelper::singleton().unpack8LogBound(packedPuppiWNoLepDiff + packedPuppiW, -2., 0., 64) * 0.5 + 0.5;
}

#include "../interface/UnpackedPFCand.h"

panda::PFCand&
panda::PFCand::operator=(UnpackedPFCand const& _rhs)
{
  PFCandBase::operator=(static_cast<PFCandBase const&>(_rhs));
  setPtEtaPhiM(_rhs.pt(), _rhs.eta(), _rhs.phi(), _rhs.m());
  setPuppiW(_rhs.puppiW(), _rhs.puppiWNoLep());

  return *this;
}

/* END CUSTOM */
