#define PROG_SIZE 100
#define DEFAULT_BINS 40

#include <cassert>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <unordered_map>
#include <string>
#include <utility>
#include <limits>
#include <functional>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#include <TROOT.h>
#include <TError.h>

#include "TObject.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1I.h"
#include "TCanvas.h"

#include "PandaTree/Objects/interface/Event.h"
#include "PandaTree/RelVal/interface/EnumerateBranches.h"
#include "PandaTree/RelVal/interface/TemplateMagic.h"


bool exists(const char* path) {
  struct stat buffer;
  return stat(path, &buffer) == 0;
}


void draw_progress(int percent) {

  // Draw shitty progress bar
  std::cout << '\r' << '[';
  for (int i = 0; i < PROG_SIZE; i++) {
    if (i < percent)
      std::cout << '=';
    else if (i == percent)
      std::cout << '>';
    else
      std::cout << ' ';
  }
  std::cout << "] " << percent * 100/PROG_SIZE << '%';
}


void make_dirs(std::string path) {
  char path_array[256];
  // Stick a slash on the end to trick our character flipping
  strncpy(path_array, (path + "/").data(), sizeof(path_array) - 1);
  auto num_chars = strlen(path_array);

  for (unsigned i_char = 1; i_char < num_chars; i_char++) {

    if (path_array[i_char] != '/')
      continue;

    // Flip character to null
    path_array[i_char] = '\0';
    if (!exists(path_array)) {
      std::cout << "Making: " << path_array << std::endl;
      mkdir(path_array, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    }
    // Flip back
    path_array[i_char] = '/';
  }
}


std::string get_git_tag(std::string repo) {
  auto git_dir = std::string(getenv("CMSSW_BASE")) +
    "/src/" + repo + "/.git";

  if (exists(git_dir.data())) {
    std::string head;
    std::ifstream head_file((git_dir + "/HEAD").data());
    head_file >> head >> head;
    head_file.close();

    std::string tag;
    std::ifstream tag_file((git_dir + "/" + head).data());
    tag_file >> tag;
    tag_file.close();

    return tag;
  }
  std::cout << "No git dir" << std::endl;
  return "";
}


int main(int argc, char** argv) {

  //// Create web directory and copy files, if needed ////

  auto base_dir = std::string(getenv("HOME")) + "/public_html/relval";

  make_dirs(base_dir);

  // Copy web files to relval, if needed

  auto input_web = std::string(getenv("CMSSW_BASE")) + "/src/PandaTree/RelVal/web";
  auto* web_dir = opendir(input_web.data());

  while (auto* dir_ent = readdir(web_dir)) {
    struct stat source_stat;
    auto source_name = input_web + "/" + dir_ent->d_name;
    stat(source_name.data(), &source_stat);

    // If directory entry is a file and newer, copy it
    if (source_stat.st_mode & S_IFREG &&
        source_name.compare(source_name.size() - 1, 1, "~") != 0) {
      struct stat dest_stat;
      auto dest_name = base_dir + "/" + dir_ent->d_name;
      auto ret = stat(dest_name.data(), &dest_stat);

      if (ret != 0 || source_stat.st_mtime > dest_stat.st_mtime) {

        std::cout << "Copying " << source_name << " to " << dest_name << std::endl;

        std::ifstream source_file(source_name.data());
        std::ofstream dest_file(dest_name.data());
        std::string source_content;
        while(std::getline(source_file, source_content))
          dest_file << source_content << std::endl;

        source_file.close();
        dest_file.close();
      }
    }
  }

  closedir(web_dir);

  //// Check that the input file exists, and quit if it doesn't ////

  // I'll do the stat by hand here so that I can keep the stat info
  struct stat input_stat;

  if (argc != 2 || stat(argv[1], &input_stat) != 0) {
    // Print the usage information
    std::cout << std::endl
              << "Usage: " << argv[0] << " INPUT" << std::endl
              << std::endl
              << "Takes a panda file and creates plots in your personal web directory." << std::endl
              << "A little webpage is included to make the output directory nice to look at." << std::endl
              << std::endl;

    return 1;
  }

  // Get start time
  time_t start_time;
  time(&start_time);

  //// Open input file and define loop ////

  TFile input{argv[1]};
  TTree* input_tree = static_cast<TTree*>(input.Get("events"));

  panda::Event event;
  event.setAddress(*input_tree);

  unsigned long nentries = input_tree->GetEntries();
  auto report_freq{std::max(nentries/PROG_SIZE, 1ul)};

  //// Defined in TemplateMagic.h ////
  // Loops through all enumerated branches and performs some function
  auto looper = plot_looper<0>();

  // We will loop over the entry tree and fill different things
  auto loop_tree = [&](auto message, auto filler) {
    std::cout << message << std::endl;
    int progress{0};
    for (unsigned long i_entry = 0; i_entry != nentries; i_entry++) {
      event.getEntry(*input_tree, i_entry);

      if (i_entry && i_entry % report_freq == 0)
        draw_progress(progress++);

      // Fill something for every plot
      looper(event, filler);
    }

    draw_progress(PROG_SIZE);
    std::cout << std::endl;
  };

  //// Find MIN and MAX of each plot ////

  // We will use these maps to track the maximum and minimum values for the plots
  std::vector<float> maximums;
  // Minimum includes two values in case the default value is super low or something
  std::vector<std::pair<float, float>> minimums;

  ActionFunc init_minmax = [&](auto index) {
    minimums.emplace_back(std::make_pair(std::numeric_limits<float>::max(), std::numeric_limits<float>::max()));
    maximums.emplace_back(std::numeric_limits<float>::min());
  };

  // Initialize min/max for every plot
  looper(init_minmax);

  // Function that fills the maps
  // FillFunc defined in TemplateMagic.h
  FillFunc fill_minmax_maps = [&](auto index, auto input) {

    for (auto value : input) {
      maximums[index] = std::max(maximums[index], value);

      if (value < minimums[index].first) {
        minimums[index].second = minimums[index].first;
        minimums[index].first = value;
      }
      else if (value != minimums[index].first) {
        minimums[index].second = std::min(minimums[index].second, value);
      }
    }
  };

  loop_tree("Filling min/max maps.", fill_minmax_maps);

  //// Fill histograms of each plot ////

  std::vector<TH1I> histograms;

  // Initialize the histograms
  NamedActionFunc init_hists = [&](auto index, auto name) {
    auto mins = minimums[index];
    auto max = maximums[index];
    auto min = mins.first;
    // If the gap between the two lowest minimums is large,
    // don't use the very minimum value
    if (mins.second - min > (max - mins.second) * 0.25) {
      min = mins.second;
    }

    // Get the number of bins for the histogram
    auto num_bins{(max - min < 8) ? DEFAULT_BINS : std::min(int(max - min + 1), DEFAULT_BINS)};

    // Check that bounds make sense
    if (min < max) {
      min -= 0.1;
      max += 0.1;
    }
    else {
      min = 0;
      max = 1;
    }

    // Initialize
    histograms.emplace_back(TH1I(name, name, num_bins, min, max));

  };

  // Initialize histograms for every plot
  looper(init_hists);

  // Define histogram filler
  FillFunc fill_hist_maps = [&](auto index, auto input) {

    auto& hist = histograms[index];
    for (auto value : input) {
      hist.Fill(value);
    }
  };

  // Fill histograms
  loop_tree("Filling histograms.", fill_hist_maps);

  // Draw plots

  // Create name of directory from timestamp
  time_t end_time;
  time(&end_time);

  char timestamp_str[32];
  strftime(timestamp_str, sizeof(timestamp_str) - 1, "%y%m%d_%H%M%S", localtime(&end_time));
  auto output_dir = base_dir + "/" + timestamp_str;

  // We will actually make the directory when the first plots come in

  std::vector<std::string> exts = {".png", ".pdf"};
  std::set<std::string> out_dirs;

  NamedActionFunc plot_hists = [&](auto index, auto name) {
    if (histograms[index].GetEntries()) {
      std::string branch_name {name};
      auto out_dir = branch_name.substr(0, branch_name.find('/'));
      if (out_dirs.find(out_dir) == out_dirs.end()) {
        make_dirs(output_dir + "/" + out_dir);
        out_dirs.emplace(out_dir);
      }

      // scram is complaining about not finding definitions of TCanvas constructors
      // and I'm too stupid to fix it
      // Instead, I do this hacky thing of finding the automatically generated canvas through gROOT
      // It works quite nicely :)

      histograms[index].Draw();
      auto* canvas = static_cast<TCanvas*>(gROOT->GetListOfCanvases()->At(0));
      for (auto& ext : exts) {
        canvas->SaveAs((output_dir + "/" + branch_name + ext).data());
        canvas->SetLogy(true);
        canvas->SaveAs((output_dir + "/" + branch_name + "_log" + ext).data());
        canvas->SetLogy(false);
      }
    }
  };

  gErrorIgnoreLevel = kWarning;
  // Plot every plot
  looper(plot_hists);

  //// Get the file metadata and put it in the directory ////

  char report_time_str[64];
  strftime(report_time_str, sizeof(report_time_str) - 1, "%c", localtime(&end_time));

  char mtime_str[64];
  strftime(mtime_str, sizeof(mtime_str) - 1, "%c", localtime(&input_stat.st_mtime));

  std::ofstream metadata_file(output_dir + "/metadata.txt");

  metadata_file << "Report generated: " << report_time_str << std::endl
                << std::endl
                << "File name:  " << getenv("PWD") << '/' << argv[1] << std::endl
                << "File size:  " << input_stat.st_size << std::endl
                << "File mtime: " << mtime_str << std::endl
                << std::endl
                << "Num events: " << nentries << std::endl
                << "Num plots:  " << NUM_PLOTS << std::endl
                << "Time (sec): " << end_time - start_time << std::endl
                << std::endl
                << "CMSSW Version:    " << getenv("CMSSW_VERSION") << std::endl
                << "PandaTree commit: " << get_git_tag("PandaTree") << std::endl
                << "PandaProd commit: " << get_git_tag("PandaProd") << std::endl
    ;

  metadata_file.close();

  input.Close();

  return 0;
}
