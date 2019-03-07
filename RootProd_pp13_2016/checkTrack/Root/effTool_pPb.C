#include<iostream>
#include<string>
#include<math.h>
#include "TFile.h"
#include "TF1.h"
#include "TH2D.h"
#include "TGraphErrors.h"
#include "TSystem.h"

#include "effTool_pPb.h"
static void setoverflow(TH2*h){
   int NY = h->GetNbinsY();
   int NX = h->GetNbinsX();
   for(int ix=0;ix<NX;ix++){
      h->SetBinContent(ix+1,0,h->GetBinContent(ix+1,1));
      h->SetBinContent(ix+1,NY+1,h->GetBinContent(ix+1,NY));
   }
   for(int iy=0;iy<=NY+1;iy++){
      h->SetBinContent(0,   iy,h->GetBinContent(1,iy));
      h->SetBinContent(NX+1,iy,h->GetBinContent(NX,iy));
   }
}
effTool_pPb::effTool_pPb(std::string fName) {
   Qual=2;//default

   is_bad = 0;
   if (gSystem->AccessPathName(fName.c_str())) {std::cout << "Input file cannot be found" << std::endl; is_bad=1;}
   fIn = new TFile(fName.c_str());

   char name[500];
   for (int iq=0;iq<NQUAL;iq++) {
      for (int ic=0;ic<NCENT;ic++) {
         for (int ip=0;ip<NPT;ip++) {
            sprintf(name , "hEff_q%d_p%d_c%d", iq,ip,ic);
            if (!(fIn->GetListOfKeys()->Contains(name))) {std::cout << name << " not found in " << fIn->GetName() << std::endl; is_bad = 1;}
            hEff[ic][ip][iq] = (TH2D*)fIn->Get(name); setoverflow(hEff[ic][ip][iq]);
         }
      }
   }
}

double effTool_pPb::get_eff(double eta, double vxz, double pt) {
   if (fabs(eta)>2.6 || pt<0.08) {std::cout << "Cannot evaluate efficiency, out of range: eta = " << eta << ", pt = " << pt << std::endl; return 1;} 

   if (eta>=2.49)  eta =  2.49;
   if (eta<=-2.49) eta = -2.49;
   if(vxz>=99.99)  vxz =  99.99;
   if(vxz<=-99.99) vxz = -99.99;
   if (pt<=0.1)    pt  =  0.1;

   int zb   = get_zbin(vxz);
   set_etab(eta);
   int ptb  = get_ptbin(pt);

   double wt=1;

   return hEff[centb][ptb][Qual]->Interpolate(eta,vxz)/wt;
   //return hEff[centb][ptb]->GetBinContent(eta_eff+1,zb+1)/wt;
}

void effTool_pPb::set_centb(double ntrk) {//set internal centrality bin

   centb = -1;

   if (ntrk > 180)      centb = 0;
   else if (ntrk > 120) centb = 1;
   else if (ntrk > 60)  centb = 2;
   else                 centb = 3;
}

void effTool_pPb::set_etab(double eta) {

   eta_eff = (eta+2.5)/(5.0/24.0); if (eta_eff<0) eta_eff=0; if(eta_eff>=24 ) eta_eff=23 ;
}

int effTool_pPb::get_zbin(double vxz) {

   int zbin;
   zbin = (vxz+100)/(200.0/20.0); if (zbin<0) zbin=0; if(zbin>=20 ) zbin=19 ;
   return zbin;
}

int effTool_pPb::get_ptbin(double pt) {

   int ptbin = -1;
   if (pt>=0.1 && pt<0.2) ptbin=0;
   if (pt>=0.2 && pt<0.3) ptbin=1;
   if (pt>=0.3 && pt<0.4) ptbin=2;
   if (pt>=0.4 && pt<0.5) ptbin=3;
   if (pt>=0.5 && pt<0.6) ptbin=4;
   if (pt>=0.6 && pt<0.7) ptbin=5;
   if (pt>=0.7 && pt<0.8) ptbin=6;
   if (pt>=0.8 && pt<0.9) ptbin=7;
   if (pt>=0.9 && pt<1.0) ptbin=8;
   if (pt>=1.0 && pt<1.5) ptbin=9;
   if (pt>=1.5 && pt<2.0) ptbin=10;
   if (pt>=2.0)           ptbin=11;

   return ptbin;
}

effTool_pPb::~effTool_pPb () {
}
