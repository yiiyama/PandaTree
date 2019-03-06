#ifndef PANDATREE_UTILS_JECCORRECTOR_H
#define PANDATREE_UTILS_JECCORRECTOR_H


#include "PandaTree/Objects/interface/Event.h"

#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "CondFormats/JetMETObjects/interface/FactorizedJetCorrector.h"


namespace panda {
  /**
     @brief A wrapper for CMSSW's FactorizedJetCorrector for Panda JetCollections
  */
  class JECCorrector {
  public:
    /**
       @param files_base Directory location and beginning of file name. e.g. "data/Autumn18_V3_MC"
       @param jet_type Type of jet to correct. e.g. "AK4PFchs"
    */
    JECCorrector (const std::string& files_base, const std::string& jet_type);

    /// Must be called at the beginning of each event to update the corrected values
    void update_event (const panda::Event& event, const panda::JetCollection& jets, const RecoMet& met);

    const JetCollection& get_jets () const;
    const RecoMet& get_met () const;

  private:

    /// Holds the corrected jets
    JetCollection m_corrected_jets {};

    /// Holds the corrected MET
    RecoMet m_corrected_met {};

    /// A vector of the JetCorrectorParameters, initialized by panda::JECCorrector::load_params
    std::vector<JetCorrectorParameters> m_corrector_params;
    /// The FactorizedJetCorrector that is used underneath
    FactorizedJetCorrector m_corrector;

  };
}


#endif
