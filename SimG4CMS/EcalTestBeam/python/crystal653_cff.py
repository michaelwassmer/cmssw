import FWCore.ParameterSet.Config as cms
                                        
common_beam_direction_parameters = cms.PSet(
    MinEta = cms.double(0.572552),
    MaxEta = cms.double(0.572552),
    MinPhi = cms.double(-0.039911 ),
    MaxPhi = cms.double(-0.039911 ),
    Psi    = cms.double(999.9),
    BeamMeanX = cms.double(0.0),
    BeamMeanY = cms.double(0.0),
    BeamPosition = cms.double(-26733.5)
)
