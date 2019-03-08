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

int trackSelection(const xAOD::TrackParticle*, float);

static effTool_pPb* eff_fun = 0;

const double pTcut = 0.4;
const double etCut[50] ={0,0.34,0.48,0.42,0.48,0.28,0.32,0.38,0.6,0.58,0.13,0.17,0.28,0.11,0.14,0.14,0.34,0.39,0.28,0.3,0.3,0.34,0.37,0.38,0.4,0.38,0.37,0.36,0.34,0.32,0.3,0.25,0.26,0.29,0.14,0.12,0.1,0.1,0.16,0.32,0.32,0.48,0.4,0.35,0.34,0.98,0.44,0.31,0.41,0};
const double fcalCut[51] = {-0.9995,0.0055,0.0085,0.0125,0.0165,0.0205,0.0265,0.0325,0.0405,0.0485,0.0595,0.0705,0.0835,0.0995,0.1165,0.1365,0.1585,0.1845,0.2125,0.2435,0.2785,0.3165,0.3595,0.4055,0.4565,0.5105,0.5705,0.6345,0.7045,0.7795,0.8595,0.9455,1.0375,1.1355,1.2395,1.3515,1.4705,1.5975,1.7325,1.8775,2.0315,2.1965,2.3715,2.5605,2.7615,2.9795,3.2165,3.4735,3.7595,4.0795,7};

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
	tree->Branch("QxA",QxA,"QxA[3]/F");
	tree->Branch("QxC",QxC,"QxC[3]/F");
	tree->Branch("QyA",QyA,"QyA[3]/F");
	tree->Branch("QyC",QyC,"QyC[3]/F");
	tree->Branch("MbtsHitA",&MbtsHitA,"MbtsHitA/I");
	tree->Branch("MbtsHitC",&MbtsHitC,"MbtsHitC/I");
	tree->Branch("MbtsTimeA",&MbtsTimeA,"MbtsTimeA/F");
	tree->Branch("MbtsTimeC",&MbtsTimeC,"MbtsTimeC/F");
	tree->Branch("GapA",&GapA,"GapA/F");
	tree->Branch("GapC",&GapC,"GapC/F");
	tree->Branch("ZdcA",&ZdcA,"ZdcA/F");
	tree->Branch("ZdcC",&ZdcC,"ZdcC/F");
	tree->Branch("TrkRef",&TrkRef,"TrkRef/F");
	tree->Branch("TrkEff",&TrkEff,"TrkEff/F");
	tree->Branch("TrkAll",&TrkAll,"TrkAll/F");
	tree->Branch("TrkPos",&TrkPos,"TrkPos/F");
	tree->Branch("TrkNeg",&TrkNeg,"TrkNeg/F");
	tree->Branch("TrkDeltaEtaAll",TrkDeltaEtaAll,"TrkDeltaEtaAll[50]/F");
	tree->Branch("TrkDeltaEtaPos",TrkDeltaEtaPos,"TrkDeltaEtaPos[50]/F");
	tree->Branch("TrkDeltaEtaNeg",TrkDeltaEtaNeg,"TrkDeltaEtaNeg[50]/F");
	tree->Branch("TrkDeltaPhiAll",TrkDeltaPhiAll,"TrkDeltaPhiAll[50]/F");
	tree->Branch("TrkDeltaPhiPos",TrkDeltaPhiPos,"TrkDeltaPhiPos[50]/F");
	tree->Branch("TrkDeltaPhiNeg",TrkDeltaPhiNeg,"TrkDeltaPhiNeg[50]/F");
	tree->Branch("TrkDeltaEtaAllMix",TrkDeltaEtaAllMix,"TrkDeltaEtaAllMix[50]/F");
	tree->Branch("TrkDeltaEtaPosMix",TrkDeltaEtaPosMix,"TrkDeltaEtaPosMix[50]/F");
	tree->Branch("TrkDeltaEtaNegMix",TrkDeltaEtaNegMix,"TrkDeltaEtaNegMix[50]/F");
	tree->Branch("TrkDeltaPhiAllMix",TrkDeltaPhiAllMix,"TrkDeltaPhiAllMix[50]/F");
	tree->Branch("TrkDeltaPhiPosMix",TrkDeltaPhiPosMix,"TrkDeltaPhiPosMix[50]/F");
	tree->Branch("TrkDeltaPhiNegMix",TrkDeltaPhiNegMix,"TrkDeltaPhiNegMix[50]/F");

	eff_fun = new effTool_pPb("$ROOTCOREBIN/data/checkTrack/eff_pPb.root");
	eff_fun->Qual=2; // loose cuts

	return EL::StatusCode::SUCCESS;
}

int trackSelection(const xAOD::TrackParticle* ptrTrk, float VtxZ)
{
		if(ptrTrk->auxdata<unsigned char>("numberOfPixelHits")<1) return -1;
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")<=5) return -1;
		if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfInnermostPixelLayerHits")>=1) ;
		else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfNextToInnermostPixelLayerHits")>=1) ;
		else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")==0) ;
		else return -1;
		if(!(ptrTrk->pt()/1000.<10 || TMath::Prob(ptrTrk->chiSquared(),ptrTrk->numberDoF())>0.01)) return -1;
		if(fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-VtxZ)/sqrt((ptrTrk->definingParametersCovMatrix()(1,1))*pow(sin(ptrTrk->theta()),2) + (ptrTrk->definingParametersCovMatrix()(3,3))*pow((ptrTrk->z0()+ptrTrk->vz()-VtxZ)*cos(ptrTrk->theta()),2)+ 2*(ptrTrk->definingParametersCovMatrix()(1,3))*fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-VtxZ)*cos(ptrTrk->theta()))))>=3) return -1;
		if(fabs(ptrTrk->d0()/sqrt(ptrTrk->definingParametersCovMatrix()(0,0)))>=3) return -1;
		if(fabs(ptrTrk->eta())>=2.5) return -1;
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

	memset(QxA, 	0,  sizeof QxA);
	memset(QxC, 	0,  sizeof QxC);
	memset(QyA, 	0,  sizeof QyA);
	memset(QyC, 	0,  sizeof QyC);
	memset(TopoEta, 	0,  sizeof TopoEta);
	memset(TrkDeltaEtaAll, 0,  sizeof TrkDeltaEtaAll);
	memset(TrkDeltaEtaPos, 0,  sizeof TrkDeltaEtaPos);
	memset(TrkDeltaEtaNeg, 0,  sizeof TrkDeltaEtaNeg);
	memset(TrkDeltaPhiAll, 0,  sizeof TrkDeltaPhiAll);
	memset(TrkDeltaPhiPos, 0,  sizeof TrkDeltaPhiPos);
	memset(TrkDeltaPhiNeg, 0,  sizeof TrkDeltaPhiNeg);
	memset(TrkDeltaEtaAllMix, 0,  sizeof TrkDeltaEtaAllMix);
	memset(TrkDeltaEtaPosMix, 0,  sizeof TrkDeltaEtaPosMix);
	memset(TrkDeltaEtaNegMix, 0,  sizeof TrkDeltaEtaNegMix);
	memset(TrkDeltaPhiAllMix, 0,  sizeof TrkDeltaPhiAllMix);
	memset(TrkDeltaPhiPosMix, 0,  sizeof TrkDeltaPhiPosMix);
	memset(TrkDeltaPhiNegMix, 0,  sizeof TrkDeltaPhiNegMix);

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
	int tagFcal = -1;
	const xAOD::HIEventShapeContainer *ptrEvtShpCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrEvtShpCon,"HIEventShape"));
	for(const auto *ptrEvtShp : *ptrEvtShpCon)
	{
		if(ptrEvtShp->layer()==21 || ptrEvtShp->layer()==22 || ptrEvtShp->layer()==23)
		{
			if((ptrEvtShp->etaMin()+ptrEvtShp->etaMax())/2>0)
			{
				FcalA += ptrEvtShp->et()/1000000.;
				for(int i=0; i<3; i++)
				{
					QxA[i] += (ptrEvtShp->etCos()).at(i)/1000000.;
					QyA[i] += (ptrEvtShp->etSin()).at(i)/1000000.;
				}
			}
			if((ptrEvtShp->etaMin()+ptrEvtShp->etaMax())/2<0)
			{
				FcalC += ptrEvtShp->et()/1000000.;
				for(int i=0; i<3; i++)
				{
					QxC[i] += (ptrEvtShp->etCos()).at(i)/1000000.;
					QyC[i] += (ptrEvtShp->etSin()).at(i)/1000000.;
				}
			}
		}
		tagEta = floor(((ptrEvtShp->etaMax()+ptrEvtShp->etaMin())/2+5)*5);
		if(tagEta<0 || tagEta>=50) continue;
		//CaloEt[tagEta] += ptrEvtShp->et()/1000.;
	}
	for(int i=0; i<50; i++)
	{
		if(FcalA+FcalC<fcalCut[i] || FcalA+FcalC>=fcalCut[i+1]) continue;
		tagFcal = 50-i-1;
		break;
	}
	if(tagFcal*2<20 || tagFcal*2>=30) return EL::StatusCode::SUCCESS;

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
	int tagZvtx = -1;
	const xAOD::VertexContainer *ptrOffVtxCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrOffVtxCon,"PrimaryVertices"));
	for(const auto ptrOffVtx : *ptrOffVtxCon)
	{
		if(ptrOffVtx->vertexType() == xAOD::VxType::PriVtx) VtxZ = ptrOffVtx->z();
	}
	tagZvtx = floor((VtxZ+50)/10);
	if(tagZvtx<0 || tagZvtx>=10) return EL::StatusCode::SUCCESS;
  


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
	float wei1 = 0;
	float wei2 = 0;
	int tagChg1 = 0;
	int tagChg2 = 0;
	float deltaPhi = 0;
	for(const auto *ptrTrk : *ptrTrkCon)
	{
		if(trackSelection(ptrTrk,VtxZ)<0) continue;
		if(ptrTrk->pt()/1000.>pTcut) TrkRef++;
	}
	mixWeiAll.clear(); mixEtaAll.clear(); mixPhiAll.clear();
	mixWeiPos.clear(); mixEtaPos.clear(); mixPhiPos.clear();
	mixWeiNeg.clear(); mixEtaNeg.clear(); mixPhiNeg.clear();
	for(const auto *ptrTrk : *ptrTrkCon)
	{
		if(trackSelection(ptrTrk,VtxZ)<0) continue;
		if(ptrTrk->pt()/1000.<pTcut) continue;
		
		eff_fun->set_centb(TrkRef);
		wei = 1./eff_fun->get_eff(ptrTrk->eta(),VtxZ,ptrTrk->pt()/1000.);
		//wei = 1;

		if(1)
		{
			mixWeiAll.push_back(wei);
			mixEtaAll.push_back(ptrTrk->eta());
			mixPhiAll.push_back(ptrTrk->phi());
		}
		if(ptrTrk->charge()>0)
		{
			mixWeiPos.push_back(wei);
			mixEtaPos.push_back(ptrTrk->eta());
			mixPhiPos.push_back(ptrTrk->phi());
		}
		if(ptrTrk->charge()<0)
		{
			mixWeiNeg.push_back(wei);
			mixEtaNeg.push_back(ptrTrk->eta());
			mixPhiNeg.push_back(ptrTrk->phi());
		}
	}
	//std::cout<<poolEtaAll[tagFcal][tagZvtx].size()<<": "<<tagFcal<<" | "<<tagZvtx<<std::endl;
	poolWeiAll[tagFcal][tagZvtx].push_back(mixWeiAll);
	poolWeiPos[tagFcal][tagZvtx].push_back(mixWeiPos);
	poolWeiNeg[tagFcal][tagZvtx].push_back(mixWeiNeg);
	poolEtaAll[tagFcal][tagZvtx].push_back(mixEtaAll);
	poolEtaPos[tagFcal][tagZvtx].push_back(mixEtaPos);
	poolEtaNeg[tagFcal][tagZvtx].push_back(mixEtaNeg);
	poolPhiAll[tagFcal][tagZvtx].push_back(mixPhiAll);
	poolPhiPos[tagFcal][tagZvtx].push_back(mixPhiPos);
	poolPhiNeg[tagFcal][tagZvtx].push_back(mixPhiNeg);
	if(poolWeiAll[tagFcal][tagZvtx].size()<=1) return EL::StatusCode::SUCCESS;

	const xAOD::TrackParticle* ptrTrk1 = 0;
	const xAOD::TrackParticle* ptrTrk2 = 0;
	for(xAOD::TrackParticleContainer::const_iterator itr1 = ptrTrkCon->begin(); itr1<ptrTrkCon->end(); itr1++)
	{
		ptrTrk1 = (*itr1);
		if(trackSelection(ptrTrk1,VtxZ)<0) continue;
		
		eff_fun->set_centb(TrkRef);
		wei1 = 1./eff_fun->get_eff(ptrTrk1->eta(),VtxZ,ptrTrk1->pt()/1000.);
		//wei1 = 1;
		if(ptrTrk1->pt()/1000.>pTcut) TrkEff+=wei1;
		if(ptrTrk1->pt()/1000.<pTcut) continue;
		if(5-ptrTrk1->eta()<GapA) GapA = 5-ptrTrk1->eta();
		if(5+ptrTrk1->eta()<GapC) GapC = 5+ptrTrk1->eta();
		tagChg1 = 0;
		if(1) TrkAll+=wei1;
		if(ptrTrk1->charge()>0)
		{
			tagChg1 = 1;
			TrkPos+=wei1;
		}
		if(ptrTrk1->charge()<0)
		{
			tagChg1 = -1;
			TrkNeg+=wei1;
		}
		// same event fill
		///for(xAOD::TrackParticleContainer::const_iterator itr2 = itr1+1; itr2<ptrTrkCon->end(); itr2++)
		for(xAOD::TrackParticleContainer::const_iterator itr2 = ptrTrkCon->begin(); itr2<ptrTrkCon->end(); itr2++)
		{
			ptrTrk2 = (*itr2);
			if(trackSelection(ptrTrk2,VtxZ)<0) continue;
			if(ptrTrk2 == ptrTrk1) continue;
			wei2 = 1./eff_fun->get_eff(ptrTrk2->eta(),VtxZ,ptrTrk2->pt()/1000.);
			//wei2 = 1;
			if(ptrTrk2->pt()/1000.<pTcut) continue;
			tagChg2 = 0;
			if(ptrTrk2->charge()>0) tagChg2 = 1;
			if(ptrTrk2->charge()<0) tagChg2 = -1;

			tagEta = floor((ptrTrk1->eta()-ptrTrk2->eta()+5)*5);
			if(tagEta<0 || tagEta>=50) continue;
			if(1) TrkDeltaEtaAll[tagEta] += wei1*wei2;
			if(tagChg1>0 && tagChg2>0) TrkDeltaEtaPos[tagEta] += wei1*wei2;
			if(tagChg1<0 && tagChg2<0) TrkDeltaEtaNeg[tagEta] += wei1*wei2;

			deltaPhi = ptrTrk1->phi()-ptrTrk2->phi();
			if(deltaPhi>+TMath::Pi()) deltaPhi -= 2*TMath::Pi();
			if(deltaPhi<-TMath::Pi()) deltaPhi += 2*TMath::Pi();
			if(deltaPhi<-0.5*TMath::Pi()) deltaPhi += 2*TMath::Pi();
			tagPhi = floor((deltaPhi+0.5*TMath::Pi())/2/TMath::Pi()*50);
			if(tagPhi<0 || tagPhi>=50) continue;
			if(1) TrkDeltaPhiAll[tagPhi] += wei1*wei2;
			if(tagChg1>0 && tagChg2>0) TrkDeltaPhiPos[tagPhi] += wei1*wei2;
			if(tagChg1<0 && tagChg2<0) TrkDeltaPhiNeg[tagPhi] += wei1*wei2;
		}
		// same event fill
		// mixed event fill
		for(int iPool=0; iPool<1; iPool++)
		{
			if(1)
			{
				for(unsigned int iTrk=0; iTrk<poolWeiAll[tagFcal][tagZvtx].at(iPool).size(); iTrk++)
				{
					tagEta = floor((ptrTrk1->eta()-poolEtaAll[tagFcal][tagZvtx].at(iPool).at(iTrk)+5)*5);
					if(tagEta<0 || tagEta>=50) continue;
					TrkDeltaEtaAllMix[tagEta] += wei1*poolWeiAll[tagFcal][tagZvtx].at(iPool).at(iTrk);

					deltaPhi = ptrTrk1->phi()-poolPhiAll[tagFcal][tagZvtx].at(iPool).at(iTrk);
					if(deltaPhi>+TMath::Pi()) deltaPhi -= 2*TMath::Pi();
					if(deltaPhi<-TMath::Pi()) deltaPhi += 2*TMath::Pi();
					if(deltaPhi<-0.5*TMath::Pi()) deltaPhi += 2*TMath::Pi();
					tagPhi = floor((deltaPhi+0.5*TMath::Pi())/2/TMath::Pi()*50);
					if(tagPhi<0 || tagPhi>=50) continue;
					TrkDeltaPhiAllMix[tagPhi] += wei1*poolWeiAll[tagFcal][tagZvtx].at(iPool).at(iTrk);
				}
			}
			if(ptrTrk1->charge()>0)
			{
				for(unsigned int iTrk=0; iTrk<poolWeiPos[tagFcal][tagZvtx].at(iPool).size(); iTrk++)
				{
					tagEta = floor((ptrTrk1->eta()-poolEtaPos[tagFcal][tagZvtx].at(iPool).at(iTrk)+5)*5);
					if(tagEta<0 || tagEta>=50) continue;
					TrkDeltaEtaPosMix[tagEta] += wei1*poolWeiPos[tagFcal][tagZvtx].at(iPool).at(iTrk);

					deltaPhi = ptrTrk1->phi()-poolPhiPos[tagFcal][tagZvtx].at(iPool).at(iTrk);
					if(deltaPhi>+TMath::Pi()) deltaPhi -= 2*TMath::Pi();
					if(deltaPhi<-TMath::Pi()) deltaPhi += 2*TMath::Pi();
					if(deltaPhi<-0.5*TMath::Pi()) deltaPhi += 2*TMath::Pi();
					tagPhi = floor((deltaPhi+0.5*TMath::Pi())/2/TMath::Pi()*50);
					if(tagPhi<0 || tagPhi>=50) continue;
					TrkDeltaPhiPosMix[tagPhi] += wei1*poolWeiPos[tagFcal][tagZvtx].at(iPool).at(iTrk);
				}
			}
			if(ptrTrk1->charge()<0)
			{
				for(unsigned int iTrk=0; iTrk<poolWeiNeg[tagFcal][tagZvtx].at(iPool).size(); iTrk++)
				{
					tagEta = floor((ptrTrk1->eta()-poolEtaNeg[tagFcal][tagZvtx].at(iPool).at(iTrk)+5)*5);
					if(tagEta<0 || tagEta>=50) continue;
					TrkDeltaEtaNegMix[tagEta] += wei1*poolWeiNeg[tagFcal][tagZvtx].at(iPool).at(iTrk);

					deltaPhi = ptrTrk1->phi()-poolPhiNeg[tagFcal][tagZvtx].at(iPool).at(iTrk);
					if(deltaPhi>+TMath::Pi()) deltaPhi -= 2*TMath::Pi();
					if(deltaPhi<-TMath::Pi()) deltaPhi += 2*TMath::Pi();
					if(deltaPhi<-0.5*TMath::Pi()) deltaPhi += 2*TMath::Pi();
					tagPhi = floor((deltaPhi+0.5*TMath::Pi())/2/TMath::Pi()*50);
					if(tagPhi<0 || tagPhi>=50) continue;
					TrkDeltaPhiNegMix[tagPhi] += wei1*poolWeiNeg[tagFcal][tagZvtx].at(iPool).at(iTrk);
				}
			}
		}
		// mixed event fill
	}
	poolWeiAll[tagFcal][tagZvtx].erase(poolWeiAll[tagFcal][tagZvtx].begin());
	poolWeiPos[tagFcal][tagZvtx].erase(poolWeiPos[tagFcal][tagZvtx].begin());
	poolWeiNeg[tagFcal][tagZvtx].erase(poolWeiNeg[tagFcal][tagZvtx].begin());
	poolEtaAll[tagFcal][tagZvtx].erase(poolEtaAll[tagFcal][tagZvtx].begin());
	poolEtaPos[tagFcal][tagZvtx].erase(poolEtaPos[tagFcal][tagZvtx].begin());
	poolEtaNeg[tagFcal][tagZvtx].erase(poolEtaNeg[tagFcal][tagZvtx].begin());
	poolPhiAll[tagFcal][tagZvtx].erase(poolPhiAll[tagFcal][tagZvtx].begin());
	poolPhiPos[tagFcal][tagZvtx].erase(poolPhiPos[tagFcal][tagZvtx].begin());
	poolPhiNeg[tagFcal][tagZvtx].erase(poolPhiNeg[tagFcal][tagZvtx].begin());


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
