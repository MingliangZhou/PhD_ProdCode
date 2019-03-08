#ifndef ANACUMU_ANACUMUALG_H
#define ANACUMU_ANACUMUALG_H 1

#include "AthAnalysisBaseComps/AthAnalysisAlgorithm.h"
#include "AsgTools/AnaToolHandle.h"
#include "TrigDecisionTool/TrigDecisionTool.h"
#include "xAODEventInfo/EventInfo.h"
#include "xAODHIEvent/HIEventShapeContainer.h"
#include "xAODTracking/VertexContainer.h"
#include "xAODTracking/TrackParticleContainer.h"

//Example ROOT Includes
#include "TH1.h"
#include "TH2.h"
#include "TProfile.h"
#include "TRandom.h"
#include "TFile.h"
#include "TComplex.h"
#include "TMath.h"

const double centCut[80] = {
0.063719, 0.06956, 0.075838, 0.082548, 0.089723, 0.097388, 0.105619, 0.114352, 0.123657, 0.133573,
0.14414, 0.155307, 0.167193, 0.179776, 0.193096, 0.207148, 0.22199, 0.237615, 0.25407, 0.27137,
0.289595, 0.308686, 0.328744, 0.349697, 0.371561, 0.394518, 0.418573, 0.443549, 0.46959, 0.49675,
0.525092, 0.554569, 0.585275, 0.617108, 0.65018, 0.684377, 0.719896, 0.756791, 0.795018, 0.834538,
0.87541, 0.917795, 0.961609, 1.0068, 1.05367, 1.10211, 1.15214, 1.20373, 1.25693, 1.31197, 1.36875,
1.42719, 1.48744, 1.55005, 1.61434, 1.68058, 1.74932, 1.81997, 1.89316, 1.96859, 2.04651, 2.12711,
2.21002, 2.29572, 2.38468, 2.47658, 2.57162, 2.66999, 2.77237, 2.87864, 2.98931, 3.10407, 3.22397,
3.34945, 3.48077, 3.61844, 3.7635, 3.91763, 4.08137, 4.26258};

class AnaCumuAlg: public ::AthAnalysisAlgorithm { 
	public: 
		AnaCumuAlg( const std::string& name, ISvcLocator* pSvcLocator );
		virtual ~AnaCumuAlg(); 

		virtual StatusCode  initialize();     //once, before any input is loaded
		virtual StatusCode  beginInputFile(); //start of each input file, only metadata loaded
		//virtual StatusCode  firstExecute();   //once, after first eventdata is loaded (not per file)
		virtual StatusCode  execute();        //per event
		//virtual StatusCode  endInputFile();   //end of each input file
		//virtual StatusCode  metaDataStop();   //when outputMetaStore is populated by MetaDataTools
		virtual StatusCode  finalize();       //once, after all events processed


		///Other useful methods provided by base class are:
		///evtStore()        : ServiceHandle to main event data storegate
		///inputMetaStore()  : ServiceHandle to input metadata storegate
		///outputMetaStore() : ServiceHandle to output metadata storegate
		///histSvc()         : ServiceHandle to output ROOT service (writing TObjects)
		///currentFile()     : TFile* to the currently open input file
		///retrieveMetadata(...): See twiki.cern.ch/twiki/bin/view/AtlasProtected/AthAnalysisBase#ReadingMetaDataInCpp


	private: 
		TH1D* m_mon_fcalEt;
		TH1D* m_mon_zPriVtx;
		TH1D* m_mon_nTrk;
		TH1D* m_mon_trkPt;
		TH1D* m_mon_trkEta;
		TH1D* m_mon_trkPhi;
		TH2D* m_mon_nTrk_fcalEt;

		double etaCut = 2.5;
		double etaGap = 0;
		const static int NV = 5;
		const static int NVm = 13;
		const static int NP = 7;
		double pTmin[NP] = {0.5, 0.7, 1.0, 1.2, 1.5, 1.7, 2.0};
		double pTmax[NP] = {5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0};
		const static int NW = 7;
		const static int NA = 3;
		const static int nBin = 80;
		double minBin = 0;
		double maxBin = 80;
		double nTrk1sub[NP][1][NW]; TComplex Q1sub[NVm][NP][1][NW]; // harmonic | pT | subevt | power of weight
		double nTrk2sub[NP][2][NW]; TComplex Q2sub[NVm][NP][2][NW];
		double nTrk3sub[NP][3][NW]; TComplex Q3sub[NVm][NP][3][NW];
		double nTrk4sub[NP][4][NW]; TComplex Q4sub[NVm][NP][4][NW];
		double evtWght;
		// standard
		TH1D* cnt_1sub[NP]; // save the number of events
		TH1D* c2_1sub_mean[NV][NP]; // mean of <2>_{n|n}
TH1D* c2_1sub_wght[NV][NP]; // weight for <2>_{n|n}
TH1D* c4_1sub_mean[NV][NP]; // mean of <4>_{n,n|n,n}
TH1D* c4_1sub_wght[NV][NP]; // weight of <4>_{n,n|n,n}
TH1D* c6_1sub_mean[NV][NP]; // mean of <6>_{n,n,n|n,n,n}
TH1D* c6_1sub_wght[NV][NP]; // weight of <6>_{n,n,n|n,n,n}
// 2-subevent
TH1D* cnt_2sub[NP]; // save the number of events
TH1D* c2_2sub_mean[NV][NP]; // mean of <2>_{a|b}
TH1D* c2_2sub_wght[NV][NP]; // weight for <2>_{a|b}
TH1D* c4_2sub_mean[NV][NP]; // mean of <4>_{a,a|b,b}
TH1D* c4_2sub_wght[NV][NP]; // weight of <4>_{a,a|b,b}
// 3-subevent
TH1D* cnt_3sub[NA][NP]; // save the number of events
TH1D* c2_1_3sub_mean[NA][NV][NP]; // mean of <2>_{a|b}
TH1D* c2_1_3sub_wght[NA][NV][NP]; // weight for <2>_{a|b}
TH1D* c2_2_3sub_mean[NA][NV][NP]; // mean of <2>_{a|c}
TH1D* c2_2_3sub_wght[NA][NV][NP]; // weight for <2>_{a|c}
TH1D* c4_3sub_mean[NA][NV][NP]; // mean of <4>_{a,a|b,c}
TH1D* c4_3sub_wght[NA][NV][NP]; // weight of <4>_{a,a|b,c}
// 4-subevent
TH1D* cnt_4sub[NA][NP]; // save the number of events
TH1D* c2_1_4sub_mean[NA][NV][NP]; // mean of <2>_{a|c}
TH1D* c2_1_4sub_wght[NA][NV][NP]; // weight for <2>_{a|c}
TH1D* c2_2_4sub_mean[NA][NV][NP]; // mean of <2>_{a|d}
TH1D* c2_2_4sub_wght[NA][NV][NP]; // weight for <2>_{a|d}
TH1D* c2_3_4sub_mean[NA][NV][NP]; // mean of <2>_{b|c}
TH1D* c2_3_4sub_wght[NA][NV][NP]; // weight for <2>_{b|c}
TH1D* c2_4_4sub_mean[NA][NV][NP]; // mean of <2>_{b|d}
TH1D* c2_4_4sub_wght[NA][NV][NP]; // weight for <2>_{b|d}
TH1D* c4_4sub_mean[NA][NV][NP]; // mean of <4>_{a,a|b,c}
TH1D* c4_4sub_wght[NA][NV][NP]; // weight of <4>_{a,a|b,c}

void AnaSubEvtCumu();
StatusCode initHist(TH1D*&, const char*, int iP); // initialize event distribution
StatusCode initHist(TH1D*&, const char*, int iV, int iP); // initialize multi-particle correlation
StatusCode initHistPm(TH1D*&, const char*, int iA, int iP); // initialize event distribution for 3/4 subevents
StatusCode initHistPm(TH1D*&, const char*, int iA, int iV, int iP);
double cal_2PC_1sub(TComplex, double, double);
double cal_4PC_1sub(TComplex, TComplex, TComplex, double, double, double, double);
double cal_6PC_1sub(TComplex, TComplex, TComplex, TComplex, TComplex, TComplex, double, double, double, double, double, double, double, double, double, double, double, double, double);
double cal_2PC_2sub(TComplex, TComplex, double, double);
double cal_4PC_2sub(TComplex, TComplex, TComplex, TComplex, double, double, double, double);
double cal_2PC_3sub(TComplex, TComplex, double, double);
double cal_4PC_3sub(TComplex, TComplex, TComplex, TComplex, double, double, double, double);
double cal_2PC_4sub(TComplex, TComplex, double, double);
double cal_4PC_4sub(TComplex, TComplex, TComplex, TComplex, double, double, double, double);
void swap(double&, double&, double&);
void swap(TComplex&, TComplex&, TComplex&);
void fill_1sub_FG();
void fill_2sub_FG();
void fill_3sub_FG();
void fill_4sub_FG();
void set_Q();
//double evtCls() const { return nTrk1sub[1][0][0]; }
double evtCls() const { return m_centrality; }
int detSubEvt(int numSubEvent, double eta);

const static int nTrkMax = 10000;
int m_runNo;
int m_lbNo;
int m_bcId;
double m_fcalEt;
double m_zPriVtx;
double m_centrality;
int m_nTrk;
double m_trkPt[nTrkMax];
double m_trkEta[nTrkMax];
double m_trkPhi[nTrkMax];

bool isGoodEvent(const xAOD::EventInfo*, double zVtx);

asg::AnaToolHandle<Trig::TrigDecisionTool> m_TDT;
const static int nTrig = 11;
const std::string nameTrig[nTrig] = 
{
	"HLT_noalg_mb_L1TE4",
	"HLT_mb_sptrk_VTE4",
	"HLT_mb_sptrk_L1MBTS_1_VTE4",
	"HLT_mb_sptrk",
	"HLT_mb_sptrk_L1MBTS_1",
	"HLT_mb_mbts_L1MBTS_1",
	"HLT_noalg_mb_L1MBTS_1",
	"HLT_noalg_mb_L1MBTS_2",
	"HLT_mu4_L1MU4",
	"HLT_mb_sp_L1MBTS_1_OVERLAY",
	"HLT_noalg_L1TE20_OVERLAY"
};
bool isPassTrig();

bool isPassErrState(const xAOD::EventInfo*);

const xAOD::Vertex* vertexParticle(const xAOD::TrackParticle*);

bool isPassTrackQual(const xAOD::TrackParticle* ptrTrk, float zVtx);
}; 

#endif //> !ANACUMU_ANACUMUALG_H
