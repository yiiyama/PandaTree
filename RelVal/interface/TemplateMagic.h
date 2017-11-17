#ifndef THATSBAD
#define THATSBAD 1

// This let's us loop over the branches with various fillers

#include <vector>
#include <functional>

#include "PandaTree/Objects/interface/Event.h"
#include "PandaTree/RelVal/interface/EnumerateBranches.h"

// Call the filler and then call the next branch

typedef std::function<void(int, std::vector<float>)> FillFunc;
typedef std::function<void(int)> ActionFunc;
typedef std::function<void(int, const char*)> NamedActionFunc;

template <int P>
struct plot_looper {

  void operator () (panda::Event& event, FillFunc& filler) {
    filler(P, plotter<P>()(event));
    plot_looper<P + 1>()(event, filler);
  };

  void operator () (ActionFunc& actor) {
    actor(P);
    plot_looper<P + 1>()(actor);
  }

  void operator () (NamedActionFunc& actor) {
    actor(P, plotter<P>::name);
    plot_looper<P + 1>()(actor);
  }

};

// Have to terminate at some point

// Make sure that NUM_PLOTS is defined correctly
static_assert(NUM_PLOTS, "No plots will be made");
static_assert(plotter<NUM_PLOTS - 1>::name, "NUM_PLOTS improperly set");
static_assert(plotter<NUM_PLOTS>::name == nullptr, "NUM_PLOTS improperly set");

template <>
struct plot_looper<NUM_PLOTS> {
  void operator ()(panda::Event&, FillFunc&) { };
  void operator ()(ActionFunc&) { };
  void operator ()(NamedActionFunc&) { };
};

#endif
