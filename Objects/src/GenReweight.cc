#include "../interface/GenReweight.h"

panda::GenReweight::GenReweight(char const* _name/* = ""*/) :
  Singlet(_name)
{
}

panda::GenReweight::GenReweight(GenReweight const& _src) :
  Singlet(_src.name_),
  r1f2DW(_src.r1f2DW),
  r1f5DW(_src.r1f5DW),
  r2f1DW(_src.r2f1DW),
  r2f2DW(_src.r2f2DW),
  r5f1DW(_src.r5f1DW),
  r5f5DW(_src.r5f5DW),
  pdfDW(_src.pdfDW)
{
  r1f2DW = _src.r1f2DW;
  r1f5DW = _src.r1f5DW;
  r2f1DW = _src.r2f1DW;
  r2f2DW = _src.r2f2DW;
  r5f1DW = _src.r5f1DW;
  r5f5DW = _src.r5f5DW;
  pdfDW = _src.pdfDW;
  std::memcpy(genParam, _src.genParam, sizeof(Float_t) * 128);
}

panda::GenReweight::~GenReweight()
{
}

panda::GenReweight&
panda::GenReweight::operator=(GenReweight const& _src)
{
  Singlet::operator=(_src);

  r1f2DW = _src.r1f2DW;
  r1f5DW = _src.r1f5DW;
  r2f1DW = _src.r2f1DW;
  r2f2DW = _src.r2f2DW;
  r5f1DW = _src.r5f1DW;
  r5f5DW = _src.r5f5DW;
  pdfDW = _src.pdfDW;
  std::memcpy(genParam, _src.genParam, sizeof(Float_t) * 128);

  return *this;
}

void
panda::GenReweight::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  Singlet::doSetStatus_(_tree, _branches);

  utils::setStatus(_tree, name_, "r1f2DW", _branches);
  utils::setStatus(_tree, name_, "r1f5DW", _branches);
  utils::setStatus(_tree, name_, "r2f1DW", _branches);
  utils::setStatus(_tree, name_, "r2f2DW", _branches);
  utils::setStatus(_tree, name_, "r5f1DW", _branches);
  utils::setStatus(_tree, name_, "r5f5DW", _branches);
  utils::setStatus(_tree, name_, "pdfDW", _branches);
  utils::setStatus(_tree, name_, "genParam", _branches);
}

void
panda::GenReweight::doSetAddress_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Singlet::doSetAddress_(_tree, _branches, _setStatus);

  utils::setAddress(_tree, name_, "r1f2DW", &r1f2DW, _branches, _setStatus);
  utils::setAddress(_tree, name_, "r1f5DW", &r1f5DW, _branches, _setStatus);
  utils::setAddress(_tree, name_, "r2f1DW", &r2f1DW, _branches, _setStatus);
  utils::setAddress(_tree, name_, "r2f2DW", &r2f2DW, _branches, _setStatus);
  utils::setAddress(_tree, name_, "r5f1DW", &r5f1DW, _branches, _setStatus);
  utils::setAddress(_tree, name_, "r5f5DW", &r5f5DW, _branches, _setStatus);
  utils::setAddress(_tree, name_, "pdfDW", &pdfDW, _branches, _setStatus);
  utils::setAddress(_tree, name_, "genParam", genParam, _branches, _setStatus);
}

void
panda::GenReweight::doBook_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  Singlet::doBook_(_tree, _branches);

  utils::book(_tree, name_, "r1f2DW", "", 'F', &r1f2DW, _branches);
  utils::book(_tree, name_, "r1f5DW", "", 'F', &r1f5DW, _branches);
  utils::book(_tree, name_, "r2f1DW", "", 'F', &r2f1DW, _branches);
  utils::book(_tree, name_, "r2f2DW", "", 'F', &r2f2DW, _branches);
  utils::book(_tree, name_, "r5f1DW", "", 'F', &r5f1DW, _branches);
  utils::book(_tree, name_, "r5f5DW", "", 'F', &r5f5DW, _branches);
  utils::book(_tree, name_, "pdfDW", "", 'F', &pdfDW, _branches);
  utils::book(_tree, name_, "genParam", TString::Format("[128]"), 'F', genParam, _branches);
}

void
panda::GenReweight::doReleaseTree_(TTree& _tree)
{
  Singlet::doReleaseTree_(_tree);

  utils::resetAddress(_tree, name_, "r1f2DW");
  utils::resetAddress(_tree, name_, "r1f5DW");
  utils::resetAddress(_tree, name_, "r2f1DW");
  utils::resetAddress(_tree, name_, "r2f2DW");
  utils::resetAddress(_tree, name_, "r5f1DW");
  utils::resetAddress(_tree, name_, "r5f5DW");
  utils::resetAddress(_tree, name_, "pdfDW");
  utils::resetAddress(_tree, name_, "genParam");
}

void
panda::GenReweight::doInit_()
{
  Singlet::doInit_();

  r1f2DW = 0.;
  r1f5DW = 0.;
  r2f1DW = 0.;
  r2f2DW = 0.;
  r5f1DW = 0.;
  r5f5DW = 0.;
  pdfDW = 0.;
  for (auto& p0 : genParam) p0 = 0.;
}

/* BEGIN CUSTOM GenReweight.cc.global */
/* END CUSTOM */
