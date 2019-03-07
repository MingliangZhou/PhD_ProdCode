/**    @file HLTMinBiasMonTool.cxx
 *   
 *    
 *    DON'T DELETE THE COMMENTS                   
 *                          
 *    @author Regina Kwee
 *    BCM modifications and updates : eo - at - hep.ucl.ac.uk
 *    updated by Alexander Paramonov
 *    updated by Edward Sarkisyan-Grinbaum (High Mult,Energy-Timing,Eff)
 *    (8 TeV Low-mu, Lucid)
 *    (pA 2012 pilot run changes:
 *    mbSpTrk->mbSp,rd0_filled_NoAlg->mbRd1_eff, mbZdc, mbLucid, histos)
 *    (pA run Jan 2013:
 *    mbSpTrk || mbSp,rd0_filled_NoAlg in, and a lot of pA hip_trk trigs,
 *    Lucid_eff, mbMbts_1_eff->mbMbts_2_eff, EF_L1LHCF_NoAlg, EF_L1ZDC_A/C_NoAlg)
 *    sedward - at - cern.ch
 *    Edward Sarkisyan-Grinbaum (moved to unmanaged histo booking:
 *    https://twiki.cern.ch/twiki/bin/viewauth/AtlasComputing/
 *       LS1UpgradeAthenaMonFramework)
 *    sedward - at - cern.ch
 *
 *    Based on HLTMonTool example by Christiane Risler and Martin zur Nedden
 */
#include "TrigMinBiasMonitoring/HLTMinBiasMonTool.h" 
 
#include "GaudiKernel/IJobOptionsSvc.h"
#include "AthenaMonitoring/AthenaMonManager.h"
#include "AthenaMonitoring/ManagedMonitorToolTest.h"
#include "AthenaMonitoring/ManagedMonitorToolBase.h"

#include "xAODTrigMinBias/TrigSpacePointCountsContainer.h"
#include "xAODTrigMinBias/TrigSpacePointCounts.h"
#include "xAODTrigMinBias/TrigT2MbtsBitsContainer.h"
#include "xAODTrigMinBias/TrigT2MbtsBits.h"
#include "xAODTrigMinBias/TrigVertexCountsContainer.h"
#include "xAODTrigMinBias/TrigVertexCounts.h"
#include "xAODTrigMinBias/TrigTrackCountsContainer.h"
#include "xAODTrigMinBias/TrigTrackCounts.h"

#include "TileEvent/TileContainer.h"
#include "TileEvent/TileCell.h"
#include "TileEvent/TileDigitsContainer.h"

#include "InDetBCM_RawData/BCM_RDO_Container.h"

#include "LUCID_RawEvent/LUCID_RawDataContainer.h"

#include "ZdcEvent/ZdcDigitsCollection.h"
#include "ZdcEvent/ZdcRawChannelCollection.h"
#include "ZdcEvent/ZdcRawChannel.h"
#include "ZdcEvent/ZdcRawData.h"

#include "CaloEvent/CaloCell.h"
#include "CaloEvent/CaloCellContainer.h"
#include "CaloEvent/CaloSamplingHelper.h"
#include "CaloGeoHelpers/CaloSampling.h"

// Energy-Time 
#include "TrigCaloEvent/TrigT2MbtsBitsContainer.h"

#include "xAODTrigMinBias/TrigHisto2D.h"
#include "TrigInDetEvent/TrigVertexCollection.h"

#include "xAODTracking/TrackParticle.h"
#include "xAODTracking/VertexContainer.h"
#include "xAODTrigger/EnergySumRoI.h"
#include "xAODTrigMissingET/TrigMissingETContainer.h"
#include "xAODMissingET/MissingETContainer.h"

#include "TROOT.h"
#include "TH1I.h"
#include "TH1F.h"
#include "TH2I.h"
#include "TH2F.h"
#include "TH1D.h"

#include <bitset>


using namespace std;

/** Constructor, calls base class constructor with parameters
 *
 *  several properties are "declared" here, allowing selection
 *  of the filepath for histograms, the first and second plane
 *  numbers to be used, and the timebin.
 */
HLTMinBiasMonTool::HLTMinBiasMonTool(const std::string & type, const std::string & myname, const IInterface* parent) :
	IHLTMonTool(type, myname, parent), m_log(0), m_tileTBID(0)
{
	m_log = new MsgStream(msgSvc(), name());

	//Lvl-2 containers
	declareProperty("SPContainerName", m_spContainerName);

	// Cut made on time over-threshold before any multiplicities are calculated.
	declareProperty("PixelCLToTCut", m_timeOverThresholdCut = 20.);

	// If set to false the trigger combination of Pixel and SCT is an OR.
	declareProperty("TriggerTypeAND", m_triggerTypeAND = true);

	// Threshold settings for multiplicity requirements.
	// A trigger threshold can be disabled by setting it to be < 0
	declareProperty("TotalPixelClus", m_totalPixelClus_cut = 3.);

	declareProperty("TotalSctSp", m_totalSctSp_cut = 3.);

	//EF container
	declareProperty("TCContainerName", m_tcContainerName);

	declareProperty("max_z0", m_max_z0 = 401.0); // (mm)
	declareProperty("min_pt", m_min_pt = 0.2); // (GeV)
	
	// Parameter to be tuned to correspond to trigger threshold
	declareProperty("TimeCut", m_timeCut = 20.0);
	declareProperty("EnergyCut", m_energyCut = 40. / 222.); // It should be 60./222.
	
	// -------------------------------------------------------- NEW AUTOMATIC WAY TO COPE WITH THINGS----------------------
	declareProperty("monitoring_minbias", m_trigItems);
	declareProperty("MinBiasAvailableAlgorithms", m_availableAlgs);
	declareProperty("MinBiasHistoTargets", m_histoTargets);	

	m_numberOfEvents=0;
	//Energy-Time
	declareProperty("T2MBTSContainerName", m_t2mbtsContainerName);
	declareProperty("MBTSContainerName", m_mbtsContainerName);
	declareProperty("MBTS_countsSideA", m_mbtsCountsSideA);
	declareProperty("MBTS_countsSideC", m_mbtsCountsSideC);
        
	//BCM
	declareProperty("BCMContainerName", m_bcmContainerName = "BCM_RDOs");
	//Timing Cut-offs
	declareProperty("OutOfTimePulsePosition", m_OOTPulse = 11); //6 old value
	declareProperty("InTimePulsePosition", m_ITPulse = 43); //38 old value
	declareProperty("WideInTimePulsePosition", m_WITPulse = 38); //38 old value
	declareProperty("NarrowTimeWindow", m_TimeWindow = 7); //2 old value
	declareProperty("WideTimeWindow", m_WideTimeWindow = 10); //10 old value
	declareProperty("RdoIndex", m_rdoIndex = 18); // Rdo index; 0 for MC
	
	//LUCID
	declareProperty("LUCID_RawDataContainerName", m_LUCID_RawDataContainerName);
	
	//ZDC
	declareProperty("ZDC_ContainerName", m_ZdcContainerName);
	declareProperty("Calo_ContainerName", m_CaloCellContainerName);

	std::ostringstream ss;
	std::string partName;

	//side A
	for (int c = 0; c < 16; c++) {
		partName = "A";
		ss.str("");
		ss << partName << std::setfill('0') << std::setw(2) << c << std::setfill(' '); //MBTS_A00, MBTS_C03
		m_moduleLabel.push_back(ss.str());
	}

	//side C
	for (int c = 0; c < 16; c++) {
		partName = "C";
		ss.str("");
		ss << partName << std::setfill('0') << std::setw(2) << c << std::setfill(' '); //MBTS_A00, MBTS_C03
		m_moduleLabel.push_back(ss.str());
	}

	//HMT
	declareProperty("VCContainerName", m_vcContainerName);
	declareProperty("VColContainerName", m_vcolContainerName);
	//declareProperty("TrigSpacePointCountsName", m_trigSpacePointCountsName);
	// Cut made on time overthreshold before any multiplicities are calculated.
	declareProperty("PixelCLToTCut", m_timeOverThreshold_cut = 20.);
		
	//purity & efficiency
	declareProperty("InDetTrackParticleContainerName", m_inDetTrackParticleContainerName);
	
	declareProperty("MinBiasRefTrigItem", m_refTrigItem);
	declareProperty("MinBiasEffCuts", m_effCuts);
	declareProperty("MinBiasPurCuts", m_purCuts);
}

StatusCode HLTMinBiasMonTool::init()
{
    StatusCode sc;

	/*sc = service("StoreGateSvc", m_storeGate);
	if (sc.isFailure()) {
		ATH_MSG_FATAL("Unable to locate Service StoreGateSvc");
		return sc;
	}*/

	sc = service("DetectorStore", m_detStore);
	if (sc.isFailure()) {
		(*m_log) << MSG::ERROR << "Unable to get pointer to DetectorStore Service" << endreq;
		return sc;
	}
	
	sc = m_detStore->retrieve(m_tileTBID);
	if (sc.isFailure()) {
		(*m_log) << MSG::ERROR << "Unable to retrieve TileTBID helper from DetectorStore" << endreq;
		return sc;
	}
	
	sc = m_detStore->retrieve(m_ZdcID);
	if (sc.isFailure()) {
		(*m_log) << MSG::ERROR << "Unable to retrieve ZdcID helper from DetectorStore" << endreq;
		return sc;
	}
	
	/*sc = m_detStore->retrieve(m_evinfo);
	if (sc.isFailure()) {
		(*m_log) << MSG::ERROR << "Unable to retrieve XAOD::EventInfo helper from DetectorStore" << endreq;
		return sc;
	}*/

	// retrieve the trigger decision tool
	/*sc = m_tdthandle.retrieve();
	if (sc.isFailure()) {
		*m_log << MSG::ERROR << "Could not retrieve TrigDecisionTool!" << endreq;
		return sc;
	}*/
	
	// --------------------------------- NEW AUTOMATIC WAY TO COPE WITH THINGS----------------------
        
	//filling map so that only desired algorithms will be executed in the following steps...
	for (unsigned i = 0; i < m_availableAlgs.size(); ++i)
	{
		m_algorithmsForChainClass[m_availableAlgs[i]] = m_histoTargets[i]; 
		m_effCutForChainClass[m_availableAlgs[i]] = i;
	}
  
	m_pathForGroup[MBTS]  =         "MBTS";
	m_pathForGroup[LUCID] =         "LUCID";
	m_pathForGroup[IDMINBIAS] =     "IDMinbias";
	m_pathForGroup[ZDC] =           "ZDC";
	m_pathForGroup[BCM] =           "BCM";
	m_pathForGroup[HMT] =           "HMT";
        
	m_mbtsCountsBothSides = m_mbtsCountsSideA + m_mbtsCountsSideC;
        
	/*
	 sc = service("THistSvc", m_histsvc);
	 if( sc.isFailure() ) {
	 *m_log << MSG::FATAL << "Unable to locate Service THistSvc" << endreq;
	 return sc;
	 }
	 */

	sc = ManagedMonitorToolBase::initialize();
	if (sc.isFailure()) {
		*m_log << MSG::ERROR << "Unable to call ManagedMonitoringToolBase::initialize" << endreq;
		return sc;
	}
	
	//purity & efficiency	
	initSelTools(m_effSelTool, m_effCuts);
	initSelTools(m_purSelTool, m_purCuts);
	
	return sc;
}

void HLTMinBiasMonTool::initSelTools(std::vector< ToolHandle< InDet::IInDetTrackSelectionTool > > &selTool, const std::vector<unsigned> &cuts)
{
	StatusCode sc;
	
	selTool.resize(cuts.size()); 
	for (unsigned i = 0; i < cuts.size(); ++i )
	{
		selTool[i] = ToolHandle< InDet::IInDetTrackSelectionTool >( "InDet::InDetTrackSelectionTool/TrackSelection", this );
		switch(cuts[i])
		{
			case 0:
				selTool[i]->setCutLevel( InDet::CutLevel::NoCut );
				break;
			case 1:
				selTool[i]->setCutLevel( InDet::CutLevel::Loose );
				break;
			case 2:
				selTool[i]->setCutLevel( InDet::CutLevel::LoosePrimary );
				break;
			case 3:
				selTool[i]->setCutLevel( InDet::CutLevel::TightPrimary );
				break;
			default:
				*m_log << MSG::WARNING << "Inappropriate cut level for InDetTrackSelectionTool - setting to default..." << endreq;
		}
		
		sc = selTool[i]->initialize();
		if (sc.isFailure())
		{
			*m_log << MSG::ERROR << "Unable to initialize InDetTrackSelectionTool" << endreq;
		}
	}
	
	return;
}
#ifdef ManagedMonitorToolBase_Uses_API_201401
StatusCode HLTMinBiasMonTool::book()
#else
StatusCode HLTMinBiasMonTool::book(bool newEventsBlock, bool newLumiBlock, bool newRun)
#endif
{
// Mingliang
// + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
//+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
// + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
// Validation Plots for Online and Offline Information
	addMonGroup(new MonGroup(this, "HLT/MinBiasMon/Validation", run, ATTRIB_UNMANAGED));
	addHistogram(new TH1F("hOnL1te","Online L1TE;online L1TE;entry rate",110,-10,100));
	addHistogram(new TH1F("hOnSumEt","Online SumEt;online sumEt;entry rate",110,-50,500));
	addHistogram(new TH1F("hOffSumEt","Offline SumEt;offline sumEt;entry rate",110,-50,500));
	addHistogram(new TH1F("hOnSp","Online Space Points;online space points;entry rate",300,0,3000));
	addHistogram(new TH1F("hOnTrk","Online Tracks;online tracks;entry rate",200,0,400));
	addHistogram(new TH1F("hOffTrk","Offline Tracks;offline tracks;entry rate",200,0,400));
	addHistogram(new TH1F("hOnVtx","Online Vertices;online vertices;entry rate",10,-0.5,9.5));
	addHistogram(new TH1F("hOffVtx","Offline Vertices;offline vertices;entry rate",10,-0.5,9.5));
	addHistogram(new TH1F("hOnTrkPri","Online Tracks from PriVtx;online tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hOffTrkPri","Offline Tracks from PriVtx;offline tracks from priVtx;entry rate",200,0,200));
// Online Offline
	addHistogram(new TH2F("hOnOffTrk","Online & Offline Tracks;online tracks;offline tracks",200,0,200,200,0,200));
	addHistogram(new TH2F("hOnOffVtx","Online & Offline Vertices;online vertices;offline vertices",10,-0.5,9.5,10,-0.5,9.5));
	addHistogram(new TH2F("hOnOffTrkPri","Online & Offline Tracks from PriVtx;online tracks from priVtx;offline tracks from priVtx",200,0,200,200,0,200));
	addHistogram(new TH2F("hOnOffSumEt","Online & Offline SumEt;online sumEt;offline sumEt",200,-100,900,200,-100,900));
	addHistogram(new TH2F("hOnMbtsAC","MBTS sideA & sideC Hits;sideA Hits;sideC Hits",13,-0.5,12.5,13,-0.5,12.5));
// Pile Up Suppression
	addMonGroup(new MonGroup(this, "HLT/MinBiasMon/PileUp", run, ATTRIB_UNMANAGED));
	addHistogram(new TH1F("hOnWei","Online pile up weight;online pile up weight;entry rate",400,0,2000));
	addHistogram(new TH2F("hOnWeiOffTrk","Online pile up weight & Offline tracks;online pile up weight;offline tracks",400,0,2000,200,0,200));
	addHistogram(new TH1F("hOnWeiCut0","Online pile up weight >= 0;offline tracks;entry rate",200,0,200));
	addHistogram(new TH1F("hOnWeiCut1","Online pile up weight >= 100;offline tracks;entry rate",200,0,200));
	addHistogram(new TH1F("hOnWeiCut2","Online pile up weight >= 200;offline tracks;entry rate",200,0,200));
	addHistogram(new TH1F("hOnWeiCut3","Online pile up weight >= 300;offline tracks;entry rate",200,0,200));
	addHistogram(new TH1F("hOnWeiCut4","Online pile up weight >= 400;offline tracks;entry rate",200,0,200));
	addHistogram(new TH1F("hOnWeiCut5","Online pile up weight >= 500;offline tracks;entry rate",200,0,200));
	addHistogram(new TH1F("hOnWeiCut6","Online pile up weight >= 600;offline tracks;entry rate",200,0,200));
	addHistogram(new TH1F("hOnWeiCut7","Online pile up weight >= 700;offline tracks;entry rate",200,0,200));
	addHistogram(new TH1F("hOnWeiCut8","Online pile up weight >= 800;offline tracks;entry rate",200,0,200));
	addHistogram(new TH1F("hOnWeiCut9","Online pile up weight >= 900;offline tracks;entry rate",200,0,200));
// SumEt Bug
	addMonGroup(new MonGroup(this, "HLT/MinBiasMon/SumEtBug", run, ATTRIB_UNMANAGED));
	addHistogram(new TH1F("hOnSumEtAll","Online SumEt All;online sumEt;entry rate",110,-50,500));
	addHistogram(new TH1F("hOffSumEtAll","Offline SumEt All;offline sumEt;entry rate",110,-50,500));
	addHistogram(new TH1F("hOffSumEt0","Offline SumEt PEMB;offline sumEt;entry rate",110,-20,200));
	addHistogram(new TH1F("hOffSumEt1","Offline SumEt EMB;offline sumEt;entry rate",110,-20,200));
	addHistogram(new TH1F("hOffSumEt2","Offline SumEt PEME;offline sumEt;entry rate",110,-20,200));
	addHistogram(new TH1F("hOffSumEt3","Offline SumEt EME;offline sumEt;entry rate",110,-20,200));
	addHistogram(new TH1F("hOffSumEt4","Offline SumEt TILE;offline sumEt;entry rate",110,-20,200));
	addHistogram(new TH1F("hOffSumEt5","Offline SumEt HEC;offline sumEt;entry rate",110,-20,200));
	addHistogram(new TH1F("hOffSumEt6","Offline SumEt FCAL;offline sumEt;entry rate",110,-20,200));
	addHistogram(new TH2F("hSumEtCorrAll","Offline SumEt All;offline sumEt;online sumEt",110,-50,500,110,-20,200));
	addHistogram(new TH2F("hSumEtCorr0","Offline SumEt PEMB;offline sumEt;online sumEt",110,-20,200,110,-20,200));
	addHistogram(new TH2F("hSumEtCorr1","Offline SumEt EMB;offline sumEt;online sumEt",110,-20,200,110,-20,200));
	addHistogram(new TH2F("hSumEtCorr2","Offline SumEt PEME;offline sumEt;online sumEt",110,-20,200,110,-20,200));
	addHistogram(new TH2F("hSumEtCorr3","Offline SumEt EME;offline sumEt;online sumEt",110,-20,200,110,-20,200));
	addHistogram(new TH2F("hSumEtCorr4","Offline SumEt TILE;offline sumEt;online sumEt",110,-20,200,110,-20,200));
	addHistogram(new TH2F("hSumEtCorr5","Offline SumEt HEC;offline sumEt;online sumEt",110,-20,200,110,-20,200));
	addHistogram(new TH2F("hSumEtCorr6","Offline SumEt FCAL;offline sumEt;online sumEt",110,-20,200,110,-20,200));
// SpCut
	addMonGroup(new MonGroup(this, "HLT/MinBiasMon/SpCut", run, ATTRIB_UNMANAGED));
	addHistogram(new TH2F("hOnSpOffTrk","Online Space Points & Offline Tracks;online space points;offline tracks",3000,0,3000,200,0,200));
	addHistogram(new TH2F("hOnSpOffTrkPri","Online Space Points & Offline Tracks from PriVtx;online space points;offline tracks from priVtx",3000,0,3000,200,0,200));
	addHistogram(new TH1F("hSpCut0","SCT Space Points Cut = 0;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpCut1","SCT Space Points Cut = 200;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpCut2","SCT Space Points Cut = 400;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpCut3","SCT Space Points Cut = 600;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpCut4","SCT Space Points Cut = 800;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpCut5","SCT Space Points Cut = 1000;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpCut6","SCT Space Points Cut = 1200;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpCut7","SCT Space Points Cut = 1400;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpCut8","SCT Space Points Cut = 1600;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpCut9","SCT Space Points Cut = 1800;offline tracks from priVtx;entry rate",200,0,200));
// SumEt
	addMonGroup(new MonGroup(this, "HLT/MinBiasMon/SumEt", run, ATTRIB_UNMANAGED));
	addHistogram(new TH2F("hOnL1teOnSumEt","Online L1TE & Online SumEt;online L1TE;online sumEt",210,-10,200,110,-10,100));
	addHistogram(new TH2F("hOnSpOnSumEt","Online Space Points & Online SumEt;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt1","Online Space Points & Online SumEt with trkPri>=50;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt2","Online Space Points & Online SumEt with trkPri>=55;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt3","Online Space Points & Online SumEt with trkPri>=60;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt4","Online Space Points & Online SumEt with trkPri>=65;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt5","Online Space Points & Online SumEt with trkPri>=70;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt6","Online Space Points & Online SumEt with trkPri>=75;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt7","Online Space Points & Online SumEt with trkPri>=80;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt8","Online Space Points & Online SumEt with trkPri>=85;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt9","Online Space Points & Online SumEt with trkPri>=90;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSumEtOffTrkPri","Online SumEt & Offline Tracks from priVtx;online sumEt;offline tracks from priVtx",110,-10,100,200,0,200));
	addHistogram(new TH1F("hSpSumEtCut0","sp0;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpSumEtCut1","sp900;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpSumEtCut2","sp1000;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpSumEtCut3","sp900_sumet25;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpSumEtCut4","sp900_sumet30;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpSumEtCut5","sp1000_sumet25;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpSumEtCut6","sp1000_sumet30;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpSumEtCut7","sp1000_sumet30_add1800;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpSumEtCut8","sp1000_sumet30_add1900;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hSpSumEtCut9","sp1000_sumet30_add2000;tracks from priVtx;entry rate",200,0,200));
// L1TE
	addMonGroup(new MonGroup(this, "HLT/MinBiasMon/L1TE", run, ATTRIB_UNMANAGED));
	addHistogram(new TH2F("hOnL1teOffTrkPri","Online L1TE & Offline Tracks from priVtx;online L1TE;offline tracks from priVtx",110,-10,100,200,0,200));
	addHistogram(new TH2F("hOnL1teOffSumEt","Online L1TE & Offline SumEt;online L1TE;offline sumEt",110,-10,100,110,-50,500));
	addHistogram(new TH1F("hL1teCut0","l1te0;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hL1teCut1","l1te2;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hL1teCut2","l1te4;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hL1teCut3","l1te6;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hL1teCut4","l1te8;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hL1teCut5","l1te10;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hL1teCut6","l1te12;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hL1teCut7","l1te14;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hL1teCut8","l1te16;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hL1teCut9","l1te18;tracks from priVtx;entry rate",200,0,200));
// MBTS_X_X
	addMonGroup(new MonGroup(this, "HLT/MinBiasMon/MBTS_X_X", run, ATTRIB_UNMANAGED));
	addHistogram(new TH1F("hMbtsCut0","MBTS_0_0;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hMbtsCut1","MBTS_1_1;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hMbtsCut2","MBTS_2_2;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hMbtsCut3","MBTS_3_3;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hMbtsCut4","MBTS_4_4;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hMbtsCut5","MBTS_5_5;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hMbtsCut6","MBTS_6_6;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hMbtsCut7","MBTS_7_7;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hMbtsCut8","MBTS_8_8;tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hMbtsCut9","MBTS_9_9;tracks from priVtx;entry rate",200,0,200));
// TrigSumEt
	addMonGroup(new MonGroup(this, "HLT/MinBiasMon/TrigSumEt", run, ATTRIB_UNMANAGED));
	addHistogram(new TH2F("hOnSumEtOffSumEt","Online & Offline SumEt;online sumEt;offline sumEt",110,-50,500,110,-50,500));
	addHistogram(new TH2F("hOffSumEtOffSumEt","Offline SumEt EMB & EMB+EME+FCAL;offline sumEt EMB;offline sumEt EMB+EME+FCAL",110,-50,500,110,-50,500));
	addHistogram(new TH2F("hOnSpOffSumEt","Online Space Points & Offline SumEt;online space points;offline sumEt",3000,0,3000,110,-50,500));
	addHistogram(new TH2F("hOnSpOnSumEt00","Online Space Points and Online SumEt with OffSumEt>=-10;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt01","Online Space Points and Online SumEt with OffSumEt>=20;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt02","Online Space Points and Online SumEt with OffSumEt>=30;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt03","Online Space Points and Online SumEt with OffSumEt>=40;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt04","Online Space Points and Online SumEt with OffSumEt>=50;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt05","Online Space Points and Online SumEt with OffSumEt>=60;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt06","Online Space Points and Online SumEt with OffSumEt>=70;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt07","Online Space Points and Online SumEt with OffSumEt>=80;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt08","Online Space Points and Online SumEt with OffSumEt>=90;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH2F("hOnSpOnSumEt09","Online Space Points and Online SumEt with OffSumEt>=100;online space points;online sumEt",3000,0,3000,210,-10,200));
	addHistogram(new TH1F("hEtCut0","minbias;offline sumEt;entry rate",210,-10,200));
	addHistogram(new TH1F("hEtCut1","sumet0;offline sumEt;entry rate",210,-10,200));
	addHistogram(new TH1F("hEtCut2","sumet10;offline sumEt;entry rate",210,-10,200));
	addHistogram(new TH1F("hEtCut3","sumet20;offline sumEt;entry rate",210,-10,200));
	addHistogram(new TH1F("hEtCut4","sumet30;offline sumEt;entry rate",210,-10,200));
	addHistogram(new TH1F("hEtCut5","sumet40;offline sumEt;entry rate",210,-10,200));
	addHistogram(new TH1F("hEtCut6","sumet50;offline sumEt;entry rate",210,-10,200));
	addHistogram(new TH1F("hEtCut7","sumet60;offline sumEt;entry rate",210,-10,200));
	addHistogram(new TH1F("hEtCut8","sumet70;offline sumEt;entry rate",210,-10,200));
	addHistogram(new TH1F("hEtCut9","sumet80;offline sumEt;entry rate",210,-10,200));
// TrigTrack
	addMonGroup(new MonGroup(this, "HLT/MinBiasMon/TrigTrack", run, ATTRIB_UNMANAGED));
	addHistogram(new TH2F("hOnSpOnTrkPri0","Online Space Points & Tracks from PriVtx with offTrkPri>=0;online space points;online tracks from priVtx",3000,0,3000,200,0,200));
	addHistogram(new TH2F("hOnSpOnTrkPri1","Online Space Points & Tracks from PriVtx with offTrkPri>=40;online space points;online tracks from priVtx",3000,0,3000,200,0,200));
	addHistogram(new TH2F("hOnSpOnTrkPri2","Online Space Points & Tracks from PriVtx with offTrkPri>=45;online space points;online tracks from priVtx",3000,0,3000,200,0,200));
	addHistogram(new TH2F("hOnSpOnTrkPri3","Online Space Points & Tracks from PriVtx with offTrkPri>=50;online space points;online tracks from priVtx",3000,0,3000,200,0,200));
	addHistogram(new TH2F("hOnSpOnTrkPri4","Online Space Points & Tracks from PriVtx with offTrkPri>=55;online space points;online tracks from priVtx",3000,0,3000,200,0,200));
	addHistogram(new TH2F("hOnSpOnTrkPri5","Online Space Points & Tracks from PriVtx with offTrkPri>=60;online space points;online tracks from priVtx",3000,0,3000,200,0,200));
	addHistogram(new TH2F("hOnSpOnTrkPri6","Online Space Points & Tracks from PriVtx with offTrkPri>=65;online space points;online tracks from priVtx",3000,0,3000,200,0,200));
	addHistogram(new TH2F("hOnSpOnTrkPri7","Online Space Points & Tracks from PriVtx with offTrkPri>=70;online space points;online tracks from priVtx",3000,0,3000,200,0,200));
	addHistogram(new TH2F("hOnSpOnTrkPri8","Online Space Points & Tracks from PriVtx with offTrkPri>=75;online space points;online tracks from priVtx",3000,0,3000,200,0,200));
	addHistogram(new TH2F("hOnSpOnTrkPri9","Online Space Points & Tracks from PriVtx with offTrkPri>=80;online space points;online tracks from priVtx",3000,0,3000,200,0,200));
	addHistogram(new TH1F("hTrkCut0","minbias;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkCut1","sp600_trk50;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkCut2","sp700_trk55;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkCut3","sp900_trk60;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkCut4","sp1000_trk65;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkCut5","sp1200_trk70;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkCut6","sp1300_trk75;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkCut7","sp1400_trk80;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkCut8","sp1400_trk85;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkCut9","sp1400_trk90;offline tracks from priVtx;entry rate",200,0,200));
// TrigHMT
	addMonGroup(new MonGroup(this, "HLT/MinBiasMon/TrigHMT", run, ATTRIB_UNMANAGED));
	addHistogram(new TH1F("hTest","700 50 50;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH2F("hOnTrkPriOnSumEt","online trkPri & online sumEt;online tracks from priVtx;online sumEt",200,0,200,210,-10,200));
	addHistogram(new TH1F("hTrkHMT00","mb_sp2_hmtperf_L1MBTS_1_1;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkHMT01","mb_sp400_trk40_L1MBTS_1_1;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkHMT02","mb_sp600_trk45_L1MBTS_1_1;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkHMT03","mb_sp700_trk50_L1MBTS_1_1;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkHMT04","mb_sp700_trk55_L1MBTS_1_1;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkHMT05","mb_sp900_trk60_L1MBTS_1_1;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkHMT06","mb_sp900_trk65_L1MBTS_1_1;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkHMT07","mb_sp1000_trk70_L1MBTS_1_1;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkHMT08","mb_sp1200_trk75_L1MBTS_1_1;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hTrkHMT09","mb_sp1400_trk80_L1MBTS_1_1;offline tracks from priVtx;entry rate",200,0,200));
	addHistogram(new TH1F("hEtHMT00","mb_sp2_hmtperf_L1MBTS_1_1;offline sumEt (EMB+EME);entry rate",210,-10,200));
	addHistogram(new TH1F("hEtHMT01","mb_sumet40_L1MBTS_1_1;offline sumEt (EMB+EME);entry rate",210,-10,200));
	addHistogram(new TH1F("hEtHMT02","mb_sp300_sumet40_L1MBTS_1_1;offline sumEt (EMB+EME);entry rate",210,-10,200));
	addHistogram(new TH1F("hEtHMT03","mb_sp600_sumet40_L1MBTS_1_1;offline sumEt (EMB+EME);entry rate",210,-10,200));
	addHistogram(new TH1F("hEtHMT04","mb_sumet50_L1MBTS_1_1;offline sumEt (EMB+EME);entry rate",210,-10,200));
	addHistogram(new TH1F("hEtHMT05","mb_sp300_sumet50_L1MBTS_1_1;offline sumEt (EMB+EME);entry rate",210,-10,200));
	addHistogram(new TH1F("hEtHMT06","mb_sp600_sumet50_L1MBTS_1_1;offline sumEt (EMB+EME);entry rate",210,-10,200));
	addHistogram(new TH1F("hEtHMT07","mb_sumet60_L1MBTS_1_1;offline sumEt (EMB+EME);entry rate",210,-10,200));
	addHistogram(new TH1F("hEtHMT08","mb_sp300_sumet60_L1MBTS_1_1;offline sumEt (EMB+EME);entry rate",210,-10,200));
	addHistogram(new TH1F("hEtHMT09","mb_sp600_sumet60_L1MBTS_1_1;offline sumEt (EMB+EME);entry rate",210,-10,200));
	addHistogram(new TH1F("hEtHMT10","mb_sumet70_L1MBTS_1_1;offline sumEt (EMB+EME);entry rate",210,-10,200));
	addHistogram(new TH1F("hEtHMT11","mb_sp300_sumet70_L1MBTS_1_1;offline sumEt (EMB+EME);entry rate",210,-10,200));
	addHistogram(new TH1F("hEtHMT12","mb_sp600_sumet70_L1MBTS_1_1;offline sumEt (EMB+EME);entry rate",210,-10,200));
	addHistogram(new TH1F("hEtHMT13","mb_sumet80_L1MBTS_1_1;offline sumEt (EMB+EME);entry rate",210,-10,200));
	addHistogram(new TH1F("hEtHMT14","mb_sp300_sumet80_L1MBTS_1_1;offline sumEt (EMB+EME);entry rate",210,-10,200));
	addHistogram(new TH1F("hEtHMT15","mb_sp600_sumet80_L1MBTS_1_1;offline sumEt (EMB+EME);entry rate",210,-10,200));

//	addMonGroup(new MonGroup(this, "HLT/MinBiasMon/PileUp", run, ATTRIB_UNMANAGED));
//	addHistogram(new TH1F("hPileUpDis", "Number of Hits from PriVtx;nHits from PriVtx;entry rate", 200, 0, 1000));
// + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
//+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
// + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 



	// -------------------------------------------------------- NEW AUTOMATIC WAY TO COPE WITH THINGS----------------------
	addMonGroup(new MonGroup(this,"HLT/MinBiasMon", run, ATTRIB_UNMANAGED));
	//Trigger entries
	TH1I *th1i = new TH1I("TriggerEntries", "Trigger Entries;trigger chain id;entry rate", m_trigItems.size(), 0, m_trigItems.size());		
	TProfile *tProf = new TProfile("TriggerEntriesProfile", "Trigger Entries;trigger chain id;entry rate", m_trigItems.size(), 0, m_trigItems.size(), 0, 1);
	
	//histograms filled with mean purity for every trigger chain
	TH1F *tAllTracks = new TH1F("TriggerPuritiesAll", "Trigger All Purities;trigger chain id;entry rate", m_trigItems.size(), 0, m_trigItems.size());	
	TH1F *tTracksPassed = new TH1F("TriggerPuritiesPassed", "Trigger Purities Passed;trigger chain id;entry rate", m_trigItems.size(), 0, m_trigItems.size());	
	TH1F *tPurities = new TH1F("TriggerPurities", "Trigger Purities;trigger chain id;purity", m_trigItems.size(), 0, m_trigItems.size());
	
	//histograms filled with mean efficiency for every trigger chain
	TH1F *tEffAll = new TH1F("TriggerEfficienciesAll", "Trigger All Efficiencies;trigger chain id;entry rate", m_trigItems.size(), 0, m_trigItems.size());
	TH1F *tEffPassed = new TH1F("TriggerEfficienciesPassed", "Trigger Efficiencies Passed;trigger chain id;entry rate", m_trigItems.size(), 0, m_trigItems.size());
	TH1F *tEff = new TH1F("TriggerEfficiencies", "Trigger Efficiencies;trigger chain id;entry rate", m_trigItems.size(), 0, m_trigItems.size());
	
	//Error rates for IDMinBias
	addMonGroup(new MonGroup(this,"HLT/MinBiasMon/IDMinbias", run, ATTRIB_UNMANAGED));
	TProfile *tTrigErrors = new TProfile("IDMinBiasTriggerErrors", "Trigger Errors;trigger chain id;error rate", m_trigItems.size(), 0, m_trigItems.size(), 0, 1);	
        	
	for (const auto &i: m_trigItems)	//for each chain
	{
		tProf->GetXaxis()->FindBin(i.c_str());
		
		tAllTracks->GetXaxis()->FindBin(i.c_str());
		tTracksPassed->GetXaxis()->FindBin(i.c_str());
		tPurities->GetXaxis()->FindBin(i.c_str());
		
		tEffAll->GetXaxis()->FindBin(i.c_str());
		tEffPassed->GetXaxis()->FindBin(i.c_str());
		tEff->GetXaxis()->FindBin(i.c_str());
		
		tTrigErrors->GetXaxis()->FindBin(i.c_str());
	
		for (const auto &j: m_availableAlgs)	//iterate through algorithms
		{
			if (std::string::npos != i.find(j)) //and find their signatures in the chain name
			{
				unsigned k = m_algorithmsForChainClass[j];
				m_chainProperties[i].histoGroup = k;//assign histoGroup(s) for a given chain
				m_chainProperties[i].effCutIdx = m_effCutForChainClass[j];
				if (k)
				{
					for (const auto &l: m_pathForGroup)//book needed histograms
					{
							if ( (k & l.first) == l.first)
							{
									addMonGroup(new MonGroup(this,"HLT/MinBiasMon/" + l.second + "/" + i, run, ATTRIB_UNMANAGED));
									if (newRun)
										bookHistogramsForItem(i, l.first);
							}
					}
				}
				break; //no need to look further
			}
		}
		//Time-dependent purity&efficiency histograms
		addMonGroup(new MonGroup(this,"HLT/MinBiasMon/Purities&Efficiencies/" + i, run, ATTRIB_UNMANAGED));
		if (newRun)
		{
			addHistogram(new TH1F("PurityAll", "Trigger All Purity;lumiblock;entry rate", 1000, -0.5, 999.5));
			addHistogram(new TH1F("PurityPassed", "Trigger Passed Purity;lumiblock;entry rate", 1000, -0.5, 999.5));
			addHistogram(new TH1F("Purity", "Trigger Purity;lumiblock;entry rate", 1000, -0.5, 999.5));
			
			addHistogram(new TH1F("EfficiencyAll", "Trigger All Efficiency;lumiblock;entry rate", 1000, -0.5, 999.5));
			addHistogram(new TH1F("EfficiencyPassed", "Trigger Passed Efficiency;lumiblock;entry rate", 1000, -0.5, 999.5));
			addHistogram(new TH1F("Efficiency", "Trigger Efficiency;lumiblock;entry rate", 1000, -0.5, 999.5));
			
			addHistogram(new TH1F("EfficiencyTracksAll", "Trigger All Efficiency per Track;tracks;entry rate", 1000, -0.5, 999.5));
			addHistogram(new TH1F("EfficiencyTracksPassed", "Trigger Passed Efficiency per Track;tracks;entry rate", 1000, -0.5, 999.5));
			addHistogram(new TH1F("EfficiencyTracks", "Trigger Efficiency per Track;tracks;entry rate", 1000, -0.5, 999.5));
			
			addHistogram(new TH1F("NumGoodOfflineTracks", "Number of accepted offline tracks (trigger passed);tracks;entry rate", 200, 0, 200));
			addHistogram(new TH1F("NumGoodOfflineEt", "Accepted offline sumet (trigger passed);tracks;entry rate", 110, -50, 500));
			addHistogram(new TH1F("NumGoodOnlineL1TE", "Number of accepted online L1TE (trigger passed);tracks;entry rate", 110, -10, 100));
			addHistogram(new TH1F("NumGoodOnlineSp", "Number of accepted online Sp (trigger passed);tracks;entry rate", 300, 0, 3000));
		}
 	}
	
	if (newRun)
	{
		tProf->ResetBit(TH1::kCanRebin);
		tProf->SetMinimum(0.0);
		
		tAllTracks->SetMinimum(0.0);
		tTracksPassed->SetMinimum(0.0);
		tPurities->SetMinimum(0.0);
		
		tEffAll->SetMinimum(0.0);
		tEffPassed->SetMinimum(0.0);
		tEff->SetMinimum(0.0);
		
		th1i->SetMinimum(0.0);
		
		tTrigErrors->ResetBit(TH1::kCanRebin);
		tTrigErrors->SetMinimum(0.0);
		
		addProfile(tProf, "HLT/MinBiasMon");
		addHistogram(th1i, "HLT/MinBiasMon");
			
		addHistogram(tAllTracks, "HLT/MinBiasMon");
		addHistogram(tTracksPassed, "HLT/MinBiasMon");
		addHistogram(tPurities, "HLT/MinBiasMon");
			
		addHistogram(tEffAll, "HLT/MinBiasMon");
		addHistogram(tEffPassed, "HLT/MinBiasMon");
		addHistogram(tEff, "HLT/MinBiasMon");
			
		addProfile(tTrigErrors, "HLT/MinBiasMon/IDMinbias");
	} 
	return StatusCode::SUCCESS;
}

void HLTMinBiasMonTool::bookHistogramsForItem(const std::string &item, unsigned histGroup)
{
	TH1I *th1i;
	TH1F *th1f;
	TH2I *th2i;
	TH2F *th2f;
	TProfile *tProf;
	
	(*m_log) << MSG::DEBUG << "Booking histograms for " << item << " chain in hisGroups: " << histGroup << endreq; 
	
	if ( (histGroup & MBTS) == MBTS)
 	{
		th1i = new TH1I("Occupancy", "Offline MBTS Occupancy (no time cut);channel id;entries", 32, 0, 32);
		fixXaxis(th1i);
		th1i->SetMinimum(0.0);
		addHistogram(th1i);
 	        
		th1i = new TH1I("Occupancy_Online", "Online MBTS Occupancy (no time cut);channel id;entries", 32, 0, 32);
		fixXaxis(th1i);
		addHistogram(th1i);
		
		th2f = new TH2F("m_h_time", "MBTS time;channel id;MBTS Time [ns]", 32, 0, 32, 100, -100, 100);
		fixXaxis(th2f);
		addHistogram(th2f);
 	        
		th2f = new TH2F("m_h_time_Online", "Online MBTS Time;channel id;MBTS Time [ns]", 32, 0, 32, 100, -100, 100);
		fixXaxis(th2f);
		addHistogram(th2f);
		
		th2f = new TH2F("m_h_energy", "MBTS energy;channel id;MBTS Energy [pC]", 32, 0, 32, 100, -2, 2);
		fixXaxis(th2f);
		addHistogram(th2f);
		
		th2f = new TH2F("m_h_energy_Online", "Online MBTS energy;channel id;MBTS Energy [pC]", 32, 0, 32, 100,-2, 2);
		fixXaxis(th2f);
		addHistogram(th2f);
		
		addHistogram(new TH1I("mbMbts_N_N_hits", "mbMbts_N_N Passed;Min #hits on side A or C;entries", TMath::Max(m_mbtsCountsSideA, m_mbtsCountsSideC) + 1, -0.5, TMath::Max(m_mbtsCountsSideA, m_mbtsCountsSideC) + 0.5));
		addHistogram(new TH1I("TriggerRate", "# of Events per Trigger;trigger chain id;# events", 1, 0, 1));
		addHistogram(new TH1I("TriggerRatePS","# of Events per Trigger * Prescale;trigger chain id;# events * prescale", 10, 0, 10));	        
		addHistogram(new TH1I("mbMbts_hits", "mbMbts total hits;#hits;entries", m_mbtsCountsBothSides + 1, -0.5, m_mbtsCountsBothSides + 0.5));

		th2f = new TH2F("m_h_time_TF_SP", "L2 bit failed & simulation passed;channel id;MBTS Time [ns]", 32, 0,	32, 100, -100, 100);
		fixXaxis(th2f);
		addHistogram(th2f);

		th2f = new TH2F("m_h_time_TP_SF", "L2 bit passed & simulation failed;channel id;MBTS Time [ns]", 32, 0,	32, 100, -100, 100);
		fixXaxis(th2f);
		addHistogram(th2f);

		tProf = new TProfile("MbtsEnergyErrors", "Offline MBTS Energy Discrepancies;channel id;error rate", 32, 0, 32, 0, 1);
		fixXaxis(tProf);
		tProf->SetMinimum(0.0);
		addProfile(tProf);
                
		tProf = new TProfile("MbtsTimeErrors", "Offline MBTS Time Discrepancies;channel id;error rate", 32, 0, 32, 0, 1);
		fixXaxis(tProf);
		tProf->SetMinimum(0.0);
		addProfile(tProf);
		
		th2i = new TH2I("m_h_mbtsCorr_N_N", "MBTS hits correlation;MBTS Side A;MBTS Side C", m_mbtsCountsSideA + 1, -0.5, m_mbtsCountsSideA + 0.5, m_mbtsCountsSideC + 1, -0.5, m_mbtsCountsSideC + 0.5);
		th2i->SetOption("COLZ");
		addHistogram(th2i);
		
		/////////
		
		// EF, ID
	 	addHistogram(new TH1I("minbiasTracks", "number of minbias tracks;# of tracks; entries", 125, -0.5, 2499.5));             
	 	
		// MBTS energy
		// The A side mean energy passed the trigger
		addHistogram(new TH1F("m_h_energyMean_A", "Mean MBTS Energy A side passed;MBTS Energy [pC];entries", 100, -5, 95));           
		
		//The A side  maximum energy passed the trigger
		addHistogram(new TH1F("m_h_energyMax_A", "Maximum MBTS Energy A side passed;MBTS Energy [ns];[pC];entries", 100, -5, 95));    

		//The C side  mean energy passed the trigger
		addHistogram(new TH1F("m_h_energyMean_C", "Mean MBTS Energy C side passed;MBTS Energy [pC];entries", 100, -5, 95));           

		//The C side  maximum energy passed the trigger
		addHistogram(new TH1F("m_h_energyMax_C", "Maximum MBTS Energy C side passed;MBTS Energy [pC];entries", 100, -5, 95));         

		//energy online + L2 , EF passed/failed
		//The  time online
		addHistogram(new TH1D("m_h_energy_onl", "MBTS Energy online;MBTS Energy [pC];entries", 100, -5, 95));                  

		// Time
		//=== The time is monitored only if the energy is sufficient to suppress noise
		//The A side  mean time passed the trigger
		addHistogram(new TH1F("m_h_timeMean_A", "Mean MBTS Time A side passed;MBTS Time [ns];entries", 100, -25, 25));        

		//The A side  minimum time passed the trigger
		addHistogram(new TH1F("m_h_timeMin_A", "Minimum MBTS Time A side passed;MBTS Time [ns];entries", 100, -25, 25));      

		//The C side  mean time passed the trigger
		addHistogram(new TH1F("m_h_timeMean_C", "Mean MBTS Time C side passed;MBTS Time [ns];entries", 100, -25, 25));        

		//The C side  minimum time passed the trigger
		addHistogram(new TH1F("m_h_timeMin_C", "Minimum MBTS Time C side passed;MBTS Time [ns];entries", 100, -25, 25));      

		// time online + L2 , EF passed/failed
		//The  time online
		addHistogram(new TH1D("m_h_time_onl", "MBTS Time online;MBTS Time [ns];entries", 100, -25, 25));                       

		// energy-time cell occupancy
		// side A
		th1i = new TH1I("Occupancy_Online - side A", "Online MBTS Occupancy (no time cut);channel id;entries", 32, 0, 32);        	
		th1i->SetMinimum(0.0);
		addHistogram(th1i);
		
		// side C
		th1i = new TH1I("Occupancy_Online - side C", "Online MBTS Occupancy (no time cut);channel id;entries", 32, 0, 32);              
		th1i->SetMinimum(0.0);
		addHistogram(th1i);
 	}
	
 	if ( (histGroup & LUCID) == LUCID)
 	{
 	        // Lucid
		addHistogram(new TH1I("lucidChannels", "occupancy;channel;hits per channel", 40, -0.5, 39.5));
		addHistogram(new TH1I("lucidChannels_pBX", "occupancy for the previous BX;channel;hits per channel", 40,	-0.5, 39.5));
		addHistogram(new TH1I("lucidChannels_nBX", "occupancy for the next BX;channel;hits per channel", 40, -0.5, 39.5));
		
		//addHistogram(new TH1F("LUCID_All", "L1_LUCID All passed;max. # of hits on side A or C;entries", 21, -0.5, 20.5));
		addHistogram(new TH1F("LUCID_A_C_All", "L1_LUCID_A_C All passed; min. # of hits on side A or C;entries", 21, -0.5, 20.5));
		addHistogram(new TH1F("LUCID_All", "L1_LUCID All passed;max. # of hits on side A or C;entries", 21, -0.5, 20.5));
		addHistogram(new TH1F("LUCID_nBX", "L1_LUCID passed;max. # of hits on side A or C for the next BX;entries", 21,-0.5, 20.5));
		addHistogram(new TH1F("LUCID_pBX", "L1_LUCID passed;max. # of hits on side A or C for the previous BX;entries",21, -0.5, 20.5));
		addHistogram(new TH1F("LUCID_A_C", "L1_LUCID_A_C passed; min. # of hits on side A or C;entries", 21, -0.5, 20.5));
		addHistogram(new TH1F("LUCID_A_C_nBX","L1_LUCID_A_C passed; min. # of hits on side A or C for the next BX;entries", 21, -0.5, 20.5));
		addHistogram(new TH1F("LUCID_A_C_pBX","L1_LUCID_A_C passed; min. # of hits on side A or C for the previous BX;entries", 21, -0.5, 20.5));
		
		//Error rates
		tProf = new TProfile("TriggerErrors", "Trigger Errors;trigger chain id;error rate", 5, 0, 5, 0, 1);
		tProf->GetXaxis()->FindBin("L1_LUCID");
		tProf->GetXaxis()->FindBin("L1_LUCID_A");
		tProf->GetXaxis()->FindBin("L1_LUCID_C");
		tProf->GetXaxis()->FindBin("L1_LUCID_A_C");
		tProf->GetXaxis()->FindBin("L1_LUCID_COMM");
		tProf->ResetBit(TH1::kCanRebin);
		tProf->SetMinimum(0.0);
		addProfile(tProf);
 	}
 		 	                
 	if ( (histGroup & IDMINBIAS) == IDMINBIAS)
 	{
		//default:
		// L2, ID
	 	addHistogram(new TH1I("pixBarr_sp", "number of L2 pixel spacepoints in the barrel;;entries", 250, -0.5, 2499.5));       
	 	addHistogram(new TH1I("pixECA_sp", "number of L2 pixel spacepoints in ECA;;entries", 250, -0.5, 2499.5));               
	 	addHistogram(new TH1I("pixECC_sp", "number of L2 pixel spacepoints in ECC;;entries", 250, -0.5, 2499.5));               
	 	addHistogram(new TH1I("sctBarr_sp", "number of L2 sct spacepoints in the barrel;;entries", 300, -0.5, 2999.5));         
	 	addHistogram(new TH1I("sctECA_sp", "number of L2 sct spacepoints in ECA;;entries", 300, -0.5, 2999.5));                 
	 	addHistogram(new TH1I("sctECC_sp", "number of L2 sct spacepoints in ECC;;entries", 300, -0.5, 2999.5));                 
	 	
	 	addHistogram(new TH1I("h_pixTot", "L2_mbMbts_ passed;total number of L2 pixel space-points;entries", 250, -0.5, 2499.5));
	 	addHistogram(new TH1I("h_sctTot", "L2_mbMbts_ passed;total number of L2 SCT space-points;entries", 300, -0.5, 2999.5));
	}
	
 	if ( (histGroup & ZDC) == ZDC)
 	{
		addHistogram(new TH2I("zdcChannels", "occupancy;channel ID;hits per channel", 8, -0.5, 7.5, 100, 0,1200));
		addHistogram(new TH1I("ZDC_EMPTY", "L1_ZDC_EMPTY passed;min. Low Gain ADC counts on side A or C;entries", 100,0., 2000.));
		
		th1f = new TH1F("m_h_ZDC_LHCF_corr", "L1_ZDC_C vs L1_LHCF with MbSp(Trk);;events accepted", 4,0,4);
		th1f->GetXaxis()->FindBin("LHCF and ZDC_C");
		th1f->GetXaxis()->FindBin("no LHCF and no ZDC_C");
		th1f->GetXaxis()->FindBin("LHCF, no ZDC_C");
		th1f->GetXaxis()->FindBin("no LHCF but ZDC_C");
		th1f->ResetBit(TH1::kCanRebin);
		th1f->Sumw2();
		addHistogram(th1f);
		
		th1f = new TH1F("m_h_ZDC_TE", "L1_TE and L1_ZDC_x_VTE with MbSp(Trk);;events accepted", 5,0,5);
		th1f->GetXaxis()->FindBin("L1_TE0");
		th1f->GetXaxis()->FindBin("L1_TE20");
		th1f->GetXaxis()->FindBin("L1_TE50");
		th1f->GetXaxis()->FindBin("L1_ZDC_A_VTE20");
		th1f->GetXaxis()->FindBin("L1_ZDC_C_VTE20");
		th1f->ResetBit(TH1::kCanRebin);
		th1f->Sumw2();
		addHistogram(th1f);
		
		addHistogram(new TH1I("ZDC_All", "L1_ZDC passed any beam;min. Low Gain ADC counts on side A or C;entries", 100, 0., 2000.));
		addHistogram(new TH1I("ZDC_A_C_All", "L1_ZDC_A_C passed any beam;max. Low Gain ADC counts on side A or C;entries", 100, 0.,2000.));
		addHistogram(new TH2F("ZDC_vs_FCAL_A_All","L1_ZDC_A passed any beam;Low Gain ADC counts on side A;Calo energy", 100, 0., 2000., 100, 0., 20000));
		addHistogram(new TH1I("ZDC_A_All", "L1_ZDC_A passed any beam;Low Gain ADC counts on side A;entries", 100, 0., 2000.));
		addHistogram(new TH2F("ZDC_vs_FCAL_C_All","L1_ZDC_C passed any beam;Low Gain ADC counts on side C;Calo energy", 100, 0., 2000., 100, 0., 20000));
		addHistogram(new TH1I("ZDC_C_All", "L1_ZDC_C passed any beam;Low Gain ADC counts on side C;entries", 100, 0., 2000.));
 	}
	
 	if ( (histGroup & BCM) == BCM)
 	{
		addHistogram(new TH1I("bcmChannels", "occupancy;channel;hits per channel", 16, -0.5, 15.5));
		addHistogram(new TH2I("pulse1position", "1st pulse timing;channel;position of pulse1", 16, -0.5, 15.5, 64, -0.5, 63.5));
		addHistogram(new TH2I("pulse1width", "1st pulse width;channel;width of pulse1", 16, -0.5, 15.5, 32, -0.5, 31.5));
		addHistogram(new TH2I("pulse2position", "2nd pulse timing;channel;position of pulse2", 16, -0.5, 15.5, 64, -0.5, 63.5));
		addHistogram(new TH2I("pulse2width", "2nd pulse width;channel; width of pulse2", 16, -0.5, 15.5, 32, -0.5, 31.5));
		
		//TProfiles are to be drawn on top of the corresponsing 1D plots

		addProfile(new TProfile("pulse1position_prof", "1st pulse average timing;channel;position of pulse1",16, -0.5, 15.5, -0.5, 63.5));
		addProfile(new TProfile("pulse1width_prof", "1st pulse average width;channel;width of pulse1", 16, -0.5, 15.5, -0.5, 31.5));
		addProfile(new TProfile("pulse2position_prof", "2nd pulse average timing;channel;position of pulse2", 16, -0.5, 15.5, -0.5, 63.5));
		addProfile(new TProfile("pulse2width_prof", "2nd pulse average width;channel; width of pulse2", 16, -0.5, 15.5, -0.5, 31.5));
		
		addHistogram(new TH1F("BCM_Wide_All", "L1_BCM_Wide passed all; min. # of hits on side A or C;entries", 9, -0.5, 8.5));
		addHistogram(new TH1F("BCM_AC_CA_All", "L1_BCM_AC_CA passed all; min. # of hits on side A or C;entries", 9, -0.5, 8.5));
		addHistogram(new TH1F("BCM_HT_All", "L1_BCM_HT passed all;# of low-gain hits;entries", 17, -0.5, 16.5));
		addHistogram(new TH1D("BCM_Wide", "L1_BCM_Wide passed; min. # of hits on side A or C;entries", 9, -0.5, 8.5));
		addHistogram(new TH1D("BCM_AC_CA", "L1_BCM_AC_CA passed; min. # of hits on side A or C;entries", 9, -0.5, 8.5));
		addHistogram(new TH1D("BCM_HT", "L1_BCM_HT passed;# of low-gain hits;entries", 17, -0.5, 16.5));
		
		//Error rates
		tProf = new TProfile("TriggerErrors", "Trigger Errors;trigger chain id;error rate", 3, 0, 3, 0, 1);
		tProf->GetXaxis()->FindBin("L1_BCM_AC_CA");
		tProf->GetXaxis()->FindBin("L1_BCM_Wide");
		tProf->GetXaxis()->FindBin("L1_BCM_HT");
		tProf->ResetBit(TH1::kCanRebin);
		tProf->SetMinimum(0.0);
		addProfile(tProf);
 	}
	
 	if ( (histGroup & HMT) == HMT)
 	{
		addHistogram(new TH1I("numSpacePoints", "Space points;amount;entries", 1000, -0.5, 9999.5));
		
		addHistogram(new TH1I("numVertices", "Vertices;amount;entries", 100, -0.5, 99.5));
		addHistogram(new TH1I("numTracksAtVertex", "Tracks at vertex;amount;entries", 100, -0.5, 99.5));
		
		addHistogram(new TH1I("numHitsAtVertex", "Hits at vertex;amount;entries", 200, -0.5, 999.5));
 	}
	
 	(*m_log) << MSG::DEBUG << "All histograms booked successfully" << endreq; 
}

StatusCode HLTMinBiasMonTool::fill()
{
	StatusCode sc = StatusCode::SUCCESS;
// Mingliang
// + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
//+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
// + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
//---------------------------------------------
// Online L1TE
	float onL1te = 0;
	const xAOD::EnergySumRoI *ptrOnL1te = 0;
	CHECK(evtStore()->retrieve(ptrOnL1te,"LVL1EnergySumRoI"));
	onL1te=ptrOnL1te->energyT()/1000.;
//---------------------------------------------
// Online SumEt
	float onSumEt = 0;
	const xAOD::TrigMissingETContainer *ptrOnSumEtCon = 0;
	CHECK(evtStore()->retrieve(ptrOnSumEtCon,"HLT_xAOD__TrigMissingETContainer_TrigEFMissingET"));
//	CHECK(evtStore()->retrieve(ptrOnSumEtCon,"HLT_xAOD__TrigMissingETContainer_EFMissingET_Fex_2sidednoiseSupp_PUC"));
	for(const auto *ptrOnSumEt : *ptrOnSumEtCon)
	{
		onSumEt+=ptrOnSumEt->sumEt()/1000.;
 		(*m_log) << MSG::DEBUG <<"OnSumEt : "<<onSumEt<< endreq; 
	}
//---------------------------------------------
// Offline SumEt

	float offSumEt = 0;
	float offSumEt0 = 0;
	float offSumEt1 = 0;
	float offSumEt2 = 0;
	float offSumEt3 = 0;
	float offSumEt4 = 0;
	float offSumEt5 = 0;
	float offSumEt6 = 0;
	float offSumEtAll = 0;
	int slct = 0;
	const xAOD::MissingETContainer *ptrOffSumEtCon = 0;
	CHECK(evtStore()->retrieve(ptrOffSumEtCon,"MET_Calo"));
//	CHECK(evtStore()->retrieve(ptrOffSumEtCon,"MET_Truth"));
	for(const auto *ptrOffSumEt : *ptrOffSumEtCon)
	{
		offSumEt+=ptrOffSumEt->sumet()/1000.;
//		if(slct==1 || slct==3) offSumEt+=ptrOffSumEt->sumet()/1000.;
		if(slct==1 || slct==3 || slct==6) offSumEtAll+=ptrOffSumEt->sumet()/1000.;
		if(slct==0) offSumEt0=ptrOffSumEt->sumet()/1000.;
		if(slct==1) offSumEt1=ptrOffSumEt->sumet()/1000.;
		if(slct==2) offSumEt2=ptrOffSumEt->sumet()/1000.;
		if(slct==3) offSumEt3=ptrOffSumEt->sumet()/1000.;
		if(slct==4) offSumEt4=ptrOffSumEt->sumet()/1000.;
		if(slct==5) offSumEt5=ptrOffSumEt->sumet()/1000.;
		if(slct==6) offSumEt6=ptrOffSumEt->sumet()/1000.;
		slct++;
//		(*m_log) << MSG::DEBUG <<"OffSumEt : "<<ptrOffSumEt->sumet()/1000.<< endreq; 
	}
//---------------------------------------------
// Online Space Points
	float onSp = 0;
	const xAOD::TrigSpacePointCountsContainer *ptrOnSpCon = 0;
	CHECK(evtStore()->retrieve(ptrOnSpCon,"HLT_xAOD__TrigSpacePointCountsContainer_spacepoints"));
	for(const auto *ptrOnSp : *ptrOnSpCon)
	{
		onSp=(ptrOnSp->sctSpEndcapA()+ptrOnSp->sctSpEndcapC()+ptrOnSp->sctSpBarrel());
	}
//---------------------------------------------
// Online Tracks
	float onTrk = 0;
	const xAOD::TrigTrackCountsContainer *ptrOnTrkCon = 0;
	CHECK(evtStore()->retrieve(ptrOnTrkCon,"HLT_xAOD__TrigTrackCountsContainer_trackcounts"));
	for(const auto *ptrOnTrk : *ptrOnTrkCon)
	{
		onTrk=ptrOnTrk->z0_ptSumEntries(400,0.4,xAOD::TrigHistoCutType::BELOW_X_ABOVE_Y);
	}
//---------------------------------------------
// Offline Tracks
	float offTrk = 0;
	const xAOD::TrackParticleContainer *ptrOffTrkCon = 0;
	CHECK(evtStore()->retrieve(ptrOffTrkCon,"InDetTrackParticles"));
	offTrk=0;
	for(const auto *ptrOffTrk : *ptrOffTrkCon)
	{
		if(ptrOffTrk->pt()>400) offTrk++;
	}
//---------------------------------------------
// Online Vertex
	float onVtx = 0;
	float onTrkPri = 0;
	const xAOD::TrigVertexCountsContainer *ptrOnVtxCon = 0;
	CHECK(evtStore()->retrieve(ptrOnVtxCon,"HLT_xAOD__TrigVertexCountsContainer_vertexcounts"));
	for(const auto *ptrOnVtx : *ptrOnVtxCon)
	{
		for(const auto &i : ptrOnVtx->vtxNtrks())
		{
			onVtx++;
			if(i>onTrkPri) onTrkPri=i;
		}
	}
//---------------------------------------------
// Offline Vertex
	float offVtx = 0;
	float offTrkPri = 0;
	const xAOD::VertexContainer *ptrOffVtxCon = 0;
	CHECK(evtStore()->retrieve(ptrOffVtxCon,"PrimaryVertices"));
	for(const auto *ptrOffVtx : *ptrOffVtxCon)
	{
		offVtx++;
		if((ptrOffVtx->nTrackParticles())>offTrkPri) offTrkPri=ptrOffVtx->nTrackParticles();
	}
//---------------------------------------------
// online MBTS
	unsigned int onMbtsA = 0;
	unsigned int onMbtsC = 0;
	unsigned int triggerWord = 0;
	unsigned int timeWord = 0;
	const unsigned int mask = 65535;
	std::vector<float> mbtsHitEnergies;
	std::vector<float> mbtsHitTimes;
	const xAOD::TrigT2MbtsBitsContainer *ptrOnMbtsCon = 0;
	CHECK(evtStore()->retrieve(ptrOnMbtsCon,"HLT_xAOD__TrigT2MbtsBitsContainer_T2Mbts"));
	for(const auto *ptrOnMbts : *ptrOnMbtsCon)
	{
		mbtsHitEnergies = ptrOnMbts->triggerEnergies();
		mbtsHitTimes = ptrOnMbts->triggerTimes();
		for(std::size_t k=0; k<mbtsHitEnergies.size() && k<32; k++)
		{
			if(mbtsHitEnergies.at(k)>m_energyCut) triggerWord+=(1<<k);
		}
		for(std::size_t k=0; k<mbtsHitTimes.size() && k<32; k++)
		{
			if(fabs(mbtsHitTimes.at(k))<m_timeCut || m_timeCut<=0.) timeWord+=(1<<k);
		}
		timeWord &= triggerWord;
		std::bitset<8> InnerEbaBitset(triggerWord & timeWord & mask);
		std::bitset<8> OuterEbaBitset(((triggerWord & timeWord) >> 8) & mask);
		std::bitset<8> InnerEbcBitset(((triggerWord & timeWord) >> 16) & mask);
		std::bitset<8> OuterEbcBitset(((triggerWord & timeWord) >> 24) & mask);
		onMbtsA=InnerEbaBitset.count()+OuterEbaBitset.count();
		onMbtsC=InnerEbcBitset.count()+OuterEbcBitset.count();
	}
//---------------------------------------------
// online pileup
	float onWei = 0;
	const TrigVertexCollection *ptrOnWeiCon = 0;
	CHECK(evtStore()->retrieve(ptrOnWeiCon,"HLT_TrigVertexCollection_TrigL2SiTrackFinder_FullScan_ZF_Only"));
 	(*m_log) << MSG::DEBUG <<"Mingliang Knows the Best : "<< endreq; 
	for(const auto *ptrOnWei : *ptrOnWeiCon)
	{
 		(*m_log) << MSG::DEBUG <<"Online Weight: "<<ptrOnWei->z()<< endreq; 
		if((ptrOnWei->z())>=onWei) onWei=ptrOnWei->z();
	}

//---------------------------------------------
// MBTS_X_X Cut
	hist2("hOnMbtsAC","HLT/MinBiasMon/Validation")->Fill(onMbtsA,onMbtsC,1);
	if(onMbtsA>=0 && onMbtsC>=0) hist("hMbtsCut0","HLT/MinBiasMon/MBTS_X_X")->Fill(offTrk);
	if(onMbtsA>=1 && onMbtsC>=1) hist("hMbtsCut1","HLT/MinBiasMon/MBTS_X_X")->Fill(offTrk);
	if(onMbtsA>=2 && onMbtsC>=2) hist("hMbtsCut2","HLT/MinBiasMon/MBTS_X_X")->Fill(offTrk);
	if(onMbtsA>=3 && onMbtsC>=3) hist("hMbtsCut3","HLT/MinBiasMon/MBTS_X_X")->Fill(offTrk);
	if(onMbtsA>=4 && onMbtsC>=4) hist("hMbtsCut4","HLT/MinBiasMon/MBTS_X_X")->Fill(offTrk);
	if(onMbtsA>=5 && onMbtsC>=5) hist("hMbtsCut5","HLT/MinBiasMon/MBTS_X_X")->Fill(offTrk);
	if(onMbtsA>=6 && onMbtsC>=6) hist("hMbtsCut6","HLT/MinBiasMon/MBTS_X_X")->Fill(offTrk);
	if(onMbtsA>=7 && onMbtsC>=7) hist("hMbtsCut7","HLT/MinBiasMon/MBTS_X_X")->Fill(offTrk);
	if(onMbtsA>=8 && onMbtsC>=8) hist("hMbtsCut8","HLT/MinBiasMon/MBTS_X_X")->Fill(offTrk);
	if(onMbtsA>=9 && onMbtsC>=9) hist("hMbtsCut9","HLT/MinBiasMon/MBTS_X_X")->Fill(offTrk);
//---------------------------------------------
if(onMbtsA>=0 && onMbtsC>=0)
{
//---------------------------------------------
// Validation
	hist("hOnL1te","HLT/MinBiasMon/Validation")->Fill(onL1te);
	hist("hOnSumEt","HLT/MinBiasMon/Validation")->Fill(onSumEt);
	hist("hOffSumEt","HLT/MinBiasMon/Validation")->Fill(offSumEt);
	hist("hOnSp","HLT/MinBiasMon/Validation")->Fill(onSp);
	hist("hOnTrk","HLT/MinBiasMon/Validation")->Fill(onTrk);
	hist("hOffTrk","HLT/MinBiasMon/Validation")->Fill(offTrk);
	hist("hOnVtx","HLT/MinBiasMon/Validation")->Fill(onVtx);
	hist("hOnTrkPri","HLT/MinBiasMon/Validation")->Fill(onTrkPri);
	hist("hOffVtx","HLT/MinBiasMon/Validation")->Fill(offVtx);
	hist("hOffTrkPri","HLT/MinBiasMon/Validation")->Fill(offTrkPri);
//---------------------------------------------
// Pile Up
	hist("hOnWei","HLT/MinBiasMon/PileUp")->Fill(onWei);
	hist2("hOnWeiOffTrk","HLT/MinBiasMon/PileUp")->Fill(onWei,offTrkPri);
	if(onWei>0) hist("hOnWeiCut0","HLT/MinBiasMon/PileUp")->Fill(offTrkPri);
	if(onWei>100) hist("hOnWeiCut1","HLT/MinBiasMon/PileUp")->Fill(offTrkPri);
	if(onWei>200) hist("hOnWeiCut2","HLT/MinBiasMon/PileUp")->Fill(offTrkPri);
	if(onWei>300) hist("hOnWeiCut3","HLT/MinBiasMon/PileUp")->Fill(offTrkPri);
	if(onWei>400) hist("hOnWeiCut4","HLT/MinBiasMon/PileUp")->Fill(offTrkPri);
	if(onWei>500) hist("hOnWeiCut5","HLT/MinBiasMon/PileUp")->Fill(offTrkPri);
	if(onWei>600) hist("hOnWeiCut6","HLT/MinBiasMon/PileUp")->Fill(offTrkPri);
	if(onWei>700) hist("hOnWeiCut7","HLT/MinBiasMon/PileUp")->Fill(offTrkPri);
	if(onWei>800) hist("hOnWeiCut8","HLT/MinBiasMon/PileUp")->Fill(offTrkPri);
	if(onWei>900) hist("hOnWeiCut9","HLT/MinBiasMon/PileUp")->Fill(offTrkPri);
//---------------------------------------------
// SumEt Bug
	hist("hOnSumEtAll","HLT/MinBiasMon/SumEtBug")->Fill(onSumEt);
	hist("hOffSumEtAll","HLT/MinBiasMon/SumEtBug")->Fill(offSumEt);
	hist("hOffSumEt0","HLT/MinBiasMon/SumEtBug")->Fill(offSumEt0);
	hist("hOffSumEt1","HLT/MinBiasMon/SumEtBug")->Fill(offSumEt1);
	hist("hOffSumEt2","HLT/MinBiasMon/SumEtBug")->Fill(offSumEt2);
	hist("hOffSumEt3","HLT/MinBiasMon/SumEtBug")->Fill(offSumEt3);
	hist("hOffSumEt4","HLT/MinBiasMon/SumEtBug")->Fill(offSumEt4);
	hist("hOffSumEt5","HLT/MinBiasMon/SumEtBug")->Fill(offSumEt5);
	hist("hOffSumEt6","HLT/MinBiasMon/SumEtBug")->Fill(offSumEt6);
	hist2("hSumEtCorrAll","HLT/MinBiasMon/SumEtBug")->Fill(offSumEt,onSumEt,1);
	hist2("hSumEtCorr0","HLT/MinBiasMon/SumEtBug")->Fill(offSumEt0,onSumEt,1);
	hist2("hSumEtCorr1","HLT/MinBiasMon/SumEtBug")->Fill(offSumEt1,onSumEt,1);
	hist2("hSumEtCorr2","HLT/MinBiasMon/SumEtBug")->Fill(offSumEt2,onSumEt,1);
	hist2("hSumEtCorr3","HLT/MinBiasMon/SumEtBug")->Fill(offSumEt3,onSumEt,1);
	hist2("hSumEtCorr4","HLT/MinBiasMon/SumEtBug")->Fill(offSumEt4,onSumEt,1);
	hist2("hSumEtCorr5","HLT/MinBiasMon/SumEtBug")->Fill(offSumEt5,onSumEt,1);
	hist2("hSumEtCorr6","HLT/MinBiasMon/SumEtBug")->Fill(offSumEt6,onSumEt,1);
//---------------------------------------------
// Correlations
	hist2("hOnOffTrk","HLT/MinBiasMon/Validation")->Fill(onTrk,offTrk,1);
	hist2("hOnOffVtx","HLT/MinBiasMon/Validation")->Fill(onVtx,offVtx,1);
	hist2("hOnOffTrkPri","HLT/MinBiasMon/Validation")->Fill(onTrkPri,offTrkPri,1);
	hist2("hOnOffSumEt","HLT/MinBiasMon/Validation")->Fill(onSumEt,offSumEt,1);
//---------------------------------------------
// Space Points Cut
	hist2("hOnSpOffTrk","HLT/MinBiasMon/SpCut")->Fill(onSp,offTrk,1);
	hist2("hOnSpOffTrkPri","HLT/MinBiasMon/SpCut")->Fill(onSp,offTrkPri,1);
	if(onSp>=0) hist("hSpCut0","HLT/MinBiasMon/SpCut")->Fill(offTrk);
	if(onSp>=200) hist("hSpCut1","HLT/MinBiasMon/SpCut")->Fill(offTrk);
	if(onSp>=400) hist("hSpCut2","HLT/MinBiasMon/SpCut")->Fill(offTrk);
	if(onSp>=600) hist("hSpCut3","HLT/MinBiasMon/SpCut")->Fill(offTrk);
	if(onSp>=800) hist("hSpCut4","HLT/MinBiasMon/SpCut")->Fill(offTrk);
	if(onSp>=1000) hist("hSpCut5","HLT/MinBiasMon/SpCut")->Fill(offTrk);
	if(onSp>=1200) hist("hSpCut6","HLT/MinBiasMon/SpCut")->Fill(offTrk);
	if(onSp>=1400) hist("hSpCut7","HLT/MinBiasMon/SpCut")->Fill(offTrk);
	if(onSp>=1600) hist("hSpCut8","HLT/MinBiasMon/SpCut")->Fill(offTrk);
	if(onSp>=1800) hist("hSpCut9","HLT/MinBiasMon/SpCut")->Fill(offTrk);
//---------------------------------------------
// SumEt Cut
	hist2("hOnL1teOnSumEt","HLT/MinBiasMon/SumEt")->Fill(onL1te,onSumEt,1);
	hist2("hOnSpOnSumEt","HLT/MinBiasMon/SumEt")->Fill(onSp,onSumEt,1);
	if(offTrkPri>=50) hist2("hOnSpOnSumEt1","HLT/MinBiasMon/SumEt")->Fill(onSp,onSumEt,1);
	if(offTrkPri>=55) hist2("hOnSpOnSumEt2","HLT/MinBiasMon/SumEt")->Fill(onSp,onSumEt,1);
	if(offTrkPri>=60) hist2("hOnSpOnSumEt3","HLT/MinBiasMon/SumEt")->Fill(onSp,onSumEt,1);
	if(offTrkPri>=65) hist2("hOnSpOnSumEt4","HLT/MinBiasMon/SumEt")->Fill(onSp,onSumEt,1);
	if(offTrkPri>=70) hist2("hOnSpOnSumEt5","HLT/MinBiasMon/SumEt")->Fill(onSp,onSumEt,1);
	if(offTrkPri>=75) hist2("hOnSpOnSumEt6","HLT/MinBiasMon/SumEt")->Fill(onSp,onSumEt,1);
	if(offTrkPri>=80) hist2("hOnSpOnSumEt7","HLT/MinBiasMon/SumEt")->Fill(onSp,onSumEt,1);
	if(offTrkPri>=85) hist2("hOnSpOnSumEt8","HLT/MinBiasMon/SumEt")->Fill(onSp,onSumEt,1);
	if(offTrkPri>=90) hist2("hOnSpOnSumEt9","HLT/MinBiasMon/SumEt")->Fill(onSp,onSumEt,1);
	hist2("hOnSumEtOffTrkPri","HLT/MinBiasMon/SumEt")->Fill(onSumEt,offTrk,1);
	if(1) hist("hSpSumEtCut0","HLT/MinBiasMon/SumEt")->Fill(offTrkPri);
	if(onSp>=900 && onSumEt>=20) hist("hSpSumEtCut1","HLT/MinBiasMon/SumEt")->Fill(offTrkPri);
	if(1) hist("hSpSumEtCut2","HLT/MinBiasMon/SumEt")->Fill(offTrkPri);
	if(onSp>=1000 && onSumEt>=30) hist("hSpSumEtCut3","HLT/MinBiasMon/SumEt")->Fill(offTrkPri);
	if(1) hist("hSpSumEtCut4","HLT/MinBiasMon/SumEt")->Fill(offTrkPri);
	if(onSp>=1400 && onSumEt>=40) hist("hSpSumEtCut5","HLT/MinBiasMon/SumEt")->Fill(offTrkPri);
	if(1) hist("hSpSumEtCut6","HLT/MinBiasMon/SumEt")->Fill(offTrkPri);
	if(onSp>=1600 && onSumEt>=50) hist("hSpSumEtCut7","HLT/MinBiasMon/SumEt")->Fill(offTrkPri);
	if(1) hist("hSpSumEtCut8","HLT/MinBiasMon/SumEt")->Fill(offTrkPri);
	if(onSp>=1800 && onSumEt>=60) hist("hSpSumEtCut9","HLT/MinBiasMon/SumEt")->Fill(offTrkPri);
//---------------------------------------------
// L1TE Cut
	hist2("hOnL1teOffTrkPri","HLT/MinBiasMon/L1TE")->Fill(onL1te,offTrk,1);
	hist2("hOnL1teOffSumEt","HLT/MinBiasMon/L1TE")->Fill(onL1te,offSumEt,1);
	if(onL1te>=0) hist("hL1teCut0","HLT/MinBiasMon/L1TE")->Fill(offTrk);
	if(onL1te>=2) hist("hL1teCut1","HLT/MinBiasMon/L1TE")->Fill(offTrk);
	if(onL1te>=4) hist("hL1teCut2","HLT/MinBiasMon/L1TE")->Fill(offTrk);
	if(onL1te>=6) hist("hL1teCut3","HLT/MinBiasMon/L1TE")->Fill(offTrk);
	if(onL1te>=8) hist("hL1teCut4","HLT/MinBiasMon/L1TE")->Fill(offTrk);
	if(onL1te>=10) hist("hL1teCut5","HLT/MinBiasMon/L1TE")->Fill(offTrk);
	if(onL1te>=12) hist("hL1teCut6","HLT/MinBiasMon/L1TE")->Fill(offTrk);
	if(onL1te>=14) hist("hL1teCut7","HLT/MinBiasMon/L1TE")->Fill(offTrk);
	if(onL1te>=16) hist("hL1teCut8","HLT/MinBiasMon/L1TE")->Fill(offTrk);
	if(onL1te>=18) hist("hL1teCut9","HLT/MinBiasMon/L1TE")->Fill(offTrk);
//---------------------------------------------
// TrigSumEt
	hist2("hOnSumEtOffSumEt","HLT/MinBiasMon/TrigSumEt")->Fill(onSumEt,offSumEt,1);
	hist2("hOffSumEtOffSumEt","HLT/MinBiasMon/TrigSumEt")->Fill(offSumEt,offSumEtAll,1);
	hist2("hOnSpOffSumEt","HLT/MinBiasMon/TrigSumEt")->Fill(onSp,offSumEt,1);
	if(1) hist2("hOnSpOnSumEt00","HLT/MinBiasMon/TrigSumEt")->Fill(onSp,onSumEt,1);
	if(offSumEt>=20) hist2("hOnSpOnSumEt01","HLT/MinBiasMon/TrigSumEt")->Fill(onSp,onSumEt,1);
	if(offSumEt>=30) hist2("hOnSpOnSumEt02","HLT/MinBiasMon/TrigSumEt")->Fill(onSp,onSumEt,1);
	if(offSumEt>=40) hist2("hOnSpOnSumEt03","HLT/MinBiasMon/TrigSumEt")->Fill(onSp,onSumEt,1);
	if(offSumEt>=50) hist2("hOnSpOnSumEt04","HLT/MinBiasMon/TrigSumEt")->Fill(onSp,onSumEt,1);
	if(offSumEt>=60) hist2("hOnSpOnSumEt05","HLT/MinBiasMon/TrigSumEt")->Fill(onSp,onSumEt,1);
	if(offSumEt>=70) hist2("hOnSpOnSumEt06","HLT/MinBiasMon/TrigSumEt")->Fill(onSp,onSumEt,1);
	if(offSumEt>=80) hist2("hOnSpOnSumEt07","HLT/MinBiasMon/TrigSumEt")->Fill(onSp,onSumEt,1);
	if(offSumEt>=90) hist2("hOnSpOnSumEt08","HLT/MinBiasMon/TrigSumEt")->Fill(onSp,onSumEt,1);
	if(offSumEt>=100) hist2("hOnSpOnSumEt09","HLT/MinBiasMon/TrigSumEt")->Fill(onSp,onSumEt,1);
	if(1) hist("hEtCut0","HLT/MinBiasMon/TrigSumEt")->Fill(offSumEt);
	if(onSumEt>=0) hist("hEtCut1","HLT/MinBiasMon/TrigSumEt")->Fill(offSumEt);
	if(onSumEt>=10) hist("hEtCut2","HLT/MinBiasMon/TrigSumEt")->Fill(offSumEt);
	if(onSumEt>=20) hist("hEtCut3","HLT/MinBiasMon/TrigSumEt")->Fill(offSumEt);
	if(onSumEt>=30) hist("hEtCut4","HLT/MinBiasMon/TrigSumEt")->Fill(offSumEt);
	if(onSumEt>=40) hist("hEtCut5","HLT/MinBiasMon/TrigSumEt")->Fill(offSumEt);
	if(onSumEt>=50) hist("hEtCut6","HLT/MinBiasMon/TrigSumEt")->Fill(offSumEt);
	if(onSumEt>=60) hist("hEtCut7","HLT/MinBiasMon/TrigSumEt")->Fill(offSumEt);
	if(onSumEt>=70) hist("hEtCut8","HLT/MinBiasMon/TrigSumEt")->Fill(offSumEt);
	if(onSumEt>=80) hist("hEtCut9","HLT/MinBiasMon/TrigSumEt")->Fill(offSumEt);
//---------------------------------------------
// TrigTrack
	if(1) hist2("hOnSpOnTrkPri0","HLT/MinBiasMon/TrigTrack")->Fill(onSp,onTrkPri,1);
	if(offTrkPri>=40) hist2("hOnSpOnTrkPri1","HLT/MinBiasMon/TrigTrack")->Fill(onSp,onTrkPri,1);
	if(offTrkPri>=45) hist2("hOnSpOnTrkPri2","HLT/MinBiasMon/TrigTrack")->Fill(onSp,onTrkPri,1);
	if(offTrkPri>=50) hist2("hOnSpOnTrkPri3","HLT/MinBiasMon/TrigTrack")->Fill(onSp,onTrkPri,1);
	if(offTrkPri>=55) hist2("hOnSpOnTrkPri4","HLT/MinBiasMon/TrigTrack")->Fill(onSp,onTrkPri,1);
	if(offTrkPri>=60) hist2("hOnSpOnTrkPri5","HLT/MinBiasMon/TrigTrack")->Fill(onSp,onTrkPri,1);
	if(offTrkPri>=65) hist2("hOnSpOnTrkPri6","HLT/MinBiasMon/TrigTrack")->Fill(onSp,onTrkPri,1);
	if(offTrkPri>=70) hist2("hOnSpOnTrkPri7","HLT/MinBiasMon/TrigTrack")->Fill(onSp,onTrkPri,1);
	if(offTrkPri>=75) hist2("hOnSpOnTrkPri8","HLT/MinBiasMon/TrigTrack")->Fill(onSp,onTrkPri,1);
	if(offTrkPri>=80) hist2("hOnSpOnTrkPri9","HLT/MinBiasMon/TrigTrack")->Fill(onSp,onTrkPri,1);
	if(1) hist("hTrkCut0","HLT/MinBiasMon/TrigTrack")->Fill(offTrkPri);
	if(onSp>=600 && onTrkPri>=50) hist("hTrkCut1","HLT/MinBiasMon/TrigTrack")->Fill(offTrkPri);
	if(onSp>=700 && onTrkPri>=55) hist("hTrkCut2","HLT/MinBiasMon/TrigTrack")->Fill(offTrkPri);
	if(onSp>=900 && onTrkPri>=60) hist("hTrkCut3","HLT/MinBiasMon/TrigTrack")->Fill(offTrkPri);
	if(onSp>=1000 && onTrkPri>=65) hist("hTrkCut4","HLT/MinBiasMon/TrigTrack")->Fill(offTrkPri);
	if(onSp>=1200 && onTrkPri>=70) hist("hTrkCut5","HLT/MinBiasMon/TrigTrack")->Fill(offTrkPri);
	if(onSp>=1300 && onTrkPri>=75) hist("hTrkCut6","HLT/MinBiasMon/TrigTrack")->Fill(offTrkPri);
	if(onSp>=1400 && onTrkPri>=80) hist("hTrkCut7","HLT/MinBiasMon/TrigTrack")->Fill(offTrkPri);
	if(onSp>=1400 && onTrkPri>=85) hist("hTrkCut8","HLT/MinBiasMon/TrigTrack")->Fill(offTrkPri);
	if(onSp>=1400 && onTrkPri>=90) hist("hTrkCut9","HLT/MinBiasMon/TrigTrack")->Fill(offTrkPri);
//---------------------------------------------
// TrigHMT
	if(1) hist("hTrkHMT00","HLT/MinBiasMon/TrigHMT")->Fill(offTrkPri);
	if(onSp>=400 && onTrkPri>=40) hist("hTrkHMT01","HLT/MinBiasMon/TrigHMT")->Fill(offTrkPri);
	if(onSp>=600 && onTrkPri>=45) hist("hTrkHMT02","HLT/MinBiasMon/TrigHMT")->Fill(offTrkPri);
	if(onSp>=700 && onTrkPri>=50) hist("hTrkHMT03","HLT/MinBiasMon/TrigHMT")->Fill(offTrkPri);
	if(onSp>=700 && onTrkPri>=55) hist("hTrkHMT04","HLT/MinBiasMon/TrigHMT")->Fill(offTrkPri);
	if(onSp>=900 && onTrkPri>=60) hist("hTrkHMT05","HLT/MinBiasMon/TrigHMT")->Fill(offTrkPri);
	if(onSp>=900 && onTrkPri>=65) hist("hTrkHMT06","HLT/MinBiasMon/TrigHMT")->Fill(offTrkPri);
	if(onSp>=1000 && onTrkPri>=70) hist("hTrkHMT07","HLT/MinBiasMon/TrigHMT")->Fill(offTrkPri);
	if(onSp>=1200 && onTrkPri>=75) hist("hTrkHMT08","HLT/MinBiasMon/TrigHMT")->Fill(offTrkPri);
	if(onSp>=1400 && onTrkPri>=80) hist("hTrkHMT09","HLT/MinBiasMon/TrigHMT")->Fill(offTrkPri);
	if(1) hist("hEtHMT00","HLT/MinBiasMon/TrigHMT")->Fill(offSumEt);
	if(onSumEt>=40) hist("hEtHMT01","HLT/MinBiasMon/TrigHMT")->Fill(offSumEt);
	if(onSp>=300 && onSumEt>=40) hist("hEtHMT02","HLT/MinBiasMon/TrigHMT")->Fill(offSumEt);
	if(onSp>=600 && onSumEt>=40) hist("hEtHMT03","HLT/MinBiasMon/TrigHMT")->Fill(offSumEt);
	if(onSumEt>=50) hist("hEtHMT04","HLT/MinBiasMon/TrigHMT")->Fill(offSumEt);
	if(onSp>=300 && onSumEt>=50) hist("hEtHMT05","HLT/MinBiasMon/TrigHMT")->Fill(offSumEt);
	if(onSp>=600 && onSumEt>=50) hist("hEtHMT06","HLT/MinBiasMon/TrigHMT")->Fill(offSumEt);
	if(onSumEt>=60) hist("hEtHMT07","HLT/MinBiasMon/TrigHMT")->Fill(offSumEt);
	if(onSp>=300 && onSumEt>=60) hist("hEtHMT08","HLT/MinBiasMon/TrigHMT")->Fill(offSumEt);
	if(onSp>=600 && onSumEt>=60) hist("hEtHMT09","HLT/MinBiasMon/TrigHMT")->Fill(offSumEt);
	if(onSumEt>=70) hist("hEtHMT10","HLT/MinBiasMon/TrigHMT")->Fill(offSumEt);
	if(onSp>=300 && onSumEt>=70) hist("hEtHMT11","HLT/MinBiasMon/TrigHMT")->Fill(offSumEt);
	if(onSp>=600 && onSumEt>=70) hist("hEtHMT12","HLT/MinBiasMon/TrigHMT")->Fill(offSumEt);
	if(onSumEt>=80) hist("hEtHMT13","HLT/MinBiasMon/TrigHMT")->Fill(offSumEt);
	if(onSp>=300 && onSumEt>=80) hist("hEtHMT14","HLT/MinBiasMon/TrigHMT")->Fill(offSumEt);
	if(onSp>=600 && onSumEt>=80) hist("hEtHMT15","HLT/MinBiasMon/TrigHMT")->Fill(offSumEt);
	if((onSp>=900 && onTrkPri>=60) || (onSp>=300 && onSumEt>=60)) hist("hTest","HLT/MinBiasMon/TrigHMT")->Fill(offTrkPri);
	hist2("hOnTrkPriOnSumEt","HLT/MinBiasMon/TrigHMT")->Fill(onTrkPri,onSumEt,1);
//---------------------------------------------
}
/*//---------------------------------------------
	const xAOD::VertexContainer *vertices = 0;
	CHECK(evtStore()->retrieve(vertices,"HLT_xAOD__VertexContainer_xPrimVx"));
	float pileUp_offline=0;
	for(const auto *vertex : *vertices)
	{
		if(vertex->z()>pileUp_offline)
		{
			pileUp_offline=vertex->z();
		}
	}
	if(pileUp_offline>0) hist("hPileUpDis","HLT/MinBiasMon/PileUp")->Fill(pileUp_offline);
*//*//---------------------------------------------
	const TrigVertexCollection* vertexCollection = nullptr;
	sc = m_storeGate->retrieve(vertexCollection, m_vcolContainerName);
	for(TrigVertexCollection::const_iterator vtxIt = vertexCollection->begin(); vtxIt != vertexCollection->end(); ++vtxIt)
	{
		hist("hPileUpDis")->Fill((*vtxIt)->z() );
	}

*///---------------------------------------------
//---------------------------------------------

// + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
//+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
// + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
	
	bool refTrigPassed = getTDT()->isPassed(/*"EF_"*/ "HLT_" + m_refTrigItem);
	unsigned goodTracks;
	
	for (const auto &i: m_trigItems)
	{
		goodTracks = howManyGoodTracks(m_effSelTool[m_chainProperties[i].effCutIdx]);
		
		if (getTDT()->isPassed(/*"EF_"*/ "HLT_" + i))        //temporally
		{
			profile("TriggerEntriesProfile", "HLT/MinBiasMon")->Fill(i.c_str(), 1);
			hist("TriggerEntries", "HLT/MinBiasMon")->Fill(i.c_str(), 1);
			fillHistogramsForItem(i, m_chainProperties[i].histoGroup);
			fillPurityForItem(i, m_purSelTool[0]);
			
			if (refTrigPassed && (goodTracks > 1)) fillEfficiencyForItem(i, goodTracks, true);
			
//			hist("NumGoodOfflineTracks", "HLT/MinBiasMon/Purities&Efficiencies/" + i)->Fill(goodTracks, 1);
			hist("NumGoodOfflineTracks", "HLT/MinBiasMon/Purities&Efficiencies/" + i)->Fill(offTrkPri, 1);
			hist("NumGoodOfflineEt", "HLT/MinBiasMon/Purities&Efficiencies/" + i)->Fill(offSumEt, 1);
			hist("NumGoodOnlineL1TE", "HLT/MinBiasMon/Purities&Efficiencies/" + i)->Fill(onL1te, 1);
			hist("NumGoodOnlineSp", "HLT/MinBiasMon/Purities&Efficiencies/" + i)->Fill(onSp, 1);
		}
		else
		{
			profile("TriggerEntriesProfile", "HLT/MinBiasMon")->Fill(i.c_str(), 0);
			hist("TriggerEntries", "HLT/MinBiasMon")->Fill(i.c_str(), 0);
			(*m_log) << MSG::DEBUG << i << " chain is empty" << endreq; 
			
			if (refTrigPassed && (goodTracks > 1)) fillEfficiencyForItem(i, goodTracks, false);
		}
	}	
	return sc;
}

void HLTMinBiasMonTool::fillEfficiencyForItem(const std::string &item, unsigned goodTracks, bool isPassed)
{
	hist("TriggerEfficienciesAll", "HLT/MinBiasMon")->Fill(item.c_str(), 1);
	hist("EfficiencyAll", "HLT/MinBiasMon/Purities&Efficiencies/" + item)->Fill(getLumiBlockNr(), 1);
	hist("EfficiencyTracksAll", "HLT/MinBiasMon/Purities&Efficiencies/" + item)->Fill(goodTracks, 1);
	
	hist("TriggerEfficienciesPassed", "HLT/MinBiasMon")->Fill(item.c_str(), (isPassed)?1:0);
	hist("EfficiencyPassed", "HLT/MinBiasMon/Purities&Efficiencies/" + item)->Fill(getLumiBlockNr(), (isPassed)?1:0);
	hist("EfficiencyTracksPassed", "HLT/MinBiasMon/Purities&Efficiencies/" + item)->Fill(goodTracks, (isPassed)?1:0);
	
	return;
}

unsigned HLTMinBiasMonTool::howManyGoodTracks(const ToolHandle< InDet::IInDetTrackSelectionTool > &selTool)
{
	StatusCode sc = StatusCode::SUCCESS;
	// Get the InDetTrackParticles from the event:
	const xAOD::TrackParticleContainer* tracks = nullptr;
	sc = m_storeGate->retrieve(tracks,m_inDetTrackParticleContainerName);
	unsigned goodTracks(0);
	if (sc.isFailure() || tracks->empty()) {
		if (sc.isFailure())
			(*m_log) << MSG::WARNING << "Failed to retrieve TrackParticleCollection" << endreq;
		else
			(*m_log) << MSG::DEBUG << "TrackParticleCollection is empty." << endreq;
	} else {
	
		xAOD::TrackParticleContainer::const_iterator itr = tracks->begin();
		xAOD::TrackParticleContainer::const_iterator end = tracks->end();
	
		for ( ; itr!=end; ++itr)
		{
			const xAOD::TrackParticle* track = (*itr);
			if (selTool->accept(*track)) ++goodTracks;
		}
	}
	return goodTracks;
}

void HLTMinBiasMonTool::fillPurityForItem(const std::string &item, const ToolHandle< InDet::IInDetTrackSelectionTool > &selTool, unsigned greaterThan)
{
	StatusCode sc = StatusCode::SUCCESS;
	// Get the InDetTrackParticles from the event:
	const xAOD::TrackParticleContainer* tracks = nullptr;
	sc = m_storeGate->retrieve(tracks,m_inDetTrackParticleContainerName);
	unsigned goodTracks(0);
	if (sc.isFailure() || tracks->empty()) {
		if (sc.isFailure())
			(*m_log) << MSG::WARNING << "Failed to retrieve TrackParticleCollection" << endreq;
		else
			(*m_log) << MSG::DEBUG << "TrackParticleCollection is empty." << endreq;
	} else {
	
		xAOD::TrackParticleContainer::const_iterator itr = tracks->begin();
		xAOD::TrackParticleContainer::const_iterator end = tracks->end();
	
		for ( ; itr!=end; ++itr)
		{
			const xAOD::TrackParticle* track = (*itr);
			if (selTool->accept(*track)) ++goodTracks;
		}
		hist("TriggerPuritiesAll", "HLT/MinBiasMon")->Fill(item.c_str(), 1);
		hist("PurityAll", "HLT/MinBiasMon/Purities&Efficiencies/" + item)->Fill(getLumiBlockNr(), 1);
		hist("TriggerPuritiesPassed", "HLT/MinBiasMon")->Fill(item.c_str(), ((goodTracks > greaterThan)?1:0));
		hist("PurityPassed", "HLT/MinBiasMon/Purities&Efficiencies/" + item)->Fill(getLumiBlockNr(), ((goodTracks > greaterThan)?1:0));
	}
}

void HLTMinBiasMonTool::fillHistogramsForItem(const std::string &item, unsigned histGroup)
{
	StatusCode sc = StatusCode::SUCCESS;
	
	(*m_log) << MSG::DEBUG << "Currently processing: " << item << " in " << histGroup << endreq;
	
	if ( (histGroup & MBTS) == MBTS)
 	{
		setCurrentMonGroup("HLT/MinBiasMon/MBTS/" + item);
		sc = fillMbtsInfo(item);
		if (sc.isFailure())
		{
			(*m_log) << MSG::WARNING << "Couldn't fill MBTS info properly for: " << item << endreq;
		}
		sc = fillHLTMbtsInfo();
		if (sc.isFailure())
		{
			(*m_log) << MSG::WARNING << "Couldn't fill HLT MBTS info properly for: " << item << endreq;
		}
		sc = fillTrackingInfo();
		if (sc.isFailure())
		{
			(*m_log) << MSG::WARNING << "Couldn't fill tracking info properly for: " << item << endreq;
		}	
 	}
	
 	if ( (histGroup & LUCID) == LUCID)
 	{
		setCurrentMonGroup("HLT/MinBiasMon/LUCID/" + item);
		sc = fillLUCIDInfo();
		if (sc.isFailure())
		{
			(*m_log) << MSG::WARNING << "Couldn't fill LUCID info properly for: " << item << endreq;
		}
 	}
	
	if ( (histGroup & IDMINBIAS) == IDMINBIAS)
 	{
		setCurrentMonGroup("HLT/MinBiasMon/IDMinbias/" + item);
		sc = fillSpacePointInfo(item);
		if (sc.isFailure())
		{
			(*m_log) << MSG::WARNING << "Couldn't fill space point info properly for: " << item << endreq;
		}        
 	}
	
 	if ( (histGroup & ZDC) == ZDC)
 	{
		setCurrentMonGroup("HLT/MinBiasMon/ZDC/" + item);
		sc = fillZDCInfo();
		if (sc.isFailure())
		{
			(*m_log) << MSG::WARNING << "Couldn't fill ZDC info properly for: " << item << endreq;
		}
 	}
	
 	if ( (histGroup & BCM) == BCM)
 	{
		setCurrentMonGroup("HLT/MinBiasMon/BCM/" + item);
		sc = fillBCMInfo();
		if (sc.isFailure())
		{
			(*m_log) << MSG::WARNING << "Couldn't fill BCM info properly for: " << item << endreq;
		}
 	}
        
	if ( (histGroup & HMT) == HMT)
	{
		setCurrentMonGroup("HLT/MinBiasMon/HMT/" + item);
		sc = fillHMTSpacePointsInfo();
		if (sc.isFailure())
		{
			(*m_log) << MSG::WARNING << "Couldn't fill HMTSpacePoints info properly for: " << item << endreq;
		}
		sc = fillHMTVertexCountsInfo();
		if (sc.isFailure())
		{
			(*m_log) << MSG::WARNING << "Couldn't fill HMTVertexCounts info properly for: " << item << endreq;
		}
		sc = fillHMTTrigVertexCollectionInfo();
		if (sc.isFailure())
		{
			(*m_log) << MSG::WARNING << "Couldn't fill HMTTrigVertexCollection info properly for: " << item << endreq;
		}
	}
	if (sc.isFailure())
	{
		(*m_log) << MSG::WARNING << "Unknown error occurred in FillHistogramsForItem!" << endreq;
	}
	
	++m_numberOfEvents;
	(*m_log) << MSG::DEBUG << "PROCESSED SUCCESSFULLY" << endreq;        
}

StatusCode HLTMinBiasMonTool::fillZDCInfo()
{
	StatusCode sc = StatusCode::SUCCESS;
	
	// Unapcking Calorimeter energy:

	const CaloCellContainer * cellColl = 0;
	sc = m_storeGate->retrieve(cellColl,m_CaloCellContainerName);
	if (sc.isFailure()) {
	  return(StatusCode::SUCCESS); // to fix no-Calo datasets (bug #90180)
	}
	double FCal_A = 0;
	double FCal_C = 0;

	CaloCellContainer::const_iterator itrCell = cellColl->begin();
	CaloCellContainer::const_iterator itrLastCell = cellColl->end();      
	
	for ( ; itrCell!=itrLastCell; ++itrCell){
	  const CaloCell* cell = (*itrCell) ; 
	  const double theCellE=cell->energy();
	  

//	  int inum = CaloSampling::getSampling( *cell );
	  int inum = CaloSamplingHelper::getSampling( *cell );
	  if ((CaloSampling::FCAL0 == inum ) || 
	      (CaloSampling::FCAL1 == inum ) || 
	      (CaloSampling::FCAL2 == inum ) ){
	    if(cell->eta()>0){
	      FCal_A+= theCellE;
	    } else {
	      FCal_C+= theCellE;
	    }
	  }
	}
	FCal_A/= 1000.; //Calorimeter energy on side A
	FCal_C/= 1000.; //Calorimeter energy on side c


	//Unpacking Zdc Data:
	const ZdcRawChannelCollection *zdcChannelCollection = 0;

	double E_A = 0; //ZDC energy on Side A
	double E_C = 0; //ZDC energy on Side C

	sc = m_storeGate->retrieve(zdcChannelCollection, m_ZdcContainerName);

	if (sc.isFailure() || zdcChannelCollection->empty()) {
		if (sc.isFailure())
			(*m_log) << MSG::WARNING << "Failed to retrieve ZdcRawChannelCollection" << endreq;
		else
			(*m_log) << MSG::DEBUG << "ZdcRawChannelCollection is empty." << endreq;
	} else {

		ZdcRawChannelCollection::const_iterator itr = zdcChannelCollection->begin();
		ZdcRawChannelCollection::const_iterator end = zdcChannelCollection->end();

		double e;
		//double t;

		for (; itr != end; ++itr) {

			Identifier id = (*itr)->identify();
			e = ((*itr)->getEnergy(0));// / 1000.; // MeV-->GeV
			//t = (*itr)->getTime(0);

			if (m_ZdcID->module(id) < 4 && m_ZdcID->type(id) == 0) {
				if (m_ZdcID->side(id) > 0) { //Side A
					hist2("zdcChannels")->Fill(m_ZdcID->module(id), e);
					E_A += e;
				} else { //Side C
					E_C += e;
					hist2("zdcChannels")->Fill(m_ZdcID->module(id) + 4, e);
				}
			}

		} //End of loop over ZdcRawChannelCollection
	}

	//Test of the trigger decisions


	//Empty
	//----------------------------------------------------------------------
	hist("ZDC_EMPTY")->Fill(TMath::Max(E_A, E_C));

	// LHCf vs ZDC_C
	hist("m_h_ZDC_LHCF_corr")->Fill("LHCF and ZDC_C",1.0);
	hist("m_h_ZDC_LHCF_corr")->Fill("no LHCF and no ZDC_C",1.0);
	hist("m_h_ZDC_LHCF_corr")->Fill("LHCF, no ZDC_C",1.0);
	hist("m_h_ZDC_LHCF_corr")->Fill("no LHCF but ZDC_C",1.0);
	hist("m_h_ZDC_TE")->Fill("L1_TE0",1.0);
	hist("m_h_ZDC_TE")->Fill("L1_TE20",1.0);
	hist("m_h_ZDC_TE")->Fill("L1_TE50",1.0);
	hist("m_h_ZDC_TE")->Fill("L1_ZDC_C_VTE20",1.0);
	hist("m_h_ZDC_TE")->Fill("L1_ZDC_A_VTE20",1.0);
	
	// Any beam
	//----------------------------------------------------------------------
	hist("ZDC_All")->Fill(TMath::Max(E_A, E_C));
	hist("ZDC_A_C_All")->Fill(TMath::Min(E_A, E_C));
	hist2("ZDC_vs_FCAL_A_All")->Fill(E_A,FCal_A);
	hist("ZDC_A_All")->Fill(E_A);
	hist2("ZDC_vs_FCAL_C_All")->Fill(E_C,FCal_C);
	hist("ZDC_C_All")->Fill(E_C);
	
	// MBTS condition (stable beam)
	//----------------------------------------------------------------------


	/*if (orthogonal_trigger)
		return sc;*/

	return sc;
}

StatusCode HLTMinBiasMonTool::fillLUCIDInfo()
{
	StatusCode sc = StatusCode::SUCCESS;
	
	const int m_nLucidTubes = 40;
	
	int hitsA       = 0, hitsC      = 0;
	int hitsAp      = 0, hitsCp     = 0;
	int hitsAn      = 0, hitsCn     = 0;
        
	const LUCID_RawDataContainer* m_LUCID_RawDataContainer;
	sc = m_storeGate->retrieve(m_LUCID_RawDataContainer, m_LUCID_RawDataContainerName);

	if (sc.isFailure() || m_LUCID_RawDataContainer->empty()) {
		if (sc.isFailure())
			(*m_log) << MSG::WARNING << "Failed to retrieve LucidMinBiasMonTool for  LUCID_RawDataContainer" << endreq;
		else
			(*m_log) << MSG::DEBUG << "LUCID_RawDataContainer is empty." << endreq;

	} else {
		(*m_log) << (MSG::DEBUG) << " LUCID_RawDataContainer is retrived from StoreGate " << endreq;

		LUCID_RawDataContainer::const_iterator LUCID_RawData_itr = m_LUCID_RawDataContainer->begin();
		LUCID_RawDataContainer::const_iterator LUCID_RawData_end = m_LUCID_RawDataContainer->end();

		for (; LUCID_RawData_itr != LUCID_RawData_end; LUCID_RawData_itr++) {

			(*m_log) << (MSG::DEBUG) << " word1  : " << (*LUCID_RawData_itr)->getWord0() << endreq << " word2  : "
					<< (*LUCID_RawData_itr)->getWord1() << endreq << " word3  : " << (*LUCID_RawData_itr)->getWord2() << endreq
					<< " word4  : " << (*LUCID_RawData_itr)->getWord3() << endreq << " word1p : "
					<< (*LUCID_RawData_itr)->getWord0p() << endreq << " word2p : " << (*LUCID_RawData_itr)->getWord1p() << endreq
					<< " word3p : " << (*LUCID_RawData_itr)->getWord2p() << endreq << " word4p : "
					<< (*LUCID_RawData_itr)->getWord3p() << endreq << " word1n : " << (*LUCID_RawData_itr)->getWord0n() << endreq
					<< " word2n : " << (*LUCID_RawData_itr)->getWord1n() << endreq << " word3n : "
					<< (*LUCID_RawData_itr)->getWord2n() << endreq << " word4n : " << (*LUCID_RawData_itr)->getWord3n() << endreq
					<< " status: " << (*LUCID_RawData_itr)->getStatus() << endreq;

			for (int tub = 0; tub < m_nLucidTubes; tub++)
				if ((*LUCID_RawData_itr)->isTubeFired(tub, 0))
					hist("lucidChannels")->Fill(tub);

			//previous BX
			for (int tub = 0; tub < m_nLucidTubes; tub++)
				if ((*LUCID_RawData_itr)->isTubeFired(tub, 1))
					hist("lucidChannels_pBX")->Fill(tub);

			//next BX
			for (int tub = 0; tub < m_nLucidTubes; tub++)
				if ((*LUCID_RawData_itr)->isTubeFired(tub, 2))
					hist("lucidChannels_nBX")->Fill(tub);

			hitsA = (*LUCID_RawData_itr)->getNhitsPMTsideA();
			hitsC = (*LUCID_RawData_itr)->getNhitsPMTsideC();

			hitsAp = (*LUCID_RawData_itr)->getNhitsPMTsideAprevBX();
			hitsCp = (*LUCID_RawData_itr)->getNhitsPMTsideCprevBX();

			hitsAn = (*LUCID_RawData_itr)->getNhitsPMTsideAnextBX();
			hitsCn = (*LUCID_RawData_itr)->getNhitsPMTsideCnextBX();

		}
	}

	// Now we make plots to monitor the trigger decisions.
	// All the plots are done using # of hits
	// ---- fill histos with all events
	
	hist("LUCID_All")->Fill(TMath::Max(hitsA, hitsC));
	hist("LUCID_A_C_All")->Fill(TMath::Min(hitsA, hitsC));

	// --- fill only histos only for chains passing orthogonal trigger 
	/*if (orthogonal_trigger)               //how to resolve this???
		return sc;*/
        
	hist("LUCID_All")->Fill(TMath::Max(hitsA, hitsC));
	hist("LUCID_nBX")->Fill(TMath::Max(hitsAn, hitsCn));
	hist("LUCID_pBX")->Fill(TMath::Max(hitsAp, hitsCp));
	profile("TriggerErrors")->Fill("L1_LUCID", error_bit(TMath::Max(hitsA, hitsC) >= 1, 1));
	profile("TriggerErrors")->Fill("L1_LUCID_COMM", error_bit(TMath::Max(hitsA, hitsC) >= 1, 1));

	hist("LUCID_A_C")->Fill(TMath::Min(hitsA, hitsC));
	hist("LUCID_A_C_nBX")->Fill(TMath::Min(hitsAn, hitsCn));
	hist("LUCID_A_C_pBX")->Fill(TMath::Min(hitsAp, hitsCp));
	profile("TriggerErrors")->Fill("L1_LUCID_A_C", error_bit(TMath::Min(hitsA, hitsC) >= 1, 1));
	profile("TriggerErrors")->Fill("L1_LUCID_A", error_bit(TMath::Min(hitsA, hitsC) >= 1, 1));
	profile("TriggerErrors")->Fill("L1_LUCID_C", error_bit(TMath::Min(hitsA, hitsC) >= 1, 1));

	return sc;
}

StatusCode HLTMinBiasMonTool::fillBCMInfo()
{
	//hits on high-gain channels
	int n_OOT_A     = 0;
	int n_OOT_C     = 0;
	int n_W_OOT_A   = 0;
	int n_W_OOT_C   = 0;
	int n_IT_A      = 0;
	int n_IT_C      = 0;
	int n_W_IT_A    = 0;
	int n_W_IT_C    = 0;

	//hits on low-gain chnnels
	int n_LG_A = 0;
	int n_LG_C = 0;

	//we should check that the both triggers are in the same state!

	const BCM_RDO_Container* bcmRDOcont = 0;
	StatusCode sc_bcm = m_storeGate->retrieve(bcmRDOcont, m_bcmContainerName);
	if (sc_bcm.isFailure() || (bcmRDOcont->empty())) {
		if (sc_bcm.isFailure())
			(*m_log) << MSG::WARNING << "Failed to retrieve BcmMinBiasMonTool for BCM_RDO_Container" << endreq;
		else
			(*m_log) << MSG::DEBUG << " BCM_RDO_Container is empty." << endreq;
	} else {
		(*m_log) << MSG::DEBUG << " ====== START HLTMinBias MonTool for BCM_RDO_Container ====== " << endreq;

		BCM_RDO_Container::const_iterator bcm_coll_itr = bcmRDOcont->begin();
		for (; bcm_coll_itr != bcmRDOcont->end(); ++bcm_coll_itr) {

			unsigned int channelID = (*bcm_coll_itr)->getChannel();

			if ((*bcm_coll_itr)->empty()) {
				// If we look at InnerDetector/InDetDigitization/BCM_Digitization/src/BCM_Digitization.cxx, we see
				//  that a new collection is created if you are to insert an RDO in to it.  So we should not see
				//  empty collections.
				(*m_log) << MSG::DEBUG << "Encountered an empty BCM_RDO_Collection, skipping it." << endreq;
			} else {

				//Now we process a non-empty BCM container
				BCM_RDO_Collection::const_iterator bcm_rdo = (*bcm_coll_itr)->begin();

				for (; bcm_rdo != (*bcm_coll_itr)->end(); ++bcm_rdo) {

					if (channelID != static_cast<unsigned int> ((*bcm_rdo)->getChannel())) {
						// This should not happen. (Again see the digitization code mentioned above.)
						(*m_log) << MSG::WARNING << "Encountered a BCM_RDO in a wrong BCM_RDO_Collection, skipping it." << endreq;
					} else {

						//if (index != 18) { // we check only 1 BC for data
						if ((*bcm_rdo)->getLVL1A() != m_rdoIndex)
							continue;

						int pulse1pstn = (*bcm_rdo)->getPulse1Position();
						int pulse1wdth = (*bcm_rdo)->getPulse1Width();
						int pulse2pstn = (*bcm_rdo)->getPulse2Position();
						int pulse2wdth = (*bcm_rdo)->getPulse2Width();

						if (pulse1wdth > 0) {
							hist("bcmChannels")->Fill(channelID); //Hit multiplicity

							hist2("pulse1position")->Fill(channelID, pulse1pstn);
							profile("pulse1position_prof")->Fill(channelID, pulse1pstn);
							hist("pulse1width")->Fill(channelID, pulse1wdth);
							profile("pulse1width_prof")->Fill(channelID, pulse1wdth);
						}

						if (pulse2wdth > 0) {
							hist("bcmChannels")->Fill(channelID); //Hit multiplicity

							hist2("pulse2position")->Fill(channelID, pulse2pstn);
							profile("pulse2position_prof")->Fill(channelID, pulse2wdth);
							hist("pulse2width")->Fill(channelID, pulse2wdth);
							profile("pulse2width_prof")->Fill(channelID, pulse2pstn);
						}

						//Emulation of the Trigger logic
						if (channelID < 8) { //A. Low-gain channels
							if (channelID < 4) { //Side A
								if (pulse1wdth > 0)
									n_LG_A++;
								if (pulse2wdth > 0)
									n_LG_A++;
							} else { //side C
								if (pulse1wdth > 0)
									n_LG_C++;
								if (pulse2wdth > 0)
									n_LG_C++;
							}
						} else { // B.High-Gain channels
							if (channelID < 12) { //Side A

								if (abs(pulse1pstn - m_OOTPulse) < m_TimeWindow)
									n_OOT_A++;
								if (abs(pulse1pstn - m_ITPulse) < m_TimeWindow)
									n_IT_A++;
								if (abs(pulse1pstn - m_OOTPulse) < m_WideTimeWindow)
									n_W_OOT_A++;
								if (abs(pulse1pstn - m_WITPulse) < m_WideTimeWindow)
									n_W_IT_A++;

								if (abs(pulse2pstn - m_OOTPulse) < m_TimeWindow)
									n_OOT_A++;
								if (abs(pulse2pstn - m_ITPulse) < m_TimeWindow)
									n_IT_A++;
								if (abs(pulse2pstn - m_OOTPulse) < m_WideTimeWindow)
									n_W_OOT_A++;
								if (abs(pulse2pstn - m_WITPulse) < m_WideTimeWindow)
									n_W_IT_A++;
							} else { //Side C

								if (abs(pulse1pstn - m_OOTPulse) < m_TimeWindow)
									n_OOT_C++;
								if (abs(pulse1pstn - m_ITPulse) < m_TimeWindow)
									n_IT_C++;
								if (abs(pulse1pstn - m_OOTPulse) < m_WideTimeWindow)
									n_W_OOT_C++;
								if (abs(pulse1pstn - m_WITPulse) < m_WideTimeWindow)
									n_W_IT_C++;

								if (abs(pulse2pstn - m_OOTPulse) < m_TimeWindow)
									n_OOT_C++;
								if (abs(pulse2pstn - m_ITPulse) < m_TimeWindow)
									n_IT_C++;
								if (abs(pulse2pstn - m_OOTPulse) < m_WideTimeWindow)
									n_W_OOT_C++;
								if (abs(pulse2pstn - m_WITPulse) < m_WideTimeWindow)
									n_W_IT_C++;
							} // End of the if statement for the channel ID

						}// end of loop

					}
				}

			}
		}
	}

	// Now we make plots to monitor detector work, no MBTS trigger decisions.
	// All the plots are done using # of hits
	
	hist("BCM_Wide_All")->Fill(TMath::Min(n_W_IT_A, n_W_IT_C));
	int min_all = TMath::Max(TMath::Min(n_OOT_A, n_IT_C), TMath::Min(n_OOT_C, n_IT_A));
	hist("BCM_AC_CA_All")->Fill(min_all);
	hist("BCM_HT_All")->Fill(n_LG_A + n_LG_C);

	// Now we make plots to monitor the trigger decisions.
	// All the plots are done using # of hits
	// consequently, improve reliability of the monitoring code

	//if (orthogonal_trigger) return StatusCode::SUCCESS;   //WHAT TO DO WITH THIS???
	
	//up to 8 hits per side [0,8]
	hist("BCM_Wide")->Fill(TMath::Min(n_W_IT_A, n_W_IT_C));
	profile("TriggerErrors")->Fill("L1_BCM_Wide", error_bit(TMath::Min(n_W_IT_A, n_W_IT_C) >= 1, 1));
	
	//int min_all = TMath::Max(TMath::Min(n_OOT_A, n_IT_C), TMath::Min(n_OOT_C, n_IT_A));
	hist("BCM_AC_CA")->Fill(min_all);     
	profile("TriggerErrors")->Fill("L1_BCM_AC_CA", error_bit(TMath::Min(n_OOT_A, n_IT_C) >= 1 || TMath::Min(n_OOT_C, n_IT_A) >= 1, 1));
        
	//up to 16 hits in total [0,16]
	hist("BCM_HT")->Fill(n_LG_A + n_LG_C);
	profile("TriggerErrors")->Fill("L1_BCM_HT", error_bit((n_LG_A + n_LG_C) >= 1, 1));
	

	//TODO: The summary timing plot to distinguish pp collisions against beam gas & splash
	/*
	 //we find the minimum time difference between hits on side A and side C
	 for (int i = 0; i < nhits_A; i++)
	 for (int j = 0; j < nhits_C; j++)
	 if (abs(time_A[i] - time_C[j]) < t_diff)
	 t_diff = abs(time_A[i] - time_C[j]);

	 bcmTime_AC->Fill(t_diff);
	 */
	return StatusCode::SUCCESS;
}

StatusCode HLTMinBiasMonTool::fillHLTMbtsInfo()
{
	StatusCode sc = StatusCode::SUCCESS;
	
	// Energy Time
	
	unsigned int triggerWord = 0;
	unsigned int timeWord = 0;
	
	std::vector<float> mbtsHitEnergies; // energy (in pC) of signal in a counter (relative to IP), vector for all counters
	std::vector<float> mbtsHitTimes; // time of signal in counter (relative to IP), vector for all counters        
	
	int time_ebaCounters=0, time_ebcCounters=0;
	int energy_ebaCounters=0, energy_ebcCounters=0;
	float timeMean_A = 0.;
	float timeMean_C = 0.;
	float timeMin_A = 10000.;
	float timeMin_C = 10000.;
	float energyMean_A = 0.;
	float energyMean_C = 0.;
	float energyMax_A = -10000.;
	float energyMax_C = -10000.;
	
	//==============================================================================
	// MBTS BITS INFORMATION
	//==============================================================================
	
	const xAOD::TrigT2MbtsBitsContainer* mbTScont = 0;
	sc = m_storeGate->retrieve(mbTScont, m_t2mbtsContainerName);
	
	if (sc.isFailure() || mbTScont->empty()) {
		if (sc.isFailure())
			(*m_log) << MSG::WARNING << "Failed to retrieve MbtsMinBiasMonTool for xAOD::TrigT2MbtsBitsContainer" << endreq;
		else
			(*m_log) << MSG::DEBUG << "xAOD::TrigT2MbtsBitsContainer is empty." << endreq;
	} else {
		(*m_log) << MSG::DEBUG << " ====== START MbtsMinBiasMonTool for xAOD::TrigT2MbtsBitsContainer ====== " << endreq;
	
		// Loop over EF TrigMinBias objects
		xAOD::TrigT2MbtsBitsContainer::const_iterator mbTS_coll_itr = mbTScont->begin();
		for (; mbTS_coll_itr != mbTScont->end(); ++mbTS_coll_itr) {
	
			xAOD::TrigT2MbtsBits *mbtsFeature = (*mbTS_coll_itr);
	
			mbtsHitEnergies = mbtsFeature->triggerEnergies();
			mbtsHitTimes = mbtsFeature->triggerTimes();
	
			if (mbtsHitTimes.size() != 32)
				(*m_log) << MSG::ERROR << "MBTS Cell Times are stored incorrectly. The array should have 32 elements." << endreq;
	
			if (mbtsHitEnergies.size() != 32)
				(*m_log) << MSG::ERROR << "MBTS Cell Energies are stored incorrectly. The array should have 32 elements." << endreq;
	
			//The energy-dependent bitmask is produced below
			for (std::size_t k = 0; k < mbtsHitEnergies.size() && k < 32; k++)
				if (mbtsHitEnergies.at(k) > m_energyCut) {
					triggerWord += (1 << k);
					// Online distributions
					const char* cell_name = (m_moduleLabel[k]).data();
					if (k < 16) { // A side
						hist("Occupancy_Online - side A")->Fill(cell_name, 1.0);
						timeMean_A += mbtsHitTimes.at(k); time_ebaCounters++;
						if (mbtsHitTimes.at(k) < timeMin_A) timeMin_A = mbtsHitTimes.at(k);
						if (k == 15) {  
							hist("m_h_timeMin_A")->Fill(timeMin_A);
							if (time_ebaCounters> 0) {
								timeMean_A /= time_ebaCounters;
								hist("m_h_timeMean_A")->Fill(timeMean_A);
							} 
							else {
							timeMean_A = -999.0;
							}
						}
					} else { // C side 
						hist("Occupancy_Online - side C")->Fill(cell_name, 1.0);
						timeMean_C += mbtsHitTimes.at(k); time_ebcCounters++;
						if (mbtsHitTimes.at(k) < timeMin_C) timeMin_C = mbtsHitTimes.at(k);
						if (k == 31) {
							hist("m_h_timeMin_C")->Fill(timeMin_C);
							if (time_ebcCounters> 0) {
								timeMean_C /= time_ebcCounters;
								hist("m_h_timeMean_C")->Fill(timeMean_C);
							} 
							else {
							timeMean_C = -999.0;
							}
						}
					}
					//Time online
					hist("m_h_time_onl")->Fill(mbtsHitTimes.at(k));                                        
				}
			//The time-dependent bitmask is produced for the case
			//of time-dependent L2 trigger
			for (std::size_t k = 0; k < mbtsHitTimes.size() && k < 32; k++) {
				if (fabs(mbtsHitTimes.at(k)) < m_timeCut || m_timeCut <= 0.0)
					timeWord += (1 << k);
	
				// Online distributions
				//const char* cell_name = (m_moduleLabel[k]).data();
	
				if (k < 16) { // A side
					energyMean_A += mbtsHitEnergies.at(k); energy_ebaCounters++;
					if (mbtsHitEnergies.at(k) > energyMax_A) energyMax_A = mbtsHitEnergies.at(k);
					if (k == 15) {
						hist("m_h_energyMax_A")->Fill(energyMax_A);                                             
						if (energy_ebaCounters> 0) {
							energyMean_A /= energy_ebaCounters;
							hist("m_h_energyMean_A")->Fill(energyMean_A);
						} 
						else {
							energyMean_A = -999.0;
						}
					}
				} else { // C side 
					energyMean_C += mbtsHitEnergies.at(k); energy_ebcCounters++;
					if (mbtsHitEnergies.at(k) > energyMax_C) energyMax_C = mbtsHitEnergies.at(k);
					if (k == 31)  {
						hist("m_h_energyMax_C")->Fill(energyMax_C);
						if ( energy_ebcCounters> 0) {
							energyMean_C /= energy_ebcCounters;
							hist("m_h_energyMean_C")->Fill(energyMean_C);
						} 
						else {
							energyMean_C = -999.0;
						}
					}
				}
				//Energy online
				hist("m_h_energy_onl")->Fill(mbtsHitEnergies.at(k));                                 
			}
		}
	} // end TrigT2MbtsBitsContainer.h    
	
	return sc;
}

StatusCode HLTMinBiasMonTool::fillMbtsInfo(const std::string &item)
{
	unsigned int triggerWord = 0;
	unsigned int timeWord = 0;
	const unsigned int mask = 65535; // 2^16 - 1
	//int counter = 0;

	unsigned int innerMBTS_EBA = 0;
	unsigned int innerMBTS_EBC = 0;
	unsigned int outerMBTS_EBA = 0;
	unsigned int outerMBTS_EBC = 0;

	unsigned int innerMBTS_EBA_NoCut_Time = 10; // it can not be larger than 8
	unsigned int innerMBTS_EBC_NoCut_Time = 0;
	unsigned int outerMBTS_EBA_NoCut_Time = 0;
	unsigned int outerMBTS_EBC_NoCut_Time = 0;

	unsigned int total_hits_NoCut_Time = 0;
	//unsigned int sideA_hits_NoCut_Time = 0;
	//unsigned int sideC_hits_NoCut_Time = 0;

	//unsigned int total_hits = 0;
	unsigned int sideA_hits = 0;
	unsigned int sideC_hits = 0;

	std::vector<float> mbtsHitEnergies; // energy (in pC) of signal in a counter (relative to IP), vector for all counters
	std::vector<float> mbtsHitTimes; // time of signal in counter (relative to IP), vector for all counters
	
	//==============================================================================
	// MBTS BITS INFORMATION
	//==============================================================================
	const xAOD::TrigT2MbtsBitsContainer* mbTScont = 0;
	StatusCode sc = m_storeGate->retrieve(mbTScont, m_t2mbtsContainerName);

	if (sc.isFailure() || mbTScont->empty()) {
		if (sc.isFailure())
			(*m_log) << MSG::WARNING << "Failed to retrieve MbtsMinBiasMonTool for xAOD::TrigT2MbtsBitsContainer" << endreq;
		else
			(*m_log) << MSG::DEBUG << "xAOD::TrigT2MbtsBitsContainer is empty." << endreq;
	} else {
		(*m_log) << MSG::DEBUG << " ====== START MbtsMinBiasMonTool for xAOD::TrigT2MbtsBitsContainer ====== " << endreq;

		// Loop over EF TrigMinBias objects
		xAOD::TrigT2MbtsBitsContainer::const_iterator mbTS_coll_itr = mbTScont->begin();
		for (; mbTS_coll_itr != mbTScont->end(); ++mbTS_coll_itr) {

			xAOD::TrigT2MbtsBits *mbtsFeature = (*mbTS_coll_itr);

			mbtsHitEnergies = mbtsFeature->triggerEnergies();
			mbtsHitTimes = mbtsFeature->triggerTimes();

			if (mbtsHitTimes.size() != 32)
				(*m_log) << MSG::ERROR << "MBTS Cell Times are stored incorrectly. The array should have 32 elements."
						<< endreq;

			if (mbtsHitEnergies.size() != 32)
				(*m_log) << MSG::ERROR << "MBTS Cell Energies are stored incorrectly. The array should have 32 elements."
						<< endreq;

			//The energy-dependent bitmask is produced below 
			for (std::size_t k = 0; k < mbtsHitEnergies.size() && k < 32; k++)
				if (mbtsHitEnergies.at(k) > m_energyCut) {
					triggerWord += (1 << k);
					// Online distributions
					const char* cell_name = (m_moduleLabel[k]).data();
					hist("Occupancy_Online")->Fill(cell_name, 1.0);                        
					hist2("m_h_time_Online")->Fill(cell_name, mbtsHitTimes.at(k), 1.0);         
				}

			//The time-dependent bitmask is produced for the case 
			//of time-dependent L2 trigger
			for (std::size_t k = 0; k < mbtsHitTimes.size() && k < 32; k++) {
				if (fabs(mbtsHitTimes.at(k)) < m_timeCut || m_timeCut <= 0.0)
					timeWord += (1 << k);

				// Online distributions
				const char* cell_name = (m_moduleLabel[k]).data();
				hist2("m_h_energy_Online")->Fill(cell_name, mbtsHitEnergies.at(k), 1.0);            
			}

			timeWord &= triggerWord;

			//This are the multiplicities without the time cut-offs
			//TODO: The calculations can be simplified significantly

			std::bitset<8> InnerEbaBitset_NoCut_Time(triggerWord & mask);
			std::bitset<8> OuterEbaBitset_NoCut_Time((triggerWord >> 8) & mask);
			std::bitset<8> InnerEbcBitset_NoCut_Time((triggerWord >> 16) & mask);
			std::bitset<8> OuterEbcBitset_NoCut_Time((triggerWord >> 24) & mask);

			innerMBTS_EBA_NoCut_Time = InnerEbaBitset_NoCut_Time.count();
			outerMBTS_EBA_NoCut_Time = OuterEbaBitset_NoCut_Time.count();
			innerMBTS_EBC_NoCut_Time = InnerEbcBitset_NoCut_Time.count();
			outerMBTS_EBC_NoCut_Time = OuterEbcBitset_NoCut_Time.count();

			total_hits_NoCut_Time = innerMBTS_EBA_NoCut_Time + outerMBTS_EBA_NoCut_Time + innerMBTS_EBC_NoCut_Time
					+ outerMBTS_EBC_NoCut_Time;
			//sideA_hits_NoCut_Time = innerMBTS_EBA_NoCut_Time + outerMBTS_EBA_NoCut_Time;
			//sideC_hits_NoCut_Time = innerMBTS_EBC_NoCut_Time + outerMBTS_EBC_NoCut_Time;

			std::bitset<8> InnerEbaBitset(triggerWord & timeWord & mask);
			std::bitset<8> OuterEbaBitset(((triggerWord & timeWord) >> 8) & mask);
			std::bitset<8> InnerEbcBitset(((triggerWord & timeWord) >> 16) & mask);
			std::bitset<8> OuterEbcBitset(((triggerWord & timeWord) >> 24) & mask);

			innerMBTS_EBA = InnerEbaBitset.count();
			outerMBTS_EBA = OuterEbaBitset.count();
			innerMBTS_EBC = InnerEbcBitset.count();
			outerMBTS_EBC = OuterEbcBitset.count();

			//total_hits = innerMBTS_EBA + outerMBTS_EBA + innerMBTS_EBC + outerMBTS_EBC;
			sideA_hits = innerMBTS_EBA + outerMBTS_EBA;
			sideC_hits = innerMBTS_EBC + outerMBTS_EBC;

			//Filling Histograms

                        hist("mbMbts_N_N_hits")->Fill(TMath::Min(sideA_hits, sideC_hits));               
			hist("TriggerRate")->Fill(/*item.c_str(),*/ 1);                                      
			//hist("TriggerRatePS")->Fill(/*item.c_str(),*/ m_tdthandle->getChainGroup(item.c_str())->getPrescale());       
			hist("mbMbts_hits")->Fill(total_hits_NoCut_Time);  
			
			hist2("m_h_mbtsCorr_N_N")->Fill(sideA_hits, sideC_hits, 1);                        
		}
	} // end TrigT2MbtsBitsContainer.h


	//==============================================================================
	// CELL LEVEL INFORMATION
	//==============================================================================
	//Retrieve MBTS container collection from SG

	const TileCellContainer* theMBTScontainer;
	sc = m_storeGate->retrieve(theMBTScontainer, m_mbtsContainerName);
	if (sc.isFailure() || theMBTScontainer->empty()) {
		if (sc.isFailure())
			(*m_log) << MSG::WARNING << "Cannot find TileCellContainer object with name " << m_mbtsContainerName << " in TDS"
					<< endreq;
		else
			(*m_log) << MSG::DEBUG << "TileCellContainer is empty." << endreq;
	} else {
		(*m_log) << MSG::VERBOSE << "Retrieval of MBTS container " << m_mbtsContainerName << " succeeded" << endreq;

		double quality;
		double energy[32], time[32];
		memset(energy, 0, sizeof(energy));
		memset(time, 0, sizeof(time));

		bool sim_bit = false;
		bool trigger_bit = false;

		bool sim_time_bit = false;
		bool time_bit = false;

		TileCellContainer::const_iterator iCell = theMBTScontainer->begin();
		TileCellContainer::const_iterator lastCell = theMBTScontainer->end();

		//We process the cell information only if the T2MbtsFex was ran
		for (; iCell != lastCell; ++iCell) {

			const TileCell* mbtsCell = *iCell; // pointer to cell object
			if (mbtsCell != 0) {
				Identifier id = mbtsCell->ID();

				// Calculate MBTS counter from "side", "tower" and "module"
				// Counter goes 0-31.
				// EBA-inner:0-7,EBA-outer:8-15,EBC-inner:16-23,EBC-outer:24-31
				// tower is 1 for outer counter (lower eta) and 0 for inner counter (higher eta)
				// module counts from 0-7 in increasing phi
				// side is -1 for EBC 1 for EBA
                                //int counter = m_tileTBID->phi(id) + 8 * m_tileTBID->eta(id); 
	 
                               int counter = m_tileTBID->phi(id) + 8 * m_tileTBID->eta(id); 
	                       if (m_tileTBID->side(id) < 0) counter += 16;// EBC side

				//the counter should not go outside of the range: [0,31]
				if (counter < 0 || counter > 31) {
					(*m_log) << MSG::WARNING << "MBTS Cell ID is incorrect. The cell is skipped. " << endreq;
					continue;
				}

				energy[counter] = mbtsCell->energy();
				time[counter] = mbtsCell->time();
				quality = mbtsCell->quality();

				const char* cell_name = (m_moduleLabel[counter]).data();

				if (msgSvc()->outputLevel(name()) < MSG::DEBUG) {
					(*m_log) << MSG::VERBOSE << "Counter: " << counter << endreq;
					(*m_log) << MSG::VERBOSE << "Energy= " << energy[counter] << " pCb" << endreq;
					(*m_log) << MSG::VERBOSE << "Time= " << time[counter] << endreq;
					(*m_log) << MSG::VERBOSE << "Quality= " << quality << endreq;
				}

				hist2("m_h_energy")->Fill(cell_name, energy[counter], 1.0);      

				//The simulated trigger dicision
				sim_bit = (energy[counter] > m_energyCut);

				//The simulated trigger time dicision
				sim_time_bit = ((fabs(time[counter]) < m_timeCut) || (m_timeCut <= 0.0));

				if (sim_bit) {
					hist("Occupancy")->Fill(cell_name, 1.0);            
					hist2("m_h_time")->Fill(cell_name, time[counter], 1.0);  
				}

				//The histograms are filled only when the L2 MbtsFex was ran
				if (innerMBTS_EBA_NoCut_Time < 9) {
					//L2 trigger bit
					trigger_bit = (((triggerWord >> counter) & 1) == 1);

					//L2 time bit
					time_bit = (((timeWord >> counter) & 1) == 1);

					if (sim_bit && !trigger_bit)
						hist2("m_h_time_TF_SP")->Fill(cell_name, energy[counter], 1.0);        

					if (!sim_bit && trigger_bit)
						hist2("m_h_time_TP_SF")->Fill(cell_name, energy[counter], 1.0);        

					profile("MbtsEnergyErrors")->Fill(cell_name, error_bit(sim_bit, trigger_bit)); 

					//Timing information is stored only for cells with E > threshold @ L2:
					if (trigger_bit && sim_bit) {
						if (!time_bit && sim_time_bit)
							hist2("m_h_time_TF_SP")->Fill(cell_name, time[counter], 1.0);    

						if (time_bit && !sim_time_bit)
							hist2("m_h_time_TP_SF")->Fill(cell_name, time[counter], 1.0);    

						profile("MbtsTimeErrors")->Fill(cell_name, error_bit(time_bit, sim_time_bit)); 
					}
				} //require L2 Trigger

			} // end if cell not empty
		} // end Cell loop


	} // End of processing of TileCellContainer


	return StatusCode::SUCCESS;
}

StatusCode HLTMinBiasMonTool::fillSpacePointInfo(const std::string &item)
{
	StatusCode sc = StatusCode::SUCCESS;
	
	pixSpBarr = 0;
	pixSpECA = 0;
	pixSpECC = 0;
	sctSpBarr = 0;
	sctSpECA = 0;
	sctSpECC = 0;

	const xAOD::TrigSpacePointCountsContainer* mbSPcont = 0;
	StatusCode sc_mbsp = m_storeGate->retrieve(mbSPcont, m_spContainerName);

	if (sc_mbsp.isFailure() || mbSPcont->empty()) {
		if (sc_mbsp.isFailure())
			(*m_log) << MSG::WARNING << "Failed to retrieve HLT MinBias for xAOD::TrigSpacePointCountsContainer" << endreq;
		else
			(*m_log) << MSG::DEBUG << "xAOD::TrigSpacePointCountsContainer is empty." << endreq;
	} else {
		(*m_log) << MSG::DEBUG << " ====== START HLTMinBias MonTool for xAOD::TrigSpacePointCountsContainer ====== " << endreq;

		(*m_log) << MSG::DEBUG << "space point container has " << mbSPcont->size() << " entries." << endreq;

		// Loop over TrigMinBias feature objects
		xAOD::TrigSpacePointCountsContainer::const_iterator mbSP_coll_itr = mbSPcont->begin();
		xAOD::TrigSpacePointCountsContainer::const_iterator mbSP_coll_itrE = mbSPcont->end();

		for (; mbSP_coll_itr != mbSP_coll_itrE; ++mbSP_coll_itr) {
			xAOD::TrigSpacePointCounts *id_mbFeature = (*mbSP_coll_itr);
			unsigned totBins = id_mbFeature->pixelClusTotBins();
			if ( totBins > 0){
				pixSpBarr = (int) id_mbFeature->pixelClusBarrelSumEntries(m_timeOverThresholdCut, 0., xAOD::TrigHistoCutType::ABOVE_X_ABOVE_Y);
				hist("pixBarr_sp")->Fill(pixSpBarr);
				
				pixSpECA = (int) id_mbFeature->pixelClusEndcapASumEntries(m_timeOverThresholdCut, 0., xAOD::TrigHistoCutType::ABOVE_X_ABOVE_Y);
				hist("pixECA_sp")->Fill(pixSpECA);
				
				pixSpECC = (int) id_mbFeature->pixelClusEndcapCSumEntries(m_timeOverThresholdCut, 0., xAOD::TrigHistoCutType::ABOVE_X_ABOVE_Y);
				hist("pixECC_sp")->Fill(pixSpECC);
				
			} else {
				(*m_log) << MSG::WARNING << "SpacePointCounts is not initialized properly; it has 0 bins in X or Y: "	<< totBins << endreq;
			}
                        
			sctSpBarr = (int) id_mbFeature->sctSpBarrel();
			sctSpECA = (int) id_mbFeature->sctSpEndcapA();
			sctSpECC = (int) id_mbFeature->sctSpEndcapC();
			
			hist("sctBarr_sp")->Fill(sctSpBarr);
			hist("sctECA_sp")->Fill(sctSpECA);
			hist("sctECC_sp")->Fill(sctSpECC);
                        
			hist("h_pixTot")->Fill(pixSpBarr + pixSpECA + pixSpECC);
			hist("h_sctTot")->Fill(sctSpBarr + sctSpECA + sctSpECC); //has overflows -> deeper investigation needed
		}

	} // end TrigSpacePointCounts

	//Now we can form a proper L2 simulated decision
        
        bool sim = false;
	if (m_triggerTypeAND) {
                sim = ((pixSpBarr + pixSpECC + pixSpECA) > m_totalPixelClus_cut) && ((sctSpBarr + sctSpECA + sctSpECC) > m_totalSctSp_cut);
	} else {
		sim  = ((pixSpBarr + pixSpECC + pixSpECA) > m_totalPixelClus_cut) || ((sctSpBarr + sctSpECA + sctSpECC) > m_totalSctSp_cut);
	}
         
	if (!sim) { //Trigger mismatch; error
		profile("IDMinBiasTriggerErrors", "HLT/MinBiasMon/IDMinbias")->Fill(item.c_str(), 1.0);
	} else {
		profile("IDMinBiasTriggerErrors", "HLT/MinBiasMon/IDMinbias")->Fill(item.c_str(), 0.0);
	}
       
        return sc;
}

StatusCode HLTMinBiasMonTool::fillTrackingInfo()
{
	StatusCode sc = StatusCode::SUCCESS;

	// EF ID (it is the same for trt and pixel+sct)
	const xAOD::TrigTrackCountsContainer* mbTTcont = 0;
	StatusCode sc_mbtt = m_storeGate->retrieve(mbTTcont, m_tcContainerName);

	if (sc_mbtt.isFailure() || mbTTcont->empty()) {
		if (sc_mbtt.isFailure())
			(*m_log) << MSG::WARNING << "Failed to retrieve HLT MinBias MonTool for xAOD::TrigTrackCountsContainer" << endreq;
		else
			(*m_log) << MSG::DEBUG << "xAOD::TrigTrackCountsContainer is empty." << endreq;

	} else {
		(*m_log) << MSG::DEBUG << " ====== START HLTMinBias MonTool for xAOD::TrigTrackCountsContainer ====== " << endreq;

		mbTracks = 0;
		totpix_spEF = 0;
		totsct_spEF = 0;

		// Loop over EF TrigMinBias objects
		xAOD::TrigTrackCountsContainer::const_iterator mbTT_coll_itr = mbTTcont->begin();
		for (; mbTT_coll_itr != mbTTcont->end(); ++mbTT_coll_itr) {
			xAOD::TrigTrackCounts *mbTT = (*mbTT_coll_itr);

			if (mbTT->z0Bins() > 0) {
				mbTracks = (int) (mbTT->z0_ptSumEntries(m_max_z0, m_min_pt, xAOD::TrigHistoCutType::BELOW_X_ABOVE_Y));
				hist("minbiasTracks")->Fill(mbTracks);
			} else {
				(*m_log) << MSG::WARNING << "The trigger histogram z0_pt is not initialized properly; it has 0 bins in X or Y: " << mbTT->z0Bins()	<< endreq;
			}

		}
	} // end TrigTrackCounts

        return sc;
}

StatusCode HLTMinBiasMonTool::fillHMTSpacePointsInfo()
{
	StatusCode sc = StatusCode::SUCCESS;
	
	// for monitoring
	int totNumPixSP = -999;
	int totNumSctSP = -999;
	double multiplicity[3];
	for (auto &i: multiplicity) i = 0.0;
	
	const xAOD::TrigSpacePointCountsContainer* mbSPcont = nullptr;
	sc = m_storeGate->retrieve(mbSPcont, m_spContainerName);
	
	if (sc.isFailure() || !mbSPcont) {
		if (sc.isFailure())
			(*m_log) << MSG::WARNING << "Failed to retrieve TrigSpacePointCountsMonTool for xAOD::TrigSpacePointCounts" << endreq;
		else
			(*m_log) << MSG::DEBUG << "xAOD::TrigSpacePointCounts is empty." << endreq;
	} else {
		(*m_log) << MSG::DEBUG << " ====== START TrigSpacePointCountsMonTool for xAOD::TrigSpacePointCounts ====== " << endreq;
		
		xAOD::TrigSpacePointCountsContainer::const_iterator mbSP_coll_itr = mbSPcont->begin();
		xAOD::TrigSpacePointCountsContainer::const_iterator mbSP_coll_itrE = mbSPcont->end();
		unsigned tmp = 0;
		for (; mbSP_coll_itr != mbSP_coll_itrE; ++mbSP_coll_itr) 
		{
			xAOD::TrigSpacePointCounts *trigSpacePointCounts = (*mbSP_coll_itr);
			++tmp;
	
			totNumSctSP = trigSpacePointCounts->sctSpEndcapC() + trigSpacePointCounts->sctSpEndcapA() + trigSpacePointCounts->sctSpBarrel();
			
			xAOD::TrigHisto2D *th2dPixelClusEndcapC = new xAOD::TrigHisto2D;
			xAOD::TrigHisto2D *th2dPixelClusBarrel  = new xAOD::TrigHisto2D;
			xAOD::TrigHisto2D *th2dPixelClusEndcapA = new xAOD::TrigHisto2D;
		
			//make private stores
			th2dPixelClusEndcapC->makePrivateStore();
			th2dPixelClusBarrel->makePrivateStore();
			th2dPixelClusEndcapA->makePrivateStore();
		
			th2dPixelClusEndcapC->initialize(trigSpacePointCounts->pixelClusTotBins(),
										trigSpacePointCounts->pixelClusTotMin(),
										trigSpacePointCounts->pixelClusTotMax(),
										trigSpacePointCounts->pixelClusSizeBins(),
										trigSpacePointCounts->pixelClusSizeMin(),
										trigSpacePointCounts->pixelClusSizeMax());
	
			th2dPixelClusEndcapC->setContents(trigSpacePointCounts->contentsPixelClusEndcapC());
	
			th2dPixelClusBarrel->initialize(trigSpacePointCounts->pixelClusTotBins(),
										trigSpacePointCounts->pixelClusTotMin(),
										trigSpacePointCounts->pixelClusTotMax(),
										trigSpacePointCounts->pixelClusSizeBins(),
										trigSpacePointCounts->pixelClusSizeMin(),
										trigSpacePointCounts->pixelClusSizeMax());
	
			th2dPixelClusBarrel->setContents(trigSpacePointCounts->contentsPixelClusBarrel());
	
			th2dPixelClusEndcapA->initialize(trigSpacePointCounts->pixelClusTotBins(),
										trigSpacePointCounts->pixelClusTotMin(),
										trigSpacePointCounts->pixelClusTotMax(),
										trigSpacePointCounts->pixelClusSizeBins(),
										trigSpacePointCounts->pixelClusSizeMin(),
										trigSpacePointCounts->pixelClusSizeMax());
	
			th2dPixelClusEndcapA->setContents(trigSpacePointCounts->contentsPixelClusEndcapA());
	
			multiplicity[0] = th2dPixelClusEndcapC->sumEntries(m_timeOverThreshold_cut, 0., xAOD::TrigHistoCutType::ABOVE_X_ABOVE_Y);
			multiplicity[1] = th2dPixelClusEndcapA->sumEntries(m_timeOverThreshold_cut, 0., xAOD::TrigHistoCutType::ABOVE_X_ABOVE_Y);
			multiplicity[2] = th2dPixelClusBarrel->sumEntries(m_timeOverThreshold_cut, 0., xAOD::TrigHistoCutType::ABOVE_X_ABOVE_Y);
			totNumPixSP = multiplicity[0] + multiplicity[1] + multiplicity[2];
		
			hist("numSpacePoints")->Fill(totNumPixSP + totNumSctSP);
		
			//check if it fits the problem :)
			th2dPixelClusEndcapC->releasePrivateStore();
			th2dPixelClusBarrel->releasePrivateStore();
			th2dPixelClusEndcapA->releasePrivateStore();
		}
	}
	
	return sc;
}
//Works fine
StatusCode HLTMinBiasMonTool::fillHMTVertexCountsInfo()
{
    StatusCode sc = StatusCode::SUCCESS;
    
    //const xAOD::TrigVertexCounts* trigVertexCounts = nullptr;
	const xAOD::TrigVertexCountsContainer* vcCont = nullptr;
    sc = m_storeGate->retrieve(vcCont, m_vcContainerName);

    if (sc.isFailure() || !vcCont) {
		if (sc.isFailure())
			(*m_log) << MSG::WARNING << "Failed to retrieve TrigVertexCountsMonTool for xAOD::TrigVertexCounts" << endreq;
		else
			(*m_log) << MSG::DEBUG << "xAOD::TrigVertexCounts is empty." << endreq;
    } else {
		(*m_log) << MSG::DEBUG << " ====== START TrigVertexCountsMonTool for xAOD::TrigVertexCounts ====== " << endreq;
		
		xAOD::TrigVertexCountsContainer::const_iterator vc_coll_itr = vcCont->begin();
		xAOD::TrigVertexCountsContainer::const_iterator vc_coll_itrE = vcCont->end();
		
		for (; vc_coll_itr != vc_coll_itrE; ++vc_coll_itr) 
		{
			xAOD::TrigVertexCounts *trigVertexCounts = (*vc_coll_itr);
		
			// Get the number of tracks per vertex
			std::vector<unsigned int> vtxNtrks = trigVertexCounts->vtxNtrks();
			unsigned int nvtx = vtxNtrks.size();
						
			hist("numVertices")->Fill(nvtx);
			for (const auto &i: vtxNtrks)
			{
				hist("numTracksAtVertex")->Fill(i);
			}
		}
    }
    return sc;
}
	
StatusCode HLTMinBiasMonTool::fillHMTTrigVertexCollectionInfo()
{
	StatusCode sc = StatusCode::SUCCESS;
	
	const TrigVertexCollection* vertexCollection = nullptr;
	sc = m_storeGate->retrieve(vertexCollection, m_vcolContainerName);
	
	if (sc.isFailure() || vertexCollection->empty()) {
		if (sc.isFailure())
			(*m_log) << MSG::WARNING << "Failed to retrieve VertexCollectionMonTool for TrigVertexCollection" << endreq;
		else
			(*m_log) << MSG::DEBUG << "TrigVertexCollection is empty." << endreq;
	} else {
		(*m_log) << MSG::DEBUG << " ====== START VertexCollectionMonTool for TrigVertexCollection ====== " << endreq;
		
		for( /*const auto &i: vertexCollection*/TrigVertexCollection::const_iterator vtxIt = vertexCollection->begin(); vtxIt != vertexCollection->end(); ++vtxIt)
		{
			hist("numHitsAtVertex")->Fill((*vtxIt)->z() );
			//m_vertexWeight.push_back( (*vtxIt)->z() );
			//if ( (*vtxIt)->z() > m_vertexWeightMax ) m_vertexWeightMax = (*vtxIt)->z(); //looking for the biggest weight
			//if ( (*vtxIt)->z() > -999. && (*vtxIt)->z() > m_weightThreshold ) nVertices++;
		}
	}
	
	return sc;
}


/*---------------------------------------------------------*/
HLTMinBiasMonTool::~HLTMinBiasMonTool()
/*---------------------------------------------------------*/
{
	if (m_log)
		delete m_log;
}

void HLTMinBiasMonTool::fixXaxis(TH1* h) {

	for (unsigned int i = 0; i < m_moduleLabel.size(); i++) {
		const char* cell_name = (m_moduleLabel[i]).data();
		h->GetXaxis()->FindBin(cell_name);
	}
	h->ResetBit(TH1::kCanRebin);

	return;
}

int HLTMinBiasMonTool::error_bit(bool a, bool b) {

	if (a == b)
		return 0;
	else
		return 1;

}

#ifdef ManagedMonitorToolBase_Uses_API_201401
StatusCode HLTMinBiasMonTool::proc()
#else
StatusCode HLTMinBiasMonTool::proc(bool endOfEventsBlock, bool endOfLumiBlock, bool endOfRun)
#endif
{
	StatusCode sc = StatusCode::SUCCESS;
	
	if (endOfRun)
	{
		hist("TriggerPurities", "HLT/MinBiasMon")->Divide(hist("TriggerPuritiesPassed", "HLT/MinBiasMon"), hist("TriggerPuritiesAll", "HLT/MinBiasMon"), 1.0, 1.0, "B");
		
		hist("TriggerEfficiencies", "HLT/MinBiasMon")->Divide(hist("TriggerEfficienciesPassed", "HLT/MinBiasMon"), hist("TriggerEfficienciesAll", "HLT/MinBiasMon"), 1.0, 1.0, "B");
		
		
		for (const auto &i: m_trigItems)
		{
			hist("Purity", "HLT/MinBiasMon/Purities&Efficiencies/" + i)->Divide(hist("PurityPassed", "HLT/MinBiasMon/Purities&Efficiencies/" + i), hist("PurityAll", "HLT/MinBiasMon/Purities&Efficiencies/" + i), 1.0, 1.0, "B");
			
			hist("Efficiency", "HLT/MinBiasMon/Purities&Efficiencies/" + i)->Divide(hist("EfficiencyPassed", "HLT/MinBiasMon/Purities&Efficiencies/" + i), hist("EfficiencyAll", "HLT/MinBiasMon/Purities&Efficiencies/" + i), 1.0, 1.0, "B");
			hist("EfficiencyTracks", "HLT/MinBiasMon/Purities&Efficiencies/" + i)->Divide(hist("EfficiencyTracksPassed", "HLT/MinBiasMon/Purities&Efficiencies/" + i), hist("EfficiencyTracksAll", "HLT/MinBiasMon/Purities&Efficiencies/" + i), 1.0, 1.0, "B");
		}
	}
	
	return sc;
}

/*---------------------------------------------------------*/

//StatusCode HLTMinBiasMonTool::procHistograms(bool isEndOfEventsBlock, bool isEndOfLumiBlock, bool isEndOfRun) 

/*---------------------------------------------------------*/
/*{
       if (isEndOfEventsBlock || isEndOfLumiBlock) {}
       if (isEndOfRun) {
	   
				hist("TriggerPurities", "HLT/MinBiasMon")->Divide(hist("TriggerAllTracks", "HLT/MinBiasMon"), hist("TriggerTracksPassed", "HLT/MinBiasMon"), 1.0, 1.0, "B");

				cout << " m_numberOfEvents: " << m_numberOfEvents << " events " << endreq;

                msg(MSG::DEBUG) << " m_numberOfEvents: " << m_numberOfEvents << endreq;
              
               // Track efficiency (EF)
               TH1D *SumTrk=(TH1D*)h_mbSpTrk_trkTot_P->Clone(); 
               SumTrk->Add(h_mbSpTrk_trkTot_P,h_mbSpTrk_trkTot_F);
               h_mbSpTrk_trkTot_Eff->Divide(h_mbSpTrk_trkTot_P,SumTrk,1.,1.,"B");

               // Pixel Space Points efficiency (L2)
               TH1D *SumPix=(TH1D*)h_mbSpTrk_pixTot_P->Clone(); 
               SumPix->Add(h_mbSpTrk_pixTot_P,h_mbSpTrk_pixTot_F);
               h_mbSpTrk_pixTot_Eff->Divide(h_mbSpTrk_pixTot_P,SumPix,1.,1.,"B");

               // SCT Space Points efficiency (L2)
               TH1D *SumSCT=(TH1D*)h_mbSpTrk_sctTot_P->Clone(); 
               SumSCT->Add(h_mbSpTrk_sctTot_P,h_mbSpTrk_sctTot_F);
               h_mbSpTrk_sctTot_Eff->Divide(h_mbSpTrk_sctTot_P,SumSCT,1.,1.,"B");

               // Timing efficiency (L2)
               m_h_time_L2_Eff->Divide(m_h_time_L2_P,m_h_time_1d,1.,1.,"B");

               // Energy efficiency (L2)
               m_h_energy_L2_Eff->Divide(m_h_energy_L2_P,m_h_energy_1d,1.,1.,"B");
			   

       }
   
       return StatusCode::SUCCESS;
}*/
