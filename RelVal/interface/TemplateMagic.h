#ifndef THATSBAD
#define THATSBAD 1

// This let's us loop over the branches with various fillers

#include <vector>
#include <functional>

#include "PandaTree/Objects/interface/Event.h"
#include "PandaTree/RelVal/interface/EnumerateBranches.h"

// Call the filler and then call the next branch

template <int P>
struct plot_looper {
  void operator () 
    (panda::Event& event,
     std::function<void(int, std::vector<float>)>& filler) {
    filler(P, plotter<P>()(event)); plot_looper<P + 1>()(event, filler);
  };
};

// Have to terminate at some point

template <>
struct plot_looper<panda_plots::PLOTS_SIZE> {
  void operator ()
    (panda::Event&,
     std::function<void(int, std::vector<float>)>&) { };
};

#endif
