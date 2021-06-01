
#include "DataFormats/JetReco/interface/CaloJet.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/PatCandidates/interface/Jet.h"

namespace SmearedJetProducer_namespace {
    template <typename T>
    void SmearJet(T& jet, float smearfactor) {
        //std::cout << "smearing jet in main template with smear factor " << smearfactor << std::endl;
        jet.scaleEnergy(smearfactor);
    }
    
    template <>
    void SmearJet<pat::Jet>(pat::Jet& jet, float smearfactor) {
        //std::cout << "smearing jet in specialized template with smear factor " << smearfactor << std::endl;
        jet.scaleEnergy(smearfactor);
        //std::cout << "storing smear factor " << smearfactor << " in specialized template" << std::endl;
        jet.addUserFloat("SmearFactor",smearfactor);
    }
}

#include "PhysicsTools/PatUtils/interface/SmearedJetProducerT.h"

typedef SmearedJetProducerT<reco::CaloJet> SmearedCaloJetProducer;
typedef SmearedJetProducerT<reco::PFJet>   SmearedPFJetProducer;
typedef SmearedJetProducerT<pat::Jet> SmearedPATJetProducer;

#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_FWK_MODULE(SmearedCaloJetProducer);
DEFINE_FWK_MODULE(SmearedPFJetProducer);
DEFINE_FWK_MODULE(SmearedPATJetProducer);
