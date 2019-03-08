// AnaCumu includes
#include "AnaCumuAlg.h"

//#include "xAODEventInfo/EventInfo.h"

AnaCumuAlg::AnaCumuAlg( const std::string& name, ISvcLocator* pSvcLocator ) : AthAnalysisAlgorithm( name, pSvcLocator )
{
	//declareProperty( "Property", m_nProperty = 0, "My Example Integer Property" ); //example property declaration
}

AnaCumuAlg::~AnaCumuAlg()
{
/*
	for(int iP=0; iP<NP; iP++) delete cnt_1sub[iP];
	for(int iV=0; iV<NV; iV++)
	{
		for(int iP=0; iP<NP; iP++)
		{
			delete c2_1sub_mean[iV][iP];
			delete c2_1sub_wght[iV][iP];
			delete c4_1sub_mean[iV][iP];
			delete c4_1sub_wght[iV][iP];
			delete c6_1sub_mean[iV][iP];
			delete c6_1sub_wght[iV][iP];
		}
	}

	for(int iP=0; iP<NP; iP++) delete cnt_2sub[iP];
	for(int iV=0; iV<NV; iV++)
	{
		for(int iP=0; iP<NP; iP++)
		{
			delete c2_2sub_mean[iV][iP];
			delete c2_2sub_wght[iV][iP];
			delete c4_2sub_mean[iV][iP];
			delete c4_2sub_wght[iV][iP];
		}
	}

	for(int iA=0; iA<NA; iA++)
	{
		for(int iP=0; iP<NP; iP++) delete cnt_3sub[iA][iP];
		for(int iV=0; iV<NV; iV++)
		{
			for(int iP=0; iP<NP; iP++)
			{
				delete c2_1_3sub_mean[iA][iV][iP];
				delete c2_1_3sub_wght[iA][iV][iP];
				delete c2_2_3sub_mean[iA][iV][iP];
				delete c2_2_3sub_wght[iA][iV][iP];
				delete c4_3sub_mean[iA][iV][iP];
				delete c4_3sub_wght[iA][iV][iP];
			}
		}
	}

	for(int iA=0; iA<NA; iA++)
	{
		for(int iP=0; iP<NP; iP++) delete cnt_4sub[iA][iP];
		for(int iV=0; iV<NV; iV++)
		{
			for(int iP=0; iP<NP; iP++)
			{
				delete c2_1_4sub_mean[iA][iV][iP];
				delete c2_1_4sub_wght[iA][iV][iP];
				delete c2_2_4sub_mean[iA][iV][iP];
				delete c2_2_4sub_wght[iA][iV][iP];
				delete c2_3_4sub_mean[iA][iV][iP];
				delete c2_3_4sub_wght[iA][iV][iP];
				delete c2_4_4sub_mean[iA][iV][iP];
				delete c2_4_4sub_wght[iA][iV][iP];
				delete c4_4sub_mean[iA][iV][iP];
				delete c4_4sub_wght[iA][iV][iP];
			}
		}
	}
*/
}


StatusCode AnaCumuAlg::initialize()
{
	ATH_MSG_INFO ("Initializing " << name() << "...");

	// initialize trigger dicision tool
	m_TDT.setTypeAndName("Trig::TrigDecisionTool/TrigDecisionTool");
	CHECK(m_TDT.initialize() );

	m_mon_fcalEt = new TH1D("mon_fcalEt","",600,-1,5); CHECK(histSvc()->regHist("/MYSTREAM/mon_fcalEt",m_mon_fcalEt));
	m_mon_zPriVtx = new TH1D("mon_zPriVtx","",400,-200,200); CHECK(histSvc()->regHist("/MYSTREAM/mon_zPriVtx",m_mon_zPriVtx));
	m_mon_nTrk = new TH1D("mon_nTrk","",500,0,5000); CHECK(histSvc()->regHist("/MYSTREAM/mon_nTrk",m_mon_nTrk));
	m_mon_trkPt = new TH1D("mon_trkPt","",300,0,30); CHECK(histSvc()->regHist("/MYSTREAM/mon_trkPt",m_mon_trkPt));
	m_mon_trkEta = new TH1D("mon_trkEta","",100,-2.5,2.5); CHECK(histSvc()->regHist("/MYSTREAM/mon_trkEta",m_mon_trkEta));
	m_mon_trkPhi = new TH1D("mon_trkPhi","",100,-TMath::Pi(),TMath::Pi()); CHECK(histSvc()->regHist("/MYSTREAM/mon_trkPhi",m_mon_trkPhi));
	m_mon_nTrk_fcalEt = new TH2D("mon_nTrk_fcalEt","",500,0,5000,600,-1,5); CHECK(histSvc()->regHist("/MYSTREAM/mon_nTrk_fcalEt",m_mon_nTrk_fcalEt));

	for(int iP=0; iP<NP; iP++) CHECK(initHist(cnt_1sub[iP],"cnt_1sub",iP));
	for(int iV=0; iV<NV; iV++)
	{
		for(int iP=0; iP<NP; iP++)
		{
			CHECK(initHist(c2_1sub_mean[iV][iP],"c2_1sub_mean",iV,iP));
			CHECK(initHist(c2_1sub_wght[iV][iP],"c2_1sub_wght",iV,iP));
			CHECK(initHist(c4_1sub_mean[iV][iP],"c4_1sub_mean",iV,iP));
			CHECK(initHist(c4_1sub_wght[iV][iP],"c4_1sub_wght",iV,iP));
			CHECK(initHist(c6_1sub_mean[iV][iP],"c6_1sub_mean",iV,iP));
			CHECK(initHist(c6_1sub_wght[iV][iP],"c6_1sub_wght",iV,iP));
		}
	}

	for(int iP=0; iP<NP; iP++) CHECK(initHist(cnt_2sub[iP],"cnt_2sub",iP));
	for(int iV=0; iV<NV; iV++)
	{
		for(int iP=0; iP<NP; iP++)
		{
			CHECK(initHist(c2_2sub_mean[iV][iP],"c2_2sub_mean",iV,iP));
			CHECK(initHist(c2_2sub_wght[iV][iP],"c2_2sub_wght",iV,iP));
			CHECK(initHist(c4_2sub_mean[iV][iP],"c4_2sub_mean",iV,iP));
			CHECK(initHist(c4_2sub_wght[iV][iP],"c4_2sub_wght",iV,iP));
		}
	}

	for(int iA=0; iA<NA; iA++)
	{
		for(int iP=0; iP<NP; iP++) CHECK(initHistPm(cnt_3sub[iA][iP],"cnt_3sub",iA,iP));
		for(int iV=0; iV<NV; iV++)
		{
			for(int iP=0; iP<NP; iP++)
			{
				CHECK(initHistPm(c2_1_3sub_mean[iA][iV][iP],"c2_1_3sub_mean",iA,iV,iP));
				CHECK(initHistPm(c2_1_3sub_wght[iA][iV][iP],"c2_1_3sub_wght",iA,iV,iP));
				CHECK(initHistPm(c2_2_3sub_mean[iA][iV][iP],"c2_2_3sub_mean",iA,iV,iP));
				CHECK(initHistPm(c2_2_3sub_wght[iA][iV][iP],"c2_2_3sub_wght",iA,iV,iP));
				CHECK(initHistPm(c4_3sub_mean[iA][iV][iP],"c4_3sub_mean",iA,iV,iP));
				CHECK(initHistPm(c4_3sub_wght[iA][iV][iP],"c4_3sub_wght",iA,iV,iP));
			}
		}
	}


	for(int iA=0; iA<NA; iA++)
	{
		for(int iP=0; iP<NP; iP++) CHECK(initHistPm(cnt_4sub[iA][iP],"cnt_4sub",iA,iP));
		for(int iV=0; iV<NV; iV++)
		{
			for(int iP=0; iP<NP; iP++)
			{
				CHECK(initHistPm(c2_1_4sub_mean[iA][iV][iP],"c2_1_4sub_mean",iA,iV,iP));
				CHECK(initHistPm(c2_1_4sub_wght[iA][iV][iP],"c2_1_4sub_wght",iA,iV,iP));
				CHECK(initHistPm(c2_2_4sub_mean[iA][iV][iP],"c2_2_4sub_mean",iA,iV,iP));
				CHECK(initHistPm(c2_2_4sub_wght[iA][iV][iP],"c2_2_4sub_wght",iA,iV,iP));
				CHECK(initHistPm(c2_3_4sub_mean[iA][iV][iP],"c2_3_4sub_mean",iA,iV,iP));
				CHECK(initHistPm(c2_3_4sub_wght[iA][iV][iP],"c2_3_4sub_wght",iA,iV,iP));
				CHECK(initHistPm(c2_4_4sub_mean[iA][iV][iP],"c2_4_4sub_mean",iA,iV,iP));
				CHECK(initHistPm(c2_4_4sub_wght[iA][iV][iP],"c2_4_4sub_wght",iA,iV,iP));
				CHECK(initHistPm(c4_4sub_mean[iA][iV][iP],"c4_4sub_mean",iA,iV,iP));
				CHECK(initHistPm(c4_4sub_wght[iA][iV][iP],"c4_4sub_wght",iA,iV,iP));
			}
		}
	}

	return StatusCode::SUCCESS;
}

StatusCode AnaCumuAlg::finalize()
{
	ATH_MSG_INFO ("Finalizing " << name() << "...");

	return StatusCode::SUCCESS;
}

StatusCode AnaCumuAlg::execute()
{
	ATH_MSG_DEBUG ("Executing " << name() << "...");
	setFilterPassed(false); //optional: start with algorithm not passed

	const xAOD::EventInfo* ptrEvt = 0;
	CHECK(evtStore()->retrieve(ptrEvt,"EventInfo"));

	m_zPriVtx = 9999;
	const xAOD::VertexContainer *ptrRecVtxCon = 0;
	CHECK(evtStore()->retrieve(ptrRecVtxCon,"PrimaryVertices"));
	for(const auto ptrRecVtx : *ptrRecVtxCon)
	{
		if(ptrRecVtx->vertexType() == xAOD::VxType::PriVtx)
		{
			m_zPriVtx = ptrRecVtx->z();
		}
	}
	m_mon_zPriVtx->Fill(m_zPriVtx);

	if(!isGoodEvent(ptrEvt,m_zPriVtx)) return StatusCode::SUCCESS;

	m_runNo = ptrEvt->runNumber();
	m_lbNo = ptrEvt->lumiBlock();
	m_bcId = ptrEvt->bcid();

	if(m_lbNo<198 || m_lbNo>565) return StatusCode::SUCCESS;

	const xAOD::HIEventShapeContainer *ptrEvtShpCon = 0;
	CHECK(evtStore()->retrieve(ptrEvtShpCon,"HIEventShape"));
	m_fcalEt = 0;
	for(const auto* ptrEvtShp : *ptrEvtShpCon)
	{
		if(ptrEvtShp->layer()<21) continue;
		m_fcalEt += ptrEvtShp->et()/1E6;
	}
	m_mon_fcalEt->Fill(m_fcalEt);

	const xAOD::Vertex *ptrVtx = 0;
	const xAOD::TrackParticleContainer *ptrRecTrkCon = 0;
	CHECK(evtStore()->retrieve(ptrRecTrkCon,"InDetTrackParticles"));
	m_nTrk = 0;
	for(int iT=0; iT<nTrkMax; iT++)
	{
		m_trkPt[iT] = 0;
		m_trkEta[iT] = 0;
		m_trkPhi[iT] = 0;
	}
	for(const auto* ptrRecTrk : *ptrRecTrkCon)
	{
	/* only for pp reconstruction
		ptrVtx = vertexParticle(ptrRecTrk);
		if(!ptrVtx) continue;
		else if(fabs(ptrVtx->z()-m_zPriVtx)>0.0001) continue;
	*/
		if(!isPassTrackQual(ptrRecTrk, m_zPriVtx)) continue;

		m_trkPt[m_nTrk] = ptrRecTrk->pt()/1E3;
		m_trkEta[m_nTrk] = ptrRecTrk->eta();
		m_trkPhi[m_nTrk] = ptrRecTrk->phi();

		m_mon_trkPt->Fill(m_trkPt[m_nTrk]);
		m_mon_trkEta->Fill(m_trkEta[m_nTrk]);
		m_mon_trkPhi->Fill(m_trkPhi[m_nTrk]);

		m_nTrk ++;
	}
	if(1.133*1E-3*m_nTrk+0.15<=m_fcalEt) return StatusCode::SUCCESS; // pileup rejection
	if(4*1E-4*(m_nTrk-2400)+3<=m_fcalEt) return StatusCode::SUCCESS; // pileup rejection
	
	m_mon_nTrk->Fill(m_nTrk);
	m_mon_nTrk_fcalEt->Fill(m_nTrk,m_fcalEt);

	m_centrality = 0;
	for(int i=0; i<80; i++)
	{
		if(m_fcalEt<(centCut[i]*0.65))
		{
			m_centrality = 80-i;
			break;
		}
	}
	//if(m_fcalEt>2) std::cout<<m_fcalEt<<" | "<<m_centrality<<std::endl;

	AnaSubEvtCumu();

	setFilterPassed(true); //if got here, assume that means algorithm passed
	return StatusCode::SUCCESS;
}

StatusCode AnaCumuAlg::beginInputFile()
{
	return StatusCode::SUCCESS;
}

bool AnaCumuAlg::isGoodEvent(const xAOD::EventInfo* evtInfo, double zVtx)
{
	if(!isPassTrig()) return false;
	if(!isPassErrState(evtInfo)) return false;
	if(fabs(zVtx)>150) return false;
	return true;
}

bool AnaCumuAlg::isPassTrig()
{
	for(int iT=0; iT<nTrig; iT++)
	{
		if(m_TDT->isPassed(nameTrig[iT].c_str())) return true;
	}
	return false;
}

bool AnaCumuAlg::isPassErrState(const xAOD::EventInfo* evtInfo)
{
	if(evtInfo->errorState(xAOD::EventInfo::LAr)==xAOD::EventInfo::Error) return false;
	if(evtInfo->errorState(xAOD::EventInfo::Tile)==xAOD::EventInfo::Error) return false;
	if(evtInfo->errorState(xAOD::EventInfo::SCT)==xAOD::EventInfo::Error) return false;
	if(evtInfo->isEventFlagBitSet(xAOD::EventInfo::Core, 18)) return false;
	return true;
}

const xAOD::Vertex* AnaCumuAlg::vertexParticle(const xAOD::TrackParticle* ptrTrk)
{ 
	typedef ElementLink<xAOD::VertexContainer> Link_t;
	static const char* NAME = "vertexLink";
	if(!ptrTrk->isAvailable<Link_t>(NAME)) return 0;
	const Link_t& link = ptrTrk->auxdata<Link_t>(NAME);
	if(!link.isValid()) return 0;
	return *link;
}

bool AnaCumuAlg::isPassTrackQual(const xAOD::TrackParticle* ptrTrk, float zVtx)
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
	if(fabs(ptrTrk->eta())>=2.5) return false;
	if(ptrTrk->pt()/1E3<0.3) return false;
	return true;
}

void AnaCumuAlg::AnaSubEvtCumu()
{
	set_Q();
	fill_1sub_FG();
	fill_2sub_FG();
	fill_3sub_FG();
	fill_4sub_FG();
}

void AnaCumuAlg::set_Q()
{
	int tag1sub = 0; double Qx1sub[NVm][NP][1][NW]; double Qy1sub[NVm][NP][1][NW];
	int tag2sub = 0; double Qx2sub[NVm][NP][2][NW]; double Qy2sub[NVm][NP][2][NW];
	int tag3sub = 0; double Qx3sub[NVm][NP][3][NW]; double Qy3sub[NVm][NP][3][NW];
	int tag4sub = 0; double Qx4sub[NVm][NP][4][NW]; double Qy4sub[NVm][NP][4][NW];
	memset(nTrk1sub,0,sizeof nTrk1sub); memset(Qx1sub,0,sizeof Qx1sub); memset(Qy1sub,0,sizeof Qy1sub);
	memset(nTrk2sub,0,sizeof nTrk2sub); memset(Qx2sub,0,sizeof Qx2sub); memset(Qy2sub,0,sizeof Qy2sub);
	memset(nTrk3sub,0,sizeof nTrk3sub); memset(Qx3sub,0,sizeof Qx3sub); memset(Qy3sub,0,sizeof Qy3sub);
	memset(nTrk4sub,0,sizeof nTrk4sub); memset(Qx4sub,0,sizeof Qx4sub); memset(Qy4sub,0,sizeof Qy4sub);
	double m_trkWei[nTrkMax];
	evtWght = 1;
	for(int iT=0; iT<m_nTrk; iT++)
	{
		m_trkWei[iT] = 1;
		for(int iP=0; iP<NP; iP++)
		{
			if(m_trkPt[iT]<pTmin[iP] || m_trkPt[iT]>=pTmax[iP]) continue;
			tag1sub = detSubEvt(1,m_trkEta[iT]);
			tag2sub = detSubEvt(2,m_trkEta[iT]);
			tag3sub = detSubEvt(3,m_trkEta[iT]);
			tag4sub = detSubEvt(4,m_trkEta[iT]);
			for(int iW=0; iW<NW; iW++)
			{
				if(tag1sub>=0) nTrk1sub[iP][tag1sub][iW] += pow(m_trkWei[iT],iW);
				if(tag2sub>=0) nTrk2sub[iP][tag2sub][iW] += pow(m_trkWei[iT],iW);
				if(tag3sub>=0) nTrk3sub[iP][tag3sub][iW] += pow(m_trkWei[iT],iW);
				if(tag4sub>=0) nTrk4sub[iP][tag4sub][iW] += pow(m_trkWei[iT],iW);
				for(int iV=0; iV<NVm; iV++)
				{
					if(tag1sub>=0)
					{
						Qx1sub[iV][iP][tag1sub][iW] += cos(iV*m_trkPhi[iT])*pow(m_trkWei[iT],iW);
						Qy1sub[iV][iP][tag1sub][iW] += sin(iV*m_trkPhi[iT])*pow(m_trkWei[iT],iW);
					}
					if(tag2sub>=0)
					{
						Qx2sub[iV][iP][tag2sub][iW] += cos(iV*m_trkPhi[iT])*pow(m_trkWei[iT],iW);
						Qy2sub[iV][iP][tag2sub][iW] += sin(iV*m_trkPhi[iT])*pow(m_trkWei[iT],iW);
					}
					if(tag3sub>=0)
					{
						Qx3sub[iV][iP][tag3sub][iW] += cos(iV*m_trkPhi[iT])*pow(m_trkWei[iT],iW);
						Qy3sub[iV][iP][tag3sub][iW] += sin(iV*m_trkPhi[iT])*pow(m_trkWei[iT],iW);
					}
					if(tag4sub>=0)
					{
						Qx4sub[iV][iP][tag4sub][iW] += cos(iV*m_trkPhi[iT])*pow(m_trkWei[iT],iW);
						Qy4sub[iV][iP][tag4sub][iW] += sin(iV*m_trkPhi[iT])*pow(m_trkWei[iT],iW);
					}
				}
			}
		}
	}
	for(int iV=0; iV<NVm; iV++)
	{
		for(int iP=0; iP<NP; iP++)
		{
			for(int iW=0; iW<NW; iW++)
			{
				for(int i=0; i<1; i++) Q1sub[iV][iP][i][iW] = TComplex(Qx1sub[iV][iP][i][iW],Qy1sub[iV][iP][i][iW]);
				for(int i=0; i<2; i++) Q2sub[iV][iP][i][iW] = TComplex(Qx2sub[iV][iP][i][iW],Qy2sub[iV][iP][i][iW]);
				for(int i=0; i<3; i++) Q3sub[iV][iP][i][iW] = TComplex(Qx3sub[iV][iP][i][iW],Qy3sub[iV][iP][i][iW]);
				for(int i=0; i<4; i++) Q4sub[iV][iP][i][iW] = TComplex(Qx4sub[iV][iP][i][iW],Qy4sub[iV][iP][i][iW]);
			}
		}
	}
}

int AnaCumuAlg::detSubEvt(int numSubEvent, double eta)
{
	switch(numSubEvent)
	{
		case 1:
			{
				return 0;
			}
		case 2:
			{
				if(eta<0-etaGap/2) return 0;
				else if(eta>=0+etaGap/2) return 1;
				else return -1;
			}
		case 3:
			{
				if(fabs(eta)<etaCut/3-etaGap/2) return 0;
				else if(eta< 0-etaCut/3.-etaGap/2.) return 1;
				else if(eta>=0+etaCut/3.+etaGap/2.) return 2;
				else return -1;
			}
		case 4:
			{
				if(eta<-etaCut/2.-etaGap/2.) return 0;
				else if(eta>=-etaCut/2.+etaGap/2. && eta<0-etaGap/2.) return 1;
				else if(eta>=0+etaGap/2. && eta<+etaCut/2.-etaGap/2.) return 2;
				else if(eta>=+etaCut/2.+etaGap/2.) return 3;
				else return -1;
			}
		default:
			{
				std::cout<<"Wrong number of subevents!"<<std::endl;
				return -1;
			}
	}
}

void AnaCumuAlg::fill_1sub_FG()
{
	for(int iP=0; iP<NP; iP++)
	{
		double nTrkX = evtCls();
		double w2pc = pow(nTrk1sub[iP][0][1],2)-nTrk1sub[iP][0][2];
		double w4pc = pow(nTrk1sub[iP][0][1],4)+8*nTrk1sub[iP][0][3]*nTrk1sub[iP][0][1]-6*nTrk1sub[iP][0][2]*pow(nTrk1sub[iP][0][1],2)+3*pow(nTrk1sub[iP][0][2],2)-6*nTrk1sub[iP][0][4];
		double w6pc = pow(nTrk1sub[iP][0][1],6)-15*nTrk1sub[iP][0][2]*pow(nTrk1sub[iP][0][1],4)+40*nTrk1sub[iP][0][3]*pow(nTrk1sub[iP][0][1],3)+45*pow(nTrk1sub[iP][0][2],2)*pow(nTrk1sub[iP][0][1],2)-90*nTrk1sub[iP][0][4]*pow(nTrk1sub[iP][0][1],2)-120*nTrk1sub[iP][0][3]*nTrk1sub[iP][0][2]*nTrk1sub[iP][0][1]-15*pow(nTrk1sub[iP][0][2],3)+144*nTrk1sub[iP][0][5]*nTrk1sub[iP][0][1]+90*nTrk1sub[iP][0][4]*nTrk1sub[iP][0][2]+40*pow(nTrk1sub[iP][0][3],2)-120*nTrk1sub[iP][0][6];
		if(w6pc<1e-6) continue;
		cnt_1sub[iP]->Fill(nTrkX,evtWght);
		for(int iV=0; iV<NV; iV++)
		{
			c2_1sub_mean[iV][iP]->Fill(nTrkX,evtWght*w2pc*cal_2PC_1sub(Q1sub[iV][iP][0][1],nTrk1sub[iP][0][1],nTrk1sub[iP][0][2]));
			c2_1sub_wght[iV][iP]->Fill(nTrkX,evtWght*w2pc);
			c4_1sub_mean[iV][iP]->Fill(nTrkX,evtWght*w4pc*cal_4PC_1sub(Q1sub[iV][iP][0][1],Q1sub[iV][iP][0][3],Q1sub[2*iV][iP][0][2],nTrk1sub[iP][0][1],nTrk1sub[iP][0][2],nTrk1sub[iP][0][3],nTrk1sub[iP][0][4]));
			c4_1sub_wght[iV][iP]->Fill(nTrkX,evtWght*w4pc);
			c6_1sub_mean[iV][iP]->Fill(nTrkX,evtWght*w6pc*cal_6PC_1sub(Q1sub[iV][iP][0][1],Q1sub[iV][iP][0][3],Q1sub[iV][iP][0][5],Q1sub[2*iV][iP][0][2],Q1sub[2*iV][iP][0][4],Q1sub[3*iV][iP][0][3],nTrk1sub[iP][0][1],nTrk1sub[iP][0][2],nTrk1sub[iP][0][3],nTrk1sub[iP][0][4],nTrk1sub[iP][0][5],nTrk1sub[iP][0][6],pow(nTrk1sub[iP][0][1],2),pow(nTrk1sub[iP][0][2],2),pow(nTrk1sub[iP][0][3],2),pow(nTrk1sub[iP][0][1],3),pow(nTrk1sub[iP][0][2],3),pow(nTrk1sub[iP][0][1],4),pow(nTrk1sub[iP][0][1],6)));
			c6_1sub_wght[iV][iP]->Fill(nTrkX,evtWght*w6pc);
		}
	}
}

void AnaCumuAlg::fill_2sub_FG()
{
	for(int iP=0; iP<NP; iP++)
	{
		double nTrkX = evtCls();
		double w2pc = nTrk2sub[iP][0][1]*nTrk2sub[iP][1][1];
		double w4pc = pow(nTrk2sub[iP][0][1],2)*pow(nTrk2sub[iP][1][1],2)-nTrk2sub[iP][0][2]*pow(nTrk2sub[iP][1][1],2)-nTrk2sub[iP][1][2]*pow(nTrk2sub[iP][0][1],2)+nTrk2sub[iP][0][2]*nTrk2sub[iP][1][2];
		if(w4pc<1e-6) continue;
		cnt_2sub[iP]->Fill(nTrkX,evtWght);
		for(int iV=0; iV<NV; iV++)
		{
			c2_2sub_mean[iV][iP]->Fill(nTrkX,evtWght*w2pc*cal_2PC_2sub(Q2sub[iV][iP][0][1],Q2sub[iV][iP][1][1],nTrk2sub[iP][0][1],nTrk2sub[iP][1][1]));
			c2_2sub_wght[iV][iP]->Fill(nTrkX,evtWght*w2pc);
			c4_2sub_mean[iV][iP]->Fill(nTrkX,evtWght*w4pc*cal_4PC_2sub(Q2sub[iV][iP][0][1],Q2sub[2*iV][iP][0][2],Q2sub[iV][iP][1][1],Q2sub[2*iV][iP][1][2],nTrk2sub[iP][0][1],nTrk2sub[iP][0][2],nTrk2sub[iP][1][1],nTrk2sub[iP][1][2]));
			c4_2sub_wght[iV][iP]->Fill(nTrkX,evtWght*w4pc);
		}
	}
}

void AnaCumuAlg::fill_3sub_FG()
{
	for(int iA=0; iA<NA; iA++)
	{
		for(int iP=0; iP<NP; iP++)
		{
			double nTrkX = evtCls();
			double w2pc1 = nTrk3sub[iP][0][1]*nTrk3sub[iP][1][1];
			double w2pc2 = nTrk3sub[iP][0][1]*nTrk3sub[iP][2][1];
			double w4pc = (pow(nTrk3sub[iP][0][1],2)-nTrk3sub[iP][0][2])*nTrk3sub[iP][1][1]*nTrk3sub[iP][2][1];
			if(w4pc<1e-6) continue;
			cnt_3sub[iA][iP]->Fill(nTrkX,evtWght);
			for(int iV=0; iV<NV; iV++)
			{
				c2_1_3sub_mean[iA][iV][iP]->Fill(nTrkX,evtWght*w2pc1*cal_2PC_3sub(Q3sub[iV][iP][0][1],Q3sub[iV][iP][1][1],nTrk3sub[iP][0][1],nTrk3sub[iP][1][1]));
				c2_1_3sub_wght[iA][iV][iP]->Fill(nTrkX,evtWght*w2pc1);
				c2_2_3sub_mean[iA][iV][iP]->Fill(nTrkX,evtWght*w2pc2*cal_2PC_3sub(Q3sub[iV][iP][0][1],Q3sub[iV][iP][2][1],nTrk3sub[iP][0][1],nTrk3sub[iP][2][1]));
				c2_2_3sub_wght[iA][iV][iP]->Fill(nTrkX,evtWght*w2pc2);
				c4_3sub_mean[iA][iV][iP]->Fill(nTrkX,evtWght*w4pc*cal_4PC_3sub(Q3sub[iV][iP][0][1],Q3sub[2*iV][iP][0][2],Q3sub[iV][iP][1][1],Q3sub[iV][iP][2][1],nTrk3sub[iP][0][1],nTrk3sub[iP][0][2],nTrk3sub[iP][1][1],nTrk3sub[iP][2][1]));
				c4_3sub_wght[iA][iV][iP]->Fill(nTrkX,evtWght*w4pc);
			}
		}
		for(int iP=0; iP<NP; iP++)
		{
			for(int iW=0; iW<NW; iW++)
			{
				swap(nTrk3sub[iP][0][iW],nTrk3sub[iP][1][iW],nTrk3sub[iP][2][iW]);
				for(int iV=0; iV<NVm; iV++)
				{
					swap(Q3sub[iV][iP][0][iW],Q3sub[iV][iP][1][iW],Q3sub[iV][iP][2][iW]);
				}
			}
		}
	}
}

void AnaCumuAlg::fill_4sub_FG()
{
	for(int iA=0; iA<NA; iA++)
	{
		for(int iP=0; iP<NP; iP++)
		{
			double nTrkX = evtCls();
			double w2pc1 = nTrk4sub[iP][0][1]*nTrk4sub[iP][2][1];
			double w2pc2 = nTrk4sub[iP][0][1]*nTrk4sub[iP][3][1];
			double w2pc3 = nTrk4sub[iP][1][1]*nTrk4sub[iP][2][1];
			double w2pc4 = nTrk4sub[iP][1][1]*nTrk4sub[iP][3][1];
			double w4pc = nTrk4sub[iP][0][1]*nTrk4sub[iP][1][1]*nTrk4sub[iP][2][1]*nTrk4sub[iP][3][1];
			if(w4pc<1e-6) continue;
			cnt_4sub[iA][iP]->Fill(nTrkX,evtWght);
			for(int iV=0; iV<NV; iV++)
			{
				c2_1_4sub_mean[iA][iV][iP]->Fill(nTrkX,evtWght*w2pc1*cal_2PC_4sub(Q4sub[iV][iP][0][1],Q4sub[iV][iP][2][1],nTrk4sub[iP][0][1],nTrk4sub[iP][2][1]));
				c2_1_4sub_wght[iA][iV][iP]->Fill(nTrkX,evtWght*w2pc1);
				c2_2_4sub_mean[iA][iV][iP]->Fill(nTrkX,evtWght*w2pc2*cal_2PC_4sub(Q4sub[iV][iP][0][1],Q4sub[iV][iP][3][1],nTrk4sub[iP][0][1],nTrk4sub[iP][3][1]));
				c2_2_4sub_wght[iA][iV][iP]->Fill(nTrkX,evtWght*w2pc2);
				c2_3_4sub_mean[iA][iV][iP]->Fill(nTrkX,evtWght*w2pc3*cal_2PC_4sub(Q4sub[iV][iP][1][1],Q4sub[iV][iP][2][1],nTrk4sub[iP][1][1],nTrk4sub[iP][2][1]));
				c2_3_4sub_wght[iA][iV][iP]->Fill(nTrkX,evtWght*w2pc3);
				c2_4_4sub_mean[iA][iV][iP]->Fill(nTrkX,evtWght*w2pc4*cal_2PC_4sub(Q4sub[iV][iP][1][1],Q4sub[iV][iP][3][1],nTrk4sub[iP][1][1],nTrk4sub[iP][3][1]));
				c2_4_4sub_wght[iA][iV][iP]->Fill(nTrkX,evtWght*w2pc4);
				c4_4sub_mean[iA][iV][iP]->Fill(nTrkX,evtWght*w4pc*cal_4PC_4sub(Q4sub[iV][iP][0][1],Q4sub[iV][iP][1][1],Q4sub[iV][iP][2][1],Q4sub[iV][iP][3][1],nTrk4sub[iP][0][1],nTrk4sub[iP][1][1],nTrk4sub[iP][2][1],nTrk4sub[iP][3][1]));
				c4_4sub_wght[iA][iV][iP]->Fill(nTrkX,evtWght*w4pc);
			}
		}
		for(int iP=0; iP<NP; iP++)
		{
			for(int iW=0; iW<NW; iW++)
			{
				swap(nTrk4sub[iP][1][iW],nTrk4sub[iP][2][iW],nTrk4sub[iP][3][iW]);
				for(int iV=0; iV<NVm; iV++)
				{
					swap(Q4sub[iV][iP][1][iW],Q4sub[iV][iP][2][iW],Q4sub[iV][iP][3][iW]);
				}
			}
		}
	}
}

double AnaCumuAlg::cal_2PC_1sub(TComplex Q1n1, double s1, double s2)
{
	return ((Q1n1*TComplex::Conjugate(Q1n1)).Re()-s2)/(pow(s1,2)-s2);
}

double AnaCumuAlg::cal_4PC_1sub(TComplex Q1n1, TComplex Q1n3, TComplex Q2n2, double s1, double s2, double s3, double s4)
{
	return (pow((Q1n1*TComplex::Conjugate(Q1n1)).Re(),2)+(Q2n2*TComplex::Conjugate(Q2n2)).Re()-2*(Q2n2*TComplex::Conjugate(Q1n1)*TComplex::Conjugate(Q1n1)).Re()+8*(Q1n3*TComplex::Conjugate(Q1n1)).Re()-4*s2*(Q1n1*TComplex::Conjugate(Q1n1)).Re()+2*pow(s2,2)-6*s4)/(pow(s1,4)+8*s3*s1-6*s2*pow(s1,2)+3*pow(s2,2)-6*s4);
}

double AnaCumuAlg::cal_6PC_1sub(TComplex Q1n1, TComplex Q1n3, TComplex Q1n5, TComplex Q2n2, TComplex Q2n4, TComplex Q3n3, double S1n1, double S1n2, double S1n3, double S1n4, double S1n5, double S1n6, double S2n1, double S2n2, double S2n3, double S3n1, double S3n2, double S4n1, double S6n1)
{
	return (pow((Q1n1*TComplex::Conjugate(Q1n1)).Re(),3)-6*(Q1n1*TComplex::Conjugate(Q1n1)).Re()*(Q2n2*TComplex::Conjugate(Q1n1)*TComplex::Conjugate(Q1n1)).Re()+9*(Q2n2*TComplex::Conjugate(Q2n2)).Re()*(Q1n1*TComplex::Conjugate(Q1n1)).Re()+4*(Q3n3*TComplex::Conjugate(Q1n1)*TComplex::Conjugate(Q1n1)*TComplex::Conjugate(Q1n1)).Re()+18*S1n2*(Q2n2*TComplex::Conjugate(Q1n1)*TComplex::Conjugate(Q1n1)).Re()-36*(Q2n4*TComplex::Conjugate(Q1n1)*TComplex::Conjugate(Q1n1)).Re()-36*(Q1n3*Q1n1*TComplex::Conjugate(Q2n2)).Re()+18*S2n2*(Q1n1*TComplex::Conjugate(Q1n1)).Re()-54*S1n4*(Q1n1*TComplex::Conjugate(Q1n1)).Re()-72*S1n2*(Q1n3*TComplex::Conjugate(Q1n1)).Re()+36*(Q1n3*TComplex::Conjugate(Q1n3)).Re()+144*(Q1n5*TComplex::Conjugate(Q1n1)).Re()-9*S1n2*pow((Q1n1*TComplex::Conjugate(Q1n1)).Re(),2)+36*(Q1n1*TComplex::Conjugate(Q1n1)).Re()*(Q1n3*TComplex::Conjugate(Q1n1)).Re()-9*S1n2*(Q2n2*TComplex::Conjugate(Q2n2)).Re()+36*(Q2n4*TComplex::Conjugate(Q2n2)).Re()-12*(Q3n3*TComplex::Conjugate(Q2n2)*TComplex::Conjugate(Q1n1)).Re()+4*(Q3n3*TComplex::Conjugate(Q3n3)).Re()+54*S1n4*S1n2-6*S3n2-120*S1n6)/(S6n1-15*S1n2*S4n1+40*S1n3*S3n1+45*S2n2*S2n1-90*S1n4*S2n1-120*S1n3*S1n2*S1n1-15*S3n2+144*S1n5*S1n1+90*S1n4*S1n2+40*S2n3-120*S1n6);
}

double AnaCumuAlg::cal_2PC_2sub(TComplex A1n1, TComplex B1n1, double a1, double b1)
{
	return (A1n1*TComplex::Conjugate(B1n1)).Re()/a1/b1;
}

double AnaCumuAlg::cal_4PC_2sub(TComplex A1n1, TComplex A2n2, TComplex B1n1, TComplex B2n2, double a1, double a2, double b1, double b2)
{
	return ((A1n1*TComplex::Conjugate(B1n1)*A1n1*TComplex::Conjugate(B1n1)).Re()-(A2n2*TComplex::Conjugate(B1n1)*TComplex::Conjugate(B1n1)).Re()-(A1n1*A1n1*TComplex::Conjugate(B2n2)).Re()+(A2n2*TComplex::Conjugate(B2n2)).Re())/(pow(a1,2)*pow(b1,2)-a2*pow(b1,2)-pow(a1,2)*b2+a2*b2);
}

double AnaCumuAlg::cal_2PC_3sub(TComplex A1n1, TComplex B1n1, double a1, double b1)
{
	return (A1n1*TComplex::Conjugate(B1n1)).Re()/a1/b1;
}

double AnaCumuAlg::cal_4PC_3sub(TComplex A1n1, TComplex A2n2, TComplex B1n1, TComplex C1n1, double a1, double a2, double b1, double c1)
{
	return ((A1n1*TComplex::Conjugate(B1n1)*A1n1*TComplex::Conjugate(C1n1)).Re()-(A2n2*TComplex::Conjugate(B1n1)*TComplex::Conjugate(C1n1)).Re())/((pow(a1,2)-a2)*b1*c1);
}

double AnaCumuAlg::cal_2PC_4sub(TComplex A1n1, TComplex B1n1, double a1, double b1)
{
	return (A1n1*TComplex::Conjugate(B1n1)).Re()/a1/b1;
}

double AnaCumuAlg::cal_4PC_4sub(TComplex A1n1, TComplex B1n1, TComplex C1n1, TComplex D1n1, double a1, double b1, double c1, double d1)
{
	return (A1n1*B1n1*TComplex::Conjugate(C1n1)*TComplex::Conjugate(D1n1)).Re()/(a1*b1*c1*d1);
}

void AnaCumuAlg::swap(double& val1, double& val2, double& val3)
{
	double tmp = 0;
	tmp = val1;
	val1 = val2;
	val2 = val3;
	val3 = tmp;
}

void AnaCumuAlg::swap(TComplex& val1, TComplex& val2, TComplex& val3)
{
	TComplex tmp;
	tmp = val1;
	val1 = val2;
	val2 = val3;
	val3 = tmp;
}

StatusCode AnaCumuAlg::initHist(TH1D*& hIn, const char* hName, int iP)
{
	char name[200];
	sprintf(name,"%s_Pt%d",hName,iP);
	hIn = new TH1D(name,"",nBin,minBin,maxBin);
	char sName[200];
	sprintf(sName,"/MYSTREAM/%s",name);
	CHECK(histSvc()->regHist(sName,hIn));
	return StatusCode::SUCCESS;
}

StatusCode AnaCumuAlg::initHist(TH1D*& hIn, const char* hName, int iV, int iP)
{
	char name[200];
	sprintf(name,"%s_Har%d_Pt%d",hName,iV,iP);
	hIn = new TH1D(name,"",nBin,minBin,maxBin);
	char sName[200];
	sprintf(sName,"/MYSTREAM/%s",name);
	CHECK(histSvc()->regHist(sName,hIn));
	return StatusCode::SUCCESS;
}

StatusCode AnaCumuAlg::initHistPm(TH1D*& hIn, const char* hName, int iA, int iP)
{
	char name[200];
	sprintf(name,"%s_Pm%d_Pt%d",hName,iA,iP);
	hIn = new TH1D(name,"",nBin,minBin,maxBin);
	char sName[200];
	sprintf(sName,"/MYSTREAM/%s",name);
	CHECK(histSvc()->regHist(sName,hIn));
	return StatusCode::SUCCESS;
}

StatusCode AnaCumuAlg::initHistPm(TH1D*& hIn, const char* hName, int iA, int iV, int iP)
{
	char name[200];
	sprintf(name,"%s_Pm%d_Har%d_Pt%d",hName,iA,iV,iP);
	hIn = new TH1D(name,"",nBin,minBin,maxBin);
	char sName[200];
	sprintf(sName,"/MYSTREAM/%s",name);
	CHECK(histSvc()->regHist(sName,hIn));
	return StatusCode::SUCCESS;
}
