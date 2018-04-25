#ifndef IWILLSEEYOULATER
#define IWILLSEEYOULATER 1

#include <vector>
#include <functional>
#include <algorithm>
#include <cassert>
#include "PandaTree/Objects/interface/Event.h"

namespace testpanda {

  template <int P>
  struct plotter {
    constexpr static const char* name = nullptr;
  };

  template <>
  struct plotter <0> {
    constexpr static const char* name = "common/eventNumber";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.eventNumber)};
      return output;
    }
  };

  template <>
  struct plotter <1> {
    constexpr static const char* name = "common/runNumber";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.runNumber)};
      return output;
    }
  };

  template <>
  struct plotter <2> {
    constexpr static const char* name = "common/weight";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.weight)};
      return output;
    }
  };

  template <>
  struct plotter <3> {
    constexpr static const char* name = "common/isData";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.isData)};
      return output;
    }
  };

  template <>
  struct plotter <4> {
    constexpr static const char* name = "common/lumiNumber";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.lumiNumber)};
      return output;
    }
  };

  template <>
  struct plotter <5> {
    constexpr static const char* name = "common/rhoCentralCalo";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.rhoCentralCalo)};
      return output;
    }
  };

  template <>
  struct plotter <6> {
    constexpr static const char* name = "common/npv";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.npv)};
      return output;
    }
  };

  template <>
  struct plotter <7> {
    constexpr static const char* name = "common/rho";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.rho)};
      return output;
    }
  };

  template <>
  struct plotter <8> {
    constexpr static const char* name = "common/npvTrue";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.npvTrue)};
      return output;
    }
  };

  template <>
  struct plotter <9> {
    constexpr static const char* name = "genReweight/r5f1DW";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.genReweight.r5f1DW)};
      return output;
    }
  };

  template <>
  struct plotter <10> {
    constexpr static const char* name = "genReweight/r2f2DW";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.genReweight.r2f2DW)};
      return output;
    }
  };

  template <>
  struct plotter <11> {
    constexpr static const char* name = "genReweight/r2f1DW";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.genReweight.r2f1DW)};
      return output;
    }
  };

  template <>
  struct plotter <12> {
    constexpr static const char* name = "genReweight/r1f5DW";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.genReweight.r1f5DW)};
      return output;
    }
  };

  template <>
  struct plotter <13> {
    constexpr static const char* name = "genReweight/r5f5DW";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.genReweight.r5f5DW)};
      return output;
    }
  };

  template <>
  struct plotter <14> {
    constexpr static const char* name = "genReweight/r1f2DW";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.genReweight.r1f2DW)};
      return output;
    }
  };

  template <>
  struct plotter <15> {
    constexpr static const char* name = "pfCandidates/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.pfCandidates.size())};
      return output;
    }
  };

  template <>
  struct plotter <16> {
    constexpr static const char* name = "pfCandidates/vertex_isValid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.pfCandidates)
        output.push_back(i.vertex.isValid());
      return output;
    }
  };

  template <>
  struct plotter <17> {
    constexpr static const char* name = "pfCandidates/track_isValid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.pfCandidates)
        output.push_back(i.track.isValid());
      return output;
    }
  };

  template <>
  struct plotter <18> {
    constexpr static const char* name = "pfCandidates/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.pfCandidates)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <19> {
    constexpr static const char* name = "pfCandidates/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.pfCandidates)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <20> {
    constexpr static const char* name = "pfCandidates/puppiWNoLep";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.pfCandidates)
        output.push_back(i.puppiWNoLep());
      return output;
    }
  };

  template <>
  struct plotter <21> {
    constexpr static const char* name = "pfCandidates/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.pfCandidates)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <22> {
    constexpr static const char* name = "pfCandidates/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.pfCandidates)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <23> {
    constexpr static const char* name = "pfCandidates/pdgId";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.pfCandidates)
        output.push_back(i.pdgId());
      return output;
    }
  };

  template <>
  struct plotter <24> {
    constexpr static const char* name = "pfCandidates/hCalFrac";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.pfCandidates)
        output.push_back(i.hCalFrac);
      return output;
    }
  };

  template <>
  struct plotter <25> {
    constexpr static const char* name = "pfCandidates/ptype";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.pfCandidates)
        output.push_back(i.ptype);
      return output;
    }
  };

  template <>
  struct plotter <26> {
    constexpr static const char* name = "pfCandidates/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.pfCandidates)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <27> {
    constexpr static const char* name = "pfCandidates/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.pfCandidates)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <28> {
    constexpr static const char* name = "pfCandidates/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.pfCandidates)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <29> {
    constexpr static const char* name = "pfCandidates/q";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.pfCandidates)
        output.push_back(i.q());
      return output;
    }
  };

  template <>
  struct plotter <30> {
    constexpr static const char* name = "pfCandidates/puppiW";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.pfCandidates)
        output.push_back(i.puppiW());
      return output;
    }
  };

  template <>
  struct plotter <31> {
    constexpr static const char* name = "pfCandidates/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.pfCandidates)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <32> {
    constexpr static const char* name = "pfCandidates/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.pfCandidates)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <33> {
    constexpr static const char* name = "vertices/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.vertices.size())};
      return output;
    }
  };

  template <>
  struct plotter <34> {
    constexpr static const char* name = "vertices/chi2";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.vertices)
        output.push_back(i.chi2);
      return output;
    }
  };

  template <>
  struct plotter <35> {
    constexpr static const char* name = "vertices/ntrk";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.vertices)
        output.push_back(i.ntrk);
      return output;
    }
  };

  template <>
  struct plotter <36> {
    constexpr static const char* name = "vertices/ndof";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.vertices)
        output.push_back(i.ndof);
      return output;
    }
  };

  template <>
  struct plotter <37> {
    constexpr static const char* name = "vertices/score";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.vertices)
        output.push_back(i.score);
      return output;
    }
  };

  template <>
  struct plotter <38> {
    constexpr static const char* name = "vertices/normChi2";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.vertices)
        output.push_back(i.normChi2());
      return output;
    }
  };

  template <>
  struct plotter <39> {
    constexpr static const char* name = "vertices/pfRangeMax";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.vertices)
        output.push_back(i.pfRangeMax);
      return output;
    }
  };

  template <>
  struct plotter <40> {
    constexpr static const char* name = "vertices/y";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.vertices)
        output.push_back(i.y);
      return output;
    }
  };

  template <>
  struct plotter <41> {
    constexpr static const char* name = "vertices/x";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.vertices)
        output.push_back(i.x);
      return output;
    }
  };

  template <>
  struct plotter <42> {
    constexpr static const char* name = "vertices/z";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.vertices)
        output.push_back(i.z);
      return output;
    }
  };

  template <>
  struct plotter <43> {
    constexpr static const char* name = "secondaryVertices/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.secondaryVertices.size())};
      return output;
    }
  };

  template <>
  struct plotter <44> {
    constexpr static const char* name = "secondaryVertices/daughters_size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.daughters.size());
      return output;
    }
  };

  template <>
  struct plotter <45> {
    constexpr static const char* name = "secondaryVertices/vtx3DVal";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.vtx3DVal);
      return output;
    }
  };

  template <>
  struct plotter <46> {
    constexpr static const char* name = "secondaryVertices/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <47> {
    constexpr static const char* name = "secondaryVertices/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <48> {
    constexpr static const char* name = "secondaryVertices/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <49> {
    constexpr static const char* name = "secondaryVertices/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <50> {
    constexpr static const char* name = "secondaryVertices/chi2";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.chi2);
      return output;
    }
  };

  template <>
  struct plotter <51> {
    constexpr static const char* name = "secondaryVertices/significance";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.significance);
      return output;
    }
  };

  template <>
  struct plotter <52> {
    constexpr static const char* name = "secondaryVertices/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <53> {
    constexpr static const char* name = "secondaryVertices/ndof";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.ndof);
      return output;
    }
  };

  template <>
  struct plotter <54> {
    constexpr static const char* name = "secondaryVertices/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <55> {
    constexpr static const char* name = "secondaryVertices/vtx3DeVal";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.vtx3DeVal);
      return output;
    }
  };

  template <>
  struct plotter <56> {
    constexpr static const char* name = "secondaryVertices/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <57> {
    constexpr static const char* name = "secondaryVertices/normChi2";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.normChi2());
      return output;
    }
  };

  template <>
  struct plotter <58> {
    constexpr static const char* name = "secondaryVertices/ntrk";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.ntrk);
      return output;
    }
  };

  template <>
  struct plotter <59> {
    constexpr static const char* name = "secondaryVertices/y";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.y);
      return output;
    }
  };

  template <>
  struct plotter <60> {
    constexpr static const char* name = "secondaryVertices/x";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.x);
      return output;
    }
  };

  template <>
  struct plotter <61> {
    constexpr static const char* name = "secondaryVertices/z";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.z);
      return output;
    }
  };

  template <>
  struct plotter <62> {
    constexpr static const char* name = "secondaryVertices/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <63> {
    constexpr static const char* name = "secondaryVertices/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.secondaryVertices)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <64> {
    constexpr static const char* name = "tracks/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.tracks.size())};
      return output;
    }
  };

  template <>
  struct plotter <65> {
    constexpr static const char* name = "tracks/dxy";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.tracks)
        output.push_back(i.dxy());
      return output;
    }
  };

  template <>
  struct plotter <66> {
    constexpr static const char* name = "tracks/dPhi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.tracks)
        output.push_back(i.dPhi());
      return output;
    }
  };

  template <>
  struct plotter <67> {
    constexpr static const char* name = "tracks/dz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.tracks)
        output.push_back(i.dz());
      return output;
    }
  };

  template <>
  struct plotter <68> {
    constexpr static const char* name = "tracks/highPurity";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.tracks)
        output.push_back(i.highPurity);
      return output;
    }
  };

  template <>
  struct plotter <69> {
    constexpr static const char* name = "tracks/ptError";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.tracks)
        output.push_back(i.ptError());
      return output;
    }
  };

  template <>
  struct plotter <70> {
    constexpr static const char* name = "superClusters/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.superClusters.size())};
      return output;
    }
  };

  template <>
  struct plotter <71> {
    constexpr static const char* name = "superClusters/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.superClusters)
        output.push_back(i.phi);
      return output;
    }
  };

  template <>
  struct plotter <72> {
    constexpr static const char* name = "superClusters/rawPt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.superClusters)
        output.push_back(i.rawPt);
      return output;
    }
  };

  template <>
  struct plotter <73> {
    constexpr static const char* name = "superClusters/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.superClusters)
        output.push_back(i.eta);
      return output;
    }
  };

  template <>
  struct plotter <74> {
    constexpr static const char* name = "electrons/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.electrons.size())};
      return output;
    }
  };

  template <>
  struct plotter <75> {
    constexpr static const char* name = "electrons/superCluster_isValid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.superCluster.isValid());
      return output;
    }
  };

  template <>
  struct plotter <76> {
    constexpr static const char* name = "electrons/mvaWPLoose";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.mvaWPLoose);
      return output;
    }
  };

  template <>
  struct plotter <77> {
    constexpr static const char* name = "electrons/dxy";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.dxy);
      return output;
    }
  };

  template <>
  struct plotter <78> {
    constexpr static const char* name = "electrons/chIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.chIso);
      return output;
    }
  };

  template <>
  struct plotter <79> {
    constexpr static const char* name = "electrons/phIsoPh";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.phIsoPh);
      return output;
    }
  };

  template <>
  struct plotter <80> {
    constexpr static const char* name = "electrons/mvaVal";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.mvaVal);
      return output;
    }
  };

  template <>
  struct plotter <81> {
    constexpr static const char* name = "electrons/mvaIsoWP80";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.mvaIsoWP80);
      return output;
    }
  };

  template <>
  struct plotter <82> {
    constexpr static const char* name = "electrons/trackIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.trackIso);
      return output;
    }
  };

  template <>
  struct plotter <83> {
    constexpr static const char* name = "electrons/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <84> {
    constexpr static const char* name = "electrons/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <85> {
    constexpr static const char* name = "electrons/ecalIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.ecalIso);
      return output;
    }
  };

  template <>
  struct plotter <86> {
    constexpr static const char* name = "electrons/medium";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.medium);
      return output;
    }
  };

  template <>
  struct plotter <87> {
    constexpr static const char* name = "electrons/isoPUOffset";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.isoPUOffset);
      return output;
    }
  };

  template <>
  struct plotter <88> {
    constexpr static const char* name = "electrons/pfPt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.pfPt);
      return output;
    }
  };

  template <>
  struct plotter <89> {
    constexpr static const char* name = "electrons/trackP";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.trackP);
      return output;
    }
  };

  template <>
  struct plotter <90> {
    constexpr static const char* name = "electrons/ecalE";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.ecalE);
      return output;
    }
  };

  template <>
  struct plotter <91> {
    constexpr static const char* name = "electrons/sipip";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.sipip);
      return output;
    }
  };

  template <>
  struct plotter <92> {
    constexpr static const char* name = "electrons/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <93> {
    constexpr static const char* name = "electrons/hltsafe";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.hltsafe);
      return output;
    }
  };

  template <>
  struct plotter <94> {
    constexpr static const char* name = "electrons/tripleCharge";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.tripleCharge);
      return output;
    }
  };

  template <>
  struct plotter <95> {
    constexpr static const char* name = "electrons/charge";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.charge);
      return output;
    }
  };

  template <>
  struct plotter <96> {
    constexpr static const char* name = "electrons/mvaWP80";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.mvaWP80);
      return output;
    }
  };

  template <>
  struct plotter <97> {
    constexpr static const char* name = "electrons/dEtaInSeed";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.dEtaInSeed);
      return output;
    }
  };

  template <>
  struct plotter <98> {
    constexpr static const char* name = "electrons/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <99> {
    constexpr static const char* name = "electrons/tight";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.tight);
      return output;
    }
  };

  template <>
  struct plotter <100> {
    constexpr static const char* name = "electrons/sieie";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.sieie);
      return output;
    }
  };

  template <>
  struct plotter <101> {
    constexpr static const char* name = "electrons/eseed";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.eseed);
      return output;
    }
  };

  template <>
  struct plotter <102> {
    constexpr static const char* name = "electrons/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <103> {
    constexpr static const char* name = "electrons/veto";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.veto);
      return output;
    }
  };

  template <>
  struct plotter <104> {
    constexpr static const char* name = "electrons/mvaIsoWP90";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.mvaIsoWP90);
      return output;
    }
  };

  template <>
  struct plotter <105> {
    constexpr static const char* name = "electrons/conversionVeto";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.conversionVeto);
      return output;
    }
  };

  template <>
  struct plotter <106> {
    constexpr static const char* name = "electrons/loose";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.loose);
      return output;
    }
  };

  template <>
  struct plotter <107> {
    constexpr static const char* name = "electrons/regPt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.regPt);
      return output;
    }
  };

  template <>
  struct plotter <108> {
    constexpr static const char* name = "electrons/nhIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.nhIso);
      return output;
    }
  };

  template <>
  struct plotter <109> {
    constexpr static const char* name = "electrons/dPhiIn";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.dPhiIn);
      return output;
    }
  };

  template <>
  struct plotter <110> {
    constexpr static const char* name = "electrons/dz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.dz);
      return output;
    }
  };

  template <>
  struct plotter <111> {
    constexpr static const char* name = "electrons/chIsoPh";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.chIsoPh);
      return output;
    }
  };

  template <>
  struct plotter <112> {
    constexpr static const char* name = "electrons/phIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.phIso);
      return output;
    }
  };

  template <>
  struct plotter <113> {
    constexpr static const char* name = "electrons/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <114> {
    constexpr static const char* name = "electrons/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <115> {
    constexpr static const char* name = "electrons/nhIsoPh";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.nhIsoPh);
      return output;
    }
  };

  template <>
  struct plotter <116> {
    constexpr static const char* name = "electrons/hcalIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.hcalIso);
      return output;
    }
  };

  template <>
  struct plotter <117> {
    constexpr static const char* name = "electrons/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <118> {
    constexpr static const char* name = "electrons/puIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.puIso);
      return output;
    }
  };

  template <>
  struct plotter <119> {
    constexpr static const char* name = "electrons/combIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.combIso());
      return output;
    }
  };

  template <>
  struct plotter <120> {
    constexpr static const char* name = "electrons/mvaIsoWPLoose";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.mvaIsoWPLoose);
      return output;
    }
  };

  template <>
  struct plotter <121> {
    constexpr static const char* name = "electrons/r9";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.r9);
      return output;
    }
  };

  template <>
  struct plotter <122> {
    constexpr static const char* name = "electrons/nMissingHits";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.nMissingHits);
      return output;
    }
  };

  template <>
  struct plotter <123> {
    constexpr static const char* name = "electrons/hOverE";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.hOverE);
      return output;
    }
  };

  template <>
  struct plotter <124> {
    constexpr static const char* name = "electrons/smearedPt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.smearedPt);
      return output;
    }
  };

  template <>
  struct plotter <125> {
    constexpr static const char* name = "electrons/mvaWP90";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.mvaWP90);
      return output;
    }
  };

  template <>
  struct plotter <126> {
    constexpr static const char* name = "electrons/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.electrons)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <127> {
    constexpr static const char* name = "muons/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.muons.size())};
      return output;
    }
  };

  template <>
  struct plotter <128> {
    constexpr static const char* name = "muons/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <129> {
    constexpr static const char* name = "muons/miniIsoMedium";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.miniIsoMedium);
      return output;
    }
  };

  template <>
  struct plotter <130> {
    constexpr static const char* name = "muons/mvaMedium";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.mvaMedium);
      return output;
    }
  };

  template <>
  struct plotter <131> {
    constexpr static const char* name = "muons/global";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.global);
      return output;
    }
  };

  template <>
  struct plotter <132> {
    constexpr static const char* name = "muons/miniIsoLoose";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.miniIsoLoose);
      return output;
    }
  };

  template <>
  struct plotter <133> {
    constexpr static const char* name = "muons/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <134> {
    constexpr static const char* name = "muons/rpc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.rpc);
      return output;
    }
  };

  template <>
  struct plotter <135> {
    constexpr static const char* name = "muons/medium";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.medium);
      return output;
    }
  };

  template <>
  struct plotter <136> {
    constexpr static const char* name = "muons/pfIsoTight";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.pfIsoTight);
      return output;
    }
  };

  template <>
  struct plotter <137> {
    constexpr static const char* name = "muons/normChi2";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.normChi2);
      return output;
    }
  };

  template <>
  struct plotter <138> {
    constexpr static const char* name = "muons/globalHighPt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.globalHighPt);
      return output;
    }
  };

  template <>
  struct plotter <139> {
    constexpr static const char* name = "muons/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <140> {
    constexpr static const char* name = "muons/miniIsoTight";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.miniIsoTight);
      return output;
    }
  };

  template <>
  struct plotter <141> {
    constexpr static const char* name = "muons/validFraction";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.validFraction);
      return output;
    }
  };

  template <>
  struct plotter <142> {
    constexpr static const char* name = "muons/dxy";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.dxy);
      return output;
    }
  };

  template <>
  struct plotter <143> {
    constexpr static const char* name = "muons/pfPt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.pfPt);
      return output;
    }
  };

  template <>
  struct plotter <144> {
    constexpr static const char* name = "muons/chIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.chIso);
      return output;
    }
  };

  template <>
  struct plotter <145> {
    constexpr static const char* name = "muons/trkLayersWithMmt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.trkLayersWithMmt);
      return output;
    }
  };

  template <>
  struct plotter <146> {
    constexpr static const char* name = "muons/hltsafe";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.hltsafe);
      return output;
    }
  };

  template <>
  struct plotter <147> {
    constexpr static const char* name = "muons/tight";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.tight);
      return output;
    }
  };

  template <>
  struct plotter <148> {
    constexpr static const char* name = "muons/charge";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.charge);
      return output;
    }
  };

  template <>
  struct plotter <149> {
    constexpr static const char* name = "muons/tracker";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.tracker);
      return output;
    }
  };

  template <>
  struct plotter <150> {
    constexpr static const char* name = "muons/pf";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.pf);
      return output;
    }
  };

  template <>
  struct plotter <151> {
    constexpr static const char* name = "muons/calo";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.calo);
      return output;
    }
  };

  template <>
  struct plotter <152> {
    constexpr static const char* name = "muons/segmentCompatibility";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.segmentCompatibility);
      return output;
    }
  };

  template <>
  struct plotter <153> {
    constexpr static const char* name = "muons/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <154> {
    constexpr static const char* name = "muons/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <155> {
    constexpr static const char* name = "muons/mediumPrompt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.mediumPrompt);
      return output;
    }
  };

  template <>
  struct plotter <156> {
    constexpr static const char* name = "muons/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <157> {
    constexpr static const char* name = "muons/pfIsoVeryTight";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.pfIsoVeryTight);
      return output;
    }
  };

  template <>
  struct plotter <158> {
    constexpr static const char* name = "muons/nMatched";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.nMatched);
      return output;
    }
  };

  template <>
  struct plotter <159> {
    constexpr static const char* name = "muons/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.pt());
      assert(std::is_sorted(output.begin(), output.end(), std::greater<float>()));
      return output;
    }
  };

  template <>
  struct plotter <160> {
    constexpr static const char* name = "muons/loose";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.loose);
      return output;
    }
  };

  template <>
  struct plotter <161> {
    constexpr static const char* name = "muons/miniIsoVeryTight";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.miniIsoVeryTight);
      return output;
    }
  };

  template <>
  struct plotter <162> {
    constexpr static const char* name = "muons/nValidPixel";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.nValidPixel);
      return output;
    }
  };

  template <>
  struct plotter <163> {
    constexpr static const char* name = "muons/trkHighPt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.trkHighPt);
      return output;
    }
  };

  template <>
  struct plotter <164> {
    constexpr static const char* name = "muons/nValidMuon";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.nValidMuon);
      return output;
    }
  };

  template <>
  struct plotter <165> {
    constexpr static const char* name = "muons/dz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.dz);
      return output;
    }
  };

  template <>
  struct plotter <166> {
    constexpr static const char* name = "muons/chi2LocalPosition";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.chi2LocalPosition);
      return output;
    }
  };

  template <>
  struct plotter <167> {
    constexpr static const char* name = "muons/pixLayersWithMmt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.pixLayersWithMmt);
      return output;
    }
  };

  template <>
  struct plotter <168> {
    constexpr static const char* name = "muons/phIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.phIso);
      return output;
    }
  };

  template <>
  struct plotter <169> {
    constexpr static const char* name = "muons/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <170> {
    constexpr static const char* name = "muons/gem";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.gem);
      return output;
    }
  };

  template <>
  struct plotter <171> {
    constexpr static const char* name = "muons/pfIsoLoose";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.pfIsoLoose);
      return output;
    }
  };

  template <>
  struct plotter <172> {
    constexpr static const char* name = "muons/nhIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.nhIso);
      return output;
    }
  };

  template <>
  struct plotter <173> {
    constexpr static const char* name = "muons/pfIsoMedium";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.pfIsoMedium);
      return output;
    }
  };

  template <>
  struct plotter <174> {
    constexpr static const char* name = "muons/mvaLoose";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.mvaLoose);
      return output;
    }
  };

  template <>
  struct plotter <175> {
    constexpr static const char* name = "muons/puIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.puIso);
      return output;
    }
  };

  template <>
  struct plotter <176> {
    constexpr static const char* name = "muons/rochCorr";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.rochCorr);
      return output;
    }
  };

  template <>
  struct plotter <177> {
    constexpr static const char* name = "muons/standalone";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.standalone);
      return output;
    }
  };

  template <>
  struct plotter <178> {
    constexpr static const char* name = "muons/softMVA";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.softMVA);
      return output;
    }
  };

  template <>
  struct plotter <179> {
    constexpr static const char* name = "muons/r03Iso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.r03Iso);
      return output;
    }
  };

  template <>
  struct plotter <180> {
    constexpr static const char* name = "muons/rochCorrErr";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.rochCorrErr);
      return output;
    }
  };

  template <>
  struct plotter <181> {
    constexpr static const char* name = "muons/tkIsoLoose";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.tkIsoLoose);
      return output;
    }
  };

  template <>
  struct plotter <182> {
    constexpr static const char* name = "muons/tkIsoTight";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.tkIsoTight);
      return output;
    }
  };

  template <>
  struct plotter <183> {
    constexpr static const char* name = "muons/pfIsoVeryLoose";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.pfIsoVeryLoose);
      return output;
    }
  };

  template <>
  struct plotter <184> {
    constexpr static const char* name = "muons/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <185> {
    constexpr static const char* name = "muons/trkKink";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.trkKink);
      return output;
    }
  };

  template <>
  struct plotter <186> {
    constexpr static const char* name = "muons/soft";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.soft);
      return output;
    }
  };

  template <>
  struct plotter <187> {
    constexpr static const char* name = "muons/combIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.combIso());
      return output;
    }
  };

  template <>
  struct plotter <188> {
    constexpr static const char* name = "muons/mvaTight";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.mvaTight);
      return output;
    }
  };

  template <>
  struct plotter <189> {
    constexpr static const char* name = "muons/me0";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.muons)
        output.push_back(i.me0);
      return output;
    }
  };

  template <>
  struct plotter <190> {
    constexpr static const char* name = "taus/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.taus.size())};
      return output;
    }
  };

  template <>
  struct plotter <191> {
    constexpr static const char* name = "taus/vertex_isValid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.vertex.isValid());
      return output;
    }
  };

  template <>
  struct plotter <192> {
    constexpr static const char* name = "taus/matchedGen_isValid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.matchedGen.isValid());
      return output;
    }
  };

  template <>
  struct plotter <193> {
    constexpr static const char* name = "taus/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <194> {
    constexpr static const char* name = "taus/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <195> {
    constexpr static const char* name = "taus/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <196> {
    constexpr static const char* name = "taus/decayMode";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.decayMode);
      return output;
    }
  };

  template <>
  struct plotter <197> {
    constexpr static const char* name = "taus/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <198> {
    constexpr static const char* name = "taus/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <199> {
    constexpr static const char* name = "taus/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <200> {
    constexpr static const char* name = "taus/isoDeltaBetaCorr";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.isoDeltaBetaCorr);
      return output;
    }
  };

  template <>
  struct plotter <201> {
    constexpr static const char* name = "taus/charge";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.charge);
      return output;
    }
  };

  template <>
  struct plotter <202> {
    constexpr static const char* name = "taus/iso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.iso);
      return output;
    }
  };

  template <>
  struct plotter <203> {
    constexpr static const char* name = "taus/looseIsoMVA";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.looseIsoMVA);
      return output;
    }
  };

  template <>
  struct plotter <204> {
    constexpr static const char* name = "taus/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <205> {
    constexpr static const char* name = "taus/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <206> {
    constexpr static const char* name = "taus/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <207> {
    constexpr static const char* name = "taus/looseIsoMVAOld";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.looseIsoMVAOld);
      return output;
    }
  };

  template <>
  struct plotter <208> {
    constexpr static const char* name = "taus/decayModeNew";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.taus)
        output.push_back(i.decayModeNew);
      return output;
    }
  };

  template <>
  struct plotter <209> {
    constexpr static const char* name = "photons/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.photons.size())};
      return output;
    }
  };

  template <>
  struct plotter <210> {
    constexpr static const char* name = "photons/superCluster_isValid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.superCluster.isValid());
      return output;
    }
  };

  template <>
  struct plotter <211> {
    constexpr static const char* name = "photons/matchedPF_isValid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.matchedPF.isValid());
      return output;
    }
  };

  template <>
  struct plotter <212> {
    constexpr static const char* name = "photons/matchedGen_isValid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.matchedGen.isValid());
      return output;
    }
  };

  template <>
  struct plotter <213> {
    constexpr static const char* name = "photons/iy";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.iy);
      return output;
    }
  };

  template <>
  struct plotter <214> {
    constexpr static const char* name = "photons/ix";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.ix);
      return output;
    }
  };

  template <>
  struct plotter <215> {
    constexpr static const char* name = "photons/emax";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.emax);
      return output;
    }
  };

  template <>
  struct plotter <216> {
    constexpr static const char* name = "photons/chIsoMax";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.chIsoMax);
      return output;
    }
  };

  template <>
  struct plotter <217> {
    constexpr static const char* name = "photons/e2nd";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.e2nd);
      return output;
    }
  };

  template <>
  struct plotter <218> {
    constexpr static const char* name = "photons/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <219> {
    constexpr static const char* name = "photons/etop";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.etop);
      return output;
    }
  };

  template <>
  struct plotter <220> {
    constexpr static const char* name = "photons/phiWidth";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.phiWidth);
      return output;
    }
  };

  template <>
  struct plotter <221> {
    constexpr static const char* name = "photons/highpt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.highpt);
      return output;
    }
  };

  template <>
  struct plotter <222> {
    constexpr static const char* name = "photons/mipEnergy";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.mipEnergy);
      return output;
    }
  };

  template <>
  struct plotter <223> {
    constexpr static const char* name = "photons/pixelVeto";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.pixelVeto);
      return output;
    }
  };

  template <>
  struct plotter <224> {
    constexpr static const char* name = "photons/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <225> {
    constexpr static const char* name = "photons/pfchVeto";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.pfchVeto);
      return output;
    }
  };

  template <>
  struct plotter <226> {
    constexpr static const char* name = "photons/pfPt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.pfPt);
      return output;
    }
  };

  template <>
  struct plotter <227> {
    constexpr static const char* name = "photons/eleft";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.eleft);
      return output;
    }
  };

  template <>
  struct plotter <228> {
    constexpr static const char* name = "photons/sipip";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.sipip);
      return output;
    }
  };

  template <>
  struct plotter <229> {
    constexpr static const char* name = "photons/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <230> {
    constexpr static const char* name = "photons/tight";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.tight);
      return output;
    }
  };

  template <>
  struct plotter <231> {
    constexpr static const char* name = "photons/genIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.genIso);
      return output;
    }
  };

  template <>
  struct plotter <232> {
    constexpr static const char* name = "photons/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <233> {
    constexpr static const char* name = "photons/sieie";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.sieie);
      return output;
    }
  };

  template <>
  struct plotter <234> {
    constexpr static const char* name = "photons/medium";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.medium);
      return output;
    }
  };

  template <>
  struct plotter <235> {
    constexpr static const char* name = "photons/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <236> {
    constexpr static const char* name = "photons/loose";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.loose);
      return output;
    }
  };

  template <>
  struct plotter <237> {
    constexpr static const char* name = "photons/eright";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.eright);
      return output;
    }
  };

  template <>
  struct plotter <238> {
    constexpr static const char* name = "photons/nhIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.nhIso);
      return output;
    }
  };

  template <>
  struct plotter <239> {
    constexpr static const char* name = "photons/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <240> {
    constexpr static const char* name = "photons/ebottom";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.ebottom);
      return output;
    }
  };

  template <>
  struct plotter <241> {
    constexpr static const char* name = "photons/csafeVeto";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.csafeVeto);
      return output;
    }
  };

  template <>
  struct plotter <242> {
    constexpr static const char* name = "photons/phIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.phIso);
      return output;
    }
  };

  template <>
  struct plotter <243> {
    constexpr static const char* name = "photons/regPt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.regPt);
      return output;
    }
  };

  template <>
  struct plotter <244> {
    constexpr static const char* name = "photons/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <245> {
    constexpr static const char* name = "photons/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <246> {
    constexpr static const char* name = "photons/r9";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.r9);
      return output;
    }
  };

  template <>
  struct plotter <247> {
    constexpr static const char* name = "photons/timeSpan";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.timeSpan);
      return output;
    }
  };

  template <>
  struct plotter <248> {
    constexpr static const char* name = "photons/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <249> {
    constexpr static const char* name = "photons/etaWidth";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.etaWidth);
      return output;
    }
  };

  template <>
  struct plotter <250> {
    constexpr static const char* name = "photons/chIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.chIso);
      return output;
    }
  };

  template <>
  struct plotter <251> {
    constexpr static const char* name = "photons/hOverE";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.hOverE);
      return output;
    }
  };

  template <>
  struct plotter <252> {
    constexpr static const char* name = "photons/smearedPt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.smearedPt);
      return output;
    }
  };

  template <>
  struct plotter <253> {
    constexpr static const char* name = "photons/time";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.photons)
        output.push_back(i.time);
      return output;
    }
  };

  template <>
  struct plotter <254> {
    constexpr static const char* name = "chsAK4Jets/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.chsAK4Jets.size())};
      return output;
    }
  };

  template <>
  struct plotter <255> {
    constexpr static const char* name = "chsAK4Jets/matchedGenJet_isValid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.matchedGenJet.isValid());
      return output;
    }
  };

  template <>
  struct plotter <256> {
    constexpr static const char* name = "chsAK4Jets/constituents_size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.constituents.size());
      return output;
    }
  };

  template <>
  struct plotter <257> {
    constexpr static const char* name = "chsAK4Jets/secondaryVertex_isValid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.secondaryVertex.isValid());
      return output;
    }
  };

  template <>
  struct plotter <258> {
    constexpr static const char* name = "chsAK4Jets/deepCMVAudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.deepCMVAudsg);
      return output;
    }
  };

  template <>
  struct plotter <259> {
    constexpr static const char* name = "chsAK4Jets/nhf";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.nhf);
      return output;
    }
  };

  template <>
  struct plotter <260> {
    constexpr static const char* name = "chsAK4Jets/ptCorrUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.ptCorrUp);
      return output;
    }
  };

  template <>
  struct plotter <261> {
    constexpr static const char* name = "chsAK4Jets/deepCMVAcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.deepCMVAcc);
      return output;
    }
  };

  template <>
  struct plotter <262> {
    constexpr static const char* name = "chsAK4Jets/deepCSVudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.deepCSVudsg);
      return output;
    }
  };

  template <>
  struct plotter <263> {
    constexpr static const char* name = "chsAK4Jets/cmva";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.cmva);
      return output;
    }
  };

  template <>
  struct plotter <264> {
    constexpr static const char* name = "chsAK4Jets/deepCSVcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.deepCSVcc);
      return output;
    }
  };

  template <>
  struct plotter <265> {
    constexpr static const char* name = "chsAK4Jets/deepCMVAbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.deepCMVAbb);
      return output;
    }
  };

  template <>
  struct plotter <266> {
    constexpr static const char* name = "chsAK4Jets/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <267> {
    constexpr static const char* name = "chsAK4Jets/chf";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.chf);
      return output;
    }
  };

  template <>
  struct plotter <268> {
    constexpr static const char* name = "chsAK4Jets/area";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.area);
      return output;
    }
  };

  template <>
  struct plotter <269> {
    constexpr static const char* name = "chsAK4Jets/nef";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.nef);
      return output;
    }
  };

  template <>
  struct plotter <270> {
    constexpr static const char* name = "chsAK4Jets/ptCorrDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.ptCorrDown);
      return output;
    }
  };

  template <>
  struct plotter <271> {
    constexpr static const char* name = "chsAK4Jets/deepCSVbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.deepCSVbb);
      return output;
    }
  };

  template <>
  struct plotter <272> {
    constexpr static const char* name = "chsAK4Jets/deepCMVAb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.deepCMVAb);
      return output;
    }
  };

  template <>
  struct plotter <273> {
    constexpr static const char* name = "chsAK4Jets/tight";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.tight);
      return output;
    }
  };

  template <>
  struct plotter <274> {
    constexpr static const char* name = "chsAK4Jets/puid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.puid);
      return output;
    }
  };

  template <>
  struct plotter <275> {
    constexpr static const char* name = "chsAK4Jets/qgl";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.qgl);
      return output;
    }
  };

  template <>
  struct plotter <276> {
    constexpr static const char* name = "chsAK4Jets/tightLepVeto";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.tightLepVeto);
      return output;
    }
  };

  template <>
  struct plotter <277> {
    constexpr static const char* name = "chsAK4Jets/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <278> {
    constexpr static const char* name = "chsAK4Jets/cef";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.cef);
      return output;
    }
  };

  template <>
  struct plotter <279> {
    constexpr static const char* name = "chsAK4Jets/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <280> {
    constexpr static const char* name = "chsAK4Jets/rawPt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.rawPt);
      return output;
    }
  };

  template <>
  struct plotter <281> {
    constexpr static const char* name = "chsAK4Jets/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <282> {
    constexpr static const char* name = "chsAK4Jets/loose";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.loose);
      return output;
    }
  };

  template <>
  struct plotter <283> {
    constexpr static const char* name = "chsAK4Jets/deepCMVAc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.deepCMVAc);
      return output;
    }
  };

  template <>
  struct plotter <284> {
    constexpr static const char* name = "chsAK4Jets/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <285> {
    constexpr static const char* name = "chsAK4Jets/monojet";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.monojet);
      return output;
    }
  };

  template <>
  struct plotter <286> {
    constexpr static const char* name = "chsAK4Jets/ptSmearDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.ptSmearDown);
      return output;
    }
  };

  template <>
  struct plotter <287> {
    constexpr static const char* name = "chsAK4Jets/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <288> {
    constexpr static const char* name = "chsAK4Jets/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <289> {
    constexpr static const char* name = "chsAK4Jets/csv";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.csv);
      return output;
    }
  };

  template <>
  struct plotter <290> {
    constexpr static const char* name = "chsAK4Jets/deepCSVb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.deepCSVb);
      return output;
    }
  };

  template <>
  struct plotter <291> {
    constexpr static const char* name = "chsAK4Jets/deepCSVc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.deepCSVc);
      return output;
    }
  };

  template <>
  struct plotter <292> {
    constexpr static const char* name = "chsAK4Jets/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <293> {
    constexpr static const char* name = "chsAK4Jets/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <294> {
    constexpr static const char* name = "chsAK4Jets/ptSmear";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.ptSmear);
      return output;
    }
  };

  template <>
  struct plotter <295> {
    constexpr static const char* name = "chsAK4Jets/ptSmearUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK4Jets)
        output.push_back(i.ptSmearUp);
      return output;
    }
  };

  template <>
  struct plotter <296> {
    constexpr static const char* name = "puppiAK4Jets/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.puppiAK4Jets.size())};
      return output;
    }
  };

  template <>
  struct plotter <297> {
    constexpr static const char* name = "puppiAK4Jets/matchedGenJet_isValid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.matchedGenJet.isValid());
      return output;
    }
  };

  template <>
  struct plotter <298> {
    constexpr static const char* name = "puppiAK4Jets/constituents_size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.constituents.size());
      return output;
    }
  };

  template <>
  struct plotter <299> {
    constexpr static const char* name = "puppiAK4Jets/secondaryVertex_isValid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.secondaryVertex.isValid());
      return output;
    }
  };

  template <>
  struct plotter <300> {
    constexpr static const char* name = "puppiAK4Jets/deepCMVAudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.deepCMVAudsg);
      return output;
    }
  };

  template <>
  struct plotter <301> {
    constexpr static const char* name = "puppiAK4Jets/nhf";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.nhf);
      return output;
    }
  };

  template <>
  struct plotter <302> {
    constexpr static const char* name = "puppiAK4Jets/ptCorrUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.ptCorrUp);
      return output;
    }
  };

  template <>
  struct plotter <303> {
    constexpr static const char* name = "puppiAK4Jets/deepCMVAcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.deepCMVAcc);
      return output;
    }
  };

  template <>
  struct plotter <304> {
    constexpr static const char* name = "puppiAK4Jets/deepCSVudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.deepCSVudsg);
      return output;
    }
  };

  template <>
  struct plotter <305> {
    constexpr static const char* name = "puppiAK4Jets/cmva";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.cmva);
      return output;
    }
  };

  template <>
  struct plotter <306> {
    constexpr static const char* name = "puppiAK4Jets/deepCSVcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.deepCSVcc);
      return output;
    }
  };

  template <>
  struct plotter <307> {
    constexpr static const char* name = "puppiAK4Jets/deepCMVAbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.deepCMVAbb);
      return output;
    }
  };

  template <>
  struct plotter <308> {
    constexpr static const char* name = "puppiAK4Jets/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <309> {
    constexpr static const char* name = "puppiAK4Jets/chf";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.chf);
      return output;
    }
  };

  template <>
  struct plotter <310> {
    constexpr static const char* name = "puppiAK4Jets/area";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.area);
      return output;
    }
  };

  template <>
  struct plotter <311> {
    constexpr static const char* name = "puppiAK4Jets/nef";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.nef);
      return output;
    }
  };

  template <>
  struct plotter <312> {
    constexpr static const char* name = "puppiAK4Jets/ptCorrDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.ptCorrDown);
      return output;
    }
  };

  template <>
  struct plotter <313> {
    constexpr static const char* name = "puppiAK4Jets/deepCSVbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.deepCSVbb);
      return output;
    }
  };

  template <>
  struct plotter <314> {
    constexpr static const char* name = "puppiAK4Jets/deepCMVAb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.deepCMVAb);
      return output;
    }
  };

  template <>
  struct plotter <315> {
    constexpr static const char* name = "puppiAK4Jets/tight";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.tight);
      return output;
    }
  };

  template <>
  struct plotter <316> {
    constexpr static const char* name = "puppiAK4Jets/puid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.puid);
      return output;
    }
  };

  template <>
  struct plotter <317> {
    constexpr static const char* name = "puppiAK4Jets/qgl";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.qgl);
      return output;
    }
  };

  template <>
  struct plotter <318> {
    constexpr static const char* name = "puppiAK4Jets/tightLepVeto";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.tightLepVeto);
      return output;
    }
  };

  template <>
  struct plotter <319> {
    constexpr static const char* name = "puppiAK4Jets/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <320> {
    constexpr static const char* name = "puppiAK4Jets/cef";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.cef);
      return output;
    }
  };

  template <>
  struct plotter <321> {
    constexpr static const char* name = "puppiAK4Jets/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <322> {
    constexpr static const char* name = "puppiAK4Jets/rawPt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.rawPt);
      return output;
    }
  };

  template <>
  struct plotter <323> {
    constexpr static const char* name = "puppiAK4Jets/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <324> {
    constexpr static const char* name = "puppiAK4Jets/loose";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.loose);
      return output;
    }
  };

  template <>
  struct plotter <325> {
    constexpr static const char* name = "puppiAK4Jets/deepCMVAc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.deepCMVAc);
      return output;
    }
  };

  template <>
  struct plotter <326> {
    constexpr static const char* name = "puppiAK4Jets/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <327> {
    constexpr static const char* name = "puppiAK4Jets/monojet";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.monojet);
      return output;
    }
  };

  template <>
  struct plotter <328> {
    constexpr static const char* name = "puppiAK4Jets/ptSmearDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.ptSmearDown);
      return output;
    }
  };

  template <>
  struct plotter <329> {
    constexpr static const char* name = "puppiAK4Jets/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <330> {
    constexpr static const char* name = "puppiAK4Jets/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <331> {
    constexpr static const char* name = "puppiAK4Jets/csv";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.csv);
      return output;
    }
  };

  template <>
  struct plotter <332> {
    constexpr static const char* name = "puppiAK4Jets/deepCSVb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.deepCSVb);
      return output;
    }
  };

  template <>
  struct plotter <333> {
    constexpr static const char* name = "puppiAK4Jets/deepCSVc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.deepCSVc);
      return output;
    }
  };

  template <>
  struct plotter <334> {
    constexpr static const char* name = "puppiAK4Jets/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <335> {
    constexpr static const char* name = "puppiAK4Jets/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <336> {
    constexpr static const char* name = "puppiAK4Jets/ptSmear";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.ptSmear);
      return output;
    }
  };

  template <>
  struct plotter <337> {
    constexpr static const char* name = "puppiAK4Jets/ptSmearUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK4Jets)
        output.push_back(i.ptSmearUp);
      return output;
    }
  };

  template <>
  struct plotter <338> {
    constexpr static const char* name = "chsAK8Jets/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.chsAK8Jets.size())};
      return output;
    }
  };

  template <>
  struct plotter <339> {
    constexpr static const char* name = "chsAK8Jets/subjets_size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.subjets.size());
      return output;
    }
  };

  template <>
  struct plotter <340> {
    constexpr static const char* name = "chsAK8Jets/deepCMVAudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.deepCMVAudsg);
      return output;
    }
  };

  template <>
  struct plotter <341> {
    constexpr static const char* name = "chsAK8Jets/deepBBprobH";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.deepBBprobH);
      return output;
    }
  };

  template <>
  struct plotter <342> {
    constexpr static const char* name = "chsAK8Jets/deepCMVAbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.deepCMVAbb);
      return output;
    }
  };

  template <>
  struct plotter <343> {
    constexpr static const char* name = "chsAK8Jets/ptCorrUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.ptCorrUp);
      return output;
    }
  };

  template <>
  struct plotter <344> {
    constexpr static const char* name = "chsAK8Jets/cef";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.cef);
      return output;
    }
  };

  template <>
  struct plotter <345> {
    constexpr static const char* name = "chsAK8Jets/deepCSVudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.deepCSVudsg);
      return output;
    }
  };

  template <>
  struct plotter <346> {
    constexpr static const char* name = "chsAK8Jets/tight";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.tight);
      return output;
    }
  };

  template <>
  struct plotter <347> {
    constexpr static const char* name = "chsAK8Jets/cmva";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.cmva);
      return output;
    }
  };

  template <>
  struct plotter <348> {
    constexpr static const char* name = "chsAK8Jets/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <349> {
    constexpr static const char* name = "chsAK8Jets/nhf";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.nhf);
      return output;
    }
  };

  template <>
  struct plotter <350> {
    constexpr static const char* name = "chsAK8Jets/deepBBprobQ";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.deepBBprobQ);
      return output;
    }
  };

  template <>
  struct plotter <351> {
    constexpr static const char* name = "chsAK8Jets/deepCSVbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.deepCSVbb);
      return output;
    }
  };

  template <>
  struct plotter <352> {
    constexpr static const char* name = "chsAK8Jets/htt_frec";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.htt_frec);
      return output;
    }
  };

  template <>
  struct plotter <353> {
    constexpr static const char* name = "chsAK8Jets/deepCMVAb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.deepCMVAb);
      return output;
    }
  };

  template <>
  struct plotter <354> {
    constexpr static const char* name = "chsAK8Jets/chf";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.chf);
      return output;
    }
  };

  template <>
  struct plotter <355> {
    constexpr static const char* name = "chsAK8Jets/area";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.area);
      return output;
    }
  };

  template <>
  struct plotter <356> {
    constexpr static const char* name = "chsAK8Jets/nef";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.nef);
      return output;
    }
  };

  template <>
  struct plotter <357> {
    constexpr static const char* name = "chsAK8Jets/htt_mass";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.htt_mass);
      return output;
    }
  };

  template <>
  struct plotter <358> {
    constexpr static const char* name = "chsAK8Jets/ptCorrDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.ptCorrDown);
      return output;
    }
  };

  template <>
  struct plotter <359> {
    constexpr static const char* name = "chsAK8Jets/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <360> {
    constexpr static const char* name = "chsAK8Jets/tau2";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.tau2);
      return output;
    }
  };

  template <>
  struct plotter <361> {
    constexpr static const char* name = "chsAK8Jets/tau3";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.tau3);
      return output;
    }
  };

  template <>
  struct plotter <362> {
    constexpr static const char* name = "chsAK8Jets/puid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.puid);
      return output;
    }
  };

  template <>
  struct plotter <363> {
    constexpr static const char* name = "chsAK8Jets/tau1";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.tau1);
      return output;
    }
  };

  template <>
  struct plotter <364> {
    constexpr static const char* name = "chsAK8Jets/mSD";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.mSD);
      return output;
    }
  };

  template <>
  struct plotter <365> {
    constexpr static const char* name = "chsAK8Jets/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <366> {
    constexpr static const char* name = "chsAK8Jets/deepCMVAcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.deepCMVAcc);
      return output;
    }
  };

  template <>
  struct plotter <367> {
    constexpr static const char* name = "chsAK8Jets/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <368> {
    constexpr static const char* name = "chsAK8Jets/rawPt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.rawPt);
      return output;
    }
  };

  template <>
  struct plotter <369> {
    constexpr static const char* name = "chsAK8Jets/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <370> {
    constexpr static const char* name = "chsAK8Jets/double_sub";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.double_sub);
      return output;
    }
  };

  template <>
  struct plotter <371> {
    constexpr static const char* name = "chsAK8Jets/loose";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.loose);
      return output;
    }
  };

  template <>
  struct plotter <372> {
    constexpr static const char* name = "chsAK8Jets/ptSmear";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.ptSmear);
      return output;
    }
  };

  template <>
  struct plotter <373> {
    constexpr static const char* name = "chsAK8Jets/deepCMVAc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.deepCMVAc);
      return output;
    }
  };

  template <>
  struct plotter <374> {
    constexpr static const char* name = "chsAK8Jets/qgl";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.qgl);
      return output;
    }
  };

  template <>
  struct plotter <375> {
    constexpr static const char* name = "chsAK8Jets/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <376> {
    constexpr static const char* name = "chsAK8Jets/monojet";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.monojet);
      return output;
    }
  };

  template <>
  struct plotter <377> {
    constexpr static const char* name = "chsAK8Jets/ptSmearDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.ptSmearDown);
      return output;
    }
  };

  template <>
  struct plotter <378> {
    constexpr static const char* name = "chsAK8Jets/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <379> {
    constexpr static const char* name = "chsAK8Jets/mPruned";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.mPruned);
      return output;
    }
  };

  template <>
  struct plotter <380> {
    constexpr static const char* name = "chsAK8Jets/tau1SD";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.tau1SD);
      return output;
    }
  };

  template <>
  struct plotter <381> {
    constexpr static const char* name = "chsAK8Jets/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <382> {
    constexpr static const char* name = "chsAK8Jets/tightLepVeto";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.tightLepVeto);
      return output;
    }
  };

  template <>
  struct plotter <383> {
    constexpr static const char* name = "chsAK8Jets/deepCSVb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.deepCSVb);
      return output;
    }
  };

  template <>
  struct plotter <384> {
    constexpr static const char* name = "chsAK8Jets/deepCSVc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.deepCSVc);
      return output;
    }
  };

  template <>
  struct plotter <385> {
    constexpr static const char* name = "chsAK8Jets/tau3SD";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.tau3SD);
      return output;
    }
  };

  template <>
  struct plotter <386> {
    constexpr static const char* name = "chsAK8Jets/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <387> {
    constexpr static const char* name = "chsAK8Jets/deepCSVcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.deepCSVcc);
      return output;
    }
  };

  template <>
  struct plotter <388> {
    constexpr static const char* name = "chsAK8Jets/tau2SD";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.tau2SD);
      return output;
    }
  };

  template <>
  struct plotter <389> {
    constexpr static const char* name = "chsAK8Jets/csv";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.csv);
      return output;
    }
  };

  template <>
  struct plotter <390> {
    constexpr static const char* name = "chsAK8Jets/ptSmearUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Jets)
        output.push_back(i.ptSmearUp);
      return output;
    }
  };

  template <>
  struct plotter <391> {
    constexpr static const char* name = "chsAK8Subjets/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.chsAK8Subjets.size())};
      return output;
    }
  };

  template <>
  struct plotter <392> {
    constexpr static const char* name = "chsAK8Subjets/deepCMVAudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.deepCMVAudsg);
      return output;
    }
  };

  template <>
  struct plotter <393> {
    constexpr static const char* name = "chsAK8Subjets/deepCMVAbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.deepCMVAbb);
      return output;
    }
  };

  template <>
  struct plotter <394> {
    constexpr static const char* name = "chsAK8Subjets/deepCSVudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.deepCSVudsg);
      return output;
    }
  };

  template <>
  struct plotter <395> {
    constexpr static const char* name = "chsAK8Subjets/cmva";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.cmva);
      return output;
    }
  };

  template <>
  struct plotter <396> {
    constexpr static const char* name = "chsAK8Subjets/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <397> {
    constexpr static const char* name = "chsAK8Subjets/deepCSVbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.deepCSVbb);
      return output;
    }
  };

  template <>
  struct plotter <398> {
    constexpr static const char* name = "chsAK8Subjets/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <399> {
    constexpr static const char* name = "chsAK8Subjets/deepCMVAb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.deepCMVAb);
      return output;
    }
  };

  template <>
  struct plotter <400> {
    constexpr static const char* name = "chsAK8Subjets/deepCMVAc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.deepCMVAc);
      return output;
    }
  };

  template <>
  struct plotter <401> {
    constexpr static const char* name = "chsAK8Subjets/qgl";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.qgl);
      return output;
    }
  };

  template <>
  struct plotter <402> {
    constexpr static const char* name = "chsAK8Subjets/csv";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.csv);
      return output;
    }
  };

  template <>
  struct plotter <403> {
    constexpr static const char* name = "chsAK8Subjets/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <404> {
    constexpr static const char* name = "chsAK8Subjets/deepCMVAcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.deepCMVAcc);
      return output;
    }
  };

  template <>
  struct plotter <405> {
    constexpr static const char* name = "chsAK8Subjets/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <406> {
    constexpr static const char* name = "chsAK8Subjets/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <407> {
    constexpr static const char* name = "chsAK8Subjets/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <408> {
    constexpr static const char* name = "chsAK8Subjets/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <409> {
    constexpr static const char* name = "chsAK8Subjets/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <410> {
    constexpr static const char* name = "chsAK8Subjets/deepCSVb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.deepCSVb);
      return output;
    }
  };

  template <>
  struct plotter <411> {
    constexpr static const char* name = "chsAK8Subjets/deepCSVc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.deepCSVc);
      return output;
    }
  };

  template <>
  struct plotter <412> {
    constexpr static const char* name = "chsAK8Subjets/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <413> {
    constexpr static const char* name = "chsAK8Subjets/deepCSVcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsAK8Subjets)
        output.push_back(i.deepCSVcc);
      return output;
    }
  };

  template <>
  struct plotter <414> {
    constexpr static const char* name = "chsCA15Jets/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.chsCA15Jets.size())};
      return output;
    }
  };

  template <>
  struct plotter <415> {
    constexpr static const char* name = "chsCA15Jets/subjets_size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.subjets.size());
      return output;
    }
  };

  template <>
  struct plotter <416> {
    constexpr static const char* name = "chsCA15Jets/deepCMVAudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.deepCMVAudsg);
      return output;
    }
  };

  template <>
  struct plotter <417> {
    constexpr static const char* name = "chsCA15Jets/deepBBprobH";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.deepBBprobH);
      return output;
    }
  };

  template <>
  struct plotter <418> {
    constexpr static const char* name = "chsCA15Jets/deepCMVAbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.deepCMVAbb);
      return output;
    }
  };

  template <>
  struct plotter <419> {
    constexpr static const char* name = "chsCA15Jets/ptCorrUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.ptCorrUp);
      return output;
    }
  };

  template <>
  struct plotter <420> {
    constexpr static const char* name = "chsCA15Jets/cef";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.cef);
      return output;
    }
  };

  template <>
  struct plotter <421> {
    constexpr static const char* name = "chsCA15Jets/deepCSVudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.deepCSVudsg);
      return output;
    }
  };

  template <>
  struct plotter <422> {
    constexpr static const char* name = "chsCA15Jets/tight";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.tight);
      return output;
    }
  };

  template <>
  struct plotter <423> {
    constexpr static const char* name = "chsCA15Jets/cmva";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.cmva);
      return output;
    }
  };

  template <>
  struct plotter <424> {
    constexpr static const char* name = "chsCA15Jets/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <425> {
    constexpr static const char* name = "chsCA15Jets/nhf";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.nhf);
      return output;
    }
  };

  template <>
  struct plotter <426> {
    constexpr static const char* name = "chsCA15Jets/deepBBprobQ";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.deepBBprobQ);
      return output;
    }
  };

  template <>
  struct plotter <427> {
    constexpr static const char* name = "chsCA15Jets/deepCSVbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.deepCSVbb);
      return output;
    }
  };

  template <>
  struct plotter <428> {
    constexpr static const char* name = "chsCA15Jets/htt_frec";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.htt_frec);
      return output;
    }
  };

  template <>
  struct plotter <429> {
    constexpr static const char* name = "chsCA15Jets/deepCMVAb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.deepCMVAb);
      return output;
    }
  };

  template <>
  struct plotter <430> {
    constexpr static const char* name = "chsCA15Jets/chf";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.chf);
      return output;
    }
  };

  template <>
  struct plotter <431> {
    constexpr static const char* name = "chsCA15Jets/area";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.area);
      return output;
    }
  };

  template <>
  struct plotter <432> {
    constexpr static const char* name = "chsCA15Jets/nef";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.nef);
      return output;
    }
  };

  template <>
  struct plotter <433> {
    constexpr static const char* name = "chsCA15Jets/htt_mass";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.htt_mass);
      return output;
    }
  };

  template <>
  struct plotter <434> {
    constexpr static const char* name = "chsCA15Jets/ptCorrDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.ptCorrDown);
      return output;
    }
  };

  template <>
  struct plotter <435> {
    constexpr static const char* name = "chsCA15Jets/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <436> {
    constexpr static const char* name = "chsCA15Jets/tau2";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.tau2);
      return output;
    }
  };

  template <>
  struct plotter <437> {
    constexpr static const char* name = "chsCA15Jets/tau3";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.tau3);
      return output;
    }
  };

  template <>
  struct plotter <438> {
    constexpr static const char* name = "chsCA15Jets/puid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.puid);
      return output;
    }
  };

  template <>
  struct plotter <439> {
    constexpr static const char* name = "chsCA15Jets/tau1";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.tau1);
      return output;
    }
  };

  template <>
  struct plotter <440> {
    constexpr static const char* name = "chsCA15Jets/mSD";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.mSD);
      return output;
    }
  };

  template <>
  struct plotter <441> {
    constexpr static const char* name = "chsCA15Jets/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <442> {
    constexpr static const char* name = "chsCA15Jets/deepCMVAcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.deepCMVAcc);
      return output;
    }
  };

  template <>
  struct plotter <443> {
    constexpr static const char* name = "chsCA15Jets/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <444> {
    constexpr static const char* name = "chsCA15Jets/rawPt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.rawPt);
      return output;
    }
  };

  template <>
  struct plotter <445> {
    constexpr static const char* name = "chsCA15Jets/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <446> {
    constexpr static const char* name = "chsCA15Jets/double_sub";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.double_sub);
      return output;
    }
  };

  template <>
  struct plotter <447> {
    constexpr static const char* name = "chsCA15Jets/loose";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.loose);
      return output;
    }
  };

  template <>
  struct plotter <448> {
    constexpr static const char* name = "chsCA15Jets/ptSmear";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.ptSmear);
      return output;
    }
  };

  template <>
  struct plotter <449> {
    constexpr static const char* name = "chsCA15Jets/deepCMVAc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.deepCMVAc);
      return output;
    }
  };

  template <>
  struct plotter <450> {
    constexpr static const char* name = "chsCA15Jets/qgl";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.qgl);
      return output;
    }
  };

  template <>
  struct plotter <451> {
    constexpr static const char* name = "chsCA15Jets/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <452> {
    constexpr static const char* name = "chsCA15Jets/monojet";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.monojet);
      return output;
    }
  };

  template <>
  struct plotter <453> {
    constexpr static const char* name = "chsCA15Jets/ptSmearDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.ptSmearDown);
      return output;
    }
  };

  template <>
  struct plotter <454> {
    constexpr static const char* name = "chsCA15Jets/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <455> {
    constexpr static const char* name = "chsCA15Jets/mPruned";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.mPruned);
      return output;
    }
  };

  template <>
  struct plotter <456> {
    constexpr static const char* name = "chsCA15Jets/tau1SD";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.tau1SD);
      return output;
    }
  };

  template <>
  struct plotter <457> {
    constexpr static const char* name = "chsCA15Jets/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <458> {
    constexpr static const char* name = "chsCA15Jets/tightLepVeto";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.tightLepVeto);
      return output;
    }
  };

  template <>
  struct plotter <459> {
    constexpr static const char* name = "chsCA15Jets/deepCSVb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.deepCSVb);
      return output;
    }
  };

  template <>
  struct plotter <460> {
    constexpr static const char* name = "chsCA15Jets/deepCSVc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.deepCSVc);
      return output;
    }
  };

  template <>
  struct plotter <461> {
    constexpr static const char* name = "chsCA15Jets/tau3SD";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.tau3SD);
      return output;
    }
  };

  template <>
  struct plotter <462> {
    constexpr static const char* name = "chsCA15Jets/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <463> {
    constexpr static const char* name = "chsCA15Jets/deepCSVcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.deepCSVcc);
      return output;
    }
  };

  template <>
  struct plotter <464> {
    constexpr static const char* name = "chsCA15Jets/tau2SD";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.tau2SD);
      return output;
    }
  };

  template <>
  struct plotter <465> {
    constexpr static const char* name = "chsCA15Jets/csv";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.csv);
      return output;
    }
  };

  template <>
  struct plotter <466> {
    constexpr static const char* name = "chsCA15Jets/ptSmearUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Jets)
        output.push_back(i.ptSmearUp);
      return output;
    }
  };

  template <>
  struct plotter <467> {
    constexpr static const char* name = "chsCA15Subjets/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.chsCA15Subjets.size())};
      return output;
    }
  };

  template <>
  struct plotter <468> {
    constexpr static const char* name = "chsCA15Subjets/deepCMVAudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.deepCMVAudsg);
      return output;
    }
  };

  template <>
  struct plotter <469> {
    constexpr static const char* name = "chsCA15Subjets/deepCMVAbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.deepCMVAbb);
      return output;
    }
  };

  template <>
  struct plotter <470> {
    constexpr static const char* name = "chsCA15Subjets/deepCSVudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.deepCSVudsg);
      return output;
    }
  };

  template <>
  struct plotter <471> {
    constexpr static const char* name = "chsCA15Subjets/cmva";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.cmva);
      return output;
    }
  };

  template <>
  struct plotter <472> {
    constexpr static const char* name = "chsCA15Subjets/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <473> {
    constexpr static const char* name = "chsCA15Subjets/deepCSVbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.deepCSVbb);
      return output;
    }
  };

  template <>
  struct plotter <474> {
    constexpr static const char* name = "chsCA15Subjets/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <475> {
    constexpr static const char* name = "chsCA15Subjets/deepCMVAb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.deepCMVAb);
      return output;
    }
  };

  template <>
  struct plotter <476> {
    constexpr static const char* name = "chsCA15Subjets/deepCMVAc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.deepCMVAc);
      return output;
    }
  };

  template <>
  struct plotter <477> {
    constexpr static const char* name = "chsCA15Subjets/qgl";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.qgl);
      return output;
    }
  };

  template <>
  struct plotter <478> {
    constexpr static const char* name = "chsCA15Subjets/csv";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.csv);
      return output;
    }
  };

  template <>
  struct plotter <479> {
    constexpr static const char* name = "chsCA15Subjets/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <480> {
    constexpr static const char* name = "chsCA15Subjets/deepCMVAcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.deepCMVAcc);
      return output;
    }
  };

  template <>
  struct plotter <481> {
    constexpr static const char* name = "chsCA15Subjets/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <482> {
    constexpr static const char* name = "chsCA15Subjets/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <483> {
    constexpr static const char* name = "chsCA15Subjets/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <484> {
    constexpr static const char* name = "chsCA15Subjets/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <485> {
    constexpr static const char* name = "chsCA15Subjets/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <486> {
    constexpr static const char* name = "chsCA15Subjets/deepCSVb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.deepCSVb);
      return output;
    }
  };

  template <>
  struct plotter <487> {
    constexpr static const char* name = "chsCA15Subjets/deepCSVc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.deepCSVc);
      return output;
    }
  };

  template <>
  struct plotter <488> {
    constexpr static const char* name = "chsCA15Subjets/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <489> {
    constexpr static const char* name = "chsCA15Subjets/deepCSVcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.chsCA15Subjets)
        output.push_back(i.deepCSVcc);
      return output;
    }
  };

  template <>
  struct plotter <490> {
    constexpr static const char* name = "puppiAK8Jets/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.puppiAK8Jets.size())};
      return output;
    }
  };

  template <>
  struct plotter <491> {
    constexpr static const char* name = "puppiAK8Jets/subjets_size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.subjets.size());
      return output;
    }
  };

  template <>
  struct plotter <492> {
    constexpr static const char* name = "puppiAK8Jets/deepCMVAudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.deepCMVAudsg);
      return output;
    }
  };

  template <>
  struct plotter <493> {
    constexpr static const char* name = "puppiAK8Jets/deepBBprobH";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.deepBBprobH);
      return output;
    }
  };

  template <>
  struct plotter <494> {
    constexpr static const char* name = "puppiAK8Jets/deepCMVAbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.deepCMVAbb);
      return output;
    }
  };

  template <>
  struct plotter <495> {
    constexpr static const char* name = "puppiAK8Jets/ptCorrUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.ptCorrUp);
      return output;
    }
  };

  template <>
  struct plotter <496> {
    constexpr static const char* name = "puppiAK8Jets/cef";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.cef);
      return output;
    }
  };

  template <>
  struct plotter <497> {
    constexpr static const char* name = "puppiAK8Jets/deepCSVudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.deepCSVudsg);
      return output;
    }
  };

  template <>
  struct plotter <498> {
    constexpr static const char* name = "puppiAK8Jets/tight";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.tight);
      return output;
    }
  };

  template <>
  struct plotter <499> {
    constexpr static const char* name = "puppiAK8Jets/cmva";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.cmva);
      return output;
    }
  };

  template <>
  struct plotter <500> {
    constexpr static const char* name = "puppiAK8Jets/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <501> {
    constexpr static const char* name = "puppiAK8Jets/nhf";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.nhf);
      return output;
    }
  };

  template <>
  struct plotter <502> {
    constexpr static const char* name = "puppiAK8Jets/deepBBprobQ";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.deepBBprobQ);
      return output;
    }
  };

  template <>
  struct plotter <503> {
    constexpr static const char* name = "puppiAK8Jets/deepCSVbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.deepCSVbb);
      return output;
    }
  };

  template <>
  struct plotter <504> {
    constexpr static const char* name = "puppiAK8Jets/htt_frec";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.htt_frec);
      return output;
    }
  };

  template <>
  struct plotter <505> {
    constexpr static const char* name = "puppiAK8Jets/deepCMVAb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.deepCMVAb);
      return output;
    }
  };

  template <>
  struct plotter <506> {
    constexpr static const char* name = "puppiAK8Jets/chf";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.chf);
      return output;
    }
  };

  template <>
  struct plotter <507> {
    constexpr static const char* name = "puppiAK8Jets/area";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.area);
      return output;
    }
  };

  template <>
  struct plotter <508> {
    constexpr static const char* name = "puppiAK8Jets/nef";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.nef);
      return output;
    }
  };

  template <>
  struct plotter <509> {
    constexpr static const char* name = "puppiAK8Jets/htt_mass";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.htt_mass);
      return output;
    }
  };

  template <>
  struct plotter <510> {
    constexpr static const char* name = "puppiAK8Jets/ptCorrDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.ptCorrDown);
      return output;
    }
  };

  template <>
  struct plotter <511> {
    constexpr static const char* name = "puppiAK8Jets/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <512> {
    constexpr static const char* name = "puppiAK8Jets/tau2";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.tau2);
      return output;
    }
  };

  template <>
  struct plotter <513> {
    constexpr static const char* name = "puppiAK8Jets/tau3";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.tau3);
      return output;
    }
  };

  template <>
  struct plotter <514> {
    constexpr static const char* name = "puppiAK8Jets/puid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.puid);
      return output;
    }
  };

  template <>
  struct plotter <515> {
    constexpr static const char* name = "puppiAK8Jets/tau1";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.tau1);
      return output;
    }
  };

  template <>
  struct plotter <516> {
    constexpr static const char* name = "puppiAK8Jets/mSD";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.mSD);
      return output;
    }
  };

  template <>
  struct plotter <517> {
    constexpr static const char* name = "puppiAK8Jets/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <518> {
    constexpr static const char* name = "puppiAK8Jets/deepCMVAcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.deepCMVAcc);
      return output;
    }
  };

  template <>
  struct plotter <519> {
    constexpr static const char* name = "puppiAK8Jets/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <520> {
    constexpr static const char* name = "puppiAK8Jets/rawPt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.rawPt);
      return output;
    }
  };

  template <>
  struct plotter <521> {
    constexpr static const char* name = "puppiAK8Jets/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <522> {
    constexpr static const char* name = "puppiAK8Jets/double_sub";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.double_sub);
      return output;
    }
  };

  template <>
  struct plotter <523> {
    constexpr static const char* name = "puppiAK8Jets/loose";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.loose);
      return output;
    }
  };

  template <>
  struct plotter <524> {
    constexpr static const char* name = "puppiAK8Jets/ptSmear";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.ptSmear);
      return output;
    }
  };

  template <>
  struct plotter <525> {
    constexpr static const char* name = "puppiAK8Jets/deepCMVAc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.deepCMVAc);
      return output;
    }
  };

  template <>
  struct plotter <526> {
    constexpr static const char* name = "puppiAK8Jets/qgl";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.qgl);
      return output;
    }
  };

  template <>
  struct plotter <527> {
    constexpr static const char* name = "puppiAK8Jets/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <528> {
    constexpr static const char* name = "puppiAK8Jets/monojet";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.monojet);
      return output;
    }
  };

  template <>
  struct plotter <529> {
    constexpr static const char* name = "puppiAK8Jets/ptSmearDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.ptSmearDown);
      return output;
    }
  };

  template <>
  struct plotter <530> {
    constexpr static const char* name = "puppiAK8Jets/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <531> {
    constexpr static const char* name = "puppiAK8Jets/mPruned";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.mPruned);
      return output;
    }
  };

  template <>
  struct plotter <532> {
    constexpr static const char* name = "puppiAK8Jets/tau1SD";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.tau1SD);
      return output;
    }
  };

  template <>
  struct plotter <533> {
    constexpr static const char* name = "puppiAK8Jets/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <534> {
    constexpr static const char* name = "puppiAK8Jets/tightLepVeto";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.tightLepVeto);
      return output;
    }
  };

  template <>
  struct plotter <535> {
    constexpr static const char* name = "puppiAK8Jets/deepCSVb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.deepCSVb);
      return output;
    }
  };

  template <>
  struct plotter <536> {
    constexpr static const char* name = "puppiAK8Jets/deepCSVc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.deepCSVc);
      return output;
    }
  };

  template <>
  struct plotter <537> {
    constexpr static const char* name = "puppiAK8Jets/tau3SD";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.tau3SD);
      return output;
    }
  };

  template <>
  struct plotter <538> {
    constexpr static const char* name = "puppiAK8Jets/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <539> {
    constexpr static const char* name = "puppiAK8Jets/deepCSVcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.deepCSVcc);
      return output;
    }
  };

  template <>
  struct plotter <540> {
    constexpr static const char* name = "puppiAK8Jets/tau2SD";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.tau2SD);
      return output;
    }
  };

  template <>
  struct plotter <541> {
    constexpr static const char* name = "puppiAK8Jets/csv";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.csv);
      return output;
    }
  };

  template <>
  struct plotter <542> {
    constexpr static const char* name = "puppiAK8Jets/ptSmearUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Jets)
        output.push_back(i.ptSmearUp);
      return output;
    }
  };

  template <>
  struct plotter <543> {
    constexpr static const char* name = "puppiAK8Subjets/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.puppiAK8Subjets.size())};
      return output;
    }
  };

  template <>
  struct plotter <544> {
    constexpr static const char* name = "puppiAK8Subjets/deepCMVAudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.deepCMVAudsg);
      return output;
    }
  };

  template <>
  struct plotter <545> {
    constexpr static const char* name = "puppiAK8Subjets/deepCMVAbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.deepCMVAbb);
      return output;
    }
  };

  template <>
  struct plotter <546> {
    constexpr static const char* name = "puppiAK8Subjets/deepCSVudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.deepCSVudsg);
      return output;
    }
  };

  template <>
  struct plotter <547> {
    constexpr static const char* name = "puppiAK8Subjets/cmva";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.cmva);
      return output;
    }
  };

  template <>
  struct plotter <548> {
    constexpr static const char* name = "puppiAK8Subjets/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <549> {
    constexpr static const char* name = "puppiAK8Subjets/deepCSVbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.deepCSVbb);
      return output;
    }
  };

  template <>
  struct plotter <550> {
    constexpr static const char* name = "puppiAK8Subjets/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <551> {
    constexpr static const char* name = "puppiAK8Subjets/deepCMVAb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.deepCMVAb);
      return output;
    }
  };

  template <>
  struct plotter <552> {
    constexpr static const char* name = "puppiAK8Subjets/deepCMVAc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.deepCMVAc);
      return output;
    }
  };

  template <>
  struct plotter <553> {
    constexpr static const char* name = "puppiAK8Subjets/qgl";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.qgl);
      return output;
    }
  };

  template <>
  struct plotter <554> {
    constexpr static const char* name = "puppiAK8Subjets/csv";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.csv);
      return output;
    }
  };

  template <>
  struct plotter <555> {
    constexpr static const char* name = "puppiAK8Subjets/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <556> {
    constexpr static const char* name = "puppiAK8Subjets/deepCMVAcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.deepCMVAcc);
      return output;
    }
  };

  template <>
  struct plotter <557> {
    constexpr static const char* name = "puppiAK8Subjets/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <558> {
    constexpr static const char* name = "puppiAK8Subjets/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <559> {
    constexpr static const char* name = "puppiAK8Subjets/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <560> {
    constexpr static const char* name = "puppiAK8Subjets/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <561> {
    constexpr static const char* name = "puppiAK8Subjets/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <562> {
    constexpr static const char* name = "puppiAK8Subjets/deepCSVb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.deepCSVb);
      return output;
    }
  };

  template <>
  struct plotter <563> {
    constexpr static const char* name = "puppiAK8Subjets/deepCSVc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.deepCSVc);
      return output;
    }
  };

  template <>
  struct plotter <564> {
    constexpr static const char* name = "puppiAK8Subjets/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <565> {
    constexpr static const char* name = "puppiAK8Subjets/deepCSVcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiAK8Subjets)
        output.push_back(i.deepCSVcc);
      return output;
    }
  };

  template <>
  struct plotter <566> {
    constexpr static const char* name = "puppiCA15Jets/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.puppiCA15Jets.size())};
      return output;
    }
  };

  template <>
  struct plotter <567> {
    constexpr static const char* name = "puppiCA15Jets/subjets_size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.subjets.size());
      return output;
    }
  };

  template <>
  struct plotter <568> {
    constexpr static const char* name = "puppiCA15Jets/deepCMVAudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.deepCMVAudsg);
      return output;
    }
  };

  template <>
  struct plotter <569> {
    constexpr static const char* name = "puppiCA15Jets/deepBBprobH";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.deepBBprobH);
      return output;
    }
  };

  template <>
  struct plotter <570> {
    constexpr static const char* name = "puppiCA15Jets/deepCMVAbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.deepCMVAbb);
      return output;
    }
  };

  template <>
  struct plotter <571> {
    constexpr static const char* name = "puppiCA15Jets/ptCorrUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.ptCorrUp);
      return output;
    }
  };

  template <>
  struct plotter <572> {
    constexpr static const char* name = "puppiCA15Jets/cef";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.cef);
      return output;
    }
  };

  template <>
  struct plotter <573> {
    constexpr static const char* name = "puppiCA15Jets/deepCSVudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.deepCSVudsg);
      return output;
    }
  };

  template <>
  struct plotter <574> {
    constexpr static const char* name = "puppiCA15Jets/tight";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.tight);
      return output;
    }
  };

  template <>
  struct plotter <575> {
    constexpr static const char* name = "puppiCA15Jets/cmva";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.cmva);
      return output;
    }
  };

  template <>
  struct plotter <576> {
    constexpr static const char* name = "puppiCA15Jets/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <577> {
    constexpr static const char* name = "puppiCA15Jets/nhf";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.nhf);
      return output;
    }
  };

  template <>
  struct plotter <578> {
    constexpr static const char* name = "puppiCA15Jets/deepBBprobQ";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.deepBBprobQ);
      return output;
    }
  };

  template <>
  struct plotter <579> {
    constexpr static const char* name = "puppiCA15Jets/deepCSVbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.deepCSVbb);
      return output;
    }
  };

  template <>
  struct plotter <580> {
    constexpr static const char* name = "puppiCA15Jets/htt_frec";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.htt_frec);
      return output;
    }
  };

  template <>
  struct plotter <581> {
    constexpr static const char* name = "puppiCA15Jets/deepCMVAb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.deepCMVAb);
      return output;
    }
  };

  template <>
  struct plotter <582> {
    constexpr static const char* name = "puppiCA15Jets/chf";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.chf);
      return output;
    }
  };

  template <>
  struct plotter <583> {
    constexpr static const char* name = "puppiCA15Jets/area";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.area);
      return output;
    }
  };

  template <>
  struct plotter <584> {
    constexpr static const char* name = "puppiCA15Jets/nef";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.nef);
      return output;
    }
  };

  template <>
  struct plotter <585> {
    constexpr static const char* name = "puppiCA15Jets/htt_mass";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.htt_mass);
      return output;
    }
  };

  template <>
  struct plotter <586> {
    constexpr static const char* name = "puppiCA15Jets/ptCorrDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.ptCorrDown);
      return output;
    }
  };

  template <>
  struct plotter <587> {
    constexpr static const char* name = "puppiCA15Jets/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <588> {
    constexpr static const char* name = "puppiCA15Jets/tau2";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.tau2);
      return output;
    }
  };

  template <>
  struct plotter <589> {
    constexpr static const char* name = "puppiCA15Jets/tau3";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.tau3);
      return output;
    }
  };

  template <>
  struct plotter <590> {
    constexpr static const char* name = "puppiCA15Jets/puid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.puid);
      return output;
    }
  };

  template <>
  struct plotter <591> {
    constexpr static const char* name = "puppiCA15Jets/tau1";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.tau1);
      return output;
    }
  };

  template <>
  struct plotter <592> {
    constexpr static const char* name = "puppiCA15Jets/mSD";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.mSD);
      return output;
    }
  };

  template <>
  struct plotter <593> {
    constexpr static const char* name = "puppiCA15Jets/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <594> {
    constexpr static const char* name = "puppiCA15Jets/deepCMVAcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.deepCMVAcc);
      return output;
    }
  };

  template <>
  struct plotter <595> {
    constexpr static const char* name = "puppiCA15Jets/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <596> {
    constexpr static const char* name = "puppiCA15Jets/rawPt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.rawPt);
      return output;
    }
  };

  template <>
  struct plotter <597> {
    constexpr static const char* name = "puppiCA15Jets/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <598> {
    constexpr static const char* name = "puppiCA15Jets/double_sub";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.double_sub);
      return output;
    }
  };

  template <>
  struct plotter <599> {
    constexpr static const char* name = "puppiCA15Jets/loose";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.loose);
      return output;
    }
  };

  template <>
  struct plotter <600> {
    constexpr static const char* name = "puppiCA15Jets/ptSmear";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.ptSmear);
      return output;
    }
  };

  template <>
  struct plotter <601> {
    constexpr static const char* name = "puppiCA15Jets/deepCMVAc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.deepCMVAc);
      return output;
    }
  };

  template <>
  struct plotter <602> {
    constexpr static const char* name = "puppiCA15Jets/qgl";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.qgl);
      return output;
    }
  };

  template <>
  struct plotter <603> {
    constexpr static const char* name = "puppiCA15Jets/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <604> {
    constexpr static const char* name = "puppiCA15Jets/monojet";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.monojet);
      return output;
    }
  };

  template <>
  struct plotter <605> {
    constexpr static const char* name = "puppiCA15Jets/ptSmearDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.ptSmearDown);
      return output;
    }
  };

  template <>
  struct plotter <606> {
    constexpr static const char* name = "puppiCA15Jets/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <607> {
    constexpr static const char* name = "puppiCA15Jets/mPruned";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.mPruned);
      return output;
    }
  };

  template <>
  struct plotter <608> {
    constexpr static const char* name = "puppiCA15Jets/tau1SD";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.tau1SD);
      return output;
    }
  };

  template <>
  struct plotter <609> {
    constexpr static const char* name = "puppiCA15Jets/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <610> {
    constexpr static const char* name = "puppiCA15Jets/tightLepVeto";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.tightLepVeto);
      return output;
    }
  };

  template <>
  struct plotter <611> {
    constexpr static const char* name = "puppiCA15Jets/deepCSVb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.deepCSVb);
      return output;
    }
  };

  template <>
  struct plotter <612> {
    constexpr static const char* name = "puppiCA15Jets/deepCSVc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.deepCSVc);
      return output;
    }
  };

  template <>
  struct plotter <613> {
    constexpr static const char* name = "puppiCA15Jets/tau3SD";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.tau3SD);
      return output;
    }
  };

  template <>
  struct plotter <614> {
    constexpr static const char* name = "puppiCA15Jets/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <615> {
    constexpr static const char* name = "puppiCA15Jets/deepCSVcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.deepCSVcc);
      return output;
    }
  };

  template <>
  struct plotter <616> {
    constexpr static const char* name = "puppiCA15Jets/tau2SD";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.tau2SD);
      return output;
    }
  };

  template <>
  struct plotter <617> {
    constexpr static const char* name = "puppiCA15Jets/csv";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.csv);
      return output;
    }
  };

  template <>
  struct plotter <618> {
    constexpr static const char* name = "puppiCA15Jets/ptSmearUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Jets)
        output.push_back(i.ptSmearUp);
      return output;
    }
  };

  template <>
  struct plotter <619> {
    constexpr static const char* name = "puppiCA15Subjets/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.puppiCA15Subjets.size())};
      return output;
    }
  };

  template <>
  struct plotter <620> {
    constexpr static const char* name = "puppiCA15Subjets/deepCMVAudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.deepCMVAudsg);
      return output;
    }
  };

  template <>
  struct plotter <621> {
    constexpr static const char* name = "puppiCA15Subjets/deepCMVAbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.deepCMVAbb);
      return output;
    }
  };

  template <>
  struct plotter <622> {
    constexpr static const char* name = "puppiCA15Subjets/deepCSVudsg";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.deepCSVudsg);
      return output;
    }
  };

  template <>
  struct plotter <623> {
    constexpr static const char* name = "puppiCA15Subjets/cmva";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.cmva);
      return output;
    }
  };

  template <>
  struct plotter <624> {
    constexpr static const char* name = "puppiCA15Subjets/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <625> {
    constexpr static const char* name = "puppiCA15Subjets/deepCSVbb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.deepCSVbb);
      return output;
    }
  };

  template <>
  struct plotter <626> {
    constexpr static const char* name = "puppiCA15Subjets/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <627> {
    constexpr static const char* name = "puppiCA15Subjets/deepCMVAb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.deepCMVAb);
      return output;
    }
  };

  template <>
  struct plotter <628> {
    constexpr static const char* name = "puppiCA15Subjets/deepCMVAc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.deepCMVAc);
      return output;
    }
  };

  template <>
  struct plotter <629> {
    constexpr static const char* name = "puppiCA15Subjets/qgl";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.qgl);
      return output;
    }
  };

  template <>
  struct plotter <630> {
    constexpr static const char* name = "puppiCA15Subjets/csv";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.csv);
      return output;
    }
  };

  template <>
  struct plotter <631> {
    constexpr static const char* name = "puppiCA15Subjets/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <632> {
    constexpr static const char* name = "puppiCA15Subjets/deepCMVAcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.deepCMVAcc);
      return output;
    }
  };

  template <>
  struct plotter <633> {
    constexpr static const char* name = "puppiCA15Subjets/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <634> {
    constexpr static const char* name = "puppiCA15Subjets/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <635> {
    constexpr static const char* name = "puppiCA15Subjets/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <636> {
    constexpr static const char* name = "puppiCA15Subjets/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <637> {
    constexpr static const char* name = "puppiCA15Subjets/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <638> {
    constexpr static const char* name = "puppiCA15Subjets/deepCSVb";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.deepCSVb);
      return output;
    }
  };

  template <>
  struct plotter <639> {
    constexpr static const char* name = "puppiCA15Subjets/deepCSVc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.deepCSVc);
      return output;
    }
  };

  template <>
  struct plotter <640> {
    constexpr static const char* name = "puppiCA15Subjets/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <641> {
    constexpr static const char* name = "puppiCA15Subjets/deepCSVcc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.puppiCA15Subjets)
        output.push_back(i.deepCSVcc);
      return output;
    }
  };

  template <>
  struct plotter <642> {
    constexpr static const char* name = "ak4GenJets/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.ak4GenJets.size())};
      return output;
    }
  };

  template <>
  struct plotter <643> {
    constexpr static const char* name = "ak4GenJets/matchedBHadrons_size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak4GenJets)
        output.push_back(i.matchedBHadrons.size());
      return output;
    }
  };

  template <>
  struct plotter <644> {
    constexpr static const char* name = "ak4GenJets/matchedCHadrons_size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak4GenJets)
        output.push_back(i.matchedCHadrons.size());
      return output;
    }
  };

  template <>
  struct plotter <645> {
    constexpr static const char* name = "ak4GenJets/partonFlavor";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak4GenJets)
        output.push_back(i.partonFlavor);
      return output;
    }
  };

  template <>
  struct plotter <646> {
    constexpr static const char* name = "ak4GenJets/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak4GenJets)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <647> {
    constexpr static const char* name = "ak4GenJets/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak4GenJets)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <648> {
    constexpr static const char* name = "ak4GenJets/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak4GenJets)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <649> {
    constexpr static const char* name = "ak4GenJets/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak4GenJets)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <650> {
    constexpr static const char* name = "ak4GenJets/pdgid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak4GenJets)
        output.push_back(i.pdgid);
      return output;
    }
  };

  template <>
  struct plotter <651> {
    constexpr static const char* name = "ak4GenJets/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak4GenJets)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <652> {
    constexpr static const char* name = "ak4GenJets/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak4GenJets)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <653> {
    constexpr static const char* name = "ak4GenJets/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak4GenJets)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <654> {
    constexpr static const char* name = "ak4GenJets/numB";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak4GenJets)
        output.push_back(i.numB);
      return output;
    }
  };

  template <>
  struct plotter <655> {
    constexpr static const char* name = "ak4GenJets/numC";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak4GenJets)
        output.push_back(i.numC);
      return output;
    }
  };

  template <>
  struct plotter <656> {
    constexpr static const char* name = "ak4GenJets/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak4GenJets)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <657> {
    constexpr static const char* name = "ak4GenJets/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak4GenJets)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <658> {
    constexpr static const char* name = "ak8GenJets/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.ak8GenJets.size())};
      return output;
    }
  };

  template <>
  struct plotter <659> {
    constexpr static const char* name = "ak8GenJets/matchedBHadrons_size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak8GenJets)
        output.push_back(i.matchedBHadrons.size());
      return output;
    }
  };

  template <>
  struct plotter <660> {
    constexpr static const char* name = "ak8GenJets/matchedCHadrons_size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak8GenJets)
        output.push_back(i.matchedCHadrons.size());
      return output;
    }
  };

  template <>
  struct plotter <661> {
    constexpr static const char* name = "ak8GenJets/partonFlavor";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak8GenJets)
        output.push_back(i.partonFlavor);
      return output;
    }
  };

  template <>
  struct plotter <662> {
    constexpr static const char* name = "ak8GenJets/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak8GenJets)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <663> {
    constexpr static const char* name = "ak8GenJets/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak8GenJets)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <664> {
    constexpr static const char* name = "ak8GenJets/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak8GenJets)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <665> {
    constexpr static const char* name = "ak8GenJets/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak8GenJets)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <666> {
    constexpr static const char* name = "ak8GenJets/pdgid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak8GenJets)
        output.push_back(i.pdgid);
      return output;
    }
  };

  template <>
  struct plotter <667> {
    constexpr static const char* name = "ak8GenJets/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak8GenJets)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <668> {
    constexpr static const char* name = "ak8GenJets/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak8GenJets)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <669> {
    constexpr static const char* name = "ak8GenJets/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak8GenJets)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <670> {
    constexpr static const char* name = "ak8GenJets/numB";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak8GenJets)
        output.push_back(i.numB);
      return output;
    }
  };

  template <>
  struct plotter <671> {
    constexpr static const char* name = "ak8GenJets/numC";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak8GenJets)
        output.push_back(i.numC);
      return output;
    }
  };

  template <>
  struct plotter <672> {
    constexpr static const char* name = "ak8GenJets/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak8GenJets)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <673> {
    constexpr static const char* name = "ak8GenJets/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ak8GenJets)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <674> {
    constexpr static const char* name = "ca15GenJets/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.ca15GenJets.size())};
      return output;
    }
  };

  template <>
  struct plotter <675> {
    constexpr static const char* name = "ca15GenJets/matchedBHadrons_size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ca15GenJets)
        output.push_back(i.matchedBHadrons.size());
      return output;
    }
  };

  template <>
  struct plotter <676> {
    constexpr static const char* name = "ca15GenJets/matchedCHadrons_size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ca15GenJets)
        output.push_back(i.matchedCHadrons.size());
      return output;
    }
  };

  template <>
  struct plotter <677> {
    constexpr static const char* name = "ca15GenJets/partonFlavor";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ca15GenJets)
        output.push_back(i.partonFlavor);
      return output;
    }
  };

  template <>
  struct plotter <678> {
    constexpr static const char* name = "ca15GenJets/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ca15GenJets)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <679> {
    constexpr static const char* name = "ca15GenJets/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ca15GenJets)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <680> {
    constexpr static const char* name = "ca15GenJets/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ca15GenJets)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <681> {
    constexpr static const char* name = "ca15GenJets/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ca15GenJets)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <682> {
    constexpr static const char* name = "ca15GenJets/pdgid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ca15GenJets)
        output.push_back(i.pdgid);
      return output;
    }
  };

  template <>
  struct plotter <683> {
    constexpr static const char* name = "ca15GenJets/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ca15GenJets)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <684> {
    constexpr static const char* name = "ca15GenJets/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ca15GenJets)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <685> {
    constexpr static const char* name = "ca15GenJets/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ca15GenJets)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <686> {
    constexpr static const char* name = "ca15GenJets/numB";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ca15GenJets)
        output.push_back(i.numB);
      return output;
    }
  };

  template <>
  struct plotter <687> {
    constexpr static const char* name = "ca15GenJets/numC";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ca15GenJets)
        output.push_back(i.numC);
      return output;
    }
  };

  template <>
  struct plotter <688> {
    constexpr static const char* name = "ca15GenJets/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ca15GenJets)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <689> {
    constexpr static const char* name = "ca15GenJets/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.ca15GenJets)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <690> {
    constexpr static const char* name = "genParticles/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.genParticles.size())};
      return output;
    }
  };

  template <>
  struct plotter <691> {
    constexpr static const char* name = "genParticles/parent_isValid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.genParticles)
        output.push_back(i.parent.isValid());
      return output;
    }
  };

  template <>
  struct plotter <692> {
    constexpr static const char* name = "genParticles/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.genParticles)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <693> {
    constexpr static const char* name = "genParticles/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.genParticles)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <694> {
    constexpr static const char* name = "genParticles/statusFlags";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.genParticles)
        output.push_back(i.statusFlags);
      return output;
    }
  };

  template <>
  struct plotter <695> {
    constexpr static const char* name = "genParticles/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.genParticles)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <696> {
    constexpr static const char* name = "genParticles/pdgid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.genParticles)
        output.push_back(i.pdgid);
      return output;
    }
  };

  template <>
  struct plotter <697> {
    constexpr static const char* name = "genParticles/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.genParticles)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <698> {
    constexpr static const char* name = "genParticles/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.genParticles)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <699> {
    constexpr static const char* name = "genParticles/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.genParticles)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <700> {
    constexpr static const char* name = "genParticles/finalState";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.genParticles)
        output.push_back(i.finalState);
      return output;
    }
  };

  template <>
  struct plotter <701> {
    constexpr static const char* name = "genParticles/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.genParticles)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <702> {
    constexpr static const char* name = "genParticles/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.genParticles)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <703> {
    constexpr static const char* name = "genParticles/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.genParticles)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <704> {
    constexpr static const char* name = "genVertex/y";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.genVertex.y)};
      return output;
    }
  };

  template <>
  struct plotter <705> {
    constexpr static const char* name = "genVertex/x";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.genVertex.x)};
      return output;
    }
  };

  template <>
  struct plotter <706> {
    constexpr static const char* name = "genVertex/z";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.genVertex.z)};
      return output;
    }
  };

  template <>
  struct plotter <707> {
    constexpr static const char* name = "partons/size";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.partons.size())};
      return output;
    }
  };

  template <>
  struct plotter <708> {
    constexpr static const char* name = "partons/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.partons)
        output.push_back(i.pt());
      return output;
    }
  };

  template <>
  struct plotter <709> {
    constexpr static const char* name = "partons/p";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.partons)
        output.push_back(i.p());
      return output;
    }
  };

  template <>
  struct plotter <710> {
    constexpr static const char* name = "partons/eta";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.partons)
        output.push_back(i.eta());
      return output;
    }
  };

  template <>
  struct plotter <711> {
    constexpr static const char* name = "partons/m";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.partons)
        output.push_back(i.m());
      return output;
    }
  };

  template <>
  struct plotter <712> {
    constexpr static const char* name = "partons/pdgid";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.partons)
        output.push_back(i.pdgid);
      return output;
    }
  };

  template <>
  struct plotter <713> {
    constexpr static const char* name = "partons/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.partons)
        output.push_back(i.phi());
      return output;
    }
  };

  template <>
  struct plotter <714> {
    constexpr static const char* name = "partons/pz";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.partons)
        output.push_back(i.pz());
      return output;
    }
  };

  template <>
  struct plotter <715> {
    constexpr static const char* name = "partons/py";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.partons)
        output.push_back(i.py());
      return output;
    }
  };

  template <>
  struct plotter <716> {
    constexpr static const char* name = "partons/px";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.partons)
        output.push_back(i.px());
      return output;
    }
  };

  template <>
  struct plotter <717> {
    constexpr static const char* name = "partons/e";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output;
      for (auto& i : event.partons)
        output.push_back(i.e());
      return output;
    }
  };

  template <>
  struct plotter <718> {
    constexpr static const char* name = "pfMet/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.pfMet.phi)};
      return output;
    }
  };

  template <>
  struct plotter <719> {
    constexpr static const char* name = "pfMet/phiUnclUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.pfMet.phiUnclUp)};
      return output;
    }
  };

  template <>
  struct plotter <720> {
    constexpr static const char* name = "pfMet/sumETRaw";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.pfMet.sumETRaw)};
      return output;
    }
  };

  template <>
  struct plotter <721> {
    constexpr static const char* name = "pfMet/ptCorrUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.pfMet.ptCorrUp)};
      return output;
    }
  };

  template <>
  struct plotter <722> {
    constexpr static const char* name = "pfMet/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.pfMet.pt)};
      return output;
    }
  };

  template <>
  struct plotter <723> {
    constexpr static const char* name = "pfMet/ptCorrDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.pfMet.ptCorrDown)};
      return output;
    }
  };

  template <>
  struct plotter <724> {
    constexpr static const char* name = "pfMet/phiCorrUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.pfMet.phiCorrUp)};
      return output;
    }
  };

  template <>
  struct plotter <725> {
    constexpr static const char* name = "pfMet/phiUnclDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.pfMet.phiUnclDown)};
      return output;
    }
  };

  template <>
  struct plotter <726> {
    constexpr static const char* name = "pfMet/ptUnclDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.pfMet.ptUnclDown)};
      return output;
    }
  };

  template <>
  struct plotter <727> {
    constexpr static const char* name = "pfMet/significance";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.pfMet.significance)};
      return output;
    }
  };

  template <>
  struct plotter <728> {
    constexpr static const char* name = "pfMet/phiCorrDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.pfMet.phiCorrDown)};
      return output;
    }
  };

  template <>
  struct plotter <729> {
    constexpr static const char* name = "pfMet/ptUnclUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.pfMet.ptUnclUp)};
      return output;
    }
  };

  template <>
  struct plotter <730> {
    constexpr static const char* name = "puppiMet/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.puppiMet.phi)};
      return output;
    }
  };

  template <>
  struct plotter <731> {
    constexpr static const char* name = "puppiMet/phiUnclUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.puppiMet.phiUnclUp)};
      return output;
    }
  };

  template <>
  struct plotter <732> {
    constexpr static const char* name = "puppiMet/sumETRaw";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.puppiMet.sumETRaw)};
      return output;
    }
  };

  template <>
  struct plotter <733> {
    constexpr static const char* name = "puppiMet/ptCorrUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.puppiMet.ptCorrUp)};
      return output;
    }
  };

  template <>
  struct plotter <734> {
    constexpr static const char* name = "puppiMet/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.puppiMet.pt)};
      return output;
    }
  };

  template <>
  struct plotter <735> {
    constexpr static const char* name = "puppiMet/ptCorrDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.puppiMet.ptCorrDown)};
      return output;
    }
  };

  template <>
  struct plotter <736> {
    constexpr static const char* name = "puppiMet/phiCorrUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.puppiMet.phiCorrUp)};
      return output;
    }
  };

  template <>
  struct plotter <737> {
    constexpr static const char* name = "puppiMet/phiUnclDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.puppiMet.phiUnclDown)};
      return output;
    }
  };

  template <>
  struct plotter <738> {
    constexpr static const char* name = "puppiMet/ptUnclDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.puppiMet.ptUnclDown)};
      return output;
    }
  };

  template <>
  struct plotter <739> {
    constexpr static const char* name = "puppiMet/significance";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.puppiMet.significance)};
      return output;
    }
  };

  template <>
  struct plotter <740> {
    constexpr static const char* name = "puppiMet/phiCorrDown";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.puppiMet.phiCorrDown)};
      return output;
    }
  };

  template <>
  struct plotter <741> {
    constexpr static const char* name = "puppiMet/ptUnclUp";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.puppiMet.ptUnclUp)};
      return output;
    }
  };

  template <>
  struct plotter <742> {
    constexpr static const char* name = "rawMet/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.rawMet.phi)};
      return output;
    }
  };

  template <>
  struct plotter <743> {
    constexpr static const char* name = "rawMet/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.rawMet.pt)};
      return output;
    }
  };

  template <>
  struct plotter <744> {
    constexpr static const char* name = "caloMet/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.caloMet.phi)};
      return output;
    }
  };

  template <>
  struct plotter <745> {
    constexpr static const char* name = "caloMet/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.caloMet.pt)};
      return output;
    }
  };

  template <>
  struct plotter <746> {
    constexpr static const char* name = "noMuMet/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.noMuMet.phi)};
      return output;
    }
  };

  template <>
  struct plotter <747> {
    constexpr static const char* name = "noMuMet/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.noMuMet.pt)};
      return output;
    }
  };

  template <>
  struct plotter <748> {
    constexpr static const char* name = "noHFMet/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.noHFMet.phi)};
      return output;
    }
  };

  template <>
  struct plotter <749> {
    constexpr static const char* name = "noHFMet/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.noHFMet.pt)};
      return output;
    }
  };

  template <>
  struct plotter <750> {
    constexpr static const char* name = "trkMet/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.trkMet.phi)};
      return output;
    }
  };

  template <>
  struct plotter <751> {
    constexpr static const char* name = "trkMet/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.trkMet.pt)};
      return output;
    }
  };

  template <>
  struct plotter <752> {
    constexpr static const char* name = "neutralMet/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.neutralMet.phi)};
      return output;
    }
  };

  template <>
  struct plotter <753> {
    constexpr static const char* name = "neutralMet/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.neutralMet.pt)};
      return output;
    }
  };

  template <>
  struct plotter <754> {
    constexpr static const char* name = "photonMet/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.photonMet.phi)};
      return output;
    }
  };

  template <>
  struct plotter <755> {
    constexpr static const char* name = "photonMet/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.photonMet.pt)};
      return output;
    }
  };

  template <>
  struct plotter <756> {
    constexpr static const char* name = "hfMet/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.hfMet.phi)};
      return output;
    }
  };

  template <>
  struct plotter <757> {
    constexpr static const char* name = "hfMet/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.hfMet.pt)};
      return output;
    }
  };

  template <>
  struct plotter <758> {
    constexpr static const char* name = "genMet/phi";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.genMet.phi)};
      return output;
    }
  };

  template <>
  struct plotter <759> {
    constexpr static const char* name = "genMet/pt";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.genMet.pt)};
      return output;
    }
  };

  template <>
  struct plotter <760> {
    constexpr static const char* name = "metFilters/duplicateMuons";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.metFilters.duplicateMuons)};
      return output;
    }
  };

  template <>
  struct plotter <761> {
    constexpr static const char* name = "metFilters/badMuons";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.metFilters.badMuons)};
      return output;
    }
  };

  template <>
  struct plotter <762> {
    constexpr static const char* name = "metFilters/globalHalo16";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.metFilters.globalHalo16)};
      return output;
    }
  };

  template <>
  struct plotter <763> {
    constexpr static const char* name = "metFilters/badsc";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.metFilters.badsc)};
      return output;
    }
  };

  template <>
  struct plotter <764> {
    constexpr static const char* name = "metFilters/hbheIso";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.metFilters.hbheIso)};
      return output;
    }
  };

  template <>
  struct plotter <765> {
    constexpr static const char* name = "metFilters/hbhe";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.metFilters.hbhe)};
      return output;
    }
  };

  template <>
  struct plotter <766> {
    constexpr static const char* name = "metFilters/badPFMuons";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.metFilters.badPFMuons)};
      return output;
    }
  };

  template <>
  struct plotter <767> {
    constexpr static const char* name = "metFilters/goodVertices";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.metFilters.goodVertices)};
      return output;
    }
  };

  template <>
  struct plotter <768> {
    constexpr static const char* name = "metFilters/ecalDeadCell";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.metFilters.ecalDeadCell)};
      return output;
    }
  };

  template <>
  struct plotter <769> {
    constexpr static const char* name = "metFilters/badChargedHadrons";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.metFilters.badChargedHadrons)};
      return output;
    }
  };

  template <>
  struct plotter <770> {
    constexpr static const char* name = "metFilters/pass";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.metFilters.pass())};
      return output;
    }
  };

  template <>
  struct plotter <771> {
    constexpr static const char* name = "metFilters/ecalBadCalib";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.metFilters.ecalBadCalib)};
      return output;
    }
  };

  template <>
  struct plotter <772> {
    constexpr static const char* name = "recoil/max";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.recoil.max)};
      return output;
    }
  };

  template <>
  struct plotter <773> {
    constexpr static const char* name = "recoil/monoE";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.recoil.monoE)};
      return output;
    }
  };

  template <>
  struct plotter <774> {
    constexpr static const char* name = "recoil/diE";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.recoil.diE)};
      return output;
    }
  };

  template <>
  struct plotter <775> {
    constexpr static const char* name = "recoil/monoMu";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.recoil.monoMu)};
      return output;
    }
  };

  template <>
  struct plotter <776> {
    constexpr static const char* name = "recoil/met";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.recoil.met)};
      return output;
    }
  };

  template <>
  struct plotter <777> {
    constexpr static const char* name = "recoil/diMu";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.recoil.diMu)};
      return output;
    }
  };

  template <>
  struct plotter <778> {
    constexpr static const char* name = "recoil/any";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.recoil.any())};
      return output;
    }
  };

  template <>
  struct plotter <779> {
    constexpr static const char* name = "recoil/gamma";
    std::vector<float> operator () (panda::Event& event) {
      std::vector<float> output {float(event.recoil.gamma)};
      return output;
    }
  };

#define NUM_PLOTS 780

};

#endif
