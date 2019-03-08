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

#include "effTool_pPb.C"

static effTool_pPb* eff_fun = 0;

const double etCut[50] ={0,0.34,0.48,0.42,0.48,0.28,0.32,0.38,0.6,0.58,0.13,0.17,0.28,0.11,0.14,0.14,0.34,0.39,0.28,0.3,0.3,0.34,0.37,0.38,0.4,0.38,0.37,0.36,0.34,0.32,0.3,0.25,0.26,0.29,0.14,0.12,0.1,0.1,0.16,0.32,0.32,0.48,0.4,0.35,0.34,0.98,0.44,0.31,0.41,0};

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

	tree = new TTree("tree","Data15 PbPb 5TeV");
	tree->Branch("RunNo",&RunNo,"RunNo/I");
	tree->Branch("LbNo",&LbNo,"LbNo/I");
	tree->Branch("Bcid",&Bcid,"Bcid/I");
	tree->Branch("Trigger",Trigger,"Trigger[7]/F");
	tree->Branch("VtxZ",&VtxZ,"VtxZ/F");
	tree->Branch("FcalA",&FcalA,"FcalA/F");
	tree->Branch("FcalC",&FcalC,"FcalC/F");
	tree->Branch("MbtsHitA",&MbtsHitA,"MbtsHitA/I");
	tree->Branch("MbtsHitC",&MbtsHitC,"MbtsHitC/I");
	tree->Branch("MbtsTimeA",&MbtsTimeA,"MbtsTimeA/F");
	tree->Branch("MbtsTimeC",&MbtsTimeC,"MbtsTimeC/F");
	tree->Branch("GapA",&GapA,"GapA/F");
	tree->Branch("GapC",&GapC,"GapC/F");
	tree->Branch("ZdcA",&ZdcA,"ZdcA/F");
	tree->Branch("ZdcC",&ZdcC,"ZdcC/F");
	tree->Branch("Topo",&Topo,"Topo/I");
	tree->Branch("TopoEta",TopoEta,"TopoEta[50]/I");
	tree->Branch("TrkRef",&TrkRef,"TrkRef/F");
	tree->Branch("TrkEff",&TrkEff,"TrkEff/F");
	tree->Branch("TrkAll",&TrkAll,"TrkAll/F");
	tree->Branch("TrkPos",&TrkPos,"TrkPos/F");
	tree->Branch("TrkNeg",&TrkNeg,"TrkNeg/F");
	tree->Branch("TrkEtaAll",TrkEtaAll,"TrkEtaAll[50]/F");
	tree->Branch("TrkEtaPos",TrkEtaPos,"TrkEtaPos[50]/F");
	tree->Branch("TrkEtaNeg",TrkEtaNeg,"TrkEtaNeg[50]/F");
	//tree->Branch("TrkPhiAll",TrkPhiAll,"TrkPhiAll[50]/F");
	//tree->Branch("TrkPhiPos",TrkPhiPos,"TrkPhiPos[50]/F");
	//tree->Branch("TrkPhiNeg",TrkPhiNeg,"TrkPhiNeg[50]/F");
	tree->Branch("TrkEtaAllSelf",TrkEtaAllSelf,"TrkEtaAllSelf[50]/F");
	tree->Branch("TrkEtaPosSelf",TrkEtaPosSelf,"TrkEtaPosSelf[50]/F");
	tree->Branch("TrkEtaNegSelf",TrkEtaNegSelf,"TrkEtaNegSelf[50]/F");
	//tree->Branch("TrkPhiAllSelf",TrkPhiAllSelf,"TrkPhiAllSelf[50]/F");
	//tree->Branch("TrkPhiPosSelf",TrkPhiPosSelf,"TrkPhiPosSelf[50]/F");
	//tree->Branch("TrkPhiNegSelf",TrkPhiNegSelf,"TrkPhiNegSelf[50]/F");

	eff_fun = new effTool_pPb("$ROOTCOREBIN/data/checkTrack/eff_pPb.root");
	eff_fun->Qual=2; // loose cuts

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

	memset(TopoEta, 	0,  sizeof TopoEta);
	memset(TrkEtaAll, 0,  sizeof TrkEtaAll);
	memset(TrkEtaPos, 0,  sizeof TrkEtaPos);
	memset(TrkEtaNeg, 0,  sizeof TrkEtaNeg);
	memset(TrkPhiAll, 0,  sizeof TrkPhiAll);
	memset(TrkPhiPos, 0,  sizeof TrkPhiPos);
	memset(TrkPhiNeg, 0,  sizeof TrkPhiNeg);
	memset(TrkEtaAllSelf, 0,  sizeof TrkEtaAllSelf);
	memset(TrkEtaPosSelf, 0,  sizeof TrkEtaPosSelf);
	memset(TrkEtaNegSelf, 0,  sizeof TrkEtaNegSelf);
	memset(TrkPhiAllSelf, 0,  sizeof TrkPhiAllSelf);
	memset(TrkPhiPosSelf, 0,  sizeof TrkPhiPosSelf);
	memset(TrkPhiNegSelf, 0,  sizeof TrkPhiNegSelf);

	//------------------------------------------------------  
	// Fill All Triggers
	//------------------------------------------------------ 
	auto chainGroup = m_trigDecisionTool->getChainGroup(".*");
	for(int i=0; i<7; i++)
	{
		Trigger[i] = 0;
		if(i==0) sprintf(nameTrig,"HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50");
		if(i==1) sprintf(nameTrig,"HLT_noalg_mb_L1TE50");
		if(i==2) sprintf(nameTrig,"HLT_mb_sp");
		if(i==3) sprintf(nameTrig,"L1_ZDC_A_C");
		if(i==4) sprintf(nameTrig,"L1_ZDC_XOR");
		if(i==5) sprintf(nameTrig,"L1_ZDC_A");
		if(i==6) sprintf(nameTrig,"L1_ZDC_C");
		//if(i==0) sprintf(nameTrig,"HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50_OVERLAY");
		//if(i==1) sprintf(nameTrig,"HLT_noalg_L1TE50_OVERLAY");
		chainGroup = m_trigDecisionTool->getChainGroup(nameTrig);
		if(chainGroup->getPrescale()==-1) Trigger[i] = 0;
		else if(m_trigDecisionTool->isPassed(nameTrig)) Trigger[i] = chainGroup->getPrescale();
		else Trigger[i] = -1.*chainGroup->getPrescale();
		if(i>2) Trigger[i] = (chainGroup->isPassedBits() & TrigDefs::L1_isPassedBeforePrescale);
	}
	//if(Trig[0]<=0 && Trig[1]<=0) return EL::StatusCode::SUCCESS;


	
	//------------------------------------------------------  
	// Event Infomation
	//------------------------------------------------------ 
	const xAOD::EventInfo* eventInfo = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve( eventInfo, "EventInfo"));
	RunNo = eventInfo->runNumber();
	// = eventInfo->eventNumber();
	LbNo = eventInfo->lumiBlock();
	Bcid = eventInfo->bcid();
	
	if(eventInfo->errorState(xAOD::EventInfo::LAr)==xAOD::EventInfo::Error) return EL::StatusCode::SUCCESS;
	if(eventInfo->errorState(xAOD::EventInfo::Tile)==xAOD::EventInfo::Error) return EL::StatusCode::SUCCESS;
	if(eventInfo->errorState(xAOD::EventInfo::SCT)==xAOD::EventInfo::Error) return EL::StatusCode::SUCCESS;
	if(eventInfo->isEventFlagBitSet(xAOD::EventInfo::Core, 18)) return EL::StatusCode::SUCCESS;
	
	
	//------------------------------------------------------  
	// ET
	//------------------------------------------------------ 
	FcalA = 0;
	FcalC = 0;
	const xAOD::HIEventShapeContainer *ptrEvtShpCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrEvtShpCon,"HIEventShape"));
	for(const auto *ptrEvtShp : *ptrEvtShpCon)
	{
		if(ptrEvtShp->layer()==21 || ptrEvtShp->layer()==22 || ptrEvtShp->layer()==23)
		{
			if((ptrEvtShp->etaMin()+ptrEvtShp->etaMax())/2>0) FcalA += ptrEvtShp->et()/1000000.;
			if((ptrEvtShp->etaMin()+ptrEvtShp->etaMax())/2<0) FcalC += ptrEvtShp->et()/1000000.;
		}
		tagEta = (int)(((ptrEvtShp->etaMax()+ptrEvtShp->etaMin())/2+5)*5);
		if(tagEta<0 || tagEta>=50) continue;
		//CaloEt[tagEta] += ptrEvtShp->et()/1000.;
	}

	
	
	//------------------------------------------------------  
	// Topo Cluster
	//------------------------------------------------------ 
	GapA = 10;
	GapC = 10;
	Topo = 0;
	const xAOD::CaloClusterContainer *ptrTopoCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrTopoCon,"CaloCalTopoClusters"));
	for(const auto *ptrTopo : *ptrTopoCon)
	{
		if(ptrTopo->getMomentValue(xAOD::CaloCluster_v1::CELL_SIGNIFICANCE)>=4.5)
		{
			tagEta = (int)((ptrTopo->eta()+5)*5);
			if(tagEta<0 || tagEta>=50) continue;
			if(ptrTopo->et()/1000.<etCut[tagEta]) continue;
			if(5+ptrTopo->eta()<GapC) GapC = 5+ptrTopo->eta();
			if(5-ptrTopo->eta()<GapA) GapA = 5-ptrTopo->eta();
			Topo++;
			TopoEta[tagEta]++;
		}
	}

	
	
	//------------------------------------------------------  
	// ZDC
	//------------------------------------------------------ 
	ZdcA = 0;
	ZdcC = 0;
	const xAOD::ZdcModuleContainer* ptrZdcCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrZdcCon,"ZdcModules"));
	for(const auto *ptrZdc : *ptrZdcCon)
	{
		//std::cout<<ptrZdc->side()<<" | "<<ptrZdc->zdcModule()<<" | "<<ptrZdc->type()<<" | "<<ptrZdc->channel()<<" : "<<ptrZdc->energy()<<" | "<<ptrZdc->amplitude()<<" | "<<ptrZdc->amplitudeG0()<<" | "<<ptrZdc->amplitudeG1()<<std::endl;
		if(ptrZdc->type()!=0 || ptrZdc->zdcModule()<0 || ptrZdc->zdcModule()>3)  continue;
		if(ptrZdc->side()<0) ZdcA += ptrZdc->amplitudeG0();
		if(ptrZdc->side()>0) ZdcC += ptrZdc->amplitudeG0();
	}
	
	//------------------------------------------------------  
	// MBTS
	//------------------------------------------------------ 
	const xAOD::ForwardEventInfoContainer *ptrMbtsCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrMbtsCon,"MBTSForwardEventInfo"));
	for(const auto *ptrMbts : *ptrMbtsCon)
	{
		MbtsTimeA = ptrMbts->timeA();
		MbtsTimeC = ptrMbts->timeC();
		MbtsHitA = ptrMbts->countA();
		MbtsHitC = ptrMbts->countC();
	}
		

	
	//------------------------------------------------------  
	// Offline Vertex
	//------------------------------------------------------ 
	VtxZ = 99999;
	const xAOD::VertexContainer *ptrOffVtxCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrOffVtxCon,"PrimaryVertices"));
	for(const auto ptrOffVtx : *ptrOffVtxCon)
	{
		if(ptrOffVtx->vertexType() == xAOD::VxType::PriVtx) VtxZ = ptrOffVtx->z();
	}
  


	//------------------------------------------------------  
	// Offline Tracks
	//------------------------------------------------------ 
	TrkRef = 0;
	TrkEff = 0;
	TrkAll = 0;
	TrkPos = 0;
	TrkNeg = 0;
	const xAOD::TrackParticleContainer *ptrTrkCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrTrkCon,"InDetTrackParticles"));
	float wei = 0;
	for(const auto *ptrTrk : *ptrTrkCon)
	{
	///* loose cut
		if(ptrTrk->auxdata<unsigned char>("numberOfPixelHits")<1) continue;
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")<=5) continue;
		if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfInnermostPixelLayerHits")>=1) ;
		else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfNextToInnermostPixelLayerHits")>=1) ;
		else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")==0) ;
		else continue;
		if(!(ptrTrk->pt()/1000.<10 || TMath::Prob(ptrTrk->chiSquared(),ptrTrk->numberDoF())>0.01)) continue;
		if(fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-VtxZ)/sqrt((ptrTrk->definingParametersCovMatrix()(1,1))*pow(sin(ptrTrk->theta()),2) + (ptrTrk->definingParametersCovMatrix()(3,3))*pow((ptrTrk->z0()+ptrTrk->vz()-VtxZ)*cos(ptrTrk->theta()),2)+ 2*(ptrTrk->definingParametersCovMatrix()(1,3))*fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-VtxZ)*cos(ptrTrk->theta()))))>=3) continue;
		if(fabs(ptrTrk->d0()/sqrt(ptrTrk->definingParametersCovMatrix()(0,0)))>=3) continue;
	//*/
	/* tight+ cut
		if(ptrTrk->auxdata<unsigned char>("numberOfPixelHits")<=1) continue;
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")<=7) continue;
		if(ptrTrk->auxdata<unsigned char>("numberOfPixelHoles")>0) continue;
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHoles")>1) continue;
		if(fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-VtxZ))>=1.5) continue;
		if(fabs(ptrTrk->d0())>=1.5) continue;
	*/
		if(fabs(ptrTrk->eta())>=2.5) continue;
		if(ptrTrk->pt()/1000.>0.4) TrkRef++;
	}
	for(const auto *ptrTrk : *ptrTrkCon)
	{
		///* loose cut
		if(ptrTrk->auxdata<unsigned char>("numberOfPixelHits")<1) continue;
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")<=5) continue;
		if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfInnermostPixelLayerHits")>=1) ;
		else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfNextToInnermostPixelLayerHits")>=1) ;
		else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")==0) ;
		else continue;
		if(!(ptrTrk->pt()/1000.<10 || TMath::Prob(ptrTrk->chiSquared(),ptrTrk->numberDoF())>0.01)) continue;
		if(fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-VtxZ)/sqrt((ptrTrk->definingParametersCovMatrix()(1,1))*pow(sin(ptrTrk->theta()),2) + (ptrTrk->definingParametersCovMatrix()(3,3))*pow((ptrTrk->z0()+ptrTrk->vz()-VtxZ)*cos(ptrTrk->theta()),2)+ 2*(ptrTrk->definingParametersCovMatrix()(1,3))*fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-VtxZ)*cos(ptrTrk->theta()))))>=3) continue;
		if(fabs(ptrTrk->d0()/sqrt(ptrTrk->definingParametersCovMatrix()(0,0)))>=3) continue;
	//*/
	/* tight+ cut
		if(ptrTrk->auxdata<unsigned char>("numberOfPixelHits")<=1) continue;
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")<=7) continue;
		if(ptrTrk->auxdata<unsigned char>("numberOfPixelHoles")>0) continue;
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHoles")>1) continue;
		if(fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-VtxZ))>=1.5) continue;
		if(fabs(ptrTrk->d0())>=1.5) continue;
	*/
		if(fabs(ptrTrk->eta())>=2.5) continue;
		
		// efficiency correction
		eff_fun->set_centb(TrkRef);
		wei = 1./eff_fun->get_eff(ptrTrk->eta(),VtxZ,ptrTrk->pt()/1000.);

		if(ptrTrk->pt()/1000.>0.4) TrkEff+=wei;
		if(ptrTrk->pt()/1000.<0.5) continue;

		wei = 1.;
		tagEta = (int)((ptrTrk->eta()+2.5)*10);
		tagPhi = (int)((ptrTrk->phi()+TMath::Pi())/TMath::Pi()*25);
		if(tagEta<0 || tagEta>=50) continue;
		if(1)
		{
			TrkAll+=wei;
			TrkEtaAll[tagEta]+=wei;
			TrkPhiAll[tagPhi]+=wei;
			TrkEtaAllSelf[tagEta]+=wei*wei;
			TrkPhiAllSelf[tagPhi]+=wei*wei;
		}
		if(ptrTrk->charge()>0)
		{
			TrkPos+=wei;
			TrkEtaPos[tagEta]+=wei;
			TrkPhiPos[tagPhi]+=wei;
			TrkEtaPosSelf[tagEta]+=wei*wei;
			TrkPhiPosSelf[tagPhi]+=wei*wei;
		}
		if(ptrTrk->charge()<0)
		{
			TrkNeg+=wei;
			TrkEtaNeg[tagEta]+=wei;
			TrkPhiNeg[tagPhi]+=wei;
			TrkEtaNegSelf[tagEta]+=wei*wei;
			TrkPhiNegSelf[tagPhi]+=wei*wei;
		}

		if(5-ptrTrk->eta()<GapA) GapA = 5-ptrTrk->eta();
		if(5+ptrTrk->eta()<GapC) GapC = 5+ptrTrk->eta();
	}

	
	
	//------------------------------------------------------  
	// Event Selection
	//------------------------------------------------------ 
	//if(nTrk==0) return EL::StatusCode::SUCCESS;
	//if(nTrk>50) return EL::StatusCode::SUCCESS;
	//if(FCalA+FCalC>0.5) return EL::StatusCode::SUCCESS;
	
	m_eventCounter++;

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
