from CRABClient.UserUtilities import config
config = config()

config.General.requestName = 'ZJetsPPMCFinal'
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
# Name of the CMSSW configuration file
config.JobType.psetName = 'ConfFile_cfg.py'

config.Data.inputDataset = '/Pythia8_Z30mumuJet/HINppWinter16DR-75X_mcRun2_asymptotic_ppAt5TeV_v3-v1/AODSIM'
#/Pythia8_Z30mumuJet_Hydjet_MB/HINPbPbWinter16DR-75X_mcRun2_HeavyIon_v13-v1/AODSIM -PbPb MC dataset
#/Pythia8_Z30mumuJet/HINppWinter16DR-75X_mcRun2_asymptotic_ppAt5TeV_v3-v1/AODSIM- PP  MC dataset
#/SingleMuHighPt/Run2015E-ZMM-PromptReco-v1/RAW-RECO - PP filtered dataset
#/DoubleMu/Run2015E-PromptReco-v1/AOD - PP dataset
#/SingleMuHighPt/Run2015E-PromptReco-v1/AOD - PP dataset
#/HIEWQExo/HIRun2015-PromptReco-v1/AOD -PbPb dataset
#/HIEWQExo/HIRun2015-ZMM-PromptReco-v1/RAW-RECO - filtered PbPb dataset
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 100
config.Data.publication = False
# This string is used to construct the output dataset name
config.Data.outputDatasetTag = 'CRAB3_ZJetsPPMCFinalAnaS'

# These values only make sense for processing data
#    Select input data based on a lumi mask
#config.Data.lumiMask = '/afs/cern.ch/user/a/asnjegot/CMSSW_7_5_8/src/FirstAnalyzer/MuonAnalyzer/python/json_DCSONLY.json'
#    Select input data based on run-ranges
#config.Data.runRange = '190456-194076'

# Where the output files will be transmitted to
config.Site.storageSite = 'T2_US_MIT'
