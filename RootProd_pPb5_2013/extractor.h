#ifndef extractor_h
#define extractor_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TMath.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>

#define MAXTRK 50000
#define MAXVTX 100

using namespace std;

class extractor {
   public :

      TTree          *fChain;       //!pointer to the analyzed TTree or TChain
      TTree          *fChainMeta;   //!pointer to the meta data of analyzed TTree or TChain
      Int_t           fCurrent; //!current Tree number in a TChain

      extractor(){};
      extractor(string filelist);
      virtual ~extractor();

      virtual void     Loop();

      vector<string> HLTChains;
      vector<string> L2Chains;
      vector<string> L1Names;

   private:

      void Fill_prescale();
      void Fill_Trigger();

      virtual void     Init(TTree *tree);
      virtual void     InitMeta(TTree *tree);

      virtual Int_t    Cut(Long64_t entry);
      virtual Int_t    GetEntry(Long64_t entry);
      virtual Long64_t LoadTree(Long64_t entry);
      virtual Bool_t   Notify();
      virtual void     Show(Long64_t entry = -1);

      int NTRIG;

      Int_t SMK;
      Int_t L1PSK;
      Int_t HLTPSK;
      std::map<std::string, int>* L1NameMap;
      std::map<std::string, int>* HLTNameMap;
      std::map<std::string, float>* L1PrescaleMap;
      std::map<std::string, float>* HLTPrescaleMap;

      std::vector<std::vector<Int_t> > dBKeys;

      int metaEntryOld;

      std::vector<float>* EFPrescales;
      std::vector<float>* L2Prescales;
      std::vector<float>* L1Prescales;
      std::vector<float>* Prescales  ;

      Int_t    trigs_MB, trigs_HMT;
      Bool_t   is_MinBias;
      Bool_t   is_HMT;

      Int_t     Mytrk_n;
      Float_t   Mytrk_eta        [MAXTRK];
      Float_t   Mytrk_pt         [MAXTRK];
      Float_t   Mytrk_phi        [MAXTRK];
      UInt_t    Mytrk_Quality    [MAXTRK];
      Bool_t    Mytrk_charge     [MAXTRK];

      Bool_t   is_pileup;
      Bool_t   is_pileupZDC;

      Float_t  Fcal_Et,Fcal_Et_n,Fcal_Et_p;

      Float_t  wt_mbPrimHmt, wt_mbHmt;
      std::vector<float>* wt_trig;

      Int_t    Myvx_n;
      Float_t  Myvx_x    [MAXVTX],Myvx_y    [MAXVTX],Myvx_z    [MAXVTX];
      Float_t  Myvx_sumPt[MAXVTX];

      // Declaration of leaf types
      UInt_t          RunNumber;
      UInt_t          EventNumber;
      UInt_t          timestamp;
      UInt_t          timestamp_ns;
      UInt_t          lbn;
      UInt_t          bcid;
      UInt_t          detmask0;
      UInt_t          detmask1;
      Float_t         actualIntPerXing;
      Float_t         averageIntPerXing;
      UInt_t          pixelFlags;
      UInt_t          sctFlags;
      UInt_t          trtFlags;
      UInt_t          larFlags;
      UInt_t          tileFlags;
      UInt_t          muonFlags;
      UInt_t          fwdFlags;
      UInt_t          coreFlags;
      UInt_t          pixelError;
      UInt_t          sctError;
      UInt_t          trtError;
      UInt_t          larError;
      UInt_t          tileError;
      UInt_t          muonError;
      UInt_t          fwdError;
      UInt_t          coreError;
      Bool_t          streamDecision_Egamma;
      Bool_t          streamDecision_Muons;
      Bool_t          streamDecision_JetTauEtmiss;
      UInt_t          l1id;
      Bool_t          isSimulation;
      Bool_t          isCalibration;
      Bool_t          isTestBeam;
      Int_t           mb_n;
      vector<float>   *mb_E;
      vector<float>   *mb_eta;
      vector<float>   *mb_phi;
      vector<float>   *mb_time;
      vector<int>     *mb_quality;
      vector<int>     *mb_type;
      vector<int>     *mb_module;
      vector<int>     *mb_channel;
      Float_t         mbtime_timeDiff;
      Float_t         mbtime_timeA;
      Float_t         mbtime_timeC;
      Int_t           mbtime_countA;
      Int_t           mbtime_countC;
      Int_t           lucidRaw_word0;
      Int_t           lucidRaw_word1;
      Int_t           lucidRaw_word2;
      Int_t           lucidRaw_word3;
      Int_t           lucidRaw_word0p;
      Int_t           lucidRaw_word1p;
      Int_t           lucidRaw_word2p;
      Int_t           lucidRaw_word3p;
      Int_t           lucidRaw_word0n;
      Int_t           lucidRaw_word1n;
      Int_t           lucidRaw_word2n;
      Int_t           lucidRaw_word3n;
      Int_t           lucidRaw_status;
      Int_t           lucidRaw_totalHits;
      Int_t           lucidRaw_ASideHits;
      Int_t           lucidRaw_CSideHits;
      Int_t           Zdc_n;
      vector<vector<float> > *Zdc_Energy_Vec;
      vector<vector<float> > *Zdc_Time_Vec;
      vector<int>     *Zdc_Vec_Size;
      vector<float>   *Zdc_Energy_LG;
      vector<float>   *Zdc_Time_LG;
      vector<float>   *Zdc_Energy_HG;
      vector<float>   *Zdc_Time_HG;
      vector<unsigned int> *Zdc_Id;
      vector<int>     *Zdc_Side;
      vector<int>     *Zdc_Type;
      vector<int>     *Zdc_Module;
      vector<int>     *Zdc_Channel;
      vector<float>   *Zdc_TimeCalib;
      vector<unsigned int> *Zdc_RecMethod;
      Int_t           ZdcDigits_n;
      vector<vector<int> > *ZdcDigits_dig_g0d0;
      vector<vector<int> > *ZdcDigits_dig_g0d1;
      vector<vector<int> > *ZdcDigits_dig_g1d0;
      vector<vector<int> > *ZdcDigits_dig_g1d1;
      vector<unsigned int> *ZdcDigits_Id;
      vector<int>     *ZdcDigits_Side;
      vector<int>     *ZdcDigits_Type;
      vector<int>     *ZdcDigits_Module;
      vector<int>     *ZdcDigits_Channel;
      Float_t         ZdcReco_ESumA;
      Float_t         ZdcReco_ESumC;
      vector<float>   *ZdcReco_EA;
      vector<float>   *ZdcReco_EC;
      vector<int>     *ZdcReco_qA;
      vector<int>     *ZdcReco_qC;
      Int_t           ZdcReco_ESumA_LG;
      Int_t           ZdcReco_ESumA_HG;
      Int_t           ZdcReco_ESumC_LG;
      Int_t           ZdcReco_ESumC_HG;
      Int_t           cc_fcal_n;
      vector<float>   *cc_fcal_E;
      vector<float>   *cc_fcal_pt;
      vector<float>   *cc_fcal_eta;
      vector<float>   *cc_fcal_phi;
      vector<int>     *cc_fcal_QCells;
      vector<int>     *cc_fcal_GainCells;
      vector<int>     *cc_fcal_DetCells;
      vector<float>   *cc_fcal_TimeCells;
      vector<float>   *cc_fcal_xCells;
      vector<float>   *cc_fcal_yCells;
      vector<float>   *cc_fcal_zCells;
      vector<int>     *cc_fcal_BadCells;
      vector<unsigned int> *cc_fcal_IdCells;
      vector<float>   *cc_fcal_Sigma;

      //Int_t           TotalEt_n;
      vector<float>   *TotalEt_layer_eta;
      //vector<float>   *TotalEt_layer_phi;
      vector<float>   *TotalEt_layer_towerEt;
			vector<vector<float> > *TotalEt_layer_sampling;
			//vector<vector<float> > *TotalEt_layer_sampling_calib;

      Int_t           ccc_Nh_Calo;
      Float_t         ccc_Eh_Calo;
      Int_t           ccc_Nh_EM;
      Float_t         ccc_Eh_EM;
      Int_t           ccc_Nh_HAD;
      Float_t         ccc_Eh_HAD;
      Int_t           ccc_Nh_PresB;
      vector<float>   *ccc_Eh_PresB;
      Int_t           ccc_Nh_EMB;
      vector<float>   *ccc_Eh_EMB;
      Int_t           ccc_Nh_EMEC;
      vector<float>   *ccc_Eh_EMEC;
      Int_t           ccc_Nh_Tile;
      vector<float>   *ccc_Eh_Tile;
      Int_t           ccc_Nh_TileGap;
      vector<float>   *ccc_Eh_TileGap;
      Int_t           ccc_Nh_HEC;
      vector<float>   *ccc_Eh_HEC;
      Int_t           ccc_Nh_FCal;
      vector<float>   *ccc_Eh_FCal;
      Int_t           ccc_Nh_PresE;
      vector<float>   *ccc_Eh_PresE;
      Int_t           ccc_Nh_Scint;
      vector<float>   *ccc_Eh_Scint;
      Int_t           cccEt_Et_Nh_Calo;
      Float_t         cccEt_Et_Eh_Calo;
      Int_t           cccEt_Et_Nh_EM;
      Float_t         cccEt_Et_Eh_EM;
      Int_t           cccEt_Et_Nh_HAD;
      Float_t         cccEt_Et_Eh_HAD;
      Int_t           cccEt_Et_Nh_PresB;
      vector<float>   *cccEt_Et_Eh_PresB;
      Int_t           cccEt_Et_Nh_EMB;
      vector<float>   *cccEt_Et_Eh_EMB;
      Int_t           cccEt_Et_Nh_EMEC;
      vector<float>   *cccEt_Et_Eh_EMEC;
      Int_t           cccEt_Et_Nh_Tile;
      vector<float>   *cccEt_Et_Eh_Tile;
      Int_t           cccEt_Et_Nh_TileGap;
      vector<float>   *cccEt_Et_Eh_TileGap;
      Int_t           cccEt_Et_Nh_HEC;
      vector<float>   *cccEt_Et_Eh_HEC;
      Int_t           cccEt_Et_Nh_FCal;
      vector<float>   *cccEt_Et_Eh_FCal;
      Int_t           cccEt_Et_Nh_PresE;
      vector<float>   *cccEt_Et_Eh_PresE;
      Int_t           cccEt_Et_Nh_Scint;
      vector<float>   *cccEt_Et_Eh_Scint;
      Int_t           cccEt_p_Nh_Calo;
      Float_t         cccEt_p_Eh_Calo;
      Int_t           cccEt_p_Nh_EM;
      Float_t         cccEt_p_Eh_EM;
      Int_t           cccEt_p_Nh_HAD;
      Float_t         cccEt_p_Eh_HAD;
      Int_t           cccEt_p_Nh_PresB;
      vector<float>   *cccEt_p_Eh_PresB;
      Int_t           cccEt_p_Nh_EMB;
      vector<float>   *cccEt_p_Eh_EMB;
      Int_t           cccEt_p_Nh_EMEC;
      vector<float>   *cccEt_p_Eh_EMEC;
      Int_t           cccEt_p_Nh_Tile;
      vector<float>   *cccEt_p_Eh_Tile;
      Int_t           cccEt_p_Nh_TileGap;
      vector<float>   *cccEt_p_Eh_TileGap;
      Int_t           cccEt_p_Nh_HEC;
      vector<float>   *cccEt_p_Eh_HEC;
      Int_t           cccEt_p_Nh_FCal;
      vector<float>   *cccEt_p_Eh_FCal;
      Int_t           cccEt_p_Nh_PresE;
      vector<float>   *cccEt_p_Eh_PresE;
      Int_t           cccEt_p_Nh_Scint;
      vector<float>   *cccEt_p_Eh_Scint;
      Int_t           cccEt_n_Nh_Calo;
      Float_t         cccEt_n_Eh_Calo;
      Int_t           cccEt_n_Nh_EM;
      Float_t         cccEt_n_Eh_EM;
      Int_t           cccEt_n_Nh_HAD;
      Float_t         cccEt_n_Eh_HAD;
      Int_t           cccEt_n_Nh_PresB;
      vector<float>   *cccEt_n_Eh_PresB;
      Int_t           cccEt_n_Nh_EMB;
      vector<float>   *cccEt_n_Eh_EMB;
      Int_t           cccEt_n_Nh_EMEC;
      vector<float>   *cccEt_n_Eh_EMEC;
      Int_t           cccEt_n_Nh_Tile;
      vector<float>   *cccEt_n_Eh_Tile;
      Int_t           cccEt_n_Nh_TileGap;
      vector<float>   *cccEt_n_Eh_TileGap;
      Int_t           cccEt_n_Nh_HEC;
      vector<float>   *cccEt_n_Eh_HEC;
      Int_t           cccEt_n_Nh_FCal;
      vector<float>   *cccEt_n_Eh_FCal;
      Int_t           cccEt_n_Nh_PresE;
      vector<float>   *cccEt_n_Eh_PresE;
      Int_t           cccEt_n_Nh_Scint;
      vector<float>   *cccEt_n_Eh_Scint;
      Int_t           lar_ncellA;
      Int_t           lar_ncellC;
      Float_t         lar_energyA;
      Float_t         lar_energyC;
      Float_t         lar_timeA;
      Float_t         lar_timeC;
      Float_t         lar_timeDiff;
      Int_t           trk_n;
      vector<float>   *trk_d0;
      vector<float>   *trk_z0;
      vector<float>   *trk_phi;
      vector<float>   *trk_theta;
      vector<float>   *trk_qoverp;
      vector<float>   *trk_pt;
      vector<float>   *trk_eta;
      vector<float>   *trk_err_d0;
      vector<float>   *trk_err_z0;
      vector<float>   *trk_err_phi;
      vector<float>   *trk_err_theta;
      vector<float>   *trk_err_qoverp;
      vector<float>   *trk_cov_d0_z0;
      vector<float>   *trk_cov_d0_phi;
      vector<float>   *trk_cov_d0_theta;
      vector<float>   *trk_cov_d0_qoverp;
      vector<float>   *trk_cov_z0_phi;
      vector<float>   *trk_cov_z0_theta;
      vector<float>   *trk_cov_z0_qoverp;
      vector<float>   *trk_cov_phi_theta;
      vector<float>   *trk_cov_phi_qoverp;
      vector<float>   *trk_cov_theta_qoverp;
      vector<float>   *trk_d0_wrtPV;
      vector<float>   *trk_z0_wrtPV;
      vector<float>   *trk_phi_wrtPV;
      vector<float>   *trk_err_d0_wrtPV;
      vector<float>   *trk_err_z0_wrtPV;
      vector<float>   *trk_err_phi_wrtPV;
      vector<float>   *trk_err_theta_wrtPV;
      vector<float>   *trk_err_qoverp_wrtPV;
      vector<float>   *trk_cov_d0_z0_wrtPV;
      vector<float>   *trk_cov_d0_phi_wrtPV;
      vector<float>   *trk_cov_d0_theta_wrtPV;
      vector<float>   *trk_cov_d0_qoverp_wrtPV;
      vector<float>   *trk_cov_z0_phi_wrtPV;
      vector<float>   *trk_cov_z0_theta_wrtPV;
      vector<float>   *trk_cov_z0_qoverp_wrtPV;
      vector<float>   *trk_cov_phi_theta_wrtPV;
      vector<float>   *trk_cov_phi_qoverp_wrtPV;
      vector<float>   *trk_cov_theta_qoverp_wrtPV;
      vector<float>   *trk_d0_wrtBS;
      vector<float>   *trk_z0_wrtBS;
      vector<float>   *trk_phi_wrtBS;
      vector<float>   *trk_err_d0_wrtBS;
      vector<float>   *trk_err_z0_wrtBS;
      vector<float>   *trk_err_phi_wrtBS;
      vector<float>   *trk_err_theta_wrtBS;
      vector<float>   *trk_err_qoverp_wrtBS;
      vector<float>   *trk_cov_d0_z0_wrtBS;
      vector<float>   *trk_cov_d0_phi_wrtBS;
      vector<float>   *trk_cov_d0_theta_wrtBS;
      vector<float>   *trk_cov_d0_qoverp_wrtBS;
      vector<float>   *trk_cov_z0_phi_wrtBS;
      vector<float>   *trk_cov_z0_theta_wrtBS;
      vector<float>   *trk_cov_z0_qoverp_wrtBS;
      vector<float>   *trk_cov_phi_theta_wrtBS;
      vector<float>   *trk_cov_phi_qoverp_wrtBS;
      vector<float>   *trk_cov_theta_qoverp_wrtBS;
      vector<float>   *trk_d0_wrtBL;
      vector<float>   *trk_z0_wrtBL;
      vector<float>   *trk_phi_wrtBL;
      vector<float>   *trk_d0_err_wrtBL;
      vector<float>   *trk_z0_err_wrtBL;
      vector<float>   *trk_phi_err_wrtBL;
      vector<float>   *trk_theta_err_wrtBL;
      vector<float>   *trk_qoverp_err_wrtBL;
      vector<float>   *trk_d0_z0_err_wrtBL;
      vector<float>   *trk_d0_phi_err_wrtBL;
      vector<float>   *trk_d0_theta_err_wrtBL;
      vector<float>   *trk_d0_qoverp_err_wrtBL;
      vector<float>   *trk_z0_phi_err_wrtBL;
      vector<float>   *trk_z0_theta_err_wrtBL;
      vector<float>   *trk_z0_qoverp_err_wrtBL;
      vector<float>   *trk_phi_theta_err_wrtBL;
      vector<float>   *trk_phi_qoverp_err_wrtBL;
      vector<float>   *trk_theta_qoverp_err_wrtBL;
      vector<float>   *trk_chi2;
      vector<int>     *trk_ndof;
      vector<int>     *trk_nBLHits;
      vector<int>     *trk_nPixHits;
      vector<int>     *trk_nSCTHits;
      vector<int>     *trk_nTRTHits;
      vector<int>     *trk_nTRTHighTHits;
      vector<int>     *trk_nTRTXenonHits;
      vector<int>     *trk_nPixHoles;
      vector<int>     *trk_nSCTHoles;
      vector<int>     *trk_nTRTHoles;
      vector<int>     *trk_nPixelDeadSensors;
      vector<int>     *trk_nSCTDeadSensors;
      vector<int>     *trk_nBLSharedHits;
      vector<int>     *trk_nPixSharedHits;
      vector<int>     *trk_nSCTSharedHits;
      vector<int>     *trk_nBLayerSplitHits;
      vector<int>     *trk_nPixSplitHits;
      vector<int>     *trk_expectBLayerHit;
      vector<int>     *trk_nMDTHits;
      vector<int>     *trk_nCSCEtaHits;
      vector<int>     *trk_nCSCPhiHits;
      vector<int>     *trk_nRPCEtaHits;
      vector<int>     *trk_nRPCPhiHits;
      vector<int>     *trk_nTGCEtaHits;
      vector<int>     *trk_nTGCPhiHits;
      vector<int>     *trk_nHits;
      vector<int>     *trk_nHoles;
      vector<int>     *trk_hitPattern;
      vector<float>   *trk_TRTHighTHitsRatio;
      vector<float>   *trk_TRTHighTOutliersRatio;
      vector<float>   *trk_pixeldEdx;
      vector<int>     *trk_nGoodHitsPixeldEdx;
      vector<float>   *trk_massPixeldEdx;
      vector<vector<float> > *trk_likelihoodsPixeldEdx;
      vector<int>     *trk_fitter;
      vector<int>     *trk_patternReco1;
      vector<int>     *trk_patternReco2;
      vector<int>     *trk_trackProperties;
      vector<int>     *trk_particleHypothesis;
      vector<vector<float> > *trk_blayerPrediction_x;
      vector<vector<float> > *trk_blayerPrediction_y;
      vector<vector<float> > *trk_blayerPrediction_z;
      vector<vector<float> > *trk_blayerPrediction_locX;
      vector<vector<float> > *trk_blayerPrediction_locY;
      vector<vector<float> > *trk_blayerPrediction_err_locX;
      vector<vector<float> > *trk_blayerPrediction_err_locY;
      vector<vector<float> > *trk_blayerPrediction_etaDistToEdge;
      vector<vector<float> > *trk_blayerPrediction_phiDistToEdge;
      vector<vector<unsigned int> > *trk_blayerPrediction_detElementId;
      vector<vector<int> > *trk_blayerPrediction_row;
      vector<vector<int> > *trk_blayerPrediction_col;
      vector<vector<int> > *trk_blayerPrediction_type;
      Int_t           trkPix_n;
      vector<float>   *trkPix_d0;
      vector<float>   *trkPix_z0;
      vector<float>   *trkPix_phi;
      vector<float>   *trkPix_theta;
      vector<float>   *trkPix_qoverp;
      vector<float>   *trkPix_pt;
      vector<float>   *trkPix_eta;
      vector<float>   *trkPix_err_d0;
      vector<float>   *trkPix_err_z0;
      vector<float>   *trkPix_err_phi;
      vector<float>   *trkPix_err_theta;
      vector<float>   *trkPix_err_qoverp;
      vector<float>   *trkPix_cov_d0_z0;
      vector<float>   *trkPix_cov_d0_phi;
      vector<float>   *trkPix_cov_d0_theta;
      vector<float>   *trkPix_cov_d0_qoverp;
      vector<float>   *trkPix_cov_z0_phi;
      vector<float>   *trkPix_cov_z0_theta;
      vector<float>   *trkPix_cov_z0_qoverp;
      vector<float>   *trkPix_cov_phi_theta;
      vector<float>   *trkPix_cov_phi_qoverp;
      vector<float>   *trkPix_cov_theta_qoverp;
      vector<float>   *trkPix_d0_wrtPV;
      vector<float>   *trkPix_z0_wrtPV;
      vector<float>   *trkPix_phi_wrtPV;
      vector<float>   *trkPix_err_d0_wrtPV;
      vector<float>   *trkPix_err_z0_wrtPV;
      vector<float>   *trkPix_err_phi_wrtPV;
      vector<float>   *trkPix_err_theta_wrtPV;
      vector<float>   *trkPix_err_qoverp_wrtPV;
      vector<float>   *trkPix_cov_d0_z0_wrtPV;
      vector<float>   *trkPix_cov_d0_phi_wrtPV;
      vector<float>   *trkPix_cov_d0_theta_wrtPV;
      vector<float>   *trkPix_cov_d0_qoverp_wrtPV;
      vector<float>   *trkPix_cov_z0_phi_wrtPV;
      vector<float>   *trkPix_cov_z0_theta_wrtPV;
      vector<float>   *trkPix_cov_z0_qoverp_wrtPV;
      vector<float>   *trkPix_cov_phi_theta_wrtPV;
      vector<float>   *trkPix_cov_phi_qoverp_wrtPV;
      vector<float>   *trkPix_cov_theta_qoverp_wrtPV;
      vector<float>   *trkPix_d0_wrtBS;
      vector<float>   *trkPix_z0_wrtBS;
      vector<float>   *trkPix_phi_wrtBS;
      vector<float>   *trkPix_err_d0_wrtBS;
      vector<float>   *trkPix_err_z0_wrtBS;
      vector<float>   *trkPix_err_phi_wrtBS;
      vector<float>   *trkPix_err_theta_wrtBS;
      vector<float>   *trkPix_err_qoverp_wrtBS;
      vector<float>   *trkPix_cov_d0_z0_wrtBS;
      vector<float>   *trkPix_cov_d0_phi_wrtBS;
      vector<float>   *trkPix_cov_d0_theta_wrtBS;
      vector<float>   *trkPix_cov_d0_qoverp_wrtBS;
      vector<float>   *trkPix_cov_z0_phi_wrtBS;
      vector<float>   *trkPix_cov_z0_theta_wrtBS;
      vector<float>   *trkPix_cov_z0_qoverp_wrtBS;
      vector<float>   *trkPix_cov_phi_theta_wrtBS;
      vector<float>   *trkPix_cov_phi_qoverp_wrtBS;
      vector<float>   *trkPix_cov_theta_qoverp_wrtBS;
      vector<float>   *trkPix_d0_wrtBL;
      vector<float>   *trkPix_z0_wrtBL;
      vector<float>   *trkPix_phi_wrtBL;
      vector<float>   *trkPix_d0_err_wrtBL;
      vector<float>   *trkPix_z0_err_wrtBL;
      vector<float>   *trkPix_phi_err_wrtBL;
      vector<float>   *trkPix_theta_err_wrtBL;
      vector<float>   *trkPix_qoverp_err_wrtBL;
      vector<float>   *trkPix_d0_z0_err_wrtBL;
      vector<float>   *trkPix_d0_phi_err_wrtBL;
      vector<float>   *trkPix_d0_theta_err_wrtBL;
      vector<float>   *trkPix_d0_qoverp_err_wrtBL;
      vector<float>   *trkPix_z0_phi_err_wrtBL;
      vector<float>   *trkPix_z0_theta_err_wrtBL;
      vector<float>   *trkPix_z0_qoverp_err_wrtBL;
      vector<float>   *trkPix_phi_theta_err_wrtBL;
      vector<float>   *trkPix_phi_qoverp_err_wrtBL;
      vector<float>   *trkPix_theta_qoverp_err_wrtBL;
      vector<float>   *trkPix_chi2;
      vector<int>     *trkPix_ndof;
      vector<int>     *trkPix_nBLHits;
      vector<int>     *trkPix_nPixHits;
      vector<int>     *trkPix_nSCTHits;
      vector<int>     *trkPix_nTRTHits;
      vector<int>     *trkPix_nTRTHighTHits;
      vector<int>     *trkPix_nTRTXenonHits;
      vector<int>     *trkPix_nPixHoles;
      vector<int>     *trkPix_nSCTHoles;
      vector<int>     *trkPix_nTRTHoles;
      vector<int>     *trkPix_nPixelDeadSensors;
      vector<int>     *trkPix_nSCTDeadSensors;
      vector<int>     *trkPix_nBLSharedHits;
      vector<int>     *trkPix_nPixSharedHits;
      vector<int>     *trkPix_nSCTSharedHits;
      vector<int>     *trkPix_nBLayerSplitHits;
      vector<int>     *trkPix_nPixSplitHits;
      vector<int>     *trkPix_expectBLayerHit;
      vector<int>     *trkPix_nMDTHits;
      vector<int>     *trkPix_nCSCEtaHits;
      vector<int>     *trkPix_nCSCPhiHits;
      vector<int>     *trkPix_nRPCEtaHits;
      vector<int>     *trkPix_nRPCPhiHits;
      vector<int>     *trkPix_nTGCEtaHits;
      vector<int>     *trkPix_nTGCPhiHits;
      vector<int>     *trkPix_nHits;
      vector<int>     *trkPix_nHoles;
      vector<int>     *trkPix_hitPattern;
      vector<float>   *trkPix_TRTHighTHitsRatio;
      vector<float>   *trkPix_TRTHighTOutliersRatio;
      vector<float>   *trkPix_pixeldEdx;
      vector<int>     *trkPix_nGoodHitsPixeldEdx;
      vector<float>   *trkPix_massPixeldEdx;
      vector<vector<float> > *trkPix_likelihoodsPixeldEdx;
      vector<int>     *trkPix_fitter;
      vector<int>     *trkPix_patternReco1;
      vector<int>     *trkPix_patternReco2;
      vector<int>     *trkPix_trackProperties;
      vector<int>     *trkPix_particleHypothesis;
      vector<vector<float> > *trkPix_blayerPrediction_x;
      vector<vector<float> > *trkPix_blayerPrediction_y;
      vector<vector<float> > *trkPix_blayerPrediction_z;
      vector<vector<float> > *trkPix_blayerPrediction_locX;
      vector<vector<float> > *trkPix_blayerPrediction_locY;
      vector<vector<float> > *trkPix_blayerPrediction_err_locX;
      vector<vector<float> > *trkPix_blayerPrediction_err_locY;
      vector<vector<float> > *trkPix_blayerPrediction_etaDistToEdge;
      vector<vector<float> > *trkPix_blayerPrediction_phiDistToEdge;
      vector<vector<unsigned int> > *trkPix_blayerPrediction_detElementId;
      vector<vector<int> > *trkPix_blayerPrediction_row;
      vector<vector<int> > *trkPix_blayerPrediction_col;
      vector<vector<int> > *trkPix_blayerPrediction_type;
      Int_t           trt_RDO_countRDOhitsInEvent;
      Int_t           trt_RDO_countBarrelhitsInEvent;
      Int_t           trt_RDO_countEndCaphitsInEvent;
      Int_t           trt_RDO_countEndCapAhitsInEvent;
      Int_t           trt_RDO_countEndCapChitsInEvent;
      Int_t           trt_RDO_countdeadstraws;
      Float_t         HIFlow_v1_PsiFCAL0_w;
      Float_t         HIFlow_v1_PsiPFCAL0_w;
      Float_t         HIFlow_v1_PsiNFCAL0_w;
      vector<float>   *HIFlow_v1_EtInLayer;
      vector<float>   *HIFlow_v1_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers;
      Float_t         HIFlow_v1_AvgV2fromCalo;
      vector<float>   *HIFlow_v1_PsiHICaloUtilLayers;
      vector<float>   *HIFlow_v1_PsiEtHICaloUtilLayers;
      Float_t         HIFlow_v1_PsiPtrack;
      Float_t         HIFlow_v1_PsiNtrack;
      Float_t         HIFlow_v1_v2FCAL0sil;
      Float_t         HIFlow_v1_v2track;
      vector<float>   *HIFlow_v1_Meanv2_Psi_From_FCAL0CaloCel_IDLayers;
      Float_t         HIFlow_v2_PsiFCAL0_w;
      Float_t         HIFlow_v2_PsiPFCAL0_w;
      Float_t         HIFlow_v2_PsiNFCAL0_w;
      vector<float>   *HIFlow_v2_EtInLayer;
      vector<float>   *HIFlow_v2_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers;
      Float_t         HIFlow_v2_AvgV2fromCalo;
      vector<float>   *HIFlow_v2_PsiHICaloUtilLayers;
      vector<float>   *HIFlow_v2_PsiEtHICaloUtilLayers;
      Float_t         HIFlow_v2_PsiPtrack;
      Float_t         HIFlow_v2_PsiNtrack;
      Float_t         HIFlow_v2_v2FCAL0sil;
      Float_t         HIFlow_v2_v2track;
      vector<float>   *HIFlow_v2_Meanv2_Psi_From_FCAL0CaloCel_IDLayers;
      Float_t         HIFlow_v3_PsiFCAL0_w;
      Float_t         HIFlow_v3_PsiPFCAL0_w;
      Float_t         HIFlow_v3_PsiNFCAL0_w;
      vector<float>   *HIFlow_v3_EtInLayer;
      vector<float>   *HIFlow_v3_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers;
      Float_t         HIFlow_v3_AvgV2fromCalo;
      vector<float>   *HIFlow_v3_PsiHICaloUtilLayers;
      vector<float>   *HIFlow_v3_PsiEtHICaloUtilLayers;
      Float_t         HIFlow_v3_PsiPtrack;
      Float_t         HIFlow_v3_PsiNtrack;
      Float_t         HIFlow_v3_v2FCAL0sil;
      Float_t         HIFlow_v3_v2track;
      vector<float>   *HIFlow_v3_Meanv2_Psi_From_FCAL0CaloCel_IDLayers;
      Float_t         HIFlow_v4_PsiFCAL0_w;
      Float_t         HIFlow_v4_PsiPFCAL0_w;
      Float_t         HIFlow_v4_PsiNFCAL0_w;
      vector<float>   *HIFlow_v4_EtInLayer;
      vector<float>   *HIFlow_v4_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers;
      Float_t         HIFlow_v4_AvgV2fromCalo;
      vector<float>   *HIFlow_v4_PsiHICaloUtilLayers;
      vector<float>   *HIFlow_v4_PsiEtHICaloUtilLayers;
      Float_t         HIFlow_v4_PsiPtrack;
      Float_t         HIFlow_v4_PsiNtrack;
      Float_t         HIFlow_v4_v2FCAL0sil;
      Float_t         HIFlow_v4_v2track;
      vector<float>   *HIFlow_v4_Meanv2_Psi_From_FCAL0CaloCel_IDLayers;
      Float_t         HIFlow_v5_PsiFCAL0_w;
      Float_t         HIFlow_v5_PsiPFCAL0_w;
      Float_t         HIFlow_v5_PsiNFCAL0_w;
      vector<float>   *HIFlow_v5_EtInLayer;
      vector<float>   *HIFlow_v5_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers;
      Float_t         HIFlow_v5_AvgV2fromCalo;
      vector<float>   *HIFlow_v5_PsiHICaloUtilLayers;
      vector<float>   *HIFlow_v5_PsiEtHICaloUtilLayers;
      Float_t         HIFlow_v5_PsiPtrack;
      Float_t         HIFlow_v5_PsiNtrack;
      Float_t         HIFlow_v5_v2FCAL0sil;
      Float_t         HIFlow_v5_v2track;
      vector<float>   *HIFlow_v5_Meanv2_Psi_From_FCAL0CaloCel_IDLayers;
      Float_t         HIFlow_v6_PsiFCAL0_w;
      Float_t         HIFlow_v6_PsiPFCAL0_w;
      Float_t         HIFlow_v6_PsiNFCAL0_w;
      vector<float>   *HIFlow_v6_EtInLayer;
      vector<float>   *HIFlow_v6_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers;
      Float_t         HIFlow_v6_AvgV2fromCalo;
      vector<float>   *HIFlow_v6_PsiHICaloUtilLayers;
      vector<float>   *HIFlow_v6_PsiEtHICaloUtilLayers;
      Float_t         HIFlow_v6_PsiPtrack;
      Float_t         HIFlow_v6_PsiNtrack;
      Float_t         HIFlow_v6_v2FCAL0sil;
      Float_t         HIFlow_v6_v2track;
      vector<float>   *HIFlow_v6_Meanv2_Psi_From_FCAL0CaloCel_IDLayers;
      Float_t         MET_RefFinal_etx;
      Float_t         MET_RefFinal_ety;
      Float_t         MET_RefFinal_phi;
      Float_t         MET_RefFinal_et;
      Float_t         MET_RefFinal_sumet;
      Float_t         MET_RefFinal_etx_CentralReg;
      Float_t         MET_RefFinal_ety_CentralReg;
      Float_t         MET_RefFinal_sumet_CentralReg;
      Float_t         MET_RefFinal_phi_CentralReg;
      Float_t         MET_RefFinal_etx_EndcapRegion;
      Float_t         MET_RefFinal_ety_EndcapRegion;
      Float_t         MET_RefFinal_sumet_EndcapRegion;
      Float_t         MET_RefFinal_phi_EndcapRegion;
      Float_t         MET_RefFinal_etx_ForwardReg;
      Float_t         MET_RefFinal_ety_ForwardReg;
      Float_t         MET_RefFinal_sumet_ForwardReg;
      Float_t         MET_RefFinal_phi_ForwardReg;
      Int_t           cccEt2_Et2_Nh_Calo;
      Float_t         cccEt2_Et2_Eh_Calo;
      Int_t           cccEt2_Et2_Nh_EM;
      Float_t         cccEt2_Et2_Eh_EM;
      Int_t           cccEt2_Et2_Nh_HAD;
      Float_t         cccEt2_Et2_Eh_HAD;
      Int_t           cccEt2_Et2_Nh_PresB;
      vector<float>   *cccEt2_Et2_Eh_PresB;
      Int_t           cccEt2_Et2_Nh_EMB;
      vector<float>   *cccEt2_Et2_Eh_EMB;
      Int_t           cccEt2_Et2_Nh_EMEC;
      vector<float>   *cccEt2_Et2_Eh_EMEC;
      Int_t           cccEt2_Et2_Nh_Tile;
      vector<float>   *cccEt2_Et2_Eh_Tile;
      Int_t           cccEt2_Et2_Nh_TileGap;
      vector<float>   *cccEt2_Et2_Eh_TileGap;
      Int_t           cccEt2_Et2_Nh_HEC;
      vector<float>   *cccEt2_Et2_Eh_HEC;
      Int_t           cccEt2_Et2_Nh_FCal;
      vector<float>   *cccEt2_Et2_Eh_FCal;
      Int_t           cccEt2_Et2_Nh_PresE;
      vector<float>   *cccEt2_Et2_Eh_PresE;
      Int_t           cccEt2_Et2_Nh_Scint;
      vector<float>   *cccEt2_Et2_Eh_Scint;
      Int_t           cccEt2_p2_Nh_Calo;
      Float_t         cccEt2_p2_Eh_Calo;
      Int_t           cccEt2_p2_Nh_EM;
      Float_t         cccEt2_p2_Eh_EM;
      Int_t           cccEt2_p2_Nh_HAD;
      Float_t         cccEt2_p2_Eh_HAD;
      Int_t           cccEt2_p2_Nh_PresB;
      vector<float>   *cccEt2_p2_Eh_PresB;
      Int_t           cccEt2_p2_Nh_EMB;
      vector<float>   *cccEt2_p2_Eh_EMB;
      Int_t           cccEt2_p2_Nh_EMEC;
      vector<float>   *cccEt2_p2_Eh_EMEC;
      Int_t           cccEt2_p2_Nh_Tile;
      vector<float>   *cccEt2_p2_Eh_Tile;
      Int_t           cccEt2_p2_Nh_TileGap;
      vector<float>   *cccEt2_p2_Eh_TileGap;
      Int_t           cccEt2_p2_Nh_HEC;
      vector<float>   *cccEt2_p2_Eh_HEC;
      Int_t           cccEt2_p2_Nh_FCal;
      vector<float>   *cccEt2_p2_Eh_FCal;
      Int_t           cccEt2_p2_Nh_PresE;
      vector<float>   *cccEt2_p2_Eh_PresE;
      Int_t           cccEt2_p2_Nh_Scint;
      vector<float>   *cccEt2_p2_Eh_Scint;
      Int_t           cccEt2_n2_Nh_Calo;
      Float_t         cccEt2_n2_Eh_Calo;
      Int_t           cccEt2_n2_Nh_EM;
      Float_t         cccEt2_n2_Eh_EM;
      Int_t           cccEt2_n2_Nh_HAD;
      Float_t         cccEt2_n2_Eh_HAD;
      Int_t           cccEt2_n2_Nh_PresB;
      vector<float>   *cccEt2_n2_Eh_PresB;
      Int_t           cccEt2_n2_Nh_EMB;
      vector<float>   *cccEt2_n2_Eh_EMB;
      Int_t           cccEt2_n2_Nh_EMEC;
      vector<float>   *cccEt2_n2_Eh_EMEC;
      Int_t           cccEt2_n2_Nh_Tile;
      vector<float>   *cccEt2_n2_Eh_Tile;
      Int_t           cccEt2_n2_Nh_TileGap;
      vector<float>   *cccEt2_n2_Eh_TileGap;
      Int_t           cccEt2_n2_Nh_HEC;
      vector<float>   *cccEt2_n2_Eh_HEC;
      Int_t           cccEt2_n2_Nh_FCal;
      vector<float>   *cccEt2_n2_Eh_FCal;
      Int_t           cccEt2_n2_Nh_PresE;
      vector<float>   *cccEt2_n2_Eh_PresE;
      Int_t           cccEt2_n2_Nh_Scint;
      vector<float>   *cccEt2_n2_Eh_Scint;
      Int_t           cl_hadTopo_n;
      vector<float>   *cl_hadTopo_E;
      vector<float>   *cl_hadTopo_pt;
      vector<float>   *cl_hadTopo_eta;
      vector<float>   *cl_hadTopo_phi;
      vector<float>   *cl_hadTopo_E_em;
      vector<float>   *cl_hadTopo_E_had;
      vector<float>   *cl_hadTopo_significance;
      vector<float>   *cl_hadTopo_cellSignificance;
      vector<float>   *cl_hadTopo_cellSigSampling;
      vector<float>   *cl_hadTopo_firstEdens;
      vector<float>   *cl_hadTopo_cellmaxfrac;
      vector<float>   *cl_hadTopo_longitudinal;
      vector<float>   *cl_hadTopo_secondlambda;
      vector<float>   *cl_hadTopo_lateral;
      vector<float>   *cl_hadTopo_secondR;
      vector<float>   *cl_hadTopo_centerlambda;
      vector<float>   *cl_hadTopo_deltaTheta;
      vector<float>   *cl_hadTopo_deltaPhi;
      vector<float>   *cl_hadTopo_centermag;
      vector<float>   *cl_hadTopo_time;
      vector<float>   *cl_hadTopo_E_PreSamplerB;
      vector<float>   *cl_hadTopo_E_EMB1;
      vector<float>   *cl_hadTopo_E_EMB2;
      vector<float>   *cl_hadTopo_E_EMB3;
      vector<float>   *cl_hadTopo_E_PreSamplerE;
      vector<float>   *cl_hadTopo_E_EME1;
      vector<float>   *cl_hadTopo_E_EME2;
      vector<float>   *cl_hadTopo_E_EME3;
      vector<float>   *cl_hadTopo_E_HEC0;
      vector<float>   *cl_hadTopo_E_HEC1;
      vector<float>   *cl_hadTopo_E_HEC2;
      vector<float>   *cl_hadTopo_E_HEC3;
      vector<float>   *cl_hadTopo_E_TileBar0;
      vector<float>   *cl_hadTopo_E_TileBar1;
      vector<float>   *cl_hadTopo_E_TileBar2;
      vector<float>   *cl_hadTopo_E_TileGap1;
      vector<float>   *cl_hadTopo_E_TileGap2;
      vector<float>   *cl_hadTopo_E_TileGap3;
      vector<float>   *cl_hadTopo_E_TileExt0;
      vector<float>   *cl_hadTopo_E_TileExt1;
      vector<float>   *cl_hadTopo_E_TileExt2;
      vector<float>   *cl_hadTopo_E_FCAL0;
      vector<float>   *cl_hadTopo_E_FCAL1;
      vector<float>   *cl_hadTopo_E_FCAL2;
      UInt_t          HIEtaGap_beam1;
      UInt_t          HIEtaGap_beam2;
      vector<float>   *HIEtaGap_lowerEta;
      vector<float>   *HIEtaGap_upperEta;
      vector<float>   *HIEtaGap_lowerEdgeType;
      vector<float>   *HIEtaGap_upperEdgeType;
      Float_t         HIEtaGap_lowerEtaNegEdge;
      Float_t         HIEtaGap_upperEtaNegEdge;
      Float_t         HIEtaGap_lowerEtaPosEdge;
      Float_t         HIEtaGap_upperEtaPosEdge;
      Float_t         HIEtaGap_maxGapSize;
      Int_t           HITrigVtxCounts_NtrksPrim;
      Float_t         HITrigVtxCounts_SumPtsqPrim;
      UInt_t          trig_DB_SMK;
      UInt_t          trig_DB_L1PSK;
      UInt_t          trig_DB_HLTPSK;
      vector<unsigned int> *trig_L1_TAV;
      vector<short>   *trig_L2_passedPhysics;
      vector<short>   *trig_EF_passedPhysics;
      vector<unsigned int> *trig_L1_TBP;
      vector<unsigned int> *trig_L1_TAP;
      vector<short>   *trig_L2_passedRaw;
      vector<short>   *trig_EF_passedRaw;
      Bool_t          trig_L2_truncated;
      Bool_t          trig_EF_truncated;
      vector<short>   *trig_L2_resurrected;
      vector<short>   *trig_EF_resurrected;
      vector<short>   *trig_L2_passedThrough;
      vector<short>   *trig_EF_passedThrough;
      vector<short>   *trig_L2_wasPrescaled;
      vector<short>   *trig_L2_wasResurrected;
      vector<short>   *trig_EF_wasPrescaled;
      vector<short>   *trig_EF_wasResurrected;
      Int_t           trig_L1_jet_n;
      vector<float>   *trig_L1_jet_eta;
      vector<float>   *trig_L1_jet_phi;
      vector<vector<string> > *trig_L1_jet_thrNames;
      vector<vector<float> > *trig_L1_jet_thrValues;
      vector<unsigned int> *trig_L1_jet_thrPattern;
      vector<unsigned int> *trig_L1_jet_RoIWord;
      vector<float>   *trig_L1_jet_et4x4;
      vector<float>   *trig_L1_jet_et6x6;
      vector<float>   *trig_L1_jet_et8x8;
      Int_t           trig_L1_emtau_n;
      vector<float>   *trig_L1_emtau_eta;
      vector<float>   *trig_L1_emtau_phi;
      vector<vector<string> > *trig_L1_emtau_thrNames;
      vector<vector<float> > *trig_L1_emtau_thrValues;
      vector<float>   *trig_L1_emtau_core;
      vector<float>   *trig_L1_emtau_EMClus;
      vector<float>   *trig_L1_emtau_tauClus;
      vector<float>   *trig_L1_emtau_EMIsol;
      vector<float>   *trig_L1_emtau_hadIsol;
      vector<float>   *trig_L1_emtau_hadCore;
      vector<unsigned int> *trig_L1_emtau_thrPattern;
      vector<unsigned int> *trig_L1_emtau_RoIWord;
      Int_t           trig_L1_mu_n;
      vector<float>   *trig_L1_mu_pt;
      vector<float>   *trig_L1_mu_eta;
      vector<float>   *trig_L1_mu_phi;
      vector<string>  *trig_L1_mu_thrName;
      vector<short>   *trig_L1_mu_thrNumber;
      vector<short>   *trig_L1_mu_RoINumber;
      vector<short>   *trig_L1_mu_sectorAddress;
      vector<int>     *trig_L1_mu_firstCandidate;
      vector<int>     *trig_L1_mu_moreCandInRoI;
      vector<int>     *trig_L1_mu_moreCandInSector;
      vector<short>   *trig_L1_mu_source;
      vector<short>   *trig_L1_mu_hemisphere;
      vector<short>   *trig_L1_mu_charge;
      vector<int>     *trig_L1_mu_vetoed;
      vector<unsigned int> *trig_L1_mu_RoIWord;
      Int_t           trig_EF_jet_n;
      vector<float>   *trig_EF_jet_E;
      vector<float>   *trig_EF_jet_pt;
      vector<float>   *trig_EF_jet_m;
      vector<float>   *trig_EF_jet_eta;
      vector<float>   *trig_EF_jet_phi;
      vector<int>     *trig_EF_jet_a4tcem;
      vector<int>     *trig_EF_jet_a2tcem;
      vector<int>     *trig_EF_jet_a4tchad;
      vector<int>     *trig_EF_jet_a4hi;
      vector<int>     *trig_EF_jet_a2hi;
      vector<unsigned int> *trig_EF_jet_RoIword;
      vector<int>     *trig_EF_jet_EF_2j0_a4tcem_deta40;
      vector<int>     *trig_EF_jet_EF_2j10_a4hi_EFFS_2L1J5;
      vector<int>     *trig_EF_jet_EF_2j10_a4hi_EFFS_2L1J5_L1TE90;
      vector<int>     *trig_EF_jet_EF_2j10_a4hi_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j10_a4hi_EFFS_L1TE100;
      vector<int>     *trig_EF_jet_EF_2j10_a4hi_EFFS_L1TE90;
      vector<int>     *trig_EF_jet_EF_2j10_a4hi_deta40_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j10_a4hi_eta50_deta40;
      vector<int>     *trig_EF_jet_EF_2j10_a4hi_eta50_deta40_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j10_a4tcem_EFFS_2L1J5;
      vector<int>     *trig_EF_jet_EF_2j10_a4tcem_deta40;
      vector<int>     *trig_EF_jet_EF_2j10_a4tcem_eta50_deta40;
      vector<int>     *trig_EF_jet_EF_2j10_a4tchad_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j10_a4tchad_deta40_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j10_a4tchad_eta50_deta40_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j15_a4hi_EFFS_2L1J5;
      vector<int>     *trig_EF_jet_EF_2j15_a4hi_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j15_a4hi_deta40_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j15_a4hi_eta50_deta40;
      vector<int>     *trig_EF_jet_EF_2j15_a4hi_eta50_deta40_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j15_a4tcem_EFFS_2L1J5;
      vector<int>     *trig_EF_jet_EF_2j15_a4tcem_deta40;
      vector<int>     *trig_EF_jet_EF_2j15_a4tcem_eta50_deta40;
      vector<int>     *trig_EF_jet_EF_2j15_a4tchad_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j15_a4tchad_deta40_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j15_a4tchad_eta50_deta40_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j20_a4hi_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j20_a4tchad_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j7_a4hi_EFFS_2L1J5;
      vector<int>     *trig_EF_jet_EF_2j7_a4hi_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j7_a4hi_deta40_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j7_a4hi_eta50_deta40;
      vector<int>     *trig_EF_jet_EF_2j7_a4hi_eta50_deta40_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j7_a4tcem_EFFS_2L1J5;
      vector<int>     *trig_EF_jet_EF_2j7_a4tcem_deta40;
      vector<int>     *trig_EF_jet_EF_2j7_a4tcem_eta50_deta40;
      vector<int>     *trig_EF_jet_EF_2j7_a4tchad_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j7_a4tchad_deta40_L1MBTS;
      vector<int>     *trig_EF_jet_EF_2j7_a4tchad_eta50_deta40_L1MBTS;
      vector<int>     *trig_EF_jet_EF_fj10_a4hi_EFFS_L1FJ0;
      vector<int>     *trig_EF_jet_EF_fj10_a4tchad_EFFS_L1FJ0;
      vector<int>     *trig_EF_jet_EF_fj15_a4hi_EFFS_L1FJ0;
      vector<int>     *trig_EF_jet_EF_fj15_a4tchad_EFFS_L1FJ0;
      vector<int>     *trig_EF_jet_EF_fj7_a4hi_EFFS_L1FJ0;
      vector<int>     *trig_EF_jet_EF_fj7_a4hi_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_fj7_a4tchad_EFFS_L1FJ0;
      vector<int>     *trig_EF_jet_EF_fj7_a4tchad_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_j10_a4hi_EFFS_L1EM3;
      vector<int>     *trig_EF_jet_EF_j10_a4hi_EFFS_L1J5;
      vector<int>     *trig_EF_jet_EF_j10_a4hi_EFFS_L1J5_L1TE90;
      vector<int>     *trig_EF_jet_EF_j10_a4hi_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_j10_a4hi_EFFS_L1TAU3;
      vector<int>     *trig_EF_jet_EF_j10_a4hi_EFFS_L1TE100;
      vector<int>     *trig_EF_jet_EF_j10_a4hi_EFFS_L1TE90;
      vector<int>     *trig_EF_jet_EF_j10_a4tcem_EFFS_L1EM3;
      vector<int>     *trig_EF_jet_EF_j10_a4tcem_EFFS_L1J5;
      vector<int>     *trig_EF_jet_EF_j10_a4tcem_EFFS_L1J5_win6;
      vector<int>     *trig_EF_jet_EF_j10_a4tcem_EFFS_L1TAU3;
      vector<int>     *trig_EF_jet_EF_j10_a4tchad_EFFS_L1J5;
      vector<int>     *trig_EF_jet_EF_j10_a4tchad_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_j10_u0uchad_LArNoiseBurst;
      vector<int>     *trig_EF_jet_EF_j10_u0uchad_empty_LArNoiseBurst;
      vector<int>     *trig_EF_jet_EF_j10_u0uchad_firstempty_LArNoiseBurst;
      vector<int>     *trig_EF_jet_EF_j15_a2tcem_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j15_a2tcem_EFFS_L1J5;
      vector<int>     *trig_EF_jet_EF_j15_a4hi_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j15_a4hi_EFFS_L1J5;
      vector<int>     *trig_EF_jet_EF_j15_a4hi_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_j15_a4tcem_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j15_a4tcem_EFFS_L1J5;
      vector<int>     *trig_EF_jet_EF_j15_a4tchad_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_j20_a4hi_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j20_a4hi_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_j20_a4tcem_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j20_a4tcem_EFFS_L1J5;
      vector<int>     *trig_EF_jet_EF_j20_a4tchad_EFFS_L1J5;
      vector<int>     *trig_EF_jet_EF_j20_a4tchad_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_j25_a4hi_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j25_a4tcem_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j30_a4hi_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j30_a4hi_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_j30_a4tcem_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j30_a4tcem_EFFS_L1J5;
      vector<int>     *trig_EF_jet_EF_j30_a4tchad_EFFS_L1J5;
      vector<int>     *trig_EF_jet_EF_j30_a4tchad_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_j30_u0uchad_empty_LArNoiseBurst;
      vector<int>     *trig_EF_jet_EF_j35_a4hi_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j35_a4tcem_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j40_a4hi_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j40_a4hi_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_j40_a4tcem_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j40_a4tcem_EFFS_L1J5;
      vector<int>     *trig_EF_jet_EF_j40_a4tchad_EFFS_L1J5;
      vector<int>     *trig_EF_jet_EF_j40_a4tchad_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_j45_a4hi_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j45_a4tcem_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j50_a4hi_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j50_a4hi_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_j50_a4tcem_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j50_a4tcem_EFFS_L1J15;
      vector<int>     *trig_EF_jet_EF_j50_a4tchad_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j50_a4tchad_EFFS_L1J15;
      vector<int>     *trig_EF_jet_EF_j50_a4tchad_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_j60_a4tcem_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j60_a4tcem_EFFS_L1J15;
      vector<int>     *trig_EF_jet_EF_j60_a4tchad_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j60_a4tchad_EFFS_L1J15;
      vector<int>     *trig_EF_jet_EF_j75_a4hi_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j75_a4tcem_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j75_a4tcem_EFFS_L1J15;
      vector<int>     *trig_EF_jet_EF_j75_a4tchad_EFFS_L1J10;
      vector<int>     *trig_EF_jet_EF_j75_a4tchad_EFFS_L1J15;
      vector<int>     *trig_EF_jet_EF_j7_a4hi_EFFS_L1EM3;
      vector<int>     *trig_EF_jet_EF_j7_a4hi_EFFS_L1J5;
      vector<int>     *trig_EF_jet_EF_j7_a4hi_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_j7_a4hi_EFFS_L1TAU3;
      vector<int>     *trig_EF_jet_EF_j7_a4tcem_EFFS_L1EM3;
      vector<int>     *trig_EF_jet_EF_j7_a4tcem_EFFS_L1J5;
      vector<int>     *trig_EF_jet_EF_j7_a4tcem_EFFS_L1J5_win6;
      vector<int>     *trig_EF_jet_EF_j7_a4tcem_EFFS_L1TAU3;
      vector<int>     *trig_EF_jet_EF_j7_a4tchad_EFFS_L1J5;
      vector<int>     *trig_EF_jet_EF_j7_a4tchad_EFFS_L1MBTS;
      vector<int>     *trig_EF_jet_EF_j80_a4tchad_EFFS_L1J15;
      vector<int>     *trig_EF_jet_EF_j90_a4tchad_EFFS_L1J15;
      vector<string>  *trig_L1_esum_thrNames;
      Float_t         trig_L1_esum_ExMiss;
      Float_t         trig_L1_esum_EyMiss;
      Float_t         trig_L1_esum_energyT;
      Bool_t          trig_L1_esum_overflowX;
      Bool_t          trig_L1_esum_overflowY;
      Bool_t          trig_L1_esum_overflowT;
      UInt_t          trig_L1_esum_RoIWord0;
      UInt_t          trig_L1_esum_RoIWord1;
      UInt_t          trig_L1_esum_RoIWord2;
      Float_t         trig_EF_met_MEx;
      Float_t         trig_EF_met_MEy;
      Float_t         trig_EF_met_MEz;
      Float_t         trig_EF_met_sumEt;
      Float_t         trig_EF_met_sumE;
      Int_t           trig_EF_met_flag;
      vector<string>  *trig_EF_met_nameOfComponent;
      vector<float>   *trig_EF_met_MExComponent;
      vector<float>   *trig_EF_met_MEyComponent;
      vector<float>   *trig_EF_met_MEzComponent;
      vector<float>   *trig_EF_met_sumEtComponent;
      vector<float>   *trig_EF_met_sumEComponent;
      vector<float>   *trig_EF_met_componentCalib0;
      vector<float>   *trig_EF_met_componentCalib1;
      vector<short>   *trig_EF_met_sumOfSigns;
      vector<unsigned short> *trig_EF_met_usedChannels;
      vector<short>   *trig_EF_met_status;
      Int_t           trig_EF_ph_n;
      vector<float>   *trig_EF_ph_E;
      vector<float>   *trig_EF_ph_Et;
      vector<float>   *trig_EF_ph_pt;
      vector<float>   *trig_EF_ph_m;
      vector<float>   *trig_EF_ph_eta;
      vector<float>   *trig_EF_ph_phi;
      vector<float>   *trig_EF_ph_px;
      vector<float>   *trig_EF_ph_py;
      vector<float>   *trig_EF_ph_pz;
      vector<int>     *trig_EF_ph_author;
      vector<int>     *trig_EF_ph_isRecovered;
      vector<unsigned int> *trig_EF_ph_isEM;
      vector<unsigned int> *trig_EF_ph_isEMLoose;
      vector<unsigned int> *trig_EF_ph_isEMMedium;
      vector<unsigned int> *trig_EF_ph_isEMTight;
      vector<int>     *trig_EF_ph_convFlag;
      vector<int>     *trig_EF_ph_isConv;
      vector<int>     *trig_EF_ph_nConv;
      vector<int>     *trig_EF_ph_nSingleTrackConv;
      vector<int>     *trig_EF_ph_nDoubleTrackConv;
      vector<int>     *trig_EF_ph_loose;
      vector<int>     *trig_EF_ph_looseIso;
      vector<int>     *trig_EF_ph_tight;
      vector<int>     *trig_EF_ph_tightIso;
      vector<int>     *trig_EF_ph_looseAR;
      vector<int>     *trig_EF_ph_looseARIso;
      vector<int>     *trig_EF_ph_tightAR;
      vector<int>     *trig_EF_ph_tightARIso;
      vector<float>   *trig_EF_ph_Ethad;
      vector<float>   *trig_EF_ph_Ethad1;
      vector<float>   *trig_EF_ph_E033;
      vector<float>   *trig_EF_ph_f1;
      vector<float>   *trig_EF_ph_f1core;
      vector<float>   *trig_EF_ph_Emins1;
      vector<float>   *trig_EF_ph_fside;
      vector<float>   *trig_EF_ph_Emax2;
      vector<float>   *trig_EF_ph_ws3;
      vector<float>   *trig_EF_ph_wstot;
      vector<float>   *trig_EF_ph_E132;
      vector<float>   *trig_EF_ph_E1152;
      vector<float>   *trig_EF_ph_emaxs1;
      vector<float>   *trig_EF_ph_deltaEs;
      vector<float>   *trig_EF_ph_E233;
      vector<float>   *trig_EF_ph_E237;
      vector<float>   *trig_EF_ph_E277;
      vector<float>   *trig_EF_ph_weta2;
      vector<float>   *trig_EF_ph_f3;
      vector<float>   *trig_EF_ph_f3core;
      vector<float>   *trig_EF_ph_rphiallcalo;
      vector<float>   *trig_EF_ph_Etcone45;
      vector<float>   *trig_EF_ph_Etcone15;
      vector<float>   *trig_EF_ph_Etcone20;
      vector<float>   *trig_EF_ph_Etcone25;
      vector<float>   *trig_EF_ph_Etcone30;
      vector<float>   *trig_EF_ph_Etcone35;
      vector<float>   *trig_EF_ph_Etcone40;
      vector<float>   *trig_EF_ph_ptcone20;
      vector<float>   *trig_EF_ph_ptcone30;
      vector<float>   *trig_EF_ph_ptcone40;
      vector<float>   *trig_EF_ph_convanglematch;
      vector<float>   *trig_EF_ph_convtrackmatch;
      vector<int>     *trig_EF_ph_hasconv;
      vector<float>   *trig_EF_ph_convvtxx;
      vector<float>   *trig_EF_ph_convvtxy;
      vector<float>   *trig_EF_ph_convvtxz;
      vector<float>   *trig_EF_ph_Rconv;
      vector<float>   *trig_EF_ph_zconv;
      vector<float>   *trig_EF_ph_convvtxchi2;
      vector<float>   *trig_EF_ph_pt1conv;
      vector<int>     *trig_EF_ph_convtrk1nBLHits;
      vector<int>     *trig_EF_ph_convtrk1nPixHits;
      vector<int>     *trig_EF_ph_convtrk1nSCTHits;
      vector<int>     *trig_EF_ph_convtrk1nTRTHits;
      vector<float>   *trig_EF_ph_pt2conv;
      vector<int>     *trig_EF_ph_convtrk2nBLHits;
      vector<int>     *trig_EF_ph_convtrk2nPixHits;
      vector<int>     *trig_EF_ph_convtrk2nSCTHits;
      vector<int>     *trig_EF_ph_convtrk2nTRTHits;
      vector<float>   *trig_EF_ph_ptconv;
      vector<float>   *trig_EF_ph_pzconv;
      vector<float>   *trig_EF_ph_reta;
      vector<float>   *trig_EF_ph_rphi;
      vector<float>   *trig_EF_ph_cl_E;
      vector<float>   *trig_EF_ph_cl_pt;
      vector<float>   *trig_EF_ph_cl_eta;
      vector<float>   *trig_EF_ph_cl_phi;
      vector<float>   *trig_EF_ph_cl_etas2;
      Int_t           trig_EF_el_n;
      vector<float>   *trig_EF_el_E;
      vector<float>   *trig_EF_el_Et;
      vector<float>   *trig_EF_el_pt;
      vector<float>   *trig_EF_el_m;
      vector<float>   *trig_EF_el_eta;
      vector<float>   *trig_EF_el_phi;
      vector<float>   *trig_EF_el_px;
      vector<float>   *trig_EF_el_py;
      vector<float>   *trig_EF_el_pz;
      vector<float>   *trig_EF_el_charge;
      vector<int>     *trig_EF_el_author;
      vector<unsigned int> *trig_EF_el_isEM;
      vector<unsigned int> *trig_EF_el_isEMLoose;
      vector<unsigned int> *trig_EF_el_isEMMedium;
      vector<unsigned int> *trig_EF_el_isEMTight;
      vector<int>     *trig_EF_el_loose;
      vector<int>     *trig_EF_el_looseIso;
      vector<int>     *trig_EF_el_medium;
      vector<int>     *trig_EF_el_mediumIso;
      vector<int>     *trig_EF_el_mediumWithoutTrack;
      vector<int>     *trig_EF_el_mediumIsoWithoutTrack;
      vector<int>     *trig_EF_el_tight;
      vector<int>     *trig_EF_el_tightIso;
      vector<int>     *trig_EF_el_tightWithoutTrack;
      vector<int>     *trig_EF_el_tightIsoWithoutTrack;
      vector<int>     *trig_EF_el_loosePP;
      vector<int>     *trig_EF_el_loosePPIso;
      vector<int>     *trig_EF_el_mediumPP;
      vector<int>     *trig_EF_el_mediumPPIso;
      vector<int>     *trig_EF_el_tightPP;
      vector<int>     *trig_EF_el_tightPPIso;
      vector<float>   *trig_EF_el_Ethad;
      vector<float>   *trig_EF_el_Ethad1;
      vector<float>   *trig_EF_el_f1;
      vector<float>   *trig_EF_el_f1core;
      vector<float>   *trig_EF_el_Emins1;
      vector<float>   *trig_EF_el_fside;
      vector<float>   *trig_EF_el_Emax2;
      vector<float>   *trig_EF_el_ws3;
      vector<float>   *trig_EF_el_wstot;
      vector<float>   *trig_EF_el_emaxs1;
      vector<float>   *trig_EF_el_deltaEs;
      vector<float>   *trig_EF_el_E233;
      vector<float>   *trig_EF_el_E237;
      vector<float>   *trig_EF_el_E277;
      vector<float>   *trig_EF_el_weta2;
      vector<float>   *trig_EF_el_f3;
      vector<float>   *trig_EF_el_f3core;
      vector<float>   *trig_EF_el_rphiallcalo;
      vector<float>   *trig_EF_el_Etcone45;
      vector<float>   *trig_EF_el_Etcone15;
      vector<float>   *trig_EF_el_Etcone20;
      vector<float>   *trig_EF_el_Etcone25;
      vector<float>   *trig_EF_el_Etcone30;
      vector<float>   *trig_EF_el_Etcone35;
      vector<float>   *trig_EF_el_Etcone40;
      vector<float>   *trig_EF_el_ptcone20;
      vector<float>   *trig_EF_el_ptcone30;
      vector<float>   *trig_EF_el_ptcone40;
      vector<float>   *trig_EF_el_pos7;
      vector<float>   *trig_EF_el_etacorrmag;
      vector<float>   *trig_EF_el_deltaeta1;
      vector<float>   *trig_EF_el_deltaeta2;
      vector<float>   *trig_EF_el_deltaphi2;
      vector<float>   *trig_EF_el_expectHitInBLayer;
      vector<float>   *trig_EF_el_trackd0_physics;
      vector<float>   *trig_EF_el_reta;
      vector<float>   *trig_EF_el_rphi;
      vector<float>   *trig_EF_el_EtringnoisedR03sig2;
      vector<float>   *trig_EF_el_EtringnoisedR03sig3;
      vector<float>   *trig_EF_el_EtringnoisedR03sig4;
      vector<double>  *trig_EF_el_isolationlikelihoodjets;
      vector<double>  *trig_EF_el_isolationlikelihoodhqelectrons;
      vector<double>  *trig_EF_el_electronweight;
      vector<double>  *trig_EF_el_electronbgweight;
      vector<double>  *trig_EF_el_softeweight;
      vector<double>  *trig_EF_el_softebgweight;
      vector<double>  *trig_EF_el_neuralnet;
      vector<double>  *trig_EF_el_Hmatrix;
      vector<double>  *trig_EF_el_Hmatrix5;
      vector<double>  *trig_EF_el_adaboost;
      vector<double>  *trig_EF_el_softeneuralnet;
      vector<float>   *trig_EF_el_zvertex;
      vector<float>   *trig_EF_el_errz;
      vector<float>   *trig_EF_el_etap;
      vector<float>   *trig_EF_el_depth;
      vector<float>   *trig_EF_el_Es0;
      vector<float>   *trig_EF_el_etas0;
      vector<float>   *trig_EF_el_phis0;
      vector<float>   *trig_EF_el_Es1;
      vector<float>   *trig_EF_el_etas1;
      vector<float>   *trig_EF_el_phis1;
      vector<float>   *trig_EF_el_Es2;
      vector<float>   *trig_EF_el_etas2;
      vector<float>   *trig_EF_el_phis2;
      vector<float>   *trig_EF_el_Es3;
      vector<float>   *trig_EF_el_etas3;
      vector<float>   *trig_EF_el_phis3;
      vector<float>   *trig_EF_el_cl_E;
      vector<float>   *trig_EF_el_cl_pt;
      vector<float>   *trig_EF_el_cl_eta;
      vector<float>   *trig_EF_el_cl_phi;
      vector<float>   *trig_EF_el_trackd0;
      vector<float>   *trig_EF_el_trackz0;
      vector<float>   *trig_EF_el_trackphi;
      vector<float>   *trig_EF_el_tracktheta;
      vector<float>   *trig_EF_el_trackqoverp;
      vector<float>   *trig_EF_el_trackpt;
      vector<float>   *trig_EF_el_tracketa;
      vector<float>   *trig_EF_el_trackfitchi2;
      vector<int>     *trig_EF_el_trackfitndof;
      vector<int>     *trig_EF_el_nBLHits;
      vector<int>     *trig_EF_el_nPixHits;
      vector<int>     *trig_EF_el_nSCTHits;
      vector<int>     *trig_EF_el_nTRTHits;
      vector<int>     *trig_EF_el_nTRTHighTHits;
      vector<int>     *trig_EF_el_nTRTXenonHits;
      vector<int>     *trig_EF_el_nPixHoles;
      vector<int>     *trig_EF_el_nSCTHoles;
      vector<int>     *trig_EF_el_nTRTHoles;
      vector<int>     *trig_EF_el_nPixelDeadSensors;
      vector<int>     *trig_EF_el_nSCTDeadSensors;
      vector<int>     *trig_EF_el_nBLSharedHits;
      vector<int>     *trig_EF_el_nPixSharedHits;
      vector<int>     *trig_EF_el_nSCTSharedHits;
      vector<int>     *trig_EF_el_nBLayerSplitHits;
      vector<int>     *trig_EF_el_nPixSplitHits;
      vector<int>     *trig_EF_el_nBLayerOutliers;
      vector<int>     *trig_EF_el_nPixelOutliers;
      vector<int>     *trig_EF_el_nSCTOutliers;
      vector<int>     *trig_EF_el_nTRTOutliers;
      vector<int>     *trig_EF_el_nTRTHighTOutliers;
      vector<int>     *trig_EF_el_expectBLayerHit;
      vector<int>     *trig_EF_el_nSiHits;
      vector<float>   *trig_EF_el_TRTHighTHitsRatio;
      vector<float>   *trig_EF_el_TRTHighTOutliersRatio;
      vector<float>   *trig_EF_el_pixeldEdx;
      vector<int>     *trig_EF_el_nGoodHitsPixeldEdx;
      vector<float>   *trig_EF_el_massPixeldEdx;
      vector<vector<float> > *trig_EF_el_likelihoodsPixeldEdx;
      vector<float>   *trig_EF_el_eProbabilityComb;
      vector<float>   *trig_EF_el_eProbabilityHT;
      vector<float>   *trig_EF_el_eProbabilityToT;
      vector<float>   *trig_EF_el_eProbabilityBrem;
      vector<float>   *trig_EF_el_vertweight;
      vector<float>   *trig_EF_el_vertx;
      vector<float>   *trig_EF_el_verty;
      vector<float>   *trig_EF_el_vertz;
      vector<int>     *trig_EF_el_hastrack;
      Int_t           trig_EF_trigmuonef_n;
      vector<int>     *trig_EF_trigmuonef_effs15;
      vector<int>     *trig_EF_trigmuonef_effs18;
      vector<int>     *trig_EF_trigmuonef_effs24;
      vector<int>     *trig_EF_trigmuonef_RoINum;
      vector<int>     *trig_EF_trigmuonef_NSegments;
      vector<int>     *trig_EF_trigmuonef_NMdtHits;
      vector<int>     *trig_EF_trigmuonef_NRpcHits;
      vector<int>     *trig_EF_trigmuonef_NTgcHits;
      vector<int>     *trig_EF_trigmuonef_NCscHits;
      vector<float>   *trig_EF_trigmuonef_EtaPreviousLevel;
      vector<float>   *trig_EF_trigmuonef_PhiPreviousLevel;
      vector<int>     *trig_EF_trigmuonef_track_n;
      vector<vector<int> > *trig_EF_trigmuonef_track_MuonType;
      vector<vector<float> > *trig_EF_trigmuonef_track_MS_pt;
      vector<vector<float> > *trig_EF_trigmuonef_track_MS_eta;
      vector<vector<float> > *trig_EF_trigmuonef_track_MS_phi;
      vector<vector<float> > *trig_EF_trigmuonef_track_MS_charge;
      vector<vector<float> > *trig_EF_trigmuonef_track_MS_d0;
      vector<vector<float> > *trig_EF_trigmuonef_track_MS_z0;
      vector<vector<float> > *trig_EF_trigmuonef_track_MS_chi2;
      vector<vector<float> > *trig_EF_trigmuonef_track_MS_chi2prob;
      vector<vector<float> > *trig_EF_trigmuonef_track_MS_posX;
      vector<vector<float> > *trig_EF_trigmuonef_track_MS_posY;
      vector<vector<float> > *trig_EF_trigmuonef_track_MS_posZ;
      vector<vector<int> > *trig_EF_trigmuonef_track_MS_NRpcHitsPhi;
      vector<vector<int> > *trig_EF_trigmuonef_track_MS_NTgcHitsPhi;
      vector<vector<int> > *trig_EF_trigmuonef_track_MS_NCscHitsPhi;
      vector<vector<int> > *trig_EF_trigmuonef_track_MS_NRpcHitsEta;
      vector<vector<int> > *trig_EF_trigmuonef_track_MS_NTgcHitsEta;
      vector<vector<int> > *trig_EF_trigmuonef_track_MS_NCscHitsEta;
      vector<vector<int> > *trig_EF_trigmuonef_track_MS_NMdtHits;
      vector<vector<int> > *trig_EF_trigmuonef_track_MS_hasMS;
      vector<vector<float> > *trig_EF_trigmuonef_track_SA_pt;
      vector<vector<float> > *trig_EF_trigmuonef_track_SA_eta;
      vector<vector<float> > *trig_EF_trigmuonef_track_SA_phi;
      vector<vector<float> > *trig_EF_trigmuonef_track_SA_charge;
      vector<vector<float> > *trig_EF_trigmuonef_track_SA_d0;
      vector<vector<float> > *trig_EF_trigmuonef_track_SA_z0;
      vector<vector<float> > *trig_EF_trigmuonef_track_SA_chi2;
      vector<vector<float> > *trig_EF_trigmuonef_track_SA_chi2prob;
      vector<vector<float> > *trig_EF_trigmuonef_track_SA_posX;
      vector<vector<float> > *trig_EF_trigmuonef_track_SA_posY;
      vector<vector<float> > *trig_EF_trigmuonef_track_SA_posZ;
      vector<vector<int> > *trig_EF_trigmuonef_track_SA_hasSA;
      vector<vector<float> > *trig_EF_trigmuonef_track_CB_pt;
      vector<vector<float> > *trig_EF_trigmuonef_track_CB_eta;
      vector<vector<float> > *trig_EF_trigmuonef_track_CB_phi;
      vector<vector<float> > *trig_EF_trigmuonef_track_CB_charge;
      vector<vector<float> > *trig_EF_trigmuonef_track_CB_d0;
      vector<vector<float> > *trig_EF_trigmuonef_track_CB_z0;
      vector<vector<float> > *trig_EF_trigmuonef_track_CB_chi2;
      vector<vector<float> > *trig_EF_trigmuonef_track_CB_chi2prob;
      vector<vector<float> > *trig_EF_trigmuonef_track_CB_posX;
      vector<vector<float> > *trig_EF_trigmuonef_track_CB_posY;
      vector<vector<float> > *trig_EF_trigmuonef_track_CB_posZ;
      vector<vector<float> > *trig_EF_trigmuonef_track_CB_matchChi2;
      vector<vector<int> > *trig_EF_trigmuonef_track_CB_NIdSctHits;
      vector<vector<int> > *trig_EF_trigmuonef_track_CB_NIdPixelHits;
      vector<vector<int> > *trig_EF_trigmuonef_track_CB_NTrtHits;
      vector<vector<int> > *trig_EF_trigmuonef_track_CB_hasCB;
      Int_t           bcmRDO_n;
      vector<vector<int> > *bcmRDO_channel;
      vector<int>     *bcmRDO_nhits;
      vector<vector<int> > *bcmRDO_pulse1pos;
      vector<vector<int> > *bcmRDO_pulse1width;
      vector<vector<int> > *bcmRDO_pulse2pos;
      vector<vector<int> > *bcmRDO_pulse2width;
      vector<vector<int> > *bcmRDO_lvl1a;
      vector<vector<int> > *bcmRDO_bcid;
      vector<vector<int> > *bcmRDO_lvl1id;
      UInt_t          ctpRDO_nBC;
      UInt_t          ctpRDO_lvl1aBC;
      UInt_t          ctpRDO_time_s;
      UInt_t          ctpRDO_time_ns;
      vector<unsigned int> *ctpRDO_pit;
      vector<unsigned int> *ctpRDO_tbp;
      vector<unsigned int> *ctpRDO_tap;
      vector<unsigned int> *ctpRDO_tav;
      UInt_t          ctp_decisionTypeWord;
      vector<string>  *ctp_decisionItems;
      vector<unsigned int> *ctp_decisionWords;
      UInt_t          ctp_nDecisionItems;
      UInt_t          mbtsLvl2_nElements;
      vector<float>   *mbtsLvl2_energies;
      UInt_t          mbtsLvl2_ntimes;
      vector<float>   *mbtsLvl2_times;
      UInt_t          lvl2_sp_nElements;
      UInt_t          lvl2_sp_hPixelClusTotBins;
      Float_t         lvl2_sp_hPixelClusTotMin;
      Float_t         lvl2_sp_hPixelClusTotMax;
      UInt_t          lvl2_sp_hPixelClusSizeBins;
      Float_t         lvl2_sp_hPixelClusSizeMin;
      Float_t         lvl2_sp_hPixelClusSizeMax;
      vector<float>   *lvl2_sp_pixelClusEndcapC_contents;
      vector<float>   *lvl2_sp_pixelClusBarrel_contents;
      vector<float>   *lvl2_sp_pixelClusEndcapA_contents;
      vector<unsigned int> *lvl2_sp_droppedPixelModuleIds;
      UInt_t          lvl2_sp_sctSpEndcapC;
      UInt_t          lvl2_sp_sctSpBarrel;
      UInt_t          lvl2_sp_sctSpEndcapA;
      vector<unsigned int> *lvl2_sp_droppedSctModuleIds;
      UInt_t          lvl2_mbTrt_nElements;
      UInt_t          lvl2_mbTrt_hTotBins;
      Float_t         lvl2_mbTrt_hTotMin;
      Float_t         lvl2_mbTrt_hTotMax;
      vector<float>   *lvl2_mbTrt_endcapC_contents;
      vector<float>   *lvl2_mbTrt_barrel_contents;
      vector<float>   *lvl2_mbTrt_endcapA_contents;
      UInt_t          ef_trk_nElements;
      UInt_t          ef_trk_hZ0Bins;
      Float_t         ef_trk_hZ0Min;
      Float_t         ef_trk_hZ0Max;
      UInt_t          ef_trk_hPtBins;
      Float_t         ef_trk_hPtMin;
      Float_t         ef_trk_hPtMax;
      UInt_t          ef_trk_hEtaBins;
      Float_t         ef_trk_hEtaMin;
      Float_t         ef_trk_hEtaMax;
      UInt_t          ef_trk_hPhiBins;
      Float_t         ef_trk_hPhiMin;
      Float_t         ef_trk_hPhiMax;
      vector<float>   *ef_trk_z0_pt_contents;
      vector<float>   *ef_trk_eta_phi_contents;
      Int_t           trig_L2_jet_n;
      vector<float>   *trig_L2_jet_E;
      vector<float>   *trig_L2_jet_eta;
      vector<float>   *trig_L2_jet_phi;
      vector<unsigned int> *trig_L2_jet_RoIWord;
      vector<string>  *trig_L2_jet_InputType;
      vector<string>  *trig_L2_jet_OutputType;
      vector<int>     *trig_L2_jet_counter;
      vector<int>     *trig_L2_jet_c4cchad;
      vector<int>     *trig_L2_jet_c4ccem;
      vector<int>     *trig_L2_jet_c4uchad;
      vector<double>  *trig_L2_jet_ehad0;
      vector<double>  *trig_L2_jet_eem0;
      vector<int>     *trig_L2_jet_nLeadingCells;
      vector<float>   *trig_L2_jet_hecf;
      vector<float>   *trig_L2_jet_jetQuality;
      vector<float>   *trig_L2_jet_emf;
      vector<float>   *trig_L2_jet_jetTimeCells;
      Int_t           vx_n;
      vector<float>   *vx_x;
      vector<float>   *vx_y;
      vector<float>   *vx_z;
      vector<float>   *vx_err_x;
      vector<float>   *vx_err_y;
      vector<float>   *vx_err_z;
      vector<float>   *vx_cov_xy;
      vector<float>   *vx_cov_xz;
      vector<float>   *vx_cov_yz;
      vector<int>     *vx_type;
      vector<float>   *vx_chi2;
      vector<int>     *vx_ndof;
      vector<float>   *vx_px;
      vector<float>   *vx_py;
      vector<float>   *vx_pz;
      vector<float>   *vx_E;
      vector<float>   *vx_m;
      vector<int>     *vx_nTracks;
      vector<float>   *vx_sumPt;
      vector<vector<float> > *vx_trk_weight;
      vector<int>     *vx_trk_n;
      vector<vector<int> > *vx_trk_index;

      // List of branches
      TBranch        *b_RunNumber;   //!
      TBranch        *b_EventNumber;   //!
      TBranch        *b_timestamp;   //!
      TBranch        *b_timestamp_ns;   //!
      TBranch        *b_lbn;   //!
      TBranch        *b_bcid;   //!
      TBranch        *b_detmask0;   //!
      TBranch        *b_detmask1;   //!
      TBranch        *b_actualIntPerXing;   //!
      TBranch        *b_averageIntPerXing;   //!
      TBranch        *b_pixelFlags;   //!
      TBranch        *b_sctFlags;   //!
      TBranch        *b_trtFlags;   //!
      TBranch        *b_larFlags;   //!
      TBranch        *b_tileFlags;   //!
      TBranch        *b_muonFlags;   //!
      TBranch        *b_fwdFlags;   //!
      TBranch        *b_coreFlags;   //!
      TBranch        *b_pixelError;   //!
      TBranch        *b_sctError;   //!
      TBranch        *b_trtError;   //!
      TBranch        *b_larError;   //!
      TBranch        *b_tileError;   //!
      TBranch        *b_muonError;   //!
      TBranch        *b_fwdError;   //!
      TBranch        *b_coreError;   //!
      TBranch        *b_streamDecision_Egamma;   //!
      TBranch        *b_streamDecision_Muons;   //!
      TBranch        *b_streamDecision_JetTauEtmiss;   //!
      TBranch        *b_l1id;   //!
      TBranch        *b_isSimulation;   //!
      TBranch        *b_isCalibration;   //!
      TBranch        *b_isTestBeam;   //!
      TBranch        *b_mb_n;   //!
      TBranch        *b_mb_E;   //!
      TBranch        *b_mb_eta;   //!
      TBranch        *b_mb_phi;   //!
      TBranch        *b_mb_time;   //!
      TBranch        *b_mb_quality;   //!
      TBranch        *b_mb_type;   //!
      TBranch        *b_mb_module;   //!
      TBranch        *b_mb_channel;   //!
      TBranch        *b_mbtime_timeDiff;   //!
      TBranch        *b_mbtime_timeA;   //!
      TBranch        *b_mbtime_timeC;   //!
      TBranch        *b_mbtime_countA;   //!
      TBranch        *b_mbtime_countC;   //!
      TBranch        *b_lucidRaw_word0;   //!
      TBranch        *b_lucidRaw_word1;   //!
      TBranch        *b_lucidRaw_word2;   //!
      TBranch        *b_lucidRaw_word3;   //!
      TBranch        *b_lucidRaw_word0p;   //!
      TBranch        *b_lucidRaw_word1p;   //!
      TBranch        *b_lucidRaw_word2p;   //!
      TBranch        *b_lucidRaw_word3p;   //!
      TBranch        *b_lucidRaw_word0n;   //!
      TBranch        *b_lucidRaw_word1n;   //!
      TBranch        *b_lucidRaw_word2n;   //!
      TBranch        *b_lucidRaw_word3n;   //!
      TBranch        *b_lucidRaw_status;   //!
      TBranch        *b_lucidRaw_totalHits;   //!
      TBranch        *b_lucidRaw_ASideHits;   //!
      TBranch        *b_lucidRaw_CSideHits;   //!
      TBranch        *b_Zdc_n;   //!
      TBranch        *b_Zdc_Energy_Vec;   //!
      TBranch        *b_Zdc_Time_Vec;   //!
      TBranch        *b_Zdc_Vec_Size;   //!
      TBranch        *b_Zdc_Energy_LG;   //!
      TBranch        *b_Zdc_Time_LG;   //!
      TBranch        *b_Zdc_Energy_HG;   //!
      TBranch        *b_Zdc_Time_HG;   //!
      TBranch        *b_Zdc_Id;   //!
      TBranch        *b_Zdc_Side;   //!
      TBranch        *b_Zdc_Type;   //!
      TBranch        *b_Zdc_Module;   //!
      TBranch        *b_Zdc_Channel;   //!
      TBranch        *b_Zdc_TimeCalib;   //!
      TBranch        *b_Zdc_RecMethod;   //!
      TBranch        *b_ZdcDigits_n;   //!
      TBranch        *b_ZdcDigits_dig_g0d0;   //!
      TBranch        *b_ZdcDigits_dig_g0d1;   //!
      TBranch        *b_ZdcDigits_dig_g1d0;   //!
      TBranch        *b_ZdcDigits_dig_g1d1;   //!
      TBranch        *b_ZdcDigits_Id;   //!
      TBranch        *b_ZdcDigits_Side;   //!
      TBranch        *b_ZdcDigits_Type;   //!
      TBranch        *b_ZdcDigits_Module;   //!
      TBranch        *b_ZdcDigits_Channel;   //!
      TBranch        *b_ZdcReco_ESumA;   //!
      TBranch        *b_ZdcReco_ESumC;   //!
      TBranch        *b_ZdcReco_EA;   //!
      TBranch        *b_ZdcReco_EC;   //!
      TBranch        *b_ZdcReco_qA;   //!
      TBranch        *b_ZdcReco_qC;   //!
      TBranch        *b_ZdcReco_ESumA_LG;   //!
      TBranch        *b_ZdcReco_ESumA_HG;   //!
      TBranch        *b_ZdcReco_ESumC_LG;   //!
      TBranch        *b_ZdcReco_ESumC_HG;   //!
      TBranch        *b_alfa_DCS_BLM;   //!
      TBranch        *b_cc_fcal_n;   //!
      TBranch        *b_cc_fcal_E;   //!
      TBranch        *b_cc_fcal_pt;   //!
      TBranch        *b_cc_fcal_eta;   //!
      TBranch        *b_cc_fcal_phi;   //!
      TBranch        *b_cc_fcal_QCells;   //!
      TBranch        *b_cc_fcal_GainCells;   //!
      TBranch        *b_cc_fcal_DetCells;   //!
      TBranch        *b_cc_fcal_TimeCells;   //!
      TBranch        *b_cc_fcal_xCells;   //!
      TBranch        *b_cc_fcal_yCells;   //!
      TBranch        *b_cc_fcal_zCells;   //!
      TBranch        *b_cc_fcal_BadCells;   //!
      TBranch        *b_cc_fcal_IdCells;   //!
      TBranch        *b_cc_fcal_Sigma;   //!
			
      //TBranch        *b_TotalEt_n;   //!
      TBranch        *b_TotalEt_layer_eta;   //!
      //TBranch        *b_TotalEt_layer_phi;   //!
      TBranch        *b_TotalEt_layer_towerEt;   //!
      TBranch        *b_TotalEt_layer_sampling;   //!
      //TBranch        *b_TotalEt_layer_sampling_calib;   //!
			
      TBranch        *b_ccc_Nh_Calo;   //!
      TBranch        *b_ccc_Eh_Calo;   //!
      TBranch        *b_ccc_Nh_EM;   //!
      TBranch        *b_ccc_Eh_EM;   //!
      TBranch        *b_ccc_Nh_HAD;   //!
      TBranch        *b_ccc_Eh_HAD;   //!
      TBranch        *b_ccc_Nh_PresB;   //!
      TBranch        *b_ccc_Eh_PresB;   //!
      TBranch        *b_ccc_Nh_EMB;   //!
      TBranch        *b_ccc_Eh_EMB;   //!
      TBranch        *b_ccc_Nh_EMEC;   //!
      TBranch        *b_ccc_Eh_EMEC;   //!
      TBranch        *b_ccc_Nh_Tile;   //!
      TBranch        *b_ccc_Eh_Tile;   //!
      TBranch        *b_ccc_Nh_TileGap;   //!
      TBranch        *b_ccc_Eh_TileGap;   //!
      TBranch        *b_ccc_Nh_HEC;   //!
      TBranch        *b_ccc_Eh_HEC;   //!
      TBranch        *b_ccc_Nh_FCal;   //!
      TBranch        *b_ccc_Eh_FCal;   //!
      TBranch        *b_ccc_Nh_PresE;   //!
      TBranch        *b_ccc_Eh_PresE;   //!
      TBranch        *b_ccc_Nh_Scint;   //!
      TBranch        *b_ccc_Eh_Scint;   //!
      TBranch        *b_cccEt_Et_Nh_Calo;   //!
      TBranch        *b_cccEt_Et_Eh_Calo;   //!
      TBranch        *b_cccEt_Et_Nh_EM;   //!
      TBranch        *b_cccEt_Et_Eh_EM;   //!
      TBranch        *b_cccEt_Et_Nh_HAD;   //!
      TBranch        *b_cccEt_Et_Eh_HAD;   //!
      TBranch        *b_cccEt_Et_Nh_PresB;   //!
      TBranch        *b_cccEt_Et_Eh_PresB;   //!
      TBranch        *b_cccEt_Et_Nh_EMB;   //!
      TBranch        *b_cccEt_Et_Eh_EMB;   //!
      TBranch        *b_cccEt_Et_Nh_EMEC;   //!
      TBranch        *b_cccEt_Et_Eh_EMEC;   //!
      TBranch        *b_cccEt_Et_Nh_Tile;   //!
      TBranch        *b_cccEt_Et_Eh_Tile;   //!
      TBranch        *b_cccEt_Et_Nh_TileGap;   //!
      TBranch        *b_cccEt_Et_Eh_TileGap;   //!
      TBranch        *b_cccEt_Et_Nh_HEC;   //!
      TBranch        *b_cccEt_Et_Eh_HEC;   //!
      TBranch        *b_cccEt_Et_Nh_FCal;   //!
      TBranch        *b_cccEt_Et_Eh_FCal;   //!
      TBranch        *b_cccEt_Et_Nh_PresE;   //!
      TBranch        *b_cccEt_Et_Eh_PresE;   //!
      TBranch        *b_cccEt_Et_Nh_Scint;   //!
      TBranch        *b_cccEt_Et_Eh_Scint;   //!
      TBranch        *b_cccEt_p_Nh_Calo;   //!
      TBranch        *b_cccEt_p_Eh_Calo;   //!
      TBranch        *b_cccEt_p_Nh_EM;   //!
      TBranch        *b_cccEt_p_Eh_EM;   //!
      TBranch        *b_cccEt_p_Nh_HAD;   //!
      TBranch        *b_cccEt_p_Eh_HAD;   //!
      TBranch        *b_cccEt_p_Nh_PresB;   //!
      TBranch        *b_cccEt_p_Eh_PresB;   //!
      TBranch        *b_cccEt_p_Nh_EMB;   //!
      TBranch        *b_cccEt_p_Eh_EMB;   //!
      TBranch        *b_cccEt_p_Nh_EMEC;   //!
      TBranch        *b_cccEt_p_Eh_EMEC;   //!
      TBranch        *b_cccEt_p_Nh_Tile;   //!
      TBranch        *b_cccEt_p_Eh_Tile;   //!
      TBranch        *b_cccEt_p_Nh_TileGap;   //!
      TBranch        *b_cccEt_p_Eh_TileGap;   //!
      TBranch        *b_cccEt_p_Nh_HEC;   //!
      TBranch        *b_cccEt_p_Eh_HEC;   //!
      TBranch        *b_cccEt_p_Nh_FCal;   //!
      TBranch        *b_cccEt_p_Eh_FCal;   //!
      TBranch        *b_cccEt_p_Nh_PresE;   //!
      TBranch        *b_cccEt_p_Eh_PresE;   //!
      TBranch        *b_cccEt_p_Nh_Scint;   //!
      TBranch        *b_cccEt_p_Eh_Scint;   //!
      TBranch        *b_cccEt_n_Nh_Calo;   //!
      TBranch        *b_cccEt_n_Eh_Calo;   //!
      TBranch        *b_cccEt_n_Nh_EM;   //!
      TBranch        *b_cccEt_n_Eh_EM;   //!
      TBranch        *b_cccEt_n_Nh_HAD;   //!
      TBranch        *b_cccEt_n_Eh_HAD;   //!
      TBranch        *b_cccEt_n_Nh_PresB;   //!
      TBranch        *b_cccEt_n_Eh_PresB;   //!
      TBranch        *b_cccEt_n_Nh_EMB;   //!
      TBranch        *b_cccEt_n_Eh_EMB;   //!
      TBranch        *b_cccEt_n_Nh_EMEC;   //!
      TBranch        *b_cccEt_n_Eh_EMEC;   //!
      TBranch        *b_cccEt_n_Nh_Tile;   //!
      TBranch        *b_cccEt_n_Eh_Tile;   //!
      TBranch        *b_cccEt_n_Nh_TileGap;   //!
      TBranch        *b_cccEt_n_Eh_TileGap;   //!
      TBranch        *b_cccEt_n_Nh_HEC;   //!
      TBranch        *b_cccEt_n_Eh_HEC;   //!
      TBranch        *b_cccEt_n_Nh_FCal;   //!
      TBranch        *b_cccEt_n_Eh_FCal;   //!
      TBranch        *b_cccEt_n_Nh_PresE;   //!
      TBranch        *b_cccEt_n_Eh_PresE;   //!
      TBranch        *b_cccEt_n_Nh_Scint;   //!
      TBranch        *b_cccEt_n_Eh_Scint;   //!
      TBranch        *b_lar_ncellA;   //!
      TBranch        *b_lar_ncellC;   //!
      TBranch        *b_lar_energyA;   //!
      TBranch        *b_lar_energyC;   //!
      TBranch        *b_lar_timeA;   //!
      TBranch        *b_lar_timeC;   //!
      TBranch        *b_lar_timeDiff;   //!
      TBranch        *b_trk_n;   //!
      TBranch        *b_trk_d0;   //!
      TBranch        *b_trk_z0;   //!
      TBranch        *b_trk_phi;   //!
      TBranch        *b_trk_theta;   //!
      TBranch        *b_trk_qoverp;   //!
      TBranch        *b_trk_pt;   //!
      TBranch        *b_trk_eta;   //!
      TBranch        *b_trk_err_d0;   //!
      TBranch        *b_trk_err_z0;   //!
      TBranch        *b_trk_err_phi;   //!
      TBranch        *b_trk_err_theta;   //!
      TBranch        *b_trk_err_qoverp;   //!
      TBranch        *b_trk_cov_d0_z0;   //!
      TBranch        *b_trk_cov_d0_phi;   //!
      TBranch        *b_trk_cov_d0_theta;   //!
      TBranch        *b_trk_cov_d0_qoverp;   //!
      TBranch        *b_trk_cov_z0_phi;   //!
      TBranch        *b_trk_cov_z0_theta;   //!
      TBranch        *b_trk_cov_z0_qoverp;   //!
      TBranch        *b_trk_cov_phi_theta;   //!
      TBranch        *b_trk_cov_phi_qoverp;   //!
      TBranch        *b_trk_cov_theta_qoverp;   //!
      TBranch        *b_trk_d0_wrtPV;   //!
      TBranch        *b_trk_z0_wrtPV;   //!
      TBranch        *b_trk_phi_wrtPV;   //!
      TBranch        *b_trk_err_d0_wrtPV;   //!
      TBranch        *b_trk_err_z0_wrtPV;   //!
      TBranch        *b_trk_err_phi_wrtPV;   //!
      TBranch        *b_trk_err_theta_wrtPV;   //!
      TBranch        *b_trk_err_qoverp_wrtPV;   //!
      TBranch        *b_trk_cov_d0_z0_wrtPV;   //!
      TBranch        *b_trk_cov_d0_phi_wrtPV;   //!
      TBranch        *b_trk_cov_d0_theta_wrtPV;   //!
      TBranch        *b_trk_cov_d0_qoverp_wrtPV;   //!
      TBranch        *b_trk_cov_z0_phi_wrtPV;   //!
      TBranch        *b_trk_cov_z0_theta_wrtPV;   //!
      TBranch        *b_trk_cov_z0_qoverp_wrtPV;   //!
      TBranch        *b_trk_cov_phi_theta_wrtPV;   //!
      TBranch        *b_trk_cov_phi_qoverp_wrtPV;   //!
      TBranch        *b_trk_cov_theta_qoverp_wrtPV;   //!
      TBranch        *b_trk_d0_wrtBS;   //!
      TBranch        *b_trk_z0_wrtBS;   //!
      TBranch        *b_trk_phi_wrtBS;   //!
      TBranch        *b_trk_err_d0_wrtBS;   //!
      TBranch        *b_trk_err_z0_wrtBS;   //!
      TBranch        *b_trk_err_phi_wrtBS;   //!
      TBranch        *b_trk_err_theta_wrtBS;   //!
      TBranch        *b_trk_err_qoverp_wrtBS;   //!
      TBranch        *b_trk_cov_d0_z0_wrtBS;   //!
      TBranch        *b_trk_cov_d0_phi_wrtBS;   //!
      TBranch        *b_trk_cov_d0_theta_wrtBS;   //!
      TBranch        *b_trk_cov_d0_qoverp_wrtBS;   //!
      TBranch        *b_trk_cov_z0_phi_wrtBS;   //!
      TBranch        *b_trk_cov_z0_theta_wrtBS;   //!
      TBranch        *b_trk_cov_z0_qoverp_wrtBS;   //!
      TBranch        *b_trk_cov_phi_theta_wrtBS;   //!
      TBranch        *b_trk_cov_phi_qoverp_wrtBS;   //!
      TBranch        *b_trk_cov_theta_qoverp_wrtBS;   //!
      TBranch        *b_trk_d0_wrtBL;   //!
      TBranch        *b_trk_z0_wrtBL;   //!
      TBranch        *b_trk_phi_wrtBL;   //!
      TBranch        *b_trk_d0_err_wrtBL;   //!
      TBranch        *b_trk_z0_err_wrtBL;   //!
      TBranch        *b_trk_phi_err_wrtBL;   //!
      TBranch        *b_trk_theta_err_wrtBL;   //!
      TBranch        *b_trk_qoverp_err_wrtBL;   //!
      TBranch        *b_trk_d0_z0_err_wrtBL;   //!
      TBranch        *b_trk_d0_phi_err_wrtBL;   //!
      TBranch        *b_trk_d0_theta_err_wrtBL;   //!
      TBranch        *b_trk_d0_qoverp_err_wrtBL;   //!
      TBranch        *b_trk_z0_phi_err_wrtBL;   //!
      TBranch        *b_trk_z0_theta_err_wrtBL;   //!
      TBranch        *b_trk_z0_qoverp_err_wrtBL;   //!
      TBranch        *b_trk_phi_theta_err_wrtBL;   //!
      TBranch        *b_trk_phi_qoverp_err_wrtBL;   //!
      TBranch        *b_trk_theta_qoverp_err_wrtBL;   //!
      TBranch        *b_trk_chi2;   //!
      TBranch        *b_trk_ndof;   //!
      TBranch        *b_trk_nBLHits;   //!
      TBranch        *b_trk_nPixHits;   //!
      TBranch        *b_trk_nSCTHits;   //!
      TBranch        *b_trk_nTRTHits;   //!
      TBranch        *b_trk_nTRTHighTHits;   //!
      TBranch        *b_trk_nTRTXenonHits;   //!
      TBranch        *b_trk_nPixHoles;   //!
      TBranch        *b_trk_nSCTHoles;   //!
      TBranch        *b_trk_nTRTHoles;   //!
      TBranch        *b_trk_nPixelDeadSensors;   //!
      TBranch        *b_trk_nSCTDeadSensors;   //!
      TBranch        *b_trk_nBLSharedHits;   //!
      TBranch        *b_trk_nPixSharedHits;   //!
      TBranch        *b_trk_nSCTSharedHits;   //!
      TBranch        *b_trk_nBLayerSplitHits;   //!
      TBranch        *b_trk_nPixSplitHits;   //!
      TBranch        *b_trk_expectBLayerHit;   //!
      TBranch        *b_trk_nMDTHits;   //!
      TBranch        *b_trk_nCSCEtaHits;   //!
      TBranch        *b_trk_nCSCPhiHits;   //!
      TBranch        *b_trk_nRPCEtaHits;   //!
      TBranch        *b_trk_nRPCPhiHits;   //!
      TBranch        *b_trk_nTGCEtaHits;   //!
      TBranch        *b_trk_nTGCPhiHits;   //!
      TBranch        *b_trk_nHits;   //!
      TBranch        *b_trk_nHoles;   //!
      TBranch        *b_trk_hitPattern;   //!
      TBranch        *b_trk_TRTHighTHitsRatio;   //!
      TBranch        *b_trk_TRTHighTOutliersRatio;   //!
      TBranch        *b_trk_pixeldEdx;   //!
      TBranch        *b_trk_nGoodHitsPixeldEdx;   //!
      TBranch        *b_trk_massPixeldEdx;   //!
      TBranch        *b_trk_likelihoodsPixeldEdx;   //!
      TBranch        *b_trk_fitter;   //!
      TBranch        *b_trk_patternReco1;   //!
      TBranch        *b_trk_patternReco2;   //!
      TBranch        *b_trk_trackProperties;   //!
      TBranch        *b_trk_particleHypothesis;   //!
      TBranch        *b_trk_blayerPrediction_x;   //!
      TBranch        *b_trk_blayerPrediction_y;   //!
      TBranch        *b_trk_blayerPrediction_z;   //!
      TBranch        *b_trk_blayerPrediction_locX;   //!
      TBranch        *b_trk_blayerPrediction_locY;   //!
      TBranch        *b_trk_blayerPrediction_err_locX;   //!
      TBranch        *b_trk_blayerPrediction_err_locY;   //!
      TBranch        *b_trk_blayerPrediction_etaDistToEdge;   //!
      TBranch        *b_trk_blayerPrediction_phiDistToEdge;   //!
      TBranch        *b_trk_blayerPrediction_detElementId;   //!
      TBranch        *b_trk_blayerPrediction_row;   //!
      TBranch        *b_trk_blayerPrediction_col;   //!
      TBranch        *b_trk_blayerPrediction_type;   //!
      TBranch        *b_trkPix_n;   //!
      TBranch        *b_trkPix_d0;   //!
      TBranch        *b_trkPix_z0;   //!
      TBranch        *b_trkPix_phi;   //!
      TBranch        *b_trkPix_theta;   //!
      TBranch        *b_trkPix_qoverp;   //!
      TBranch        *b_trkPix_pt;   //!
      TBranch        *b_trkPix_eta;   //!
      TBranch        *b_trkPix_err_d0;   //!
      TBranch        *b_trkPix_err_z0;   //!
      TBranch        *b_trkPix_err_phi;   //!
      TBranch        *b_trkPix_err_theta;   //!
      TBranch        *b_trkPix_err_qoverp;   //!
      TBranch        *b_trkPix_cov_d0_z0;   //!
      TBranch        *b_trkPix_cov_d0_phi;   //!
      TBranch        *b_trkPix_cov_d0_theta;   //!
      TBranch        *b_trkPix_cov_d0_qoverp;   //!
      TBranch        *b_trkPix_cov_z0_phi;   //!
      TBranch        *b_trkPix_cov_z0_theta;   //!
      TBranch        *b_trkPix_cov_z0_qoverp;   //!
      TBranch        *b_trkPix_cov_phi_theta;   //!
      TBranch        *b_trkPix_cov_phi_qoverp;   //!
      TBranch        *b_trkPix_cov_theta_qoverp;   //!
      TBranch        *b_trkPix_d0_wrtPV;   //!
      TBranch        *b_trkPix_z0_wrtPV;   //!
      TBranch        *b_trkPix_phi_wrtPV;   //!
      TBranch        *b_trkPix_err_d0_wrtPV;   //!
      TBranch        *b_trkPix_err_z0_wrtPV;   //!
      TBranch        *b_trkPix_err_phi_wrtPV;   //!
      TBranch        *b_trkPix_err_theta_wrtPV;   //!
      TBranch        *b_trkPix_err_qoverp_wrtPV;   //!
      TBranch        *b_trkPix_cov_d0_z0_wrtPV;   //!
      TBranch        *b_trkPix_cov_d0_phi_wrtPV;   //!
      TBranch        *b_trkPix_cov_d0_theta_wrtPV;   //!
      TBranch        *b_trkPix_cov_d0_qoverp_wrtPV;   //!
      TBranch        *b_trkPix_cov_z0_phi_wrtPV;   //!
      TBranch        *b_trkPix_cov_z0_theta_wrtPV;   //!
      TBranch        *b_trkPix_cov_z0_qoverp_wrtPV;   //!
      TBranch        *b_trkPix_cov_phi_theta_wrtPV;   //!
      TBranch        *b_trkPix_cov_phi_qoverp_wrtPV;   //!
      TBranch        *b_trkPix_cov_theta_qoverp_wrtPV;   //!
      TBranch        *b_trkPix_d0_wrtBS;   //!
      TBranch        *b_trkPix_z0_wrtBS;   //!
      TBranch        *b_trkPix_phi_wrtBS;   //!
      TBranch        *b_trkPix_err_d0_wrtBS;   //!
      TBranch        *b_trkPix_err_z0_wrtBS;   //!
      TBranch        *b_trkPix_err_phi_wrtBS;   //!
      TBranch        *b_trkPix_err_theta_wrtBS;   //!
      TBranch        *b_trkPix_err_qoverp_wrtBS;   //!
      TBranch        *b_trkPix_cov_d0_z0_wrtBS;   //!
      TBranch        *b_trkPix_cov_d0_phi_wrtBS;   //!
      TBranch        *b_trkPix_cov_d0_theta_wrtBS;   //!
      TBranch        *b_trkPix_cov_d0_qoverp_wrtBS;   //!
      TBranch        *b_trkPix_cov_z0_phi_wrtBS;   //!
      TBranch        *b_trkPix_cov_z0_theta_wrtBS;   //!
      TBranch        *b_trkPix_cov_z0_qoverp_wrtBS;   //!
      TBranch        *b_trkPix_cov_phi_theta_wrtBS;   //!
      TBranch        *b_trkPix_cov_phi_qoverp_wrtBS;   //!
      TBranch        *b_trkPix_cov_theta_qoverp_wrtBS;   //!
      TBranch        *b_trkPix_d0_wrtBL;   //!
      TBranch        *b_trkPix_z0_wrtBL;   //!
      TBranch        *b_trkPix_phi_wrtBL;   //!
      TBranch        *b_trkPix_d0_err_wrtBL;   //!
      TBranch        *b_trkPix_z0_err_wrtBL;   //!
      TBranch        *b_trkPix_phi_err_wrtBL;   //!
      TBranch        *b_trkPix_theta_err_wrtBL;   //!
      TBranch        *b_trkPix_qoverp_err_wrtBL;   //!
      TBranch        *b_trkPix_d0_z0_err_wrtBL;   //!
      TBranch        *b_trkPix_d0_phi_err_wrtBL;   //!
      TBranch        *b_trkPix_d0_theta_err_wrtBL;   //!
      TBranch        *b_trkPix_d0_qoverp_err_wrtBL;   //!
      TBranch        *b_trkPix_z0_phi_err_wrtBL;   //!
      TBranch        *b_trkPix_z0_theta_err_wrtBL;   //!
      TBranch        *b_trkPix_z0_qoverp_err_wrtBL;   //!
      TBranch        *b_trkPix_phi_theta_err_wrtBL;   //!
      TBranch        *b_trkPix_phi_qoverp_err_wrtBL;   //!
      TBranch        *b_trkPix_theta_qoverp_err_wrtBL;   //!
      TBranch        *b_trkPix_chi2;   //!
      TBranch        *b_trkPix_ndof;   //!
      TBranch        *b_trkPix_nBLHits;   //!
      TBranch        *b_trkPix_nPixHits;   //!
      TBranch        *b_trkPix_nSCTHits;   //!
      TBranch        *b_trkPix_nTRTHits;   //!
      TBranch        *b_trkPix_nTRTHighTHits;   //!
      TBranch        *b_trkPix_nTRTXenonHits;   //!
      TBranch        *b_trkPix_nPixHoles;   //!
      TBranch        *b_trkPix_nSCTHoles;   //!
      TBranch        *b_trkPix_nTRTHoles;   //!
      TBranch        *b_trkPix_nPixelDeadSensors;   //!
      TBranch        *b_trkPix_nSCTDeadSensors;   //!
      TBranch        *b_trkPix_nBLSharedHits;   //!
      TBranch        *b_trkPix_nPixSharedHits;   //!
      TBranch        *b_trkPix_nSCTSharedHits;   //!
      TBranch        *b_trkPix_nBLayerSplitHits;   //!
      TBranch        *b_trkPix_nPixSplitHits;   //!
      TBranch        *b_trkPix_expectBLayerHit;   //!
      TBranch        *b_trkPix_nMDTHits;   //!
      TBranch        *b_trkPix_nCSCEtaHits;   //!
      TBranch        *b_trkPix_nCSCPhiHits;   //!
      TBranch        *b_trkPix_nRPCEtaHits;   //!
      TBranch        *b_trkPix_nRPCPhiHits;   //!
      TBranch        *b_trkPix_nTGCEtaHits;   //!
      TBranch        *b_trkPix_nTGCPhiHits;   //!
      TBranch        *b_trkPix_nHits;   //!
      TBranch        *b_trkPix_nHoles;   //!
      TBranch        *b_trkPix_hitPattern;   //!
      TBranch        *b_trkPix_TRTHighTHitsRatio;   //!
      TBranch        *b_trkPix_TRTHighTOutliersRatio;   //!
      TBranch        *b_trkPix_pixeldEdx;   //!
      TBranch        *b_trkPix_nGoodHitsPixeldEdx;   //!
      TBranch        *b_trkPix_massPixeldEdx;   //!
      TBranch        *b_trkPix_likelihoodsPixeldEdx;   //!
      TBranch        *b_trkPix_fitter;   //!
      TBranch        *b_trkPix_patternReco1;   //!
      TBranch        *b_trkPix_patternReco2;   //!
      TBranch        *b_trkPix_trackProperties;   //!
      TBranch        *b_trkPix_particleHypothesis;   //!
      TBranch        *b_trkPix_blayerPrediction_x;   //!
      TBranch        *b_trkPix_blayerPrediction_y;   //!
      TBranch        *b_trkPix_blayerPrediction_z;   //!
      TBranch        *b_trkPix_blayerPrediction_locX;   //!
      TBranch        *b_trkPix_blayerPrediction_locY;   //!
      TBranch        *b_trkPix_blayerPrediction_err_locX;   //!
      TBranch        *b_trkPix_blayerPrediction_err_locY;   //!
      TBranch        *b_trkPix_blayerPrediction_etaDistToEdge;   //!
      TBranch        *b_trkPix_blayerPrediction_phiDistToEdge;   //!
      TBranch        *b_trkPix_blayerPrediction_detElementId;   //!
      TBranch        *b_trkPix_blayerPrediction_row;   //!
      TBranch        *b_trkPix_blayerPrediction_col;   //!
      TBranch        *b_trkPix_blayerPrediction_type;   //!
      TBranch        *b_trt_RDO_countRDOhitsInEvent;   //!
      TBranch        *b_trt_RDO_countBarrelhitsInEvent;   //!
      TBranch        *b_trt_RDO_countEndCaphitsInEvent;   //!
      TBranch        *b_trt_RDO_countEndCapAhitsInEvent;   //!
      TBranch        *b_trt_RDO_countEndCapChitsInEvent;   //!
      TBranch        *b_trt_RDO_countdeadstraws;   //!
      TBranch        *b_HIFlow_v1_PsiFCAL0_w;   //!
      TBranch        *b_HIFlow_v1_PsiPFCAL0_w;   //!
      TBranch        *b_HIFlow_v1_PsiNFCAL0_w;   //!
      TBranch        *b_HIFlow_v1_EtInLayer;   //!
      TBranch        *b_HIFlow_v1_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers;   //!
      TBranch        *b_HIFlow_v1_AvgV2fromCalo;   //!
      TBranch        *b_HIFlow_v1_PsiHICaloUtilLayers;   //!
      TBranch        *b_HIFlow_v1_PsiEtHICaloUtilLayers;   //!
      TBranch        *b_HIFlow_v1_PsiPtrack;   //!
      TBranch        *b_HIFlow_v1_PsiNtrack;   //!
      TBranch        *b_HIFlow_v1_v2FCAL0sil;   //!
      TBranch        *b_HIFlow_v1_v2track;   //!
      TBranch        *b_HIFlow_v1_Meanv2_Psi_From_FCAL0CaloCel_IDLayers;   //!
      TBranch        *b_HIFlow_v2_PsiFCAL0_w;   //!
      TBranch        *b_HIFlow_v2_PsiPFCAL0_w;   //!
      TBranch        *b_HIFlow_v2_PsiNFCAL0_w;   //!
      TBranch        *b_HIFlow_v2_EtInLayer;   //!
      TBranch        *b_HIFlow_v2_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers;   //!
      TBranch        *b_HIFlow_v2_AvgV2fromCalo;   //!
      TBranch        *b_HIFlow_v2_PsiHICaloUtilLayers;   //!
      TBranch        *b_HIFlow_v2_PsiEtHICaloUtilLayers;   //!
      TBranch        *b_HIFlow_v2_PsiPtrack;   //!
      TBranch        *b_HIFlow_v2_PsiNtrack;   //!
      TBranch        *b_HIFlow_v2_v2FCAL0sil;   //!
      TBranch        *b_HIFlow_v2_v2track;   //!
      TBranch        *b_HIFlow_v2_Meanv2_Psi_From_FCAL0CaloCel_IDLayers;   //!
      TBranch        *b_HIFlow_v3_PsiFCAL0_w;   //!
      TBranch        *b_HIFlow_v3_PsiPFCAL0_w;   //!
      TBranch        *b_HIFlow_v3_PsiNFCAL0_w;   //!
      TBranch        *b_HIFlow_v3_EtInLayer;   //!
      TBranch        *b_HIFlow_v3_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers;   //!
      TBranch        *b_HIFlow_v3_AvgV2fromCalo;   //!
      TBranch        *b_HIFlow_v3_PsiHICaloUtilLayers;   //!
      TBranch        *b_HIFlow_v3_PsiEtHICaloUtilLayers;   //!
      TBranch        *b_HIFlow_v3_PsiPtrack;   //!
      TBranch        *b_HIFlow_v3_PsiNtrack;   //!
      TBranch        *b_HIFlow_v3_v2FCAL0sil;   //!
      TBranch        *b_HIFlow_v3_v2track;   //!
      TBranch        *b_HIFlow_v3_Meanv2_Psi_From_FCAL0CaloCel_IDLayers;   //!
      TBranch        *b_HIFlow_v4_PsiFCAL0_w;   //!
      TBranch        *b_HIFlow_v4_PsiPFCAL0_w;   //!
      TBranch        *b_HIFlow_v4_PsiNFCAL0_w;   //!
      TBranch        *b_HIFlow_v4_EtInLayer;   //!
      TBranch        *b_HIFlow_v4_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers;   //!
      TBranch        *b_HIFlow_v4_AvgV2fromCalo;   //!
      TBranch        *b_HIFlow_v4_PsiHICaloUtilLayers;   //!
      TBranch        *b_HIFlow_v4_PsiEtHICaloUtilLayers;   //!
      TBranch        *b_HIFlow_v4_PsiPtrack;   //!
      TBranch        *b_HIFlow_v4_PsiNtrack;   //!
      TBranch        *b_HIFlow_v4_v2FCAL0sil;   //!
      TBranch        *b_HIFlow_v4_v2track;   //!
      TBranch        *b_HIFlow_v4_Meanv2_Psi_From_FCAL0CaloCel_IDLayers;   //!
      TBranch        *b_HIFlow_v5_PsiFCAL0_w;   //!
      TBranch        *b_HIFlow_v5_PsiPFCAL0_w;   //!
      TBranch        *b_HIFlow_v5_PsiNFCAL0_w;   //!
      TBranch        *b_HIFlow_v5_EtInLayer;   //!
      TBranch        *b_HIFlow_v5_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers;   //!
      TBranch        *b_HIFlow_v5_AvgV2fromCalo;   //!
      TBranch        *b_HIFlow_v5_PsiHICaloUtilLayers;   //!
      TBranch        *b_HIFlow_v5_PsiEtHICaloUtilLayers;   //!
      TBranch        *b_HIFlow_v5_PsiPtrack;   //!
      TBranch        *b_HIFlow_v5_PsiNtrack;   //!
      TBranch        *b_HIFlow_v5_v2FCAL0sil;   //!
      TBranch        *b_HIFlow_v5_v2track;   //!
      TBranch        *b_HIFlow_v5_Meanv2_Psi_From_FCAL0CaloCel_IDLayers;   //!
      TBranch        *b_HIFlow_v6_PsiFCAL0_w;   //!
      TBranch        *b_HIFlow_v6_PsiPFCAL0_w;   //!
      TBranch        *b_HIFlow_v6_PsiNFCAL0_w;   //!
      TBranch        *b_HIFlow_v6_EtInLayer;   //!
      TBranch        *b_HIFlow_v6_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers;   //!
      TBranch        *b_HIFlow_v6_AvgV2fromCalo;   //!
      TBranch        *b_HIFlow_v6_PsiHICaloUtilLayers;   //!
      TBranch        *b_HIFlow_v6_PsiEtHICaloUtilLayers;   //!
      TBranch        *b_HIFlow_v6_PsiPtrack;   //!
      TBranch        *b_HIFlow_v6_PsiNtrack;   //!
      TBranch        *b_HIFlow_v6_v2FCAL0sil;   //!
      TBranch        *b_HIFlow_v6_v2track;   //!
      TBranch        *b_HIFlow_v6_Meanv2_Psi_From_FCAL0CaloCel_IDLayers;   //!
      TBranch        *b_MET_RefFinal_etx;   //!
      TBranch        *b_MET_RefFinal_ety;   //!
      TBranch        *b_MET_RefFinal_phi;   //!
      TBranch        *b_MET_RefFinal_et;   //!
      TBranch        *b_MET_RefFinal_sumet;   //!
      TBranch        *b_MET_RefFinal_etx_CentralReg;   //!
      TBranch        *b_MET_RefFinal_ety_CentralReg;   //!
      TBranch        *b_MET_RefFinal_sumet_CentralReg;   //!
      TBranch        *b_MET_RefFinal_phi_CentralReg;   //!
      TBranch        *b_MET_RefFinal_etx_EndcapRegion;   //!
      TBranch        *b_MET_RefFinal_ety_EndcapRegion;   //!
      TBranch        *b_MET_RefFinal_sumet_EndcapRegion;   //!
      TBranch        *b_MET_RefFinal_phi_EndcapRegion;   //!
      TBranch        *b_MET_RefFinal_etx_ForwardReg;   //!
      TBranch        *b_MET_RefFinal_ety_ForwardReg;   //!
      TBranch        *b_MET_RefFinal_sumet_ForwardReg;   //!
      TBranch        *b_MET_RefFinal_phi_ForwardReg;   //!
      TBranch        *b_cccEt2_Et2_Nh_Calo;   //!
      TBranch        *b_cccEt2_Et2_Eh_Calo;   //!
      TBranch        *b_cccEt2_Et2_Nh_EM;   //!
      TBranch        *b_cccEt2_Et2_Eh_EM;   //!
      TBranch        *b_cccEt2_Et2_Nh_HAD;   //!
      TBranch        *b_cccEt2_Et2_Eh_HAD;   //!
      TBranch        *b_cccEt2_Et2_Nh_PresB;   //!
      TBranch        *b_cccEt2_Et2_Eh_PresB;   //!
      TBranch        *b_cccEt2_Et2_Nh_EMB;   //!
      TBranch        *b_cccEt2_Et2_Eh_EMB;   //!
      TBranch        *b_cccEt2_Et2_Nh_EMEC;   //!
      TBranch        *b_cccEt2_Et2_Eh_EMEC;   //!
      TBranch        *b_cccEt2_Et2_Nh_Tile;   //!
      TBranch        *b_cccEt2_Et2_Eh_Tile;   //!
      TBranch        *b_cccEt2_Et2_Nh_TileGap;   //!
      TBranch        *b_cccEt2_Et2_Eh_TileGap;   //!
      TBranch        *b_cccEt2_Et2_Nh_HEC;   //!
      TBranch        *b_cccEt2_Et2_Eh_HEC;   //!
      TBranch        *b_cccEt2_Et2_Nh_FCal;   //!
      TBranch        *b_cccEt2_Et2_Eh_FCal;   //!
      TBranch        *b_cccEt2_Et2_Nh_PresE;   //!
      TBranch        *b_cccEt2_Et2_Eh_PresE;   //!
      TBranch        *b_cccEt2_Et2_Nh_Scint;   //!
      TBranch        *b_cccEt2_Et2_Eh_Scint;   //!
      TBranch        *b_cccEt2_p2_Nh_Calo;   //!
      TBranch        *b_cccEt2_p2_Eh_Calo;   //!
      TBranch        *b_cccEt2_p2_Nh_EM;   //!
      TBranch        *b_cccEt2_p2_Eh_EM;   //!
      TBranch        *b_cccEt2_p2_Nh_HAD;   //!
      TBranch        *b_cccEt2_p2_Eh_HAD;   //!
      TBranch        *b_cccEt2_p2_Nh_PresB;   //!
      TBranch        *b_cccEt2_p2_Eh_PresB;   //!
      TBranch        *b_cccEt2_p2_Nh_EMB;   //!
      TBranch        *b_cccEt2_p2_Eh_EMB;   //!
      TBranch        *b_cccEt2_p2_Nh_EMEC;   //!
      TBranch        *b_cccEt2_p2_Eh_EMEC;   //!
      TBranch        *b_cccEt2_p2_Nh_Tile;   //!
      TBranch        *b_cccEt2_p2_Eh_Tile;   //!
      TBranch        *b_cccEt2_p2_Nh_TileGap;   //!
      TBranch        *b_cccEt2_p2_Eh_TileGap;   //!
      TBranch        *b_cccEt2_p2_Nh_HEC;   //!
      TBranch        *b_cccEt2_p2_Eh_HEC;   //!
      TBranch        *b_cccEt2_p2_Nh_FCal;   //!
      TBranch        *b_cccEt2_p2_Eh_FCal;   //!
      TBranch        *b_cccEt2_p2_Nh_PresE;   //!
      TBranch        *b_cccEt2_p2_Eh_PresE;   //!
      TBranch        *b_cccEt2_p2_Nh_Scint;   //!
      TBranch        *b_cccEt2_p2_Eh_Scint;   //!
      TBranch        *b_cccEt2_n2_Nh_Calo;   //!
      TBranch        *b_cccEt2_n2_Eh_Calo;   //!
      TBranch        *b_cccEt2_n2_Nh_EM;   //!
      TBranch        *b_cccEt2_n2_Eh_EM;   //!
      TBranch        *b_cccEt2_n2_Nh_HAD;   //!
      TBranch        *b_cccEt2_n2_Eh_HAD;   //!
      TBranch        *b_cccEt2_n2_Nh_PresB;   //!
      TBranch        *b_cccEt2_n2_Eh_PresB;   //!
      TBranch        *b_cccEt2_n2_Nh_EMB;   //!
      TBranch        *b_cccEt2_n2_Eh_EMB;   //!
      TBranch        *b_cccEt2_n2_Nh_EMEC;   //!
      TBranch        *b_cccEt2_n2_Eh_EMEC;   //!
      TBranch        *b_cccEt2_n2_Nh_Tile;   //!
      TBranch        *b_cccEt2_n2_Eh_Tile;   //!
      TBranch        *b_cccEt2_n2_Nh_TileGap;   //!
      TBranch        *b_cccEt2_n2_Eh_TileGap;   //!
      TBranch        *b_cccEt2_n2_Nh_HEC;   //!
      TBranch        *b_cccEt2_n2_Eh_HEC;   //!
      TBranch        *b_cccEt2_n2_Nh_FCal;   //!
      TBranch        *b_cccEt2_n2_Eh_FCal;   //!
      TBranch        *b_cccEt2_n2_Nh_PresE;   //!
      TBranch        *b_cccEt2_n2_Eh_PresE;   //!
      TBranch        *b_cccEt2_n2_Nh_Scint;   //!
      TBranch        *b_cccEt2_n2_Eh_Scint;   //!
      TBranch        *b_cl_hadTopo_n;   //!
      TBranch        *b_cl_hadTopo_E;   //!
      TBranch        *b_cl_hadTopo_pt;   //!
      TBranch        *b_cl_hadTopo_eta;   //!
      TBranch        *b_cl_hadTopo_phi;   //!
      TBranch        *b_cl_hadTopo_E_em;   //!
      TBranch        *b_cl_hadTopo_E_had;   //!
      TBranch        *b_cl_hadTopo_significance;   //!
      TBranch        *b_cl_hadTopo_cellSignificance;   //!
      TBranch        *b_cl_hadTopo_cellSigSampling;   //!
      TBranch        *b_cl_hadTopo_firstEdens;   //!
      TBranch        *b_cl_hadTopo_cellmaxfrac;   //!
      TBranch        *b_cl_hadTopo_longitudinal;   //!
      TBranch        *b_cl_hadTopo_secondlambda;   //!
      TBranch        *b_cl_hadTopo_lateral;   //!
      TBranch        *b_cl_hadTopo_secondR;   //!
      TBranch        *b_cl_hadTopo_centerlambda;   //!
      TBranch        *b_cl_hadTopo_deltaTheta;   //!
      TBranch        *b_cl_hadTopo_deltaPhi;   //!
      TBranch        *b_cl_hadTopo_centermag;   //!
      TBranch        *b_cl_hadTopo_time;   //!
      TBranch        *b_cl_hadTopo_E_PreSamplerB;   //!
      TBranch        *b_cl_hadTopo_E_EMB1;   //!
      TBranch        *b_cl_hadTopo_E_EMB2;   //!
      TBranch        *b_cl_hadTopo_E_EMB3;   //!
      TBranch        *b_cl_hadTopo_E_PreSamplerE;   //!
      TBranch        *b_cl_hadTopo_E_EME1;   //!
      TBranch        *b_cl_hadTopo_E_EME2;   //!
      TBranch        *b_cl_hadTopo_E_EME3;   //!
      TBranch        *b_cl_hadTopo_E_HEC0;   //!
      TBranch        *b_cl_hadTopo_E_HEC1;   //!
      TBranch        *b_cl_hadTopo_E_HEC2;   //!
      TBranch        *b_cl_hadTopo_E_HEC3;   //!
      TBranch        *b_cl_hadTopo_E_TileBar0;   //!
      TBranch        *b_cl_hadTopo_E_TileBar1;   //!
      TBranch        *b_cl_hadTopo_E_TileBar2;   //!
      TBranch        *b_cl_hadTopo_E_TileGap1;   //!
      TBranch        *b_cl_hadTopo_E_TileGap2;   //!
      TBranch        *b_cl_hadTopo_E_TileGap3;   //!
      TBranch        *b_cl_hadTopo_E_TileExt0;   //!
      TBranch        *b_cl_hadTopo_E_TileExt1;   //!
      TBranch        *b_cl_hadTopo_E_TileExt2;   //!
      TBranch        *b_cl_hadTopo_E_FCAL0;   //!
      TBranch        *b_cl_hadTopo_E_FCAL1;   //!
      TBranch        *b_cl_hadTopo_E_FCAL2;   //!
      TBranch        *b_HIEtaGap_beam1;   //!
      TBranch        *b_HIEtaGap_beam2;   //!
      TBranch        *b_HIEtaGap_lowerEta;   //!
      TBranch        *b_HIEtaGap_upperEta;   //!
      TBranch        *b_HIEtaGap_lowerEdgeType;   //!
      TBranch        *b_HIEtaGap_upperEdgeType;   //!
      TBranch        *b_HIEtaGap_lowerEtaNegEdge;   //!
      TBranch        *b_HIEtaGap_upperEtaNegEdge;   //!
      TBranch        *b_HIEtaGap_lowerEtaPosEdge;   //!
      TBranch        *b_HIEtaGap_upperEtaPosEdge;   //!
      TBranch        *b_HIEtaGap_maxGapSize;   //!
      TBranch        *b_HITrigVtxCounts_NtrksPrim;   //!
      TBranch        *b_HITrigVtxCounts_SumPtsqPrim;   //!
      TBranch        *b_trig_DB_SMK;   //!
      TBranch        *b_trig_DB_L1PSK;   //!
      TBranch        *b_trig_DB_HLTPSK;   //!
      TBranch        *b_trig_L1_TAV;   //!
      TBranch        *b_trig_L2_passedPhysics;   //!
      TBranch        *b_trig_EF_passedPhysics;   //!
      TBranch        *b_trig_L1_TBP;   //!
      TBranch        *b_trig_L1_TAP;   //!
      TBranch        *b_trig_L2_passedRaw;   //!
      TBranch        *b_trig_EF_passedRaw;   //!
      TBranch        *b_trig_L2_truncated;   //!
      TBranch        *b_trig_EF_truncated;   //!
      TBranch        *b_trig_L2_resurrected;   //!
      TBranch        *b_trig_EF_resurrected;   //!
      TBranch        *b_trig_L2_passedThrough;   //!
      TBranch        *b_trig_EF_passedThrough;   //!
      TBranch        *b_trig_L2_wasPrescaled;   //!
      TBranch        *b_trig_L2_wasResurrected;   //!
      TBranch        *b_trig_EF_wasPrescaled;   //!
      TBranch        *b_trig_EF_wasResurrected;   //!
      TBranch        *b_trig_L1_jet_n;   //!
      TBranch        *b_trig_L1_jet_eta;   //!
      TBranch        *b_trig_L1_jet_phi;   //!
      TBranch        *b_trig_L1_jet_thrNames;   //!
      TBranch        *b_trig_L1_jet_thrValues;   //!
      TBranch        *b_trig_L1_jet_thrPattern;   //!
      TBranch        *b_trig_L1_jet_RoIWord;   //!
      TBranch        *b_trig_L1_jet_et4x4;   //!
      TBranch        *b_trig_L1_jet_et6x6;   //!
      TBranch        *b_trig_L1_jet_et8x8;   //!
      TBranch        *b_trig_L1_emtau_n;   //!
      TBranch        *b_trig_L1_emtau_eta;   //!
      TBranch        *b_trig_L1_emtau_phi;   //!
      TBranch        *b_trig_L1_emtau_thrNames;   //!
      TBranch        *b_trig_L1_emtau_thrValues;   //!
      TBranch        *b_trig_L1_emtau_core;   //!
      TBranch        *b_trig_L1_emtau_EMClus;   //!
      TBranch        *b_trig_L1_emtau_tauClus;   //!
      TBranch        *b_trig_L1_emtau_EMIsol;   //!
      TBranch        *b_trig_L1_emtau_hadIsol;   //!
      TBranch        *b_trig_L1_emtau_hadCore;   //!
      TBranch        *b_trig_L1_emtau_thrPattern;   //!
      TBranch        *b_trig_L1_emtau_RoIWord;   //!
      TBranch        *b_trig_L1_mu_n;   //!
      TBranch        *b_trig_L1_mu_pt;   //!
      TBranch        *b_trig_L1_mu_eta;   //!
      TBranch        *b_trig_L1_mu_phi;   //!
      TBranch        *b_trig_L1_mu_thrName;   //!
      TBranch        *b_trig_L1_mu_thrNumber;   //!
      TBranch        *b_trig_L1_mu_RoINumber;   //!
      TBranch        *b_trig_L1_mu_sectorAddress;   //!
      TBranch        *b_trig_L1_mu_firstCandidate;   //!
      TBranch        *b_trig_L1_mu_moreCandInRoI;   //!
      TBranch        *b_trig_L1_mu_moreCandInSector;   //!
      TBranch        *b_trig_L1_mu_source;   //!
      TBranch        *b_trig_L1_mu_hemisphere;   //!
      TBranch        *b_trig_L1_mu_charge;   //!
      TBranch        *b_trig_L1_mu_vetoed;   //!
      TBranch        *b_trig_L1_mu_RoIWord;   //!
      TBranch        *b_trig_EF_jet_n;   //!
      TBranch        *b_trig_EF_jet_E;   //!
      TBranch        *b_trig_EF_jet_pt;   //!
      TBranch        *b_trig_EF_jet_m;   //!
      TBranch        *b_trig_EF_jet_eta;   //!
      TBranch        *b_trig_EF_jet_phi;   //!
      TBranch        *b_trig_EF_jet_a4tcem;   //!
      TBranch        *b_trig_EF_jet_a2tcem;   //!
      TBranch        *b_trig_EF_jet_a4tchad;   //!
      TBranch        *b_trig_EF_jet_a4hi;   //!
      TBranch        *b_trig_EF_jet_a2hi;   //!
      TBranch        *b_trig_EF_jet_RoIword;   //!
      TBranch        *b_trig_EF_jet_EF_2j0_a4tcem_deta40;   //!
      TBranch        *b_trig_EF_jet_EF_2j10_a4hi_EFFS_2L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_2j10_a4hi_EFFS_2L1J5_L1TE90;   //!
      TBranch        *b_trig_EF_jet_EF_2j10_a4hi_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j10_a4hi_EFFS_L1TE100;   //!
      TBranch        *b_trig_EF_jet_EF_2j10_a4hi_EFFS_L1TE90;   //!
      TBranch        *b_trig_EF_jet_EF_2j10_a4hi_deta40_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j10_a4hi_eta50_deta40;   //!
      TBranch        *b_trig_EF_jet_EF_2j10_a4hi_eta50_deta40_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j10_a4tcem_EFFS_2L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_2j10_a4tcem_deta40;   //!
      TBranch        *b_trig_EF_jet_EF_2j10_a4tcem_eta50_deta40;   //!
      TBranch        *b_trig_EF_jet_EF_2j10_a4tchad_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j10_a4tchad_deta40_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j10_a4tchad_eta50_deta40_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j15_a4hi_EFFS_2L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_2j15_a4hi_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j15_a4hi_deta40_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j15_a4hi_eta50_deta40;   //!
      TBranch        *b_trig_EF_jet_EF_2j15_a4hi_eta50_deta40_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j15_a4tcem_EFFS_2L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_2j15_a4tcem_deta40;   //!
      TBranch        *b_trig_EF_jet_EF_2j15_a4tcem_eta50_deta40;   //!
      TBranch        *b_trig_EF_jet_EF_2j15_a4tchad_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j15_a4tchad_deta40_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j15_a4tchad_eta50_deta40_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j20_a4hi_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j20_a4tchad_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j7_a4hi_EFFS_2L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_2j7_a4hi_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j7_a4hi_deta40_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j7_a4hi_eta50_deta40;   //!
      TBranch        *b_trig_EF_jet_EF_2j7_a4hi_eta50_deta40_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j7_a4tcem_EFFS_2L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_2j7_a4tcem_deta40;   //!
      TBranch        *b_trig_EF_jet_EF_2j7_a4tcem_eta50_deta40;   //!
      TBranch        *b_trig_EF_jet_EF_2j7_a4tchad_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j7_a4tchad_deta40_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_2j7_a4tchad_eta50_deta40_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_fj10_a4hi_EFFS_L1FJ0;   //!
      TBranch        *b_trig_EF_jet_EF_fj10_a4tchad_EFFS_L1FJ0;   //!
      TBranch        *b_trig_EF_jet_EF_fj15_a4hi_EFFS_L1FJ0;   //!
      TBranch        *b_trig_EF_jet_EF_fj15_a4tchad_EFFS_L1FJ0;   //!
      TBranch        *b_trig_EF_jet_EF_fj7_a4hi_EFFS_L1FJ0;   //!
      TBranch        *b_trig_EF_jet_EF_fj7_a4hi_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_fj7_a4tchad_EFFS_L1FJ0;   //!
      TBranch        *b_trig_EF_jet_EF_fj7_a4tchad_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_j10_a4hi_EFFS_L1EM3;   //!
      TBranch        *b_trig_EF_jet_EF_j10_a4hi_EFFS_L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_j10_a4hi_EFFS_L1J5_L1TE90;   //!
      TBranch        *b_trig_EF_jet_EF_j10_a4hi_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_j10_a4hi_EFFS_L1TAU3;   //!
      TBranch        *b_trig_EF_jet_EF_j10_a4hi_EFFS_L1TE100;   //!
      TBranch        *b_trig_EF_jet_EF_j10_a4hi_EFFS_L1TE90;   //!
      TBranch        *b_trig_EF_jet_EF_j10_a4tcem_EFFS_L1EM3;   //!
      TBranch        *b_trig_EF_jet_EF_j10_a4tcem_EFFS_L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_j10_a4tcem_EFFS_L1J5_win6;   //!
      TBranch        *b_trig_EF_jet_EF_j10_a4tcem_EFFS_L1TAU3;   //!
      TBranch        *b_trig_EF_jet_EF_j10_a4tchad_EFFS_L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_j10_a4tchad_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_j10_u0uchad_LArNoiseBurst;   //!
      TBranch        *b_trig_EF_jet_EF_j10_u0uchad_empty_LArNoiseBurst;   //!
      TBranch        *b_trig_EF_jet_EF_j10_u0uchad_firstempty_LArNoiseBurst;   //!
      TBranch        *b_trig_EF_jet_EF_j15_a2tcem_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j15_a2tcem_EFFS_L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_j15_a4hi_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j15_a4hi_EFFS_L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_j15_a4hi_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_j15_a4tcem_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j15_a4tcem_EFFS_L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_j15_a4tchad_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_j20_a4hi_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j20_a4hi_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_j20_a4tcem_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j20_a4tcem_EFFS_L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_j20_a4tchad_EFFS_L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_j20_a4tchad_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_j25_a4hi_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j25_a4tcem_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j30_a4hi_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j30_a4hi_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_j30_a4tcem_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j30_a4tcem_EFFS_L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_j30_a4tchad_EFFS_L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_j30_a4tchad_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_j30_u0uchad_empty_LArNoiseBurst;   //!
      TBranch        *b_trig_EF_jet_EF_j35_a4hi_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j35_a4tcem_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j40_a4hi_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j40_a4hi_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_j40_a4tcem_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j40_a4tcem_EFFS_L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_j40_a4tchad_EFFS_L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_j40_a4tchad_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_j45_a4hi_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j45_a4tcem_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j50_a4hi_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j50_a4hi_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_j50_a4tcem_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j50_a4tcem_EFFS_L1J15;   //!
      TBranch        *b_trig_EF_jet_EF_j50_a4tchad_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j50_a4tchad_EFFS_L1J15;   //!
      TBranch        *b_trig_EF_jet_EF_j50_a4tchad_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_j60_a4tcem_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j60_a4tcem_EFFS_L1J15;   //!
      TBranch        *b_trig_EF_jet_EF_j60_a4tchad_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j60_a4tchad_EFFS_L1J15;   //!
      TBranch        *b_trig_EF_jet_EF_j75_a4hi_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j75_a4tcem_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j75_a4tcem_EFFS_L1J15;   //!
      TBranch        *b_trig_EF_jet_EF_j75_a4tchad_EFFS_L1J10;   //!
      TBranch        *b_trig_EF_jet_EF_j75_a4tchad_EFFS_L1J15;   //!
      TBranch        *b_trig_EF_jet_EF_j7_a4hi_EFFS_L1EM3;   //!
      TBranch        *b_trig_EF_jet_EF_j7_a4hi_EFFS_L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_j7_a4hi_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_j7_a4hi_EFFS_L1TAU3;   //!
      TBranch        *b_trig_EF_jet_EF_j7_a4tcem_EFFS_L1EM3;   //!
      TBranch        *b_trig_EF_jet_EF_j7_a4tcem_EFFS_L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_j7_a4tcem_EFFS_L1J5_win6;   //!
      TBranch        *b_trig_EF_jet_EF_j7_a4tcem_EFFS_L1TAU3;   //!
      TBranch        *b_trig_EF_jet_EF_j7_a4tchad_EFFS_L1J5;   //!
      TBranch        *b_trig_EF_jet_EF_j7_a4tchad_EFFS_L1MBTS;   //!
      TBranch        *b_trig_EF_jet_EF_j80_a4tchad_EFFS_L1J15;   //!
      TBranch        *b_trig_EF_jet_EF_j90_a4tchad_EFFS_L1J15;   //!
      TBranch        *b_trig_L1_esum_thrNames;   //!
      TBranch        *b_trig_L1_esum_ExMiss;   //!
      TBranch        *b_trig_L1_esum_EyMiss;   //!
      TBranch        *b_trig_L1_esum_energyT;   //!
      TBranch        *b_trig_L1_esum_overflowX;   //!
      TBranch        *b_trig_L1_esum_overflowY;   //!
      TBranch        *b_trig_L1_esum_overflowT;   //!
      TBranch        *b_trig_L1_esum_RoIWord0;   //!
      TBranch        *b_trig_L1_esum_RoIWord1;   //!
      TBranch        *b_trig_L1_esum_RoIWord2;   //!
      TBranch        *b_trig_EF_met_MEx;   //!
      TBranch        *b_trig_EF_met_MEy;   //!
      TBranch        *b_trig_EF_met_MEz;   //!
      TBranch        *b_trig_EF_met_sumEt;   //!
      TBranch        *b_trig_EF_met_sumE;   //!
      TBranch        *b_trig_EF_met_flag;   //!
      TBranch        *b_trig_EF_met_nameOfComponent;   //!
      TBranch        *b_trig_EF_met_MExComponent;   //!
      TBranch        *b_trig_EF_met_MEyComponent;   //!
      TBranch        *b_trig_EF_met_MEzComponent;   //!
      TBranch        *b_trig_EF_met_sumEtComponent;   //!
      TBranch        *b_trig_EF_met_sumEComponent;   //!
      TBranch        *b_trig_EF_met_componentCalib0;   //!
      TBranch        *b_trig_EF_met_componentCalib1;   //!
      TBranch        *b_trig_EF_met_sumOfSigns;   //!
      TBranch        *b_trig_EF_met_usedChannels;   //!
      TBranch        *b_trig_EF_met_status;   //!
      TBranch        *b_trig_EF_ph_n;   //!
      TBranch        *b_trig_EF_ph_E;   //!
      TBranch        *b_trig_EF_ph_Et;   //!
      TBranch        *b_trig_EF_ph_pt;   //!
      TBranch        *b_trig_EF_ph_m;   //!
      TBranch        *b_trig_EF_ph_eta;   //!
      TBranch        *b_trig_EF_ph_phi;   //!
      TBranch        *b_trig_EF_ph_px;   //!
      TBranch        *b_trig_EF_ph_py;   //!
      TBranch        *b_trig_EF_ph_pz;   //!
      TBranch        *b_trig_EF_ph_author;   //!
      TBranch        *b_trig_EF_ph_isRecovered;   //!
      TBranch        *b_trig_EF_ph_isEM;   //!
      TBranch        *b_trig_EF_ph_isEMLoose;   //!
      TBranch        *b_trig_EF_ph_isEMMedium;   //!
      TBranch        *b_trig_EF_ph_isEMTight;   //!
      TBranch        *b_trig_EF_ph_convFlag;   //!
      TBranch        *b_trig_EF_ph_isConv;   //!
      TBranch        *b_trig_EF_ph_nConv;   //!
      TBranch        *b_trig_EF_ph_nSingleTrackConv;   //!
      TBranch        *b_trig_EF_ph_nDoubleTrackConv;   //!
      TBranch        *b_trig_EF_ph_loose;   //!
      TBranch        *b_trig_EF_ph_looseIso;   //!
      TBranch        *b_trig_EF_ph_tight;   //!
      TBranch        *b_trig_EF_ph_tightIso;   //!
      TBranch        *b_trig_EF_ph_looseAR;   //!
      TBranch        *b_trig_EF_ph_looseARIso;   //!
      TBranch        *b_trig_EF_ph_tightAR;   //!
      TBranch        *b_trig_EF_ph_tightARIso;   //!
      TBranch        *b_trig_EF_ph_Ethad;   //!
      TBranch        *b_trig_EF_ph_Ethad1;   //!
      TBranch        *b_trig_EF_ph_E033;   //!
      TBranch        *b_trig_EF_ph_f1;   //!
      TBranch        *b_trig_EF_ph_f1core;   //!
      TBranch        *b_trig_EF_ph_Emins1;   //!
      TBranch        *b_trig_EF_ph_fside;   //!
      TBranch        *b_trig_EF_ph_Emax2;   //!
      TBranch        *b_trig_EF_ph_ws3;   //!
      TBranch        *b_trig_EF_ph_wstot;   //!
      TBranch        *b_trig_EF_ph_E132;   //!
      TBranch        *b_trig_EF_ph_E1152;   //!
      TBranch        *b_trig_EF_ph_emaxs1;   //!
      TBranch        *b_trig_EF_ph_deltaEs;   //!
      TBranch        *b_trig_EF_ph_E233;   //!
      TBranch        *b_trig_EF_ph_E237;   //!
      TBranch        *b_trig_EF_ph_E277;   //!
      TBranch        *b_trig_EF_ph_weta2;   //!
      TBranch        *b_trig_EF_ph_f3;   //!
      TBranch        *b_trig_EF_ph_f3core;   //!
      TBranch        *b_trig_EF_ph_rphiallcalo;   //!
      TBranch        *b_trig_EF_ph_Etcone45;   //!
      TBranch        *b_trig_EF_ph_Etcone15;   //!
      TBranch        *b_trig_EF_ph_Etcone20;   //!
      TBranch        *b_trig_EF_ph_Etcone25;   //!
      TBranch        *b_trig_EF_ph_Etcone30;   //!
      TBranch        *b_trig_EF_ph_Etcone35;   //!
      TBranch        *b_trig_EF_ph_Etcone40;   //!
      TBranch        *b_trig_EF_ph_ptcone20;   //!
      TBranch        *b_trig_EF_ph_ptcone30;   //!
      TBranch        *b_trig_EF_ph_ptcone40;   //!
      TBranch        *b_trig_EF_ph_convanglematch;   //!
      TBranch        *b_trig_EF_ph_convtrackmatch;   //!
      TBranch        *b_trig_EF_ph_hasconv;   //!
      TBranch        *b_trig_EF_ph_convvtxx;   //!
      TBranch        *b_trig_EF_ph_convvtxy;   //!
      TBranch        *b_trig_EF_ph_convvtxz;   //!
      TBranch        *b_trig_EF_ph_Rconv;   //!
      TBranch        *b_trig_EF_ph_zconv;   //!
      TBranch        *b_trig_EF_ph_convvtxchi2;   //!
      TBranch        *b_trig_EF_ph_pt1conv;   //!
      TBranch        *b_trig_EF_ph_convtrk1nBLHits;   //!
      TBranch        *b_trig_EF_ph_convtrk1nPixHits;   //!
      TBranch        *b_trig_EF_ph_convtrk1nSCTHits;   //!
      TBranch        *b_trig_EF_ph_convtrk1nTRTHits;   //!
      TBranch        *b_trig_EF_ph_pt2conv;   //!
      TBranch        *b_trig_EF_ph_convtrk2nBLHits;   //!
      TBranch        *b_trig_EF_ph_convtrk2nPixHits;   //!
      TBranch        *b_trig_EF_ph_convtrk2nSCTHits;   //!
      TBranch        *b_trig_EF_ph_convtrk2nTRTHits;   //!
      TBranch        *b_trig_EF_ph_ptconv;   //!
      TBranch        *b_trig_EF_ph_pzconv;   //!
      TBranch        *b_trig_EF_ph_reta;   //!
      TBranch        *b_trig_EF_ph_rphi;   //!
      TBranch        *b_trig_EF_ph_cl_E;   //!
      TBranch        *b_trig_EF_ph_cl_pt;   //!
      TBranch        *b_trig_EF_ph_cl_eta;   //!
      TBranch        *b_trig_EF_ph_cl_phi;   //!
      TBranch        *b_trig_EF_ph_cl_etas2;   //!
      TBranch        *b_trig_EF_el_n;   //!
      TBranch        *b_trig_EF_el_E;   //!
      TBranch        *b_trig_EF_el_Et;   //!
      TBranch        *b_trig_EF_el_pt;   //!
      TBranch        *b_trig_EF_el_m;   //!
      TBranch        *b_trig_EF_el_eta;   //!
      TBranch        *b_trig_EF_el_phi;   //!
      TBranch        *b_trig_EF_el_px;   //!
      TBranch        *b_trig_EF_el_py;   //!
      TBranch        *b_trig_EF_el_pz;   //!
      TBranch        *b_trig_EF_el_charge;   //!
      TBranch        *b_trig_EF_el_author;   //!
      TBranch        *b_trig_EF_el_isEM;   //!
      TBranch        *b_trig_EF_el_isEMLoose;   //!
      TBranch        *b_trig_EF_el_isEMMedium;   //!
      TBranch        *b_trig_EF_el_isEMTight;   //!
      TBranch        *b_trig_EF_el_loose;   //!
      TBranch        *b_trig_EF_el_looseIso;   //!
      TBranch        *b_trig_EF_el_medium;   //!
      TBranch        *b_trig_EF_el_mediumIso;   //!
      TBranch        *b_trig_EF_el_mediumWithoutTrack;   //!
      TBranch        *b_trig_EF_el_mediumIsoWithoutTrack;   //!
      TBranch        *b_trig_EF_el_tight;   //!
      TBranch        *b_trig_EF_el_tightIso;   //!
      TBranch        *b_trig_EF_el_tightWithoutTrack;   //!
      TBranch        *b_trig_EF_el_tightIsoWithoutTrack;   //!
      TBranch        *b_trig_EF_el_loosePP;   //!
      TBranch        *b_trig_EF_el_loosePPIso;   //!
      TBranch        *b_trig_EF_el_mediumPP;   //!
      TBranch        *b_trig_EF_el_mediumPPIso;   //!
      TBranch        *b_trig_EF_el_tightPP;   //!
      TBranch        *b_trig_EF_el_tightPPIso;   //!
      TBranch        *b_trig_EF_el_Ethad;   //!
      TBranch        *b_trig_EF_el_Ethad1;   //!
      TBranch        *b_trig_EF_el_f1;   //!
      TBranch        *b_trig_EF_el_f1core;   //!
      TBranch        *b_trig_EF_el_Emins1;   //!
      TBranch        *b_trig_EF_el_fside;   //!
      TBranch        *b_trig_EF_el_Emax2;   //!
      TBranch        *b_trig_EF_el_ws3;   //!
      TBranch        *b_trig_EF_el_wstot;   //!
      TBranch        *b_trig_EF_el_emaxs1;   //!
      TBranch        *b_trig_EF_el_deltaEs;   //!
      TBranch        *b_trig_EF_el_E233;   //!
      TBranch        *b_trig_EF_el_E237;   //!
      TBranch        *b_trig_EF_el_E277;   //!
      TBranch        *b_trig_EF_el_weta2;   //!
      TBranch        *b_trig_EF_el_f3;   //!
      TBranch        *b_trig_EF_el_f3core;   //!
      TBranch        *b_trig_EF_el_rphiallcalo;   //!
      TBranch        *b_trig_EF_el_Etcone45;   //!
      TBranch        *b_trig_EF_el_Etcone15;   //!
      TBranch        *b_trig_EF_el_Etcone20;   //!
      TBranch        *b_trig_EF_el_Etcone25;   //!
      TBranch        *b_trig_EF_el_Etcone30;   //!
      TBranch        *b_trig_EF_el_Etcone35;   //!
      TBranch        *b_trig_EF_el_Etcone40;   //!
      TBranch        *b_trig_EF_el_ptcone20;   //!
      TBranch        *b_trig_EF_el_ptcone30;   //!
      TBranch        *b_trig_EF_el_ptcone40;   //!
      TBranch        *b_trig_EF_el_pos7;   //!
      TBranch        *b_trig_EF_el_etacorrmag;   //!
      TBranch        *b_trig_EF_el_deltaeta1;   //!
      TBranch        *b_trig_EF_el_deltaeta2;   //!
      TBranch        *b_trig_EF_el_deltaphi2;   //!
      TBranch        *b_trig_EF_el_expectHitInBLayer;   //!
      TBranch        *b_trig_EF_el_trackd0_physics;   //!
      TBranch        *b_trig_EF_el_reta;   //!
      TBranch        *b_trig_EF_el_rphi;   //!
      TBranch        *b_trig_EF_el_EtringnoisedR03sig2;   //!
      TBranch        *b_trig_EF_el_EtringnoisedR03sig3;   //!
      TBranch        *b_trig_EF_el_EtringnoisedR03sig4;   //!
      TBranch        *b_trig_EF_el_isolationlikelihoodjets;   //!
      TBranch        *b_trig_EF_el_isolationlikelihoodhqelectrons;   //!
      TBranch        *b_trig_EF_el_electronweight;   //!
      TBranch        *b_trig_EF_el_electronbgweight;   //!
      TBranch        *b_trig_EF_el_softeweight;   //!
      TBranch        *b_trig_EF_el_softebgweight;   //!
      TBranch        *b_trig_EF_el_neuralnet;   //!
      TBranch        *b_trig_EF_el_Hmatrix;   //!
      TBranch        *b_trig_EF_el_Hmatrix5;   //!
      TBranch        *b_trig_EF_el_adaboost;   //!
      TBranch        *b_trig_EF_el_softeneuralnet;   //!
      TBranch        *b_trig_EF_el_zvertex;   //!
      TBranch        *b_trig_EF_el_errz;   //!
      TBranch        *b_trig_EF_el_etap;   //!
      TBranch        *b_trig_EF_el_depth;   //!
      TBranch        *b_trig_EF_el_Es0;   //!
      TBranch        *b_trig_EF_el_etas0;   //!
      TBranch        *b_trig_EF_el_phis0;   //!
      TBranch        *b_trig_EF_el_Es1;   //!
      TBranch        *b_trig_EF_el_etas1;   //!
      TBranch        *b_trig_EF_el_phis1;   //!
      TBranch        *b_trig_EF_el_Es2;   //!
      TBranch        *b_trig_EF_el_etas2;   //!
      TBranch        *b_trig_EF_el_phis2;   //!
      TBranch        *b_trig_EF_el_Es3;   //!
      TBranch        *b_trig_EF_el_etas3;   //!
      TBranch        *b_trig_EF_el_phis3;   //!
      TBranch        *b_trig_EF_el_cl_E;   //!
      TBranch        *b_trig_EF_el_cl_pt;   //!
      TBranch        *b_trig_EF_el_cl_eta;   //!
      TBranch        *b_trig_EF_el_cl_phi;   //!
      TBranch        *b_trig_EF_el_trackd0;   //!
      TBranch        *b_trig_EF_el_trackz0;   //!
      TBranch        *b_trig_EF_el_trackphi;   //!
      TBranch        *b_trig_EF_el_tracktheta;   //!
      TBranch        *b_trig_EF_el_trackqoverp;   //!
      TBranch        *b_trig_EF_el_trackpt;   //!
      TBranch        *b_trig_EF_el_tracketa;   //!
      TBranch        *b_trig_EF_el_trackfitchi2;   //!
      TBranch        *b_trig_EF_el_trackfitndof;   //!
      TBranch        *b_trig_EF_el_nBLHits;   //!
      TBranch        *b_trig_EF_el_nPixHits;   //!
      TBranch        *b_trig_EF_el_nSCTHits;   //!
      TBranch        *b_trig_EF_el_nTRTHits;   //!
      TBranch        *b_trig_EF_el_nTRTHighTHits;   //!
      TBranch        *b_trig_EF_el_nTRTXenonHits;   //!
      TBranch        *b_trig_EF_el_nPixHoles;   //!
      TBranch        *b_trig_EF_el_nSCTHoles;   //!
      TBranch        *b_trig_EF_el_nTRTHoles;   //!
      TBranch        *b_trig_EF_el_nPixelDeadSensors;   //!
      TBranch        *b_trig_EF_el_nSCTDeadSensors;   //!
      TBranch        *b_trig_EF_el_nBLSharedHits;   //!
      TBranch        *b_trig_EF_el_nPixSharedHits;   //!
      TBranch        *b_trig_EF_el_nSCTSharedHits;   //!
      TBranch        *b_trig_EF_el_nBLayerSplitHits;   //!
      TBranch        *b_trig_EF_el_nPixSplitHits;   //!
      TBranch        *b_trig_EF_el_nBLayerOutliers;   //!
      TBranch        *b_trig_EF_el_nPixelOutliers;   //!
      TBranch        *b_trig_EF_el_nSCTOutliers;   //!
      TBranch        *b_trig_EF_el_nTRTOutliers;   //!
      TBranch        *b_trig_EF_el_nTRTHighTOutliers;   //!
      TBranch        *b_trig_EF_el_expectBLayerHit;   //!
      TBranch        *b_trig_EF_el_nSiHits;   //!
      TBranch        *b_trig_EF_el_TRTHighTHitsRatio;   //!
      TBranch        *b_trig_EF_el_TRTHighTOutliersRatio;   //!
      TBranch        *b_trig_EF_el_pixeldEdx;   //!
      TBranch        *b_trig_EF_el_nGoodHitsPixeldEdx;   //!
      TBranch        *b_trig_EF_el_massPixeldEdx;   //!
      TBranch        *b_trig_EF_el_likelihoodsPixeldEdx;   //!
      TBranch        *b_trig_EF_el_eProbabilityComb;   //!
      TBranch        *b_trig_EF_el_eProbabilityHT;   //!
      TBranch        *b_trig_EF_el_eProbabilityToT;   //!
      TBranch        *b_trig_EF_el_eProbabilityBrem;   //!
      TBranch        *b_trig_EF_el_vertweight;   //!
      TBranch        *b_trig_EF_el_vertx;   //!
      TBranch        *b_trig_EF_el_verty;   //!
      TBranch        *b_trig_EF_el_vertz;   //!
      TBranch        *b_trig_EF_el_hastrack;   //!
      TBranch        *b_trig_EF_trigmuonef_n;   //!
      TBranch        *b_trig_EF_trigmuonef_effs15;   //!
      TBranch        *b_trig_EF_trigmuonef_effs18;   //!
      TBranch        *b_trig_EF_trigmuonef_effs24;   //!
      TBranch        *b_trig_EF_trigmuonef_RoINum;   //!
      TBranch        *b_trig_EF_trigmuonef_NSegments;   //!
      TBranch        *b_trig_EF_trigmuonef_NMdtHits;   //!
      TBranch        *b_trig_EF_trigmuonef_NRpcHits;   //!
      TBranch        *b_trig_EF_trigmuonef_NTgcHits;   //!
      TBranch        *b_trig_EF_trigmuonef_NCscHits;   //!
      TBranch        *b_trig_EF_trigmuonef_EtaPreviousLevel;   //!
      TBranch        *b_trig_EF_trigmuonef_PhiPreviousLevel;   //!
      TBranch        *b_trig_EF_trigmuonef_track_n;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MuonType;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_pt;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_eta;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_phi;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_charge;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_d0;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_z0;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_chi2;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_chi2prob;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_posX;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_posY;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_posZ;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_NRpcHitsPhi;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_NTgcHitsPhi;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_NCscHitsPhi;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_NRpcHitsEta;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_NTgcHitsEta;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_NCscHitsEta;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_NMdtHits;   //!
      TBranch        *b_trig_EF_trigmuonef_track_MS_hasMS;   //!
      TBranch        *b_trig_EF_trigmuonef_track_SA_pt;   //!
      TBranch        *b_trig_EF_trigmuonef_track_SA_eta;   //!
      TBranch        *b_trig_EF_trigmuonef_track_SA_phi;   //!
      TBranch        *b_trig_EF_trigmuonef_track_SA_charge;   //!
      TBranch        *b_trig_EF_trigmuonef_track_SA_d0;   //!
      TBranch        *b_trig_EF_trigmuonef_track_SA_z0;   //!
      TBranch        *b_trig_EF_trigmuonef_track_SA_chi2;   //!
      TBranch        *b_trig_EF_trigmuonef_track_SA_chi2prob;   //!
      TBranch        *b_trig_EF_trigmuonef_track_SA_posX;   //!
      TBranch        *b_trig_EF_trigmuonef_track_SA_posY;   //!
      TBranch        *b_trig_EF_trigmuonef_track_SA_posZ;   //!
      TBranch        *b_trig_EF_trigmuonef_track_SA_hasSA;   //!
      TBranch        *b_trig_EF_trigmuonef_track_CB_pt;   //!
      TBranch        *b_trig_EF_trigmuonef_track_CB_eta;   //!
      TBranch        *b_trig_EF_trigmuonef_track_CB_phi;   //!
      TBranch        *b_trig_EF_trigmuonef_track_CB_charge;   //!
      TBranch        *b_trig_EF_trigmuonef_track_CB_d0;   //!
      TBranch        *b_trig_EF_trigmuonef_track_CB_z0;   //!
      TBranch        *b_trig_EF_trigmuonef_track_CB_chi2;   //!
      TBranch        *b_trig_EF_trigmuonef_track_CB_chi2prob;   //!
      TBranch        *b_trig_EF_trigmuonef_track_CB_posX;   //!
      TBranch        *b_trig_EF_trigmuonef_track_CB_posY;   //!
      TBranch        *b_trig_EF_trigmuonef_track_CB_posZ;   //!
      TBranch        *b_trig_EF_trigmuonef_track_CB_matchChi2;   //!
      TBranch        *b_trig_EF_trigmuonef_track_CB_NIdSctHits;   //!
      TBranch        *b_trig_EF_trigmuonef_track_CB_NIdPixelHits;   //!
      TBranch        *b_trig_EF_trigmuonef_track_CB_NTrtHits;   //!
      TBranch        *b_trig_EF_trigmuonef_track_CB_hasCB;   //!
      TBranch        *b_bcmRDO_n;   //!
      TBranch        *b_bcmRDO_channel;   //!
      TBranch        *b_bcmRDO_nhits;   //!
      TBranch        *b_bcmRDO_pulse1pos;   //!
      TBranch        *b_bcmRDO_pulse1width;   //!
      TBranch        *b_bcmRDO_pulse2pos;   //!
      TBranch        *b_bcmRDO_pulse2width;   //!
      TBranch        *b_bcmRDO_lvl1a;   //!
      TBranch        *b_bcmRDO_bcid;   //!
      TBranch        *b_bcmRDO_lvl1id;   //!
      TBranch        *b_ctpRDO_nBC;   //!
      TBranch        *b_ctpRDO_lvl1aBC;   //!
      TBranch        *b_ctpRDO_time_s;   //!
      TBranch        *b_ctpRDO_time_ns;   //!
      TBranch        *b_ctpRDO_pit;   //!
      TBranch        *b_ctpRDO_tbp;   //!
      TBranch        *b_ctpRDO_tap;   //!
      TBranch        *b_ctpRDO_tav;   //!
      TBranch        *b_ctp_decisionTypeWord;   //!
      TBranch        *b_ctp_decisionItems;   //!
      TBranch        *b_ctp_decisionWords;   //!
      TBranch        *b_ctp_nDecisionItems;   //!
      TBranch        *b_mbtsLvl2_nElements;   //!
      TBranch        *b_mbtsLvl2_energies;   //!
      TBranch        *b_mbtsLvl2_ntimes;   //!
      TBranch        *b_mbtsLvl2_times;   //!
      TBranch        *b_lvl2_sp_nElements;   //!
      TBranch        *b_lvl2_sp_hPixelClusTotBins;   //!
      TBranch        *b_lvl2_sp_hPixelClusTotMin;   //!
      TBranch        *b_lvl2_sp_hPixelClusTotMax;   //!
      TBranch        *b_lvl2_sp_hPixelClusSizeBins;   //!
      TBranch        *b_lvl2_sp_hPixelClusSizeMin;   //!
      TBranch        *b_lvl2_sp_hPixelClusSizeMax;   //!
      TBranch        *b_lvl2_sp_pixelClusEndcapC_contents;   //!
      TBranch        *b_lvl2_sp_pixelClusBarrel_contents;   //!
      TBranch        *b_lvl2_sp_pixelClusEndcapA_contents;   //!
      TBranch        *b_lvl2_sp_droppedPixelModuleIds;   //!
      TBranch        *b_lvl2_sp_sctSpEndcapC;   //!
      TBranch        *b_lvl2_sp_sctSpBarrel;   //!
      TBranch        *b_lvl2_sp_sctSpEndcapA;   //!
      TBranch        *b_lvl2_sp_droppedSctModuleIds;   //!
      TBranch        *b_lvl2_mbTrt_nElements;   //!
      TBranch        *b_lvl2_mbTrt_hTotBins;   //!
      TBranch        *b_lvl2_mbTrt_hTotMin;   //!
      TBranch        *b_lvl2_mbTrt_hTotMax;   //!
      TBranch        *b_lvl2_mbTrt_endcapC_contents;   //!
      TBranch        *b_lvl2_mbTrt_barrel_contents;   //!
      TBranch        *b_lvl2_mbTrt_endcapA_contents;   //!
      TBranch        *b_ef_trk_nElements;   //!
      TBranch        *b_ef_trk_hZ0Bins;   //!
      TBranch        *b_ef_trk_hZ0Min;   //!
      TBranch        *b_ef_trk_hZ0Max;   //!
      TBranch        *b_ef_trk_hPtBins;   //!
      TBranch        *b_ef_trk_hPtMin;   //!
      TBranch        *b_ef_trk_hPtMax;   //!
      TBranch        *b_ef_trk_hEtaBins;   //!
      TBranch        *b_ef_trk_hEtaMin;   //!
      TBranch        *b_ef_trk_hEtaMax;   //!
      TBranch        *b_ef_trk_hPhiBins;   //!
      TBranch        *b_ef_trk_hPhiMin;   //!
      TBranch        *b_ef_trk_hPhiMax;   //!
      TBranch        *b_ef_trk_z0_pt_contents;   //!
      TBranch        *b_ef_trk_eta_phi_contents;   //!
      TBranch        *b_trig_L2_jet_n;   //!
      TBranch        *b_trig_L2_jet_E;   //!
      TBranch        *b_trig_L2_jet_eta;   //!
      TBranch        *b_trig_L2_jet_phi;   //!
      TBranch        *b_trig_L2_jet_RoIWord;   //!
      TBranch        *b_trig_L2_jet_InputType;   //!
      TBranch        *b_trig_L2_jet_OutputType;   //!
      TBranch        *b_trig_L2_jet_counter;   //!
      TBranch        *b_trig_L2_jet_c4cchad;   //!
      TBranch        *b_trig_L2_jet_c4ccem;   //!
      TBranch        *b_trig_L2_jet_c4uchad;   //!
      TBranch        *b_trig_L2_jet_ehad0;   //!
      TBranch        *b_trig_L2_jet_eem0;   //!
      TBranch        *b_trig_L2_jet_nLeadingCells;   //!
      TBranch        *b_trig_L2_jet_hecf;   //!
      TBranch        *b_trig_L2_jet_jetQuality;   //!
      TBranch        *b_trig_L2_jet_emf;   //!
      TBranch        *b_trig_L2_jet_jetTimeCells;   //!
      TBranch        *b_vx_n;   //!
      TBranch        *b_vx_x;   //!
      TBranch        *b_vx_y;   //!
      TBranch        *b_vx_z;   //!
      TBranch        *b_vx_err_x;   //!
      TBranch        *b_vx_err_y;   //!
      TBranch        *b_vx_err_z;   //!
      TBranch        *b_vx_cov_xy;   //!
      TBranch        *b_vx_cov_xz;   //!
      TBranch        *b_vx_cov_yz;   //!
      TBranch        *b_vx_type;   //!
      TBranch        *b_vx_chi2;   //!
      TBranch        *b_vx_ndof;   //!
      TBranch        *b_vx_px;   //!
      TBranch        *b_vx_py;   //!
      TBranch        *b_vx_pz;   //!
      TBranch        *b_vx_E;   //!
      TBranch        *b_vx_m;   //!
      TBranch        *b_vx_nTracks;   //!
      TBranch        *b_vx_sumPt;   //!
      TBranch        *b_vx_trk_weight;   //!
      TBranch        *b_vx_trk_n;   //!
      TBranch        *b_vx_trk_index;   //!
      TBranch        *b_el_n;   //!
      TBranch        *b_el_E;   //!
      TBranch        *b_el_Et;   //!
      TBranch        *b_el_pt;   //!
      TBranch        *b_el_m;   //!
      TBranch        *b_el_eta;   //!
      TBranch        *b_el_phi;   //!
      TBranch        *b_el_px;   //!
      TBranch        *b_el_py;   //!
      TBranch        *b_el_pz;   //!
      TBranch        *b_el_charge;   //!
      TBranch        *b_el_author;   //!
      TBranch        *b_el_isEM;   //!
      TBranch        *b_el_isEMLoose;   //!
      TBranch        *b_el_isEMMedium;   //!
      TBranch        *b_el_isEMTight;   //!
      TBranch        *b_el_OQ;   //!
      TBranch        *b_el_convFlag;   //!
      TBranch        *b_el_isConv;   //!
      TBranch        *b_el_nConv;   //!
      TBranch        *b_el_nSingleTrackConv;   //!
      TBranch        *b_el_nDoubleTrackConv;   //!
      TBranch        *b_el_mediumWithoutTrack;   //!
      TBranch        *b_el_mediumIsoWithoutTrack;   //!
      TBranch        *b_el_tightWithoutTrack;   //!
      TBranch        *b_el_tightIsoWithoutTrack;   //!
      TBranch        *b_el_loose;   //!
      TBranch        *b_el_looseIso;   //!
      TBranch        *b_el_medium;   //!
      TBranch        *b_el_mediumIso;   //!
      TBranch        *b_el_tight;   //!
      TBranch        *b_el_tightIso;   //!
      TBranch        *b_el_loosePP;   //!
      TBranch        *b_el_loosePPIso;   //!
      TBranch        *b_el_mediumPP;   //!
      TBranch        *b_el_mediumPPIso;   //!
      TBranch        *b_el_tightPP;   //!
      TBranch        *b_el_tightPPIso;   //!
      TBranch        *b_el_goodOQ;   //!
      TBranch        *b_el_Ethad;   //!
      TBranch        *b_el_Ethad1;   //!
      TBranch        *b_el_f1;   //!
      TBranch        *b_el_f1core;   //!
      TBranch        *b_el_Emins1;   //!
      TBranch        *b_el_fside;   //!
      TBranch        *b_el_Emax2;   //!
      TBranch        *b_el_ws3;   //!
      TBranch        *b_el_wstot;   //!
      TBranch        *b_el_emaxs1;   //!
      TBranch        *b_el_deltaEs;   //!
      TBranch        *b_el_E233;   //!
      TBranch        *b_el_E237;   //!
      TBranch        *b_el_E277;   //!
      TBranch        *b_el_weta2;   //!
      TBranch        *b_el_f3;   //!
      TBranch        *b_el_f3core;   //!
      TBranch        *b_el_rphiallcalo;   //!
      TBranch        *b_el_Etcone45;   //!
      TBranch        *b_el_Etcone15;   //!
      TBranch        *b_el_Etcone20;   //!
      TBranch        *b_el_Etcone25;   //!
      TBranch        *b_el_Etcone30;   //!
      TBranch        *b_el_Etcone35;   //!
      TBranch        *b_el_Etcone40;   //!
      TBranch        *b_el_ptcone20;   //!
      TBranch        *b_el_ptcone30;   //!
      TBranch        *b_el_ptcone40;   //!
      TBranch        *b_el_nucone20;   //!
      TBranch        *b_el_nucone30;   //!
      TBranch        *b_el_nucone40;   //!
      TBranch        *b_el_Etcone15_pt_corrected;   //!
      TBranch        *b_el_Etcone20_pt_corrected;   //!
      TBranch        *b_el_Etcone25_pt_corrected;   //!
      TBranch        *b_el_Etcone30_pt_corrected;   //!
      TBranch        *b_el_Etcone35_pt_corrected;   //!
      TBranch        *b_el_Etcone40_pt_corrected;   //!
      TBranch        *b_el_convanglematch;   //!
      TBranch        *b_el_convtrackmatch;   //!
      TBranch        *b_el_pos7;   //!
      TBranch        *b_el_etacorrmag;   //!
      TBranch        *b_el_deltaeta1;   //!
      TBranch        *b_el_deltaeta2;   //!
      TBranch        *b_el_deltaphi2;   //!
      TBranch        *b_el_deltaphiRescaled;   //!
      TBranch        *b_el_deltaPhiFromLast;   //!
      TBranch        *b_el_deltaPhiRot;   //!
      TBranch        *b_el_expectHitInBLayer;   //!
      TBranch        *b_el_trackd0_physics;   //!
      TBranch        *b_el_etaSampling1;   //!
      TBranch        *b_el_reta;   //!
      TBranch        *b_el_rphi;   //!
      TBranch        *b_el_topoEtcone20;   //!
      TBranch        *b_el_topoEtcone30;   //!
      TBranch        *b_el_topoEtcone40;   //!
      TBranch        *b_el_materialTraversed;   //!
      TBranch        *b_el_EtringnoisedR03sig2;   //!
      TBranch        *b_el_EtringnoisedR03sig3;   //!
      TBranch        *b_el_EtringnoisedR03sig4;   //!
      TBranch        *b_el_ptcone20_zpv05;   //!
      TBranch        *b_el_ptcone30_zpv05;   //!
      TBranch        *b_el_ptcone40_zpv05;   //!
      TBranch        *b_el_nucone20_zpv05;   //!
      TBranch        *b_el_nucone30_zpv05;   //!
      TBranch        *b_el_nucone40_zpv05;   //!
      TBranch        *b_el_isolationlikelihoodjets;   //!
      TBranch        *b_el_isolationlikelihoodhqelectrons;   //!
      TBranch        *b_el_electronweight;   //!
      TBranch        *b_el_electronbgweight;   //!
      TBranch        *b_el_softeweight;   //!
      TBranch        *b_el_softebgweight;   //!
      TBranch        *b_el_neuralnet;   //!
      TBranch        *b_el_Hmatrix;   //!
      TBranch        *b_el_Hmatrix5;   //!
      TBranch        *b_el_adaboost;   //!
      TBranch        *b_el_softeneuralnet;   //!
      TBranch        *b_el_ringernn;   //!
      TBranch        *b_el_zvertex;   //!
      TBranch        *b_el_errz;   //!
      TBranch        *b_el_etap;   //!
      TBranch        *b_el_depth;   //!
      TBranch        *b_el_refittedTrack_n;   //!
      TBranch        *b_el_refittedTrack_author;   //!
      TBranch        *b_el_refittedTrack_chi2;   //!
      TBranch        *b_el_refittedTrack_hasBrem;   //!
      TBranch        *b_el_refittedTrack_bremRadius;   //!
      TBranch        *b_el_refittedTrack_bremZ;   //!
      TBranch        *b_el_refittedTrack_bremRadiusErr;   //!
      TBranch        *b_el_refittedTrack_bremZErr;   //!
      TBranch        *b_el_refittedTrack_bremFitStatus;   //!
      TBranch        *b_el_refittedTrack_qoverp;   //!
      TBranch        *b_el_refittedTrack_d0;   //!
      TBranch        *b_el_refittedTrack_z0;   //!
      TBranch        *b_el_refittedTrack_theta;   //!
      TBranch        *b_el_refittedTrack_phi;   //!
      TBranch        *b_el_refittedTrack_LMqoverp;   //!
      TBranch        *b_el_refittedTrack_covd0;   //!
      TBranch        *b_el_refittedTrack_covz0;   //!
      TBranch        *b_el_refittedTrack_covphi;   //!
      TBranch        *b_el_refittedTrack_covtheta;   //!
      TBranch        *b_el_refittedTrack_covqoverp;   //!
      TBranch        *b_el_refittedTrack_covd0z0;   //!
      TBranch        *b_el_refittedTrack_covz0phi;   //!
      TBranch        *b_el_refittedTrack_covz0theta;   //!
      TBranch        *b_el_refittedTrack_covz0qoverp;   //!
      TBranch        *b_el_refittedTrack_covd0phi;   //!
      TBranch        *b_el_refittedTrack_covd0theta;   //!
      TBranch        *b_el_refittedTrack_covd0qoverp;   //!
      TBranch        *b_el_refittedTrack_covphitheta;   //!
      TBranch        *b_el_refittedTrack_covphiqoverp;   //!
      TBranch        *b_el_refittedTrack_covthetaqoverp;   //!
      TBranch        *b_el_refittedTrack_d0_wrtBL;   //!
      TBranch        *b_el_refittedTrack_z0_wrtBL;   //!
      TBranch        *b_el_refittedTrack_phi_wrtBL;   //!
      TBranch        *b_el_refittedTrack_theta_wrtBL;   //!
      TBranch        *b_el_refittedTrack_qoverp_wrtBL;   //!
      TBranch        *b_el_refittedTrack_d0_err_wrtBL;   //!
      TBranch        *b_el_refittedTrack_z0_err_wrtBL;   //!
      TBranch        *b_el_refittedTrack_phi_err_wrtBL;   //!
      TBranch        *b_el_refittedTrack_theta_err_wrtBL;   //!
      TBranch        *b_el_refittedTrack_qoverp_err_wrtBL;   //!
      TBranch        *b_el_refittedTrack_d0_z0_err_wrtBL;   //!
      TBranch        *b_el_refittedTrack_d0_phi_err_wrtBL;   //!
      TBranch        *b_el_refittedTrack_d0_theta_err_wrtBL;   //!
      TBranch        *b_el_refittedTrack_d0_qoverp_err_wrtBL;   //!
      TBranch        *b_el_refittedTrack_z0_phi_err_wrtBL;   //!
      TBranch        *b_el_refittedTrack_z0_theta_err_wrtBL;   //!
      TBranch        *b_el_refittedTrack_z0_qoverp_err_wrtBL;   //!
      TBranch        *b_el_refittedTrack_phi_theta_err_wrtBL;   //!
      TBranch        *b_el_refittedTrack_phi_qoverp_err_wrtBL;   //!
      TBranch        *b_el_refittedTrack_theta_qoverp_err_wrtBL;   //!
      TBranch        *b_el_Es0;   //!
      TBranch        *b_el_etas0;   //!
      TBranch        *b_el_phis0;   //!
      TBranch        *b_el_Es1;   //!
      TBranch        *b_el_etas1;   //!
      TBranch        *b_el_phis1;   //!
      TBranch        *b_el_Es2;   //!
      TBranch        *b_el_etas2;   //!
      TBranch        *b_el_phis2;   //!
      TBranch        *b_el_Es3;   //!
      TBranch        *b_el_etas3;   //!
      TBranch        *b_el_phis3;   //!
      TBranch        *b_el_E_PreSamplerB;   //!
      TBranch        *b_el_E_EMB1;   //!
      TBranch        *b_el_E_EMB2;   //!
      TBranch        *b_el_E_EMB3;   //!
      TBranch        *b_el_E_PreSamplerE;   //!
      TBranch        *b_el_E_EME1;   //!
      TBranch        *b_el_E_EME2;   //!
      TBranch        *b_el_E_EME3;   //!
      TBranch        *b_el_E_HEC0;   //!
      TBranch        *b_el_E_HEC1;   //!
      TBranch        *b_el_E_HEC2;   //!
      TBranch        *b_el_E_HEC3;   //!
      TBranch        *b_el_E_TileBar0;   //!
      TBranch        *b_el_E_TileBar1;   //!
      TBranch        *b_el_E_TileBar2;   //!
      TBranch        *b_el_E_TileGap1;   //!
      TBranch        *b_el_E_TileGap2;   //!
      TBranch        *b_el_E_TileGap3;   //!
      TBranch        *b_el_E_TileExt0;   //!
      TBranch        *b_el_E_TileExt1;   //!
      TBranch        *b_el_E_TileExt2;   //!
      TBranch        *b_el_E_FCAL0;   //!
      TBranch        *b_el_E_FCAL1;   //!
      TBranch        *b_el_E_FCAL2;   //!
      TBranch        *b_el_cl_E;   //!
      TBranch        *b_el_cl_pt;   //!
      TBranch        *b_el_cl_eta;   //!
      TBranch        *b_el_cl_phi;   //!
      TBranch        *b_el_cl_etaCalo;   //!
      TBranch        *b_el_cl_phiCalo;   //!
      TBranch        *b_el_firstEdens;   //!
      TBranch        *b_el_cellmaxfrac;   //!
      TBranch        *b_el_longitudinal;   //!
      TBranch        *b_el_secondlambda;   //!
      TBranch        *b_el_lateral;   //!
      TBranch        *b_el_secondR;   //!
      TBranch        *b_el_centerlambda;   //!
      TBranch        *b_el_rawcl_Es0;   //!
      TBranch        *b_el_rawcl_etas0;   //!
      TBranch        *b_el_rawcl_phis0;   //!
      TBranch        *b_el_rawcl_Es1;   //!
      TBranch        *b_el_rawcl_etas1;   //!
      TBranch        *b_el_rawcl_phis1;   //!
      TBranch        *b_el_rawcl_Es2;   //!
      TBranch        *b_el_rawcl_etas2;   //!
      TBranch        *b_el_rawcl_phis2;   //!
      TBranch        *b_el_rawcl_Es3;   //!
      TBranch        *b_el_rawcl_etas3;   //!
      TBranch        *b_el_rawcl_phis3;   //!
      TBranch        *b_el_rawcl_E;   //!
      TBranch        *b_el_rawcl_pt;   //!
      TBranch        *b_el_rawcl_eta;   //!
      TBranch        *b_el_rawcl_phi;   //!
      TBranch        *b_el_trackd0;   //!
      TBranch        *b_el_trackz0;   //!
      TBranch        *b_el_trackphi;   //!
      TBranch        *b_el_tracktheta;   //!
      TBranch        *b_el_trackqoverp;   //!
      TBranch        *b_el_trackpt;   //!
      TBranch        *b_el_tracketa;   //!
      TBranch        *b_el_trackcov_d0;   //!
      TBranch        *b_el_trackcov_z0;   //!
      TBranch        *b_el_trackcov_phi;   //!
      TBranch        *b_el_trackcov_theta;   //!
      TBranch        *b_el_trackcov_qoverp;   //!
      TBranch        *b_el_trackcov_d0_z0;   //!
      TBranch        *b_el_trackcov_d0_phi;   //!
      TBranch        *b_el_trackcov_d0_theta;   //!
      TBranch        *b_el_trackcov_d0_qoverp;   //!
      TBranch        *b_el_trackcov_z0_phi;   //!
      TBranch        *b_el_trackcov_z0_theta;   //!
      TBranch        *b_el_trackcov_z0_qoverp;   //!
      TBranch        *b_el_trackcov_phi_theta;   //!
      TBranch        *b_el_trackcov_phi_qoverp;   //!
      TBranch        *b_el_trackcov_theta_qoverp;   //!
      TBranch        *b_el_trackfitchi2;   //!
      TBranch        *b_el_trackfitndof;   //!
      TBranch        *b_el_nBLHits;   //!
      TBranch        *b_el_nPixHits;   //!
      TBranch        *b_el_nSCTHits;   //!
      TBranch        *b_el_nTRTHits;   //!
      TBranch        *b_el_nTRTHighTHits;   //!
      TBranch        *b_el_nTRTXenonHits;   //!
      TBranch        *b_el_nPixHoles;   //!
      TBranch        *b_el_nSCTHoles;   //!
      TBranch        *b_el_nTRTHoles;   //!
      TBranch        *b_el_nPixelDeadSensors;   //!
      TBranch        *b_el_nSCTDeadSensors;   //!
      TBranch        *b_el_nBLSharedHits;   //!
      TBranch        *b_el_nPixSharedHits;   //!
      TBranch        *b_el_nSCTSharedHits;   //!
      TBranch        *b_el_nBLayerSplitHits;   //!
      TBranch        *b_el_nPixSplitHits;   //!
      TBranch        *b_el_nBLayerOutliers;   //!
      TBranch        *b_el_nPixelOutliers;   //!
      TBranch        *b_el_nSCTOutliers;   //!
      TBranch        *b_el_nTRTOutliers;   //!
      TBranch        *b_el_nTRTHighTOutliers;   //!
      TBranch        *b_el_nContribPixelLayers;   //!
      TBranch        *b_el_nGangedPixels;   //!
      TBranch        *b_el_nGangedFlaggedFakes;   //!
      TBranch        *b_el_nPixelSpoiltHits;   //!
      TBranch        *b_el_nSCTDoubleHoles;   //!
      TBranch        *b_el_nSCTSpoiltHits;   //!
      TBranch        *b_el_expectBLayerHit;   //!
      TBranch        *b_el_nSiHits;   //!
      TBranch        *b_el_TRTHighTHitsRatio;   //!
      TBranch        *b_el_TRTHighTOutliersRatio;   //!
      TBranch        *b_el_pixeldEdx;   //!
      TBranch        *b_el_nGoodHitsPixeldEdx;   //!
      TBranch        *b_el_massPixeldEdx;   //!
      TBranch        *b_el_likelihoodsPixeldEdx;   //!
      TBranch        *b_el_eProbabilityComb;   //!
      TBranch        *b_el_eProbabilityHT;   //!
      TBranch        *b_el_eProbabilityToT;   //!
      TBranch        *b_el_eProbabilityBrem;   //!
      TBranch        *b_el_vertweight;   //!
      TBranch        *b_el_vertx;   //!
      TBranch        *b_el_verty;   //!
      TBranch        *b_el_vertz;   //!
      TBranch        *b_el_trackd0beam;   //!
      TBranch        *b_el_trackz0beam;   //!
      TBranch        *b_el_tracksigd0beam;   //!
      TBranch        *b_el_tracksigz0beam;   //!
      TBranch        *b_el_trackd0pv;   //!
      TBranch        *b_el_trackz0pv;   //!
      TBranch        *b_el_tracksigd0pv;   //!
      TBranch        *b_el_tracksigz0pv;   //!
      TBranch        *b_el_trackIPEstimate_d0_biasedpvunbiased;   //!
      TBranch        *b_el_trackIPEstimate_z0_biasedpvunbiased;   //!
      TBranch        *b_el_trackIPEstimate_sigd0_biasedpvunbiased;   //!
      TBranch        *b_el_trackIPEstimate_sigz0_biasedpvunbiased;   //!
      TBranch        *b_el_trackIPEstimate_d0_unbiasedpvunbiased;   //!
      TBranch        *b_el_trackIPEstimate_z0_unbiasedpvunbiased;   //!
      TBranch        *b_el_trackIPEstimate_sigd0_unbiasedpvunbiased;   //!
      TBranch        *b_el_trackIPEstimate_sigz0_unbiasedpvunbiased;   //!
      TBranch        *b_el_trackd0pvunbiased;   //!
      TBranch        *b_el_trackz0pvunbiased;   //!
      TBranch        *b_el_tracksigd0pvunbiased;   //!
      TBranch        *b_el_tracksigz0pvunbiased;   //!
      TBranch        *b_el_Unrefittedtrack_d0;   //!
      TBranch        *b_el_Unrefittedtrack_z0;   //!
      TBranch        *b_el_Unrefittedtrack_phi;   //!
      TBranch        *b_el_Unrefittedtrack_theta;   //!
      TBranch        *b_el_Unrefittedtrack_qoverp;   //!
      TBranch        *b_el_Unrefittedtrack_pt;   //!
      TBranch        *b_el_Unrefittedtrack_eta;   //!
      TBranch        *b_el_theta_LM;   //!
      TBranch        *b_el_qoverp_LM;   //!
      TBranch        *b_el_locX_LM;   //!
      TBranch        *b_el_locY_LM;   //!
      TBranch        *b_el_phi_LM;   //!
      TBranch        *b_el_theta_err_LM;   //!
      TBranch        *b_el_qoverp_err_LM;   //!
      TBranch        *b_el_locX_err_LM;   //!
      TBranch        *b_el_locY_err_LM;   //!
      TBranch        *b_el_phi_err_LM;   //!
      TBranch        *b_el_locX_locY_err_LM;   //!
      TBranch        *b_el_locX_phi_err_LM;   //!
      TBranch        *b_el_locX_theta_err_LM;   //!
      TBranch        *b_el_locX_qoverp_err_LM;   //!
      TBranch        *b_el_locY_phi_err_LM;   //!
      TBranch        *b_el_locY_theta_err_LM;   //!
      TBranch        *b_el_locY_qoverp_err_LM;   //!
      TBranch        *b_el_phi_theta_err_LM;   //!
      TBranch        *b_el_phi_qoverp_err_LM;   //!
      TBranch        *b_el_theta_qoverp_err_LM;   //!
      TBranch        *b_el_hastrack;   //!
      TBranch        *b_el_deltaEmax2;   //!
      TBranch        *b_el_calibHitsShowerDepth;   //!
      TBranch        *b_el_isIso;   //!
      TBranch        *b_el_mvaptcone20;   //!
      TBranch        *b_el_mvaptcone30;   //!
      TBranch        *b_el_mvaptcone40;   //!
      TBranch        *b_el_CaloPointing_eta;   //!
      TBranch        *b_el_CaloPointing_sigma_eta;   //!
      TBranch        *b_el_CaloPointing_zvertex;   //!
      TBranch        *b_el_CaloPointing_sigma_zvertex;   //!
      TBranch        *b_el_HPV_eta;   //!
      TBranch        *b_el_HPV_sigma_eta;   //!
      TBranch        *b_el_HPV_zvertex;   //!
      TBranch        *b_el_HPV_sigma_zvertex;   //!
      TBranch        *b_el_topoEtcone60;   //!
      TBranch        *b_el_ES0_real;   //!
      TBranch        *b_el_ES1_real;   //!
      TBranch        *b_el_ES2_real;   //!
      TBranch        *b_el_ES3_real;   //!
      TBranch        *b_el_EcellS0;   //!
      TBranch        *b_el_etacellS0;   //!
      TBranch        *b_el_Etcone40_ED_corrected;   //!
      TBranch        *b_el_Etcone40_corrected;   //!
      TBranch        *b_el_topoEtcone20_corrected;   //!
      TBranch        *b_el_topoEtcone30_corrected;   //!
      TBranch        *b_el_topoEtcone40_corrected;   //!
      TBranch        *b_el_ED_median;   //!
      TBranch        *b_el_ED_sigma;   //!
      TBranch        *b_el_ED_Njets;   //!
      TBranch        *b_el_EF_dr;   //!
      TBranch        *b_el_EF_index;   //!
      TBranch        *b_el_L2_dr;   //!
      TBranch        *b_el_L1_dr;   //!
      TBranch        *b_el_L1_index;   //!
      TBranch        *b_ph_n;   //!
      TBranch        *b_ph_E;   //!
      TBranch        *b_ph_Et;   //!
      TBranch        *b_ph_pt;   //!
      TBranch        *b_ph_m;   //!
      TBranch        *b_ph_eta;   //!
      TBranch        *b_ph_phi;   //!
      TBranch        *b_ph_px;   //!
      TBranch        *b_ph_py;   //!
      TBranch        *b_ph_pz;   //!
      TBranch        *b_ph_author;   //!
      TBranch        *b_ph_isRecovered;   //!
      TBranch        *b_ph_isEM;   //!
      TBranch        *b_ph_isEMLoose;   //!
      TBranch        *b_ph_isEMMedium;   //!
      TBranch        *b_ph_isEMTight;   //!
      TBranch        *b_ph_OQ;   //!
      TBranch        *b_ph_convFlag;   //!
      TBranch        *b_ph_isConv;   //!
      TBranch        *b_ph_nConv;   //!
      TBranch        *b_ph_nSingleTrackConv;   //!
      TBranch        *b_ph_nDoubleTrackConv;   //!
      TBranch        *b_ph_loose;   //!
      TBranch        *b_ph_looseIso;   //!
      TBranch        *b_ph_tight;   //!
      TBranch        *b_ph_tightIso;   //!
      TBranch        *b_ph_looseAR;   //!
      TBranch        *b_ph_looseARIso;   //!
      TBranch        *b_ph_tightAR;   //!
      TBranch        *b_ph_tightARIso;   //!
      TBranch        *b_ph_goodOQ;   //!
      TBranch        *b_ph_Ethad;   //!
      TBranch        *b_ph_Ethad1;   //!
      TBranch        *b_ph_E033;   //!
      TBranch        *b_ph_f1;   //!
      TBranch        *b_ph_f1core;   //!
      TBranch        *b_ph_Emins1;   //!
      TBranch        *b_ph_fside;   //!
      TBranch        *b_ph_Emax2;   //!
      TBranch        *b_ph_ws3;   //!
      TBranch        *b_ph_wstot;   //!
      TBranch        *b_ph_E132;   //!
      TBranch        *b_ph_E1152;   //!
      TBranch        *b_ph_emaxs1;   //!
      TBranch        *b_ph_deltaEs;   //!
      TBranch        *b_ph_E233;   //!
      TBranch        *b_ph_E237;   //!
      TBranch        *b_ph_E277;   //!
      TBranch        *b_ph_weta2;   //!
      TBranch        *b_ph_f3;   //!
      TBranch        *b_ph_f3core;   //!
      TBranch        *b_ph_rphiallcalo;   //!
      TBranch        *b_ph_Etcone45;   //!
      TBranch        *b_ph_Etcone15;   //!
      TBranch        *b_ph_Etcone20;   //!
      TBranch        *b_ph_Etcone25;   //!
      TBranch        *b_ph_Etcone30;   //!
      TBranch        *b_ph_Etcone35;   //!
      TBranch        *b_ph_Etcone40;   //!
      TBranch        *b_ph_ptcone20;   //!
      TBranch        *b_ph_ptcone30;   //!
      TBranch        *b_ph_ptcone40;   //!
      TBranch        *b_ph_nucone20;   //!
      TBranch        *b_ph_nucone30;   //!
      TBranch        *b_ph_nucone40;   //!
      TBranch        *b_ph_Etcone15_pt_corrected;   //!
      TBranch        *b_ph_Etcone20_pt_corrected;   //!
      TBranch        *b_ph_Etcone25_pt_corrected;   //!
      TBranch        *b_ph_Etcone30_pt_corrected;   //!
      TBranch        *b_ph_Etcone35_pt_corrected;   //!
      TBranch        *b_ph_Etcone40_pt_corrected;   //!
      TBranch        *b_ph_convanglematch;   //!
      TBranch        *b_ph_convtrackmatch;   //!
      TBranch        *b_ph_hasconv;   //!
      TBranch        *b_ph_convvtxx;   //!
      TBranch        *b_ph_convvtxy;   //!
      TBranch        *b_ph_convvtxz;   //!
      TBranch        *b_ph_Rconv;   //!
      TBranch        *b_ph_zconv;   //!
      TBranch        *b_ph_convvtxchi2;   //!
      TBranch        *b_ph_pt1conv;   //!
      TBranch        *b_ph_convtrk1nBLHits;   //!
      TBranch        *b_ph_convtrk1nPixHits;   //!
      TBranch        *b_ph_convtrk1nSCTHits;   //!
      TBranch        *b_ph_convtrk1nTRTHits;   //!
      TBranch        *b_ph_pt2conv;   //!
      TBranch        *b_ph_convtrk2nBLHits;   //!
      TBranch        *b_ph_convtrk2nPixHits;   //!
      TBranch        *b_ph_convtrk2nSCTHits;   //!
      TBranch        *b_ph_convtrk2nTRTHits;   //!
      TBranch        *b_ph_ptconv;   //!
      TBranch        *b_ph_pzconv;   //!
      TBranch        *b_ph_reta;   //!
      TBranch        *b_ph_rphi;   //!
      TBranch        *b_ph_topoEtcone20;   //!
      TBranch        *b_ph_topoEtcone30;   //!
      TBranch        *b_ph_topoEtcone40;   //!
      TBranch        *b_ph_materialTraversed;   //!
      TBranch        *b_ph_EtringnoisedR03sig2;   //!
      TBranch        *b_ph_EtringnoisedR03sig3;   //!
      TBranch        *b_ph_EtringnoisedR03sig4;   //!
      TBranch        *b_ph_ptcone20_zpv05;   //!
      TBranch        *b_ph_ptcone30_zpv05;   //!
      TBranch        *b_ph_ptcone40_zpv05;   //!
      TBranch        *b_ph_nucone20_zpv05;   //!
      TBranch        *b_ph_nucone30_zpv05;   //!
      TBranch        *b_ph_nucone40_zpv05;   //!
      TBranch        *b_ph_isolationlikelihoodjets;   //!
      TBranch        *b_ph_isolationlikelihoodhqelectrons;   //!
      TBranch        *b_ph_loglikelihood;   //!
      TBranch        *b_ph_photonweight;   //!
      TBranch        *b_ph_photonbgweight;   //!
      TBranch        *b_ph_neuralnet;   //!
      TBranch        *b_ph_Hmatrix;   //!
      TBranch        *b_ph_Hmatrix5;   //!
      TBranch        *b_ph_adaboost;   //!
      TBranch        *b_ph_ringernn;   //!
      TBranch        *b_ph_zvertex;   //!
      TBranch        *b_ph_errz;   //!
      TBranch        *b_ph_etap;   //!
      TBranch        *b_ph_depth;   //!
      TBranch        *b_ph_cl_E;   //!
      TBranch        *b_ph_cl_pt;   //!
      TBranch        *b_ph_cl_eta;   //!
      TBranch        *b_ph_cl_phi;   //!
      TBranch        *b_ph_cl_etaCalo;   //!
      TBranch        *b_ph_cl_phiCalo;   //!
      TBranch        *b_ph_Es0;   //!
      TBranch        *b_ph_etas0;   //!
      TBranch        *b_ph_phis0;   //!
      TBranch        *b_ph_Es1;   //!
      TBranch        *b_ph_etas1;   //!
      TBranch        *b_ph_phis1;   //!
      TBranch        *b_ph_Es2;   //!
      TBranch        *b_ph_etas2;   //!
      TBranch        *b_ph_phis2;   //!
      TBranch        *b_ph_Es3;   //!
      TBranch        *b_ph_etas3;   //!
      TBranch        *b_ph_phis3;   //!
      TBranch        *b_ph_rawcl_Es0;   //!
      TBranch        *b_ph_rawcl_etas0;   //!
      TBranch        *b_ph_rawcl_phis0;   //!
      TBranch        *b_ph_rawcl_Es1;   //!
      TBranch        *b_ph_rawcl_etas1;   //!
      TBranch        *b_ph_rawcl_phis1;   //!
      TBranch        *b_ph_rawcl_Es2;   //!
      TBranch        *b_ph_rawcl_etas2;   //!
      TBranch        *b_ph_rawcl_phis2;   //!
      TBranch        *b_ph_rawcl_Es3;   //!
      TBranch        *b_ph_rawcl_etas3;   //!
      TBranch        *b_ph_rawcl_phis3;   //!
      TBranch        *b_ph_rawcl_E;   //!
      TBranch        *b_ph_rawcl_pt;   //!
      TBranch        *b_ph_rawcl_eta;   //!
      TBranch        *b_ph_rawcl_phi;   //!
      TBranch        *b_ph_convMatchDeltaEta1;   //!
      TBranch        *b_ph_convMatchDeltaEta2;   //!
      TBranch        *b_ph_convMatchDeltaPhi1;   //!
      TBranch        *b_ph_convMatchDeltaPhi2;   //!
      TBranch        *b_ph_rings_E;   //!
      TBranch        *b_ph_vx_n;   //!
      TBranch        *b_ph_vx_x;   //!
      TBranch        *b_ph_vx_y;   //!
      TBranch        *b_ph_vx_z;   //!
      TBranch        *b_ph_vx_px;   //!
      TBranch        *b_ph_vx_py;   //!
      TBranch        *b_ph_vx_pz;   //!
      TBranch        *b_ph_vx_E;   //!
      TBranch        *b_ph_vx_m;   //!
      TBranch        *b_ph_vx_nTracks;   //!
      TBranch        *b_ph_vx_sumPt;   //!
      TBranch        *b_ph_vx_convTrk_weight;   //!
      TBranch        *b_ph_vx_convTrk_n;   //!
      TBranch        *b_ph_vx_convTrk_fitter;   //!
      TBranch        *b_ph_vx_convTrk_patternReco1;   //!
      TBranch        *b_ph_vx_convTrk_patternReco2;   //!
      TBranch        *b_ph_vx_convTrk_trackProperties;   //!
      TBranch        *b_ph_vx_convTrk_particleHypothesis;   //!
      TBranch        *b_ph_vx_convTrk_nBLHits;   //!
      TBranch        *b_ph_vx_convTrk_nPixHits;   //!
      TBranch        *b_ph_vx_convTrk_nSCTHits;   //!
      TBranch        *b_ph_vx_convTrk_nTRTHits;   //!
      TBranch        *b_ph_vx_convTrk_nTRTHighTHits;   //!
      TBranch        *b_ph_vx_convTrk_nTRTXenonHits;   //!
      TBranch        *b_ph_vx_convTrk_nPixHoles;   //!
      TBranch        *b_ph_vx_convTrk_nSCTHoles;   //!
      TBranch        *b_ph_vx_convTrk_nTRTHoles;   //!
      TBranch        *b_ph_vx_convTrk_nPixelDeadSensors;   //!
      TBranch        *b_ph_vx_convTrk_nSCTDeadSensors;   //!
      TBranch        *b_ph_vx_convTrk_nBLSharedHits;   //!
      TBranch        *b_ph_vx_convTrk_nPixSharedHits;   //!
      TBranch        *b_ph_vx_convTrk_nSCTSharedHits;   //!
      TBranch        *b_ph_vx_convTrk_nBLayerSplitHits;   //!
      TBranch        *b_ph_vx_convTrk_nPixSplitHits;   //!
      TBranch        *b_ph_vx_convTrk_nBLayerOutliers;   //!
      TBranch        *b_ph_vx_convTrk_nPixelOutliers;   //!
      TBranch        *b_ph_vx_convTrk_nSCTOutliers;   //!
      TBranch        *b_ph_vx_convTrk_nTRTOutliers;   //!
      TBranch        *b_ph_vx_convTrk_nTRTHighTOutliers;   //!
      TBranch        *b_ph_vx_convTrk_nContribPixelLayers;   //!
      TBranch        *b_ph_vx_convTrk_nGangedPixels;   //!
      TBranch        *b_ph_vx_convTrk_nGangedFlaggedFakes;   //!
      TBranch        *b_ph_vx_convTrk_nPixelSpoiltHits;   //!
      TBranch        *b_ph_vx_convTrk_nSCTDoubleHoles;   //!
      TBranch        *b_ph_vx_convTrk_nSCTSpoiltHits;   //!
      TBranch        *b_ph_vx_convTrk_nTRTDeadStraws;   //!
      TBranch        *b_ph_vx_convTrk_nTRTTubeHits;   //!
      TBranch        *b_ph_vx_convTrk_nOutliersOnTrack;   //!
      TBranch        *b_ph_vx_convTrk_standardDeviationOfChi2OS;   //!
      TBranch        *b_ph_vx_convTrk_expectBLayerHit;   //!
      TBranch        *b_ph_vx_convTrk_nMDTHits;   //!
      TBranch        *b_ph_vx_convTrk_nCSCEtaHits;   //!
      TBranch        *b_ph_vx_convTrk_nCSCPhiHits;   //!
      TBranch        *b_ph_vx_convTrk_nRPCEtaHits;   //!
      TBranch        *b_ph_vx_convTrk_nRPCPhiHits;   //!
      TBranch        *b_ph_vx_convTrk_nTGCEtaHits;   //!
      TBranch        *b_ph_vx_convTrk_nTGCPhiHits;   //!
      TBranch        *b_ph_vx_convTrk_nMdtHoles;   //!
      TBranch        *b_ph_vx_convTrk_nCscEtaHoles;   //!
      TBranch        *b_ph_vx_convTrk_nCscPhiHoles;   //!
      TBranch        *b_ph_vx_convTrk_nRpcEtaHoles;   //!
      TBranch        *b_ph_vx_convTrk_nRpcPhiHoles;   //!
      TBranch        *b_ph_vx_convTrk_nTgcEtaHoles;   //!
      TBranch        *b_ph_vx_convTrk_nTgcPhiHoles;   //!
      TBranch        *b_ph_vx_convTrk_nHits;   //!
      TBranch        *b_ph_vx_convTrk_nHoles;   //!
      TBranch        *b_ph_vx_convTrk_hitPattern;   //!
      TBranch        *b_ph_vx_convTrk_nSiHits;   //!
      TBranch        *b_ph_vx_convTrk_TRTHighTHitsRatio;   //!
      TBranch        *b_ph_vx_convTrk_TRTHighTOutliersRatio;   //!
      TBranch        *b_ph_vx_convTrk_eProbabilityComb;   //!
      TBranch        *b_ph_vx_convTrk_eProbabilityHT;   //!
      TBranch        *b_ph_vx_convTrk_eProbabilityToT;   //!
      TBranch        *b_ph_vx_convTrk_eProbabilityBrem;   //!
      TBranch        *b_ph_vx_convTrk_chi2;   //!
      TBranch        *b_ph_vx_convTrk_ndof;   //!
      TBranch        *b_ph_deltaEmax2;   //!
      TBranch        *b_ph_calibHitsShowerDepth;   //!
      TBranch        *b_ph_isIso;   //!
      TBranch        *b_ph_mvaptcone20;   //!
      TBranch        *b_ph_mvaptcone30;   //!
      TBranch        *b_ph_mvaptcone40;   //!
      TBranch        *b_ph_topoEtcone60;   //!
      TBranch        *b_ph_vx_Chi2;   //!
      TBranch        *b_ph_vx_Dcottheta;   //!
      TBranch        *b_ph_vx_Dphi;   //!
      TBranch        *b_ph_vx_Dist;   //!
      TBranch        *b_ph_vx_DR1R2;   //!
      TBranch        *b_ph_CaloPointing_eta;   //!
      TBranch        *b_ph_CaloPointing_sigma_eta;   //!
      TBranch        *b_ph_CaloPointing_zvertex;   //!
      TBranch        *b_ph_CaloPointing_sigma_zvertex;   //!
      TBranch        *b_ph_HPV_eta;   //!
      TBranch        *b_ph_HPV_sigma_eta;   //!
      TBranch        *b_ph_HPV_zvertex;   //!
      TBranch        *b_ph_HPV_sigma_zvertex;   //!
      TBranch        *b_ph_NN_passes;   //!
      TBranch        *b_ph_NN_discriminant;   //!
      TBranch        *b_ph_ES0_real;   //!
      TBranch        *b_ph_ES1_real;   //!
      TBranch        *b_ph_ES2_real;   //!
      TBranch        *b_ph_ES3_real;   //!
      TBranch        *b_ph_EcellS0;   //!
      TBranch        *b_ph_etacellS0;   //!
      TBranch        *b_ph_Etcone40_ED_corrected;   //!
      TBranch        *b_ph_Etcone40_corrected;   //!
      TBranch        *b_ph_topoEtcone20_corrected;   //!
      TBranch        *b_ph_topoEtcone30_corrected;   //!
      TBranch        *b_ph_topoEtcone40_corrected;   //!
      TBranch        *b_ph_ED_median;   //!
      TBranch        *b_ph_ED_sigma;   //!
      TBranch        *b_ph_ED_Njets;   //!
      TBranch        *b_ph_convIP;   //!
      TBranch        *b_ph_convIPRev;   //!
      TBranch        *b_ph_el_index;   //!
      TBranch        *b_ph_EF_dr;   //!
      TBranch        *b_ph_EF_index;   //!
      TBranch        *b_ph_L2_dr;   //!
      TBranch        *b_ph_L1_dr;   //!
      TBranch        *b_ph_L1_index;   //!

};

#endif

#ifdef extractor_cxx
void extractor::Init(TTree *tree) {
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   mb_E = 0;
   mb_eta = 0;
   mb_phi = 0;
   mb_time = 0;
   mb_quality = 0;
   mb_type = 0;
   mb_module = 0;
   mb_channel = 0;
   Zdc_Energy_Vec = 0;
   Zdc_Time_Vec = 0;
   Zdc_Vec_Size = 0;
   Zdc_Energy_LG = 0;
   Zdc_Time_LG = 0;
   Zdc_Energy_HG = 0;
   Zdc_Time_HG = 0;
   Zdc_Id = 0;
   Zdc_Side = 0;
   Zdc_Type = 0;
   Zdc_Module = 0;
   Zdc_Channel = 0;
   Zdc_TimeCalib = 0;
   Zdc_RecMethod = 0;
   ZdcDigits_dig_g0d0 = 0;
   ZdcDigits_dig_g0d1 = 0;
   ZdcDigits_dig_g1d0 = 0;
   ZdcDigits_dig_g1d1 = 0;
   ZdcDigits_Id = 0;
   ZdcDigits_Side = 0;
   ZdcDigits_Type = 0;
   ZdcDigits_Module = 0;
   ZdcDigits_Channel = 0;
   ZdcReco_EA = 0;
   ZdcReco_EC = 0;
   ZdcReco_qA = 0;
   ZdcReco_qC = 0;
   cc_fcal_E = 0;
   cc_fcal_pt = 0;
   cc_fcal_eta = 0;
   cc_fcal_phi = 0;
   cc_fcal_QCells = 0;
   cc_fcal_GainCells = 0;
   cc_fcal_DetCells = 0;
   cc_fcal_TimeCells = 0;
   cc_fcal_xCells = 0;
   cc_fcal_yCells = 0;
   cc_fcal_zCells = 0;
   cc_fcal_BadCells = 0;
   cc_fcal_IdCells = 0;
   cc_fcal_Sigma = 0;
	 
   TotalEt_layer_eta = 0;
   //TotalEt_layer_phi = 0;
   TotalEt_layer_towerEt = 0;
   TotalEt_layer_sampling = 0;
   //TotalEt_layer_sampling_calib = 0;
	 
   ccc_Eh_PresB = 0;
   ccc_Eh_EMB = 0;
   ccc_Eh_EMEC = 0;
   ccc_Eh_Tile = 0;
   ccc_Eh_TileGap = 0;
   ccc_Eh_HEC = 0;
   ccc_Eh_FCal = 0;
   ccc_Eh_PresE = 0;
   ccc_Eh_Scint = 0;
   cccEt_Et_Eh_PresB = 0;
   cccEt_Et_Eh_EMB = 0;
   cccEt_Et_Eh_EMEC = 0;
   cccEt_Et_Eh_Tile = 0;
   cccEt_Et_Eh_TileGap = 0;
   cccEt_Et_Eh_HEC = 0;
   cccEt_Et_Eh_FCal = 0;
   cccEt_Et_Eh_PresE = 0;
   cccEt_Et_Eh_Scint = 0;
   cccEt_p_Eh_PresB = 0;
   cccEt_p_Eh_EMB = 0;
   cccEt_p_Eh_EMEC = 0;
   cccEt_p_Eh_Tile = 0;
   cccEt_p_Eh_TileGap = 0;
   cccEt_p_Eh_HEC = 0;
   cccEt_p_Eh_FCal = 0;
   cccEt_p_Eh_PresE = 0;
   cccEt_p_Eh_Scint = 0;
   cccEt_n_Eh_PresB = 0;
   cccEt_n_Eh_EMB = 0;
   cccEt_n_Eh_EMEC = 0;
   cccEt_n_Eh_Tile = 0;
   cccEt_n_Eh_TileGap = 0;
   cccEt_n_Eh_HEC = 0;
   cccEt_n_Eh_FCal = 0;
   cccEt_n_Eh_PresE = 0;
   cccEt_n_Eh_Scint = 0;
   trk_d0 = 0;
   trk_z0 = 0;
   trk_phi = 0;
   trk_theta = 0;
   trk_qoverp = 0;
   trk_pt = 0;
   trk_eta = 0;
   trk_err_d0 = 0;
   trk_err_z0 = 0;
   trk_err_phi = 0;
   trk_err_theta = 0;
   trk_err_qoverp = 0;
   trk_cov_d0_z0 = 0;
   trk_cov_d0_phi = 0;
   trk_cov_d0_theta = 0;
   trk_cov_d0_qoverp = 0;
   trk_cov_z0_phi = 0;
   trk_cov_z0_theta = 0;
   trk_cov_z0_qoverp = 0;
   trk_cov_phi_theta = 0;
   trk_cov_phi_qoverp = 0;
   trk_cov_theta_qoverp = 0;
   trk_d0_wrtPV = 0;
   trk_z0_wrtPV = 0;
   trk_phi_wrtPV = 0;
   trk_err_d0_wrtPV = 0;
   trk_err_z0_wrtPV = 0;
   trk_err_phi_wrtPV = 0;
   trk_err_theta_wrtPV = 0;
   trk_err_qoverp_wrtPV = 0;
   trk_cov_d0_z0_wrtPV = 0;
   trk_cov_d0_phi_wrtPV = 0;
   trk_cov_d0_theta_wrtPV = 0;
   trk_cov_d0_qoverp_wrtPV = 0;
   trk_cov_z0_phi_wrtPV = 0;
   trk_cov_z0_theta_wrtPV = 0;
   trk_cov_z0_qoverp_wrtPV = 0;
   trk_cov_phi_theta_wrtPV = 0;
   trk_cov_phi_qoverp_wrtPV = 0;
   trk_cov_theta_qoverp_wrtPV = 0;
   trk_d0_wrtBS = 0;
   trk_z0_wrtBS = 0;
   trk_phi_wrtBS = 0;
   trk_err_d0_wrtBS = 0;
   trk_err_z0_wrtBS = 0;
   trk_err_phi_wrtBS = 0;
   trk_err_theta_wrtBS = 0;
   trk_err_qoverp_wrtBS = 0;
   trk_cov_d0_z0_wrtBS = 0;
   trk_cov_d0_phi_wrtBS = 0;
   trk_cov_d0_theta_wrtBS = 0;
   trk_cov_d0_qoverp_wrtBS = 0;
   trk_cov_z0_phi_wrtBS = 0;
   trk_cov_z0_theta_wrtBS = 0;
   trk_cov_z0_qoverp_wrtBS = 0;
   trk_cov_phi_theta_wrtBS = 0;
   trk_cov_phi_qoverp_wrtBS = 0;
   trk_cov_theta_qoverp_wrtBS = 0;
   trk_d0_wrtBL = 0;
   trk_z0_wrtBL = 0;
   trk_phi_wrtBL = 0;
   trk_d0_err_wrtBL = 0;
   trk_z0_err_wrtBL = 0;
   trk_phi_err_wrtBL = 0;
   trk_theta_err_wrtBL = 0;
   trk_qoverp_err_wrtBL = 0;
   trk_d0_z0_err_wrtBL = 0;
   trk_d0_phi_err_wrtBL = 0;
   trk_d0_theta_err_wrtBL = 0;
   trk_d0_qoverp_err_wrtBL = 0;
   trk_z0_phi_err_wrtBL = 0;
   trk_z0_theta_err_wrtBL = 0;
   trk_z0_qoverp_err_wrtBL = 0;
   trk_phi_theta_err_wrtBL = 0;
   trk_phi_qoverp_err_wrtBL = 0;
   trk_theta_qoverp_err_wrtBL = 0;
   trk_chi2 = 0;
   trk_ndof = 0;
   trk_nBLHits = 0;
   trk_nPixHits = 0;
   trk_nSCTHits = 0;
   trk_nTRTHits = 0;
   trk_nTRTHighTHits = 0;
   trk_nTRTXenonHits = 0;
   trk_nPixHoles = 0;
   trk_nSCTHoles = 0;
   trk_nTRTHoles = 0;
   trk_nPixelDeadSensors = 0;
   trk_nSCTDeadSensors = 0;
   trk_nBLSharedHits = 0;
   trk_nPixSharedHits = 0;
   trk_nSCTSharedHits = 0;
   trk_nBLayerSplitHits = 0;
   trk_nPixSplitHits = 0;
   trk_expectBLayerHit = 0;
   trk_nMDTHits = 0;
   trk_nCSCEtaHits = 0;
   trk_nCSCPhiHits = 0;
   trk_nRPCEtaHits = 0;
   trk_nRPCPhiHits = 0;
   trk_nTGCEtaHits = 0;
   trk_nTGCPhiHits = 0;
   trk_nHits = 0;
   trk_nHoles = 0;
   trk_hitPattern = 0;
   trk_TRTHighTHitsRatio = 0;
   trk_TRTHighTOutliersRatio = 0;
   trk_pixeldEdx = 0;
   trk_nGoodHitsPixeldEdx = 0;
   trk_massPixeldEdx = 0;
   trk_likelihoodsPixeldEdx = 0;
   trk_fitter = 0;
   trk_patternReco1 = 0;
   trk_patternReco2 = 0;
   trk_trackProperties = 0;
   trk_particleHypothesis = 0;
   trk_blayerPrediction_x = 0;
   trk_blayerPrediction_y = 0;
   trk_blayerPrediction_z = 0;
   trk_blayerPrediction_locX = 0;
   trk_blayerPrediction_locY = 0;
   trk_blayerPrediction_err_locX = 0;
   trk_blayerPrediction_err_locY = 0;
   trk_blayerPrediction_etaDistToEdge = 0;
   trk_blayerPrediction_phiDistToEdge = 0;
   trk_blayerPrediction_detElementId = 0;
   trk_blayerPrediction_row = 0;
   trk_blayerPrediction_col = 0;
   trk_blayerPrediction_type = 0;
   trkPix_d0 = 0;
   trkPix_z0 = 0;
   trkPix_phi = 0;
   trkPix_theta = 0;
   trkPix_qoverp = 0;
   trkPix_pt = 0;
   trkPix_eta = 0;
   trkPix_err_d0 = 0;
   trkPix_err_z0 = 0;
   trkPix_err_phi = 0;
   trkPix_err_theta = 0;
   trkPix_err_qoverp = 0;
   trkPix_cov_d0_z0 = 0;
   trkPix_cov_d0_phi = 0;
   trkPix_cov_d0_theta = 0;
   trkPix_cov_d0_qoverp = 0;
   trkPix_cov_z0_phi = 0;
   trkPix_cov_z0_theta = 0;
   trkPix_cov_z0_qoverp = 0;
   trkPix_cov_phi_theta = 0;
   trkPix_cov_phi_qoverp = 0;
   trkPix_cov_theta_qoverp = 0;
   trkPix_d0_wrtPV = 0;
   trkPix_z0_wrtPV = 0;
   trkPix_phi_wrtPV = 0;
   trkPix_err_d0_wrtPV = 0;
   trkPix_err_z0_wrtPV = 0;
   trkPix_err_phi_wrtPV = 0;
   trkPix_err_theta_wrtPV = 0;
   trkPix_err_qoverp_wrtPV = 0;
   trkPix_cov_d0_z0_wrtPV = 0;
   trkPix_cov_d0_phi_wrtPV = 0;
   trkPix_cov_d0_theta_wrtPV = 0;
   trkPix_cov_d0_qoverp_wrtPV = 0;
   trkPix_cov_z0_phi_wrtPV = 0;
   trkPix_cov_z0_theta_wrtPV = 0;
   trkPix_cov_z0_qoverp_wrtPV = 0;
   trkPix_cov_phi_theta_wrtPV = 0;
   trkPix_cov_phi_qoverp_wrtPV = 0;
   trkPix_cov_theta_qoverp_wrtPV = 0;
   trkPix_d0_wrtBS = 0;
   trkPix_z0_wrtBS = 0;
   trkPix_phi_wrtBS = 0;
   trkPix_err_d0_wrtBS = 0;
   trkPix_err_z0_wrtBS = 0;
   trkPix_err_phi_wrtBS = 0;
   trkPix_err_theta_wrtBS = 0;
   trkPix_err_qoverp_wrtBS = 0;
   trkPix_cov_d0_z0_wrtBS = 0;
   trkPix_cov_d0_phi_wrtBS = 0;
   trkPix_cov_d0_theta_wrtBS = 0;
   trkPix_cov_d0_qoverp_wrtBS = 0;
   trkPix_cov_z0_phi_wrtBS = 0;
   trkPix_cov_z0_theta_wrtBS = 0;
   trkPix_cov_z0_qoverp_wrtBS = 0;
   trkPix_cov_phi_theta_wrtBS = 0;
   trkPix_cov_phi_qoverp_wrtBS = 0;
   trkPix_cov_theta_qoverp_wrtBS = 0;
   trkPix_d0_wrtBL = 0;
   trkPix_z0_wrtBL = 0;
   trkPix_phi_wrtBL = 0;
   trkPix_d0_err_wrtBL = 0;
   trkPix_z0_err_wrtBL = 0;
   trkPix_phi_err_wrtBL = 0;
   trkPix_theta_err_wrtBL = 0;
   trkPix_qoverp_err_wrtBL = 0;
   trkPix_d0_z0_err_wrtBL = 0;
   trkPix_d0_phi_err_wrtBL = 0;
   trkPix_d0_theta_err_wrtBL = 0;
   trkPix_d0_qoverp_err_wrtBL = 0;
   trkPix_z0_phi_err_wrtBL = 0;
   trkPix_z0_theta_err_wrtBL = 0;
   trkPix_z0_qoverp_err_wrtBL = 0;
   trkPix_phi_theta_err_wrtBL = 0;
   trkPix_phi_qoverp_err_wrtBL = 0;
   trkPix_theta_qoverp_err_wrtBL = 0;
   trkPix_chi2 = 0;
   trkPix_ndof = 0;
   trkPix_nBLHits = 0;
   trkPix_nPixHits = 0;
   trkPix_nSCTHits = 0;
   trkPix_nTRTHits = 0;
   trkPix_nTRTHighTHits = 0;
   trkPix_nTRTXenonHits = 0;
   trkPix_nPixHoles = 0;
   trkPix_nSCTHoles = 0;
   trkPix_nTRTHoles = 0;
   trkPix_nPixelDeadSensors = 0;
   trkPix_nSCTDeadSensors = 0;
   trkPix_nBLSharedHits = 0;
   trkPix_nPixSharedHits = 0;
   trkPix_nSCTSharedHits = 0;
   trkPix_nBLayerSplitHits = 0;
   trkPix_nPixSplitHits = 0;
   trkPix_expectBLayerHit = 0;
   trkPix_nMDTHits = 0;
   trkPix_nCSCEtaHits = 0;
   trkPix_nCSCPhiHits = 0;
   trkPix_nRPCEtaHits = 0;
   trkPix_nRPCPhiHits = 0;
   trkPix_nTGCEtaHits = 0;
   trkPix_nTGCPhiHits = 0;
   trkPix_nHits = 0;
   trkPix_nHoles = 0;
   trkPix_hitPattern = 0;
   trkPix_TRTHighTHitsRatio = 0;
   trkPix_TRTHighTOutliersRatio = 0;
   trkPix_pixeldEdx = 0;
   trkPix_nGoodHitsPixeldEdx = 0;
   trkPix_massPixeldEdx = 0;
   trkPix_likelihoodsPixeldEdx = 0;
   trkPix_fitter = 0;
   trkPix_patternReco1 = 0;
   trkPix_patternReco2 = 0;
   trkPix_trackProperties = 0;
   trkPix_particleHypothesis = 0;
   trkPix_blayerPrediction_x = 0;
   trkPix_blayerPrediction_y = 0;
   trkPix_blayerPrediction_z = 0;
   trkPix_blayerPrediction_locX = 0;
   trkPix_blayerPrediction_locY = 0;
   trkPix_blayerPrediction_err_locX = 0;
   trkPix_blayerPrediction_err_locY = 0;
   trkPix_blayerPrediction_etaDistToEdge = 0;
   trkPix_blayerPrediction_phiDistToEdge = 0;
   trkPix_blayerPrediction_detElementId = 0;
   trkPix_blayerPrediction_row = 0;
   trkPix_blayerPrediction_col = 0;
   trkPix_blayerPrediction_type = 0;
   HIFlow_v1_EtInLayer = 0;
   HIFlow_v1_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers = 0;
   HIFlow_v1_PsiHICaloUtilLayers = 0;
   HIFlow_v1_PsiEtHICaloUtilLayers = 0;
   HIFlow_v1_Meanv2_Psi_From_FCAL0CaloCel_IDLayers = 0;
   HIFlow_v2_EtInLayer = 0;
   HIFlow_v2_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers = 0;
   HIFlow_v2_PsiHICaloUtilLayers = 0;
   HIFlow_v2_PsiEtHICaloUtilLayers = 0;
   HIFlow_v2_Meanv2_Psi_From_FCAL0CaloCel_IDLayers = 0;
   HIFlow_v3_EtInLayer = 0;
   HIFlow_v3_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers = 0;
   HIFlow_v3_PsiHICaloUtilLayers = 0;
   HIFlow_v3_PsiEtHICaloUtilLayers = 0;
   HIFlow_v3_Meanv2_Psi_From_FCAL0CaloCel_IDLayers = 0;
   HIFlow_v4_EtInLayer = 0;
   HIFlow_v4_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers = 0;
   HIFlow_v4_PsiHICaloUtilLayers = 0;
   HIFlow_v4_PsiEtHICaloUtilLayers = 0;
   HIFlow_v4_Meanv2_Psi_From_FCAL0CaloCel_IDLayers = 0;
   HIFlow_v5_EtInLayer = 0;
   HIFlow_v5_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers = 0;
   HIFlow_v5_PsiHICaloUtilLayers = 0;
   HIFlow_v5_PsiEtHICaloUtilLayers = 0;
   HIFlow_v5_Meanv2_Psi_From_FCAL0CaloCel_IDLayers = 0;
   HIFlow_v6_EtInLayer = 0;
   HIFlow_v6_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers = 0;
   HIFlow_v6_PsiHICaloUtilLayers = 0;
   HIFlow_v6_PsiEtHICaloUtilLayers = 0;
   HIFlow_v6_Meanv2_Psi_From_FCAL0CaloCel_IDLayers = 0;
   cccEt2_Et2_Eh_PresB = 0;
   cccEt2_Et2_Eh_EMB = 0;
   cccEt2_Et2_Eh_EMEC = 0;
   cccEt2_Et2_Eh_Tile = 0;
   cccEt2_Et2_Eh_TileGap = 0;
   cccEt2_Et2_Eh_HEC = 0;
   cccEt2_Et2_Eh_FCal = 0;
   cccEt2_Et2_Eh_PresE = 0;
   cccEt2_Et2_Eh_Scint = 0;
   cccEt2_p2_Eh_PresB = 0;
   cccEt2_p2_Eh_EMB = 0;
   cccEt2_p2_Eh_EMEC = 0;
   cccEt2_p2_Eh_Tile = 0;
   cccEt2_p2_Eh_TileGap = 0;
   cccEt2_p2_Eh_HEC = 0;
   cccEt2_p2_Eh_FCal = 0;
   cccEt2_p2_Eh_PresE = 0;
   cccEt2_p2_Eh_Scint = 0;
   cccEt2_n2_Eh_PresB = 0;
   cccEt2_n2_Eh_EMB = 0;
   cccEt2_n2_Eh_EMEC = 0;
   cccEt2_n2_Eh_Tile = 0;
   cccEt2_n2_Eh_TileGap = 0;
   cccEt2_n2_Eh_HEC = 0;
   cccEt2_n2_Eh_FCal = 0;
   cccEt2_n2_Eh_PresE = 0;
   cccEt2_n2_Eh_Scint = 0;
   cl_hadTopo_E = 0;
   cl_hadTopo_pt = 0;
   cl_hadTopo_eta = 0;
   cl_hadTopo_phi = 0;
   cl_hadTopo_E_em = 0;
   cl_hadTopo_E_had = 0;
   cl_hadTopo_significance = 0;
   cl_hadTopo_cellSignificance = 0;
   cl_hadTopo_cellSigSampling = 0;
   cl_hadTopo_firstEdens = 0;
   cl_hadTopo_cellmaxfrac = 0;
   cl_hadTopo_longitudinal = 0;
   cl_hadTopo_secondlambda = 0;
   cl_hadTopo_lateral = 0;
   cl_hadTopo_secondR = 0;
   cl_hadTopo_centerlambda = 0;
   cl_hadTopo_deltaTheta = 0;
   cl_hadTopo_deltaPhi = 0;
   cl_hadTopo_centermag = 0;
   cl_hadTopo_time = 0;
   cl_hadTopo_E_PreSamplerB = 0;
   cl_hadTopo_E_EMB1 = 0;
   cl_hadTopo_E_EMB2 = 0;
   cl_hadTopo_E_EMB3 = 0;
   cl_hadTopo_E_PreSamplerE = 0;
   cl_hadTopo_E_EME1 = 0;
   cl_hadTopo_E_EME2 = 0;
   cl_hadTopo_E_EME3 = 0;
   cl_hadTopo_E_HEC0 = 0;
   cl_hadTopo_E_HEC1 = 0;
   cl_hadTopo_E_HEC2 = 0;
   cl_hadTopo_E_HEC3 = 0;
   cl_hadTopo_E_TileBar0 = 0;
   cl_hadTopo_E_TileBar1 = 0;
   cl_hadTopo_E_TileBar2 = 0;
   cl_hadTopo_E_TileGap1 = 0;
   cl_hadTopo_E_TileGap2 = 0;
   cl_hadTopo_E_TileGap3 = 0;
   cl_hadTopo_E_TileExt0 = 0;
   cl_hadTopo_E_TileExt1 = 0;
   cl_hadTopo_E_TileExt2 = 0;
   cl_hadTopo_E_FCAL0 = 0;
   cl_hadTopo_E_FCAL1 = 0;
   cl_hadTopo_E_FCAL2 = 0;
   HIEtaGap_lowerEta = 0;
   HIEtaGap_upperEta = 0;
   HIEtaGap_lowerEdgeType = 0;
   HIEtaGap_upperEdgeType = 0;
   trig_L1_TAV = 0;
   trig_L2_passedPhysics = 0;
   trig_EF_passedPhysics = 0;
   trig_L1_TBP = 0;
   trig_L1_TAP = 0;
   trig_L2_passedRaw = 0;
   trig_EF_passedRaw = 0;
   trig_L2_resurrected = 0;
   trig_EF_resurrected = 0;
   trig_L2_passedThrough = 0;
   trig_EF_passedThrough = 0;
   trig_L2_wasPrescaled = 0;
   trig_L2_wasResurrected = 0;
   trig_EF_wasPrescaled = 0;
   trig_EF_wasResurrected = 0;
   trig_L1_jet_eta = 0;
   trig_L1_jet_phi = 0;
   trig_L1_jet_thrNames = 0;
   trig_L1_jet_thrValues = 0;
   trig_L1_jet_thrPattern = 0;
   trig_L1_jet_RoIWord = 0;
   trig_L1_jet_et4x4 = 0;
   trig_L1_jet_et6x6 = 0;
   trig_L1_jet_et8x8 = 0;
   trig_L1_emtau_eta = 0;
   trig_L1_emtau_phi = 0;
   trig_L1_emtau_thrNames = 0;
   trig_L1_emtau_thrValues = 0;
   trig_L1_emtau_core = 0;
   trig_L1_emtau_EMClus = 0;
   trig_L1_emtau_tauClus = 0;
   trig_L1_emtau_EMIsol = 0;
   trig_L1_emtau_hadIsol = 0;
   trig_L1_emtau_hadCore = 0;
   trig_L1_emtau_thrPattern = 0;
   trig_L1_emtau_RoIWord = 0;
   trig_L1_mu_pt = 0;
   trig_L1_mu_eta = 0;
   trig_L1_mu_phi = 0;
   trig_L1_mu_thrName = 0;
   trig_L1_mu_thrNumber = 0;
   trig_L1_mu_RoINumber = 0;
   trig_L1_mu_sectorAddress = 0;
   trig_L1_mu_firstCandidate = 0;
   trig_L1_mu_moreCandInRoI = 0;
   trig_L1_mu_moreCandInSector = 0;
   trig_L1_mu_source = 0;
   trig_L1_mu_hemisphere = 0;
   trig_L1_mu_charge = 0;
   trig_L1_mu_vetoed = 0;
   trig_L1_mu_RoIWord = 0;
   trig_EF_jet_E = 0;
   trig_EF_jet_pt = 0;
   trig_EF_jet_m = 0;
   trig_EF_jet_eta = 0;
   trig_EF_jet_phi = 0;
   trig_EF_jet_a4tcem = 0;
   trig_EF_jet_a2tcem = 0;
   trig_EF_jet_a4tchad = 0;
   trig_EF_jet_a4hi = 0;
   trig_EF_jet_a2hi = 0;
   trig_EF_jet_RoIword = 0;
   trig_EF_jet_EF_2j0_a4tcem_deta40 = 0;
   trig_EF_jet_EF_2j10_a4hi_EFFS_2L1J5 = 0;
   trig_EF_jet_EF_2j10_a4hi_EFFS_2L1J5_L1TE90 = 0;
   trig_EF_jet_EF_2j10_a4hi_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_2j10_a4hi_EFFS_L1TE100 = 0;
   trig_EF_jet_EF_2j10_a4hi_EFFS_L1TE90 = 0;
   trig_EF_jet_EF_2j10_a4hi_deta40_L1MBTS = 0;
   trig_EF_jet_EF_2j10_a4hi_eta50_deta40 = 0;
   trig_EF_jet_EF_2j10_a4hi_eta50_deta40_L1MBTS = 0;
   trig_EF_jet_EF_2j10_a4tcem_EFFS_2L1J5 = 0;
   trig_EF_jet_EF_2j10_a4tcem_deta40 = 0;
   trig_EF_jet_EF_2j10_a4tcem_eta50_deta40 = 0;
   trig_EF_jet_EF_2j10_a4tchad_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_2j10_a4tchad_deta40_L1MBTS = 0;
   trig_EF_jet_EF_2j10_a4tchad_eta50_deta40_L1MBTS = 0;
   trig_EF_jet_EF_2j15_a4hi_EFFS_2L1J5 = 0;
   trig_EF_jet_EF_2j15_a4hi_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_2j15_a4hi_deta40_L1MBTS = 0;
   trig_EF_jet_EF_2j15_a4hi_eta50_deta40 = 0;
   trig_EF_jet_EF_2j15_a4hi_eta50_deta40_L1MBTS = 0;
   trig_EF_jet_EF_2j15_a4tcem_EFFS_2L1J5 = 0;
   trig_EF_jet_EF_2j15_a4tcem_deta40 = 0;
   trig_EF_jet_EF_2j15_a4tcem_eta50_deta40 = 0;
   trig_EF_jet_EF_2j15_a4tchad_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_2j15_a4tchad_deta40_L1MBTS = 0;
   trig_EF_jet_EF_2j15_a4tchad_eta50_deta40_L1MBTS = 0;
   trig_EF_jet_EF_2j20_a4hi_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_2j20_a4tchad_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_2j7_a4hi_EFFS_2L1J5 = 0;
   trig_EF_jet_EF_2j7_a4hi_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_2j7_a4hi_deta40_L1MBTS = 0;
   trig_EF_jet_EF_2j7_a4hi_eta50_deta40 = 0;
   trig_EF_jet_EF_2j7_a4hi_eta50_deta40_L1MBTS = 0;
   trig_EF_jet_EF_2j7_a4tcem_EFFS_2L1J5 = 0;
   trig_EF_jet_EF_2j7_a4tcem_deta40 = 0;
   trig_EF_jet_EF_2j7_a4tcem_eta50_deta40 = 0;
   trig_EF_jet_EF_2j7_a4tchad_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_2j7_a4tchad_deta40_L1MBTS = 0;
   trig_EF_jet_EF_2j7_a4tchad_eta50_deta40_L1MBTS = 0;
   trig_EF_jet_EF_fj10_a4hi_EFFS_L1FJ0 = 0;
   trig_EF_jet_EF_fj10_a4tchad_EFFS_L1FJ0 = 0;
   trig_EF_jet_EF_fj15_a4hi_EFFS_L1FJ0 = 0;
   trig_EF_jet_EF_fj15_a4tchad_EFFS_L1FJ0 = 0;
   trig_EF_jet_EF_fj7_a4hi_EFFS_L1FJ0 = 0;
   trig_EF_jet_EF_fj7_a4hi_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_fj7_a4tchad_EFFS_L1FJ0 = 0;
   trig_EF_jet_EF_fj7_a4tchad_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_j10_a4hi_EFFS_L1EM3 = 0;
   trig_EF_jet_EF_j10_a4hi_EFFS_L1J5 = 0;
   trig_EF_jet_EF_j10_a4hi_EFFS_L1J5_L1TE90 = 0;
   trig_EF_jet_EF_j10_a4hi_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_j10_a4hi_EFFS_L1TAU3 = 0;
   trig_EF_jet_EF_j10_a4hi_EFFS_L1TE100 = 0;
   trig_EF_jet_EF_j10_a4hi_EFFS_L1TE90 = 0;
   trig_EF_jet_EF_j10_a4tcem_EFFS_L1EM3 = 0;
   trig_EF_jet_EF_j10_a4tcem_EFFS_L1J5 = 0;
   trig_EF_jet_EF_j10_a4tcem_EFFS_L1J5_win6 = 0;
   trig_EF_jet_EF_j10_a4tcem_EFFS_L1TAU3 = 0;
   trig_EF_jet_EF_j10_a4tchad_EFFS_L1J5 = 0;
   trig_EF_jet_EF_j10_a4tchad_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_j10_u0uchad_LArNoiseBurst = 0;
   trig_EF_jet_EF_j10_u0uchad_empty_LArNoiseBurst = 0;
   trig_EF_jet_EF_j10_u0uchad_firstempty_LArNoiseBurst = 0;
   trig_EF_jet_EF_j15_a2tcem_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j15_a2tcem_EFFS_L1J5 = 0;
   trig_EF_jet_EF_j15_a4hi_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j15_a4hi_EFFS_L1J5 = 0;
   trig_EF_jet_EF_j15_a4hi_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_j15_a4tcem_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j15_a4tcem_EFFS_L1J5 = 0;
   trig_EF_jet_EF_j15_a4tchad_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_j20_a4hi_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j20_a4hi_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_j20_a4tcem_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j20_a4tcem_EFFS_L1J5 = 0;
   trig_EF_jet_EF_j20_a4tchad_EFFS_L1J5 = 0;
   trig_EF_jet_EF_j20_a4tchad_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_j25_a4hi_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j25_a4tcem_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j30_a4hi_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j30_a4hi_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_j30_a4tcem_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j30_a4tcem_EFFS_L1J5 = 0;
   trig_EF_jet_EF_j30_a4tchad_EFFS_L1J5 = 0;
   trig_EF_jet_EF_j30_a4tchad_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_j30_u0uchad_empty_LArNoiseBurst = 0;
   trig_EF_jet_EF_j35_a4hi_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j35_a4tcem_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j40_a4hi_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j40_a4hi_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_j40_a4tcem_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j40_a4tcem_EFFS_L1J5 = 0;
   trig_EF_jet_EF_j40_a4tchad_EFFS_L1J5 = 0;
   trig_EF_jet_EF_j40_a4tchad_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_j45_a4hi_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j45_a4tcem_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j50_a4hi_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j50_a4hi_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_j50_a4tcem_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j50_a4tcem_EFFS_L1J15 = 0;
   trig_EF_jet_EF_j50_a4tchad_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j50_a4tchad_EFFS_L1J15 = 0;
   trig_EF_jet_EF_j50_a4tchad_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_j60_a4tcem_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j60_a4tcem_EFFS_L1J15 = 0;
   trig_EF_jet_EF_j60_a4tchad_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j60_a4tchad_EFFS_L1J15 = 0;
   trig_EF_jet_EF_j75_a4hi_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j75_a4tcem_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j75_a4tcem_EFFS_L1J15 = 0;
   trig_EF_jet_EF_j75_a4tchad_EFFS_L1J10 = 0;
   trig_EF_jet_EF_j75_a4tchad_EFFS_L1J15 = 0;
   trig_EF_jet_EF_j7_a4hi_EFFS_L1EM3 = 0;
   trig_EF_jet_EF_j7_a4hi_EFFS_L1J5 = 0;
   trig_EF_jet_EF_j7_a4hi_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_j7_a4hi_EFFS_L1TAU3 = 0;
   trig_EF_jet_EF_j7_a4tcem_EFFS_L1EM3 = 0;
   trig_EF_jet_EF_j7_a4tcem_EFFS_L1J5 = 0;
   trig_EF_jet_EF_j7_a4tcem_EFFS_L1J5_win6 = 0;
   trig_EF_jet_EF_j7_a4tcem_EFFS_L1TAU3 = 0;
   trig_EF_jet_EF_j7_a4tchad_EFFS_L1J5 = 0;
   trig_EF_jet_EF_j7_a4tchad_EFFS_L1MBTS = 0;
   trig_EF_jet_EF_j80_a4tchad_EFFS_L1J15 = 0;
   trig_EF_jet_EF_j90_a4tchad_EFFS_L1J15 = 0;
   trig_L1_esum_thrNames = 0;
   trig_EF_met_nameOfComponent = 0;
   trig_EF_met_MExComponent = 0;
   trig_EF_met_MEyComponent = 0;
   trig_EF_met_MEzComponent = 0;
   trig_EF_met_sumEtComponent = 0;
   trig_EF_met_sumEComponent = 0;
   trig_EF_met_componentCalib0 = 0;
   trig_EF_met_componentCalib1 = 0;
   trig_EF_met_sumOfSigns = 0;
   trig_EF_met_usedChannels = 0;
   trig_EF_met_status = 0;
   trig_EF_ph_E = 0;
   trig_EF_ph_Et = 0;
   trig_EF_ph_pt = 0;
   trig_EF_ph_m = 0;
   trig_EF_ph_eta = 0;
   trig_EF_ph_phi = 0;
   trig_EF_ph_px = 0;
   trig_EF_ph_py = 0;
   trig_EF_ph_pz = 0;
   trig_EF_ph_author = 0;
   trig_EF_ph_isRecovered = 0;
   trig_EF_ph_isEM = 0;
   trig_EF_ph_isEMLoose = 0;
   trig_EF_ph_isEMMedium = 0;
   trig_EF_ph_isEMTight = 0;
   trig_EF_ph_convFlag = 0;
   trig_EF_ph_isConv = 0;
   trig_EF_ph_nConv = 0;
   trig_EF_ph_nSingleTrackConv = 0;
   trig_EF_ph_nDoubleTrackConv = 0;
   trig_EF_ph_loose = 0;
   trig_EF_ph_looseIso = 0;
   trig_EF_ph_tight = 0;
   trig_EF_ph_tightIso = 0;
   trig_EF_ph_looseAR = 0;
   trig_EF_ph_looseARIso = 0;
   trig_EF_ph_tightAR = 0;
   trig_EF_ph_tightARIso = 0;
   trig_EF_ph_Ethad = 0;
   trig_EF_ph_Ethad1 = 0;
   trig_EF_ph_E033 = 0;
   trig_EF_ph_f1 = 0;
   trig_EF_ph_f1core = 0;
   trig_EF_ph_Emins1 = 0;
   trig_EF_ph_fside = 0;
   trig_EF_ph_Emax2 = 0;
   trig_EF_ph_ws3 = 0;
   trig_EF_ph_wstot = 0;
   trig_EF_ph_E132 = 0;
   trig_EF_ph_E1152 = 0;
   trig_EF_ph_emaxs1 = 0;
   trig_EF_ph_deltaEs = 0;
   trig_EF_ph_E233 = 0;
   trig_EF_ph_E237 = 0;
   trig_EF_ph_E277 = 0;
   trig_EF_ph_weta2 = 0;
   trig_EF_ph_f3 = 0;
   trig_EF_ph_f3core = 0;
   trig_EF_ph_rphiallcalo = 0;
   trig_EF_ph_Etcone45 = 0;
   trig_EF_ph_Etcone15 = 0;
   trig_EF_ph_Etcone20 = 0;
   trig_EF_ph_Etcone25 = 0;
   trig_EF_ph_Etcone30 = 0;
   trig_EF_ph_Etcone35 = 0;
   trig_EF_ph_Etcone40 = 0;
   trig_EF_ph_ptcone20 = 0;
   trig_EF_ph_ptcone30 = 0;
   trig_EF_ph_ptcone40 = 0;
   trig_EF_ph_convanglematch = 0;
   trig_EF_ph_convtrackmatch = 0;
   trig_EF_ph_hasconv = 0;
   trig_EF_ph_convvtxx = 0;
   trig_EF_ph_convvtxy = 0;
   trig_EF_ph_convvtxz = 0;
   trig_EF_ph_Rconv = 0;
   trig_EF_ph_zconv = 0;
   trig_EF_ph_convvtxchi2 = 0;
   trig_EF_ph_pt1conv = 0;
   trig_EF_ph_convtrk1nBLHits = 0;
   trig_EF_ph_convtrk1nPixHits = 0;
   trig_EF_ph_convtrk1nSCTHits = 0;
   trig_EF_ph_convtrk1nTRTHits = 0;
   trig_EF_ph_pt2conv = 0;
   trig_EF_ph_convtrk2nBLHits = 0;
   trig_EF_ph_convtrk2nPixHits = 0;
   trig_EF_ph_convtrk2nSCTHits = 0;
   trig_EF_ph_convtrk2nTRTHits = 0;
   trig_EF_ph_ptconv = 0;
   trig_EF_ph_pzconv = 0;
   trig_EF_ph_reta = 0;
   trig_EF_ph_rphi = 0;
   trig_EF_ph_cl_E = 0;
   trig_EF_ph_cl_pt = 0;
   trig_EF_ph_cl_eta = 0;
   trig_EF_ph_cl_phi = 0;
   trig_EF_ph_cl_etas2 = 0;
   trig_EF_el_E = 0;
   trig_EF_el_Et = 0;
   trig_EF_el_pt = 0;
   trig_EF_el_m = 0;
   trig_EF_el_eta = 0;
   trig_EF_el_phi = 0;
   trig_EF_el_px = 0;
   trig_EF_el_py = 0;
   trig_EF_el_pz = 0;
   trig_EF_el_charge = 0;
   trig_EF_el_author = 0;
   trig_EF_el_isEM = 0;
   trig_EF_el_isEMLoose = 0;
   trig_EF_el_isEMMedium = 0;
   trig_EF_el_isEMTight = 0;
   trig_EF_el_loose = 0;
   trig_EF_el_looseIso = 0;
   trig_EF_el_medium = 0;
   trig_EF_el_mediumIso = 0;
   trig_EF_el_mediumWithoutTrack = 0;
   trig_EF_el_mediumIsoWithoutTrack = 0;
   trig_EF_el_tight = 0;
   trig_EF_el_tightIso = 0;
   trig_EF_el_tightWithoutTrack = 0;
   trig_EF_el_tightIsoWithoutTrack = 0;
   trig_EF_el_loosePP = 0;
   trig_EF_el_loosePPIso = 0;
   trig_EF_el_mediumPP = 0;
   trig_EF_el_mediumPPIso = 0;
   trig_EF_el_tightPP = 0;
   trig_EF_el_tightPPIso = 0;
   trig_EF_el_Ethad = 0;
   trig_EF_el_Ethad1 = 0;
   trig_EF_el_f1 = 0;
   trig_EF_el_f1core = 0;
   trig_EF_el_Emins1 = 0;
   trig_EF_el_fside = 0;
   trig_EF_el_Emax2 = 0;
   trig_EF_el_ws3 = 0;
   trig_EF_el_wstot = 0;
   trig_EF_el_emaxs1 = 0;
   trig_EF_el_deltaEs = 0;
   trig_EF_el_E233 = 0;
   trig_EF_el_E237 = 0;
   trig_EF_el_E277 = 0;
   trig_EF_el_weta2 = 0;
   trig_EF_el_f3 = 0;
   trig_EF_el_f3core = 0;
   trig_EF_el_rphiallcalo = 0;
   trig_EF_el_Etcone45 = 0;
   trig_EF_el_Etcone15 = 0;
   trig_EF_el_Etcone20 = 0;
   trig_EF_el_Etcone25 = 0;
   trig_EF_el_Etcone30 = 0;
   trig_EF_el_Etcone35 = 0;
   trig_EF_el_Etcone40 = 0;
   trig_EF_el_ptcone20 = 0;
   trig_EF_el_ptcone30 = 0;
   trig_EF_el_ptcone40 = 0;
   trig_EF_el_pos7 = 0;
   trig_EF_el_etacorrmag = 0;
   trig_EF_el_deltaeta1 = 0;
   trig_EF_el_deltaeta2 = 0;
   trig_EF_el_deltaphi2 = 0;
   trig_EF_el_expectHitInBLayer = 0;
   trig_EF_el_trackd0_physics = 0;
   trig_EF_el_reta = 0;
   trig_EF_el_rphi = 0;
   trig_EF_el_EtringnoisedR03sig2 = 0;
   trig_EF_el_EtringnoisedR03sig3 = 0;
   trig_EF_el_EtringnoisedR03sig4 = 0;
   trig_EF_el_isolationlikelihoodjets = 0;
   trig_EF_el_isolationlikelihoodhqelectrons = 0;
   trig_EF_el_electronweight = 0;
   trig_EF_el_electronbgweight = 0;
   trig_EF_el_softeweight = 0;
   trig_EF_el_softebgweight = 0;
   trig_EF_el_neuralnet = 0;
   trig_EF_el_Hmatrix = 0;
   trig_EF_el_Hmatrix5 = 0;
   trig_EF_el_adaboost = 0;
   trig_EF_el_softeneuralnet = 0;
   trig_EF_el_zvertex = 0;
   trig_EF_el_errz = 0;
   trig_EF_el_etap = 0;
   trig_EF_el_depth = 0;
   trig_EF_el_Es0 = 0;
   trig_EF_el_etas0 = 0;
   trig_EF_el_phis0 = 0;
   trig_EF_el_Es1 = 0;
   trig_EF_el_etas1 = 0;
   trig_EF_el_phis1 = 0;
   trig_EF_el_Es2 = 0;
   trig_EF_el_etas2 = 0;
   trig_EF_el_phis2 = 0;
   trig_EF_el_Es3 = 0;
   trig_EF_el_etas3 = 0;
   trig_EF_el_phis3 = 0;
   trig_EF_el_cl_E = 0;
   trig_EF_el_cl_pt = 0;
   trig_EF_el_cl_eta = 0;
   trig_EF_el_cl_phi = 0;
   trig_EF_el_trackd0 = 0;
   trig_EF_el_trackz0 = 0;
   trig_EF_el_trackphi = 0;
   trig_EF_el_tracktheta = 0;
   trig_EF_el_trackqoverp = 0;
   trig_EF_el_trackpt = 0;
   trig_EF_el_tracketa = 0;
   trig_EF_el_trackfitchi2 = 0;
   trig_EF_el_trackfitndof = 0;
   trig_EF_el_nBLHits = 0;
   trig_EF_el_nPixHits = 0;
   trig_EF_el_nSCTHits = 0;
   trig_EF_el_nTRTHits = 0;
   trig_EF_el_nTRTHighTHits = 0;
   trig_EF_el_nTRTXenonHits = 0;
   trig_EF_el_nPixHoles = 0;
   trig_EF_el_nSCTHoles = 0;
   trig_EF_el_nTRTHoles = 0;
   trig_EF_el_nPixelDeadSensors = 0;
   trig_EF_el_nSCTDeadSensors = 0;
   trig_EF_el_nBLSharedHits = 0;
   trig_EF_el_nPixSharedHits = 0;
   trig_EF_el_nSCTSharedHits = 0;
   trig_EF_el_nBLayerSplitHits = 0;
   trig_EF_el_nPixSplitHits = 0;
   trig_EF_el_nBLayerOutliers = 0;
   trig_EF_el_nPixelOutliers = 0;
   trig_EF_el_nSCTOutliers = 0;
   trig_EF_el_nTRTOutliers = 0;
   trig_EF_el_nTRTHighTOutliers = 0;
   trig_EF_el_expectBLayerHit = 0;
   trig_EF_el_nSiHits = 0;
   trig_EF_el_TRTHighTHitsRatio = 0;
   trig_EF_el_TRTHighTOutliersRatio = 0;
   trig_EF_el_pixeldEdx = 0;
   trig_EF_el_nGoodHitsPixeldEdx = 0;
   trig_EF_el_massPixeldEdx = 0;
   trig_EF_el_likelihoodsPixeldEdx = 0;
   trig_EF_el_eProbabilityComb = 0;
   trig_EF_el_eProbabilityHT = 0;
   trig_EF_el_eProbabilityToT = 0;
   trig_EF_el_eProbabilityBrem = 0;
   trig_EF_el_vertweight = 0;
   trig_EF_el_vertx = 0;
   trig_EF_el_verty = 0;
   trig_EF_el_vertz = 0;
   trig_EF_el_hastrack = 0;
   trig_EF_trigmuonef_effs15 = 0;
   trig_EF_trigmuonef_effs18 = 0;
   trig_EF_trigmuonef_effs24 = 0;
   trig_EF_trigmuonef_RoINum = 0;
   trig_EF_trigmuonef_NSegments = 0;
   trig_EF_trigmuonef_NMdtHits = 0;
   trig_EF_trigmuonef_NRpcHits = 0;
   trig_EF_trigmuonef_NTgcHits = 0;
   trig_EF_trigmuonef_NCscHits = 0;
   trig_EF_trigmuonef_EtaPreviousLevel = 0;
   trig_EF_trigmuonef_PhiPreviousLevel = 0;
   trig_EF_trigmuonef_track_n = 0;
   trig_EF_trigmuonef_track_MuonType = 0;
   trig_EF_trigmuonef_track_MS_pt = 0;
   trig_EF_trigmuonef_track_MS_eta = 0;
   trig_EF_trigmuonef_track_MS_phi = 0;
   trig_EF_trigmuonef_track_MS_charge = 0;
   trig_EF_trigmuonef_track_MS_d0 = 0;
   trig_EF_trigmuonef_track_MS_z0 = 0;
   trig_EF_trigmuonef_track_MS_chi2 = 0;
   trig_EF_trigmuonef_track_MS_chi2prob = 0;
   trig_EF_trigmuonef_track_MS_posX = 0;
   trig_EF_trigmuonef_track_MS_posY = 0;
   trig_EF_trigmuonef_track_MS_posZ = 0;
   trig_EF_trigmuonef_track_MS_NRpcHitsPhi = 0;
   trig_EF_trigmuonef_track_MS_NTgcHitsPhi = 0;
   trig_EF_trigmuonef_track_MS_NCscHitsPhi = 0;
   trig_EF_trigmuonef_track_MS_NRpcHitsEta = 0;
   trig_EF_trigmuonef_track_MS_NTgcHitsEta = 0;
   trig_EF_trigmuonef_track_MS_NCscHitsEta = 0;
   trig_EF_trigmuonef_track_MS_NMdtHits = 0;
   trig_EF_trigmuonef_track_MS_hasMS = 0;
   trig_EF_trigmuonef_track_SA_pt = 0;
   trig_EF_trigmuonef_track_SA_eta = 0;
   trig_EF_trigmuonef_track_SA_phi = 0;
   trig_EF_trigmuonef_track_SA_charge = 0;
   trig_EF_trigmuonef_track_SA_d0 = 0;
   trig_EF_trigmuonef_track_SA_z0 = 0;
   trig_EF_trigmuonef_track_SA_chi2 = 0;
   trig_EF_trigmuonef_track_SA_chi2prob = 0;
   trig_EF_trigmuonef_track_SA_posX = 0;
   trig_EF_trigmuonef_track_SA_posY = 0;
   trig_EF_trigmuonef_track_SA_posZ = 0;
   trig_EF_trigmuonef_track_SA_hasSA = 0;
   trig_EF_trigmuonef_track_CB_pt = 0;
   trig_EF_trigmuonef_track_CB_eta = 0;
   trig_EF_trigmuonef_track_CB_phi = 0;
   trig_EF_trigmuonef_track_CB_charge = 0;
   trig_EF_trigmuonef_track_CB_d0 = 0;
   trig_EF_trigmuonef_track_CB_z0 = 0;
   trig_EF_trigmuonef_track_CB_chi2 = 0;
   trig_EF_trigmuonef_track_CB_chi2prob = 0;
   trig_EF_trigmuonef_track_CB_posX = 0;
   trig_EF_trigmuonef_track_CB_posY = 0;
   trig_EF_trigmuonef_track_CB_posZ = 0;
   trig_EF_trigmuonef_track_CB_matchChi2 = 0;
   trig_EF_trigmuonef_track_CB_NIdSctHits = 0;
   trig_EF_trigmuonef_track_CB_NIdPixelHits = 0;
   trig_EF_trigmuonef_track_CB_NTrtHits = 0;
   trig_EF_trigmuonef_track_CB_hasCB = 0;
   bcmRDO_channel = 0;
   bcmRDO_nhits = 0;
   bcmRDO_pulse1pos = 0;
   bcmRDO_pulse1width = 0;
   bcmRDO_pulse2pos = 0;
   bcmRDO_pulse2width = 0;
   bcmRDO_lvl1a = 0;
   bcmRDO_bcid = 0;
   bcmRDO_lvl1id = 0;
   ctpRDO_pit = 0;
   ctpRDO_tbp = 0;
   ctpRDO_tap = 0;
   ctpRDO_tav = 0;
   ctp_decisionItems = 0;
   ctp_decisionWords = 0;
   mbtsLvl2_energies = 0;
   mbtsLvl2_times = 0;
   lvl2_sp_pixelClusEndcapC_contents = 0;
   lvl2_sp_pixelClusBarrel_contents = 0;
   lvl2_sp_pixelClusEndcapA_contents = 0;
   lvl2_sp_droppedPixelModuleIds = 0;
   lvl2_sp_droppedSctModuleIds = 0;
   lvl2_mbTrt_endcapC_contents = 0;
   lvl2_mbTrt_barrel_contents = 0;
   lvl2_mbTrt_endcapA_contents = 0;
   ef_trk_z0_pt_contents = 0;
   ef_trk_eta_phi_contents = 0;
   trig_L2_jet_E = 0;
   trig_L2_jet_eta = 0;
   trig_L2_jet_phi = 0;
   trig_L2_jet_RoIWord = 0;
   trig_L2_jet_InputType = 0;
   trig_L2_jet_OutputType = 0;
   trig_L2_jet_counter = 0;
   trig_L2_jet_c4cchad = 0;
   trig_L2_jet_c4ccem = 0;
   trig_L2_jet_c4uchad = 0;
   trig_L2_jet_ehad0 = 0;
   trig_L2_jet_eem0 = 0;
   trig_L2_jet_nLeadingCells = 0;
   trig_L2_jet_hecf = 0;
   trig_L2_jet_jetQuality = 0;
   trig_L2_jet_emf = 0;
   trig_L2_jet_jetTimeCells = 0;
   vx_x = 0;
   vx_y = 0;
   vx_z = 0;
   vx_err_x = 0;
   vx_err_y = 0;
   vx_err_z = 0;
   vx_cov_xy = 0;
   vx_cov_xz = 0;
   vx_cov_yz = 0;
   vx_type = 0;
   vx_chi2 = 0;
   vx_ndof = 0;
   vx_px = 0;
   vx_py = 0;
   vx_pz = 0;
   vx_E = 0;
   vx_m = 0;
   vx_nTracks = 0;
   vx_sumPt = 0;
   vx_trk_weight = 0;
   vx_trk_n = 0;
   vx_trk_index = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("timestamp", &timestamp, &b_timestamp);
   fChain->SetBranchAddress("timestamp_ns", &timestamp_ns, &b_timestamp_ns);
   fChain->SetBranchAddress("lbn", &lbn, &b_lbn);
   fChain->SetBranchAddress("bcid", &bcid, &b_bcid);
   fChain->SetBranchAddress("detmask0", &detmask0, &b_detmask0);
   fChain->SetBranchAddress("detmask1", &detmask1, &b_detmask1);
   fChain->SetBranchAddress("actualIntPerXing", &actualIntPerXing, &b_actualIntPerXing);
   fChain->SetBranchAddress("averageIntPerXing", &averageIntPerXing, &b_averageIntPerXing);
   fChain->SetBranchAddress("pixelFlags", &pixelFlags, &b_pixelFlags);
   fChain->SetBranchAddress("sctFlags", &sctFlags, &b_sctFlags);
   fChain->SetBranchAddress("trtFlags", &trtFlags, &b_trtFlags);
   fChain->SetBranchAddress("larFlags", &larFlags, &b_larFlags);
   fChain->SetBranchAddress("tileFlags", &tileFlags, &b_tileFlags);
   fChain->SetBranchAddress("muonFlags", &muonFlags, &b_muonFlags);
   fChain->SetBranchAddress("fwdFlags", &fwdFlags, &b_fwdFlags);
   fChain->SetBranchAddress("coreFlags", &coreFlags, &b_coreFlags);
   fChain->SetBranchAddress("pixelError", &pixelError, &b_pixelError);
   fChain->SetBranchAddress("sctError", &sctError, &b_sctError);
   fChain->SetBranchAddress("trtError", &trtError, &b_trtError);
   fChain->SetBranchAddress("larError", &larError, &b_larError);
   fChain->SetBranchAddress("tileError", &tileError, &b_tileError);
   fChain->SetBranchAddress("muonError", &muonError, &b_muonError);
   fChain->SetBranchAddress("fwdError", &fwdError, &b_fwdError);
   fChain->SetBranchAddress("coreError", &coreError, &b_coreError);
   fChain->SetBranchAddress("streamDecision_Egamma", &streamDecision_Egamma, &b_streamDecision_Egamma);
   fChain->SetBranchAddress("streamDecision_Muons", &streamDecision_Muons, &b_streamDecision_Muons);
   fChain->SetBranchAddress("streamDecision_JetTauEtmiss", &streamDecision_JetTauEtmiss, &b_streamDecision_JetTauEtmiss);
   fChain->SetBranchAddress("l1id", &l1id, &b_l1id);
   fChain->SetBranchAddress("isSimulation", &isSimulation, &b_isSimulation);
   fChain->SetBranchAddress("isCalibration", &isCalibration, &b_isCalibration);
   fChain->SetBranchAddress("isTestBeam", &isTestBeam, &b_isTestBeam);
   fChain->SetBranchAddress("mb_n", &mb_n, &b_mb_n);
   fChain->SetBranchAddress("mb_E", &mb_E, &b_mb_E);
   fChain->SetBranchAddress("mb_eta", &mb_eta, &b_mb_eta);
   fChain->SetBranchAddress("mb_phi", &mb_phi, &b_mb_phi);
   fChain->SetBranchAddress("mb_time", &mb_time, &b_mb_time);
   fChain->SetBranchAddress("mb_quality", &mb_quality, &b_mb_quality);
   fChain->SetBranchAddress("mb_type", &mb_type, &b_mb_type);
   fChain->SetBranchAddress("mb_module", &mb_module, &b_mb_module);
   fChain->SetBranchAddress("mb_channel", &mb_channel, &b_mb_channel);
   fChain->SetBranchAddress("mbtime_timeDiff", &mbtime_timeDiff, &b_mbtime_timeDiff);
   fChain->SetBranchAddress("mbtime_timeA", &mbtime_timeA, &b_mbtime_timeA);
   fChain->SetBranchAddress("mbtime_timeC", &mbtime_timeC, &b_mbtime_timeC);
   fChain->SetBranchAddress("mbtime_countA", &mbtime_countA, &b_mbtime_countA);
   fChain->SetBranchAddress("mbtime_countC", &mbtime_countC, &b_mbtime_countC);
   fChain->SetBranchAddress("lucidRaw_word0", &lucidRaw_word0, &b_lucidRaw_word0);
   fChain->SetBranchAddress("lucidRaw_word1", &lucidRaw_word1, &b_lucidRaw_word1);
   fChain->SetBranchAddress("lucidRaw_word2", &lucidRaw_word2, &b_lucidRaw_word2);
   fChain->SetBranchAddress("lucidRaw_word3", &lucidRaw_word3, &b_lucidRaw_word3);
   fChain->SetBranchAddress("lucidRaw_word0p", &lucidRaw_word0p, &b_lucidRaw_word0p);
   fChain->SetBranchAddress("lucidRaw_word1p", &lucidRaw_word1p, &b_lucidRaw_word1p);
   fChain->SetBranchAddress("lucidRaw_word2p", &lucidRaw_word2p, &b_lucidRaw_word2p);
   fChain->SetBranchAddress("lucidRaw_word3p", &lucidRaw_word3p, &b_lucidRaw_word3p);
   fChain->SetBranchAddress("lucidRaw_word0n", &lucidRaw_word0n, &b_lucidRaw_word0n);
   fChain->SetBranchAddress("lucidRaw_word1n", &lucidRaw_word1n, &b_lucidRaw_word1n);
   fChain->SetBranchAddress("lucidRaw_word2n", &lucidRaw_word2n, &b_lucidRaw_word2n);
   fChain->SetBranchAddress("lucidRaw_word3n", &lucidRaw_word3n, &b_lucidRaw_word3n);
   fChain->SetBranchAddress("lucidRaw_status", &lucidRaw_status, &b_lucidRaw_status);
   fChain->SetBranchAddress("lucidRaw_totalHits", &lucidRaw_totalHits, &b_lucidRaw_totalHits);
   fChain->SetBranchAddress("lucidRaw_ASideHits", &lucidRaw_ASideHits, &b_lucidRaw_ASideHits);
   fChain->SetBranchAddress("lucidRaw_CSideHits", &lucidRaw_CSideHits, &b_lucidRaw_CSideHits);
   fChain->SetBranchAddress("Zdc_n", &Zdc_n, &b_Zdc_n);
   fChain->SetBranchAddress("Zdc_Energy_Vec", &Zdc_Energy_Vec, &b_Zdc_Energy_Vec);
   fChain->SetBranchAddress("Zdc_Time_Vec", &Zdc_Time_Vec, &b_Zdc_Time_Vec);
   fChain->SetBranchAddress("Zdc_Vec_Size", &Zdc_Vec_Size, &b_Zdc_Vec_Size);
   fChain->SetBranchAddress("Zdc_Energy_LG", &Zdc_Energy_LG, &b_Zdc_Energy_LG);
   fChain->SetBranchAddress("Zdc_Time_LG", &Zdc_Time_LG, &b_Zdc_Time_LG);
   fChain->SetBranchAddress("Zdc_Energy_HG", &Zdc_Energy_HG, &b_Zdc_Energy_HG);
   fChain->SetBranchAddress("Zdc_Time_HG", &Zdc_Time_HG, &b_Zdc_Time_HG);
   fChain->SetBranchAddress("Zdc_Id", &Zdc_Id, &b_Zdc_Id);
   fChain->SetBranchAddress("Zdc_Side", &Zdc_Side, &b_Zdc_Side);
   fChain->SetBranchAddress("Zdc_Type", &Zdc_Type, &b_Zdc_Type);
   fChain->SetBranchAddress("Zdc_Module", &Zdc_Module, &b_Zdc_Module);
   fChain->SetBranchAddress("Zdc_Channel", &Zdc_Channel, &b_Zdc_Channel);
   fChain->SetBranchAddress("Zdc_TimeCalib", &Zdc_TimeCalib, &b_Zdc_TimeCalib);
   fChain->SetBranchAddress("Zdc_RecMethod", &Zdc_RecMethod, &b_Zdc_RecMethod);
   fChain->SetBranchAddress("ZdcDigits_n", &ZdcDigits_n, &b_ZdcDigits_n);
   fChain->SetBranchAddress("ZdcDigits_dig_g0d0", &ZdcDigits_dig_g0d0, &b_ZdcDigits_dig_g0d0);
   fChain->SetBranchAddress("ZdcDigits_dig_g0d1", &ZdcDigits_dig_g0d1, &b_ZdcDigits_dig_g0d1);
   fChain->SetBranchAddress("ZdcDigits_dig_g1d0", &ZdcDigits_dig_g1d0, &b_ZdcDigits_dig_g1d0);
   fChain->SetBranchAddress("ZdcDigits_dig_g1d1", &ZdcDigits_dig_g1d1, &b_ZdcDigits_dig_g1d1);
   fChain->SetBranchAddress("ZdcDigits_Id", &ZdcDigits_Id, &b_ZdcDigits_Id);
   fChain->SetBranchAddress("ZdcDigits_Side", &ZdcDigits_Side, &b_ZdcDigits_Side);
   fChain->SetBranchAddress("ZdcDigits_Type", &ZdcDigits_Type, &b_ZdcDigits_Type);
   fChain->SetBranchAddress("ZdcDigits_Module", &ZdcDigits_Module, &b_ZdcDigits_Module);
   fChain->SetBranchAddress("ZdcDigits_Channel", &ZdcDigits_Channel, &b_ZdcDigits_Channel);
   fChain->SetBranchAddress("ZdcReco_ESumA", &ZdcReco_ESumA, &b_ZdcReco_ESumA);
   fChain->SetBranchAddress("ZdcReco_ESumC", &ZdcReco_ESumC, &b_ZdcReco_ESumC);
   fChain->SetBranchAddress("ZdcReco_EA", &ZdcReco_EA, &b_ZdcReco_EA);
   fChain->SetBranchAddress("ZdcReco_EC", &ZdcReco_EC, &b_ZdcReco_EC);
   fChain->SetBranchAddress("ZdcReco_qA", &ZdcReco_qA, &b_ZdcReco_qA);
   fChain->SetBranchAddress("ZdcReco_qC", &ZdcReco_qC, &b_ZdcReco_qC);
   fChain->SetBranchAddress("ZdcReco_ESumA_LG", &ZdcReco_ESumA_LG, &b_ZdcReco_ESumA_LG);
   fChain->SetBranchAddress("ZdcReco_ESumA_HG", &ZdcReco_ESumA_HG, &b_ZdcReco_ESumA_HG);
   fChain->SetBranchAddress("ZdcReco_ESumC_LG", &ZdcReco_ESumC_LG, &b_ZdcReco_ESumC_LG);
   fChain->SetBranchAddress("ZdcReco_ESumC_HG", &ZdcReco_ESumC_HG, &b_ZdcReco_ESumC_HG);
   fChain->SetBranchAddress("cc_fcal_n", &cc_fcal_n, &b_cc_fcal_n);
   fChain->SetBranchAddress("cc_fcal_E", &cc_fcal_E, &b_cc_fcal_E);
   fChain->SetBranchAddress("cc_fcal_pt", &cc_fcal_pt, &b_cc_fcal_pt);
   fChain->SetBranchAddress("cc_fcal_eta", &cc_fcal_eta, &b_cc_fcal_eta);
   fChain->SetBranchAddress("cc_fcal_phi", &cc_fcal_phi, &b_cc_fcal_phi);
   fChain->SetBranchAddress("cc_fcal_QCells", &cc_fcal_QCells, &b_cc_fcal_QCells);
   fChain->SetBranchAddress("cc_fcal_GainCells", &cc_fcal_GainCells, &b_cc_fcal_GainCells);
   fChain->SetBranchAddress("cc_fcal_DetCells", &cc_fcal_DetCells, &b_cc_fcal_DetCells);
   fChain->SetBranchAddress("cc_fcal_TimeCells", &cc_fcal_TimeCells, &b_cc_fcal_TimeCells);
   fChain->SetBranchAddress("cc_fcal_xCells", &cc_fcal_xCells, &b_cc_fcal_xCells);
   fChain->SetBranchAddress("cc_fcal_yCells", &cc_fcal_yCells, &b_cc_fcal_yCells);
   fChain->SetBranchAddress("cc_fcal_zCells", &cc_fcal_zCells, &b_cc_fcal_zCells);
   fChain->SetBranchAddress("cc_fcal_BadCells", &cc_fcal_BadCells, &b_cc_fcal_BadCells);
   fChain->SetBranchAddress("cc_fcal_IdCells", &cc_fcal_IdCells, &b_cc_fcal_IdCells);
   fChain->SetBranchAddress("cc_fcal_Sigma", &cc_fcal_Sigma, &b_cc_fcal_Sigma);
	 
   //fChain->SetBranchAddress("TotalEt_n", &TotalEt_n, &b_TotalEt_n);
   fChain->SetBranchAddress("TotalEt_layer_eta", &TotalEt_layer_eta, &b_TotalEt_layer_eta);
   //fChain->SetBranchAddress("TotalEt_layer_phi", &TotalEt_layer_phi, &b_TotalEt_layer_phi);
   fChain->SetBranchAddress("TotalEt_layer_towerEt", &TotalEt_layer_towerEt, &b_TotalEt_layer_towerEt);
   fChain->SetBranchAddress("TotalEt_layer_sampling", &TotalEt_layer_sampling, &b_TotalEt_layer_sampling);
   //fChain->SetBranchAddress("TotalEt_layer_sampling_calib", &TotalEt_layer_sampling_calib, &b_TotalEt_layer_sampling_calib);
	 
   fChain->SetBranchAddress("ccc_Nh_Calo", &ccc_Nh_Calo, &b_ccc_Nh_Calo);
   fChain->SetBranchAddress("ccc_Eh_Calo", &ccc_Eh_Calo, &b_ccc_Eh_Calo);
   fChain->SetBranchAddress("ccc_Nh_EM", &ccc_Nh_EM, &b_ccc_Nh_EM);
   fChain->SetBranchAddress("ccc_Eh_EM", &ccc_Eh_EM, &b_ccc_Eh_EM);
   fChain->SetBranchAddress("ccc_Nh_HAD", &ccc_Nh_HAD, &b_ccc_Nh_HAD);
   fChain->SetBranchAddress("ccc_Eh_HAD", &ccc_Eh_HAD, &b_ccc_Eh_HAD);
   fChain->SetBranchAddress("ccc_Nh_PresB", &ccc_Nh_PresB, &b_ccc_Nh_PresB);
   fChain->SetBranchAddress("ccc_Eh_PresB", &ccc_Eh_PresB, &b_ccc_Eh_PresB);
   fChain->SetBranchAddress("ccc_Nh_EMB", &ccc_Nh_EMB, &b_ccc_Nh_EMB);
   fChain->SetBranchAddress("ccc_Eh_EMB", &ccc_Eh_EMB, &b_ccc_Eh_EMB);
   fChain->SetBranchAddress("ccc_Nh_EMEC", &ccc_Nh_EMEC, &b_ccc_Nh_EMEC);
   fChain->SetBranchAddress("ccc_Eh_EMEC", &ccc_Eh_EMEC, &b_ccc_Eh_EMEC);
   fChain->SetBranchAddress("ccc_Nh_Tile", &ccc_Nh_Tile, &b_ccc_Nh_Tile);
   fChain->SetBranchAddress("ccc_Eh_Tile", &ccc_Eh_Tile, &b_ccc_Eh_Tile);
   fChain->SetBranchAddress("ccc_Nh_TileGap", &ccc_Nh_TileGap, &b_ccc_Nh_TileGap);
   fChain->SetBranchAddress("ccc_Eh_TileGap", &ccc_Eh_TileGap, &b_ccc_Eh_TileGap);
   fChain->SetBranchAddress("ccc_Nh_HEC", &ccc_Nh_HEC, &b_ccc_Nh_HEC);
   fChain->SetBranchAddress("ccc_Eh_HEC", &ccc_Eh_HEC, &b_ccc_Eh_HEC);
   fChain->SetBranchAddress("ccc_Nh_FCal", &ccc_Nh_FCal, &b_ccc_Nh_FCal);
   fChain->SetBranchAddress("ccc_Eh_FCal", &ccc_Eh_FCal, &b_ccc_Eh_FCal);
   fChain->SetBranchAddress("ccc_Nh_PresE", &ccc_Nh_PresE, &b_ccc_Nh_PresE);
   fChain->SetBranchAddress("ccc_Eh_PresE", &ccc_Eh_PresE, &b_ccc_Eh_PresE);
   fChain->SetBranchAddress("ccc_Nh_Scint", &ccc_Nh_Scint, &b_ccc_Nh_Scint);
   fChain->SetBranchAddress("ccc_Eh_Scint", &ccc_Eh_Scint, &b_ccc_Eh_Scint);
   fChain->SetBranchAddress("cccEt_Et_Nh_Calo", &cccEt_Et_Nh_Calo, &b_cccEt_Et_Nh_Calo);
   fChain->SetBranchAddress("cccEt_Et_Eh_Calo", &cccEt_Et_Eh_Calo, &b_cccEt_Et_Eh_Calo);
   fChain->SetBranchAddress("cccEt_Et_Nh_EM", &cccEt_Et_Nh_EM, &b_cccEt_Et_Nh_EM);
   fChain->SetBranchAddress("cccEt_Et_Eh_EM", &cccEt_Et_Eh_EM, &b_cccEt_Et_Eh_EM);
   fChain->SetBranchAddress("cccEt_Et_Nh_HAD", &cccEt_Et_Nh_HAD, &b_cccEt_Et_Nh_HAD);
   fChain->SetBranchAddress("cccEt_Et_Eh_HAD", &cccEt_Et_Eh_HAD, &b_cccEt_Et_Eh_HAD);
   fChain->SetBranchAddress("cccEt_Et_Nh_PresB", &cccEt_Et_Nh_PresB, &b_cccEt_Et_Nh_PresB);
   fChain->SetBranchAddress("cccEt_Et_Eh_PresB", &cccEt_Et_Eh_PresB, &b_cccEt_Et_Eh_PresB);
   fChain->SetBranchAddress("cccEt_Et_Nh_EMB", &cccEt_Et_Nh_EMB, &b_cccEt_Et_Nh_EMB);
   fChain->SetBranchAddress("cccEt_Et_Eh_EMB", &cccEt_Et_Eh_EMB, &b_cccEt_Et_Eh_EMB);
   fChain->SetBranchAddress("cccEt_Et_Nh_EMEC", &cccEt_Et_Nh_EMEC, &b_cccEt_Et_Nh_EMEC);
   fChain->SetBranchAddress("cccEt_Et_Eh_EMEC", &cccEt_Et_Eh_EMEC, &b_cccEt_Et_Eh_EMEC);
   fChain->SetBranchAddress("cccEt_Et_Nh_Tile", &cccEt_Et_Nh_Tile, &b_cccEt_Et_Nh_Tile);
   fChain->SetBranchAddress("cccEt_Et_Eh_Tile", &cccEt_Et_Eh_Tile, &b_cccEt_Et_Eh_Tile);
   fChain->SetBranchAddress("cccEt_Et_Nh_TileGap", &cccEt_Et_Nh_TileGap, &b_cccEt_Et_Nh_TileGap);
   fChain->SetBranchAddress("cccEt_Et_Eh_TileGap", &cccEt_Et_Eh_TileGap, &b_cccEt_Et_Eh_TileGap);
   fChain->SetBranchAddress("cccEt_Et_Nh_HEC", &cccEt_Et_Nh_HEC, &b_cccEt_Et_Nh_HEC);
   fChain->SetBranchAddress("cccEt_Et_Eh_HEC", &cccEt_Et_Eh_HEC, &b_cccEt_Et_Eh_HEC);
   fChain->SetBranchAddress("cccEt_Et_Nh_FCal", &cccEt_Et_Nh_FCal, &b_cccEt_Et_Nh_FCal);
   fChain->SetBranchAddress("cccEt_Et_Eh_FCal", &cccEt_Et_Eh_FCal, &b_cccEt_Et_Eh_FCal);
   fChain->SetBranchAddress("cccEt_Et_Nh_PresE", &cccEt_Et_Nh_PresE, &b_cccEt_Et_Nh_PresE);
   fChain->SetBranchAddress("cccEt_Et_Eh_PresE", &cccEt_Et_Eh_PresE, &b_cccEt_Et_Eh_PresE);
   fChain->SetBranchAddress("cccEt_Et_Nh_Scint", &cccEt_Et_Nh_Scint, &b_cccEt_Et_Nh_Scint);
   fChain->SetBranchAddress("cccEt_Et_Eh_Scint", &cccEt_Et_Eh_Scint, &b_cccEt_Et_Eh_Scint);
   fChain->SetBranchAddress("cccEt_p_Nh_Calo", &cccEt_p_Nh_Calo, &b_cccEt_p_Nh_Calo);
   fChain->SetBranchAddress("cccEt_p_Eh_Calo", &cccEt_p_Eh_Calo, &b_cccEt_p_Eh_Calo);
   fChain->SetBranchAddress("cccEt_p_Nh_EM", &cccEt_p_Nh_EM, &b_cccEt_p_Nh_EM);
   fChain->SetBranchAddress("cccEt_p_Eh_EM", &cccEt_p_Eh_EM, &b_cccEt_p_Eh_EM);
   fChain->SetBranchAddress("cccEt_p_Nh_HAD", &cccEt_p_Nh_HAD, &b_cccEt_p_Nh_HAD);
   fChain->SetBranchAddress("cccEt_p_Eh_HAD", &cccEt_p_Eh_HAD, &b_cccEt_p_Eh_HAD);
   fChain->SetBranchAddress("cccEt_p_Nh_PresB", &cccEt_p_Nh_PresB, &b_cccEt_p_Nh_PresB);
   fChain->SetBranchAddress("cccEt_p_Eh_PresB", &cccEt_p_Eh_PresB, &b_cccEt_p_Eh_PresB);
   fChain->SetBranchAddress("cccEt_p_Nh_EMB", &cccEt_p_Nh_EMB, &b_cccEt_p_Nh_EMB);
   fChain->SetBranchAddress("cccEt_p_Eh_EMB", &cccEt_p_Eh_EMB, &b_cccEt_p_Eh_EMB);
   fChain->SetBranchAddress("cccEt_p_Nh_EMEC", &cccEt_p_Nh_EMEC, &b_cccEt_p_Nh_EMEC);
   fChain->SetBranchAddress("cccEt_p_Eh_EMEC", &cccEt_p_Eh_EMEC, &b_cccEt_p_Eh_EMEC);
   fChain->SetBranchAddress("cccEt_p_Nh_Tile", &cccEt_p_Nh_Tile, &b_cccEt_p_Nh_Tile);
   fChain->SetBranchAddress("cccEt_p_Eh_Tile", &cccEt_p_Eh_Tile, &b_cccEt_p_Eh_Tile);
   fChain->SetBranchAddress("cccEt_p_Nh_TileGap", &cccEt_p_Nh_TileGap, &b_cccEt_p_Nh_TileGap);
   fChain->SetBranchAddress("cccEt_p_Eh_TileGap", &cccEt_p_Eh_TileGap, &b_cccEt_p_Eh_TileGap);
   fChain->SetBranchAddress("cccEt_p_Nh_HEC", &cccEt_p_Nh_HEC, &b_cccEt_p_Nh_HEC);
   fChain->SetBranchAddress("cccEt_p_Eh_HEC", &cccEt_p_Eh_HEC, &b_cccEt_p_Eh_HEC);
   fChain->SetBranchAddress("cccEt_p_Nh_FCal", &cccEt_p_Nh_FCal, &b_cccEt_p_Nh_FCal);
   fChain->SetBranchAddress("cccEt_p_Eh_FCal", &cccEt_p_Eh_FCal, &b_cccEt_p_Eh_FCal);
   fChain->SetBranchAddress("cccEt_p_Nh_PresE", &cccEt_p_Nh_PresE, &b_cccEt_p_Nh_PresE);
   fChain->SetBranchAddress("cccEt_p_Eh_PresE", &cccEt_p_Eh_PresE, &b_cccEt_p_Eh_PresE);
   fChain->SetBranchAddress("cccEt_p_Nh_Scint", &cccEt_p_Nh_Scint, &b_cccEt_p_Nh_Scint);
   fChain->SetBranchAddress("cccEt_p_Eh_Scint", &cccEt_p_Eh_Scint, &b_cccEt_p_Eh_Scint);
   fChain->SetBranchAddress("cccEt_n_Nh_Calo", &cccEt_n_Nh_Calo, &b_cccEt_n_Nh_Calo);
   fChain->SetBranchAddress("cccEt_n_Eh_Calo", &cccEt_n_Eh_Calo, &b_cccEt_n_Eh_Calo);
   fChain->SetBranchAddress("cccEt_n_Nh_EM", &cccEt_n_Nh_EM, &b_cccEt_n_Nh_EM);
   fChain->SetBranchAddress("cccEt_n_Eh_EM", &cccEt_n_Eh_EM, &b_cccEt_n_Eh_EM);
   fChain->SetBranchAddress("cccEt_n_Nh_HAD", &cccEt_n_Nh_HAD, &b_cccEt_n_Nh_HAD);
   fChain->SetBranchAddress("cccEt_n_Eh_HAD", &cccEt_n_Eh_HAD, &b_cccEt_n_Eh_HAD);
   fChain->SetBranchAddress("cccEt_n_Nh_PresB", &cccEt_n_Nh_PresB, &b_cccEt_n_Nh_PresB);
   fChain->SetBranchAddress("cccEt_n_Eh_PresB", &cccEt_n_Eh_PresB, &b_cccEt_n_Eh_PresB);
   fChain->SetBranchAddress("cccEt_n_Nh_EMB", &cccEt_n_Nh_EMB, &b_cccEt_n_Nh_EMB);
   fChain->SetBranchAddress("cccEt_n_Eh_EMB", &cccEt_n_Eh_EMB, &b_cccEt_n_Eh_EMB);
   fChain->SetBranchAddress("cccEt_n_Nh_EMEC", &cccEt_n_Nh_EMEC, &b_cccEt_n_Nh_EMEC);
   fChain->SetBranchAddress("cccEt_n_Eh_EMEC", &cccEt_n_Eh_EMEC, &b_cccEt_n_Eh_EMEC);
   fChain->SetBranchAddress("cccEt_n_Nh_Tile", &cccEt_n_Nh_Tile, &b_cccEt_n_Nh_Tile);
   fChain->SetBranchAddress("cccEt_n_Eh_Tile", &cccEt_n_Eh_Tile, &b_cccEt_n_Eh_Tile);
   fChain->SetBranchAddress("cccEt_n_Nh_TileGap", &cccEt_n_Nh_TileGap, &b_cccEt_n_Nh_TileGap);
   fChain->SetBranchAddress("cccEt_n_Eh_TileGap", &cccEt_n_Eh_TileGap, &b_cccEt_n_Eh_TileGap);
   fChain->SetBranchAddress("cccEt_n_Nh_HEC", &cccEt_n_Nh_HEC, &b_cccEt_n_Nh_HEC);
   fChain->SetBranchAddress("cccEt_n_Eh_HEC", &cccEt_n_Eh_HEC, &b_cccEt_n_Eh_HEC);
   fChain->SetBranchAddress("cccEt_n_Nh_FCal", &cccEt_n_Nh_FCal, &b_cccEt_n_Nh_FCal);
   fChain->SetBranchAddress("cccEt_n_Eh_FCal", &cccEt_n_Eh_FCal, &b_cccEt_n_Eh_FCal);
   fChain->SetBranchAddress("cccEt_n_Nh_PresE", &cccEt_n_Nh_PresE, &b_cccEt_n_Nh_PresE);
   fChain->SetBranchAddress("cccEt_n_Eh_PresE", &cccEt_n_Eh_PresE, &b_cccEt_n_Eh_PresE);
   fChain->SetBranchAddress("cccEt_n_Nh_Scint", &cccEt_n_Nh_Scint, &b_cccEt_n_Nh_Scint);
   fChain->SetBranchAddress("cccEt_n_Eh_Scint", &cccEt_n_Eh_Scint, &b_cccEt_n_Eh_Scint);
   fChain->SetBranchAddress("lar_ncellA", &lar_ncellA, &b_lar_ncellA);
   fChain->SetBranchAddress("lar_ncellC", &lar_ncellC, &b_lar_ncellC);
   fChain->SetBranchAddress("lar_energyA", &lar_energyA, &b_lar_energyA);
   fChain->SetBranchAddress("lar_energyC", &lar_energyC, &b_lar_energyC);
   fChain->SetBranchAddress("lar_timeA", &lar_timeA, &b_lar_timeA);
   fChain->SetBranchAddress("lar_timeC", &lar_timeC, &b_lar_timeC);
   fChain->SetBranchAddress("lar_timeDiff", &lar_timeDiff, &b_lar_timeDiff);
   fChain->SetBranchAddress("trk_n", &trk_n, &b_trk_n);
   fChain->SetBranchAddress("trk_d0", &trk_d0, &b_trk_d0);
   fChain->SetBranchAddress("trk_z0", &trk_z0, &b_trk_z0);
   fChain->SetBranchAddress("trk_phi", &trk_phi, &b_trk_phi);
   fChain->SetBranchAddress("trk_theta", &trk_theta, &b_trk_theta);
   fChain->SetBranchAddress("trk_qoverp", &trk_qoverp, &b_trk_qoverp);
   fChain->SetBranchAddress("trk_pt", &trk_pt, &b_trk_pt);
   fChain->SetBranchAddress("trk_eta", &trk_eta, &b_trk_eta);
   fChain->SetBranchAddress("trk_err_d0", &trk_err_d0, &b_trk_err_d0);
   fChain->SetBranchAddress("trk_err_z0", &trk_err_z0, &b_trk_err_z0);
   fChain->SetBranchAddress("trk_err_phi", &trk_err_phi, &b_trk_err_phi);
   fChain->SetBranchAddress("trk_err_theta", &trk_err_theta, &b_trk_err_theta);
   fChain->SetBranchAddress("trk_err_qoverp", &trk_err_qoverp, &b_trk_err_qoverp);
   fChain->SetBranchAddress("trk_cov_d0_z0", &trk_cov_d0_z0, &b_trk_cov_d0_z0);
   fChain->SetBranchAddress("trk_cov_d0_phi", &trk_cov_d0_phi, &b_trk_cov_d0_phi);
   fChain->SetBranchAddress("trk_cov_d0_theta", &trk_cov_d0_theta, &b_trk_cov_d0_theta);
   fChain->SetBranchAddress("trk_cov_d0_qoverp", &trk_cov_d0_qoverp, &b_trk_cov_d0_qoverp);
   fChain->SetBranchAddress("trk_cov_z0_phi", &trk_cov_z0_phi, &b_trk_cov_z0_phi);
   fChain->SetBranchAddress("trk_cov_z0_theta", &trk_cov_z0_theta, &b_trk_cov_z0_theta);
   fChain->SetBranchAddress("trk_cov_z0_qoverp", &trk_cov_z0_qoverp, &b_trk_cov_z0_qoverp);
   fChain->SetBranchAddress("trk_cov_phi_theta", &trk_cov_phi_theta, &b_trk_cov_phi_theta);
   fChain->SetBranchAddress("trk_cov_phi_qoverp", &trk_cov_phi_qoverp, &b_trk_cov_phi_qoverp);
   fChain->SetBranchAddress("trk_cov_theta_qoverp", &trk_cov_theta_qoverp, &b_trk_cov_theta_qoverp);
   fChain->SetBranchAddress("trk_d0_wrtPV", &trk_d0_wrtPV, &b_trk_d0_wrtPV);
   fChain->SetBranchAddress("trk_z0_wrtPV", &trk_z0_wrtPV, &b_trk_z0_wrtPV);
   fChain->SetBranchAddress("trk_phi_wrtPV", &trk_phi_wrtPV, &b_trk_phi_wrtPV);
   fChain->SetBranchAddress("trk_err_d0_wrtPV", &trk_err_d0_wrtPV, &b_trk_err_d0_wrtPV);
   fChain->SetBranchAddress("trk_err_z0_wrtPV", &trk_err_z0_wrtPV, &b_trk_err_z0_wrtPV);
   fChain->SetBranchAddress("trk_err_phi_wrtPV", &trk_err_phi_wrtPV, &b_trk_err_phi_wrtPV);
   fChain->SetBranchAddress("trk_err_theta_wrtPV", &trk_err_theta_wrtPV, &b_trk_err_theta_wrtPV);
   fChain->SetBranchAddress("trk_err_qoverp_wrtPV", &trk_err_qoverp_wrtPV, &b_trk_err_qoverp_wrtPV);
   fChain->SetBranchAddress("trk_cov_d0_z0_wrtPV", &trk_cov_d0_z0_wrtPV, &b_trk_cov_d0_z0_wrtPV);
   fChain->SetBranchAddress("trk_cov_d0_phi_wrtPV", &trk_cov_d0_phi_wrtPV, &b_trk_cov_d0_phi_wrtPV);
   fChain->SetBranchAddress("trk_cov_d0_theta_wrtPV", &trk_cov_d0_theta_wrtPV, &b_trk_cov_d0_theta_wrtPV);
   fChain->SetBranchAddress("trk_cov_d0_qoverp_wrtPV", &trk_cov_d0_qoverp_wrtPV, &b_trk_cov_d0_qoverp_wrtPV);
   fChain->SetBranchAddress("trk_cov_z0_phi_wrtPV", &trk_cov_z0_phi_wrtPV, &b_trk_cov_z0_phi_wrtPV);
   fChain->SetBranchAddress("trk_cov_z0_theta_wrtPV", &trk_cov_z0_theta_wrtPV, &b_trk_cov_z0_theta_wrtPV);
   fChain->SetBranchAddress("trk_cov_z0_qoverp_wrtPV", &trk_cov_z0_qoverp_wrtPV, &b_trk_cov_z0_qoverp_wrtPV);
   fChain->SetBranchAddress("trk_cov_phi_theta_wrtPV", &trk_cov_phi_theta_wrtPV, &b_trk_cov_phi_theta_wrtPV);
   fChain->SetBranchAddress("trk_cov_phi_qoverp_wrtPV", &trk_cov_phi_qoverp_wrtPV, &b_trk_cov_phi_qoverp_wrtPV);
   fChain->SetBranchAddress("trk_cov_theta_qoverp_wrtPV", &trk_cov_theta_qoverp_wrtPV, &b_trk_cov_theta_qoverp_wrtPV);
   fChain->SetBranchAddress("trk_d0_wrtBS", &trk_d0_wrtBS, &b_trk_d0_wrtBS);
   fChain->SetBranchAddress("trk_z0_wrtBS", &trk_z0_wrtBS, &b_trk_z0_wrtBS);
   fChain->SetBranchAddress("trk_phi_wrtBS", &trk_phi_wrtBS, &b_trk_phi_wrtBS);
   fChain->SetBranchAddress("trk_err_d0_wrtBS", &trk_err_d0_wrtBS, &b_trk_err_d0_wrtBS);
   fChain->SetBranchAddress("trk_err_z0_wrtBS", &trk_err_z0_wrtBS, &b_trk_err_z0_wrtBS);
   fChain->SetBranchAddress("trk_err_phi_wrtBS", &trk_err_phi_wrtBS, &b_trk_err_phi_wrtBS);
   fChain->SetBranchAddress("trk_err_theta_wrtBS", &trk_err_theta_wrtBS, &b_trk_err_theta_wrtBS);
   fChain->SetBranchAddress("trk_err_qoverp_wrtBS", &trk_err_qoverp_wrtBS, &b_trk_err_qoverp_wrtBS);
   fChain->SetBranchAddress("trk_cov_d0_z0_wrtBS", &trk_cov_d0_z0_wrtBS, &b_trk_cov_d0_z0_wrtBS);
   fChain->SetBranchAddress("trk_cov_d0_phi_wrtBS", &trk_cov_d0_phi_wrtBS, &b_trk_cov_d0_phi_wrtBS);
   fChain->SetBranchAddress("trk_cov_d0_theta_wrtBS", &trk_cov_d0_theta_wrtBS, &b_trk_cov_d0_theta_wrtBS);
   fChain->SetBranchAddress("trk_cov_d0_qoverp_wrtBS", &trk_cov_d0_qoverp_wrtBS, &b_trk_cov_d0_qoverp_wrtBS);
   fChain->SetBranchAddress("trk_cov_z0_phi_wrtBS", &trk_cov_z0_phi_wrtBS, &b_trk_cov_z0_phi_wrtBS);
   fChain->SetBranchAddress("trk_cov_z0_theta_wrtBS", &trk_cov_z0_theta_wrtBS, &b_trk_cov_z0_theta_wrtBS);
   fChain->SetBranchAddress("trk_cov_z0_qoverp_wrtBS", &trk_cov_z0_qoverp_wrtBS, &b_trk_cov_z0_qoverp_wrtBS);
   fChain->SetBranchAddress("trk_cov_phi_theta_wrtBS", &trk_cov_phi_theta_wrtBS, &b_trk_cov_phi_theta_wrtBS);
   fChain->SetBranchAddress("trk_cov_phi_qoverp_wrtBS", &trk_cov_phi_qoverp_wrtBS, &b_trk_cov_phi_qoverp_wrtBS);
   fChain->SetBranchAddress("trk_cov_theta_qoverp_wrtBS", &trk_cov_theta_qoverp_wrtBS, &b_trk_cov_theta_qoverp_wrtBS);
   fChain->SetBranchAddress("trk_d0_wrtBL", &trk_d0_wrtBL, &b_trk_d0_wrtBL);
   fChain->SetBranchAddress("trk_z0_wrtBL", &trk_z0_wrtBL, &b_trk_z0_wrtBL);
   fChain->SetBranchAddress("trk_phi_wrtBL", &trk_phi_wrtBL, &b_trk_phi_wrtBL);
   fChain->SetBranchAddress("trk_d0_err_wrtBL", &trk_d0_err_wrtBL, &b_trk_d0_err_wrtBL);
   fChain->SetBranchAddress("trk_z0_err_wrtBL", &trk_z0_err_wrtBL, &b_trk_z0_err_wrtBL);
   fChain->SetBranchAddress("trk_phi_err_wrtBL", &trk_phi_err_wrtBL, &b_trk_phi_err_wrtBL);
   fChain->SetBranchAddress("trk_theta_err_wrtBL", &trk_theta_err_wrtBL, &b_trk_theta_err_wrtBL);
   fChain->SetBranchAddress("trk_qoverp_err_wrtBL", &trk_qoverp_err_wrtBL, &b_trk_qoverp_err_wrtBL);
   fChain->SetBranchAddress("trk_d0_z0_err_wrtBL", &trk_d0_z0_err_wrtBL, &b_trk_d0_z0_err_wrtBL);
   fChain->SetBranchAddress("trk_d0_phi_err_wrtBL", &trk_d0_phi_err_wrtBL, &b_trk_d0_phi_err_wrtBL);
   fChain->SetBranchAddress("trk_d0_theta_err_wrtBL", &trk_d0_theta_err_wrtBL, &b_trk_d0_theta_err_wrtBL);
   fChain->SetBranchAddress("trk_d0_qoverp_err_wrtBL", &trk_d0_qoverp_err_wrtBL, &b_trk_d0_qoverp_err_wrtBL);
   fChain->SetBranchAddress("trk_z0_phi_err_wrtBL", &trk_z0_phi_err_wrtBL, &b_trk_z0_phi_err_wrtBL);
   fChain->SetBranchAddress("trk_z0_theta_err_wrtBL", &trk_z0_theta_err_wrtBL, &b_trk_z0_theta_err_wrtBL);
   fChain->SetBranchAddress("trk_z0_qoverp_err_wrtBL", &trk_z0_qoverp_err_wrtBL, &b_trk_z0_qoverp_err_wrtBL);
   fChain->SetBranchAddress("trk_phi_theta_err_wrtBL", &trk_phi_theta_err_wrtBL, &b_trk_phi_theta_err_wrtBL);
   fChain->SetBranchAddress("trk_phi_qoverp_err_wrtBL", &trk_phi_qoverp_err_wrtBL, &b_trk_phi_qoverp_err_wrtBL);
   fChain->SetBranchAddress("trk_theta_qoverp_err_wrtBL", &trk_theta_qoverp_err_wrtBL, &b_trk_theta_qoverp_err_wrtBL);
   fChain->SetBranchAddress("trk_chi2", &trk_chi2, &b_trk_chi2);
   fChain->SetBranchAddress("trk_ndof", &trk_ndof, &b_trk_ndof);
   fChain->SetBranchAddress("trk_nBLHits", &trk_nBLHits, &b_trk_nBLHits);
   fChain->SetBranchAddress("trk_nPixHits", &trk_nPixHits, &b_trk_nPixHits);
   fChain->SetBranchAddress("trk_nSCTHits", &trk_nSCTHits, &b_trk_nSCTHits);
   fChain->SetBranchAddress("trk_nTRTHits", &trk_nTRTHits, &b_trk_nTRTHits);
   fChain->SetBranchAddress("trk_nTRTHighTHits", &trk_nTRTHighTHits, &b_trk_nTRTHighTHits);
   fChain->SetBranchAddress("trk_nTRTXenonHits", &trk_nTRTXenonHits, &b_trk_nTRTXenonHits);
   fChain->SetBranchAddress("trk_nPixHoles", &trk_nPixHoles, &b_trk_nPixHoles);
   fChain->SetBranchAddress("trk_nSCTHoles", &trk_nSCTHoles, &b_trk_nSCTHoles);
   fChain->SetBranchAddress("trk_nTRTHoles", &trk_nTRTHoles, &b_trk_nTRTHoles);
   fChain->SetBranchAddress("trk_nPixelDeadSensors", &trk_nPixelDeadSensors, &b_trk_nPixelDeadSensors);
   fChain->SetBranchAddress("trk_nSCTDeadSensors", &trk_nSCTDeadSensors, &b_trk_nSCTDeadSensors);
   fChain->SetBranchAddress("trk_nBLSharedHits", &trk_nBLSharedHits, &b_trk_nBLSharedHits);
   fChain->SetBranchAddress("trk_nPixSharedHits", &trk_nPixSharedHits, &b_trk_nPixSharedHits);
   fChain->SetBranchAddress("trk_nSCTSharedHits", &trk_nSCTSharedHits, &b_trk_nSCTSharedHits);
   fChain->SetBranchAddress("trk_nBLayerSplitHits", &trk_nBLayerSplitHits, &b_trk_nBLayerSplitHits);
   fChain->SetBranchAddress("trk_nPixSplitHits", &trk_nPixSplitHits, &b_trk_nPixSplitHits);
   fChain->SetBranchAddress("trk_expectBLayerHit", &trk_expectBLayerHit, &b_trk_expectBLayerHit);
   fChain->SetBranchAddress("trk_nMDTHits", &trk_nMDTHits, &b_trk_nMDTHits);
   fChain->SetBranchAddress("trk_nCSCEtaHits", &trk_nCSCEtaHits, &b_trk_nCSCEtaHits);
   fChain->SetBranchAddress("trk_nCSCPhiHits", &trk_nCSCPhiHits, &b_trk_nCSCPhiHits);
   fChain->SetBranchAddress("trk_nRPCEtaHits", &trk_nRPCEtaHits, &b_trk_nRPCEtaHits);
   fChain->SetBranchAddress("trk_nRPCPhiHits", &trk_nRPCPhiHits, &b_trk_nRPCPhiHits);
   fChain->SetBranchAddress("trk_nTGCEtaHits", &trk_nTGCEtaHits, &b_trk_nTGCEtaHits);
   fChain->SetBranchAddress("trk_nTGCPhiHits", &trk_nTGCPhiHits, &b_trk_nTGCPhiHits);
   fChain->SetBranchAddress("trk_nHits", &trk_nHits, &b_trk_nHits);
   fChain->SetBranchAddress("trk_nHoles", &trk_nHoles, &b_trk_nHoles);
   fChain->SetBranchAddress("trk_hitPattern", &trk_hitPattern, &b_trk_hitPattern);
   fChain->SetBranchAddress("trk_TRTHighTHitsRatio", &trk_TRTHighTHitsRatio, &b_trk_TRTHighTHitsRatio);
   fChain->SetBranchAddress("trk_TRTHighTOutliersRatio", &trk_TRTHighTOutliersRatio, &b_trk_TRTHighTOutliersRatio);
   fChain->SetBranchAddress("trk_pixeldEdx", &trk_pixeldEdx, &b_trk_pixeldEdx);
   fChain->SetBranchAddress("trk_nGoodHitsPixeldEdx", &trk_nGoodHitsPixeldEdx, &b_trk_nGoodHitsPixeldEdx);
   fChain->SetBranchAddress("trk_massPixeldEdx", &trk_massPixeldEdx, &b_trk_massPixeldEdx);
   fChain->SetBranchAddress("trk_likelihoodsPixeldEdx", &trk_likelihoodsPixeldEdx, &b_trk_likelihoodsPixeldEdx);
   fChain->SetBranchAddress("trk_fitter", &trk_fitter, &b_trk_fitter);
   fChain->SetBranchAddress("trk_patternReco1", &trk_patternReco1, &b_trk_patternReco1);
   fChain->SetBranchAddress("trk_patternReco2", &trk_patternReco2, &b_trk_patternReco2);
   fChain->SetBranchAddress("trk_trackProperties", &trk_trackProperties, &b_trk_trackProperties);
   fChain->SetBranchAddress("trk_particleHypothesis", &trk_particleHypothesis, &b_trk_particleHypothesis);
   fChain->SetBranchAddress("trk_blayerPrediction_x", &trk_blayerPrediction_x, &b_trk_blayerPrediction_x);
   fChain->SetBranchAddress("trk_blayerPrediction_y", &trk_blayerPrediction_y, &b_trk_blayerPrediction_y);
   fChain->SetBranchAddress("trk_blayerPrediction_z", &trk_blayerPrediction_z, &b_trk_blayerPrediction_z);
   fChain->SetBranchAddress("trk_blayerPrediction_locX", &trk_blayerPrediction_locX, &b_trk_blayerPrediction_locX);
   fChain->SetBranchAddress("trk_blayerPrediction_locY", &trk_blayerPrediction_locY, &b_trk_blayerPrediction_locY);
   fChain->SetBranchAddress("trk_blayerPrediction_err_locX", &trk_blayerPrediction_err_locX, &b_trk_blayerPrediction_err_locX);
   fChain->SetBranchAddress("trk_blayerPrediction_err_locY", &trk_blayerPrediction_err_locY, &b_trk_blayerPrediction_err_locY);
   fChain->SetBranchAddress("trk_blayerPrediction_etaDistToEdge", &trk_blayerPrediction_etaDistToEdge, &b_trk_blayerPrediction_etaDistToEdge);
   fChain->SetBranchAddress("trk_blayerPrediction_phiDistToEdge", &trk_blayerPrediction_phiDistToEdge, &b_trk_blayerPrediction_phiDistToEdge);
   fChain->SetBranchAddress("trk_blayerPrediction_detElementId", &trk_blayerPrediction_detElementId, &b_trk_blayerPrediction_detElementId);
   fChain->SetBranchAddress("trk_blayerPrediction_row", &trk_blayerPrediction_row, &b_trk_blayerPrediction_row);
   fChain->SetBranchAddress("trk_blayerPrediction_col", &trk_blayerPrediction_col, &b_trk_blayerPrediction_col);
   fChain->SetBranchAddress("trk_blayerPrediction_type", &trk_blayerPrediction_type, &b_trk_blayerPrediction_type);
   fChain->SetBranchAddress("trkPix_n", &trkPix_n, &b_trkPix_n);
   fChain->SetBranchAddress("trkPix_d0", &trkPix_d0, &b_trkPix_d0);
   fChain->SetBranchAddress("trkPix_z0", &trkPix_z0, &b_trkPix_z0);
   fChain->SetBranchAddress("trkPix_phi", &trkPix_phi, &b_trkPix_phi);
   fChain->SetBranchAddress("trkPix_theta", &trkPix_theta, &b_trkPix_theta);
   fChain->SetBranchAddress("trkPix_qoverp", &trkPix_qoverp, &b_trkPix_qoverp);
   fChain->SetBranchAddress("trkPix_pt", &trkPix_pt, &b_trkPix_pt);
   fChain->SetBranchAddress("trkPix_eta", &trkPix_eta, &b_trkPix_eta);
   fChain->SetBranchAddress("trkPix_err_d0", &trkPix_err_d0, &b_trkPix_err_d0);
   fChain->SetBranchAddress("trkPix_err_z0", &trkPix_err_z0, &b_trkPix_err_z0);
   fChain->SetBranchAddress("trkPix_err_phi", &trkPix_err_phi, &b_trkPix_err_phi);
   fChain->SetBranchAddress("trkPix_err_theta", &trkPix_err_theta, &b_trkPix_err_theta);
   fChain->SetBranchAddress("trkPix_err_qoverp", &trkPix_err_qoverp, &b_trkPix_err_qoverp);
   fChain->SetBranchAddress("trkPix_cov_d0_z0", &trkPix_cov_d0_z0, &b_trkPix_cov_d0_z0);
   fChain->SetBranchAddress("trkPix_cov_d0_phi", &trkPix_cov_d0_phi, &b_trkPix_cov_d0_phi);
   fChain->SetBranchAddress("trkPix_cov_d0_theta", &trkPix_cov_d0_theta, &b_trkPix_cov_d0_theta);
   fChain->SetBranchAddress("trkPix_cov_d0_qoverp", &trkPix_cov_d0_qoverp, &b_trkPix_cov_d0_qoverp);
   fChain->SetBranchAddress("trkPix_cov_z0_phi", &trkPix_cov_z0_phi, &b_trkPix_cov_z0_phi);
   fChain->SetBranchAddress("trkPix_cov_z0_theta", &trkPix_cov_z0_theta, &b_trkPix_cov_z0_theta);
   fChain->SetBranchAddress("trkPix_cov_z0_qoverp", &trkPix_cov_z0_qoverp, &b_trkPix_cov_z0_qoverp);
   fChain->SetBranchAddress("trkPix_cov_phi_theta", &trkPix_cov_phi_theta, &b_trkPix_cov_phi_theta);
   fChain->SetBranchAddress("trkPix_cov_phi_qoverp", &trkPix_cov_phi_qoverp, &b_trkPix_cov_phi_qoverp);
   fChain->SetBranchAddress("trkPix_cov_theta_qoverp", &trkPix_cov_theta_qoverp, &b_trkPix_cov_theta_qoverp);
   fChain->SetBranchAddress("trkPix_d0_wrtPV", &trkPix_d0_wrtPV, &b_trkPix_d0_wrtPV);
   fChain->SetBranchAddress("trkPix_z0_wrtPV", &trkPix_z0_wrtPV, &b_trkPix_z0_wrtPV);
   fChain->SetBranchAddress("trkPix_phi_wrtPV", &trkPix_phi_wrtPV, &b_trkPix_phi_wrtPV);
   fChain->SetBranchAddress("trkPix_err_d0_wrtPV", &trkPix_err_d0_wrtPV, &b_trkPix_err_d0_wrtPV);
   fChain->SetBranchAddress("trkPix_err_z0_wrtPV", &trkPix_err_z0_wrtPV, &b_trkPix_err_z0_wrtPV);
   fChain->SetBranchAddress("trkPix_err_phi_wrtPV", &trkPix_err_phi_wrtPV, &b_trkPix_err_phi_wrtPV);
   fChain->SetBranchAddress("trkPix_err_theta_wrtPV", &trkPix_err_theta_wrtPV, &b_trkPix_err_theta_wrtPV);
   fChain->SetBranchAddress("trkPix_err_qoverp_wrtPV", &trkPix_err_qoverp_wrtPV, &b_trkPix_err_qoverp_wrtPV);
   fChain->SetBranchAddress("trkPix_cov_d0_z0_wrtPV", &trkPix_cov_d0_z0_wrtPV, &b_trkPix_cov_d0_z0_wrtPV);
   fChain->SetBranchAddress("trkPix_cov_d0_phi_wrtPV", &trkPix_cov_d0_phi_wrtPV, &b_trkPix_cov_d0_phi_wrtPV);
   fChain->SetBranchAddress("trkPix_cov_d0_theta_wrtPV", &trkPix_cov_d0_theta_wrtPV, &b_trkPix_cov_d0_theta_wrtPV);
   fChain->SetBranchAddress("trkPix_cov_d0_qoverp_wrtPV", &trkPix_cov_d0_qoverp_wrtPV, &b_trkPix_cov_d0_qoverp_wrtPV);
   fChain->SetBranchAddress("trkPix_cov_z0_phi_wrtPV", &trkPix_cov_z0_phi_wrtPV, &b_trkPix_cov_z0_phi_wrtPV);
   fChain->SetBranchAddress("trkPix_cov_z0_theta_wrtPV", &trkPix_cov_z0_theta_wrtPV, &b_trkPix_cov_z0_theta_wrtPV);
   fChain->SetBranchAddress("trkPix_cov_z0_qoverp_wrtPV", &trkPix_cov_z0_qoverp_wrtPV, &b_trkPix_cov_z0_qoverp_wrtPV);
   fChain->SetBranchAddress("trkPix_cov_phi_theta_wrtPV", &trkPix_cov_phi_theta_wrtPV, &b_trkPix_cov_phi_theta_wrtPV);
   fChain->SetBranchAddress("trkPix_cov_phi_qoverp_wrtPV", &trkPix_cov_phi_qoverp_wrtPV, &b_trkPix_cov_phi_qoverp_wrtPV);
   fChain->SetBranchAddress("trkPix_cov_theta_qoverp_wrtPV", &trkPix_cov_theta_qoverp_wrtPV, &b_trkPix_cov_theta_qoverp_wrtPV);
   fChain->SetBranchAddress("trkPix_d0_wrtBS", &trkPix_d0_wrtBS, &b_trkPix_d0_wrtBS);
   fChain->SetBranchAddress("trkPix_z0_wrtBS", &trkPix_z0_wrtBS, &b_trkPix_z0_wrtBS);
   fChain->SetBranchAddress("trkPix_phi_wrtBS", &trkPix_phi_wrtBS, &b_trkPix_phi_wrtBS);
   fChain->SetBranchAddress("trkPix_err_d0_wrtBS", &trkPix_err_d0_wrtBS, &b_trkPix_err_d0_wrtBS);
   fChain->SetBranchAddress("trkPix_err_z0_wrtBS", &trkPix_err_z0_wrtBS, &b_trkPix_err_z0_wrtBS);
   fChain->SetBranchAddress("trkPix_err_phi_wrtBS", &trkPix_err_phi_wrtBS, &b_trkPix_err_phi_wrtBS);
   fChain->SetBranchAddress("trkPix_err_theta_wrtBS", &trkPix_err_theta_wrtBS, &b_trkPix_err_theta_wrtBS);
   fChain->SetBranchAddress("trkPix_err_qoverp_wrtBS", &trkPix_err_qoverp_wrtBS, &b_trkPix_err_qoverp_wrtBS);
   fChain->SetBranchAddress("trkPix_cov_d0_z0_wrtBS", &trkPix_cov_d0_z0_wrtBS, &b_trkPix_cov_d0_z0_wrtBS);
   fChain->SetBranchAddress("trkPix_cov_d0_phi_wrtBS", &trkPix_cov_d0_phi_wrtBS, &b_trkPix_cov_d0_phi_wrtBS);
   fChain->SetBranchAddress("trkPix_cov_d0_theta_wrtBS", &trkPix_cov_d0_theta_wrtBS, &b_trkPix_cov_d0_theta_wrtBS);
   fChain->SetBranchAddress("trkPix_cov_d0_qoverp_wrtBS", &trkPix_cov_d0_qoverp_wrtBS, &b_trkPix_cov_d0_qoverp_wrtBS);
   fChain->SetBranchAddress("trkPix_cov_z0_phi_wrtBS", &trkPix_cov_z0_phi_wrtBS, &b_trkPix_cov_z0_phi_wrtBS);
   fChain->SetBranchAddress("trkPix_cov_z0_theta_wrtBS", &trkPix_cov_z0_theta_wrtBS, &b_trkPix_cov_z0_theta_wrtBS);
   fChain->SetBranchAddress("trkPix_cov_z0_qoverp_wrtBS", &trkPix_cov_z0_qoverp_wrtBS, &b_trkPix_cov_z0_qoverp_wrtBS);
   fChain->SetBranchAddress("trkPix_cov_phi_theta_wrtBS", &trkPix_cov_phi_theta_wrtBS, &b_trkPix_cov_phi_theta_wrtBS);
   fChain->SetBranchAddress("trkPix_cov_phi_qoverp_wrtBS", &trkPix_cov_phi_qoverp_wrtBS, &b_trkPix_cov_phi_qoverp_wrtBS);
   fChain->SetBranchAddress("trkPix_cov_theta_qoverp_wrtBS", &trkPix_cov_theta_qoverp_wrtBS, &b_trkPix_cov_theta_qoverp_wrtBS);
   fChain->SetBranchAddress("trkPix_d0_wrtBL", &trkPix_d0_wrtBL, &b_trkPix_d0_wrtBL);
   fChain->SetBranchAddress("trkPix_z0_wrtBL", &trkPix_z0_wrtBL, &b_trkPix_z0_wrtBL);
   fChain->SetBranchAddress("trkPix_phi_wrtBL", &trkPix_phi_wrtBL, &b_trkPix_phi_wrtBL);
   fChain->SetBranchAddress("trkPix_d0_err_wrtBL", &trkPix_d0_err_wrtBL, &b_trkPix_d0_err_wrtBL);
   fChain->SetBranchAddress("trkPix_z0_err_wrtBL", &trkPix_z0_err_wrtBL, &b_trkPix_z0_err_wrtBL);
   fChain->SetBranchAddress("trkPix_phi_err_wrtBL", &trkPix_phi_err_wrtBL, &b_trkPix_phi_err_wrtBL);
   fChain->SetBranchAddress("trkPix_theta_err_wrtBL", &trkPix_theta_err_wrtBL, &b_trkPix_theta_err_wrtBL);
   fChain->SetBranchAddress("trkPix_qoverp_err_wrtBL", &trkPix_qoverp_err_wrtBL, &b_trkPix_qoverp_err_wrtBL);
   fChain->SetBranchAddress("trkPix_d0_z0_err_wrtBL", &trkPix_d0_z0_err_wrtBL, &b_trkPix_d0_z0_err_wrtBL);
   fChain->SetBranchAddress("trkPix_d0_phi_err_wrtBL", &trkPix_d0_phi_err_wrtBL, &b_trkPix_d0_phi_err_wrtBL);
   fChain->SetBranchAddress("trkPix_d0_theta_err_wrtBL", &trkPix_d0_theta_err_wrtBL, &b_trkPix_d0_theta_err_wrtBL);
   fChain->SetBranchAddress("trkPix_d0_qoverp_err_wrtBL", &trkPix_d0_qoverp_err_wrtBL, &b_trkPix_d0_qoverp_err_wrtBL);
   fChain->SetBranchAddress("trkPix_z0_phi_err_wrtBL", &trkPix_z0_phi_err_wrtBL, &b_trkPix_z0_phi_err_wrtBL);
   fChain->SetBranchAddress("trkPix_z0_theta_err_wrtBL", &trkPix_z0_theta_err_wrtBL, &b_trkPix_z0_theta_err_wrtBL);
   fChain->SetBranchAddress("trkPix_z0_qoverp_err_wrtBL", &trkPix_z0_qoverp_err_wrtBL, &b_trkPix_z0_qoverp_err_wrtBL);
   fChain->SetBranchAddress("trkPix_phi_theta_err_wrtBL", &trkPix_phi_theta_err_wrtBL, &b_trkPix_phi_theta_err_wrtBL);
   fChain->SetBranchAddress("trkPix_phi_qoverp_err_wrtBL", &trkPix_phi_qoverp_err_wrtBL, &b_trkPix_phi_qoverp_err_wrtBL);
   fChain->SetBranchAddress("trkPix_theta_qoverp_err_wrtBL", &trkPix_theta_qoverp_err_wrtBL, &b_trkPix_theta_qoverp_err_wrtBL);
   fChain->SetBranchAddress("trkPix_chi2", &trkPix_chi2, &b_trkPix_chi2);
   fChain->SetBranchAddress("trkPix_ndof", &trkPix_ndof, &b_trkPix_ndof);
   fChain->SetBranchAddress("trkPix_nBLHits", &trkPix_nBLHits, &b_trkPix_nBLHits);
   fChain->SetBranchAddress("trkPix_nPixHits", &trkPix_nPixHits, &b_trkPix_nPixHits);
   fChain->SetBranchAddress("trkPix_nSCTHits", &trkPix_nSCTHits, &b_trkPix_nSCTHits);
   fChain->SetBranchAddress("trkPix_nTRTHits", &trkPix_nTRTHits, &b_trkPix_nTRTHits);
   fChain->SetBranchAddress("trkPix_nTRTHighTHits", &trkPix_nTRTHighTHits, &b_trkPix_nTRTHighTHits);
   fChain->SetBranchAddress("trkPix_nTRTXenonHits", &trkPix_nTRTXenonHits, &b_trkPix_nTRTXenonHits);
   fChain->SetBranchAddress("trkPix_nPixHoles", &trkPix_nPixHoles, &b_trkPix_nPixHoles);
   fChain->SetBranchAddress("trkPix_nSCTHoles", &trkPix_nSCTHoles, &b_trkPix_nSCTHoles);
   fChain->SetBranchAddress("trkPix_nTRTHoles", &trkPix_nTRTHoles, &b_trkPix_nTRTHoles);
   fChain->SetBranchAddress("trkPix_nPixelDeadSensors", &trkPix_nPixelDeadSensors, &b_trkPix_nPixelDeadSensors);
   fChain->SetBranchAddress("trkPix_nSCTDeadSensors", &trkPix_nSCTDeadSensors, &b_trkPix_nSCTDeadSensors);
   fChain->SetBranchAddress("trkPix_nBLSharedHits", &trkPix_nBLSharedHits, &b_trkPix_nBLSharedHits);
   fChain->SetBranchAddress("trkPix_nPixSharedHits", &trkPix_nPixSharedHits, &b_trkPix_nPixSharedHits);
   fChain->SetBranchAddress("trkPix_nSCTSharedHits", &trkPix_nSCTSharedHits, &b_trkPix_nSCTSharedHits);
   fChain->SetBranchAddress("trkPix_nBLayerSplitHits", &trkPix_nBLayerSplitHits, &b_trkPix_nBLayerSplitHits);
   fChain->SetBranchAddress("trkPix_nPixSplitHits", &trkPix_nPixSplitHits, &b_trkPix_nPixSplitHits);
   fChain->SetBranchAddress("trkPix_expectBLayerHit", &trkPix_expectBLayerHit, &b_trkPix_expectBLayerHit);
   fChain->SetBranchAddress("trkPix_nMDTHits", &trkPix_nMDTHits, &b_trkPix_nMDTHits);
   fChain->SetBranchAddress("trkPix_nCSCEtaHits", &trkPix_nCSCEtaHits, &b_trkPix_nCSCEtaHits);
   fChain->SetBranchAddress("trkPix_nCSCPhiHits", &trkPix_nCSCPhiHits, &b_trkPix_nCSCPhiHits);
   fChain->SetBranchAddress("trkPix_nRPCEtaHits", &trkPix_nRPCEtaHits, &b_trkPix_nRPCEtaHits);
   fChain->SetBranchAddress("trkPix_nRPCPhiHits", &trkPix_nRPCPhiHits, &b_trkPix_nRPCPhiHits);
   fChain->SetBranchAddress("trkPix_nTGCEtaHits", &trkPix_nTGCEtaHits, &b_trkPix_nTGCEtaHits);
   fChain->SetBranchAddress("trkPix_nTGCPhiHits", &trkPix_nTGCPhiHits, &b_trkPix_nTGCPhiHits);
   fChain->SetBranchAddress("trkPix_nHits", &trkPix_nHits, &b_trkPix_nHits);
   fChain->SetBranchAddress("trkPix_nHoles", &trkPix_nHoles, &b_trkPix_nHoles);
   fChain->SetBranchAddress("trkPix_hitPattern", &trkPix_hitPattern, &b_trkPix_hitPattern);
   fChain->SetBranchAddress("trkPix_TRTHighTHitsRatio", &trkPix_TRTHighTHitsRatio, &b_trkPix_TRTHighTHitsRatio);
   fChain->SetBranchAddress("trkPix_TRTHighTOutliersRatio", &trkPix_TRTHighTOutliersRatio, &b_trkPix_TRTHighTOutliersRatio);
   fChain->SetBranchAddress("trkPix_pixeldEdx", &trkPix_pixeldEdx, &b_trkPix_pixeldEdx);
   fChain->SetBranchAddress("trkPix_nGoodHitsPixeldEdx", &trkPix_nGoodHitsPixeldEdx, &b_trkPix_nGoodHitsPixeldEdx);
   fChain->SetBranchAddress("trkPix_massPixeldEdx", &trkPix_massPixeldEdx, &b_trkPix_massPixeldEdx);
   fChain->SetBranchAddress("trkPix_likelihoodsPixeldEdx", &trkPix_likelihoodsPixeldEdx, &b_trkPix_likelihoodsPixeldEdx);
   fChain->SetBranchAddress("trkPix_fitter", &trkPix_fitter, &b_trkPix_fitter);
   fChain->SetBranchAddress("trkPix_patternReco1", &trkPix_patternReco1, &b_trkPix_patternReco1);
   fChain->SetBranchAddress("trkPix_patternReco2", &trkPix_patternReco2, &b_trkPix_patternReco2);
   fChain->SetBranchAddress("trkPix_trackProperties", &trkPix_trackProperties, &b_trkPix_trackProperties);
   fChain->SetBranchAddress("trkPix_particleHypothesis", &trkPix_particleHypothesis, &b_trkPix_particleHypothesis);
   fChain->SetBranchAddress("trkPix_blayerPrediction_x", &trkPix_blayerPrediction_x, &b_trkPix_blayerPrediction_x);
   fChain->SetBranchAddress("trkPix_blayerPrediction_y", &trkPix_blayerPrediction_y, &b_trkPix_blayerPrediction_y);
   fChain->SetBranchAddress("trkPix_blayerPrediction_z", &trkPix_blayerPrediction_z, &b_trkPix_blayerPrediction_z);
   fChain->SetBranchAddress("trkPix_blayerPrediction_locX", &trkPix_blayerPrediction_locX, &b_trkPix_blayerPrediction_locX);
   fChain->SetBranchAddress("trkPix_blayerPrediction_locY", &trkPix_blayerPrediction_locY, &b_trkPix_blayerPrediction_locY);
   fChain->SetBranchAddress("trkPix_blayerPrediction_err_locX", &trkPix_blayerPrediction_err_locX, &b_trkPix_blayerPrediction_err_locX);
   fChain->SetBranchAddress("trkPix_blayerPrediction_err_locY", &trkPix_blayerPrediction_err_locY, &b_trkPix_blayerPrediction_err_locY);
   fChain->SetBranchAddress("trkPix_blayerPrediction_etaDistToEdge", &trkPix_blayerPrediction_etaDistToEdge, &b_trkPix_blayerPrediction_etaDistToEdge);
   fChain->SetBranchAddress("trkPix_blayerPrediction_phiDistToEdge", &trkPix_blayerPrediction_phiDistToEdge, &b_trkPix_blayerPrediction_phiDistToEdge);
   fChain->SetBranchAddress("trkPix_blayerPrediction_detElementId", &trkPix_blayerPrediction_detElementId, &b_trkPix_blayerPrediction_detElementId);
   fChain->SetBranchAddress("trkPix_blayerPrediction_row", &trkPix_blayerPrediction_row, &b_trkPix_blayerPrediction_row);
   fChain->SetBranchAddress("trkPix_blayerPrediction_col", &trkPix_blayerPrediction_col, &b_trkPix_blayerPrediction_col);
   fChain->SetBranchAddress("trkPix_blayerPrediction_type", &trkPix_blayerPrediction_type, &b_trkPix_blayerPrediction_type);
   fChain->SetBranchAddress("trt_RDO_countRDOhitsInEvent", &trt_RDO_countRDOhitsInEvent, &b_trt_RDO_countRDOhitsInEvent);
   fChain->SetBranchAddress("trt_RDO_countBarrelhitsInEvent", &trt_RDO_countBarrelhitsInEvent, &b_trt_RDO_countBarrelhitsInEvent);
   fChain->SetBranchAddress("trt_RDO_countEndCaphitsInEvent", &trt_RDO_countEndCaphitsInEvent, &b_trt_RDO_countEndCaphitsInEvent);
   fChain->SetBranchAddress("trt_RDO_countEndCapAhitsInEvent", &trt_RDO_countEndCapAhitsInEvent, &b_trt_RDO_countEndCapAhitsInEvent);
   fChain->SetBranchAddress("trt_RDO_countEndCapChitsInEvent", &trt_RDO_countEndCapChitsInEvent, &b_trt_RDO_countEndCapChitsInEvent);
   fChain->SetBranchAddress("trt_RDO_countdeadstraws", &trt_RDO_countdeadstraws, &b_trt_RDO_countdeadstraws);
   fChain->SetBranchAddress("HIFlow_v1_PsiFCAL0_w", &HIFlow_v1_PsiFCAL0_w, &b_HIFlow_v1_PsiFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v1_PsiPFCAL0_w", &HIFlow_v1_PsiPFCAL0_w, &b_HIFlow_v1_PsiPFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v1_PsiNFCAL0_w", &HIFlow_v1_PsiNFCAL0_w, &b_HIFlow_v1_PsiNFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v1_EtInLayer", &HIFlow_v1_EtInLayer, &b_HIFlow_v1_EtInLayer);
   fChain->SetBranchAddress("HIFlow_v1_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers", &HIFlow_v1_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers, &b_HIFlow_v1_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers);
   fChain->SetBranchAddress("HIFlow_v1_AvgV2fromCalo", &HIFlow_v1_AvgV2fromCalo, &b_HIFlow_v1_AvgV2fromCalo);
   fChain->SetBranchAddress("HIFlow_v1_PsiHICaloUtilLayers", &HIFlow_v1_PsiHICaloUtilLayers, &b_HIFlow_v1_PsiHICaloUtilLayers);
   fChain->SetBranchAddress("HIFlow_v1_PsiEtHICaloUtilLayers", &HIFlow_v1_PsiEtHICaloUtilLayers, &b_HIFlow_v1_PsiEtHICaloUtilLayers);
   fChain->SetBranchAddress("HIFlow_v1_PsiPtrack", &HIFlow_v1_PsiPtrack, &b_HIFlow_v1_PsiPtrack);
   fChain->SetBranchAddress("HIFlow_v1_PsiNtrack", &HIFlow_v1_PsiNtrack, &b_HIFlow_v1_PsiNtrack);
   fChain->SetBranchAddress("HIFlow_v1_v2FCAL0sil", &HIFlow_v1_v2FCAL0sil, &b_HIFlow_v1_v2FCAL0sil);
   fChain->SetBranchAddress("HIFlow_v1_v2track", &HIFlow_v1_v2track, &b_HIFlow_v1_v2track);
   fChain->SetBranchAddress("HIFlow_v1_Meanv2_Psi_From_FCAL0CaloCel_IDLayers", &HIFlow_v1_Meanv2_Psi_From_FCAL0CaloCel_IDLayers, &b_HIFlow_v1_Meanv2_Psi_From_FCAL0CaloCel_IDLayers);
   fChain->SetBranchAddress("HIFlow_v2_PsiFCAL0_w", &HIFlow_v2_PsiFCAL0_w, &b_HIFlow_v2_PsiFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v2_PsiPFCAL0_w", &HIFlow_v2_PsiPFCAL0_w, &b_HIFlow_v2_PsiPFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v2_PsiNFCAL0_w", &HIFlow_v2_PsiNFCAL0_w, &b_HIFlow_v2_PsiNFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v2_EtInLayer", &HIFlow_v2_EtInLayer, &b_HIFlow_v2_EtInLayer);
   fChain->SetBranchAddress("HIFlow_v2_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers", &HIFlow_v2_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers, &b_HIFlow_v2_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers);
   fChain->SetBranchAddress("HIFlow_v2_AvgV2fromCalo", &HIFlow_v2_AvgV2fromCalo, &b_HIFlow_v2_AvgV2fromCalo);
   fChain->SetBranchAddress("HIFlow_v2_PsiHICaloUtilLayers", &HIFlow_v2_PsiHICaloUtilLayers, &b_HIFlow_v2_PsiHICaloUtilLayers);
   fChain->SetBranchAddress("HIFlow_v2_PsiEtHICaloUtilLayers", &HIFlow_v2_PsiEtHICaloUtilLayers, &b_HIFlow_v2_PsiEtHICaloUtilLayers);
   fChain->SetBranchAddress("HIFlow_v2_PsiPtrack", &HIFlow_v2_PsiPtrack, &b_HIFlow_v2_PsiPtrack);
   fChain->SetBranchAddress("HIFlow_v2_PsiNtrack", &HIFlow_v2_PsiNtrack, &b_HIFlow_v2_PsiNtrack);
   fChain->SetBranchAddress("HIFlow_v2_v2FCAL0sil", &HIFlow_v2_v2FCAL0sil, &b_HIFlow_v2_v2FCAL0sil);
   fChain->SetBranchAddress("HIFlow_v2_v2track", &HIFlow_v2_v2track, &b_HIFlow_v2_v2track);
   fChain->SetBranchAddress("HIFlow_v2_Meanv2_Psi_From_FCAL0CaloCel_IDLayers", &HIFlow_v2_Meanv2_Psi_From_FCAL0CaloCel_IDLayers, &b_HIFlow_v2_Meanv2_Psi_From_FCAL0CaloCel_IDLayers);
   fChain->SetBranchAddress("HIFlow_v3_PsiFCAL0_w", &HIFlow_v3_PsiFCAL0_w, &b_HIFlow_v3_PsiFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v3_PsiPFCAL0_w", &HIFlow_v3_PsiPFCAL0_w, &b_HIFlow_v3_PsiPFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v3_PsiNFCAL0_w", &HIFlow_v3_PsiNFCAL0_w, &b_HIFlow_v3_PsiNFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v3_EtInLayer", &HIFlow_v3_EtInLayer, &b_HIFlow_v3_EtInLayer);
   fChain->SetBranchAddress("HIFlow_v3_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers", &HIFlow_v3_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers, &b_HIFlow_v3_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers);
   fChain->SetBranchAddress("HIFlow_v3_AvgV2fromCalo", &HIFlow_v3_AvgV2fromCalo, &b_HIFlow_v3_AvgV2fromCalo);
   fChain->SetBranchAddress("HIFlow_v3_PsiHICaloUtilLayers", &HIFlow_v3_PsiHICaloUtilLayers, &b_HIFlow_v3_PsiHICaloUtilLayers);
   fChain->SetBranchAddress("HIFlow_v3_PsiEtHICaloUtilLayers", &HIFlow_v3_PsiEtHICaloUtilLayers, &b_HIFlow_v3_PsiEtHICaloUtilLayers);
   fChain->SetBranchAddress("HIFlow_v3_PsiPtrack", &HIFlow_v3_PsiPtrack, &b_HIFlow_v3_PsiPtrack);
   fChain->SetBranchAddress("HIFlow_v3_PsiNtrack", &HIFlow_v3_PsiNtrack, &b_HIFlow_v3_PsiNtrack);
   fChain->SetBranchAddress("HIFlow_v3_v2FCAL0sil", &HIFlow_v3_v2FCAL0sil, &b_HIFlow_v3_v2FCAL0sil);
   fChain->SetBranchAddress("HIFlow_v3_v2track", &HIFlow_v3_v2track, &b_HIFlow_v3_v2track);
   fChain->SetBranchAddress("HIFlow_v3_Meanv2_Psi_From_FCAL0CaloCel_IDLayers", &HIFlow_v3_Meanv2_Psi_From_FCAL0CaloCel_IDLayers, &b_HIFlow_v3_Meanv2_Psi_From_FCAL0CaloCel_IDLayers);
   fChain->SetBranchAddress("HIFlow_v4_PsiFCAL0_w", &HIFlow_v4_PsiFCAL0_w, &b_HIFlow_v4_PsiFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v4_PsiPFCAL0_w", &HIFlow_v4_PsiPFCAL0_w, &b_HIFlow_v4_PsiPFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v4_PsiNFCAL0_w", &HIFlow_v4_PsiNFCAL0_w, &b_HIFlow_v4_PsiNFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v4_EtInLayer", &HIFlow_v4_EtInLayer, &b_HIFlow_v4_EtInLayer);
   fChain->SetBranchAddress("HIFlow_v4_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers", &HIFlow_v4_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers, &b_HIFlow_v4_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers);
   fChain->SetBranchAddress("HIFlow_v4_AvgV2fromCalo", &HIFlow_v4_AvgV2fromCalo, &b_HIFlow_v4_AvgV2fromCalo);
   fChain->SetBranchAddress("HIFlow_v4_PsiHICaloUtilLayers", &HIFlow_v4_PsiHICaloUtilLayers, &b_HIFlow_v4_PsiHICaloUtilLayers);
   fChain->SetBranchAddress("HIFlow_v4_PsiEtHICaloUtilLayers", &HIFlow_v4_PsiEtHICaloUtilLayers, &b_HIFlow_v4_PsiEtHICaloUtilLayers);
   fChain->SetBranchAddress("HIFlow_v4_PsiPtrack", &HIFlow_v4_PsiPtrack, &b_HIFlow_v4_PsiPtrack);
   fChain->SetBranchAddress("HIFlow_v4_PsiNtrack", &HIFlow_v4_PsiNtrack, &b_HIFlow_v4_PsiNtrack);
   fChain->SetBranchAddress("HIFlow_v4_v2FCAL0sil", &HIFlow_v4_v2FCAL0sil, &b_HIFlow_v4_v2FCAL0sil);
   fChain->SetBranchAddress("HIFlow_v4_v2track", &HIFlow_v4_v2track, &b_HIFlow_v4_v2track);
   fChain->SetBranchAddress("HIFlow_v4_Meanv2_Psi_From_FCAL0CaloCel_IDLayers", &HIFlow_v4_Meanv2_Psi_From_FCAL0CaloCel_IDLayers, &b_HIFlow_v4_Meanv2_Psi_From_FCAL0CaloCel_IDLayers);
   fChain->SetBranchAddress("HIFlow_v5_PsiFCAL0_w", &HIFlow_v5_PsiFCAL0_w, &b_HIFlow_v5_PsiFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v5_PsiPFCAL0_w", &HIFlow_v5_PsiPFCAL0_w, &b_HIFlow_v5_PsiPFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v5_PsiNFCAL0_w", &HIFlow_v5_PsiNFCAL0_w, &b_HIFlow_v5_PsiNFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v5_EtInLayer", &HIFlow_v5_EtInLayer, &b_HIFlow_v5_EtInLayer);
   fChain->SetBranchAddress("HIFlow_v5_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers", &HIFlow_v5_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers, &b_HIFlow_v5_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers);
   fChain->SetBranchAddress("HIFlow_v5_AvgV2fromCalo", &HIFlow_v5_AvgV2fromCalo, &b_HIFlow_v5_AvgV2fromCalo);
   fChain->SetBranchAddress("HIFlow_v5_PsiHICaloUtilLayers", &HIFlow_v5_PsiHICaloUtilLayers, &b_HIFlow_v5_PsiHICaloUtilLayers);
   fChain->SetBranchAddress("HIFlow_v5_PsiEtHICaloUtilLayers", &HIFlow_v5_PsiEtHICaloUtilLayers, &b_HIFlow_v5_PsiEtHICaloUtilLayers);
   fChain->SetBranchAddress("HIFlow_v5_PsiPtrack", &HIFlow_v5_PsiPtrack, &b_HIFlow_v5_PsiPtrack);
   fChain->SetBranchAddress("HIFlow_v5_PsiNtrack", &HIFlow_v5_PsiNtrack, &b_HIFlow_v5_PsiNtrack);
   fChain->SetBranchAddress("HIFlow_v5_v2FCAL0sil", &HIFlow_v5_v2FCAL0sil, &b_HIFlow_v5_v2FCAL0sil);
   fChain->SetBranchAddress("HIFlow_v5_v2track", &HIFlow_v5_v2track, &b_HIFlow_v5_v2track);
   fChain->SetBranchAddress("HIFlow_v5_Meanv2_Psi_From_FCAL0CaloCel_IDLayers", &HIFlow_v5_Meanv2_Psi_From_FCAL0CaloCel_IDLayers, &b_HIFlow_v5_Meanv2_Psi_From_FCAL0CaloCel_IDLayers);
   fChain->SetBranchAddress("HIFlow_v6_PsiFCAL0_w", &HIFlow_v6_PsiFCAL0_w, &b_HIFlow_v6_PsiFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v6_PsiPFCAL0_w", &HIFlow_v6_PsiPFCAL0_w, &b_HIFlow_v6_PsiPFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v6_PsiNFCAL0_w", &HIFlow_v6_PsiNFCAL0_w, &b_HIFlow_v6_PsiNFCAL0_w);
   fChain->SetBranchAddress("HIFlow_v6_EtInLayer", &HIFlow_v6_EtInLayer, &b_HIFlow_v6_EtInLayer);
   fChain->SetBranchAddress("HIFlow_v6_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers", &HIFlow_v6_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers, &b_HIFlow_v6_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers);
   fChain->SetBranchAddress("HIFlow_v6_AvgV2fromCalo", &HIFlow_v6_AvgV2fromCalo, &b_HIFlow_v6_AvgV2fromCalo);
   fChain->SetBranchAddress("HIFlow_v6_PsiHICaloUtilLayers", &HIFlow_v6_PsiHICaloUtilLayers, &b_HIFlow_v6_PsiHICaloUtilLayers);
   fChain->SetBranchAddress("HIFlow_v6_PsiEtHICaloUtilLayers", &HIFlow_v6_PsiEtHICaloUtilLayers, &b_HIFlow_v6_PsiEtHICaloUtilLayers);
   fChain->SetBranchAddress("HIFlow_v6_PsiPtrack", &HIFlow_v6_PsiPtrack, &b_HIFlow_v6_PsiPtrack);
   fChain->SetBranchAddress("HIFlow_v6_PsiNtrack", &HIFlow_v6_PsiNtrack, &b_HIFlow_v6_PsiNtrack);
   fChain->SetBranchAddress("HIFlow_v6_v2FCAL0sil", &HIFlow_v6_v2FCAL0sil, &b_HIFlow_v6_v2FCAL0sil);
   fChain->SetBranchAddress("HIFlow_v6_v2track", &HIFlow_v6_v2track, &b_HIFlow_v6_v2track);
   fChain->SetBranchAddress("HIFlow_v6_Meanv2_Psi_From_FCAL0CaloCel_IDLayers", &HIFlow_v6_Meanv2_Psi_From_FCAL0CaloCel_IDLayers, &b_HIFlow_v6_Meanv2_Psi_From_FCAL0CaloCel_IDLayers);
   fChain->SetBranchAddress("MET_RefFinal_etx", &MET_RefFinal_etx, &b_MET_RefFinal_etx);
   fChain->SetBranchAddress("MET_RefFinal_ety", &MET_RefFinal_ety, &b_MET_RefFinal_ety);
   fChain->SetBranchAddress("MET_RefFinal_phi", &MET_RefFinal_phi, &b_MET_RefFinal_phi);
   fChain->SetBranchAddress("MET_RefFinal_et", &MET_RefFinal_et, &b_MET_RefFinal_et);
   fChain->SetBranchAddress("MET_RefFinal_sumet", &MET_RefFinal_sumet, &b_MET_RefFinal_sumet);
   fChain->SetBranchAddress("MET_RefFinal_etx_CentralReg", &MET_RefFinal_etx_CentralReg, &b_MET_RefFinal_etx_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_ety_CentralReg", &MET_RefFinal_ety_CentralReg, &b_MET_RefFinal_ety_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_sumet_CentralReg", &MET_RefFinal_sumet_CentralReg, &b_MET_RefFinal_sumet_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_phi_CentralReg", &MET_RefFinal_phi_CentralReg, &b_MET_RefFinal_phi_CentralReg);
   fChain->SetBranchAddress("MET_RefFinal_etx_EndcapRegion", &MET_RefFinal_etx_EndcapRegion, &b_MET_RefFinal_etx_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_ety_EndcapRegion", &MET_RefFinal_ety_EndcapRegion, &b_MET_RefFinal_ety_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_sumet_EndcapRegion", &MET_RefFinal_sumet_EndcapRegion, &b_MET_RefFinal_sumet_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_phi_EndcapRegion", &MET_RefFinal_phi_EndcapRegion, &b_MET_RefFinal_phi_EndcapRegion);
   fChain->SetBranchAddress("MET_RefFinal_etx_ForwardReg", &MET_RefFinal_etx_ForwardReg, &b_MET_RefFinal_etx_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_ety_ForwardReg", &MET_RefFinal_ety_ForwardReg, &b_MET_RefFinal_ety_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_sumet_ForwardReg", &MET_RefFinal_sumet_ForwardReg, &b_MET_RefFinal_sumet_ForwardReg);
   fChain->SetBranchAddress("MET_RefFinal_phi_ForwardReg", &MET_RefFinal_phi_ForwardReg, &b_MET_RefFinal_phi_ForwardReg);
   fChain->SetBranchAddress("cccEt2_Et2_Nh_Calo", &cccEt2_Et2_Nh_Calo, &b_cccEt2_Et2_Nh_Calo);
   fChain->SetBranchAddress("cccEt2_Et2_Eh_Calo", &cccEt2_Et2_Eh_Calo, &b_cccEt2_Et2_Eh_Calo);
   fChain->SetBranchAddress("cccEt2_Et2_Nh_EM", &cccEt2_Et2_Nh_EM, &b_cccEt2_Et2_Nh_EM);
   fChain->SetBranchAddress("cccEt2_Et2_Eh_EM", &cccEt2_Et2_Eh_EM, &b_cccEt2_Et2_Eh_EM);
   fChain->SetBranchAddress("cccEt2_Et2_Nh_HAD", &cccEt2_Et2_Nh_HAD, &b_cccEt2_Et2_Nh_HAD);
   fChain->SetBranchAddress("cccEt2_Et2_Eh_HAD", &cccEt2_Et2_Eh_HAD, &b_cccEt2_Et2_Eh_HAD);
   fChain->SetBranchAddress("cccEt2_Et2_Nh_PresB", &cccEt2_Et2_Nh_PresB, &b_cccEt2_Et2_Nh_PresB);
   fChain->SetBranchAddress("cccEt2_Et2_Eh_PresB", &cccEt2_Et2_Eh_PresB, &b_cccEt2_Et2_Eh_PresB);
   fChain->SetBranchAddress("cccEt2_Et2_Nh_EMB", &cccEt2_Et2_Nh_EMB, &b_cccEt2_Et2_Nh_EMB);
   fChain->SetBranchAddress("cccEt2_Et2_Eh_EMB", &cccEt2_Et2_Eh_EMB, &b_cccEt2_Et2_Eh_EMB);
   fChain->SetBranchAddress("cccEt2_Et2_Nh_EMEC", &cccEt2_Et2_Nh_EMEC, &b_cccEt2_Et2_Nh_EMEC);
   fChain->SetBranchAddress("cccEt2_Et2_Eh_EMEC", &cccEt2_Et2_Eh_EMEC, &b_cccEt2_Et2_Eh_EMEC);
   fChain->SetBranchAddress("cccEt2_Et2_Nh_Tile", &cccEt2_Et2_Nh_Tile, &b_cccEt2_Et2_Nh_Tile);
   fChain->SetBranchAddress("cccEt2_Et2_Eh_Tile", &cccEt2_Et2_Eh_Tile, &b_cccEt2_Et2_Eh_Tile);
   fChain->SetBranchAddress("cccEt2_Et2_Nh_TileGap", &cccEt2_Et2_Nh_TileGap, &b_cccEt2_Et2_Nh_TileGap);
   fChain->SetBranchAddress("cccEt2_Et2_Eh_TileGap", &cccEt2_Et2_Eh_TileGap, &b_cccEt2_Et2_Eh_TileGap);
   fChain->SetBranchAddress("cccEt2_Et2_Nh_HEC", &cccEt2_Et2_Nh_HEC, &b_cccEt2_Et2_Nh_HEC);
   fChain->SetBranchAddress("cccEt2_Et2_Eh_HEC", &cccEt2_Et2_Eh_HEC, &b_cccEt2_Et2_Eh_HEC);
   fChain->SetBranchAddress("cccEt2_Et2_Nh_FCal", &cccEt2_Et2_Nh_FCal, &b_cccEt2_Et2_Nh_FCal);
   fChain->SetBranchAddress("cccEt2_Et2_Eh_FCal", &cccEt2_Et2_Eh_FCal, &b_cccEt2_Et2_Eh_FCal);
   fChain->SetBranchAddress("cccEt2_Et2_Nh_PresE", &cccEt2_Et2_Nh_PresE, &b_cccEt2_Et2_Nh_PresE);
   fChain->SetBranchAddress("cccEt2_Et2_Eh_PresE", &cccEt2_Et2_Eh_PresE, &b_cccEt2_Et2_Eh_PresE);
   fChain->SetBranchAddress("cccEt2_Et2_Nh_Scint", &cccEt2_Et2_Nh_Scint, &b_cccEt2_Et2_Nh_Scint);
   fChain->SetBranchAddress("cccEt2_Et2_Eh_Scint", &cccEt2_Et2_Eh_Scint, &b_cccEt2_Et2_Eh_Scint);
   fChain->SetBranchAddress("cccEt2_p2_Nh_Calo", &cccEt2_p2_Nh_Calo, &b_cccEt2_p2_Nh_Calo);
   fChain->SetBranchAddress("cccEt2_p2_Eh_Calo", &cccEt2_p2_Eh_Calo, &b_cccEt2_p2_Eh_Calo);
   fChain->SetBranchAddress("cccEt2_p2_Nh_EM", &cccEt2_p2_Nh_EM, &b_cccEt2_p2_Nh_EM);
   fChain->SetBranchAddress("cccEt2_p2_Eh_EM", &cccEt2_p2_Eh_EM, &b_cccEt2_p2_Eh_EM);
   fChain->SetBranchAddress("cccEt2_p2_Nh_HAD", &cccEt2_p2_Nh_HAD, &b_cccEt2_p2_Nh_HAD);
   fChain->SetBranchAddress("cccEt2_p2_Eh_HAD", &cccEt2_p2_Eh_HAD, &b_cccEt2_p2_Eh_HAD);
   fChain->SetBranchAddress("cccEt2_p2_Nh_PresB", &cccEt2_p2_Nh_PresB, &b_cccEt2_p2_Nh_PresB);
   fChain->SetBranchAddress("cccEt2_p2_Eh_PresB", &cccEt2_p2_Eh_PresB, &b_cccEt2_p2_Eh_PresB);
   fChain->SetBranchAddress("cccEt2_p2_Nh_EMB", &cccEt2_p2_Nh_EMB, &b_cccEt2_p2_Nh_EMB);
   fChain->SetBranchAddress("cccEt2_p2_Eh_EMB", &cccEt2_p2_Eh_EMB, &b_cccEt2_p2_Eh_EMB);
   fChain->SetBranchAddress("cccEt2_p2_Nh_EMEC", &cccEt2_p2_Nh_EMEC, &b_cccEt2_p2_Nh_EMEC);
   fChain->SetBranchAddress("cccEt2_p2_Eh_EMEC", &cccEt2_p2_Eh_EMEC, &b_cccEt2_p2_Eh_EMEC);
   fChain->SetBranchAddress("cccEt2_p2_Nh_Tile", &cccEt2_p2_Nh_Tile, &b_cccEt2_p2_Nh_Tile);
   fChain->SetBranchAddress("cccEt2_p2_Eh_Tile", &cccEt2_p2_Eh_Tile, &b_cccEt2_p2_Eh_Tile);
   fChain->SetBranchAddress("cccEt2_p2_Nh_TileGap", &cccEt2_p2_Nh_TileGap, &b_cccEt2_p2_Nh_TileGap);
   fChain->SetBranchAddress("cccEt2_p2_Eh_TileGap", &cccEt2_p2_Eh_TileGap, &b_cccEt2_p2_Eh_TileGap);
   fChain->SetBranchAddress("cccEt2_p2_Nh_HEC", &cccEt2_p2_Nh_HEC, &b_cccEt2_p2_Nh_HEC);
   fChain->SetBranchAddress("cccEt2_p2_Eh_HEC", &cccEt2_p2_Eh_HEC, &b_cccEt2_p2_Eh_HEC);
   fChain->SetBranchAddress("cccEt2_p2_Nh_FCal", &cccEt2_p2_Nh_FCal, &b_cccEt2_p2_Nh_FCal);
   fChain->SetBranchAddress("cccEt2_p2_Eh_FCal", &cccEt2_p2_Eh_FCal, &b_cccEt2_p2_Eh_FCal);
   fChain->SetBranchAddress("cccEt2_p2_Nh_PresE", &cccEt2_p2_Nh_PresE, &b_cccEt2_p2_Nh_PresE);
   fChain->SetBranchAddress("cccEt2_p2_Eh_PresE", &cccEt2_p2_Eh_PresE, &b_cccEt2_p2_Eh_PresE);
   fChain->SetBranchAddress("cccEt2_p2_Nh_Scint", &cccEt2_p2_Nh_Scint, &b_cccEt2_p2_Nh_Scint);
   fChain->SetBranchAddress("cccEt2_p2_Eh_Scint", &cccEt2_p2_Eh_Scint, &b_cccEt2_p2_Eh_Scint);
   fChain->SetBranchAddress("cccEt2_n2_Nh_Calo", &cccEt2_n2_Nh_Calo, &b_cccEt2_n2_Nh_Calo);
   fChain->SetBranchAddress("cccEt2_n2_Eh_Calo", &cccEt2_n2_Eh_Calo, &b_cccEt2_n2_Eh_Calo);
   fChain->SetBranchAddress("cccEt2_n2_Nh_EM", &cccEt2_n2_Nh_EM, &b_cccEt2_n2_Nh_EM);
   fChain->SetBranchAddress("cccEt2_n2_Eh_EM", &cccEt2_n2_Eh_EM, &b_cccEt2_n2_Eh_EM);
   fChain->SetBranchAddress("cccEt2_n2_Nh_HAD", &cccEt2_n2_Nh_HAD, &b_cccEt2_n2_Nh_HAD);
   fChain->SetBranchAddress("cccEt2_n2_Eh_HAD", &cccEt2_n2_Eh_HAD, &b_cccEt2_n2_Eh_HAD);
   fChain->SetBranchAddress("cccEt2_n2_Nh_PresB", &cccEt2_n2_Nh_PresB, &b_cccEt2_n2_Nh_PresB);
   fChain->SetBranchAddress("cccEt2_n2_Eh_PresB", &cccEt2_n2_Eh_PresB, &b_cccEt2_n2_Eh_PresB);
   fChain->SetBranchAddress("cccEt2_n2_Nh_EMB", &cccEt2_n2_Nh_EMB, &b_cccEt2_n2_Nh_EMB);
   fChain->SetBranchAddress("cccEt2_n2_Eh_EMB", &cccEt2_n2_Eh_EMB, &b_cccEt2_n2_Eh_EMB);
   fChain->SetBranchAddress("cccEt2_n2_Nh_EMEC", &cccEt2_n2_Nh_EMEC, &b_cccEt2_n2_Nh_EMEC);
   fChain->SetBranchAddress("cccEt2_n2_Eh_EMEC", &cccEt2_n2_Eh_EMEC, &b_cccEt2_n2_Eh_EMEC);
   fChain->SetBranchAddress("cccEt2_n2_Nh_Tile", &cccEt2_n2_Nh_Tile, &b_cccEt2_n2_Nh_Tile);
   fChain->SetBranchAddress("cccEt2_n2_Eh_Tile", &cccEt2_n2_Eh_Tile, &b_cccEt2_n2_Eh_Tile);
   fChain->SetBranchAddress("cccEt2_n2_Nh_TileGap", &cccEt2_n2_Nh_TileGap, &b_cccEt2_n2_Nh_TileGap);
   fChain->SetBranchAddress("cccEt2_n2_Eh_TileGap", &cccEt2_n2_Eh_TileGap, &b_cccEt2_n2_Eh_TileGap);
   fChain->SetBranchAddress("cccEt2_n2_Nh_HEC", &cccEt2_n2_Nh_HEC, &b_cccEt2_n2_Nh_HEC);
   fChain->SetBranchAddress("cccEt2_n2_Eh_HEC", &cccEt2_n2_Eh_HEC, &b_cccEt2_n2_Eh_HEC);
   fChain->SetBranchAddress("cccEt2_n2_Nh_FCal", &cccEt2_n2_Nh_FCal, &b_cccEt2_n2_Nh_FCal);
   fChain->SetBranchAddress("cccEt2_n2_Eh_FCal", &cccEt2_n2_Eh_FCal, &b_cccEt2_n2_Eh_FCal);
   fChain->SetBranchAddress("cccEt2_n2_Nh_PresE", &cccEt2_n2_Nh_PresE, &b_cccEt2_n2_Nh_PresE);
   fChain->SetBranchAddress("cccEt2_n2_Eh_PresE", &cccEt2_n2_Eh_PresE, &b_cccEt2_n2_Eh_PresE);
   fChain->SetBranchAddress("cccEt2_n2_Nh_Scint", &cccEt2_n2_Nh_Scint, &b_cccEt2_n2_Nh_Scint);
   fChain->SetBranchAddress("cccEt2_n2_Eh_Scint", &cccEt2_n2_Eh_Scint, &b_cccEt2_n2_Eh_Scint);
   fChain->SetBranchAddress("cl_hadTopo_n", &cl_hadTopo_n, &b_cl_hadTopo_n);
   fChain->SetBranchAddress("cl_hadTopo_E", &cl_hadTopo_E, &b_cl_hadTopo_E);
   fChain->SetBranchAddress("cl_hadTopo_pt", &cl_hadTopo_pt, &b_cl_hadTopo_pt);
   fChain->SetBranchAddress("cl_hadTopo_eta", &cl_hadTopo_eta, &b_cl_hadTopo_eta);
   fChain->SetBranchAddress("cl_hadTopo_phi", &cl_hadTopo_phi, &b_cl_hadTopo_phi);
   fChain->SetBranchAddress("cl_hadTopo_E_em", &cl_hadTopo_E_em, &b_cl_hadTopo_E_em);
   fChain->SetBranchAddress("cl_hadTopo_E_had", &cl_hadTopo_E_had, &b_cl_hadTopo_E_had);
   fChain->SetBranchAddress("cl_hadTopo_significance", &cl_hadTopo_significance, &b_cl_hadTopo_significance);
   fChain->SetBranchAddress("cl_hadTopo_cellSignificance", &cl_hadTopo_cellSignificance, &b_cl_hadTopo_cellSignificance);
   fChain->SetBranchAddress("cl_hadTopo_cellSigSampling", &cl_hadTopo_cellSigSampling, &b_cl_hadTopo_cellSigSampling);
   fChain->SetBranchAddress("cl_hadTopo_firstEdens", &cl_hadTopo_firstEdens, &b_cl_hadTopo_firstEdens);
   fChain->SetBranchAddress("cl_hadTopo_cellmaxfrac", &cl_hadTopo_cellmaxfrac, &b_cl_hadTopo_cellmaxfrac);
   fChain->SetBranchAddress("cl_hadTopo_longitudinal", &cl_hadTopo_longitudinal, &b_cl_hadTopo_longitudinal);
   fChain->SetBranchAddress("cl_hadTopo_secondlambda", &cl_hadTopo_secondlambda, &b_cl_hadTopo_secondlambda);
   fChain->SetBranchAddress("cl_hadTopo_lateral", &cl_hadTopo_lateral, &b_cl_hadTopo_lateral);
   fChain->SetBranchAddress("cl_hadTopo_secondR", &cl_hadTopo_secondR, &b_cl_hadTopo_secondR);
   fChain->SetBranchAddress("cl_hadTopo_centerlambda", &cl_hadTopo_centerlambda, &b_cl_hadTopo_centerlambda);
   fChain->SetBranchAddress("cl_hadTopo_deltaTheta", &cl_hadTopo_deltaTheta, &b_cl_hadTopo_deltaTheta);
   fChain->SetBranchAddress("cl_hadTopo_deltaPhi", &cl_hadTopo_deltaPhi, &b_cl_hadTopo_deltaPhi);
   fChain->SetBranchAddress("cl_hadTopo_centermag", &cl_hadTopo_centermag, &b_cl_hadTopo_centermag);
   fChain->SetBranchAddress("cl_hadTopo_time", &cl_hadTopo_time, &b_cl_hadTopo_time);
   fChain->SetBranchAddress("cl_hadTopo_E_PreSamplerB", &cl_hadTopo_E_PreSamplerB, &b_cl_hadTopo_E_PreSamplerB);
   fChain->SetBranchAddress("cl_hadTopo_E_EMB1", &cl_hadTopo_E_EMB1, &b_cl_hadTopo_E_EMB1);
   fChain->SetBranchAddress("cl_hadTopo_E_EMB2", &cl_hadTopo_E_EMB2, &b_cl_hadTopo_E_EMB2);
   fChain->SetBranchAddress("cl_hadTopo_E_EMB3", &cl_hadTopo_E_EMB3, &b_cl_hadTopo_E_EMB3);
   fChain->SetBranchAddress("cl_hadTopo_E_PreSamplerE", &cl_hadTopo_E_PreSamplerE, &b_cl_hadTopo_E_PreSamplerE);
   fChain->SetBranchAddress("cl_hadTopo_E_EME1", &cl_hadTopo_E_EME1, &b_cl_hadTopo_E_EME1);
   fChain->SetBranchAddress("cl_hadTopo_E_EME2", &cl_hadTopo_E_EME2, &b_cl_hadTopo_E_EME2);
   fChain->SetBranchAddress("cl_hadTopo_E_EME3", &cl_hadTopo_E_EME3, &b_cl_hadTopo_E_EME3);
   fChain->SetBranchAddress("cl_hadTopo_E_HEC0", &cl_hadTopo_E_HEC0, &b_cl_hadTopo_E_HEC0);
   fChain->SetBranchAddress("cl_hadTopo_E_HEC1", &cl_hadTopo_E_HEC1, &b_cl_hadTopo_E_HEC1);
   fChain->SetBranchAddress("cl_hadTopo_E_HEC2", &cl_hadTopo_E_HEC2, &b_cl_hadTopo_E_HEC2);
   fChain->SetBranchAddress("cl_hadTopo_E_HEC3", &cl_hadTopo_E_HEC3, &b_cl_hadTopo_E_HEC3);
   fChain->SetBranchAddress("cl_hadTopo_E_TileBar0", &cl_hadTopo_E_TileBar0, &b_cl_hadTopo_E_TileBar0);
   fChain->SetBranchAddress("cl_hadTopo_E_TileBar1", &cl_hadTopo_E_TileBar1, &b_cl_hadTopo_E_TileBar1);
   fChain->SetBranchAddress("cl_hadTopo_E_TileBar2", &cl_hadTopo_E_TileBar2, &b_cl_hadTopo_E_TileBar2);
   fChain->SetBranchAddress("cl_hadTopo_E_TileGap1", &cl_hadTopo_E_TileGap1, &b_cl_hadTopo_E_TileGap1);
   fChain->SetBranchAddress("cl_hadTopo_E_TileGap2", &cl_hadTopo_E_TileGap2, &b_cl_hadTopo_E_TileGap2);
   fChain->SetBranchAddress("cl_hadTopo_E_TileGap3", &cl_hadTopo_E_TileGap3, &b_cl_hadTopo_E_TileGap3);
   fChain->SetBranchAddress("cl_hadTopo_E_TileExt0", &cl_hadTopo_E_TileExt0, &b_cl_hadTopo_E_TileExt0);
   fChain->SetBranchAddress("cl_hadTopo_E_TileExt1", &cl_hadTopo_E_TileExt1, &b_cl_hadTopo_E_TileExt1);
   fChain->SetBranchAddress("cl_hadTopo_E_TileExt2", &cl_hadTopo_E_TileExt2, &b_cl_hadTopo_E_TileExt2);
   fChain->SetBranchAddress("cl_hadTopo_E_FCAL0", &cl_hadTopo_E_FCAL0, &b_cl_hadTopo_E_FCAL0);
   fChain->SetBranchAddress("cl_hadTopo_E_FCAL1", &cl_hadTopo_E_FCAL1, &b_cl_hadTopo_E_FCAL1);
   fChain->SetBranchAddress("cl_hadTopo_E_FCAL2", &cl_hadTopo_E_FCAL2, &b_cl_hadTopo_E_FCAL2);
   fChain->SetBranchAddress("HIEtaGap_beam1", &HIEtaGap_beam1, &b_HIEtaGap_beam1);
   fChain->SetBranchAddress("HIEtaGap_beam2", &HIEtaGap_beam2, &b_HIEtaGap_beam2);
   fChain->SetBranchAddress("HIEtaGap_lowerEta", &HIEtaGap_lowerEta, &b_HIEtaGap_lowerEta);
   fChain->SetBranchAddress("HIEtaGap_upperEta", &HIEtaGap_upperEta, &b_HIEtaGap_upperEta);
   fChain->SetBranchAddress("HIEtaGap_lowerEdgeType", &HIEtaGap_lowerEdgeType, &b_HIEtaGap_lowerEdgeType);
   fChain->SetBranchAddress("HIEtaGap_upperEdgeType", &HIEtaGap_upperEdgeType, &b_HIEtaGap_upperEdgeType);
   fChain->SetBranchAddress("HIEtaGap_lowerEtaNegEdge", &HIEtaGap_lowerEtaNegEdge, &b_HIEtaGap_lowerEtaNegEdge);
   fChain->SetBranchAddress("HIEtaGap_upperEtaNegEdge", &HIEtaGap_upperEtaNegEdge, &b_HIEtaGap_upperEtaNegEdge);
   fChain->SetBranchAddress("HIEtaGap_lowerEtaPosEdge", &HIEtaGap_lowerEtaPosEdge, &b_HIEtaGap_lowerEtaPosEdge);
   fChain->SetBranchAddress("HIEtaGap_upperEtaPosEdge", &HIEtaGap_upperEtaPosEdge, &b_HIEtaGap_upperEtaPosEdge);
   fChain->SetBranchAddress("HIEtaGap_maxGapSize", &HIEtaGap_maxGapSize, &b_HIEtaGap_maxGapSize);
   fChain->SetBranchAddress("HITrigVtxCounts_NtrksPrim", &HITrigVtxCounts_NtrksPrim, &b_HITrigVtxCounts_NtrksPrim);
   fChain->SetBranchAddress("HITrigVtxCounts_SumPtsqPrim", &HITrigVtxCounts_SumPtsqPrim, &b_HITrigVtxCounts_SumPtsqPrim);
   fChain->SetBranchAddress("trig_DB_SMK", &trig_DB_SMK, &b_trig_DB_SMK);
   fChain->SetBranchAddress("trig_DB_L1PSK", &trig_DB_L1PSK, &b_trig_DB_L1PSK);
   fChain->SetBranchAddress("trig_DB_HLTPSK", &trig_DB_HLTPSK, &b_trig_DB_HLTPSK);
   fChain->SetBranchAddress("trig_L1_TAV", &trig_L1_TAV, &b_trig_L1_TAV);
   fChain->SetBranchAddress("trig_L2_passedPhysics", &trig_L2_passedPhysics, &b_trig_L2_passedPhysics);
   fChain->SetBranchAddress("trig_EF_passedPhysics", &trig_EF_passedPhysics, &b_trig_EF_passedPhysics);
   fChain->SetBranchAddress("trig_L1_TBP", &trig_L1_TBP, &b_trig_L1_TBP);
   fChain->SetBranchAddress("trig_L1_TAP", &trig_L1_TAP, &b_trig_L1_TAP);
   fChain->SetBranchAddress("trig_L2_passedRaw", &trig_L2_passedRaw, &b_trig_L2_passedRaw);
   fChain->SetBranchAddress("trig_EF_passedRaw", &trig_EF_passedRaw, &b_trig_EF_passedRaw);
   fChain->SetBranchAddress("trig_L2_truncated", &trig_L2_truncated, &b_trig_L2_truncated);
   fChain->SetBranchAddress("trig_EF_truncated", &trig_EF_truncated, &b_trig_EF_truncated);
   fChain->SetBranchAddress("trig_L2_resurrected", &trig_L2_resurrected, &b_trig_L2_resurrected);
   fChain->SetBranchAddress("trig_EF_resurrected", &trig_EF_resurrected, &b_trig_EF_resurrected);
   fChain->SetBranchAddress("trig_L2_passedThrough", &trig_L2_passedThrough, &b_trig_L2_passedThrough);
   fChain->SetBranchAddress("trig_EF_passedThrough", &trig_EF_passedThrough, &b_trig_EF_passedThrough);
   fChain->SetBranchAddress("trig_L2_wasPrescaled", &trig_L2_wasPrescaled, &b_trig_L2_wasPrescaled);
   fChain->SetBranchAddress("trig_L2_wasResurrected", &trig_L2_wasResurrected, &b_trig_L2_wasResurrected);
   fChain->SetBranchAddress("trig_EF_wasPrescaled", &trig_EF_wasPrescaled, &b_trig_EF_wasPrescaled);
   fChain->SetBranchAddress("trig_EF_wasResurrected", &trig_EF_wasResurrected, &b_trig_EF_wasResurrected);
   fChain->SetBranchAddress("trig_L1_jet_n", &trig_L1_jet_n, &b_trig_L1_jet_n);
   fChain->SetBranchAddress("trig_L1_jet_eta", &trig_L1_jet_eta, &b_trig_L1_jet_eta);
   fChain->SetBranchAddress("trig_L1_jet_phi", &trig_L1_jet_phi, &b_trig_L1_jet_phi);
   fChain->SetBranchAddress("trig_L1_jet_thrNames", &trig_L1_jet_thrNames, &b_trig_L1_jet_thrNames);
   fChain->SetBranchAddress("trig_L1_jet_thrValues", &trig_L1_jet_thrValues, &b_trig_L1_jet_thrValues);
   fChain->SetBranchAddress("trig_L1_jet_thrPattern", &trig_L1_jet_thrPattern, &b_trig_L1_jet_thrPattern);
   fChain->SetBranchAddress("trig_L1_jet_RoIWord", &trig_L1_jet_RoIWord, &b_trig_L1_jet_RoIWord);
   fChain->SetBranchAddress("trig_L1_jet_et4x4", &trig_L1_jet_et4x4, &b_trig_L1_jet_et4x4);
   fChain->SetBranchAddress("trig_L1_jet_et6x6", &trig_L1_jet_et6x6, &b_trig_L1_jet_et6x6);
   fChain->SetBranchAddress("trig_L1_jet_et8x8", &trig_L1_jet_et8x8, &b_trig_L1_jet_et8x8);
   fChain->SetBranchAddress("trig_L1_emtau_n", &trig_L1_emtau_n, &b_trig_L1_emtau_n);
   fChain->SetBranchAddress("trig_L1_emtau_eta", &trig_L1_emtau_eta, &b_trig_L1_emtau_eta);
   fChain->SetBranchAddress("trig_L1_emtau_phi", &trig_L1_emtau_phi, &b_trig_L1_emtau_phi);
   fChain->SetBranchAddress("trig_L1_emtau_thrNames", &trig_L1_emtau_thrNames, &b_trig_L1_emtau_thrNames);
   fChain->SetBranchAddress("trig_L1_emtau_thrValues", &trig_L1_emtau_thrValues, &b_trig_L1_emtau_thrValues);
   fChain->SetBranchAddress("trig_L1_emtau_core", &trig_L1_emtau_core, &b_trig_L1_emtau_core);
   fChain->SetBranchAddress("trig_L1_emtau_EMClus", &trig_L1_emtau_EMClus, &b_trig_L1_emtau_EMClus);
   fChain->SetBranchAddress("trig_L1_emtau_tauClus", &trig_L1_emtau_tauClus, &b_trig_L1_emtau_tauClus);
   fChain->SetBranchAddress("trig_L1_emtau_EMIsol", &trig_L1_emtau_EMIsol, &b_trig_L1_emtau_EMIsol);
   fChain->SetBranchAddress("trig_L1_emtau_hadIsol", &trig_L1_emtau_hadIsol, &b_trig_L1_emtau_hadIsol);
   fChain->SetBranchAddress("trig_L1_emtau_hadCore", &trig_L1_emtau_hadCore, &b_trig_L1_emtau_hadCore);
   fChain->SetBranchAddress("trig_L1_emtau_thrPattern", &trig_L1_emtau_thrPattern, &b_trig_L1_emtau_thrPattern);
   fChain->SetBranchAddress("trig_L1_emtau_RoIWord", &trig_L1_emtau_RoIWord, &b_trig_L1_emtau_RoIWord);
   fChain->SetBranchAddress("trig_L1_mu_n", &trig_L1_mu_n, &b_trig_L1_mu_n);
   fChain->SetBranchAddress("trig_L1_mu_pt", &trig_L1_mu_pt, &b_trig_L1_mu_pt);
   fChain->SetBranchAddress("trig_L1_mu_eta", &trig_L1_mu_eta, &b_trig_L1_mu_eta);
   fChain->SetBranchAddress("trig_L1_mu_phi", &trig_L1_mu_phi, &b_trig_L1_mu_phi);
   fChain->SetBranchAddress("trig_L1_mu_thrName", &trig_L1_mu_thrName, &b_trig_L1_mu_thrName);
   fChain->SetBranchAddress("trig_L1_mu_thrNumber", &trig_L1_mu_thrNumber, &b_trig_L1_mu_thrNumber);
   fChain->SetBranchAddress("trig_L1_mu_RoINumber", &trig_L1_mu_RoINumber, &b_trig_L1_mu_RoINumber);
   fChain->SetBranchAddress("trig_L1_mu_sectorAddress", &trig_L1_mu_sectorAddress, &b_trig_L1_mu_sectorAddress);
   fChain->SetBranchAddress("trig_L1_mu_firstCandidate", &trig_L1_mu_firstCandidate, &b_trig_L1_mu_firstCandidate);
   fChain->SetBranchAddress("trig_L1_mu_moreCandInRoI", &trig_L1_mu_moreCandInRoI, &b_trig_L1_mu_moreCandInRoI);
   fChain->SetBranchAddress("trig_L1_mu_moreCandInSector", &trig_L1_mu_moreCandInSector, &b_trig_L1_mu_moreCandInSector);
   fChain->SetBranchAddress("trig_L1_mu_source", &trig_L1_mu_source, &b_trig_L1_mu_source);
   fChain->SetBranchAddress("trig_L1_mu_hemisphere", &trig_L1_mu_hemisphere, &b_trig_L1_mu_hemisphere);
   fChain->SetBranchAddress("trig_L1_mu_charge", &trig_L1_mu_charge, &b_trig_L1_mu_charge);
   fChain->SetBranchAddress("trig_L1_mu_vetoed", &trig_L1_mu_vetoed, &b_trig_L1_mu_vetoed);
   fChain->SetBranchAddress("trig_L1_mu_RoIWord", &trig_L1_mu_RoIWord, &b_trig_L1_mu_RoIWord);
   fChain->SetBranchAddress("trig_EF_jet_n", &trig_EF_jet_n, &b_trig_EF_jet_n);
   fChain->SetBranchAddress("trig_EF_jet_E", &trig_EF_jet_E, &b_trig_EF_jet_E);
   fChain->SetBranchAddress("trig_EF_jet_pt", &trig_EF_jet_pt, &b_trig_EF_jet_pt);
   fChain->SetBranchAddress("trig_EF_jet_m", &trig_EF_jet_m, &b_trig_EF_jet_m);
   fChain->SetBranchAddress("trig_EF_jet_eta", &trig_EF_jet_eta, &b_trig_EF_jet_eta);
   fChain->SetBranchAddress("trig_EF_jet_phi", &trig_EF_jet_phi, &b_trig_EF_jet_phi);
   fChain->SetBranchAddress("trig_EF_jet_a4tcem", &trig_EF_jet_a4tcem, &b_trig_EF_jet_a4tcem);
   fChain->SetBranchAddress("trig_EF_jet_a2tcem", &trig_EF_jet_a2tcem, &b_trig_EF_jet_a2tcem);
   fChain->SetBranchAddress("trig_EF_jet_a4tchad", &trig_EF_jet_a4tchad, &b_trig_EF_jet_a4tchad);
   fChain->SetBranchAddress("trig_EF_jet_a4hi", &trig_EF_jet_a4hi, &b_trig_EF_jet_a4hi);
   fChain->SetBranchAddress("trig_EF_jet_a2hi", &trig_EF_jet_a2hi, &b_trig_EF_jet_a2hi);
   fChain->SetBranchAddress("trig_EF_jet_RoIword", &trig_EF_jet_RoIword, &b_trig_EF_jet_RoIword);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j0_a4tcem_deta40", &trig_EF_jet_EF_2j0_a4tcem_deta40, &b_trig_EF_jet_EF_2j0_a4tcem_deta40);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j10_a4hi_EFFS_2L1J5", &trig_EF_jet_EF_2j10_a4hi_EFFS_2L1J5, &b_trig_EF_jet_EF_2j10_a4hi_EFFS_2L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j10_a4hi_EFFS_2L1J5_L1TE90", &trig_EF_jet_EF_2j10_a4hi_EFFS_2L1J5_L1TE90, &b_trig_EF_jet_EF_2j10_a4hi_EFFS_2L1J5_L1TE90);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j10_a4hi_EFFS_L1MBTS", &trig_EF_jet_EF_2j10_a4hi_EFFS_L1MBTS, &b_trig_EF_jet_EF_2j10_a4hi_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j10_a4hi_EFFS_L1TE100", &trig_EF_jet_EF_2j10_a4hi_EFFS_L1TE100, &b_trig_EF_jet_EF_2j10_a4hi_EFFS_L1TE100);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j10_a4hi_EFFS_L1TE90", &trig_EF_jet_EF_2j10_a4hi_EFFS_L1TE90, &b_trig_EF_jet_EF_2j10_a4hi_EFFS_L1TE90);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j10_a4hi_deta40_L1MBTS", &trig_EF_jet_EF_2j10_a4hi_deta40_L1MBTS, &b_trig_EF_jet_EF_2j10_a4hi_deta40_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j10_a4hi_eta50_deta40", &trig_EF_jet_EF_2j10_a4hi_eta50_deta40, &b_trig_EF_jet_EF_2j10_a4hi_eta50_deta40);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j10_a4hi_eta50_deta40_L1MBTS", &trig_EF_jet_EF_2j10_a4hi_eta50_deta40_L1MBTS, &b_trig_EF_jet_EF_2j10_a4hi_eta50_deta40_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j10_a4tcem_EFFS_2L1J5", &trig_EF_jet_EF_2j10_a4tcem_EFFS_2L1J5, &b_trig_EF_jet_EF_2j10_a4tcem_EFFS_2L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j10_a4tcem_deta40", &trig_EF_jet_EF_2j10_a4tcem_deta40, &b_trig_EF_jet_EF_2j10_a4tcem_deta40);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j10_a4tcem_eta50_deta40", &trig_EF_jet_EF_2j10_a4tcem_eta50_deta40, &b_trig_EF_jet_EF_2j10_a4tcem_eta50_deta40);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j10_a4tchad_EFFS_L1MBTS", &trig_EF_jet_EF_2j10_a4tchad_EFFS_L1MBTS, &b_trig_EF_jet_EF_2j10_a4tchad_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j10_a4tchad_deta40_L1MBTS", &trig_EF_jet_EF_2j10_a4tchad_deta40_L1MBTS, &b_trig_EF_jet_EF_2j10_a4tchad_deta40_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j10_a4tchad_eta50_deta40_L1MBTS", &trig_EF_jet_EF_2j10_a4tchad_eta50_deta40_L1MBTS, &b_trig_EF_jet_EF_2j10_a4tchad_eta50_deta40_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j15_a4hi_EFFS_2L1J5", &trig_EF_jet_EF_2j15_a4hi_EFFS_2L1J5, &b_trig_EF_jet_EF_2j15_a4hi_EFFS_2L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j15_a4hi_EFFS_L1MBTS", &trig_EF_jet_EF_2j15_a4hi_EFFS_L1MBTS, &b_trig_EF_jet_EF_2j15_a4hi_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j15_a4hi_deta40_L1MBTS", &trig_EF_jet_EF_2j15_a4hi_deta40_L1MBTS, &b_trig_EF_jet_EF_2j15_a4hi_deta40_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j15_a4hi_eta50_deta40", &trig_EF_jet_EF_2j15_a4hi_eta50_deta40, &b_trig_EF_jet_EF_2j15_a4hi_eta50_deta40);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j15_a4hi_eta50_deta40_L1MBTS", &trig_EF_jet_EF_2j15_a4hi_eta50_deta40_L1MBTS, &b_trig_EF_jet_EF_2j15_a4hi_eta50_deta40_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j15_a4tcem_EFFS_2L1J5", &trig_EF_jet_EF_2j15_a4tcem_EFFS_2L1J5, &b_trig_EF_jet_EF_2j15_a4tcem_EFFS_2L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j15_a4tcem_deta40", &trig_EF_jet_EF_2j15_a4tcem_deta40, &b_trig_EF_jet_EF_2j15_a4tcem_deta40);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j15_a4tcem_eta50_deta40", &trig_EF_jet_EF_2j15_a4tcem_eta50_deta40, &b_trig_EF_jet_EF_2j15_a4tcem_eta50_deta40);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j15_a4tchad_EFFS_L1MBTS", &trig_EF_jet_EF_2j15_a4tchad_EFFS_L1MBTS, &b_trig_EF_jet_EF_2j15_a4tchad_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j15_a4tchad_deta40_L1MBTS", &trig_EF_jet_EF_2j15_a4tchad_deta40_L1MBTS, &b_trig_EF_jet_EF_2j15_a4tchad_deta40_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j15_a4tchad_eta50_deta40_L1MBTS", &trig_EF_jet_EF_2j15_a4tchad_eta50_deta40_L1MBTS, &b_trig_EF_jet_EF_2j15_a4tchad_eta50_deta40_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j20_a4hi_EFFS_L1MBTS", &trig_EF_jet_EF_2j20_a4hi_EFFS_L1MBTS, &b_trig_EF_jet_EF_2j20_a4hi_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j20_a4tchad_EFFS_L1MBTS", &trig_EF_jet_EF_2j20_a4tchad_EFFS_L1MBTS, &b_trig_EF_jet_EF_2j20_a4tchad_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j7_a4hi_EFFS_2L1J5", &trig_EF_jet_EF_2j7_a4hi_EFFS_2L1J5, &b_trig_EF_jet_EF_2j7_a4hi_EFFS_2L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j7_a4hi_EFFS_L1MBTS", &trig_EF_jet_EF_2j7_a4hi_EFFS_L1MBTS, &b_trig_EF_jet_EF_2j7_a4hi_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j7_a4hi_deta40_L1MBTS", &trig_EF_jet_EF_2j7_a4hi_deta40_L1MBTS, &b_trig_EF_jet_EF_2j7_a4hi_deta40_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j7_a4hi_eta50_deta40", &trig_EF_jet_EF_2j7_a4hi_eta50_deta40, &b_trig_EF_jet_EF_2j7_a4hi_eta50_deta40);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j7_a4hi_eta50_deta40_L1MBTS", &trig_EF_jet_EF_2j7_a4hi_eta50_deta40_L1MBTS, &b_trig_EF_jet_EF_2j7_a4hi_eta50_deta40_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j7_a4tcem_EFFS_2L1J5", &trig_EF_jet_EF_2j7_a4tcem_EFFS_2L1J5, &b_trig_EF_jet_EF_2j7_a4tcem_EFFS_2L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j7_a4tcem_deta40", &trig_EF_jet_EF_2j7_a4tcem_deta40, &b_trig_EF_jet_EF_2j7_a4tcem_deta40);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j7_a4tcem_eta50_deta40", &trig_EF_jet_EF_2j7_a4tcem_eta50_deta40, &b_trig_EF_jet_EF_2j7_a4tcem_eta50_deta40);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j7_a4tchad_EFFS_L1MBTS", &trig_EF_jet_EF_2j7_a4tchad_EFFS_L1MBTS, &b_trig_EF_jet_EF_2j7_a4tchad_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j7_a4tchad_deta40_L1MBTS", &trig_EF_jet_EF_2j7_a4tchad_deta40_L1MBTS, &b_trig_EF_jet_EF_2j7_a4tchad_deta40_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_2j7_a4tchad_eta50_deta40_L1MBTS", &trig_EF_jet_EF_2j7_a4tchad_eta50_deta40_L1MBTS, &b_trig_EF_jet_EF_2j7_a4tchad_eta50_deta40_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_fj10_a4hi_EFFS_L1FJ0", &trig_EF_jet_EF_fj10_a4hi_EFFS_L1FJ0, &b_trig_EF_jet_EF_fj10_a4hi_EFFS_L1FJ0);
   fChain->SetBranchAddress("trig_EF_jet_EF_fj10_a4tchad_EFFS_L1FJ0", &trig_EF_jet_EF_fj10_a4tchad_EFFS_L1FJ0, &b_trig_EF_jet_EF_fj10_a4tchad_EFFS_L1FJ0);
   fChain->SetBranchAddress("trig_EF_jet_EF_fj15_a4hi_EFFS_L1FJ0", &trig_EF_jet_EF_fj15_a4hi_EFFS_L1FJ0, &b_trig_EF_jet_EF_fj15_a4hi_EFFS_L1FJ0);
   fChain->SetBranchAddress("trig_EF_jet_EF_fj15_a4tchad_EFFS_L1FJ0", &trig_EF_jet_EF_fj15_a4tchad_EFFS_L1FJ0, &b_trig_EF_jet_EF_fj15_a4tchad_EFFS_L1FJ0);
   fChain->SetBranchAddress("trig_EF_jet_EF_fj7_a4hi_EFFS_L1FJ0", &trig_EF_jet_EF_fj7_a4hi_EFFS_L1FJ0, &b_trig_EF_jet_EF_fj7_a4hi_EFFS_L1FJ0);
   fChain->SetBranchAddress("trig_EF_jet_EF_fj7_a4hi_EFFS_L1MBTS", &trig_EF_jet_EF_fj7_a4hi_EFFS_L1MBTS, &b_trig_EF_jet_EF_fj7_a4hi_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_fj7_a4tchad_EFFS_L1FJ0", &trig_EF_jet_EF_fj7_a4tchad_EFFS_L1FJ0, &b_trig_EF_jet_EF_fj7_a4tchad_EFFS_L1FJ0);
   fChain->SetBranchAddress("trig_EF_jet_EF_fj7_a4tchad_EFFS_L1MBTS", &trig_EF_jet_EF_fj7_a4tchad_EFFS_L1MBTS, &b_trig_EF_jet_EF_fj7_a4tchad_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_j10_a4hi_EFFS_L1EM3", &trig_EF_jet_EF_j10_a4hi_EFFS_L1EM3, &b_trig_EF_jet_EF_j10_a4hi_EFFS_L1EM3);
   fChain->SetBranchAddress("trig_EF_jet_EF_j10_a4hi_EFFS_L1J5", &trig_EF_jet_EF_j10_a4hi_EFFS_L1J5, &b_trig_EF_jet_EF_j10_a4hi_EFFS_L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_j10_a4hi_EFFS_L1J5_L1TE90", &trig_EF_jet_EF_j10_a4hi_EFFS_L1J5_L1TE90, &b_trig_EF_jet_EF_j10_a4hi_EFFS_L1J5_L1TE90);
   fChain->SetBranchAddress("trig_EF_jet_EF_j10_a4hi_EFFS_L1MBTS", &trig_EF_jet_EF_j10_a4hi_EFFS_L1MBTS, &b_trig_EF_jet_EF_j10_a4hi_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_j10_a4hi_EFFS_L1TAU3", &trig_EF_jet_EF_j10_a4hi_EFFS_L1TAU3, &b_trig_EF_jet_EF_j10_a4hi_EFFS_L1TAU3);
   fChain->SetBranchAddress("trig_EF_jet_EF_j10_a4hi_EFFS_L1TE100", &trig_EF_jet_EF_j10_a4hi_EFFS_L1TE100, &b_trig_EF_jet_EF_j10_a4hi_EFFS_L1TE100);
   fChain->SetBranchAddress("trig_EF_jet_EF_j10_a4hi_EFFS_L1TE90", &trig_EF_jet_EF_j10_a4hi_EFFS_L1TE90, &b_trig_EF_jet_EF_j10_a4hi_EFFS_L1TE90);
   fChain->SetBranchAddress("trig_EF_jet_EF_j10_a4tcem_EFFS_L1EM3", &trig_EF_jet_EF_j10_a4tcem_EFFS_L1EM3, &b_trig_EF_jet_EF_j10_a4tcem_EFFS_L1EM3);
   fChain->SetBranchAddress("trig_EF_jet_EF_j10_a4tcem_EFFS_L1J5", &trig_EF_jet_EF_j10_a4tcem_EFFS_L1J5, &b_trig_EF_jet_EF_j10_a4tcem_EFFS_L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_j10_a4tcem_EFFS_L1J5_win6", &trig_EF_jet_EF_j10_a4tcem_EFFS_L1J5_win6, &b_trig_EF_jet_EF_j10_a4tcem_EFFS_L1J5_win6);
   fChain->SetBranchAddress("trig_EF_jet_EF_j10_a4tcem_EFFS_L1TAU3", &trig_EF_jet_EF_j10_a4tcem_EFFS_L1TAU3, &b_trig_EF_jet_EF_j10_a4tcem_EFFS_L1TAU3);
   fChain->SetBranchAddress("trig_EF_jet_EF_j10_a4tchad_EFFS_L1J5", &trig_EF_jet_EF_j10_a4tchad_EFFS_L1J5, &b_trig_EF_jet_EF_j10_a4tchad_EFFS_L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_j10_a4tchad_EFFS_L1MBTS", &trig_EF_jet_EF_j10_a4tchad_EFFS_L1MBTS, &b_trig_EF_jet_EF_j10_a4tchad_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_j10_u0uchad_LArNoiseBurst", &trig_EF_jet_EF_j10_u0uchad_LArNoiseBurst, &b_trig_EF_jet_EF_j10_u0uchad_LArNoiseBurst);
   fChain->SetBranchAddress("trig_EF_jet_EF_j10_u0uchad_empty_LArNoiseBurst", &trig_EF_jet_EF_j10_u0uchad_empty_LArNoiseBurst, &b_trig_EF_jet_EF_j10_u0uchad_empty_LArNoiseBurst);
   fChain->SetBranchAddress("trig_EF_jet_EF_j10_u0uchad_firstempty_LArNoiseBurst", &trig_EF_jet_EF_j10_u0uchad_firstempty_LArNoiseBurst, &b_trig_EF_jet_EF_j10_u0uchad_firstempty_LArNoiseBurst);
   fChain->SetBranchAddress("trig_EF_jet_EF_j15_a2tcem_EFFS_L1J10", &trig_EF_jet_EF_j15_a2tcem_EFFS_L1J10, &b_trig_EF_jet_EF_j15_a2tcem_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j15_a2tcem_EFFS_L1J5", &trig_EF_jet_EF_j15_a2tcem_EFFS_L1J5, &b_trig_EF_jet_EF_j15_a2tcem_EFFS_L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_j15_a4hi_EFFS_L1J10", &trig_EF_jet_EF_j15_a4hi_EFFS_L1J10, &b_trig_EF_jet_EF_j15_a4hi_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j15_a4hi_EFFS_L1J5", &trig_EF_jet_EF_j15_a4hi_EFFS_L1J5, &b_trig_EF_jet_EF_j15_a4hi_EFFS_L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_j15_a4hi_EFFS_L1MBTS", &trig_EF_jet_EF_j15_a4hi_EFFS_L1MBTS, &b_trig_EF_jet_EF_j15_a4hi_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_j15_a4tcem_EFFS_L1J10", &trig_EF_jet_EF_j15_a4tcem_EFFS_L1J10, &b_trig_EF_jet_EF_j15_a4tcem_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j15_a4tcem_EFFS_L1J5", &trig_EF_jet_EF_j15_a4tcem_EFFS_L1J5, &b_trig_EF_jet_EF_j15_a4tcem_EFFS_L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_j15_a4tchad_EFFS_L1MBTS", &trig_EF_jet_EF_j15_a4tchad_EFFS_L1MBTS, &b_trig_EF_jet_EF_j15_a4tchad_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_j20_a4hi_EFFS_L1J10", &trig_EF_jet_EF_j20_a4hi_EFFS_L1J10, &b_trig_EF_jet_EF_j20_a4hi_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j20_a4hi_EFFS_L1MBTS", &trig_EF_jet_EF_j20_a4hi_EFFS_L1MBTS, &b_trig_EF_jet_EF_j20_a4hi_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_j20_a4tcem_EFFS_L1J10", &trig_EF_jet_EF_j20_a4tcem_EFFS_L1J10, &b_trig_EF_jet_EF_j20_a4tcem_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j20_a4tcem_EFFS_L1J5", &trig_EF_jet_EF_j20_a4tcem_EFFS_L1J5, &b_trig_EF_jet_EF_j20_a4tcem_EFFS_L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_j20_a4tchad_EFFS_L1J5", &trig_EF_jet_EF_j20_a4tchad_EFFS_L1J5, &b_trig_EF_jet_EF_j20_a4tchad_EFFS_L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_j20_a4tchad_EFFS_L1MBTS", &trig_EF_jet_EF_j20_a4tchad_EFFS_L1MBTS, &b_trig_EF_jet_EF_j20_a4tchad_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_j25_a4hi_EFFS_L1J10", &trig_EF_jet_EF_j25_a4hi_EFFS_L1J10, &b_trig_EF_jet_EF_j25_a4hi_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j25_a4tcem_EFFS_L1J10", &trig_EF_jet_EF_j25_a4tcem_EFFS_L1J10, &b_trig_EF_jet_EF_j25_a4tcem_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j30_a4hi_EFFS_L1J10", &trig_EF_jet_EF_j30_a4hi_EFFS_L1J10, &b_trig_EF_jet_EF_j30_a4hi_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j30_a4hi_EFFS_L1MBTS", &trig_EF_jet_EF_j30_a4hi_EFFS_L1MBTS, &b_trig_EF_jet_EF_j30_a4hi_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_j30_a4tcem_EFFS_L1J10", &trig_EF_jet_EF_j30_a4tcem_EFFS_L1J10, &b_trig_EF_jet_EF_j30_a4tcem_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j30_a4tcem_EFFS_L1J5", &trig_EF_jet_EF_j30_a4tcem_EFFS_L1J5, &b_trig_EF_jet_EF_j30_a4tcem_EFFS_L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_j30_a4tchad_EFFS_L1J5", &trig_EF_jet_EF_j30_a4tchad_EFFS_L1J5, &b_trig_EF_jet_EF_j30_a4tchad_EFFS_L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_j30_a4tchad_EFFS_L1MBTS", &trig_EF_jet_EF_j30_a4tchad_EFFS_L1MBTS, &b_trig_EF_jet_EF_j30_a4tchad_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_j30_u0uchad_empty_LArNoiseBurst", &trig_EF_jet_EF_j30_u0uchad_empty_LArNoiseBurst, &b_trig_EF_jet_EF_j30_u0uchad_empty_LArNoiseBurst);
   fChain->SetBranchAddress("trig_EF_jet_EF_j35_a4hi_EFFS_L1J10", &trig_EF_jet_EF_j35_a4hi_EFFS_L1J10, &b_trig_EF_jet_EF_j35_a4hi_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j35_a4tcem_EFFS_L1J10", &trig_EF_jet_EF_j35_a4tcem_EFFS_L1J10, &b_trig_EF_jet_EF_j35_a4tcem_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j40_a4hi_EFFS_L1J10", &trig_EF_jet_EF_j40_a4hi_EFFS_L1J10, &b_trig_EF_jet_EF_j40_a4hi_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j40_a4hi_EFFS_L1MBTS", &trig_EF_jet_EF_j40_a4hi_EFFS_L1MBTS, &b_trig_EF_jet_EF_j40_a4hi_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_j40_a4tcem_EFFS_L1J10", &trig_EF_jet_EF_j40_a4tcem_EFFS_L1J10, &b_trig_EF_jet_EF_j40_a4tcem_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j40_a4tcem_EFFS_L1J5", &trig_EF_jet_EF_j40_a4tcem_EFFS_L1J5, &b_trig_EF_jet_EF_j40_a4tcem_EFFS_L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_j40_a4tchad_EFFS_L1J5", &trig_EF_jet_EF_j40_a4tchad_EFFS_L1J5, &b_trig_EF_jet_EF_j40_a4tchad_EFFS_L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_j40_a4tchad_EFFS_L1MBTS", &trig_EF_jet_EF_j40_a4tchad_EFFS_L1MBTS, &b_trig_EF_jet_EF_j40_a4tchad_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_j45_a4hi_EFFS_L1J10", &trig_EF_jet_EF_j45_a4hi_EFFS_L1J10, &b_trig_EF_jet_EF_j45_a4hi_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j45_a4tcem_EFFS_L1J10", &trig_EF_jet_EF_j45_a4tcem_EFFS_L1J10, &b_trig_EF_jet_EF_j45_a4tcem_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j50_a4hi_EFFS_L1J10", &trig_EF_jet_EF_j50_a4hi_EFFS_L1J10, &b_trig_EF_jet_EF_j50_a4hi_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j50_a4hi_EFFS_L1MBTS", &trig_EF_jet_EF_j50_a4hi_EFFS_L1MBTS, &b_trig_EF_jet_EF_j50_a4hi_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_j50_a4tcem_EFFS_L1J10", &trig_EF_jet_EF_j50_a4tcem_EFFS_L1J10, &b_trig_EF_jet_EF_j50_a4tcem_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j50_a4tcem_EFFS_L1J15", &trig_EF_jet_EF_j50_a4tcem_EFFS_L1J15, &b_trig_EF_jet_EF_j50_a4tcem_EFFS_L1J15);
   fChain->SetBranchAddress("trig_EF_jet_EF_j50_a4tchad_EFFS_L1J10", &trig_EF_jet_EF_j50_a4tchad_EFFS_L1J10, &b_trig_EF_jet_EF_j50_a4tchad_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j50_a4tchad_EFFS_L1J15", &trig_EF_jet_EF_j50_a4tchad_EFFS_L1J15, &b_trig_EF_jet_EF_j50_a4tchad_EFFS_L1J15);
   fChain->SetBranchAddress("trig_EF_jet_EF_j50_a4tchad_EFFS_L1MBTS", &trig_EF_jet_EF_j50_a4tchad_EFFS_L1MBTS, &b_trig_EF_jet_EF_j50_a4tchad_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_j60_a4tcem_EFFS_L1J10", &trig_EF_jet_EF_j60_a4tcem_EFFS_L1J10, &b_trig_EF_jet_EF_j60_a4tcem_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j60_a4tcem_EFFS_L1J15", &trig_EF_jet_EF_j60_a4tcem_EFFS_L1J15, &b_trig_EF_jet_EF_j60_a4tcem_EFFS_L1J15);
   fChain->SetBranchAddress("trig_EF_jet_EF_j60_a4tchad_EFFS_L1J10", &trig_EF_jet_EF_j60_a4tchad_EFFS_L1J10, &b_trig_EF_jet_EF_j60_a4tchad_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j60_a4tchad_EFFS_L1J15", &trig_EF_jet_EF_j60_a4tchad_EFFS_L1J15, &b_trig_EF_jet_EF_j60_a4tchad_EFFS_L1J15);
   fChain->SetBranchAddress("trig_EF_jet_EF_j75_a4hi_EFFS_L1J10", &trig_EF_jet_EF_j75_a4hi_EFFS_L1J10, &b_trig_EF_jet_EF_j75_a4hi_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j75_a4tcem_EFFS_L1J10", &trig_EF_jet_EF_j75_a4tcem_EFFS_L1J10, &b_trig_EF_jet_EF_j75_a4tcem_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j75_a4tcem_EFFS_L1J15", &trig_EF_jet_EF_j75_a4tcem_EFFS_L1J15, &b_trig_EF_jet_EF_j75_a4tcem_EFFS_L1J15);
   fChain->SetBranchAddress("trig_EF_jet_EF_j75_a4tchad_EFFS_L1J10", &trig_EF_jet_EF_j75_a4tchad_EFFS_L1J10, &b_trig_EF_jet_EF_j75_a4tchad_EFFS_L1J10);
   fChain->SetBranchAddress("trig_EF_jet_EF_j75_a4tchad_EFFS_L1J15", &trig_EF_jet_EF_j75_a4tchad_EFFS_L1J15, &b_trig_EF_jet_EF_j75_a4tchad_EFFS_L1J15);
   fChain->SetBranchAddress("trig_EF_jet_EF_j7_a4hi_EFFS_L1EM3", &trig_EF_jet_EF_j7_a4hi_EFFS_L1EM3, &b_trig_EF_jet_EF_j7_a4hi_EFFS_L1EM3);
   fChain->SetBranchAddress("trig_EF_jet_EF_j7_a4hi_EFFS_L1J5", &trig_EF_jet_EF_j7_a4hi_EFFS_L1J5, &b_trig_EF_jet_EF_j7_a4hi_EFFS_L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_j7_a4hi_EFFS_L1MBTS", &trig_EF_jet_EF_j7_a4hi_EFFS_L1MBTS, &b_trig_EF_jet_EF_j7_a4hi_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_j7_a4hi_EFFS_L1TAU3", &trig_EF_jet_EF_j7_a4hi_EFFS_L1TAU3, &b_trig_EF_jet_EF_j7_a4hi_EFFS_L1TAU3);
   fChain->SetBranchAddress("trig_EF_jet_EF_j7_a4tcem_EFFS_L1EM3", &trig_EF_jet_EF_j7_a4tcem_EFFS_L1EM3, &b_trig_EF_jet_EF_j7_a4tcem_EFFS_L1EM3);
   fChain->SetBranchAddress("trig_EF_jet_EF_j7_a4tcem_EFFS_L1J5", &trig_EF_jet_EF_j7_a4tcem_EFFS_L1J5, &b_trig_EF_jet_EF_j7_a4tcem_EFFS_L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_j7_a4tcem_EFFS_L1J5_win6", &trig_EF_jet_EF_j7_a4tcem_EFFS_L1J5_win6, &b_trig_EF_jet_EF_j7_a4tcem_EFFS_L1J5_win6);
   fChain->SetBranchAddress("trig_EF_jet_EF_j7_a4tcem_EFFS_L1TAU3", &trig_EF_jet_EF_j7_a4tcem_EFFS_L1TAU3, &b_trig_EF_jet_EF_j7_a4tcem_EFFS_L1TAU3);
   fChain->SetBranchAddress("trig_EF_jet_EF_j7_a4tchad_EFFS_L1J5", &trig_EF_jet_EF_j7_a4tchad_EFFS_L1J5, &b_trig_EF_jet_EF_j7_a4tchad_EFFS_L1J5);
   fChain->SetBranchAddress("trig_EF_jet_EF_j7_a4tchad_EFFS_L1MBTS", &trig_EF_jet_EF_j7_a4tchad_EFFS_L1MBTS, &b_trig_EF_jet_EF_j7_a4tchad_EFFS_L1MBTS);
   fChain->SetBranchAddress("trig_EF_jet_EF_j80_a4tchad_EFFS_L1J15", &trig_EF_jet_EF_j80_a4tchad_EFFS_L1J15, &b_trig_EF_jet_EF_j80_a4tchad_EFFS_L1J15);
   fChain->SetBranchAddress("trig_EF_jet_EF_j90_a4tchad_EFFS_L1J15", &trig_EF_jet_EF_j90_a4tchad_EFFS_L1J15, &b_trig_EF_jet_EF_j90_a4tchad_EFFS_L1J15);
   fChain->SetBranchAddress("trig_L1_esum_thrNames", &trig_L1_esum_thrNames, &b_trig_L1_esum_thrNames);
   fChain->SetBranchAddress("trig_L1_esum_ExMiss", &trig_L1_esum_ExMiss, &b_trig_L1_esum_ExMiss);
   fChain->SetBranchAddress("trig_L1_esum_EyMiss", &trig_L1_esum_EyMiss, &b_trig_L1_esum_EyMiss);
   fChain->SetBranchAddress("trig_L1_esum_energyT", &trig_L1_esum_energyT, &b_trig_L1_esum_energyT);
   fChain->SetBranchAddress("trig_L1_esum_overflowX", &trig_L1_esum_overflowX, &b_trig_L1_esum_overflowX);
   fChain->SetBranchAddress("trig_L1_esum_overflowY", &trig_L1_esum_overflowY, &b_trig_L1_esum_overflowY);
   fChain->SetBranchAddress("trig_L1_esum_overflowT", &trig_L1_esum_overflowT, &b_trig_L1_esum_overflowT);
   fChain->SetBranchAddress("trig_L1_esum_RoIWord0", &trig_L1_esum_RoIWord0, &b_trig_L1_esum_RoIWord0);
   fChain->SetBranchAddress("trig_L1_esum_RoIWord1", &trig_L1_esum_RoIWord1, &b_trig_L1_esum_RoIWord1);
   fChain->SetBranchAddress("trig_L1_esum_RoIWord2", &trig_L1_esum_RoIWord2, &b_trig_L1_esum_RoIWord2);
   fChain->SetBranchAddress("trig_EF_met_MEx", &trig_EF_met_MEx, &b_trig_EF_met_MEx);
   fChain->SetBranchAddress("trig_EF_met_MEy", &trig_EF_met_MEy, &b_trig_EF_met_MEy);
   fChain->SetBranchAddress("trig_EF_met_MEz", &trig_EF_met_MEz, &b_trig_EF_met_MEz);
   fChain->SetBranchAddress("trig_EF_met_sumEt", &trig_EF_met_sumEt, &b_trig_EF_met_sumEt);
   fChain->SetBranchAddress("trig_EF_met_sumE", &trig_EF_met_sumE, &b_trig_EF_met_sumE);
   fChain->SetBranchAddress("trig_EF_met_flag", &trig_EF_met_flag, &b_trig_EF_met_flag);
   fChain->SetBranchAddress("trig_EF_met_nameOfComponent", &trig_EF_met_nameOfComponent, &b_trig_EF_met_nameOfComponent);
   fChain->SetBranchAddress("trig_EF_met_MExComponent", &trig_EF_met_MExComponent, &b_trig_EF_met_MExComponent);
   fChain->SetBranchAddress("trig_EF_met_MEyComponent", &trig_EF_met_MEyComponent, &b_trig_EF_met_MEyComponent);
   fChain->SetBranchAddress("trig_EF_met_MEzComponent", &trig_EF_met_MEzComponent, &b_trig_EF_met_MEzComponent);
   fChain->SetBranchAddress("trig_EF_met_sumEtComponent", &trig_EF_met_sumEtComponent, &b_trig_EF_met_sumEtComponent);
   fChain->SetBranchAddress("trig_EF_met_sumEComponent", &trig_EF_met_sumEComponent, &b_trig_EF_met_sumEComponent);
   fChain->SetBranchAddress("trig_EF_met_componentCalib0", &trig_EF_met_componentCalib0, &b_trig_EF_met_componentCalib0);
   fChain->SetBranchAddress("trig_EF_met_componentCalib1", &trig_EF_met_componentCalib1, &b_trig_EF_met_componentCalib1);
   fChain->SetBranchAddress("trig_EF_met_sumOfSigns", &trig_EF_met_sumOfSigns, &b_trig_EF_met_sumOfSigns);
   fChain->SetBranchAddress("trig_EF_met_usedChannels", &trig_EF_met_usedChannels, &b_trig_EF_met_usedChannels);
   fChain->SetBranchAddress("trig_EF_met_status", &trig_EF_met_status, &b_trig_EF_met_status);
   fChain->SetBranchAddress("trig_EF_ph_n", &trig_EF_ph_n, &b_trig_EF_ph_n);
   fChain->SetBranchAddress("trig_EF_ph_E", &trig_EF_ph_E, &b_trig_EF_ph_E);
   fChain->SetBranchAddress("trig_EF_ph_Et", &trig_EF_ph_Et, &b_trig_EF_ph_Et);
   fChain->SetBranchAddress("trig_EF_ph_pt", &trig_EF_ph_pt, &b_trig_EF_ph_pt);
   fChain->SetBranchAddress("trig_EF_ph_m", &trig_EF_ph_m, &b_trig_EF_ph_m);
   fChain->SetBranchAddress("trig_EF_ph_eta", &trig_EF_ph_eta, &b_trig_EF_ph_eta);
   fChain->SetBranchAddress("trig_EF_ph_phi", &trig_EF_ph_phi, &b_trig_EF_ph_phi);
   fChain->SetBranchAddress("trig_EF_ph_px", &trig_EF_ph_px, &b_trig_EF_ph_px);
   fChain->SetBranchAddress("trig_EF_ph_py", &trig_EF_ph_py, &b_trig_EF_ph_py);
   fChain->SetBranchAddress("trig_EF_ph_pz", &trig_EF_ph_pz, &b_trig_EF_ph_pz);
   fChain->SetBranchAddress("trig_EF_ph_author", &trig_EF_ph_author, &b_trig_EF_ph_author);
   fChain->SetBranchAddress("trig_EF_ph_isRecovered", &trig_EF_ph_isRecovered, &b_trig_EF_ph_isRecovered);
   fChain->SetBranchAddress("trig_EF_ph_isEM", &trig_EF_ph_isEM, &b_trig_EF_ph_isEM);
   fChain->SetBranchAddress("trig_EF_ph_isEMLoose", &trig_EF_ph_isEMLoose, &b_trig_EF_ph_isEMLoose);
   fChain->SetBranchAddress("trig_EF_ph_isEMMedium", &trig_EF_ph_isEMMedium, &b_trig_EF_ph_isEMMedium);
   fChain->SetBranchAddress("trig_EF_ph_isEMTight", &trig_EF_ph_isEMTight, &b_trig_EF_ph_isEMTight);
   fChain->SetBranchAddress("trig_EF_ph_convFlag", &trig_EF_ph_convFlag, &b_trig_EF_ph_convFlag);
   fChain->SetBranchAddress("trig_EF_ph_isConv", &trig_EF_ph_isConv, &b_trig_EF_ph_isConv);
   fChain->SetBranchAddress("trig_EF_ph_nConv", &trig_EF_ph_nConv, &b_trig_EF_ph_nConv);
   fChain->SetBranchAddress("trig_EF_ph_nSingleTrackConv", &trig_EF_ph_nSingleTrackConv, &b_trig_EF_ph_nSingleTrackConv);
   fChain->SetBranchAddress("trig_EF_ph_nDoubleTrackConv", &trig_EF_ph_nDoubleTrackConv, &b_trig_EF_ph_nDoubleTrackConv);
   fChain->SetBranchAddress("trig_EF_ph_loose", &trig_EF_ph_loose, &b_trig_EF_ph_loose);
   fChain->SetBranchAddress("trig_EF_ph_looseIso", &trig_EF_ph_looseIso, &b_trig_EF_ph_looseIso);
   fChain->SetBranchAddress("trig_EF_ph_tight", &trig_EF_ph_tight, &b_trig_EF_ph_tight);
   fChain->SetBranchAddress("trig_EF_ph_tightIso", &trig_EF_ph_tightIso, &b_trig_EF_ph_tightIso);
   fChain->SetBranchAddress("trig_EF_ph_looseAR", &trig_EF_ph_looseAR, &b_trig_EF_ph_looseAR);
   fChain->SetBranchAddress("trig_EF_ph_looseARIso", &trig_EF_ph_looseARIso, &b_trig_EF_ph_looseARIso);
   fChain->SetBranchAddress("trig_EF_ph_tightAR", &trig_EF_ph_tightAR, &b_trig_EF_ph_tightAR);
   fChain->SetBranchAddress("trig_EF_ph_tightARIso", &trig_EF_ph_tightARIso, &b_trig_EF_ph_tightARIso);
   fChain->SetBranchAddress("trig_EF_ph_Ethad", &trig_EF_ph_Ethad, &b_trig_EF_ph_Ethad);
   fChain->SetBranchAddress("trig_EF_ph_Ethad1", &trig_EF_ph_Ethad1, &b_trig_EF_ph_Ethad1);
   fChain->SetBranchAddress("trig_EF_ph_E033", &trig_EF_ph_E033, &b_trig_EF_ph_E033);
   fChain->SetBranchAddress("trig_EF_ph_f1", &trig_EF_ph_f1, &b_trig_EF_ph_f1);
   fChain->SetBranchAddress("trig_EF_ph_f1core", &trig_EF_ph_f1core, &b_trig_EF_ph_f1core);
   fChain->SetBranchAddress("trig_EF_ph_Emins1", &trig_EF_ph_Emins1, &b_trig_EF_ph_Emins1);
   fChain->SetBranchAddress("trig_EF_ph_fside", &trig_EF_ph_fside, &b_trig_EF_ph_fside);
   fChain->SetBranchAddress("trig_EF_ph_Emax2", &trig_EF_ph_Emax2, &b_trig_EF_ph_Emax2);
   fChain->SetBranchAddress("trig_EF_ph_ws3", &trig_EF_ph_ws3, &b_trig_EF_ph_ws3);
   fChain->SetBranchAddress("trig_EF_ph_wstot", &trig_EF_ph_wstot, &b_trig_EF_ph_wstot);
   fChain->SetBranchAddress("trig_EF_ph_E132", &trig_EF_ph_E132, &b_trig_EF_ph_E132);
   fChain->SetBranchAddress("trig_EF_ph_E1152", &trig_EF_ph_E1152, &b_trig_EF_ph_E1152);
   fChain->SetBranchAddress("trig_EF_ph_emaxs1", &trig_EF_ph_emaxs1, &b_trig_EF_ph_emaxs1);
   fChain->SetBranchAddress("trig_EF_ph_deltaEs", &trig_EF_ph_deltaEs, &b_trig_EF_ph_deltaEs);
   fChain->SetBranchAddress("trig_EF_ph_E233", &trig_EF_ph_E233, &b_trig_EF_ph_E233);
   fChain->SetBranchAddress("trig_EF_ph_E237", &trig_EF_ph_E237, &b_trig_EF_ph_E237);
   fChain->SetBranchAddress("trig_EF_ph_E277", &trig_EF_ph_E277, &b_trig_EF_ph_E277);
   fChain->SetBranchAddress("trig_EF_ph_weta2", &trig_EF_ph_weta2, &b_trig_EF_ph_weta2);
   fChain->SetBranchAddress("trig_EF_ph_f3", &trig_EF_ph_f3, &b_trig_EF_ph_f3);
   fChain->SetBranchAddress("trig_EF_ph_f3core", &trig_EF_ph_f3core, &b_trig_EF_ph_f3core);
   fChain->SetBranchAddress("trig_EF_ph_rphiallcalo", &trig_EF_ph_rphiallcalo, &b_trig_EF_ph_rphiallcalo);
   fChain->SetBranchAddress("trig_EF_ph_Etcone45", &trig_EF_ph_Etcone45, &b_trig_EF_ph_Etcone45);
   fChain->SetBranchAddress("trig_EF_ph_Etcone15", &trig_EF_ph_Etcone15, &b_trig_EF_ph_Etcone15);
   fChain->SetBranchAddress("trig_EF_ph_Etcone20", &trig_EF_ph_Etcone20, &b_trig_EF_ph_Etcone20);
   fChain->SetBranchAddress("trig_EF_ph_Etcone25", &trig_EF_ph_Etcone25, &b_trig_EF_ph_Etcone25);
   fChain->SetBranchAddress("trig_EF_ph_Etcone30", &trig_EF_ph_Etcone30, &b_trig_EF_ph_Etcone30);
   fChain->SetBranchAddress("trig_EF_ph_Etcone35", &trig_EF_ph_Etcone35, &b_trig_EF_ph_Etcone35);
   fChain->SetBranchAddress("trig_EF_ph_Etcone40", &trig_EF_ph_Etcone40, &b_trig_EF_ph_Etcone40);
   fChain->SetBranchAddress("trig_EF_ph_ptcone20", &trig_EF_ph_ptcone20, &b_trig_EF_ph_ptcone20);
   fChain->SetBranchAddress("trig_EF_ph_ptcone30", &trig_EF_ph_ptcone30, &b_trig_EF_ph_ptcone30);
   fChain->SetBranchAddress("trig_EF_ph_ptcone40", &trig_EF_ph_ptcone40, &b_trig_EF_ph_ptcone40);
   fChain->SetBranchAddress("trig_EF_ph_convanglematch", &trig_EF_ph_convanglematch, &b_trig_EF_ph_convanglematch);
   fChain->SetBranchAddress("trig_EF_ph_convtrackmatch", &trig_EF_ph_convtrackmatch, &b_trig_EF_ph_convtrackmatch);
   fChain->SetBranchAddress("trig_EF_ph_hasconv", &trig_EF_ph_hasconv, &b_trig_EF_ph_hasconv);
   fChain->SetBranchAddress("trig_EF_ph_convvtxx", &trig_EF_ph_convvtxx, &b_trig_EF_ph_convvtxx);
   fChain->SetBranchAddress("trig_EF_ph_convvtxy", &trig_EF_ph_convvtxy, &b_trig_EF_ph_convvtxy);
   fChain->SetBranchAddress("trig_EF_ph_convvtxz", &trig_EF_ph_convvtxz, &b_trig_EF_ph_convvtxz);
   fChain->SetBranchAddress("trig_EF_ph_Rconv", &trig_EF_ph_Rconv, &b_trig_EF_ph_Rconv);
   fChain->SetBranchAddress("trig_EF_ph_zconv", &trig_EF_ph_zconv, &b_trig_EF_ph_zconv);
   fChain->SetBranchAddress("trig_EF_ph_convvtxchi2", &trig_EF_ph_convvtxchi2, &b_trig_EF_ph_convvtxchi2);
   fChain->SetBranchAddress("trig_EF_ph_pt1conv", &trig_EF_ph_pt1conv, &b_trig_EF_ph_pt1conv);
   fChain->SetBranchAddress("trig_EF_ph_convtrk1nBLHits", &trig_EF_ph_convtrk1nBLHits, &b_trig_EF_ph_convtrk1nBLHits);
   fChain->SetBranchAddress("trig_EF_ph_convtrk1nPixHits", &trig_EF_ph_convtrk1nPixHits, &b_trig_EF_ph_convtrk1nPixHits);
   fChain->SetBranchAddress("trig_EF_ph_convtrk1nSCTHits", &trig_EF_ph_convtrk1nSCTHits, &b_trig_EF_ph_convtrk1nSCTHits);
   fChain->SetBranchAddress("trig_EF_ph_convtrk1nTRTHits", &trig_EF_ph_convtrk1nTRTHits, &b_trig_EF_ph_convtrk1nTRTHits);
   fChain->SetBranchAddress("trig_EF_ph_pt2conv", &trig_EF_ph_pt2conv, &b_trig_EF_ph_pt2conv);
   fChain->SetBranchAddress("trig_EF_ph_convtrk2nBLHits", &trig_EF_ph_convtrk2nBLHits, &b_trig_EF_ph_convtrk2nBLHits);
   fChain->SetBranchAddress("trig_EF_ph_convtrk2nPixHits", &trig_EF_ph_convtrk2nPixHits, &b_trig_EF_ph_convtrk2nPixHits);
   fChain->SetBranchAddress("trig_EF_ph_convtrk2nSCTHits", &trig_EF_ph_convtrk2nSCTHits, &b_trig_EF_ph_convtrk2nSCTHits);
   fChain->SetBranchAddress("trig_EF_ph_convtrk2nTRTHits", &trig_EF_ph_convtrk2nTRTHits, &b_trig_EF_ph_convtrk2nTRTHits);
   fChain->SetBranchAddress("trig_EF_ph_ptconv", &trig_EF_ph_ptconv, &b_trig_EF_ph_ptconv);
   fChain->SetBranchAddress("trig_EF_ph_pzconv", &trig_EF_ph_pzconv, &b_trig_EF_ph_pzconv);
   fChain->SetBranchAddress("trig_EF_ph_reta", &trig_EF_ph_reta, &b_trig_EF_ph_reta);
   fChain->SetBranchAddress("trig_EF_ph_rphi", &trig_EF_ph_rphi, &b_trig_EF_ph_rphi);
   fChain->SetBranchAddress("trig_EF_ph_cl_E", &trig_EF_ph_cl_E, &b_trig_EF_ph_cl_E);
   fChain->SetBranchAddress("trig_EF_ph_cl_pt", &trig_EF_ph_cl_pt, &b_trig_EF_ph_cl_pt);
   fChain->SetBranchAddress("trig_EF_ph_cl_eta", &trig_EF_ph_cl_eta, &b_trig_EF_ph_cl_eta);
   fChain->SetBranchAddress("trig_EF_ph_cl_phi", &trig_EF_ph_cl_phi, &b_trig_EF_ph_cl_phi);
   fChain->SetBranchAddress("trig_EF_ph_cl_etas2", &trig_EF_ph_cl_etas2, &b_trig_EF_ph_cl_etas2);
   fChain->SetBranchAddress("trig_EF_el_n", &trig_EF_el_n, &b_trig_EF_el_n);
   fChain->SetBranchAddress("trig_EF_el_E", &trig_EF_el_E, &b_trig_EF_el_E);
   fChain->SetBranchAddress("trig_EF_el_Et", &trig_EF_el_Et, &b_trig_EF_el_Et);
   fChain->SetBranchAddress("trig_EF_el_pt", &trig_EF_el_pt, &b_trig_EF_el_pt);
   fChain->SetBranchAddress("trig_EF_el_m", &trig_EF_el_m, &b_trig_EF_el_m);
   fChain->SetBranchAddress("trig_EF_el_eta", &trig_EF_el_eta, &b_trig_EF_el_eta);
   fChain->SetBranchAddress("trig_EF_el_phi", &trig_EF_el_phi, &b_trig_EF_el_phi);
   fChain->SetBranchAddress("trig_EF_el_px", &trig_EF_el_px, &b_trig_EF_el_px);
   fChain->SetBranchAddress("trig_EF_el_py", &trig_EF_el_py, &b_trig_EF_el_py);
   fChain->SetBranchAddress("trig_EF_el_pz", &trig_EF_el_pz, &b_trig_EF_el_pz);
   fChain->SetBranchAddress("trig_EF_el_charge", &trig_EF_el_charge, &b_trig_EF_el_charge);
   fChain->SetBranchAddress("trig_EF_el_author", &trig_EF_el_author, &b_trig_EF_el_author);
   fChain->SetBranchAddress("trig_EF_el_isEM", &trig_EF_el_isEM, &b_trig_EF_el_isEM);
   fChain->SetBranchAddress("trig_EF_el_isEMLoose", &trig_EF_el_isEMLoose, &b_trig_EF_el_isEMLoose);
   fChain->SetBranchAddress("trig_EF_el_isEMMedium", &trig_EF_el_isEMMedium, &b_trig_EF_el_isEMMedium);
   fChain->SetBranchAddress("trig_EF_el_isEMTight", &trig_EF_el_isEMTight, &b_trig_EF_el_isEMTight);
   fChain->SetBranchAddress("trig_EF_el_loose", &trig_EF_el_loose, &b_trig_EF_el_loose);
   fChain->SetBranchAddress("trig_EF_el_looseIso", &trig_EF_el_looseIso, &b_trig_EF_el_looseIso);
   fChain->SetBranchAddress("trig_EF_el_medium", &trig_EF_el_medium, &b_trig_EF_el_medium);
   fChain->SetBranchAddress("trig_EF_el_mediumIso", &trig_EF_el_mediumIso, &b_trig_EF_el_mediumIso);
   fChain->SetBranchAddress("trig_EF_el_mediumWithoutTrack", &trig_EF_el_mediumWithoutTrack, &b_trig_EF_el_mediumWithoutTrack);
   fChain->SetBranchAddress("trig_EF_el_mediumIsoWithoutTrack", &trig_EF_el_mediumIsoWithoutTrack, &b_trig_EF_el_mediumIsoWithoutTrack);
   fChain->SetBranchAddress("trig_EF_el_tight", &trig_EF_el_tight, &b_trig_EF_el_tight);
   fChain->SetBranchAddress("trig_EF_el_tightIso", &trig_EF_el_tightIso, &b_trig_EF_el_tightIso);
   fChain->SetBranchAddress("trig_EF_el_tightWithoutTrack", &trig_EF_el_tightWithoutTrack, &b_trig_EF_el_tightWithoutTrack);
   fChain->SetBranchAddress("trig_EF_el_tightIsoWithoutTrack", &trig_EF_el_tightIsoWithoutTrack, &b_trig_EF_el_tightIsoWithoutTrack);
   fChain->SetBranchAddress("trig_EF_el_loosePP", &trig_EF_el_loosePP, &b_trig_EF_el_loosePP);
   fChain->SetBranchAddress("trig_EF_el_loosePPIso", &trig_EF_el_loosePPIso, &b_trig_EF_el_loosePPIso);
   fChain->SetBranchAddress("trig_EF_el_mediumPP", &trig_EF_el_mediumPP, &b_trig_EF_el_mediumPP);
   fChain->SetBranchAddress("trig_EF_el_mediumPPIso", &trig_EF_el_mediumPPIso, &b_trig_EF_el_mediumPPIso);
   fChain->SetBranchAddress("trig_EF_el_tightPP", &trig_EF_el_tightPP, &b_trig_EF_el_tightPP);
   fChain->SetBranchAddress("trig_EF_el_tightPPIso", &trig_EF_el_tightPPIso, &b_trig_EF_el_tightPPIso);
   fChain->SetBranchAddress("trig_EF_el_Ethad", &trig_EF_el_Ethad, &b_trig_EF_el_Ethad);
   fChain->SetBranchAddress("trig_EF_el_Ethad1", &trig_EF_el_Ethad1, &b_trig_EF_el_Ethad1);
   fChain->SetBranchAddress("trig_EF_el_f1", &trig_EF_el_f1, &b_trig_EF_el_f1);
   fChain->SetBranchAddress("trig_EF_el_f1core", &trig_EF_el_f1core, &b_trig_EF_el_f1core);
   fChain->SetBranchAddress("trig_EF_el_Emins1", &trig_EF_el_Emins1, &b_trig_EF_el_Emins1);
   fChain->SetBranchAddress("trig_EF_el_fside", &trig_EF_el_fside, &b_trig_EF_el_fside);
   fChain->SetBranchAddress("trig_EF_el_Emax2", &trig_EF_el_Emax2, &b_trig_EF_el_Emax2);
   fChain->SetBranchAddress("trig_EF_el_ws3", &trig_EF_el_ws3, &b_trig_EF_el_ws3);
   fChain->SetBranchAddress("trig_EF_el_wstot", &trig_EF_el_wstot, &b_trig_EF_el_wstot);
   fChain->SetBranchAddress("trig_EF_el_emaxs1", &trig_EF_el_emaxs1, &b_trig_EF_el_emaxs1);
   fChain->SetBranchAddress("trig_EF_el_deltaEs", &trig_EF_el_deltaEs, &b_trig_EF_el_deltaEs);
   fChain->SetBranchAddress("trig_EF_el_E233", &trig_EF_el_E233, &b_trig_EF_el_E233);
   fChain->SetBranchAddress("trig_EF_el_E237", &trig_EF_el_E237, &b_trig_EF_el_E237);
   fChain->SetBranchAddress("trig_EF_el_E277", &trig_EF_el_E277, &b_trig_EF_el_E277);
   fChain->SetBranchAddress("trig_EF_el_weta2", &trig_EF_el_weta2, &b_trig_EF_el_weta2);
   fChain->SetBranchAddress("trig_EF_el_f3", &trig_EF_el_f3, &b_trig_EF_el_f3);
   fChain->SetBranchAddress("trig_EF_el_f3core", &trig_EF_el_f3core, &b_trig_EF_el_f3core);
   fChain->SetBranchAddress("trig_EF_el_rphiallcalo", &trig_EF_el_rphiallcalo, &b_trig_EF_el_rphiallcalo);
   fChain->SetBranchAddress("trig_EF_el_Etcone45", &trig_EF_el_Etcone45, &b_trig_EF_el_Etcone45);
   fChain->SetBranchAddress("trig_EF_el_Etcone15", &trig_EF_el_Etcone15, &b_trig_EF_el_Etcone15);
   fChain->SetBranchAddress("trig_EF_el_Etcone20", &trig_EF_el_Etcone20, &b_trig_EF_el_Etcone20);
   fChain->SetBranchAddress("trig_EF_el_Etcone25", &trig_EF_el_Etcone25, &b_trig_EF_el_Etcone25);
   fChain->SetBranchAddress("trig_EF_el_Etcone30", &trig_EF_el_Etcone30, &b_trig_EF_el_Etcone30);
   fChain->SetBranchAddress("trig_EF_el_Etcone35", &trig_EF_el_Etcone35, &b_trig_EF_el_Etcone35);
   fChain->SetBranchAddress("trig_EF_el_Etcone40", &trig_EF_el_Etcone40, &b_trig_EF_el_Etcone40);
   fChain->SetBranchAddress("trig_EF_el_ptcone20", &trig_EF_el_ptcone20, &b_trig_EF_el_ptcone20);
   fChain->SetBranchAddress("trig_EF_el_ptcone30", &trig_EF_el_ptcone30, &b_trig_EF_el_ptcone30);
   fChain->SetBranchAddress("trig_EF_el_ptcone40", &trig_EF_el_ptcone40, &b_trig_EF_el_ptcone40);
   fChain->SetBranchAddress("trig_EF_el_pos7", &trig_EF_el_pos7, &b_trig_EF_el_pos7);
   fChain->SetBranchAddress("trig_EF_el_etacorrmag", &trig_EF_el_etacorrmag, &b_trig_EF_el_etacorrmag);
   fChain->SetBranchAddress("trig_EF_el_deltaeta1", &trig_EF_el_deltaeta1, &b_trig_EF_el_deltaeta1);
   fChain->SetBranchAddress("trig_EF_el_deltaeta2", &trig_EF_el_deltaeta2, &b_trig_EF_el_deltaeta2);
   fChain->SetBranchAddress("trig_EF_el_deltaphi2", &trig_EF_el_deltaphi2, &b_trig_EF_el_deltaphi2);
   fChain->SetBranchAddress("trig_EF_el_expectHitInBLayer", &trig_EF_el_expectHitInBLayer, &b_trig_EF_el_expectHitInBLayer);
   fChain->SetBranchAddress("trig_EF_el_trackd0_physics", &trig_EF_el_trackd0_physics, &b_trig_EF_el_trackd0_physics);
   fChain->SetBranchAddress("trig_EF_el_reta", &trig_EF_el_reta, &b_trig_EF_el_reta);
   fChain->SetBranchAddress("trig_EF_el_rphi", &trig_EF_el_rphi, &b_trig_EF_el_rphi);
   fChain->SetBranchAddress("trig_EF_el_EtringnoisedR03sig2", &trig_EF_el_EtringnoisedR03sig2, &b_trig_EF_el_EtringnoisedR03sig2);
   fChain->SetBranchAddress("trig_EF_el_EtringnoisedR03sig3", &trig_EF_el_EtringnoisedR03sig3, &b_trig_EF_el_EtringnoisedR03sig3);
   fChain->SetBranchAddress("trig_EF_el_EtringnoisedR03sig4", &trig_EF_el_EtringnoisedR03sig4, &b_trig_EF_el_EtringnoisedR03sig4);
   fChain->SetBranchAddress("trig_EF_el_isolationlikelihoodjets", &trig_EF_el_isolationlikelihoodjets, &b_trig_EF_el_isolationlikelihoodjets);
   fChain->SetBranchAddress("trig_EF_el_isolationlikelihoodhqelectrons", &trig_EF_el_isolationlikelihoodhqelectrons, &b_trig_EF_el_isolationlikelihoodhqelectrons);
   fChain->SetBranchAddress("trig_EF_el_electronweight", &trig_EF_el_electronweight, &b_trig_EF_el_electronweight);
   fChain->SetBranchAddress("trig_EF_el_electronbgweight", &trig_EF_el_electronbgweight, &b_trig_EF_el_electronbgweight);
   fChain->SetBranchAddress("trig_EF_el_softeweight", &trig_EF_el_softeweight, &b_trig_EF_el_softeweight);
   fChain->SetBranchAddress("trig_EF_el_softebgweight", &trig_EF_el_softebgweight, &b_trig_EF_el_softebgweight);
   fChain->SetBranchAddress("trig_EF_el_neuralnet", &trig_EF_el_neuralnet, &b_trig_EF_el_neuralnet);
   fChain->SetBranchAddress("trig_EF_el_Hmatrix", &trig_EF_el_Hmatrix, &b_trig_EF_el_Hmatrix);
   fChain->SetBranchAddress("trig_EF_el_Hmatrix5", &trig_EF_el_Hmatrix5, &b_trig_EF_el_Hmatrix5);
   fChain->SetBranchAddress("trig_EF_el_adaboost", &trig_EF_el_adaboost, &b_trig_EF_el_adaboost);
   fChain->SetBranchAddress("trig_EF_el_softeneuralnet", &trig_EF_el_softeneuralnet, &b_trig_EF_el_softeneuralnet);
   fChain->SetBranchAddress("trig_EF_el_zvertex", &trig_EF_el_zvertex, &b_trig_EF_el_zvertex);
   fChain->SetBranchAddress("trig_EF_el_errz", &trig_EF_el_errz, &b_trig_EF_el_errz);
   fChain->SetBranchAddress("trig_EF_el_etap", &trig_EF_el_etap, &b_trig_EF_el_etap);
   fChain->SetBranchAddress("trig_EF_el_depth", &trig_EF_el_depth, &b_trig_EF_el_depth);
   fChain->SetBranchAddress("trig_EF_el_Es0", &trig_EF_el_Es0, &b_trig_EF_el_Es0);
   fChain->SetBranchAddress("trig_EF_el_etas0", &trig_EF_el_etas0, &b_trig_EF_el_etas0);
   fChain->SetBranchAddress("trig_EF_el_phis0", &trig_EF_el_phis0, &b_trig_EF_el_phis0);
   fChain->SetBranchAddress("trig_EF_el_Es1", &trig_EF_el_Es1, &b_trig_EF_el_Es1);
   fChain->SetBranchAddress("trig_EF_el_etas1", &trig_EF_el_etas1, &b_trig_EF_el_etas1);
   fChain->SetBranchAddress("trig_EF_el_phis1", &trig_EF_el_phis1, &b_trig_EF_el_phis1);
   fChain->SetBranchAddress("trig_EF_el_Es2", &trig_EF_el_Es2, &b_trig_EF_el_Es2);
   fChain->SetBranchAddress("trig_EF_el_etas2", &trig_EF_el_etas2, &b_trig_EF_el_etas2);
   fChain->SetBranchAddress("trig_EF_el_phis2", &trig_EF_el_phis2, &b_trig_EF_el_phis2);
   fChain->SetBranchAddress("trig_EF_el_Es3", &trig_EF_el_Es3, &b_trig_EF_el_Es3);
   fChain->SetBranchAddress("trig_EF_el_etas3", &trig_EF_el_etas3, &b_trig_EF_el_etas3);
   fChain->SetBranchAddress("trig_EF_el_phis3", &trig_EF_el_phis3, &b_trig_EF_el_phis3);
   fChain->SetBranchAddress("trig_EF_el_cl_E", &trig_EF_el_cl_E, &b_trig_EF_el_cl_E);
   fChain->SetBranchAddress("trig_EF_el_cl_pt", &trig_EF_el_cl_pt, &b_trig_EF_el_cl_pt);
   fChain->SetBranchAddress("trig_EF_el_cl_eta", &trig_EF_el_cl_eta, &b_trig_EF_el_cl_eta);
   fChain->SetBranchAddress("trig_EF_el_cl_phi", &trig_EF_el_cl_phi, &b_trig_EF_el_cl_phi);
   fChain->SetBranchAddress("trig_EF_el_trackd0", &trig_EF_el_trackd0, &b_trig_EF_el_trackd0);
   fChain->SetBranchAddress("trig_EF_el_trackz0", &trig_EF_el_trackz0, &b_trig_EF_el_trackz0);
   fChain->SetBranchAddress("trig_EF_el_trackphi", &trig_EF_el_trackphi, &b_trig_EF_el_trackphi);
   fChain->SetBranchAddress("trig_EF_el_tracktheta", &trig_EF_el_tracktheta, &b_trig_EF_el_tracktheta);
   fChain->SetBranchAddress("trig_EF_el_trackqoverp", &trig_EF_el_trackqoverp, &b_trig_EF_el_trackqoverp);
   fChain->SetBranchAddress("trig_EF_el_trackpt", &trig_EF_el_trackpt, &b_trig_EF_el_trackpt);
   fChain->SetBranchAddress("trig_EF_el_tracketa", &trig_EF_el_tracketa, &b_trig_EF_el_tracketa);
   fChain->SetBranchAddress("trig_EF_el_trackfitchi2", &trig_EF_el_trackfitchi2, &b_trig_EF_el_trackfitchi2);
   fChain->SetBranchAddress("trig_EF_el_trackfitndof", &trig_EF_el_trackfitndof, &b_trig_EF_el_trackfitndof);
   fChain->SetBranchAddress("trig_EF_el_nBLHits", &trig_EF_el_nBLHits, &b_trig_EF_el_nBLHits);
   fChain->SetBranchAddress("trig_EF_el_nPixHits", &trig_EF_el_nPixHits, &b_trig_EF_el_nPixHits);
   fChain->SetBranchAddress("trig_EF_el_nSCTHits", &trig_EF_el_nSCTHits, &b_trig_EF_el_nSCTHits);
   fChain->SetBranchAddress("trig_EF_el_nTRTHits", &trig_EF_el_nTRTHits, &b_trig_EF_el_nTRTHits);
   fChain->SetBranchAddress("trig_EF_el_nTRTHighTHits", &trig_EF_el_nTRTHighTHits, &b_trig_EF_el_nTRTHighTHits);
   fChain->SetBranchAddress("trig_EF_el_nTRTXenonHits", &trig_EF_el_nTRTXenonHits, &b_trig_EF_el_nTRTXenonHits);
   fChain->SetBranchAddress("trig_EF_el_nPixHoles", &trig_EF_el_nPixHoles, &b_trig_EF_el_nPixHoles);
   fChain->SetBranchAddress("trig_EF_el_nSCTHoles", &trig_EF_el_nSCTHoles, &b_trig_EF_el_nSCTHoles);
   fChain->SetBranchAddress("trig_EF_el_nTRTHoles", &trig_EF_el_nTRTHoles, &b_trig_EF_el_nTRTHoles);
   fChain->SetBranchAddress("trig_EF_el_nPixelDeadSensors", &trig_EF_el_nPixelDeadSensors, &b_trig_EF_el_nPixelDeadSensors);
   fChain->SetBranchAddress("trig_EF_el_nSCTDeadSensors", &trig_EF_el_nSCTDeadSensors, &b_trig_EF_el_nSCTDeadSensors);
   fChain->SetBranchAddress("trig_EF_el_nBLSharedHits", &trig_EF_el_nBLSharedHits, &b_trig_EF_el_nBLSharedHits);
   fChain->SetBranchAddress("trig_EF_el_nPixSharedHits", &trig_EF_el_nPixSharedHits, &b_trig_EF_el_nPixSharedHits);
   fChain->SetBranchAddress("trig_EF_el_nSCTSharedHits", &trig_EF_el_nSCTSharedHits, &b_trig_EF_el_nSCTSharedHits);
   fChain->SetBranchAddress("trig_EF_el_nBLayerSplitHits", &trig_EF_el_nBLayerSplitHits, &b_trig_EF_el_nBLayerSplitHits);
   fChain->SetBranchAddress("trig_EF_el_nPixSplitHits", &trig_EF_el_nPixSplitHits, &b_trig_EF_el_nPixSplitHits);
   fChain->SetBranchAddress("trig_EF_el_nBLayerOutliers", &trig_EF_el_nBLayerOutliers, &b_trig_EF_el_nBLayerOutliers);
   fChain->SetBranchAddress("trig_EF_el_nPixelOutliers", &trig_EF_el_nPixelOutliers, &b_trig_EF_el_nPixelOutliers);
   fChain->SetBranchAddress("trig_EF_el_nSCTOutliers", &trig_EF_el_nSCTOutliers, &b_trig_EF_el_nSCTOutliers);
   fChain->SetBranchAddress("trig_EF_el_nTRTOutliers", &trig_EF_el_nTRTOutliers, &b_trig_EF_el_nTRTOutliers);
   fChain->SetBranchAddress("trig_EF_el_nTRTHighTOutliers", &trig_EF_el_nTRTHighTOutliers, &b_trig_EF_el_nTRTHighTOutliers);
   fChain->SetBranchAddress("trig_EF_el_expectBLayerHit", &trig_EF_el_expectBLayerHit, &b_trig_EF_el_expectBLayerHit);
   fChain->SetBranchAddress("trig_EF_el_nSiHits", &trig_EF_el_nSiHits, &b_trig_EF_el_nSiHits);
   fChain->SetBranchAddress("trig_EF_el_TRTHighTHitsRatio", &trig_EF_el_TRTHighTHitsRatio, &b_trig_EF_el_TRTHighTHitsRatio);
   fChain->SetBranchAddress("trig_EF_el_TRTHighTOutliersRatio", &trig_EF_el_TRTHighTOutliersRatio, &b_trig_EF_el_TRTHighTOutliersRatio);
   fChain->SetBranchAddress("trig_EF_el_pixeldEdx", &trig_EF_el_pixeldEdx, &b_trig_EF_el_pixeldEdx);
   fChain->SetBranchAddress("trig_EF_el_nGoodHitsPixeldEdx", &trig_EF_el_nGoodHitsPixeldEdx, &b_trig_EF_el_nGoodHitsPixeldEdx);
   fChain->SetBranchAddress("trig_EF_el_massPixeldEdx", &trig_EF_el_massPixeldEdx, &b_trig_EF_el_massPixeldEdx);
   fChain->SetBranchAddress("trig_EF_el_likelihoodsPixeldEdx", &trig_EF_el_likelihoodsPixeldEdx, &b_trig_EF_el_likelihoodsPixeldEdx);
   fChain->SetBranchAddress("trig_EF_el_eProbabilityComb", &trig_EF_el_eProbabilityComb, &b_trig_EF_el_eProbabilityComb);
   fChain->SetBranchAddress("trig_EF_el_eProbabilityHT", &trig_EF_el_eProbabilityHT, &b_trig_EF_el_eProbabilityHT);
   fChain->SetBranchAddress("trig_EF_el_eProbabilityToT", &trig_EF_el_eProbabilityToT, &b_trig_EF_el_eProbabilityToT);
   fChain->SetBranchAddress("trig_EF_el_eProbabilityBrem", &trig_EF_el_eProbabilityBrem, &b_trig_EF_el_eProbabilityBrem);
   fChain->SetBranchAddress("trig_EF_el_vertweight", &trig_EF_el_vertweight, &b_trig_EF_el_vertweight);
   fChain->SetBranchAddress("trig_EF_el_vertx", &trig_EF_el_vertx, &b_trig_EF_el_vertx);
   fChain->SetBranchAddress("trig_EF_el_verty", &trig_EF_el_verty, &b_trig_EF_el_verty);
   fChain->SetBranchAddress("trig_EF_el_vertz", &trig_EF_el_vertz, &b_trig_EF_el_vertz);
   fChain->SetBranchAddress("trig_EF_el_hastrack", &trig_EF_el_hastrack, &b_trig_EF_el_hastrack);
   fChain->SetBranchAddress("trig_EF_trigmuonef_n", &trig_EF_trigmuonef_n, &b_trig_EF_trigmuonef_n);
   fChain->SetBranchAddress("trig_EF_trigmuonef_effs15", &trig_EF_trigmuonef_effs15, &b_trig_EF_trigmuonef_effs15);
   fChain->SetBranchAddress("trig_EF_trigmuonef_effs18", &trig_EF_trigmuonef_effs18, &b_trig_EF_trigmuonef_effs18);
   fChain->SetBranchAddress("trig_EF_trigmuonef_effs24", &trig_EF_trigmuonef_effs24, &b_trig_EF_trigmuonef_effs24);
   fChain->SetBranchAddress("trig_EF_trigmuonef_RoINum", &trig_EF_trigmuonef_RoINum, &b_trig_EF_trigmuonef_RoINum);
   fChain->SetBranchAddress("trig_EF_trigmuonef_NSegments", &trig_EF_trigmuonef_NSegments, &b_trig_EF_trigmuonef_NSegments);
   fChain->SetBranchAddress("trig_EF_trigmuonef_NMdtHits", &trig_EF_trigmuonef_NMdtHits, &b_trig_EF_trigmuonef_NMdtHits);
   fChain->SetBranchAddress("trig_EF_trigmuonef_NRpcHits", &trig_EF_trigmuonef_NRpcHits, &b_trig_EF_trigmuonef_NRpcHits);
   fChain->SetBranchAddress("trig_EF_trigmuonef_NTgcHits", &trig_EF_trigmuonef_NTgcHits, &b_trig_EF_trigmuonef_NTgcHits);
   fChain->SetBranchAddress("trig_EF_trigmuonef_NCscHits", &trig_EF_trigmuonef_NCscHits, &b_trig_EF_trigmuonef_NCscHits);
   fChain->SetBranchAddress("trig_EF_trigmuonef_EtaPreviousLevel", &trig_EF_trigmuonef_EtaPreviousLevel, &b_trig_EF_trigmuonef_EtaPreviousLevel);
   fChain->SetBranchAddress("trig_EF_trigmuonef_PhiPreviousLevel", &trig_EF_trigmuonef_PhiPreviousLevel, &b_trig_EF_trigmuonef_PhiPreviousLevel);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_n", &trig_EF_trigmuonef_track_n, &b_trig_EF_trigmuonef_track_n);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MuonType", &trig_EF_trigmuonef_track_MuonType, &b_trig_EF_trigmuonef_track_MuonType);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_pt", &trig_EF_trigmuonef_track_MS_pt, &b_trig_EF_trigmuonef_track_MS_pt);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_eta", &trig_EF_trigmuonef_track_MS_eta, &b_trig_EF_trigmuonef_track_MS_eta);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_phi", &trig_EF_trigmuonef_track_MS_phi, &b_trig_EF_trigmuonef_track_MS_phi);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_charge", &trig_EF_trigmuonef_track_MS_charge, &b_trig_EF_trigmuonef_track_MS_charge);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_d0", &trig_EF_trigmuonef_track_MS_d0, &b_trig_EF_trigmuonef_track_MS_d0);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_z0", &trig_EF_trigmuonef_track_MS_z0, &b_trig_EF_trigmuonef_track_MS_z0);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_chi2", &trig_EF_trigmuonef_track_MS_chi2, &b_trig_EF_trigmuonef_track_MS_chi2);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_chi2prob", &trig_EF_trigmuonef_track_MS_chi2prob, &b_trig_EF_trigmuonef_track_MS_chi2prob);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_posX", &trig_EF_trigmuonef_track_MS_posX, &b_trig_EF_trigmuonef_track_MS_posX);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_posY", &trig_EF_trigmuonef_track_MS_posY, &b_trig_EF_trigmuonef_track_MS_posY);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_posZ", &trig_EF_trigmuonef_track_MS_posZ, &b_trig_EF_trigmuonef_track_MS_posZ);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_NRpcHitsPhi", &trig_EF_trigmuonef_track_MS_NRpcHitsPhi, &b_trig_EF_trigmuonef_track_MS_NRpcHitsPhi);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_NTgcHitsPhi", &trig_EF_trigmuonef_track_MS_NTgcHitsPhi, &b_trig_EF_trigmuonef_track_MS_NTgcHitsPhi);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_NCscHitsPhi", &trig_EF_trigmuonef_track_MS_NCscHitsPhi, &b_trig_EF_trigmuonef_track_MS_NCscHitsPhi);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_NRpcHitsEta", &trig_EF_trigmuonef_track_MS_NRpcHitsEta, &b_trig_EF_trigmuonef_track_MS_NRpcHitsEta);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_NTgcHitsEta", &trig_EF_trigmuonef_track_MS_NTgcHitsEta, &b_trig_EF_trigmuonef_track_MS_NTgcHitsEta);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_NCscHitsEta", &trig_EF_trigmuonef_track_MS_NCscHitsEta, &b_trig_EF_trigmuonef_track_MS_NCscHitsEta);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_NMdtHits", &trig_EF_trigmuonef_track_MS_NMdtHits, &b_trig_EF_trigmuonef_track_MS_NMdtHits);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_MS_hasMS", &trig_EF_trigmuonef_track_MS_hasMS, &b_trig_EF_trigmuonef_track_MS_hasMS);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_SA_pt", &trig_EF_trigmuonef_track_SA_pt, &b_trig_EF_trigmuonef_track_SA_pt);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_SA_eta", &trig_EF_trigmuonef_track_SA_eta, &b_trig_EF_trigmuonef_track_SA_eta);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_SA_phi", &trig_EF_trigmuonef_track_SA_phi, &b_trig_EF_trigmuonef_track_SA_phi);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_SA_charge", &trig_EF_trigmuonef_track_SA_charge, &b_trig_EF_trigmuonef_track_SA_charge);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_SA_d0", &trig_EF_trigmuonef_track_SA_d0, &b_trig_EF_trigmuonef_track_SA_d0);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_SA_z0", &trig_EF_trigmuonef_track_SA_z0, &b_trig_EF_trigmuonef_track_SA_z0);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_SA_chi2", &trig_EF_trigmuonef_track_SA_chi2, &b_trig_EF_trigmuonef_track_SA_chi2);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_SA_chi2prob", &trig_EF_trigmuonef_track_SA_chi2prob, &b_trig_EF_trigmuonef_track_SA_chi2prob);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_SA_posX", &trig_EF_trigmuonef_track_SA_posX, &b_trig_EF_trigmuonef_track_SA_posX);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_SA_posY", &trig_EF_trigmuonef_track_SA_posY, &b_trig_EF_trigmuonef_track_SA_posY);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_SA_posZ", &trig_EF_trigmuonef_track_SA_posZ, &b_trig_EF_trigmuonef_track_SA_posZ);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_SA_hasSA", &trig_EF_trigmuonef_track_SA_hasSA, &b_trig_EF_trigmuonef_track_SA_hasSA);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_CB_pt", &trig_EF_trigmuonef_track_CB_pt, &b_trig_EF_trigmuonef_track_CB_pt);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_CB_eta", &trig_EF_trigmuonef_track_CB_eta, &b_trig_EF_trigmuonef_track_CB_eta);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_CB_phi", &trig_EF_trigmuonef_track_CB_phi, &b_trig_EF_trigmuonef_track_CB_phi);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_CB_charge", &trig_EF_trigmuonef_track_CB_charge, &b_trig_EF_trigmuonef_track_CB_charge);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_CB_d0", &trig_EF_trigmuonef_track_CB_d0, &b_trig_EF_trigmuonef_track_CB_d0);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_CB_z0", &trig_EF_trigmuonef_track_CB_z0, &b_trig_EF_trigmuonef_track_CB_z0);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_CB_chi2", &trig_EF_trigmuonef_track_CB_chi2, &b_trig_EF_trigmuonef_track_CB_chi2);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_CB_chi2prob", &trig_EF_trigmuonef_track_CB_chi2prob, &b_trig_EF_trigmuonef_track_CB_chi2prob);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_CB_posX", &trig_EF_trigmuonef_track_CB_posX, &b_trig_EF_trigmuonef_track_CB_posX);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_CB_posY", &trig_EF_trigmuonef_track_CB_posY, &b_trig_EF_trigmuonef_track_CB_posY);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_CB_posZ", &trig_EF_trigmuonef_track_CB_posZ, &b_trig_EF_trigmuonef_track_CB_posZ);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_CB_matchChi2", &trig_EF_trigmuonef_track_CB_matchChi2, &b_trig_EF_trigmuonef_track_CB_matchChi2);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_CB_NIdSctHits", &trig_EF_trigmuonef_track_CB_NIdSctHits, &b_trig_EF_trigmuonef_track_CB_NIdSctHits);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_CB_NIdPixelHits", &trig_EF_trigmuonef_track_CB_NIdPixelHits, &b_trig_EF_trigmuonef_track_CB_NIdPixelHits);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_CB_NTrtHits", &trig_EF_trigmuonef_track_CB_NTrtHits, &b_trig_EF_trigmuonef_track_CB_NTrtHits);
   fChain->SetBranchAddress("trig_EF_trigmuonef_track_CB_hasCB", &trig_EF_trigmuonef_track_CB_hasCB, &b_trig_EF_trigmuonef_track_CB_hasCB);
   fChain->SetBranchAddress("bcmRDO_n", &bcmRDO_n, &b_bcmRDO_n);
   fChain->SetBranchAddress("bcmRDO_channel", &bcmRDO_channel, &b_bcmRDO_channel);
   fChain->SetBranchAddress("bcmRDO_nhits", &bcmRDO_nhits, &b_bcmRDO_nhits);
   fChain->SetBranchAddress("bcmRDO_pulse1pos", &bcmRDO_pulse1pos, &b_bcmRDO_pulse1pos);
   fChain->SetBranchAddress("bcmRDO_pulse1width", &bcmRDO_pulse1width, &b_bcmRDO_pulse1width);
   fChain->SetBranchAddress("bcmRDO_pulse2pos", &bcmRDO_pulse2pos, &b_bcmRDO_pulse2pos);
   fChain->SetBranchAddress("bcmRDO_pulse2width", &bcmRDO_pulse2width, &b_bcmRDO_pulse2width);
   fChain->SetBranchAddress("bcmRDO_lvl1a", &bcmRDO_lvl1a, &b_bcmRDO_lvl1a);
   fChain->SetBranchAddress("bcmRDO_bcid", &bcmRDO_bcid, &b_bcmRDO_bcid);
   fChain->SetBranchAddress("bcmRDO_lvl1id", &bcmRDO_lvl1id, &b_bcmRDO_lvl1id);
   fChain->SetBranchAddress("ctpRDO_nBC", &ctpRDO_nBC, &b_ctpRDO_nBC);
   fChain->SetBranchAddress("ctpRDO_lvl1aBC", &ctpRDO_lvl1aBC, &b_ctpRDO_lvl1aBC);
   fChain->SetBranchAddress("ctpRDO_time_s", &ctpRDO_time_s, &b_ctpRDO_time_s);
   fChain->SetBranchAddress("ctpRDO_time_ns", &ctpRDO_time_ns, &b_ctpRDO_time_ns);
   fChain->SetBranchAddress("ctpRDO_pit", &ctpRDO_pit, &b_ctpRDO_pit);
   fChain->SetBranchAddress("ctpRDO_tbp", &ctpRDO_tbp, &b_ctpRDO_tbp);
   fChain->SetBranchAddress("ctpRDO_tap", &ctpRDO_tap, &b_ctpRDO_tap);
   fChain->SetBranchAddress("ctpRDO_tav", &ctpRDO_tav, &b_ctpRDO_tav);
   fChain->SetBranchAddress("ctp_decisionTypeWord", &ctp_decisionTypeWord, &b_ctp_decisionTypeWord);
   fChain->SetBranchAddress("ctp_decisionItems", &ctp_decisionItems, &b_ctp_decisionItems);
   fChain->SetBranchAddress("ctp_decisionWords", &ctp_decisionWords, &b_ctp_decisionWords);
   fChain->SetBranchAddress("ctp_nDecisionItems", &ctp_nDecisionItems, &b_ctp_nDecisionItems);
   fChain->SetBranchAddress("mbtsLvl2_nElements", &mbtsLvl2_nElements, &b_mbtsLvl2_nElements);
   fChain->SetBranchAddress("mbtsLvl2_energies", &mbtsLvl2_energies, &b_mbtsLvl2_energies);
   fChain->SetBranchAddress("mbtsLvl2_ntimes", &mbtsLvl2_ntimes, &b_mbtsLvl2_ntimes);
   fChain->SetBranchAddress("mbtsLvl2_times", &mbtsLvl2_times, &b_mbtsLvl2_times);
   fChain->SetBranchAddress("lvl2_sp_nElements", &lvl2_sp_nElements, &b_lvl2_sp_nElements);
   fChain->SetBranchAddress("lvl2_sp_hPixelClusTotBins", &lvl2_sp_hPixelClusTotBins, &b_lvl2_sp_hPixelClusTotBins);
   fChain->SetBranchAddress("lvl2_sp_hPixelClusTotMin", &lvl2_sp_hPixelClusTotMin, &b_lvl2_sp_hPixelClusTotMin);
   fChain->SetBranchAddress("lvl2_sp_hPixelClusTotMax", &lvl2_sp_hPixelClusTotMax, &b_lvl2_sp_hPixelClusTotMax);
   fChain->SetBranchAddress("lvl2_sp_hPixelClusSizeBins", &lvl2_sp_hPixelClusSizeBins, &b_lvl2_sp_hPixelClusSizeBins);
   fChain->SetBranchAddress("lvl2_sp_hPixelClusSizeMin", &lvl2_sp_hPixelClusSizeMin, &b_lvl2_sp_hPixelClusSizeMin);
   fChain->SetBranchAddress("lvl2_sp_hPixelClusSizeMax", &lvl2_sp_hPixelClusSizeMax, &b_lvl2_sp_hPixelClusSizeMax);
   fChain->SetBranchAddress("lvl2_sp_pixelClusEndcapC_contents", &lvl2_sp_pixelClusEndcapC_contents, &b_lvl2_sp_pixelClusEndcapC_contents);
   fChain->SetBranchAddress("lvl2_sp_pixelClusBarrel_contents", &lvl2_sp_pixelClusBarrel_contents, &b_lvl2_sp_pixelClusBarrel_contents);
   fChain->SetBranchAddress("lvl2_sp_pixelClusEndcapA_contents", &lvl2_sp_pixelClusEndcapA_contents, &b_lvl2_sp_pixelClusEndcapA_contents);
   fChain->SetBranchAddress("lvl2_sp_droppedPixelModuleIds", &lvl2_sp_droppedPixelModuleIds, &b_lvl2_sp_droppedPixelModuleIds);
   fChain->SetBranchAddress("lvl2_sp_sctSpEndcapC", &lvl2_sp_sctSpEndcapC, &b_lvl2_sp_sctSpEndcapC);
   fChain->SetBranchAddress("lvl2_sp_sctSpBarrel", &lvl2_sp_sctSpBarrel, &b_lvl2_sp_sctSpBarrel);
   fChain->SetBranchAddress("lvl2_sp_sctSpEndcapA", &lvl2_sp_sctSpEndcapA, &b_lvl2_sp_sctSpEndcapA);
   fChain->SetBranchAddress("lvl2_sp_droppedSctModuleIds", &lvl2_sp_droppedSctModuleIds, &b_lvl2_sp_droppedSctModuleIds);
   fChain->SetBranchAddress("lvl2_mbTrt_nElements", &lvl2_mbTrt_nElements, &b_lvl2_mbTrt_nElements);
   fChain->SetBranchAddress("lvl2_mbTrt_hTotBins", &lvl2_mbTrt_hTotBins, &b_lvl2_mbTrt_hTotBins);
   fChain->SetBranchAddress("lvl2_mbTrt_hTotMin", &lvl2_mbTrt_hTotMin, &b_lvl2_mbTrt_hTotMin);
   fChain->SetBranchAddress("lvl2_mbTrt_hTotMax", &lvl2_mbTrt_hTotMax, &b_lvl2_mbTrt_hTotMax);
   fChain->SetBranchAddress("lvl2_mbTrt_endcapC_contents", &lvl2_mbTrt_endcapC_contents, &b_lvl2_mbTrt_endcapC_contents);
   fChain->SetBranchAddress("lvl2_mbTrt_barrel_contents", &lvl2_mbTrt_barrel_contents, &b_lvl2_mbTrt_barrel_contents);
   fChain->SetBranchAddress("lvl2_mbTrt_endcapA_contents", &lvl2_mbTrt_endcapA_contents, &b_lvl2_mbTrt_endcapA_contents);
   fChain->SetBranchAddress("ef_trk_nElements", &ef_trk_nElements, &b_ef_trk_nElements);
   fChain->SetBranchAddress("ef_trk_hZ0Bins", &ef_trk_hZ0Bins, &b_ef_trk_hZ0Bins);
   fChain->SetBranchAddress("ef_trk_hZ0Min", &ef_trk_hZ0Min, &b_ef_trk_hZ0Min);
   fChain->SetBranchAddress("ef_trk_hZ0Max", &ef_trk_hZ0Max, &b_ef_trk_hZ0Max);
   fChain->SetBranchAddress("ef_trk_hPtBins", &ef_trk_hPtBins, &b_ef_trk_hPtBins);
   fChain->SetBranchAddress("ef_trk_hPtMin", &ef_trk_hPtMin, &b_ef_trk_hPtMin);
   fChain->SetBranchAddress("ef_trk_hPtMax", &ef_trk_hPtMax, &b_ef_trk_hPtMax);
   fChain->SetBranchAddress("ef_trk_hEtaBins", &ef_trk_hEtaBins, &b_ef_trk_hEtaBins);
   fChain->SetBranchAddress("ef_trk_hEtaMin", &ef_trk_hEtaMin, &b_ef_trk_hEtaMin);
   fChain->SetBranchAddress("ef_trk_hEtaMax", &ef_trk_hEtaMax, &b_ef_trk_hEtaMax);
   fChain->SetBranchAddress("ef_trk_hPhiBins", &ef_trk_hPhiBins, &b_ef_trk_hPhiBins);
   fChain->SetBranchAddress("ef_trk_hPhiMin", &ef_trk_hPhiMin, &b_ef_trk_hPhiMin);
   fChain->SetBranchAddress("ef_trk_hPhiMax", &ef_trk_hPhiMax, &b_ef_trk_hPhiMax);
   fChain->SetBranchAddress("ef_trk_z0_pt_contents", &ef_trk_z0_pt_contents, &b_ef_trk_z0_pt_contents);
   fChain->SetBranchAddress("ef_trk_eta_phi_contents", &ef_trk_eta_phi_contents, &b_ef_trk_eta_phi_contents);
   fChain->SetBranchAddress("trig_L2_jet_n", &trig_L2_jet_n, &b_trig_L2_jet_n);
   fChain->SetBranchAddress("trig_L2_jet_E", &trig_L2_jet_E, &b_trig_L2_jet_E);
   fChain->SetBranchAddress("trig_L2_jet_eta", &trig_L2_jet_eta, &b_trig_L2_jet_eta);
   fChain->SetBranchAddress("trig_L2_jet_phi", &trig_L2_jet_phi, &b_trig_L2_jet_phi);
   fChain->SetBranchAddress("trig_L2_jet_RoIWord", &trig_L2_jet_RoIWord, &b_trig_L2_jet_RoIWord);
   fChain->SetBranchAddress("trig_L2_jet_InputType", &trig_L2_jet_InputType, &b_trig_L2_jet_InputType);
   fChain->SetBranchAddress("trig_L2_jet_OutputType", &trig_L2_jet_OutputType, &b_trig_L2_jet_OutputType);
   fChain->SetBranchAddress("trig_L2_jet_counter", &trig_L2_jet_counter, &b_trig_L2_jet_counter);
   fChain->SetBranchAddress("trig_L2_jet_c4cchad", &trig_L2_jet_c4cchad, &b_trig_L2_jet_c4cchad);
   fChain->SetBranchAddress("trig_L2_jet_c4ccem", &trig_L2_jet_c4ccem, &b_trig_L2_jet_c4ccem);
   fChain->SetBranchAddress("trig_L2_jet_c4uchad", &trig_L2_jet_c4uchad, &b_trig_L2_jet_c4uchad);
   fChain->SetBranchAddress("trig_L2_jet_ehad0", &trig_L2_jet_ehad0, &b_trig_L2_jet_ehad0);
   fChain->SetBranchAddress("trig_L2_jet_eem0", &trig_L2_jet_eem0, &b_trig_L2_jet_eem0);
   fChain->SetBranchAddress("trig_L2_jet_nLeadingCells", &trig_L2_jet_nLeadingCells, &b_trig_L2_jet_nLeadingCells);
   fChain->SetBranchAddress("trig_L2_jet_hecf", &trig_L2_jet_hecf, &b_trig_L2_jet_hecf);
   fChain->SetBranchAddress("trig_L2_jet_jetQuality", &trig_L2_jet_jetQuality, &b_trig_L2_jet_jetQuality);
   fChain->SetBranchAddress("trig_L2_jet_emf", &trig_L2_jet_emf, &b_trig_L2_jet_emf);
   fChain->SetBranchAddress("trig_L2_jet_jetTimeCells", &trig_L2_jet_jetTimeCells, &b_trig_L2_jet_jetTimeCells);
   fChain->SetBranchAddress("vx_n", &vx_n, &b_vx_n);
   fChain->SetBranchAddress("vx_x", &vx_x, &b_vx_x);
   fChain->SetBranchAddress("vx_y", &vx_y, &b_vx_y);
   fChain->SetBranchAddress("vx_z", &vx_z, &b_vx_z);
   fChain->SetBranchAddress("vx_err_x", &vx_err_x, &b_vx_err_x);
   fChain->SetBranchAddress("vx_err_y", &vx_err_y, &b_vx_err_y);
   fChain->SetBranchAddress("vx_err_z", &vx_err_z, &b_vx_err_z);
   fChain->SetBranchAddress("vx_cov_xy", &vx_cov_xy, &b_vx_cov_xy);
   fChain->SetBranchAddress("vx_cov_xz", &vx_cov_xz, &b_vx_cov_xz);
   fChain->SetBranchAddress("vx_cov_yz", &vx_cov_yz, &b_vx_cov_yz);
   fChain->SetBranchAddress("vx_type", &vx_type, &b_vx_type);
   fChain->SetBranchAddress("vx_chi2", &vx_chi2, &b_vx_chi2);
   fChain->SetBranchAddress("vx_ndof", &vx_ndof, &b_vx_ndof);
   fChain->SetBranchAddress("vx_px", &vx_px, &b_vx_px);
   fChain->SetBranchAddress("vx_py", &vx_py, &b_vx_py);
   fChain->SetBranchAddress("vx_pz", &vx_pz, &b_vx_pz);
   fChain->SetBranchAddress("vx_E", &vx_E, &b_vx_E);
   fChain->SetBranchAddress("vx_m", &vx_m, &b_vx_m);
   fChain->SetBranchAddress("vx_nTracks", &vx_nTracks, &b_vx_nTracks);
   fChain->SetBranchAddress("vx_sumPt", &vx_sumPt, &b_vx_sumPt);
   fChain->SetBranchAddress("vx_trk_weight", &vx_trk_weight, &b_vx_trk_weight);
   fChain->SetBranchAddress("vx_trk_n", &vx_trk_n, &b_vx_trk_n);
   fChain->SetBranchAddress("vx_trk_index", &vx_trk_index, &b_vx_trk_index);
   Notify();
}

void extractor::InitMeta (TTree* tree) {

   HLTChains.push_back("EF_mbSpTrk");
   HLTChains.push_back("EF_mbMbts_1_1");
   HLTChains.push_back("EF_mbMbts_2");
   HLTChains.push_back("EF_L1MBTS_1_1_NoAlg");
   HLTChains.push_back("EF_L1ZDC_A_NoAlg");
   HLTChains.push_back("EF_L1ZDC_C_NoAlg");
   HLTChains.push_back("EF_mbSpTrkVtxMh_hip_trk100_L1TE10");
   HLTChains.push_back("EF_mbSpTrkVtxMh_hip_trk130_L1TE10");
   HLTChains.push_back("EF_mbSpTrkVtxMh_hip_trk150_L1TE50");
   HLTChains.push_back("EF_mbSpTrkVtxMh_hip_trk180_L1TE50");
   HLTChains.push_back("EF_mbSpTrkVtxMh_hip_trk200_L1TE65");
   HLTChains.push_back("EF_mbSpTrkVtxMh_hip_trk225_L1TE65");
   HLTChains.push_back("EF_L1TE100_NoAlg");
   HLTChains.push_back("EF_L1TE90_NoAlg");
   HLTChains.push_back("EF_L1TE65_NoAlg");
   HLTChains.push_back("EF_L1TE50_NoAlg");

   L2Chains.push_back("L2_mbSpTrk");
   L2Chains.push_back("L2_mbMbts_1_1");
   L2Chains.push_back("L2_mbMbts_2");
   L2Chains.push_back("L2_L1MBTS_1_1_NoAlg");
   L2Chains.push_back("L2_L1ZDC_A_NoAlg");
   L2Chains.push_back("L2_L1ZDC_C_NoAlg");
   L2Chains.push_back("L2_mbSpTrkVtxMh_hip_trk100_L1TE10");
   L2Chains.push_back("L2_mbSpTrkVtxMh_hip_trk130_L1TE10");
   L2Chains.push_back("L2_mbSpTrkVtxMh_hip_trk150_L1TE50");
   L2Chains.push_back("L2_mbSpTrkVtxMh_hip_trk180_L1TE50");
   L2Chains.push_back("L2_mbSpTrkVtxMh_hip_trk200_L1TE65");
   L2Chains.push_back("L2_mbSpTrkVtxMh_hip_trk225_L1TE65");
   L2Chains.push_back("L2_L1TE100_NoAlg");
   L2Chains.push_back("L2_L1TE90_NoAlg");
   L2Chains.push_back("L2_L1TE65_NoAlg");
   L2Chains.push_back("L2_L1TE50_NoAlg");

   L1Names.push_back("L1_RD0_FILLED");
   L1Names.push_back("L1_MBTS_1_1");
   L1Names.push_back("L1_MBTS_2");
   L1Names.push_back("L1_MBTS_1_1");
   L1Names.push_back("L1_ZDC_A");
   L1Names.push_back("L1_ZDC_C");
   L1Names.push_back("L1_TE10");
   L1Names.push_back("L1_TE10");
   L1Names.push_back("L1_TE50");
   L1Names.push_back("L1_TE50");
   L1Names.push_back("L1_TE65");
   L1Names.push_back("L1_TE65");
   L1Names.push_back("L1_TE100");
   L1Names.push_back("L1_TE90");
   L1Names.push_back("L1_TE65");
   L1Names.push_back("L1_TE50");

   NTRIG = HLTChains.size();

   EFPrescales = new std::vector<float>(NTRIG, -1);
   L2Prescales = new std::vector<float>(NTRIG, -1);
   L1Prescales = new std::vector<float>(NTRIG, -1);
   Prescales   = new std::vector<float>(NTRIG, -1);

   metaEntryOld = -1;

   L1NameMap = 0;
   HLTNameMap = 0;
   L1PrescaleMap = 0;
   HLTPrescaleMap = 0;

   if (!tree) return;
   fChainMeta = tree;

   fChainMeta->SetBranchAddress("SMK", &SMK);
   fChainMeta->SetBranchAddress("L1PSK", &L1PSK);
   fChainMeta->SetBranchAddress("HLTPSK", &HLTPSK);
   fChainMeta->SetBranchAddress("LVL1NameMap", &L1NameMap);
   fChainMeta->SetBranchAddress("HLTNameMap", &HLTNameMap);
   fChainMeta->SetBranchAddress("LVL1PrescaleMap", &L1PrescaleMap);
   fChainMeta->SetBranchAddress("HLTPrescaleMap", &HLTPrescaleMap);

   int nenMeta = fChainMeta->GetEntries();

   dBKeys.clear();

   for (int ien=0; ien<nenMeta; ien++) {

      std::vector<Int_t> dBKeysTemp;
      fChainMeta->GetEntry(ien);

      dBKeysTemp.push_back(SMK);
      dBKeysTemp.push_back(L1PSK);
      dBKeysTemp.push_back(HLTPSK);

      dBKeys.push_back(dBKeysTemp);

      std::cout << "dBen = " << ien << ": SMK = " << SMK << ", " << dBKeys.at(ien).at(0) << ": L1PSK = " << L1PSK << ", " << dBKeys.at(ien).at(1) << ": HLTPSK = " << dBKeys.at(ien).at(2) << std::endl;
   }
}
#endif // #ifdef extractor_cxx
