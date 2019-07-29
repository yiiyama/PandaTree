#include "../interface/SecondaryVertex.h"

/*static*/
panda::utils::BranchList
panda::SecondaryVertex::getListOfBranches()
{
  utils::BranchList blist;
  blist += ParticleM::getListOfBranches();
  blist += {"x", "y", "z", "ntrk", "ndof", "chi2", "daughters_", "significance", "vtx3DVal", "vtx3DeVal"};
  return blist;
}

void
panda::SecondaryVertex::datastore::allocate(UInt_t _nmax)
{
  ParticleM::datastore::allocate(_nmax);

  x = new Float_t[nmax_];
  y = new Float_t[nmax_];
  z = new Float_t[nmax_];
  ntrk = new UShort_t[nmax_];
  ndof = new Float_t[nmax_];
  chi2 = new Float_t[nmax_];
  daughters_ = new std::vector<std::vector<Short_t>>(nmax_);
  significance = new Float_t[nmax_];
  vtx3DVal = new Float_t[nmax_];
  vtx3DeVal = new Float_t[nmax_];
}

void
panda::SecondaryVertex::datastore::deallocate()
{
  ParticleM::datastore::deallocate();

  delete [] x;
  x = 0;
  delete [] y;
  y = 0;
  delete [] z;
  z = 0;
  delete [] ntrk;
  ntrk = 0;
  delete [] ndof;
  ndof = 0;
  delete [] chi2;
  chi2 = 0;
  delete daughters_;
  daughters_ = 0;
  delete [] significance;
  significance = 0;
  delete [] vtx3DVal;
  vtx3DVal = 0;
  delete [] vtx3DeVal;
  vtx3DeVal = 0;
}

void
panda::SecondaryVertex::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  ParticleM::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "x", _branches);
  utils::setStatus(_tree, _name, "y", _branches);
  utils::setStatus(_tree, _name, "z", _branches);
  utils::setStatus(_tree, _name, "ntrk", _branches);
  utils::setStatus(_tree, _name, "ndof", _branches);
  utils::setStatus(_tree, _name, "chi2", _branches);
  utils::setStatus(_tree, _name, "daughters_", _branches);
  utils::setStatus(_tree, _name, "significance", _branches);
  utils::setStatus(_tree, _name, "vtx3DVal", _branches);
  utils::setStatus(_tree, _name, "vtx3DeVal", _branches);
}

panda::utils::BranchList
panda::SecondaryVertex::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(ParticleM::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "x"));
  blist.push_back(utils::getStatus(_tree, _name, "y"));
  blist.push_back(utils::getStatus(_tree, _name, "z"));
  blist.push_back(utils::getStatus(_tree, _name, "ntrk"));
  blist.push_back(utils::getStatus(_tree, _name, "ndof"));
  blist.push_back(utils::getStatus(_tree, _name, "chi2"));
  blist.push_back(utils::getStatus(_tree, _name, "daughters_"));
  blist.push_back(utils::getStatus(_tree, _name, "significance"));
  blist.push_back(utils::getStatus(_tree, _name, "vtx3DVal"));
  blist.push_back(utils::getStatus(_tree, _name, "vtx3DeVal"));

  return blist;
}

void
panda::SecondaryVertex::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "x", x, _branches, _setStatus);
  utils::setAddress(_tree, _name, "y", y, _branches, _setStatus);
  utils::setAddress(_tree, _name, "z", z, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ntrk", ntrk, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ndof", ndof, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chi2", chi2, _branches, _setStatus);
  utils::setAddress(_tree, _name, "daughters_", &daughters_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "significance", significance, _branches, _setStatus);
  utils::setAddress(_tree, _name, "vtx3DVal", vtx3DVal, _branches, _setStatus);
  utils::setAddress(_tree, _name, "vtx3DeVal", vtx3DeVal, _branches, _setStatus);
}

void
panda::SecondaryVertex::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "x", size, 'F', x, _branches);
  utils::book(_tree, _name, "y", size, 'F', y, _branches);
  utils::book(_tree, _name, "z", size, 'F', z, _branches);
  utils::book(_tree, _name, "ntrk", size, 's', ntrk, _branches);
  utils::book(_tree, _name, "ndof", size, 'F', ndof, _branches);
  utils::book(_tree, _name, "chi2", size, 'F', chi2, _branches);
  utils::book(_tree, _name, "daughters_", "std::vector<std::vector<Short_t>>", &daughters_, _branches);
  utils::book(_tree, _name, "significance", size, 'F', significance, _branches);
  utils::book(_tree, _name, "vtx3DVal", size, 'F', vtx3DVal, _branches);
  utils::book(_tree, _name, "vtx3DeVal", size, 'F', vtx3DeVal, _branches);
}

void
panda::SecondaryVertex::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  ParticleM::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "x");
  utils::resetAddress(_tree, _name, "y");
  utils::resetAddress(_tree, _name, "z");
  utils::resetAddress(_tree, _name, "ntrk");
  utils::resetAddress(_tree, _name, "ndof");
  utils::resetAddress(_tree, _name, "chi2");
  utils::resetAddress(_tree, _name, "daughters_");
  utils::resetAddress(_tree, _name, "significance");
  utils::resetAddress(_tree, _name, "vtx3DVal");
  utils::resetAddress(_tree, _name, "vtx3DeVal");
}

void
panda::SecondaryVertex::datastore::resizeVectors_(UInt_t _size)
{
  ParticleM::datastore::resizeVectors_(_size);

  daughters_->resize(_size);
}


panda::utils::BranchList
panda::SecondaryVertex::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return SecondaryVertex::getListOfBranches().fullNames(_name);
}

panda::SecondaryVertex::SecondaryVertex(char const* _name/* = ""*/) :
  ParticleM(new SecondaryVertexArray(1, _name)),
  x(gStore.getData(this).x[0]),
  y(gStore.getData(this).y[0]),
  z(gStore.getData(this).z[0]),
  ntrk(gStore.getData(this).ntrk[0]),
  ndof(gStore.getData(this).ndof[0]),
  chi2(gStore.getData(this).chi2[0]),
  daughters(gStore.getData(this).daughtersContainer_, (*gStore.getData(this).daughters_)[0]),
  significance(gStore.getData(this).significance[0]),
  vtx3DVal(gStore.getData(this).vtx3DVal[0]),
  vtx3DeVal(gStore.getData(this).vtx3DeVal[0])
{
}

panda::SecondaryVertex::SecondaryVertex(SecondaryVertex const& _src) :
  ParticleM(new SecondaryVertexArray(1, _src.getName())),
  x(gStore.getData(this).x[0]),
  y(gStore.getData(this).y[0]),
  z(gStore.getData(this).z[0]),
  ntrk(gStore.getData(this).ntrk[0]),
  ndof(gStore.getData(this).ndof[0]),
  chi2(gStore.getData(this).chi2[0]),
  daughters(gStore.getData(this).daughtersContainer_, (*gStore.getData(this).daughters_)[0]),
  significance(gStore.getData(this).significance[0]),
  vtx3DVal(gStore.getData(this).vtx3DVal[0]),
  vtx3DeVal(gStore.getData(this).vtx3DeVal[0])
{
  operator=(_src);
}

panda::SecondaryVertex::SecondaryVertex(datastore& _data, UInt_t _idx) :
  ParticleM(_data, _idx),
  x(_data.x[_idx]),
  y(_data.y[_idx]),
  z(_data.z[_idx]),
  ntrk(_data.ntrk[_idx]),
  ndof(_data.ndof[_idx]),
  chi2(_data.chi2[_idx]),
  daughters(_data.daughtersContainer_, (*_data.daughters_)[_idx]),
  significance(_data.significance[_idx]),
  vtx3DVal(_data.vtx3DVal[_idx]),
  vtx3DeVal(_data.vtx3DeVal[_idx])
{
}

panda::SecondaryVertex::SecondaryVertex(ArrayBase* _array) :
  ParticleM(_array),
  x(gStore.getData(this).x[0]),
  y(gStore.getData(this).y[0]),
  z(gStore.getData(this).z[0]),
  ntrk(gStore.getData(this).ntrk[0]),
  ndof(gStore.getData(this).ndof[0]),
  chi2(gStore.getData(this).chi2[0]),
  daughters(gStore.getData(this).daughtersContainer_, (*gStore.getData(this).daughters_)[0]),
  significance(gStore.getData(this).significance[0]),
  vtx3DVal(gStore.getData(this).vtx3DVal[0]),
  vtx3DeVal(gStore.getData(this).vtx3DeVal[0])
{
}

panda::SecondaryVertex::~SecondaryVertex()
{
  destructor();
}

void
panda::SecondaryVertex::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM SecondaryVertex.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    ParticleM::destructor(kTRUE);
}

panda::SecondaryVertex&
panda::SecondaryVertex::operator=(SecondaryVertex const& _src)
{
  ParticleM::operator=(_src);

  x = _src.x;
  y = _src.y;
  z = _src.z;
  ntrk = _src.ntrk;
  ndof = _src.ndof;
  chi2 = _src.chi2;
  daughters = _src.daughters;
  significance = _src.significance;
  vtx3DVal = _src.vtx3DVal;
  vtx3DeVal = _src.vtx3DeVal;

  /* BEGIN CUSTOM SecondaryVertex.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
panda::SecondaryVertex::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ParticleM::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "x", "", 'F', &x, _branches);
  utils::book(_tree, _name, "y", "", 'F', &y, _branches);
  utils::book(_tree, _name, "z", "", 'F', &z, _branches);
  utils::book(_tree, _name, "ntrk", "", 's', &ntrk, _branches);
  utils::book(_tree, _name, "ndof", "", 'F', &ndof, _branches);
  utils::book(_tree, _name, "chi2", "", 'F', &chi2, _branches);
  utils::book(_tree, _name, "daughters_", "std::vector<Short_t>", &daughters.indices(), _branches);
  utils::book(_tree, _name, "significance", "", 'F', &significance, _branches);
  utils::book(_tree, _name, "vtx3DVal", "", 'F', &vtx3DVal, _branches);
  utils::book(_tree, _name, "vtx3DeVal", "", 'F', &vtx3DeVal, _branches);
}

void
panda::SecondaryVertex::doInit_()
{
  ParticleM::doInit_();

  x = 0.;
  y = 0.;
  z = 0.;
  ntrk = 0;
  ndof = 0.;
  chi2 = 0.;
  daughters.init();
  significance = 0.;
  vtx3DVal = 0.;
  vtx3DeVal = 0.;

  /* BEGIN CUSTOM SecondaryVertex.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::SecondaryVertex::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM SecondaryVertex.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::SecondaryVertex::dump(std::ostream& _out/* = std::cout*/) const
{
  ParticleM::dump(_out);

  _out << "x = " << x << std::endl;
  _out << "y = " << y << std::endl;
  _out << "z = " << z << std::endl;
  _out << "ntrk = " << ntrk << std::endl;
  _out << "ndof = " << ndof << std::endl;
  _out << "chi2 = " << chi2 << std::endl;
  _out << "daughters = " << daughters << std::endl;
  _out << "significance = " << significance << std::endl;
  _out << "vtx3DVal = " << vtx3DVal << std::endl;
  _out << "vtx3DeVal = " << vtx3DeVal << std::endl;
}


/* BEGIN CUSTOM SecondaryVertex.cc.global */
/* END CUSTOM */
