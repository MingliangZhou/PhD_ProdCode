#ifndef ROOTCORE_PACKAGES_H
#define ROOTCORE_PACKAGES_H

// This file contains one define statement for each package detected by
// RootCore.  It is meant to allow to write package A in a form that
// it uses the services of package B when available, but otherwise
// skips it without failing.  For this to work properly you need to list
// package B in the PACKAGE_TRYDEP of package A.

#define ROOTCORE_PACKAGE_RootCore
#define ROOTCORE_PACKAGE_Asg_Doxygen
#define ROOTCORE_PACKAGE_Asg_Test
#define ROOTCORE_PACKAGE_Asg_root
#define ROOTCORE_PACKAGE_ApplyJetCalibration
#define ROOTCORE_PACKAGE_Asg_GoogleTest
#define ROOTCORE_PACKAGE_xAODRootAccessInterfaces
#define ROOTCORE_PACKAGE_Asg_Boost
#define ROOTCORE_PACKAGE_TestTools
#define ROOTCORE_PACKAGE_CxxUtils
#define ROOTCORE_PACKAGE_AthContainersInterfaces
#define ROOTCORE_PACKAGE_AthLinks
#define ROOTCORE_PACKAGE_AthContainers
#define ROOTCORE_PACKAGE_xAODCore
#define ROOTCORE_PACKAGE_xAODEventFormat
#define ROOTCORE_PACKAGE_xAODRootAccess
#define ROOTCORE_PACKAGE_AsgTools
#define ROOTCORE_PACKAGE_AsgExampleTools
#define ROOTCORE_PACKAGE_Asg_Eigen
#define ROOTCORE_PACKAGE_Asg_FastJet
#define ROOTCORE_PACKAGE_Asg_HEPUtils
#define ROOTCORE_PACKAGE_Asg_Lhapdf
#define ROOTCORE_PACKAGE_Asg_MCUtils
#define ROOTCORE_PACKAGE_Asg_RooUnfold
#define ROOTCORE_PACKAGE_xAODBase
#define ROOTCORE_PACKAGE_CaloGeoHelpers
#define ROOTCORE_PACKAGE_EventPrimitives
#define ROOTCORE_PACKAGE_GeoPrimitives
#define ROOTCORE_PACKAGE_xAODCaloEvent
#define ROOTCORE_PACKAGE_xAODTracking
#define ROOTCORE_PACKAGE_xAODTrigger
#define ROOTCORE_PACKAGE_xAODBTagging
#define ROOTCORE_PACKAGE_xAODPFlow
#define ROOTCORE_PACKAGE_xAODJet
#define ROOTCORE_PACKAGE_TruthUtils
#define ROOTCORE_PACKAGE_xAODTruth
#define ROOTCORE_PACKAGE_xAODMissingET
#define ROOTCORE_PACKAGE_FourMomUtils
#define ROOTCORE_PACKAGE_xAODEventInfo
#define ROOTCORE_PACKAGE_xAODPrimitives
#define ROOTCORE_PACKAGE_xAODEgamma
#define ROOTCORE_PACKAGE_MuonIdHelpers
#define ROOTCORE_PACKAGE_xAODMuon
#define ROOTCORE_PACKAGE_xAODTau
#define ROOTCORE_PACKAGE_AssociationUtils
#define ROOTCORE_PACKAGE_RootCoreUtils
#define ROOTCORE_PACKAGE_SampleHandler
#define ROOTCORE_PACKAGE_EventLoop
#define ROOTCORE_PACKAGE_PATCore
#define ROOTCORE_PACKAGE_PATInterfaces
#define ROOTCORE_PACKAGE_PathResolver
#define ROOTCORE_PACKAGE_xAODParticleEvent
#define ROOTCORE_PACKAGE_ReweightUtils
#define ROOTCORE_PACKAGE_GoodRunsLists
#define ROOTCORE_PACKAGE_PileupReweighting
#define ROOTCORE_PACKAGE_MuonEfficiencyCorrections
#define ROOTCORE_PACKAGE_MuonSelectorTools
#define ROOTCORE_PACKAGE_MuonMomentumCorrections
#define ROOTCORE_PACKAGE_ElectronPhotonSelectorTools
#define ROOTCORE_PACKAGE_egammaLayerRecalibTool
#define ROOTCORE_PACKAGE_MVAUtils
#define ROOTCORE_PACKAGE_egammaRecEvent
#define ROOTCORE_PACKAGE_egammaMVACalib
#define ROOTCORE_PACKAGE_xAODMetaData
#define ROOTCORE_PACKAGE_ElectronPhotonFourMomentumCorrection
#define ROOTCORE_PACKAGE_InDetTrackSelectionTool
#define ROOTCORE_PACKAGE_MCTruthClassifier
#define ROOTCORE_PACKAGE_tauRecTools
#define ROOTCORE_PACKAGE_TauAnalysisTools
#define ROOTCORE_PACKAGE_ElectronEfficiencyCorrection
#define ROOTCORE_PACKAGE_CalibrationDataInterface
#define ROOTCORE_PACKAGE_JetInterface
#define ROOTCORE_PACKAGE_xAODEventShape
#define ROOTCORE_PACKAGE_JetCalibTools
#define ROOTCORE_PACKAGE_JetSelectorTools
#define ROOTCORE_PACKAGE_JetResolution
#define ROOTCORE_PACKAGE_JetCPInterfaces
#define ROOTCORE_PACKAGE_JetUncertainties
#define ROOTCORE_PACKAGE_METInterface
#define ROOTCORE_PACKAGE_METUtilities
#define ROOTCORE_PACKAGE_xAODBTaggingEfficiency
#define ROOTCORE_PACKAGE_CPAnalysisExamples
#define ROOTCORE_PACKAGE_DiTauMassTools
#define ROOTCORE_PACKAGE_ElectronPhotonShowerShapeFudgeTool
#define ROOTCORE_PACKAGE_MultiDraw
#define ROOTCORE_PACKAGE_EventLoopAlgs
#define ROOTCORE_PACKAGE_EventLoopGrid
#define ROOTCORE_PACKAGE_EventShapeInterface
#define ROOTCORE_PACKAGE_IsolationSelection
#define ROOTCORE_PACKAGE_FsrUtils
#define ROOTCORE_PACKAGE_IRegionSelector
#define ROOTCORE_PACKAGE_InDetTrackSystematicsTools
#define ROOTCORE_PACKAGE_JetEDM
#define ROOTCORE_PACKAGE_JetRec
#define ROOTCORE_PACKAGE_IsolationCorrections
#define ROOTCORE_PACKAGE_JetJvtEfficiency
#define ROOTCORE_PACKAGE_JetUtils
#define ROOTCORE_PACKAGE_JetMomentTools
#define ROOTCORE_PACKAGE_JetSubStructureUtils
#define ROOTCORE_PACKAGE_JetSubStructureMomentTools
#define ROOTCORE_PACKAGE_PMGTools
#define ROOTCORE_PACKAGE_PhotonEfficiencyCorrection
#define ROOTCORE_PACKAGE_PhotonVertexSelection
#define ROOTCORE_PACKAGE_TrigNavStructure
#define ROOTCORE_PACKAGE_TrigConfBase
#define ROOTCORE_PACKAGE_TrigConfL1Data
#define ROOTCORE_PACKAGE_TrigConfHLTData
#define ROOTCORE_PACKAGE_TrigConfInterfaces
#define ROOTCORE_PACKAGE_TrigConfxAOD
#define ROOTCORE_PACKAGE_TrigDecisionInterface
#define ROOTCORE_PACKAGE_RoiDescriptor
#define ROOTCORE_PACKAGE_TrigSteeringEvent
#define ROOTCORE_PACKAGE_TrigRoiConversion
#define ROOTCORE_PACKAGE_TrigDecisionTool
#define ROOTCORE_PACKAGE_xAODTrigCalo
#define ROOTCORE_PACKAGE_xAODTrigEgamma
#define ROOTCORE_PACKAGE_TriggerMatchingTool
#define ROOTCORE_PACKAGE_QuickAna
#define ROOTCORE_PACKAGE_RootCoreTest
#define ROOTCORE_PACKAGE_xAODCutFlow
#define ROOTCORE_PACKAGE_TauCorrUncert
#define ROOTCORE_PACKAGE_SUSYTools
#define ROOTCORE_PACKAGE_SemileptonicCorr
#define ROOTCORE_PACKAGE_TrackVertexAssociationTool
#define ROOTCORE_PACKAGE_TrigAnalysisInterfaces
#define ROOTCORE_PACKAGE_xAODTrigMissingET
#define ROOTCORE_PACKAGE_xAODTrigBphys
#define ROOTCORE_PACKAGE_TrigAnalysisTest
#define ROOTCORE_PACKAGE_TrigBunchCrossingTool
#define ROOTCORE_PACKAGE_TrigMuonEfficiency
#define ROOTCORE_PACKAGE_TrigTauMatching
#define ROOTCORE_PACKAGE_ZMassConstraint
#define ROOTCORE_PACKAGE_xAODTrigMinBias
#define ROOTCORE_PACKAGE_xAODHIEvent
#define ROOTCORE_PACKAGE_xAODTrigL1Calo
#define ROOTCORE_PACKAGE_xAODForward
#define ROOTCORE_PACKAGE_checkTrack
#define ROOTCORE_PACKAGE_xAODAssociations
#define ROOTCORE_PACKAGE_xAODBPhys
#define ROOTCORE_PACKAGE_xAODLuminosity
#define ROOTCORE_PACKAGE_xAODMetaDataCnv
#define ROOTCORE_PACKAGE_xAODTrigMuon
#define ROOTCORE_PACKAGE_xAODTrigRinger
#define ROOTCORE_PACKAGE_xAODTriggerCnv

#endif