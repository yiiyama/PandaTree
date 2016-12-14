#ifndef PandaTree_Objects_ParticleM_h
#define PandaTree_Objects_ParticleM_h
#include "Constants.h"
#include "Particle.h"
#include "../../Framework/interface/Container.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class ParticleM : public Particle {
  public:
    struct datastore : public Particle::datastore {
      datastore() : Particle::datastore() {}
      ~datastore() { deallocate(); }

      /* Particle
      Float_t* pt{0};
      Float_t* eta{0};
      Float_t* phi{0};
      */
      Float_t* mass{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, Bool_t, utils::BranchList const& = {}) override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {}, Bool_t dynamic = kTRUE) override;
      void resetAddress(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Particle base_type;
    typedef Array<ParticleM> array_type;
    typedef Collection<ParticleM> collection_type;

    ParticleM(char const* name = "");
    ParticleM(ParticleM const&);
    ParticleM(datastore&, UInt_t idx);
    ~ParticleM();
    ParticleM& operator=(ParticleM const&);

    void setStatus(TTree&, Bool_t, utils::BranchList const& = {}) override;
    void setAddress(TTree&, utils::BranchList const& = {}, Bool_t setStatus = kTRUE) override;
    void book(TTree&, utils::BranchList const& = {}) override;
    void resetAddress(TTree&) override;

    void init() override;

    double m() const override { return mass; }
    void setXYZE(double px, double py, double pz, double e) override;

    /* Particle
    Float_t& pt;
    Float_t& eta;
    Float_t& phi;
    */
    Float_t& mass;

    /* BEGIN CUSTOM ParticleM.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    ParticleM(ArrayBase*);
  };

  typedef ParticleM::array_type ParticleMArray;
  typedef ParticleM::collection_type ParticleMCollection;
  typedef Ref<ParticleM> ParticleMRef;
  typedef RefVector<ParticleM> ParticleMRefVector;

  /* BEGIN CUSTOM ParticleM.h.global */
  /* END CUSTOM */

}

#endif
