#include "../interface/GenReweight.h"

panda::GenReweight::GenReweight(char const* _name/* = ""*/) :
  Singlet(_name)
{
}

panda::GenReweight::GenReweight(GenReweight const& _src) :
  Singlet(_src.name_),
  r1f2(_src.r1f2),
  r1f5(_src.r1f5),
  r2f1(_src.r2f1),
  r2f2(_src.r2f2),
  r5f1(_src.r5f1),
  r5f5(_src.r5f5),
  pdf(_src.pdf)
{
  r1f2 = _src.r1f2;
  r1f5 = _src.r1f5;
  r2f1 = _src.r2f1;
  r2f2 = _src.r2f2;
  r5f1 = _src.r5f1;
  r5f5 = _src.r5f5;
  pdf = _src.pdf;
  std::memcpy(genParam, _src.genParam, sizeof(Float_t) * 128);
}

panda::GenReweight::~GenReweight()
{
}

panda::GenReweight&
panda::GenReweight::operator=(GenReweight const& _src)
{
  Singlet::operator=(_src);

  r1f2 = _src.r1f2;
  r1f5 = _src.r1f5;
  r2f1 = _src.r2f1;
  r2f2 = _src.r2f2;
  r5f1 = _src.r5f1;
  r5f5 = _src.r5f5;
  pdf = _src.pdf;
  std::memcpy(genParam, _src.genParam, sizeof(Float_t) * 128);

  return *this;
}

void
panda::GenReweight::setStatus(TTree& _tree, Bool_t _status, utils::BranchList const& _branches/* = {}*/)
{
  Singlet::setStatus(_tree, _status, _branches);

  utils::setStatus(_tree, name_, "r1f2", _status, _branches);
  utils::setStatus(_tree, name_, "r1f5", _status, _branches);
  utils::setStatus(_tree, name_, "r2f1", _status, _branches);
  utils::setStatus(_tree, name_, "r2f2", _status, _branches);
  utils::setStatus(_tree, name_, "r5f1", _status, _branches);
  utils::setStatus(_tree, name_, "r5f5", _status, _branches);
  utils::setStatus(_tree, name_, "pdf", _status, _branches);
  utils::setStatus(_tree, name_, "genParam", _status, _branches);
}

void
panda::GenReweight::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Singlet::setAddress(_tree, _branches, _setStatus);

  utils::setAddress(_tree, name_, "r1f2", &r1f2, _branches, _setStatus);
  utils::setAddress(_tree, name_, "r1f5", &r1f5, _branches, _setStatus);
  utils::setAddress(_tree, name_, "r2f1", &r2f1, _branches, _setStatus);
  utils::setAddress(_tree, name_, "r2f2", &r2f2, _branches, _setStatus);
  utils::setAddress(_tree, name_, "r5f1", &r5f1, _branches, _setStatus);
  utils::setAddress(_tree, name_, "r5f5", &r5f5, _branches, _setStatus);
  utils::setAddress(_tree, name_, "pdf", &pdf, _branches, _setStatus);
  utils::setAddress(_tree, name_, "genParam", genParam, _branches, _setStatus);
}

void
panda::GenReweight::book(TTree& _tree, utils::BranchList const& _branches/* = {}*/)
{
  Singlet::book(_tree, _branches);

  utils::book(_tree, name_, "r1f2", "", 'F', &r1f2, _branches);
  utils::book(_tree, name_, "r1f5", "", 'F', &r1f5, _branches);
  utils::book(_tree, name_, "r2f1", "", 'F', &r2f1, _branches);
  utils::book(_tree, name_, "r2f2", "", 'F', &r2f2, _branches);
  utils::book(_tree, name_, "r5f1", "", 'F', &r5f1, _branches);
  utils::book(_tree, name_, "r5f5", "", 'F', &r5f5, _branches);
  utils::book(_tree, name_, "pdf", "", 'F', &pdf, _branches);
  utils::book(_tree, name_, "genParam", "[128]", 'F', genParam, _branches);
}

void
panda::GenReweight::resetAddress(TTree& _tree)
{
  Singlet::resetAddress(_tree);

  utils::resetAddress(_tree, name_, "r1f2");
  utils::resetAddress(_tree, name_, "r1f5");
  utils::resetAddress(_tree, name_, "r2f1");
  utils::resetAddress(_tree, name_, "r2f2");
  utils::resetAddress(_tree, name_, "r5f1");
  utils::resetAddress(_tree, name_, "r5f5");
  utils::resetAddress(_tree, name_, "pdf");
  utils::resetAddress(_tree, name_, "genParam");
}

void
panda::GenReweight::init()
{
  Singlet::init();

  r1f2 = 0.;
  r1f5 = 0.;
  r2f1 = 0.;
  r2f2 = 0.;
  r5f1 = 0.;
  r5f5 = 0.;
  pdf = 0.;
  for (auto& p0 : genParam) p0 = 0.;
}

/* BEGIN CUSTOM GenReweight.cc.global */
/* END CUSTOM */
