#include "../Framework/interface/Object.h"
#include "../Framework/interface/Container.h"
#include "../Objects/interface/Particle.h"
#include "../Objects/interface/PackedParticle.h"
#include "../Objects/interface/GenParticle.h"
#include "../Objects/interface/PFCand.h"
#include "../Objects/interface/ParticleP.h"
#include "../Objects/interface/ParticleM.h"
#include "../Objects/interface/Parton.h"
#include "../Objects/interface/SuperCluster.h"
#include "../Objects/interface/Lepton.h"
#include "../Objects/interface/Electron.h"
#include "../Objects/interface/Muon.h"
#include "../Objects/interface/Tau.h"
#include "../Objects/interface/Photon.h"
#include "../Objects/interface/GenJet.h"
#include "../Objects/interface/MicroJet.h"
#include "../Objects/interface/Jet.h"
#include "../Objects/interface/FatJet.h"
#include "../Objects/interface/Met.h"
#include "../Objects/interface/RecoMet.h"
#include "../Objects/interface/MetFilters.h"
#include "../Objects/interface/HLTBits.h"
#include "../Objects/interface/GenReweight.h"
#include "../Objects/interface/Recoil.h"
#include "../Objects/interface/Event.h"
#include "../Objects/interface/Run.h"

#ifdef __CLING__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;
#pragma link C++ namespace panda;

#pragma link C++ enum panda::PhotonTriggerObject;
#pragma link C++ enum panda::ElectronTriggerObject;
#pragma link C++ enum panda::MuonTriggerObject;
#pragma link C++ class panda::Particle;
#pragma link C++ class panda::PackedParticle;
#pragma link C++ class panda::GenParticle;
#pragma link C++ class panda::PFCand;
#pragma link C++ class panda::ParticleP;
#pragma link C++ class panda::ParticleM;
#pragma link C++ class panda::Parton;
#pragma link C++ class panda::SuperCluster;
#pragma link C++ class panda::Lepton;
#pragma link C++ class panda::Electron;
#pragma link C++ class panda::Muon;
#pragma link C++ class panda::Tau;
#pragma link C++ class panda::Photon;
#pragma link C++ class panda::GenJet;
#pragma link C++ class panda::MicroJet;
#pragma link C++ class panda::Jet;
#pragma link C++ class panda::FatJet;
#pragma link C++ class panda::Met;
#pragma link C++ class panda::RecoMet;
#pragma link C++ class panda::MetFilters;
#pragma link C++ class panda::HLTBits;
#pragma link C++ class panda::GenReweight;
#pragma link C++ class panda::Recoil;
#pragma link C++ class Array<panda::Particle>;
#pragma link C++ class Collection<panda::Particle>;
#pragma link C++ class Array<panda::PackedParticle>;
#pragma link C++ class Collection<panda::PackedParticle>;
#pragma link C++ class Array<panda::GenParticle>;
#pragma link C++ class Collection<panda::GenParticle>;
#pragma link C++ class Array<panda::PFCand>;
#pragma link C++ class Collection<panda::PFCand>;
#pragma link C++ class Array<panda::ParticleP>;
#pragma link C++ class Collection<panda::ParticleP>;
#pragma link C++ class Array<panda::ParticleM>;
#pragma link C++ class Collection<panda::ParticleM>;
#pragma link C++ class Array<panda::Parton>;
#pragma link C++ class Collection<panda::Parton>;
#pragma link C++ class Array<panda::SuperCluster>;
#pragma link C++ class Collection<panda::SuperCluster>;
#pragma link C++ class Array<panda::Lepton>;
#pragma link C++ class Collection<panda::Lepton>;
#pragma link C++ class Array<panda::Electron>;
#pragma link C++ class Collection<panda::Electron>;
#pragma link C++ class Array<panda::Muon>;
#pragma link C++ class Collection<panda::Muon>;
#pragma link C++ class Array<panda::Tau>;
#pragma link C++ class Collection<panda::Tau>;
#pragma link C++ class Array<panda::Photon>;
#pragma link C++ class Collection<panda::Photon>;
#pragma link C++ class Array<panda::GenJet>;
#pragma link C++ class Collection<panda::GenJet>;
#pragma link C++ class Array<panda::MicroJet>;
#pragma link C++ class Collection<panda::MicroJet>;
#pragma link C++ class Array<panda::Jet>;
#pragma link C++ class Collection<panda::Jet>;
#pragma link C++ class Array<panda::FatJet>;
#pragma link C++ class Collection<panda::FatJet>;
#pragma link C++ typedef panda::ParticleArray;
#pragma link C++ typedef panda::ParticleCollection;
#pragma link C++ typedef panda::PackedParticleArray;
#pragma link C++ typedef panda::PackedParticleCollection;
#pragma link C++ typedef panda::GenParticleArray;
#pragma link C++ typedef panda::GenParticleCollection;
#pragma link C++ typedef panda::PFCandArray;
#pragma link C++ typedef panda::PFCandCollection;
#pragma link C++ typedef panda::ParticlePArray;
#pragma link C++ typedef panda::ParticlePCollection;
#pragma link C++ typedef panda::ParticleMArray;
#pragma link C++ typedef panda::ParticleMCollection;
#pragma link C++ typedef panda::PartonArray;
#pragma link C++ typedef panda::PartonCollection;
#pragma link C++ typedef panda::SuperClusterArray;
#pragma link C++ typedef panda::SuperClusterCollection;
#pragma link C++ typedef panda::LeptonArray;
#pragma link C++ typedef panda::LeptonCollection;
#pragma link C++ typedef panda::ElectronArray;
#pragma link C++ typedef panda::ElectronCollection;
#pragma link C++ typedef panda::MuonArray;
#pragma link C++ typedef panda::MuonCollection;
#pragma link C++ typedef panda::TauArray;
#pragma link C++ typedef panda::TauCollection;
#pragma link C++ typedef panda::PhotonArray;
#pragma link C++ typedef panda::PhotonCollection;
#pragma link C++ typedef panda::GenJetArray;
#pragma link C++ typedef panda::GenJetCollection;
#pragma link C++ typedef panda::MicroJetArray;
#pragma link C++ typedef panda::MicroJetCollection;
#pragma link C++ typedef panda::JetArray;
#pragma link C++ typedef panda::JetCollection;
#pragma link C++ typedef panda::FatJetArray;
#pragma link C++ typedef panda::FatJetCollection;
#pragma link C++ class panda::Event;
#pragma link C++ class panda::Run;

#endif
