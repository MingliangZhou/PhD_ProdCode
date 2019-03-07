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
#include "xAODMissingET/MissingETContainer.h"
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

const double pTmin = 0.3;
const double etaMax = 2.5;
const int nTrkMax = 1000;

UInt_t	 runNo;
UInt_t	 lbNo;
UInt_t 	 bcid;
float    trigPS[40];
float    zVtx;
float 	 fcalEt;
UInt_t   nVtx;
UInt_t   nTrk;
UInt_t   trkInfo[nTrkMax];

bool trackSelection(const xAOD::TrackParticle*, float);
int cvtPt(double);
int cvtEta(double);
int cvtPhi(double);
double detPt(UInt_t);
double detEta(UInt_t);
double detPhi(UInt_t);

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
	m_trigConfigTool = new TrigConf::xAODConfigTool("xAODConfigTool");
	EL_RETURN_CHECK( "initialize", m_trigConfigTool->initialize() );

	ToolHandle< TrigConf::ITrigConfigTool > trigConfigHandle( m_trigConfigTool );
	if (trigConfigHandle->initialize().isFailure()) {
		if (trigConfigHandle->initialize().isFailure()) {
			Error("initialize()","Failed to initialize trigger config handle");
			return EL::StatusCode::FAILURE;
		}
	}
	m_trigDecisionTool = new Trig::TrigDecisionTool("TrigDecisionTool");
	EL_RETURN_CHECK( "initialize", m_trigDecisionTool->setProperty( "ConfigTool", trigConfigHandle ) );
	EL_RETURN_CHECK( "initialize", m_trigDecisionTool->setProperty( "TrigDecisionKey", "xTrigDecision" ) );
	EL_RETURN_CHECK( "initialize", m_trigDecisionTool->initialize() );

	fout = new TFile("myaod.root","recreate");
	tree = new TTree("tree","2015 pp 13 TeV");
	tree->Branch("runNo", 	 &runNo,    "runNo/i");
	tree->Branch("lbNo", 	 	 &lbNo,     "lbNo/i");
	tree->Branch("bcid", 	 	 &bcid,     "bcid/i");
	tree->Branch("trigPS", 	 trigPS, 		"trigPS[40]/F");
	tree->Branch("zVtx", 	   &zVtx,     "zVtx/F");
	tree->Branch("fcalEt", 	 &fcalEt,   "fcalEt/F");
	tree->Branch("nVtx", 	   &nVtx,     "nVtx/i");
	tree->Branch("nTrk", 		 &nTrk,     "nTrk/i");
	tree->Branch("trkInfo",  trkInfo,   "trkInfo[nTrk]/i");

	return EL::StatusCode::SUCCESS;
}


int cvtPt(double pT)
{
	int flagPt = int(pT/100.);
	if(flagPt<0) flagPt = 0;
	if(flagPt>=250) flagPt = 250;
	return flagPt;
}
int cvtEta(double eta)
{
	int flagEta = int((eta+etaMax)/2/etaMax*250);
	if(flagEta<0) flagEta = 0;
	if(flagEta>=250) flagEta = 250;
	return flagEta;
}
int cvtPhi(double phi)
{
	int flagPhi = int((phi+TMath::Pi())/2/TMath::Pi()*pow(2,14));
	if(flagPhi<0) flagPhi = 0;
	if(flagPhi>=pow(2,14)) flagPhi = int(pow(2,14)-1); // put phi=pi to phi=-pi
	return flagPhi;
}
double detPt(UInt_t pt)
{
	return (pt+0.5)/10.;
}
double detEta(UInt_t eta)
{
	return (eta+0.5)/250.*2*etaMax-etaMax;
}
double detPhi(UInt_t phi)
{
	return (phi+0.5)/pow(2,14)*2*TMath::Pi()-TMath::Pi();
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
	if(fabs(ptrTrk->eta()) >= etaMax) return 0;
	if(ptrTrk->pt()/1000. <= pTmin) return 0;
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
	// Event info
	//------------------------------------------------------ 
	const xAOD::EventInfo* eventInfo = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve( eventInfo, "EventInfo"));
	runNo = eventInfo->runNumber();
	lbNo = eventInfo->lumiBlock();
	bcid = eventInfo->bcid();



	//------------------------------------------------------  
	// Trigger info
	//------------------------------------------------------ 
	char name[200];
	for(int i=0; i<40; i++) trigPS[i] = 0;
	// pp 13 TeV low-mu
	if(runNo<=277089)
	{
		for(int i=0; i<17; i++)
		{
			if(i==0) sprintf(name,"HLT_noalg_mb_L1MBTS_1");
			if(i==1) sprintf(name,"HLT_noalg_mb_L1MBTS_2");
			if(i==2) sprintf(name,"HLT_noalg_mb_L1MBTS_1_1");
			if(i==3) sprintf(name,"HLT_mb_sptrk");
			if(i==4) sprintf(name,"HLT_noalg_mb_L1TE10");
			if(i==5) sprintf(name,"HLT_noalg_mb_L1TE20");
			if(i==6) sprintf(name,"HLT_noalg_mb_L1TE30");
			if(i==7) sprintf(name,"HLT_noalg_mb_L1TE40");
			if(i==8) sprintf(name,"HLT_noalg_mb_L1TE50");
			if(i==9) sprintf(name,"HLT_mb_sp1400_hmtperf_L1TE10");
			if(i==10) sprintf(name,"HLT_mb_sp1400_hmtperf_L1TE20");
			if(i==11) sprintf(name,"HLT_mb_sp400_trk40_hmt_L1MBTS_1_1");
			if(i==12) sprintf(name,"HLT_mb_sp700_trk50_hmt_L1MBTS_1_1");
			if(i==13) sprintf(name,"HLT_mb_sp900_trk60_hmt_L1MBTS_1_1");
			if(i==14) sprintf(name,"HLT_mb_sp1400_trk80_hmt_L1MBTS_1_1");
			if(i==15) sprintf(name,"HLT_mb_sp1400_trk90_hmt_L1TE10");
			if(i==16) sprintf(name,"HLT_mb_sp1400_trk100_hmt_L1TE20");

			if(m_trigDecisionTool->isPassed(name)) trigPS[i] = m_trigDecisionTool->getChainGroup(name)->getPrescale();
			else trigPS[i] = 0;
		}
	}
	else if(runNo<=300287)
	{
		for(int i=0; i<36; i++)
		{
			if(i==0) sprintf(name,"HLT_noalg_mb_L1MBTS_1_1");
			if(i==1) sprintf(name,"HLT_mb_sptrk");
			if(i==2) sprintf(name,"HLT_noalg_mb_L1TE10");
			if(i==3) sprintf(name,"HLT_noalg_mb_L1TE20");
			if(i==4) sprintf(name,"HLT_noalg_mb_L1TE30");
			if(i==5) sprintf(name,"HLT_noalg_mb_L1TE40");
			if(i==6) sprintf(name,"HLT_noalg_mb_L1TE50");
			if(i==7) sprintf(name,"HLT_noalg_mb_L1TE60");
			if(i==8) sprintf(name,"HLT_noalg_mb_L1TE70");
			if(i==9) sprintf(name,"HLT_noalg_mb_L1TE10.0ETA24");
			if(i==10) sprintf(name,"HLT_noalg_mb_L1TE20.0ETA24");
			if(i==11) sprintf(name,"HLT_noalg_mb_L1TE30.0ETA24");
			if(i==12) sprintf(name,"HLT_noalg_mb_L1TE40.0ETA24");
			if(i==13) sprintf(name,"HLT_noalg_mb_L1TE50.0ETA24");
			if(i==14) sprintf(name,"HLT_noalg_mb_L1TE60.0ETA24");
			if(i==15) sprintf(name,"HLT_noalg_mb_L1TE70.0ETA24");
			if(i==16) sprintf(name,"HLT_mb_sp700_hmtperf_L1TE5");
			if(i==17) sprintf(name,"HLT_mb_sp1800_hmtperf_L1TE5");
			if(i==18) sprintf(name,"HLT_mb_sp1500_hmtperf_L1TE10");
			if(i==19) sprintf(name,"HLT_mb_sp900_trk60_hmt_L1MBTS_1_1");
			if(i==20) sprintf(name,"HLT_mb_sp900_trk60_hmt_L1TE5");
			if(i==21) sprintf(name,"HLT_mb_sp900_pusup400_trk60_hmt_L1TE5");
			if(i==22) sprintf(name,"HLT_mb_sp1000_trk70_hmt_L1TE5");
			if(i==23) sprintf(name,"HLT_mb_sp1000_pusup450_trk70_hmt_L1TE5");
			if(i==24) sprintf(name,"HLT_mb_sp1400_trk90_hmt_L1TE10");
			if(i==25) sprintf(name,"HLT_mb_sp1400_pusup550_trk90_hmt_L1TE10");
			if(i==26) sprintf(name,"HLT_mb_sp1400_pusup550_trk90_hmt_L1TE10.0ETA24");
			if(i==27) sprintf(name,"HLT_mb_sp1600_trk100_hmt_L1TE10");
			if(i==28) sprintf(name,"HLT_mb_sp1600_pusup600_trk100_hmt_L1TE10");
			if(i==29) sprintf(name,"HLT_mb_sp1600_trk100_hmt_L1TE20");
			if(i==30) sprintf(name,"HLT_mb_sp1600_pusup600_trk100_hmt_L1TE20");
			if(i==31) sprintf(name,"HLT_mb_sp1500_pusup700_trk100_hmt_L1TE20.0ETA24");
			if(i==32) sprintf(name,"HLT_mb_sp1800_trk110_hmt_L1TE10");
			if(i==33) sprintf(name,"HLT_mb_sp1800_pusup700_trk110_hmt_L1TE10");
			if(i==34) sprintf(name,"HLT_mb_sp1800_trk110_hmt_L1TE20");
			if(i==35) sprintf(name,"HLT_mb_sp1800_pusup700_trk110_hmt_L1TE20");

			if(m_trigDecisionTool->isPassed(name)) trigPS[i] = m_trigDecisionTool->getChainGroup(name)->getPrescale();
			else trigPS[i] = 0;
		}
	}
	else if(runNo<=305359)
	{
		for(int i=0; i<32; i++)
		{
			if(i==0) sprintf(name,"HLT_mb_mbts_L1MBTS_1_1");
			if(i==1) sprintf(name,"HLT_mb_sptrk");
			if(i==2) sprintf(name,"HLT_noalg_mb_L1TE30");
			if(i==3) sprintf(name,"HLT_noalg_mb_L1TE30.0ETA24");
			if(i==4) sprintf(name,"HLT_noalg_mb_L1TE60");
			if(i==5) sprintf(name,"HLT_noalg_mb_L1TE60.0ETA24");
			if(i==6) sprintf(name,"HLT_mb_sp700_hmtperf_L1TE5");
			if(i==7) sprintf(name,"HLT_mb_sp1500_hmtperf_L1TE10");
			if(i==8) sprintf(name,"HLT_mb_sp900_trk60_hmt_L1MBTS_1_1");
			if(i==9) sprintf(name,"HLT_mb_sp1000_trk70_hmt_L1TE5");
			if(i==10) sprintf(name,"HLT_mb_sp1000_pusup450_trk70_hmt_L1TE5");
			if(i==11) sprintf(name,"HLT_mb_sp1400_trk90_hmt_L1TE10");
			if(i==12) sprintf(name,"HLT_mb_sp1400_pusup550_trk90_hmt_L1TE10");
			if(i==13) sprintf(name,"HLT_mb_sp1400_pusup550_trk90_hmt_L1TE10.0ETA24");
			if(i==14) sprintf(name,"HLT_mb_sp1600_trk100_hmt_L1TE10");
			if(i==15) sprintf(name,"HLT_mb_sp1600_pusup600_trk100_hmt_L1TE10");
			if(i==16) sprintf(name,"HLT_mb_sp1600_pusup600_trk100_hmt_L1TE10.0ETA24");
			if(i==17) sprintf(name,"HLT_mb_sp1600_trk100_hmt_L1TE20");
			if(i==18) sprintf(name,"HLT_mb_sp1600_pusup600_trk100_hmt_L1TE20");
			if(i==19) sprintf(name,"HLT_mb_sp1600_pusup600_trk100_hmt_L1TE20.0ETA24");
			if(i==20) sprintf(name,"HLT_mb_sp1800_trk110_hmt_L1TE10");
			if(i==21) sprintf(name,"HLT_mb_sp1800_pusup700_trk110_hmt_L1TE10");
			if(i==22) sprintf(name,"HLT_mb_sp1800_pusup700_trk110_hmt_L1TE10.0ETA24");
			if(i==23) sprintf(name,"HLT_mb_sp1800_trk110_hmt_L1TE20");
			if(i==24) sprintf(name,"HLT_mb_sp1800_pusup700_trk110_hmt_L1TE20");
			if(i==25) sprintf(name,"HLT_mb_sp1800_pusup700_trk110_hmt_L1TE20.0ETA24");
			if(i==26) sprintf(name,"HLT_mb_sp2100_trk120_hmt_L1TE30");
			if(i==27) sprintf(name,"HLT_mb_sp2100_pusup900_trk120_hmt_L1TE30");
			if(i==28) sprintf(name,"HLT_mb_sp2100_pusup900_trk120_hmt_L1TE30.0ETA24");
			if(i==29) sprintf(name,"HLT_mb_sp2300_trk130_hmt_L1TE30");
			if(i==30) sprintf(name,"HLT_mb_sp2300_pusup1000_trk130_hmt_L1TE30");
			if(i==31) sprintf(name,"HLT_mb_sp2300_pusup1000_trk130_hmt_L1TE30.0ETA24");

			if(m_trigDecisionTool->isPassed(name)) trigPS[i] = m_trigDecisionTool->getChainGroup(name)->getPrescale();
			else trigPS[i] = 0;
		}
	}
	else
	{
		for(int i=0; i<36; i++)
		{
			if(i==0) sprintf(name,"HLT_mb_sptrk");
			if(i==1) sprintf(name,"HLT_noalg_mb_L1MBTS_2");
			if(i==2) sprintf(name,"HLT_noalg_mb_L1TE5");
			if(i==3) sprintf(name,"HLT_noalg_mb_L1TE5.0ETA24");
			if(i==4) sprintf(name,"HLT_noalg_mb_L1TE10");
			if(i==5) sprintf(name,"HLT_noalg_mb_L1TE10.0ETA24");
			if(i==6) sprintf(name,"HLT_noalg_mb_L1TE20");
			if(i==7) sprintf(name,"HLT_noalg_mb_L1TE20.0ETA24");
			if(i==8) sprintf(name,"HLT_noalg_mb_L1TE30");
			if(i==9) sprintf(name,"HLT_noalg_mb_L1TE30.0ETA24");
			if(i==10) sprintf(name,"HLT_noalg_mb_L1TE40");
			if(i==11) sprintf(name,"HLT_noalg_mb_L1TE40.0ETA24");
			if(i==12) sprintf(name,"HLT_noalg_mb_L1TE50");
			if(i==13) sprintf(name,"HLT_noalg_mb_L1TE50.0ETA24");
			if(i==14) sprintf(name,"HLT_noalg_mb_L1TE60");
			if(i==15) sprintf(name,"HLT_noalg_mb_L1TE60.0ETA24");
			if(i==16) sprintf(name,"HLT_noalg_mb_L1TE70");
			if(i==17) sprintf(name,"HLT_noalg_mb_L1TE70.0ETA24");
			if(i==18) sprintf(name,"HLT_mb_sp900_trk50_hmt_L1TE5");
			if(i==19) sprintf(name,"HLT_mb_sp900_pusup400_trk50_hmt_L1TE5");
			if(i==20) sprintf(name,"HLT_mb_sp900_trk50_hmt_L1TE5.0ETA24");
			if(i==21) sprintf(name,"HLT_mb_sp900_pusup400_trk60_hmt_L1TE5");
			if(i==22) sprintf(name,"HLT_mb_sp1000_trk70_hmt_L1TE10");
			if(i==23) sprintf(name,"HLT_mb_sp1000_pusup450_trk70_hmt_L1TE10");
			if(i==24) sprintf(name,"HLT_mb_sp1000_trk70_hmt_L1TE10.0ETA24");
			if(i==25) sprintf(name,"HLT_mb_sp1000_pusup450_trk70_hmt_L1TE10.0ETA24");
			if(i==26) sprintf(name,"HLT_mb_sp1200_trk80_hmt_L1TE15");
			if(i==27) sprintf(name,"HLT_mb_sp1200_trk80_hmt_L1TE15.0ETA24");
			if(i==28) sprintf(name,"HLT_mb_sp1400_trk90_hmt_L1TE20");
			if(i==29) sprintf(name,"HLT_mb_sp1400_pusup550_trk90_hmt_L1TE20");
			if(i==30) sprintf(name,"HLT_mb_sp1400_trk90_hmt_L1TE20.0ETA24");
			if(i==31) sprintf(name,"HLT_mb_sp1400_pusup550_trk90_hmt_L1TE20.0ETA24");
			if(i==32) sprintf(name,"HLT_mb_sp1600_trk100_hmt_L1TE25.0ETA24");
			if(i==33) sprintf(name,"HLT_mb_sp1600_pusup600_trk100_hmt_L1TE25.0ETA24");
			if(i==34) sprintf(name,"HLT_mb_sp1800_trk110_hmt_L1TE30");
			if(i==35) sprintf(name,"HLT_mb_sp1800_pusup700_trk110_hmt_L1TE30");

			if(m_trigDecisionTool->isPassed(name)) trigPS[i] = m_trigDecisionTool->getChainGroup(name)->getPrescale();
			else trigPS[i] = 0;
		}
	}
	bool tagTrig = false;
	for(int i=0; i<40; i++)
	{
		if(trigPS[i]>0)
		{
			tagTrig = true;
			break;
		}
	}
	if(!tagTrig) return EL::StatusCode::SUCCESS;



	//------------------------------------------------------  
	// GRL and errorState rejection
	//------------------------------------------------------
	bool tagGRL = false;
	if(runNo==267358)
	{
		if(lbNo>=89 && lbNo<=196) tagGRL = true;
	}
	else if(runNo==267359)
	{
		if(lbNo>=177 && lbNo<=304) tagGRL = true;
	}
	else if(runNo==267360)
	{
		if(lbNo>=294 && lbNo<=295) tagGRL = true;
		if(lbNo>=297 && lbNo<=381) tagGRL = true;
		if(lbNo>=421 && lbNo<=443) tagGRL = true;
	}
	else if(runNo==267367)
	{
		if(lbNo>=328 && lbNo<=399) tagGRL = true;
		if(lbNo>=401 && lbNo<=401) tagGRL = true;
		if(lbNo>=406 && lbNo<=426) tagGRL = true;
		if(lbNo>=431 && lbNo<=443) tagGRL = true;
		if(lbNo>=446 && lbNo<=500) tagGRL = true;
	}
	else if(runNo==267385)
	{
		if(lbNo>=238 && lbNo<=588) tagGRL = true;
		if(lbNo>=591 && lbNo<=908) tagGRL = true;
	}
	else if(runNo==267599)
	{
		if(lbNo>=287 && lbNo<=1073) tagGRL = true;
		if(lbNo>=1088 && lbNo<=1110) tagGRL = true;
		if(lbNo>=1112 && lbNo<=1129) tagGRL = true;
	}
	else if(runNo==277025)
	{
		if(lbNo>=470 && lbNo<=575) tagGRL = true;
		if(lbNo>=583 && lbNo<=757) tagGRL = true;
		if(lbNo>=759 && lbNo<=786) tagGRL = true;
	}
	else if(runNo==277081)
	{
		if(lbNo>=74 && lbNo<=369) tagGRL = true;
	}
	else if(runNo==277089)
	{
		if(lbNo>=12 && lbNo<=255) tagGRL = true;
	}
	else tagGRL = true;

	bool tagError = false;
	if(eventInfo->errorState(xAOD::EventInfo::LAr)==xAOD::EventInfo::Error) tagError = true;
	if(eventInfo->errorState(xAOD::EventInfo::Tile)==xAOD::EventInfo::Error) tagError = true;
	if(eventInfo->errorState(xAOD::EventInfo::SCT)==xAOD::EventInfo::Error) tagError = true;
	if(eventInfo->isEventFlagBitSet(xAOD::EventInfo::Core, 18)) tagError = true;

	if(!tagGRL || tagError) return EL::StatusCode::SUCCESS;

	
	//------------------------------------------------------  
	// FCal ernergy Et
	//------------------------------------------------------ 
	/*
	fcalEt = 0;
	const xAOD::HIEventShapeContainer *ptrEvtShpCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrEvtShpCon,"HIEventShape"));
	for(const auto *ptrEvtShp : *ptrEvtShpCon)
	{
		if(ptrEvtShp->layer()==21 || ptrEvtShp->layer()==22 || ptrEvtShp->layer()==23) fcalEt += ptrEvtShp->et()/1000.;
	}
	*/
	
	
	//------------------------------------------------------  
	// MET
	//------------------------------------------------------ 
	double fcalEt2 = 0;
	const xAOD::MissingETContainer *ptrMetCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrMetCon,"MET_Calo"));
	for(const auto *ptrMet : *ptrMetCon)
	{
		if(ptrMet->name()=="FCAL") fcalEt2 = ptrMet->sumet();
	}
	fcalEt = fcalEt2/1000.;

	//------------------------------------------------------  
	// Reconstructed Vertex
	//------------------------------------------------------ 
	zVtx = 99999;
	nVtx = 0;
	const xAOD::VertexContainer *ptrRecVtxCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrRecVtxCon,"PrimaryVertices"));
	for(const auto ptrRecVtx : *ptrRecVtxCon)
	{
		if(ptrRecVtx->vertexType() == xAOD::VxType::PriVtx)
		{
			zVtx = ptrRecVtx->z();
			nVtx ++;
		}
		else
		{
			if(ptrRecVtx->nTrackParticles()>4) nVtx ++;
		}
	}
	if(fabs(zVtx)>150) return EL::StatusCode::SUCCESS;



	//------------------------------------------------------  
	// Reconstructed Tracks
	//------------------------------------------------------ 
	nTrk = 0;
	for(int i=0; i<nTrkMax; i++) trkInfo[i] = 0;
	UInt_t trkChg = 0;
	UInt_t trkQual = 0;
	UInt_t trkPt = 0;
	UInt_t trkEta = 0;
	UInt_t trkPhi = 0;

	UInt_t tmpInfo = 0;
	double tmpChg = 0;
	double tmpQual = 0;
	double tmpPt = 0;
	double tmpEta = 0;
	double tmpPhi = 0;

  const xAOD::Vertex *ptrVtx = 0;
	const xAOD::TrackParticleContainer *ptrRecTrkCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrRecTrkCon,"InDetTrackParticles"));
	for(const auto* ptrRecTrk : *ptrRecTrkCon)
	{
		if(!trackSelection(ptrRecTrk, zVtx)) continue;
		ptrVtx = vertexParticle(ptrRecTrk);
		if(!ptrVtx) continue;
		else if(fabs(ptrVtx->z()-zVtx)>0.0001) continue;

		if(ptrRecTrk->charge()>0) trkChg = 1;
		else if(ptrRecTrk->charge()<0) trkChg = 0;
		if(fabs(sin(ptrRecTrk->theta())*(ptrRecTrk->z0()+ptrRecTrk->vz()-zVtx))<1.0 && fabs(ptrRecTrk->d0())<1.0) trkQual = 1;
		else trkQual = 0;
		trkPt = cvtPt(ptrRecTrk->pt());
		trkEta = cvtEta(ptrRecTrk->eta());
		trkPhi = cvtPhi(ptrRecTrk->phi());

		trkInfo[nTrk] = trkChg;
		trkInfo[nTrk] <<=  1; trkInfo[nTrk] |= trkQual;
		trkInfo[nTrk] <<=  8; trkInfo[nTrk] |= trkPt;
		trkInfo[nTrk] <<=  8; trkInfo[nTrk] |= trkEta;
		trkInfo[nTrk] <<= 14; trkInfo[nTrk] |= trkPhi;

		tmpInfo= trkInfo[nTrk];
		tmpPhi = detPhi(tmpInfo & 0x3fff); tmpInfo >>= 14;
		tmpEta = detEta(tmpInfo & 0xff);   tmpInfo >>= 8;
		tmpPt  = detPt(tmpInfo & 0xff);    tmpInfo >>= 8;
		tmpQual= tmpInfo & 0x1; 					 tmpInfo >>= 1;
		tmpChg = tmpInfo & 0x1;

		if(fabs(trkChg-tmpChg)>0 || fabs(trkQual-tmpQual)>0 || fabs(ptrRecTrk->pt()/1000-tmpPt)>0.1 || fabs(ptrRecTrk->eta()-tmpEta)>0.01 || fabs(ptrRecTrk->phi()-tmpPhi)>0.001)
		{
			std::cout<<trkChg<<"  |  "<<trkQual<<"  |  "<<ptrRecTrk->pt()/1000<<"  |  "<<ptrRecTrk->eta()<<"  |  "<<ptrRecTrk->phi()<<std::endl;
			std::cout<<tmpChg<<"  |  "<<tmpQual<<"  |  "<<tmpPt<<"  |  "<<tmpEta<<"  |  "<<tmpPhi<<std::endl;
		}

		nTrk ++;
		if(nTrk>=nTrkMax) break;
	}

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
