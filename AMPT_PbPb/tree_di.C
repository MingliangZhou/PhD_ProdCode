#include <Riostream.h>
#include <fstream>
#include "TTree.h"
#include "TMath.h"
#include "TFile.h"

const int nTrkMax = 10000;
const double etaAcc = 2.5;
const double ptAcc = 0.3;

int cvtPt(double pT)
{
	int flagPt = int(pT*10.);
	if(flagPt<0) flagPt = 0;
	if(flagPt>=250) flagPt = 250;
	return flagPt;
}
int cvtEta(double eta)
{
	int flagEta = int((eta+etaAcc)/2/etaAcc*250);
	if(flagEta<0) flagEta = 0;
	if(flagEta>=250) flagEta = 250;
	return flagEta;
}
int cvtPhi(double phi)
{
	int flagPhi = int((phi+TMath::Pi())/2/TMath::Pi()*pow(2,14));
	if(flagPhi<0) flagPhi = 0;
	if(flagPhi>=pow(2,14)) flagPhi = int(pow(2,14));
	return flagPhi;
}
double detPt(UInt_t pt)
{
	return (pt+0.5)/10.;
}
double detEta(UInt_t eta)
{
	return (eta+0.5)/250.*2*etaAcc-etaAcc;
}
double detPhi(UInt_t phi)
{
	return (phi+0.5)/pow(2,14)*2*TMath::Pi()-TMath::Pi();
}

void tree_di(Int_t nEvts = 1, Int_t seed=0)
{

	unsigned int nTrk;
	unsigned int trkInfo[nTrkMax];
	int 	trkID[nTrkMax];
	float trkPt[nTrkMax];
	float trkEta[nTrkMax];
	float trkPhi[nTrkMax];

	TFile fOut("ampt.root","recreate");

	TTree *tree = new TTree("tree","AMPT");
	tree->Branch("nTrk",		&nTrk,		"nTrk/i");
	tree->Branch("trkInfo", trkInfo,	"trkInfo[nTrk]/i");
	/*
	tree->Branch("trkID",   trkID,	  "trkID[nTrk]/I");
	tree->Branch("trkPt",   trkPt,	  "trkPt[nTrk]/F");
	tree->Branch("trkEta",  trkEta,	  "trkEta[nTrk]/F");
	tree->Branch("trkPhi",  trkPhi,	  "trkPhi[nTrk]/F");
	*/

	ifstream ifs;   ifs.open("ampt.dat");
	ifstream jfs;   jfs.open("zpc.dat");
	ifstream nfs;   nfs.open("npart-xy.dat");
	ifstream pfs;   pfs.open("parton-initial-afterPropagation.dat");

	Int_t   i0,i1,i2,i3,i4,i5;
	Float_t f0,f1,f2,f3,f4,f5,f6,f7;

	int ieve;
	int jeve;
	int m_nTrk;
	float bimp;
	for (int iEvt=0; iEvt<nEvts; iEvt++)
	{
		ifs >> ieve >> jeve >> m_nTrk >> bimp >> i0 >> i1 >> i2 >> i3 >> i4 >> i5;

		nTrk = 0;
		for(int i=0; i<nTrkMax; i++) trkInfo[i] = 0;
		unsigned int m_trkChg = 0;
		unsigned int m_trkQual = 0;
		unsigned int m_trkPt = 0;
		unsigned int m_trkEta = 0;
		unsigned int m_trkPhi = 0;
		unsigned int m_tmpInfo = 0;
		double m_tmpChg = 0;
		double m_tmpQual = 0;
		double m_tmpPt = 0;
		double m_tmpEta = 0;
		double m_tmpPhi = 0;
		for (int iT=0; iT<m_nTrk; iT++)
		{
			ifs >> i0 >> f0 >> f1 >> f2 >> f3 >> f4 >> f5 >> f6 >> f7;
			// i0: PID;
			// f0: px;
			// f1: py;
			// f2: pz;
			double p = sqrt(pow(f0,2)+pow(f1,2)+pow(f2,2));
			if(p==fabs(f2)) trkEta[nTrk]=1e9;
			else trkEta[nTrk] = 0.5*log((p+f2)/(p-f2));
			if(fabs(trkEta[nTrk])>=etaAcc) continue;

			trkPt[nTrk] = sqrt(f0*f0+f1*f1);
			if(trkPt[nTrk]<ptAcc) continue;

			trkID[nTrk] = i0;
			if(fabs(trkID[nTrk])!=211 && fabs(trkID[nTrk])!=321 && fabs(trkID[nTrk])!=2212) continue;

			trkPhi[nTrk] = atan2(f1,f0);

			m_trkPt = cvtPt(trkPt[nTrk]);
			m_trkEta = cvtEta(trkEta[nTrk]);
			m_trkPhi = cvtPhi(trkPhi[nTrk]);
			m_trkQual = 1;
			if(trkID[nTrk]>0) m_trkChg = 1;
			else m_trkChg = 0;

			trkInfo[nTrk] = m_trkChg;
			trkInfo[nTrk] <<=  1; trkInfo[nTrk] |= m_trkQual;
			trkInfo[nTrk] <<=  8; trkInfo[nTrk] |= m_trkPt;
			trkInfo[nTrk] <<=  8; trkInfo[nTrk] |= m_trkEta;
			trkInfo[nTrk] <<= 14; trkInfo[nTrk] |= m_trkPhi;

			m_tmpInfo= trkInfo[nTrk];
			m_tmpPhi = detPhi(m_tmpInfo & 0x3fff); m_tmpInfo >>= 14;
			m_tmpEta = detEta(m_tmpInfo & 0xff);   m_tmpInfo >>= 8;
			m_tmpPt  = detPt(m_tmpInfo & 0xff);    m_tmpInfo >>= 8;
			m_tmpQual= m_tmpInfo & 0x1;            m_tmpInfo >>= 1;
			m_tmpChg = m_tmpInfo & 0x1;

			if(fabs(m_trkChg-m_tmpChg)>0 || fabs(m_trkQual-m_tmpQual)>0 || fabs(trkPt[nTrk]-m_tmpPt)>0.1 || fabs(trkEta[nTrk]-m_tmpEta)>0.01 || fabs(trkPhi[nTrk]-m_tmpPhi)>0.001)
			{
				std::cout<<m_trkChg<<"  |  "<<m_trkQual<<"  |  "<<trkPt[nTrk]<<"  |  "<<trkEta[nTrk]<<"  |  "<<trkPhi[nTrk]<<std::endl;
				std::cout<<m_tmpChg<<"  |  "<<m_tmpQual<<"  |  "<<m_tmpPt<<"  |  "<<m_tmpEta<<"  |  "<<m_tmpPhi<<std::endl;
			}

			nTrk++;
		}
		tree->Fill();
	}
	ifs.close();
	jfs.close();
	nfs.close();
	tree->Print();
	tree->Write();

	fOut.Close();
} 
