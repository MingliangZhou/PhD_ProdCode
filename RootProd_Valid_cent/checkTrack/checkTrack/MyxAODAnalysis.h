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

#include "HIPileupTool/HIPileupTool.h"
#include "HIPileupTool/IHIPileupTool.h"

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
	
				int runNo; //!
				int lbNo; //!
				int bcid; //!
				bool isPassVTE50; //!
				float preScaleVTE50; //!
				bool isPassTE50; //!
				float preScaleTE50; //!
				bool hasPriVtx; //!
				float zPriVtx; //!
				float fcalEtA; //!
				float fcalEtC; //!
				bool isPassGap; //!
				bool isPassPileUp; //!

				float mbtsTimeA; //!
				float mbtsTimeC; //!
				float gapA; //!
				float gapC; //!

				int tagGRL; //!
				int tagError; //!

				ULong64_t evtNo; //!
				float xVtx[2]; //!
				float yVtx[2]; //!
				float zVtx[2]; //!
				int typeVtx[2]; //!
				int nTrk; //!
				float d0trk[20000]; //!
				float z0trk[20000]; //!

				HIPileupTool* puTool; //!

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
