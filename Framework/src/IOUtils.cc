#include "../interface/IOUtils.h"

panda::utils::BranchName::BranchName(BranchName const& _src) :
  std::vector<TString>(_src),
  isVeto_(_src.isVeto_)
{
}

panda::utils::BranchName::BranchName(char const* _name)
{
  TString name(_name);
  if (name[0] == '!') {
    isVeto_ = true;
    name = name(1, name.Length());
  }

  auto* parts(name.Tokenize("."));

  for (auto* s : *parts)
    emplace_back(s->GetName());

  delete parts;
}

panda::utils::BranchName::operator TString() const
{
  TString name;
  for (unsigned iN(0); iN != size() - 1; ++iN)
    name += (*this)[iN] + ".";
  name += back();

  return name;
}

TString
panda::utils::BranchName::fullName(TString const& _objName) const
{
  TString bFullName(*this);
  if (_objName.Length() != 0)
    bFullName.Prepend(_objName + ".");

  return bFullName;
}

bool
panda::utils::BranchName::match(BranchName const& _rhs) const
{
  if (size() == 0 || _rhs.size() == 0)
    return false;

  for (unsigned iP(0); iP != size(); ++iP) {
    if (iP == _rhs.size()) // this has more sub-branches -> consider as match
      return true;

    if ((*this)[iP] == "*" || _rhs[iP] == "*" || (*this)[iP] == _rhs[iP])
      continue;

    return false;
  }
        
  // rhs has more sub-branches -> also consider as match
  // or it's a perfect match
  return true;
}

bool
panda::utils::BranchName::in(BranchList const& _list) const
{
  // last match determines

  bool included(false);
  for (auto& bname : _list) {
    if (match(bname))
      included = !bname.isVeto();
  }
  return included;
}

panda::utils::BranchList
panda::utils::BranchList::subList(TString const& _objName) const
{
  BranchList list;

  for (auto& b : *this) {
    if (b.size() == 0 || (b[0] != "*" && b[0] != _objName))
      continue;

    list.push_back(b);
    auto& bname(list.back());

    if (bname.size() == 1)
      bname.emplace_back("*");
    bname.erase(bname.begin());
  }

  return list;
}

Int_t
panda::utils::checkStatus(TTree& _tree, TString const& _objName, BranchName const& _bName, Bool_t _status, BranchList const& _bList)
{
  // we can assume that _bList is a list of terminal branches
  if (!_bName.in(_bList))
    return -1;

  TString fullName(_bName.fullName(_objName));

  if (!_tree.GetBranch(fullName))
    return -1;

  if (_tree.GetBranchStatus(fullName) == _status)
    return 0;
  else
    return 1;
}

Int_t
panda::utils::setStatus(TTree& _tree, TString const& _objName, BranchName const& _bName, Bool_t _status, BranchList const& _bList)
{
  // -1 -> branch does not exist or not in the list; 0 -> status is already set
  Int_t checkResult(checkStatus(_tree, _objName, _bName, _status, _bList));
  if (checkResult != 0)
    return checkResult;

  _tree.SetBranchStatus(_bName.fullName(_objName), _status);
  return 1;
}

Int_t
panda::utils::setAddress(TTree& _tree, TString const& _objName, BranchName const& _bName, void* _bPtr, BranchList const& _bList, Bool_t _setStatus)
{
  Int_t returnCode(0);

  if (_setStatus) {
    returnCode = setStatus(_tree, _objName, _bName, true, _bList);
    if (returnCode == -1)
      return -1;
  }
  else {
    // -1 -> branch does not exist or not in the list; 0 -> status is false
    returnCode = checkStatus(_tree, _objName, _bName, false, _bList);
    if (returnCode != 1)
      return returnCode;
  }

  _tree.SetBranchAddress(_bName.fullName(_objName), _bPtr);
  return returnCode;
}

Int_t 
panda::utils::book(TTree& _tree, TString const& _objName, BranchName const& _bName, TString const& _size, char _lType, void* _bPtr, BranchList const& _bList)
{
  // objName: electrons
  // bName: pt
  // size: [electrons.size]
  // lType: F

  if (!_bName.in(_bList))
    return -1;

  TString lExpr(_bName + _size);

  lExpr += "/";
  lExpr += _lType;

  _tree.Branch(_bName.fullName(_objName), _bPtr, lExpr);

  return 0;
}

Int_t 
panda::utils::resetAddress(TTree& _tree, TString const& _objName, BranchName const& _bName)
{
  // bName: electrons.pt
  auto* branch(_tree.GetBranch(_bName.fullName(_objName)));
  if (branch)
    branch->ResetAddress();

  return 0;
}
