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
		"L1_RD0_FILLED",
		"L1_ZDC_A_C",
		"L1_ZDC_AND",
		"L1_ZDC_A",
		"L1_ZDC_C",
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
		"L1_ZDC_A_C_VTE50",
		"L1_TE5_VTE200",
		"HLT_noalg_mb_L1TE50",
		"HLT_mb_sptrk_ion_L1ZDC_A_C_VTE50",
		"HLT_mb_sp",
		"HLT_hi_th1_ucc_L1TE14000",
		"HLT_hi_th2_ucc_L1TE14000",
		"HLT_hi_th3_ucc_L1TE14000",
		"HLT_mb_sp1600_pusup1100_trk90_hmt_L1TE50",
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
	tree->SetBranchAddress("bcid",&bcid);
	tree->SetBranchAddress("trig",trig);
	tree->SetBranchAddress("trigL1",trigL1);
	//tree->SetBranchAddress("nVtx",&nVtx);
	//tree->SetBranchAddress("zVtx",&zVtx);
	tree->SetBranchAddress("nTrk",&nTrk);
	//tree->SetBranchAddress("nEt",&nEt);
	//tree->SetBranchAddress("et",et);
	//tree->SetBranchAddress("etaMin",etaMin);
	//tree->SetBranchAddress("etaMax",etaMax);
	tree->SetBranchAddress("eta",eta);
	tree->SetBranchAddress("pt",pt);
	int nEvt = tree->GetEntries();
	//nEvt = 100000;

	TH1D *hTrigRate = new TH1D("hTrigRate","hTrigRate",nTrig+1,-1.5,nTrig-0.5);
	hTrigRate->GetXaxis()->SetBinLabel(1,"all");
	for (int i=1; i<=nTrig; i++) hTrigRate->GetXaxis()->SetBinLabel(i+1,trigLabel[i-1]);
	TH1D *hEvt_A = new TH1D("hEvt_A","",50,-0.5,49.5);
	TH1D *hEvt_C = new TH1D("hEvt_C","",50,-0.5,49.5);
	TH1D *hEvt_B = new TH1D("hEvt_B","",50,-0.5,49.5);
	TH2D *hPt_A = new TH2D("hPt_A","",100,0,10,50,-0.5,49.5);
	TH2D *hPt_C = new TH2D("hPt_C","",100,0,10,50,-0.5,49.5);
	TH2D *hPt_B = new TH2D("hPt_B","",100,0,10,50,-0.5,49.5);
	
	int tagFst;
	int tagLst;
	cout<<"Processing..."<<endl;
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

		if(trig[20]<0) continue;

		hTrigRate->Fill(-1);
		for(int iTrig=0; iTrig<nTrig; iTrig++)
		{
			if(trig[iTrig]>0) hTrigRate->Fill(iTrig);
		}

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

		//if(tagLst!=1) continue;

		if(trigL1[3]>0 && trigL1[4]==0)
		{
			hEvt_A->Fill(nTrk);
			for(int i=0; i<nTrk; i++) hPt_A->Fill(pt[i],nTrk,1);
		}
		if(trigL1[3]==0 && trigL1[4]>0)
		{
			hEvt_C->Fill(nTrk);
			for(int i=0; i<nTrk; i++) hPt_C->Fill(pt[i],nTrk,1);
		}
		if(trigL1[1]>0)
		{
			hEvt_B->Fill(nTrk);
			for(int i=0; i<nTrk; i++) hPt_B->Fill(pt[i],nTrk,1);
		}
	}
	cout<<"Done!"<<endl;

	sprintf(name,"hist_pt_mb.root");
	TFile *fOut = new TFile(name,"recreate");
	fOut->cd();
	hTrigRate->Write();
	hEvt_A->Write();
	hEvt_C->Write();
	hEvt_B->Write();
	hPt_A->Write();
	hPt_C->Write();
	hPt_B->Write();
	fOut->Close();
}



//----------------------------------------------------
// Draw comparison
//----------------------------------------------------
void drawComp()
{
	TFile *fIn = new TFile("hist_pt_mb.root");
	TH1D *hEvt_A = (TH1D*)fIn->Get("hEvt_A");
	styleHist1(hEvt_A);
	TH1D *hEvt_C = (TH1D*)fIn->Get("hEvt_C");
	styleHist1(hEvt_C);
	TH1D *hEvt_B = (TH1D*)fIn->Get("hEvt_B");
	styleHist1(hEvt_B);
	TH2D *hPt_A = (TH2D*)fIn->Get("hPt_A");
	styleHist2(hPt_A);
	TH2D *hPt_C = (TH2D*)fIn->Get("hPt_C");
	styleHist2(hPt_C);
	TH2D *hPt_B = (TH2D*)fIn->Get("hPt_B");
	styleHist2(hPt_B);

	TH2D *hPtN_A = (TH2D*)hPt_A->Clone("hPtN_A");
	TH2D *hPtN_C = (TH2D*)hPt_C->Clone("hPtN_C");
	TH2D *hPtN_B = (TH2D*)hPt_B->Clone("hPtN_B");
	TH2D *hPtN_D = (TH2D*)hPtN_B->Clone("hPtN_D");
	for(int i=0; i<hPt_B->GetNbinsX(); i++)
	{
		for(int j=1; j<hPt_B->GetNbinsY(); j++)
		{
			if(hEvt_A->GetBinContent(j+1)>0) hPtN_A->SetBinContent(i+1,j+1,hPtN_A->GetBinContent(i+1,j+1)/hEvt_A->GetBinContent(j+1)/j);
			if(hEvt_C->GetBinContent(j+1)>0) hPtN_C->SetBinContent(i+1,j+1,hPtN_C->GetBinContent(i+1,j+1)/hEvt_C->GetBinContent(j+1)/j);
			if(hEvt_B->GetBinContent(j+1)>0) hPtN_B->SetBinContent(i+1,j+1,hPtN_B->GetBinContent(i+1,j+1)/hEvt_B->GetBinContent(j+1)/j);
			hPtN_D->SetBinContent(i+1,j+1,(hPtN_A->GetBinContent(i+1,j+1)+hPtN_C->GetBinContent(i+1,j+1))/2);
		}
	}

	TH1D *hProj_A[3];
	TH1D *hProj_C[3];
	TH1D *hProj_B[3];
	TH1D *hProj_D[3];
	for(int i=0; i<3; i++)
	{
		sprintf(name,"hProj_A_%d",i);
		hProj_A[i] = new TH1D(name,"",100,0,10);
		styleHist1(hProj_A[i]);
		sprintf(name,"hProj_C_%d",i);
		hProj_C[i] = new TH1D(name,"",100,0,10);
		styleHist1(hProj_C[i]);
		sprintf(name,"hProj_B_%d",i);
		hProj_B[i] = new TH1D(name,"",100,0,10);
		styleHist1(hProj_B[i]);
		sprintf(name,"hProj_D_%d",i);
		hProj_D[i] = new TH1D(name,"",100,0,10);
		styleHist1(hProj_D[i]);
	}
	for(int i=0; i<hPt_B->GetNbinsX(); i++)
	{
		for(int j=0; j<3; j++)
		{
			for(int k=0; k<10; k++)
			{
				hProj_A[j]->AddBinContent(i+1,hPtN_A->GetBinContent(i+1,j*10+k+1)/10);
				hProj_C[j]->AddBinContent(i+1,hPtN_C->GetBinContent(i+1,j*10+k+1)/10);
				hProj_B[j]->AddBinContent(i+1,hPtN_B->GetBinContent(i+1,j*10+k+1)/10);
				hProj_D[j]->AddBinContent(i+1,hPtN_D->GetBinContent(i+1,j*10+k+1)/10);
			}
		}
	}
	for(int i=0; i<3; i++)
	{
		hProj_A[i]->Rebin(2);
		hProj_C[i]->Rebin(2);
		hProj_B[i]->Rebin(2);
		hProj_D[i]->Rebin(2);

		hProj_B[i]->SetMarkerStyle(mS[0]);
		hProj_B[i]->SetMarkerColor(mC[0]);
		hProj_B[i]->SetLineStyle(lS[0]);
		hProj_B[i]->SetLineColor(lC[0]);
		hProj_D[i]->SetMarkerStyle(mS[1]);
		hProj_D[i]->SetMarkerColor(mC[1]);
		hProj_D[i]->SetLineStyle(lS[1]);
		hProj_D[i]->SetLineColor(lC[1]);
	}

	TLatex *tex = new TLatex();
	tex->SetTextSize(0.04);
	tex->SetTextAlign(12);
	tex->SetNDC(1);
	TLine *lin = new TLine();
	lin->SetLineStyle(lS[0]);
	lin->SetLineColor(lC[0]);
	TLegend *leg = new TLegend(0.45,0.75,0.85,0.85);
	leg->SetBorderSize(0);
	leg->SetFillColor(0);
	leg->AddEntry(hProj_B[0],"ZDC_A_C","lep");
	leg->AddEntry(hProj_D[0],"ZDC_A(C) ONLY","lep");

	TCanvas *cOut0 = new TCanvas("cOut0","",1200,400);
	cOut0->Divide(3,1,0.0001,0.0001);
	gStyle->SetOptStat(0);
	gStyle->SetNumberContours(100);
	TH1D *h1Copy;
	for(int iC=0; iC<3; iC++)
	{
		if(iC==0) h1Copy = (TH1D*)hEvt_A->Clone("h1Copy");
		if(iC==1) h1Copy = (TH1D*)hEvt_B->Clone("h1Copy");
		if(iC==2) h1Copy = (TH1D*)hEvt_C->Clone("h1Copy");
		cOut0->cd(iC+1);
		gPad->SetLogy();
		gPad->SetTicks(1,1);
		gPad->SetTopMargin(0.075);
		gPad->SetBottomMargin(0.1);
		gPad->SetLeftMargin(0.125);
		gPad->SetRightMargin(0.05);
		if(iC==0) h1Copy->SetTitle("ZDC_A ONLY");
		if(iC==1) h1Copy->SetTitle("ZDC_A_C");
		if(iC==2) h1Copy->SetTitle("ZDC_C ONLY");
		h1Copy->GetXaxis()->SetTitle("N_{ch}");
		h1Copy->GetXaxis()->SetTitleOffset(1.25);
		h1Copy->GetXaxis()->SetRangeUser(-0.5,29.5);
		h1Copy->GetYaxis()->SetTitle("dN_{evt} / N_{ch}");
		h1Copy->GetYaxis()->SetTitleOffset(1.25);
		//h1Copy->GetYaxis()->SetRangeUser(-0.5,49.5);
		h1Copy->SetFillStyle(3013);
		h1Copy->SetFillColor(46);
		h1Copy->DrawCopy();
		tex->DrawLatex(0.575,0.85,"#font[72]{ATLAS}  #font[42]{Internal}");
		tex->SetTextFont(42);
		tex->DrawLatex(0.575,0.775,"#font[12]{Pb+Pb} #sqrt{s}=5.02TeV");
	}

	TCanvas *cOut1 = new TCanvas("cOut1","",1200,800);
	cOut1->Divide(3,2,0.0001,0.0001);
	gStyle->SetOptStat(0);
	gStyle->SetNumberContours(100);
	TH2D *h2Copy;
	for(int iC=0; iC<6; iC++)
	{
		if(iC==0) h2Copy = (TH2D*)hPt_A->Clone("h2Copy");
		if(iC==1) h2Copy = (TH2D*)hPt_B->Clone("h2Copy");
		if(iC==2) h2Copy = (TH2D*)hPt_C->Clone("h2Copy");
		if(iC==3) h2Copy = (TH2D*)hPtN_A->Clone("h2Copy");
		if(iC==4) h2Copy = (TH2D*)hPtN_B->Clone("h2Copy");
		if(iC==5) h2Copy = (TH2D*)hPtN_C->Clone("h2Copy");
		cOut1->cd(iC+1);
		gPad->SetLogz();
		gPad->SetTicks(1,1);
		gPad->SetTopMargin(0.135);
		gPad->SetBottomMargin(0.1);
		gPad->SetLeftMargin(0.1);
		gPad->SetRightMargin(0.125);
		if(iC==0) h2Copy->SetTitle("#scale[0.8]{#frac{dN_{ch}}{dp_{T}} | ZDC_A ONLY}");
		if(iC==1) h2Copy->SetTitle("#scale[0.8]{#frac{dN_{ch}}{dp_{T}} | ZDC_A_C}");
		if(iC==2) h2Copy->SetTitle("#scale[0.8]{#frac{dN_{ch}}{dp_{T}} | ZDC_C ONLY}");
		if(iC==3) h2Copy->SetTitle("#scale[0.8]{#frac{dN_{ch}}{N_{ch} dp_{T}} | ZDC_A ONLY}");
		if(iC==4) h2Copy->SetTitle("#scale[0.8]{#frac{dN_{ch}}{N_{ch} dp_{T}} | ZDC_A_C}");
		if(iC==5) h2Copy->SetTitle("#scale[0.8]{#frac{dN_{ch}}{N_{ch} dp_{T}} | ZDC_C ONLY}");
		h2Copy->GetXaxis()->SetTitle("p_{T}");
		h2Copy->GetXaxis()->SetTitleOffset(2.25);
		h2Copy->GetXaxis()->SetRangeUser(0,10);
		h2Copy->GetYaxis()->SetTitle("N_{ch}");
		h2Copy->GetYaxis()->SetTitleOffset(2.25);
		h2Copy->GetYaxis()->SetRangeUser(-0.5,29.5);
		h2Copy->DrawCopy("colz");
		if(iC%3==0)
		{
			tex->DrawLatex(0.55,0.80,"#font[72]{ATLAS}  #font[42]{Internal}");
			tex->SetTextFont(42);
			tex->DrawLatex(0.55,0.725,"#font[12]{Pb+Pb} #sqrt{s}=5.02TeV");
		}
	}

	TCanvas *cOut2 = new TCanvas("cOut2","",1200,400);
	cOut2->Divide(3,1,0.0001,0.0001);
	gStyle->SetOptStat(0);
	gStyle->SetNumberContours(100);
	TH1D *h1CopyM[2];
	for(int iC=0; iC<3; iC++)
	{
		if(iC==0)
		{
			h1CopyM[0] = (TH1D*)hProj_D[0]->Clone("h1CopyM");
			h1CopyM[1] = (TH1D*)hProj_B[0]->Clone("h1CopyM");
		}
		if(iC==1)
		{
			h1CopyM[0] = (TH1D*)hProj_D[1]->Clone("h1CopyM");
			h1CopyM[1] = (TH1D*)hProj_B[1]->Clone("h1CopyM");
		}
		if(iC==2)
		{
			h1CopyM[0] = (TH1D*)hProj_D[2]->Clone("h1CopyM");
			h1CopyM[1] = (TH1D*)hProj_B[2]->Clone("h1CopyM");
		}
		cOut2->cd(iC+1);
		gPad->SetLogy();
		gPad->SetTicks(1,1);
		gPad->SetTopMargin(0.075);
		gPad->SetBottomMargin(0.1);
		gPad->SetLeftMargin(0.15);
		gPad->SetRightMargin(0.05);
		if(iC==0) h1CopyM[0]->SetTitle("0 #leq N_{ch} < 10");
		if(iC==1) h1CopyM[0]->SetTitle("10 #leq N_{ch} < 20");
		if(iC==2) h1CopyM[0]->SetTitle("20 #leq N_{ch} < 30");
		h1CopyM[0]->GetXaxis()->SetTitle("p_{T}");
		h1CopyM[0]->GetXaxis()->SetTitleOffset(1.25);
		h1CopyM[0]->GetXaxis()->SetRangeUser(0.2,10);
		h1CopyM[0]->GetYaxis()->SetTitle("dN_{evt} / (dp_{T} N_{evt} N_{ch})");
		h1CopyM[0]->GetYaxis()->SetTitleOffset(1.5);
		h1CopyM[0]->SetMaximum(2.);
		//h1CopyM[0]->GetYaxis()->SetRangeUser(0.5,10);
		h1CopyM[0]->DrawCopy("PL");
		h1CopyM[1]->DrawCopy("PL same");
		if(iC==0)
		{
			tex->DrawLatex(0.575,0.85,"#font[72]{ATLAS}  #font[42]{Internal}");
			tex->SetTextFont(42);
			tex->DrawLatex(0.575,0.775,"#font[12]{Pb+Pb} #sqrt{s}=5.02TeV");
		}
		if(iC==1) leg->Draw();
	}


	cOut0->Print("pt_Evt_mb.pdf");
	cOut1->Print("pt_2D_mb.pdf");
	cOut2->Print("pt_1D_mb.pdf");
}



//----------------------------------------------------
// Macro
//----------------------------------------------------
void draw_pt()
{
	gen();

	drawComp();
}















