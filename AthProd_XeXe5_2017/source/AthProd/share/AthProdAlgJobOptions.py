#Skeleton joboption for a simple analysis job

#---- Minimal joboptions -------

theApp.EvtMax=-1                                         #how many events to run over. Set to -1 for all events.
jps.AthenaCommonFlags.FilesInput = ["/afs/cern.ch/work/m/mizhou/INPUT_test/data17_XeXe5_MinBias.root"]   #insert your list of input files here (do this before next lines)

#Now choose your read mode (POOL, xAOD, or TTree):

#POOL:
#import AthenaPoolCnvSvc.ReadAthenaPool                   #sets up reading of any POOL files (but POOL is slow)

#xAOD:
import AthenaRootComps.ReadAthenaxAODHybrid               #FAST xAOD reading!

#TTree:
#import AthenaRootComps.ReadAthenaRoot                    #read a flat TTree, very fast, but no EDM objects
#svcMgr.EventSelector.TupleName="MyTree"                  #You usually must specify the name of the tree (default: CollectionTree)

#algseq = CfgMgr.AthSequencer("AthAlgSeq")
athAlgSeq += CfgMgr.AthProdAlg()                           #adds an instance of your alg to the main alg sequence

#-------------------------------


#note that if you edit the input files after this point you need to pass the new files to the EventSelector:
#like this: svcMgr.EventSelector.InputCollections = ["new","list"] 





##--------------------------------------------------------------------
## This section shows up to set up a HistSvc output stream for outputing histograms and trees
## See https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/AthAnalysisBase#How_to_output_trees_and_histogra for more details and examples

#if not hasattr(svcMgr, 'THistSvc'): svcMgr += CfgMgr.THistSvc() #only add the histogram service if not already present (will be the case in this jobo)
#svcMgr.THistSvc.Output += ["MYSTREAM DATAFILE='myfile.root' OPT='RECREATE'"] #add an output root file stream

##--------------------------------------------------------------------


##--------------------------------------------------------------------
## The lines below are an example of how to create an output xAOD
## See https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/AthAnalysisBase#How_to_create_an_output_xAOD for more details and examples

#from OutputStreamAthenaPool.MultipleStreamManager import MSMgr
#xaodStream = MSMgr.NewPoolRootStream( "StreamXAOD", "xAOD.out.root" )

##EXAMPLE OF BASIC ADDITION OF EVENT AND METADATA ITEMS
##AddItem and AddMetaDataItem methods accept either string or list of strings
#xaodStream.AddItem( ["xAOD::JetContainer#*","xAOD::JetAuxContainer#*"] ) #Keeps all JetContainers (and their aux stores)
#xaodStream.AddMetaDataItem( ["xAOD::TriggerMenuContainer#*","xAOD::TriggerMenuAuxContainer#*"] )
#ToolSvc += CfgMgr.xAODMaker__TriggerMenuMetaDataTool("TriggerMenuMetaDataTool") #MetaDataItems needs their corresponding MetaDataTool
#svcMgr.MetaDataSvc.MetaDataTools += [ ToolSvc.TriggerMenuMetaDataTool ] #Add the tool to the MetaDataSvc to ensure it is loaded

##EXAMPLE OF SLIMMING (keeping parts of the aux store)
#xaodStream.AddItem( ["xAOD::ElectronContainer#Electrons","xAOD::ElectronAuxContainer#ElectronsAux.pt.eta.phi"] ) #example of slimming: only keep pt,eta,phi auxdata of electrons

##EXAMPLE OF SKIMMING (keeping specific events)
#xaodStream.AddAcceptAlgs( "AthProdAlg" ) #will only keep events where 'setFilterPassed(false)' has NOT been called in the given algorithm

##--------------------------------------------------------------------


include("AthAnalysisBaseComps/SuppressLogging.py")              #Optional include to suppress as much athena output as possible. Keep at bottom of joboptions so that it doesn't suppress the logging of the things you have configured above
svcMgr.THistSvc.Output += ["MYSTREAM DATAFILE='hist.root' OPT='RECREATE'"]
