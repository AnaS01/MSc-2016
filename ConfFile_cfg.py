import FWCore.ParameterSet.Config as cms

process = cms.Process("Test")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger = cms.Service("MessageLogger",
                                    destinations =  cms.untracked.vstring('detailedInfo' ))

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
                             fileNames = cms.untracked.vstring('file:/afs/cern.ch/user/a/asnjegot/Data/PbPbSample.root'))

process.demo = cms.EDAnalyzer('MuonAnalyzer')
process.TFileService = cms.Service("TFileService", fileName = cms.string("zJetsPPMC.root"))

process.p = cms.Path(process.demo)
