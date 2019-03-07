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

const double pTmin = 0.2;
const double etaMax = 2.5;
const int nChMax = 1000;

float 	 truZvtx;
UInt_t   truNch;
UChar_t  truPt[nChMax];
UChar_t  truEta[nChMax];
UShort_t truPhi[nChMax];

float 	 recZvtx;
UInt_t   recNch;
UChar_t  recPt[nChMax];
UChar_t  recEta[nChMax];
UShort_t recPhi[nChMax];
bool		 recQual[nChMax];
bool		 recPrim[nChMax];
bool		 recFake[nChMax];
UChar_t  assPt[nChMax];
UChar_t  assEta[nChMax];
UShort_t assPhi[nChMax];

bool trackSelection(const xAOD::TrackParticle*, float);
bool isPrimaryParticle( const xAOD::TruthParticle*);
const xAOD::TruthParticle *truthParticle(const xAOD::TrackParticle*);
int cvtPt(double);
int cvtEta(double);
int cvtPhi(double);

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
	tree = new TTree("tree","p+Pb 8 TeV HIJING");
	tree->Branch("truZvtx", 	 &truZvtx,     "truZvtx/F");
	tree->Branch("truNch", 		 &truNch,      "truNch/i");
	tree->Branch("truPt", 	   truPt,        "truPt[truNch]/b");
	tree->Branch("truEta", 	   truEta,       "truEta[truNch]/b");
	tree->Branch("truPhi", 	   truPhi,       "truPhi[truNch]/s");

	tree->Branch("recZvtx", 	 &recZvtx,     "recZvtx/F");
	tree->Branch("recNch", 		 &recNch,      "recNch/i");
	tree->Branch("recPt", 	   recPt,        "recPt[recNch]/b");
	tree->Branch("recEta", 	   recEta,       "recEta[recNch]/b");
	tree->Branch("recPhi", 	   recPhi,       "recPhi[recNch]/s");
	tree->Branch("recQual", 	 recQual,      "recQual[recNch]/O");
	tree->Branch("recPrim", 	 recPrim,      "recPrim[recNch]/O");
	tree->Branch("recFake", 	 recFake,      "recFake[recNch]/O");
	tree->Branch("assPt", 	   assPt,        "assPt[recNch]/b");
	tree->Branch("assEta", 	   assEta,       "assEta[recNch]/b");
	tree->Branch("assPhi", 	   assPhi,       "assPhi[recNch]/s");

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
	int flagPhi = int((phi+TMath::Pi())/2/TMath::Pi()*250);
	if(flagPhi<0) flagPhi = 0;
	if(flagPhi>=250) flagPhi = 250;
	return flagPhi;
}



bool isPrimaryParticle(const xAOD::TruthParticle* truth)
{
	if( truth->status() != 1 ) return false;
	if( const_cast<xAOD::TruthParticle*>(truth)->isNeutral() ) return false;
	if( truth->barcode() == 0 || truth->barcode() >= 200e3) return false;
	if( fabs(truth->eta()) >= etaMax ) return false;
	if( truth->pt()/1000. <= pTmin ) return false;
	if( truth->isStrangeBaryon() ) return false;
	return true;
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
	// Truth Vertex
	//------------------------------------------------------ 
	truZvtx = 9999;
	const xAOD::TruthVertexContainer* ptrTruVtxCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrTruVtxCon,"TruthVertices"));
	for(const auto ptrTruVtx : *ptrTruVtxCon)
	{
		//if(ptrTruVtx->vertexType() == xAOD::VxType::PriVtx) // first vertex is always primary vertex
		{
			truZvtx = ptrTruVtx->z();
			break;
		}
	}
	
	
	
	//------------------------------------------------------  
	// Reconstructed Vertex
	//------------------------------------------------------ 
	recZvtx = 9999;
	const xAOD::VertexContainer *ptrRecVtxCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrRecVtxCon,"PrimaryVertices"));
	for(const auto ptrRecVtx : *ptrRecVtxCon)
	{
		if(ptrRecVtx->vertexType() == xAOD::VxType::PriVtx)
		{
			recZvtx = ptrRecVtx->z();
			break;
		}
	}


	//------------------------------------------------------  
	// Truth Tracks
	//------------------------------------------------------ 
	truNch = 0;
	for(int i=0; i<nChMax; i++)
	{
		truPt[i] = 251;
		truEta[i] = 251;
		truPhi[i] = 251;
	}
	const xAOD::TruthVertex *ptrTruVtx = 0;
	const xAOD::TruthParticleContainer* ptrTruTrkCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve( ptrTruTrkCon, "TruthParticles" ));
	for(const auto* ptrTruTrk : *ptrTruTrkCon)
	{
		if(!isPrimaryParticle(ptrTruTrk)) continue;

		bool tagVtx = true;
		ptrTruVtx = vertexTruthParticle(ptrTruTrk);
		if(!ptrTruVtx) tagVtx = false;
		else if(fabs(ptrTruVtx->z()-truZvtx)>0.0001) tagVtx = false;

		truPt[truNch] = cvtPt(ptrTruTrk->pt());
		truEta[truNch] = cvtEta(ptrTruTrk->eta());
		truPhi[truNch] = cvtPhi(ptrTruTrk->phi());

		truNch ++;
	}

	//------------------------------------------------------  
	// Reconstructed Tracks
	//------------------------------------------------------ 
	recNch = 0;
	for(int i=0; i<nChMax; i++)
	{
		recPt[i] = 251;
		recEta[i] = 251;
		recPhi[i] = 251;
		recPrim[i] = true;
		recFake[i] = false;
		assPt[i] = 251;
		assEta[i] = 251;
		assPhi[i] = 251;
	}

	const xAOD::Vertex *ptrVtx = 0;
	const xAOD::TruthParticle* ptrTruRec = 0;
	const xAOD::TrackParticleContainer *ptrRecTrkCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrRecTrkCon,"InDetTrackParticles"));
	for(const auto* ptrRecTrk : *ptrRecTrkCon)
	{
		if(!trackSelection(ptrRecTrk, recZvtx)) continue;

		ptrTruRec = truthParticle(ptrRecTrk);
		if(!ptrTruRec) recFake[recNch] = true;
		else if(ptrTruRec->barcode()==0) recFake[recNch] = true;
		if(ptrRecTrk->auxdata<float>("truthMatchProbability")<0.5) recFake[recNch] = true;

		if(!ptrTruRec) recPrim[recNch] = false;
		else if(!isPrimaryParticle(ptrTruRec)) recPrim[recNch] = false;
		if(ptrRecTrk->auxdata<float>("truthMatchProbability")<0.5) recPrim[recNch] = false;

		if(recPrim[recNch])
		{
			bool tagVtx = true;
			ptrVtx = vertexParticle(ptrRecTrk);
			if(!ptrVtx) tagVtx = false;
			else if(fabs(ptrVtx->z()-recZvtx)>0.0001) tagVtx = false;
			//std::cout<<tagVtx<<std::endl;
		}

		if(fabs(sin(ptrRecTrk->theta())*(ptrRecTrk->z0()+ptrRecTrk->vz()-recZvtx))<1.0 && fabs(ptrRecTrk->d0())<1.0) recQual[recNch] = 1;
		else recQual[recNch] = 0;

		recPt[recNch] = cvtPt(ptrRecTrk->pt());
		recEta[recNch] = cvtEta(ptrRecTrk->eta());
		recPhi[recNch] = cvtPhi(ptrRecTrk->phi());
		if(ptrTruRec)
		{
			assPt[recNch] = cvtPt(ptrTruRec->pt());
			assEta[recNch] = cvtEta(ptrTruRec->eta());
			assPhi[recNch] = cvtPhi(ptrTruRec->phi());
		}

		recNch ++;
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
