#include <fstream>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <utility>
#include <limits>
#include <functional>
#include <sys/stat.h>

#include "TFile.h"
#include "TTree.h"

#include "PandaTree/Objects/interface/Event.h"
#include "PandaTree/RelVal/interface/EnumerateBranches.h"
#include "PandaTree/RelVal/interface/TemplateMagic.h"

int main(int argc, char** argv) {

  // Check that the input file exists
  struct stat buffer;
  if (argc != 2 || stat(argv[1], &buffer) != 0) {
    // Print the usage information
    std::cout << std::endl
              << "Usage: " << argv[0] << " INPUT" << std::endl
              << std::endl
              << "Takes a panda file and creates plots in your personal web directory." << std::endl
              << "A little webpage is included to make the output directory nice to look at." << std::endl
              << std::endl;

    return 1;
  }

  TFile input{argv[1]};
  TTree* input_tree = static_cast<TTree*>(input.Get("events"));

  panda::Event event;
  event.setAddress(*input_tree);

  unsigned long nentries = input_tree->GetEntries();

  // We will use these maps to track the maximum and minimum values for the "branches"
  std::unordered_map<std::string, float> maximums;
  std::unordered_map<std::string, std::pair<float, float>> minimums;

  // Initialize the maps
  for (auto i_branch : panda_plot_names) {
    minimums[i_branch] = std::make_pair(std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
    maximums[i_branch] = std::numeric_limits<float>::min();
  }

  std::function<void(int, std::vector<float>)> fill_minmax_maps = [&](int index, std::vector<float> input) {

    std::string plot_name = panda_plot_names[index];
    for (auto value : input) {
      maximums[plot_name] = std::max(maximums[plot_name], value);

      if (value < minimums[plot_name].first) {
        minimums[plot_name].second = minimums[plot_name].first;
        minimums[plot_name].first = value;
      }
      else if (value != minimums[plot_name].first) {
        minimums[plot_name].second = std::min(minimums[plot_name].second, value);
      }
    }
  };

  // Draw shitty progress bar
  std::cout << '[';
  for (int i = 0; i < 100; i++)
    std::cout << '-';
  std::cout << ']' << std::endl;

  int report_freq = nentries/100;

  for (unsigned long i_entry = 0; i_entry != nentries; i_entry++) {
    event.getEntry(*input_tree, i_entry);

    if (i_entry % report_freq == 0)
      std::cout << '.';

    plot_looper<0>()(event, fill_minmax_maps);

  }
  std::cout << std::endl;

  for (int i_branch = 0; i_branch != panda_plots::PLOTS_SIZE; i_branch++) {
    std::cout << "Max " << panda_plot_names[i_branch] << " : " << maximums[panda_plot_names[i_branch]] << std::endl;
    std::cout << "Mins " << panda_plot_names[i_branch] << " : " << minimums[panda_plot_names[i_branch]].second << std::endl;
    std::cout << "Mins " << panda_plot_names[i_branch] << " : " << minimums[panda_plot_names[i_branch]].first << std::endl;
  }

  input.Close();

}
