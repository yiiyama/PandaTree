#ifndef IWILLSEEYOULATER
#define IWILLSEEYOULATER 1

#include <vector>
#include "PandaTree/Objects/interface/Event.h"


template <int P>
struct plotter {
  constexpr static const char* name = nullptr;
};


// The following should be automatically generated


template <>
struct plotter <0> {
  constexpr static const char* name = "common/npv";
  std::vector<float> operator () (panda::Event& event) {
    std::vector<float> output {float(event.npv)};
    return output;
  }
};

template <>
struct plotter <1> {
  constexpr static const char* name = "electrons/pt";
  std::vector<float> operator () (panda::Event& event) {
    std::vector<float> output;
    for (auto& i : event.electrons)
      output.push_back(i.pt());
    return output;
  }
};

template <>
struct plotter <2> {
  constexpr static const char* name = "electrons/eta";
  std::vector<float> operator () (panda::Event& event) {
    std::vector<float> output;
    for (auto& i : event.electrons)
      output.push_back(i.eta());
    return output;
  }
};

template <>
struct plotter <3> {
  constexpr static const char* name = "electrons/r9";
  std::vector<float> operator () (panda::Event& event) {
    std::vector<float> output;
    for (auto& i : event.electrons)
      output.push_back(i.r9);
    return output;
  }
};

template <>
struct plotter <4> {
  constexpr static const char* name = "pfCandidates/pt";
  std::vector<float> operator () (panda::Event& event) {
    std::vector<float> output;
    for (auto& i : event.pfCandidates)
      output.push_back(i.pt());
    return output;
  }
};

#define NUM_PLOTS 5


// End automatic generation


#endif
