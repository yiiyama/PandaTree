#ifndef IWILLSEEYOULATER
#define IWILLSEEYOULATER 1

#include <map>
#include <string>
#include <vector>

#include "PandaTree/Objects/interface/Event.h"

enum panda_plots {
  electrons_pt,
  electrons_eta,
  electrons_r9,
  PLOTS_SIZE
};

const std::vector<std::string> panda_plot_names = {
  "electrons_pt",
  "electrons_eta",
  "electrons_r9"
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

#endif
