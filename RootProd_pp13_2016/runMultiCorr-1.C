#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<complex>
#include<TFile.h>
#include<TTree.h>
#include<TChain.h>
#include<TF1.h>
#include<TH1.h>
#include<TH2.h>
#include<TRandom3.h>
#include<TMath.h>

#include "runMultiCorr_adam_eff.h"

runMultiCorr_adam_eff::runMultiCorr_adam_eff(std::string fN_in) {

   fChain     = new TChain("tree","");

   char fname[400];
   ifstream lis(fN_in.c_str());
   int cnt=0;
   while(!lis.eof()){
      string filename;
      lis >> filename;
      sprintf(fname,"%s",filename.c_str());
      cout << fname << endl;
      if(!filename.empty()) {
         fChain->Add(fname);
      }
      cnt++;
      if(cnt>1000000) {cout<<"Too Many Files"<<endl;break;}
   }
   std::cout << fChain->GetEntries() << std::endl;

   std::string fN_out = "Out_multcorr_pp_nocentering.root";
   std::cout << "Output file name " << fN_out << std::endl;
   fOut = new TFile(fN_out.c_str(), "recreate");
}

runMultiCorr_adam_eff::~runMultiCorr_adam_eff() {

   fOut->Close();
   fIn->Close();
}

void runMultiCorr_adam_eff::exec() {

   SetupAll();
   //getCalib("Out_multcorr_pp_nocentering_pt0p3t3_noeff_ntrk1.root");
   run();
   Save();
}

void runMultiCorr_adam_eff::SetupAll(){

   InitTrees();

   randGen = new TRandom3();
   nevents = 0;

   char name[500], name1[500];
   sprintf(name,"hcent");    hcent    = new TH1D(name,"",NCENTH,-0.5,NCENTH-0.5); hcent->Sumw2();
   sprintf(name,"hntrk");    hntrk    = new TH1D(name,"",1000,0,1000); hntrk->Sumw2();
   sprintf(name,"hntrkAll"); hntrkAll = new TH1D(name,"",10000,0,10000); hntrkAll->Sumw2();
   
   sprintf(name,"hpt");  hpt  = new TH1D(name,"",10000,0,100); hpt->Sumw2();
   sprintf(name,"heta"); heta = new TH1D(name,"",1000,-3,3); heta->Sumw2();
   sprintf(name,"hphi"); hphi = new TH1D(name,"",1000,-4,4); hphi->Sumw2();

   for (int ihar=0;ihar<NHAR;ihar++) {
      for (int icut=0;icut<NCUT+2;icut++) {
         for (int is=0;is<2;is++) {
            for (int ix=0;ix<2;ix++) {
               for (int io=0;io<4;io++) {
                  if (icut==0 && is>0) continue;
                  int idet = 1 + 2*(icut-1) + is; if (icut==0) idet=0;
                  int iox  = 4*ix + io;
                  sprintf(name,"h_Qn_xy_mean_har%d_cut%d_side%d_x%d_ord%d",ihar+2,icut,is,ix,io);
                  hQn_xy_mean[ihar][idet][iox] = new TH1D(name,"",NCENTH,-0.5,NCENTH-0.5);
               }
            }
         }
      }
   }

   for (int ic=0;ic<NCENTH;ic++) {
      for (int icut=0;icut<NCUT+2;icut++) {
         sprintf(name, "hntrk_c%d_cut%d",ic,icut); hntrkC[ic][icut] = new TH1D(name,"",1000,0,1000); hntrkC[ic][icut]->Sumw2();
      }

      for (int ihar=0;ihar<NHAR;ihar++) {
         for (int icut=0;icut<NCUT+2;icut++) {
            sprintf(name,"h_Qn_c%d_har%d_cut%d",ic,ihar+2,icut); hQn[ic][ihar][icut] = new TH1D(name,"",5050,-1.01,1.01); hQn[ic][ihar][icut]->Sumw2();
            sprintf(name,"h_RF_sub_c%d_har%d_cut%d",ic,ihar+2,icut); hRF_sub[ic][ihar][icut] = new TH1D(name,"",5050,-1.01,1.01); hRF_sub[ic][ihar][icut]->Sumw2();

            for (int is=0;is<2;is++) {
               for (int ix=0;ix<2;ix++) {
                  for (int io=0;io<4;io++) {
                     if (icut==0 && is>0) continue;
                     int idet = 1 + 2*(icut-1) + is; if (icut==0) idet=0;
                     int iox  = 4*ix + io;
                     sprintf(name,"h_Qn_xy_c%d_har%d_cut%d_side%d_x%d_ord%d",ic,ihar+2,icut,is,ix,io); 
                     hQn_xy[ic][ihar][idet][iox] = new TH1D(name,"",505,-1.01,1.01); hQn_xy[ic][ihar][idet][iox]->Sumw2();
                  }
               }
            }
         }
      }
   }

   for (int ihar=0;ihar<NHAR;ihar++) {
      sprintf(name, "h_QC2_har%d",ihar+2); h_QC2[ihar] = new TH1D(name, "", NCENTH,-0.5,NCENTH-0.5); h_QC2[ihar]->Sumw2();
      sprintf(name, "h_QC4_har%d",ihar+2); h_QC4[ihar] = new TH1D(name, "", NCENTH,-0.5,NCENTH-0.5); h_QC4[ihar]->Sumw2();
      sprintf(name, "h_QC6_har%d",ihar+2); h_QC6[ihar] = new TH1D(name, "", NCENTH,-0.5,NCENTH-0.5); h_QC6[ihar]->Sumw2();
      sprintf(name, "h_QC8_har%d",ihar+2); h_QC8[ihar] = new TH1D(name, "", NCENTH,-0.5,NCENTH-0.5); h_QC8[ihar]->Sumw2();

      sprintf(name, "h_QC24_har%d",ihar+2); h_QC24[ihar] = new TH1D(name, "", NCENTH,-0.5,NCENTH-0.5); h_QC24[ihar]->Sumw2();
      sprintf(name, "h_QC26_har%d",ihar+2); h_QC26[ihar] = new TH1D(name, "", NCENTH,-0.5,NCENTH-0.5); h_QC26[ihar]->Sumw2();
      sprintf(name, "h_QC28_har%d",ihar+2); h_QC28[ihar] = new TH1D(name, "", NCENTH,-0.5,NCENTH-0.5); h_QC28[ihar]->Sumw2();
      sprintf(name, "h_QC46_har%d",ihar+2); h_QC46[ihar] = new TH1D(name, "", NCENTH,-0.5,NCENTH-0.5); h_QC46[ihar]->Sumw2();
      sprintf(name, "h_QC48_har%d",ihar+2); h_QC48[ihar] = new TH1D(name, "", NCENTH,-0.5,NCENTH-0.5); h_QC48[ihar]->Sumw2();
      sprintf(name, "h_QC68_har%d",ihar+2); h_QC68[ihar] = new TH1D(name, "", NCENTH,-0.5,NCENTH-0.5); h_QC68[ihar]->Sumw2();
   }

   sprintf(name, "h_W2"); h_W2 = new TH1D(name,"",NCENTH,-0.5,NCENTH-0.5); h_W2->Sumw2();
   sprintf(name, "h_W4"); h_W4 = new TH1D(name,"",NCENTH,-0.5,NCENTH-0.5); h_W4->Sumw2();
   sprintf(name, "h_W6"); h_W6 = new TH1D(name,"",NCENTH,-0.5,NCENTH-0.5); h_W6->Sumw2();
   sprintf(name, "h_W8"); h_W8 = new TH1D(name,"",NCENTH,-0.5,NCENTH-0.5); h_W8->Sumw2();

   TFile* fEff = new TFile("tracking_efficients.root");
   hEff = (TH2F*)fEff->Get("Primary_efficiency_PtEta_rebin_NDA2");
}

void runMultiCorr_adam_eff::InitTrees() {

   fChain->SetBranchAddress("Trigger", &Trigger, &b_Trigger);
   fChain->SetBranchAddress("zPriVtx", &zPriVtx, &b_zPriVtx);
   fChain->SetBranchAddress("nTrk", &nTrk, &b_nTrk);
   fChain->SetBranchAddress("trkPt", trkPt, &b_trkPt);
   fChain->SetBranchAddress("trkEta", trkEta, &b_trkEta);
   fChain->SetBranchAddress("trkPhi", trkPhi, &b_trkPhi);
}

void runMultiCorr_adam_eff::getCalib(std::string fName) {
   
   TFile* fCalib = new TFile(fName.c_str());

   char name[500], name1[500];
   for (int ic=0;ic<NCENTH;ic++) {
      std::cout << "cent = " << ic << std::endl;
      for (int ihar=0;ihar<NHAR;ihar++) {
         for (int icut=0;icut<NCUT+2;icut++) {
            for (int is=0;is<2;is++) {
               for (int ix=0;ix<2;ix++) {
                  for (int io=0;io<4;io++) {
                     if (icut==0 && is>0) continue;
                     int idet = 1 + 2*(icut-1) + is; if (icut==0) idet=0;
                     int iox  = 4*ix + io;
                  
                     sprintf(name,"h_Qn_xy_c%d_har%d_cut%d_side%d_x%d_ord%d",ic,ihar+2,icut,is,ix,io); 
                     sprintf(name1,"h_Qn_xy_c%d_har%d_cut%d_side%d_x%d_ord%d_Clone",ic,ihar+2,icut,is,ix,io); 
                      :Qn TH1D* hQn_xy_iter0 = (TH1D*)((TH1D*)fCalib->Get(name))->Clone(name1);
                     hQn_xy_mean[ihar][idet][iox]->SetBinContent(ic+1,hQn_xy_iter0->GetMean());
                     hQn_xy_mean[ihar][idet][iox]->SetBinError  (ic+1,hQn_xy_iter0->GetMeanError());
                     delete hQn_xy_iter0;
                  }
               }
            }
         }
      }
   }
   fCalib->Close();
}

void runMultiCorr_adam_eff::run() {

   Long64_t nentries = fChain->GetEntries();
   //nentries = 100000;

   std::cout << "Starting run, Entries = " << nentries << std::endl;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      if (jentry%10000==0) std::cout << "running event " << jentry << std::endl;
      fChain->GetEntry(jentry);

      if (Trigger == 0) continue;

      //--- Event Cuts -----------------------------------------------------------------------------------------------//
      int centb=-1;
      int ntrkCent=0; int ntrkH = 0; int ntrkTrig=0;
      for (int itrk=0; itrk<nTrk; itrk++) {
         double eta = trkEta[itrk]*0.02 + 0.01 - 2.5; 
         double ptgev = (trkPt[itrk]*50 + 25)/1000.0;
         //std::cout << "ev = " << jentry << ": ntrk = " << nTrk << ": j = " << itrk << ": pt = " << ptgev << ": eta = " << eta << std::endl;
         if (fabs(eta)>2.5) continue;
         ntrkH++;
         if (ptgev<0.4) continue;
         ntrkCent++;
         ntrkTrig++;
      }
      //centb=get_centb(ntrkCent); if (centb<0) continue;
      centb=ntrkCent; if (centb<5 || centb>=200) continue;
      if (!(Trigger&1) && ( (Trigger&2) && ntrkTrig<70)) continue;
      if (!(Trigger&1) && ( (Trigger&4) && ntrkTrig<110)) continue;

      nevents++;
      hcent->Fill(centb);
      hntrk->Fill(ntrkCent);
      hntrkAll->Fill(nTrk);
      //--- Event Cuts -----------------------------------------------------------------------------------------------//

      //--- Setup ----------------------------------------------------------------------------------------------------//
      for (int ix=0; ix<2; ix++) {
         for (int idet=0; idet<NDET; idet++){
            for (int ihar=0; ihar<NHAR; ihar++) {
               Qn [ix][idet][ihar] = 0;
               Q2n[ix][idet][ihar] = 0;
               Q3n[ix][idet][ihar] = 0;
               Q4n[ix][idet][ihar] = 0;
               
               Qn_1  [ix][idet][ihar] = 0;
               Qn_2  [ix][idet][ihar] = 0;
               Qn_3  [ix][idet][ihar] = 0;
               Q2n_1 [ix][idet][ihar] = 0;
               Q2n_2 [ix][idet][ihar] = 0;
            }
         }
      }
      for (int idet=0; idet<NDET; idet++) {
         ntrkQ[idet] = 0;
      }
      //--- Setup ----------------------------------------------------------------------------------------------------//

      //--- Track Loop for multi particle correlations ---------------------------------------------------------------//
      double wi=1.0;
      double S1_1 = 0. ;
      double S1_2 = 0. ;
      double S1_3 = 0. ;
      double S1_4 = 0. ;
      double S2_1 = 0. ;
      double S3_1 = 0. ;
      double S4_1 = 0. ;
      double S2_2 = 0. ;
      
      for (int itrk=0; itrk<nTrk; itrk++) {
         double eta = trkEta[itrk]*0.02 + 0.01 - 2.5; 
         double ptgev = (trkPt[itrk]*50 + 25)/1000.0;
         hpt->Fill(ptgev); heta->Fill(eta); hphi->Fill(trkPhi[itrk]);
         if (fabs(eta)>2.5) continue;
         if (ptgev<0.3 || ptgev>3.0) continue;

         double eff = hEff->GetBinContent(hEff->FindFixBin(ptgev,eta));
         wi = 1/eff;

         bool etaBin[NDET] = {0};
         etaBin[0] = 1;  ntrkQ[0]++;
         if   (randGen->Rndm() < 0.5) {etaBin[1] = 1; ntrkQ[1]++;}
         else                         {etaBin[2] = 1; ntrkQ[2]++;}
         for (int icut=0;icut<NCUT;icut++) {
            if (eta<(-detCuts[icut])) {etaBin[3+2*icut] = 1; ntrkQ[3+2*icut]++;}
            else if (eta>(detCuts[icut])) {etaBin[3+2*icut+1] = 1; ntrkQ[3+2*icut+1]++;}
         }

         for (int ihar=0; ihar<NHAR; ihar++) {
            for (int idet=0;idet<NDET;idet++) {
               if (!etaBin[idet]) continue;
               Qn  [0][idet][ihar]        += cos((ihar+2)*trkPhi[itrk]);
               Qn  [1][idet][ihar]        += sin((ihar+2)*trkPhi[itrk]);
               Q2n [0][idet][ihar]        += cos(2*(ihar+2)*trkPhi[itrk]);
               Q2n [1][idet][ihar]        += sin(2*(ihar+2)*trkPhi[itrk]);
               Q3n [0][idet][ihar]        += cos(3*(ihar+2)*trkPhi[itrk]);
               Q3n [1][idet][ihar]        += sin(3*(ihar+2)*trkPhi[itrk]);
               Q4n [0][idet][ihar]        += cos(4*(ihar+2)*trkPhi[itrk]);
               Q4n [1][idet][ihar]        += sin(4*(ihar+2)*trkPhi[itrk]);
               
               Qn_1  [0][idet][ihar]      += wi * cos((ihar+2)*trkPhi[itrk]);
               Qn_1  [1][idet][ihar]      += wi * sin((ihar+2)*trkPhi[itrk]);
               Qn_2  [0][idet][ihar]      += wi*wi * cos((ihar+2)*trkPhi[itrk]);
               Qn_2  [1][idet][ihar]      += wi*wi * sin((ihar+2)*trkPhi[itrk]);
               Qn_3  [0][idet][ihar]      += wi*wi*wi * cos((ihar+2)*trkPhi[itrk]);
               Qn_3  [1][idet][ihar]      += wi*wi*wi * sin((ihar+2)*trkPhi[itrk]);
               Q2n_1 [0][idet][ihar]      += wi * cos(2*(ihar+2)*trkPhi[itrk]);
               Q2n_1 [1][idet][ihar]      += wi * sin(2*(ihar+2)*trkPhi[itrk]);
               Q2n_2 [0][idet][ihar]      += wi*wi * cos(2*(ihar+2)*trkPhi[itrk]);
               Q2n_2 [1][idet][ihar]      += wi*wi * sin(2*(ihar+2)*trkPhi[itrk]);
            }
         }

         S1_1 += wi;
         S1_2 += wi*wi;
         S1_3 += pow(wi,3.);
         S1_4 += pow(wi,4.);
      }

      for (int icut=0;icut<NCUT+2;icut++) {
         if (icut==0) hntrkC[centb][icut]->Fill(ntrkQ[0]);
         else if (icut==1) hntrkC[centb][icut]->Fill(ntrkQ[1]+ntrkQ[2]);
         else hntrkC[centb][icut]->Fill(ntrkQ[3+2*(icut-2)]+ntrkQ[3+2*(icut-2)+1]);
      }

      /*for (int ihar=0; ihar<NHAR; ihar++) {
         for (int icut=0;icut<NCUT+2;icut++) {
            for (int is=0;is<2;is++) {
               for (int ix=0;ix<2;ix++) {
                  if (icut==0 && is>0) continue;
                  int idet = 1 + 2*(icut-1) + is; if (icut==0) idet=0;
                  
                  Qn [ix][idet][ihar] -= hQn_xy_mean[ihar][idet][4*ix+0]->GetBinContent(centb+1);
                  Q2n[ix][idet][ihar] -= hQn_xy_mean[ihar][idet][4*ix+1]->GetBinContent(centb+1);
                  Q3n[ix][idet][ihar] -= hQn_xy_mean[ihar][idet][4*ix+2]->GetBinContent(centb+1);
                  Q4n[ix][idet][ihar] -= hQn_xy_mean[ihar][idet][4*ix+3]->GetBinContent(centb+1);
               }
            }
         }
      }*/
      //--- Track Loop for multi particle correlations ---------------------------------------------------------------//

      //--- Fill vnTrue, vnEP, Qn, RFs -------------------------------------------------------------------------------//
      for (int ihar=0; ihar<NHAR; ihar++) {
         {
            double Q = sqrt( Qn[0][0][ihar]*Qn[0][0][ihar] + Qn[1][0][ihar]*Qn[1][0][ihar] )/double(ntrkQ[0]);
            hQn   [centb][ihar][0]->Fill(Q);
            for (int ix=0;ix<2;ix++) {
               hQn_xy[centb][ihar][0][4*ix+0]->Fill(Qn [ix][0][ihar]/double(ntrkQ[0]));
               hQn_xy[centb][ihar][0][4*ix+1]->Fill(Q2n[ix][0][ihar]/double(ntrkQ[0]));
               hQn_xy[centb][ihar][0][4*ix+2]->Fill(Q3n[ix][0][ihar]/double(ntrkQ[0]));
               hQn_xy[centb][ihar][0][4*ix+3]->Fill(Q4n[ix][0][ihar]/double(ntrkQ[0]));
            }
         }

         if (ntrkQ[1]>0 && ntrkQ[2]>0) {
            double Qx_ran1 = Qn  [0][1][ihar]/double(ntrkQ[1]);
            double Qy_ran1 = Qn  [1][1][ihar]/double(ntrkQ[1]);
            double Qx_ran2 = Qn  [0][2][ihar]/double(ntrkQ[2]);
            double Qy_ran2 = Qn  [1][2][ihar]/double(ntrkQ[2]);
            hQn    [centb][ihar][1]->Fill( sqrt( pow( 0.5*(Qx_ran1 + Qx_ran2), 2) + pow( 0.5*(Qy_ran1 + Qy_ran2), 2) ) );
            hRF_sub[centb][ihar][1]->Fill( sqrt( pow( 0.5*(Qx_ran1 - Qx_ran2), 2) + pow( 0.5*(Qy_ran1 - Qy_ran2), 2) ) );
            for (int is=0;is<2;is++) {
               for (int ix=0;ix<2;ix++) {
                  int idet = 1 + 2*(1-1) + is; 
                  hQn_xy[centb][ihar][idet][4*ix+0]->Fill(Qn [ix][idet][ihar]/double(ntrkQ[idet]));
                  hQn_xy[centb][ihar][idet][4*ix+1]->Fill(Q2n[ix][idet][ihar]/double(ntrkQ[idet]));
                  hQn_xy[centb][ihar][idet][4*ix+2]->Fill(Q3n[ix][idet][ihar]/double(ntrkQ[idet]));
                  hQn_xy[centb][ihar][idet][4*ix+3]->Fill(Q4n[ix][idet][ihar]/double(ntrkQ[idet]));
               }
            }
         }

         for (int icut=0;icut<NCUT;icut++) {
            if (ntrkQ[3+2*icut]>0 && ntrkQ[3+2*icut+1]>0) {
               double Qx_eta1 = Qn  [0][3+2*icut]  [ihar]/double(ntrkQ[3+2*icut]);
               double Qy_eta1 = Qn  [1][3+2*icut]  [ihar]/double(ntrkQ[3+2*icut]);
               double Qx_eta2 = Qn  [0][3+2*icut+1][ihar]/double(ntrkQ[3+2*icut+1]);
               double Qy_eta2 = Qn  [1][3+2*icut+1][ihar]/double(ntrkQ[3+2*icut+1]);
               hQn    [centb][ihar][icut+2]->Fill( sqrt( pow( 0.5*(Qx_eta1 + Qx_eta2), 2) + pow( 0.5*(Qy_eta1 + Qy_eta2), 2) ) );
               hRF_sub[centb][ihar][icut+2]->Fill( sqrt( pow( 0.5*(Qx_eta1 - Qx_eta2), 2) + pow( 0.5*(Qy_eta1 - Qy_eta2), 2) ) );
               for (int is=0;is<2;is++) {
                  for (int ix=0;ix<2;ix++) {
                     int idet = 3 + 2*icut + is; 
                     hQn_xy[centb][ihar][idet][4*ix+0]->Fill(Qn [ix][idet][ihar]/double(ntrkQ[idet]));
                     hQn_xy[centb][ihar][idet][4*ix+1]->Fill(Q2n[ix][idet][ihar]/double(ntrkQ[idet]));
                     hQn_xy[centb][ihar][idet][4*ix+2]->Fill(Q3n[ix][idet][ihar]/double(ntrkQ[idet]));
                     hQn_xy[centb][ihar][idet][4*ix+3]->Fill(Q4n[ix][idet][ihar]/double(ntrkQ[idet]));
                  }
               }
            }
         }
      }
      //--- Fill vnTrue, vnEP, Qn, RFs -------------------------------------------------------------------------------//

      //--- QCorrelators for traditional cumulants -------------------------------------------------------------------//
      S2_1 = S1_1*S1_1;
      S3_1 = S1_1*S1_1*S1_1;
      S4_1 = S1_1*S1_1*S1_1*S1_1;
      S2_2 = S1_2*S1_2;
      
      complex<double>   g(0.0,0.0);
      complex<double>   QC_Qn_Sum [NDET][NHAR];
      complex<double>   QC_Q2n_Sum[NDET][NHAR];
      complex<double>   QC_Q3n_Sum[NDET][NHAR];
      complex<double>   QC_Q4n_Sum[NDET][NHAR];
      
      complex<double>   QC_Qn_Sum_1  [NDET][NHAR];
      complex<double>   QC_Qn_Sum_2  [NDET][NHAR];
      complex<double>   QC_Qn_Sum_3  [NDET][NHAR];
      complex<double>   QC_Q2n_Sum_1 [NDET][NHAR];
      complex<double>   QC_Q2n_Sum_2 [NDET][NHAR];

      for (int idet=0; idet<1; idet++) {
         for(int jn=0;jn<NHAR;jn++){
            complex<double> cc1(Qn  [0][idet][jn], Qn  [1][idet][jn]);
            complex<double> cc2(Q2n [0][idet][jn], Q2n [1][idet][jn]);
            complex<double> cc3(Q3n [0][idet][jn], Q3n [1][idet][jn]);
            complex<double> cc4(Q4n [0][idet][jn], Q4n [1][idet][jn]);
            
            complex<double> cc1_1(Qn_1  [0][idet][jn], Qn_1  [1][idet][jn]);
            complex<double> cc1_2(Qn_2  [0][idet][jn], Qn_2  [1][idet][jn]);
            complex<double> cc1_3(Qn_3  [0][idet][jn], Qn_3  [1][idet][jn]);
            complex<double> cc2_1(Q2n_1 [0][idet][jn], Q2n_1 [1][idet][jn]);
            complex<double> cc2_2(Q2n_2 [0][idet][jn], Q2n_2 [1][idet][jn]);

            QC_Qn_Sum [idet][jn] = cc1;
            QC_Q2n_Sum[idet][jn] = cc2;
            QC_Q3n_Sum[idet][jn] = cc3;
            QC_Q4n_Sum[idet][jn] = cc4;
            
            QC_Qn_Sum_1  [idet][jn] = cc1_1;
            QC_Qn_Sum_2  [idet][jn] = cc1_2;
            QC_Qn_Sum_3  [idet][jn] = cc1_3;
            QC_Q2n_Sum_1 [idet][jn] = cc2_1;
            QC_Q2n_Sum_2 [idet][jn] = cc2_2;
         }

         double ntrkCum = ntrkQ[idet];
         double wei2p  = S2_1 - S1_2;
         double wei4p = S4_1-6*S1_2*S2_1+8*S1_3*S1_1+3*S2_2-6*S1_4;
         
         //double wei2p = ntrkCum*(ntrkCum-1);
         //double wei4p = ntrkCum*(ntrkCum-1)*(ntrkCum-2)*(ntrkCum-3);
         double wei6p = ntrkCum*(ntrkCum-1)*(ntrkCum-2)*(ntrkCum-3)*(ntrkCum-4)*(ntrkCum-5);
         double wei8p = ntrkCum*(ntrkCum-1)*(ntrkCum-2)*(ntrkCum-3)*(ntrkCum-4)*(ntrkCum-5)*(ntrkCum-6)*(ntrkCum-7);

         double corr_2p[NHAR] = {0};
         double corr_4p[NHAR] = {0};   
         double corr_6p[NHAR] = {0};   
         double corr_8p[NHAR] = {0};   

         for(int jn=0;jn<NHAR;jn++){
            double absQn  = abs (QC_Qn_Sum [idet][jn]);
            double absQ2n = abs (QC_Q2n_Sum[idet][jn]);
            double dReQ1n = real(QC_Qn_Sum [idet][jn]);
            double dReQ2n = real(QC_Q2n_Sum[idet][jn]);
            double dImQ1n = imag(QC_Qn_Sum [idet][jn]);
            double dImQ2n = imag(QC_Q2n_Sum[idet][jn]);

            double absQC_w  = abs(QC_Qn_Sum_1 [idet][jn]);
            double absQC2_w = abs(QC_Q2n_Sum_2[idet][jn]);

            corr_2p[jn] = abs(QC_Qn_Sum_1[idet][jn])*abs(QC_Qn_Sum_1[idet][jn])-S1_2;

            corr_4p[jn]
               = absQC_w*absQC_w*absQC_w*absQC_w
               + absQC2_w*absQC2_w
               - 2.*real(QC_Q2n_Sum_2[idet][jn]*conj(QC_Qn_Sum_1[idet][jn])*conj(QC_Qn_Sum_1[idet][jn]))
               + 8.*real(QC_Qn_Sum_3[idet][jn]*conj(QC_Qn_Sum_1[idet][jn]))
               - 4.*S1_2*absQC_w*absQC_w
               - 6. * S1_4 + 2. * S2_2;

            //corr_2p[jn] /= wei2p;
            //corr_4p[jn] /= wei4p;

            /*corr_2p[jn] = ( pow(dReQ1n,2.) + pow(dImQ1n,2.) - ntrkCum )/wei2p;
            corr_4p[jn] = (pow( absQn, 4)
                  + pow( absQ2n, 2)
                  - 2*( pow(dReQ1n,2.)*dReQ2n+2.*dReQ1n*dImQ1n*dImQ2n-pow(dImQ1n,2.)*dReQ2n)
                  - 4*(ntrkCum-2)*absQn*absQn
                  + 2*ntrkCum*(ntrkCum-3) )/wei4p;*/

            double absQC  = abs(QC_Qn_Sum [idet][jn]);
            double absQC2 = abs(QC_Q2n_Sum[idet][jn]);
            double absQC3 = abs(QC_Q3n_Sum[idet][jn]);
            double absQC4 = abs(QC_Q4n_Sum[idet][jn]);

            corr_6p[jn]
               = pow(absQC,6.)
               + 9*absQC2*absQC2*absQC*absQC
               - 6*real(QC_Q2n_Sum[idet][jn]*QC_Qn_Sum[idet][jn]*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn]))
               + 4*(real(QC_Q3n_Sum[idet][jn]*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn]))
                     -3* real(QC_Q3n_Sum[idet][jn]*conj(QC_Q2n_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn])))
               + 2*(9.*(ntrkCum-4.)*real(QC_Q2n_Sum[idet][jn]*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn]))
                     + 2 * abs(QC_Q3n_Sum[idet][jn])* abs(QC_Q3n_Sum[idet][jn]))
               - 9.*(ntrkCum-4.)*(absQC*absQC*absQC*absQC+ absQC2*absQC2)
               + 18 *(ntrkCum-2.)* (ntrkCum-5)*absQC*absQC
               - 6 * ntrkCum *(ntrkCum-4)*(ntrkCum-5);

            corr_8p[jn]
               = pow(absQC,8.)
               - 12.*pow(absQC,4.)*real(QC_Q2n_Sum[idet][jn]*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn]))
               + 16.*pow(absQC,2.)*real(QC_Q3n_Sum[idet][jn]*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn]))
               +  6.*real(QC_Q2n_Sum[idet][jn]*QC_Q2n_Sum[idet][jn]*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn]))
               - 12.*real(QC_Q4n_Sum[idet][jn]*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn]))
               - 36.*pow(absQC2,2.)*real(QC_Q2n_Sum[idet][jn]*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn]))
               - 96.*pow(absQC,2.)*real(QC_Q3n_Sum[idet][jn]*conj(QC_Q2n_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn]))
               + 72.*real(QC_Q4n_Sum[idet][jn]*conj(QC_Q2n_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn]))
               + 48.*real(QC_Q3n_Sum[idet][jn]*QC_Qn_Sum[idet][jn]*conj(QC_Q2n_Sum[idet][jn])*conj(QC_Q2n_Sum[idet][jn]))
               - 64.*(ntrkCum-6.)*real(QC_Q3n_Sum[idet][jn]*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn]))
               + 96.*(ntrkCum-6.)*pow(absQC,2.)*real(QC_Q2n_Sum[idet][jn]*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn]))
               - 96.*real(QC_Q4n_Sum[idet][jn]*conj(QC_Q3n_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn]))
               - 36.*real(QC_Q4n_Sum[idet][jn]*conj(QC_Q2n_Sum[idet][jn])*conj(QC_Q2n_Sum[idet][jn]))
               +192.*(ntrkCum-6.)*real(QC_Q3n_Sum[idet][jn]*conj(QC_Q2n_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn]))
               -144.*(ntrkCum-7.)*(ntrkCum-4.)*real(QC_Q2n_Sum[idet][jn]*conj(QC_Qn_Sum[idet][jn])*conj(QC_Qn_Sum[idet][jn]))
               + 64.*pow(absQC,2.)*pow(absQC3,2.)
               -144.*(ntrkCum-6.)*pow(absQC,2.)*pow(absQC2,2.)
               + 72.*(ntrkCum-7.)*(ntrkCum-4.)*(pow(absQC,4.)+pow(absQC2,2.))
               - 96.*(ntrkCum-7.)*(ntrkCum-6.)*(ntrkCum-2.)*pow(absQC,2.)
               + 36.*pow(absQC,4.)*pow(absQC2,2.)
               +  9.*pow(absQC2,4.)
               - 64.*(ntrkCum-6.)*pow(absQC3,2.)
               + 36.*pow(absQC4,2.)
               - 16.*(ntrkCum-6.)*pow(absQC,6.)
               + 24.*ntrkCum*(ntrkCum-7.)*(ntrkCum-6.)*(ntrkCum-5.)
               ;

            //corr_6p[jn] = corr_6p[jn]/wei6p;
            //corr_8p[jn] = corr_8p[jn]/wei8p;

            double corr2 = corr_2p[jn];
            double corr4 = corr_4p[jn];
            double corr6 = corr_6p[jn];
            double corr8 = corr_8p[jn];

            double cum2 = corr2;
            double cum4 = corr4 - 2*corr2*corr2;
            double cum6 = corr6 - 9*corr2*corr4 + 12*corr2*corr2*corr2;
            double cum8 = corr8 - 16*corr2*corr6 - 18*corr4*corr4 + 144*corr2*corr2*corr4 - 144*corr2*corr2*corr2*corr2;

            double v_n2 = pow( cum2, 1/2.0); //if(corr2<0) v_n2 = -0.05;
            double v_n4 = pow( -cum4, 1/4.0); //if(corr4<0) v_n4 = -0.05;
            double v_n6 = pow( cum6/4.0, 1/6.0); //if(corr6<0) v_n6 = -0.05;
            double v_n8 = pow( -cum8/33.0, 1/8.0); //if(corr8<0) v_n8 = -0.05;

            h_QC2 [jn]->Fill(centb+1,corr_2p[jn]);
            h_QC4 [jn]->Fill(centb+1,corr_4p[jn]);
            h_QC6 [jn]->Fill(centb+1,corr_6p[jn]);
            h_QC8 [jn]->Fill(centb+1,corr_8p[jn]);

            h_QC24  [jn]->Fill(centb+1,corr_2p[jn]*corr_4p[jn]);
            h_QC26  [jn]->Fill(centb+1,corr_2p[jn]*corr_6p[jn]);
            h_QC28  [jn]->Fill(centb+1,corr_2p[jn]*corr_8p[jn]);
            h_QC46  [jn]->Fill(centb+1,corr_4p[jn]*corr_6p[jn]);
            h_QC48  [jn]->Fill(centb+1,corr_4p[jn]*corr_8p[jn]);
            h_QC68  [jn]->Fill(centb+1,corr_6p[jn]*corr_8p[jn]);
         }
         h_W2->Fill(centb+1,wei2p);
         h_W4->Fill(centb+1,wei4p);
         h_W6->Fill(centb+1,wei6p);
         h_W8->Fill(centb+1,wei8p);
      }
      //--- QCorrelators for traditional cumulants -------------------------------------------------------------------//
   }
}

void runMultiCorr_adam_eff::Save() {

   std::cout << "Finished run, Total events = " << nevents << std::endl;
   std::cout << "Saving results" << std::endl;

   fOut->cd(0);
   fOut->Write();

   std::cout << "Finished saving" << std::endl;
}

int runMultiCorr_adam_eff::get_centb(double ntrk) {

   int cent1 = -1;
   for (int icent=0;icent<NCENTH;icent++ ) {
      if (ntrk >= centCutsH[icent]) {
         cent1 = icent;
         break;
      }
   }

   return cent1;
}

int runMultiCorr_adam_eff::get_centbH(double ntrk) {

   int cent1 = -1;
   for (int icent=0;icent<NCENTH;icent++ ) {
      if (ntrk >= centCutsH[icent]) {
         cent1 = icent;
         break;
      }
   }

   return cent1;
}
