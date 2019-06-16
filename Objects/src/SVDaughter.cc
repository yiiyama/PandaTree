#include "../interface/SVDaughter.h"

/*static*/
panda::utils::BranchList
panda::SVDaughter::getListOfBranches()
{
  utils::BranchList blist;
  blist += UnpackedPFCand::getListOfBranches();
  blist += {"dxySV", "dzSV", "rawPhi", "qtrk", "ptAxis", "plAxis"};
  return blist;
}

void
panda::SVDaughter::datastore::allocate(UInt_t _nmax)
{
  UnpackedPFCand::datastore::allocate(_nmax);

  dxySV = new Float_t[nmax_];
  dzSV = new Float_t[nmax_];
  rawPhi = new Float_t[nmax_];
  qtrk = new Short_t[nmax_];
  ptAxis = new Float_t[nmax_];
  plAxis = new Float_t[nmax_];
}

void
panda::SVDaughter::datastore::deallocate()
{
  UnpackedPFCand::datastore::deallocate();

  delete [] dxySV;
  dxySV = 0;
  delete [] dzSV;
  dzSV = 0;
  delete [] rawPhi;
  rawPhi = 0;
  delete [] qtrk;
  qtrk = 0;
  delete [] ptAxis;
  ptAxis = 0;
  delete [] plAxis;
  plAxis = 0;
}

void
panda::SVDaughter::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  UnpackedPFCand::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "dxySV", _branches);
  utils::setStatus(_tree, _name, "dzSV", _branches);
  utils::setStatus(_tree, _name, "rawPhi", _branches);
  utils::setStatus(_tree, _name, "qtrk", _branches);
  utils::setStatus(_tree, _name, "ptAxis", _branches);
  utils::setStatus(_tree, _name, "plAxis", _branches);
}

panda::utils::BranchList
panda::SVDaughter::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(UnpackedPFCand::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "dxySV"));
  blist.push_back(utils::getStatus(_tree, _name, "dzSV"));
  blist.push_back(utils::getStatus(_tree, _name, "rawPhi"));
  blist.push_back(utils::getStatus(_tree, _name, "qtrk"));
  blist.push_back(utils::getStatus(_tree, _name, "ptAxis"));
  blist.push_back(utils::getStatus(_tree, _name, "plAxis"));

  return blist;
}

void
panda::SVDaughter::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  UnpackedPFCand::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "dxySV", dxySV, _branches, _setStatus);
  utils::setAddress(_tree, _name, "dzSV", dzSV, _branches, _setStatus);
  utils::setAddress(_tree, _name, "rawPhi", rawPhi, _branches, _setStatus);
  utils::setAddress(_tree, _name, "qtrk", qtrk, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptAxis", ptAxis, _branches, _setStatus);
  utils::setAddress(_tree, _name, "plAxis", plAxis, _branches, _setStatus);
}

void
panda::SVDaughter::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  UnpackedPFCand::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "dxySV", size, 'F', dxySV, _branches);
  utils::book(_tree, _name, "dzSV", size, 'F', dzSV, _branches);
  utils::book(_tree, _name, "rawPhi", size, 'F', rawPhi, _branches);
  utils::book(_tree, _name, "qtrk", size, 'S', qtrk, _branches);
  utils::book(_tree, _name, "ptAxis", size, 'F', ptAxis, _branches);
  utils::book(_tree, _name, "plAxis", size, 'F', plAxis, _branches);
}

void
panda::SVDaughter::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  UnpackedPFCand::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "dxySV");
  utils::resetAddress(_tree, _name, "dzSV");
  utils::resetAddress(_tree, _name, "rawPhi");
  utils::resetAddress(_tree, _name, "qtrk");
  utils::resetAddress(_tree, _name, "ptAxis");
  utils::resetAddress(_tree, _name, "plAxis");
}

void
panda::SVDaughter::datastore::resizeVectors_(UInt_t _size)
{
  UnpackedPFCand::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::SVDaughter::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return SVDaughter::getListOfBranches().fullNames(_name);
}

panda::SVDaughter::SVDaughter(char const* _name/* = ""*/) :
  UnpackedPFCand(new SVDaughterArray(1, _name)),
  dxySV(gStore.getData(this).dxySV[0]),
  dzSV(gStore.getData(this).dzSV[0]),
  rawPhi(gStore.getData(this).rawPhi[0]),
  qtrk(gStore.getData(this).qtrk[0]),
  ptAxis(gStore.getData(this).ptAxis[0]),
  plAxis(gStore.getData(this).plAxis[0])
{
}

panda::SVDaughter::SVDaughter(SVDaughter const& _src) :
  UnpackedPFCand(new SVDaughterArray(1, _src.getName())),
  dxySV(gStore.getData(this).dxySV[0]),
  dzSV(gStore.getData(this).dzSV[0]),
  rawPhi(gStore.getData(this).rawPhi[0]),
  qtrk(gStore.getData(this).qtrk[0]),
  ptAxis(gStore.getData(this).ptAxis[0]),
  plAxis(gStore.getData(this).plAxis[0])
{
  operator=(_src);
}

panda::SVDaughter::SVDaughter(datastore& _data, UInt_t _idx) :
  UnpackedPFCand(_data, _idx),
  dxySV(_data.dxySV[_idx]),
  dzSV(_data.dzSV[_idx]),
  rawPhi(_data.rawPhi[_idx]),
  qtrk(_data.qtrk[_idx]),
  ptAxis(_data.ptAxis[_idx]),
  plAxis(_data.plAxis[_idx])
{
}

panda::SVDaughter::SVDaughter(ArrayBase* _array) :
  UnpackedPFCand(_array),
  dxySV(gStore.getData(this).dxySV[0]),
  dzSV(gStore.getData(this).dzSV[0]),
  rawPhi(gStore.getData(this).rawPhi[0]),
  qtrk(gStore.getData(this).qtrk[0]),
  ptAxis(gStore.getData(this).ptAxis[0]),
  plAxis(gStore.getData(this).plAxis[0])
{
}

panda::SVDaughter::~SVDaughter()
{
  destructor();
}

void
panda::SVDaughter::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM SVDaughter.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    UnpackedPFCand::destructor(kTRUE);
}

panda::SVDaughter&
panda::SVDaughter::operator=(SVDaughter const& _src)
{
  UnpackedPFCand::operator=(_src);

  dxySV = _src.dxySV;
  dzSV = _src.dzSV;
  rawPhi = _src.rawPhi;
  qtrk = _src.qtrk;
  ptAxis = _src.ptAxis;
  plAxis = _src.plAxis;

  /* BEGIN CUSTOM SVDaughter.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
panda::SVDaughter::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  UnpackedPFCand::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "dxySV", "", 'F', &dxySV, _branches);
  utils::book(_tree, _name, "dzSV", "", 'F', &dzSV, _branches);
  utils::book(_tree, _name, "rawPhi", "", 'F', &rawPhi, _branches);
  utils::book(_tree, _name, "qtrk", "", 'S', &qtrk, _branches);
  utils::book(_tree, _name, "ptAxis", "", 'F', &ptAxis, _branches);
  utils::book(_tree, _name, "plAxis", "", 'F', &plAxis, _branches);
}

void
panda::SVDaughter::doInit_()
{
  UnpackedPFCand::doInit_();

  dxySV = 0.;
  dzSV = 0.;
  rawPhi = 0.;
  qtrk = 0;
  ptAxis = 0.;
  plAxis = 0.;

  /* BEGIN CUSTOM SVDaughter.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::SVDaughter::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM SVDaughter.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::SVDaughter::dump(std::ostream& _out/* = std::cout*/) const
{
  UnpackedPFCand::dump(_out);

  _out << "dxySV = " << dxySV << std::endl;
  _out << "dzSV = " << dzSV << std::endl;
  _out << "rawPhi = " << rawPhi << std::endl;
  _out << "qtrk = " << qtrk << std::endl;
  _out << "ptAxis = " << ptAxis << std::endl;
  _out << "plAxis = " << plAxis << std::endl;
}

/* BEGIN CUSTOM SVDaughter.cc.global */
/* END CUSTOM */
