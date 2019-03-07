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

#include "checkTrack/isGoodEvent_PbPb2015.C"

const double etCut[50] ={0,0.34,0.48,0.42,0.48,0.28,0.32,0.38,0.6,0.58,0.13,0.17,0.28,0.11,0.14,0.14,0.34,0.39,0.28,0.3,0.3,0.34,0.37,0.38,0.4,0.38,0.37,0.36,0.34,0.32,0.3,0.25,0.26,0.29,0.14,0.12,0.1,0.1,0.16,0.32,0.32,0.48,0.4,0.35,0.34,0.98,0.44,0.31,0.41,0};

TH2F* hComp;

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

	fout = new TFile("myaod.root","recreate");

	hComp = new TH2F("hComp","",1000,-0.0005,0.0005,800,-1,7);

	tree = new TTree("tree","Data15 5.02TeV PbPb");
	tree->Branch("runNo",					&runNo,						"runNo/I");
	tree->Branch("lbNo",					&lbNo,						"lbNo/I");
	tree->Branch("bcid",					&bcid,						"bcid/I");
	tree->Branch("isPassVTE50",		&isPassVTE50,			"isPassVTE50/O");
	tree->Branch("preScaleVTE50",	&preScaleVTE50,		"preScaleVTE50/F");
	tree->Branch("isPassTE50",		&isPassTE50,			"isPassTE50/O");
	tree->Branch("preScaleTE50",	&preScaleTE50,		"preScaleTE50/F");
	tree->Branch("hasPriVtx",			&hasPriVtx,				"hasPriVtx/O");
	tree->Branch("zPriVtx",				&zPriVtx,					"zPriVtx/F");
	tree->Branch("fcalEtA",				&fcalEtA,					"fcalEtA/F");
	tree->Branch("fcalEtC",				&fcalEtC,					"fcalEtC/F");
	tree->Branch("isPassGap",			&isPassGap,				"isPassGap/O");
	tree->Branch("isPassPileUp",	&isPassPileUp,		"isPassPileUp/O");

	tree->Branch("mbtsTimeA",			&mbtsTimeA,				"mbtsTimeA/F");
	tree->Branch("mbtsTimeC",			&mbtsTimeC,				"mbtsTimeC/F");
	tree->Branch("gapA",					&gapA,						"gapA/F");
	tree->Branch("gapC",					&gapC,						"gapC/F");
	tree->Branch("tagGRL",				&tagGRL,					"tagGRL/I");
	tree->Branch("tagError",			&tagError,				"tagError/I");
	
	/*
	tree->Branch("evtNo",					&evtNo,						"evtNo/l");
	tree->Branch("xVtx",					xVtx,							"xVtx[2]/F");
	tree->Branch("yVtx",					yVtx,							"yVtx[2]/F");
	tree->Branch("zVtx",					zVtx,							"zVtx[2]/F");
	tree->Branch("typeVtx",				typeVtx,					"typeVtx[2]/I");
	tree->Branch("nTrk",					&nTrk,						"nTrk/I");
	tree->Branch("d0trk",					d0trk,						"d0trk[nTrk]/F");
	tree->Branch("z0trk",					z0trk,						"z0trk[nTrk]/F");
	*/

	puTool = new HIPileupTool("puTool");
 	puTool->setProperty("inpFilePath","$ROOTCOREBIN/data/HIPileupTool/HIRun2PileUp_PbPb5p02_v2.root");
	puTool->initialize();

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
	// Fill All Triggers
	//------------------------------------------------------ 
	isPassVTE50 = false;
	isPassTE50 = false;
	preScaleVTE50 = -1;
	preScaleTE50 = -1;
	if(m_trigDecisionTool->isPassed("HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50"))
	//if(m_trigDecisionTool->isPassed("HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50_OVERLAY"))
	{
		isPassVTE50 = true;
		preScaleVTE50 = m_trigDecisionTool->getChainGroup("HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50")->getPrescale();
		//preScaleVTE50 = m_trigDecisionTool->getChainGroup("HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50_OVERLAY")->getPrescale();
	}
	if(m_trigDecisionTool->isPassed("HLT_noalg_mb_L1TE50"))
	//if(m_trigDecisionTool->isPassed("HLT_noalg_L1TE50_OVERLAY"))
	{
		isPassTE50 = true;
		preScaleTE50 = m_trigDecisionTool->getChainGroup("HLT_noalg_mb_L1TE50")->getPrescale();
		//preScaleTE50 = m_trigDecisionTool->getChainGroup("HLT_noalg_L1TE50_OVERLAY")->getPrescale();
	}
	
	//if(!isPassVTE50 && !isPassTE50) return EL::StatusCode::SUCCESS;


	
	//------------------------------------------------------  
	// Event Infomation
	//------------------------------------------------------ 
	const xAOD::EventInfo* eventInfo = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve( eventInfo, "EventInfo"));
	runNo = eventInfo->runNumber();
	lbNo = eventInfo->lumiBlock();
	bcid = eventInfo->bcid();
	evtNo = eventInfo->eventNumber();

	tagGRL = 0;
	tagError = 0;
	if(!isGoodEvent_PbPb2015(runNo,lbNo,bcid)) tagGRL = 1;

	if(eventInfo->errorState(xAOD::EventInfo::LAr)==xAOD::EventInfo::Error) tagError = 1;
	if(eventInfo->errorState(xAOD::EventInfo::Tile)==xAOD::EventInfo::Error) tagError = 1;
	if(eventInfo->errorState(xAOD::EventInfo::SCT)==xAOD::EventInfo::Error) tagError = 1;
	if(eventInfo->isEventFlagBitSet(xAOD::EventInfo::Core, 18)) tagError = 1;
/*
	if(eventInfo->errorState(xAOD::EventInfo::LAr)==xAOD::EventInfo::Error) return EL::StatusCode::SUCCESS;
	if(eventInfo->errorState(xAOD::EventInfo::Tile)==xAOD::EventInfo::Error) return EL::StatusCode::SUCCESS;
	if(eventInfo->errorState(xAOD::EventInfo::SCT)==xAOD::EventInfo::Error) return EL::StatusCode::SUCCESS;
	if(eventInfo->isEventFlagBitSet(xAOD::EventInfo::Core, 18)) return EL::StatusCode::SUCCESS;
*/
/*
	if(tagGRL==1) std::cout<<"GRL: "<<tagGRL<<" | "<<tagError<<std::endl;
	if(tagError==1) std::cout<<"Error: "<<tagError<<" | "<<tagGRL<<std::endl;
	if(tagGRL==1 || tagError==1) std::cout<<std::endl;
*/

	//------------------------------------------------------  
	// ET
	//------------------------------------------------------ 
	fcalEtA = 0;
	fcalEtC = 0;
	const xAOD::HIEventShapeContainer *ptrEvtShpCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrEvtShpCon,"HIEventShape"));
	const xAOD::ZdcModuleContainer* ptrZdcCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrZdcCon,"ZdcModules"));
	for(const auto *ptrEvtShp : *ptrEvtShpCon)
	{
		if(ptrEvtShp->layer()==21 || ptrEvtShp->layer()==22 || ptrEvtShp->layer()==23)
		{
			//if(fabs((ptrEvtShp->etaMin()+ptrEvtShp->etaMax())/2.0)<3.2) continue;
			if((ptrEvtShp->etaMin()+ptrEvtShp->etaMax())/2>0) fcalEtA += ptrEvtShp->et()/1000000.;
			if((ptrEvtShp->etaMin()+ptrEvtShp->etaMax())/2<0) fcalEtC += ptrEvtShp->et()/1000000.;
		}
	}
	isPassPileUp = true;
	isPassPileUp = !(puTool->is_pileup(*ptrEvtShpCon, *ptrZdcCon));

	//if(fcalEtA+fcalEtC>0.0055) return EL::StatusCode::SUCCESS;
///*
	// test
	// test
	// test
	float b_fcalet = 0;
	const xAOD::HIEventShapeContainer* summary_container=0;
	if ( !m_event->retrieve(summary_container,"CaloSums").isSuccess() )
	{
		Error("execute()", "Failed to retrieve CaloSums container. Exiting." );
		return EL::StatusCode::FAILURE;
	}
	for(unsigned int i=0; i<summary_container->size(); i++)
	{
		const xAOD::HIEventShape* sh = (*summary_container)[i];
		std::string summary;
		if(sh->isAvailable<std::string>("Summary")) {
			summary=sh->auxdata<std::string>("Summary");
			if(summary.compare("FCal") == 0) {
				b_fcalet = sh->et()/1000000;
			}
		}
	}

	float fcal = 0;
	const unsigned int FCAL_LAYER=14680064;
	for(unsigned int k=0; k < summary_container->size(); k++)  {
		if(summary_container->at(k)->layer()==FCAL_LAYER)
		{
			fcal = summary_container->at(k)->et()/1000000;
		}
	}
	//std::cout<<fcalEtA+fcalEtC<<" | "<<b_fcalet<<" | "<<fcal<<" | "<<fabs(fcalEtA+fcalEtC-b_fcalet)/b_fcalet*100<<std::endl;
	if(fcalEtA+fcalEtC-b_fcalet>=0.0005) hComp->Fill(0.00049,b_fcalet);
	else if(fcalEtA+fcalEtC-b_fcalet<=-0.0005) hComp->Fill(-0.00049,b_fcalet);
	else hComp->Fill(fcalEtA+fcalEtC-b_fcalet,b_fcalet);

	// test
	// test
	// test
//*/

	//------------------------------------------------------  
	// Topo Cluster
	//------------------------------------------------------ 
	gapA = 10;
	gapC = 10;
	int tagEta = -10;
	const xAOD::CaloClusterContainer *ptrTopoCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrTopoCon,"CaloCalTopoClusters"));
	for(const auto *ptrTopo : *ptrTopoCon)
	{
		if(ptrTopo->getMomentValue(xAOD::CaloCluster_v1::CELL_SIGNIFICANCE)>=4.5)
		{
			tagEta = (int)((ptrTopo->eta()+5)*5);
			if(ptrTopo->et()/1000.<etCut[tagEta]) continue;
			if(5+ptrTopo->eta()<gapC) gapC = 5+ptrTopo->eta();
			if(5-ptrTopo->eta()<gapA) gapA = 5-ptrTopo->eta();
		}
	}

	
	
	//------------------------------------------------------  
	// MBTS
	//------------------------------------------------------ 
	const xAOD::ForwardEventInfoContainer *ptrMbtsCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrMbtsCon,"MBTSForwardEventInfo"));
	for(const auto *ptrMbts : *ptrMbtsCon)
	{
		mbtsTimeA = ptrMbts->timeA();
		mbtsTimeC = ptrMbts->timeC();
	}
		

	
	//------------------------------------------------------  
	// Offline Vertex
	//------------------------------------------------------ 
	hasPriVtx = false;
	zPriVtx = 0;
	int cnt = 0;
	const xAOD::VertexContainer *ptrOffVtxCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrOffVtxCon,"PrimaryVertices"));
	for(const auto ptrOffVtx : *ptrOffVtxCon)
	{
		xVtx[cnt] = ptrOffVtx->x();
		yVtx[cnt] = ptrOffVtx->y();
		zVtx[cnt] = ptrOffVtx->z();
		typeVtx[cnt] = ptrOffVtx->vertexType();
		cnt++;
		if(ptrOffVtx->vertexType() == xAOD::VxType::PriVtx)
		{
			hasPriVtx = true;
			zPriVtx = ptrOffVtx->z();
			break;
		}
	}
  

/*
	//------------------------------------------------------  
	// Offline Tracks
	//------------------------------------------------------ 
	nTrk = 0;
	const xAOD::TrackParticleContainer *ptrTrkCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrTrkCon,"InDetTrackParticles"));
	for(const auto *ptrTrk : *ptrTrkCon)
	{
		nTrk ++;
		d0trk[nTrk-1] = sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-zPriVtx);
		z0trk[nTrk-1] = ptrTrk->d0();

		// loose cut
		if(ptrTrk->auxdata<unsigned char>("numberOfPixelHits")<1) continue;
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")<=5) continue;
		if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfInnermostPixelLayerHits")>=1) ;
		else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfNextToInnermostPixelLayerHits")>=1) ;
		else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")==0) ;
		else continue;
		if(!(ptrTrk->pt()/1000.<10 || TMath::Prob(ptrTrk->chiSquared(),ptrTrk->numberDoF())>0.01)) continue;
		//if(fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-zPriVtx)/sqrt((ptrTrk->definingParametersCovMatrix()(1,1))*pow(sin(ptrTrk->theta()),2) + (ptrTrk->definingParametersCovMatrix()(3,3))*pow((ptrTrk->z0()+ptrTrk->vz()-zPriVtx)*cos(ptrTrk->theta()),2)+ 2*(ptrTrk->definingParametersCovMatrix()(1,3))*fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-zPriVtx)*cos(ptrTrk->theta()))))>=3) continue;
		//if(fabs(ptrTrk->d0()/sqrt(ptrTrk->definingParametersCovMatrix()(0,0)))>=3) continue;
	
		if(fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-zPriVtx))>=1.5) continue;
		if(fabs(ptrTrk->d0())>=1.5) continue;

		if(5-ptrTrk->eta()<gapA) gapA = 5-ptrTrk->eta();
		if(5+ptrTrk->eta()<gapC) gapC = 5+ptrTrk->eta();
	}

	isPassGap = false;
	if(gapA<2 && gapC<2) isPassGap = true;
*/

	m_eventCounter++;

	//if(fcalEtA+fcalEtC<0.04 || fcalEtA+fcalEtC>5 || hasPriVtx) return EL::StatusCode::SUCCESS;

	//tree->Fill();

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
	hComp->Write();
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
