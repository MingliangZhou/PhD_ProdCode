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

				float MBTStimeA; //!
				float MBTStimeC; //!
				float MBTStimeDiff; //!
				float MBTScountA; //!
				float MBTScountC; //!
				unsigned int nEt; //!
				float et[1000]; //!
				float etaMin[1000]; //!
				float etaMax[1000]; //!
				float layer[1000]; //!
				float etCos[1000][7]; //!
				float etSin[1000][7]; //!
				unsigned int nCalo; //!
				float etCalo[10000]; //!
				float etaCalo[10000]; //!
				float phiCalo[10000]; //!
				float etCaloRaw[10000]; //!
				float etaCaloRaw[10000]; //!
				float phiCaloRaw[10000]; //!
				float etCaloCal[10000]; //!
				float etaCaloCal[10000]; //!
				float phiCaloCal[10000]; //!
				unsigned int nTopo; //!
				float eTopo[10000]; //!
				float etTopo[10000]; //!
				float etaTopo[10000]; //!
				float phiTopo[10000]; //!
				float sigClus[10000]; //!
				float sigCell[10000]; //!
				float sigSamp[10000]; //!
				float etTopoRaw[10000]; //!
				float etaTopoRaw[10000]; //!
				float phiTopoRaw[10000]; //!
				float etTopoCal[10000]; //!
				float etaTopoCal[10000]; //!
				float phiTopoCal[10000]; //!
				float eLayer[10000][24]; //!
				float etaLayer[10000][24]; //!
				float phiLayer[10000][24]; //!

				unsigned int RunNumber; //!
				unsigned long long EvtNumber; //!
				unsigned int lbn; //!
				unsigned int bcid; //!
				float trig[25]; //!
				float trigL1[25]; //!
				float L1TE; //!
				unsigned int nVtx; //!
				unsigned int trkVtx[50]; //!
				float xVtx[50]; //!
				float yVtx[50]; //!
				float zVtx[50]; //!
				unsigned int nTrk; //!
				unsigned int nTrkOn; //!
				
				float pt[20000]; //!
				float eta[20000]; //!
				float phi[20000]; //!
				float chg[20000]; //!
				float z0[20000]; //!
				float theta[20000]; //!
				float d0[20000]; //!

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
