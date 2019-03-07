#include "CombineTriggers.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "TFile.h"
#include "TGraphAsymmErrors.h"

CombineTriggers::CombineTriggers() {

   NTRIG_0 = 12;

   fEff = 0;
   fEff = new TFile("trigEff.root");

   gEff[0]  = 0;
   gEff[1]  = (TGraphAsymmErrors*)fEff->Get("g_mbEff_mbMbts_1_1");
   gEff[2]  = (TGraphAsymmErrors*)fEff->Get("g_mbEff_Mbts_2");
   gEff[3]  = (TGraphAsymmErrors*)fEff->Get("g_mbEff_L1Mbts_1_1");
   gEff[4]  = (TGraphAsymmErrors*)fEff->Get("g_mbEff_ZDCPb");
   gEff[5]  = 0;
   gEff[6]  = (TGraphAsymmErrors*)fEff->Get("g_hmtEff_trk100_te10");
   gEff[7]  = (TGraphAsymmErrors*)fEff->Get("g_hmtEff_trk130_te10");
   gEff[8]  = (TGraphAsymmErrors*)fEff->Get("g_hmtEff_trk150_te50");
   gEff[9]  = (TGraphAsymmErrors*)fEff->Get("g_hmtEff_trk180_te50");
   gEff[10] = (TGraphAsymmErrors*)fEff->Get("g_hmtEff_trk200_te65");
   gEff[11] = (TGraphAsymmErrors*)fEff->Get("g_hmtEff_trk225_te65");

   gCrc[0] = (TGraphAsymmErrors*)fEff->Get("g_crc_hmt_MbP");

   if (fEff) std::cout << "Set Efficiency Histograms" << std::endl;
}


CombineTriggers::~CombineTriggers() {

   if (fEff) fEff->Close();
}

double CombineTriggers::calc_weight_mbPrimHmt(const std::vector<float>* Prescales, int ntrk, double EtL1) {

   double wt = -1;
   if (ntrk>220 && Prescales->at(11)<0) return wt;

   std::vector<double> trigEff  (NTRIG_0, 0);
   std::vector<double> trigPresc(NTRIG_0, 1);
   std::vector<double> Pacc     (NTRIG_0, 0);

   for (int itrig=0; itrig<NTRIG_0; itrig++) {
      if (Prescales->at(itrig) <= 0) continue;
      if (!(itrig==1 || itrig>5))    continue;

      trigPresc[itrig] = Prescales->at(itrig);
      trigEff [itrig] = gEff[itrig]->Eval(ntrk);

      Pacc[itrig] = trigEff [itrig]/double(trigPresc[itrig]);
   }

   if (EtL1/1000.0 < 10) {Pacc[6]  = 0; Pacc[7]  = 0;}
   if (EtL1/1000.0 < 50) {Pacc[8]  = 0; Pacc[9]  = 0;}
   if (EtL1/1000.0 < 65) {Pacc[10] = 0; Pacc[11] = 0;}

   double Xall     = 1;
   for (int itrig=0; itrig<NTRIG_0; itrig++) {
      Xall *= (1 - Pacc[itrig]);
   }

   if ((1-Xall) < 1e-10) return wt;
   wt = 1/(1-Xall);
   wt/=gCrc[0]->Eval(ntrk);

   return wt;
}

double CombineTriggers::calc_weight_mbHmt(const std::vector<float>* Prescales, int ntrk, double EtL1) {

   double wt = -1;
   if (ntrk>220 && Prescales->at(11)<0) return wt;

   std::vector<double> trigEff  (NTRIG_0, 0);
   std::vector<double> trigPresc(NTRIG_0, 1);
   std::vector<double> Pacc     (NTRIG_0, 0);

   for (int itrig=0; itrig<NTRIG_0; itrig++) {
      if (Prescales->at(itrig) <= 0) continue;
      if ((itrig==0 || itrig==5))    continue;

      trigPresc[itrig] = Prescales->at(itrig);
      trigEff [itrig] = gEff[itrig]->Eval(ntrk);

      Pacc[itrig] = trigEff [itrig]/double(trigPresc[itrig]);
   }

   if (EtL1/1000.0 < 10) {Pacc[6]  = 0; Pacc[7]  = 0;}
   if (EtL1/1000.0 < 50) {Pacc[8]  = 0; Pacc[9]  = 0;}
   if (EtL1/1000.0 < 65) {Pacc[10] = 0; Pacc[11] = 0;}

   double Xall     = 1;
   for (int itrig=0; itrig<NTRIG_0; itrig++) {
      Xall *= (1 - Pacc[itrig]);
   }

   if ((1-Xall) < 1e-10) return wt;
   wt = 1/(1-Xall);
   wt/=gCrc[0]->Eval(ntrk);

   return wt;
}

double CombineTriggers::calc_weight_trig(const std::vector<float>* Prescales, int ntrk, double EtL1, int itrig) {

   double wt = -1;

   if (itrig==0 || itrig==5 || itrig>11) {
      std::cout << "Trigger not in list " << std::endl;
      return wt;
   }

   double trigEff   = 0;
   double trigPresc = 1;
   double Pacc      = 0;

   if (Prescales->at(itrig) > 0) {
      trigEff   = gEff[itrig]->Eval(ntrk);
      trigPresc = Prescales->at(itrig);
      Pacc      = trigEff/double(trigPresc);
   }

   if ((itrig == 6  || itrig == 7 ) && (EtL1/1000.0 < 10)) Pacc = 0;
   if ((itrig == 8  || itrig == 9 ) && (EtL1/1000.0 < 50)) Pacc = 0;
   if ((itrig == 10 || itrig == 11) && (EtL1/1000.0 < 65)) Pacc = 0;

   if (Pacc<1e-10) return wt;
   wt = 1/Pacc;

   return wt;
}
