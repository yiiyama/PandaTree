#ifndef IWILLSEEYOULATER
#define IWILLSEEYOULATER 1

#include <vector>
#include "PandaTree/Objects/interface/Event.h"


template <int P>
struct plotter {
  constexpr static const char* name = nullptr;
};


template <>
struct plotter <0> {
  constexpr static const char* name = "pfCandidates/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.pfCandidates)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <1> {
  constexpr static const char* name = "pfCandidates/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.pfCandidates)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <2> {
  constexpr static const char* name = "pfCandidates/puppiWNoLep";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.pfCandidates)
      output.push_back(i.puppiWNoLep());

    return output;
  }
};


template <>
struct plotter <3> {
  constexpr static const char* name = "pfCandidates/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.pfCandidates)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <4> {
  constexpr static const char* name = "pfCandidates/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.pfCandidates)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <5> {
  constexpr static const char* name = "pfCandidates/pdgId";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.pfCandidates)
      output.push_back(i.pdgId());

    return output;
  }
};


template <>
struct plotter <6> {
  constexpr static const char* name = "pfCandidates/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.pfCandidates)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <7> {
  constexpr static const char* name = "pfCandidates/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.pfCandidates)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <8> {
  constexpr static const char* name = "pfCandidates/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.pfCandidates)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <9> {
  constexpr static const char* name = "pfCandidates/q";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.pfCandidates)
      output.push_back(i.q());

    return output;
  }
};


template <>
struct plotter <10> {
  constexpr static const char* name = "pfCandidates/puppiW";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.pfCandidates)
      output.push_back(i.puppiW());

    return output;
  }
};


template <>
struct plotter <11> {
  constexpr static const char* name = "pfCandidates/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.pfCandidates)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <12> {
  constexpr static const char* name = "pfCandidates/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.pfCandidates)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <13> {
  constexpr static const char* name = "vertices/normChi2";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.vertices)
      output.push_back(i.normChi2());

    return output;
  }
};


template <>
struct plotter <14> {
  constexpr static const char* name = "secondaryVertices/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.secondaryVertices)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <15> {
  constexpr static const char* name = "secondaryVertices/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.secondaryVertices)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <16> {
  constexpr static const char* name = "secondaryVertices/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.secondaryVertices)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <17> {
  constexpr static const char* name = "secondaryVertices/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.secondaryVertices)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <18> {
  constexpr static const char* name = "secondaryVertices/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.secondaryVertices)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <19> {
  constexpr static const char* name = "secondaryVertices/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.secondaryVertices)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <20> {
  constexpr static const char* name = "secondaryVertices/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.secondaryVertices)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <21> {
  constexpr static const char* name = "secondaryVertices/normChi2";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.secondaryVertices)
      output.push_back(i.normChi2());

    return output;
  }
};


template <>
struct plotter <22> {
  constexpr static const char* name = "secondaryVertices/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.secondaryVertices)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <23> {
  constexpr static const char* name = "secondaryVertices/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.secondaryVertices)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <24> {
  constexpr static const char* name = "tracks/dxy";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.tracks)
      output.push_back(i.dxy());

    return output;
  }
};


template <>
struct plotter <25> {
  constexpr static const char* name = "tracks/dPhi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.tracks)
      output.push_back(i.dPhi());

    return output;
  }
};


template <>
struct plotter <26> {
  constexpr static const char* name = "tracks/dz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.tracks)
      output.push_back(i.dz());

    return output;
  }
};


template <>
struct plotter <27> {
  constexpr static const char* name = "tracks/ptError";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.tracks)
      output.push_back(i.ptError());

    return output;
  }
};


template <>
struct plotter <28> {
  constexpr static const char* name = "electrons/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.electrons)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <29> {
  constexpr static const char* name = "electrons/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.electrons)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <30> {
  constexpr static const char* name = "electrons/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.electrons)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <31> {
  constexpr static const char* name = "electrons/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.electrons)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <32> {
  constexpr static const char* name = "electrons/combIso";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.electrons)
      output.push_back(i.combIso());

    return output;
  }
};


template <>
struct plotter <33> {
  constexpr static const char* name = "electrons/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.electrons)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <34> {
  constexpr static const char* name = "electrons/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.electrons)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <35> {
  constexpr static const char* name = "electrons/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.electrons)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <36> {
  constexpr static const char* name = "electrons/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.electrons)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <37> {
  constexpr static const char* name = "electrons/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.electrons)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <38> {
  constexpr static const char* name = "muons/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.muons)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <39> {
  constexpr static const char* name = "muons/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.muons)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <40> {
  constexpr static const char* name = "muons/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.muons)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <41> {
  constexpr static const char* name = "muons/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.muons)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <42> {
  constexpr static const char* name = "muons/combIso";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.muons)
      output.push_back(i.combIso());

    return output;
  }
};


template <>
struct plotter <43> {
  constexpr static const char* name = "muons/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.muons)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <44> {
  constexpr static const char* name = "muons/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.muons)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <45> {
  constexpr static const char* name = "muons/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.muons)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <46> {
  constexpr static const char* name = "muons/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.muons)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <47> {
  constexpr static const char* name = "muons/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.muons)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <48> {
  constexpr static const char* name = "taus/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.taus)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <49> {
  constexpr static const char* name = "taus/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.taus)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <50> {
  constexpr static const char* name = "taus/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.taus)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <51> {
  constexpr static const char* name = "taus/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.taus)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <52> {
  constexpr static const char* name = "taus/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.taus)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <53> {
  constexpr static const char* name = "taus/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.taus)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <54> {
  constexpr static const char* name = "taus/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.taus)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <55> {
  constexpr static const char* name = "taus/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.taus)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <56> {
  constexpr static const char* name = "taus/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.taus)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <57> {
  constexpr static const char* name = "photons/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.photons)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <58> {
  constexpr static const char* name = "photons/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.photons)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <59> {
  constexpr static const char* name = "photons/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.photons)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <60> {
  constexpr static const char* name = "photons/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.photons)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <61> {
  constexpr static const char* name = "photons/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.photons)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <62> {
  constexpr static const char* name = "photons/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.photons)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <63> {
  constexpr static const char* name = "photons/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.photons)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <64> {
  constexpr static const char* name = "photons/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.photons)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <65> {
  constexpr static const char* name = "photons/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.photons)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <66> {
  constexpr static const char* name = "chsAK4Jets/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK4Jets)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <67> {
  constexpr static const char* name = "chsAK4Jets/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK4Jets)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <68> {
  constexpr static const char* name = "chsAK4Jets/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK4Jets)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <69> {
  constexpr static const char* name = "chsAK4Jets/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK4Jets)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <70> {
  constexpr static const char* name = "chsAK4Jets/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK4Jets)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <71> {
  constexpr static const char* name = "chsAK4Jets/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK4Jets)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <72> {
  constexpr static const char* name = "chsAK4Jets/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK4Jets)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <73> {
  constexpr static const char* name = "chsAK4Jets/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK4Jets)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <74> {
  constexpr static const char* name = "chsAK4Jets/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK4Jets)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <75> {
  constexpr static const char* name = "puppiAK4Jets/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK4Jets)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <76> {
  constexpr static const char* name = "puppiAK4Jets/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK4Jets)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <77> {
  constexpr static const char* name = "puppiAK4Jets/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK4Jets)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <78> {
  constexpr static const char* name = "puppiAK4Jets/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK4Jets)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <79> {
  constexpr static const char* name = "puppiAK4Jets/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK4Jets)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <80> {
  constexpr static const char* name = "puppiAK4Jets/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK4Jets)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <81> {
  constexpr static const char* name = "puppiAK4Jets/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK4Jets)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <82> {
  constexpr static const char* name = "puppiAK4Jets/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK4Jets)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <83> {
  constexpr static const char* name = "puppiAK4Jets/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK4Jets)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <84> {
  constexpr static const char* name = "chsAK8Jets/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Jets)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <85> {
  constexpr static const char* name = "chsAK8Jets/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Jets)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <86> {
  constexpr static const char* name = "chsAK8Jets/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Jets)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <87> {
  constexpr static const char* name = "chsAK8Jets/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Jets)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <88> {
  constexpr static const char* name = "chsAK8Jets/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Jets)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <89> {
  constexpr static const char* name = "chsAK8Jets/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Jets)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <90> {
  constexpr static const char* name = "chsAK8Jets/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Jets)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <91> {
  constexpr static const char* name = "chsAK8Jets/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Jets)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <92> {
  constexpr static const char* name = "chsAK8Jets/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Jets)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <93> {
  constexpr static const char* name = "chsAK8Subjets/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Subjets)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <94> {
  constexpr static const char* name = "chsAK8Subjets/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Subjets)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <95> {
  constexpr static const char* name = "chsAK8Subjets/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Subjets)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <96> {
  constexpr static const char* name = "chsAK8Subjets/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Subjets)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <97> {
  constexpr static const char* name = "chsAK8Subjets/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Subjets)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <98> {
  constexpr static const char* name = "chsAK8Subjets/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Subjets)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <99> {
  constexpr static const char* name = "chsAK8Subjets/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Subjets)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <100> {
  constexpr static const char* name = "chsAK8Subjets/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Subjets)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <101> {
  constexpr static const char* name = "chsAK8Subjets/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsAK8Subjets)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <102> {
  constexpr static const char* name = "chsCA15Jets/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Jets)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <103> {
  constexpr static const char* name = "chsCA15Jets/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Jets)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <104> {
  constexpr static const char* name = "chsCA15Jets/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Jets)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <105> {
  constexpr static const char* name = "chsCA15Jets/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Jets)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <106> {
  constexpr static const char* name = "chsCA15Jets/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Jets)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <107> {
  constexpr static const char* name = "chsCA15Jets/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Jets)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <108> {
  constexpr static const char* name = "chsCA15Jets/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Jets)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <109> {
  constexpr static const char* name = "chsCA15Jets/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Jets)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <110> {
  constexpr static const char* name = "chsCA15Jets/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Jets)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <111> {
  constexpr static const char* name = "chsCA15Subjets/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Subjets)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <112> {
  constexpr static const char* name = "chsCA15Subjets/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Subjets)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <113> {
  constexpr static const char* name = "chsCA15Subjets/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Subjets)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <114> {
  constexpr static const char* name = "chsCA15Subjets/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Subjets)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <115> {
  constexpr static const char* name = "chsCA15Subjets/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Subjets)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <116> {
  constexpr static const char* name = "chsCA15Subjets/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Subjets)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <117> {
  constexpr static const char* name = "chsCA15Subjets/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Subjets)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <118> {
  constexpr static const char* name = "chsCA15Subjets/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Subjets)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <119> {
  constexpr static const char* name = "chsCA15Subjets/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.chsCA15Subjets)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <120> {
  constexpr static const char* name = "puppiAK8Jets/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Jets)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <121> {
  constexpr static const char* name = "puppiAK8Jets/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Jets)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <122> {
  constexpr static const char* name = "puppiAK8Jets/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Jets)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <123> {
  constexpr static const char* name = "puppiAK8Jets/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Jets)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <124> {
  constexpr static const char* name = "puppiAK8Jets/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Jets)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <125> {
  constexpr static const char* name = "puppiAK8Jets/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Jets)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <126> {
  constexpr static const char* name = "puppiAK8Jets/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Jets)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <127> {
  constexpr static const char* name = "puppiAK8Jets/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Jets)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <128> {
  constexpr static const char* name = "puppiAK8Jets/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Jets)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <129> {
  constexpr static const char* name = "puppiAK8Subjets/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Subjets)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <130> {
  constexpr static const char* name = "puppiAK8Subjets/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Subjets)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <131> {
  constexpr static const char* name = "puppiAK8Subjets/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Subjets)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <132> {
  constexpr static const char* name = "puppiAK8Subjets/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Subjets)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <133> {
  constexpr static const char* name = "puppiAK8Subjets/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Subjets)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <134> {
  constexpr static const char* name = "puppiAK8Subjets/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Subjets)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <135> {
  constexpr static const char* name = "puppiAK8Subjets/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Subjets)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <136> {
  constexpr static const char* name = "puppiAK8Subjets/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Subjets)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <137> {
  constexpr static const char* name = "puppiAK8Subjets/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiAK8Subjets)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <138> {
  constexpr static const char* name = "puppiCA15Jets/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Jets)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <139> {
  constexpr static const char* name = "puppiCA15Jets/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Jets)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <140> {
  constexpr static const char* name = "puppiCA15Jets/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Jets)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <141> {
  constexpr static const char* name = "puppiCA15Jets/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Jets)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <142> {
  constexpr static const char* name = "puppiCA15Jets/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Jets)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <143> {
  constexpr static const char* name = "puppiCA15Jets/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Jets)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <144> {
  constexpr static const char* name = "puppiCA15Jets/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Jets)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <145> {
  constexpr static const char* name = "puppiCA15Jets/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Jets)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <146> {
  constexpr static const char* name = "puppiCA15Jets/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Jets)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <147> {
  constexpr static const char* name = "puppiCA15Subjets/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Subjets)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <148> {
  constexpr static const char* name = "puppiCA15Subjets/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Subjets)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <149> {
  constexpr static const char* name = "puppiCA15Subjets/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Subjets)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <150> {
  constexpr static const char* name = "puppiCA15Subjets/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Subjets)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <151> {
  constexpr static const char* name = "puppiCA15Subjets/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Subjets)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <152> {
  constexpr static const char* name = "puppiCA15Subjets/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Subjets)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <153> {
  constexpr static const char* name = "puppiCA15Subjets/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Subjets)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <154> {
  constexpr static const char* name = "puppiCA15Subjets/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Subjets)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <155> {
  constexpr static const char* name = "puppiCA15Subjets/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.puppiCA15Subjets)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <156> {
  constexpr static const char* name = "ak4GenJets/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak4GenJets)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <157> {
  constexpr static const char* name = "ak4GenJets/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak4GenJets)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <158> {
  constexpr static const char* name = "ak4GenJets/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak4GenJets)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <159> {
  constexpr static const char* name = "ak4GenJets/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak4GenJets)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <160> {
  constexpr static const char* name = "ak4GenJets/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak4GenJets)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <161> {
  constexpr static const char* name = "ak4GenJets/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak4GenJets)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <162> {
  constexpr static const char* name = "ak4GenJets/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak4GenJets)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <163> {
  constexpr static const char* name = "ak4GenJets/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak4GenJets)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <164> {
  constexpr static const char* name = "ak4GenJets/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak4GenJets)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <165> {
  constexpr static const char* name = "ak8GenJets/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak8GenJets)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <166> {
  constexpr static const char* name = "ak8GenJets/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak8GenJets)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <167> {
  constexpr static const char* name = "ak8GenJets/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak8GenJets)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <168> {
  constexpr static const char* name = "ak8GenJets/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak8GenJets)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <169> {
  constexpr static const char* name = "ak8GenJets/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak8GenJets)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <170> {
  constexpr static const char* name = "ak8GenJets/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak8GenJets)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <171> {
  constexpr static const char* name = "ak8GenJets/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak8GenJets)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <172> {
  constexpr static const char* name = "ak8GenJets/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak8GenJets)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <173> {
  constexpr static const char* name = "ak8GenJets/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ak8GenJets)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <174> {
  constexpr static const char* name = "ca15GenJets/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ca15GenJets)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <175> {
  constexpr static const char* name = "ca15GenJets/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ca15GenJets)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <176> {
  constexpr static const char* name = "ca15GenJets/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ca15GenJets)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <177> {
  constexpr static const char* name = "ca15GenJets/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ca15GenJets)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <178> {
  constexpr static const char* name = "ca15GenJets/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ca15GenJets)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <179> {
  constexpr static const char* name = "ca15GenJets/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ca15GenJets)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <180> {
  constexpr static const char* name = "ca15GenJets/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ca15GenJets)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <181> {
  constexpr static const char* name = "ca15GenJets/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ca15GenJets)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <182> {
  constexpr static const char* name = "ca15GenJets/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.ca15GenJets)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <183> {
  constexpr static const char* name = "genParticles/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.genParticles)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <184> {
  constexpr static const char* name = "genParticles/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.genParticles)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <185> {
  constexpr static const char* name = "genParticles/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.genParticles)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <186> {
  constexpr static const char* name = "genParticles/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.genParticles)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <187> {
  constexpr static const char* name = "genParticles/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.genParticles)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <188> {
  constexpr static const char* name = "genParticles/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.genParticles)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <189> {
  constexpr static const char* name = "genParticles/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.genParticles)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <190> {
  constexpr static const char* name = "genParticles/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.genParticles)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <191> {
  constexpr static const char* name = "genParticles/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.genParticles)
      output.push_back(i.e());

    return output;
  }
};


template <>
struct plotter <192> {
  constexpr static const char* name = "partons/pt";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.partons)
      output.push_back(i.pt());

    return output;
  }
};


template <>
struct plotter <193> {
  constexpr static const char* name = "partons/p";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.partons)
      output.push_back(i.p());

    return output;
  }
};


template <>
struct plotter <194> {
  constexpr static const char* name = "partons/eta";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.partons)
      output.push_back(i.eta());

    return output;
  }
};


template <>
struct plotter <195> {
  constexpr static const char* name = "partons/m";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.partons)
      output.push_back(i.m());

    return output;
  }
};


template <>
struct plotter <196> {
  constexpr static const char* name = "partons/phi";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.partons)
      output.push_back(i.phi());

    return output;
  }
};


template <>
struct plotter <197> {
  constexpr static const char* name = "partons/pz";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.partons)
      output.push_back(i.pz());

    return output;
  }
};


template <>
struct plotter <198> {
  constexpr static const char* name = "partons/py";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.partons)
      output.push_back(i.py());

    return output;
  }
};


template <>
struct plotter <199> {
  constexpr static const char* name = "partons/px";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.partons)
      output.push_back(i.px());

    return output;
  }
};


template <>
struct plotter <200> {
  constexpr static const char* name = "partons/e";
  std::vector<float> operator () (panda::Event& event) {

    std::vector<float> output;
    for (auto& i : event.partons)
      output.push_back(i.e());

    return output;
  }
};

#define NUM_PLOTS 201

#endif
