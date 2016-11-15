#include "../interface/IOUtils.h"

#include "TString.h"
#include "TObjArray.h"
#include "TTree.h"

#include <utility>

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
panda::utils::setStatus(TTree& _tree, TString const& _objName, BranchName const& _bName, Bool_t _status, BranchList const& _bList)
{
  // can assume that _bList is a list of terminal branches

  TString bFullName(_bName);
  if (_objName.Length() != 0)
    bFullName.Prepend(_objName + ".");

  if (!_tree.GetBranch(bFullName))
    return -1;

  if (!_bName.in(_bList))
    return -1;

  if (_tree.GetBranchStatus(bFullName) == _status)
    return 0;

  _tree.SetBranchStatus(bFullName, _status);
  return 1;
}

Int_t
panda::utils::setStatusAndAddress(TTree& _tree, TString const& _objName, BranchName const& _bName, void* _bPtr, BranchList const& _bList)
{
  if (setStatus(_tree, _objName, _bName, true, _bList) == -1)
    return -1;

  TString bFullName(_bName);
  if (_objName.Length() != 0)
    bFullName.Prepend(_objName + ".");

  _tree.SetBranchAddress(bFullName, _bPtr);

  return 1;
}

Int_t 
panda::utils::book(TTree& _tree, TString const& _objName, BranchName const& _bName, TString const& _size, char _lType, void* _bPtr, BranchList const& _bList)
{
  // bName: electrons.pt
  // size: [electrons.size]
  // lType: F

  if (!_bName.in(_bList))
    return -1;

  TString bFullName(_bName);
  if (_objName.Length() != 0)
    bFullName.Prepend(_objName + ".");

  TString lExpr(_bName + _size);

  lExpr += "/";
  lExpr += _lType;

  _tree.Branch(bFullName, _bPtr, lExpr);

  return 0;
}
