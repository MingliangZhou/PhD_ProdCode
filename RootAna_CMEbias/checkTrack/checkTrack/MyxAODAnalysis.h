#ifndef checkTrack_MyxAODAnalysis_H
#define checkTrack_MyxAODAnalysis_H

#include <EventLoop/Algorithm.h>

// include files for using the trigger tools
#include "TrigConfxAOD/xAODConfigTool.h"
#include "TrigDecisionTool/TrigDecisionTool.h"

#include "xAODRootAccess/Init.h"
#include "xAODRootAccess/TEvent.h"

#include "xAODTracking/TrackParticleContainer.h"
#include "xAODTracking/VertexContainer.h"

#include "TH1.h"
#include "TH2.h"
#include "TProfile.h"
#include "TFile.h"
#include "TTree.h"

class MyxAODAnalysis : public EL::Algorithm
{
    // put your configuration variables here as public variables.
    // that way they can be set directly from CINT and python.
    public:
        // trigger tools member variables
        Trig::TrigDecisionTool *m_trigDecisionTool; //!
        TrigConf::xAODConfigTool *m_trigConfigTool; //!

				const xAOD::Vertex *vertexParticle(const xAOD::TrackParticle*);

        xAOD::TEvent *m_event;  //!

        int m_eventCounter; //!
        unsigned int eventID; //!

        TFile *fout; //!
				TTree *tree; //!

				TH2F* hForeAll[50][10][5][5]; //!
				TH2F* hForePos[50][10][5][5]; //!
				TH2F* hForeNeg[50][10][5][5]; //!
				TH2F* hMixdAll[50][10][5][5]; //!
				TH2F* hMixdPos[50][10][5][5]; //!
				TH2F* hMixdNeg[50][10][5][5]; //!

				TH2F* hEtaAchgAll; //!
				TH2F* hEtaAchgPos; //!
				TH2F* hEtaAchgNeg; //!
				TH2F* hPtAchgAll; //!
				TH2F* hPtAchgPos; //!
				TH2F* hPtAchgNeg; //!
				TH2F* hPtAchgAllCnt; //!
				TH2F* hPtAchgPosCnt; //!
				TH2F* hPtAchgNegCnt; //!

				int tagEta; //!
				int tagPhi; //!
				char nameTrig[100]; //!

				std::vector<float> mixWeiAll; //!
				std::vector<float> mixWeiPos; //!
				std::vector<float> mixWeiNeg; //!
				std::vector<float> mixEtaAll; //!
				std::vector<float> mixEtaPos; //!
				std::vector<float> mixEtaNeg; //!
				std::vector<float> mixPhiAll; //!
				std::vector<float> mixPhiPos; //!
				std::vector<float> mixPhiNeg; //!
				std::vector< std::vector<float> > poolWeiAll[50][10]; //!
				std::vector< std::vector<float> > poolWeiPos[50][10]; //!
				std::vector< std::vector<float> > poolWeiNeg[50][10]; //!
				std::vector< std::vector<float> > poolEtaAll[50][10]; //!
				std::vector< std::vector<float> > poolEtaPos[50][10]; //!
				std::vector< std::vector<float> > poolEtaNeg[50][10]; //!
				std::vector< std::vector<float> > poolPhiAll[50][10]; //!
				std::vector< std::vector<float> > poolPhiPos[50][10]; //!
				std::vector< std::vector<float> > poolPhiNeg[50][10]; //!

				int RunNo; //!
				int LbNo; //!
				int Bcid; //!
				float Trigger[7]; //!
				float VtxZ; //!
				float FcalA; //!
				float FcalC; //!
				float QxA[3]; //!
				float QxC[3]; //!
				float QyA[3]; //!
				float QyC[3]; //!
				int MbtsHitA; //!
				int MbtsHitC; //!
				float MbtsTimeA; //!
				float MbtsTimeC; //!
				float GapA; //!
				float GapC; //!
				float ZdcA; //!
				float ZdcC; //!
				int Topo; //!
				int TopoEta[50]; //!
				float TrkRef; //!
				float TrkEff; //!
				float TrkAll; //!
				float TrkPos; //!
				float TrkNeg; //!
				float TrkDeltaEtaAll[50]; //!
				float TrkDeltaEtaPos[50]; //!
				float TrkDeltaEtaNeg[50]; //!
				float TrkDeltaPhiAll[50]; //!
				float TrkDeltaPhiPos[50]; //!
				float TrkDeltaPhiNeg[50]; //!
				float TrkDeltaEtaAllMix[50]; //!
				float TrkDeltaEtaPosMix[50]; //!
				float TrkDeltaEtaNegMix[50]; //!
				float TrkDeltaPhiAllMix[50]; //!
				float TrkDeltaPhiPosMix[50]; //!
				float TrkDeltaPhiNegMix[50]; //!

    public:
        // Tree *myTree; //!
        // TH1 *myHist; //!



        // this is a standard constructor
        MyxAODAnalysis ();

        // these are the functions inherited from Algorithm
        virtual EL::StatusCode setupJob (EL::Job& job);
        virtual EL::StatusCode fileExecute ();
        virtual EL::StatusCode histInitialize ();
        virtual EL::StatusCode changeInput (bool firstFile);
        virtual EL::StatusCode initialize ();
        virtual EL::StatusCode execute ();
        virtual EL::StatusCode postExecute ();
        virtual EL::StatusCode finalize ();
        virtual EL::StatusCode histFinalize ();

        // this is needed to distribute the algorithm to the workers
        ClassDef(MyxAODAnalysis, 1);
};

#endif
