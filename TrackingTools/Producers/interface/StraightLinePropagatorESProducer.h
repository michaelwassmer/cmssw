#ifndef TrackingTools_ESProducers_StraightLinePropagatorESProducer_h
#define TrackingTools_ESProducers_StraightLinePropagatorESProducer_h

#include "FWCore/Framework/interface/ESProducer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "TrackingTools/GeomPropagators/interface/StraightLinePropagator.h"
#include "TrackingTools/Records/interface/TrackingComponentsRecord.h"
#include <memory>

class  StraightLinePropagatorESProducer: public edm::ESProducer{
 public:
  StraightLinePropagatorESProducer(const edm::ParameterSet & p);
  ~StraightLinePropagatorESProducer() override; 
  std::unique_ptr<Propagator> produce(const TrackingComponentsRecord &);
 private:
  edm::ParameterSet pset_;
};


#endif




