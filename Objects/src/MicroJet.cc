#include "../interface/MicroJet.h"

/*static*/
panda::utils::BranchList
panda::MicroJet::getListOfBranches()
{
  utils::BranchList blist;
  blist += ParticleM::getListOfBranches();
  blist += {"csv", "qgl", "cmva", "leptonPtRel", "leptonPt", "leptonDR", "bRegressedEnergy", "secondaryVertices_"};
  return blist;
}

void
panda::MicroJet::datastore::allocate(UInt_t _nmax)
{
  ParticleM::datastore::allocate(_nmax);

  csv = new Float_t[nmax_];
  qgl = new Float_t[nmax_];
  cmva = new Float_t[nmax_];
  leptonPtRel = new Float_t[nmax_];
  leptonPt = new Float_t[nmax_];
  leptonDR = new Float_t[nmax_];
  bRegressedEnergy = new Float_t[nmax_];
  secondaryVertices_ = new std::vector<std::vector<Short_t>>(nmax_);
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
  delete [] leptonPtRel;
  leptonPtRel = 0;
  delete [] leptonPt;
  leptonPt = 0;
  delete [] leptonDR;
  leptonDR = 0;
  delete [] bRegressedEnergy;
  bRegressedEnergy = 0;
  delete secondaryVertices_;
  secondaryVertices_ = 0;
}

void
panda::MicroJet::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  ParticleM::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "csv", _branches);
  utils::setStatus(_tree, _name, "qgl", _branches);
  utils::setStatus(_tree, _name, "cmva", _branches);
  utils::setStatus(_tree, _name, "leptonPtRel", _branches);
  utils::setStatus(_tree, _name, "leptonPt", _branches);
  utils::setStatus(_tree, _name, "leptonDR", _branches);
  utils::setStatus(_tree, _name, "bRegressedEnergy", _branches);
  utils::setStatus(_tree, _name, "secondaryVertices_", _branches);
}

panda::utils::BranchList
panda::MicroJet::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(ParticleM::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "csv"));
  blist.push_back(utils::getStatus(_tree, _name, "qgl"));
  blist.push_back(utils::getStatus(_tree, _name, "cmva"));
  blist.push_back(utils::getStatus(_tree, _name, "leptonPtRel"));
  blist.push_back(utils::getStatus(_tree, _name, "leptonPt"));
  blist.push_back(utils::getStatus(_tree, _name, "leptonDR"));
  blist.push_back(utils::getStatus(_tree, _name, "bRegressedEnergy"));
  blist.push_back(utils::getStatus(_tree, _name, "secondaryVertices_"));

  return blist;
}

void
panda::MicroJet::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "csv", csv, _branches, _setStatus);
  utils::setAddress(_tree, _name, "qgl", qgl, _branches, _setStatus);
  utils::setAddress(_tree, _name, "cmva", cmva, _branches, _setStatus);
  utils::setAddress(_tree, _name, "leptonPtRel", leptonPtRel, _branches, _setStatus);
  utils::setAddress(_tree, _name, "leptonPt", leptonPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "leptonDR", leptonDR, _branches, _setStatus);
  utils::setAddress(_tree, _name, "bRegressedEnergy", bRegressedEnergy, _branches, _setStatus);
  utils::setAddress(_tree, _name, "secondaryVertices_", &secondaryVertices_, _branches, _setStatus);
}

void
panda::MicroJet::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "csv", size, 'F', csv, _branches);
  utils::book(_tree, _name, "qgl", size, 'F', qgl, _branches);
  utils::book(_tree, _name, "cmva", size, 'F', cmva, _branches);
  utils::book(_tree, _name, "leptonPtRel", size, 'F', leptonPtRel, _branches);
  utils::book(_tree, _name, "leptonPt", size, 'F', leptonPt, _branches);
  utils::book(_tree, _name, "leptonDR", size, 'F', leptonDR, _branches);
  utils::book(_tree, _name, "bRegressedEnergy", size, 'F', bRegressedEnergy, _branches);
  utils::book(_tree, _name, "secondaryVertices_", "std::vector<std::vector<Short_t>>", &secondaryVertices_, _branches);
}

void
panda::MicroJet::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  ParticleM::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "csv");
  utils::resetAddress(_tree, _name, "qgl");
  utils::resetAddress(_tree, _name, "cmva");
  utils::resetAddress(_tree, _name, "leptonPtRel");
  utils::resetAddress(_tree, _name, "leptonPt");
  utils::resetAddress(_tree, _name, "leptonDR");
  utils::resetAddress(_tree, _name, "bRegressedEnergy");
  utils::resetAddress(_tree, _name, "secondaryVertices_");
}

void
panda::MicroJet::datastore::resizeVectors_(UInt_t _size)
{
  ParticleM::datastore::resizeVectors_(_size);

  secondaryVertices_->resize(_size);
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
  leptonPtRel(gStore.getData(this).leptonPtRel[0]),
  leptonPt(gStore.getData(this).leptonPt[0]),
  leptonDR(gStore.getData(this).leptonDR[0]),
  bRegressedEnergy(gStore.getData(this).bRegressedEnergy[0]),
  secondaryVertices(gStore.getData(this).secondaryVerticesContainer_, (*gStore.getData(this).secondaryVertices_)[0])
{
}

panda::MicroJet::MicroJet(MicroJet const& _src) :
  ParticleM(new MicroJetArray(1, _src.getName())),
  csv(gStore.getData(this).csv[0]),
  qgl(gStore.getData(this).qgl[0]),
  cmva(gStore.getData(this).cmva[0]),
  leptonPtRel(gStore.getData(this).leptonPtRel[0]),
  leptonPt(gStore.getData(this).leptonPt[0]),
  leptonDR(gStore.getData(this).leptonDR[0]),
  bRegressedEnergy(gStore.getData(this).bRegressedEnergy[0]),
  secondaryVertices(gStore.getData(this).secondaryVerticesContainer_, (*gStore.getData(this).secondaryVertices_)[0])
{
  ParticleM::operator=(_src);

  csv = _src.csv;
  qgl = _src.qgl;
  cmva = _src.cmva;
  leptonPtRel = _src.leptonPtRel;
  leptonPt = _src.leptonPt;
  leptonDR = _src.leptonDR;
  bRegressedEnergy = _src.bRegressedEnergy;
  secondaryVertices = _src.secondaryVertices;
}

panda::MicroJet::MicroJet(datastore& _data, UInt_t _idx) :
  ParticleM(_data, _idx),
  csv(_data.csv[_idx]),
  qgl(_data.qgl[_idx]),
  cmva(_data.cmva[_idx]),
  leptonPtRel(_data.leptonPtRel[_idx]),
  leptonPt(_data.leptonPt[_idx]),
  leptonDR(_data.leptonDR[_idx]),
  bRegressedEnergy(_data.bRegressedEnergy[_idx]),
  secondaryVertices(_data.secondaryVerticesContainer_, (*_data.secondaryVertices_)[_idx])
{
}

panda::MicroJet::MicroJet(ArrayBase* _array) :
  ParticleM(_array),
  csv(gStore.getData(this).csv[0]),
  qgl(gStore.getData(this).qgl[0]),
  cmva(gStore.getData(this).cmva[0]),
  leptonPtRel(gStore.getData(this).leptonPtRel[0]),
  leptonPt(gStore.getData(this).leptonPt[0]),
  leptonDR(gStore.getData(this).leptonDR[0]),
  bRegressedEnergy(gStore.getData(this).bRegressedEnergy[0]),
  secondaryVertices(gStore.getData(this).secondaryVerticesContainer_, (*gStore.getData(this).secondaryVertices_)[0])
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
  leptonPtRel = _src.leptonPtRel;
  leptonPt = _src.leptonPt;
  leptonDR = _src.leptonDR;
  bRegressedEnergy = _src.bRegressedEnergy;
  secondaryVertices = _src.secondaryVertices;

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
  utils::book(_tree, _name, "leptonPtRel", "", 'F', &leptonPtRel, _branches);
  utils::book(_tree, _name, "leptonPt", "", 'F', &leptonPt, _branches);
  utils::book(_tree, _name, "leptonDR", "", 'F', &leptonDR, _branches);
  utils::book(_tree, _name, "bRegressedEnergy", "", 'F', &bRegressedEnergy, _branches);
  utils::book(_tree, _name, "secondaryVertices_", "std::vector<Short_t>", &secondaryVertices.indices(), _branches);
}

void
panda::MicroJet::doInit_()
{
  ParticleM::doInit_();

  csv = 0.;
  qgl = 0.;
  cmva = 0.;
  leptonPtRel = 0.;
  leptonPt = 0.;
  leptonDR = 0.;
  bRegressedEnergy = 0.;
  secondaryVertices.init();

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
  _out << "leptonPtRel = " << leptonPtRel << std::endl;
  _out << "leptonPt = " << leptonPt << std::endl;
  _out << "leptonDR = " << leptonDR << std::endl;
  _out << "bRegressedEnergy = " << bRegressedEnergy << std::endl;
  _out << "secondaryVertices = " << secondaryVertices << std::endl;
}

/* BEGIN CUSTOM MicroJet.cc.global */
/* END CUSTOM */
