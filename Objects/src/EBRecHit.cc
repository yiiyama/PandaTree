#include "../interface/EBRecHit.h"

/*static*/
panda::utils::BranchList
panda::EBRecHit::getListOfBranches()
{
  utils::BranchList blist;
  blist += {"energy", "time", "timeError", "ieta", "iphi", "superCluster_"};
  return blist;
}

void
panda::EBRecHit::datastore::allocate(UInt_t _nmax)
{
  Element::datastore::allocate(_nmax);

  energy = new Float_t[nmax_];
  time = new Float_t[nmax_];
  timeError = new Float_t[nmax_];
  ieta = new Short_t[nmax_];
  iphi = new Short_t[nmax_];
  superCluster_ = new Short_t[nmax_];
}

void
panda::EBRecHit::datastore::deallocate()
{
  Element::datastore::deallocate();

  delete [] energy;
  energy = 0;
  delete [] time;
  time = 0;
  delete [] timeError;
  timeError = 0;
  delete [] ieta;
  ieta = 0;
  delete [] iphi;
  iphi = 0;
  delete [] superCluster_;
  superCluster_ = 0;
}

void
panda::EBRecHit::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Element::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "energy", _branches);
  utils::setStatus(_tree, _name, "time", _branches);
  utils::setStatus(_tree, _name, "timeError", _branches);
  utils::setStatus(_tree, _name, "ieta", _branches);
  utils::setStatus(_tree, _name, "iphi", _branches);
  utils::setStatus(_tree, _name, "superCluster_", _branches);
}

panda::utils::BranchList
panda::EBRecHit::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Element::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "energy"));
  blist.push_back(utils::getStatus(_tree, _name, "time"));
  blist.push_back(utils::getStatus(_tree, _name, "timeError"));
  blist.push_back(utils::getStatus(_tree, _name, "ieta"));
  blist.push_back(utils::getStatus(_tree, _name, "iphi"));
  blist.push_back(utils::getStatus(_tree, _name, "superCluster_"));

  return blist;
}

void
panda::EBRecHit::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Element::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "energy", energy, _branches, _setStatus);
  utils::setAddress(_tree, _name, "time", time, _branches, _setStatus);
  utils::setAddress(_tree, _name, "timeError", timeError, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ieta", ieta, _branches, _setStatus);
  utils::setAddress(_tree, _name, "iphi", iphi, _branches, _setStatus);
  utils::setAddress(_tree, _name, "superCluster_", superCluster_, _branches, _setStatus);
}

void
panda::EBRecHit::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Element::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "energy", size, 'F', energy, _branches);
  utils::book(_tree, _name, "time", size, 'F', time, _branches);
  utils::book(_tree, _name, "timeError", size, 'F', timeError, _branches);
  utils::book(_tree, _name, "ieta", size, 'S', ieta, _branches);
  utils::book(_tree, _name, "iphi", size, 'S', iphi, _branches);
  utils::book(_tree, _name, "superCluster_", size, 'S', superCluster_, _branches);
}

void
panda::EBRecHit::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Element::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "energy");
  utils::resetAddress(_tree, _name, "time");
  utils::resetAddress(_tree, _name, "timeError");
  utils::resetAddress(_tree, _name, "ieta");
  utils::resetAddress(_tree, _name, "iphi");
  utils::resetAddress(_tree, _name, "superCluster_");
}

void
panda::EBRecHit::datastore::resizeVectors_(UInt_t _size)
{
  Element::datastore::resizeVectors_(_size);

}


panda::utils::BranchList
panda::EBRecHit::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return EBRecHit::getListOfBranches().fullNames(_name);
}

panda::EBRecHit::EBRecHit(char const* _name/* = ""*/) :
  Element(new EBRecHitArray(1, _name)),
  energy(gStore.getData(this).energy[0]),
  time(gStore.getData(this).time[0]),
  timeError(gStore.getData(this).timeError[0]),
  ieta(gStore.getData(this).ieta[0]),
  iphi(gStore.getData(this).iphi[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0])
{
}

panda::EBRecHit::EBRecHit(EBRecHit const& _src) :
  Element(new EBRecHitArray(1, gStore.getName(&_src))),
  energy(gStore.getData(this).energy[0]),
  time(gStore.getData(this).time[0]),
  timeError(gStore.getData(this).timeError[0]),
  ieta(gStore.getData(this).ieta[0]),
  iphi(gStore.getData(this).iphi[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0])
{
  Element::operator=(_src);

  energy = _src.energy;
  time = _src.time;
  timeError = _src.timeError;
  ieta = _src.ieta;
  iphi = _src.iphi;
  superCluster = _src.superCluster;
}

panda::EBRecHit::EBRecHit(datastore& _data, UInt_t _idx) :
  Element(_data, _idx),
  energy(_data.energy[_idx]),
  time(_data.time[_idx]),
  timeError(_data.timeError[_idx]),
  ieta(_data.ieta[_idx]),
  iphi(_data.iphi[_idx]),
  superCluster(_data.superClusterContainer_, _data.superCluster_[_idx])
{
}

panda::EBRecHit::EBRecHit(ArrayBase* _array) :
  Element(_array),
  energy(gStore.getData(this).energy[0]),
  time(gStore.getData(this).time[0]),
  timeError(gStore.getData(this).timeError[0]),
  ieta(gStore.getData(this).ieta[0]),
  iphi(gStore.getData(this).iphi[0]),
  superCluster(gStore.getData(this).superClusterContainer_, gStore.getData(this).superCluster_[0])
{
}

panda::EBRecHit::~EBRecHit()
{
  destructor();
  gStore.free(this);
}

void
panda::EBRecHit::destructor()
{
  /* BEGIN CUSTOM EBRecHit.cc.destructor */
  /* END CUSTOM */

  Element::destructor();
}

panda::EBRecHit&
panda::EBRecHit::operator=(EBRecHit const& _src)
{
  energy = _src.energy;
  time = _src.time;
  timeError = _src.timeError;
  ieta = _src.ieta;
  iphi = _src.iphi;
  superCluster = _src.superCluster;

  return *this;
}

void
panda::EBRecHit::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  utils::setAddress(_tree, _name, "energy", &energy, _branches, _setStatus);
  utils::setAddress(_tree, _name, "time", &time, _branches, _setStatus);
  utils::setAddress(_tree, _name, "timeError", &timeError, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ieta", &ieta, _branches, _setStatus);
  utils::setAddress(_tree, _name, "iphi", &iphi, _branches, _setStatus);
  utils::setAddress(_tree, _name, "superCluster_", gStore.getData(this).superCluster_, _branches, true);
}

void
panda::EBRecHit::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  utils::book(_tree, _name, "energy", "", 'F', &energy, _branches);
  utils::book(_tree, _name, "time", "", 'F', &time, _branches);
  utils::book(_tree, _name, "timeError", "", 'F', &timeError, _branches);
  utils::book(_tree, _name, "ieta", "", 'S', &ieta, _branches);
  utils::book(_tree, _name, "iphi", "", 'S', &iphi, _branches);
  utils::book(_tree, _name, "superCluster_", "", 'S', gStore.getData(this).superCluster_, _branches);
}

void
panda::EBRecHit::doInit_()
{
  energy = 0.;
  time = 0.;
  timeError = 0.;
  ieta = 0;
  iphi = 0;
  superCluster.init();

  /* BEGIN CUSTOM EBRecHit.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::EBRecHit::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM EBRecHit.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::EBRecHit::dump(std::ostream& _out/* = std::cout*/) const
{
  _out << "energy = " << energy << std::endl;
  _out << "time = " << time << std::endl;
  _out << "timeError = " << timeError << std::endl;
  _out << "ieta = " << ieta << std::endl;
  _out << "iphi = " << iphi << std::endl;
  _out << "superCluster = " << superCluster << std::endl;
}

/* BEGIN CUSTOM EBRecHit.cc.global */
/* END CUSTOM */
