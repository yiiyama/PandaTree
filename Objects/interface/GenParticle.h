#ifndef PandaTree_Objects_GenParticle_h
#define PandaTree_Objects_GenParticle_h
#include "Constants.h"
#include "PackedParticle.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class GenParticle : public PackedParticle {
  public:
    struct datastore : public PackedParticle::datastore {
      datastore() : PackedParticle::datastore() {}
      ~datastore() { deallocate(); }

      /* PackedParticle
      UShort_t* packedPt{0};
      Short_t* packedPhi{0};
      UShort_t* packedM{0};
      */
      Short_t* packedY{0};
      Int_t* pdgid{0};
      UShort_t* statusFlags{0};
      ContainerBase const* parentContainer_{0};
      Int_t* parent_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<GenParticle> array_type;
    typedef Collection<GenParticle> collection_type;

    typedef PackedParticle base_type;

    GenParticle(char const* name = "");
    GenParticle(GenParticle const&);
    GenParticle(datastore&, UInt_t idx);
    ~GenParticle();
    GenParticle& operator=(GenParticle const&);

    /* PackedParticle
    UShort_t& packedPt;
    Short_t& packedPhi;
    UShort_t& packedM;
    */
    Short_t& packedY;
    Int_t& pdgid;
    UShort_t& statusFlags;
    Ref<GenParticle> parent;

    /* BEGIN CUSTOM GenParticle.h.classdef */
  protected:
    //! Value of packedEta for GenParticle corresponds to *rapidity*, not pseudorapidity.
    void pack_() override;
    void unpack_() const override;

  public:
    /* END CUSTOM */

    void destructor() override;

  protected:
    GenParticle(ArrayBase*);

    void doSetStatus_(TTree&, TString const&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&, TString const&) const override;
    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&, TString const&) override;
    void doInit_() override;
  };

  typedef GenParticle::array_type GenParticleArray;
  typedef GenParticle::collection_type GenParticleCollection;
  typedef Ref<GenParticle> GenParticleRef;
  typedef RefVector<GenParticle> GenParticleRefVector;

  /* BEGIN CUSTOM GenParticle.h.global */
  /* END CUSTOM */

}

#endif
