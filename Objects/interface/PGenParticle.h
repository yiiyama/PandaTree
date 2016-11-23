#ifndef PandaTree_Objects_PGenParticle_h
#define PandaTree_Objects_PGenParticle_h
#include "Constants.h"
#include "PParticleM.h"
#include "../../Framework/interface/Container.h"
#include "PGenParticle.h"

namespace panda {

  class PGenParticle : public PParticleM {
  public:
    typedef Container<PGenParticle, PParticleMCollection> container_type;

    struct array_data : public PParticleM::array_data {
      static UInt_t const NMAX{256};

      array_data() : PParticleM::array_data() {}

      /* PParticle
      Float_t pt[NMAX]{};
      Float_t eta[NMAX]{};
      Float_t phi[NMAX]{};
      */
      /* PParticleM
      Float_t mass[NMAX]{};
      */
      Int_t pdgid[NMAX]{};
      UInt_t parent_[NMAX]{};

      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {"*"});
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"});
      void book(TTree&, TString const&, utils::BranchList const& = {"*"});
    };

    PGenParticle(char const* name = "");
    PGenParticle(PGenParticle const&);
    PGenParticle(array_data&, UInt_t idx);
    ~PGenParticle();
    PGenParticle& operator=(PGenParticle const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {"*"}) override;
    void setAddress(TTree&, utils::BranchList const& = {"*"}) override;
    void book(TTree&, utils::BranchList const& = {"*"}) override;

    void init() override;

    /* PParticle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    /* PParticleM
    Float_t& mass;
    */
    Int_t& pdgid;
    PGenParticle* parent() const
    { if (parentRef_ && parent_ < parentRef_->size()) return &(*parentRef_)[parent_]; else return 0; }
    void parent(PGenParticle& p)
    { if (!parentRef_) return; for (parent_ = 0; parent_ != parentRef_->size(); ++parent_) if (&(*parentRef_)[parent_] == &p) return; parent_ = PGenParticle::array_data::NMAX; }
    void parentRef(PGenParticle::container_type& cont) { parentRef_ = &cont; }
  private:
    UInt_t& parent_;
    PGenParticle::container_type* parentRef_{0};
  public:

    /* BEGIN CUSTOM */
    /* END CUSTOM */

  protected:
    PGenParticle(utils::AllocatorBase const&, char const* name);
  };

  typedef PGenParticle::container_type PGenParticleCollection;

  /* BEGIN CUSTOM */
  /* END CUSTOM */

}

#endif
