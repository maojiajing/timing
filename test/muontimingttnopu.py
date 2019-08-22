# Auto generated configuration file
# using: 
# Revision: 1.20 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: muontimingttnopu -s NONE --conditions PH2_1K_FB_V6::All --no_output --no_exec -n -1 --filein das:/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/TP2023HGCALDR-62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v3/GEN-SIM-RECO --python_filename muontimingttnopu.py
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
    fileNames = cms.untracked.vstring('/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v3/00000/08E9C6F5-311F-E611-B0B4-0CC47A13CDB0.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v3/00000/269025F5-311F-E611-8657-0CC47A6C1866.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v3/00000/2E07CA41-2B1F-E611-95E5-0025901D4B0E.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v3/00000/3E6A83F5-311F-E611-9019-90B11C2CA3F8.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v3/00000/3ECF8BF6-311F-E611-A72D-90B11C27F8B2.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v3/00000/402A40D7-6C1F-E611-BB9B-0025904C7A58.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v3/00000/4425F158-091F-E611-B40E-0CC47A6C06C2.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v3/00000/52A7C657-E11E-E611-8358-0025901D1668.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v3/00000/52F57E29-901F-E611-AC9B-0025900B5648.root', 
        '/store/mc/TP2023HGCALDR/PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v3/00000/621CA39F-D71F-E611-9C08-00259048812E.root')
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
    fileName = cms.string("muontimingttnopu.root"),
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

