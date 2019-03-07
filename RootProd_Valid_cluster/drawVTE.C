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
	sprintf(name,"data_665.root");
	//sprintf(name,"data_767_1.root");
	TFile *fIn = new TFile(name);
	float L1TE;
	float trig[nTrig];
	float trigL1[nTrig];
	int nVtx;
	int trkVtx[50];
	float zVtx[50];
	int nTrk;
	float eta[1000];
	int nEt;
	float et[1000];
	float etaMin[1000];
	float etaMax[1000];
	int nCalo;
	float etCalo[10000];
	float etaCalo[10000];
	TTree *tree = (TTree*)fIn->Get("tree");
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

	TH1D *hL1TE = new TH1D("hL1TE","L1TE distribution",100,0,100);
	TH1D *hL1TErej = new TH1D("hL1TErej","L1TE rejection rate",100,0,100);
	TH1D *hL1TE1 = new TH1D("hL1TE1","L1TE distribution",100,0,100);
	TH1D *hL1TE1rej = new TH1D("hL1TE1rej","L1TE rejection rate",100,0,100);
	TH2D *hZDC_A_C = new TH2D("hZDC_A_C","ZDC_A : ZDC_C",2,-0.5,1.5,2,-0.5,1.5);
	TH2D *hCorr_eta_trk_et[nTrig];
	for(int i=0; i<nTrig; i++)
	{
		sprintf(name,"hCorr_eta_trk_et_%d",i);
		hCorr_eta_trk_et[i] = new TH2D(name,name,50,-5,5,50,-0.5,49.5);
	}
	TH1D *hEtA[4];
	TH1D *hEtC[4];
	TH1D *hTrkR[4];
	TH1D *hTrk = new TH1D("hTrk","Nch distribution",50,-0.5,49.5);
	hTrk->Sumw2();
	for(int i=0; i<4; i++)
	{
		sprintf(name,"hEtA_%d",i);
		hEtA[i] = new TH1D(name,"E_{T} A side is more",50,-5,5);
		sprintf(name,"hEtC_%d",i);
		hEtC[i] = new TH1D(name,"E_{T} C side is more",50,-5,5);
		sprintf(name,"hTrkR_%d",i);
		hTrkR[i] = new TH1D(name,"Asy/All",50,-0.5,49.5);
		hTrkR[i]->Sumw2();
	}
	TH1D *hTrk_TE50 = new TH1D("hTrk_TE50","",160,-1,7);
	TH1D *hTrk_VTE50 = new TH1D("hTrk_VTE50","",160,-1,7);
	TH1D *hTrk_VTE50_mb = new TH1D("hTrk_VTE50_mb","",300,-0.1,0.2);
	TH1D *hTrk_VTE50_trk = new TH1D("hTrk_VTE50_trk","",300,-0.1,0.2);
	TH1D *hTrk_VTE50_vtx = new TH1D("hTrk_VTE50_vtx","",300,-0.1,0.2);
	TH1D *hWei = new TH1D("hWei","",200,-400,400);
	TH1D *hWei_etA[4];
	TH1D *hWei_etC[4];
	TH1D *hWei_trk[4];
	for(int i=0; i<4; i++)
	{
		sprintf(name,"hWei_etA_%d",i);
		hWei_etA[i] = new TH1D(name,name,50,-5,5);
		sprintf(name,"hWei_etC_%d",i);
		hWei_etC[i] = new TH1D(name,name,50,-5,5);
		sprintf(name,"hWei_trk_%d",i);
		hWei_trk[i] = new TH1D(name,"Asy/All",50,-0.5,49.5);
		hWei_trk[i]->Sumw2();
	}
	TH2D *hGapEt = new TH2D("hGapEt","",100,-5,5,820,-10,400);
	TH2D *hGapEt_zoom = new TH2D("hGapEt_zoom","",100,-5,5,100,-5,5);
	TH1D *hGap[10];
	TH1D *hGap_all[10];
	TH1D *hGap_trk[10];
	for(int i=0; i<10; i++)
	{
		sprintf(name,"hGap_%d",i);
		hGap[i] = new TH1D(name,"",200,-10,10);
		sprintf(name,"hGap_trk_%d",i);
		hGap_trk[i] = new TH1D(name,"",50,-0.5,49.5);
	}

	double sum = 0;
	double sum1 = 0;
	double etA;
	double etC;
	int cntA[4];
	int cntC[4];
	int weiA[4];
	int weiC[4];
	double gapA;
	double gapC;
	for(int i=0; i<4; i++)
	{
		cntA[i] = 0;
		cntC[i] = 0;
		weiA[i] = 0;
		weiC[i] = 0;
	}
	const int ratioCut[4] = {2,3,4,5};
	const int weiCut[4] = {40,60,80,100};
	double FCal;
	double wei;
	TH1D *hGap_tmp = new TH1D("hGap_tmp","",100,-5,5);
	for(int iEvt=0; iEvt<nEvt; iEvt++)
	{
		if(iEvt%10==0)
		{
			for(int i=0; i<100.*iEvt/nEvt; i++) cout<<"#";
			cout<<">>>";
			for(int i=100.*iEvt/nEvt; i<100-1; i++) cout<<"-";
			cout<<'\r';
		}
		tree->GetEntry(iEvt);

		if(trigL1[3]==0 && trigL1[4]==0) hZDC_A_C->Fill(0.,0.);
		if(trigL1[3]>0 && trigL1[4]==0) hZDC_A_C->Fill(1.,0.);
		if(trigL1[3]==0 && trigL1[4]>0) hZDC_A_C->Fill(0.,1.);
		if(trigL1[3]>0 && trigL1[4]>0) hZDC_A_C->Fill(1.,1.);
		
		if(trig[1]<0) continue;
		//if(trig[20]<0) continue;
		
		hTrk->Fill(nTrk);
		FCal = 0;
		for(int i=0; i<nEt; i++)
		{
			if(fabs((etaMin[i]+etaMax[i])/2)>=3.2) FCal += et[i]/1000;
		}
		if(trigL1[13]>0) hTrk_TE50->Fill(FCal);
		if(trigL1[16]>0) hTrk_VTE50->Fill(FCal);
		if(trigL1[16]>0) hTrk_VTE50_mb->Fill(FCal);
		if(trigL1[16]>0 && nTrk>0) hTrk_VTE50_trk->Fill(FCal);
		if(trigL1[16]>0 && zVtx[0]<100) hTrk_VTE50_vtx->Fill(FCal);
		
		if(nTrk==0) continue;

		if(trigL1[1]>0 && nTrk!=0)
		{
			sum1++;
			hL1TE1->Fill(L1TE);
		}
		if(trigL1[1]>0)
		{
			sum++;
			hL1TE->Fill(L1TE);
		}
	
		for(int i=0; i<nTrig; i++)
		{
			if(trigL1[i]>0)
			{
				for(int j=0; j<nEt; j++)
				{
					hCorr_eta_trk_et[i]->Fill((etaMin[j]+etaMax[j])/2,nTrk,et[j]);
				}
			}
		}
		etA = 0;
		etC = 0;
		wei = 0;
		hGap_tmp->Reset();
		for(int i=0; i<nEt; i++)
		{
			if((etaMin[i]+etaMax[i])/2<0) etA += et[i];
			if((etaMin[i]+etaMax[i])/2>=0) etC += et[i];
			if(nTrk<20) wei += exp(et[i])*(etaMin[i]+etaMax[i])/2;
			hGap_tmp->Fill((etaMin[i]+etaMax[i])/2,et[i]);		
		}
		if(nTrk<20) hWei->Fill(wei);
		
		for(int i=0; i<hGapEt->GetNbinsX(); i++)
		{
			hGapEt->Fill(-5+(2*i+1)*0.05,hGap_tmp->GetBinContent(i+1));
			hGapEt_zoom->Fill(-5+(2*i+1)*0.05,hGap_tmp->GetBinContent(i+1));
		}
		for(int j=0; j<10; j++)
		{
			gapA = -10;
			gapC = 10;
			for(int i=0; i<hGap_tmp->GetNbinsX(); i++)
			{
				if(hGap_tmp->GetBinContent(i+1)>0.1*j)
				{
					if(-5-(-5+(2*i+1)*0.05)>gapA) gapA = -5-(-5+(2*i+1)*0.05);
					if(+5-(-5+(2*i+1)*0.05)<gapC) gapC = +5-(-5+(2*i+1)*0.05);
				}
			}
			hGap[j]->Fill(gapA);
			hGap[j]->Fill(gapC);
		}
		for(int i=0; i<nEt; i++)
		{
			for(int j=0; j<4; j++)
			{
				if(etA/etC>ratioCut[j])
				{
					cntA[j]++;
					hEtA[j]->Fill((etaMin[i]+etaMax[i])/2,et[i]);
				}
				if(etC/etA>ratioCut[j])
				{
					cntC[j]++;
					hEtC[j]->Fill((etaMin[i]+etaMax[i])/2,et[i]);
				}
				if(nTrk<20)
				{
					if(wei<-weiCut[j])
					{
						weiA[j]++;
						hWei_etA[j]->Fill((etaMin[i]+etaMax[i])/2,et[i]);
					}
					if(wei>+weiCut[j])
					{
						weiC[j]++;
						hWei_etC[j]->Fill((etaMin[i]+etaMax[i])/2,et[i]);
					}
				}
			}	
		}
		for(int i=0; i<4; i++)
		{
			if(etA/etC>ratioCut[i] || etC/etA>ratioCut[i]) hTrkR[i]->Fill(nTrk);
			if(fabs(wei)>weiCut[i]) hWei_trk[i]->Fill(nTrk);
		}
	}
	for(int i=0; i<4; i++)
	{
		hEtA[i]->Scale(1./cntA[i]);
		hEtC[i]->Scale(1./cntC[i]);
		hTrkR[i]->Divide(hTrk);
		hWei_etA[i]->Scale(1./weiA[i]);
		hWei_etC[i]->Scale(1./weiC[i]);
		hWei_trk[i]->Divide(hTrk);
	}

	double cnt;
	cnt = 0;
	for(int i=0; i<hL1TE->GetNbinsX(); i++)
	{
		hL1TErej->SetBinContent(i+1,cnt/sum*100);
		cnt += hL1TE->GetBinContent(i+1);
	}
	cnt = 0;
	for(int i=0; i<hL1TE1->GetNbinsX(); i++)
	{
		hL1TE1rej->SetBinContent(i+1,cnt/sum1*100);
		cnt += hL1TE1->GetBinContent(i+1);
	}

	TFile *fOut = new TFile("hist_vte.root","RECREATE");
	//TFile *fOut = new TFile("vte_767.root","RECREATE");
	fOut->cd();
	hL1TE->Write();
	hL1TErej->Write();
	hL1TE1->Write();
	hL1TE1rej->Write();
	hZDC_A_C->Write();
	hTrk->Write();
	for(int i=0; i<4; i++)
	{
		hEtA[i]->Write();
		hEtC[i]->Write();
		hTrkR[i]->Write();
	}
	hTrk_TE50->Write();
	hTrk_VTE50->Write();
	hTrk_VTE50_mb->Write();
	hTrk_VTE50_trk->Write();
	hTrk_VTE50_vtx->Write();
	hWei->Write();
	for(int i=0; i<4; i++)
	{
		hWei_etA[i]->Write();
		hWei_etC[i]->Write();
		hWei_trk[i]->Write();
	}
	hGapEt->Write();
	hGapEt_zoom->Write();
	for(int i=0; i<10; i++) hGap[i]->Write();
	for(int i=0; i<nTrig; i++) hCorr_eta_trk_et[i]->Write();
	fOut->Close();
}



//----------------------------------------------------
// Draw L1TE
//----------------------------------------------------
void drawL1TE()
{
	TFile *fIn = new TFile("hist_vte.root");
	TH1D *hL1TErej = (TH1D*)fIn->Get("hL1TE1rej");
	styleHist1(hL1TErej);

	const double cL1TE[3] = {2,8,6};
	const double xL1TE[3] = {5,20,50};
	double yL1TE[3];
	for(int i=0; i<3; i++) yL1TE[i] = hL1TErej->GetBinContent(xL1TE[i]+1);

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
	//leg->AddEntry(gTrig[0],"ZDC_A","lep");

	TCanvas *cOut = new TCanvas("cOut","",400,400);
	gStyle->SetOptStat(0);
	cOut->cd();
	gPad->SetTicks(1,1);
	gPad->SetTopMargin(0.05);
	gPad->SetBottomMargin(0.125);
	gPad->SetLeftMargin(0.125);
	gPad->SetRightMargin(0.05);
	hL1TErej->GetXaxis()->SetTitle("L1TE");
	hL1TErej->GetXaxis()->SetTitleOffset(1.25);
	hL1TErej->GetXaxis()->SetRangeUser(0,75);
	hL1TErej->GetYaxis()->SetTitle("VTE percentile");
	hL1TErej->GetYaxis()->SetTitleOffset(1.25);
	hL1TErej->GetYaxis()->SetRangeUser(0,60);
	hL1TErej->Draw();
	for(int i=0; i<3; i++)
	{
		lin->SetLineColor(cL1TE[i]);
		lin->DrawLine(xL1TE[i],0,xL1TE[i],yL1TE[i]);
		lin->DrawLine(0,yL1TE[i],xL1TE[i],yL1TE[i]);
	}
	tex->DrawLatex(0.175,0.90,"#font[72]{ATLAS}  #font[42]{Internal}");
	tex->SetTextFont(42);
	tex->DrawLatex(0.175,0.825,"#font[12]{PbPb} #sqrt{s}=5.02TeV");

	cOut->Print("L1TE_665.pdf");
}



//----------------------------------------------------
// Draw ET
//----------------------------------------------------
void drawCorr()
{
	TFile *fIn = new TFile("hist_vte.root");
	const int slc[3] = {3,4,1};
	TH2D *hCorr[3];
	for(int i=0; i<3; i++)
	{
		sprintf(name,"hCorr_eta_trk_et_%d",slc[i]);
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
		gPad->SetBottomMargin(0.125);
		gPad->SetLeftMargin(0.125);
		gPad->SetRightMargin(0.05);

		hCorr[iC]->GetXaxis()->SetTitle("#eta");
		hCorr[iC]->GetXaxis()->SetTitleOffset(1.25);
		hCorr[iC]->GetXaxis()->SetRangeUser(-5,5);
		hCorr[iC]->GetYaxis()->SetTitle("N_{ch}");
		hCorr[iC]->GetYaxis()->SetTitleOffset(1.25);
		hCorr[iC]->GetYaxis()->SetRangeUser(-0.5,19.5);
		hCorr[iC]->Draw("COL");

		if(iC==0)
		{
			tex->DrawLatex(0.175,0.90,"#font[72]{ATLAS}  #font[42]{Internal}");
			tex->SetTextFont(42);
			tex->DrawLatex(0.175,0.825,"#font[12]{PbPb} #sqrt{s}=5.02TeV");
		}
		if(iC==0) tex->DrawLatex(0.8,0.90,"#font[72]{ZDC_A}");
		if(iC==1) tex->DrawLatex(0.8,0.90,"#font[72]{ZDC_C}");
	}
	
	cOut->Print("CorrEt_665.pdf");
}



//----------------------------------------------------
// Draw Bias
//----------------------------------------------------
void drawBias()
{
	TFile *fIn = new TFile("hist_vte.root");
	TH1D *hEtA[4];
	TH1D *hEtC[4];
	for(int i=0; i<4; i++)
	{
		sprintf(name,"hEtA_%d",i);
		hEtA[i] = (TH1D*)fIn->Get(name);
		styleHist1(hEtA[i]);
		hEtA[i]->SetMarkerStyle(mS[i]);
		hEtA[i]->SetMarkerColor(mC[i]);
		hEtA[i]->SetLineStyle(lS[i]);
		hEtA[i]->SetLineColor(lC[i]);
		sprintf(name,"hEtC_%d",i);
		hEtC[i] = (TH1D*)fIn->Get(name);
		styleHist1(hEtC[i]);
		hEtC[i]->SetMarkerStyle(mS[i]);
		hEtC[i]->SetMarkerColor(mC[i]);
		hEtC[i]->SetLineStyle(lS[i]);
		hEtC[i]->SetLineColor(lC[i]);
	}

	TLatex *tex = new TLatex();
	tex->SetTextSize(0.04);
	tex->SetTextAlign(12);
	tex->SetNDC(1);
	TLine *lin = new TLine();
	lin->SetLineStyle(lS[0]);
	lin->SetLineColor(lC[0]);
	TLegend *leg = new TLegend(0.25,0.6,0.45,0.85);
	leg->SetBorderSize(0);
	leg->SetFillColor(0);
	leg->AddEntry(hEtA[0],"Bias = 2","lep");
	leg->AddEntry(hEtA[1],"Bias = 3","lep");
	leg->AddEntry(hEtA[2],"Bias = 4","lep");
	leg->AddEntry(hEtA[3],"Bias = 5","lep");

	TCanvas *cOut = new TCanvas("cOut","",800,400);
	cOut->Divide(2,1,0.0001,0.0001);
	gStyle->SetOptStat(0);
	for(int iC=0; iC<2; iC++)
	{
		cOut->cd(iC+1);
		gPad->SetTicks(1,1);
		gPad->SetTopMargin(0.05);
		gPad->SetBottomMargin(0.1);
		gPad->SetLeftMargin(0.2);
		gPad->SetRightMargin(0.05);
		if(iC==0)
		{
			hEtA[0]->GetXaxis()->SetTitle("#eta");
			hEtA[0]->GetXaxis()->SetTitleOffset(1);
			hEtA[0]->GetXaxis()->SetRangeUser(-5,5);
			hEtA[0]->GetYaxis()->SetTitle("E_{T}");
			hEtA[0]->GetYaxis()->SetTitleOffset(2.5);
			hEtA[0]->GetYaxis()->SetRangeUser(-0.001,0.005);
			hEtA[0]->Draw("PL");
			for(int i=1; i<4; i++) hEtA[i]->Draw("PL same");
			tex->DrawLatex(0.6,0.80,"#font[72]{ATLAS}  #font[42]{Internal}");
			tex->SetTextFont(42);
			tex->DrawLatex(0.6,0.725,"#font[12]{PbPb} #sqrt{s}=5.02TeV");
		}
		if(iC==1)
		{
			hEtC[0]->GetXaxis()->SetTitle("#eta");
			hEtC[0]->GetXaxis()->SetTitleOffset(1);
			hEtC[0]->GetXaxis()->SetRangeUser(-5,5);
			hEtC[0]->GetYaxis()->SetTitle("E_{T}");
			hEtC[0]->GetYaxis()->SetTitleOffset(2.5);
			hEtC[0]->GetYaxis()->SetRangeUser(-0.001,0.005);
			hEtC[0]->Draw("PL");
			for(int i=1; i<4; i++) hEtC[i]->Draw("PL same");
			leg->Draw();
		}
	}

	cOut->Print("EtBias_665.pdf");
}



//----------------------------------------------------
// Draw Fraction
//----------------------------------------------------
void drawRatio()
{
	TFile *fIn = new TFile("hist_vte.root");
	TH1D *hTrkR[4];
	for(int i=0; i<4; i++)
	{
		sprintf(name,"hTrkR_%d",i);
		hTrkR[i] = (TH1D*)fIn->Get(name);
	}
	
	TGraphAsymmErrors *gTrig[4];
	double x[hTrkR[0]->GetNbinsX()];
	double y[hTrkR[0]->GetNbinsX()];
	double yElw[hTrkR[0]->GetNbinsX()];
	double yEup[hTrkR[0]->GetNbinsX()];
	for(int iTrig=0; iTrig<4; iTrig++)
	{
		for(int i=0; i<hTrkR[0]->GetNbinsX(); i++)
		{
			x[i] = hTrkR[iTrig]->GetBinCenter(i+1);
			y[i] = hTrkR[iTrig]->GetBinContent(i+1);
			yElw[i] = hTrkR[iTrig]->GetBinError(i+1);
			yEup[i] = hTrkR[iTrig]->GetBinError(i+1);
			if(y[i]+yEup[i]>=1) yEup[i] = 1-y[i];
			if(y[i]-yElw[i]<=0) yElw[i] = y[i];
		}
		gTrig[iTrig] = new TGraphAsymmErrors(hTrkR[0]->GetNbinsX(),x,y,0,0,yElw,yEup);
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
	TLegend *leg = new TLegend(0.625,0.55,0.825,0.8);
	leg->SetBorderSize(0);
	leg->SetFillColor(0);
	leg->AddEntry(gTrig[0],"Bias = 2","lep");
	leg->AddEntry(gTrig[1],"Bias = 3","lep");
	leg->AddEntry(gTrig[2],"Bias = 4","lep");
	leg->AddEntry(gTrig[3],"Bias = 5","lep");

	TCanvas *cOut = new TCanvas("cOut","",400,400); 
	gStyle->SetOptStat(0);
	cOut->cd();
	gPad->SetTicks(1,1);
	gPad->SetTopMargin(0.05);
	gPad->SetBottomMargin(0.125);
	gPad->SetLeftMargin(0.125);
	gPad->SetRightMargin(0.05);
	for(int i=0; i<4; i++)
	{
		if(i==0)
		{
			gTrig[i]->GetXaxis()->SetRangeUser(0,50);
			gTrig[i]->GetXaxis()->SetTitle("N_{ch}^{rec}");
			gTrig[i]->GetXaxis()->SetTitleOffset(1.2);
			gTrig[i]->GetYaxis()->SetRangeUser(0,0.5);
			gTrig[i]->GetYaxis()->SetTitle("non-diffractive percentile");
			gTrig[i]->GetYaxis()->SetTitleOffset(1.5);
			gTrig[i]->Draw("APL");
		}
		else gTrig[i]->Draw("PL");
	}
	lin->DrawLine(0,1,maxTrk,1);
	leg->Draw();
	tex->DrawLatex(0.175,0.90,"#font[72]{ATLAS}  #font[42]{Internal}");
	tex->SetTextFont(42);
	tex->DrawLatex(0.175,0.825,"#font[12]{pp} #sqrt{s}=5TeV");

	cOut->Print("nonDiff_trk_655.pdf");
}



//----------------------------------------------------
// Draw FCal
//----------------------------------------------------
void drawFCal1()
{
	TFile *fIn = new TFile("hist_vte.root");
	TH1D *hTrk[4];
	for(int i=0; i<4; i++)
	{
		if(i==0) hTrk[i] = (TH1D*)fIn->Get("hTrk_TE50");
		if(i==1) hTrk[i] = (TH1D*)fIn->Get("hTrk_VTE50");
		if(i==2) hTrk[i] = (TH1D*)fIn->Get("hTrk_VTE50_trk");
		if(i==3) hTrk[i] = (TH1D*)fIn->Get("hTrk_VTE50_vtx");
		styleHist1(hTrk[i]);
		hTrk[i]->SetMarkerStyle(mS[i]);
		hTrk[i]->SetMarkerColor(mC[i]);
		hTrk[i]->SetLineStyle(lS[i]);
		hTrk[i]->SetLineColor(lC[i]);
	}

	TLatex *tex = new TLatex();
	tex->SetTextSize(0.04);
	tex->SetTextAlign(12);
	tex->SetNDC(1);
	TLine *lin = new TLine();
	lin->SetLineStyle(lS[0]);
	lin->SetLineColor(lC[0]);
	TLegend *leg = new TLegend(0.675,0.5,0.825,0.65);
	leg->SetBorderSize(0);
	leg->SetFillColor(0);
	leg->AddEntry(hTrk[0],"TE50","lep");
	leg->AddEntry(hTrk[1],"VTE50","lep");

	TCanvas *cOut = new TCanvas("cOut","",400,400);
	gStyle->SetOptStat(0);
	cOut->cd();
	gPad->SetLogy();
	gPad->SetTicks(1,1);
	gPad->SetTopMargin(0.05);
	gPad->SetBottomMargin(0.125);
	gPad->SetLeftMargin(0.125);
	gPad->SetRightMargin(0.05);
	hTrk[1]->GetXaxis()->SetTitle("FCal E_{T}");
	hTrk[1]->GetXaxis()->SetTitleOffset(1.25);
	//hTrk[0]->GetXaxis()->SetRangeUser(0,75);
	//hTrk[1]->GetYaxis()->SetTitle("VTE percentile");
	hTrk[1]->GetYaxis()->SetTitleOffset(1.25);
	hTrk[1]->GetYaxis()->SetRangeUser(1,800000);
	hTrk[1]->Draw("PL");
	hTrk[0]->Draw("PL same");
	tex->DrawLatex(0.575,0.80,"#font[72]{ATLAS}  #font[42]{Internal}");
	tex->SetTextFont(42);
	tex->DrawLatex(0.575,0.725,"#font[12]{PbPb} #sqrt{s}=5.02TeV");
	leg->Draw();

	cOut->Print("FCal1_665.pdf");
}
void drawFCal2()
{
	TFile *fIn = new TFile("hist_vte.root");
	TH1D *hTrk[4];
	for(int i=0; i<3; i++)
	{
		if(i==0) hTrk[i] = (TH1D*)fIn->Get("hTrk_VTE50_mb");
		if(i==1) hTrk[i] = (TH1D*)fIn->Get("hTrk_VTE50_trk");
		if(i==2) hTrk[i] = (TH1D*)fIn->Get("hTrk_VTE50_vtx");
		styleHist1(hTrk[i]);
		hTrk[i]->SetMarkerStyle(mS[i]);
		hTrk[i]->SetMarkerColor(mC[i]);
		hTrk[i]->SetLineStyle(lS[i]);
		hTrk[i]->SetLineColor(lC[i]);
	}

	TLatex *tex = new TLatex();
	tex->SetTextSize(0.04);
	tex->SetTextAlign(12);
	tex->SetNDC(1);
	TLine *lin = new TLine();
	lin->SetLineStyle(lS[0]);
	lin->SetLineColor(lC[0]);
	TLegend *leg = new TLegend(0.275,0.2,0.625,0.45);
	leg->SetBorderSize(0);
	leg->SetFillColor(0);
	leg->AddEntry(hTrk[0],"VTE50","lep");
	leg->AddEntry(hTrk[1],"VTE50 with N_{ch}>0","lep");
	leg->AddEntry(hTrk[2],"VTE50 with N_{vtx}>0","lep");

	TCanvas *cOut = new TCanvas("cOut","",400,400);
	gStyle->SetOptStat(0);
	cOut->cd();
	gPad->SetLogy();
	gPad->SetTicks(1,1);
	gPad->SetTopMargin(0.05);
	gPad->SetBottomMargin(0.125);
	gPad->SetLeftMargin(0.125);
	gPad->SetRightMargin(0.05);
	hTrk[0]->GetXaxis()->SetTitle("FCal E_{T}");
	hTrk[0]->GetXaxis()->SetTitleOffset(1.25);
	hTrk[0]->GetXaxis()->SetRangeUser(-0.01,0.15);
	//hTrk[0]->GetYaxis()->SetTitle("VTE percentile");
	hTrk[0]->GetYaxis()->SetTitleOffset(1.25);
	hTrk[0]->GetYaxis()->SetRangeUser(1,80000);
	hTrk[0]->Draw("PL");
	hTrk[1]->Draw("PL same");
	hTrk[2]->Draw("PL same");
	tex->DrawLatex(0.575,0.80,"#font[72]{ATLAS}  #font[42]{Internal}");
	tex->SetTextFont(42);
	tex->DrawLatex(0.575,0.725,"#font[12]{PbPb} #sqrt{s}=5.02TeV");
	leg->Draw();

	cOut->Print("FCal2_665.pdf");
}



//----------------------------------------------------
// Draw Weighting
//----------------------------------------------------
void drawWei()
{
	TFile *fIn = new TFile("hist_vte.root");
	TH1D *hWei = (TH1D*)fIn->Get("hWei");
	styleHist1(hWei);
	hWei->SetMarkerStyle(mS[0]);
	hWei->SetMarkerColor(mC[0]);
	hWei->SetLineStyle(lS[0]);
	hWei->SetLineColor(lC[0]);
	TH1D *hWei_etA[4];
	TH1D *hWei_etC[4];
	TH1D *hWei_trk[4];
	for(int i=0; i<4; i++)
	{
		sprintf(name,"hWei_etA_%d",i);
		hWei_etA[i] = (TH1D*)fIn->Get(name);
		styleHist1(hWei_etA[i]);
		hWei_etA[i]->SetMarkerStyle(mS[i]);
		hWei_etA[i]->SetMarkerColor(mC[i]);
		hWei_etA[i]->SetLineStyle(lS[i]);
		hWei_etA[i]->SetLineColor(lC[i]);
		sprintf(name,"hWei_etC_%d",i);
		hWei_etC[i] = (TH1D*)fIn->Get(name);
		styleHist1(hWei_etC[i]);
		hWei_etC[i]->SetMarkerStyle(mS[i]);
		hWei_etC[i]->SetMarkerColor(mC[i]);
		hWei_etC[i]->SetLineStyle(lS[i]);
		hWei_etC[i]->SetLineColor(lC[i]);
		sprintf(name,"hWei_trk_%d",i);
		hWei_trk[i] = (TH1D*)fIn->Get(name);
		styleHist1(hWei_trk[i]);
		hWei_trk[i]->SetMarkerStyle(mS[i]);
		hWei_trk[i]->SetMarkerColor(mC[i]);
		hWei_trk[i]->SetLineStyle(lS[i]);
		hWei_trk[i]->SetLineColor(lC[i]);
	}
	
	TLatex *tex = new TLatex();
	tex->SetTextSize(0.04);
	tex->SetTextAlign(12);
	tex->SetNDC(1);
	TLine *lin = new TLine();
	lin->SetLineStyle(lS[0]);
	lin->SetLineColor(lC[0]);
	TLegend *leg = new TLegend(0.25,0.6,0.45,0.85);
	leg->SetBorderSize(0);
	leg->SetFillColor(0);
	leg->AddEntry(hWei_etA[0],"|<#eta>|>40","lep");
	leg->AddEntry(hWei_etA[1],"|<#eta>|>60","lep");
	leg->AddEntry(hWei_etA[2],"|<#eta>|>80","lep");
	leg->AddEntry(hWei_etA[3],"|<#eta>|>100","lep");

	TCanvas *cOut1 = new TCanvas("cOut1","",400,400);
	gStyle->SetOptStat(0);
	cOut1->cd();
	gPad->SetTicks(1,1);
	gPad->SetTopMargin(0.05);
	gPad->SetBottomMargin(0.1);
	gPad->SetLeftMargin(0.2);
	gPad->SetRightMargin(0.05);
	hWei->GetXaxis()->SetTitle("<#eta>");
	hWei->GetXaxis()->SetTitleOffset(1);
	hWei->GetXaxis()->SetRangeUser(-500,500);
	hWei->GetYaxis()->SetTitle("Counts");
	hWei->GetYaxis()->SetTitleOffset(2.5);
	hWei->GetYaxis()->SetRangeUser(0,2000);
	hWei->Draw("P");
	tex->DrawLatex(0.6,0.85,"#font[72]{ATLAS}  #font[42]{Internal}");
	tex->SetTextFont(42);
	tex->DrawLatex(0.6,0.775,"#font[12]{PbPb} #sqrt{s}=5.02TeV");

	TCanvas *cOut2 = new TCanvas("cOut2","",800,400);
	cOut2->Divide(2,1,0.0001,0.0001);
	gStyle->SetOptStat(0);
	for(int iC=0; iC<2; iC++)
	{
		cOut2->cd(iC+1);
		gPad->SetTicks(1,1);
		gPad->SetTopMargin(0.05);
		gPad->SetBottomMargin(0.1);
		gPad->SetLeftMargin(0.2);
		gPad->SetRightMargin(0.05);
		if(iC==0)
		{
			hWei_etA[0]->GetXaxis()->SetTitle("#eta");
			hWei_etA[0]->GetXaxis()->SetTitleOffset(1);
			hWei_etA[0]->GetXaxis()->SetRangeUser(-5,5);
			hWei_etA[0]->GetYaxis()->SetTitle("E_{T}");
			hWei_etA[0]->GetYaxis()->SetTitleOffset(1.5);
			hWei_etA[0]->GetYaxis()->SetRangeUser(0,0.007);
			hWei_etA[0]->Draw("PL");
			for(int i=1; i<4; i++) hWei_etA[i]->Draw("PL same");
			tex->DrawLatex(0.6,0.85,"#font[72]{ATLAS}  #font[42]{Internal}");
			tex->SetTextFont(42);
			tex->DrawLatex(0.6,0.775,"#font[12]{PbPb} #sqrt{s}=5.02TeV");
		}
		if(iC==1)
		{
			hWei_etC[0]->GetXaxis()->SetTitle("#eta");
			hWei_etC[0]->GetXaxis()->SetTitleOffset(1);
			hWei_etC[0]->GetXaxis()->SetRangeUser(-5,5);
			hWei_etC[0]->GetYaxis()->SetTitle("E_{T}");
			hWei_etC[0]->GetYaxis()->SetTitleOffset(1.5);
			hWei_etC[0]->GetYaxis()->SetRangeUser(0,0.007);
			hWei_etC[0]->Draw("PL");
			for(int i=1; i<4; i++) hWei_etC[i]->Draw("PL same");
			leg->Draw();
		}
	}
	
	TCanvas *cOut3 = new TCanvas("cOut3","",400,400);
	gStyle->SetOptStat(0);
	cOut3->cd();
	gPad->SetTicks(1,1);
	gPad->SetTopMargin(0.05);
	gPad->SetBottomMargin(0.1);
	gPad->SetLeftMargin(0.2);
	gPad->SetRightMargin(0.05);
	hWei_trk[0]->GetXaxis()->SetTitle("N_{ch}");
	hWei_trk[0]->GetXaxis()->SetTitleOffset(1);
	hWei_trk[0]->GetXaxis()->SetRangeUser(-0.5,19.5);
	hWei_trk[0]->GetYaxis()->SetTitle("Fraction");
	hWei_trk[0]->GetYaxis()->SetTitleOffset(1.5);
	hWei_trk[0]->GetYaxis()->SetRangeUser(0,0.8);
	hWei_trk[0]->Draw("PL");
	for(int i=1; i<4; i++) hWei_trk[i]->Draw("PL same");
	tex->DrawLatex(0.25,0.85,"#font[72]{ATLAS}  #font[42]{Internal}");
	tex->SetTextFont(42);
	tex->DrawLatex(0.25,0.775,"#font[12]{PbPb} #sqrt{s}=5.02TeV");

	cOut1->Print("wei_dis.pdf");
	cOut2->Print("wei_bias.pdf");
	cOut3->Print("wei_ratio.pdf");
}



//----------------------------------------------------
// Macro
//----------------------------------------------------
void drawVTE()
{
	gen();

	//drawL1TE();
	//drawCorr();
	//drawBias();
	//drawRatio();
	//drawFCal1();
	//drawFCal2();

	//drawWei();
}
















