#include "../interface/GenJet.h"

/*static*/
panda::utils::BranchList
panda::GenJet::getListOfBranches()
{
  utils::BranchList blist;
  blist += ParticleM::getListOfBranches();
  blist += {"pdgid", "partonFlavor", "numB", "numC", "matchedBHadrons_", "matchedCHadrons_"};
  return blist;
}

void
panda::GenJet::datastore::allocate(UInt_t _nmax)
{
  ParticleM::datastore::allocate(_nmax);

  pdgid = new Short_t[nmax_];
  partonFlavor = new Short_t[nmax_];
  numB = new Short_t[nmax_];
  numC = new Short_t[nmax_];
  matchedBHadrons_ = new std::vector<std::vector<Short_t>>(nmax_);
  matchedCHadrons_ = new std::vector<std::vector<Short_t>>(nmax_);
}

void
panda::GenJet::datastore::deallocate()
{
  ParticleM::datastore::deallocate();

  delete [] pdgid;
  pdgid = 0;
  delete [] partonFlavor;
  partonFlavor = 0;
  delete [] numB;
  numB = 0;
  delete [] numC;
  numC = 0;
  delete matchedBHadrons_;
  matchedBHadrons_ = 0;
  delete matchedCHadrons_;
  matchedCHadrons_ = 0;
}

void
panda::GenJet::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  ParticleM::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "pdgid", _branches);
  utils::setStatus(_tree, _name, "partonFlavor", _branches);
  utils::setStatus(_tree, _name, "numB", _branches);
  utils::setStatus(_tree, _name, "numC", _branches);
  utils::setStatus(_tree, _name, "matchedBHadrons_", _branches);
  utils::setStatus(_tree, _name, "matchedCHadrons_", _branches);
}

panda::utils::BranchList
panda::GenJet::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(ParticleM::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "pdgid"));
  blist.push_back(utils::getStatus(_tree, _name, "partonFlavor"));
  blist.push_back(utils::getStatus(_tree, _name, "numB"));
  blist.push_back(utils::getStatus(_tree, _name, "numC"));
  blist.push_back(utils::getStatus(_tree, _name, "matchedBHadrons_"));
  blist.push_back(utils::getStatus(_tree, _name, "matchedCHadrons_"));

  return blist;
}

void
panda::GenJet::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "pdgid", pdgid, _branches, _setStatus);
  utils::setAddress(_tree, _name, "partonFlavor", partonFlavor, _branches, _setStatus);
  utils::setAddress(_tree, _name, "numB", numB, _branches, _setStatus);
  utils::setAddress(_tree, _name, "numC", numC, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedBHadrons_", &matchedBHadrons_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedCHadrons_", &matchedCHadrons_, _branches, _setStatus);
}

void
panda::GenJet::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "pdgid", size, 'S', pdgid, _branches);
  utils::book(_tree, _name, "partonFlavor", size, 'S', partonFlavor, _branches);
  utils::book(_tree, _name, "numB", size, 'S', numB, _branches);
  utils::book(_tree, _name, "numC", size, 'S', numC, _branches);
  utils::book(_tree, _name, "matchedBHadrons_", "std::vector<std::vector<Short_t>>", &matchedBHadrons_, _branches);
  utils::book(_tree, _name, "matchedCHadrons_", "std::vector<std::vector<Short_t>>", &matchedCHadrons_, _branches);
}

void
panda::GenJet::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  ParticleM::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "pdgid");
  utils::resetAddress(_tree, _name, "partonFlavor");
  utils::resetAddress(_tree, _name, "numB");
  utils::resetAddress(_tree, _name, "numC");
  utils::resetAddress(_tree, _name, "matchedBHadrons_");
  utils::resetAddress(_tree, _name, "matchedCHadrons_");
}

void
panda::GenJet::datastore::resizeVectors_(UInt_t _size)
{
  ParticleM::datastore::resizeVectors_(_size);

  matchedBHadrons_->resize(_size);
  matchedCHadrons_->resize(_size);
}


panda::utils::BranchList
panda::GenJet::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return GenJet::getListOfBranches().fullNames(_name);
}

panda::GenJet::GenJet(char const* _name/* = ""*/) :
  ParticleM(new GenJetArray(1, _name)),
  pdgid(gStore.getData(this).pdgid[0]),
  partonFlavor(gStore.getData(this).partonFlavor[0]),
  numB(gStore.getData(this).numB[0]),
  numC(gStore.getData(this).numC[0]),
  matchedBHadrons(gStore.getData(this).matchedBHadronsContainer_, (*gStore.getData(this).matchedBHadrons_)[0]),
  matchedCHadrons(gStore.getData(this).matchedCHadronsContainer_, (*gStore.getData(this).matchedCHadrons_)[0])
{
}

panda::GenJet::GenJet(GenJet const& _src) :
  ParticleM(new GenJetArray(1, _src.getName())),
  pdgid(gStore.getData(this).pdgid[0]),
  partonFlavor(gStore.getData(this).partonFlavor[0]),
  numB(gStore.getData(this).numB[0]),
  numC(gStore.getData(this).numC[0]),
  matchedBHadrons(gStore.getData(this).matchedBHadronsContainer_, (*gStore.getData(this).matchedBHadrons_)[0]),
  matchedCHadrons(gStore.getData(this).matchedCHadronsContainer_, (*gStore.getData(this).matchedCHadrons_)[0])
{
  operator=(_src);
}

panda::GenJet::GenJet(datastore& _data, UInt_t _idx) :
  ParticleM(_data, _idx),
  pdgid(_data.pdgid[_idx]),
  partonFlavor(_data.partonFlavor[_idx]),
  numB(_data.numB[_idx]),
  numC(_data.numC[_idx]),
  matchedBHadrons(_data.matchedBHadronsContainer_, (*_data.matchedBHadrons_)[_idx]),
  matchedCHadrons(_data.matchedCHadronsContainer_, (*_data.matchedCHadrons_)[_idx])
{
}

panda::GenJet::GenJet(ArrayBase* _array) :
  ParticleM(_array),
  pdgid(gStore.getData(this).pdgid[0]),
  partonFlavor(gStore.getData(this).partonFlavor[0]),
  numB(gStore.getData(this).numB[0]),
  numC(gStore.getData(this).numC[0]),
  matchedBHadrons(gStore.getData(this).matchedBHadronsContainer_, (*gStore.getData(this).matchedBHadrons_)[0]),
  matchedCHadrons(gStore.getData(this).matchedCHadronsContainer_, (*gStore.getData(this).matchedCHadrons_)[0])
{
}

panda::GenJet::~GenJet()
{
  destructor();
}

void
panda::GenJet::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM GenJet.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    ParticleM::destructor(kTRUE);
}

panda::GenJet&
panda::GenJet::operator=(GenJet const& _src)
{
  ParticleM::operator=(_src);

  pdgid = _src.pdgid;
  partonFlavor = _src.partonFlavor;
  numB = _src.numB;
  numC = _src.numC;
  matchedBHadrons = _src.matchedBHadrons;
  matchedCHadrons = _src.matchedCHadrons;

  /* BEGIN CUSTOM GenJet.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
panda::GenJet::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ParticleM::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "pdgid", "", 'S', &pdgid, _branches);
  utils::book(_tree, _name, "partonFlavor", "", 'S', &partonFlavor, _branches);
  utils::book(_tree, _name, "numB", "", 'S', &numB, _branches);
  utils::book(_tree, _name, "numC", "", 'S', &numC, _branches);
  utils::book(_tree, _name, "matchedBHadrons_", "std::vector<Short_t>", &matchedBHadrons.indices(), _branches);
  utils::book(_tree, _name, "matchedCHadrons_", "std::vector<Short_t>", &matchedCHadrons.indices(), _branches);
}

void
panda::GenJet::doInit_()
{
  ParticleM::doInit_();

  pdgid = 0;
  partonFlavor = 0;
  numB = 0;
  numC = 0;
  matchedBHadrons.init();
  matchedCHadrons.init();

  /* BEGIN CUSTOM GenJet.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::GenJet::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM GenJet.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::GenJet::dump(std::ostream& _out/* = std::cout*/) const
{
  ParticleM::dump(_out);

  _out << "pdgid = " << pdgid << std::endl;
  _out << "partonFlavor = " << partonFlavor << std::endl;
  _out << "numB = " << numB << std::endl;
  _out << "numC = " << numC << std::endl;
  _out << "matchedBHadrons = " << matchedBHadrons << std::endl;
  _out << "matchedCHadrons = " << matchedCHadrons << std::endl;
}

/* BEGIN CUSTOM GenJet.cc.global */
/* END CUSTOM */
