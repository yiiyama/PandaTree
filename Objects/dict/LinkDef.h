#include "PandaTree/Framework/interface/Object.h"
#include "PandaTree/Framework/interface/Array.h"
#include "PandaTree/Framework/interface/Collection.h"
#include "PandaTree/Objects/interface/Particle.h"
#include "PandaTree/Objects/interface/Vertex.h"
#include "PandaTree/Objects/interface/RecoVertex.h"
#include "PandaTree/Objects/interface/PackedTrack.h"
#include "PandaTree/Objects/interface/SuperCluster.h"
#include "PandaTree/Objects/interface/PackedParticle.h"
#include "PandaTree/Objects/interface/GenParticle.h"
#include "PandaTree/Objects/interface/PFCand.h"
#include "PandaTree/Objects/interface/ParticleP.h"
#include "PandaTree/Objects/interface/ParticleM.h"
#include "PandaTree/Objects/interface/UnpackedPFCand.h"
#include "PandaTree/Objects/interface/Parton.h"
#include "PandaTree/Objects/interface/UnpackedGenParticle.h"
#include "PandaTree/Objects/interface/Lepton.h"
#include "PandaTree/Objects/interface/Electron.h"
#include "PandaTree/Objects/interface/Muon.h"
#include "PandaTree/Objects/interface/Tau.h"
#include "PandaTree/Objects/interface/Photon.h"
#include "PandaTree/Objects/interface/GenJet.h"
#include "PandaTree/Objects/interface/MicroJet.h"
#include "PandaTree/Objects/interface/Jet.h"
#include "PandaTree/Objects/interface/FatJet.h"
#include "PandaTree/Objects/interface/Met.h"
#include "PandaTree/Objects/interface/RecoMet.h"
#include "PandaTree/Objects/interface/MetFilters.h"
#include "PandaTree/Objects/interface/HLTBits.h"
#include "PandaTree/Objects/interface/GenReweight.h"
#include "PandaTree/Objects/interface/Recoil.h"
#include "PandaTree/Objects/interface/XPhoton.h"
#include "PandaTree/Objects/interface/TPPair.h"
#include "PandaTree/Objects/interface/EventBase.h"
#include "PandaTree/Objects/interface/Event.h"
#include "PandaTree/Objects/interface/Run.h"
#include "PandaTree/Objects/interface/EventMonophoton.h"
#include "PandaTree/Objects/interface/EventTPPhoton.h"

#ifdef __CLING__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;
#pragma link C++ namespace panda;

#pragma link C++ class panda::Object;
#pragma link C++ class panda::Singlet;
#pragma link C++ class panda::Element;
#pragma link C++ class panda::ContainerBase;
#pragma link C++ class panda::ArrayBase;
#pragma link C++ class panda::CollectionBase;
#pragma link C++ class panda::TreeEntry;
#pragma link C++ class panda::Particle;
#pragma link C++ class panda::Vertex;
#pragma link C++ class panda::RecoVertex;
#pragma link C++ class panda::PackedTrack;
#pragma link C++ class panda::SuperCluster;
#pragma link C++ class panda::PackedParticle;
#pragma link C++ class panda::GenParticle;
#pragma link C++ class panda::PFCand;
#pragma link C++ class panda::ParticleP;
#pragma link C++ class panda::ParticleM;
#pragma link C++ class panda::UnpackedPFCand;
#pragma link C++ class panda::Parton;
#pragma link C++ class panda::UnpackedGenParticle;
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
#pragma link C++ class panda::XPhoton;
#pragma link C++ class panda::TPPair;
#pragma link C++ class panda::Array<panda::Particle>;
#pragma link C++ class panda::Collection<panda::Particle>;
#pragma link C++ class panda::Array<panda::Vertex>;
#pragma link C++ class panda::Collection<panda::Vertex>;
#pragma link C++ class panda::Array<panda::RecoVertex>;
#pragma link C++ class panda::Collection<panda::RecoVertex>;
#pragma link C++ class panda::Array<panda::PackedTrack>;
#pragma link C++ class panda::Collection<panda::PackedTrack>;
#pragma link C++ class panda::Array<panda::SuperCluster>;
#pragma link C++ class panda::Collection<panda::SuperCluster>;
#pragma link C++ class panda::Array<panda::PackedParticle>;
#pragma link C++ class panda::Collection<panda::PackedParticle>;
#pragma link C++ class panda::Array<panda::GenParticle>;
#pragma link C++ class panda::Collection<panda::GenParticle>;
#pragma link C++ class panda::Array<panda::PFCand>;
#pragma link C++ class panda::Collection<panda::PFCand>;
#pragma link C++ class panda::Array<panda::ParticleP>;
#pragma link C++ class panda::Collection<panda::ParticleP>;
#pragma link C++ class panda::Array<panda::ParticleM>;
#pragma link C++ class panda::Collection<panda::ParticleM>;
#pragma link C++ class panda::Array<panda::UnpackedPFCand>;
#pragma link C++ class panda::Collection<panda::UnpackedPFCand>;
#pragma link C++ class panda::Array<panda::Parton>;
#pragma link C++ class panda::Collection<panda::Parton>;
#pragma link C++ class panda::Array<panda::UnpackedGenParticle>;
#pragma link C++ class panda::Collection<panda::UnpackedGenParticle>;
#pragma link C++ class panda::Array<panda::Lepton>;
#pragma link C++ class panda::Collection<panda::Lepton>;
#pragma link C++ class panda::Array<panda::Electron>;
#pragma link C++ class panda::Collection<panda::Electron>;
#pragma link C++ class panda::Array<panda::Muon>;
#pragma link C++ class panda::Collection<panda::Muon>;
#pragma link C++ class panda::Array<panda::Tau>;
#pragma link C++ class panda::Collection<panda::Tau>;
#pragma link C++ class panda::Array<panda::Photon>;
#pragma link C++ class panda::Collection<panda::Photon>;
#pragma link C++ class panda::Array<panda::GenJet>;
#pragma link C++ class panda::Collection<panda::GenJet>;
#pragma link C++ class panda::Array<panda::MicroJet>;
#pragma link C++ class panda::Collection<panda::MicroJet>;
#pragma link C++ class panda::Array<panda::Jet>;
#pragma link C++ class panda::Collection<panda::Jet>;
#pragma link C++ class panda::Array<panda::FatJet>;
#pragma link C++ class panda::Collection<panda::FatJet>;
#pragma link C++ class panda::Array<panda::XPhoton>;
#pragma link C++ class panda::Collection<panda::XPhoton>;
#pragma link C++ class panda::Array<panda::TPPair>;
#pragma link C++ class panda::Collection<panda::TPPair>;
#pragma link C++ typedef panda::ParticleArray;
#pragma link C++ typedef panda::ParticleCollection;
#pragma link C++ typedef panda::VertexArray;
#pragma link C++ typedef panda::VertexCollection;
#pragma link C++ typedef panda::RecoVertexArray;
#pragma link C++ typedef panda::RecoVertexCollection;
#pragma link C++ typedef panda::PackedTrackArray;
#pragma link C++ typedef panda::PackedTrackCollection;
#pragma link C++ typedef panda::SuperClusterArray;
#pragma link C++ typedef panda::SuperClusterCollection;
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
#pragma link C++ typedef panda::UnpackedPFCandArray;
#pragma link C++ typedef panda::UnpackedPFCandCollection;
#pragma link C++ typedef panda::PartonArray;
#pragma link C++ typedef panda::PartonCollection;
#pragma link C++ typedef panda::UnpackedGenParticleArray;
#pragma link C++ typedef panda::UnpackedGenParticleCollection;
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
#pragma link C++ typedef panda::XPhotonArray;
#pragma link C++ typedef panda::XPhotonCollection;
#pragma link C++ typedef panda::TPPairArray;
#pragma link C++ typedef panda::TPPairCollection;
#pragma link C++ class panda::EventBase;
#pragma link C++ class panda::Event;
#pragma link C++ class panda::Run;
#pragma link C++ class panda::EventMonophoton;
#pragma link C++ class panda::EventTPPhoton;

#endif
