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

const double pTmin = 0.2;
const double etaMax = 2.5;
const int nTrkMax = 1000;

UInt_t	 runNo;
UInt_t	 lbNo;
UInt_t 	 bcid;
float    trigPS[40];
float    zVtx;
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
	tree = new TTree("tree","2015 pp 5 TeV");
	tree->Branch("runNo", 	 &runNo,    "runNo/i");
	tree->Branch("lbNo", 	 	 &lbNo,     "lbNo/i");
	tree->Branch("bcid", 	 	 &bcid,     "bcid/i");
	tree->Branch("trigPS", 	 trigPS, 		"trigPS[40]/F");
	tree->Branch("zVtx", 	   &zVtx,     "zVtx/F");
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
	if(flagPhi>=pow(2,14)) flagPhi = int(pow(2,14));
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
	// pp 5 TeV
	if(1)
	{
		for(int i=0; i<24; i++)
		{
			if(i==0) sprintf(name,"HLT_mb_sptrk");
			if(i==1) sprintf(name,"HLT_noalg_mb_L1MBTS_1");
			if(i==2) sprintf(name,"HLT_noalg_mb_L1MBTS_1_1");
			if(i==3) sprintf(name,"HLT_noalg_mb_L1ZDC_A");
			if(i==4) sprintf(name,"HLT_noalg_mb_L1ZDC_C");
			if(i==5) sprintf(name,"HLT_noalg_mb_L1ZDC_AND");
			if(i==6) sprintf(name,"HLT_noalg_mb_L1ZDC_A_C");
			if(i==7) sprintf(name,"HLT_noalg_mb_L1TE5");
			if(i==8) sprintf(name,"HLT_noalg_mb_L1TE10");
			if(i==9) sprintf(name,"HLT_noalg_mb_L1TE20");
			if(i==10) sprintf(name,"HLT_noalg_mb_L1TE30");
			if(i==11) sprintf(name,"HLT_noalg_mb_L1TE40");
			if(i==12) sprintf(name,"HLT_noalg_mb_L1TE50");
			if(i==13) sprintf(name,"HLT_noalg_mb_L1TE60");
			if(i==14) sprintf(name,"HLT_noalg_mb_L1TE70");
			if(i==15) sprintf(name,"HLT_mb_sp700_hmtperf_L1TE5");
			if(i==16) sprintf(name,"HLT_mb_sp1500_hmtperf_L1TE10");
			if(i==17) sprintf(name,"HLT_mb_sp2100_hmtperf_L1TE10");
			if(i==18) sprintf(name,"HLT_mb_sp800_pusup400_trk50_hmt_L1TE5");
			if(i==19) sprintf(name,"HLT_mb_sp900_pusup500_trk60_hmt_L1TE5");
			if(i==20) sprintf(name,"HLT_mb_sp1200_pusup700_trk70_hmt_L1TE5");
			if(i==21) sprintf(name,"HLT_mb_sp1400_pusup550_trk90_hmt_L1TE10");
			if(i==22) sprintf(name,"HLT_mb_sp1600_pusup1100_trk90_hmt_L1TE10");
			if(i==23) sprintf(name,"HLT_mb_sp1400_pusup550_trk90_hmt_L1TE20");

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
	if(isGoodEvent_pp2015(runNo, lbNo, bcid)>0) tagGRL = true;

	bool tagError = false;
	if(eventInfo->errorState(xAOD::EventInfo::LAr)==xAOD::EventInfo::Error) tagError = true;
	if(eventInfo->errorState(xAOD::EventInfo::Tile)==xAOD::EventInfo::Error) tagError = true;
	if(eventInfo->errorState(xAOD::EventInfo::SCT)==xAOD::EventInfo::Error) tagError = true;
	if(eventInfo->isEventFlagBitSet(xAOD::EventInfo::Core, 18)) tagError = true;

	if(!tagGRL || tagError) return EL::StatusCode::SUCCESS;

	
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
