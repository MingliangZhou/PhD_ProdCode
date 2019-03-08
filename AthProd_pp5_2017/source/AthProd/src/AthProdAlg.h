#ifndef ATHPROD_ATHPRODALG_H
#define ATHPROD_ATHPRODALG_H 1

#include "AthAnalysisBaseComps/AthAnalysisAlgorithm.h"
#include "AsgTools/AnaToolHandle.h"
#include "TrigDecisionTool/TrigDecisionTool.h"
#include "xAODEventInfo/EventInfo.h"
#include "xAODHIEvent/HIEventShapeContainer.h"
#include "xAODTracking/VertexContainer.h"
#include "xAODTracking/TrackParticleContainer.h"
#include "xAODMissingET/MissingETContainer.h"

//Example ROOT Includes
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TProfile.h"
#include "TRandom.h"
#include "TFile.h"
#include "TComplex.h"
#include "TMath.h"

const int maxNtrk = 1000;
const int nTrig = 17;
const double minPt = 0.3;
const double maxPt = 25.;
const double cutEta = 2.5;

class AthProdAlg: public ::AthAnalysisAlgorithm { 
 public: 
  AthProdAlg( const std::string& name, ISvcLocator* pSvcLocator );
  virtual ~AthProdAlg(); 
  virtual StatusCode  initialize();     //once, before any input is loaded
  virtual StatusCode  beginInputFile(); //start of each input file, only metadata loaded
  virtual StatusCode  execute();        //per event
  virtual StatusCode  finalize();       //once, after all events processed

 private:
 	TTree* m_treeOut;
	unsigned int m_runNo;
	unsigned int m_lbNo;
	unsigned int m_bcid;
	double m_trigPS[nTrig];
	double m_fcalEt;
	double m_fcalEtA;
	double m_fcalEtC;
	double m_zPriVtx;
	unsigned int m_nTrk;
	unsigned int m_infoTrk[maxNtrk];

	asg::AnaToolHandle<Trig::TrigDecisionTool> m_TDT;
	// pp13 2018
	const std::string nameTrig[nTrig] =
	{
		"HLT_mb_sptrk",																// 00
		"HLT_mb_sp1200_trk80_hmt_L1TE20",							// 01
		"HLT_mb_sp1400_trk90_hmt_L1TE30",							// 02
		"HLT_mb_sp1600_trk100_hmt_L1TE40",						// 03
		"HLT_mb_sp1700_trk110_hmt_L1TE50",						// 04
		"HLT_mb_sp1200_pusup500_trk80_hmt_L1TE20",		// 05
		"HLT_mb_sp1400_pusup550_trk90_hmt_L1TE30",		// 06
		"HLT_mb_sp1600_pusup600_trk100_hmt_L1TE40",		// 07
		"HLT_mb_sp1700_pusup650_trk110_hmt_L1TE50",		// 08
		"HLT_mb_sp1200_trk80_hmt_L1TE20",							// 09
		"HLT_mb_sp1400_trk90_hmt_L1TE30",							// 10
		"HLT_mb_sp1700_trk110_hmt_L1TE40",						// 11
		"HLT_mb_sp1900_trk120_hmt_L1TE50",						// 12
		"HLT_mb_sp1200_pusup500_trk80_hmt_L1TE20",		// 13
		"HLT_mb_sp1400_pusup550_trk90_hmt_L1TE30",		// 14
		"HLT_mb_sp1700_pusup650_trk110_hmt_L1TE40",		// 15
		"HLT_mb_sp1900_pusup700_trk120_hmt_L1TE50",		// 16
	};
/*	// pp13 2017
	const std::string nameTrig[nTrig] =
	{
		"HLT_mb_sptrk",														// 00
		"HLT_mb_sp600_trk40_hmt_L1TE10",					// 01
		"HLT_mb_sp700_trk50_hmt_L1TE10",					// 02
		"HLT_mb_sp900_trk60_hmt_L1TE10",					// 03
		"HLT_mb_sp1100_trk70_hmt_L1TE10",					// 04
		"HLT_mb_sp1200_trk80_hmt_L1TE10",					// 05
		"HLT_mb_sp1400_trk90_hmt_L1TE10",					// 06
		"HLT_mb_sp700_trk50_hmt_L1TE20",					// 07
		"HLT_mb_sp900_trk60_hmt_L1TE20",					// 08
		"HLT_mb_sp1100_trk70_hmt_L1TE20",					// 09
		"HLT_mb_sp1200_trk80_hmt_L1TE20",					// 10
		"HLT_mb_sp1400_trk90_hmt_L1TE20",					// 11
		"HLT_mb_sp1600_trk100_hmt_L1TE20",				// 12
		"HLT_mb_sp1100_trk70_hmt_L1TE30",					// 13
		"HLT_mb_sp1200_trk80_hmt_L1TE30",					// 14
		"HLT_mb_sp1400_trk90_hmt_L1TE30",					// 15
		"HLT_mb_sp1600_trk100_hmt_L1TE30",				// 16
		"HLT_mb_sp1700_trk110_hmt_L1TE30",				// 17
		"HLT_mb_sp1900_trk120_hmt_L1TE30",				// 18
		"HLT_mb_sp1400_trk90_hmt_L1TE40",					// 19
		"HLT_mb_sp1600_trk100_hmt_L1TE40",				// 20
		"HLT_mb_sp1700_trk110_hmt_L1TE40",				// 21
		"HLT_mb_sp1900_trk120_hmt_L1TE40",				// 22
		"HLT_mb_sp2100_trk130_hmt_L1TE40",				// 23
		"HLT_mb_sp2200_trk140_hmt_L1TE40",				// 24
		"HLT_mb_sp1600_trk100_hmt_L1TE50",				// 25
		"HLT_mb_sp1700_trk110_hmt_L1TE50",				// 26
		"HLT_mb_sp1900_trk120_hmt_L1TE50",				// 27
		"HLT_mb_sp2100_trk130_hmt_L1TE50",				// 28
		"HLT_mb_sp2200_trk140_hmt_L1TE50",				// 29
		"HLT_mb_sp2400_trk150_hmt_L1TE50",				// 30
		"HLT_mu4_L1MU4",													// 31
		"HLT_mu4_mb_sp600_trk40_hmt_L1MU4_TE10",	// 32
		"HLT_mu4_mb_sp700_trk50_hmt_L1MU4_TE10",	// 33
		"HLT_mu4_mb_sp900_trk60_hmt_L1MU4_TE10",	// 34
		"HLT_mu4_mb_sp1100_trk70_hmt_L1MU4_TE10",	// 35
		"HLT_mu4_mb_sp1200_trk80_hmt_L1MU4_TE10", // 36
		"HLT_mu4_mb_sp1400_trk90_hmt_L1MU4_TE10",	// 37
		"HLT_mu4_mb_sp1600_trk100_hmt_L1MU4_TE10",// 38
		"HLT_mu4_mb_sp1100_trk70_hmt_L1MU4_TE20",	// 39
		"HLT_mu4_mb_sp1200_trk80_hmt_L1MU4_TE20", // 40
		"HLT_mu4_mb_sp1400_trk90_hmt_L1MU4_TE20", // 41
		"HLT_mu4_mb_sp1600_trk100_hmt_L1MU4_TE20",// 42
		"HLT_mu4_mb_sp1700_trk110_hmt_L1MU4_TE20",// 43
		"HLT_mu4_mb_sp1100_trk70_hmt_L1MU4_TE30",	// 44
		"HLT_mu4_mb_sp1200_trk80_hmt_L1MU4_TE30", // 45
		"HLT_mu4_mb_sp1400_trk90_hmt_L1MU4_TE30",	// 46
		"HLT_mu4_mb_sp1600_trk100_hmt_L1MU4_TE30",// 47
		"HLT_mu4_mb_sp1700_trk110_hmt_L1MU4_TE30",// 48
		"HLT_mu4_mb_sp1200_trk80_hmt_L1MU4_TE40",	// 49
		"HLT_mu4_mb_sp1400_trk90_hmt_L1MU4_TE40",	// 50
		"HLT_mu4_mb_sp1600_trk100_hmt_L1MU4_TE40",// 51
		"HLT_mu4_mb_sp1700_trk110_hmt_L1MU4_TE40",// 52
	};
	*/
	/* // pp5 2017
	const std::string nameTrig[nTrig] =
	{
		"HLT_mb_sptrk",
		"HLT_mb_sp600_trk40_hmt_L1TE5",
		"HLT_mb_sp700_trk50_hmt_L1TE5",
		"HLT_mb_sp900_trk60_hmt_L1TE5",
		"HLT_mb_sp700_trk50_hmt_L1TE10",
		"HLT_mb_sp900_trk60_hmt_L1TE10",
		"HLT_mb_sp1100_trk70_hmt_L1TE10",
		"HLT_mb_sp1100_trk70_hmt_L1TE15",
		"HLT_mb_sp1200_trk80_hmt_L1TE15",
		"HLT_mb_sp1400_trk90_hmt_L1TE15",
		"HLT_mb_sp1200_trk80_hmt_L1TE20",
		"HLT_mb_sp1400_trk90_hmt_L1TE20",
		"HLT_mb_sp1600_trk100_hmt_L1TE20",
		"HLT_mb_sp1400_trk90_hmt_L1TE25",
		"HLT_mb_sp1600_trk100_hmt_L1TE25",
		"HLT_mb_sp1700_trk110_hmt_L1TE25",
	};
	*/

	const xAOD::Vertex* vertexParticle(const xAOD::TrackParticle*);

	bool isPassTrackQual(const xAOD::TrackParticle* ptrTrk, float zVtx);

	bool isPassGRL(int, int, int);

	bool isPassErrState(const xAOD::EventInfo*);

	bool isPassTrig();

	unsigned int cvtPt(double);
	unsigned int cvtEta(double);
	unsigned int cvtPhi(double);
	double detPt(unsigned int);
	double detEta(unsigned int);
	double detPhi(unsigned int);
}; 

#endif //> !ATHPROD_ATHPRODALG_H

