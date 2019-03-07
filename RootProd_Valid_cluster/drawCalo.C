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
	sprintf(name,"myaod.root");
	TFile *fIn = new TFile(name);
	int RunNumber;
	int lbn;
	int bcid;
	int EvtNumber;
	float L1TE;
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
	float MBTStimeA;
	float MBTStimeC;
	float MBTScountA;
	float MBTScountC;
	int nEt;
	float et[1000];
	float etaMin[1000];
	float etaMax[1000];
	float layer[1000];
	float etSin[1000][7];
	float etCos[1000][7];
	int nCalo;
	float etCalo[10000];
	float etaCalo[10000];
	float phiCalo[10000];
	TTree *tree = (TTree*)fIn->Get("tree");
	tree->SetBranchAddress("L1TE",&L1TE);
	tree->SetBranchAddress("trig",trig);
	tree->SetBranchAddress("trigL1",trigL1);
	tree->SetBranchAddress("nTrk",&nTrk);
	tree->SetBranchAddress("MBTStimeA",&MBTStimeA);
	tree->SetBranchAddress("MBTStimeC",&MBTStimeC);
	tree->SetBranchAddress("MBTScountA",&MBTScountA);
	tree->SetBranchAddress("MBTScountC",&MBTScountC);
	tree->SetBranchAddress("nEt",&nEt);
	tree->SetBranchAddress("et",et);
	tree->SetBranchAddress("etaMin",etaMin);
	tree->SetBranchAddress("etaMax",etaMax);
	tree->SetBranchAddress("layer",layer);
	tree->SetBranchAddress("etSin",etSin);
	tree->SetBranchAddress("etCos",etCos);
	tree->SetBranchAddress("nCalo",&nCalo);
	tree->SetBranchAddress("etCalo",etCalo);
	tree->SetBranchAddress("etaCalo",etaCalo);
	tree->SetBranchAddress("phiCalo",phiCalo);
	int nEvt = tree->GetEntries();

	TH1D *hES_eta = new TH1D("hES_eta","hES_eta",120,-6,6);
	TH1D *hES_layer = new TH1D("hES_layer","hES_layer",25,0,25);
	TH2D *hES_eta_layer = new TH2D("hES_eta_layer","hES_eta_layer",100,-5,5,25,0,25);
	TH2D *hES_eta_layer_et = new TH2D("hES_eta_layer_et","hES_eta_layer_et",100,-5,5,25,0,25);
	TH1D *hES_eta_et = new TH1D("hES_eta_et","hES_eta_et",100,-5,5);
	TH1D *hCalo_eta = new TH1D("hCalo_eta","hCalo_eta",120,-6,6);
	TH1D *hCalo_phi = new TH1D("hCalo_phi","hCalo_phi",100,-PI,PI);
	TH2D *hCalo_eta_phi = new TH2D("hCalo_eta_phi","hCalo_eta_phi",200,-5,5,200,-PI,PI);
	TH2D *hCalo_eta_phi_et = new TH2D("hCalo_eta_phi_et","hCalo_eta_phi_et",100,-5,5,64,-PI,PI);
	TH1D *hCalo_eta_et = new TH1D("hCalo_eta_et","hCalo_eta_et",100,-5,5);
	TH2D *hCorr_SumEt_L1TE = new TH2D("hCorr_SumEt_L1TE","",100,0,10000,100,0,10000);

	const int nPhi = 100;
	TH2D *hES_eta_phi_Q = new TH2D("hES_eta_phi_Q","",100,-5,5,nPhi,-PI,PI);


	double sum;
	for(int iEvt=0; iEvt<nEvt; iEvt++)
	{
		cout<<iEvt<<endl;
		/*
		if(iEvt%100==0)
		{
			for(int i=0; i<100.*iEvt/nEvt; i++) cout<<"#";
			cout<<">>>";
			for(int i=100.*iEvt/nEvt; i<100-1; i++) cout<<"-";
			cout<<'\r';
		}
		*/
		tree->GetEntry(iEvt);
		
		sum = 0;
		for(int i=0; i<nEt; i++)
		{
			hES_eta->Fill((etaMin[i]+etaMax[i])/2);
			hES_layer->Fill(layer[i]);
			if(iEvt<500) hES_eta_layer->Fill((etaMin[i]+etaMax[i])/2,layer[i]);
			hES_eta_layer_et->Fill((etaMin[i]+etaMax[i])/2,layer[i],et[i]);
			hES_eta_et->Fill((etaMin[i]+etaMax[i])/2,et[i]);
			sum += et[i];
		}
/*
		hCalo_n->Fill(nCalo);
		for(int i=0; i<nCalo; i++)
		{
			hCalo_eta->Fill(etaCalo[i]);
			hCalo_phi->Fill(phiCalo[i]);
			if(iEvt<500) hCalo_eta_phi->Fill(etaCalo[i],phiCalo[i]);
			hCalo_eta_phi_et->Fill(etaCalo[i],phiCalo[i],etCalo[i]);
			hCalo_eta_et->Fill(etaCalo[i],etCalo[i]);
		}
*/
		hCorr_SumEt_L1TE->Fill(sum,L1TE);
		
		for(int i=0; i<nEt; i++)
		{
			for(int j=0; j<nPhi; j++)
			{
				sum = 0;
				for(int k=0; k<7; k++) sum += 2*etCos[i][k]*cos((k+1)*(-PI+j*2*PI/nPhi))+2*etSin[i][k]*sin((k+1)*(-PI+j*2*PI/nPhi));
				hES_eta_phi_Q->Fill((etaMin[i]+etaMax[i])/2,-PI+j*2*PI/nPhi,sum);
			}
		}
	}
	for(int i=0; i<2000; i++)
	{
		for(int j=0; j<2000; j++)
		{
			if(hES_eta_layer->GetBinContent(i+1,j+1)!=0) hES_eta_layer->SetBinContent(i+1,j+1,1);
			if(hCalo_eta_phi->GetBinContent(i+1,j+1)!=0) hCalo_eta_phi->SetBinContent(i+1,j+1,1);
		}
	}

	TFile *fOut = new TFile("hist_et.root","RECREATE");
	fOut->cd();
	hES_eta->Write();
	hES_layer->Write();
	hES_eta_layer->Write();
	hES_eta_layer_et->Write();
	hES_eta_et->Write();
	hCalo_eta->Write();
	hCalo_phi->Write();
	hCalo_eta_phi->Write();
	hCalo_eta_phi_et->Write();
	hCalo_eta_et->Write();
	hES_eta_phi_Q->Write();
	hCorr_SumEt_L1TE->Write();
	fOut->Close();
}



//----------------------------------------------------
// Draw Pattern
//----------------------------------------------------
void patternDraw()
{
	TFile *fIn = new TFile("hist_et.root");
	TH2D *hES_eta_layer = (TH2D*)fIn->Get("hES_eta_layer");
	styleHist2(hES_eta_layer);
	TH2D *hES_eta_layer_et = (TH2D*)fIn->Get("hES_eta_layer_et");
	styleHist2(hES_eta_layer_et);
	TH2D *hCalo_eta_phi = (TH2D*)fIn->Get("hCalo_eta_phi");
	styleHist2(hCalo_eta_phi);
	TH2D *hCalo_eta_phi_et = (TH2D*)fIn->Get("hCalo_eta_phi_et");
	styleHist2(hCalo_eta_phi_et);

	TCanvas *cOut1 = new TCanvas("cOut1","",800,400);
	cOut1->Divide(2,1,0.0001,0.0001);
	gStyle->SetOptStat(0);
	gStyle->SetNumberContours(100);
	TH2D *hCopy;
	for(int iC=0; iC<2; iC++)
	{
		if(iC==0) hCopy = (TH2D*)hES_eta_layer->Clone("hCopy");
		if(iC==1) hCopy = (TH2D*)hES_eta_layer_et->Clone("hCopy");
		cOut1->cd(iC+1);
		gPad->SetTicks(1,1);
		if(iC==1) gPad->SetLogz(1);
		gPad->SetTopMargin(0.05);
		gPad->SetBottomMargin(0.1);
		gPad->SetLeftMargin(0.1);
		gPad->SetRightMargin(0.05);
		hCopy->GetXaxis()->SetTitle("#eta");
		hCopy->GetXaxis()->SetTitleOffset(1);
		hCopy->GetYaxis()->SetTitle("layer");
		hCopy->GetYaxis()->SetTitleOffset(1);
		if(iC==0) hCopy->Draw("box");
		if(iC==1) hCopy->Draw("col");
	}
	cOut1->Print("et_pattern_ES.pdf");

	TCanvas *cOut2 = new TCanvas("cOut2","",800,400);
	cOut2->Divide(2,1,0.0001,0.0001);
	gStyle->SetOptStat(0);
	gStyle->SetNumberContours(100);
	for(int iC=0; iC<2; iC++)
	{
		if(iC==0) hCopy = (TH2D*)hCalo_eta_phi->Clone("hCopy");
		if(iC==1) hCopy = (TH2D*)hCalo_eta_phi_et->Clone("hCopy");
		cOut2->cd(iC+1);
		gPad->SetTicks(1,1);
		if(iC==1) gPad->SetLogz(1);
		gPad->SetTopMargin(0.05);
		gPad->SetBottomMargin(0.1);
		gPad->SetLeftMargin(0.1);
		gPad->SetRightMargin(0.05);
		hCopy->GetXaxis()->SetTitle("#eta");
		hCopy->GetXaxis()->SetTitleOffset(1);
		hCopy->GetYaxis()->SetTitle("#phi");
		hCopy->GetYaxis()->SetTitleOffset(1);
		if(iC==0) hCopy->Draw("");
		if(iC==1) hCopy->Draw("col");
	}
	cOut2->Print("et_pattern_Calo.pdf");
}


//----------------------------------------------------
// Macro
//----------------------------------------------------
void drawCalo()
{
	gen();

	//patternDraw();
}















