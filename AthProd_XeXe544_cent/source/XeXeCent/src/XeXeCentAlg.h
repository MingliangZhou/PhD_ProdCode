#ifndef XEXECENT_XEXECENTALG_H
#define XEXECENT_XEXECENTALG_H 1

#include "AthAnalysisBaseComps/AthAnalysisAlgorithm.h"
#include "AsgTools/AnaToolHandle.h"
#include "TrigDecisionTool/TrigDecisionTool.h"
#include "xAODEventInfo/EventInfo.h"
#include "xAODHIEvent/HIEventShapeContainer.h"
#include "xAODTracking/VertexContainer.h"
#include "xAODTracking/TrackParticleContainer.h"
#include "xAODCaloEvent/CaloClusterContainer.h"

//Example ROOT Includes
#include "TH1.h"
#include "TH2.h"
#include "TProfile.h"
#include "TRandom.h"
#include "TFile.h"
#include "TComplex.h"
#include "TMath.h"

const unsigned int pairBunch[8] = {10, 190, 370, 550, 1795, 1975, 2155, 2335};
const double topoEtCut[100] = {0.0, 0.0625, 0.0875, 0.1375, 0.1625, 0.1375, 0.1375, 0.1875, 0.2125, 0.2125, 0.2125, 0.2625, 0.2625, 0.2875, 0.3125, 0.3625, 0.4375, 0.7625, 0.6375, 0.5625, 0.7125, 0.6375, 0.6375, 0.6625, 0.6375, 0.1875, 0.7375, 1.6375, 1.5625, 0.8875, 0.8875, 1.0125, 1.3625, 0.7125, 0.7875, 0.4125, 0.2125, 0.2625, 0.3625, 0.2875, 0.3125, 0.3375, 0.3625, 0.3375, 0.3625, 0.4125, 0.4625, 0.4125, 0.4125, 0.3875, 0.4125, 0.4125, 0.3875, 0.3875, 0.3875, 0.3625, 0.3375, 0.3375, 0.3375, 0.3125, 0.2875, 0.2875, 0.2625, 0.2125, 0.3375, 0.7375, 0.5125, 0.8625, 0.7875, 1.5875, 0.5125, 0.6625, 0.6125, 0.3125, 0.6125, 0.6375, 0.6625, 0.6125, 0.5875, 0.8625, 0.8375, 0.4125, 0.4875, 0.4375, 0.3875, 0.3375, 0.3125, 0.2875, 0.2875, 0.2625, 0.2375, 0.2625, 0.2375, 0.2125, 0.1875, 0.1875, 0.1625, 0.1375, 0.0375, 0.0}; // eta (-5,5) 100 bins

class XeXeCentAlg: public ::AthAnalysisAlgorithm
{ 
	public: 
		XeXeCentAlg( const std::string& name, ISvcLocator* pSvcLocator );
		virtual ~XeXeCentAlg(); 

		///uncomment and implement methods as required

		//IS EXECUTED:
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
		TTree* m_tree;
		unsigned int m_runNo;
		unsigned int m_lbNo;
		unsigned int m_bcid;
		bool m_isPassGRL;
		bool m_isPassErrState;
		bool m_isPassPileup;
		bool m_isPassVTE4;
		double m_psVTE4;
		bool m_isPassTE4;
		double m_psTE4;
		double m_fcalEt;
		double m_fcalEtA;
		double m_fcalEtC;
		bool m_hasPriVtx;
		double m_zPriVtx;
		bool m_isPassGap;
		double m_etaGapA;
		double m_etaGapC;
		double m_etaGap;
		unsigned int m_nTrk;
		
		bool m_isPairBunch;

		TH2D* m_cor_eta_sg_pair;
		TH2D* m_cor_eta_sg_unpair;
		TH2D* m_cor_eta_et_pair;
		TH2D* m_cor_eta_et_unpair;

		asg::AnaToolHandle<Trig::TrigDecisionTool> m_TDT;
		const std::string nameTrig[2] = {"HLT_mb_sptrk_L1VTE4","HLT_noalg_mb_L1TE4"};

		bool isPassTrackQual(const xAOD::TrackParticle* ptrTrk, float zPriVtx);
}; 

#endif //> !XEXECENT_XEXECENTALG_H
