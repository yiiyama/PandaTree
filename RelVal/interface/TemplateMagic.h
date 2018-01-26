#ifndef THATSBAD
#define THATSBAD 1

#include <vector>
#include <functional>

#include "PandaTree/Objects/interface/Event.h"
#include "PandaTree/RelVal/interface/EnumerateBranches.h"

// These are the types of functions that plot_looper can take as an argument
// For all of these, the function action should be different for each branch
//     (represented as the int passed first to each function)

namespace testpanda {
  // FillFunc also should be passed to plot_looper with an event tree
  // This calls the () operator for the plotters in EnumerateBranches.h
  typedef std::function<void(int, std::vector<float>)> FillFunc;
  typedef std::function<void(int)> ActionFunc;
  // This also grabs the plot names from the plotters in EnumerateBranches.h
  typedef std::function<void(int, const char*)> NamedActionFunc;

  // This let's us loop over the branches with recursive templating
  // Call the filler and then call the next branch

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

  // Override the recursive behavior

  template <>
    struct plot_looper<NUM_PLOTS> {
    void operator ()(panda::Event&, FillFunc&) { };
    void operator ()(ActionFunc&) { };
    void operator ()(NamedActionFunc&) { };
  };
};

#endif
