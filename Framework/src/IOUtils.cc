#include "../interface/IOUtils.h"

#include <stdexcept>

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

panda::utils::BranchName::BranchName(std::string const& _name) :
  BranchName(_name.c_str())
{
}

panda::utils::BranchName::operator TString() const
{
  TString name;

  if (isVeto_)
    name = "!";

  for (unsigned iN(0); iN != size() - 1; ++iN)
    name += (*this)[iN] + ".";

  name += back();

  return name;
}

TString
panda::utils::BranchName::fullName(TString const& _objName) const
{
  TString bFullName(*this);

  if (_objName.Length() != 0) {
    if (isVeto_) {
      // remove the leading '!'
      bFullName = bFullName(1, bFullName.Length());
    }
    
    bFullName.Prepend(_objName + ".");

    if (isVeto_) {
      // and add it to the front
      bFullName.Prepend("!");
    }
  }

  return bFullName;
}

bool
panda::utils::BranchName::match(BranchName const& _rhs) const
{
  // case 1. Both names are null. -> no match
  if (size() == 0 || _rhs.size() == 0)
    return false;

  // now match the names word by word
  for (unsigned iP(0); iP != size(); ++iP) {
    // case 2. RHS has fewer words, but agreeds up to the last word. -> match
    if (iP == _rhs.size())
      return true;

    // case 3. A word does not agree. -> no match
    if ((*this)[iP] != "*" && _rhs[iP] != "*" && (*this)[iP] != _rhs[iP])
      return false;
  }
        
  // case 4. A perfect match.
  // case 5. RHS has more words.
  // -> both considered a match
  return true;
}

bool
panda::utils::BranchName::in(BranchList const& _list) const
{
  // last match determines the result

  bool included(false);
  for (auto& bname : _list) {
    if (match(bname))
      included = !bname.isVeto();
  }
  return included;
}

bool
panda::utils::BranchName::vetoed(BranchList const& _list) const
{
  // last match determines the result

  bool vetoed(false);
  for (auto& bname : _list) {
    if (match(bname))
      vetoed = bname.isVeto();
  }
  return vetoed;
}

panda::utils::BranchList
panda::utils::BranchList::subList(TString const& _objName) const
{
  BranchList list;

  // loop over my branch names
  for (auto& b : *this) {
    // if the first name is not * and not objName, skip
    if (b.size() == 0 || (b[0] != "*" && b[0] != _objName))
      continue;

    list.emplace_back(b);
    auto& bname(list.back());

    // if the branch name is just objName, consider it as objName.*
    if (bname.size() == 1)
      bname.emplace_back("*");

    // remove the objName. part
    bname.erase(bname.begin());
  }

  return list;
}

bool
panda::utils::BranchList::any() const
{
  // loop over my branch names
  for (auto& b : *this) {
    if (!b.isVeto())
      return true;
  }

  return false;
}

Int_t
panda::utils::checkStatus(TTree& _tree, TString const& _fullName, Bool_t _status)
{
  if (!_tree.GetBranch(_fullName))
    return -1;

  if (_tree.GetBranchStatus(_fullName) == _status)
    return 0;
  else
    return 1;
}

Int_t
panda::utils::setStatus(TTree& _tree, TString const& _objName, BranchName const& _bName, BranchList const& _bList)
{
  bool status;
  if (_bName.in(_bList))
    status = true;
  else if (_bName.vetoed(_bList))
    status = false;
  else
    return -2;

  TString fullName(_bName.fullName(_objName));

  // -1 -> branch does not exist; 0 -> status is already set; 1 -> status is different
  Int_t returnCode(checkStatus(_tree, fullName, status));
  if (returnCode != 1)
    return returnCode;

  _tree.SetBranchStatus(fullName, status);
  return 1;
}

Int_t
panda::utils::setAddress(TTree& _tree, TString const& _objName, BranchName const& _bName, void* _bPtr, BranchList const& _bList, Bool_t _setStatus)
{
  Int_t returnCode(0);

  TString fullName(_bName.fullName(_objName));

  if (_setStatus) {
    returnCode = setStatus(_tree, _objName, _bName, _bList);
    if (returnCode < 0) // branch does not exist or is not in the list (includes vetoed case)
      return returnCode;
  }
  else {
    if (!_bName.in(_bList))
      return -2;

    // -1 -> branch does not exist; 0 -> status is false; 1 -> status is true
    returnCode = checkStatus(_tree, fullName, false);
    if (returnCode != 1)
      return returnCode;
  }

  _tree.SetBranchAddress(fullName, _bPtr);
  return 1;
}

Int_t 
panda::utils::book(TTree& _tree, TString const& _objName, BranchName const& _bName, TString const& _size, char _lType, void* _bPtr, BranchList const& _bList)
{
  // objName: electrons
  // bName: pt
  // size: [electrons.size]
  // lType: F

  if (!_bName.in(_bList))
    return -2;

  TString fullName(_bName.fullName(_objName));
  if (_tree.GetBranch(fullName))
    throw std::runtime_error(("Branch " + fullName + " booked twice").Data());

  TString lExpr(_bName + _size);

  lExpr += "/";
  lExpr += _lType;

  _tree.Branch(_bName.fullName(_objName), _bPtr, lExpr);

  return 1;
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
