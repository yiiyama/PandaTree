#include <iostream>
#include <exception>

#include <boost/filesystem.hpp>

#include "PandaTree/Utils/interface/JECCorrector.h"


using namespace panda;


namespace {

  // Used to initialize the JetCorrectionParameters
  std::vector<JetCorrectorParameters> load_params (const std::string& files_base, const std::string& jet_type) {

    std::vector<JetCorrectorParameters> output {};

    const std::vector<std::string> levels = {
      "L1FastJet",
      "L2Relative",
      "L3Absolute",
      "L2L3Residual"
    };

    for (const auto& level : levels) {

      const std::string correction_file = files_base + "_" + level + "_" + jet_type + ".txt";

      if (not boost::filesystem::exists(correction_file)) {
        std::cerr << "Cannot find correction file: " << correction_file << std::endl;
        throw std::runtime_error {"No file"};
      }

      output.emplace_back(correction_file);
    }

    return output;

  }

}


JECCorrector::JECCorrector (const std::string& files_base, const std::string& jet_type) :
  m_corrector_params {load_params(files_base, jet_type)},
  m_corrector {m_corrector_params} {}


void JECCorrector::update_event (const panda::Event& event, const panda::JetCollection& jets, const Met& raw_met) {

  // Copy jets over
  m_corrected_jets = jets;

  auto new_met = raw_met.v();
  TVector2 met_correction {};

  m_corrector.setNPV(event.npv);
  m_corrector.setRho(event.rho);

  for (auto& jet : m_corrected_jets) {
    m_corrector.setJetEta(jet.eta());
    m_corrector.setJetPt(jet.rawPt);
    m_corrector.setJetE(jet.e());
    m_corrector.setJetPhi(jet.phi());
    m_corrector.setJetEMF(jet.cef + jet.nef); // Check that this is right
    m_corrector.setJetA(jet.area);

    auto scale = m_corrector.getCorrection();

    // Use 1.0 minus new so that we don't have to flip phi.
    // This adds to MET if scale > 1 and points in opposite direction
    // Subtracts if scale < 1 and points in opposite direction
    met_correction.SetMagPhi((1.0 - scale) * jet.rawPt, jet.phi());

    new_met += met_correction;

    jet.setPtEtaPhiM(scale * jet.rawPt, jet.eta(), jet.phi(), jet.m());
  }

  // Change stored MET
  m_corrected_met.setXY(new_met.X(), new_met.Y());

}


const JetCollection& JECCorrector::get_jets () const {

  return m_corrected_jets;

}


const Met& JECCorrector::get_met () const {

  return m_corrected_met;

}
