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

const int mS[6] = {24,25,27,28,30,26};
const int mC[6] = { 4, 2, 1, 6, 3, 7};
const int lS[6] = { 2, 2, 2, 2, 2, 2};
const int lC[6] = { 4, 2, 1, 6, 3, 7};
char name[100];
const int nTrig = 25;
const int maxTrk = 100;
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

	sprintf(name,"data_PbPb1.root");
	TFile *fIn = new TFile(name);
	int RunNumber;
	int lbn;
	int bcid;
	float L1TE;
	float trig[nTrig];
	float trigL1[nTrig];
	int nVtx;
	int trkVtx[50];
	float zVtx[50];
	int nTrk;
	float eta[10000];
	int nEt;
	float et[1000];
	float etaMin[1000];
	float etaMax[1000];
	int nCalo;
	float etCalo[10000];
	float etaCalo[10000];
	TTree *tree = (TTree*)fIn->Get("tree");
	tree->SetBranchAddress("RunNumber",&RunNumber);
	tree->SetBranchAddress("lbn",&lbn);
	tree->SetBranchAddress("bcid",&bcid);
	tree->SetBranchAddress("L1TE",&L1TE);
	tree->SetBranchAddress("trig",trig);
	tree->SetBranchAddress("trigL1",trigL1);
	tree->SetBranchAddress("nVtx",&nVtx);
	tree->SetBranchAddress("trkVtx",trkVtx);
	tree->SetBranchAddress("zVtx",zVtx);
	tree->SetBranchAddress("nTrk",&nTrk);
	tree->SetBranchAddress("eta",eta);
	tree->SetBranchAddress("nEt",&nEt);
	tree->SetBranchAddress("et",et);
	tree->SetBranchAddress("etaMin",etaMin);
	tree->SetBranchAddress("etaMax",etaMax);
	int nEvt = tree->GetEntries();

	TH2D *hZDC_A_C = new TH2D("hZDC_A_C","ZDC_A : ZDC_C",2,-0.5,1.5,2,-0.5,1.5);
	TH2D *hGapEt_fst = new TH2D("hGapEt_fst","",100,-5,5,820,-10,400);
	TH2D *hGapEt_zoom_fst = new TH2D("hGapEt_zoom_fst","",100,-5,5,100,-5,5);
	TH2D *hGapEt_lst = new TH2D("hGapEt_lst","",100,-5,5,820,-10,400);
	TH2D *hGapEt_zoom_lst = new TH2D("hGapEt_zoom_lst","",100,-5,5,100,-5,5);

	TH1D *hGap_tmp = new TH1D("hGap_tmp","",100,-5,5);
	int tagFst;
	int tagLst;
	double etTmp[100];
	for(int iEvt=0; iEvt<nEvt; iEvt++)
	{
		if(iEvt%1000==0)
		{
			for(int i=0; i<100.*iEvt/nEvt; i++) cout<<"#";
			cout<<">>>";
			for(int i=100.*iEvt/nEvt; i<100-1; i++) cout<<"-";
			cout<<'\r';
		}
		tree->GetEntry(iEvt);
		
		nEt = 562;

		tagFst = 0;
		tagLst = 0;
		for(int i=0; i<20; i++)
		{
			if(RunNumber==286767)
			{
				if(bcid==tagBCIDfst[0][i]) tagFst = 1;
				if(bcid==tagBCIDlst[0][i]) tagLst = 1;
			}
			if(RunNumber==286834)
			{
				if(bcid==tagBCIDfst[1][i]) tagFst = 1;
				if(bcid==tagBCIDlst[1][i]) tagLst = 1;
			}
		}

		if(trig[20]<0) continue;
		if(tagFst==0 && tagLst==0) continue;

		if(trigL1[3]==0 && trigL1[4]==0) hZDC_A_C->Fill(0.,0.);
		if(trigL1[3]>0 && trigL1[4]==0) hZDC_A_C->Fill(1.,0.);
		if(trigL1[3]==0 && trigL1[4]>0) hZDC_A_C->Fill(0.,1.);
		if(trigL1[3]>0 && trigL1[4]>0) hZDC_A_C->Fill(1.,1.);

		for(int i=0; i<100; i++) etTmp[i] = 0;
		//for(int i=0; i<nEt; i++) hGap_tmp->Fill((etaMin[i]+etaMax[i])/2,et[i]);		
		for(int i=0; i<nEt; i++)
		{
			for(int j=0; j<100; j++)
			{
				if(-5+j*0.1<=(etaMin[i]+etaMax[i])/2 && -5+(j+1)*0.1>(etaMin[i]+etaMax[i])/2) etTmp[j] += et[i];
			}
		}

		for(int i=0; i<100; i++)
		{
			if(tagFst==1)
			{
				hGapEt_fst->Fill(-5+(2*i+1)*0.05,etTmp[i]);
				hGapEt_zoom_fst->Fill(-5+(2*i+1)*0.05,etTmp[i]);
			}
			if(tagLst==1)
			{
				hGapEt_lst->Fill(-5+(2*i+1)*0.05,etTmp[i]);
				hGapEt_zoom_lst->Fill(-5+(2*i+1)*0.05,etTmp[i]);
			}
		}
	}

	TFile *fOut = new TFile("hist_BCID.root","RECREATE");
	fOut->cd();
	hZDC_A_C->Write();
	hGapEt_fst->Write();
	hGapEt_zoom_fst->Write();
	hGapEt_lst->Write();
	hGapEt_zoom_lst->Write();
	fOut->Close();
}



//----------------------------------------------------
// Draw ET
//----------------------------------------------------
void drawCorr(int OPT)
{
	TFile *fIn = new TFile("hist_BCID.root");
	TH2D *hCorr[2];
	for(int i=0; i<2; i++)
	{
		if(OPT==0 && i==0) sprintf(name,"hGapEt_fst");
		if(OPT==1 && i==0) sprintf(name,"hGapEt_zoom_fst");
		if(OPT==0 && i==1) sprintf(name,"hGapEt_lst");
		if(OPT==1 && i==1) sprintf(name,"hGapEt_zoom_lst");
		hCorr[i] = (TH2D*)fIn->Get(name);
		styleHist2(hCorr[i]);
	}
	
	TLatex *tex = new TLatex();
	tex->SetTextSize(0.04);
	tex->SetTextAlign(12);
	tex->SetNDC(1);

	TCanvas *cOut = new TCanvas("cOut","",800,400);
	cOut->Divide(2,1,0.0001,0.0001);
	gStyle->SetOptStat(0);
	gStyle->SetNumberContours(100);
	for(int iC=0; iC<2; iC++)
	{
		cOut->cd(iC+1);
		gPad->SetLogz(1);
		gPad->SetTicks(1,1);
		gPad->SetTopMargin(0.05);
		gPad->SetBottomMargin(0.1);
		gPad->SetLeftMargin(0.1);
		gPad->SetRightMargin(0.05);

		hCorr[iC]->GetXaxis()->SetTitle("#eta");
		hCorr[iC]->GetXaxis()->SetTitleOffset(1.25);
		hCorr[iC]->GetXaxis()->SetRangeUser(-5,5);
		hCorr[iC]->GetYaxis()->SetTitle("E_{T}");
		hCorr[iC]->GetYaxis()->SetTitleOffset(1.25);
		if(OPT==0) hCorr[iC]->GetYaxis()->SetRangeUser(-10,100);
		hCorr[iC]->Draw("COL");

		if(iC==0)
		{
			if(OPT==0)
			{
				tex->DrawLatex(0.175,0.85,"#font[72]{ATLAS}  #font[42]{Internal}");
				tex->SetTextFont(42);
				tex->DrawLatex(0.175,0.775,"#font[12]{PbPb} #sqrt{s}=5.02TeV");
			}
		}
		if(OPT==0 && iC==0) tex->DrawLatex(0.65,0.85,"#font[72]{First bunch}");
		if(OPT==0 && iC==1) tex->DrawLatex(0.65,0.85,"#font[72]{Last bunch}");
		if(OPT==1 && iC==0) tex->DrawLatex(0.75,0.15,"#font[72]{First bunch}");
		if(OPT==1 && iC==1) tex->DrawLatex(0.75,0.15,"#font[72]{Last bunch}");
	}
	
	if(OPT==0) cOut->Print("CorrEt_fst.pdf");
	if(OPT==1) cOut->Print("CorrEt_lst.pdf");
}



//----------------------------------------------------
// Macro
//----------------------------------------------------
void drawBCID()
{
	gen();

	for(int i=0; i<2; i++) drawCorr(i);
}
















