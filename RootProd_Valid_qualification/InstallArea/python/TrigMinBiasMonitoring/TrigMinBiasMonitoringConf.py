#Tue Jul 28 00:18:25 2015"""Automatically generated. DO NOT EDIT please"""
from GaudiKernel.GaudiHandles import *
from GaudiKernel.Proxy.Configurable import *

class HLTMinBiasMonTool( ConfigurableAlgTool ) :
  __slots__ = { 
    'MonitorService' : 'MonitorSvc', # str
    'OutputLevel' : 7, # int
    'AuditTools' : False, # bool
    'AuditInitialize' : False, # bool
    'AuditStart' : False, # bool
    'AuditStop' : False, # bool
    'AuditFinalize' : False, # bool
    'EvtStore' : ServiceHandle('StoreGateSvc'), # GaudiHandle
    'DetStore' : ServiceHandle('StoreGateSvc/DetectorStore'), # GaudiHandle
    'UserStore' : ServiceHandle('UserDataSvc/UserDataSvc'), # GaudiHandle
    'ProcessNEvents' : 0, # int
    'histoPathBase' : '', # str
    'PreScale' : 0, # int
    'TriggerChain' : '', # str
    'TriggerGroup' : '', # str
    'ManagerName' : 'AthenaMonManager', # str
    'TrigDecisionTool' : PublicToolHandle(''), # GaudiHandle
    'FilterTools' : PublicToolHandleArray([]), # GaudiHandleArray
    'EnableLumi' : False, # bool
    'DetailLevel' : 1, # int
    'FileKey' : '', # str
    'DataType' : 'userDefined', # str
    'Environment' : 'noOutput', # str
    'CAFonly' : False, # bool
    'TDT' : PublicToolHandle('Trig::TrigDecisionTool/TrigDecisionTool'), # GaudiHandle
    'SPContainerName' : '', # str
    'PixelCLToTCut' : 20.0000, # float
    'TriggerTypeAND' : True, # bool
    'TotalPixelClus' : 3.00000, # float
    'TotalSctSp' : 3.00000, # float
    'TCContainerName' : '', # str
    'max_z0' : 401.000, # float
    'min_pt' : 0.200000, # float
    'TimeCut' : 20.0000, # float
    'EnergyCut' : 0.180180, # float
    'monitoring_minbias' : [  ], # list
    'MinBiasAvailableAlgorithms' : [  ], # list
    'MinBiasHistoTargets' : [  ], # list
    'T2MBTSContainerName' : '', # str
    'MBTSContainerName' : '', # str
    'MBTS_countsSideA' : 0, # int
    'MBTS_countsSideC' : 0, # int
    'BCMContainerName' : 'BCM_RDOs', # str
    'OutOfTimePulsePosition' : 11, # int
    'InTimePulsePosition' : 43, # int
    'WideInTimePulsePosition' : 38, # int
    'NarrowTimeWindow' : 7, # int
    'WideTimeWindow' : 10, # int
    'RdoIndex' : 18, # int
    'LUCID_RawDataContainerName' : '', # str
    'ZDC_ContainerName' : '', # str
    'Calo_ContainerName' : '', # str
    'VCContainerName' : '', # str
    'VColContainerName' : '', # str
    'PixelCLToTCut' : 20.000000, # float
    'InDetTrackParticleContainerName' : '', # str
    'MinBiasRefTrigItem' : '', # str
    'MinBiasEffCuts' : [  ], # list
    'MinBiasPurCuts' : [  ], # list
  }
  _propertyDocDct = { 
    'DetStore' : """ Handle to a StoreGateSvc/DetectorStore instance: it will be used to retrieve data during the course of the job """,
    'UserStore' : """ Handle to a UserDataSvc/UserDataSvc instance: it will be used to retrieve user data during the course of the job """,
    'EvtStore' : """ Handle to a StoreGateSvc instance: it will be used to retrieve data during the course of the job """,
  }
  def __init__(self, name = Configurable.DefaultName, **kwargs):
      super(HLTMinBiasMonTool, self).__init__(name)
      for n,v in kwargs.items():
         setattr(self, n, v)
  def getDlls( self ):
      return 'TrigMinBiasMonitoring'
  def getType( self ):
      return 'HLTMinBiasMonTool'
  pass # class HLTMinBiasMonTool
