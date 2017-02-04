#ifndef PandaTree_Interface_IOUtils_h
#define PandaTree_Interface_IOUtils_h

#include "TString.h"
#include "TTree.h"

#include <vector>

namespace panda {
  namespace utils {

    class BranchList;

    //! Tokenized branch name
    /*!
     * Represents a branch name given in formats like muons.pt by a vector {"muons", "pt"}.
     * The name can be preceded by '!' to indicate a veto for the branch.
     * Wild card (*) is also allowed, and will match to either one section of the name or to the
     * entire remainder.
     */
    class BranchName : public std::vector<TString> {
    public:
      BranchName() {}
      BranchName(BranchName const&);
      BranchName(char const*);
      BranchName(std::string const&);
      //! Concatenate the words with '.'
      operator TString() const;
      //! Prepend the branch name with <objName.>.
      TString fullName(TString const& objName) const;
      //! Did the name start with a '!'?
      bool isVeto() const { return isVeto_; }
      //! Does the name match with the given name?
      /*!
       * Only considers the name part and not the veto-ness.
       */
      bool match(BranchName const&) const;
      //! Is the name included and not vetoed?
      /*!
       * Does not take the veto on the parent object into account. Simply asks the question
       * "is the name in the given list and not vetoed in the list?"
       */
      bool in(BranchList const&) const;
      //! Is the name included and vetoed?
      /*!
       * Does not take the veto on the parent object into account. Simply asks the question
       * "is the name in the given list and vetoed in the list?"
       */
      bool vetoed(BranchList const&) const;

    private:
      bool isVeto_{false};
    };

    //! List of branch names
    /*!
     * Basically a vector of BranchNames with a few facilities.
     */
    class BranchList : public std::vector<BranchName> {
    public:
      BranchList() {}
      BranchList(std::initializer_list<value_type> il, const allocator_type& alloc = allocator_type()) : std::vector<BranchName>(il, alloc) {}
      //! Return a new list of branches that starts with the objName, removing <objName.> from each.
      BranchList subList(TString const& objName) const;
      //! Returns true if any of the branch in the list is not vetoed.
      bool any() const;
    };

    //! Check status of a branch
    /*!
     * Return values:
     * -1 branch does not exist
     * 0  status is current
     * 1  status is different
     */
    Int_t checkStatus(TTree&, TString const& fullName, Bool_t status);
    //! Set status of a branch
    /*!
     * Return values:
     * -2 branch is not in given list
     * -1 branch does not exist
     * 0  status is already set
     * 1  status is changed
     */
    Int_t setStatus(TTree&, TString const& objName, BranchName const& bName, BranchList const&);
    //! Set address
    /*!
     * Return values:
     * -2 branch is not in given list
     * -1 branch does not exist
     * 0  status is false and address is not set
     * 1  status is true and address is set
     */
    Int_t setAddress(TTree&, TString const& objName, BranchName const& bName, void* bPtr, BranchList const&, Bool_t setStatus);
    //! Book the branch
    /*!
     * Return values:
     * -2 branch is not in given list
     * 1  branch is booked
     * Throws in case of double-booking
     */
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
