// AthProd includes
#include "AthProdAlg.h"

AthProdAlg::AthProdAlg( const std::string& name, ISvcLocator* pSvcLocator ) : AthAnalysisAlgorithm( name, pSvcLocator )
{
}

AthProdAlg::~AthProdAlg()
{
}

StatusCode AthProdAlg::initialize()
{
  ATH_MSG_INFO ("Initializing " << name() << "...");

	// initialize trigger dicision tool
	m_TDT.setTypeAndName("Trig::TrigDecisionTool/TrigDecisionTool");
	CHECK(m_TDT.initialize() );

	// initialize the tree
	m_treeOut = new TTree("tree","13 TeV pp 2017");
	CHECK(histSvc()->regTree("/MYSTREAM/tree",m_treeOut));
	m_treeOut->Branch("runNo",           &m_runNo,           "runNo/i");
	m_treeOut->Branch("lbNo",            &m_lbNo,            "lbNo/i");
	m_treeOut->Branch("bcid",            &m_bcid,            "bcid/i");
	m_treeOut->Branch("trigPS",          m_trigPS,           "trigPS[53]/D");
	m_treeOut->Branch("fcalEt",          &m_fcalEt,          "fcalEt/D");
	m_treeOut->Branch("zPriVtx",         &m_zPriVtx,         "zPriVtx/D");
	m_treeOut->Branch("nTrk",            &m_nTrk,            "nTrk/i");
	m_treeOut->Branch("infoTrk",         m_infoTrk,          "infoTrk[nTrk]/i");

  return StatusCode::SUCCESS;
}

StatusCode AthProdAlg::finalize()
{
  ATH_MSG_INFO ("Finalizing " << name() << "...");

  return StatusCode::SUCCESS;
}

StatusCode AthProdAlg::execute()
{  
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

	if(!isPassGRL(m_runNo, m_lbNo, m_bcid)) return StatusCode::SUCCESS;

	if(!isPassErrState(ptrEvt)) return StatusCode::SUCCESS;

	if(!isPassTrig()) return StatusCode::SUCCESS;

	// FCal E_T from event shape container
	///*
	m_fcalEtA = 0;
	m_fcalEtC = 0;
	const xAOD::HIEventShapeContainer *ptrEvtShpCon = 0;
	CHECK(evtStore()->retrieve(ptrEvtShpCon,"HIEventShape"));
	for(const auto* ptrEvtShp : *ptrEvtShpCon)
	{
		if(ptrEvtShp->layer()!=21 && ptrEvtShp->layer()!=22 && ptrEvtShp->layer()!=23) continue;
		if((ptrEvtShp->etaMin()+ptrEvtShp->etaMax())/2>0) m_fcalEtA += ptrEvtShp->et()/1E6;
		if((ptrEvtShp->etaMin()+ptrEvtShp->etaMax())/2<0) m_fcalEtC += ptrEvtShp->et()/1E6;
	}
	//*/

	// FCal E_T from missing E_T container
	m_fcalEt = 0;
	const xAOD::MissingETContainer *ptrMetCon = 0;
	CHECK(evtStore()->retrieve(ptrMetCon,"MET_Calo"));
	for(const auto *ptrMet : *ptrMetCon)
	{
		if(ptrMet->name()=="FCAL") m_fcalEt += ptrMet->sumet()/1E6;
	}

	// Primary vertex
	m_zPriVtx = 999;
	const xAOD::VertexContainer *ptrRecVtxCon = 0;
	CHECK(evtStore()->retrieve(ptrRecVtxCon,"PrimaryVertices"));
	for(const auto ptrRecVtx : *ptrRecVtxCon)
	{
		if(ptrRecVtx->vertexType() == xAOD::VxType::PriVtx)
		{
			m_zPriVtx = ptrRecVtx->z();
			break;
		}
	}

	// Tracking
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
	const xAOD::Vertex *ptrVtx = 0;
	const xAOD::TrackParticleContainer *ptrRecTrkCon = 0;
	CHECK(evtStore()->retrieve(ptrRecTrkCon,"InDetTrackParticles"));
	for(const auto* ptrRecTrk : *ptrRecTrkCon)
	{
		if(!isPassTrackQual(ptrRecTrk, m_zPriVtx)) continue;
		// only for pp reconstruction
		ptrVtx = vertexParticle(ptrRecTrk);
		if(!ptrVtx) continue;
		else if(fabs(ptrVtx->z()-m_zPriVtx)>0.0001) continue;
		//

		if(ptrRecTrk->charge()>0) trkChg = 1;
		else if(ptrRecTrk->charge()<0) trkChg = 0;
		if(fabs(sin(ptrRecTrk->theta())*(ptrRecTrk->z0()+ptrRecTrk->vz()-m_zPriVtx))<1.0 && fabs(ptrRecTrk->d0())<1.0) trkQual = 1;
		else trkQual = 0;
		trkPt = cvtPt(ptrRecTrk->pt());
		trkEta = cvtEta(ptrRecTrk->eta());
		trkPhi = cvtPhi(ptrRecTrk->phi());

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

	m_treeOut->Fill();

  setFilterPassed(true); //if got here, assume that means algorithm passed
  return StatusCode::SUCCESS;
}

StatusCode AthProdAlg::beginInputFile()
{ 
  return StatusCode::SUCCESS;
}

bool AthProdAlg::isPassGRL(int runNo, int lbNo, int bcid)
{
	return true;
	/* // pp 13 2017
	if(runNo==341294 && lbNo>= 152 && lbNo<= 248) return true;
	if(runNo==341312 && lbNo>= 150 && lbNo<= 758) return true;
	if(runNo==341419 && lbNo>= 116 && lbNo<=1140) return true;
	if(runNo==341534 && lbNo>=  73 && lbNo<=1716) return true;
	if(runNo==341534 && lbNo>=1743 && lbNo<=1812) return true;
	if(runNo==341615 && lbNo>= 106 && lbNo<=1162) return true;
	if(runNo==341649 && lbNo>= 106 && lbNo<= 625) return true;
	*/
	/* // pp5 2017
	if(lbNo>=208  && lbNo<=1315) return true;
	if(lbNo>=1327 && lbNo<=1713) return true;
	if(lbNo>=1725 && lbNo<=2439) return true;
	*/
	return false;
}

bool AthProdAlg::isPassErrState(const xAOD::EventInfo* evtInfo)
{ 
	if(evtInfo->errorState(xAOD::EventInfo::LAr)==xAOD::EventInfo::Error) return false;
	if(evtInfo->errorState(xAOD::EventInfo::Tile)==xAOD::EventInfo::Error) return false;
	if(evtInfo->errorState(xAOD::EventInfo::SCT)==xAOD::EventInfo::Error) return false;
	if(evtInfo->isEventFlagBitSet(xAOD::EventInfo::Core, 18)) return false;
	return true;
}

bool AthProdAlg::isPassTrig()
{
	bool isPass = false;
	for(int iT=0; iT<nTrig; iT++)
	{
		m_trigPS[iT] = 0;
		if(m_TDT->isPassed(nameTrig[iT].c_str()))
		{
			m_trigPS[iT] = m_TDT->getChainGroup(nameTrig[iT].c_str())->getPrescale();
			isPass = true;
		}
	}
	return isPass;
}

const xAOD::Vertex* AthProdAlg::vertexParticle(const xAOD::TrackParticle* ptrTrk)
{
	typedef ElementLink<xAOD::VertexContainer> Link_t;
	static const char* NAME = "vertexLink";
	if(!ptrTrk->isAvailable<Link_t>(NAME)) return 0;
	const Link_t& link = ptrTrk->auxdata<Link_t>(NAME);
	if(!link.isValid()) return 0;
	return *link;
}

bool AthProdAlg::isPassTrackQual(const xAOD::TrackParticle* ptrTrk, float zVtx)
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
	if(!(ptrTrk->pt()/1000.<10 || TMath::Prob(ptrTrk->chiSquared(),ptrTrk->numberDoF())>0.01)) return false;
	if(fabs(sin(ptrTrk->theta())*(ptrTrk->z0()+ptrTrk->vz()-zVtx))>=1.5) return false;
	if(fabs(ptrTrk->d0())>=1.5) return false;
	if(fabs(ptrTrk->eta())>=cutEta) return false;
	if(ptrTrk->pt()/1E3<minPt || ptrTrk->pt()/1E3>maxPt) return false;
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
