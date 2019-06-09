#include "../interface/GenParticleBase.h"

TString panda::GenParticleBase::StatusFlagName[] = {
  "kIsPrompt",
  "kIsDecayedLeptonHadron",
  "kIsTauDecayProduct",
  "kIsPromptTauDecayProduct",
  "kIsDirectTauDecayProduct",
  "kIsDirectPromptTauDecayProduct",
  "kIsDirectHadronDecayProduct",
  "kIsHardProcess",
  "kFromHardProcess",
  "kIsHardProcessTauDecayProduct",
  "kIsDirectHardProcessTauDecayProduct",
  "kFromHardProcessBeforeFSR",
  "kIsFirstCopy",
  "kIsLastCopy",
  "kIsLastCopyBeforeFSR"
};

/*static*/
panda::utils::BranchList
panda::GenParticleBase::getListOfBranches()
{
  utils::BranchList blist;
  blist += Particle::getListOfBranches();
  blist += {"pdgid", "finalState", "miniaodPacked", "statusFlags", "parent_"};
  return blist;
}

void
panda::GenParticleBase::datastore::allocate(UInt_t _nmax)
{
  Particle::datastore::allocate(_nmax);

  pdgid = new Int_t[nmax_];
  finalState = new Bool_t[nmax_];
  miniaodPacked = new Bool_t[nmax_];
  statusFlags = new UShort_t[nmax_];
  parent_ = new Short_t[nmax_];
}

void
panda::GenParticleBase::datastore::deallocate()
{
  Particle::datastore::deallocate();

  delete [] pdgid;
  pdgid = 0;
  delete [] finalState;
  finalState = 0;
  delete [] miniaodPacked;
  miniaodPacked = 0;
  delete [] statusFlags;
  statusFlags = 0;
  delete [] parent_;
  parent_ = 0;
}

void
panda::GenParticleBase::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Particle::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "pdgid", _branches);
  utils::setStatus(_tree, _name, "finalState", _branches);
  utils::setStatus(_tree, _name, "miniaodPacked", _branches);
  utils::setStatus(_tree, _name, "statusFlags", _branches);
  utils::setStatus(_tree, _name, "parent_", _branches);
}

panda::utils::BranchList
panda::GenParticleBase::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Particle::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "pdgid"));
  blist.push_back(utils::getStatus(_tree, _name, "finalState"));
  blist.push_back(utils::getStatus(_tree, _name, "miniaodPacked"));
  blist.push_back(utils::getStatus(_tree, _name, "statusFlags"));
  blist.push_back(utils::getStatus(_tree, _name, "parent_"));

  return blist;
}

void
panda::GenParticleBase::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "pdgid", pdgid, _branches, _setStatus);
  utils::setAddress(_tree, _name, "finalState", finalState, _branches, _setStatus);
  utils::setAddress(_tree, _name, "miniaodPacked", miniaodPacked, _branches, _setStatus);
  utils::setAddress(_tree, _name, "statusFlags", statusFlags, _branches, _setStatus);
  utils::setAddress(_tree, _name, "parent_", parent_, _branches, _setStatus);
}

void
panda::GenParticleBase::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Particle::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "pdgid", size, 'I', pdgid, _branches);
  utils::book(_tree, _name, "finalState", size, 'O', finalState, _branches);
  utils::book(_tree, _name, "miniaodPacked", size, 'O', miniaodPacked, _branches);
  utils::book(_tree, _name, "statusFlags", size, 's', statusFlags, _branches);
  utils::book(_tree, _name, "parent_", size, 'S', parent_, _branches);
}

void
panda::GenParticleBase::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Particle::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "pdgid");
  utils::resetAddress(_tree, _name, "finalState");
  utils::resetAddress(_tree, _name, "miniaodPacked");
  utils::resetAddress(_tree, _name, "statusFlags");
  utils::resetAddress(_tree, _name, "parent_");
}

void
panda::GenParticleBase::datastore::resizeVectors_(UInt_t _size)
{
  Particle::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::GenParticleBase::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return GenParticleBase::getListOfBranches().fullNames(_name);
}

panda::GenParticleBase::GenParticleBase(char const* _name/* = ""*/) :
  Particle(new GenParticleBaseArray(1, _name)),
  pdgid(gStore.getData(this).pdgid[0]),
  finalState(gStore.getData(this).finalState[0]),
  miniaodPacked(gStore.getData(this).miniaodPacked[0]),
  statusFlags(gStore.getData(this).statusFlags[0]),
  parent(gStore.getData(this).parentContainer_, gStore.getData(this).parent_[0])
{
}

panda::GenParticleBase::GenParticleBase(GenParticleBase const& _src) :
  Particle(new GenParticleBaseArray(1, _src.getName())),
  pdgid(gStore.getData(this).pdgid[0]),
  finalState(gStore.getData(this).finalState[0]),
  miniaodPacked(gStore.getData(this).miniaodPacked[0]),
  statusFlags(gStore.getData(this).statusFlags[0]),
  parent(gStore.getData(this).parentContainer_, gStore.getData(this).parent_[0])
{
  Particle::operator=(_src);

  pdgid = _src.pdgid;
  finalState = _src.finalState;
  miniaodPacked = _src.miniaodPacked;
  statusFlags = _src.statusFlags;
  parent = _src.parent;
}

panda::GenParticleBase::GenParticleBase(datastore& _data, UInt_t _idx) :
  Particle(_data, _idx),
  pdgid(_data.pdgid[_idx]),
  finalState(_data.finalState[_idx]),
  miniaodPacked(_data.miniaodPacked[_idx]),
  statusFlags(_data.statusFlags[_idx]),
  parent(_data.parentContainer_, _data.parent_[_idx])
{
}

panda::GenParticleBase::GenParticleBase(ArrayBase* _array) :
  Particle(_array),
  pdgid(gStore.getData(this).pdgid[0]),
  finalState(gStore.getData(this).finalState[0]),
  miniaodPacked(gStore.getData(this).miniaodPacked[0]),
  statusFlags(gStore.getData(this).statusFlags[0]),
  parent(gStore.getData(this).parentContainer_, gStore.getData(this).parent_[0])
{
}

panda::GenParticleBase::~GenParticleBase()
{
  destructor();
}

void
panda::GenParticleBase::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM GenParticleBase.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    Particle::destructor(kTRUE);
}

panda::GenParticleBase&
panda::GenParticleBase::operator=(GenParticleBase const& _src)
{
  Particle::operator=(_src);

  pdgid = _src.pdgid;
  finalState = _src.finalState;
  miniaodPacked = _src.miniaodPacked;
  statusFlags = _src.statusFlags;
  parent = _src.parent;

  /* BEGIN CUSTOM GenParticleBase.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
panda::GenParticleBase::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  Particle::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "pdgid", "", 'I', &pdgid, _branches);
  utils::book(_tree, _name, "finalState", "", 'O', &finalState, _branches);
  utils::book(_tree, _name, "miniaodPacked", "", 'O', &miniaodPacked, _branches);
  utils::book(_tree, _name, "statusFlags", "", 's', &statusFlags, _branches);
  utils::book(_tree, _name, "parent_", "", 'S', gStore.getData(this).parent_, _branches);
}

void
panda::GenParticleBase::doInit_()
{
  Particle::doInit_();

  pdgid = 0;
  finalState = false;
  miniaodPacked = false;
  statusFlags = 0;
  parent.init();

  /* BEGIN CUSTOM GenParticleBase.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::GenParticleBase::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM GenParticleBase.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::GenParticleBase::dump(std::ostream& _out/* = std::cout*/) const
{
  Particle::dump(_out);

  _out << "pdgid = " << pdgid << std::endl;
  _out << "finalState = " << finalState << std::endl;
  _out << "miniaodPacked = " << miniaodPacked << std::endl;
  _out << "statusFlags = " << statusFlags << std::endl;
  _out << "parent = " << parent << std::endl;
}


/* BEGIN CUSTOM GenParticleBase.cc.global */
/* END CUSTOM */
