# Auto generated configuration file
# using: 
# Revision: 1.20 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: muontimingtt -s NONE --conditions PH2_1K_FB_V6::All --no_output --no_exec -n -1 --filein das:/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/TP2023HGCALDR-62028p1_PU50NoOOT_FastTimeHLLHC_PH2_1K_FB_V6-v1/GEN-SIM-RECO --python_filename muontimingtt.py
import FWCore.ParameterSet.Config as cms

process = cms.Process('NONE')

# import of standard configurations
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

# Input source
process.source = cms.Source("PoolSource",
    secondaryFileNames = cms.untracked.vstring(),
    fileNames = cms.untracked.vstring('/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_PU50NoOOT_FastTimeHLLHC_PH2_1K_FB_V6-v1/70000/0038C3A4-A82E-E611-B412-00259055053A.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_PU50NoOOT_FastTimeHLLHC_PH2_1K_FB_V6-v1/70000/00607275-242E-E611-A1DC-0050560210EA.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_PU50NoOOT_FastTimeHLLHC_PH2_1K_FB_V6-v1/70000/027C0D97-E92E-E611-8275-0CC47A1DF7F8.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_PU50NoOOT_FastTimeHLLHC_PH2_1K_FB_V6-v1/70000/02CDF0FE-8E2E-E611-9C4F-002590775158.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_PU50NoOOT_FastTimeHLLHC_PH2_1K_FB_V6-v1/70000/02F2D03A-8A2E-E611-A6FE-008CFA197B6C.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_PU50NoOOT_FastTimeHLLHC_PH2_1K_FB_V6-v1/70000/0487C9AD-552E-E611-9BEF-0CC47A1E0482.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_PU50NoOOT_FastTimeHLLHC_PH2_1K_FB_V6-v1/70000/08642E51-A82E-E611-A654-00259055053A.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_PU50NoOOT_FastTimeHLLHC_PH2_1K_FB_V6-v1/70000/0AD683F9-632E-E611-B929-002590D0B086.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_PU50NoOOT_FastTimeHLLHC_PH2_1K_FB_V6-v1/70000/0C13530B-8F2E-E611-BE00-0090FAA58974.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_PU50NoOOT_FastTimeHLLHC_PH2_1K_FB_V6-v1/70000/0CC13E9F-FD2D-E611-B201-008CFA1111CC.root')
)

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.20 $'),
    annotation = cms.untracked.string('TimingAnalysis/MuonIsoTiming/python/muonIsoTiming_cfi.py nevts:-1'),
    #annotation = cms.untracked.string('muontimingtt nevts:-1'),
    name = cms.untracked.string('Applications')
)

# Output definition

# Additional output definition

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'PH2_1K_FB_V6::All', '')


process.TFileService = cms.Service("TFileService", 
    fileName = cms.string("muontimingtt200.root"),
    closeFileFast = cms.untracked.bool(True)
)

process.muonIsoTiming = cms.EDAnalyzer('MuonIsoTiming'
)

process.path = cms.Path(process.muonIsoTiming)

# Path and EndPath definitions

# Schedule definition
process.schedule = cms.Schedule(process.path)

# Path and EndPath definitions

# Schedule definition
#process.schedule = cms.Schedule()

