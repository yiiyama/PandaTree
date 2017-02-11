#include "../interface/Object.h"

#include "TTree.h"

Int_t
panda::Object::getEntry(Long64_t _entry, UInt_t _treeIdx/* = 0*/)
{
  auto* tree(getInput(_treeIdx));
  if (tree) {
    init();
    return tree->GetEntry(_entry);
  }
  else
    return -1;
}
