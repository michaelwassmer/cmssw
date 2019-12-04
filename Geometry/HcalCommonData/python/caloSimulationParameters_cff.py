import FWCore.ParameterSet.Config as cms

from Geometry.HcalCommonData.caloSimulationParameters_cfi import *

from Configuration.Eras.Modifier_dd4hep_cff import dd4hep

dd4hep.toModify(caloSimulationParameters,
                fromDD4Hep = cms.bool(True)
)
