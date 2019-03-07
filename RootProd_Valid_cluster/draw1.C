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
	const char *trigLabel[nTrig] = {
		"L1_RD0_FILLED",
		"L1_MBTS_1",
		"L1_MBTS_1_1",
		"L1_TE5",
		"L1_TE10",
		"L1_TE20",
		"L1_TE30",
		"L1_TE40",
		"L1_TE50",
		"L1_TE60",
		"L1_TE70",
		"HLT_mb_sptrk",
		"HLT_mb_sp700_hmtperf_L1TE5",
		"HLT_mb_sp1500_hmtperf_L1TE10",
		"HLT_mb_sp2100_hmtperf_L1TE10",
		"HLT_mb_sp400_trk40_hmt_L1MBTS_1_1",
		"HLT_mb_sp800_pusup400_trk50_hmt_L1TE5",
		"HLT_mb_sp900_pusup500_trk60_hmt_L1TE5",
		"HLT_mb_sp1200_pusup700_trk70_hmt_L1TE5",
		"HLT_mb_sp1400_pusup550_trk90_hmt_L1TE10",
		"HLT_mb_sp1600_pusup1100_trk90_hmt_L1TE10",
		"HLT_mb_sp1400_pusup550_trk90_hmt_L1TE20",
		"HLT_mb_sp1600_pusup1100_trk90_hmt_L1TE20",
		"HLT_mb_sp1600_pusup1100_trk90_hmt_L1TE40",
		"HLT_mb_sp1600_pusup1100_trk90_hmt_L1TE50",
		};

	sprintf(name,"data_767_1.root");
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
	tree->SetBranchAddress("trig",trig);
	tree->SetBranchAddress("trigL1",trigL1);
	tree->SetBranchAddress("nVtx",&nVtx);
	tree->SetBranchAddress("zVtx",&zVtx);
	tree->SetBranchAddress("nTrk",&nTrk);
	tree->SetBranchAddress("nEt",&nEt);
	tree->SetBranchAddress("et",et);
	tree->SetBranchAddress("etaMin",etaMin);
	tree->SetBranchAddress("etaMax",etaMax);
	tree->SetBranchAddress("eta",eta);
	int nEvt = tree->GetEntries();

	TH1D *hTrigRate = new TH1D("hTrigRate","hTrigRate",nTrig+1,-1.5,nTrig-0.5);
	hTrigRate->GetXaxis()->SetBinLabel(1,"all");
	for (int i=1; i<=nTrig; i++) hTrigRate->GetXaxis()->SetBinLabel(i+1,trigLabel[i-1]);
	TH2D *hEt_trk[2];
	TH2D *hEtP_trk[2];
	TH2D *hTrk_trk[2];
	TH2D *hTrkP_trk[2];
	for(int i=0; i<2; i++)
	{
		sprintf(name,"hEt_trk_%d",i);
		hEt_trk[i] = new TH2D(name,name,100,-5,5,50,-0.5,49.5);
		hEt_trk[i]->Sumw2();
		sprintf(name,"hEtP_trk_%d",i);
		hEtP_trk[i] = new TH2D(name,name,100,-5,5,50,-0.5,49.5);
		hEtP_trk[i]->Sumw2();
		sprintf(name,"hTrk_trk_%d",i);
		hTrk_trk[i] = new TH2D(name,name,100,-5,5,50,-0.5,49.5);
		hTrk_trk[i]->Sumw2();
		sprintf(name,"hTrkP_trk_%d",i);
		hTrkP_trk[i] = new TH2D(name,name,100,-5,5,50,-0.5,49.5);
		hTrkP_trk[i]->Sumw2();
	}
	TH1D *hTrk_L1[nTrig];
	TH1D *hTrk_mbL1[nTrig];
	TH1D *hTrk_psL1[nTrig];
	TH1D *hTrk_HLT[nTrig];
	TH1D *hTrk_mbHLT[nTrig];
	TH1D *hTrk_psHLT[nTrig];
	for(int iTrig=0; iTrig<nTrig; iTrig++)
	{
		sprintf(name,"hTrk_L1_%d",iTrig);
		hTrk_L1[iTrig] = new TH1D(name,name,200,0,200);
		hTrk_L1[iTrig]->Sumw2();
		sprintf(name,"hTrk_mbL1_%d",iTrig);
		hTrk_mbL1[iTrig] = new TH1D(name,name,200,0,200);
		hTrk_mbL1[iTrig]->Sumw2();
		sprintf(name,"hTrk_psL1_%d",iTrig);
		hTrk_psL1[iTrig] = new TH1D(name,name,200,0,200);
		hTrk_psL1[iTrig]->Sumw2();
		sprintf(name,"hTrk_HLT_%d",iTrig);
		hTrk_HLT[iTrig] = new TH1D(name,name,200,0,200);
		hTrk_HLT[iTrig]->Sumw2();
		sprintf(name,"hTrk_mbHLT_%d",iTrig);
		hTrk_mbHLT[iTrig] = new TH1D(name,name,200,0,200);
		hTrk_mbHLT[iTrig]->Sumw2();
		sprintf(name,"hTrk_psHLT_%d",iTrig);
		hTrk_psHLT[iTrig] = new TH1D(name,name,200,0,200);
		hTrk_psHLT[iTrig]->Sumw2();
	}
	TH2D *h_ZDC_MBTS = new TH2D("h_ZDC_MBTS","",2,-0.5,1.5,2,-0.5,1.5);

	cout<<"Processing..."<<endl;
	TH1D *hEt_tmp = new TH1D("hEt_tmp","",100,-5,5);
	const int trigSlc[2] = {1,6};
	int cntEt[2][50];
	int cntEtP[2][50];
	int cntTrk[2][50];
	int cntTrkP[2][50];
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<50; j++)
		{
			cntEt[i][j] = 0;
			cntEtP[i][j] = 0;
			cntTrk[i][j] = 0;
			cntTrkP[i][j] = 0;
		}
	}
	for(int iEvt=0; iEvt<nEvt; iEvt++)
	{
		if(iEvt%10==0)
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
			if(trig[20]>0 && trigL1[iTrig]>0) hTrk_mbL1[iTrig]->Fill(nTrk);
			if(trig[20]>0 && trigL1[iTrig]>0) hTrk_psL1[iTrig]->Fill(nTrk,trig[1]);
			if(trig[iTrig]>0) hTrk_HLT[iTrig]->Fill(nTrk);
			if(trig[20]>0 && trig[iTrig]>0) hTrk_mbHLT[iTrig]->Fill(nTrk);
			if(trig[iTrig]>0) hTrk_psHLT[iTrig]->Fill(nTrk,trig[iTrig]);
			if(trigL1[iTrig]>0) hTrigRate->Fill(iTrig);
		}

		if(trig[20]>0)
		{
			if(trigL1[1]>0 && trigL1[6]>0) h_ZDC_MBTS->Fill(1.,1.);
			if(trigL1[1]>0 && trigL1[6]==0) h_ZDC_MBTS->Fill(1.,0.);
			if(trigL1[1]==0 && trigL1[6]>0) h_ZDC_MBTS->Fill(0.,1.);
			if(trigL1[1]==0 && trigL1[6]==0) h_ZDC_MBTS->Fill(0.,0.);
		}

		for(int j=0; j<2; j++)
		{
			if(trig[20]>0 && trigL1[trigSlc[j]]==0)
			{
				if(nTrk<50) cntEt[j][nTrk]++;
				hEt_tmp->Reset();
				for(int i=0; i<nEt; i++) hEt_tmp->Fill((etaMin[i]+etaMax[i])/2,et[i]);		
				for(int i=0; i<hEt_tmp->GetNbinsX(); i++)
				{
					hEt_trk[j]->Fill(-5+(2*i+1)*0.05,nTrk,hEt_tmp->GetBinContent(i+1));
				}
			}
			if(trig[20]>0 && trigL1[trigSlc[j]]>0)
			{
				if(nTrk<50) cntEtP[j][nTrk]++;
				hEt_tmp->Reset();
				for(int i=0; i<nEt; i++) hEt_tmp->Fill((etaMin[i]+etaMax[i])/2,et[i]);		
				for(int i=0; i<hEt_tmp->GetNbinsX(); i++)
				{
					hEtP_trk[j]->Fill(-5+(2*i+1)*0.05,nTrk,hEt_tmp->GetBinContent(i+1));
				}
			}
			if(trig[20]>0 && trigL1[trigSlc[j]]==0)
			{
				if(nTrk<50) cntTrk[j][nTrk]++;
				for(int i=0; i<nTrk; i++) hTrk_trk[j]->Fill(eta[i],nTrk,1);
			}
			if(trig[20]>0 && trigL1[trigSlc[j]]>0)
			{
				if(nTrk<50) cntTrkP[j][nTrk]++;
				for(int i=0; i<nTrk; i++) hTrkP_trk[j]->Fill(eta[i],nTrk,1);
			}
		}
	}
	cout<<"Done!"<<endl;
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<50; j++)
		{
			for(int k=0; k<100; k++)
			{
				if(cntEt[i][j]!=0) hEt_trk[i]->SetBinContent(k+1,j+1,hEt_trk[i]->GetBinContent(k+1,j+1)/cntEt[i][j]);
				if(cntEtP[i][j]!=0) hEtP_trk[i]->SetBinContent(k+1,j+1,hEtP_trk[i]->GetBinContent(k+1,j+1)/cntEtP[i][j]);
				if(cntTrk[i][j]!=0) hTrk_trk[i]->SetBinContent(k+1,j+1,hTrk_trk[i]->GetBinContent(k+1,j+1)/cntTrk[i][j]);
				if(cntTrkP[i][j]!=0) hTrkP_trk[i]->SetBinContent(k+1,j+1,hTrkP_trk[i]->GetBinContent(k+1,j+1)/cntTrkP[i][j]);
			}
		}
	}

	sprintf(name,"trig_AC.root");
	TFile *fOut = new TFile(name,"recreate");
	fOut->cd();
	hTrigRate->Write();
	h_ZDC_MBTS->Write();
	for(int i=0; i<2; i++) hEt_trk[i]->Write();
	for(int i=0; i<2; i++) hEtP_trk[i]->Write();
	for(int i=0; i<2; i++) hTrk_trk[i]->Write();
	for(int i=0; i<2; i++) hTrkP_trk[i]->Write();
	for(int iTrig=0; iTrig<nTrig; iTrig++) hTrk_L1[iTrig]->Write();
	for(int iTrig=0; iTrig<nTrig; iTrig++) hTrk_mbL1[iTrig]->Write();
	for(int iTrig=0; iTrig<nTrig; iTrig++) hTrk_psL1[iTrig]->Write();
	for(int iTrig=0; iTrig<nTrig; iTrig++) hTrk_HLT[iTrig]->Write();
	for(int iTrig=0; iTrig<nTrig; iTrig++) hTrk_mbHLT[iTrig]->Write();
	for(int iTrig=0; iTrig<nTrig; iTrig++) hTrk_psHLT[iTrig]->Write();
	fOut->Close();
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
	const int trigSlc[4] = {16,13,3,4};
	TH1D *hRef = (TH1D*)hTrk_mbL1[0]->Clone("hRef");
	//hRef->Rebin(2);
	TH1D *hChk[4];
	for(int i=0; i<4; i++)
	{
		hChk[i] = (TH1D*)hTrk_mbL1[trigSlc[i]]->Clone("hChk");
		//hChk[i]->Rebin(2);
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
	TLegend *leg = new TLegend(0.375,0.25,0.725,0.45);
	leg->SetBorderSize(0);
	leg->SetFillColor(0);
	leg->AddEntry(gTrig[0],"L1_VTE50","lep");
	leg->AddEntry(gTrig[1],"L1_TE50","lep");
	//leg->AddEntry(gTrig[2],"L1_ZDC_A","lep");
	//leg->AddEntry(gTrig[3],"L1_ZDC_C","lep");
	
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
	tex->DrawLatex(0.375,0.60,"#font[72]{ATLAS}  #font[42]{Internal}");
	tex->SetTextFont(42);
	tex->DrawLatex(0.375,0.525,"#font[12]{Pb+Pb} #sqrt{s}=5TeV");

	cOut->Print("HMT_effL1_VTX_1trk.pdf");
}



//----------------------------------------------------
// Draw comparison
//----------------------------------------------------
void drawComp(int OPT)
{
	TFile *fIn = new TFile("trig_767.root");
	TH2D *hEt_trk[2];
	TH2D *hEtP_trk[2];
	TH2D *hTrk_trk[2];
	TH2D *hTrkP_trk[2];
	for(int i=0; i<2; i++)
	{
		sprintf(name,"hEt_trk_%d",i);
		hEt_trk[i] = (TH2D*)fIn->Get(name);
		styleHist2(hEt_trk[i]);
		
		sprintf(name,"hEtP_trk_%d",i);
		hEtP_trk[i] = (TH2D*)fIn->Get(name);
		styleHist2(hEtP_trk[i]);
		
		sprintf(name,"hTrk_trk_%d",i);
		hTrk_trk[i] = (TH2D*)fIn->Get(name);
		styleHist2(hTrk_trk[i]);
		
		sprintf(name,"hTrkP_trk_%d",i);
		hTrkP_trk[i] = (TH2D*)fIn->Get(name);
		styleHist2(hTrkP_trk[i]);
	}

	const int iRow = 1;
	TH1D *hEt_proj[2];
	for(int i=0; i<2; i++)
	{
		sprintf(name,"hEt_proj_%d",i);
		hEt_proj[i] = new TH1D(name,name,100,-5,5);
		for(int j=0; j<100; j++)
		{
			for(int k=0; k<10; k++) hEt_proj[i]->AddBinContent(j+1,hEt_trk[i]->GetBinContent(j+1,iRow+1+k));
			hEt_proj[i]->SetBinError(j+1,0);
		}
		styleHist1(hEt_proj[i]);
		hEt_proj[i]->SetMarkerStyle(mS[0]);
		hEt_proj[i]->SetMarkerColor(mC[0]);
		hEt_proj[i]->SetLineStyle(lS[0]);
		hEt_proj[i]->SetLineColor(lC[0]);
		hEt_proj[i]->Rebin(2);
	}
	TH1D *hEtP_proj[2];
	for(int i=0; i<2; i++)
	{
		sprintf(name,"hEtP_proj_%d",i);
		hEtP_proj[i] = new TH1D(name,name,100,-5,5);
		for(int j=0; j<100; j++)
		{
			for(int k=0; k<10; k++) hEtP_proj[i]->AddBinContent(j+1,hEtP_trk[i]->GetBinContent(j+1,iRow+1+k));
			hEtP_proj[i]->SetBinError(j+1,0);
		}
		styleHist1(hEtP_proj[i]);
		hEtP_proj[i]->SetMarkerStyle(mS[1]);
		hEtP_proj[i]->SetMarkerColor(mC[1]);
		hEtP_proj[i]->SetLineStyle(lS[1]);
		hEtP_proj[i]->SetLineColor(lC[1]);
		hEtP_proj[i]->Rebin(2);
	}
	TH1D *hTrk_proj[2];
	for(int i=0; i<2; i++)
	{
		sprintf(name,"hTrk_proj_%d",i);
		hTrk_proj[i] = new TH1D(name,name,100,-5,5);
		for(int j=0; j<100; j++)
		{
			for(int k=0; k<10; k++) hTrk_proj[i]->AddBinContent(j+1,hTrk_trk[i]->GetBinContent(j+1,iRow+1+k));
			hTrk_proj[i]->SetBinError(j+1,0);
		}
		styleHist1(hTrk_proj[i]);
		hTrk_proj[i]->SetMarkerStyle(mS[0]);
		hTrk_proj[i]->SetMarkerColor(mC[0]);
		hTrk_proj[i]->SetLineStyle(lS[0]);
		hTrk_proj[i]->SetLineColor(lC[0]);
	}
	TH1D *hTrkP_proj[2];
	for(int i=0; i<2; i++)
	{
		sprintf(name,"hTrkP_proj_%d",i);
		hTrkP_proj[i] = new TH1D(name,name,100,-5,5);
		for(int j=0; j<100; j++)
		{
			for(int k=0; k<10; k++) hTrkP_proj[i]->AddBinContent(j+1,hTrkP_trk[i]->GetBinContent(j+1,iRow+1+k));
			hTrkP_proj[i]->SetBinError(j+1,0);
		}
		styleHist1(hTrkP_proj[i]);
		hTrkP_proj[i]->SetMarkerStyle(mS[1]);
		hTrkP_proj[i]->SetMarkerColor(mC[1]);
		hTrkP_proj[i]->SetLineStyle(lS[1]);
		hTrkP_proj[i]->SetLineColor(lC[1]);
	}

	TLatex *tex = new TLatex();
	tex->SetTextSize(0.04);
	tex->SetTextAlign(12);
	tex->SetNDC(1);
	TLine *lin = new TLine();
	lin->SetLineStyle(lS[0]);
	lin->SetLineColor(lC[0]);
	TLegend *leg = new TLegend(0.15,0.7,0.55,0.85);
	leg->SetBorderSize(0);
	leg->SetFillColor(0);
	if(OPT==0) leg->AddEntry(hEt_proj[0],"ZDC_A_C not passed","lep");
	if(OPT==1) leg->AddEntry(hEt_proj[0],"MBTS_1_1 not passed","lep");
	if(OPT==0) leg->AddEntry(hEtP_proj[0],"ZDC_A_C passed","lep");
	if(OPT==1) leg->AddEntry(hEtP_proj[0],"MBTS_1_1 passed","lep");


	TCanvas *cOut1 = new TCanvas("cOut1","",800,800);
	cOut1->Divide(2,2,0.0001,0.0001);
	gStyle->SetOptStat(0);
	for(int iC=0; iC<4; iC++)
	{
		cOut1->cd(iC+1);
		gPad->SetLogz();
		gPad->SetTicks(1,1);
		gPad->SetTopMargin(0.1);
		gPad->SetBottomMargin(0.1);
		gPad->SetLeftMargin(0.1);
		gPad->SetRightMargin(0.05);
		if(iC==0)
		{
			if(OPT==0) hEt_trk[OPT]->SetTitle("E_{T} | ZDC_A_C not passed");
			if(OPT==1) hEt_trk[OPT]->SetTitle("E_{T} | MBTS_1_1 not passed");
			hEt_trk[OPT]->GetXaxis()->SetTitle("#eta");
			hEt_trk[OPT]->GetXaxis()->SetTitleOffset(2.5);
			hEt_trk[OPT]->GetXaxis()->SetRangeUser(-5,5);
			hEt_trk[OPT]->GetYaxis()->SetTitle("N_{ch}");
			hEt_trk[OPT]->GetYaxis()->SetTitleOffset(2.5);
			hEt_trk[OPT]->GetYaxis()->SetRangeUser(-0.5,49.5);
			hEt_trk[OPT]->Draw("col");
			tex->DrawLatex(0.6,0.80,"#font[72]{ATLAS}  #font[42]{Internal}");
			tex->SetTextFont(42);
			tex->DrawLatex(0.6,0.725,"#font[12]{PbPb} #sqrt{s}=5.02TeV");
		}
		if(iC==1)
		{
			if(OPT==0) hEtP_trk[OPT]->SetTitle("E_{T} | ZDC_A_C passed");
			if(OPT==1) hEtP_trk[OPT]->SetTitle("E_{T} | MBTS_1_1 passed");
			hEtP_trk[OPT]->GetXaxis()->SetTitle("#eta");
			hEtP_trk[OPT]->GetXaxis()->SetTitleOffset(2.5);
			hEtP_trk[OPT]->GetXaxis()->SetRangeUser(-5,5);
			hEtP_trk[OPT]->GetYaxis()->SetTitle("N_{ch}");
			hEtP_trk[OPT]->GetYaxis()->SetTitleOffset(2.5);
			hEtP_trk[OPT]->GetYaxis()->SetRangeUser(-0.5,49.5);
			hEtP_trk[OPT]->Draw("col");
		}
		if(iC==2)
		{
			if(OPT==0) hEt_proj[OPT]->SetTitle("N_{ch}<=10");
			if(OPT==1) hEt_proj[OPT]->SetTitle("N_{ch}<=10");
			hEt_proj[OPT]->GetXaxis()->SetTitle("#eta");
			hEt_proj[OPT]->GetXaxis()->SetTitleOffset(2.5);
			hEt_proj[OPT]->GetXaxis()->SetRangeUser(-5,5);
			hEt_proj[OPT]->GetYaxis()->SetTitle("E_{T}");
			hEt_proj[OPT]->GetYaxis()->SetTitleOffset(2.5);
			hEt_proj[OPT]->GetYaxis()->SetRangeUser(0,35);
			hEt_proj[OPT]->Draw("PL");
			hEtP_proj[OPT]->Draw("PL same");
			leg->Draw();
		}
	}
	TCanvas *cOut2 = new TCanvas("cOut2","",800,800);
	cOut2->Divide(2,2,0.0001,0.0001);
	gStyle->SetOptStat(0);
	for(int iC=0; iC<4; iC++)
	{
		cOut2->cd(iC+1);
		gPad->SetLogz();
		gPad->SetTicks(1,1);
		gPad->SetTopMargin(0.1);
		gPad->SetBottomMargin(0.1);
		gPad->SetLeftMargin(0.1);
		gPad->SetRightMargin(0.05);
		if(iC==0)
		{
			if(OPT==0) hTrk_trk[OPT]->SetTitle("N_{ch} | ZDC_A_C not passed");
			if(OPT==1) hTrk_trk[OPT]->SetTitle("N_{ch} | MBTS_1_1 not passed");
			hTrk_trk[OPT]->GetXaxis()->SetTitle("#eta");
			hTrk_trk[OPT]->GetXaxis()->SetTitleOffset(2.5);
			hTrk_trk[OPT]->GetXaxis()->SetRangeUser(-2.5,2.5);
			hTrk_trk[OPT]->GetYaxis()->SetTitle("N_{ch}");
			hTrk_trk[OPT]->GetYaxis()->SetTitleOffset(2.5);
			hTrk_trk[OPT]->GetYaxis()->SetRangeUser(-0.5,49.5);
			hTrk_trk[OPT]->Draw("col");
			tex->DrawLatex(0.6,0.80,"#font[72]{ATLAS}  #font[42]{Internal}");
			tex->SetTextFont(42);
			tex->DrawLatex(0.6,0.725,"#font[12]{PbPb} #sqrt{s}=5.02TeV");
		}
		if(iC==1)
		{
			if(OPT==0) hTrkP_trk[OPT]->SetTitle("N_{ch} | ZDC_A_C passed");
			if(OPT==1) hTrkP_trk[OPT]->SetTitle("N_{ch} | MBTS_1_1 passed");
			hTrkP_trk[OPT]->GetXaxis()->SetTitle("#eta");
			hTrkP_trk[OPT]->GetXaxis()->SetTitleOffset(2.5);
			hTrkP_trk[OPT]->GetXaxis()->SetRangeUser(-2.5,2.5);
			hTrkP_trk[OPT]->GetYaxis()->SetTitle("N_{ch}");
			hTrkP_trk[OPT]->GetYaxis()->SetTitleOffset(2.5);
			hTrkP_trk[OPT]->GetYaxis()->SetRangeUser(-0.5,49.5);
			hTrkP_trk[OPT]->Draw("col");
		}
		if(iC==2)
		{
			if(OPT==0) hTrk_proj[OPT]->SetTitle("N_{ch}<=10");
			if(OPT==1) hTrk_proj[OPT]->SetTitle("N_{ch}<=10");
			hTrk_proj[OPT]->GetXaxis()->SetTitle("#eta");
			hTrk_proj[OPT]->GetXaxis()->SetTitleOffset(2.5);
			hTrk_proj[OPT]->GetXaxis()->SetRangeUser(-2.5,2.5);
			hTrk_proj[OPT]->GetYaxis()->SetTitle("Counts");
			hTrk_proj[OPT]->GetYaxis()->SetTitleOffset(2.5);
			hTrk_proj[OPT]->GetYaxis()->SetRangeUser(0,2.7);
			hTrk_proj[OPT]->Draw("PL");
			hTrkP_proj[OPT]->Draw("PL same");
			leg->Draw();
		}
	}
	if(OPT==0) cOut1->Print("ZDC_et.pdf");
	if(OPT==0) cOut2->Print("ZDC_trk.pdf");
	if(OPT==1) cOut1->Print("MBTS_et.pdf");
	if(OPT==1) cOut2->Print("MBTS_trk.pdf");
}



//----------------------------------------------------
// Macro
//----------------------------------------------------
void draw1()
{
	gen();
	//test();
	
	//ntrk();
	//effL1();
	//effHLT();

	//for(int i=0; i<2; i++) drawComp(i);
}















