#ifndef PandaTree_Interface_IOUtils_h
#define PandaTree_Interface_IOUtils_h

#include "TString.h"
#include "TTree.h"

#include <vector>

namespace panda {
  namespace utils {

    class BranchList;

    class BranchName : public std::vector<TString> {
    // tokenized branch name
    public:
      BranchName() {}
      BranchName(BranchName const&);
      BranchName(char const*);
      operator TString() const;

      TString fullName(TString const& objName) const;
      bool isVeto() const { return isVeto_; }
      bool match(BranchName const&) const;
      bool in(BranchList const&) const;

    private:
      bool isVeto_{false};
    };

    class BranchList : public std::vector<BranchName> {
    public:
      BranchList() {}
      BranchList(std::initializer_list<value_type> il, const allocator_type& alloc = allocator_type()) : std::vector<BranchName>(il, alloc) {}
      BranchList subList(TString const& objName) const;
    };

    Int_t checkStatus(TTree&, TString const& objName, BranchName const& bName, Bool_t status, BranchList const&);
    Int_t setStatus(TTree&, TString const& objName, BranchName const& bName, Bool_t status, BranchList const&);
    Int_t setAddress(TTree&, TString const& objName, BranchName const& bName, void* bPtr, BranchList const&, Bool_t setStatus);
    Int_t book(TTree&, TString const& objName, BranchName const& bName, TString const& size, char lType, void* bPtr, BranchList const&);
    Int_t resetAddress(TTree&, TString const& objName, BranchName const& bName);

    template<class O>
    Int_t
    book(TTree& _tree, TString const& _objName, BranchName const& _bName, TString const& _objType, O** _bPtr, BranchList const& _bList)
    {
      // objName: electrons
      // bName: tags
      // objType: std::vector<int>

      if (!_bName.in(_bList))
        return -1;

      _tree.Branch(_bName.fullName(_objName), _objType, _bPtr);

      return 0;
    }
  }
}

#endif
