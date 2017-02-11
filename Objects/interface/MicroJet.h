#ifndef PandaTree_Objects_MicroJet_h
#define PandaTree_Objects_MicroJet_h
#include "Constants.h"
#include "ParticleM.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class MicroJet : public ParticleM {
  public:
    struct datastore : public ParticleM::datastore {
      datastore() : ParticleM::datastore() {}
      ~datastore() { deallocate(); }

      /* ParticleP
      Float_t* pt_{0};
      Float_t* eta_{0};
      Float_t* phi_{0};
      */
      /* ParticleM
      Float_t* mass_{0};
      */
      Float_t* csv{0};
      Float_t* qgl{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
      utils::BranchList getBranchNames(TString const&) const override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<MicroJet> array_type;
    typedef Collection<MicroJet> collection_type;

    typedef ParticleM base_type;

    MicroJet(char const* name = "");
    MicroJet(MicroJet const&);
    MicroJet(datastore&, UInt_t idx);
    ~MicroJet();
    MicroJet& operator=(MicroJet const&);

    Float_t& csv;
    Float_t& qgl;

  protected:
    /* ParticleP
    Float_t& pt_;
    Float_t& eta_;
    Float_t& phi_;
    */
    /* ParticleM
    Float_t& mass_;
    */

  public:
    /* BEGIN CUSTOM MicroJet.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    MicroJet(ArrayBase*);

    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&, TString const&) override;
    void doInit_() override;
  };

  typedef MicroJet::array_type MicroJetArray;
  typedef MicroJet::collection_type MicroJetCollection;
  typedef Ref<MicroJet> MicroJetRef;
  typedef RefVector<MicroJet> MicroJetRefVector;

  /* BEGIN CUSTOM MicroJet.h.global */
  /* END CUSTOM */

}

#endif
