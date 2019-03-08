// AthProd includes
#include "AthProdAlg.h"

//#include "xAODEventInfo/EventInfo.h"




AthProdAlg::AthProdAlg( const std::string& name, ISvcLocator* pSvcLocator ) : AthAnalysisAlgorithm( name, pSvcLocator )
{
}


AthProdAlg::~AthProdAlg() {}


StatusCode AthProdAlg::initialize() {
	ATH_MSG_INFO ("Initializing " << name() << "...");

	m_TDT.setTypeAndName("Trig::TrigDecisionTool/TrigDecisionTool");
	CHECK(m_TDT.initialize());

	m_tree = new TTree("tree","5.44 TeV Xe+Xe 2017");
	CHECK(histSvc()->regTree("/MYSTREAM/tree",m_tree));
	m_tree->Branch("runNo",           &m_runNo,           "runNo/i");
	m_tree->Branch("lbNo",            &m_lbNo,            "lbNo/i");
	m_tree->Branch("bcid",            &m_bcid,            "bcid/i");
	m_tree->Branch("isPassGRL",       &m_isPassGRL,       "isPassGRL/O");
	m_tree->Branch("isPassErrState",  &m_isPassErrState,  "isPassErrState/O");
	m_tree->Branch("isPassPileup",    &m_isPassPileup,    "isPassPileup/O");
	m_tree->Branch("isPassVTE4",      &m_isPassVTE4,      "isPassVTE4/O");
	m_tree->Branch("psVTE4",          &m_psVTE4,          "psVTE4/D");
	m_tree->Branch("isPassTE4",       &m_isPassTE4,       "isPassTE4/O");
	m_tree->Branch("psTE4",           &m_psTE4,           "psTE4/D");
	m_tree->Branch("fcalEt",          &m_fcalEt,          "fcalEt/D");
	m_tree->Branch("fcalEtA",         &m_fcalEtA,         "fcalEtA/D");
	m_tree->Branch("fcalEtC",         &m_fcalEtC,         "fcalEtC/D");
	m_tree->Branch("hasPriVtx",       &m_hasPriVtx,       "hasPriVtx/O");
	m_tree->Branch("zPriVtx",         &m_zPriVtx,         "zPriVtx/D");
	m_tree->Branch("isPassGap",       &m_isPassGap,       "isPassGap/O");
	m_tree->Branch("etaGap",          &m_etaGap,          "etaGap/D");
	m_tree->Branch("nTrk",            &m_nTrk,            "nTrk/i");
	m_tree->Branch("infoTrk",         m_infoTrk,         "m_infoTrk[nTrk]/i");

  return StatusCode::SUCCESS;
}

StatusCode AthProdAlg::finalize()
{
  ATH_MSG_INFO ("Finalizing " << name() << "...");

  return StatusCode::SUCCESS;
}

StatusCode AthProdAlg::execute() {  
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
	double m_etaGapA = 10;
	double m_etaGapC = 10;
	const xAOD::CaloClusterContainer *ptrTopoCon = 0;
	CHECK(evtStore()->retrieve(ptrTopoCon,"CaloCalTopoClusters"));
	for(const auto *ptrTopo : *ptrTopoCon)
	{ 
		double eta = ptrTopo->eta();
		double sg = ptrTopo->getMomentValue(xAOD::CaloCluster::CELL_SIGNIFICANCE);
		double et = ptrTopo->pt()/1E3;
		int iEta = int((eta+5)*10);
		if(et<topoEtCut[iEta]) continue;
		if(5-eta<m_etaGapA) m_etaGapA = 5-eta;
		if(5+eta<m_etaGapC) m_etaGapC = 5+eta;
	}
	if(m_etaGapA>=m_etaGapC) m_etaGap = m_etaGapA;
	else m_etaGap = m_etaGapC;
	if(m_etaGap<=2.1) m_isPassGap = true;

	// tracking
	double m_nTrkPU = 0; // for pileup rejection cut
	m_nTrk = 0;
	for(int iT=0; iT<maxNtrk; iT++) m_infoTrk[iT] = 0;
	UInt_t trkChg = 0;
	UInt_t trkQual = 0;
	UInt_t trkPt = 0;
	UInt_t trkEta = 0;
	UInt_t trkPhi = 0;
	UInt_t tmpInfo = 0;
	double tmpChg = 0;
	double tmpQual = 0;
	double tmpPt = 0;
	double tmpEta = 0;
	double tmpPhi = 0;
	const xAOD::TrackParticleContainer *ptrRecTrkCon = 0;
	CHECK(evtStore()->retrieve(ptrRecTrkCon,"InDetTrackParticles"));
	for(const auto* ptrRecTrk : *ptrRecTrkCon)
	{
		trkQual = 2;
		if(isPassTrackQual(ptrRecTrk, m_zPriVtx, 0)) trkQual = 0;
		if(isPassTrackQual(ptrRecTrk, m_zPriVtx, 1)) trkQual = 1;
		if(trkQual>1) continue;

		if(ptrRecTrk->pt()/1E3>=0.5) m_nTrkPU ++;

		trkPt = cvtPt(ptrRecTrk->pt());
		trkEta = cvtEta(ptrRecTrk->eta());
		trkPhi = cvtPhi(ptrRecTrk->phi());
		if(ptrRecTrk->charge()<0) trkChg = 0;
		if(ptrRecTrk->charge()>0) trkChg = 1;

		m_infoTrk[m_nTrk] = trkChg;
		m_infoTrk[m_nTrk] <<=  1; m_infoTrk[m_nTrk] |= trkQual;
		m_infoTrk[m_nTrk] <<=  8; m_infoTrk[m_nTrk] |= trkPt;
		m_infoTrk[m_nTrk] <<=  8; m_infoTrk[m_nTrk] |= trkEta;
		m_infoTrk[m_nTrk] <<= 14; m_infoTrk[m_nTrk] |= trkPhi;

		tmpInfo= m_infoTrk[m_nTrk];
		tmpPhi = detPhi(tmpInfo & 0x3fff); tmpInfo >>= 14;
		tmpEta = detEta(tmpInfo & 0xff);   tmpInfo >>= 8;
		tmpPt  = detPt(tmpInfo & 0xff);    tmpInfo >>= 8;
		tmpQual= tmpInfo & 0x1;            tmpInfo >>= 1;
		tmpChg = tmpInfo & 0x1;

		if(fabs(trkChg-tmpChg)>0 || fabs(trkQual-tmpQual)>0 || fabs(ptrRecTrk->pt()/1000-tmpPt)>0.1 || fabs(ptrRecTrk->eta()-tmpEta)>0.01 || fabs(ptrRecTrk->phi()-tmpPhi)>0.001)
		{
			std::cout<<trkChg<<"  |  "<<trkQual<<"  |  "<<ptrRecTrk->pt()/1000<<"  |  "<<ptrRecTrk->eta()<<"  |  "<<ptrRecTrk->phi()<<std::endl;
			std::cout<<tmpChg<<"  |  "<<tmpQual<<"  |  "<<tmpPt<<"  |  "<<tmpEta<<"  |  "<<tmpPhi<<std::endl;
		}


		m_nTrk ++;
	}

	// Pileup
	m_isPassPileup = true;
	if(m_fcalEt>1.5335E-3*m_nTrkPU+0.21047) m_isPassPileup = false;

	m_tree->Fill();

  setFilterPassed(true); //if got here, assume that means algorithm passed
  return StatusCode::SUCCESS;
}

StatusCode AthProdAlg::beginInputFile()
{ 
  return StatusCode::SUCCESS;
}

bool AthProdAlg::isPassTrackQual(const xAOD::TrackParticle* ptrTrk, float zVtx, int iCut)
{
	double cutPix[2] = {1,2};
	double cutSct[2] = {6,8};
	double cutZ0[2] = {1.5,1.0};
	double cutD0[2] = {1.5,1.0};
	if(ptrTrk->auxdata<unsigned char>("numberOfPixelHits")<cutPix[iCut]) return false;
	if(ptrTrk->auxdata<unsigned char>("numberOfSCTHits")<cutSct[iCut]) return false;
	if(iCut!=0)
	{
		if(ptrTrk->auxdata<unsigned char>("numberOfSCTHoles")>1) return false;
		if(ptrTrk->chiSquared()/ptrTrk->numberDoF()>=6) return false; 
	}
	if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfInnermostPixelLayerHits")>=1) ;
	else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")>0 && ptrTrk->auxdata<unsigned char>("numberOfNextToInnermostPixelLayerHits")>=1) ;
	else if(ptrTrk->auxdata<unsigned char>("expectInnermostPixelLayerHit")==0 && ptrTrk->auxdata<unsigned char>("expectNextToInnermostPixelLayerHit")==0) ;
	else return false;
	if(!(ptrTrk->pt()/1000.<10 || TMath::Prob(ptrTrk->chiSquared(),ptrTrk->numberDoF())>0.01)) return false;
	if(fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-zVtx))>=cutZ0[iCut]) return false;
	if(fabs(ptrTrk->d0())>=cutD0[iCut]) return false;
	if(fabs(ptrTrk->eta())>=2.5) return false;
	if(ptrTrk->pt()/1E3<0.2) return false;
	return true;
}

unsigned int AthProdAlg::cvtPt(double pT)
{
	int flagPt = int(pT/100.);
	if(flagPt<0) flagPt = 0;
	if(flagPt>=250) flagPt = 250;
	return flagPt;
}
unsigned int AthProdAlg::cvtEta(double eta)
{
	int flagEta = int((eta+cutEta)/2/cutEta*250);
	if(flagEta<0) flagEta = 0;
	if(flagEta>=250) flagEta = 250;
	return flagEta;
}
unsigned int AthProdAlg::cvtPhi(double phi)
{
	int flagPhi = int((phi+TMath::Pi())/2/TMath::Pi()*pow(2,14));
	if(flagPhi<0) flagPhi = 0;
	if(flagPhi>=pow(2,14)) flagPhi = int(pow(2,14)-1);
	return flagPhi;
}
double AthProdAlg::detPt(unsigned int pt)
{
	return (pt+0.5)/10.;
}
double AthProdAlg::detEta(unsigned int eta)
{
	return (eta+0.5)/250.*2*cutEta-cutEta;
}
double AthProdAlg::detPhi(unsigned int phi)
{
	return (phi+0.5)/pow(2,14)*2*TMath::Pi()-TMath::Pi();
}
