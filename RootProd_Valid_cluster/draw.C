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
	const char *trigLabel[nTrig] = {
		"L1RD0_FILLED",
		"L1_ZDC_A_C",
		"L1_ZDC_AND",
		"L1_ZDC_C",
		"L1_ZDC_A",
		"L1_MBTS_1",
		"L1_MBTS_1_1",
		"L1_MBTS_2_2",
		"L1_TE5",
		"L1_TE10",
		"L1_TE20",
		"L1_TE30",
		"L1_TE40",
		"L1_TE50",
		"L1_TE60",
		"L1_TE70",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		};

	sprintf(name,"myaod.root");
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
	float pt[1000];
	float eta[1000];
	float phi[1000];
	float chg[1000];
	TTree *tree = (TTree*)fIn->Get("tree");
	tree->SetBranchAddress("trig",trig);
	tree->SetBranchAddress("trigL1",trigL1);
	tree->SetBranchAddress("nTrk",&nTrk);
	int nEvt = tree->GetEntries();

	TH1D *hTrigRate = new TH1D("hTrigRate","hTrigRate",nTrig+1,-1.5,nTrig-0.5);
	hTrigRate->GetXaxis()->SetBinLabel(1,"all");
	for (int i=1; i<=nTrig; i++) hTrigRate->GetXaxis()->SetBinLabel(i+1,trigLabel[i-1]);
	TH1D *hTrk_L1[nTrig];
	TH1D *hTrk_mbL1[nTrig];
	TH1D *hTrk_psL1[nTrig];
	TH1D *hTrk_HLT[nTrig];
	TH1D *hTrk_mbHLT[nTrig];
	TH1D *hTrk_psHLT[nTrig];
	for(int iTrig=0; iTrig<nTrig; iTrig++)
	{
		sprintf(name,"hTrk_L1_%d",iTrig);
		hTrk_L1[iTrig] = new TH1D(name,name,2000,0,2000);
		hTrk_L1[iTrig]->Sumw2();
		sprintf(name,"hTrk_mbL1_%d",iTrig);
		hTrk_mbL1[iTrig] = new TH1D(name,name,2000,0,2000);
		hTrk_mbL1[iTrig]->Sumw2();
		sprintf(name,"hTrk_psL1_%d",iTrig);
		hTrk_psL1[iTrig] = new TH1D(name,name,2000,0,2000);
		hTrk_psL1[iTrig]->Sumw2();
		sprintf(name,"hTrk_HLT_%d",iTrig);
		hTrk_HLT[iTrig] = new TH1D(name,name,2000,0,2000);
		hTrk_HLT[iTrig]->Sumw2();
		sprintf(name,"hTrk_mbHLT_%d",iTrig);
		hTrk_mbHLT[iTrig] = new TH1D(name,name,2000,0,2000);
		hTrk_mbHLT[iTrig]->Sumw2();
		sprintf(name,"hTrk_psHLT_%d",iTrig);
		hTrk_psHLT[iTrig] = new TH1D(name,name,2000,0,2000);
		hTrk_psHLT[iTrig]->Sumw2();
	}

	cout<<"Processing..."<<endl;
	for(int iEvt=0; iEvt<nEvt; iEvt++)
	{
		if(iEvt%1000==0)
		{
			//cout<<setprecision(3)<<"Processing: "<<1.*iEvt/nEvt*100<<" %";
			for(int i=0; i<100.*iEvt/nEvt; i++) cout<<"#";
			cout<<">>>";
			for(int i=100.*iEvt/nEvt; i<100-1; i++) cout<<"-";
			cout<<'\r';
		}
		tree->GetEntry(iEvt);

		hTrigRate->Fill(-1);
		for(int iTrig=0; iTrig<nTrig; iTrig++)
		{
			if(trigL1[iTrig]>0) hTrk_L1[iTrig]->Fill(nTrk);
			if(trig[1]>0 && trigL1[iTrig]>0) hTrk_mbL1[iTrig]->Fill(nTrk);
			if(trig[1]>0 && trigL1[iTrig]>0) hTrk_psL1[iTrig]->Fill(nTrk,trig[1]);
			if(trig[iTrig]>0) hTrk_HLT[iTrig]->Fill(nTrk);
			if(trig[1]>0 && trig[iTrig]>0) hTrk_mbHLT[iTrig]->Fill(nTrk);
			if(trig[iTrig]>0) hTrk_psHLT[iTrig]->Fill(nTrk,trig[iTrig]);
			if(trig[iTrig]>0) hTrigRate->Fill(iTrig);
		}
	}
	cout<<"Done!"<<endl;

	sprintf(name,"hist.root");
	TFile *fOut = new TFile(name,"recreate");
	fOut->cd();
	hTrigRate->Write();
	for(int iTrig=0; iTrig<nTrig; iTrig++) hTrk_L1[iTrig]->Write();
	for(int iTrig=0; iTrig<nTrig; iTrig++) hTrk_mbL1[iTrig]->Write();
	for(int iTrig=0; iTrig<nTrig; iTrig++) hTrk_psL1[iTrig]->Write();
	for(int iTrig=0; iTrig<nTrig; iTrig++) hTrk_HLT[iTrig]->Write();
	for(int iTrig=0; iTrig<nTrig; iTrig++) hTrk_mbHLT[iTrig]->Write();
	for(int iTrig=0; iTrig<nTrig; iTrig++) hTrk_psHLT[iTrig]->Write();
	fOut->Close();
}



//----------------------------------------------------
// Ntrk distribution
//----------------------------------------------------
void ntrk()
{
	TFile *fIn = new TFile("hist.root");

	int chk[3] = {11,17,21};
	TH1D *hTrk[3];
	const int mS1[3] = {20,24,25};
	const int mC1[3] = {1,4,2};
	for(int i=0; i<2; i++)
	{
		sprintf(name,"hTrk_HLT_%d",chk[i]);
		hTrk[i] = (TH1D*)fIn->Get(name);
		hTrk[i]->Rebin(2);
		styleHist1(hTrk[i]);
		hTrk[i]->SetMarkerStyle(mS1[i]);
		hTrk[i]->SetMarkerColor(mC1[i]);
		hTrk[i]->SetLineStyle(lS[i]);
		hTrk[i]->SetLineColor(lC[i]);
	}
	int cnt[200];
	for(int i=0; i<200; i++) cnt[i] = 0;
	TH1D *hTrkT[nTrig];
	for(int i=0; i<nTrig; i++)
	{
		sprintf(name,"hTrk_HLT_%d",i);
		hTrkT[i] = (TH1D*)fIn->Get(name);
		if(i==19 || i==20 || i==21 || i==23 || i==24)
		{
			for(int j=0; j<200; j++) cnt[j] += hTrkT[i]->GetBinContent(j+1);
		}
	}
	hTrk[2] = new TH1D("hTrk_2","hTrk_2",200,0,200);
	for(int i=0; i<200; i++) hTrk[2]->SetBinContent(i+1,cnt[i]);
	hTrk[2]->Rebin(2);
	hTrk[2]->SetMarkerStyle(mS1[2]);
	hTrk[2]->SetMarkerColor(mC1[2]);
	hTrk[2]->SetLineStyle(lS[2]);
	hTrk[2]->SetLineColor(lC[2]);

	TLatex *tex = new TLatex();
	tex->SetTextSize(0.04);
	tex->SetTextAlign(12);
	tex->SetNDC(1);
	TLine *lin = new TLine();
	lin->SetLineStyle(lS[0]);
	lin->SetLineColor(lC[0]);
	TLegend *leg = new TLegend(0.6,0.675,0.85,0.875);
	leg->SetBorderSize(0);
	leg->SetFillColor(0);
	leg->AddEntry(hTrk[0],"min bias","p");
	leg->AddEntry(hTrk[1],"trk60","p");
	leg->AddEntry(hTrk[2],"trk90","p");
	
	TCanvas *cOut = new TCanvas("cOut","",400,400);
	gStyle->SetOptStat(0);
	for(int iC=0; iC<1; iC++)
	{
		cOut->cd(iC+1);
		gPad->SetTicks(1,1);
		gPad->SetLogy(1);
		gPad->SetTopMargin(0.05);
		gPad->SetBottomMargin(0.125);
		gPad->SetLeftMargin(0.125);
		gPad->SetRightMargin(0.05);
		hTrk[0]->GetXaxis()->SetTitle("N_{ch}^{rec}");
		hTrk[0]->GetXaxis()->SetTitleOffset(1.2);
		hTrk[0]->GetXaxis()->SetRangeUser(0,140);
		hTrk[0]->GetYaxis()->SetTitle("dN_{evt} / dN_{ch}^{rec}");
		hTrk[0]->GetYaxis()->SetTitleOffset(1.5);
		hTrk[0]->GetYaxis()->SetRangeUser(1000,10000000);
		hTrk[0]->Draw("P");
		for(int i=0; i<2; i++) hTrk[i+1]->Draw("P same");
		leg->Draw();
		tex->DrawLatex(0.2,0.85,"#font[72]{ATLAS}  #font[42]{Internal}");
		tex->SetTextFont(42);
		tex->DrawLatex(0.2,0.775,"#font[12]{pp} #sqrt{s}=5TeV");
	}

	cOut->Print("HMT_trk.pdf");
}



//----------------------------------------------------
// Efficiency for L1TE
//----------------------------------------------------
void effL1()
{
	TFile *fIn = new TFile("hist.root");
	TH1D *hTrk_L1[nTrig];
	TH1D *hTrk_mbL1[nTrig];
	TH1D *hTrk_HLT[nTrig];
	for(int iTrig=0; iTrig<nTrig; iTrig++)
	{
		sprintf(name,"hTrk_L1_%d",iTrig);
		hTrk_L1[iTrig] = (TH1D*)fIn->Get(name);
		sprintf(name,"hTrk_mbL1_%d",iTrig);
		hTrk_mbL1[iTrig] = (TH1D*)fIn->Get(name);
		sprintf(name,"hTrk_HLT_%d",iTrig);
		hTrk_HLT[iTrig] = (TH1D*)fIn->Get(name);
	}
	const int trigSlc[4] = {3,4,6,8};
	TH1D *hRef = (TH1D*)hTrk_mbL1[1]->Clone("hRef");
	hRef->Rebin(2);
	TH1D *hChk[4];
	for(int i=0; i<4; i++)
	{
		hChk[i] = (TH1D*)hTrk_mbL1[trigSlc[i]]->Clone("hChk");
		hChk[i]->Rebin(2);
		hChk[i]->Divide(hRef);
	}
	TGraphAsymmErrors *gTrig[4];

	double x[hRef->GetNbinsX()];
	double y[hRef->GetNbinsX()];
	double yElw[hRef->GetNbinsX()];
	double yEup[hRef->GetNbinsX()];
	const int mS1[4] = {24,28,25,27};
	const int mC1[4] = {4,1,2,6};
	const int lS1[4] = {2,2,2,2};
	const int lC1[4] = {4,1,2,6};
	for(int iTrig=0; iTrig<4; iTrig++)
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
	TLegend *leg = new TLegend(0.175,0.5,0.325,0.65);
	leg->SetBorderSize(0);
	leg->SetFillColor(0);
	leg->AddEntry(gTrig[0],"ZDC_A","lep");
	leg->AddEntry(gTrig[1],"ZDC_C","lep");
	leg->AddEntry(gTrig[2],"MBTS_1_1","lep");
	leg->AddEntry(gTrig[3],"L1_TE5","lep");
	
	TCanvas *cOut = new TCanvas("cOut","",400,400); 
	gStyle->SetOptStat(0);
	cOut->cd();
	gPad->SetTicks(1,1);
	gPad->SetTopMargin(0.05);
	gPad->SetBottomMargin(0.125);
	gPad->SetLeftMargin(0.125);
	gPad->SetRightMargin(0.05);
	for(int i=0; i<2; i++)
	{
		if(i==0)
		{
			gTrig[i]->GetXaxis()->SetRangeUser(0,maxTrk);
			gTrig[i]->GetXaxis()->SetTitle("N_{ch}^{rec}");
			gTrig[i]->GetXaxis()->SetTitleOffset(1.2);
			gTrig[i]->GetYaxis()->SetRangeUser(0,1.05);
			gTrig[i]->GetYaxis()->SetTitle("Efficiency");
			gTrig[i]->GetYaxis()->SetTitleOffset(1.5);
			gTrig[i]->Draw("AP");
		}
		else gTrig[i]->Draw("P");
	}
	lin->DrawLine(0,1,maxTrk,1);
	leg->Draw();
	tex->DrawLatex(0.175,0.80,"#font[72]{ATLAS}  #font[42]{Internal}");
	tex->SetTextFont(42);
	tex->DrawLatex(0.175,0.725,"#font[12]{PbPb} #sqrt{s}=13TeV");

	cOut->Print("HMT_effL1.pdf");
}
/*
void effL1()
{
	TFile *fIn = new TFile("hist.root");
	TH1D *hTrk_mbL1[nTrig];
	TH1D *hTrk_L1[nTrig];
	TH1D *hTrk_HLT[nTrig];
	for(int iTrig=0; iTrig<nTrig; iTrig++)
	{
		sprintf(name,"hTrk_mbL1_%d",iTrig);
		hTrk_mbL1[iTrig] = (TH1D*)fIn->Get(name);
		sprintf(name,"hTrk_L1_%d",iTrig);
		hTrk_L1[iTrig] = (TH1D*)fIn->Get(name);
		sprintf(name,"hTrk_HLT_%d",iTrig);
		hTrk_HLT[iTrig] = (TH1D*)fIn->Get(name);
	}
	TH1D *hRef;
	TH1D *hChk;

	const int maxL1TE05 = 100;
	const int maxL1TE10 = 110;
	const int maxL1TE20 = 120;
	TH1D *hL1TE05 = new TH1D("hL1TE05","hL1TE05",maxL1TE05,0,maxL1TE05);
	TH1D *hL1TE10 = new TH1D("hL1TE10","hL1TE10",maxL1TE10,0,maxL1TE10);
	TH1D *hL1TE20 = new TH1D("hL1TE20","hL1TE20",maxL1TE20,0,maxL1TE20);
	TGraphAsymmErrors *gL1TE05;
	TGraphAsymmErrors *gL1TE10;
	TGraphAsymmErrors *gL1TE20;

	// determine L1TE05
	double x[maxL1TE20];
	double y[maxL1TE20];
	double yElw[maxL1TE20];
	double yEup[maxL1TE20];
	hRef = (TH1D*)hTrk_mbL1[11]->Clone("hRef");
	hChk = (TH1D*)hTrk_mbL1[3]->Clone("hChk");
	hChk->Divide(hRef);
	for(int i=0; i<maxL1TE05; i++)
	{
		x[i] = hChk->GetBinCenter(i+1);
		y[i] = hChk->GetBinContent(i+1);
		yElw[i] = hChk->GetBinError(i+1);
		yEup[i] = hChk->GetBinError(i+1);
		if(y[i]+yEup[i]>=1) yEup[i] = 1-y[i];
		if(y[i]-yEup[i]<=0) yElw[i] = y[i];
	}
	gL1TE05 = new TGraphAsymmErrors(maxL1TE05,x,y,0,0,yElw,yEup);
	styleGraph1(gL1TE05);
	gL1TE05->SetMarkerStyle(24);
	gL1TE05->SetMarkerColor(2);
	gL1TE05->SetLineStyle(2);
	gL1TE05->SetLineColor(2);

	// determine L1TE10
	hRef = (TH1D*)hTrk_mbL1[11]->Clone("hRef");
	hChk = (TH1D*)hTrk_mbL1[4]->Clone("hChk");
	hChk->Divide(hRef);
	for(int i=0; i<85; i++)
	{
		x[i] = hChk->GetBinCenter(i+1);
		y[i] = hChk->GetBinContent(i+1);
		yElw[i] = hChk->GetBinError(i+1);
		yEup[i] = hChk->GetBinError(i+1);
		if(y[i]+yEup[i]>=1) yEup[i] = 1-y[i];
		if(y[i]-yEup[i]<=0) yElw[i] = y[i];
	}
	hRef = (TH1D*)hTrk_HLT[3]->Clone("hRef");
	hChk = (TH1D*)hTrk_HLT[4]->Clone("hChk");
	hChk->Divide(hRef);
	for(int i=85; i<maxL1TE10; i++)
	{
		x[i] = hChk->GetBinCenter(i+1);
		y[i] = hChk->GetBinContent(i+1);
		yElw[i] = hChk->GetBinError(i+1);
		yEup[i] = hChk->GetBinError(i+1);
		if(y[i]+yEup[i]>=1) yEup[i] = 1-y[i];
		if(y[i]-yEup[i]<=0) yElw[i] = y[i];
	}
	gL1TE10 = new TGraphAsymmErrors(maxL1TE10,x,y,0,0,yElw,yEup);
	styleGraph1(gL1TE10);
	gL1TE10->SetMarkerStyle(25);
	gL1TE10->SetMarkerColor(4);
	gL1TE10->SetLineStyle(2);
	gL1TE10->SetLineColor(4);

	// determine L1TE10
	hRef = (TH1D*)hTrk_mbL1[11]->Clone("hRef");
	hChk = (TH1D*)hTrk_mbL1[5]->Clone("hChk");
	hChk->Divide(hRef);
	for(int i=0; i<85; i++)
	{
		x[i] = hChk->GetBinCenter(i+1);
		y[i] = hChk->GetBinContent(i+1);
		yElw[i] = hChk->GetBinError(i+1);
		yEup[i] = hChk->GetBinError(i+1);
		if(y[i]+yEup[i]>=1) yEup[i] = 1-y[i];
		if(y[i]-yEup[i]<=0) yElw[i] = y[i];
	}
	hRef = (TH1D*)hTrk_HLT[3]->Clone("hRef");
	hChk = (TH1D*)hTrk_HLT[5]->Clone("hChk");
	hChk->Divide(hRef);
	for(int i=85; i<100; i++)
	{
		x[i] = hChk->GetBinCenter(i+1);
		y[i] = hChk->GetBinContent(i+1);
		yElw[i] = hChk->GetBinError(i+1);
		yEup[i] = hChk->GetBinError(i+1);
		if(y[i]+yEup[i]>=1) yEup[i] = 1-y[i];
		if(y[i]-yEup[i]<=0) yElw[i] = y[i];
	}
	hRef = (TH1D*)hTrk_HLT[4]->Clone("hRef");
	hChk = (TH1D*)hTrk_HLT[5]->Clone("hChk");
	hChk->Divide(hRef);
	for(int i=100; i<maxL1TE20; i++)
	{
		x[i] = hChk->GetBinCenter(i+1);
		y[i] = hChk->GetBinContent(i+1);
		yElw[i] = hChk->GetBinError(i+1);
		yEup[i] = hChk->GetBinError(i+1);
		if(y[i]+yEup[i]>=1) yEup[i] = 1-y[i];
		if(y[i]-yEup[i]<=0) yElw[i] = y[i];
	}
	gL1TE20 = new TGraphAsymmErrors(maxL1TE20,x,y,0,0,yElw,yEup);
	styleGraph1(gL1TE20);
	gL1TE20->SetMarkerStyle(27);
	gL1TE20->SetMarkerColor(6);
	gL1TE20->SetLineStyle(2);
	gL1TE20->SetLineColor(6);

	gL1TE05->Draw("AP");
	gL1TE10->Draw("P");
	gL1TE20->Draw("P");
}
*/



//----------------------------------------------------
// Efficiency for HLT
//----------------------------------------------------
void effHLT()
{
	TFile *fIn = new TFile("hist.root");
	TH1D *hTrk_L1[nTrig];
	TH1D *hTrk_mbL1[nTrig];
	TH1D *hTrk_psL1[nTrig];
	TH1D *hTrk_HLT[nTrig];
	TH1D *hTrk_mbHLT[nTrig];
	TH1D *hTrk_psHLT[nTrig];
	for(int iTrig=0; iTrig<nTrig; iTrig++)
	{
		sprintf(name,"hTrk_L1_%d",iTrig);
		hTrk_L1[iTrig] = (TH1D*)fIn->Get(name);
		sprintf(name,"hTrk_mbL1_%d",iTrig);
		hTrk_mbL1[iTrig] = (TH1D*)fIn->Get(name);
		sprintf(name,"hTrk_psL1_%d",iTrig);
		hTrk_psL1[iTrig] = (TH1D*)fIn->Get(name);
		sprintf(name,"hTrk_HLT_%d",iTrig);
		hTrk_HLT[iTrig] = (TH1D*)fIn->Get(name);
		sprintf(name,"hTrk_mbHLT_%d",iTrig);
		hTrk_mbHLT[iTrig] = (TH1D*)fIn->Get(name);
		sprintf(name,"hTrk_psHLT_%d",iTrig);
		hTrk_psHLT[iTrig] = (TH1D*)fIn->Get(name);
	}
	const int trigSlcL1[4] = {3,5,7,8};
	const int trigSlc[4] = {17,21,23,24};
	TH1D *hRef[4];
	for(int i=0; i<4; i++)
	{
		hRef[i] = (TH1D*)hTrk_psL1[trigSlcL1[i]]->Clone("hRef");
		hRef[i]->Rebin(2);
	}
	TH1D *hChk[4];
	for(int i=0; i<4; i++)
	{
		hChk[i] = (TH1D*)hTrk_psHLT[trigSlc[i]]->Clone("hChk");
		hChk[i]->Rebin(2);
		hChk[i]->Divide(hRef[i]);
	}
	TGraphAsymmErrors *gTrig[4];

	double x[hRef[0]->GetNbinsX()];
	double y[hRef[0]->GetNbinsX()];
	double yElw[hRef[0]->GetNbinsX()];
	double yEup[hRef[0]->GetNbinsX()];
	double scale;
	for(int iTrig=0; iTrig<4; iTrig++)
	{
		scale = 0;
		for(int i=0; i<hRef[0]->GetNbinsX(); i++)
		{
			x[i] = hChk[iTrig]->GetBinCenter(i+1);
			y[i] = hChk[iTrig]->GetBinContent(i+1);
			yElw[i] = hChk[iTrig]->GetBinError(i+1);
			yEup[i] = hChk[iTrig]->GetBinError(i+1);
			if(iTrig==0 && i>=70/2. && i<100/2.) scale += y[i]/15;
			if(iTrig==1 && i>=96/2. && i<110/2.) scale += y[i]/7;
		}
		if(iTrig==0 || iTrig==1)
		{
			cout<<scale<<endl;
			for(int i=0; i<hRef[0]->GetNbinsX(); i++)
			{
				y[i] /= scale;
				yElw[i] /= scale;
				yEup[i] /= scale;
			}
		}
		for(int i=0; i<hRef[0]->GetNbinsX(); i++)
		{
			if(y[i]>1) y[i] = 1;
			if(y[i]+yEup[i]>=1) yEup[i] = 1-y[i];
			if(y[i]-yElw[i]<=0) yElw[i] = y[i];
		}
		gTrig[iTrig] = new TGraphAsymmErrors(hRef[0]->GetNbinsX(),x,y,0,0,yElw,yEup);
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
	TLegend *leg = new TLegend(0.175,0.5,0.525,0.65);
	leg->SetBorderSize(0);
	leg->SetFillColor(0);
	leg->AddEntry(gTrig[0],"trk_60 wrt L1TE5","lep");
	leg->AddEntry(gTrig[1],"trk_90 wrt L1TE20","lep");
	//leg->AddEntry(gTrig[3],"L1TE30","lep");
	
	TCanvas *cOut = new TCanvas("cOut","",400,400); 
	gStyle->SetOptStat(0);
	cOut->cd();
	gPad->SetTicks(1,1);
	gPad->SetTopMargin(0.05);
	gPad->SetBottomMargin(0.125);
	gPad->SetLeftMargin(0.125);
	gPad->SetRightMargin(0.05);
	for(int i=0; i<2; i++)
	{
		if(i==0)
		{
			gTrig[i]->GetXaxis()->SetRangeUser(0,maxTrk);
			gTrig[i]->GetXaxis()->SetTitle("N_{ch}^{rec}");
			gTrig[i]->GetXaxis()->SetTitleOffset(1.2);
			gTrig[i]->GetYaxis()->SetRangeUser(0,1.05);
			gTrig[i]->GetYaxis()->SetTitle("Efficiency");
			gTrig[i]->GetYaxis()->SetTitleOffset(1.5);
			gTrig[i]->Draw("AP");
		}
		else gTrig[i]->Draw("P");
	}
	lin->DrawLine(0,1,maxTrk,1);
	leg->Draw();
	tex->DrawLatex(0.175,0.80,"#font[72]{ATLAS}  #font[42]{Internal}");
	tex->SetTextFont(42);
	tex->DrawLatex(0.175,0.725,"#font[12]{pp} #sqrt{s}=5TeV");

	cOut->Print("HMT_effHLT.pdf");
}



//----------------------------------------------------
// test
//----------------------------------------------------
void test()
{
	TFile *fIn = new TFile("hist.root");
	TH1D *hTrk_mbL1[nTrig];
	TH1D *hTrk_L1[nTrig];
	TH1D *hTrk_HLT[nTrig];
	for(int iTrig=0; iTrig<nTrig; iTrig++)
	{
		sprintf(name,"hTrk_mbL1_%d",iTrig);
		hTrk_mbL1[iTrig] = (TH1D*)fIn->Get(name);
		sprintf(name,"hTrk_L1_%d",iTrig);
		hTrk_L1[iTrig] = (TH1D*)fIn->Get(name);
		sprintf(name,"hTrk_HLT_%d",iTrig);
		hTrk_HLT[iTrig] = (TH1D*)fIn->Get(name);
	}

	TH1D *hTest = new TH1D("hTest","hTest",200,0,200);
	for(int i=0; i<200; i++)
	{
		hTest->SetBinContent(i+1,hTrk_mbL1[3]->GetBinContent(i+1)+hTrk_mbL1[17]->GetBinContent(i+1)+hTrk_mbL1[21]->GetBinContent(i+1));
	}
	hTest->Draw();
	hTrk_L1[3]->SetLineColor(2);
	hTrk_L1[3]->Draw("same");
}



//----------------------------------------------------
// Macro
//----------------------------------------------------
void draw()
{
	gen();
	//test();
	
	//ntrk();
	//effL1();
	//effHLT();
}















