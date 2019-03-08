# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# compile CXX with /cvmfs/atlas.cern.ch/repo/sw/software/21.2/sw/lcg/releases/gcc/6.2.0/x86_64-slc6/bin/g++
CXX_FLAGS =  -fplugin=/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysisExternals/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/lib/libchecker_gccplugins.so -DNDEBUG -O2 -g -Wall -Wno-long-long -Wno-deprecated -Wno-unused-local-typedefs -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wextra -Werror=return-type -pedantic -fPIC   -std=c++14

CXX_DEFINES = -DATLAS -DATLAS_GAUDI_V21 -DAthProdLib_EXPORTS -DCLHEP_ABS_DEFINED -DCLHEP_MAX_MIN_DEFINED -DCLHEP_SQR_DEFINED -DGAUDI_V20_COMPAT -DHAVE_64_BITS -DHAVE_GAUDI_PLUGINSVC -DHAVE_PRETTY_FUNCTION -DPACKAGE_VERSION=\"AthProd-00-00-01\" -DPACKAGE_VERSION_UQ=AthProd-00-00-01 -DROOTCORE_RELEASE_SERIES=25 -DXAOD_ANALYSIS -D__IDENTIFIER_64BIT__

CXX_INCLUDES = -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/AthAnalysisBaseComps -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/AthenaBaseComps -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/AthenaKernel -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/CxxUtils -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/DataModelRoot -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/GAUDI/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/include -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/SGTools -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/StoreGate -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/AthAllocators -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/AthContainersInterfaces -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/AthContainers -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/AthLinks -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Database/IOVDbDataModel -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/CLIDSvc -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Database/AthenaPOOL/AthenaPoolUtilities -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/DataModel -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Database/AthenaPOOL/DBDataModel -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Database/PersistentDataModel -I/afs/cern.ch/work/m/mizhou/AthProd_XeXe5_2017/source/AthProd -isystem /cvmfs/atlas.cern.ch/repo/sw/software/21.2/sw/lcg/releases/LCG_91/ROOT/6.10.06/x86_64-slc6-gcc62-opt/include -isystem /cvmfs/atlas.cern.ch/repo/sw/software/21.2/sw/lcg/releases/LCG_91/Boost/1.64.0/x86_64-slc6-gcc62-opt/include -isystem /cvmfs/atlas.cern.ch/repo/sw/software/21.2/sw/lcg/releases/LCG_91/tbb/44_20160413/x86_64-slc6-gcc62-opt/include -isystem /cvmfs/atlas.cern.ch/repo/sw/software/21.2/sw/lcg/releases/LCG_91/CORAL/3_1_9/x86_64-slc6-gcc62-opt/include -isystem /cvmfs/atlas.cern.ch/repo/sw/software/21.2/sw/lcg/releases/LCG_91/Python/2.7.13/x86_64-slc6-gcc62-opt/include/python2.7 -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/RootUtils -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/AtlasTest/TestTools -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/AthenaCommon -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/AthToolSupport/AsgTools -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/xAODRootAccess -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODCore -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODEventFormat -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Control/xAODRootAccessInterfaces -isystem /cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/../../../../AthAnalysisExternals/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/include -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Trigger/TrigAnalysis/TrigDecisionTool -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Trigger/TrigConfiguration/TrigConfInterfaces -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Trigger/TrigEvent/TrigDecisionInterface -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Event/EventInfo -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODBase -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODTrigger -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Trigger/TrigConfiguration/TrigConfHLTData -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Trigger/TrigConfiguration/TrigConfL1Data -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Trigger/TrigEvent/TrigNavStructure -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Trigger/TrigEvent/TrigRoiConversion -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Trigger/TrigEvent/TrigSteeringEvent -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/DetectorDescription/RoiDescriptor -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/DetectorDescription/IRegionSelector -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/DetectorDescription/Identifier -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODTracking -isystem /cvmfs/atlas.cern.ch/repo/sw/software/21.2/sw/lcg/releases/LCG_91/eigen/3.2.9/x86_64-slc6-gcc62-opt/include/eigen3 -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/DetectorDescription/GeoPrimitives -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Event/EventPrimitives -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODEventInfo -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODHIEvent -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODCaloEvent -I/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AthAnalysis/21.2.15/InstallArea/x86_64-slc6-gcc62-opt/src/Calorimeter/CaloGeoHelpers 

