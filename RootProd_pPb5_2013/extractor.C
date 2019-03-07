#define extractor_cxx
// #define DO_RP
#include "extractor.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <stdio.h>
#include <vector>
#include <bitset>

#include "isGoodEvent_pPb.C"
#include "extractor_trigBranches.C"
#include "CombineTriggers.h"

const double pTmin = 0.2;
const double etaMax = 2.5;
const int nTrkMax = 1000;

UInt_t   runNo;
UInt_t   lbNo;
UInt_t   bcid;
float 	 ZdcE;
float    trigPS[40];
float    zVtx;
UInt_t   nVtx;
UInt_t   nTrk;
UInt_t   trkInfo[nTrkMax];
float		 mPhi[nTrkMax];

const double PI = acos(-1.0);

static const int NRUN = 31;
UInt_t Runs[NRUN]   = {217999, 218006, 218048, 218118, 218168, 218179, 218197, 218213, 218222, 218301, 218338, 218391, 218436, 218473, 218589, 218677, 218679, 218716, 218751, 218771, 218783, 218829, 218898, 218940, 218968, 219001, 219028, 219055, 219089, 219111, 219114};
Int_t ZdcCuts[NRUN] = {1500, 1140, 980, 860, 820, 780, 740, 740, 740, 660, 660, 2660, 2420, 2500, 2700, 1780, 1620, 1420, 1260, 1420, 1380, 1300, 1220, 1140, 3000, 980, 1020, 1020, 940, 900, 900};

static double centcuts[97]={
	0.090835,0.080395,0.074065,0.069395,0.065715,0.062605,0.059955,0.057565,0.055425,0.053505,
	0.051695,0.050035,0.048485,0.047035,0.045655,0.044365,0.043145,0.041975,0.040845,0.039765,
	0.038735,0.037745,0.036795,0.035865,0.034975,0.034115,0.033255,0.032435,0.031635,0.030855,
	0.030085,0.029345,0.028625,0.027915,0.027205,0.026525,0.025855,0.025195,0.024555,0.023915,
	0.023295,0.022685,0.022085,0.021495,0.020915,0.020345,0.019785,0.019235,0.018695,0.018165,
	0.017645,0.017135,0.016615,0.016125,0.015625,0.015145,0.014665,0.014195,0.013745,0.013285,
	0.012835,0.012395,0.011965,0.011535,0.011105,0.010695,0.010285,0.009885,0.009485,0.009095,
	0.008715,0.008335,0.007955,0.007595,0.007235,0.006875,0.006535,0.006185,0.005855,0.005525,
	0.005205,0.004885,0.004575,0.004275,0.003985,0.003695,0.003405,0.003125,0.002845,0.002565,
	0.002275,0.001985,0.001675,0.001355,0.000985,0.000565,5e-06
};

int cvtPt(double pT)
{
	int flagPt = int(pT/100.);
	if(flagPt<0) flagPt = 0;
	if(flagPt>=250) flagPt = 250;
	return flagPt;
}
int cvtEta(double eta)
{
	int flagEta = int((eta+etaMax)/2/etaMax*250);
	if(flagEta<0) flagEta = 0;
	if(flagEta>=250) flagEta = 250;
	return flagEta;
}
int cvtPhi(double phi)
{
	int flagPhi = int((phi+TMath::Pi())/2/TMath::Pi()*pow(2,14));
	if(flagPhi<0) flagPhi = 0;
	if(flagPhi>=pow(2,14)) flagPhi = int(pow(2,14))-1;
	return flagPhi;
}
double detPt(UInt_t pt)
{ 
	return (pt+0.5)/10.;
}
double detEta(UInt_t eta)
{
	return (eta+0.5)/250.*2*etaMax-etaMax;
}
double detPhi(UInt_t phi)
{
	return (phi+0.5)/pow(2,14)*2*TMath::Pi()-TMath::Pi();
}

void extractor::Loop()
{
	if (fChain == 0) return;
	cout<<"inside Loop() "<<endl;

	TFile *outfile    = new TFile("PDST.root","recreate");

	TTree *MyTree    = new TTree("tree","Data13 pPb 5TeV");
	//------------------------------------------------------
	MyTree->Branch("runNo",    			&runNo,    			"runNo/i");
	MyTree->Branch("lbNo",     			&lbNo,     			"lbNo/i");
	MyTree->Branch("bcid",     			&bcid,     			"bcid/i");
	MyTree->Branch("Fcal_Et_n",     &Fcal_Et_n,   	"Fcal_Et_n/F");
	MyTree->Branch("Fcal_Et_p",     &Fcal_Et_p,   	"Fcal_Et_p/F");
	MyTree->Branch("ZdcE",     			&ZdcE,   				"ZdcE/F");
	MyTree->Branch("is_pileup",     &is_pileup,   	"is_pileup/b");
	MyTree->Branch("is_pileupZDC",  &is_pileupZDC,	"is_pileupZDC/b");
	MyTree->Branch("trigPS",   			trigPS,    			"trigPS[40]/F");
	MyTree->Branch("zVtx",     			&zVtx,     			"zVtx/F");
	MyTree->Branch("nVtx",     			&nVtx,     			"nVtx/i");
	MyTree->Branch("nTrk",     			&nTrk,     			"nTrk/i");
	MyTree->Branch("trkInfo",  			trkInfo,   			"trkInfo[nTrk]/i");
	MyTree->Branch("mPhi",  			  mPhi,   			  "mPhi[nTrk]/F");

	//------------------------------------------------------

	fChain->SetBranchStatus("*",0);

	fChain->SetBranchStatus("RunNumber",1);
	fChain->SetBranchStatus("EventNumber",1);
	fChain->SetBranchStatus("bcid",1);
	fChain->SetBranchStatus("lbn",1);
	fChain->SetBranchStatus("timestamp",1);
	fChain->SetBranchStatus("timestamp_ns",1);

	fChain->SetBranchStatus("trig_L1_esum_energyT",1);
	fChain->SetBranchStatus("HITrigVtxCounts_NtrksPrim",1);
	fChain->SetBranchStatus("trig_L1_TAV",1);
	fChain->SetBranchStatus("trig_L1_TBP",1);
	fChain->SetBranchStatus("trig_L2_passedPhysics",1);
	fChain->SetBranchStatus("trig_EF_passedPhysics",1);

	fChain->SetBranchStatus("vx_n",1);
	fChain->SetBranchStatus("vx_x",1);
	fChain->SetBranchStatus("vx_y",1);
	fChain->SetBranchStatus("vx_z",1);

	fChain->SetBranchStatus("vx_chi2",1);
	fChain->SetBranchStatus("vx_ndof",1);
	fChain->SetBranchStatus("vx_sumPt",1);
	fChain->SetBranchStatus("vx_nTracks",1);

	//------------------------------------------------------
	fChain->SetBranchStatus("trk_n"           ,1);
	fChain->SetBranchStatus("trk_pt"          ,1);
	fChain->SetBranchStatus("trk_eta"         ,1);
	fChain->SetBranchStatus("trk_theta" ,1);
	fChain->SetBranchStatus("trk_phi_wrtPV"   ,1);
	fChain->SetBranchStatus("trk_qoverp"      ,1);

	fChain->SetBranchStatus("trk_err_theta_wrtPV"   ,1);
	fChain->SetBranchStatus("trk_err_phi_wrtPV"     ,1);
	fChain->SetBranchStatus("trk_err_qoverp_wrtPV"  ,1);

	fChain->SetBranchStatus("trk_chi2"        ,1);
	fChain->SetBranchStatus("trk_ndof"        ,1);
	fChain->SetBranchStatus("trk_nPixHits"    ,1);
	fChain->SetBranchStatus("trk_nPixHoles"   ,1);
	fChain->SetBranchStatus("trk_nSCTHits"    ,1);
	fChain->SetBranchStatus("trk_nSCTHoles"   ,1);
	fChain->SetBranchStatus("trk_nTRTHits"    ,1);
	fChain->SetBranchStatus("trk_nBLHits"     ,1);
	fChain->SetBranchStatus("trk_expectBLayerHit",1);

	fChain->SetBranchStatus("trk_d0_wrtPV"    ,1);
	fChain->SetBranchStatus("trk_z0_wrtPV"    ,1);
	fChain->SetBranchStatus("trk_err_d0_wrtPV",1);
	fChain->SetBranchStatus("trk_err_z0_wrtPV",1);
	fChain->SetBranchStatus("trk_d0_wrtBS"    ,1);
	fChain->SetBranchStatus("trk_cov_z0_theta_wrtPV",1);

	fChain->SetBranchStatus("trk_patternReco1",1);
	fChain->SetBranchStatus("trk_patternReco2",1);

	//------------------------------------------------------
	fChain->SetBranchStatus("cccEt_Et_Eh_PresB", 1);
	fChain->SetBranchStatus("cccEt_Et_Eh_EMB", 1);
	fChain->SetBranchStatus("cccEt_Et_Eh_EMEC", 1);
	fChain->SetBranchStatus("cccEt_Et_Eh_Tile", 1);
	fChain->SetBranchStatus("cccEt_Et_Eh_TileGap", 1);
	fChain->SetBranchStatus("cccEt_Et_Eh_HEC", 1);
	fChain->SetBranchStatus("cccEt_Et_Eh_PresE", 1);
	fChain->SetBranchStatus("cccEt_Et_Eh_Scint", 1);
	fChain->SetBranchStatus("cccEt_Et_Eh_FCal", 1);
	fChain->SetBranchStatus("cccEt_n_Eh_FCal", 1);
	fChain->SetBranchStatus("cccEt_p_Eh_FCal", 1);
	fChain->SetBranchStatus("mbtime_timeA"    , 1);
	fChain->SetBranchStatus("mbtime_timeC"    , 1);

	fChain->SetBranchStatus("mbtime_countA"   , 1);
	fChain->SetBranchStatus("mbtime_countC"   , 1);
	//------------------------------------------------------
	fChain->SetBranchStatus("lvl2_sp_sctSpEndcapC", 1);
	fChain->SetBranchStatus("lvl2_sp_sctSpBarrel", 1);
	fChain->SetBranchStatus("lvl2_sp_sctSpEndcapA", 1);

	//------------------------------------------------------
	fChain->SetBranchStatus("ZdcReco_ESumC_LG", 1);
	fChain->SetBranchStatus("ZdcReco_ESumC_HG", 1);
	fChain->SetBranchStatus("ZdcReco_ESumA_LG", 1);
	fChain->SetBranchStatus("ZdcReco_ESumA_HG", 1);

	fChain->SetBranchStatus("trig_DB_SMK",1);
	fChain->SetBranchStatus("trig_DB_L1PSK",1);
	fChain->SetBranchStatus("trig_DB_HLTPSK",1);
	//------------------------------------------------------
	//fChain->SetBranchStatus("TotalEt_n"   , 1);
	fChain->SetBranchStatus("TotalEt_layer_eta"   , 1);
	//fChain->SetBranchStatus("TotalEt_layer_phi"   , 1);
	fChain->SetBranchStatus("TotalEt_layer_towerEt"   , 1);
	//fChain->SetBranchStatus("TotalEt_layer_sampling"   , 1);
	//fChain->SetBranchStatus("TotalEt_layer_sampling_calib"   , 1);
	//------------------------------------------------------

	cout<<"NENTRIES="<<endl;
	Long64_t nentries = fChain->GetEntries();
	cout<<"NENTRIES="<<nentries<<endl;
	int ev_sel = 0;

	std::cout << "nentries = " << nentries << std::endl;
	for (Long64_t jentry=0; jentry<nentries;jentry++){
		int bytes=fChain->GetEntry(jentry);
		if(bytes<=0) {cout<<"Bad Event"<<endl;break;}
		if(jentry%1000==0) {cout<<"running event "<<jentry<<endl ;}

		runNo = RunNumber;
		lbNo = lbn;

		// cleaning
		//------------------------------------------------------
		if( isGoodEvent_pPb(RunNumber,lbn,bcid) !=1 ) continue;
		ev_sel++;
		if(ev_sel%1000==0) {cout<<"Selected Event "<<ev_sel<<endl ;}
		Fcal_Et  =(cccEt_Et_Eh_FCal->at(0)+cccEt_Et_Eh_FCal->at(1)+cccEt_Et_Eh_FCal->at(2))/1000.0;  //Fcal energy in MeV
		Fcal_Et_n=(cccEt_n_Eh_FCal ->at(0)+cccEt_n_Eh_FCal ->at(1)+cccEt_n_Eh_FCal ->at(2))/1000.0;
		Fcal_Et_p=(cccEt_p_Eh_FCal ->at(0)+cccEt_p_Eh_FCal ->at(1)+cccEt_p_Eh_FCal ->at(2))/1000.0;
		float tmpFcal = 0;
		if (RunNumber > 218589)
		{
			tmpFcal = Fcal_Et_n;
			Fcal_Et_n = Fcal_Et_p;
			Fcal_Et_p = tmpFcal;
		}

		//mbts timing
		//------------------------------------------------------
		if (vx_n<2)                                       continue;
		if (mbtime_timeA == 75|| mbtime_timeC == 75)      continue;
		else if (mbtime_timeA ==-75|| mbtime_timeC ==-75) continue;
		else if (mbtime_timeA == 0 || mbtime_timeC == 0)  continue;
		else if (fabs(mbtime_timeA-mbtime_timeC) > 10)    continue;

		//------------------------------------------------------
		Fill_Trigger();//Fill Trigger Branches
		bool tagTrig = false;
		for(int i=0; i<40; i++)
		{
			if(trigPS[i]>0)
			{
				tagTrig = true;
				break;
			}
		}
		if(!tagTrig) continue;
		//------------------------------------------------------
		
		Myvx_n=vx_n;
		is_pileup=0;
		zVtx = 99999;
		nVtx = vx_n;
		if (vx_n > MAXVTX){cout<<"Number of vertices is large "<<vx_n<<endl;}
		else{
			zVtx = vx_z->at(0);
			for(int i=0;i<vx_n;i++){
				Myvx_x      [i] = vx_x       ->at(i); //vertex info. the 0th vertex is always the primary one.
				Myvx_y      [i] = vx_y       ->at(i);
				Myvx_z      [i] = vx_z       ->at(i);
				Myvx_sumPt  [i] = vx_sumPt   ->at(i);
			}
			if(vx_n>2) {
				if(Myvx_sumPt[0]>5000 && Myvx_sumPt[1]>5000) is_pileup=1;

			}
		}
		if(fabs(zVtx)>150) continue;
		is_pileupZDC = 0;
		int run_idx = -1;
		for (int irun=0; irun<NRUN; irun++) {
			if (RunNumber == Runs[irun]) {run_idx = irun; break;}
		}
		ZdcE = ZdcReco_ESumA_LG;
		if (RunNumber > 218589) ZdcE = ZdcReco_ESumC_LG;
		if (ZdcE > ZdcCuts[run_idx]) is_pileupZDC = 1;

		//if(is_pileup==1 || is_pileupZDC==1) continue;

		//------------------------------------------------------------------------------------
		Mytrk_n=0;
		for(int reco_track=0;reco_track<trk_n;reco_track++)
		{
			UInt_t Quality=0;

			Float_t phi,pt,eta;
			phi = trk_phi_wrtPV ->at(reco_track);
			pt  = trk_pt  ->at(reco_track);
			eta = trk_eta ->at(reco_track);
			//if(pt<100) continue;

			//-----------------------------------------------------------------------------------
			// Loose Cuts on Track Quality
			int sct_cut=0;
			if(pt>100 && pt<=200 && trk_nSCTHits->at(reco_track) >=2)  sct_cut=1;
			if(pt>200 && pt<=300 && trk_nSCTHits->at(reco_track) >=4)  sct_cut=1;
			if(          pt> 300 && trk_nSCTHits->at(reco_track) >=6)  sct_cut=1;

			if (  trk_nPixHits -> at(reco_track) > 0   &&
					fabs(trk_eta -> at(reco_track))<2.5  &&
					sct_cut==1 &&
					!(trk_expectBLayerHit->at(reco_track)==1 && trk_nBLHits->at(reco_track)<=0))
			{
				Quality+=1; //basic cut
			}

			float d0     = trk_d0_wrtPV->at(reco_track);
			float z0     = trk_z0_wrtPV->at(reco_track);
			float theta  = trk_theta->at(reco_track);
			float e_z0    = trk_err_z0_wrtPV    ->at(reco_track);
			float e_theta = trk_err_theta_wrtPV ->at(reco_track);
			float e_d0    = trk_err_d0_wrtPV    ->at(reco_track);
			float cov     = trk_cov_z0_theta_wrtPV->at(reco_track);
			float e_z0_sin= sqrt( fabs( pow(e_z0*sin(theta),2.0) + pow(z0*cos(theta)*e_theta,2.0) + 2*sin(theta)*z0*cos(theta)*cov ));

			if((e_d0!=0.0 && e_z0_sin!=0.0) && (Quality&1)){
				if(fabs(z0*sin(theta)/e_z0_sin)<3 && fabs(d0/e_d0)<3) Quality+=2;//default cut w/o track author
			}
			if ( (Quality&2) && ( ((trk_patternReco1->at(reco_track))&1) || ( (trk_patternReco2->at(reco_track)) &16)) ) Quality+=4;//default cut
			//-----------------------------------------------------------------------------------

			//More cuts for cross check
			if ((Quality&1)                             &&   
					trk_nPixHits -> at(reco_track)   > 1  &&
					trk_nPixHoles-> at(reco_track)  == 0  &&
					trk_nSCTHits -> at(reco_track)   > 7  &&
					trk_nSCTHoles-> at(reco_track)   < 2  &&
					trk_ndof     -> at(reco_track)   > 0)
			{
				if(trk_chi2 -> at(reco_track)/trk_ndof -> at(reco_track) < 6 ){
					if(fabs(d0)<1.0 && fabs(z0*sin(theta))<1.0) Quality+=8; // Pb+Pb cut
				} 
			}
			if ((Quality&8) && (trk_nPixHits->at(reco_track)>2)) Quality+=16; //tighter cut Pb+Pb

			if ((Quality&4)) {//tighter significance cuts
				if(e_d0!=0.0 && e_z0_sin!=0.0) {
					if(fabs(z0*sin(theta)/e_z0_sin)<2   && fabs(d0/e_d0)<2  ) Quality+=32;
					if(fabs(z0*sin(theta)/e_z0_sin)<1.5 && fabs(d0/e_d0)<1.5) Quality+=64;
					if(fabs(z0*sin(theta)/e_z0_sin)<1.  && fabs(d0/e_d0)<1. ) Quality+=128;
				}
			}

			//-----------------------------------------------------------------------------------
			bool chbin=0;
			if (trk_qoverp->at(reco_track)<0) chbin=1;

			Mytrk_pt         [Mytrk_n] = trk_pt->at(reco_track)/1000.0;
			Mytrk_eta        [Mytrk_n] = trk_eta->at(reco_track);
			Mytrk_phi        [Mytrk_n] = phi;
			Mytrk_charge     [Mytrk_n] = chbin;
			Mytrk_Quality    [Mytrk_n] = Quality;

			Mytrk_n++;
			if(Mytrk_n>=MAXTRK) {cout<<"Number of tracks is large "<<Mytrk_n<<endl;break;} 
		}

		nTrk = 0;
		for(int i=0; i<nTrkMax; i++) trkInfo[i] = 0;
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
		for(int iT=0; iT<trk_n; iT++)
		{
			if(trk_pt->at(iT)/1000<pTmin) continue;
			if(fabs(trk_eta->at(iT))>=etaMax) continue;
			if((Mytrk_Quality[iT] & int(pow(2,2)))==0) continue;

			if(trk_qoverp->at(iT)>0) trkChg = 1;
			else trkChg = 0;
			if((Mytrk_Quality[iT] & int(pow(2,5)))!=0) trkQual = 1;
			else trkQual = 0;
			trkPt = cvtPt(trk_pt->at(iT));
			trkEta = cvtEta(trk_eta->at(iT));
			trkPhi = cvtPhi(trk_phi_wrtPV->at(iT));
			mPhi[nTrk] = trk_phi_wrtPV->at(iT);

			trkInfo[nTrk] = trkChg;
			trkInfo[nTrk] <<=  1; trkInfo[nTrk] |= trkQual;
			trkInfo[nTrk] <<=  8; trkInfo[nTrk] |= trkPt;
			trkInfo[nTrk] <<=  8; trkInfo[nTrk] |= trkEta;
			trkInfo[nTrk] <<= 14; trkInfo[nTrk] |= trkPhi;

			trkInfo[nTrk] = trkChg;
			trkInfo[nTrk] <<=  1; trkInfo[nTrk] |= trkQual;
			trkInfo[nTrk] <<=  8; trkInfo[nTrk] |= trkPt;
			trkInfo[nTrk] <<=  8; trkInfo[nTrk] |= trkEta;
			trkInfo[nTrk] <<= 14; trkInfo[nTrk] |= trkPhi;

			tmpInfo= trkInfo[nTrk];
			tmpPhi = detPhi(tmpInfo & 0x3fff); tmpInfo >>= 14;
			tmpEta = detEta(tmpInfo & 0xff);   tmpInfo >>= 8;
			tmpPt  = detPt(tmpInfo & 0xff);    tmpInfo >>= 8;
			tmpQual= tmpInfo & 0x1;            tmpInfo >>= 1;
			tmpChg = tmpInfo & 0x1;

			if(fabs(trkChg-tmpChg)>0 || fabs(trkQual-tmpQual)>0 || fabs(trk_pt->at(iT)/1000-tmpPt)>0.1 || fabs(trk_eta->at(iT)-tmpEta)>0.01 || fabs(trk_phi_wrtPV->at(iT)-tmpPhi)>0.001)
			{
				std::cout<<trkChg<<"  |  "<<trkQual<<"  |  "<<trk_pt->at(iT)/1000<<"  |  "<<trk_eta->at(iT)<<"  |  "<<trk_phi_wrtPV->at(iT)<<std::endl;
				std::cout<<tmpChg<<"  |  "<<tmpQual<<"  |  "<<tmpPt<<"  |  "<<tmpEta<<"  |  "<<tmpPhi<<std::endl;
			}

			nTrk ++;
			if(nTrk>=nTrkMax) break;
		}

		MyTree->Fill(); 
	} 

	outfile->cd();
	MyTree->Write();    
	outfile -> Close();
}


Bool_t extractor::Notify()
{
	return kTRUE;
}

void extractor::Show(Long64_t entry)
{
	if (!fChain) return;
	fChain->Show(entry);
}
Int_t extractor::Cut(Long64_t entry)
{
	return 1;
}



extractor::extractor(string filelist)
{
	TChain* chain     = new TChain("HeavyIonD3PD","");
	TChain* chainMeta = new TChain("HeavyIonD3PDMeta/TrigConfTree");

	char fname[400];
	ifstream lis(filelist.c_str());
	int cnt=0;
	while(!lis.eof()){
		string filename;
		lis >> filename;
		sprintf(fname,"%s",filename.c_str());
		cout << fname << endl;
		if(!filename.empty()) {
			chain    ->Add(fname);
			chainMeta->Add(fname);
		}
		cnt++;
		if(cnt>1000000) {cout<<"Too Many Files"<<endl;break;}
	}

	Init(chain);
	InitMeta(chainMeta);
}

extractor::~extractor()
{
	//if (!fChain) return;
	//delete fChain->GetCurrentFile();
}

Int_t extractor::GetEntry(Long64_t entry)
{
	// Read contents of entry.
	if (!fChain) return 0;
	return fChain->GetEntry(entry);
}
Long64_t extractor::LoadTree(Long64_t entry)
{
	// Set the environment to read one entry
	if (!fChain) return -5;
	Long64_t centry = fChain->LoadTree(entry);
	if (centry < 0) return centry;
	if (fChain->GetTreeNumber() != fCurrent) {
		fCurrent = fChain->GetTreeNumber();
		Notify();
	}
	return centry;
}



void extractor::Fill_Trigger(){
	for(int i=0; i<40; i++) trigPS[i] = 0;
	for(int iT=0; iT<trig_EF_passedPhysics->size(); iT++)
	{
		if(trig_EF_passedPhysics->at(iT) == EF_mbMbts_1_1_counter) 				trigPS[0] = 1;
		if(trig_EF_passedPhysics->at(iT) == EF_mbMbts_2_counter) 					trigPS[1] = 1;
		if(trig_EF_passedPhysics->at(iT) == EF_L1MBTS_1_1_NoAlg_counter)  trigPS[2] = 1;
		if(trig_EF_passedPhysics->at(iT) == EF_L1TE20_NoAlg_counter) 			trigPS[3] = 1;
		if(trig_EF_passedPhysics->at(iT) == EF_L1TE50_NoAlg_counter) 			trigPS[4] = 1;
		if(trig_EF_passedPhysics->at(iT) == EF_L1TE65_NoAlg_counter) 			trigPS[5] = 1;
		if(trig_EF_passedPhysics->at(iT) == EF_L1TE90_NoAlg_counter) 			trigPS[6] = 1;
		if(trig_EF_passedPhysics->at(iT) == EF_L1TE100_NoAlg_counter) 		trigPS[7] = 1;
		if(trig_EF_passedPhysics->at(iT) == EF_hip_trk100_TE10_counter) 	trigPS[8] = 1;
		if(trig_EF_passedPhysics->at(iT) == EF_hip_trk130_TE10_counter) 	trigPS[9] = 1;
		if(trig_EF_passedPhysics->at(iT) == EF_hip_trk150_TE50_counter) 	trigPS[10] = 1;
		if(trig_EF_passedPhysics->at(iT) == EF_hip_trk185_TE50_counter) 	trigPS[11] = 1;
		if(trig_EF_passedPhysics->at(iT) == EF_hip_trk200_TE65_counter) 	trigPS[12] = 1;
		if(trig_EF_passedPhysics->at(iT) == EF_hip_trk225_TE65_counter) 	trigPS[13] = 1;
	}
}

