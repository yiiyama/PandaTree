#include "../interface/MicroJet.h"

/*static*/
panda::utils::BranchList
panda::MicroJet::getListOfBranches()
{
  utils::BranchList blist;
  blist += ParticleM::getListOfBranches();
  blist += {"csv", "qgl", "cmva", "deepCSVudsg", "deepCSVb", "deepCSVc", "deepCSVbb", "deepCSVcc", "deepCMVAudsg", "deepCMVAb", "deepCMVAc", "deepCMVAbb", "deepCMVAcc"};
  return blist;
}

void
panda::MicroJet::datastore::allocate(UInt_t _nmax)
{
  ParticleM::datastore::allocate(_nmax);

  csv = new Float_t[nmax_];
  qgl = new Float_t[nmax_];
  cmva = new Float_t[nmax_];
  deepCSVudsg = new Float_t[nmax_];
  deepCSVb = new Float_t[nmax_];
  deepCSVc = new Float_t[nmax_];
  deepCSVbb = new Float_t[nmax_];
  deepCSVcc = new Float_t[nmax_];
  deepCMVAudsg = new Float_t[nmax_];
  deepCMVAb = new Float_t[nmax_];
  deepCMVAc = new Float_t[nmax_];
  deepCMVAbb = new Float_t[nmax_];
  deepCMVAcc = new Float_t[nmax_];
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
  delete [] deepCSVudsg;
  deepCSVudsg = 0;
  delete [] deepCSVb;
  deepCSVb = 0;
  delete [] deepCSVc;
  deepCSVc = 0;
  delete [] deepCSVbb;
  deepCSVbb = 0;
  delete [] deepCSVcc;
  deepCSVcc = 0;
  delete [] deepCMVAudsg;
  deepCMVAudsg = 0;
  delete [] deepCMVAb;
  deepCMVAb = 0;
  delete [] deepCMVAc;
  deepCMVAc = 0;
  delete [] deepCMVAbb;
  deepCMVAbb = 0;
  delete [] deepCMVAcc;
  deepCMVAcc = 0;
}

void
panda::MicroJet::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  ParticleM::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "csv", _branches);
  utils::setStatus(_tree, _name, "qgl", _branches);
  utils::setStatus(_tree, _name, "cmva", _branches);
  utils::setStatus(_tree, _name, "deepCSVudsg", _branches);
  utils::setStatus(_tree, _name, "deepCSVb", _branches);
  utils::setStatus(_tree, _name, "deepCSVc", _branches);
  utils::setStatus(_tree, _name, "deepCSVbb", _branches);
  utils::setStatus(_tree, _name, "deepCSVcc", _branches);
  utils::setStatus(_tree, _name, "deepCMVAudsg", _branches);
  utils::setStatus(_tree, _name, "deepCMVAb", _branches);
  utils::setStatus(_tree, _name, "deepCMVAc", _branches);
  utils::setStatus(_tree, _name, "deepCMVAbb", _branches);
  utils::setStatus(_tree, _name, "deepCMVAcc", _branches);
}

panda::utils::BranchList
panda::MicroJet::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(ParticleM::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "csv"));
  blist.push_back(utils::getStatus(_tree, _name, "qgl"));
  blist.push_back(utils::getStatus(_tree, _name, "cmva"));
  blist.push_back(utils::getStatus(_tree, _name, "deepCSVudsg"));
  blist.push_back(utils::getStatus(_tree, _name, "deepCSVb"));
  blist.push_back(utils::getStatus(_tree, _name, "deepCSVc"));
  blist.push_back(utils::getStatus(_tree, _name, "deepCSVbb"));
  blist.push_back(utils::getStatus(_tree, _name, "deepCSVcc"));
  blist.push_back(utils::getStatus(_tree, _name, "deepCMVAudsg"));
  blist.push_back(utils::getStatus(_tree, _name, "deepCMVAb"));
  blist.push_back(utils::getStatus(_tree, _name, "deepCMVAc"));
  blist.push_back(utils::getStatus(_tree, _name, "deepCMVAbb"));
  blist.push_back(utils::getStatus(_tree, _name, "deepCMVAcc"));

  return blist;
}

void
panda::MicroJet::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "csv", csv, _branches, _setStatus);
  utils::setAddress(_tree, _name, "qgl", qgl, _branches, _setStatus);
  utils::setAddress(_tree, _name, "cmva", cmva, _branches, _setStatus);
  utils::setAddress(_tree, _name, "deepCSVudsg", deepCSVudsg, _branches, _setStatus);
  utils::setAddress(_tree, _name, "deepCSVb", deepCSVb, _branches, _setStatus);
  utils::setAddress(_tree, _name, "deepCSVc", deepCSVc, _branches, _setStatus);
  utils::setAddress(_tree, _name, "deepCSVbb", deepCSVbb, _branches, _setStatus);
  utils::setAddress(_tree, _name, "deepCSVcc", deepCSVcc, _branches, _setStatus);
  utils::setAddress(_tree, _name, "deepCMVAudsg", deepCMVAudsg, _branches, _setStatus);
  utils::setAddress(_tree, _name, "deepCMVAb", deepCMVAb, _branches, _setStatus);
  utils::setAddress(_tree, _name, "deepCMVAc", deepCMVAc, _branches, _setStatus);
  utils::setAddress(_tree, _name, "deepCMVAbb", deepCMVAbb, _branches, _setStatus);
  utils::setAddress(_tree, _name, "deepCMVAcc", deepCMVAcc, _branches, _setStatus);
}

void
panda::MicroJet::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "csv", size, 'F', csv, _branches);
  utils::book(_tree, _name, "qgl", size, 'F', qgl, _branches);
  utils::book(_tree, _name, "cmva", size, 'F', cmva, _branches);
  utils::book(_tree, _name, "deepCSVudsg", size, 'F', deepCSVudsg, _branches);
  utils::book(_tree, _name, "deepCSVb", size, 'F', deepCSVb, _branches);
  utils::book(_tree, _name, "deepCSVc", size, 'F', deepCSVc, _branches);
  utils::book(_tree, _name, "deepCSVbb", size, 'F', deepCSVbb, _branches);
  utils::book(_tree, _name, "deepCSVcc", size, 'F', deepCSVcc, _branches);
  utils::book(_tree, _name, "deepCMVAudsg", size, 'F', deepCMVAudsg, _branches);
  utils::book(_tree, _name, "deepCMVAb", size, 'F', deepCMVAb, _branches);
  utils::book(_tree, _name, "deepCMVAc", size, 'F', deepCMVAc, _branches);
  utils::book(_tree, _name, "deepCMVAbb", size, 'F', deepCMVAbb, _branches);
  utils::book(_tree, _name, "deepCMVAcc", size, 'F', deepCMVAcc, _branches);
}

void
panda::MicroJet::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  ParticleM::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "csv");
  utils::resetAddress(_tree, _name, "qgl");
  utils::resetAddress(_tree, _name, "cmva");
  utils::resetAddress(_tree, _name, "deepCSVudsg");
  utils::resetAddress(_tree, _name, "deepCSVb");
  utils::resetAddress(_tree, _name, "deepCSVc");
  utils::resetAddress(_tree, _name, "deepCSVbb");
  utils::resetAddress(_tree, _name, "deepCSVcc");
  utils::resetAddress(_tree, _name, "deepCMVAudsg");
  utils::resetAddress(_tree, _name, "deepCMVAb");
  utils::resetAddress(_tree, _name, "deepCMVAc");
  utils::resetAddress(_tree, _name, "deepCMVAbb");
  utils::resetAddress(_tree, _name, "deepCMVAcc");
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
  deepCSVudsg(gStore.getData(this).deepCSVudsg[0]),
  deepCSVb(gStore.getData(this).deepCSVb[0]),
  deepCSVc(gStore.getData(this).deepCSVc[0]),
  deepCSVbb(gStore.getData(this).deepCSVbb[0]),
  deepCSVcc(gStore.getData(this).deepCSVcc[0]),
  deepCMVAudsg(gStore.getData(this).deepCMVAudsg[0]),
  deepCMVAb(gStore.getData(this).deepCMVAb[0]),
  deepCMVAc(gStore.getData(this).deepCMVAc[0]),
  deepCMVAbb(gStore.getData(this).deepCMVAbb[0]),
  deepCMVAcc(gStore.getData(this).deepCMVAcc[0])
{
}

panda::MicroJet::MicroJet(MicroJet const& _src) :
  ParticleM(new MicroJetArray(1, _src.getName())),
  csv(gStore.getData(this).csv[0]),
  qgl(gStore.getData(this).qgl[0]),
  cmva(gStore.getData(this).cmva[0]),
  deepCSVudsg(gStore.getData(this).deepCSVudsg[0]),
  deepCSVb(gStore.getData(this).deepCSVb[0]),
  deepCSVc(gStore.getData(this).deepCSVc[0]),
  deepCSVbb(gStore.getData(this).deepCSVbb[0]),
  deepCSVcc(gStore.getData(this).deepCSVcc[0]),
  deepCMVAudsg(gStore.getData(this).deepCMVAudsg[0]),
  deepCMVAb(gStore.getData(this).deepCMVAb[0]),
  deepCMVAc(gStore.getData(this).deepCMVAc[0]),
  deepCMVAbb(gStore.getData(this).deepCMVAbb[0]),
  deepCMVAcc(gStore.getData(this).deepCMVAcc[0])
{
  operator=(_src);
}

panda::MicroJet::MicroJet(datastore& _data, UInt_t _idx) :
  ParticleM(_data, _idx),
  csv(_data.csv[_idx]),
  qgl(_data.qgl[_idx]),
  cmva(_data.cmva[_idx]),
  deepCSVudsg(_data.deepCSVudsg[_idx]),
  deepCSVb(_data.deepCSVb[_idx]),
  deepCSVc(_data.deepCSVc[_idx]),
  deepCSVbb(_data.deepCSVbb[_idx]),
  deepCSVcc(_data.deepCSVcc[_idx]),
  deepCMVAudsg(_data.deepCMVAudsg[_idx]),
  deepCMVAb(_data.deepCMVAb[_idx]),
  deepCMVAc(_data.deepCMVAc[_idx]),
  deepCMVAbb(_data.deepCMVAbb[_idx]),
  deepCMVAcc(_data.deepCMVAcc[_idx])
{
}

panda::MicroJet::MicroJet(ArrayBase* _array) :
  ParticleM(_array),
  csv(gStore.getData(this).csv[0]),
  qgl(gStore.getData(this).qgl[0]),
  cmva(gStore.getData(this).cmva[0]),
  deepCSVudsg(gStore.getData(this).deepCSVudsg[0]),
  deepCSVb(gStore.getData(this).deepCSVb[0]),
  deepCSVc(gStore.getData(this).deepCSVc[0]),
  deepCSVbb(gStore.getData(this).deepCSVbb[0]),
  deepCSVcc(gStore.getData(this).deepCSVcc[0]),
  deepCMVAudsg(gStore.getData(this).deepCMVAudsg[0]),
  deepCMVAb(gStore.getData(this).deepCMVAb[0]),
  deepCMVAc(gStore.getData(this).deepCMVAc[0]),
  deepCMVAbb(gStore.getData(this).deepCMVAbb[0]),
  deepCMVAcc(gStore.getData(this).deepCMVAcc[0])
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
  deepCSVudsg = _src.deepCSVudsg;
  deepCSVb = _src.deepCSVb;
  deepCSVc = _src.deepCSVc;
  deepCSVbb = _src.deepCSVbb;
  deepCSVcc = _src.deepCSVcc;
  deepCMVAudsg = _src.deepCMVAudsg;
  deepCMVAb = _src.deepCMVAb;
  deepCMVAc = _src.deepCMVAc;
  deepCMVAbb = _src.deepCMVAbb;
  deepCMVAcc = _src.deepCMVAcc;

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
  utils::book(_tree, _name, "deepCSVudsg", "", 'F', &deepCSVudsg, _branches);
  utils::book(_tree, _name, "deepCSVb", "", 'F', &deepCSVb, _branches);
  utils::book(_tree, _name, "deepCSVc", "", 'F', &deepCSVc, _branches);
  utils::book(_tree, _name, "deepCSVbb", "", 'F', &deepCSVbb, _branches);
  utils::book(_tree, _name, "deepCSVcc", "", 'F', &deepCSVcc, _branches);
  utils::book(_tree, _name, "deepCMVAudsg", "", 'F', &deepCMVAudsg, _branches);
  utils::book(_tree, _name, "deepCMVAb", "", 'F', &deepCMVAb, _branches);
  utils::book(_tree, _name, "deepCMVAc", "", 'F', &deepCMVAc, _branches);
  utils::book(_tree, _name, "deepCMVAbb", "", 'F', &deepCMVAbb, _branches);
  utils::book(_tree, _name, "deepCMVAcc", "", 'F', &deepCMVAcc, _branches);
}

void
panda::MicroJet::doInit_()
{
  ParticleM::doInit_();

  csv = 0.;
  qgl = 0.;
  cmva = 0.;
  deepCSVudsg = 0.;
  deepCSVb = 0.;
  deepCSVc = 0.;
  deepCSVbb = 0.;
  deepCSVcc = 0.;
  deepCMVAudsg = 0.;
  deepCMVAb = 0.;
  deepCMVAc = 0.;
  deepCMVAbb = 0.;
  deepCMVAcc = 0.;

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
  _out << "deepCSVudsg = " << deepCSVudsg << std::endl;
  _out << "deepCSVb = " << deepCSVb << std::endl;
  _out << "deepCSVc = " << deepCSVc << std::endl;
  _out << "deepCSVbb = " << deepCSVbb << std::endl;
  _out << "deepCSVcc = " << deepCSVcc << std::endl;
  _out << "deepCMVAudsg = " << deepCMVAudsg << std::endl;
  _out << "deepCMVAb = " << deepCMVAb << std::endl;
  _out << "deepCMVAc = " << deepCMVAc << std::endl;
  _out << "deepCMVAbb = " << deepCMVAbb << std::endl;
  _out << "deepCMVAcc = " << deepCMVAcc << std::endl;
}

/* BEGIN CUSTOM MicroJet.cc.global */
/* END CUSTOM */
