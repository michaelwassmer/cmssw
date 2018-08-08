import FWCore.ParameterSet.Config as cms
from DQMServices.Core.DQMEDHarvester import DQMEDHarvester

vbfmetEfficiency = DQMEDHarvester("DQMGenericClient",
    subDirs        = cms.untracked.vstring("HLT/Higgs/VBFMET/*"),
    verbose        = cms.untracked.uint32(0), # Set to 2 for all messages
    resolution     = cms.vstring(),
    efficiency     = cms.vstring(
        "effic_met          'MET turnON;            PF MET [GeV]; efficiency'     met_numerator          met_denominator",
        "effic_met_variable 'MET turnON;            PF MET [GeV]; efficiency'     met_variable_numerator met_variable_denominator",
        "effic_metPhi       'MET efficiency vs phi; PF MET phi [rad]; efficiency' metPhi_numerator       metPhi_denominator",
        "effic_jet1pt          'jet1 pT turnON;            PFJet1 pT [GeV]; efficiency'     jet1pt_numerator          jet1pt_denominator",
        "effic_jet2pt          'jet2 pT turnON;   PFJet2 pT [GeV]; efficiency'     jet2pt_numerator       jet2pt_denominator",
        "effic_jet1eta          'jet1 #eta turnON;   jet1 #eta; efficiency'     jet1eta_numerator       jet1eta_denominator",
        "effic_jet2eta          'jet2 #eta turnON;   jet2 #eta; efficiency'     jet2eta_numerator       jet2eta_denominator",
        "effic_cjetpt          'central jet pT turnON;  central jet pT [GeV]; efficiency'     cjetpt_numerator       cjetpt_denominator",
        "effic_cjeteta          'central jet #eta turnON;       central jet #eta; efficiency'     cjeteta_numerator       cjeteta_denominator",
        "effic_fjetpt          'forward jet pT turnON;  forward jet pT [GeV]; efficiency'     fjetpt_numerator       fjetpt_denominator",
        "effic_fjeteta          'forward jet #eta turnON;       forward jet #eta; efficiency'     fjeteta_numerator       fjeteta_denominator",
        "effic_mjj          'M_{jj} turnON;       DiPFJet mass      [GeV]; efficiency'     mjj_numerator       mjj_denominator",
        "effic_detajj          '#Delta#eta_{jj} turnON; #Delta#eta_{jj}; efficiency'     detajj_numerator       detajj_denominator",
        "effic_dphijj          '#Delta#phi_{jj} turnON; #Delta#phi_{jj}; efficiency'     dphijj_numerator       dphijj_denominator",
        "effic_mindphijmet          'min#Delta#phi(j,MET) turnON; min#Delta#phi(jet,MET); efficiency'     mindphijmet_numerator       mindphijmet_denominator",
        
    ),
    efficiencyProfile = cms.untracked.vstring(
        "effic_met_vs_LS 'MET efficiency vs LS; LS; PF MET efficiency' metVsLS_numerator metVsLS_denominator",
        "effic_jet1etaVsLS 'Jet1 #eta efficiency vs LS; LS; jet1 #eta efficiency' jet1etaVsLS_numerator jet1etaVsLS_denominator",
"effic_mjjVsLS 'M_{jj} efficiency vs LS; LS;  M_{jj} efficiency' mjjVsLS_numerator mjjVsLS_denominator",
"effic_mindphijmetVsLS 'min#Delta#phi(jet,MET) efficiency vs LS; LS;  min#Delta#phi(jet,MET) efficiency' mindphijmetVsLS_numerator mindphijmetVsLS_denominator",
    ),
  
)


vbfmetClient = cms.Sequence(
    vbfmetEfficiency
)
