#define extractor_cxx
// #define DO_RP
#include "extractor.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <stdio.h>
#include <vector>
#include <bitset>

#include "isGoodEvent_PbPb.C"

const double pTmin = 0.2;
const double etaMax = 2.5;
const int nTrkMax = 1000;

UInt_t   runNo;
UInt_t   lbNo;
UInt_t   bcid;
float    trigPS[40];
float    zVtx;
UInt_t   nVtx;
UInt_t   nTrk;
UInt_t   trkInfo[nTrkMax];
float    mPhi[nTrkMax];

const double PI = acos(-1.0);

//98% centrality (Calculated on 22May2013)
static double centcuts[]={
	3.4432,3.2977,3.1648,3.0400,2.9222,2.8101,2.7033,2.6014,2.5038,2.4104,
	2.3208,2.2343,2.1516,2.0715,1.9941,1.9194,1.8473,1.7776,1.7100,1.6448,
	1.5815,1.5203,1.4610,1.4034,1.3479,1.2939,1.2417,1.1910,1.1418,1.0942,
	1.0482,1.0036,0.9604,0.9185,0.8780,0.8388,0.8009,0.7642,0.7288,0.6946,
	0.6615,0.6295,0.5987,0.5689,0.5401,0.5126,0.4859,0.4604,0.4357,0.4120,
	0.3892,0.3674,0.3465,0.3265,0.3073,0.2889,0.2714,0.2546,0.2387,0.2235,
	0.2090,0.1953,0.1822,0.1698,0.1582,0.1471,0.1366,0.1268,0.1175,0.1088,
	0.1005,0.0928,0.0856,0.0789,0.0725,0.0666,0.0611,0.0559,0.0511,0.0467,
	0.0425,0.0386,0.0350,0.0316,0.0285,0.0256,0.0229,0.0203,0.0180,0.0158,
	0.0137,0.0118,0.0100,0.0083,0.0067,0.0051,0.0033,-0.0085,   -1,    -2
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

	TTree *MyTree    = new TTree("tree","Data11 peripheral PbPb 2.76 TeV");
	//------------------------------------------------------
	MyTree->Branch("runNo",    &runNo,    "runNo/i");
	MyTree->Branch("lbNo",     &lbNo,     "lbNo/i");
	MyTree->Branch("bcid",     &bcid,     "bcid/i");
	//MyTree->Branch("trigPS",   trigPS,    "trigPS[40]/F");
	MyTree->Branch("zVtx",     &zVtx,     "zVtx/F");
	MyTree->Branch("nVtx",     &nVtx,     "nVtx/i");
	MyTree->Branch("nTrk",     &nTrk,     "nTrk/i");
	MyTree->Branch("trkInfo",  trkInfo,   "trkInfo[nTrk]/i");
	MyTree->Branch("mPhi",     mPhi,      "mPhi[nTrk]/F");

	//------------------------------------------------------

	fChain->SetBranchStatus("*",0);

	fChain->SetBranchStatus("RunNumber",1);
	fChain->SetBranchStatus("EventNumber",1);
	fChain->SetBranchStatus("bcid",1);
	fChain->SetBranchStatus("lbn",1);

	fChain->SetBranchStatus("trig_L1_TAV",1);
	fChain->SetBranchStatus("trig_L1_TBP",1);

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
	fChain->SetBranchStatus("trk_err_theta_wrtPV",1);
	fChain->SetBranchStatus("trk_d0_wrtBS"    ,1);
	fChain->SetBranchStatus("trk_cov_z0_theta_wrtPV",1);

	//------------------------------------------------------
	fChain->SetBranchStatus("cccEt_Et_Eh_FCal", 1);
	fChain->SetBranchStatus("cccEt_n_Eh_FCal", 1);
	fChain->SetBranchStatus("cccEt_p_Eh_FCal", 1);
	fChain->SetBranchStatus("mbtime_timeA"    , 1);
	fChain->SetBranchStatus("mbtime_timeC"    , 1);

	fChain->SetBranchStatus("mbtime_countA"   , 1);
	fChain->SetBranchStatus("mbtime_countC"   , 1);
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
		if( isGoodEvent(RunNumber,lbn,bcid) !=1 ) continue;
		if( RunNumber == 169884) continue;  //Zero Field
		if( RunNumber == 169866) continue;  //Zero Field
		if( RunNumber == 168875) continue; // not good for pixels
		unsigned int iMBTS_1_1   =  trig_L1_TAV->at(7)&0x10;
		unsigned int iMBTS_2_2   =  trig_L1_TAV->at(6)&0x80000000;
		unsigned int iMBTS_3_3   =  trig_L1_TAV->at(7)&0x1;
		unsigned int iMBTS_4_4   =  trig_L1_TAV->at(0)&0x8000;
		unsigned int iL1_ZDC_AND =  trig_L1_TAV->at(5)&0x20000000 ;
		unsigned int iL1_ZDC_A_C =  trig_L1_TAV->at(6)&0x1 ;
		if( iMBTS_1_1==0 && iMBTS_2_2==0 && iMBTS_3_3==0  && iMBTS_4_4==0 && iL1_ZDC_AND==0 && iL1_ZDC_A_C==0) continue;

		ev_sel++;
		if(ev_sel%1000==0) {cout<<"Selected Event "<<ev_sel<<endl ;}
		Fcal_Et  =(cccEt_Et_Eh_FCal->at(0)+cccEt_Et_Eh_FCal->at(1)+cccEt_Et_Eh_FCal->at(2))/1000.0;  //Fcal energy in MeV
		Fcal_Et_n=(cccEt_n_Eh_FCal ->at(0)+cccEt_n_Eh_FCal ->at(1)+cccEt_n_Eh_FCal ->at(2))/1000.0;
		Fcal_Et_p=(cccEt_p_Eh_FCal ->at(0)+cccEt_p_Eh_FCal ->at(1)+cccEt_p_Eh_FCal ->at(2))/1000.0;

		//mbts timing
		//------------------------------------------------------
		if (vx_n<2)                                       continue;
		if (mbtime_timeA == 75|| mbtime_timeC == 75)      continue;
		else if (mbtime_timeA ==-75|| mbtime_timeC ==-75) continue;
		else if (mbtime_timeA == 0 || mbtime_timeC == 0)  continue;
		else if (fabs(mbtime_timeA-mbtime_timeC) > 3.0)    continue;

		//------------------------------------------------------
		bool tagTrig = false;
		for(int i=0; i<40; i++)
		{
			trigPS[i] = 1;
			if(trigPS[i]>0)
			{
				tagTrig = true;
				break;
			}
		}
		if((trig_L1_TBP->at(5)&0x20000000)== 0  && (trig_L1_TBP->at(6)&0x1)== 0 && Fcal_Et<1000.0) continue;
		//if(!tagTrig) continue;
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
		if(is_pileup==1) continue;

		//------------------------------------------------------------------------------------
		/*
		Mytrk_n=0;
		for(int reco_track=0;reco_track<trk_n;reco_track++)
		{
			UInt_t Quality=0;

			if(trk_pt->at(iT)/1000<pTmin) continue;
			if(fabs(trk_eta->at(iT))>=etaMax) continue;
			if(trk_expectBLayerHit->at(reco_track)==1 && trk_nBLHits->at(reco_track)==0) continue;
			if(trk_pt->at(reco_track)>10000 && TMath::Prob(trk_chi2->at(reco_track),trk_ndof->at(reco_track))<=0.01) continue;

			if (trk_nPixHits -> at(reco_track)        > 0  && //loose
					trk_nSCTHits -> at(reco_track)      > 5  &&
					fabs(trk_d0_wrtPV -> at(reco_track))<1.5 &&
					fabs(trk_z0_wrtPV -> at(reco_track)*sin(trk_theta -> at(reco_track)))<1.5)
			{
				Quality += 1;
			}
			if (trk_nPixHits -> at(reco_track)         > 1    && //tight
					trk_nPixHoles-> at(reco_track)      == 0    &&
					trk_nSCTHits -> at(reco_track)       > 7    &&
					trk_nSCTHoles-> at(reco_track)       < 2    &&
					fabs(trk_d0_wrtPV -> at(reco_track)) < 1.   &&
					fabs(trk_z0_wrtPV -> at(reco_track)*sin(trk_theta -> at(reco_track))) < 1.  &&
					trk_ndof -> at(reco_track) > 0 && trk_chi2 -> at(reco_track)/trk_ndof -> at(reco_track) < 6 )
			{
				Quality += 2;
			}


			Float_t phi,pt,eta;
			phi = trk_phi_wrtPV ->at(reco_track);
			pt  = trk_pt  ->at(reco_track);
			eta = trk_eta ->at(reco_track);
			
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
		*/

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

		bool sctCut = false;
		for(int iT=0; iT<trk_n; iT++)
		{
			//cout<<trk_nBLHits->at(iT)<<" | "<<(trk_patternReco1->at(iT))&1<<" | "<<(trk_patternReco2->at(iT))&16<<endl;
			cout<<trk_nBLHits->at(iT)<<endl;

			if(trk_pt->at(iT)/1000<pTmin) continue;
			if(fabs(trk_eta->at(iT))>=etaMax) continue;

			sctCut = false;
			if(trk_pt->at(iT)>100 && trk_pt->at(iT)<=200 && trk_nSCTHits->at(iT)>=2) sctCut = true;
			if(trk_pt->at(iT)>200 && trk_pt->at(iT)<=300 && trk_nSCTHits->at(iT)>=4) sctCut = true;
			if(trk_pt->at(iT)>300                        && trk_nSCTHits->at(iT)>=6) sctCut = true;
			if(!sctCut) continue;
			if(trk_nPixHits->at(iT)<1) continue;
			if(trk_expectBLayerHit->at(iT)==1 && trk_nBLHits->at(iT)==0) continue;
	
			float d0     = trk_d0_wrtPV->at(iT);
			float z0     = trk_z0_wrtPV->at(iT);
			float theta  = trk_theta->at(iT);
			float e_z0    = trk_err_z0_wrtPV    ->at(iT);
			float e_theta = trk_err_theta_wrtPV ->at(iT);
			float e_d0    = trk_err_d0_wrtPV    ->at(iT);
			float cov     = trk_cov_z0_theta_wrtPV->at(iT);
			float e_z0_sin= sqrt( fabs( pow(e_z0*sin(theta),2.0) + pow(z0*cos(theta)*e_theta,2.0) + 2*sin(theta)*z0*cos(theta)*cov ));

			trkQual = 99;
			if(e_d0!=0.0 && e_z0_sin!=0.0 && fabs(z0*sin(theta)/e_z0_sin)<3 && fabs(d0/e_d0)<3)
			{
				trkQual = 0;
			}
			if(e_d0!=0.0 && e_z0_sin!=0.0 && fabs(z0*sin(theta)/e_z0_sin)<2 && fabs(d0/e_d0)<2)
			{
				trkQual = 1;
			}
			if(trkQual>1) continue;

			if(trk_qoverp->at(iT)>0) trkChg = 1;
			else trkChg = 0;
			trkPt = cvtPt(trk_pt->at(iT));
			trkEta = cvtEta(trk_eta->at(iT));
			trkPhi = cvtPhi(trk_phi_wrtPV->at(iT));
			mPhi[nTrk] = trk_phi_wrtPV->at(iT);

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
		if(nTrk>=nTrkMax) continue;

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



