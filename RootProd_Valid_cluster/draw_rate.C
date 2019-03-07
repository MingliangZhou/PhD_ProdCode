#include <iostream>
#include <iomanip>
#include <math.h>

#include "TH1.h"
#include "TH2.h"
#include "TF1.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TLine.h"
#include "TLatex.h"
#include "TTree.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TRandom.h"
#include "TMath.h"

#include "isGoodEvent_PbPb2015.C"

const int mS[6] = {24,25,27,28,30,26};
const int mC[6] = { 4, 2, 1, 6, 3, 7};
const int lS[6] = { 2, 2, 2, 2, 2, 2};
const int lC[6] = { 4, 2, 1, 6, 3, 7};
char name[100];
const int nTrig = 25;
const int maxTrk = 20;
const double PI = TMath::Pi();

//----------------------------------------------------
// Draw Options Setup
//----------------------------------------------------
static void styleHist1(TH1 *hIn)
{
	hIn->SetTitle("");
	hIn->SetTitleSize(15);
	hIn->GetYaxis()->CenterTitle();         hIn->GetXaxis()->CenterTitle();
	hIn->GetYaxis()->SetTitleOffset(1.);    hIn->GetXaxis()->SetTitleOffset(1.);
	hIn->GetYaxis()->SetTitleFont(43);      hIn->GetYaxis()->SetTitleSize(15);
	hIn->GetYaxis()->SetLabelFont(43);      hIn->GetYaxis()->SetLabelSize(15);
	hIn->GetXaxis()->SetTitleFont(43);      hIn->GetXaxis()->SetTitleSize(15);
	hIn->GetXaxis()->SetLabelFont(43);      hIn->GetXaxis()->SetLabelSize(15);
	hIn->GetZaxis()->SetLabelFont(43);      hIn->GetZaxis()->SetLabelSize(15);
}
static void styleHist2(TH2 *hIn)
{
	hIn->SetTitle("");
	hIn->SetTitleSize(15);
	hIn->GetYaxis()->CenterTitle();         hIn->GetXaxis()->CenterTitle();
	hIn->GetYaxis()->SetNdivisions(505);    hIn->GetXaxis()->SetNdivisions(505);
	hIn->GetYaxis()->SetTitleOffset(1.);    hIn->GetXaxis()->SetTitleOffset(1.);
	hIn->GetYaxis()->SetTitleFont(43);      hIn->GetYaxis()->SetTitleSize(15);
	hIn->GetYaxis()->SetLabelFont(43);      hIn->GetYaxis()->SetLabelSize(15);
	hIn->GetXaxis()->SetTitleFont(43);      hIn->GetXaxis()->SetTitleSize(15);
	hIn->GetXaxis()->SetLabelFont(43);      hIn->GetXaxis()->SetLabelSize(15);
	hIn->GetZaxis()->SetLabelFont(43);      hIn->GetZaxis()->SetLabelSize(15);
}
static void styleGraph1(TGraph *hIn)
{
	hIn->SetTitle("");
	hIn->GetYaxis()->CenterTitle();         hIn->GetXaxis()->CenterTitle();
	hIn->GetYaxis()->SetTitleOffset(1.);    hIn->GetXaxis()->SetTitleOffset(1.);
	hIn->GetYaxis()->SetTitleFont(43);      hIn->GetYaxis()->SetTitleSize(15);
	hIn->GetYaxis()->SetLabelFont(43);      hIn->GetYaxis()->SetLabelSize(15);
	hIn->GetXaxis()->SetTitleFont(43);      hIn->GetXaxis()->SetTitleSize(15);
	hIn->GetXaxis()->SetLabelFont(43);      hIn->GetXaxis()->SetLabelSize(15);
}



//----------------------------------------------------
// Generate all needed histograms
//----------------------------------------------------
void gen()
{
	const int tagBCIDfst[2][20] = {
		{   1, 184, 892,1075,1783,1966,2674,2857,3043,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
		{  12, 104, 287, 446, 629, 812, 995,1178,1520,1703,1886,2069,2228,2411,2594,2777,2960,3119,  -1,  -1},
	};
	const int tagBCIDlst[2][20] = {
		{ 148, 331,1039,1222,1930,2113,2821,3004,3190,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1},
		{  68, 251, 408, 593, 776, 959,1142,1286,1667,1850,2033,2190,2375,2558,2741,2924,3081,3266,  -1,  -1},
	};

	const char *trigLabel[nTrig] = {
		"L1_RD0_FILLED",												// 0
		"L1_ZDC_A_C",														// 1
		"L1_ZDC_AND",														// 2
		"L1_ZDC_A",															// 3
		"L1_ZDC_C",															// 4
		"L1_MBTS_1",														// 5
		"L1_MBTS_1_1",													// 6
		"L1_MBTS_2_2",													// 7
		"L1_TE5",																// 8
		"L1_TE10",															// 9
		"L1_TE20",															// 10
		"L1_TE30",															// 11
		"L1_TE40",															// 12
		"L1_TE50",															// 13
		"L1_TE60",															// 14
		"L1_TE70",															// 15
		"L1_ZDC_A_C_VTE50",											// 16
		"L1_TE5_VTE200",												// 17
		"HLT_noalg_mb_L1TE50",									// 18
		"HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50",			// 19
		"HLT_mb_sp",														// 20
		"HLT_hi_th1_ucc_L1TE14000",							// 21
		"HLT_hi_th2_ucc_L1TE14000",							// 22
		"HLT_hi_th3_ucc_L1TE14000",							// 23
		"L1_ZDC_XOR",
	};

	sprintf(name,"data_PbPb.root");
	TFile *fIn = new TFile(name);
	int RunNumber;
	int lbn;
	int bcid;
	int EvtNumber;
	float trig[nTrig];
	float trigL1[nTrig];
	int nVtx;
	int trkVtx[50];
	float xVtx[50];
	float yVtx[50];
	float zVtx[50];
	int nTrk;
	float pt[20000];
	float eta[20000];
	float phi[20000];
	float chg[20000];
	int nEt;
	float et[1000];
	float etaMin[1000];
	float etaMax[1000];
	TTree *tree = (TTree*)fIn->Get("tree");
	tree->SetBranchAddress("RunNumber",&RunNumber);
	tree->SetBranchAddress("lbn",&lbn);
	tree->SetBranchAddress("bcid",&bcid);
	tree->SetBranchAddress("trig",trig);
	tree->SetBranchAddress("trigL1",trigL1);
	tree->SetBranchAddress("nVtx",&nVtx);
	tree->SetBranchAddress("zVtx",zVtx);
	tree->SetBranchAddress("nTrk",&nTrk);
	tree->SetBranchAddress("nEt",&nEt);
	tree->SetBranchAddress("et",et);
	tree->SetBranchAddress("etaMin",etaMin);
	tree->SetBranchAddress("etaMax",etaMax);
	//tree->SetBranchAddress("eta",eta);
	//tree->SetBranchAddress("pt",pt);
	int nEvt = tree->GetEntries();
	//nEvt = 50000;

	int HLT_mb_sp = 0;
	int HLT_mb_sp_trk = 0;
	int HLT_mb_sp_vtx = 0;

	int L1_TE50 = 0;
	int L1_TE50_trk = 0;
	int L1_TE50_vtx = 0;

	int L1_ZDC_A_C = 0;
	int L1_ZDC_A_C_trk = 0;
	int L1_ZDC_A_C_vtx = 0;
	
	int L1_ZDC_A_C_VTE50 = 0;
	int L1_ZDC_A_C_VTE50_trk = 0;
	int L1_ZDC_A_C_VTE50_vtx = 0;
	
	int HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50;
	int HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50_trk;
	int HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50_vtx;

	int L1_ZDC_XOR = 0;
	int L1_ZDC_XOR_trk = 0;
	int L1_ZDC_XOR_vtx = 0;

	int L1_TE5_VTE200 = 0;
	int L1_TE5_VTE200_trk = 0;
	int L1_TE5_VTE200_vtx = 0;

	int L1_MBTS_1 = 0;
	int L1_MBTS_1_trk = 0;
	int L1_MBTS_1_vtx = 0;

	int L1_MBTS_1_1 = 0;
	int L1_MBTS_1_1_trk = 0;
	int L1_MBTS_1_1_vtx = 0;

	int L1_MBTS_2_2 = 0;
	int L1_MBTS_2_2_trk = 0;
	int L1_MBTS_2_2_vtx = 0;

	TH1D *hFCal[nTrig][7];
	for(int i=0; i<nTrig; i++)
	{
		for(int j=0; j<7; j++)
		{
			sprintf(name,"hFCal_Trig%d_Cut%d",i,j);
			hFCal[i][j] = new TH1D(name,name,1220,-0.1,6);
			hFCal[i][j]->Sumw2();
		}
	}

	double FCal;
	cout<<"Processing..."<<endl;
	for(int iEvt=nEvt-1; iEvt>=0; iEvt--)
	{
		if(iEvt%10000==0)
		{
		cout<<iEvt<<"/"<<nEvt<<endl;
		/*
			for(int i=0; i<100.*iEvt/nEvt; i++) cout<<"#";
			cout<<">>>";
			for(int i=100.*iEvt/nEvt; i<100-1; i++) cout<<"-";
			cout<<'\r';
		*/
		}
		tree->GetEntry(iEvt);

		if(!isGoodEvent_PbPb2015(RunNumber,lbn,bcid)) continue;
		if(trig[20]<=0) continue;

		for(int j=0; j<nTrig-1; j++)
		{
			FCal = 0;
			if(trigL1[j]>0)
			{
				for(int i=0; i<nEt; i++)
				{
					if(fabs((etaMin[i]+etaMax[i])/2)>=3.2) FCal += et[i]/1000;
				}
				hFCal[j][0]->Fill(FCal);
				if(nTrk>0) hFCal[j][1]->Fill(FCal);
				if(zVtx[0]!=9999) hFCal[j][2]->Fill(FCal);
				if(nTrk>=1 && zVtx[0]!=9999) hFCal[j][3]->Fill(FCal);
				if(nTrk>=2 && zVtx[0]!=9999) hFCal[j][4]->Fill(FCal);
				if(nTrk>=3 && zVtx[0]!=9999) hFCal[j][5]->Fill(FCal);
				if(nTrk>=4 && zVtx[0]!=9999) hFCal[j][6]->Fill(FCal);
			}
		}
		FCal = 0;
		if((trigL1[3]>0 && trigL1[4]==0) || (trigL1[3]==0 && trigL1[4]>0))
		{
			for(int i=0; i<nEt; i++)
			{
				if(fabs((etaMin[i]+etaMax[i])/2)>=3.2) FCal += et[i]/1000;
			}
			hFCal[24][0]->Fill(FCal);
			if(nTrk>0) hFCal[24][1]->Fill(FCal);
			if(zVtx[0]!=9999) hFCal[24][2]->Fill(FCal);
			if(nTrk>=1 && zVtx[0]!=9999) hFCal[24][3]->Fill(FCal);
			if(nTrk>=2 && zVtx[0]!=9999) hFCal[24][4]->Fill(FCal);
			if(nTrk>=3 && zVtx[0]!=9999) hFCal[24][5]->Fill(FCal);
			if(nTrk>=4 && zVtx[0]!=9999) hFCal[24][6]->Fill(FCal);
		}

		HLT_mb_sp ++;
		if(trigL1[13]>0) L1_TE50 ++;
		if(trigL1[1]>0) L1_ZDC_A_C ++;
		if(trigL1[16]>0) L1_ZDC_A_C_VTE50 ++;
		if(trigL1[16]>0 && nTrk!=0) HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50 ++;
		if((trigL1[3]>0 && trigL1[4]==0) || (trigL1[3]==0 && trigL1[4]>0)) L1_ZDC_XOR ++;
		if(trigL1[17]>0) L1_TE5_VTE200 ++;
		if(trigL1[5]>0) L1_MBTS_1 ++;
		if(trigL1[6]>0) L1_MBTS_1_1 ++;
		if(trigL1[7]>0) L1_MBTS_2_2 ++;

		if(nTrk==0)
		{
			HLT_mb_sp_trk ++;
			if(trigL1[13]>0) L1_TE50_trk ++;
			if(trigL1[1]>0) L1_ZDC_A_C_trk ++;
			if(trigL1[16]>0) L1_ZDC_A_C_VTE50_trk ++;
			if(trigL1[16]>0 && nTrk!=0) HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50_trk ++;
			if((trigL1[3]>0 && trigL1[4]==0) || (trigL1[3]==0 && trigL1[4]>0)) L1_ZDC_XOR_trk ++;
			if(trigL1[17]>0) L1_TE5_VTE200_trk ++;
			if(trigL1[5]>0) L1_MBTS_1_trk ++;
			if(trigL1[6]>0) L1_MBTS_1_1_trk ++;
			if(trigL1[7]>0) L1_MBTS_2_2_trk ++;
		}

		if(zVtx[0]==9999)
		{
			HLT_mb_sp_vtx ++;
			if(trigL1[13]>0) L1_TE50_vtx ++;
			if(trigL1[1]>0) L1_ZDC_A_C_vtx ++;
			if(trigL1[16]>0) L1_ZDC_A_C_VTE50_vtx ++;
			if(trigL1[16]>0 && nTrk!=0) HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50_vtx ++;
			if((trigL1[3]>0 && trigL1[4]==0) || (trigL1[3]==0 && trigL1[4]>0)) L1_ZDC_XOR_vtx ++;
			if(trigL1[17]>0) L1_TE5_VTE200_vtx ++;
			if(trigL1[5]>0) L1_MBTS_1_vtx ++;
			if(trigL1[6]>0) L1_MBTS_1_1_vtx ++;
			if(trigL1[7]>0) L1_MBTS_2_2_vtx ++;
		}
		//if(HLT_mb_sp>=1000) break;
	}
	cout<<"Done!"<<endl;

	cout<<endl;
	cout<<endl;
	cout<<"HLT_mb_sp     | "<<100.*HLT_mb_sp/HLT_mb_sp<<"%"<<endl;
	cout<<"HLT_mb_sp_trk | "<<100.*HLT_mb_sp_trk/HLT_mb_sp<<"%"<<endl;
	cout<<"HLT_mb_sp_vtx | "<<100.*HLT_mb_sp_vtx/HLT_mb_sp<<"%"<<endl;
	cout<<endl;
	cout<<"L1_TE50     | "<<100.*L1_TE50/HLT_mb_sp<<"%"<<endl;
	cout<<"L1_TE50_trk | "<<100.*L1_TE50_trk/L1_TE50<<"%"<<endl;
	cout<<"L1_TE50_vtx | "<<100.*L1_TE50_vtx/L1_TE50<<"%"<<endl;
	cout<<endl;
	cout<<"L1_ZDC_A_C     | "<<100.*L1_ZDC_A_C/HLT_mb_sp<<"%"<<endl;
	cout<<"L1_ZDC_A_C_trk | "<<100.*L1_ZDC_A_C_trk/L1_ZDC_A_C<<"%"<<endl;
	cout<<"L1_ZDC_A_C_vtx | "<<100.*L1_ZDC_A_C_vtx/L1_ZDC_A_C<<"%"<<endl;
	cout<<endl;
	cout<<"L1_ZDC_A_C_VTE50     | "<<100.*L1_ZDC_A_C_VTE50/HLT_mb_sp<<"%"<<endl;
	cout<<"L1_ZDC_A_C_VTE50_trk | "<<100.*L1_ZDC_A_C_VTE50_trk/L1_ZDC_A_C_VTE50<<"%"<<endl;
	cout<<"L1_ZDC_A_C_VTE50_vtx | "<<100.*L1_ZDC_A_C_VTE50_vtx/L1_ZDC_A_C_VTE50<<"%"<<endl;
	cout<<endl;
	cout<<"HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50     | "<<100.*HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50/HLT_mb_sp<<"%"<<endl;
	cout<<"HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50_trk | "<<100.*HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50_trk/HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50<<"%"<<endl;
	cout<<"HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50_vtx | "<<100.*HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50_vtx/HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50<<"%"<<endl;
	cout<<endl;
	cout<<"L1_ZDC_XOR     | "<<100.*L1_ZDC_XOR/HLT_mb_sp<<"%"<<endl;
	cout<<"L1_ZDC_XOR_trk | "<<100.*L1_ZDC_XOR_trk/L1_ZDC_XOR<<"%"<<endl;
	cout<<"L1_ZDC_XOR_vtx | "<<100.*L1_ZDC_XOR_vtx/L1_ZDC_XOR<<"%"<<endl;
	cout<<endl;
	cout<<"L1_TE5_VTE200     | "<<100.*L1_TE5_VTE200/HLT_mb_sp<<"%"<<endl;
	cout<<"L1_TE5_VTE200_trk | "<<100.*L1_TE5_VTE200_trk/L1_TE5_VTE200<<"%"<<endl;
	cout<<"L1_TE5_VTE200_vtx | "<<100.*L1_TE5_VTE200_vtx/L1_TE5_VTE200<<"%"<<endl;
	cout<<endl;
	cout<<"L1_MBTS_1     | "<<100.*L1_MBTS_1/HLT_mb_sp<<"%"<<endl;
	cout<<"L1_MBTS_1_trk | "<<100.*L1_MBTS_1_trk/L1_MBTS_1<<"%"<<endl;
	cout<<"L1_MBTS_1_vtx | "<<100.*L1_MBTS_1_vtx/L1_MBTS_1<<"%"<<endl;
	cout<<endl;
	cout<<"L1_MBTS_1_1     | "<<100.*L1_MBTS_1_1/HLT_mb_sp<<"%"<<endl;
	cout<<"L1_MBTS_1_1_trk | "<<100.*L1_MBTS_1_1_trk/L1_MBTS_1_1<<"%"<<endl;
	cout<<"L1_MBTS_1_1_vtx | "<<100.*L1_MBTS_1_1_vtx/L1_MBTS_1_1<<"%"<<endl;
	cout<<endl;
	cout<<"L1_MBTS_2_2     | "<<100.*L1_MBTS_2_2/HLT_mb_sp<<"%"<<endl;
	cout<<"L1_MBTS_2_2_trk | "<<100.*L1_MBTS_2_2_trk/L1_MBTS_2_2<<"%"<<endl;
	cout<<"L1_MBTS_2_2_vtx | "<<100.*L1_MBTS_2_2_vtx/L1_MBTS_2_2<<"%"<<endl;
	cout<<endl;

	TFile *fOut = new TFile("hist_fcal.root","recreate");
	fOut->cd();
	for(int i=0; i<nTrig; i++)
	{
		for(int j=0; j<7; j++) hFCal[i][j]->Write();
	}
	fOut->Close();
}

//----------------------------------------------------
// Efficiency for L1TE
//----------------------------------------------------
void drawEff(int OPT)
{
	TFile *fIn = new TFile("hist_fcal.root");
	TH1D *hFCal[7];
	for(int i=0; i<7; i++)
	{
		sprintf(name,"hFCal_Trig%d_Cut%d",OPT,i);
		hFCal[i] = (TH1D*)fIn->Get(name);
	}
	TH1D *hRef = (TH1D*)hFCal[0]->Clone("hRef");
	//hRef->Rebin(2);
	TH1D *hChk[5];
	for(int i=0; i<5; i++)
	{
		hChk[i] = (TH1D*)hFCal[i+1]->Clone("hChk");
		hChk[i]->Divide(hRef);
	}
	
	TGraphAsymmErrors *gTrig[5];
	double x[hRef->GetNbinsX()];
	double y[hRef->GetNbinsX()];
	double yElw[hRef->GetNbinsX()];
	double yEup[hRef->GetNbinsX()];
	for(int iTrig=0; iTrig<5; iTrig++)
	{
		for(int i=0; i<hRef->GetNbinsX(); i++)
		{
			x[i] = hChk[iTrig]->GetBinCenter(i+1);
			y[i] = hChk[iTrig]->GetBinContent(i+1);
			yElw[i] = hChk[iTrig]->GetBinError(i+1);
			yEup[i] = hChk[iTrig]->GetBinError(i+1);
			if(y[i]+yEup[i]>=1) yEup[i] = 1-y[i];
			if(y[i]-yElw[i]<=0) yElw[i] = y[i];
		}
		gTrig[iTrig] = new TGraphAsymmErrors(hRef->GetNbinsX(),x,y,0,0,yElw,yEup);
		styleGraph1(gTrig[iTrig]);
		gTrig[iTrig]->SetMarkerStyle(mS[iTrig]);
		gTrig[iTrig]->SetMarkerColor(mC[iTrig]);
		gTrig[iTrig]->SetLineStyle(lS[iTrig]);
		gTrig[iTrig]->SetLineColor(lC[iTrig]);
	}

	TLatex *tex = new TLatex();
	tex->SetTextSize(0.04);
	tex->SetTextAlign(12);
	tex->SetNDC(1);
	TLine *lin = new TLine();
	lin->SetLineStyle(lS[0]);
	lin->SetLineColor(lC[0]);
	TLegend *leg = new TLegend(0.575,0.25,0.925,0.55);
	leg->SetBorderSize(0);
	leg->SetFillColor(0);
	leg->AddEntry(gTrig[0],"N_{ch}>=1","lep");
	leg->AddEntry(gTrig[1],"N_{vtx}^{pri}=1","lep");
	leg->AddEntry(gTrig[2],"N_{ch}>=1 & N_{vtx}^{pri}=1","lep");
	leg->AddEntry(gTrig[3],"N_{ch}>=2 & N_{vtx}^{pri}=1","lep");
	leg->AddEntry(gTrig[4],"N_{ch}>=3 & N_{vtx}^{pri}=1","lep");
	
	TCanvas *cOut = new TCanvas("cOut","",400,400); 
	gStyle->SetOptStat(0);
	cOut->cd();
	gPad->SetTicks(1,1);
	gPad->SetTopMargin(0.1);
	gPad->SetBottomMargin(0.125);
	gPad->SetLeftMargin(0.125);
	gPad->SetRightMargin(0.05);
	for(int i=0; i<5; i++)
	{
		if(i==0)
		{
			gTrig[i]->GetXaxis()->SetRangeUser(-0.02,0.05);
			gTrig[i]->GetXaxis()->SetTitle("FCal E_{T}");
			gTrig[i]->GetXaxis()->SetTitleOffset(1.2);
			gTrig[i]->GetYaxis()->SetRangeUser(0,1.05);
			gTrig[i]->GetYaxis()->SetTitle("Efficiency");
			gTrig[i]->GetYaxis()->SetTitleOffset(1.5);
			if(OPT==0) gTrig[i]->SetTitle("L1_RD0_FILLED.pdf");
			if(OPT==1) gTrig[i]->SetTitle("L1_ZDC_A_C.pdf");
			if(OPT==2) gTrig[i]->SetTitle("L1_ZDC_AND.pdf");
			if(OPT==3) gTrig[i]->SetTitle("L1_ZDC_A");
			if(OPT==4) gTrig[i]->SetTitle("L1_ZDC_C");
			if(OPT==5) gTrig[i]->SetTitle("L1_MBTS_1");
			if(OPT==6) gTrig[i]->SetTitle("L1_MBTS_1_1");
			if(OPT==7) gTrig[i]->SetTitle("L1_MBTS_2_2");
			if(OPT==8) gTrig[i]->SetTitle("L1_TE5");
			if(OPT==9) gTrig[i]->SetTitle("L1_TE10");
			if(OPT==10) gTrig[i]->SetTitle("L1_TE20");
			if(OPT==11) gTrig[i]->SetTitle("L1_TE30");
			if(OPT==12) gTrig[i]->SetTitle("L1_TE40");
			if(OPT==13) gTrig[i]->SetTitle("L1_TE50");
			if(OPT==14) gTrig[i]->SetTitle("L1_TE60");
			if(OPT==15) gTrig[i]->SetTitle("L1_TE70");
			if(OPT==16) gTrig[i]->SetTitle("L1_ZDC_A_C_VTE50");
			if(OPT==17) gTrig[i]->SetTitle("L1_TE5_VTE200");
			if(OPT==18) gTrig[i]->SetTitle("HLT_noalg_mb_L1TE50");
			if(OPT==19) gTrig[i]->SetTitle("HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50");
			if(OPT==20) gTrig[i]->SetTitle("HLT_mb_sp");
			if(OPT==21) gTrig[i]->SetTitle("HLT_hi_th1_ucc_L1TE14000");
			if(OPT==22) gTrig[i]->SetTitle("HLT_hi_th2_ucc_L1TE14000");
			if(OPT==23) gTrig[i]->SetTitle("HLT_hi_th3_ucc_L1TE14000");
			if(OPT==24) gTrig[i]->SetTitle("L1_ZDC_XOR");
			gTrig[i]->Draw("APL");
		}
		else gTrig[i]->Draw("PL");
	}
	lin->DrawLine(-0.02,1,0.05,1);
	leg->Draw();
	tex->DrawLatex(0.15,0.85,"#font[72]{ATLAS}  #font[42]{Internal}");
	tex->SetTextFont(42);
	tex->DrawLatex(0.15,0.775,"#font[12]{Pb+Pb} #sqrt{s}=5TeV");

	if(OPT==0) cOut->Print("fcal_eff_L1_RD0_FILLED.pdf");
	if(OPT==1) cOut->Print("fcal_eff_L1_ZDC_A_C.pdf");
	if(OPT==2) cOut->Print("fcal_eff_L1_ZDC_AND.pdf");
	if(OPT==3) cOut->Print("fcal_eff_L1_ZDC_A.pdf");
	if(OPT==4) cOut->Print("fcal_eff_L1_ZDC_C.pdf");
	if(OPT==5) cOut->Print("fcal_eff_L1_MBTS_1.pdf");
	if(OPT==6) cOut->Print("fcal_eff_L1_MBTS_1_1.pdf");
	if(OPT==7) cOut->Print("fcal_eff_L1_MBTS_2_2.pdf");
	if(OPT==8) cOut->Print("fcal_eff_L1_TE5.pdf");
	if(OPT==9) cOut->Print("fcal_eff_L1_TE10.pdf");
	if(OPT==10) cOut->Print("fcal_eff_L1_TE20.pdf");
	if(OPT==11) cOut->Print("fcal_eff_L1_TE30.pdf");
	if(OPT==12) cOut->Print("fcal_eff_L1_TE40.pdf");
	if(OPT==13) cOut->Print("fcal_eff_L1_TE50.pdf");
	if(OPT==14) cOut->Print("fcal_eff_L1_TE60.pdf");
	if(OPT==15) cOut->Print("fcal_eff_L1_TE70.pdf");
	if(OPT==16) cOut->Print("fcal_eff_L1_ZDC_A_C_VTE50.pdf");
	if(OPT==17) cOut->Print("fcal_eff_L1_TE5_VTE200.pdf");
	if(OPT==18) cOut->Print("fcal_eff_HLT_noalg_mb_L1TE50.pdf");
	if(OPT==19) cOut->Print("fcal_eff_HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50.pdf");
	if(OPT==20) cOut->Print("fcal_eff_HLT_mb_sp.pdf");
	if(OPT==21) cOut->Print("fcal_eff_HLT_hi_th1_ucc_L1TE14000.pdf");
	if(OPT==22) cOut->Print("fcal_eff_HLT_hi_th2_ucc_L1TE14000.pdf");
	if(OPT==23) cOut->Print("fcal_eff_HLT_hi_th3_ucc_L1TE14000.pdf");
	if(OPT==24) cOut->Print("fcal_eff_L1_ZDC_XOR.pdf");
}



//----------------------------------------------------
// Macro
//----------------------------------------------------
void draw_rate()
{
	//gen();

	for(int iTrig=0; iTrig<nTrig; iTrig++) drawEff(iTrig);
}















