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

//#include "GeneratorObjects/HijingEventParams.h"

const double pTmin = 0.5;
const double etaMax = 5.0;
const int nTrkMax = 10000;

float tru_zVtx;
unsigned int tru_nVtx;
unsigned int tru_nTrk;
unsigned int tru_trkInfo[nTrkMax];
float rec_fcalEtA;
float rec_fcalEtC;
float rec_zVtx;
unsigned int rec_nVtx;
unsigned int rec_nTrk;
unsigned int rec_trkInfo[nTrkMax];

double pTcut[4] = {0.5, 1.0, 1.5, 2.0};
float bimp;
float npart;
unsigned int tru_nTrk_Fcal[4];
unsigned int tru_nTrk_Inner[4];
unsigned int rec_nTrk_Inner[2][4];
float rec_Et_Fcal;
float rec_Et_Inner;

bool trackSelection(const xAOD::TrackParticle*, float);
bool trackSelectionTight(const xAOD::TrackParticle*, float);
bool isPrimaryParticle( const xAOD::TruthParticle*);
const xAOD::TruthParticle *truthParticle(const xAOD::TrackParticle*);
int cvtPt(double);
int cvtEta(double);
int cvtPhi(double);
double detPt(unsigned int);
double detEta(unsigned int);
double detPhi(unsigned int);

TH1D* hDis;
TH2D* hCor;

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

	fout = new TFile("myaod.root","recreate");
	tree = new TTree("tree","HIJING PbPb 5.02 TeV");
	tree->Branch("tru_zVtx",     &tru_zVtx,     "tru_zVtx/F");
	//tree->Branch("tru_nTrk",     &tru_nTrk,     "tru_nTrk/i");
	//tree->Branch("tru_trkInfo",  tru_trkInfo,   "tru_trkInfo[tru_nTrk]/i");
	//tree->Branch("rec_fcalEtA",  &rec_fcalEtA,  "rec_fcalEtA/F");
	//tree->Branch("rec_fcalEtC",  &rec_fcalEtC,  "rec_fcalEtC/F");
	//tree->Branch("rec_zVtx",     &rec_zVtx,     "rec_zVtx/F");
	//tree->Branch("rec_nTrk",     &rec_nTrk,     "rec_nTrk/i");
	//tree->Branch("rec_trkInfo",  rec_trkInfo,   "rec_trkInfo[rec_nTrk]/i");
	
	tree->Branch("bimp", &bimp, "bimp/F");
	tree->Branch("npart", &npart, "npart/i");
	tree->Branch("tru_nTrk_Fcal", tru_nTrk_Fcal, "tru_nTrk_Fcal[4]/i");
	tree->Branch("tru_nTrk_Inner", tru_nTrk_Inner, "tru_nTrk_Inner[4]/i");
	tree->Branch("rec_nTrk_Inner", rec_nTrk_Inner, "rec_nTrk_Inner[2][4]/i");
	tree->Branch("rec_Et_Fcal", &rec_Et_Fcal, "rec_Et_Fcal/F");
	tree->Branch("rec_Et_Inner", &rec_Et_Inner, "rec_Et_Inner/F");

	hDis = new TH1D("hDis","",1000,-5,5);
	hCor = new TH2D("hCor","",1000,-5,5,1000,-5,5);

	selTool = new InDet::InDetTrackSelectionTool( "TrackSelection" );
	EL_RETURN_CHECK( "YourAnalysis", selTool->setProperty("CutLevel", "LoosePrimary" ));
	EL_RETURN_CHECK( "YourAnalysis", selTool->setProperty("minPt", pTmin) );
	EL_RETURN_CHECK( "YourAnalysis", selTool->setProperty("maxD0", 1.5) );
	EL_RETURN_CHECK( "YourAnalysis", selTool->setProperty("maxZ0", 1.5) );
	EL_RETURN_CHECK( "YourAnalysis", selTool->setProperty("maxD0overSigmaD0", 1.5) );
	EL_RETURN_CHECK( "YourAnalysis", selTool->setProperty("maxZ0overSigmaZ0", 1.5) );
	EL_RETURN_CHECK( "YourAnalysis", selTool->initialize() );

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
	if(flagPhi>=pow(2,14)) flagPhi = int(pow(2,14))-1;
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

bool isPrimaryParticle(const xAOD::TruthParticle* truth)
{
	if( truth->pt()/1000. < pTmin ) return false;
	if( truth->status() != 1 ) return false;
	if( const_cast<xAOD::TruthParticle*>(truth)->isNeutral() ) return false;
	if( truth->barcode() == 0 || truth->barcode() >= 200e3) return false;
	//if( fabs(truth->eta()) >= etaMax ) return false; // no eta cut
	if( truth->isStrangeBaryon() ) return false;
	return true;
}


bool trackSelection(const xAOD::TrackParticle* ptrTrk, float zPriVtx)
{ 
	if(ptrTrk->pt()/1000. < pTmin) return false;
	if(ptrTrk->auxdata<unsigned char>("numberOfPixelHits")<1) return false;
	if(ptrTrk->pt()/1000<0.3)
	{ 
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")+ptrTrk->auxdata<unsigned char>("numberOfSCTDeadSensors")<2) return false;
	}
	else if(ptrTrk->pt()/1000<0.4)
	{ 
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")+ptrTrk->auxdata<unsigned char>("numberOfSCTDeadSensors")<4) return false;
	}
	else
	{ 
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")+ptrTrk->auxdata<unsigned char>("numberOfSCTDeadSensors")<6) return false;
	}
	if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfInnermostPixelLayerHits")>=1) ;
	else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfNextToInnermostPixelLayerHits")>=1) ;
	else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")==0) ;
	else return false;
	if(!(ptrTrk->pt()/1000.<10 || TMath::Prob(ptrTrk->chiSquared(),ptrTrk->numberDoF())>0.01)) return false;
	if(fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-zPriVtx))>=1.5) return false;
	if(fabs(ptrTrk->d0())>=1.5) return false;
	if(fabs(ptrTrk->eta()) >= etaMax) return false;
	return true;
}


bool trackSelectionTight(const xAOD::TrackParticle* ptrTrk, float zPriVtx)
{ 
	if(ptrTrk->pt()/1000. < pTmin) return false;
	if(ptrTrk->auxdata<unsigned char>("numberOfPixelHits")<2) return false; // tight
	if(ptrTrk->pt()/1000<0.3)
	{ 
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")+ptrTrk->auxdata<unsigned char>("numberOfSCTDeadSensors")<2) return false;
	}
	else if(ptrTrk->pt()/1000<0.4)
	{ 
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")+ptrTrk->auxdata<unsigned char>("numberOfSCTDeadSensors")<4) return false;
	}
	else
	{ 
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")+ptrTrk->auxdata<unsigned char>("numberOfSCTDeadSensors")<8) return false;// tight
	}
	if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfInnermostPixelLayerHits")>=1) ;
	else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfNextToInnermostPixelLayerHits")>=1) ;
	else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")==0) ;
	else return false;
	if(!(ptrTrk->pt()/1000.<10 || TMath::Prob(ptrTrk->chiSquared(),ptrTrk->numberDoF())>0.01)) return false;
	if(fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-zPriVtx))>=1.0) return false; // tight
	if(fabs(ptrTrk->d0())>=1.0) return false; // tight
	if(fabs(ptrTrk->eta()) >= etaMax) return false;
	return true;
}



const xAOD::TruthParticle* truthParticle(const xAOD::TrackParticle* track) {
	typedef ElementLink< xAOD::TruthParticleContainer > Link_t;
	static const char* NAME = "truthParticleLink";
	if( ! track->isAvailable< Link_t >( NAME ) ) {
		return 0;
	}
	const Link_t& link = track->auxdata< Link_t >( NAME );
	if( ! link.isValid() ) {
		return 0;
	}

	return *link;
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



const xAOD::TruthVertex *MyxAODAnalysis::vertexTruthParticle(const xAOD::TruthParticle *ptrTrk)
{
	typedef ElementLink<xAOD::TruthVertexContainer> Link_t;
	static const char* NAME = "truthVertexLink";
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
	// Rec Et
	//------------------------------------------------------ 
	rec_fcalEtA = 0;
	rec_fcalEtC = 0;
	rec_Et_Fcal = 0;
	rec_Et_Inner = 0;
	const xAOD::HIEventShapeContainer *ptrEvtShpCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrEvtShpCon,"HIEventShape"));
	for(const auto *ptrEvtShp : *ptrEvtShpCon)
	{
		if(ptrEvtShp->layer()==21 || ptrEvtShp->layer()==22 || ptrEvtShp->layer()==23)
		{
			if((ptrEvtShp->etaMin()+ptrEvtShp->etaMax())/2>0) rec_fcalEtA += ptrEvtShp->et()/1e6;
			if((ptrEvtShp->etaMin()+ptrEvtShp->etaMax())/2<0) rec_fcalEtC += ptrEvtShp->et()/1e6;
		}
		if(fabs(ptrEvtShp->etaMin()+ptrEvtShp->etaMax())/2>=3.2) rec_Et_Fcal += ptrEvtShp->et()/1e6;
		if(fabs(ptrEvtShp->etaMin()+ptrEvtShp->etaMax())/2<=2.5) rec_Et_Inner += ptrEvtShp->et()/1e6;
	}
	rec_Et_Fcal = rec_fcalEtA + rec_fcalEtC;

	//------------------------------------------------------  
	// Truth Vertex
	//------------------------------------------------------ 
	tru_zVtx = 9999;
	const xAOD::TruthVertexContainer* ptrTruVtxCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrTruVtxCon,"TruthVertices"));
	for(const auto ptrTruVtx : *ptrTruVtxCon)
	{
		//if(ptrTruVtx->vertexType() == xAOD::VxType::PriVtx) // first vertex is always primary vertex
		{
			tru_zVtx = ptrTruVtx->z();
			break;
		}
	}
	
	
	
	//------------------------------------------------------  
	// Reconstructed Vertex
	//------------------------------------------------------ 
	rec_zVtx = 9999;
	const xAOD::VertexContainer *ptrRecVtxCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrRecVtxCon,"PrimaryVertices"));
	for(const auto ptrRecVtx : *ptrRecVtxCon)
	{
		if(ptrRecVtx->vertexType() == xAOD::VxType::PriVtx)
		{
			rec_zVtx = ptrRecVtx->z();
			break;
		}
	}


	//------------------------------------------------------  
	// Truth Tracks
	//------------------------------------------------------ 
	tru_nTrk = 0;
	for(int i=0; i<nTrkMax; i++) tru_trkInfo[i] = 0;
	UInt_t trkChg = 0;
	UInt_t trkQual = 1;
	UInt_t trkPt = 0;
	UInt_t trkEta = 0;
	UInt_t trkPhi = 0;

	UInt_t tmpInfo = 0;
	double tmpChg = 0;
	double tmpQual = 0;
	double tmpPt = 0;
	double tmpEta = 0;
	double tmpPhi = 0;

	for(int iP=0; iP<4; iP++)
	{
		tru_nTrk_Fcal[iP] = 0;
		tru_nTrk_Inner[iP] = 0;
	}

	const xAOD::TruthVertex *ptrTruVtx = 0;
	const xAOD::TruthParticleContainer* ptrTruTrkCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve( ptrTruTrkCon, "TruthParticles" ));
	for(const auto* ptrTruTrk : *ptrTruTrkCon)
	{
		if(!isPrimaryParticle(ptrTruTrk)) continue;

		for(int iP=0; iP<4; iP++)
		{
			if(ptrTruTrk->pt()/1000.>=pTcut[iP] && ptrTruTrk->pt()/1000.<=5.0)
			{
				if(fabs(ptrTruTrk->eta())>=3.2) tru_nTrk_Fcal[iP] ++;
				if(fabs(ptrTruTrk->eta())<=2.5) tru_nTrk_Inner[iP] ++;
			}
		}

		/*
		if(ptrTruTrk->charge()>0) trkChg = 1;
		else if(ptrTruTrk->charge()<0) trkChg = 0;
		trkPt = cvtPt(ptrTruTrk->pt());
		trkEta = cvtEta(ptrTruTrk->eta());
		trkPhi = cvtPhi(ptrTruTrk->phi());
		trkQual = 1;

		tru_trkInfo[tru_nTrk] = trkChg;
		tru_trkInfo[tru_nTrk] <<=  1; tru_trkInfo[tru_nTrk] |= trkQual;
		tru_trkInfo[tru_nTrk] <<=  8; tru_trkInfo[tru_nTrk] |= trkPt;
		tru_trkInfo[tru_nTrk] <<=  8; tru_trkInfo[tru_nTrk] |= trkEta;
		tru_trkInfo[tru_nTrk] <<= 14; tru_trkInfo[tru_nTrk] |= trkPhi;

		tmpInfo= tru_trkInfo[tru_nTrk];
		tmpPhi = detPhi(tmpInfo & 0x3fff); tmpInfo >>= 14;
		tmpEta = detEta(tmpInfo & 0xff);   tmpInfo >>= 8;
		tmpPt  = detPt(tmpInfo & 0xff);    tmpInfo >>= 8;
		tmpQual= tmpInfo & 0x1;            tmpInfo >>= 1;
		tmpChg = tmpInfo & 0x1;

		if(fabs(trkChg-tmpChg)>0 || fabs(trkQual-tmpQual)>0 || fabs(ptrTruTrk->pt()/1000-tmpPt)>0.1 || fabs(ptrTruTrk->eta()-tmpEta)>0.02 || fabs(ptrTruTrk->phi()-tmpPhi)>0.001)
		{
			std::cout<<trkChg<<"  |  "<<trkQual<<"  |  "<<ptrTruTrk->pt()/1000<<"  |  "<<ptrTruTrk->eta()<<"  |  "<<ptrTruTrk->phi()<<std::endl;
			std::cout<<tmpChg<<"  |  "<<tmpQual<<"  |  "<<tmpPt<<"  |  "<<tmpEta<<"  |  "<<tmpPhi<<std::endl;
		}

		tru_nTrk ++;
		if(tru_nTrk>=nTrkMax) break;
		*/
	}

	//------------------------------------------------------  
	// Reconstructed Tracks
	//------------------------------------------------------ 
	rec_nTrk = 0;
	for(int i=0; i<nTrkMax; i++) rec_trkInfo[i] = 0;
	
	for(int iC=0; iC<2; iC++)
	{
		for(int iP=0; iP<4; iP++)
		{
			rec_nTrk_Inner[iC][iP] = 0;
		}
	}

	const xAOD::Vertex *ptrVtx = 0;
	const xAOD::TruthParticle* ptrTruRec = 0;
	const xAOD::TrackParticleContainer *ptrRecTrkCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrRecTrkCon,"InDetTrackParticles"));
	for(const auto* ptrRecTrk : *ptrRecTrkCon)
	{
		if(!trackSelection(ptrRecTrk, rec_zVtx)) continue;
		//if ( !selTool->accept(ptrRecTrk) ) continue;

/*
		ptrTruRec = truthParticle(ptrRecTrk);

		if(!ptrTruRec) continue;
		else if(ptrTruRec->barcode()==0) continue;
		if(ptrRecTrk->auxdata<float>("truthMatchProbability")<0.5) continue;

		if(!ptrTruRec) continue;
		else if(!isPrimaryParticle(ptrTruRec)) continue;
		if(ptrRecTrk->auxdata<float>("truthMatchProbability")<0.5) continue;
*/	

		for(int iC=0; iC<2; iC++)
		{
			if(iC==1 && !trackSelectionTight(ptrRecTrk, rec_zVtx)) continue;
			for(int iP=0; iP<4; iP++)
			{
				if(ptrRecTrk->pt()/1000.>=pTcut[iP] && ptrRecTrk->pt()/1000.<=5.0)
				{
					rec_nTrk_Inner[iC][iP] ++;
				}
			}
		}

		/*
		const auto& covMatrix = ptrRecTrk->definingParametersCovMatrix();
		double sigD0 = std::sqrt( covMatrix(0,0) );
		double sigZ0 = std::sqrt( covMatrix(1,1) );
		hCor->Fill(ptrRecTrk->d0(),sigD0);
		hDis->Fill(ptrRecTrk->d0()/sigD0);
		//std::cout<<ptrRecTrk->d0()/sigD0<<std::endl;
		//if(sigD0>=1.5 || sigZ0>=1.5) continue;


		if(ptrRecTrk->charge()!=0) trkChg = 1;
		else trkChg = 0;
		trkPt = cvtPt(ptrRecTrk->pt());
		trkEta = cvtEta(ptrRecTrk->eta());
		trkPhi = cvtPhi(ptrRecTrk->phi());
		trkQual = 1;

		rec_trkInfo[rec_nTrk] = trkChg;
		rec_trkInfo[rec_nTrk] <<=  1; rec_trkInfo[rec_nTrk] |= trkQual;
		rec_trkInfo[rec_nTrk] <<=  8; rec_trkInfo[rec_nTrk] |= trkPt;
		rec_trkInfo[rec_nTrk] <<=  8; rec_trkInfo[rec_nTrk] |= trkEta;
		rec_trkInfo[rec_nTrk] <<= 14; rec_trkInfo[rec_nTrk] |= trkPhi;

		tmpInfo= rec_trkInfo[rec_nTrk];
		tmpPhi = detPhi(tmpInfo & 0x3fff); tmpInfo >>= 14;
		tmpEta = detEta(tmpInfo & 0xff);   tmpInfo >>= 8;
		tmpPt  = detPt(tmpInfo & 0xff);    tmpInfo >>= 8;
		tmpQual= tmpInfo & 0x1;            tmpInfo >>= 1;
		tmpChg = tmpInfo & 0x1;

		if(fabs(trkChg-tmpChg)>0 || fabs(trkQual-tmpQual)>0 || fabs(ptrRecTrk->pt()/1000-tmpPt)>0.1 || fabs(ptrRecTrk->eta()-tmpEta)>0.02 || fabs(ptrRecTrk->phi()-tmpPhi)>0.001)
		{
			std::cout<<trkChg<<"  |  "<<trkQual<<"  |  "<<ptrRecTrk->pt()/1000<<"  |  "<<ptrRecTrk->eta()<<"  |  "<<ptrRecTrk->phi()<<std::endl;
			std::cout<<tmpChg<<"  |  "<<tmpQual<<"  |  "<<tmpPt<<"  |  "<<tmpEta<<"  |  "<<tmpPhi<<std::endl;
		}

		rec_nTrk ++;
		if(rec_nTrk>=nTrkMax) break;
		*/
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
	EL_RETURN_CHECK( "YourAnalysis", selTool->finalize() );

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
