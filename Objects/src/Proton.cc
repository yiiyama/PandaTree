#include "../interface/Proton.h"

/*static*/
panda::utils::BranchList
panda::Proton::getListOfBranches()
{
  utils::BranchList blist;
  blist += {"x", "xUnc", "y", "yUnc", "rpId"};
  return blist;
}

void
panda::Proton::datastore::allocate(UInt_t _nmax)
{
  Element::datastore::allocate(_nmax);

  x = new Float_t[nmax_];
  xUnc = new Float_t[nmax_];
  y = new Float_t[nmax_];
  yUnc = new Float_t[nmax_];
  rpId = new Int_t[nmax_];
}

void
panda::Proton::datastore::deallocate()
{
  Element::datastore::deallocate();

  delete [] x;
  x = 0;
  delete [] xUnc;
  xUnc = 0;
  delete [] y;
  y = 0;
  delete [] yUnc;
  yUnc = 0;
  delete [] rpId;
  rpId = 0;
}

void
panda::Proton::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Element::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "x", _branches);
  utils::setStatus(_tree, _name, "xUnc", _branches);
  utils::setStatus(_tree, _name, "y", _branches);
  utils::setStatus(_tree, _name, "yUnc", _branches);
  utils::setStatus(_tree, _name, "rpId", _branches);
}

panda::utils::BranchList
panda::Proton::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Element::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "x"));
  blist.push_back(utils::getStatus(_tree, _name, "xUnc"));
  blist.push_back(utils::getStatus(_tree, _name, "y"));
  blist.push_back(utils::getStatus(_tree, _name, "yUnc"));
  blist.push_back(utils::getStatus(_tree, _name, "rpId"));

  return blist;
}

void
panda::Proton::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Element::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "x", x, _branches, _setStatus);
  utils::setAddress(_tree, _name, "xUnc", xUnc, _branches, _setStatus);
  utils::setAddress(_tree, _name, "y", y, _branches, _setStatus);
  utils::setAddress(_tree, _name, "yUnc", yUnc, _branches, _setStatus);
  utils::setAddress(_tree, _name, "rpId", rpId, _branches, _setStatus);
}

void
panda::Proton::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Element::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "x", size, 'F', x, _branches);
  utils::book(_tree, _name, "xUnc", size, 'F', xUnc, _branches);
  utils::book(_tree, _name, "y", size, 'F', y, _branches);
  utils::book(_tree, _name, "yUnc", size, 'F', yUnc, _branches);
  utils::book(_tree, _name, "rpId", size, 'I', rpId, _branches);
}

void
panda::Proton::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Element::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "x");
  utils::resetAddress(_tree, _name, "xUnc");
  utils::resetAddress(_tree, _name, "y");
  utils::resetAddress(_tree, _name, "yUnc");
  utils::resetAddress(_tree, _name, "rpId");
}

void
panda::Proton::datastore::resizeVectors_(UInt_t _size)
{
  Element::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::Proton::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return Proton::getListOfBranches().fullNames(_name);
}

panda::Proton::Proton(char const* _name/* = ""*/) :
  Element(new ProtonArray(1, _name)),
  x(gStore.getData(this).x[0]),
  xUnc(gStore.getData(this).xUnc[0]),
  y(gStore.getData(this).y[0]),
  yUnc(gStore.getData(this).yUnc[0]),
  rpId(gStore.getData(this).rpId[0])
{
}

panda::Proton::Proton(Proton const& _src) :
  Element(new ProtonArray(1, _src.getName())),
  x(gStore.getData(this).x[0]),
  xUnc(gStore.getData(this).xUnc[0]),
  y(gStore.getData(this).y[0]),
  yUnc(gStore.getData(this).yUnc[0]),
  rpId(gStore.getData(this).rpId[0])
{
  Element::operator=(_src);

  x = _src.x;
  xUnc = _src.xUnc;
  y = _src.y;
  yUnc = _src.yUnc;
  rpId = _src.rpId;
}

panda::Proton::Proton(datastore& _data, UInt_t _idx) :
  Element(_data, _idx),
  x(_data.x[_idx]),
  xUnc(_data.xUnc[_idx]),
  y(_data.y[_idx]),
  yUnc(_data.yUnc[_idx]),
  rpId(_data.rpId[_idx])
{
}

panda::Proton::Proton(ArrayBase* _array) :
  Element(_array),
  x(gStore.getData(this).x[0]),
  xUnc(gStore.getData(this).xUnc[0]),
  y(gStore.getData(this).y[0]),
  yUnc(gStore.getData(this).yUnc[0]),
  rpId(gStore.getData(this).rpId[0])
{
}

panda::Proton::~Proton()
{
  destructor();
}

void
panda::Proton::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM Proton.cc.destructor */
  /* END CUSTOM */
}

panda::Proton&
panda::Proton::operator=(Proton const& _src)
{
  x = _src.x;
  xUnc = _src.xUnc;
  y = _src.y;
  yUnc = _src.yUnc;
  rpId = _src.rpId;

  /* BEGIN CUSTOM Proton.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
panda::Proton::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  utils::book(_tree, _name, "x", "", 'F', &x, _branches);
  utils::book(_tree, _name, "xUnc", "", 'F', &xUnc, _branches);
  utils::book(_tree, _name, "y", "", 'F', &y, _branches);
  utils::book(_tree, _name, "yUnc", "", 'F', &yUnc, _branches);
  utils::book(_tree, _name, "rpId", "", 'I', &rpId, _branches);
}

void
panda::Proton::doInit_()
{
  x = 0.;
  xUnc = 0.;
  y = 0.;
  yUnc = 0.;
  rpId = 0;

  /* BEGIN CUSTOM Proton.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::Proton::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM Proton.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::Proton::dump(std::ostream& _out/* = std::cout*/) const
{
  _out << "x = " << x << std::endl;
  _out << "xUnc = " << xUnc << std::endl;
  _out << "y = " << y << std::endl;
  _out << "yUnc = " << yUnc << std::endl;
  _out << "rpId = " << rpId << std::endl;
}

/* BEGIN CUSTOM Proton.cc.global */
/* END CUSTOM */
