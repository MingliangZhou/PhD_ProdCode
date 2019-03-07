#include<iostream>
#include<string>
#include<vector>
#include<TFile.h>
#include<TTree.h>
#include<TChain.h>
#include<TF1.h>
#include<TH1.h>
#include<TH2.h>
#include<TRandom3.h>
#include<TMath.h>

#define MAXTRK 1000

static double PI = acos(-1.0);

static const int NCENT  = 4;
static const int NCENTH = 200;
static const int NHAR   = 2;
static const int NDET   = 13;
static const int NCUT   = 5;

const double centCutsH[]   = {300,240,180,140,120,110,100,95,90,80,85,75,70,65,60,55,50,45,40,35,30,25,20,15,10,5,0};
const double detCuts[NCUT] = {0,0.125,0.25,0.5,1.0};


class runMultiCorr_adam_eff {
   public:

      runMultiCorr_adam_eff(std::string fN_in);
      ~runMultiCorr_adam_eff();
      void exec();

   private:
      
      void InitTrees();
      void SetupAll();
      void run();
      void getCalib(std::string fName);
      void Save();
      int get_centb (double bimp);
      int get_centbH(double ntrk);
      
      TFile* fIn, *fOut, *fH;
      TChain* fChain;

      TH1D* hEtaH;

      TH1D* hcent;
      TH1D* hntrk;
      TH1D* hntrkAll;
      TH1D* hntrkC[NCENTH][NCUT+2];
      
      TH1D* hpt;
      TH1D* heta;
      TH1D* hphi;
      TH2F* hEff;

      TH1D* hVnT   [NCENTH][NHAR];
      TH1D* hVnEP  [NCENTH][NHAR];
      TH1D* hQn    [NCENTH][NHAR][NCUT+2];
      TH1D* hQn_xy [NCENTH][NHAR][NDET][2*4];
      TH1D* hQn_xy_mean    [NHAR][NDET][2*4];
      TH1D* hRF_sub[NCENTH][NHAR][NCUT+2];

      TH1D* h_QC2  [NHAR];
      TH1D* h_QC4  [NHAR];
      TH1D* h_QC6  [NHAR];
      TH1D* h_QC8  [NHAR];
      TH1D* h_QC24 [NHAR];
      TH1D* h_QC26 [NHAR];
      TH1D* h_QC28 [NHAR];
      TH1D* h_QC46 [NHAR];
      TH1D* h_QC48 [NHAR];
      TH1D* h_QC68 [NHAR];
      
      TH1D* h_W2;
      TH1D* h_W4;
      TH1D* h_W6;
      TH1D* h_W8;

      TH1D* h2pc   [NCENTH];

      TRandom3* randGen;

      int nevents;

      //Leaf types for intree
      UChar_t        Trigger;
      Int_t          zPriVtx;
      UInt_t         nTrk;
      UChar_t        trkPt[MAXTRK];   //[nTrk]
      UChar_t        trkEta[MAXTRK];   //[nTrk]
      Float_t        trkPhi[MAXTRK];   //[nTrk]

      TBranch        *b_Trigger;   //!
      TBranch        *b_zPriVtx;   //!
      TBranch        *b_nTrk;   //!
      TBranch        *b_trkPt;   //!
      TBranch        *b_trkEta;   //!
      TBranch        *b_trkPhi;   //!
      
      //Leaf types for outtree
      float Qn[2][NDET][NHAR] ;
      float Q2n[2][NDET][NHAR];
      float Q3n[2][NDET][NHAR];
      float Q4n[2][NDET][NHAR];
      
      float Qn_1 [2][NDET][NHAR] ;
      float Qn_2 [2][NDET][NHAR] ;
      float Qn_3 [2][NDET][NHAR] ;
      float Q2n_1[2][NDET][NHAR] ;
      float Q2n_2[2][NDET][NHAR] ;

      int ntrkQ[NDET];
};
