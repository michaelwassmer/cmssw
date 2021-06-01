#include "JetMETCorrections/Type1MET/interface/PFJetMETcorrInputProducerT.h"

#include "DataFormats/PatCandidates/interface/Jet.h"

#include "PhysicsTools/PatUtils/interface/PATJetCorrExtractor.h"

namespace PFJetMETcorrInputProducer_namespace
{
  template <>
  class InputTypeCheckerT<pat::Jet, PATJetCorrExtractor>
  {
    public:

     void operator()(const pat::Jet& jet) const
     {
       // check that pat::Jet is of PF-type
       if ( !jet.isPFJet() )
	 throw cms::Exception("InvalidInput")
	   << "Input pat::Jet is not of PF-type !!\n";
     }
     bool isPatJet(const pat::Jet& jet) const {
       return true;
     }
  };

  template <>
  class RawJetExtractorT<pat::Jet>
  {
    public:

     RawJetExtractorT(){}
     reco::Candidate::LorentzVector operator()(const pat::Jet& jet) const
     {
       //std::cout << "getting uncorrected jet in specialized template" << std::endl;
       reco::Candidate::LorentzVector uncorrected_jet;
       if ( jet.jecSetsAvailable() ) uncorrected_jet = jet.correctedP4("Uncorrected");
       else uncorrected_jet = jet.p4();
       if(jet.hasUserFloat("SmearFactor")) {
           uncorrected_jet*=(1.0/jet.userFloat("SmearFactor"));
           //std::cout << "removed JER smear factor " << jet.userFloat("SmearFactor") << std::endl;
       }
       return uncorrected_jet;
     }
  };
  
  template <>
  class RetrieveJerT<pat::Jet>
  {
    public:
    
      RetrieveJerT(){}
      float operator()(const pat::Jet& jet) const
      {
        //std::cout << "retrieving JER in specialized template" << std::endl;
        if(jet.hasUserFloat("SmearFactor")) {
            //std::cout << "returning JER smear factor" << jet.userFloat("SmearFactor") << std::endl;
            return jet.userFloat("SmearFactor");
        }
        else return 1.0;
      } 
  };
}

typedef PFJetMETcorrInputProducerT<pat::Jet, PATJetCorrExtractor> PATPFJetMETcorrInputProducer;

#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_FWK_MODULE(PATPFJetMETcorrInputProducer);


