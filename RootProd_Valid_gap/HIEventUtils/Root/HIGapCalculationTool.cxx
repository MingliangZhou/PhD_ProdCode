// HIGapCalculationTool.cxx

#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>
#include "xAODRootAccess/Init.h"
#include "xAODRootAccess/TEvent.h"
#include "xAODRootAccess/tools/Message.h"

//#include "HIEventUtils/IHIGapCalculationTool.h"
#include "HIEventUtils/HIGapCalculationTool.h"
#include "AsgTools/Check.h"

#include "xAODCaloEvent/CaloClusterContainer.h"
#include "xAODTracking/TrackParticleContainer.h"

const double etCut[50] = {0,0.34,0.48,0.42,0.48,0.28,0.32,0.38,0.6,0.58,0.13,0.17,0.28,0.11,0.14,0.14,0.34,0.39,0.28,0.3,0.3,0.34,0.37,0.38,0.4,0.38,0.37,0.36,0.34,0.32,0.3,0.25,0.26,0.29,0.14,0.12,0.1,0.1,0.16,0.32,0.32,0.48,0.4,0.35,0.34,0.98,0.44,0.31,0.41,0};

HI::HIGapCalculationTool::HIGapCalculationTool(const std::string& myname):AsgTool(myname)
{
	declareProperty("CellSigCut",m_cell_sig_cut,"Cell significance cut");
	declareProperty("PercentageCut",m_percentage_cut,"Percentage suppression on empty bunches");
}

HI::HIGapCalculationTool::~HIGapCalculationTool() = default;

StatusCode HI::HIGapCalculationTool::initialize()
{
	ATH_MSG_INFO("Initializing gap calculation tool.");

	if(m_cell_sig_cut>=4.0) ATH_MSG_INFO("Cell significance cut at "<<m_cell_sig_cut);
	else ATH_MSG_INFO("Not valid cell significance cut, cut should be larger than 4.0");

	if(m_percentage_cut>0 && m_percentage_cut<=1.) ATH_MSG_INFO("Empty bunches suppression cut at "<<m_percentage_cut*100<<"%");
	else ATH_MSG_INFO("Not valid percentage cut, cut should be between 0 and 1");

	return StatusCode::SUCCESS;
}

StatusCode HI::HIGapCalculationTool::finalize()
{
	ATH_MSG_INFO("Finalizing gap calculation tool.");

	return StatusCode::SUCCESS;
}

void HI::HIGapCalculationTool::CalculateGaps(double& gapA, double& gapC)
{
	double etaTopo;
	double sigCell;
	double etTopo;
	gapA = 10;
	gapC = 10;
	const xAOD::CaloClusterContainer *ptrTopoCon = 0;
	evtStore()->retrieve(ptrTopoCon,"CaloCalTopoClusters");
	for(const auto *ptrTopo : *ptrTopoCon)
	{
		etaTopo = ptrTopo->eta();
		etTopo = ptrTopo->et()/1000;
		sigCell = ptrTopo->getMomentValue(xAOD::CaloCluster_v1::CELL_SIGNIFICANCE);
		if(sigCell>=4.5)
		{
			for(int i=0; i<50; i++)
			{
				if(etaTopo<-5+10./50*i || etaTopo>=-5+10./50*(i+1)) continue;
				if(etTopo<etCut[i]) continue;
				if(5+etaTopo<gapC) gapC = 5+etaTopo;
				if(5-etaTopo<gapA) gapA = 5-etaTopo;
			}
		}
	}

	double etaTrk;
	const xAOD::TrackParticleContainer *ptrTrkCon = 0;
	evtStore()->retrieve(ptrTrkCon,"InDetTrackParticles");
	for(const auto *ptrTrk : *ptrTrkCon)
	{
		etaTrk = ptrTrk->eta();
		if(5-etaTrk<gapA) gapA = 5-etaTrk;
		if(5+etaTrk<gapC) gapC = 5+etaTrk;
	}
}

