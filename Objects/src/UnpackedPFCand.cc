#include "../interface/UnpackedPFCand.h"

/*static*/
panda::utils::BranchList
panda::UnpackedPFCand::getListOfBranches()
{
  utils::BranchList blist;
  blist += PFCandBase::getListOfBranches();
  blist += {"pt_", "eta_", "phi_", "mass_"};
  return blist;
}

void
panda::UnpackedPFCand::datastore::allocate(UInt_t _nmax)
{
  PFCandBase::datastore::allocate(_nmax);

  pt_ = new Float_t[nmax_];
  eta_ = new Float_t[nmax_];
  phi_ = new Float_t[nmax_];
  mass_ = new Float_t[nmax_];
}

void
panda::UnpackedPFCand::datastore::deallocate()
{
  PFCandBase::datastore::deallocate();

  delete [] pt_;
  pt_ = 0;
  delete [] eta_;
  eta_ = 0;
  delete [] phi_;
  phi_ = 0;
  delete [] mass_;
  mass_ = 0;
}

void
panda::UnpackedPFCand::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  PFCandBase::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "pt_", _branches);
  utils::setStatus(_tree, _name, "eta_", _branches);
  utils::setStatus(_tree, _name, "phi_", _branches);
  utils::setStatus(_tree, _name, "mass_", _branches);
}

panda::utils::BranchList
panda::UnpackedPFCand::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(PFCandBase::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "pt_"));
  blist.push_back(utils::getStatus(_tree, _name, "eta_"));
  blist.push_back(utils::getStatus(_tree, _name, "phi_"));
  blist.push_back(utils::getStatus(_tree, _name, "mass_"));

  return blist;
}

void
panda::UnpackedPFCand::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PFCandBase::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "pt_", pt_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "eta_", eta_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phi_", phi_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mass_", mass_, _branches, _setStatus);
}

void
panda::UnpackedPFCand::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PFCandBase::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "pt_", size, 'F', pt_, _branches);
  utils::book(_tree, _name, "eta_", size, 'F', eta_, _branches);
  utils::book(_tree, _name, "phi_", size, 'F', phi_, _branches);
  utils::book(_tree, _name, "mass_", size, 'F', mass_, _branches);
}

void
panda::UnpackedPFCand::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  PFCandBase::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "pt_");
  utils::resetAddress(_tree, _name, "eta_");
  utils::resetAddress(_tree, _name, "phi_");
  utils::resetAddress(_tree, _name, "mass_");
}

void
panda::UnpackedPFCand::datastore::resizeVectors_(UInt_t _size)
{
  PFCandBase::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::UnpackedPFCand::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return UnpackedPFCand::getListOfBranches().fullNames(_name);
}

panda::UnpackedPFCand::UnpackedPFCand(char const* _name/* = ""*/) :
  PFCandBase(new UnpackedPFCandArray(1, _name)),
  pt_(gStore.getData(this).pt_[0]),
  eta_(gStore.getData(this).eta_[0]),
  phi_(gStore.getData(this).phi_[0]),
  mass_(gStore.getData(this).mass_[0])
{
}

panda::UnpackedPFCand::UnpackedPFCand(UnpackedPFCand const& _src) :
  PFCandBase(new UnpackedPFCandArray(1, _src.getName())),
  pt_(gStore.getData(this).pt_[0]),
  eta_(gStore.getData(this).eta_[0]),
  phi_(gStore.getData(this).phi_[0]),
  mass_(gStore.getData(this).mass_[0])
{
  PFCandBase::operator=(_src);

  pt_ = _src.pt_;
  eta_ = _src.eta_;
  phi_ = _src.phi_;
  mass_ = _src.mass_;
}

panda::UnpackedPFCand::UnpackedPFCand(datastore& _data, UInt_t _idx) :
  PFCandBase(_data, _idx),
  pt_(_data.pt_[_idx]),
  eta_(_data.eta_[_idx]),
  phi_(_data.phi_[_idx]),
  mass_(_data.mass_[_idx])
{
}

panda::UnpackedPFCand::UnpackedPFCand(ArrayBase* _array) :
  PFCandBase(_array),
  pt_(gStore.getData(this).pt_[0]),
  eta_(gStore.getData(this).eta_[0]),
  phi_(gStore.getData(this).phi_[0]),
  mass_(gStore.getData(this).mass_[0])
{
}

panda::UnpackedPFCand::~UnpackedPFCand()
{
  destructor();
}

void
panda::UnpackedPFCand::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM UnpackedPFCand.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    PFCandBase::destructor(kTRUE);
}

panda::UnpackedPFCand&
panda::UnpackedPFCand::operator=(UnpackedPFCand const& _src)
{
  PFCandBase::operator=(_src);

  pt_ = _src.pt_;
  eta_ = _src.eta_;
  phi_ = _src.phi_;
  mass_ = _src.mass_;

  /* BEGIN CUSTOM UnpackedPFCand.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
panda::UnpackedPFCand::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PFCandBase::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "pt_", "", 'F', &pt_, _branches);
  utils::book(_tree, _name, "eta_", "", 'F', &eta_, _branches);
  utils::book(_tree, _name, "phi_", "", 'F', &phi_, _branches);
  utils::book(_tree, _name, "mass_", "", 'F', &mass_, _branches);
}

void
panda::UnpackedPFCand::doInit_()
{
  PFCandBase::doInit_();

  pt_ = 0.;
  eta_ = 0.;
  phi_ = 0.;
  mass_ = 0.;

  /* BEGIN CUSTOM UnpackedPFCand.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::UnpackedPFCand::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM UnpackedPFCand.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::UnpackedPFCand::dump(std::ostream& _out/* = std::cout*/) const
{
  PFCandBase::dump(_out);

  _out << "pt_ = " << pt_ << std::endl;
  _out << "eta_ = " << eta_ << std::endl;
  _out << "phi_ = " << phi_ << std::endl;
  _out << "mass_ = " << mass_ << std::endl;
}

void
panda::UnpackedPFCand::setPtEtaPhiM(double pt, double eta, double phi, double m)
{
  pt_ = pt;
  eta_ = eta;
  phi_ = phi;
  mass_ = m;
}

void
panda::UnpackedPFCand::setXYZE(double px, double py, double pz, double e)
{
  pt_ = std::sqrt(px * px + py * py);
  double p(std::sqrt(px * px + py * py + pz * pz));
  eta_ = 0.5 * std::log((p + pz) / (p - pz));
  phi_ = std::atan2(py, px);
  mass_ = std::sqrt(e * e - p * p);
}


/* BEGIN CUSTOM UnpackedPFCand.cc.global */
panda::UnpackedPFCand&
panda::UnpackedPFCand::operator=(PFCand const& _rhs)
{
  setPtEtaPhiM(_rhs.pt(), _rhs.eta(), _rhs.phi(), _rhs.m());

  puppiW = _rhs.puppiW();
  puppiWNoLep = _rhs.puppiWNoLep();
  ptype = _rhs.ptype;
  vertex = _rhs.vertex;

  return *this;
}

/* END CUSTOM */
