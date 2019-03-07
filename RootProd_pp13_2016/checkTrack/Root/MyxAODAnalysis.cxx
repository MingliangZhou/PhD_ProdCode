#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>
#include <checkTrack/MyxAODAnalysis.h>

#include "xAODRootAccess/tools/Message.h"

#include "xAODEventInfo/EventInfo.h"
#include "xAODTrigMinBias/TrigSpacePointCountsContainer.h"
#include "xAODTrigMinBias/TrigTrackCountsContainer.h"
#include "xAODTrigMinBias/TrigHisto2D.h"
#include "xAODTrigger/EnergySumRoI.h"
#include "xAODTracking/TrackParticleContainer.h"
#include "xAODTracking/VertexContainer.h"
#include "xAODHIEvent/HIEventShape.h"
#include "xAODHIEvent/HIEventShapeContainer.h"
#include "xAODForward/ForwardEventInfoContainer.h"
#include "xAODForward/MBTSModuleContainer.h"
#include "xAODForward/ZdcModuleContainer.h"
#include "xAODCaloEvent/CaloClusterContainer.h"
#include "CaloGeoHelpers/CaloSampling.h"
#include "xAODJet/JetContainer.h"

#include "xAODTruth/TruthParticleContainer.h"
#include "xAODTruth/TruthVertex.h"

#include "checkTrack/isGoodEvent_pp2015.C"

int runNo;
int lbNo;
int bcid;
Long64_t evtNo;
bool TriggerL1[30];
float Trigger[30];
float L1TE;
float L1TEres;
int nSP;
float zPriVtx;
int nTrk;



bool trackSelection(const xAOD::TrackParticle*, float);

char name[100];
const double PI = TMath::Pi();

#define EL_RETURN_CHECK( CONTEXT, EXP )                    \
   do {                                                    \
      if( ! EXP.isSuccess() ) {                            \
         Error( CONTEXT,                                   \
               XAOD_MESSAGE( "Failed to execute: %s" ),    \
               #EXP );                                     \
         return EL::StatusCode::FAILURE;                   \
      }                                                    \
   } while( false )



// this is needed to distribute the algorithm to the workers
ClassImp(MyxAODAnalysis)



MyxAODAnalysis :: MyxAODAnalysis ()
{
    // Here you put any code for the base initialization of variables,
    // e.g. initialize all pointers to 0.  Note that you should only put
    // the most basic initialization here, since this method will be
    // called on both the submission and the worker node.  Most of your
    // initialization code will go into histInitialize() and
    // initialize().
}



EL::StatusCode MyxAODAnalysis :: setupJob (EL::Job& job)
{
    // Here you put code that sets up the job on the submission object
    // so that it is ready to work with your algorithm, e.g. you can
    // request the D3PDReader service or add output files.  Any code you
    // put here could instead also go into the submission script.  The
    // sole advantage of putting it here is that it gets automatically
    // activated/deactivated when you add/remove the algorithm from your
    // job, which may or may not be of value to you.

    job.useXAOD ();
    EL_RETURN_CHECK( "setupJob()", xAOD::Init() );  


    return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: histInitialize ()
{
    // Here you do everything that needs to be done at the very
    // beginning on each worker node, e.g. create histograms and output
    // trees.  This method gets called before any input files are
    // connected.
    return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: fileExecute ()
{
	// Here you do everything that needs to be done exactly once for every
	// single file, e.g. collect a list of all lumi-blocks processed
	return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: changeInput (bool firstFile)
{
	// Here you do everything you need to do when we change input files,
	// e.g. resetting branch addresses on trees.  If you are using
	// D3PDReader or a similar service this method is not needed.
	return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: initialize ()
{
	TH1::AddDirectory(kFALSE);
	TH2::AddDirectory(kFALSE);

	m_event = wk()->xaodEvent();
	Info("initialize()", "Number of events = %lli", m_event->getEntries() ); // print long long int

	m_eventCounter=0;
	eventID = 0;

	// Trigger setup

	m_trigConfigTool = new TrigConf::xAODConfigTool("xAODConfigTool"); // gives us access to the meta-data
	EL_RETURN_CHECK( "initialize", m_trigConfigTool->initialize() );

	ToolHandle< TrigConf::ITrigConfigTool > trigConfigHandle( m_trigConfigTool );
	if (trigConfigHandle->initialize().isFailure()) {
		if (trigConfigHandle->initialize().isFailure()) {
			Error("initialize()","Failed to initialize trigger config handle");
			return EL::StatusCode::FAILURE;
		}
	}

	m_trigDecisionTool = new Trig::TrigDecisionTool("TrigDecisionTool");
	EL_RETURN_CHECK( "initialize", m_trigDecisionTool->setProperty( "ConfigTool", trigConfigHandle ) ); // connect the TrigDecisionTool to the ConfigTool
	EL_RETURN_CHECK( "initialize", m_trigDecisionTool->setProperty( "TrigDecisionKey", "xTrigDecision" ) );
	EL_RETURN_CHECK( "initialize", m_trigDecisionTool->initialize() );

	fout = new TFile("myaod.root","recreate");
	tree = new TTree("tree","Data16 pp13TeV");
	tree->Branch("runNo", 	 	 &runNo,   	   "runNo/I");
	tree->Branch("lbNo", 	 		 &lbNo,   		 "lbNo/I");
	tree->Branch("bcid", 	 		 &bcid,   		 "bcid/I");
	tree->Branch("evtNo", 	 	 &evtNo,  	 	 "evtNo/L");
	tree->Branch("TriggerL1",  TriggerL1,    "TriggerL1[30]/O");
	tree->Branch("Trigger", 	 Trigger,   	 "Trigger[30]/F");
	tree->Branch("L1TE", 	 		 &L1TE,     	 "L1TE/F");
	tree->Branch("L1TEres", 	 &L1TEres,     "L1TEres/F");
	tree->Branch("nSP", 	 		 &nSP,     		 "nSP/I");
	tree->Branch("zPriVtx", 	 &zPriVtx,     "zPriVtx/F");
	tree->Branch("nTrk", 			 &nTrk,        "nTrk/I");


	return EL::StatusCode::SUCCESS;
}



bool trackSelection(const xAOD::TrackParticle* ptrTrk, float zPriVtx)
{ 
	if(ptrTrk->auxdata<unsigned char>("numberOfPixelHits")<1) return 0;
	if(ptrTrk->pt()/1000<0.3)
	{ 
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")+ptrTrk->auxdata<unsigned char>("numberOfSCTDeadSensors")<2) return 0;
	}
	else if(ptrTrk->pt()/1000<0.4)
	{ 
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")+ptrTrk->auxdata<unsigned char>("numberOfSCTDeadSensors")<4) return 0;
	}
	else
	{ 
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")+ptrTrk->auxdata<unsigned char>("numberOfSCTDeadSensors")<6) return 0;
	}
	if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfInnermostPixelLayerHits")>=1) ;
	else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfNextToInnermostPixelLayerHits")>=1) ;
	else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")==0) ;
	else return 0;
	if(!(ptrTrk->pt()/1000.<10 || TMath::Prob(ptrTrk->chiSquared(),ptrTrk->numberDoF())>0.01)) return 0;
	if(fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-zPriVtx))>=1.5) return 0;
	if(fabs(ptrTrk->d0())>=1.5) return 0;
	if(fabs(ptrTrk->eta())>=2.5) return 0;
	return 1;
}



const xAOD::Vertex *MyxAODAnalysis::vertexParticle(const xAOD::TrackParticle *ptrTrk)
{
	typedef ElementLink<xAOD::VertexContainer> Link_t;
	static const char* NAME = "vertexLink";
	if( ! ptrTrk->isAvailable< Link_t >( NAME ) ) {
		return 0;
	}
	const Link_t& link = ptrTrk->auxdata< Link_t >( NAME );
	if( ! link.isValid() ) {
		return 0;
	}

	return *link;
}



EL::StatusCode MyxAODAnalysis :: execute ()
{
	if((eventID%1000) == 0) Info("execute()", "Event number = %i", m_eventCounter );
	eventID++;

	//------------------------------------------------------  
	// Fill All Triggers
	//------------------------------------------------------ 
	char nameTrigL1[100];
	char nameTrig[100];
	for(int i=0; i<30; i++) 
	{
		TriggerL1[i] = false;
		if(i==0) sprintf(nameTrigL1,"L1_MBTS_1_1");
		if(i==1) sprintf(nameTrigL1,"L1_TE5");
		if(i==2) sprintf(nameTrigL1,"L1_TE10");
		if(i==3) sprintf(nameTrigL1,"L1_TE10.0ETA24");
		if(i==4) sprintf(nameTrigL1,"L1_TE20");
		if(i==5) sprintf(nameTrigL1,"L1_TE20.0ETA24");
		if(i==6) sprintf(nameTrigL1,"L1_TE30");
		if(i==7) sprintf(nameTrigL1,"L1_TE30.0ETA24");
		if(i>7) continue;
		if(m_trigDecisionTool->getChainGroup(nameTrigL1)->isPassedBits() & TrigDefs::L1_isPassedBeforePrescale) TriggerL1[i] = true;
	}
	for(int i=0; i<30; i++) 
	{
		Trigger[i] = -1;
		if(i==0) sprintf(nameTrig,"HLT_noalg_mb_L1TE10");
		if(i==1) sprintf(nameTrig,"HLT_noalg_mb_L1TE10.0ETA24");
		if(i==2) sprintf(nameTrig,"HLT_noalg_mb_L1TE30");
		if(i==3) sprintf(nameTrig,"HLT_noalg_mb_L1TE30.0ETA24");
		if(i==4) sprintf(nameTrig,"HLT_mb_sp1800_hmtperf_L1TE5");
		if(i==5) sprintf(nameTrig,"HLT_mb_sp900_trk60_hmt_L1MBTS_1_1");
		if(i==6) sprintf(nameTrig,"HLT_mb_sp1000_trk70_hmt_L1TE5");
		if(i==7) sprintf(nameTrig,"HLT_mb_sp1000_pusup450_trk70_hmt_L1TE5");
		if(i==8) sprintf(nameTrig,"HLT_mb_sp1400_trk90_hmt_L1TE10");
		if(i==9) sprintf(nameTrig,"HLT_mb_sp1400_pusup550_trk90_hmt_L1TE10");
		if(i==10) sprintf(nameTrig,"HLT_mb_sp1400_pusup550_trk90_hmt_L1TE10.0ETA24");
		if(i==11) sprintf(nameTrig,"HLT_mb_sp1600_trk100_hmt_L1TE10");
		if(i==12) sprintf(nameTrig,"HLT_mb_sp1600_trk100_hmt_L1TE20");
		if(i==13) sprintf(nameTrig,"HLT_mb_sp1600_pusup600_trk100_hmt_L1TE10");
		if(i==14) sprintf(nameTrig,"HLT_mb_sp1600_pusup600_trk100_hmt_L1TE20");
		if(i==15) sprintf(nameTrig,"HLT_mb_sp1500_pusup700_trk100_hmt_L1TE20.0ETA24");
		if(i==16) sprintf(nameTrig,"HLT_mb_sp1800_trk110_hmt_L1TE10");
		if(i==17) sprintf(nameTrig,"HLT_mb_sp1800_trk110_hmt_L1TE20");
		if(i==18) sprintf(nameTrig,"HLT_mb_sp1800_pusup700_trk110_hmt_L1TE10");
		if(i==19) sprintf(nameTrig,"HLT_mb_sp1800_pusup700_trk110_hmt_L1TE20");
		if(i>19) continue;
		if(m_trigDecisionTool->isPassed(nameTrig)) Trigger[i] = (m_trigDecisionTool->getChainGroup(nameTrig))->getPrescale();
	}



	//------------------------------------------------------  
	// Event Infomation
	//------------------------------------------------------
	const xAOD::EventInfo* eventInfo = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve( eventInfo, "EventInfo"));
	runNo = eventInfo->runNumber();
	lbNo = eventInfo->lumiBlock();
	bcid = eventInfo->bcid();
	evtNo = eventInfo->eventNumber();

	if(eventInfo->errorState(xAOD::EventInfo::LAr)==xAOD::EventInfo::Error) return EL::StatusCode::SUCCESS;
	if(eventInfo->errorState(xAOD::EventInfo::Tile)==xAOD::EventInfo::Error) return EL::StatusCode::SUCCESS;
	if(eventInfo->errorState(xAOD::EventInfo::SCT)==xAOD::EventInfo::Error) return EL::StatusCode::SUCCESS;
	if(eventInfo->isEventFlagBitSet(xAOD::EventInfo::Core, 18)) return EL::StatusCode::SUCCESS;



	//------------------------------------------------------  
	// L1TE
	//------------------------------------------------------ 
	///*
	L1TE = 0;
	L1TEres = 0;
	const xAOD::EnergySumRoI *ptrOnL1te = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrOnL1te,"LVL1EnergySumRoI"));
	L1TE = ptrOnL1te->energyT()/1000;
	L1TEres = ptrOnL1te->energyTRestricted()/1000;
	//*/



	//------------------------------------------------------  
	// Space Point
	//------------------------------------------------------ 
	nSP = 0;
	const xAOD::TrigSpacePointCountsContainer *ptrSpCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrSpCon,"HLT_xAOD__TrigSpacePointCountsContainer_spacepoints"));
	for(const auto ptrSp : *ptrSpCon)
	{
		nSP += ptrSp->sctSpEndcapC() + ptrSp->sctSpBarrel() + ptrSp->sctSpEndcapA();
	}


/*
	//------------------------------------------------------  
	// Offline Vertex
	//------------------------------------------------------ 
	bool hasPriVtx = false;
	zPriVtx = 0;
	const xAOD::Vertex *ptrVtx = 0;
	const xAOD::VertexContainer *ptrOffVtxCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrOffVtxCon,"PrimaryVertices"));
	for(const auto ptrOffVtx : *ptrOffVtxCon)
	{
		if(ptrOffVtx->vertexType() == xAOD::VxType::PriVtx)
		{
			hasPriVtx = true;
			zPriVtx = ptrOffVtx->z();
			break;
		}
	}
	if(!hasPriVtx) return EL::StatusCode::SUCCESS;



	//------------------------------------------------------  
	// Offline Tracks
	//------------------------------------------------------ 
	nTrk = 0;
	const xAOD::TrackParticleContainer *ptrTrkCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrTrkCon,"InDetTrackParticles"));
	for(const auto* ptrTrk : *ptrTrkCon)
	{
		ptrVtx = vertexParticle(ptrTrk);
		if(!ptrVtx) continue;
		if(fabs(ptrVtx->z()-zPriVtx)>0.0001) continue;
		if(!trackSelection(ptrTrk, zPriVtx)) continue;
		if(ptrTrk->pt()/1000<0.4) continue;

		nTrk++;
	}
*/

	tree->Fill();

	m_eventCounter++;

	return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: postExecute ()
{
	// Here you do everything that needs to be done after the main event
	// processing.  This is typically very rare, particularly in user
	// code.  It is mainly used in implementing the NTupleSvc.
	return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: finalize ()
{
	fout->cd();
	tree->Write();
	fout->Close();
	
	std::cout<<"We have "<<eventID<<std::endl;
	std::cout<<"We pass "<<m_eventCounter<<std::endl;
	return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: histFinalize ()
{
	// This method is the mirror image of histInitialize(), meaning it
	// gets called after the last event has been processed on the worker
	// node and allows you to finish up any objects you created in
	// histInitialize() before they are written to disk.  This is
	// actually fairly rare, since this happens separately for each
	// worker node.  Most of the time you want to do your
	// post-processing on the submission node after all your histogram
	// outputs have been merged.  This is different from finalize() in
	// that it gets called on all worker nodes regardless of whether
	// they processed input events.
	return EL::StatusCode::SUCCESS;
}
