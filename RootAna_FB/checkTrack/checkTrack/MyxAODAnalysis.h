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
	
				int tagEta; //!
				int tagPhi; //!
				char nameTrig[100]; //!

				int RunNo; //!
				int LbNo; //!
				int Bcid; //!
				float Trigger[7]; //!
				float VtxZ; //!
				float FcalA; //!
				float FcalC; //!
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
				float TrkEtaAll[50]; //!
				float TrkEtaPos[50]; //!
				float TrkEtaNeg[50]; //!
				float TrkPhiAll[50]; //!
				float TrkPhiPos[50]; //!
				float TrkPhiNeg[50]; //!
				float TrkEtaAllSelf[50]; //!
				float TrkEtaPosSelf[50]; //!
				float TrkEtaNegSelf[50]; //!
				float TrkPhiAllSelf[50]; //!
				float TrkPhiPosSelf[50]; //!
				float TrkPhiNegSelf[50]; //!

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
