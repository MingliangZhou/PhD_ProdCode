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
#include "xAODCaloEvent/CaloClusterContainer.h"
#include "CaloGeoHelpers/CaloSampling.h"

#include "isGoodEvent.C"

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

	char name[50];

	fout = new TFile("myaod.root","recreate");

	tree = new TTree("tree","Data15 ES and MBTS Tree");
	tree->Branch("RunNumber",&RunNumber,"RunNumber/I");
	tree->Branch("lbn",&lbn,"lbn/I");
	tree->Branch("bcid",&bcid,"bcid/I");
	//tree->Branch("L1TE",&L1TE,"L1TE/F");
	tree->Branch("trig",trig,"trig[25]/F");
	tree->Branch("trigL1",trigL1,"trigL1[25]/F");
	tree->Branch("nVtx",&nVtx,"nVtx/I");
	tree->Branch("trkVtx",trkVtx,"trkVtx[nVtx]/I");
	tree->Branch("xVtx",xVtx,"xVtx[nVtx]/F");
	tree->Branch("yVtx",yVtx,"yVtx[nVtx]/F");
	tree->Branch("zVtx",zVtx,"zVtx[nVtx]/F");
	///*
	//tree->Branch("MBTStimeA",&MBTStimeA,"MBTStimeA/F");
	//tree->Branch("MBTStimeC",&MBTStimeC,"MBTStimeC/F");
	//tree->Branch("MBTStimeDiff",&MBTStimeDiff,"MBTStimeDiff/F");
	tree->Branch("MBTScountA",&MBTScountA,"MBTScountA/F");
	tree->Branch("MBTScountC",&MBTScountC,"MBTScountC/F");
	//*/
	/*
	tree->Branch("nEt",&nEt,"nEt/I");
	tree->Branch("et",et,"et[nEt]/F");
	tree->Branch("etaMin",etaMin,"etaMin[nEt]/F");
	tree->Branch("etaMax",etaMax,"etaMax[nEt]/F");
	tree->Branch("layer",layer,"layer[nEt]/F");
	*/
	/*
	tree->Branch("etCos",etCos,"etCos[nEt][7]/F");
	tree->Branch("etSin",etSin,"etSin[nEt][7]/F");
	tree->Branch("nCalo",&nCalo,"nCalo/I");
	tree->Branch("etCalo",etCalo,"etCalo[nCalo]/F");
	tree->Branch("etaCalo",etaCalo,"etaCalo[nCalo]/F");
	tree->Branch("phiCalo",phiCalo,"phiCalo[nCalo]/F");
	*/
	/*
	tree->Branch("etCaloRaw",etCaloRaw,"etCaloRaw[nCalo]/F");
	tree->Branch("etaCaloRaw",etaCaloRaw,"etaCaloRaw[nCalo]/F");
	tree->Branch("phiCaloRaw",phiCaloRaw,"phiCaloRaw[nCalo]/F");
	tree->Branch("etCaloCal",etCaloCal,"etCaloCal[nCalo]/F");
	tree->Branch("etaCaloCal",etaCaloCal,"etaCaloCal[nCalo]/F");
	tree->Branch("phiCaloCal",phiCaloCal,"phiCaloCal[nCalo]/F");
	*/
	///*
	tree->Branch("nTopo",&nTopo,"nTopo/I");
	//tree->Branch("eTopo",eTopo,"eTopo[nTopo]/F");
	tree->Branch("etTopo",etTopo,"etTopo[nTopo]/F");
	tree->Branch("etaTopo",etaTopo,"etaTopo[nTopo]/F");
	tree->Branch("phiTopo",phiTopo,"phiTopo[nTopo]/F");
	tree->Branch("sigClus",sigClus,"sigClus[nTopo]/F");
	tree->Branch("sigCell",sigCell,"sigCell[nTopo]/F");
	//tree->Branch("sigSamp",sigSamp,"sigSamp[nTopo]/F");
	//tree->Branch("eLayer",eLayer,"eLayer[nTopo][24]/F");
	//*/
	//tree->Branch("etaLayer",etaLayer,"etaLayer[nTopo][24]/F");
	//tree->Branch("phiLayer",phiLayer,"phiLayer[nTopo][24]/F");
	//tree->Branch("nTrkOn",&nTrkOn,"nTrkOn/I");
	tree->Branch("nTrk",&nTrk,"nTrk/I");
	tree->Branch("eta",eta,"eta[nTrk]/F");
	tree->Branch("pt",pt,"pt[nTrk]/F");


	return EL::StatusCode::SUCCESS;
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
/*
const xAOD::TrackParticle *MyxAODAnalysis::trackParticle(const xAOD::Vertex *ptrVtx)
{
	typedef ElementLink<xAOD::TrackContainer> Link_t;
	static const char* NAME = "TrackLink_t";
	if( ! ptrVtx->isAvailable< Link_t >( NAME ) ) {
		return 0;
	}
	const Link_t& link = ptrVtx->auxdata< Link_t >( NAME );
	if( ! link.isValid() ) {
		return 0;
	}

	return *link;
}
*/
EL::StatusCode MyxAODAnalysis :: execute ()
{
	if((eventID%1000) == 0) Info("execute()", "Event number = %i", m_eventCounter );
	eventID++;

	
	
	//------------------------------------------------------  
	// Event Infomation
	//------------------------------------------------------ 
	const xAOD::EventInfo* eventInfo = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve( eventInfo, "EventInfo"));
	RunNumber = eventInfo->runNumber();
	EvtNumber = eventInfo->eventNumber();
	lbn  		 = eventInfo->lumiBlock();
	bcid 		 = eventInfo->bcid();

	
	
	//------------------------------------------------------  
	// Trigger Selection
	//------------------------------------------------------ 
	bool pass_trigger_cuts = false;
	if(m_trigDecisionTool->isPassed("HLT_mb_sptrk")){ pass_trigger_cuts =true; }
	//if( !pass_trigger_cuts ) return EL::StatusCode::SUCCESS;
	
	auto chainGroup = m_trigDecisionTool->getChainGroup(".*");
	for(auto &trig : chainGroup->getListOfTriggers())
	{
		//if(m_trigDecisionTool->isPassed(trig)) std::cout<<trig<<std::endl;
	}
	
	
	
	//------------------------------------------------------  
	// L1TE
	//------------------------------------------------------ 
	L1TE = 0;
	const xAOD::EnergySumRoI *ptrOnL1te = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrOnL1te,"LVL1EnergySumRoI"));
	L1TE = ptrOnL1te->energyT()/1000;
	
	
	
	//------------------------------------------------------  
	// ET
	//------------------------------------------------------ 
	nEt = 0;
	const xAOD::HIEventShapeContainer *ptrEvtShpCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrEvtShpCon,"HIEventShape"));
	for(const auto *ptrEvtShp : *ptrEvtShpCon)
	{
		et[nEt] = ptrEvtShp->et()/1000;
		etaMin[nEt] = ptrEvtShp->etaMin();
		etaMax[nEt] = ptrEvtShp->etaMax();
		layer[nEt] = ptrEvtShp->layer();
	
		for(int i=0; i<7; i++)
		{
			etSin[nEt][i] = (ptrEvtShp->etSin()).at(i);
			etCos[nEt][i] = (ptrEvtShp->etCos()).at(i);
		}

		nEt++;
	}
	
	
	
	//------------------------------------------------------  
	// Calo Cluster
	//------------------------------------------------------ 
	nCalo = 0;
	const xAOD::CaloClusterContainer *ptrCaloCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrCaloCon,"HIClusters"));
	for(const auto *ptrCalo : *ptrCaloCon)
	{
		etCalo[nCalo] = ptrCalo->e()/1000;
		etaCalo[nCalo] = ptrCalo->eta();
		phiCalo[nCalo] = ptrCalo->phi();
		
		etCaloRaw[nCalo] = ptrCalo->rawE()/1000;
		etaCaloRaw[nCalo] = ptrCalo->rawEta();
		phiCaloRaw[nCalo] = ptrCalo->rawPhi();
		
		etCaloCal[nCalo] = ptrCalo->calE()/1000;
		etaCaloCal[nCalo] = ptrCalo->calEta();
		phiCaloCal[nCalo] = ptrCalo->calPhi();

		nCalo++;
	}

	//------------------------------------------------------  
	// Topo Cluster
	//------------------------------------------------------ 
	nTopo = 0;
	const xAOD::CaloClusterContainer *ptrTopoCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrTopoCon,"CaloCalTopoClusters"));
	for(const auto *ptrTopo : *ptrTopoCon)
	{
		eTopo[nTopo] = ptrTopo->e()/1000;
		etTopo[nTopo] = ptrTopo->et()/1000;
		etaTopo[nTopo] = ptrTopo->eta();
		phiTopo[nTopo] = ptrTopo->phi();
	
		etTopoRaw[nTopo] = ptrTopo->rawE()/1000;
		etaTopoRaw[nTopo] = ptrTopo->rawEta();
		phiTopoRaw[nTopo] = ptrTopo->rawPhi();
		
		etTopoCal[nTopo] = ptrTopo->calE()/1000;
		etaTopoCal[nTopo] = ptrTopo->calEta();
		phiTopoCal[nTopo] = ptrTopo->calPhi();

		sigClus[nTopo] = ptrTopo->getMomentValue(xAOD::CaloCluster_v1::SIGNIFICANCE);
		sigCell[nTopo] = ptrTopo->getMomentValue(xAOD::CaloCluster_v1::CELL_SIGNIFICANCE);
		sigSamp[nTopo] = ptrTopo->getMomentValue(xAOD::CaloCluster_v1::CELL_SIG_SAMPLING);

		eLayer[nTopo][0] = ptrTopo->eSample(CaloSampling::PreSamplerB)/1000;
		eLayer[nTopo][1] = ptrTopo->eSample(CaloSampling::EMB1)/1000;
		eLayer[nTopo][2] = ptrTopo->eSample(CaloSampling::EMB2)/1000;
		eLayer[nTopo][3] = ptrTopo->eSample(CaloSampling::EMB3)/1000;
		eLayer[nTopo][4] = ptrTopo->eSample(CaloSampling::PreSamplerE)/1000;
		eLayer[nTopo][5] = ptrTopo->eSample(CaloSampling::EME1)/1000;
		eLayer[nTopo][6] = ptrTopo->eSample(CaloSampling::EME2)/1000;
		eLayer[nTopo][7] = ptrTopo->eSample(CaloSampling::EME3)/1000;
		eLayer[nTopo][8] = ptrTopo->eSample(CaloSampling::HEC0)/1000;
		eLayer[nTopo][9] = ptrTopo->eSample(CaloSampling::HEC1)/1000;
		eLayer[nTopo][10] = ptrTopo->eSample(CaloSampling::HEC2)/1000;
		eLayer[nTopo][11] = ptrTopo->eSample(CaloSampling::HEC3)/1000;
		eLayer[nTopo][12] = ptrTopo->eSample(CaloSampling::TileBar0)/1000;
		eLayer[nTopo][13] = ptrTopo->eSample(CaloSampling::TileBar1)/1000;
		eLayer[nTopo][14] = ptrTopo->eSample(CaloSampling::TileBar2)/1000;
		eLayer[nTopo][15] = ptrTopo->eSample(CaloSampling::TileGap1)/1000;
		eLayer[nTopo][16] = ptrTopo->eSample(CaloSampling::TileGap2)/1000;
		eLayer[nTopo][17] = ptrTopo->eSample(CaloSampling::TileGap3)/1000;
		eLayer[nTopo][18] = ptrTopo->eSample(CaloSampling::TileExt0)/1000;
		eLayer[nTopo][19] = ptrTopo->eSample(CaloSampling::TileExt1)/1000;
		eLayer[nTopo][20] = ptrTopo->eSample(CaloSampling::TileExt2)/1000;
		eLayer[nTopo][21] = ptrTopo->eSample(CaloSampling::FCAL0)/1000;
		eLayer[nTopo][22] = ptrTopo->eSample(CaloSampling::FCAL1)/1000;
		eLayer[nTopo][23] = ptrTopo->eSample(CaloSampling::FCAL2)/1000;

		etaLayer[nTopo][0] = ptrTopo->etaSample(CaloSampling::PreSamplerB);
		etaLayer[nTopo][1] = ptrTopo->etaSample(CaloSampling::EMB1);
		etaLayer[nTopo][2] = ptrTopo->etaSample(CaloSampling::EMB2);
		etaLayer[nTopo][3] = ptrTopo->etaSample(CaloSampling::EMB3);
		etaLayer[nTopo][4] = ptrTopo->etaSample(CaloSampling::PreSamplerE);
		etaLayer[nTopo][5] = ptrTopo->etaSample(CaloSampling::EME1);
		etaLayer[nTopo][6] = ptrTopo->etaSample(CaloSampling::EME2);
		etaLayer[nTopo][7] = ptrTopo->etaSample(CaloSampling::EME3);
		etaLayer[nTopo][8] = ptrTopo->etaSample(CaloSampling::HEC0);
		etaLayer[nTopo][9] = ptrTopo->etaSample(CaloSampling::HEC1);
		etaLayer[nTopo][10] = ptrTopo->etaSample(CaloSampling::HEC2);
		etaLayer[nTopo][11] = ptrTopo->etaSample(CaloSampling::HEC3);
		etaLayer[nTopo][12] = ptrTopo->etaSample(CaloSampling::TileBar0);
		etaLayer[nTopo][13] = ptrTopo->etaSample(CaloSampling::TileBar1);
		etaLayer[nTopo][14] = ptrTopo->etaSample(CaloSampling::TileBar2);
		etaLayer[nTopo][15] = ptrTopo->etaSample(CaloSampling::TileGap1);
		etaLayer[nTopo][16] = ptrTopo->etaSample(CaloSampling::TileGap2);
		etaLayer[nTopo][17] = ptrTopo->etaSample(CaloSampling::TileGap3);
		etaLayer[nTopo][18] = ptrTopo->etaSample(CaloSampling::TileExt0);
		etaLayer[nTopo][19] = ptrTopo->etaSample(CaloSampling::TileExt1);
		etaLayer[nTopo][20] = ptrTopo->etaSample(CaloSampling::TileExt2);
		etaLayer[nTopo][21] = ptrTopo->etaSample(CaloSampling::FCAL0);
		etaLayer[nTopo][22] = ptrTopo->etaSample(CaloSampling::FCAL1);
		etaLayer[nTopo][23] = ptrTopo->etaSample(CaloSampling::FCAL2);

		phiLayer[nTopo][0] = ptrTopo->phiSample(CaloSampling::PreSamplerB);
		phiLayer[nTopo][1] = ptrTopo->phiSample(CaloSampling::EMB1);
		phiLayer[nTopo][2] = ptrTopo->phiSample(CaloSampling::EMB2);
		phiLayer[nTopo][3] = ptrTopo->phiSample(CaloSampling::EMB3);
		phiLayer[nTopo][4] = ptrTopo->phiSample(CaloSampling::PreSamplerE);
		phiLayer[nTopo][5] = ptrTopo->phiSample(CaloSampling::EME1);
		phiLayer[nTopo][6] = ptrTopo->phiSample(CaloSampling::EME2);
		phiLayer[nTopo][7] = ptrTopo->phiSample(CaloSampling::EME3);
		phiLayer[nTopo][8] = ptrTopo->phiSample(CaloSampling::HEC0);
		phiLayer[nTopo][9] = ptrTopo->phiSample(CaloSampling::HEC1);
		phiLayer[nTopo][10] = ptrTopo->phiSample(CaloSampling::HEC2);
		phiLayer[nTopo][11] = ptrTopo->phiSample(CaloSampling::HEC3);
		phiLayer[nTopo][12] = ptrTopo->phiSample(CaloSampling::TileBar0);
		phiLayer[nTopo][13] = ptrTopo->phiSample(CaloSampling::TileBar1);
		phiLayer[nTopo][14] = ptrTopo->phiSample(CaloSampling::TileBar2);
		phiLayer[nTopo][15] = ptrTopo->phiSample(CaloSampling::TileGap1);
		phiLayer[nTopo][16] = ptrTopo->phiSample(CaloSampling::TileGap2);
		phiLayer[nTopo][17] = ptrTopo->phiSample(CaloSampling::TileGap3);
		phiLayer[nTopo][18] = ptrTopo->phiSample(CaloSampling::TileExt0);
		phiLayer[nTopo][19] = ptrTopo->phiSample(CaloSampling::TileExt1);
		phiLayer[nTopo][20] = ptrTopo->phiSample(CaloSampling::TileExt2);
		phiLayer[nTopo][21] = ptrTopo->phiSample(CaloSampling::FCAL0);
		phiLayer[nTopo][22] = ptrTopo->phiSample(CaloSampling::FCAL1);
		phiLayer[nTopo][23] = ptrTopo->phiSample(CaloSampling::FCAL2);

		nTopo++;

		//std::cout<<nTopo<<" | "<<etaTopo[nTopo]<<" | "<<phiTopo[nTopo]<<" | "<<ptrTopo->getMomentValue(xAOD::CaloCluster_v1::SIGNIFICANCE)<<std::endl;
		//std::cout<<nTopo<<" | "<<etaTopo[nTopo]<<" | "<<phiTopo[nTopo]<<" | "<<ptrTopo->getMomentValue(xAOD::CaloCluster_v1::FIRST_ETA)<<std::endl;
/*
		std::cout<<nTopo<<" | "<<etaTopo[nTopo]<<" | "<<phiTopo[nTopo]<<" | "<<etTopo[nTopo]<<" | "<<eTopo[nTopo]<<std::endl;
		std::cout<<nTopo<<" | "<<etaTopoRaw[nTopo]<<" | "<<phiTopoRaw[nTopo]<<" | "<<etTopoRaw[nTopo]<<std::endl;
		std::cout<<nTopo<<" | "<<etaTopoCal[nTopo]<<" | "<<phiTopoCal[nTopo]<<" | "<<etTopoCal[nTopo]<<std::endl;
		std::cout<<std::endl;
*/
	}

	//------------------------------------------------------  
	// MBTS
	//------------------------------------------------------ 
	const xAOD::ForwardEventInfoContainer *ptrMbtsCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrMbtsCon,"MBTSForwardEventInfo"));
	for(const auto *ptrMbts : *ptrMbtsCon)
	{
		MBTStimeA = ptrMbts->timeA();
		MBTStimeC = ptrMbts->timeC();
		MBTStimeDiff = ptrMbts->timeDiff();
		MBTScountA = ptrMbts->countA();
		MBTScountC = ptrMbts->countC();
	}
		
	
	
	//------------------------------------------------------  
	// Offline Vertex
	//------------------------------------------------------ 
	nVtx = 0;
	for(int i=0; i<50; i++)
	{
		xVtx[i] = 9999;
		yVtx[i] = 9999;
		zVtx[i] = 9999;
		trkVtx[i] = 9999;
	}
	const xAOD::VertexContainer *ptrOffVtxCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrOffVtxCon,"PrimaryVertices"));
	for(const auto ptrOffVtx : *ptrOffVtxCon)
	{
		if(ptrOffVtx->vertexType() == xAOD::VxType::PriVtx)
		{
			xVtx[0] = ptrOffVtx->x();
			yVtx[0] = ptrOffVtx->y();
			zVtx[0] = ptrOffVtx->z();
			trkVtx[0] = ptrOffVtx->nTrackParticles();
		}
		else
		{
			xVtx[nVtx+1] = ptrOffVtx->x();
			yVtx[nVtx+1] = ptrOffVtx->y();
			zVtx[nVtx+1] = ptrOffVtx->z();
			trkVtx[nVtx+1] = ptrOffVtx->nTrackParticles();
			nVtx++;
		}
	}
	nVtx++;
  
	
	
	//------------------------------------------------------  
	// Online Tracks
	//------------------------------------------------------ 
	double nTrkOn = 0;
	const xAOD::TrigTrackCountsContainer *ptrOnTrkCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrOnTrkCon,"HLT_xAOD__TrigTrackCountsContainer_trackcounts"));
	for(const auto *ptrOnTrk : *ptrOnTrkCon)
	{
		nTrkOn=ptrOnTrk->z0_ptSumEntries(200,0.4,xAOD::TrigHistoCutType::BELOW_X_ABOVE_Y);
	}
	
	
	
	//------------------------------------------------------  
	// Offline Tracks
	//------------------------------------------------------ 
	nTrk = 0;
	const xAOD::TrackParticleContainer *ptrTrkCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrTrkCon,"InDetTrackParticles"));
	for(const auto *ptrTrk : *ptrTrkCon)
	{
		const xAOD::Vertex *ptrVtx = vertexParticle(ptrTrk);
		/*
		if(!ptrVtx) continue;
		if(fabs(ptrVtx->z()-zVtx[0])>0.0001) continue;

		if(ptrTrk->pt()/1000.<0.4 || fabs(ptrTrk->eta())>2.5) continue;
		if(ptrTrk->auxdata<unsigned char>("numberOfPixelHits")<1) continue;
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")<6) continue;
		if(fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-zVtx[0]))>1.5) continue;
		if(fabs(ptrTrk->d0())>1.5) continue;
		*/

		pt[nTrk] = ptrTrk->pt()/1000.;
		eta[nTrk] = ptrTrk->eta();
		phi[nTrk] = ptrTrk->phi();
		chg[nTrk] = ptrTrk->charge();
		z0[nTrk] = ptrTrk->z0()+ptrTrk->vz();
		theta[nTrk] = ptrTrk->theta();
		d0[nTrk] = ptrTrk->d0();
		nTrk++;
	}

	
	
	//------------------------------------------------------  
	// Event Selection
	//------------------------------------------------------ 
	//if(nTrk==0) return EL::StatusCode::SUCCESS;
	if(nTrk>50) return EL::StatusCode::SUCCESS;
	m_eventCounter++;




	//------------------------------------------------------  
	// Fill All Triggers
	//------------------------------------------------------ 
	char nameTrig[100];
	bool isTrig;
	for(int i=0; i<25; i++)
	{
		trig[i] = 0;
		if(i==0) sprintf(nameTrig,"L1_RD0_FILLED");
		if(i==1) sprintf(nameTrig,"L1_ZDC_A_C");
		if(i==2) sprintf(nameTrig,"L1_ZDC_AND");
		if(i==3) sprintf(nameTrig,"L1_ZDC_A");
		if(i==4) sprintf(nameTrig,"L1_ZDC_C");
		if(i==5) sprintf(nameTrig,"L1_MBTS_1");
		if(i==6) sprintf(nameTrig,"L1_MBTS_1_1");
		if(i==7) sprintf(nameTrig,"L1_MBTS_2_2");
		if(i==8) sprintf(nameTrig,"L1_TE5");
		if(i==9) sprintf(nameTrig,"L1_TE10");
		if(i==10) sprintf(nameTrig,"L1_TE20");
		if(i==11) sprintf(nameTrig,"L1_TE30");
		if(i==12) sprintf(nameTrig,"L1_TE40");
		if(i==13) sprintf(nameTrig,"L1_TE50");
		if(i==14) sprintf(nameTrig,"L1_TE60");
		if(i==15) sprintf(nameTrig,"L1_TE70");
		/*
		if(i==16) sprintf(nameTrig,"HLT_hi_v2_th10_L1TE50");
		if(i==17) sprintf(nameTrig,"HLT_hi_v3_th10_L1TE50");
		if(i==18) sprintf(nameTrig,"HLT_hi_v2_th13_L1TE50");
		if(i==19) sprintf(nameTrig,"HLT_hi_v3_th13_L1TE50");
		if(i==20) sprintf(nameTrig,"HLT_hi_v2_th14_L1TE50");
		if(i==21) sprintf(nameTrig,"HLT_hi_v3_th14_L1TE50");
		if(i==22) sprintf(nameTrig,"HLT_hi_v2_th15_L1TE50");
		if(i==23) sprintf(nameTrig,"HLT_hi_v3_th15_L1TE50");
		if(i==24) sprintf(nameTrig,"HLT_hi_v2_th16_L1TE50");
		*/
		if(i==16) sprintf(nameTrig,"L1_ZDC_A_C_VTE50");
		if(i==17) sprintf(nameTrig,"L1_TE5_VTE200");
		if(i==18) sprintf(nameTrig,"HLT_noalg_mb_L1TE50");
		if(i==19) sprintf(nameTrig,"HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50");
		if(i==20) sprintf(nameTrig,"HLT_mb_sp");
		if(i==21) sprintf(nameTrig,"HLT_hi_th1_ucc_L1TE14000");
		if(i==22) sprintf(nameTrig,"HLT_hi_th2_ucc_L1TE14000");
		if(i==23) sprintf(nameTrig,"HLT_hi_th3_ucc_L1TE14000");
		if(i==24) sprintf(nameTrig,"L1_ZDC_XOR");
		chainGroup = m_trigDecisionTool->getChainGroup(nameTrig);
		if(chainGroup->getPrescale()==-1) trig[i] = 0;
		else if(m_trigDecisionTool->isPassed(nameTrig)) trig[i] = chainGroup->getPrescale();
		else trig[i] = -1.*chainGroup->getPrescale();
		trigL1[i] = (chainGroup->isPassedBits() & TrigDefs::L1_isPassedBeforePrescale);
	}

	tree->Fill();

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
