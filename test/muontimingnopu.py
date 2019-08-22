# Auto generated configuration file
# using: 
# Revision: 1.20 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: muontimingnopu -s NONE --conditions PH2_1K_FB_V6::All --no_output --no_exec -n -1 --filein das:/DYToMuMu_M-20_TuneZ2star_14TeV-pythia6-tauola/TP2023HGCALDR-62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v2/GEN-SIM-RECO --python_filename muontimingnopu.py
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
    fileNames = cms.untracked.vstring('/store/mc/TP2023HGCALDR/DYToMuMu_M-20_TuneZ2star_14TeV-pythia6-tauola/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v2/00000/0C7ABC3E-091F-E611-92D1-842B2B180882.root', 
        '/store/mc/TP2023HGCALDR/DYToMuMu_M-20_TuneZ2star_14TeV-pythia6-tauola/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v2/00000/265AB34B-2E1F-E611-9780-842B2B17EB6A.root', 
        '/store/mc/TP2023HGCALDR/DYToMuMu_M-20_TuneZ2star_14TeV-pythia6-tauola/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v2/00000/2C619160-7820-E611-A3CA-0025901D16AC.root', 
        '/store/mc/TP2023HGCALDR/DYToMuMu_M-20_TuneZ2star_14TeV-pythia6-tauola/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v2/00000/4EBD6C53-5A1F-E611-AD81-782BCB20DE6B.root', 
        '/store/mc/TP2023HGCALDR/DYToMuMu_M-20_TuneZ2star_14TeV-pythia6-tauola/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v2/00000/62AB9042-091F-E611-AAB0-0026B93785F5.root', 
        '/store/mc/TP2023HGCALDR/DYToMuMu_M-20_TuneZ2star_14TeV-pythia6-tauola/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v2/00000/66940E28-901F-E611-83A9-90B11C26815F.root', 
        '/store/mc/TP2023HGCALDR/DYToMuMu_M-20_TuneZ2star_14TeV-pythia6-tauola/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v2/00000/7E8702A1-091F-E611-8D15-C81F66B73F37.root', 
        '/store/mc/TP2023HGCALDR/DYToMuMu_M-20_TuneZ2star_14TeV-pythia6-tauola/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v2/00000/86A42202-091F-E611-8F11-B083FED045ED.root', 
        '/store/mc/TP2023HGCALDR/DYToMuMu_M-20_TuneZ2star_14TeV-pythia6-tauola/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v2/00000/906C9308-471F-E611-BDC9-782BCB536A50.root', 
        '/store/mc/TP2023HGCALDR/DYToMuMu_M-20_TuneZ2star_14TeV-pythia6-tauola/GEN-SIM-RECO/62028p1_NoPU_FastTimeHLLHC_PH2_1K_FB_V6-v2/00000/A039C744-091F-E611-890F-141877410B85.root')
)

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.20 $'),
    annotation = cms.untracked.string('muontimingnopu nevts:-1'),
    name = cms.untracked.string('Applications')
)

# Output definition

# Additional output definition

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'PH2_1K_FB_V6::All', '')

# Path and EndPath definitions

# Schedule definition
#process.schedule = cms.Schedule()


process.TFileService = cms.Service("TFileService", 
    fileName = cms.string("muontimingzmmnopu.root"),
    closeFileFast = cms.untracked.bool(True)
)

process.muonIsoTiming = cms.EDAnalyzer('MuonIsoTiming'
)

process.path = cms.Path(process.muonIsoTiming)

# Path and EndPath definitions

# Schedule definition
process.schedule = cms.Schedule(process.path)

