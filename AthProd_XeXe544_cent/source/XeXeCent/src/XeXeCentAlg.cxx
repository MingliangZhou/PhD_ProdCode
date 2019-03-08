// XeXeCent includes
#include "XeXeCentAlg.h"

//#include "xAODEventInfo/EventInfo.h"




XeXeCentAlg::XeXeCentAlg( const std::string& name, ISvcLocator* pSvcLocator ) : AthAnalysisAlgorithm( name, pSvcLocator ){

  //declareProperty( "Property", m_nProperty = 0, "My Example Integer Property" ); //example property declaration

}


XeXeCentAlg::~XeXeCentAlg() {}


StatusCode XeXeCentAlg::initialize()
{
  ATH_MSG_INFO ("Initializing " << name() << "...");

	// initialize trigger dicision tool
	m_TDT.setTypeAndName("Trig::TrigDecisionTool/TrigDecisionTool");
	CHECK(m_TDT.initialize());

	m_tree = new TTree("tree","5.44 TeV Xe+Xe 2017");
	CHECK(histSvc()->regTree("/MYSTREAM/tree",m_tree));
	m_tree->Branch("runNo",						&m_runNo,						"runNo/i");
	m_tree->Branch("lbNo",						&m_lbNo,						"lbNo/i");
	m_tree->Branch("bcid",						&m_bcid,						"bcid/i");
	m_tree->Branch("isPassGRL",				&m_isPassGRL,				"isPassGRL/O");
	m_tree->Branch("isPassErrState",	&m_isPassErrState,	"isPassErrState/O");
	m_tree->Branch("isPassPileup",		&m_isPassPileup,		"isPassPileup/O");
	m_tree->Branch("isPassVTE4",			&m_isPassVTE4,			"isPassVTE4/O");
	m_tree->Branch("psVTE4",					&m_psVTE4,					"psVTE4/D");
	m_tree->Branch("isPassTE4",				&m_isPassTE4,				"isPassTE4/O");
	m_tree->Branch("psTE4",						&m_psTE4,						"psTE4/D");
	m_tree->Branch("fcalEt",					&m_fcalEt,					"fcalEt/D");
	m_tree->Branch("fcalEtA",					&m_fcalEtA,					"fcalEtA/D");
	m_tree->Branch("fcalEtC",					&m_fcalEtC,					"fcalEtC/D");
	m_tree->Branch("hasPriVtx",				&m_hasPriVtx,				"hasPriVtx/O");
	m_tree->Branch("zPriVtx",					&m_zPriVtx,					"zPriVtx/D");
	m_tree->Branch("isPassGap",				&m_isPassGap,				"isPassGap/O");
	m_tree->Branch("etaGap",					&m_etaGap,					"etaGap/D");
	m_tree->Branch("etaGapA",					&m_etaGapA,					"etaGapA/D");
	m_tree->Branch("etaGapC",					&m_etaGapC,					"etaGapC/D");
	m_tree->Branch("nTrk",						&m_nTrk,						"nTrk/i");

	m_cor_eta_sg_pair = new TH2D("cor_eta_sg_pair","",100,-5,5,2000,0,20);
	CHECK(histSvc()->regHist("/MYSTREAM/cor_eta_sg_pair",m_cor_eta_sg_pair));
	m_cor_eta_sg_unpair = new TH2D("cor_eta_sg_unpair","",100,-5,5,2000,0,20);
	CHECK(histSvc()->regHist("/MYSTREAM/cor_eta_sg_unpair",m_cor_eta_sg_unpair));
	m_cor_eta_et_pair = new TH2D("cor_eta_et_pair","",100,-5,5,2000,-10,40);
	CHECK(histSvc()->regHist("/MYSTREAM/cor_eta_et_pair",m_cor_eta_et_pair));
	m_cor_eta_et_unpair = new TH2D("cor_eta_et_unpair","",100,-5,5,2000,-10,40);
	CHECK(histSvc()->regHist("/MYSTREAM/cor_eta_et_unpair",m_cor_eta_et_unpair));

  return StatusCode::SUCCESS;
}

StatusCode XeXeCentAlg::finalize() {
  ATH_MSG_INFO ("Finalizing " << name() << "...");

  return StatusCode::SUCCESS;
}

StatusCode XeXeCentAlg::execute() {  
  ATH_MSG_DEBUG ("Executing " << name() << "...");
  setFilterPassed(false); //optional: start with algorithm not passed

	// event info
	m_runNo = 0;
	m_lbNo = 0;
	m_bcid = 0;
	const xAOD::EventInfo* ptrEvt = 0;
	CHECK(evtStore()->retrieve(ptrEvt,"EventInfo"));
	m_runNo = ptrEvt->runNumber();
	m_lbNo = ptrEvt->lumiBlock();
	m_bcid = ptrEvt->bcid();
	m_isPairBunch = false;
	for(int i=0; i<8; i++)
	{
		if(m_bcid==pairBunch[i])
		{
			m_isPairBunch = true;
			break;
		}
	}

	// GRL
	m_isPassGRL = false;
	if(m_lbNo>=198 && m_lbNo<=565) m_isPassGRL = true;

	// error state
	m_isPassErrState = true;
	if(ptrEvt->errorState(xAOD::EventInfo::LAr)==xAOD::EventInfo::Error) m_isPassErrState = false;
	if(ptrEvt->errorState(xAOD::EventInfo::Tile)==xAOD::EventInfo::Error) m_isPassErrState = false;
	if(ptrEvt->errorState(xAOD::EventInfo::SCT)==xAOD::EventInfo::Error) m_isPassErrState = false;
	if(ptrEvt->isEventFlagBitSet(xAOD::EventInfo::Core, 18)) m_isPassErrState = false;

	// trigger selection
	m_isPassVTE4 = false; m_psVTE4 = -1;
	m_isPassTE4 = false;  m_psTE4 = -1;
	if(m_TDT->isPassed(nameTrig[0].c_str()))
	{
		m_isPassVTE4 = true;
		m_psVTE4 = m_TDT->getChainGroup(nameTrig[0].c_str())->getPrescale();
	}
	if(m_TDT->isPassed(nameTrig[1].c_str()))
	{
		m_isPassTE4 = true;
		m_psTE4 = m_TDT->getChainGroup(nameTrig[1].c_str())->getPrescale();
	}

	// FCal Et
	m_fcalEt = 0;
	m_fcalEtA = 0;
	m_fcalEtC = 0;
	const xAOD::HIEventShapeContainer *ptrEvtShpCon = 0;
	CHECK(evtStore()->retrieve(ptrEvtShpCon,"HIEventShape"));
	for(const auto* ptrEvtShp : *ptrEvtShpCon)
	{
		if(ptrEvtShp->layer()!=21 && ptrEvtShp->layer()!=22 && ptrEvtShp->layer()!=23) continue;
		m_fcalEt += ptrEvtShp->et()/1E6;
		if((ptrEvtShp->etaMin()+ptrEvtShp->etaMax())/2>0) m_fcalEtA += ptrEvtShp->et()/1E6;
		if((ptrEvtShp->etaMin()+ptrEvtShp->etaMax())/2<0) m_fcalEtC += ptrEvtShp->et()/1E6;
	}

	// primary vertex
	m_zPriVtx = 999;
	m_hasPriVtx = false;
	int m_nPriVtx = 0;
	const xAOD::VertexContainer *ptrRecVtxCon = 0;
	CHECK(evtStore()->retrieve(ptrRecVtxCon,"PrimaryVertices"));
	for(const auto ptrRecVtx : *ptrRecVtxCon)
	{ 
		if(ptrRecVtx->vertexType() == xAOD::VxType::PriVtx)
		{ 
			m_hasPriVtx = true;
			m_zPriVtx = ptrRecVtx->z();
			m_nPriVtx ++;
		}
	}
	if(m_nPriVtx>1) m_zPriVtx = 999;

	// Topo clusters
	m_isPassGap = false;
	m_etaGap = 0;
	m_etaGapA = 10;
	m_etaGapC = 10;
	const xAOD::CaloClusterContainer *ptrTopoCon = 0;
	CHECK(evtStore()->retrieve(ptrTopoCon,"CaloCalTopoClusters"));
	for(const auto *ptrTopo : *ptrTopoCon)
	{
		double eta = ptrTopo->eta();
		double sg = ptrTopo->getMomentValue(xAOD::CaloCluster::CELL_SIGNIFICANCE);
		double et = ptrTopo->pt()/1E3;
		//double sg1 = ptrTopo->getMomentValue(xAOD::CaloCluster_v1::MomentType::SIGNIFICANCE);
		//double et = ptrTopo->et()/1E3;

		if(m_isPassGRL && m_isPassErrState)
		{
			if(m_isPairBunch)
			{
				if(m_hasPriVtx && (m_isPassVTE4 || m_isPassTE4))
				{
					m_cor_eta_sg_pair->Fill(eta,sg);
					m_cor_eta_et_pair->Fill(eta,et);
				}
				else {};
			}
			else
			{
				m_cor_eta_sg_unpair->Fill(eta,sg);
				m_cor_eta_et_unpair->Fill(eta,et);
			}
		}
		else {};

		// calculating eta gap
		int iEta = int((eta+5)*10);
		if(et<topoEtCut[iEta]) continue;
		if(5-eta<m_etaGapA) m_etaGapA = 5-eta;
		if(5+eta<m_etaGapC) m_etaGapC = 5+eta;
	}
	if(m_etaGapA>=m_etaGapC) m_etaGap = m_etaGapA;
	else m_etaGap = m_etaGapC;
	if(m_etaGap<=2.1) m_isPassGap = true;

	// tracking
	m_nTrk = 0;
	const xAOD::TrackParticleContainer *ptrRecTrkCon = 0;
	CHECK(evtStore()->retrieve(ptrRecTrkCon,"InDetTrackParticles"));
	for(const auto* ptrRecTrk : *ptrRecTrkCon)
	{
		if(!isPassTrackQual(ptrRecTrk, m_zPriVtx)) continue;
		m_nTrk ++;
	}

	// PileUp cut
	m_isPassPileup = true;
	if(m_fcalEt>1.5335E-3*m_nTrk+0.21047) m_isPassPileup = false;

	m_tree->Fill();

  setFilterPassed(true); //if got here, assume that means algorithm passed
  return StatusCode::SUCCESS;
}

StatusCode XeXeCentAlg::beginInputFile()
{ 
  return StatusCode::SUCCESS;
}

bool XeXeCentAlg::isPassTrackQual(const xAOD::TrackParticle* ptrTrk, float zVtx)
{
	if(ptrTrk->auxdata<unsigned char>("numberOfPixelHits")<1) return false;
	if(ptrTrk->pt()/1000<0.3)
	{
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")+ptrTrk->auxdata<unsigned char>("numberOfSCTDeadSensors")<2) return false;
	}
	else if(ptrTrk->pt()/1000<0.4)
	{
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")+ptrTrk->auxdata<unsigned char>("numberOfSCTDeadSensors")<4) return false;
	}
	else
	{
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")+ptrTrk->auxdata<unsigned char>("numberOfSCTDeadSensors")<6) return false;
	}
	if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfInnermostPixelLayerHits")>=1) ;
	else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfNextToInnermostPixelLayerHits")>=1) ;
	else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")==0) ;
	else return false;
	//if(!(ptrTrk->pt()/1000.<10 || TMath::Prob(ptrTrk->chiSquared(),ptrTrk->numberDoF())>0.01)) return false;
	if(fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-zVtx))>=1.5) return false;
	if(fabs(ptrTrk->d0())>=1.5) return false;
	if(fabs(ptrTrk->eta())>=2.5) return false;
	if(ptrTrk->pt()/1E3<0.5) return false;
	return true;
}


