#ifndef PandaTree_Interface_IOUtils_h
#define PandaTree_Interface_IOUtils_h

#include "Rtypes.h"
#include "TString.h"

#include <vector>
#include <initializer_list>

class TTree;

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

    Int_t setStatus(TTree&, TString const& objName, BranchName const& bName, Bool_t status, BranchList const&);
    Int_t setStatusAndAddress(TTree&, TString const& objName, BranchName const& bName, void* bPtr, BranchList const&);
    Int_t book(TTree&, TString const& objName, BranchName const& bName, TString const& size, char lType, void* bPtr, BranchList const&);

  }
}

#endif
