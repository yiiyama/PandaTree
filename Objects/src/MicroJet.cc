#include "../interface/MicroJet.h"

/*static*/
panda::utils::BranchList
panda::MicroJet::getListOfBranches()
{
  utils::BranchList blist;
  blist += ParticleM::getListOfBranches();
  blist += {"csv", "qgl", "cmva", "deepCsv", "deepCmva"};
  return blist;
}

void
panda::MicroJet::datastore::allocate(UInt_t _nmax)
{
  ParticleM::datastore::allocate(_nmax);

  csv = new Float_t[nmax_];
  qgl = new Float_t[nmax_];
  cmva = new Float_t[nmax_];
  deepCsv = new Float_t[nmax_];
  deepCmva = new Float_t[nmax_];
}

void
panda::MicroJet::datastore::deallocate()
{
  ParticleM::datastore::deallocate();

  delete [] csv;
  csv = 0;
  delete [] qgl;
  qgl = 0;
  delete [] cmva;
  cmva = 0;
  delete [] deepCsv;
  deepCsv = 0;
  delete [] deepCmva;
  deepCmva = 0;
}

void
panda::MicroJet::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  ParticleM::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "csv", _branches);
  utils::setStatus(_tree, _name, "qgl", _branches);
  utils::setStatus(_tree, _name, "cmva", _branches);
  utils::setStatus(_tree, _name, "deepCsv", _branches);
  utils::setStatus(_tree, _name, "deepCmva", _branches);
}

panda::utils::BranchList
panda::MicroJet::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(ParticleM::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "csv"));
  blist.push_back(utils::getStatus(_tree, _name, "qgl"));
  blist.push_back(utils::getStatus(_tree, _name, "cmva"));
  blist.push_back(utils::getStatus(_tree, _name, "deepCsv"));
  blist.push_back(utils::getStatus(_tree, _name, "deepCmva"));

  return blist;
}

void
panda::MicroJet::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "csv", csv, _branches, _setStatus);
  utils::setAddress(_tree, _name, "qgl", qgl, _branches, _setStatus);
  utils::setAddress(_tree, _name, "cmva", cmva, _branches, _setStatus);
  utils::setAddress(_tree, _name, "deepCsv", deepCsv, _branches, _setStatus);
  utils::setAddress(_tree, _name, "deepCmva", deepCmva, _branches, _setStatus);
}

void
panda::MicroJet::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "csv", size, 'F', csv, _branches);
  utils::book(_tree, _name, "qgl", size, 'F', qgl, _branches);
  utils::book(_tree, _name, "cmva", size, 'F', cmva, _branches);
  utils::book(_tree, _name, "deepCsv", size, 'F', deepCsv, _branches);
  utils::book(_tree, _name, "deepCmva", size, 'F', deepCmva, _branches);
}

void
panda::MicroJet::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  ParticleM::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "csv");
  utils::resetAddress(_tree, _name, "qgl");
  utils::resetAddress(_tree, _name, "cmva");
  utils::resetAddress(_tree, _name, "deepCsv");
  utils::resetAddress(_tree, _name, "deepCmva");
}

void
panda::MicroJet::datastore::resizeVectors_(UInt_t _size)
{
  ParticleM::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::MicroJet::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return MicroJet::getListOfBranches().fullNames(_name);
}

panda::MicroJet::MicroJet(char const* _name/* = ""*/) :
  ParticleM(new MicroJetArray(1, _name)),
  csv(gStore.getData(this).csv[0]),
  qgl(gStore.getData(this).qgl[0]),
  cmva(gStore.getData(this).cmva[0]),
  deepCsv(gStore.getData(this).deepCsv[0]),
  deepCmva(gStore.getData(this).deepCmva[0])
{
}

panda::MicroJet::MicroJet(MicroJet const& _src) :
  ParticleM(new MicroJetArray(1, _src.getName())),
  csv(gStore.getData(this).csv[0]),
  qgl(gStore.getData(this).qgl[0]),
  cmva(gStore.getData(this).cmva[0]),
  deepCsv(gStore.getData(this).deepCsv[0]),
  deepCmva(gStore.getData(this).deepCmva[0])
{
  ParticleM::operator=(_src);

  csv = _src.csv;
  qgl = _src.qgl;
  cmva = _src.cmva;
  deepCsv = _src.deepCsv;
  deepCmva = _src.deepCmva;
}

panda::MicroJet::MicroJet(datastore& _data, UInt_t _idx) :
  ParticleM(_data, _idx),
  csv(_data.csv[_idx]),
  qgl(_data.qgl[_idx]),
  cmva(_data.cmva[_idx]),
  deepCsv(_data.deepCsv[_idx]),
  deepCmva(_data.deepCmva[_idx])
{
}

panda::MicroJet::MicroJet(ArrayBase* _array) :
  ParticleM(_array),
  csv(gStore.getData(this).csv[0]),
  qgl(gStore.getData(this).qgl[0]),
  cmva(gStore.getData(this).cmva[0]),
  deepCsv(gStore.getData(this).deepCsv[0]),
  deepCmva(gStore.getData(this).deepCmva[0])
{
}

panda::MicroJet::~MicroJet()
{
  destructor();
}

void
panda::MicroJet::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM MicroJet.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    ParticleM::destructor(kTRUE);
}

panda::MicroJet&
panda::MicroJet::operator=(MicroJet const& _src)
{
  ParticleM::operator=(_src);

  csv = _src.csv;
  qgl = _src.qgl;
  cmva = _src.cmva;
  deepCsv = _src.deepCsv;
  deepCmva = _src.deepCmva;

  /* BEGIN CUSTOM MicroJet.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
panda::MicroJet::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ParticleM::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "csv", "", 'F', &csv, _branches);
  utils::book(_tree, _name, "qgl", "", 'F', &qgl, _branches);
  utils::book(_tree, _name, "cmva", "", 'F', &cmva, _branches);
  utils::book(_tree, _name, "deepCsv", "", 'F', &deepCsv, _branches);
  utils::book(_tree, _name, "deepCmva", "", 'F', &deepCmva, _branches);
}

void
panda::MicroJet::doInit_()
{
  ParticleM::doInit_();

  csv = 0.;
  qgl = 0.;
  cmva = 0.;
  deepCsv = 0.;
  deepCmva = 0.;

  /* BEGIN CUSTOM MicroJet.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::MicroJet::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM MicroJet.cc.print */
  MicroJet::dump(_out);
  /* END CUSTOM */
}

void
panda::MicroJet::dump(std::ostream& _out/* = std::cout*/) const
{
  ParticleM::dump(_out);

  _out << "csv = " << csv << std::endl;
  _out << "qgl = " << qgl << std::endl;
  _out << "cmva = " << cmva << std::endl;
  _out << "deepCsv = " << deepCsv << std::endl;
  _out << "deepCmva = " << deepCmva << std::endl;
}

/* BEGIN CUSTOM MicroJet.cc.global */
/* END CUSTOM */
