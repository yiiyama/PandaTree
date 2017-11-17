#ifndef IWILLSEEYOULATER
#define IWILLSEEYOULATER 1

#include <map>
#include <string>
#include <array>
#include <vector>

#include "PandaTree/Objects/interface/Event.h"

// This has to match the length of the vector
#define NUM_PLOTS 4

const std::vector<std::string> panda_plot_names = {
  "electrons/pt",
  "electrons/eta",
  "electrons/r9",
  "pfCandidates/pt"
};

template <int P>
struct plotter {};

template <>
struct plotter <0> {
  std::vector<float> operator () (panda::Event& event) {
    std::vector<float> output;
    for (auto& i : event.electrons)
      output.push_back(i.pt());
    return output;
  }
};

template <>
struct plotter <1> {
  std::vector<float> operator () (panda::Event& event) {
    std::vector<float> output;
    for (auto& i : event.electrons)
      output.push_back(i.eta());
    return output;
  }
};

template <>
struct plotter <2> {
  std::vector<float> operator () (panda::Event& event) {
    std::vector<float> output;
    for (auto& i : event.electrons)
      output.push_back(i.r9);
    return output;
  }
};

template <>
struct plotter <3> {
  std::vector<float> operator () (panda::Event& event) {
    std::vector<float> output;
    for (auto& i : event.pfCandidates)
      output.push_back(i.pt());
    return output;
  }
};

#endif
