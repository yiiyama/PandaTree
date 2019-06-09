#include "../interface/GenParticle.h"

/*static*/
panda::utils::BranchList
panda::GenParticle::getListOfBranches()
{
  utils::BranchList blist;
  blist += GenParticleBase::getListOfBranches();
  return blist;
}

void
panda::GenParticle::datastore::allocate(UInt_t _nmax)
{
  GenParticleBase::datastore::allocate(_nmax);

  packedPt = new UShort_t[nmax_];
  packedEta = new Short_t[nmax_];
  packedPhi = new Short_t[nmax_];
  packedM = new UShort_t[nmax_];
}

void
panda::GenParticle::datastore::deallocate()
{
  GenParticleBase::datastore::deallocate();

  delete [] packedPt;
  packedPt = 0;
  delete [] packedEta;
  packedEta = 0;
  delete [] packedPhi;
  packedPhi = 0;
  delete [] packedM;
  packedM = 0;
}

void
panda::GenParticle::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  GenParticleBase::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "packedPt", _branches);
  utils::setStatus(_tree, _name, "packedEta", _branches);
  utils::setStatus(_tree, _name, "packedPhi", _branches);
  utils::setStatus(_tree, _name, "packedM", _branches);
}

panda::utils::BranchList
panda::GenParticle::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(GenParticleBase::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "packedPt"));
  blist.push_back(utils::getStatus(_tree, _name, "packedEta"));
  blist.push_back(utils::getStatus(_tree, _name, "packedPhi"));
  blist.push_back(utils::getStatus(_tree, _name, "packedM"));

  return blist;
}

void
panda::GenParticle::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  GenParticleBase::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "packedPt", packedPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedEta", packedEta, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedPhi", packedPhi, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedM", packedM, _branches, _setStatus);
}

void
panda::GenParticle::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  GenParticleBase::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "packedPt", size, 's', packedPt, _branches);
  utils::book(_tree, _name, "packedEta", size, 'S', packedEta, _branches);
  utils::book(_tree, _name, "packedPhi", size, 'S', packedPhi, _branches);
  utils::book(_tree, _name, "packedM", size, 's', packedM, _branches);
}

void
panda::GenParticle::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  GenParticleBase::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "packedPt");
  utils::resetAddress(_tree, _name, "packedEta");
  utils::resetAddress(_tree, _name, "packedPhi");
  utils::resetAddress(_tree, _name, "packedM");
}

void
panda::GenParticle::datastore::resizeVectors_(UInt_t _size)
{
  GenParticleBase::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::GenParticle::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return GenParticle::getListOfBranches().fullNames(_name);
}

panda::GenParticle::GenParticle(char const* _name/* = ""*/) :
  GenParticleBase(new GenParticleArray(1, _name)),
  PackedMomentumMixin(gStore.getData(this), 0)
{
}

panda::GenParticle::GenParticle(GenParticle const& _src) :
  GenParticleBase(new GenParticleArray(1, _src.getName())),
  PackedMomentumMixin(gStore.getData(this), 0)
{
  operator=(_src);
}

panda::GenParticle::GenParticle(datastore& _data, UInt_t _idx) :
  GenParticleBase(_data, _idx),
  PackedMomentumMixin(_data, _idx)
{
}

panda::GenParticle::GenParticle(ArrayBase* _array) :
  GenParticleBase(_array),
  PackedMomentumMixin(gStore.getData(this), 0)
{
}

panda::GenParticle::~GenParticle()
{
  destructor();
}

void
panda::GenParticle::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM GenParticle.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    GenParticleBase::destructor(kTRUE);
}

panda::GenParticle&
panda::GenParticle::operator=(GenParticle const& _src)
{
  GenParticleBase::operator=(_src);

  packedPt = _src.packedPt;
  packedEta = _src.packedEta;
  packedPhi = _src.packedPhi;
  packedM = _src.packedM;

  /* BEGIN CUSTOM GenParticle.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
panda::GenParticle::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  GenParticleBase::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "packedPt", "", 's', &packedPt, _branches);
  utils::book(_tree, _name, "packedEta", "", 'S', &packedEta, _branches);
  utils::book(_tree, _name, "packedPhi", "", 'S', &packedPhi, _branches);
  utils::book(_tree, _name, "packedM", "", 's', &packedM, _branches);
}

void
panda::GenParticle::doInit_()
{
  GenParticleBase::doInit_();

  packedPt = 0;
  packedEta = 0;
  packedPhi = 0;
  packedM = 0;

  /* BEGIN CUSTOM GenParticle.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::GenParticle::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM GenParticle.cc.print */
  _out << "GenParticle " << pdgid << " (" << pt() << ", " << eta() << ", " << phi() << ") "
       << "flag=";
  for (unsigned i(0); i != 16; ++i)
    _out << ((statusFlags >> i) & 1);
  _out << std::endl;
  /* END CUSTOM */
}

void
panda::GenParticle::dump(std::ostream& _out/* = std::cout*/) const
{
  GenParticleBase::dump(_out);

  _out << "packedPt = " << packedPt << std::endl;
  _out << "packedEta = " << packedEta << std::endl;
  _out << "packedPhi = " << packedPhi << std::endl;
  _out << "packedM = " << packedM << std::endl;
}


/* BEGIN CUSTOM GenParticle.cc.global */
#include "../interface/UnpackedGenParticle.h"

panda::GenParticle&
panda::GenParticle::operator=(UnpackedGenParticle const& _rhs)
{
  GenParticleBase::operator=(static_cast<GenParticleBase const&>(_rhs));
  setPtEtaPhiM(_rhs.pt(), _rhs.eta(), _rhs.phi(), _rhs.m());

  return *this;
}
/* END CUSTOM */
