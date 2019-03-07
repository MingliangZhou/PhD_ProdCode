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
#include "xAODJet/JetContainer.h"

const double etCut[50] ={0,0.34,0.48,0.42,0.48,0.28,0.32,0.38,0.6,0.58,0.13,0.17,0.28,0.11,0.14,0.14,0.34,0.39,0.28,0.3,0.3,0.34,0.37,0.38,0.4,0.38,0.37,0.36,0.34,0.32,0.3,0.25,0.26,0.29,0.14,0.12,0.1,0.1,0.16,0.32,0.32,0.48,0.4,0.35,0.34,0.98,0.44,0.31,0.41,0};

const int pairedBunches1[424] = {18, 22, 29, 33, 40, 44, 51, 55, 62, 66, 73, 77, 84, 88, 124, 128, 135, 139, 146, 150, 157, 161, 168, 172, 179, 183, 190, 194, 201, 205, 212, 216, 223, 227, 234, 238, 245, 249, 285, 289, 296, 300, 307, 311, 318, 322, 329, 333, 340, 344, 351, 355, 362, 366, 373, 377, 384, 388, 395, 399, 607, 611, 618, 622, 629, 633, 640, 644, 651, 655, 693, 697, 704, 708, 715, 719, 726, 730, 737, 741, 748, 752, 759, 763, 770, 774, 781, 785, 792, 796, 803, 807, 814, 818, 854, 858, 865, 869, 876, 880, 887, 891, 898, 902, 909, 913, 920, 924, 931, 935, 942, 946, 953, 957, 964, 968, 975, 979, 1015, 1019, 1026, 1030, 1037, 1041, 1048, 1052, 1059, 1063, 1070, 1074, 1081, 1085, 1092, 1096, 1103, 1107, 1114, 1118, 1125, 1129, 1136, 1140, 1176, 1180, 1187, 1191, 1198, 1202, 1209, 1213, 1220, 1224, 1231, 1235, 1242, 1246, 1253, 1257, 1264, 1268, 1275, 1279, 1286, 1290, 1498, 1502, 1509, 1513, 1520, 1524, 1531, 1535, 1542, 1546, 1584, 1588, 1595, 1599, 1606, 1610, 1617, 1621, 1628, 1632, 1639, 1643, 1650, 1654, 1661, 1665, 1672, 1676, 1683, 1687, 1694, 1698, 1705, 1709, 1745, 1749, 1756, 1760, 1767, 1771, 1778, 1782, 1789, 1793, 1800, 1804, 1811, 1815, 1822, 1826, 1833, 1837, 1844, 1848, 1855, 1859, 1866, 1870, 1906, 1910, 1917, 1921, 1928, 1932, 1939, 1943, 1950, 1954, 1961, 1965, 1972, 1976, 1983, 1987, 1994, 1998, 2005, 2009, 2016, 2020, 2027, 2031, 2067, 2071, 2078, 2082, 2089, 2093, 2100, 2104, 2111, 2115, 2122, 2126, 2133, 2137, 2144, 2148, 2155, 2159, 2166, 2170, 2177, 2181, 2188, 2192, 2228, 2232, 2239, 2243, 2250, 2254, 2261, 2265, 2272, 2276, 2283, 2287, 2294, 2298, 2305, 2309, 2316, 2320, 2327, 2331, 2338, 2342, 2349, 2353, 2389, 2393, 2400, 2404, 2411, 2415, 2422, 2426, 2433, 2437, 2475, 2479, 2486, 2490, 2497, 2501, 2508, 2512, 2519, 2523, 2530, 2534, 2541, 2545, 2552, 2556, 2563, 2567, 2574, 2578, 2585, 2589, 2596, 2600, 2636, 2640, 2647, 2651, 2658, 2662, 2669, 2673, 2680, 2684, 2691, 2695, 2702, 2706, 2713, 2717, 2724, 2728, 2735, 2739, 2746, 2750, 2757, 2761, 2797, 2801, 2808, 2812, 2819, 2823, 2830, 2834, 2841, 2845, 2852, 2856, 2863, 2867, 2874, 2878, 2885, 2889, 2896, 2900, 2907, 2911, 2918, 2922, 2958, 2962, 2969, 2973, 2980, 2984, 2991, 2995, 3002, 3006, 3013, 3017, 3024, 3028, 3035, 3039, 3046, 3050, 3057, 3061, 3068, 3072, 3079, 3083, 3119, 3123, 3130, 3134, 3141, 3145, 3152, 3156, 3163, 3167, 3174, 3178, 3185, 3189, 3196, 3200, 3207, 3211, 3218, 3222, 3229, 3233, 3240, 3244};
const int pairedBunches2[424] = {18, 22, 29, 33, 40, 44, 51, 55, 62, 66, 73, 77, 84, 88, 124, 128, 135, 139, 146, 150, 157, 161, 168, 172, 179, 183, 190, 194, 201, 205, 212, 216, 223, 227, 234, 238, 245, 249, 285, 289, 296, 300, 307, 311, 318, 322, 329, 333, 340, 344, 351, 355, 362, 366, 373, 377, 384, 388, 395, 399, 607, 611, 618, 622, 629, 633, 640, 644, 651, 655, 693, 697, 704, 708, 715, 719, 726, 730, 737, 741, 748, 752, 759, 763, 770, 774, 781, 785, 792, 796, 803, 807, 814, 818, 854, 858, 865, 869, 876, 880, 887, 891, 898, 902, 909, 913, 920, 924, 931, 935, 942, 946, 953, 957, 964, 968, 975, 979, 1015, 1019, 1026, 1030, 1037, 1041, 1048, 1052, 1059, 1063, 1070, 1074, 1081, 1085, 1092, 1096, 1103, 1107, 1114, 1118, 1125, 1129, 1136, 1140, 1176, 1180, 1187, 1191, 1198, 1202, 1209, 1213, 1220, 1224, 1231, 1235, 1242, 1246, 1253, 1257, 1264, 1268, 1275, 1279, 1286, 1290, 1498, 1502, 1509, 1513, 1520, 1524, 1531, 1535, 1542, 1546, 1584, 1588, 1595, 1599, 1606, 1610, 1617, 1621, 1628, 1632, 1639, 1643, 1650, 1654, 1661, 1665, 1672, 1676, 1683, 1687, 1694, 1698, 1705, 1709, 1745, 1749, 1756, 1760, 1767, 1771, 1778, 1782, 1789, 1793, 1800, 1804, 1811, 1815, 1822, 1826, 1833, 1837, 1844, 1848, 1855, 1859, 1866, 1870, 1906, 1910, 1917, 1921, 1928, 1932, 1939, 1943, 1950, 1954, 1961, 1965, 1972, 1976, 1983, 1987, 1994, 1998, 2005, 2009, 2016, 2020, 2027, 2031, 2067, 2071, 2078, 2082, 2089, 2093, 2100, 2104, 2111, 2115, 2122, 2126, 2133, 2137, 2144, 2148, 2155, 2159, 2166, 2170, 2177, 2181, 2188, 2192, 2228, 2232, 2239, 2243, 2250, 2254, 2261, 2265, 2272, 2276, 2283, 2287, 2294, 2298, 2305, 2309, 2316, 2320, 2327, 2331, 2338, 2342, 2349, 2353, 2389, 2393, 2400, 2404, 2411, 2415, 2422, 2426, 2433, 2437, 2475, 2479, 2486, 2490, 2497, 2501, 2508, 2512, 2519, 2523, 2530, 2534, 2541, 2545, 2552, 2556, 2563, 2567, 2574, 2578, 2585, 2589, 2596, 2600, 2636, 2640, 2647, 2651, 2658, 2662, 2669, 2673, 2680, 2684, 2691, 2695, 2702, 2706, 2713, 2717, 2724, 2728, 2735, 2739, 2746, 2750, 2757, 2761, 2797, 2801, 2808, 2812, 2819, 2823, 2830, 2834, 2841, 2845, 2852, 2856, 2863, 2867, 2874, 2878, 2885, 2889, 2896, 2900, 2907, 2911, 2918, 2922, 2958, 2962, 2969, 2973, 2980, 2984, 2991, 2995, 3002, 3006, 3013, 3017, 3024, 3028, 3035, 3039, 3046, 3050, 3057, 3061, 3068, 3072, 3079, 3083, 3119, 3123, 3130, 3134, 3141, 3145, 3152, 3156, 3163, 3167, 3174, 3178, 3185, 3189, 3196, 3200, 3207, 3211, 3218, 3222, 3229, 3233, 3240, 3244};

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
	tree->Branch("EvtNumber",&EvtNumber,"EvtNumber/I");
	tree->Branch("L1TE",&L1TE,"L1TE/F");
	tree->Branch("trig",trig,"trig[25]/F");
	tree->Branch("trigL1",trigL1,"trigL1[25]/F");
	tree->Branch("nVtx",&nVtx,"nVtx/I");
	tree->Branch("trkVtx",trkVtx,"trkVtx[nVtx]/I");
	tree->Branch("xVtx",xVtx,"xVtx[nVtx]/F");
	tree->Branch("yVtx",yVtx,"yVtx[nVtx]/F");
	tree->Branch("zVtx",zVtx,"zVtx[nVtx]/F");
	tree->Branch("FCalA",&FCalA,"FCalA/F");
	tree->Branch("FCalC",&FCalC,"FCalC/F");
	tree->Branch("gapA",&gapA,"gapA/F");
	tree->Branch("gapC",&gapC,"gapC/F");
	tree->Branch("gapAnew",&gapAnew,"gapAnew/F");
	tree->Branch("gapCnew",&gapCnew,"gapCnew/F");
	//tree->Branch("numC",&numC,"numC/I");
	//tree->Branch("disC",disC,"disC[50]/I");
	///*
	tree->Branch("MBTStimeA",&MBTStimeA,"MBTStimeA/F");
	tree->Branch("MBTStimeC",&MBTStimeC,"MBTStimeC/F");
	//tree->Branch("MBTStimeDiff",&MBTStimeDiff,"MBTStimeDiff/F");
	tree->Branch("MBTScountA",&MBTScountA,"MBTScountA/F");
	tree->Branch("MBTScountC",&MBTScountC,"MBTScountC/F");
	//tree->Branch("mbtsEt",mbtsEt,"mbtsEt[24]/F");
	//tree->Branch("mbtsTime",mbtsTime,"mbtsTime[24]/F");
	//tree->Branch("MbtsOutA",&MbtsOutA,"MbtsOutA/I");
	//tree->Branch("MbtsInA",&MbtsInA,"MbtsInA/I");
	//tree->Branch("MbtsOutC",&MbtsOutC,"MbtsOutC/I");
	//tree->Branch("MbtsInC",&MbtsInC,"MbtsInC/I");
	//*/
	/*
	tree->Branch("nEt",&nEt,"nEt/I");
	tree->Branch("et",et,"et[nEt]/F");
	tree->Branch("etaMin",etaMin,"etaMin[nEt]/F");
	tree->Branch("etaMax",etaMax,"etaMax[nEt]/F");
	tree->Branch("layer",layer,"layer[nEt]/F");
	//tree->Branch("etCos",etCos,"etCos[nEt][7]/F");
	//tree->Branch("etSin",etSin,"etSin[nEt][7]/F");
	*/
	/*
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
	/*
	tree->Branch("nTopo",&nTopo,"nTopo/I");
	tree->Branch("eTopo",eTopo,"eTopo[nTopo]/F");
	tree->Branch("etTopo",etTopo,"etTopo[nTopo]/F");
	tree->Branch("etaTopo",etaTopo,"etaTopo[nTopo]/F");
	tree->Branch("phiTopo",phiTopo,"phiTopo[nTopo]/F");
	tree->Branch("sigClus",sigClus,"sigClus[nTopo]/F");
	tree->Branch("sigCell",sigCell,"sigCell[nTopo]/F");
	tree->Branch("sigSamp",sigSamp,"sigSamp[nTopo]/F");
	//tree->Branch("eLayer",eLayer,"eLayer[nTopo][24]/F");
	tree->Branch("layerMax",layerMax,"layerMax[nTopo]/I");
	*/
	//tree->Branch("etaLayer",etaLayer,"etaLayer[nTopo][24]/F");
	//tree->Branch("phiLayer",phiLayer,"phiLayer[nTopo][24]/F");
	//tree->Branch("nTrkOn",&nTrkOn,"nTrkOn/I");
	//tree->Branch("nJet",&nJet,"nJet/I");
	//tree->Branch("jetPt",jetPt,"jetPt[nJet]/F");
	tree->Branch("nTrk",&nTrk,"nTrk/I");
	//tree->Branch("trk",trk,"trk[4][3]/I");
	/*
	tree->Branch("trkN_0",&trkN_0,"trkN_0/I");
	tree->Branch("trkN_1",&trkN_1,"trkN_1/I");
	tree->Branch("trkEta_0",trkEta_0,"trkEta_0[trkN_0]/F");
	tree->Branch("trkEta_1",trkEta_1,"trkEta_1[trkN_1]/F");
	tree->Branch("trkPhi_0",trkPhi_0,"trkPhi_0[trkN_0]/F");
	tree->Branch("trkPhi_1",trkPhi_1,"trkPhi_1[trkN_1]/F");
	tree->Branch("trkPt_0",trkPt_0,"trkPt_0[trkN_0]/F");
	tree->Branch("trkPt_1",trkPt_1,"trkPt_1[trkN_1]/F");
	tree->Branch("trkZ0_0",trkZ0_0,"trkZ0_0[trkN_0]/F");
	tree->Branch("trkZ0_1",trkZ0_1,"trkZ0_1[trkN_1]/F");
	tree->Branch("trkD0_0",trkD0_0,"trkD0_0[trkN_0]/F");
	tree->Branch("trkD0_1",trkD0_1,"trkD0_1[trkN_1]/F");
	*/
	//tree->Branch("eta",eta,"eta[nTrk]/F");
	//tree->Branch("pt",pt,"pt[nTrk]/F");
	//tree->Branch("phi",phi,"phi[nTrk]/F");
	//tree->Branch("chg",chg,"chg[nTrk]/F");
	//tree->Branch("pixHit",pixHit,"pixHit[nTrk]/I");
	//tree->Branch("sctHit",sctHit,"sctHit[nTrk]/I");
	//tree->Branch("trtHit",trtHit,"trtHit[nTrk]/I");
	//tree->Branch("pixHol",pixHol,"pixHol[nTrk]/I");
	//tree->Branch("sctHol",sctHol,"sctHol[nTrk]/I");
	//tree->Branch("trtHol",trtHol,"trtHol[nTrk]/I");


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
	
	if(eventInfo->errorState(xAOD::EventInfo::LAr)==xAOD::EventInfo::Error) return EL::StatusCode::SUCCESS;
	if(eventInfo->errorState(xAOD::EventInfo::Tile)==xAOD::EventInfo::Error) return EL::StatusCode::SUCCESS;
	if(eventInfo->errorState(xAOD::EventInfo::SCT)==xAOD::EventInfo::Error) return EL::StatusCode::SUCCESS;
	if(eventInfo->isEventFlagBitSet(xAOD::EventInfo::Core, 18)) return EL::StatusCode::SUCCESS;
	// only save empty bunches
	int tagEmpty = 1;
	if(lbn>=38 && lbn<=181)
	{
		for(int i=0; i<424; i++)
		{
			if(bcid==pairedBunches1[i]) tagEmpty = -1;
		}
	}
	else if(lbn>=183 && lbn<=590)
	{
		for(int i=0; i<424; i++)
		{
			if(bcid==pairedBunches2[i]) tagEmpty = -1;
		}
	}
	else tagEmpty  = -1;
	//if(tagEmpty>0) return EL::StatusCode::SUCCESS;

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
	FCalA = 0;
	FCalC = 0;
	const xAOD::HIEventShapeContainer *ptrEvtShpCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrEvtShpCon,"HIEventShape"));
	for(const auto *ptrEvtShp : *ptrEvtShpCon)
	{
		et[nEt] = ptrEvtShp->et()/1000;
		etaMin[nEt] = ptrEvtShp->etaMin();
		etaMax[nEt] = ptrEvtShp->etaMax();
		layer[nEt] = ptrEvtShp->layer();

		if(layer[nEt]==21 || layer[nEt]==22 || layer[nEt]==23)
		{
			if((etaMin[nEt]+etaMax[nEt])/2>0) FCalA += et[nEt]/1000;
			if((etaMin[nEt]+etaMax[nEt])/2<0) FCalC += et[nEt]/1000;
		}

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
	gapA = 10;
	gapC = 10;
	gapAnew = 10;
	gapCnew = 10;
	numC = 0;
	for(int i=0; i<50; i++) disC[i] = 0;
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

		if(sigCell[nTopo]>=4.5 && etTopo[nTopo]>=0.2)
		{
			if(5+etaTopo[nTopo]<gapC) gapC = 5+etaTopo[nTopo];
			if(5-etaTopo[nTopo]<gapA) gapA = 5-etaTopo[nTopo];
			numC ++;
			disC[int((etaTopo[nTopo]+5)*5)] ++;
		}
		if(sigCell[nTopo]>=4.5)
		{
			for(int i=0; i<50; i++)
			{
				if(etaTopo[nTopo]<-5+10./50*i || etaTopo[nTopo]>=-5+10./50*(i+1)) continue;
				if(etTopo[nTopo]<etCut[i]) continue;
				if(5+etaTopo[nTopo]<gapCnew) gapCnew = 5+etaTopo[nTopo];
				if(5-etaTopo[nTopo]<gapAnew) gapAnew = 5-etaTopo[nTopo];
			}
		}

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

		double layerMaxE = -1000;
		for(int iL=0; iL<24; iL++)
		{
			if(eLayer[nTopo][iL]>layerMaxE)
			{
				layerMaxE = eLayer[nTopo][iL];
				layerMax[nTopo] = iL;
			}
		}

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
	// MBTS Modules
	//------------------------------------------------------ 
	int tag;
	MbtsOutA = 0;
	MbtsOutC = 0;
	MbtsInA = 0;
	MbtsInC = 0;
	const xAOD::MBTSModuleContainer *ptrMbts1Con = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrMbts1Con,"MBTSModules"));
	for(const auto *ptrMbts1 : *ptrMbts1Con)
	{
		//if(ptrMbts1->e()<40./222) continue;
		if(ptrMbts1->type()==+1 && ptrMbts1->channel()==0 && ptrMbts1->mbtsModule()==0) tag = 0;
		if(ptrMbts1->type()==+1 && ptrMbts1->channel()==0 && ptrMbts1->mbtsModule()==1) tag = 1;
		if(ptrMbts1->type()==+1 && ptrMbts1->channel()==0 && ptrMbts1->mbtsModule()==2) tag = 2;
		if(ptrMbts1->type()==+1 && ptrMbts1->channel()==0 && ptrMbts1->mbtsModule()==3) tag = 3;
		if(ptrMbts1->type()==+1 && ptrMbts1->channel()==0 && ptrMbts1->mbtsModule()==4) tag = 4;
		if(ptrMbts1->type()==+1 && ptrMbts1->channel()==0 && ptrMbts1->mbtsModule()==5) tag = 5;
		if(ptrMbts1->type()==+1 && ptrMbts1->channel()==0 && ptrMbts1->mbtsModule()==6) tag = 6;
		if(ptrMbts1->type()==+1 && ptrMbts1->channel()==0 && ptrMbts1->mbtsModule()==7) tag = 7;
		if(ptrMbts1->type()==+1 && ptrMbts1->channel()==1 && ptrMbts1->mbtsModule()==0) tag = 8;
		if(ptrMbts1->type()==+1 && ptrMbts1->channel()==1 && ptrMbts1->mbtsModule()==2) tag = 9;
		if(ptrMbts1->type()==+1 && ptrMbts1->channel()==1 && ptrMbts1->mbtsModule()==4) tag = 10;
		if(ptrMbts1->type()==+1 && ptrMbts1->channel()==1 && ptrMbts1->mbtsModule()==6) tag = 11;
		if(ptrMbts1->type()==-1 && ptrMbts1->channel()==0 && ptrMbts1->mbtsModule()==0) tag = 12;
		if(ptrMbts1->type()==-1 && ptrMbts1->channel()==0 && ptrMbts1->mbtsModule()==1) tag = 13;
		if(ptrMbts1->type()==-1 && ptrMbts1->channel()==0 && ptrMbts1->mbtsModule()==2) tag = 14;
		if(ptrMbts1->type()==-1 && ptrMbts1->channel()==0 && ptrMbts1->mbtsModule()==3) tag = 15;
		if(ptrMbts1->type()==-1 && ptrMbts1->channel()==0 && ptrMbts1->mbtsModule()==4) tag = 16;
		if(ptrMbts1->type()==-1 && ptrMbts1->channel()==0 && ptrMbts1->mbtsModule()==5) tag = 17;
		if(ptrMbts1->type()==-1 && ptrMbts1->channel()==0 && ptrMbts1->mbtsModule()==6) tag = 18;
		if(ptrMbts1->type()==-1 && ptrMbts1->channel()==0 && ptrMbts1->mbtsModule()==7) tag = 19;
		if(ptrMbts1->type()==-1 && ptrMbts1->channel()==1 && ptrMbts1->mbtsModule()==0) tag = 20;
		if(ptrMbts1->type()==-1 && ptrMbts1->channel()==1 && ptrMbts1->mbtsModule()==2) tag = 21;
		if(ptrMbts1->type()==-1 && ptrMbts1->channel()==1 && ptrMbts1->mbtsModule()==4) tag = 22;
		if(ptrMbts1->type()==-1 && ptrMbts1->channel()==1 && ptrMbts1->mbtsModule()==6) tag = 23;
		if(tag>=0 && tag<8) MbtsInA ++;
		if(tag>=8 && tag<12) MbtsOutA ++;
		if(tag>=12 && tag<20) MbtsInC ++;
		if(tag>=20 && tag<24) MbtsOutC ++;	
		mbtsEt[tag] = ptrMbts1->e();
		mbtsTime[tag] = ptrMbts1->time();
	}
	/*
	std::cout<<MBTScountA<<"="<<MbtsInA<<"+"<<MbtsOutA<<std::endl;
	std::cout<<MBTScountC<<"="<<MbtsInC<<"+"<<MbtsOutC<<std::endl;
	std::cout<<std::endl;
	*/
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
	// Jets
	//------------------------------------------------------ 
	nJet = 0;
	const xAOD::JetContainer *ptrJetCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrJetCon,"AntiKt4HIJets"));
	for(const auto *ptrJet : *ptrJetCon)
	{
		jetPt[nJet] = ptrJet->pt();
		nJet++;
	}

	
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
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<3; j++) trk[i][j] = 0;
	}
	trkN_0 = 0;
	trkN_1 = 0;
	int tagVtx;
	int tagQual;
	int tagPt;
	const xAOD::TrackParticleContainer *ptrTrkCon = 0;
	EL_RETURN_CHECK("execute",m_event->retrieve(ptrTrkCon,"InDetTrackParticles"));
	for(const auto *ptrTrk : *ptrTrkCon)
	{
		const xAOD::Vertex *ptrVtx = vertexParticle(ptrTrk);
		if(ptrVtx) tagVtx = 1;
		else tagVtx = 0;
		if(tagVtx == 0)
		{
			trkEta_0[trkN_0] = ptrTrk->eta();
			trkPhi_0[trkN_0] = ptrTrk->phi();
			trkPt_0[trkN_0] = ptrTrk->pt();
			trkZ0_0[trkN_0] = ptrTrk->z0()*sin(ptrTrk->theta());
			trkD0_0[trkN_0] = ptrTrk->d0();
			trkN_0 ++;
		}
		if(tagVtx == 1)
		{
			trkEta_1[trkN_1] = ptrTrk->eta();
			trkPhi_1[trkN_1] = ptrTrk->phi();
			trkPt_1[trkN_1] = ptrTrk->pt();
			trkZ0_1[trkN_1] = ptrTrk->z0()*sin(ptrTrk->theta());
			trkD0_1[trkN_1] = ptrTrk->d0();
			trkN_1 ++;
		}
		//if(fabs(ptrVtx->z()-zVtx[0])>0.0001) continue;
		/*
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
		theta[nTrk] = ptrTrk->theta();
		z0[nTrk] = ptrTrk->z0()+ptrTrk->vz()-zVtx[0];
		//std::cout<<ptrTrk->z0()<<" | "<<ptrTrk->vz()<<" | "<<zVtx[0]<<std::endl;
		d0[nTrk] = ptrTrk->d0();
		pixHit[nTrk] = ptrTrk->auxdata<unsigned char>("numberOfPixelHits");
		sctHit[nTrk] = ptrTrk->auxdata<unsigned char>("numberOfSCTHits");
		trtHit[nTrk] = ptrTrk->auxdata<unsigned char>("numberOfTRTHits");
		pixHol[nTrk] = ptrTrk->auxdata<unsigned char>("numberOfPixelHoles");
		sctHol[nTrk] = ptrTrk->auxdata<unsigned char>("numberOfSCTHoles");
		trtHol[nTrk] = ptrTrk->auxdata<unsigned char>("numberOfTRTHoles");

		if(fabs(eta[nTrk])>2.5) continue;
		tagQual = 0;
		if(pixHit[nTrk]>0 && sctHit[nTrk]>=6 && d0[nTrk]<=1.5 && z0[nTrk]*sin(theta[nTrk])<=1.5 && ptrTrk->numberDoF()>0)
		{
			tagQual = 1;
		}
		if(pixHit[nTrk]>=2 && sctHit[nTrk]>=8 && sctHol[nTrk]<=1 && d0[nTrk]<=1. && z0[nTrk]*sin(theta[nTrk])<=1. && ptrTrk->chiSquared()/ptrTrk->numberDoF()<=6)
		{
			tagQual = 2;
		}
		tagPt = -1;
		if(ptrTrk->pt()/1000.>=0.3) tagPt = 0;
		if(ptrTrk->pt()/1000.>=0.5) tagPt = 1;
		if(ptrTrk->pt()/1000.>=0.7) tagPt = 2;
		if(ptrTrk->pt()/1000.>=1) tagPt = 3;

		for(int i=0; i<=tagPt; i++)
		{
			for(int j=0; j<=tagQual; j++) trk[i][j] ++;
		}
		nTrk++;
	}
	for(int iTrk=0; iTrk<nTrk; iTrk++)
	{
		if(5-eta[iTrk]<gapA) gapA = 5-eta[iTrk];
		if(5+eta[iTrk]<gapC) gapC = 5+eta[iTrk];
	}
	for(int iTrk=0; iTrk<nTrk; iTrk++)
	{
		if(5-eta[iTrk]<gapAnew) gapAnew = 5-eta[iTrk];
		if(5+eta[iTrk]<gapCnew) gapCnew = 5+eta[iTrk];
	}

	double gapAtool;
	double gapCtool;
	HI::HIGapCalculationTool *gapTool = new HI::HIGapCalculationTool("gapTool");
	//HI::HIGapCalculationTool gapTool("gapTool");
	gapTool->CalculateGaps(gapAtool,gapCtool);
	//delete gapTool;

	std::cout<<"Ref: "<<gapAnew<<" | "<<gapCnew<<std::endl;
	std::cout<<"Chk: "<<gapAtool<<" | "<<gapCtool<<std::endl;
	std::cout<<"Dif: "<<gapAtool-gapAnew<<" | "<<gapCtool-gapCnew<<std::endl;
	std::cout<<std::endl;

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
