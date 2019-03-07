#ifndef extractor_h
#define extractor_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2D.h>
#include <TH1D.h>
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


      Int_t    trigs_MB, trigs_HMT;
      Bool_t   is_MinBias;
      Bool_t   is_HMT;

      Int_t     Mytrk_n;
      Float_t   Mytrk_eta        [MAXTRK];
      Float_t   Mytrk_pt         [MAXTRK];
      Float_t   Mytrk_phi        [MAXTRK];
      UInt_t    Mytrk_Quality    [MAXTRK];
      Bool_t    Mytrk_charge     [MAXTRK];

      Int_t    Myvx_n;
      Float_t  Myvx_x    [MAXVTX],Myvx_y    [MAXVTX],Myvx_z    [MAXVTX];
      Float_t  Myvx_sumPt[MAXVTX];

      Bool_t   is_pileup;
      Bool_t   is_pileupZDC;

      float Fcal_Et;
      float Fcal_Et_p;
      float Fcal_Et_n;
      int    Centrality;

      TTree          *fChain;   //!pointer to the analyzed TTree or TChain
      Int_t           fCurrent; //!current Tree number in a TChain

      // Declaration of leaf types
      UInt_t          RunNumber;
      UInt_t          EventNumber;
      UInt_t          timestamp;
      UInt_t          timestamp_ns;
      UInt_t          lbn;
      UInt_t          bcid;
      UInt_t          detmask0;
      UInt_t          detmask1;
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
      Int_t           pixClus_n;
      vector<unsigned int> *pixClus_id;
      vector<char>    *pixClus_bec;
      vector<char>    *pixClus_layer;
      vector<unsigned int> *pixClus_detElementId;
      vector<char>    *pixClus_phi_module;
      vector<char>    *pixClus_eta_module;
      vector<short>   *pixClus_col;
      vector<short>   *pixClus_row;
      vector<float>   *pixClus_charge;
      vector<short>   *pixClus_LVL1A;
      vector<int>     *pixClus_sizePhi;
      vector<int>     *pixClus_sizeZ;
      vector<int>     *pixClus_size;
      vector<float>   *pixClus_locX;
      vector<float>   *pixClus_locY;
      vector<float>   *pixClus_x;
      vector<float>   *pixClus_y;
      vector<float>   *pixClus_z;
      vector<char>    *pixClus_isFake;
      vector<char>    *pixClus_isGanged;
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
      Int_t           TotalEt_n;
      vector<float>   *TotalEt_tower_eta;
      vector<float>   *TotalEt_tower_phi;
      vector<vector<float> > *TotalEt_tower_area;
      vector<vector<float> > *TotalEt_tower_sampling;
      vector<vector<float> > *TotalEt_tower_sampling_calib;
      vector<float>   *TotalEt_layer_eta;
      vector<float>   *TotalEt_layer_phi;
      vector<vector<float> > *TotalEt_layer_area;
      vector<vector<float> > *TotalEt_layer_sampling;
      vector<vector<float> > *TotalEt_layer_sampling_calib;
      Int_t           trk_n;
      vector<float>   *trk_pt;
      vector<float>   *trk_eta;
      vector<float>   *trk_d0_wrtPV;
      vector<float>   *trk_err_d0_wrtPV;
      vector<float>   *trk_z0_wrtPV;
      vector<float>   *trk_err_z0_wrtPV;
      vector<float>   *trk_phi_wrtPV;
      vector<float>   *trk_theta;
      vector<float>   *trk_err_theta_wrtPV;
      vector<float>   *trk_qoverp;
      vector<float>   *trk_cov_z0_theta_wrtPV;
      vector<float>   *trk_cov_d0_wrtPV;
      vector<float>   *trk_cov_z0_wrtPV;
      vector<float>   *trk_cov_phi_wrtPV;
      vector<float>   *trk_cov_theta_wrtPV;
      vector<float>   *trk_cov_qoverp_wrtPV;
      vector<float>   *trk_chi2;
      vector<int>     *trk_ndof;
      vector<int>     *trk_nBLHits;
      vector<int>     *trk_nPixHits;
      vector<int>     *trk_nSCTHits;
      vector<int>     *trk_nTRTHits;
      vector<int>     *trk_nPixHoles;
      vector<int>     *trk_nSCTHoles;
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
      vector<float>   *trk_pixeldEdx;
      vector<int>     *trk_fitter;
      vector<int>     *trk_patternReco1;
      vector<int>     *trk_patternReco2;
      vector<int>     *trk_seedFinder;
      vector<int>     *trk_expectBLayerHit;
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
      Int_t           pTrklets_n;
      vector<int>     *pTrklets_nBPixClus;
      vector<int>     *pTrklets_n1PixClus;
      vector<int>     *pTrklets_n2PixClus;
      vector<int>     *pTrklets_layerSum;
      vector<float>   *pTrklets_eta;
      vector<float>   *pTrklets_phi;
      vector<float>   *pTrklets_pt;
      vector<float>   *pTrklets_deta;
      vector<float>   *pTrklets_dphi;
      vector<float>   *pTrklets_etaS;
      vector<float>   *pTrklets_phiS;
      vector<float>   *pTrklets_energy0;
      vector<float>   *pTrklets_energy1;
      vector<int>     *pTrklets_cSize0;
      vector<int>     *pTrklets_cSize1;
      vector<float>   *pTrklets_cRowSize0;
      vector<float>   *pTrklets_cRowSize1;
      vector<float>   *pTrklets_cColSize0;
      vector<float>   *pTrklets_cColSize1;
      vector<vector<unsigned int> > *pTrklets_clusIds;
      Int_t           trkPix_n;
      vector<float>   *trkPix_pt;
      vector<float>   *trkPix_eta;
      vector<float>   *trkPix_d0_wrtPV;
      vector<float>   *trkPix_z0_wrtPV;
      vector<float>   *trkPix_phi_wrtPV;
      vector<float>   *trkPix_theta_wrtPV;
      vector<float>   *trkPix_qoverp_wrtPV;
      vector<float>   *trkPix_cov_d0_wrtPV;
      vector<float>   *trkPix_cov_z0_wrtPV;
      vector<float>   *trkPix_cov_phi_wrtPV;
      vector<float>   *trkPix_cov_theta_wrtPV;
      vector<float>   *trkPix_cov_qoverp_wrtPV;
      vector<float>   *trkPix_chi2;
      vector<int>     *trkPix_ndof;
      vector<int>     *trkPix_nBLHits;
      vector<int>     *trkPix_nPixHits;
      vector<int>     *trkPix_nSCTHits;
      vector<int>     *trkPix_nTRTHits;
      vector<int>     *trkPix_nPixHoles;
      vector<int>     *trkPix_nSCTHoles;
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
      vector<float>   *trkPix_pixeldEdx;
      vector<int>     *trkPix_fitter;
      vector<int>     *trkPix_patternReco1;
      vector<int>     *trkPix_patternReco2;
      vector<int>     *trkPix_seedFinder;
      vector<int>     *trkPix_blayerPrediction_expectHit;
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
      vector<vector<float> > *antikt4Tow_tower_CaloBkgrEt;
      vector<vector<float> > *antikt4Tow_tower_CaloBkgrRMS;
      vector<vector<int> > *antikt4Tow_tower_CaloBkgrCounts;
      vector<float>   *antikt4Tow_tower_CaloBkgrEta;
      vector<vector<float> > *antikt4Tow_layer_CaloBkgrEt;
      vector<vector<float> > *antikt4Tow_layer_CaloBkgrRMS;
      vector<vector<int> > *antikt4Tow_layer_CaloBkgrCounts;
      vector<float>   *antikt4Tow_layer_CaloBkgrEta;
      vector<vector<float> > *antikt4FlowTow_tower_CaloBkgrEt;
      vector<vector<float> > *antikt4FlowTow_tower_CaloBkgrRMS;
      vector<vector<int> > *antikt4FlowTow_tower_CaloBkgrCounts;
      vector<float>   *antikt4FlowTow_tower_CaloBkgrEta;
      vector<vector<float> > *antikt4FlowTow_layer_CaloBkgrEt;
      vector<vector<float> > *antikt4FlowTow_layer_CaloBkgrRMS;
      vector<vector<int> > *antikt4FlowTow_layer_CaloBkgrCounts;
      vector<float>   *antikt4FlowTow_layer_CaloBkgrEta;
      vector<vector<float> > *antikt4EMTow_tower_CaloBkgrEt;
      vector<vector<float> > *antikt4EMTow_tower_CaloBkgrRMS;
      vector<vector<int> > *antikt4EMTow_tower_CaloBkgrCounts;
      vector<float>   *antikt4EMTow_tower_CaloBkgrEta;
      vector<vector<float> > *antikt4EMTow_layer_CaloBkgrEt;
      vector<vector<float> > *antikt4EMTow_layer_CaloBkgrRMS;
      vector<vector<int> > *antikt4EMTow_layer_CaloBkgrCounts;
      vector<float>   *antikt4EMTow_layer_CaloBkgrEta;
      vector<vector<float> > *AvgTower_tower_CaloBkgrEt;
      vector<vector<float> > *AvgTower_tower_CaloBkgrRMS;
      vector<vector<int> > *AvgTower_tower_CaloBkgrCounts;
      vector<float>   *AvgTower_tower_CaloBkgrEta;
      vector<vector<float> > *AvgTower_layer_CaloBkgrEt;
      vector<vector<float> > *AvgTower_layer_CaloBkgrRMS;
      vector<vector<int> > *AvgTower_layer_CaloBkgrCounts;
      vector<float>   *AvgTower_layer_CaloBkgrEta;
      vector<vector<float> > *AvgTower3Sigma_tower_CaloBkgrEt;
      vector<vector<float> > *AvgTower3Sigma_tower_CaloBkgrRMS;
      vector<vector<int> > *AvgTower3Sigma_tower_CaloBkgrCounts;
      vector<float>   *AvgTower3Sigma_tower_CaloBkgrEta;
      vector<vector<float> > *AvgTower4Sigma_tower_CaloBkgrEt;
      vector<vector<float> > *AvgTower4Sigma_tower_CaloBkgrRMS;
      vector<vector<int> > *AvgTower4Sigma_tower_CaloBkgrCounts;
      vector<float>   *AvgTower4Sigma_tower_CaloBkgrEta;
      vector<vector<float> > *AvgTowerFlow_tower_CaloBkgrEt;
      vector<vector<float> > *AvgTowerFlow_tower_CaloBkgrRMS;
      vector<vector<int> > *AvgTowerFlow_tower_CaloBkgrCounts;
      vector<float>   *AvgTowerFlow_tower_CaloBkgrEta;
      vector<vector<float> > *AvgTowerFlow_layer_CaloBkgrEt;
      vector<vector<float> > *AvgTowerFlow_layer_CaloBkgrRMS;
      vector<vector<int> > *AvgTowerFlow_layer_CaloBkgrCounts;
      vector<float>   *AvgTowerFlow_layer_CaloBkgrEta;
      vector<vector<float> > *antikt4TowItr_tower_CaloBkgrEt;
      vector<vector<float> > *antikt4TowItr_tower_CaloBkgrRMS;
      vector<vector<int> > *antikt4TowItr_tower_CaloBkgrCounts;
      vector<float>   *antikt4TowItr_tower_CaloBkgrEta;
      vector<vector<float> > *antikt4TowItr_layer_CaloBkgrEt;
      vector<vector<float> > *antikt4TowItr_layer_CaloBkgrRMS;
      vector<vector<int> > *antikt4TowItr_layer_CaloBkgrCounts;
      vector<float>   *antikt4TowItr_layer_CaloBkgrEta;
      vector<vector<float> > *antikt4TowFlowItr_tower_CaloBkgrEt;
      vector<vector<float> > *antikt4TowFlowItr_tower_CaloBkgrRMS;
      vector<vector<int> > *antikt4TowFlowItr_tower_CaloBkgrCounts;
      vector<float>   *antikt4TowFlowItr_tower_CaloBkgrEta;
      vector<vector<float> > *antikt4TowFlowItr_layer_CaloBkgrEt;
      vector<vector<float> > *antikt4TowFlowItr_layer_CaloBkgrRMS;
      vector<vector<int> > *antikt4TowFlowItr_layer_CaloBkgrCounts;
      vector<float>   *antikt4TowFlowItr_layer_CaloBkgrEta;
      Int_t           antikt4HI_n;
      vector<float>   *antikt4HI_E;
      vector<float>   *antikt4HI_pt;
      vector<float>   *antikt4HI_m;
      vector<float>   *antikt4HI_eta;
      vector<float>   *antikt4HI_phi;
      vector<float>   *antikt4HI_MaxOverMean;
      vector<float>   *antikt4HI_MeanTowerEt;
      vector<float>   *antikt4HI_SubtractedEt;
      vector<float>   *antikt4HI_RMSTowerEt;
      vector<float>   *antikt4HI_SumJt;
      vector<float>   *antikt4HI_CoreEt;
      vector<float>   *antikt4HI_EdgeEt;
      vector<float>   *antikt4HI_CryoCorr;
      vector<float>   *antikt4HI_NoFlow;
      vector<float>   *antikt4HI_NumConstituents;
      vector<float>   *antikt4HI_UncalibEt;
      vector<float>   *antikt4HI_Discriminant;
      vector<float>   *antikt4HI_MeanTowerEtUnsubtr;
      vector<float>   *antikt4HI_n90;
      vector<float>   *antikt4HI_fracSamplingMax;
      vector<float>   *antikt4HI_SamplingMax;
      vector<float>   *antikt4HI_n90constituents;
      vector<float>   *antikt4HI_Timing;
      vector<float>   *antikt4HI_LArQuality;
      vector<float>   *antikt4HI_HECQuality;
      vector<float>   *antikt4HI_TileQuality;
      vector<int>     *antikt4HI_const_n;
      vector<vector<float> > *antikt4HI_const_et;
      vector<vector<float> > *antikt4HI_const_eta;
      vector<vector<float> > *antikt4HI_const_phi;
      vector<vector<float> > *antikt4HI_sampling_et;
      vector<vector<float> > *antikt4HI_sampling_et_unsubtr;
      vector<vector<int> > *antikt4HI_bad_cell_n;
      vector<vector<float> > *antikt4HI_bad_cell_et;
      vector<vector<float> > *antikt4HI_bad_cell_area;
      vector<vector<int> > *antikt4HI_empty_cell_n;
      vector<vector<float> > *antikt4HI_empty_cell_et;
      vector<vector<float> > *antikt4HI_empty_cell_area;
      vector<vector<int> > *antikt4HI_total_cell_n;
      vector<vector<float> > *antikt4HI_total_cell_et;
      vector<vector<float> > *antikt4HI_total_cell_area;
      Int_t           antikt4HIFlow_n;
      vector<float>   *antikt4HIFlow_E;
      vector<float>   *antikt4HIFlow_pt;
      vector<float>   *antikt4HIFlow_m;
      vector<float>   *antikt4HIFlow_eta;
      vector<float>   *antikt4HIFlow_phi;
      vector<float>   *antikt4HIFlow_MaxOverMean;
      vector<float>   *antikt4HIFlow_MeanTowerEt;
      vector<float>   *antikt4HIFlow_SubtractedEt;
      vector<float>   *antikt4HIFlow_RMSTowerEt;
      vector<float>   *antikt4HIFlow_SumJt;
      vector<float>   *antikt4HIFlow_CoreEt;
      vector<float>   *antikt4HIFlow_EdgeEt;
      vector<float>   *antikt4HIFlow_CryoCorr;
      vector<float>   *antikt4HIFlow_NoFlow;
      vector<float>   *antikt4HIFlow_NumConstituents;
      vector<float>   *antikt4HIFlow_UncalibEt;
      vector<float>   *antikt4HIFlow_Discriminant;
      vector<float>   *antikt4HIFlow_MeanTowerEtUnsubtr;
      vector<float>   *antikt4HIFlow_n90;
      vector<float>   *antikt4HIFlow_fracSamplingMax;
      vector<float>   *antikt4HIFlow_SamplingMax;
      vector<float>   *antikt4HIFlow_n90constituents;
      vector<float>   *antikt4HIFlow_Timing;
      vector<float>   *antikt4HIFlow_LArQuality;
      vector<float>   *antikt4HIFlow_HECQuality;
      vector<float>   *antikt4HIFlow_TileQuality;
      vector<int>     *antikt4HIFlow_const_n;
      vector<vector<float> > *antikt4HIFlow_const_et;
      vector<vector<float> > *antikt4HIFlow_const_eta;
      vector<vector<float> > *antikt4HIFlow_const_phi;
      vector<vector<float> > *antikt4HIFlow_sampling_et;
      vector<vector<float> > *antikt4HIFlow_sampling_et_unsubtr;
      vector<vector<int> > *antikt4HIFlow_bad_cell_n;
      vector<vector<float> > *antikt4HIFlow_bad_cell_et;
      vector<vector<float> > *antikt4HIFlow_bad_cell_area;
      vector<vector<int> > *antikt4HIFlow_empty_cell_n;
      vector<vector<float> > *antikt4HIFlow_empty_cell_et;
      vector<vector<float> > *antikt4HIFlow_empty_cell_area;
      vector<vector<int> > *antikt4HIFlow_total_cell_n;
      vector<vector<float> > *antikt4HIFlow_total_cell_et;
      vector<vector<float> > *antikt4HIFlow_total_cell_area;
      Int_t           antikt4HIAvgFlow_n;
      vector<float>   *antikt4HIAvgFlow_E;
      vector<float>   *antikt4HIAvgFlow_pt;
      vector<float>   *antikt4HIAvgFlow_m;
      vector<float>   *antikt4HIAvgFlow_eta;
      vector<float>   *antikt4HIAvgFlow_phi;
      vector<float>   *antikt4HIAvgFlow_MaxOverMean;
      vector<float>   *antikt4HIAvgFlow_MeanTowerEt;
      vector<float>   *antikt4HIAvgFlow_SubtractedEt;
      vector<float>   *antikt4HIAvgFlow_RMSTowerEt;
      vector<float>   *antikt4HIAvgFlow_SumJt;
      vector<float>   *antikt4HIAvgFlow_CoreEt;
      vector<float>   *antikt4HIAvgFlow_EdgeEt;
      vector<float>   *antikt4HIAvgFlow_CryoCorr;
      vector<float>   *antikt4HIAvgFlow_NoFlow;
      vector<float>   *antikt4HIAvgFlow_NumConstituents;
      vector<float>   *antikt4HIAvgFlow_UncalibEt;
      vector<float>   *antikt4HIAvgFlow_Discriminant;
      vector<float>   *antikt4HIAvgFlow_MeanTowerEtUnsubtr;
      vector<float>   *antikt4HIAvgFlow_n90;
      vector<float>   *antikt4HIAvgFlow_fracSamplingMax;
      vector<float>   *antikt4HIAvgFlow_SamplingMax;
      vector<float>   *antikt4HIAvgFlow_n90constituents;
      vector<float>   *antikt4HIAvgFlow_Timing;
      vector<float>   *antikt4HIAvgFlow_LArQuality;
      vector<float>   *antikt4HIAvgFlow_HECQuality;
      vector<float>   *antikt4HIAvgFlow_TileQuality;
      vector<int>     *antikt4HIAvgFlow_const_n;
      vector<vector<float> > *antikt4HIAvgFlow_const_et;
      vector<vector<float> > *antikt4HIAvgFlow_const_eta;
      vector<vector<float> > *antikt4HIAvgFlow_const_phi;
      vector<vector<float> > *antikt4HIAvgFlow_sampling_et;
      vector<vector<float> > *antikt4HIAvgFlow_sampling_et_unsubtr;
      vector<vector<int> > *antikt4HIAvgFlow_bad_cell_n;
      vector<vector<float> > *antikt4HIAvgFlow_bad_cell_et;
      vector<vector<float> > *antikt4HIAvgFlow_bad_cell_area;
      vector<vector<int> > *antikt4HIAvgFlow_empty_cell_n;
      vector<vector<float> > *antikt4HIAvgFlow_empty_cell_et;
      vector<vector<float> > *antikt4HIAvgFlow_empty_cell_area;
      vector<vector<int> > *antikt4HIAvgFlow_total_cell_n;
      vector<vector<float> > *antikt4HIAvgFlow_total_cell_et;
      vector<vector<float> > *antikt4HIAvgFlow_total_cell_area;
      Int_t           antikt4HIItr_n;
      vector<float>   *antikt4HIItr_E;
      vector<float>   *antikt4HIItr_pt;
      vector<float>   *antikt4HIItr_m;
      vector<float>   *antikt4HIItr_eta;
      vector<float>   *antikt4HIItr_phi;
      vector<float>   *antikt4HIItr_MaxOverMean;
      vector<float>   *antikt4HIItr_MeanTowerEt;
      vector<float>   *antikt4HIItr_SubtractedEt;
      vector<float>   *antikt4HIItr_RMSTowerEt;
      vector<float>   *antikt4HIItr_SumJt;
      vector<float>   *antikt4HIItr_CoreEt;
      vector<float>   *antikt4HIItr_EdgeEt;
      vector<float>   *antikt4HIItr_CryoCorr;
      vector<float>   *antikt4HIItr_NoFlow;
      vector<float>   *antikt4HIItr_NumConstituents;
      vector<float>   *antikt4HIItr_UncalibEt;
      vector<float>   *antikt4HIItr_Discriminant;
      vector<float>   *antikt4HIItr_MeanTowerEtUnsubtr;
      vector<float>   *antikt4HIItr_n90;
      vector<float>   *antikt4HIItr_fracSamplingMax;
      vector<float>   *antikt4HIItr_SamplingMax;
      vector<float>   *antikt4HIItr_n90constituents;
      vector<float>   *antikt4HIItr_Timing;
      vector<float>   *antikt4HIItr_LArQuality;
      vector<float>   *antikt4HIItr_HECQuality;
      vector<float>   *antikt4HIItr_TileQuality;
      vector<int>     *antikt4HIItr_const_n;
      vector<vector<float> > *antikt4HIItr_const_et;
      vector<vector<float> > *antikt4HIItr_const_eta;
      vector<vector<float> > *antikt4HIItr_const_phi;
      vector<vector<float> > *antikt4HIItr_sampling_et;
      vector<vector<float> > *antikt4HIItr_sampling_et_unsubtr;
      vector<vector<int> > *antikt4HIItr_bad_cell_n;
      vector<vector<float> > *antikt4HIItr_bad_cell_et;
      vector<vector<float> > *antikt4HIItr_bad_cell_area;
      vector<vector<int> > *antikt4HIItr_empty_cell_n;
      vector<vector<float> > *antikt4HIItr_empty_cell_et;
      vector<vector<float> > *antikt4HIItr_empty_cell_area;
      vector<vector<int> > *antikt4HIItr_total_cell_n;
      vector<vector<float> > *antikt4HIItr_total_cell_et;
      vector<vector<float> > *antikt4HIItr_total_cell_area;
      Int_t           antikt4HIItrFlow_n;
      vector<float>   *antikt4HIItrFlow_E;
      vector<float>   *antikt4HIItrFlow_pt;
      vector<float>   *antikt4HIItrFlow_m;
      vector<float>   *antikt4HIItrFlow_eta;
      vector<float>   *antikt4HIItrFlow_phi;
      vector<float>   *antikt4HIItrFlow_MaxOverMean;
      vector<float>   *antikt4HIItrFlow_MeanTowerEt;
      vector<float>   *antikt4HIItrFlow_SubtractedEt;
      vector<float>   *antikt4HIItrFlow_RMSTowerEt;
      vector<float>   *antikt4HIItrFlow_SumJt;
      vector<float>   *antikt4HIItrFlow_CoreEt;
      vector<float>   *antikt4HIItrFlow_EdgeEt;
      vector<float>   *antikt4HIItrFlow_CryoCorr;
      vector<float>   *antikt4HIItrFlow_NoFlow;
      vector<float>   *antikt4HIItrFlow_NumConstituents;
      vector<float>   *antikt4HIItrFlow_UncalibEt;
      vector<float>   *antikt4HIItrFlow_Discriminant;
      vector<float>   *antikt4HIItrFlow_MeanTowerEtUnsubtr;
      vector<float>   *antikt4HIItrFlow_n90;
      vector<float>   *antikt4HIItrFlow_fracSamplingMax;
      vector<float>   *antikt4HIItrFlow_SamplingMax;
      vector<float>   *antikt4HIItrFlow_n90constituents;
      vector<float>   *antikt4HIItrFlow_Timing;
      vector<float>   *antikt4HIItrFlow_LArQuality;
      vector<float>   *antikt4HIItrFlow_HECQuality;
      vector<float>   *antikt4HIItrFlow_TileQuality;
      vector<int>     *antikt4HIItrFlow_const_n;
      vector<vector<float> > *antikt4HIItrFlow_const_et;
      vector<vector<float> > *antikt4HIItrFlow_const_eta;
      vector<vector<float> > *antikt4HIItrFlow_const_phi;
      vector<vector<float> > *antikt4HIItrFlow_sampling_et;
      vector<vector<float> > *antikt4HIItrFlow_sampling_et_unsubtr;
      vector<vector<int> > *antikt4HIItrFlow_bad_cell_n;
      vector<vector<float> > *antikt4HIItrFlow_bad_cell_et;
      vector<vector<float> > *antikt4HIItrFlow_bad_cell_area;
      vector<vector<int> > *antikt4HIItrFlow_empty_cell_n;
      vector<vector<float> > *antikt4HIItrFlow_empty_cell_et;
      vector<vector<float> > *antikt4HIItrFlow_empty_cell_area;
      vector<vector<int> > *antikt4HIItrFlow_total_cell_n;
      vector<vector<float> > *antikt4HIItrFlow_total_cell_et;
      vector<vector<float> > *antikt4HIItrFlow_total_cell_area;
      Int_t           antikt2HIAvg_n;
      vector<float>   *antikt2HIAvg_E;
      vector<float>   *antikt2HIAvg_pt;
      vector<float>   *antikt2HIAvg_m;
      vector<float>   *antikt2HIAvg_eta;
      vector<float>   *antikt2HIAvg_phi;
      vector<float>   *antikt2HIAvg_MaxOverMean;
      vector<float>   *antikt2HIAvg_MeanTowerEt;
      vector<float>   *antikt2HIAvg_SubtractedEt;
      vector<float>   *antikt2HIAvg_RMSTowerEt;
      vector<float>   *antikt2HIAvg_SumJt;
      vector<float>   *antikt2HIAvg_CoreEt;
      vector<float>   *antikt2HIAvg_EdgeEt;
      vector<float>   *antikt2HIAvg_CryoCorr;
      vector<float>   *antikt2HIAvg_NoFlow;
      vector<float>   *antikt2HIAvg_NumConstituents;
      vector<float>   *antikt2HIAvg_UncalibEt;
      vector<float>   *antikt2HIAvg_Discriminant;
      vector<float>   *antikt2HIAvg_MeanTowerEtUnsubtr;
      vector<float>   *antikt2HIAvg_n90;
      vector<float>   *antikt2HIAvg_fracSamplingMax;
      vector<float>   *antikt2HIAvg_SamplingMax;
      vector<float>   *antikt2HIAvg_n90constituents;
      vector<float>   *antikt2HIAvg_Timing;
      vector<float>   *antikt2HIAvg_LArQuality;
      vector<float>   *antikt2HIAvg_HECQuality;
      vector<float>   *antikt2HIAvg_TileQuality;
      vector<int>     *antikt2HIAvg_const_n;
      vector<vector<float> > *antikt2HIAvg_const_et;
      vector<vector<float> > *antikt2HIAvg_const_eta;
      vector<vector<float> > *antikt2HIAvg_const_phi;
      vector<vector<float> > *antikt2HIAvg_sampling_et;
      vector<vector<float> > *antikt2HIAvg_sampling_et_unsubtr;
      vector<vector<int> > *antikt2HIAvg_bad_cell_n;
      vector<vector<float> > *antikt2HIAvg_bad_cell_et;
      vector<vector<float> > *antikt2HIAvg_bad_cell_area;
      vector<vector<int> > *antikt2HIAvg_empty_cell_n;
      vector<vector<float> > *antikt2HIAvg_empty_cell_et;
      vector<vector<float> > *antikt2HIAvg_empty_cell_area;
      vector<vector<int> > *antikt2HIAvg_total_cell_n;
      vector<vector<float> > *antikt2HIAvg_total_cell_et;
      vector<vector<float> > *antikt2HIAvg_total_cell_area;
      Int_t           antikt4HIAvg_n;
      vector<float>   *antikt4HIAvg_E;
      vector<float>   *antikt4HIAvg_pt;
      vector<float>   *antikt4HIAvg_m;
      vector<float>   *antikt4HIAvg_eta;
      vector<float>   *antikt4HIAvg_phi;
      vector<float>   *antikt4HIAvg_MaxOverMean;
      vector<float>   *antikt4HIAvg_MeanTowerEt;
      vector<float>   *antikt4HIAvg_SubtractedEt;
      vector<float>   *antikt4HIAvg_RMSTowerEt;
      vector<float>   *antikt4HIAvg_SumJt;
      vector<float>   *antikt4HIAvg_CoreEt;
      vector<float>   *antikt4HIAvg_EdgeEt;
      vector<float>   *antikt4HIAvg_CryoCorr;
      vector<float>   *antikt4HIAvg_NoFlow;
      vector<float>   *antikt4HIAvg_NumConstituents;
      vector<float>   *antikt4HIAvg_UncalibEt;
      vector<float>   *antikt4HIAvg_Discriminant;
      vector<float>   *antikt4HIAvg_MeanTowerEtUnsubtr;
      vector<float>   *antikt4HIAvg_n90;
      vector<float>   *antikt4HIAvg_fracSamplingMax;
      vector<float>   *antikt4HIAvg_SamplingMax;
      vector<float>   *antikt4HIAvg_n90constituents;
      vector<float>   *antikt4HIAvg_Timing;
      vector<float>   *antikt4HIAvg_LArQuality;
      vector<float>   *antikt4HIAvg_HECQuality;
      vector<float>   *antikt4HIAvg_TileQuality;
      vector<int>     *antikt4HIAvg_const_n;
      vector<vector<float> > *antikt4HIAvg_const_et;
      vector<vector<float> > *antikt4HIAvg_const_eta;
      vector<vector<float> > *antikt4HIAvg_const_phi;
      vector<vector<float> > *antikt4HIAvg_sampling_et;
      vector<vector<float> > *antikt4HIAvg_sampling_et_unsubtr;
      vector<vector<int> > *antikt4HIAvg_bad_cell_n;
      vector<vector<float> > *antikt4HIAvg_bad_cell_et;
      vector<vector<float> > *antikt4HIAvg_bad_cell_area;
      vector<vector<int> > *antikt4HIAvg_empty_cell_n;
      vector<vector<float> > *antikt4HIAvg_empty_cell_et;
      vector<vector<float> > *antikt4HIAvg_empty_cell_area;
      vector<vector<int> > *antikt4HIAvg_total_cell_n;
      vector<vector<float> > *antikt4HIAvg_total_cell_et;
      vector<vector<float> > *antikt4HIAvg_total_cell_area;
      Int_t           antikt6HIAvg_n;
      vector<float>   *antikt6HIAvg_E;
      vector<float>   *antikt6HIAvg_pt;
      vector<float>   *antikt6HIAvg_m;
      vector<float>   *antikt6HIAvg_eta;
      vector<float>   *antikt6HIAvg_phi;
      vector<float>   *antikt6HIAvg_MaxOverMean;
      vector<float>   *antikt6HIAvg_MeanTowerEt;
      vector<float>   *antikt6HIAvg_SubtractedEt;
      vector<float>   *antikt6HIAvg_RMSTowerEt;
      vector<float>   *antikt6HIAvg_SumJt;
      vector<float>   *antikt6HIAvg_CoreEt;
      vector<float>   *antikt6HIAvg_EdgeEt;
      vector<float>   *antikt6HIAvg_CryoCorr;
      vector<float>   *antikt6HIAvg_NoFlow;
      vector<float>   *antikt6HIAvg_NumConstituents;
      vector<float>   *antikt6HIAvg_UncalibEt;
      vector<float>   *antikt6HIAvg_Discriminant;
      vector<float>   *antikt6HIAvg_MeanTowerEtUnsubtr;
      vector<float>   *antikt6HIAvg_n90;
      vector<float>   *antikt6HIAvg_fracSamplingMax;
      vector<float>   *antikt6HIAvg_SamplingMax;
      vector<float>   *antikt6HIAvg_n90constituents;
      vector<float>   *antikt6HIAvg_Timing;
      vector<float>   *antikt6HIAvg_LArQuality;
      vector<float>   *antikt6HIAvg_HECQuality;
      vector<float>   *antikt6HIAvg_TileQuality;
      vector<int>     *antikt6HIAvg_const_n;
      vector<vector<float> > *antikt6HIAvg_const_et;
      vector<vector<float> > *antikt6HIAvg_const_eta;
      vector<vector<float> > *antikt6HIAvg_const_phi;
      vector<vector<float> > *antikt6HIAvg_sampling_et;
      vector<vector<float> > *antikt6HIAvg_sampling_et_unsubtr;
      vector<vector<int> > *antikt6HIAvg_bad_cell_n;
      vector<vector<float> > *antikt6HIAvg_bad_cell_et;
      vector<vector<float> > *antikt6HIAvg_bad_cell_area;
      vector<vector<int> > *antikt6HIAvg_empty_cell_n;
      vector<vector<float> > *antikt6HIAvg_empty_cell_et;
      vector<vector<float> > *antikt6HIAvg_empty_cell_area;
      vector<vector<int> > *antikt6HIAvg_total_cell_n;
      vector<vector<float> > *antikt6HIAvg_total_cell_et;
      vector<vector<float> > *antikt6HIAvg_total_cell_area;
      Int_t           antikt4HIEM_n;
      vector<float>   *antikt4HIEM_E;
      vector<float>   *antikt4HIEM_pt;
      vector<float>   *antikt4HIEM_m;
      vector<float>   *antikt4HIEM_eta;
      vector<float>   *antikt4HIEM_phi;
      vector<float>   *antikt4HIEM_MaxOverMean;
      vector<float>   *antikt4HIEM_MeanTowerEt;
      vector<float>   *antikt4HIEM_SubtractedEt;
      vector<float>   *antikt4HIEM_RMSTowerEt;
      vector<float>   *antikt4HIEM_SumJt;
      vector<float>   *antikt4HIEM_CoreEt;
      vector<float>   *antikt4HIEM_EdgeEt;
      vector<float>   *antikt4HIEM_CryoCorr;
      vector<float>   *antikt4HIEM_NoFlow;
      vector<float>   *antikt4HIEM_NumConstituents;
      vector<float>   *antikt4HIEM_UncalibEt;
      vector<float>   *antikt4HIEM_Discriminant;
      vector<float>   *antikt4HIEM_MeanTowerEtUnsubtr;
      vector<float>   *antikt4HIEM_n90;
      vector<float>   *antikt4HIEM_fracSamplingMax;
      vector<float>   *antikt4HIEM_SamplingMax;
      vector<float>   *antikt4HIEM_n90constituents;
      vector<float>   *antikt4HIEM_Timing;
      vector<float>   *antikt4HIEM_LArQuality;
      vector<float>   *antikt4HIEM_HECQuality;
      vector<float>   *antikt4HIEM_TileQuality;
      vector<int>     *antikt4HIEM_const_n;
      vector<vector<float> > *antikt4HIEM_const_et;
      vector<vector<float> > *antikt4HIEM_const_eta;
      vector<vector<float> > *antikt4HIEM_const_phi;
      vector<vector<float> > *antikt4HIEM_sampling_et;
      vector<vector<float> > *antikt4HIEM_sampling_et_unsubtr;
      vector<vector<int> > *antikt4HIEM_bad_cell_n;
      vector<vector<float> > *antikt4HIEM_bad_cell_et;
      vector<vector<float> > *antikt4HIEM_bad_cell_area;
      vector<vector<int> > *antikt4HIEM_empty_cell_n;
      vector<vector<float> > *antikt4HIEM_empty_cell_et;
      vector<vector<float> > *antikt4HIEM_empty_cell_area;
      vector<vector<int> > *antikt4HIEM_total_cell_n;
      vector<vector<float> > *antikt4HIEM_total_cell_et;
      vector<vector<float> > *antikt4HIEM_total_cell_area;
      Int_t           jetSeed_n;
      vector<float>   *jetSeed_E;
      vector<float>   *jetSeed_pt;
      vector<float>   *jetSeed_m;
      vector<float>   *jetSeed_eta;
      vector<float>   *jetSeed_phi;
      Int_t           jetSeed3Sigma_n;
      vector<float>   *jetSeed3Sigma_E;
      vector<float>   *jetSeed3Sigma_pt;
      vector<float>   *jetSeed3Sigma_m;
      vector<float>   *jetSeed3Sigma_eta;
      vector<float>   *jetSeed3Sigma_phi;
      Int_t           jetSeed4Sigma_n;
      vector<float>   *jetSeed4Sigma_E;
      vector<float>   *jetSeed4Sigma_pt;
      vector<float>   *jetSeed4Sigma_m;
      vector<float>   *jetSeed4Sigma_eta;
      vector<float>   *jetSeed4Sigma_phi;
      Int_t           cone2HI_n;
      vector<float>   *cone2HI_E;
      vector<float>   *cone2HI_pt;
      vector<float>   *cone2HI_m;
      vector<float>   *cone2HI_eta;
      vector<float>   *cone2HI_phi;
      vector<float>   *cone2HI_MaxOverMean;
      vector<float>   *cone2HI_MeanTowerEt;
      vector<float>   *cone2HI_SubtractedEt;
      vector<float>   *cone2HI_RMSTowerEt;
      vector<float>   *cone2HI_SumJt;
      vector<float>   *cone2HI_CoreEt;
      vector<float>   *cone2HI_EdgeEt;
      vector<float>   *cone2HI_CryoCorr;
      vector<float>   *cone2HI_NoFlow;
      vector<float>   *cone2HI_NumConstituents;
      vector<float>   *cone2HI_UncalibEt;
      vector<float>   *cone2HI_Discriminant;
      vector<float>   *cone2HI_MeanTowerEtUnsubtr;
      vector<float>   *cone2HI_n90;
      vector<float>   *cone2HI_fracSamplingMax;
      vector<float>   *cone2HI_SamplingMax;
      vector<float>   *cone2HI_n90constituents;
      vector<float>   *cone2HI_Timing;
      vector<float>   *cone2HI_LArQuality;
      vector<float>   *cone2HI_HECQuality;
      vector<float>   *cone2HI_TileQuality;
      vector<int>     *cone2HI_const_n;
      vector<vector<float> > *cone2HI_const_et;
      vector<vector<float> > *cone2HI_const_eta;
      vector<vector<float> > *cone2HI_const_phi;
      vector<vector<float> > *cone2HI_sampling_et;
      vector<vector<float> > *cone2HI_sampling_et_unsubtr;
      vector<vector<int> > *cone2HI_bad_cell_n;
      vector<vector<float> > *cone2HI_bad_cell_et;
      vector<vector<float> > *cone2HI_bad_cell_area;
      vector<vector<int> > *cone2HI_empty_cell_n;
      vector<vector<float> > *cone2HI_empty_cell_et;
      vector<vector<float> > *cone2HI_empty_cell_area;
      vector<vector<int> > *cone2HI_total_cell_n;
      vector<vector<float> > *cone2HI_total_cell_et;
      vector<vector<float> > *cone2HI_total_cell_area;
      Int_t           cone4HI_n;
      vector<float>   *cone4HI_E;
      vector<float>   *cone4HI_pt;
      vector<float>   *cone4HI_m;
      vector<float>   *cone4HI_eta;
      vector<float>   *cone4HI_phi;
      vector<float>   *cone4HI_MaxOverMean;
      vector<float>   *cone4HI_MeanTowerEt;
      vector<float>   *cone4HI_SubtractedEt;
      vector<float>   *cone4HI_RMSTowerEt;
      vector<float>   *cone4HI_SumJt;
      vector<float>   *cone4HI_CoreEt;
      vector<float>   *cone4HI_EdgeEt;
      vector<float>   *cone4HI_CryoCorr;
      vector<float>   *cone4HI_NoFlow;
      vector<float>   *cone4HI_NumConstituents;
      vector<float>   *cone4HI_UncalibEt;
      vector<float>   *cone4HI_Discriminant;
      vector<float>   *cone4HI_MeanTowerEtUnsubtr;
      vector<float>   *cone4HI_n90;
      vector<float>   *cone4HI_fracSamplingMax;
      vector<float>   *cone4HI_SamplingMax;
      vector<float>   *cone4HI_n90constituents;
      vector<float>   *cone4HI_Timing;
      vector<float>   *cone4HI_LArQuality;
      vector<float>   *cone4HI_HECQuality;
      vector<float>   *cone4HI_TileQuality;
      vector<int>     *cone4HI_const_n;
      vector<vector<float> > *cone4HI_const_et;
      vector<vector<float> > *cone4HI_const_eta;
      vector<vector<float> > *cone4HI_const_phi;
      vector<vector<float> > *cone4HI_sampling_et;
      vector<vector<float> > *cone4HI_sampling_et_unsubtr;
      vector<vector<int> > *cone4HI_bad_cell_n;
      vector<vector<float> > *cone4HI_bad_cell_et;
      vector<vector<float> > *cone4HI_bad_cell_area;
      vector<vector<int> > *cone4HI_empty_cell_n;
      vector<vector<float> > *cone4HI_empty_cell_et;
      vector<vector<float> > *cone4HI_empty_cell_area;
      vector<vector<int> > *cone4HI_total_cell_n;
      vector<vector<float> > *cone4HI_total_cell_et;
      vector<vector<float> > *cone4HI_total_cell_area;
      Int_t           cone6HI_n;
      vector<float>   *cone6HI_E;
      vector<float>   *cone6HI_pt;
      vector<float>   *cone6HI_m;
      vector<float>   *cone6HI_eta;
      vector<float>   *cone6HI_phi;
      vector<float>   *cone6HI_MaxOverMean;
      vector<float>   *cone6HI_MeanTowerEt;
      vector<float>   *cone6HI_SubtractedEt;
      vector<float>   *cone6HI_RMSTowerEt;
      vector<float>   *cone6HI_SumJt;
      vector<float>   *cone6HI_CoreEt;
      vector<float>   *cone6HI_EdgeEt;
      vector<float>   *cone6HI_CryoCorr;
      vector<float>   *cone6HI_NoFlow;
      vector<float>   *cone6HI_NumConstituents;
      vector<float>   *cone6HI_UncalibEt;
      vector<float>   *cone6HI_Discriminant;
      vector<float>   *cone6HI_MeanTowerEtUnsubtr;
      vector<float>   *cone6HI_n90;
      vector<float>   *cone6HI_fracSamplingMax;
      vector<float>   *cone6HI_SamplingMax;
      vector<float>   *cone6HI_n90constituents;
      vector<float>   *cone6HI_Timing;
      vector<float>   *cone6HI_LArQuality;
      vector<float>   *cone6HI_HECQuality;
      vector<float>   *cone6HI_TileQuality;
      vector<int>     *cone6HI_const_n;
      vector<vector<float> > *cone6HI_const_et;
      vector<vector<float> > *cone6HI_const_eta;
      vector<vector<float> > *cone6HI_const_phi;
      vector<vector<float> > *cone6HI_sampling_et;
      vector<vector<float> > *cone6HI_sampling_et_unsubtr;
      vector<vector<int> > *cone6HI_bad_cell_n;
      vector<vector<float> > *cone6HI_bad_cell_et;
      vector<vector<float> > *cone6HI_bad_cell_area;
      vector<vector<int> > *cone6HI_empty_cell_n;
      vector<vector<float> > *cone6HI_empty_cell_et;
      vector<vector<float> > *cone6HI_empty_cell_area;
      vector<vector<int> > *cone6HI_total_cell_n;
      vector<vector<float> > *cone6HI_total_cell_et;
      vector<vector<float> > *cone6HI_total_cell_area;
      Int_t           CMSCone4HI_n;
      vector<float>   *CMSCone4HI_E;
      vector<float>   *CMSCone4HI_pt;
      vector<float>   *CMSCone4HI_m;
      vector<float>   *CMSCone4HI_eta;
      vector<float>   *CMSCone4HI_phi;
      vector<float>   *CMSCone4HI_MaxOverMean;
      vector<float>   *CMSCone4HI_MeanTowerEt;
      vector<float>   *CMSCone4HI_SubtractedEt;
      vector<float>   *CMSCone4HI_RMSTowerEt;
      vector<float>   *CMSCone4HI_SumJt;
      vector<float>   *CMSCone4HI_CoreEt;
      vector<float>   *CMSCone4HI_EdgeEt;
      vector<float>   *CMSCone4HI_CryoCorr;
      vector<float>   *CMSCone4HI_NoFlow;
      vector<float>   *CMSCone4HI_NumConstituents;
      vector<float>   *CMSCone4HI_UncalibEt;
      vector<float>   *CMSCone4HI_Discriminant;
      vector<float>   *CMSCone4HI_MeanTowerEtUnsubtr;
      vector<float>   *CMSCone4HI_n90;
      vector<float>   *CMSCone4HI_fracSamplingMax;
      vector<float>   *CMSCone4HI_SamplingMax;
      vector<float>   *CMSCone4HI_n90constituents;
      vector<float>   *CMSCone4HI_Timing;
      vector<float>   *CMSCone4HI_LArQuality;
      vector<float>   *CMSCone4HI_HECQuality;
      vector<float>   *CMSCone4HI_TileQuality;
      vector<int>     *CMSCone4HI_const_n;
      vector<vector<float> > *CMSCone4HI_const_et;
      vector<vector<float> > *CMSCone4HI_const_eta;
      vector<vector<float> > *CMSCone4HI_const_phi;
      vector<vector<float> > *CMSCone4HI_sampling_et;
      vector<vector<float> > *CMSCone4HI_sampling_et_unsubtr;
      vector<vector<int> > *CMSCone4HI_bad_cell_n;
      vector<vector<float> > *CMSCone4HI_bad_cell_et;
      vector<vector<float> > *CMSCone4HI_bad_cell_area;
      vector<vector<int> > *CMSCone4HI_empty_cell_n;
      vector<vector<float> > *CMSCone4HI_empty_cell_et;
      vector<vector<float> > *CMSCone4HI_empty_cell_area;
      vector<vector<int> > *CMSCone4HI_total_cell_n;
      vector<vector<float> > *CMSCone4HI_total_cell_et;
      vector<vector<float> > *CMSCone4HI_total_cell_area;
      Int_t           antikt4Track_n;
      vector<float>   *antikt4Track_E;
      vector<float>   *antikt4Track_pt;
      vector<float>   *antikt4Track_m;
      vector<float>   *antikt4Track_eta;
      vector<float>   *antikt4Track_phi;
      vector<int>     *antikt4Track_const_n;
      vector<vector<float> > *antikt4Track_const_pt;
      vector<vector<float> > *antikt4Track_const_eta;
      vector<vector<float> > *antikt4Track_const_phi;
      vector<vector<float> > *antikt4Track_const_chi2;
      vector<vector<float> > *antikt4Track_const_d0_wrtPV;
      vector<vector<float> > *antikt4Track_const_z0_wrtPV;
      vector<vector<float> > *antikt4Track_const_phi0_wrtPV;
      vector<vector<float> > *antikt4Track_const_theta_wrtPV;
      vector<vector<float> > *antikt4Track_const_qop;
      vector<vector<int> > *antikt4Track_const_ndof;
      vector<vector<int> > *antikt4Track_const_nBLayerHits;
      vector<vector<int> > *antikt4Track_const_nPixelHits;
      vector<vector<int> > *antikt4Track_const_nSCTHits;
      vector<vector<int> > *antikt4Track_const_nTRTHits;
      Int_t           antikt6Track_n;
      vector<float>   *antikt6Track_E;
      vector<float>   *antikt6Track_pt;
      vector<float>   *antikt6Track_m;
      vector<float>   *antikt6Track_eta;
      vector<float>   *antikt6Track_phi;
      vector<int>     *antikt6Track_const_n;
      vector<vector<float> > *antikt6Track_const_pt;
      vector<vector<float> > *antikt6Track_const_eta;
      vector<vector<float> > *antikt6Track_const_phi;
      vector<vector<float> > *antikt6Track_const_chi2;
      vector<vector<float> > *antikt6Track_const_d0_wrtPV;
      vector<vector<float> > *antikt6Track_const_z0_wrtPV;
      vector<vector<float> > *antikt6Track_const_phi0_wrtPV;
      vector<vector<float> > *antikt6Track_const_theta_wrtPV;
      vector<vector<float> > *antikt6Track_const_qop;
      vector<vector<int> > *antikt6Track_const_ndof;
      vector<vector<int> > *antikt6Track_const_nBLayerHits;
      vector<vector<int> > *antikt6Track_const_nPixelHits;
      vector<vector<int> > *antikt6Track_const_nSCTHits;
      vector<vector<int> > *antikt6Track_const_nTRTHits;
      Float_t         HICentrality_b_bin;
      Float_t         HICentrality_nw_bin;
      Float_t         HICentrality_ncoll_bin;
      Float_t         HICentrality_calocell_energy_bin;
      Float_t         HICentrality_number_of_siclusters_bin;
      Float_t         HICentrality_b_var;
      Float_t         HICentrality_nw_var;
      Float_t         HICentrality_ncoll_var;
      Float_t         HICentrality_calocell_energy_var;
      Float_t         HICentrality_number_of_siclusters_var;
      vector<float>   *HIFlow_PsiHICaloUtilLayers;
      vector<float>   *HIFlow_PsiEtHICaloUtilLayers;
      Float_t         HIFlow_PsiPtrack;
      Float_t         HIFlow_PsiNtrack;
      Float_t         HIFlow_v2EMB1sil;
      Float_t         HIFlow_v2FCAL0sil;
      Float_t         HIFlow_v2track;
      Float_t         HIFlow_PsiFCAL0_w;
      Float_t         HIFlow_PsiPFCAL0_w;
      Float_t         HIFlow_PsiNFCAL0_w;
      vector<float>   *HIFlow_Meanv2_Psi_From_EMB1CaloCel_IDLayers;
      vector<float>   *HIFlow_Meanv2_Psi_From_FCAL0CaloCel_IDLayers;
      vector<float>   *HIFlow_Meanv2Et_Psi_From_EMB1CaloCel_IDLayers;
      vector<float>   *HIFlow_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers;
      vector<float>   *HIFlow_v2Eta_Psi_From_EMBP1_InDet_EMBN1;
      vector<float>   *HIFlow_v2Eta_Psi_From_EMBN1_InDet_EMBP1;
      vector<float>   *HIFlow_v2Eta_Psi_From_EMBP1_InDet_FCALN0;
      vector<float>   *HIFlow_v2Eta_Psi_From_EMBN1_InDet_FCALP0;
      vector<float>   *HIFlow_v2Eta_Psi_From_FCALN0_InDet_EMBN1;
      vector<float>   *HIFlow_v2Eta_Psi_From_FCALP0_InDet_EMBP1;
      vector<float>   *HIFlow_v2Eta_Psi_From_FCALP0_InDet_FCALN0;
      vector<float>   *HIFlow_v2Eta_Psi_From_FCALN0_InDet_FCALP0;
      vector<float>   *HIFlow_v2EtaEt_Psi_From_EMBP1_InDet_EMBN1;
      vector<float>   *HIFlow_v2EtaEt_Psi_From_EMBN1_InDet_EMBP1;
      vector<float>   *HIFlow_v2EtaEt_Psi_From_EMBP1_InDet_FCALN0;
      vector<float>   *HIFlow_v2EtaEt_Psi_From_EMBN1_InDet_FCALP0;
      vector<float>   *HIFlow_v2EtaEt_Psi_From_FCALN0_InDet_EMBN1;
      vector<float>   *HIFlow_v2EtaEt_Psi_From_FCALP0_InDet_EMBP1;
      vector<float>   *HIFlow_v2EtaEt_Psi_From_FCALP0_InDet_FCALN0;
      vector<float>   *HIFlow_v2EtaEt_Psi_From_FCALN0_InDet_FCALP0;
      vector<float>   *HIFlow_EtaEMBN1;
      vector<float>   *HIFlow_EtaEMBP1;
      vector<float>   *HIFlow_EtaFCALN0;
      vector<float>   *HIFlow_EtaFCALP0;
      Int_t           emcl_n;
      vector<float>   *emcl_E;
      vector<float>   *emcl_pt;
      vector<float>   *emcl_m;
      vector<float>   *emcl_eta;
      vector<float>   *emcl_phi;
      vector<float>   *emcl_E_em;
      vector<float>   *emcl_E_had;
      Int_t           mu_staco_n;
      vector<float>   *mu_staco_E;
      vector<float>   *mu_staco_pt;
      vector<float>   *mu_staco_m;
      vector<float>   *mu_staco_eta;
      vector<float>   *mu_staco_phi;
      vector<float>   *mu_staco_px;
      vector<float>   *mu_staco_py;
      vector<float>   *mu_staco_pz;
      vector<float>   *mu_staco_charge;
      vector<unsigned short> *mu_staco_allauthor;
      vector<int>     *mu_staco_author;
      vector<float>   *mu_staco_matchchi2;
      vector<int>     *mu_staco_matchndof;
      vector<float>   *mu_staco_etcone20;
      vector<float>   *mu_staco_etcone30;
      vector<float>   *mu_staco_etcone40;
      vector<float>   *mu_staco_nucone20;
      vector<float>   *mu_staco_nucone30;
      vector<float>   *mu_staco_nucone40;
      vector<float>   *mu_staco_ptcone20;
      vector<float>   *mu_staco_ptcone30;
      vector<float>   *mu_staco_ptcone40;
      vector<float>   *mu_staco_energyLossPar;
      vector<float>   *mu_staco_energyLossErr;
      vector<float>   *mu_staco_etCore;
      vector<float>   *mu_staco_energyLossType;
      vector<int>     *mu_staco_bestMatch;
      vector<int>     *mu_staco_isStandAloneMuon;
      vector<int>     *mu_staco_isCombinedMuon;
      vector<int>     *mu_staco_isLowPtReconstructedMuon;
      vector<int>     *mu_staco_loose;
      vector<int>     *mu_staco_medium;
      vector<int>     *mu_staco_tight;
      vector<float>   *mu_staco_d0_exPV;
      vector<float>   *mu_staco_z0_exPV;
      vector<float>   *mu_staco_phi_exPV;
      vector<float>   *mu_staco_theta_exPV;
      vector<float>   *mu_staco_qoverp_exPV;
      vector<float>   *mu_staco_cb_d0_exPV;
      vector<float>   *mu_staco_cb_z0_exPV;
      vector<float>   *mu_staco_cb_phi_exPV;
      vector<float>   *mu_staco_cb_theta_exPV;
      vector<float>   *mu_staco_cb_qoverp_exPV;
      vector<float>   *mu_staco_id_d0_exPV;
      vector<float>   *mu_staco_id_z0_exPV;
      vector<float>   *mu_staco_id_phi_exPV;
      vector<float>   *mu_staco_id_theta_exPV;
      vector<float>   *mu_staco_id_qoverp_exPV;
      vector<float>   *mu_staco_me_d0_exPV;
      vector<float>   *mu_staco_me_z0_exPV;
      vector<float>   *mu_staco_me_phi_exPV;
      vector<float>   *mu_staco_me_theta_exPV;
      vector<float>   *mu_staco_me_qoverp_exPV;
      vector<float>   *mu_staco_ie_d0_exPV;
      vector<float>   *mu_staco_ie_z0_exPV;
      vector<float>   *mu_staco_ie_phi_exPV;
      vector<float>   *mu_staco_ie_theta_exPV;
      vector<float>   *mu_staco_ie_qoverp_exPV;
      vector<float>   *mu_staco_cov_d0_exPV;
      vector<float>   *mu_staco_cov_z0_exPV;
      vector<float>   *mu_staco_cov_phi_exPV;
      vector<float>   *mu_staco_cov_theta_exPV;
      vector<float>   *mu_staco_cov_qoverp_exPV;
      vector<float>   *mu_staco_cov_d0_z0_exPV;
      vector<float>   *mu_staco_cov_d0_phi_exPV;
      vector<float>   *mu_staco_cov_d0_theta_exPV;
      vector<float>   *mu_staco_cov_d0_qoverp_exPV;
      vector<float>   *mu_staco_cov_z0_phi_exPV;
      vector<float>   *mu_staco_cov_z0_theta_exPV;
      vector<float>   *mu_staco_cov_z0_qoverp_exPV;
      vector<float>   *mu_staco_cov_phi_theta_exPV;
      vector<float>   *mu_staco_cov_phi_qoverp_exPV;
      vector<float>   *mu_staco_cov_theta_qoverp_exPV;
      vector<float>   *mu_staco_ms_d0;
      vector<float>   *mu_staco_ms_z0;
      vector<float>   *mu_staco_ms_phi;
      vector<float>   *mu_staco_ms_theta;
      vector<float>   *mu_staco_ms_qoverp;
      vector<float>   *mu_staco_id_d0;
      vector<float>   *mu_staco_id_z0;
      vector<float>   *mu_staco_id_phi;
      vector<float>   *mu_staco_id_theta;
      vector<float>   *mu_staco_id_qoverp;
      vector<float>   *mu_staco_me_d0;
      vector<float>   *mu_staco_me_z0;
      vector<float>   *mu_staco_me_phi;
      vector<float>   *mu_staco_me_theta;
      vector<float>   *mu_staco_me_qoverp;
      vector<float>   *mu_staco_ie_d0;
      vector<float>   *mu_staco_ie_z0;
      vector<float>   *mu_staco_ie_phi;
      vector<float>   *mu_staco_ie_theta;
      vector<float>   *mu_staco_ie_qoverp;
      vector<int>     *mu_staco_nBLHits;
      vector<int>     *mu_staco_nPixHits;
      vector<int>     *mu_staco_nSCTHits;
      vector<int>     *mu_staco_nTRTHits;
      vector<int>     *mu_staco_nTRTHighTHits;
      vector<int>     *mu_staco_nBLSharedHits;
      vector<int>     *mu_staco_nPixSharedHits;
      vector<int>     *mu_staco_nPixHoles;
      vector<int>     *mu_staco_nSCTSharedHits;
      vector<int>     *mu_staco_nSCTHoles;
      vector<int>     *mu_staco_nTRTOutliers;
      vector<int>     *mu_staco_nTRTHighTOutliers;
      vector<int>     *mu_staco_nMDTHits;
      vector<int>     *mu_staco_nMDTHoles;
      vector<int>     *mu_staco_nCSCEtaHits;
      vector<int>     *mu_staco_nCSCEtaHoles;
      vector<int>     *mu_staco_nCSCPhiHits;
      vector<int>     *mu_staco_nCSCPhiHoles;
      vector<int>     *mu_staco_nRPCEtaHits;
      vector<int>     *mu_staco_nRPCEtaHoles;
      vector<int>     *mu_staco_nRPCPhiHits;
      vector<int>     *mu_staco_nRPCPhiHoles;
      vector<int>     *mu_staco_nTGCEtaHits;
      vector<int>     *mu_staco_nTGCEtaHoles;
      vector<int>     *mu_staco_nTGCPhiHits;
      vector<int>     *mu_staco_nTGCPhiHoles;
      vector<int>     *mu_staco_nGangedPixels;
      vector<int>     *mu_staco_nOutliersOnTrack;
      vector<int>     *mu_staco_nMDTBIHits;
      vector<int>     *mu_staco_nMDTBMHits;
      vector<int>     *mu_staco_nMDTBOHits;
      vector<int>     *mu_staco_nMDTBEEHits;
      vector<int>     *mu_staco_nMDTBIS78Hits;
      vector<int>     *mu_staco_nMDTEIHits;
      vector<int>     *mu_staco_nMDTEMHits;
      vector<int>     *mu_staco_nMDTEOHits;
      vector<int>     *mu_staco_nMDTEEHits;
      vector<int>     *mu_staco_nRPCLayer1EtaHits;
      vector<int>     *mu_staco_nRPCLayer2EtaHits;
      vector<int>     *mu_staco_nRPCLayer3EtaHits;
      vector<int>     *mu_staco_nRPCLayer1PhiHits;
      vector<int>     *mu_staco_nRPCLayer2PhiHits;
      vector<int>     *mu_staco_nRPCLayer3PhiHits;
      vector<int>     *mu_staco_nTGCLayer1EtaHits;
      vector<int>     *mu_staco_nTGCLayer2EtaHits;
      vector<int>     *mu_staco_nTGCLayer3EtaHits;
      vector<int>     *mu_staco_nTGCLayer4EtaHits;
      vector<int>     *mu_staco_nTGCLayer1PhiHits;
      vector<int>     *mu_staco_nTGCLayer2PhiHits;
      vector<int>     *mu_staco_nTGCLayer3PhiHits;
      vector<int>     *mu_staco_nTGCLayer4PhiHits;
      vector<int>     *mu_staco_barrelSectors;
      vector<int>     *mu_staco_endcapSectors;
      vector<float>   *mu_staco_trackd0;
      vector<float>   *mu_staco_trackz0;
      vector<float>   *mu_staco_trackphi;
      vector<float>   *mu_staco_tracktheta;
      vector<float>   *mu_staco_trackqoverp;
      vector<float>   *mu_staco_trackcov_d0;
      vector<float>   *mu_staco_trackcov_z0;
      vector<float>   *mu_staco_trackcov_phi;
      vector<float>   *mu_staco_trackcov_theta;
      vector<float>   *mu_staco_trackcov_qoverp;
      vector<float>   *mu_staco_trackcov_d0_z0;
      vector<float>   *mu_staco_trackcov_d0_phi;
      vector<float>   *mu_staco_trackcov_d0_theta;
      vector<float>   *mu_staco_trackcov_d0_qoverp;
      vector<float>   *mu_staco_trackcov_z0_phi;
      vector<float>   *mu_staco_trackcov_z0_theta;
      vector<float>   *mu_staco_trackcov_z0_qoverp;
      vector<float>   *mu_staco_trackcov_phi_theta;
      vector<float>   *mu_staco_trackcov_phi_qoverp;
      vector<float>   *mu_staco_trackcov_theta_qoverp;
      vector<float>   *mu_staco_trackfitchi2;
      vector<int>     *mu_staco_trackfitndof;
      vector<int>     *mu_staco_hastrack;
      vector<float>   *mu_staco_EF_dr;
      vector<float>   *mu_staco_EF_cb_eta;
      vector<float>   *mu_staco_EF_cb_phi;
      vector<float>   *mu_staco_EF_cb_pt;
      vector<float>   *mu_staco_EF_ms_eta;
      vector<float>   *mu_staco_EF_ms_phi;
      vector<float>   *mu_staco_EF_ms_pt;
      vector<float>   *mu_staco_EF_me_eta;
      vector<float>   *mu_staco_EF_me_phi;
      vector<float>   *mu_staco_EF_me_pt;
      vector<int>     *mu_staco_EF_matched;
      vector<float>   *mu_staco_L2CB_dr;
      vector<float>   *mu_staco_L2CB_pt;
      vector<float>   *mu_staco_L2CB_eta;
      vector<float>   *mu_staco_L2CB_phi;
      vector<float>   *mu_staco_L2CB_id_pt;
      vector<float>   *mu_staco_L2CB_ms_pt;
      vector<int>     *mu_staco_L2CB_nPixHits;
      vector<int>     *mu_staco_L2CB_nSCTHits;
      vector<int>     *mu_staco_L2CB_nTRTHits;
      vector<int>     *mu_staco_L2CB_nTRTHighTHits;
      vector<int>     *mu_staco_L2CB_matched;
      vector<float>   *mu_staco_L1_dr;
      vector<float>   *mu_staco_L1_pt;
      vector<float>   *mu_staco_L1_eta;
      vector<float>   *mu_staco_L1_phi;
      vector<short>   *mu_staco_L1_thrNumber;
      vector<short>   *mu_staco_L1_RoINumber;
      vector<short>   *mu_staco_L1_sectorAddress;
      vector<int>     *mu_staco_L1_firstCandidate;
      vector<int>     *mu_staco_L1_moreCandInRoI;
      vector<int>     *mu_staco_L1_moreCandInSector;
      vector<short>   *mu_staco_L1_source;
      vector<short>   *mu_staco_L1_hemisphere;
      vector<int>     *mu_staco_L1_matched;
      Bool_t          EF_L1ItemStreamer_L1_2MU0;
      Bool_t          EF_L1ItemStreamer_L1_2MU0_FIRSTEMPTY;
      Bool_t          EF_L1ItemStreamer_L1_2MU0_MU6;
      Bool_t          EF_L1ItemStreamer_L1_2MU10;
      Bool_t          EF_L1ItemStreamer_L1_2MU6;
      Bool_t          EF_L1ItemStreamer_L1_EM10;
      Bool_t          EF_L1ItemStreamer_L1_EM10I;
      Bool_t          EF_L1ItemStreamer_L1_EM14;
      Bool_t          EF_L1ItemStreamer_L1_EM2;
      Bool_t          EF_L1ItemStreamer_L1_EM2_MV;
      Bool_t          EF_L1ItemStreamer_L1_EM2_UNPAIRED_ISO;
      Bool_t          EF_L1ItemStreamer_L1_EM2_UNPAIRED_NONISO;
      Bool_t          EF_L1ItemStreamer_L1_EM3;
      Bool_t          EF_L1ItemStreamer_L1_EM3_EMPTY;
      Bool_t          EF_L1ItemStreamer_L1_EM3_FIRSTEMPTY;
      Bool_t          EF_L1ItemStreamer_L1_EM4;
      Bool_t          EF_L1ItemStreamer_L1_EM5;
      Bool_t          EF_L1ItemStreamer_L1_EM5I;
      Bool_t          EF_L1ItemStreamer_L1_MU0;
      Bool_t          EF_L1ItemStreamer_L1_MU0_COMM;
      Bool_t          EF_L1ItemStreamer_L1_MU0_COMM_EMPTY;
      Bool_t          EF_L1ItemStreamer_L1_MU0_COMM_FIRSTEMPTY;
      Bool_t          EF_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_ISO;
      Bool_t          EF_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_NONISO;
      Bool_t          EF_L1ItemStreamer_L1_MU0_EMPTY;
      Bool_t          EF_L1ItemStreamer_L1_MU0_FIRSTEMPTY;
      Bool_t          EF_L1ItemStreamer_L1_MU0_MV;
      Bool_t          EF_L1ItemStreamer_L1_MU0_UNPAIRED_ISO;
      Bool_t          EF_L1ItemStreamer_L1_MU0_UNPAIRED_NONISO;
      Bool_t          EF_L1ItemStreamer_L1_MU10;
      Bool_t          EF_L1ItemStreamer_L1_MU10_FIRSTEMPTY;
      Bool_t          EF_L1ItemStreamer_L1_MU15;
      Bool_t          EF_L1ItemStreamer_L1_MU20;
      Bool_t          EF_L1ItemStreamer_L1_MU6;
      Bool_t          EF_L1ItemStreamer_L1_MU6_FIRSTEMPTY;
      Bool_t          EF_SeededStreamerL1Calo;
      Bool_t          EF_g10_loose;
      Bool_t          EF_g10_loose_larcalib;
      Bool_t          EF_g5_NoCut_cosmic;
      Bool_t          EF_g5_loose;
      Bool_t          EF_g5_loose_larcalib;
      Bool_t          EF_mu4;
      Bool_t          EF_mu4_IDTrkNoCut;
      Bool_t          EF_mu4_MSonly;
      Bool_t          EF_mu4_MSonly_MB2_noL2_EFFS;
      Bool_t          EF_mu4_MSonly_cosmic;
      Bool_t          EF_mu4_MV;
      Bool_t          EF_mu4_MV_MSonly;
      Bool_t          EF_mu4_comm_MSonly_cosmic;
      Bool_t          EF_mu4_comm_cosmic;
      Bool_t          EF_mu4_cosmic;
      Bool_t          L1_2EM2;
      Bool_t          L1_2EM3;
      Bool_t          L1_2EM4;
      Bool_t          L1_2EM5;
      Bool_t          L1_2MU0;
      Bool_t          L1_2MU0_FIRSTEMPTY;
      Bool_t          L1_2MU0_MU6;
      Bool_t          L1_2MU10;
      Bool_t          L1_2MU20;
      Bool_t          L1_2MU6;
      Bool_t          L1_EM10;
      Bool_t          L1_EM10I;
      Bool_t          L1_EM14;
      Bool_t          L1_EM2;
      Bool_t          L1_EM2_MV;
      Bool_t          L1_EM2_UNPAIRED_ISO;
      Bool_t          L1_EM2_UNPAIRED_NONISO;
      Bool_t          L1_EM3;
      Bool_t          L1_EM3_EMPTY;
      Bool_t          L1_EM3_FIRSTEMPTY;
      Bool_t          L1_EM4;
      Bool_t          L1_EM5;
      Bool_t          L1_EM5I;
      Bool_t          L1_MU0;
      Bool_t          L1_MU0_COMM;
      Bool_t          L1_MU0_COMM_EMPTY;
      Bool_t          L1_MU0_COMM_FIRSTEMPTY;
      Bool_t          L1_MU0_COMM_UNPAIRED_ISO;
      Bool_t          L1_MU0_COMM_UNPAIRED_NONISO;
      Bool_t          L1_MU0_EMPTY;
      Bool_t          L1_MU0_FIRSTEMPTY;
      Bool_t          L1_MU0_MV;
      Bool_t          L1_MU0_UNPAIRED_ISO;
      Bool_t          L1_MU0_UNPAIRED_NONISO;
      Bool_t          L1_MU10;
      Bool_t          L1_MU10_FIRSTEMPTY;
      Bool_t          L1_MU15;
      Bool_t          L1_MU20;
      Bool_t          L1_MU6;
      Bool_t          L1_MU6_FIRSTEMPTY;
      Bool_t          L2_L1ItemStreamer_L1_2EM2;
      Bool_t          L2_L1ItemStreamer_L1_2EM3;
      Bool_t          L2_L1ItemStreamer_L1_2EM4;
      Bool_t          L2_L1ItemStreamer_L1_2EM5;
      Bool_t          L2_L1ItemStreamer_L1_2MU0;
      Bool_t          L2_L1ItemStreamer_L1_2MU0_FIRSTEMPTY;
      Bool_t          L2_L1ItemStreamer_L1_2MU0_MU6;
      Bool_t          L2_L1ItemStreamer_L1_2MU10;
      Bool_t          L2_L1ItemStreamer_L1_2MU6;
      Bool_t          L2_L1ItemStreamer_L1_EM10;
      Bool_t          L2_L1ItemStreamer_L1_EM10I;
      Bool_t          L2_L1ItemStreamer_L1_EM14;
      Bool_t          L2_L1ItemStreamer_L1_EM2;
      Bool_t          L2_L1ItemStreamer_L1_EM2_MV;
      Bool_t          L2_L1ItemStreamer_L1_EM2_UNPAIRED_ISO;
      Bool_t          L2_L1ItemStreamer_L1_EM2_UNPAIRED_NONISO;
      Bool_t          L2_L1ItemStreamer_L1_EM3;
      Bool_t          L2_L1ItemStreamer_L1_EM3_EMPTY;
      Bool_t          L2_L1ItemStreamer_L1_EM3_FIRSTEMPTY;
      Bool_t          L2_L1ItemStreamer_L1_EM4;
      Bool_t          L2_L1ItemStreamer_L1_EM5;
      Bool_t          L2_L1ItemStreamer_L1_EM5I;
      Bool_t          L2_L1ItemStreamer_L1_MU0;
      Bool_t          L2_L1ItemStreamer_L1_MU0_COMM;
      Bool_t          L2_L1ItemStreamer_L1_MU0_COMM_EMPTY;
      Bool_t          L2_L1ItemStreamer_L1_MU0_COMM_FIRSTEMPTY;
      Bool_t          L2_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_ISO;
      Bool_t          L2_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_NONISO;
      Bool_t          L2_L1ItemStreamer_L1_MU0_EMPTY;
      Bool_t          L2_L1ItemStreamer_L1_MU0_FIRSTEMPTY;
      Bool_t          L2_L1ItemStreamer_L1_MU0_MV;
      Bool_t          L2_L1ItemStreamer_L1_MU0_UNPAIRED_ISO;
      Bool_t          L2_L1ItemStreamer_L1_MU0_UNPAIRED_NONISO;
      Bool_t          L2_L1ItemStreamer_L1_MU10;
      Bool_t          L2_L1ItemStreamer_L1_MU10_FIRSTEMPTY;
      Bool_t          L2_L1ItemStreamer_L1_MU15;
      Bool_t          L2_L1ItemStreamer_L1_MU20;
      Bool_t          L2_L1ItemStreamer_L1_MU6;
      Bool_t          L2_L1ItemStreamer_L1_MU6_FIRSTEMPTY;
      Bool_t          L2_SeededStreamerL1Calo;
      Bool_t          L2_em3_empty_larcalib;
      Bool_t          L2_g10_loose;
      Bool_t          L2_g5_NoCut_cosmic;
      Bool_t          L2_g5_loose;
      Bool_t          L2_mu4;
      Bool_t          L2_mu4_IDTrkNoCut;
      Bool_t          L2_mu4_MSonly;
      Bool_t          L2_mu4_MSonly_MB2_noL2_EFFS;
      Bool_t          L2_mu4_MSonly_cosmic;
      Bool_t          L2_mu4_MV;
      Bool_t          L2_mu4_MV_MSonly;
      Bool_t          L2_mu4_comm_MSonly_cosmic;
      Bool_t          L2_mu4_comm_cosmic;
      Bool_t          L2_mu4_cosmic;
      Bool_t          L2_mu6_cal;
      Int_t           mu_muid_n;
      vector<float>   *mu_muid_E;
      vector<float>   *mu_muid_pt;
      vector<float>   *mu_muid_m;
      vector<float>   *mu_muid_eta;
      vector<float>   *mu_muid_phi;
      vector<float>   *mu_muid_px;
      vector<float>   *mu_muid_py;
      vector<float>   *mu_muid_pz;
      vector<float>   *mu_muid_charge;
      vector<unsigned short> *mu_muid_allauthor;
      vector<int>     *mu_muid_author;
      vector<float>   *mu_muid_matchchi2;
      vector<int>     *mu_muid_matchndof;
      vector<float>   *mu_muid_etcone20;
      vector<float>   *mu_muid_etcone30;
      vector<float>   *mu_muid_etcone40;
      vector<float>   *mu_muid_nucone20;
      vector<float>   *mu_muid_nucone30;
      vector<float>   *mu_muid_nucone40;
      vector<float>   *mu_muid_ptcone20;
      vector<float>   *mu_muid_ptcone30;
      vector<float>   *mu_muid_ptcone40;
      vector<float>   *mu_muid_energyLossPar;
      vector<float>   *mu_muid_energyLossErr;
      vector<float>   *mu_muid_etCore;
      vector<float>   *mu_muid_energyLossType;
      vector<int>     *mu_muid_bestMatch;
      vector<int>     *mu_muid_isStandAloneMuon;
      vector<int>     *mu_muid_isCombinedMuon;
      vector<int>     *mu_muid_isLowPtReconstructedMuon;
      vector<int>     *mu_muid_loose;
      vector<int>     *mu_muid_medium;
      vector<int>     *mu_muid_tight;
      vector<float>   *mu_muid_d0_exPV;
      vector<float>   *mu_muid_z0_exPV;
      vector<float>   *mu_muid_phi_exPV;
      vector<float>   *mu_muid_theta_exPV;
      vector<float>   *mu_muid_qoverp_exPV;
      vector<float>   *mu_muid_cb_d0_exPV;
      vector<float>   *mu_muid_cb_z0_exPV;
      vector<float>   *mu_muid_cb_phi_exPV;
      vector<float>   *mu_muid_cb_theta_exPV;
      vector<float>   *mu_muid_cb_qoverp_exPV;
      vector<float>   *mu_muid_id_d0_exPV;
      vector<float>   *mu_muid_id_z0_exPV;
      vector<float>   *mu_muid_id_phi_exPV;
      vector<float>   *mu_muid_id_theta_exPV;
      vector<float>   *mu_muid_id_qoverp_exPV;
      vector<float>   *mu_muid_me_d0_exPV;
      vector<float>   *mu_muid_me_z0_exPV;
      vector<float>   *mu_muid_me_phi_exPV;
      vector<float>   *mu_muid_me_theta_exPV;
      vector<float>   *mu_muid_me_qoverp_exPV;
      vector<float>   *mu_muid_ie_d0_exPV;
      vector<float>   *mu_muid_ie_z0_exPV;
      vector<float>   *mu_muid_ie_phi_exPV;
      vector<float>   *mu_muid_ie_theta_exPV;
      vector<float>   *mu_muid_ie_qoverp_exPV;
      vector<float>   *mu_muid_cov_d0_exPV;
      vector<float>   *mu_muid_cov_z0_exPV;
      vector<float>   *mu_muid_cov_phi_exPV;
      vector<float>   *mu_muid_cov_theta_exPV;
      vector<float>   *mu_muid_cov_qoverp_exPV;
      vector<float>   *mu_muid_cov_d0_z0_exPV;
      vector<float>   *mu_muid_cov_d0_phi_exPV;
      vector<float>   *mu_muid_cov_d0_theta_exPV;
      vector<float>   *mu_muid_cov_d0_qoverp_exPV;
      vector<float>   *mu_muid_cov_z0_phi_exPV;
      vector<float>   *mu_muid_cov_z0_theta_exPV;
      vector<float>   *mu_muid_cov_z0_qoverp_exPV;
      vector<float>   *mu_muid_cov_phi_theta_exPV;
      vector<float>   *mu_muid_cov_phi_qoverp_exPV;
      vector<float>   *mu_muid_cov_theta_qoverp_exPV;
      vector<float>   *mu_muid_ms_d0;
      vector<float>   *mu_muid_ms_z0;
      vector<float>   *mu_muid_ms_phi;
      vector<float>   *mu_muid_ms_theta;
      vector<float>   *mu_muid_ms_qoverp;
      vector<float>   *mu_muid_id_d0;
      vector<float>   *mu_muid_id_z0;
      vector<float>   *mu_muid_id_phi;
      vector<float>   *mu_muid_id_theta;
      vector<float>   *mu_muid_id_qoverp;
      vector<float>   *mu_muid_me_d0;
      vector<float>   *mu_muid_me_z0;
      vector<float>   *mu_muid_me_phi;
      vector<float>   *mu_muid_me_theta;
      vector<float>   *mu_muid_me_qoverp;
      vector<float>   *mu_muid_ie_d0;
      vector<float>   *mu_muid_ie_z0;
      vector<float>   *mu_muid_ie_phi;
      vector<float>   *mu_muid_ie_theta;
      vector<float>   *mu_muid_ie_qoverp;
      vector<int>     *mu_muid_nBLHits;
      vector<int>     *mu_muid_nPixHits;
      vector<int>     *mu_muid_nSCTHits;
      vector<int>     *mu_muid_nTRTHits;
      vector<int>     *mu_muid_nTRTHighTHits;
      vector<int>     *mu_muid_nBLSharedHits;
      vector<int>     *mu_muid_nPixSharedHits;
      vector<int>     *mu_muid_nPixHoles;
      vector<int>     *mu_muid_nSCTSharedHits;
      vector<int>     *mu_muid_nSCTHoles;
      vector<int>     *mu_muid_nTRTOutliers;
      vector<int>     *mu_muid_nTRTHighTOutliers;
      vector<int>     *mu_muid_nMDTHits;
      vector<int>     *mu_muid_nMDTHoles;
      vector<int>     *mu_muid_nCSCEtaHits;
      vector<int>     *mu_muid_nCSCEtaHoles;
      vector<int>     *mu_muid_nCSCPhiHits;
      vector<int>     *mu_muid_nCSCPhiHoles;
      vector<int>     *mu_muid_nRPCEtaHits;
      vector<int>     *mu_muid_nRPCEtaHoles;
      vector<int>     *mu_muid_nRPCPhiHits;
      vector<int>     *mu_muid_nRPCPhiHoles;
      vector<int>     *mu_muid_nTGCEtaHits;
      vector<int>     *mu_muid_nTGCEtaHoles;
      vector<int>     *mu_muid_nTGCPhiHits;
      vector<int>     *mu_muid_nTGCPhiHoles;
      vector<int>     *mu_muid_nGangedPixels;
      vector<int>     *mu_muid_nOutliersOnTrack;
      vector<int>     *mu_muid_nMDTBIHits;
      vector<int>     *mu_muid_nMDTBMHits;
      vector<int>     *mu_muid_nMDTBOHits;
      vector<int>     *mu_muid_nMDTBEEHits;
      vector<int>     *mu_muid_nMDTBIS78Hits;
      vector<int>     *mu_muid_nMDTEIHits;
      vector<int>     *mu_muid_nMDTEMHits;
      vector<int>     *mu_muid_nMDTEOHits;
      vector<int>     *mu_muid_nMDTEEHits;
      vector<int>     *mu_muid_nRPCLayer1EtaHits;
      vector<int>     *mu_muid_nRPCLayer2EtaHits;
      vector<int>     *mu_muid_nRPCLayer3EtaHits;
      vector<int>     *mu_muid_nRPCLayer1PhiHits;
      vector<int>     *mu_muid_nRPCLayer2PhiHits;
      vector<int>     *mu_muid_nRPCLayer3PhiHits;
      vector<int>     *mu_muid_nTGCLayer1EtaHits;
      vector<int>     *mu_muid_nTGCLayer2EtaHits;
      vector<int>     *mu_muid_nTGCLayer3EtaHits;
      vector<int>     *mu_muid_nTGCLayer4EtaHits;
      vector<int>     *mu_muid_nTGCLayer1PhiHits;
      vector<int>     *mu_muid_nTGCLayer2PhiHits;
      vector<int>     *mu_muid_nTGCLayer3PhiHits;
      vector<int>     *mu_muid_nTGCLayer4PhiHits;
      vector<int>     *mu_muid_barrelSectors;
      vector<int>     *mu_muid_endcapSectors;
      vector<float>   *mu_muid_trackd0;
      vector<float>   *mu_muid_trackz0;
      vector<float>   *mu_muid_trackphi;
      vector<float>   *mu_muid_tracktheta;
      vector<float>   *mu_muid_trackqoverp;
      vector<float>   *mu_muid_trackcov_d0;
      vector<float>   *mu_muid_trackcov_z0;
      vector<float>   *mu_muid_trackcov_phi;
      vector<float>   *mu_muid_trackcov_theta;
      vector<float>   *mu_muid_trackcov_qoverp;
      vector<float>   *mu_muid_trackcov_d0_z0;
      vector<float>   *mu_muid_trackcov_d0_phi;
      vector<float>   *mu_muid_trackcov_d0_theta;
      vector<float>   *mu_muid_trackcov_d0_qoverp;
      vector<float>   *mu_muid_trackcov_z0_phi;
      vector<float>   *mu_muid_trackcov_z0_theta;
      vector<float>   *mu_muid_trackcov_z0_qoverp;
      vector<float>   *mu_muid_trackcov_phi_theta;
      vector<float>   *mu_muid_trackcov_phi_qoverp;
      vector<float>   *mu_muid_trackcov_theta_qoverp;
      vector<float>   *mu_muid_trackfitchi2;
      vector<int>     *mu_muid_trackfitndof;
      vector<int>     *mu_muid_hastrack;
      vector<float>   *mu_muid_EF_dr;
      vector<float>   *mu_muid_EF_cb_eta;
      vector<float>   *mu_muid_EF_cb_phi;
      vector<float>   *mu_muid_EF_cb_pt;
      vector<float>   *mu_muid_EF_ms_eta;
      vector<float>   *mu_muid_EF_ms_phi;
      vector<float>   *mu_muid_EF_ms_pt;
      vector<float>   *mu_muid_EF_me_eta;
      vector<float>   *mu_muid_EF_me_phi;
      vector<float>   *mu_muid_EF_me_pt;
      vector<int>     *mu_muid_EF_matched;
      vector<float>   *mu_muid_L2CB_dr;
      vector<float>   *mu_muid_L2CB_pt;
      vector<float>   *mu_muid_L2CB_eta;
      vector<float>   *mu_muid_L2CB_phi;
      vector<float>   *mu_muid_L2CB_id_pt;
      vector<float>   *mu_muid_L2CB_ms_pt;
      vector<int>     *mu_muid_L2CB_nPixHits;
      vector<int>     *mu_muid_L2CB_nSCTHits;
      vector<int>     *mu_muid_L2CB_nTRTHits;
      vector<int>     *mu_muid_L2CB_nTRTHighTHits;
      vector<int>     *mu_muid_L2CB_matched;
      vector<float>   *mu_muid_L1_dr;
      vector<float>   *mu_muid_L1_pt;
      vector<float>   *mu_muid_L1_eta;
      vector<float>   *mu_muid_L1_phi;
      vector<short>   *mu_muid_L1_thrNumber;
      vector<short>   *mu_muid_L1_RoINumber;
      vector<short>   *mu_muid_L1_sectorAddress;
      vector<int>     *mu_muid_L1_firstCandidate;
      vector<int>     *mu_muid_L1_moreCandInRoI;
      vector<int>     *mu_muid_L1_moreCandInSector;
      vector<short>   *mu_muid_L1_source;
      vector<short>   *mu_muid_L1_hemisphere;
      vector<int>     *mu_muid_L1_matched;
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
      vector<short>   *trig_L2_resurrected;
      vector<short>   *trig_EF_resurrected;
      vector<short>   *trig_L2_passedThrough;
      vector<short>   *trig_EF_passedThrough;
      Bool_t          L1_2J10;
      Bool_t          L1_2J15;
      Bool_t          L1_2J5;
      Bool_t          L1_J10;
      Bool_t          L1_J15;
      Bool_t          L1_J30;
      Bool_t          L1_J5;
      Bool_t          L1_J55;
      Bool_t          L1_J75;
      Bool_t          L1_J95;
      Int_t           trig_L1_jet_n;
      vector<float>   *trig_L1_jet_eta;
      vector<float>   *trig_L1_jet_phi;
      vector<vector<string> > *trig_L1_jet_thrNames;
      vector<vector<float> > *trig_L1_jet_thrValues;
      vector<unsigned int> *trig_L1_jet_thrPattern;
      vector<float>   *trig_L1_jet_et4x4;
      vector<float>   *trig_L1_jet_et6x6;
      vector<float>   *trig_L1_jet_et8x8;
      vector<unsigned int> *trig_L1_jet_RoIWord;
      vector<string>  *trig_L1_esum_thrNames;
      Float_t         trig_L1_esum_energyX;
      Float_t         trig_L1_esum_energyY;
      Float_t         trig_L1_esum_energyT;
      Bool_t          trig_L1_esum_overflowX;
      Bool_t          trig_L1_esum_overflowY;
      Bool_t          trig_L1_esum_overflowT;
      UInt_t          trig_L1_esum_RoIWord0;
      UInt_t          trig_L1_esum_RoIWord1;
      UInt_t          trig_L1_esum_RoIWord2;
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
      vector<int>     *trig_L2_jet_RoIWord;
      vector<double>  *trig_L2_jet_ehad0;
      vector<double>  *trig_L2_jet_eem0;
      Int_t           trtRDO_countRDOhitsInEvent;
      Int_t           trtRDO_countBarrelhitsInEvent;
      Int_t           trtRDO_countEndCaphitsInEvent;
      Int_t           trtRDO_countEndCapAhitsInEvent;
      Int_t           trtRDO_countEndCapChitsInEvent;
      Int_t           trtRDO_countdeadstraws;
      Int_t           vx_n;
      vector<float>   *vx_x;
      vector<float>   *vx_y;
      vector<float>   *vx_z;
      vector<float>   *vx_cov_x;
      vector<float>   *vx_cov_y;
      vector<float>   *vx_cov_z;
      vector<float>   *vx_chi2;
      vector<int>     *vx_ndof;
      vector<float>   *vx_px;
      vector<float>   *vx_py;
      vector<float>   *vx_pz;
      vector<float>   *vx_E;
      vector<float>   *vx_m;
      vector<int>     *vx_nTracks;
      vector<float>   *vx_sumPt;
      vector<int>     *vx_type;
      vector<int>     *vx_trk_n;
      vector<vector<float> > *vx_trk_chi2;
      vector<vector<float> > *vx_trk_d0;
      vector<vector<float> > *vx_trk_z0;
      vector<vector<float> > *vx_trk_unbiased_d0;
      vector<vector<float> > *vx_trk_unbiased_z0;
      vector<vector<float> > *vx_trk_err_unbiased_d0;
      vector<vector<float> > *vx_trk_err_unbiased_z0;
      vector<vector<float> > *vx_trk_phi;
      vector<vector<float> > *vx_trk_theta;
      vector<vector<float> > *vx_trk_weight;
      vector<vector<int> > *vx_trk_index;
      Int_t           el_n;
      vector<float>   *el_E;
      vector<float>   *el_Et;
      vector<float>   *el_pt;
      vector<float>   *el_m;
      vector<float>   *el_eta;
      vector<float>   *el_phi;
      vector<float>   *el_px;
      vector<float>   *el_py;
      vector<float>   *el_pz;
      vector<float>   *el_charge;
      vector<int>     *el_author;
      vector<unsigned int> *el_isEM;
      vector<unsigned int> *el_OQ;
      vector<int>     *el_convFlag;
      vector<int>     *el_isConv;
      vector<int>     *el_nConv;
      vector<int>     *el_nSingleTrackConv;
      vector<int>     *el_nDoubleTrackConv;
      vector<int>     *el_loose;
      vector<int>     *el_medium;
      vector<int>     *el_mediumIso;
      vector<int>     *el_tight;
      vector<int>     *el_tightIso;
      vector<int>     *el_goodOQ;
      vector<float>   *el_Ethad;
      vector<float>   *el_Ethad1;
      vector<float>   *el_f1;
      vector<float>   *el_f1core;
      vector<float>   *el_Emins1;
      vector<float>   *el_fside;
      vector<float>   *el_Emax2;
      vector<float>   *el_ws3;
      vector<float>   *el_wstot;
      vector<float>   *el_emaxs1;
      vector<float>   *el_deltaEs;
      vector<float>   *el_E233;
      vector<float>   *el_E237;
      vector<float>   *el_E277;
      vector<float>   *el_weta2;
      vector<float>   *el_f3;
      vector<float>   *el_f3core;
      vector<float>   *el_rphiallcalo;
      vector<float>   *el_Etcone45;
      vector<float>   *el_Etcone20;
      vector<float>   *el_Etcone30;
      vector<float>   *el_Etcone40;
      vector<float>   *el_ptcone30;
      vector<float>   *el_convanglematch;
      vector<float>   *el_convtrackmatch;
      vector<float>   *el_pos7;
      vector<float>   *el_etacorrmag;
      vector<float>   *el_deltaeta1;
      vector<float>   *el_deltaeta2;
      vector<float>   *el_deltaphi2;
      vector<float>   *el_deltaphiRescaled;
      vector<float>   *el_deltaPhiRot;
      vector<float>   *el_expectHitInBLayer;
      vector<float>   *el_reta;
      vector<float>   *el_rphi;
      vector<float>   *el_EtringnoisedR03sig2;
      vector<float>   *el_EtringnoisedR03sig3;
      vector<float>   *el_EtringnoisedR03sig4;
      vector<double>  *el_isolationlikelihoodjets;
      vector<double>  *el_isolationlikelihoodhqelectrons;
      vector<double>  *el_electronweight;
      vector<double>  *el_electronbgweight;
      vector<double>  *el_softeweight;
      vector<double>  *el_softebgweight;
      vector<double>  *el_neuralnet;
      vector<double>  *el_Hmatrix;
      vector<double>  *el_Hmatrix5;
      vector<double>  *el_adaboost;
      vector<double>  *el_softeneuralnet;
      vector<float>   *el_zvertex;
      vector<float>   *el_errz;
      vector<float>   *el_etap;
      vector<float>   *el_depth;
      vector<int>     *el_refittedTrack_n;
      vector<vector<int> > *el_refittedTrack_author;
      vector<vector<float> > *el_refittedTrack_chi2;
      vector<vector<float> > *el_refittedTrack_qoverp;
      vector<vector<float> > *el_refittedTrack_d0;
      vector<vector<float> > *el_refittedTrack_z0;
      vector<vector<float> > *el_refittedTrack_theta;
      vector<vector<float> > *el_refittedTrack_phi;
      vector<vector<float> > *el_refittedTrack_LMqoverp;
      vector<vector<int> > *el_refittedTrack_hasBrem;
      vector<vector<float> > *el_refittedTrack_bremRadius;
      vector<vector<float> > *el_refittedTrack_bremZ;
      vector<vector<float> > *el_refittedTrack_bremRadiusErr;
      vector<vector<float> > *el_refittedTrack_bremZErr;
      vector<float>   *el_Es0;
      vector<float>   *el_etas0;
      vector<float>   *el_phis0;
      vector<float>   *el_Es1;
      vector<float>   *el_etas1;
      vector<float>   *el_phis1;
      vector<float>   *el_Es2;
      vector<float>   *el_etas2;
      vector<float>   *el_phis2;
      vector<float>   *el_Es3;
      vector<float>   *el_etas3;
      vector<float>   *el_phis3;
      vector<float>   *el_E_PreSamplerB;
      vector<float>   *el_E_EMB1;
      vector<float>   *el_E_EMB2;
      vector<float>   *el_E_EMB3;
      vector<float>   *el_E_PreSamplerE;
      vector<float>   *el_E_EME1;
      vector<float>   *el_E_EME2;
      vector<float>   *el_E_EME3;
      vector<float>   *el_E_HEC0;
      vector<float>   *el_E_HEC1;
      vector<float>   *el_E_HEC2;
      vector<float>   *el_E_HEC3;
      vector<float>   *el_E_TileBar0;
      vector<float>   *el_E_TileBar1;
      vector<float>   *el_E_TileBar2;
      vector<float>   *el_E_TileGap1;
      vector<float>   *el_E_TileGap2;
      vector<float>   *el_E_TileGap3;
      vector<float>   *el_E_TileExt0;
      vector<float>   *el_E_TileExt1;
      vector<float>   *el_E_TileExt2;
      vector<float>   *el_E_FCAL0;
      vector<float>   *el_E_FCAL1;
      vector<float>   *el_E_FCAL2;
      vector<float>   *el_cl_E;
      vector<float>   *el_cl_pt;
      vector<float>   *el_cl_eta;
      vector<float>   *el_cl_phi;
      vector<float>   *el_firstEdens;
      vector<float>   *el_cellmaxfrac;
      vector<float>   *el_longitudinal;
      vector<float>   *el_secondlambda;
      vector<float>   *el_lateral;
      vector<float>   *el_secondR;
      vector<float>   *el_centerlambda;
      vector<float>   *el_rawcl_Es0;
      vector<float>   *el_rawcl_etas0;
      vector<float>   *el_rawcl_phis0;
      vector<float>   *el_rawcl_Es1;
      vector<float>   *el_rawcl_etas1;
      vector<float>   *el_rawcl_phis1;
      vector<float>   *el_rawcl_Es2;
      vector<float>   *el_rawcl_etas2;
      vector<float>   *el_rawcl_phis2;
      vector<float>   *el_rawcl_Es3;
      vector<float>   *el_rawcl_etas3;
      vector<float>   *el_rawcl_phis3;
      vector<float>   *el_rawcl_E;
      vector<float>   *el_rawcl_pt;
      vector<float>   *el_rawcl_eta;
      vector<float>   *el_rawcl_phi;
      vector<float>   *el_refittedtrackcovd0;
      vector<float>   *el_refittedtrackcovz0;
      vector<float>   *el_refittedtrackcovphi;
      vector<float>   *el_refittedtrackcovtheta;
      vector<float>   *el_refittedtrackcovqoverp;
      vector<float>   *el_refittedtrackcovd0z0;
      vector<float>   *el_refittedtrackcovz0phi;
      vector<float>   *el_refittedtrackcovz0theta;
      vector<float>   *el_refittedtrackcovz0qoverp;
      vector<float>   *el_refittedtrackcovd0phi;
      vector<float>   *el_refittedtrackcovd0theta;
      vector<float>   *el_refittedtrackcovd0qoverp;
      vector<float>   *el_refittedtrackcovphitheta;
      vector<float>   *el_refittedtrackcovphiqoverp;
      vector<float>   *el_refittedtrackcovthetaqoverp;
      vector<float>   *el_trackd0;
      vector<float>   *el_trackz0;
      vector<float>   *el_trackphi;
      vector<float>   *el_tracktheta;
      vector<float>   *el_trackqoverp;
      vector<float>   *el_trackpt;
      vector<float>   *el_tracketa;
      vector<float>   *el_trackcov_d0;
      vector<float>   *el_trackcov_z0;
      vector<float>   *el_trackcov_phi;
      vector<float>   *el_trackcov_theta;
      vector<float>   *el_trackcov_qoverp;
      vector<float>   *el_trackcov_d0_z0;
      vector<float>   *el_trackcov_d0_phi;
      vector<float>   *el_trackcov_d0_theta;
      vector<float>   *el_trackcov_d0_qoverp;
      vector<float>   *el_trackcov_z0_phi;
      vector<float>   *el_trackcov_z0_theta;
      vector<float>   *el_trackcov_z0_qoverp;
      vector<float>   *el_trackcov_phi_theta;
      vector<float>   *el_trackcov_phi_qoverp;
      vector<float>   *el_trackcov_theta_qoverp;
      vector<float>   *el_trackfitchi2;
      vector<int>     *el_trackfitndof;
      vector<int>     *el_nBLHits;
      vector<int>     *el_nPixHits;
      vector<int>     *el_nSCTHits;
      vector<int>     *el_nTRTHits;
      vector<int>     *el_nPixHoles;
      vector<int>     *el_nSCTHoles;
      vector<int>     *el_nBLSharedHits;
      vector<int>     *el_nPixSharedHits;
      vector<int>     *el_nSCTSharedHits;
      vector<int>     *el_nTRTHighTHits;
      vector<int>     *el_nTRTOutliers;
      vector<int>     *el_nTRTHighTOutliers;
      vector<int>     *el_nSiHits;
      vector<float>   *el_TRTHighTHitsRatio;
      vector<float>   *el_pixeldEdx;
      vector<float>   *el_eProbabilityComb;
      vector<float>   *el_eProbabilityHT;
      vector<float>   *el_eProbabilityToT;
      vector<float>   *el_eProbabilityBrem;
      vector<float>   *el_vertx;
      vector<float>   *el_verty;
      vector<float>   *el_vertz;
      vector<int>     *el_hastrack;
      vector<float>   *el_deltaEmax2;
      vector<float>   *el_calibHitsShowerDepth;
      vector<float>   *el_trackd0beam;
      vector<float>   *el_tracksigd0beam;
      vector<float>   *el_trackd0pv;
      vector<float>   *el_tracksigd0pv;
      vector<float>   *el_trackz0pv;
      vector<float>   *el_tracksigz0pv;
      vector<float>   *el_trackd0pvunbiased;
      vector<float>   *el_tracksigd0pvunbiased;
      vector<float>   *el_trackz0pvunbiased;
      vector<float>   *el_tracksigz0pvunbiased;
      vector<unsigned int> *el_isIso;
      vector<float>   *el_mvaptcone20;
      vector<float>   *el_mvaptcone30;
      vector<float>   *el_mvaptcone40;
      Int_t           ph_n;
      vector<float>   *ph_E;
      vector<float>   *ph_Et;
      vector<float>   *ph_pt;
      vector<float>   *ph_m;
      vector<float>   *ph_eta;
      vector<float>   *ph_phi;
      vector<float>   *ph_px;
      vector<float>   *ph_py;
      vector<float>   *ph_pz;
      vector<int>     *ph_author;
      vector<int>     *ph_isRecovered;
      vector<unsigned int> *ph_isEM;
      vector<unsigned int> *ph_OQ;
      vector<int>     *ph_loose;
      vector<int>     *ph_tight;
      vector<int>     *ph_tightIso;
      vector<int>     *ph_goodOQ;
      vector<float>   *ph_Ethad;
      vector<float>   *ph_Ethad1;
      vector<float>   *ph_E033;
      vector<float>   *ph_f1;
      vector<float>   *ph_f1core;
      vector<float>   *ph_Emins1;
      vector<float>   *ph_fside;
      vector<float>   *ph_Emax2;
      vector<float>   *ph_ws3;
      vector<float>   *ph_wstot;
      vector<float>   *ph_E132;
      vector<float>   *ph_E1152;
      vector<float>   *ph_emaxs1;
      vector<float>   *ph_deltaEs;
      vector<float>   *ph_E233;
      vector<float>   *ph_E237;
      vector<float>   *ph_E277;
      vector<float>   *ph_weta2;
      vector<float>   *ph_f3;
      vector<float>   *ph_f3core;
      vector<float>   *ph_rphiallcalo;
      vector<float>   *ph_Etcone45;
      vector<float>   *ph_Etcone20;
      vector<float>   *ph_Etcone30;
      vector<float>   *ph_Etcone40;
      vector<float>   *ph_ptcone30;
      vector<float>   *ph_convanglematch;
      vector<float>   *ph_convtrackmatch;
      vector<float>   *ph_reta;
      vector<float>   *ph_rphi;
      vector<float>   *ph_EtringnoisedR03sig2;
      vector<float>   *ph_EtringnoisedR03sig3;
      vector<float>   *ph_EtringnoisedR03sig4;
      vector<double>  *ph_isolationlikelihoodjets;
      vector<double>  *ph_isolationlikelihoodhqelectrons;
      vector<double>  *ph_loglikelihood;
      vector<double>  *ph_photonweight;
      vector<double>  *ph_photonbgweight;
      vector<double>  *ph_neuralnet;
      vector<double>  *ph_Hmatrix;
      vector<double>  *ph_Hmatrix5;
      vector<double>  *ph_adaboost;
      vector<float>   *ph_zvertex;
      vector<float>   *ph_errz;
      vector<float>   *ph_etap;
      vector<float>   *ph_depth;
      vector<float>   *ph_cl_E;
      vector<float>   *ph_cl_pt;
      vector<float>   *ph_cl_eta;
      vector<float>   *ph_cl_phi;
      vector<float>   *ph_Es0;
      vector<float>   *ph_etas0;
      vector<float>   *ph_phis0;
      vector<float>   *ph_Es1;
      vector<float>   *ph_etas1;
      vector<float>   *ph_phis1;
      vector<float>   *ph_Es2;
      vector<float>   *ph_etas2;
      vector<float>   *ph_phis2;
      vector<float>   *ph_Es3;
      vector<float>   *ph_etas3;
      vector<float>   *ph_phis3;
      vector<float>   *ph_rawcl_Es0;
      vector<float>   *ph_rawcl_etas0;
      vector<float>   *ph_rawcl_phis0;
      vector<float>   *ph_rawcl_Es1;
      vector<float>   *ph_rawcl_etas1;
      vector<float>   *ph_rawcl_phis1;
      vector<float>   *ph_rawcl_Es2;
      vector<float>   *ph_rawcl_etas2;
      vector<float>   *ph_rawcl_phis2;
      vector<float>   *ph_rawcl_Es3;
      vector<float>   *ph_rawcl_etas3;
      vector<float>   *ph_rawcl_phis3;
      vector<float>   *ph_rawcl_E;
      vector<float>   *ph_rawcl_pt;
      vector<float>   *ph_rawcl_eta;
      vector<float>   *ph_rawcl_phi;
      vector<float>   *ph_deltaEmax2;
      vector<float>   *ph_calibHitsShowerDepth;
      vector<unsigned int> *ph_isIso;
      vector<float>   *ph_mvaptcone20;
      vector<float>   *ph_mvaptcone30;
      vector<float>   *ph_mvaptcone40;
      vector<float>   *ph_topoEtcone20;
      vector<float>   *ph_topoEtcone40;
      vector<float>   *ph_topoEtcone60;

      // List of branches
      TBranch        *b_RunNumber;   //!
      TBranch        *b_EventNumber;   //!
      TBranch        *b_timestamp;   //!
      TBranch        *b_timestamp_ns;   //!
      TBranch        *b_lbn;   //!
      TBranch        *b_bcid;   //!
      TBranch        *b_detmask0;   //!
      TBranch        *b_detmask1;   //!
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
      TBranch        *b_pixClus_n;   //!
      TBranch        *b_pixClus_id;   //!
      TBranch        *b_pixClus_bec;   //!
      TBranch        *b_pixClus_layer;   //!
      TBranch        *b_pixClus_detElementId;   //!
      TBranch        *b_pixClus_phi_module;   //!
      TBranch        *b_pixClus_eta_module;   //!
      TBranch        *b_pixClus_col;   //!
      TBranch        *b_pixClus_row;   //!
      TBranch        *b_pixClus_charge;   //!
      TBranch        *b_pixClus_LVL1A;   //!
      TBranch        *b_pixClus_sizePhi;   //!
      TBranch        *b_pixClus_sizeZ;   //!
      TBranch        *b_pixClus_size;   //!
      TBranch        *b_pixClus_locX;   //!
      TBranch        *b_pixClus_locY;   //!
      TBranch        *b_pixClus_x;   //!
      TBranch        *b_pixClus_y;   //!
      TBranch        *b_pixClus_z;   //!
      TBranch        *b_pixClus_isFake;   //!
      TBranch        *b_pixClus_isGanged;   //!
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
      TBranch        *b_TotalEt_n;   //!
      TBranch        *b_TotalEt_tower_eta;   //!
      TBranch        *b_TotalEt_tower_phi;   //!
      TBranch        *b_TotalEt_tower_area;   //!
      TBranch        *b_TotalEt_tower_sampling;   //!
      TBranch        *b_TotalEt_tower_sampling_calib;   //!
      TBranch        *b_TotalEt_layer_eta;   //!
      TBranch        *b_TotalEt_layer_phi;   //!
      TBranch        *b_TotalEt_layer_area;   //!
      TBranch        *b_TotalEt_layer_sampling;   //!
      TBranch        *b_TotalEt_layer_sampling_calib;   //!
      TBranch        *b_trk_n;   //!
      TBranch        *b_trk_pt;   //!
      TBranch        *b_trk_eta;   //!
      TBranch        *b_trk_d0_wrtPV;   //!
      TBranch        *b_trk_err_d0_wrtPV;   //!
      TBranch        *b_trk_z0_wrtPV;   //!
      TBranch        *b_trk_err_z0_wrtPV;   //!
      TBranch        *b_trk_phi_wrtPV;   //!
      TBranch        *b_trk_theta;   //!
      TBranch        *b_trk_err_theta_wrtPV;   //!
      TBranch        *b_trk_qoverp;   //!
      TBranch        *b_trk_cov_z0_theta_wrtPV;   //!
      TBranch        *b_trk_cov_d0_wrtPV;   //!
      TBranch        *b_trk_cov_z0_wrtPV;   //!
      TBranch        *b_trk_cov_phi_wrtPV;   //!
      TBranch        *b_trk_cov_theta_wrtPV;   //!
      TBranch        *b_trk_cov_qoverp_wrtPV;   //!
      TBranch        *b_trk_chi2;   //!
      TBranch        *b_trk_ndof;   //!
      TBranch        *b_trk_nBLHits;   //!
      TBranch        *b_trk_nPixHits;   //!
      TBranch        *b_trk_nSCTHits;   //!
      TBranch        *b_trk_nTRTHits;   //!
      TBranch        *b_trk_nPixHoles;   //!
      TBranch        *b_trk_nSCTHoles;   //!
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
      TBranch        *b_trk_pixeldEdx;   //!
      TBranch        *b_trk_fitter;   //!
      TBranch        *b_trk_patternReco1;   //!
      TBranch        *b_trk_patternReco2;   //!
      TBranch        *b_trk_seedFinder;   //!
      TBranch        *b_trk_expectBLayerHit;   //!
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
      TBranch        *b_pTrklets_n;   //!
      TBranch        *b_pTrklets_nBPixClus;   //!
      TBranch        *b_pTrklets_n1PixClus;   //!
      TBranch        *b_pTrklets_n2PixClus;   //!
      TBranch        *b_pTrklets_layerSum;   //!
      TBranch        *b_pTrklets_eta;   //!
      TBranch        *b_pTrklets_phi;   //!
      TBranch        *b_pTrklets_pt;   //!
      TBranch        *b_pTrklets_deta;   //!
      TBranch        *b_pTrklets_dphi;   //!
      TBranch        *b_pTrklets_etaS;   //!
      TBranch        *b_pTrklets_phiS;   //!
      TBranch        *b_pTrklets_energy0;   //!
      TBranch        *b_pTrklets_energy1;   //!
      TBranch        *b_pTrklets_cSize0;   //!
      TBranch        *b_pTrklets_cSize1;   //!
      TBranch        *b_pTrklets_cRowSize0;   //!
      TBranch        *b_pTrklets_cRowSize1;   //!
      TBranch        *b_pTrklets_cColSize0;   //!
      TBranch        *b_pTrklets_cColSize1;   //!
      TBranch        *b_pTrklets_clusIds;   //!
      TBranch        *b_trkPix_n;   //!
      TBranch        *b_trkPix_pt;   //!
      TBranch        *b_trkPix_eta;   //!
      TBranch        *b_trkPix_d0_wrtPV;   //!
      TBranch        *b_trkPix_z0_wrtPV;   //!
      TBranch        *b_trkPix_phi_wrtPV;   //!
      TBranch        *b_trkPix_theta_wrtPV;   //!
      TBranch        *b_trkPix_qoverp_wrtPV;   //!
      TBranch        *b_trkPix_cov_d0_wrtPV;   //!
      TBranch        *b_trkPix_cov_z0_wrtPV;   //!
      TBranch        *b_trkPix_cov_phi_wrtPV;   //!
      TBranch        *b_trkPix_cov_theta_wrtPV;   //!
      TBranch        *b_trkPix_cov_qoverp_wrtPV;   //!
      TBranch        *b_trkPix_chi2;   //!
      TBranch        *b_trkPix_ndof;   //!
      TBranch        *b_trkPix_nBLHits;   //!
      TBranch        *b_trkPix_nPixHits;   //!
      TBranch        *b_trkPix_nSCTHits;   //!
      TBranch        *b_trkPix_nTRTHits;   //!
      TBranch        *b_trkPix_nPixHoles;   //!
      TBranch        *b_trkPix_nSCTHoles;   //!
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
      TBranch        *b_trkPix_pixeldEdx;   //!
      TBranch        *b_trkPix_fitter;   //!
      TBranch        *b_trkPix_patternReco1;   //!
      TBranch        *b_trkPix_patternReco2;   //!
      TBranch        *b_trkPix_seedFinder;   //!
      TBranch        *b_trkPix_blayerPrediction_expectHit;   //!
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
      TBranch        *b_antikt4Tow_tower_CaloBkgrEt;   //!
      TBranch        *b_antikt4Tow_tower_CaloBkgrRMS;   //!
      TBranch        *b_antikt4Tow_tower_CaloBkgrCounts;   //!
      TBranch        *b_antikt4Tow_tower_CaloBkgrEta;   //!
      TBranch        *b_antikt4Tow_layer_CaloBkgrEt;   //!
      TBranch        *b_antikt4Tow_layer_CaloBkgrRMS;   //!
      TBranch        *b_antikt4Tow_layer_CaloBkgrCounts;   //!
      TBranch        *b_antikt4Tow_layer_CaloBkgrEta;   //!
      TBranch        *b_antikt4FlowTow_tower_CaloBkgrEt;   //!
      TBranch        *b_antikt4FlowTow_tower_CaloBkgrRMS;   //!
      TBranch        *b_antikt4FlowTow_tower_CaloBkgrCounts;   //!
      TBranch        *b_antikt4FlowTow_tower_CaloBkgrEta;   //!
      TBranch        *b_antikt4FlowTow_layer_CaloBkgrEt;   //!
      TBranch        *b_antikt4FlowTow_layer_CaloBkgrRMS;   //!
      TBranch        *b_antikt4FlowTow_layer_CaloBkgrCounts;   //!
      TBranch        *b_antikt4FlowTow_layer_CaloBkgrEta;   //!
      TBranch        *b_antikt4EMTow_tower_CaloBkgrEt;   //!
      TBranch        *b_antikt4EMTow_tower_CaloBkgrRMS;   //!
      TBranch        *b_antikt4EMTow_tower_CaloBkgrCounts;   //!
      TBranch        *b_antikt4EMTow_tower_CaloBkgrEta;   //!
      TBranch        *b_antikt4EMTow_layer_CaloBkgrEt;   //!
      TBranch        *b_antikt4EMTow_layer_CaloBkgrRMS;   //!
      TBranch        *b_antikt4EMTow_layer_CaloBkgrCounts;   //!
      TBranch        *b_antikt4EMTow_layer_CaloBkgrEta;   //!
      TBranch        *b_AvgTower_tower_CaloBkgrEt;   //!
      TBranch        *b_AvgTower_tower_CaloBkgrRMS;   //!
      TBranch        *b_AvgTower_tower_CaloBkgrCounts;   //!
      TBranch        *b_AvgTower_tower_CaloBkgrEta;   //!
      TBranch        *b_AvgTower_layer_CaloBkgrEt;   //!
      TBranch        *b_AvgTower_layer_CaloBkgrRMS;   //!
      TBranch        *b_AvgTower_layer_CaloBkgrCounts;   //!
      TBranch        *b_AvgTower_layer_CaloBkgrEta;   //!
      TBranch        *b_AvgTower3Sigma_tower_CaloBkgrEt;   //!
      TBranch        *b_AvgTower3Sigma_tower_CaloBkgrRMS;   //!
      TBranch        *b_AvgTower3Sigma_tower_CaloBkgrCounts;   //!
      TBranch        *b_AvgTower3Sigma_tower_CaloBkgrEta;   //!
      TBranch        *b_AvgTower4Sigma_tower_CaloBkgrEt;   //!
      TBranch        *b_AvgTower4Sigma_tower_CaloBkgrRMS;   //!
      TBranch        *b_AvgTower4Sigma_tower_CaloBkgrCounts;   //!
      TBranch        *b_AvgTower4Sigma_tower_CaloBkgrEta;   //!
      TBranch        *b_AvgTowerFlow_tower_CaloBkgrEt;   //!
      TBranch        *b_AvgTowerFlow_tower_CaloBkgrRMS;   //!
      TBranch        *b_AvgTowerFlow_tower_CaloBkgrCounts;   //!
      TBranch        *b_AvgTowerFlow_tower_CaloBkgrEta;   //!
      TBranch        *b_AvgTowerFlow_layer_CaloBkgrEt;   //!
      TBranch        *b_AvgTowerFlow_layer_CaloBkgrRMS;   //!
      TBranch        *b_AvgTowerFlow_layer_CaloBkgrCounts;   //!
      TBranch        *b_AvgTowerFlow_layer_CaloBkgrEta;   //!
      TBranch        *b_antikt4TowItr_tower_CaloBkgrEt;   //!
      TBranch        *b_antikt4TowItr_tower_CaloBkgrRMS;   //!
      TBranch        *b_antikt4TowItr_tower_CaloBkgrCounts;   //!
      TBranch        *b_antikt4TowItr_tower_CaloBkgrEta;   //!
      TBranch        *b_antikt4TowItr_layer_CaloBkgrEt;   //!
      TBranch        *b_antikt4TowItr_layer_CaloBkgrRMS;   //!
      TBranch        *b_antikt4TowItr_layer_CaloBkgrCounts;   //!
      TBranch        *b_antikt4TowItr_layer_CaloBkgrEta;   //!
      TBranch        *b_antikt4TowFlowItr_tower_CaloBkgrEt;   //!
      TBranch        *b_antikt4TowFlowItr_tower_CaloBkgrRMS;   //!
      TBranch        *b_antikt4TowFlowItr_tower_CaloBkgrCounts;   //!
      TBranch        *b_antikt4TowFlowItr_tower_CaloBkgrEta;   //!
      TBranch        *b_antikt4TowFlowItr_layer_CaloBkgrEt;   //!
      TBranch        *b_antikt4TowFlowItr_layer_CaloBkgrRMS;   //!
      TBranch        *b_antikt4TowFlowItr_layer_CaloBkgrCounts;   //!
      TBranch        *b_antikt4TowFlowItr_layer_CaloBkgrEta;   //!
      TBranch        *b_antikt4HI_n;   //!
      TBranch        *b_antikt4HI_E;   //!
      TBranch        *b_antikt4HI_pt;   //!
      TBranch        *b_antikt4HI_m;   //!
      TBranch        *b_antikt4HI_eta;   //!
      TBranch        *b_antikt4HI_phi;   //!
      TBranch        *b_antikt4HI_MaxOverMean;   //!
      TBranch        *b_antikt4HI_MeanTowerEt;   //!
      TBranch        *b_antikt4HI_SubtractedEt;   //!
      TBranch        *b_antikt4HI_RMSTowerEt;   //!
      TBranch        *b_antikt4HI_SumJt;   //!
      TBranch        *b_antikt4HI_CoreEt;   //!
      TBranch        *b_antikt4HI_EdgeEt;   //!
      TBranch        *b_antikt4HI_CryoCorr;   //!
      TBranch        *b_antikt4HI_NoFlow;   //!
      TBranch        *b_antikt4HI_NumConstituents;   //!
      TBranch        *b_antikt4HI_UncalibEt;   //!
      TBranch        *b_antikt4HI_Discriminant;   //!
      TBranch        *b_antikt4HI_MeanTowerEtUnsubtr;   //!
      TBranch        *b_antikt4HI_n90;   //!
      TBranch        *b_antikt4HI_fracSamplingMax;   //!
      TBranch        *b_antikt4HI_SamplingMax;   //!
      TBranch        *b_antikt4HI_n90constituents;   //!
      TBranch        *b_antikt4HI_Timing;   //!
      TBranch        *b_antikt4HI_LArQuality;   //!
      TBranch        *b_antikt4HI_HECQuality;   //!
      TBranch        *b_antikt4HI_TileQuality;   //!
      TBranch        *b_antikt4HI_const_n;   //!
      TBranch        *b_antikt4HI_const_et;   //!
      TBranch        *b_antikt4HI_const_eta;   //!
      TBranch        *b_antikt4HI_const_phi;   //!
      TBranch        *b_antikt4HI_sampling_et;   //!
      TBranch        *b_antikt4HI_sampling_et_unsubtr;   //!
      TBranch        *b_antikt4HI_bad_cell_n;   //!
      TBranch        *b_antikt4HI_bad_cell_et;   //!
      TBranch        *b_antikt4HI_bad_cell_area;   //!
      TBranch        *b_antikt4HI_empty_cell_n;   //!
      TBranch        *b_antikt4HI_empty_cell_et;   //!
      TBranch        *b_antikt4HI_empty_cell_area;   //!
      TBranch        *b_antikt4HI_total_cell_n;   //!
      TBranch        *b_antikt4HI_total_cell_et;   //!
      TBranch        *b_antikt4HI_total_cell_area;   //!
      TBranch        *b_antikt4HIFlow_n;   //!
      TBranch        *b_antikt4HIFlow_E;   //!
      TBranch        *b_antikt4HIFlow_pt;   //!
      TBranch        *b_antikt4HIFlow_m;   //!
      TBranch        *b_antikt4HIFlow_eta;   //!
      TBranch        *b_antikt4HIFlow_phi;   //!
      TBranch        *b_antikt4HIFlow_MaxOverMean;   //!
      TBranch        *b_antikt4HIFlow_MeanTowerEt;   //!
      TBranch        *b_antikt4HIFlow_SubtractedEt;   //!
      TBranch        *b_antikt4HIFlow_RMSTowerEt;   //!
      TBranch        *b_antikt4HIFlow_SumJt;   //!
      TBranch        *b_antikt4HIFlow_CoreEt;   //!
      TBranch        *b_antikt4HIFlow_EdgeEt;   //!
      TBranch        *b_antikt4HIFlow_CryoCorr;   //!
      TBranch        *b_antikt4HIFlow_NoFlow;   //!
      TBranch        *b_antikt4HIFlow_NumConstituents;   //!
      TBranch        *b_antikt4HIFlow_UncalibEt;   //!
      TBranch        *b_antikt4HIFlow_Discriminant;   //!
      TBranch        *b_antikt4HIFlow_MeanTowerEtUnsubtr;   //!
      TBranch        *b_antikt4HIFlow_n90;   //!
      TBranch        *b_antikt4HIFlow_fracSamplingMax;   //!
      TBranch        *b_antikt4HIFlow_SamplingMax;   //!
      TBranch        *b_antikt4HIFlow_n90constituents;   //!
      TBranch        *b_antikt4HIFlow_Timing;   //!
      TBranch        *b_antikt4HIFlow_LArQuality;   //!
      TBranch        *b_antikt4HIFlow_HECQuality;   //!
      TBranch        *b_antikt4HIFlow_TileQuality;   //!
      TBranch        *b_antikt4HIFlow_const_n;   //!
      TBranch        *b_antikt4HIFlow_const_et;   //!
      TBranch        *b_antikt4HIFlow_const_eta;   //!
      TBranch        *b_antikt4HIFlow_const_phi;   //!
      TBranch        *b_antikt4HIFlow_sampling_et;   //!
      TBranch        *b_antikt4HIFlow_sampling_et_unsubtr;   //!
      TBranch        *b_antikt4HIFlow_bad_cell_n;   //!
      TBranch        *b_antikt4HIFlow_bad_cell_et;   //!
      TBranch        *b_antikt4HIFlow_bad_cell_area;   //!
      TBranch        *b_antikt4HIFlow_empty_cell_n;   //!
      TBranch        *b_antikt4HIFlow_empty_cell_et;   //!
      TBranch        *b_antikt4HIFlow_empty_cell_area;   //!
      TBranch        *b_antikt4HIFlow_total_cell_n;   //!
      TBranch        *b_antikt4HIFlow_total_cell_et;   //!
      TBranch        *b_antikt4HIFlow_total_cell_area;   //!
      TBranch        *b_antikt4HIAvgFlow_n;   //!
      TBranch        *b_antikt4HIAvgFlow_E;   //!
      TBranch        *b_antikt4HIAvgFlow_pt;   //!
      TBranch        *b_antikt4HIAvgFlow_m;   //!
      TBranch        *b_antikt4HIAvgFlow_eta;   //!
      TBranch        *b_antikt4HIAvgFlow_phi;   //!
      TBranch        *b_antikt4HIAvgFlow_MaxOverMean;   //!
      TBranch        *b_antikt4HIAvgFlow_MeanTowerEt;   //!
      TBranch        *b_antikt4HIAvgFlow_SubtractedEt;   //!
      TBranch        *b_antikt4HIAvgFlow_RMSTowerEt;   //!
      TBranch        *b_antikt4HIAvgFlow_SumJt;   //!
      TBranch        *b_antikt4HIAvgFlow_CoreEt;   //!
      TBranch        *b_antikt4HIAvgFlow_EdgeEt;   //!
      TBranch        *b_antikt4HIAvgFlow_CryoCorr;   //!
      TBranch        *b_antikt4HIAvgFlow_NoFlow;   //!
      TBranch        *b_antikt4HIAvgFlow_NumConstituents;   //!
      TBranch        *b_antikt4HIAvgFlow_UncalibEt;   //!
      TBranch        *b_antikt4HIAvgFlow_Discriminant;   //!
      TBranch        *b_antikt4HIAvgFlow_MeanTowerEtUnsubtr;   //!
      TBranch        *b_antikt4HIAvgFlow_n90;   //!
      TBranch        *b_antikt4HIAvgFlow_fracSamplingMax;   //!
      TBranch        *b_antikt4HIAvgFlow_SamplingMax;   //!
      TBranch        *b_antikt4HIAvgFlow_n90constituents;   //!
      TBranch        *b_antikt4HIAvgFlow_Timing;   //!
      TBranch        *b_antikt4HIAvgFlow_LArQuality;   //!
      TBranch        *b_antikt4HIAvgFlow_HECQuality;   //!
      TBranch        *b_antikt4HIAvgFlow_TileQuality;   //!
      TBranch        *b_antikt4HIAvgFlow_const_n;   //!
      TBranch        *b_antikt4HIAvgFlow_const_et;   //!
      TBranch        *b_antikt4HIAvgFlow_const_eta;   //!
      TBranch        *b_antikt4HIAvgFlow_const_phi;   //!
      TBranch        *b_antikt4HIAvgFlow_sampling_et;   //!
      TBranch        *b_antikt4HIAvgFlow_sampling_et_unsubtr;   //!
      TBranch        *b_antikt4HIAvgFlow_bad_cell_n;   //!
      TBranch        *b_antikt4HIAvgFlow_bad_cell_et;   //!
      TBranch        *b_antikt4HIAvgFlow_bad_cell_area;   //!
      TBranch        *b_antikt4HIAvgFlow_empty_cell_n;   //!
      TBranch        *b_antikt4HIAvgFlow_empty_cell_et;   //!
      TBranch        *b_antikt4HIAvgFlow_empty_cell_area;   //!
      TBranch        *b_antikt4HIAvgFlow_total_cell_n;   //!
      TBranch        *b_antikt4HIAvgFlow_total_cell_et;   //!
      TBranch        *b_antikt4HIAvgFlow_total_cell_area;   //!
      TBranch        *b_antikt4HIItr_n;   //!
      TBranch        *b_antikt4HIItr_E;   //!
      TBranch        *b_antikt4HIItr_pt;   //!
      TBranch        *b_antikt4HIItr_m;   //!
      TBranch        *b_antikt4HIItr_eta;   //!
      TBranch        *b_antikt4HIItr_phi;   //!
      TBranch        *b_antikt4HIItr_MaxOverMean;   //!
      TBranch        *b_antikt4HIItr_MeanTowerEt;   //!
      TBranch        *b_antikt4HIItr_SubtractedEt;   //!
      TBranch        *b_antikt4HIItr_RMSTowerEt;   //!
      TBranch        *b_antikt4HIItr_SumJt;   //!
      TBranch        *b_antikt4HIItr_CoreEt;   //!
      TBranch        *b_antikt4HIItr_EdgeEt;   //!
      TBranch        *b_antikt4HIItr_CryoCorr;   //!
      TBranch        *b_antikt4HIItr_NoFlow;   //!
      TBranch        *b_antikt4HIItr_NumConstituents;   //!
      TBranch        *b_antikt4HIItr_UncalibEt;   //!
      TBranch        *b_antikt4HIItr_Discriminant;   //!
      TBranch        *b_antikt4HIItr_MeanTowerEtUnsubtr;   //!
      TBranch        *b_antikt4HIItr_n90;   //!
      TBranch        *b_antikt4HIItr_fracSamplingMax;   //!
      TBranch        *b_antikt4HIItr_SamplingMax;   //!
      TBranch        *b_antikt4HIItr_n90constituents;   //!
      TBranch        *b_antikt4HIItr_Timing;   //!
      TBranch        *b_antikt4HIItr_LArQuality;   //!
      TBranch        *b_antikt4HIItr_HECQuality;   //!
      TBranch        *b_antikt4HIItr_TileQuality;   //!
      TBranch        *b_antikt4HIItr_const_n;   //!
      TBranch        *b_antikt4HIItr_const_et;   //!
      TBranch        *b_antikt4HIItr_const_eta;   //!
      TBranch        *b_antikt4HIItr_const_phi;   //!
      TBranch        *b_antikt4HIItr_sampling_et;   //!
      TBranch        *b_antikt4HIItr_sampling_et_unsubtr;   //!
      TBranch        *b_antikt4HIItr_bad_cell_n;   //!
      TBranch        *b_antikt4HIItr_bad_cell_et;   //!
      TBranch        *b_antikt4HIItr_bad_cell_area;   //!
      TBranch        *b_antikt4HIItr_empty_cell_n;   //!
      TBranch        *b_antikt4HIItr_empty_cell_et;   //!
      TBranch        *b_antikt4HIItr_empty_cell_area;   //!
      TBranch        *b_antikt4HIItr_total_cell_n;   //!
      TBranch        *b_antikt4HIItr_total_cell_et;   //!
      TBranch        *b_antikt4HIItr_total_cell_area;   //!
      TBranch        *b_antikt4HIItrFlow_n;   //!
      TBranch        *b_antikt4HIItrFlow_E;   //!
      TBranch        *b_antikt4HIItrFlow_pt;   //!
      TBranch        *b_antikt4HIItrFlow_m;   //!
      TBranch        *b_antikt4HIItrFlow_eta;   //!
      TBranch        *b_antikt4HIItrFlow_phi;   //!
      TBranch        *b_antikt4HIItrFlow_MaxOverMean;   //!
      TBranch        *b_antikt4HIItrFlow_MeanTowerEt;   //!
      TBranch        *b_antikt4HIItrFlow_SubtractedEt;   //!
      TBranch        *b_antikt4HIItrFlow_RMSTowerEt;   //!
      TBranch        *b_antikt4HIItrFlow_SumJt;   //!
      TBranch        *b_antikt4HIItrFlow_CoreEt;   //!
      TBranch        *b_antikt4HIItrFlow_EdgeEt;   //!
      TBranch        *b_antikt4HIItrFlow_CryoCorr;   //!
      TBranch        *b_antikt4HIItrFlow_NoFlow;   //!
      TBranch        *b_antikt4HIItrFlow_NumConstituents;   //!
      TBranch        *b_antikt4HIItrFlow_UncalibEt;   //!
      TBranch        *b_antikt4HIItrFlow_Discriminant;   //!
      TBranch        *b_antikt4HIItrFlow_MeanTowerEtUnsubtr;   //!
      TBranch        *b_antikt4HIItrFlow_n90;   //!
      TBranch        *b_antikt4HIItrFlow_fracSamplingMax;   //!
      TBranch        *b_antikt4HIItrFlow_SamplingMax;   //!
      TBranch        *b_antikt4HIItrFlow_n90constituents;   //!
      TBranch        *b_antikt4HIItrFlow_Timing;   //!
      TBranch        *b_antikt4HIItrFlow_LArQuality;   //!
      TBranch        *b_antikt4HIItrFlow_HECQuality;   //!
      TBranch        *b_antikt4HIItrFlow_TileQuality;   //!
      TBranch        *b_antikt4HIItrFlow_const_n;   //!
      TBranch        *b_antikt4HIItrFlow_const_et;   //!
      TBranch        *b_antikt4HIItrFlow_const_eta;   //!
      TBranch        *b_antikt4HIItrFlow_const_phi;   //!
      TBranch        *b_antikt4HIItrFlow_sampling_et;   //!
      TBranch        *b_antikt4HIItrFlow_sampling_et_unsubtr;   //!
      TBranch        *b_antikt4HIItrFlow_bad_cell_n;   //!
      TBranch        *b_antikt4HIItrFlow_bad_cell_et;   //!
      TBranch        *b_antikt4HIItrFlow_bad_cell_area;   //!
      TBranch        *b_antikt4HIItrFlow_empty_cell_n;   //!
      TBranch        *b_antikt4HIItrFlow_empty_cell_et;   //!
      TBranch        *b_antikt4HIItrFlow_empty_cell_area;   //!
      TBranch        *b_antikt4HIItrFlow_total_cell_n;   //!
      TBranch        *b_antikt4HIItrFlow_total_cell_et;   //!
      TBranch        *b_antikt4HIItrFlow_total_cell_area;   //!
      TBranch        *b_antikt2HIAvg_n;   //!
      TBranch        *b_antikt2HIAvg_E;   //!
      TBranch        *b_antikt2HIAvg_pt;   //!
      TBranch        *b_antikt2HIAvg_m;   //!
      TBranch        *b_antikt2HIAvg_eta;   //!
      TBranch        *b_antikt2HIAvg_phi;   //!
      TBranch        *b_antikt2HIAvg_MaxOverMean;   //!
      TBranch        *b_antikt2HIAvg_MeanTowerEt;   //!
      TBranch        *b_antikt2HIAvg_SubtractedEt;   //!
      TBranch        *b_antikt2HIAvg_RMSTowerEt;   //!
      TBranch        *b_antikt2HIAvg_SumJt;   //!
      TBranch        *b_antikt2HIAvg_CoreEt;   //!
      TBranch        *b_antikt2HIAvg_EdgeEt;   //!
      TBranch        *b_antikt2HIAvg_CryoCorr;   //!
      TBranch        *b_antikt2HIAvg_NoFlow;   //!
      TBranch        *b_antikt2HIAvg_NumConstituents;   //!
      TBranch        *b_antikt2HIAvg_UncalibEt;   //!
      TBranch        *b_antikt2HIAvg_Discriminant;   //!
      TBranch        *b_antikt2HIAvg_MeanTowerEtUnsubtr;   //!
      TBranch        *b_antikt2HIAvg_n90;   //!
      TBranch        *b_antikt2HIAvg_fracSamplingMax;   //!
      TBranch        *b_antikt2HIAvg_SamplingMax;   //!
      TBranch        *b_antikt2HIAvg_n90constituents;   //!
      TBranch        *b_antikt2HIAvg_Timing;   //!
      TBranch        *b_antikt2HIAvg_LArQuality;   //!
      TBranch        *b_antikt2HIAvg_HECQuality;   //!
      TBranch        *b_antikt2HIAvg_TileQuality;   //!
      TBranch        *b_antikt2HIAvg_const_n;   //!
      TBranch        *b_antikt2HIAvg_const_et;   //!
      TBranch        *b_antikt2HIAvg_const_eta;   //!
      TBranch        *b_antikt2HIAvg_const_phi;   //!
      TBranch        *b_antikt2HIAvg_sampling_et;   //!
      TBranch        *b_antikt2HIAvg_sampling_et_unsubtr;   //!
      TBranch        *b_antikt2HIAvg_bad_cell_n;   //!
      TBranch        *b_antikt2HIAvg_bad_cell_et;   //!
      TBranch        *b_antikt2HIAvg_bad_cell_area;   //!
      TBranch        *b_antikt2HIAvg_empty_cell_n;   //!
      TBranch        *b_antikt2HIAvg_empty_cell_et;   //!
      TBranch        *b_antikt2HIAvg_empty_cell_area;   //!
      TBranch        *b_antikt2HIAvg_total_cell_n;   //!
      TBranch        *b_antikt2HIAvg_total_cell_et;   //!
      TBranch        *b_antikt2HIAvg_total_cell_area;   //!
      TBranch        *b_antikt4HIAvg_n;   //!
      TBranch        *b_antikt4HIAvg_E;   //!
      TBranch        *b_antikt4HIAvg_pt;   //!
      TBranch        *b_antikt4HIAvg_m;   //!
      TBranch        *b_antikt4HIAvg_eta;   //!
      TBranch        *b_antikt4HIAvg_phi;   //!
      TBranch        *b_antikt4HIAvg_MaxOverMean;   //!
      TBranch        *b_antikt4HIAvg_MeanTowerEt;   //!
      TBranch        *b_antikt4HIAvg_SubtractedEt;   //!
      TBranch        *b_antikt4HIAvg_RMSTowerEt;   //!
      TBranch        *b_antikt4HIAvg_SumJt;   //!
      TBranch        *b_antikt4HIAvg_CoreEt;   //!
      TBranch        *b_antikt4HIAvg_EdgeEt;   //!
      TBranch        *b_antikt4HIAvg_CryoCorr;   //!
      TBranch        *b_antikt4HIAvg_NoFlow;   //!
      TBranch        *b_antikt4HIAvg_NumConstituents;   //!
      TBranch        *b_antikt4HIAvg_UncalibEt;   //!
      TBranch        *b_antikt4HIAvg_Discriminant;   //!
      TBranch        *b_antikt4HIAvg_MeanTowerEtUnsubtr;   //!
      TBranch        *b_antikt4HIAvg_n90;   //!
      TBranch        *b_antikt4HIAvg_fracSamplingMax;   //!
      TBranch        *b_antikt4HIAvg_SamplingMax;   //!
      TBranch        *b_antikt4HIAvg_n90constituents;   //!
      TBranch        *b_antikt4HIAvg_Timing;   //!
      TBranch        *b_antikt4HIAvg_LArQuality;   //!
      TBranch        *b_antikt4HIAvg_HECQuality;   //!
      TBranch        *b_antikt4HIAvg_TileQuality;   //!
      TBranch        *b_antikt4HIAvg_const_n;   //!
      TBranch        *b_antikt4HIAvg_const_et;   //!
      TBranch        *b_antikt4HIAvg_const_eta;   //!
      TBranch        *b_antikt4HIAvg_const_phi;   //!
      TBranch        *b_antikt4HIAvg_sampling_et;   //!
      TBranch        *b_antikt4HIAvg_sampling_et_unsubtr;   //!
      TBranch        *b_antikt4HIAvg_bad_cell_n;   //!
      TBranch        *b_antikt4HIAvg_bad_cell_et;   //!
      TBranch        *b_antikt4HIAvg_bad_cell_area;   //!
      TBranch        *b_antikt4HIAvg_empty_cell_n;   //!
      TBranch        *b_antikt4HIAvg_empty_cell_et;   //!
      TBranch        *b_antikt4HIAvg_empty_cell_area;   //!
      TBranch        *b_antikt4HIAvg_total_cell_n;   //!
      TBranch        *b_antikt4HIAvg_total_cell_et;   //!
      TBranch        *b_antikt4HIAvg_total_cell_area;   //!
      TBranch        *b_antikt6HIAvg_n;   //!
      TBranch        *b_antikt6HIAvg_E;   //!
      TBranch        *b_antikt6HIAvg_pt;   //!
      TBranch        *b_antikt6HIAvg_m;   //!
      TBranch        *b_antikt6HIAvg_eta;   //!
      TBranch        *b_antikt6HIAvg_phi;   //!
      TBranch        *b_antikt6HIAvg_MaxOverMean;   //!
      TBranch        *b_antikt6HIAvg_MeanTowerEt;   //!
      TBranch        *b_antikt6HIAvg_SubtractedEt;   //!
      TBranch        *b_antikt6HIAvg_RMSTowerEt;   //!
      TBranch        *b_antikt6HIAvg_SumJt;   //!
      TBranch        *b_antikt6HIAvg_CoreEt;   //!
      TBranch        *b_antikt6HIAvg_EdgeEt;   //!
      TBranch        *b_antikt6HIAvg_CryoCorr;   //!
      TBranch        *b_antikt6HIAvg_NoFlow;   //!
      TBranch        *b_antikt6HIAvg_NumConstituents;   //!
      TBranch        *b_antikt6HIAvg_UncalibEt;   //!
      TBranch        *b_antikt6HIAvg_Discriminant;   //!
      TBranch        *b_antikt6HIAvg_MeanTowerEtUnsubtr;   //!
      TBranch        *b_antikt6HIAvg_n90;   //!
      TBranch        *b_antikt6HIAvg_fracSamplingMax;   //!
      TBranch        *b_antikt6HIAvg_SamplingMax;   //!
      TBranch        *b_antikt6HIAvg_n90constituents;   //!
      TBranch        *b_antikt6HIAvg_Timing;   //!
      TBranch        *b_antikt6HIAvg_LArQuality;   //!
      TBranch        *b_antikt6HIAvg_HECQuality;   //!
      TBranch        *b_antikt6HIAvg_TileQuality;   //!
      TBranch        *b_antikt6HIAvg_const_n;   //!
      TBranch        *b_antikt6HIAvg_const_et;   //!
      TBranch        *b_antikt6HIAvg_const_eta;   //!
      TBranch        *b_antikt6HIAvg_const_phi;   //!
      TBranch        *b_antikt6HIAvg_sampling_et;   //!
      TBranch        *b_antikt6HIAvg_sampling_et_unsubtr;   //!
      TBranch        *b_antikt6HIAvg_bad_cell_n;   //!
      TBranch        *b_antikt6HIAvg_bad_cell_et;   //!
      TBranch        *b_antikt6HIAvg_bad_cell_area;   //!
      TBranch        *b_antikt6HIAvg_empty_cell_n;   //!
      TBranch        *b_antikt6HIAvg_empty_cell_et;   //!
      TBranch        *b_antikt6HIAvg_empty_cell_area;   //!
      TBranch        *b_antikt6HIAvg_total_cell_n;   //!
      TBranch        *b_antikt6HIAvg_total_cell_et;   //!
      TBranch        *b_antikt6HIAvg_total_cell_area;   //!
      TBranch        *b_antikt4HIEM_n;   //!
      TBranch        *b_antikt4HIEM_E;   //!
      TBranch        *b_antikt4HIEM_pt;   //!
      TBranch        *b_antikt4HIEM_m;   //!
      TBranch        *b_antikt4HIEM_eta;   //!
      TBranch        *b_antikt4HIEM_phi;   //!
      TBranch        *b_antikt4HIEM_MaxOverMean;   //!
      TBranch        *b_antikt4HIEM_MeanTowerEt;   //!
      TBranch        *b_antikt4HIEM_SubtractedEt;   //!
      TBranch        *b_antikt4HIEM_RMSTowerEt;   //!
      TBranch        *b_antikt4HIEM_SumJt;   //!
      TBranch        *b_antikt4HIEM_CoreEt;   //!
      TBranch        *b_antikt4HIEM_EdgeEt;   //!
      TBranch        *b_antikt4HIEM_CryoCorr;   //!
      TBranch        *b_antikt4HIEM_NoFlow;   //!
      TBranch        *b_antikt4HIEM_NumConstituents;   //!
      TBranch        *b_antikt4HIEM_UncalibEt;   //!
      TBranch        *b_antikt4HIEM_Discriminant;   //!
      TBranch        *b_antikt4HIEM_MeanTowerEtUnsubtr;   //!
      TBranch        *b_antikt4HIEM_n90;   //!
      TBranch        *b_antikt4HIEM_fracSamplingMax;   //!
      TBranch        *b_antikt4HIEM_SamplingMax;   //!
      TBranch        *b_antikt4HIEM_n90constituents;   //!
      TBranch        *b_antikt4HIEM_Timing;   //!
      TBranch        *b_antikt4HIEM_LArQuality;   //!
      TBranch        *b_antikt4HIEM_HECQuality;   //!
      TBranch        *b_antikt4HIEM_TileQuality;   //!
      TBranch        *b_antikt4HIEM_const_n;   //!
      TBranch        *b_antikt4HIEM_const_et;   //!
      TBranch        *b_antikt4HIEM_const_eta;   //!
      TBranch        *b_antikt4HIEM_const_phi;   //!
      TBranch        *b_antikt4HIEM_sampling_et;   //!
      TBranch        *b_antikt4HIEM_sampling_et_unsubtr;   //!
      TBranch        *b_antikt4HIEM_bad_cell_n;   //!
      TBranch        *b_antikt4HIEM_bad_cell_et;   //!
      TBranch        *b_antikt4HIEM_bad_cell_area;   //!
      TBranch        *b_antikt4HIEM_empty_cell_n;   //!
      TBranch        *b_antikt4HIEM_empty_cell_et;   //!
      TBranch        *b_antikt4HIEM_empty_cell_area;   //!
      TBranch        *b_antikt4HIEM_total_cell_n;   //!
      TBranch        *b_antikt4HIEM_total_cell_et;   //!
      TBranch        *b_antikt4HIEM_total_cell_area;   //!
      TBranch        *b_jetSeed_n;   //!
      TBranch        *b_jetSeed_E;   //!
      TBranch        *b_jetSeed_pt;   //!
      TBranch        *b_jetSeed_m;   //!
      TBranch        *b_jetSeed_eta;   //!
      TBranch        *b_jetSeed_phi;   //!
      TBranch        *b_jetSeed3Sigma_n;   //!
      TBranch        *b_jetSeed3Sigma_E;   //!
      TBranch        *b_jetSeed3Sigma_pt;   //!
      TBranch        *b_jetSeed3Sigma_m;   //!
      TBranch        *b_jetSeed3Sigma_eta;   //!
      TBranch        *b_jetSeed3Sigma_phi;   //!
      TBranch        *b_jetSeed4Sigma_n;   //!
      TBranch        *b_jetSeed4Sigma_E;   //!
      TBranch        *b_jetSeed4Sigma_pt;   //!
      TBranch        *b_jetSeed4Sigma_m;   //!
      TBranch        *b_jetSeed4Sigma_eta;   //!
      TBranch        *b_jetSeed4Sigma_phi;   //!
      TBranch        *b_cone2HI_n;   //!
      TBranch        *b_cone2HI_E;   //!
      TBranch        *b_cone2HI_pt;   //!
      TBranch        *b_cone2HI_m;   //!
      TBranch        *b_cone2HI_eta;   //!
      TBranch        *b_cone2HI_phi;   //!
      TBranch        *b_cone2HI_MaxOverMean;   //!
      TBranch        *b_cone2HI_MeanTowerEt;   //!
      TBranch        *b_cone2HI_SubtractedEt;   //!
      TBranch        *b_cone2HI_RMSTowerEt;   //!
      TBranch        *b_cone2HI_SumJt;   //!
      TBranch        *b_cone2HI_CoreEt;   //!
      TBranch        *b_cone2HI_EdgeEt;   //!
      TBranch        *b_cone2HI_CryoCorr;   //!
      TBranch        *b_cone2HI_NoFlow;   //!
      TBranch        *b_cone2HI_NumConstituents;   //!
      TBranch        *b_cone2HI_UncalibEt;   //!
      TBranch        *b_cone2HI_Discriminant;   //!
      TBranch        *b_cone2HI_MeanTowerEtUnsubtr;   //!
      TBranch        *b_cone2HI_n90;   //!
      TBranch        *b_cone2HI_fracSamplingMax;   //!
      TBranch        *b_cone2HI_SamplingMax;   //!
      TBranch        *b_cone2HI_n90constituents;   //!
      TBranch        *b_cone2HI_Timing;   //!
      TBranch        *b_cone2HI_LArQuality;   //!
      TBranch        *b_cone2HI_HECQuality;   //!
      TBranch        *b_cone2HI_TileQuality;   //!
      TBranch        *b_cone2HI_const_n;   //!
      TBranch        *b_cone2HI_const_et;   //!
      TBranch        *b_cone2HI_const_eta;   //!
      TBranch        *b_cone2HI_const_phi;   //!
      TBranch        *b_cone2HI_sampling_et;   //!
      TBranch        *b_cone2HI_sampling_et_unsubtr;   //!
      TBranch        *b_cone2HI_bad_cell_n;   //!
      TBranch        *b_cone2HI_bad_cell_et;   //!
      TBranch        *b_cone2HI_bad_cell_area;   //!
      TBranch        *b_cone2HI_empty_cell_n;   //!
      TBranch        *b_cone2HI_empty_cell_et;   //!
      TBranch        *b_cone2HI_empty_cell_area;   //!
      TBranch        *b_cone2HI_total_cell_n;   //!
      TBranch        *b_cone2HI_total_cell_et;   //!
      TBranch        *b_cone2HI_total_cell_area;   //!
      TBranch        *b_cone4HI_n;   //!
      TBranch        *b_cone4HI_E;   //!
      TBranch        *b_cone4HI_pt;   //!
      TBranch        *b_cone4HI_m;   //!
      TBranch        *b_cone4HI_eta;   //!
      TBranch        *b_cone4HI_phi;   //!
      TBranch        *b_cone4HI_MaxOverMean;   //!
      TBranch        *b_cone4HI_MeanTowerEt;   //!
      TBranch        *b_cone4HI_SubtractedEt;   //!
      TBranch        *b_cone4HI_RMSTowerEt;   //!
      TBranch        *b_cone4HI_SumJt;   //!
      TBranch        *b_cone4HI_CoreEt;   //!
      TBranch        *b_cone4HI_EdgeEt;   //!
      TBranch        *b_cone4HI_CryoCorr;   //!
      TBranch        *b_cone4HI_NoFlow;   //!
      TBranch        *b_cone4HI_NumConstituents;   //!
      TBranch        *b_cone4HI_UncalibEt;   //!
      TBranch        *b_cone4HI_Discriminant;   //!
      TBranch        *b_cone4HI_MeanTowerEtUnsubtr;   //!
      TBranch        *b_cone4HI_n90;   //!
      TBranch        *b_cone4HI_fracSamplingMax;   //!
      TBranch        *b_cone4HI_SamplingMax;   //!
      TBranch        *b_cone4HI_n90constituents;   //!
      TBranch        *b_cone4HI_Timing;   //!
      TBranch        *b_cone4HI_LArQuality;   //!
      TBranch        *b_cone4HI_HECQuality;   //!
      TBranch        *b_cone4HI_TileQuality;   //!
      TBranch        *b_cone4HI_const_n;   //!
      TBranch        *b_cone4HI_const_et;   //!
      TBranch        *b_cone4HI_const_eta;   //!
      TBranch        *b_cone4HI_const_phi;   //!
      TBranch        *b_cone4HI_sampling_et;   //!
      TBranch        *b_cone4HI_sampling_et_unsubtr;   //!
      TBranch        *b_cone4HI_bad_cell_n;   //!
      TBranch        *b_cone4HI_bad_cell_et;   //!
      TBranch        *b_cone4HI_bad_cell_area;   //!
      TBranch        *b_cone4HI_empty_cell_n;   //!
      TBranch        *b_cone4HI_empty_cell_et;   //!
      TBranch        *b_cone4HI_empty_cell_area;   //!
      TBranch        *b_cone4HI_total_cell_n;   //!
      TBranch        *b_cone4HI_total_cell_et;   //!
      TBranch        *b_cone4HI_total_cell_area;   //!
      TBranch        *b_cone6HI_n;   //!
      TBranch        *b_cone6HI_E;   //!
      TBranch        *b_cone6HI_pt;   //!
      TBranch        *b_cone6HI_m;   //!
      TBranch        *b_cone6HI_eta;   //!
      TBranch        *b_cone6HI_phi;   //!
      TBranch        *b_cone6HI_MaxOverMean;   //!
      TBranch        *b_cone6HI_MeanTowerEt;   //!
      TBranch        *b_cone6HI_SubtractedEt;   //!
      TBranch        *b_cone6HI_RMSTowerEt;   //!
      TBranch        *b_cone6HI_SumJt;   //!
      TBranch        *b_cone6HI_CoreEt;   //!
      TBranch        *b_cone6HI_EdgeEt;   //!
      TBranch        *b_cone6HI_CryoCorr;   //!
      TBranch        *b_cone6HI_NoFlow;   //!
      TBranch        *b_cone6HI_NumConstituents;   //!
      TBranch        *b_cone6HI_UncalibEt;   //!
      TBranch        *b_cone6HI_Discriminant;   //!
      TBranch        *b_cone6HI_MeanTowerEtUnsubtr;   //!
      TBranch        *b_cone6HI_n90;   //!
      TBranch        *b_cone6HI_fracSamplingMax;   //!
      TBranch        *b_cone6HI_SamplingMax;   //!
      TBranch        *b_cone6HI_n90constituents;   //!
      TBranch        *b_cone6HI_Timing;   //!
      TBranch        *b_cone6HI_LArQuality;   //!
      TBranch        *b_cone6HI_HECQuality;   //!
      TBranch        *b_cone6HI_TileQuality;   //!
      TBranch        *b_cone6HI_const_n;   //!
      TBranch        *b_cone6HI_const_et;   //!
      TBranch        *b_cone6HI_const_eta;   //!
      TBranch        *b_cone6HI_const_phi;   //!
      TBranch        *b_cone6HI_sampling_et;   //!
      TBranch        *b_cone6HI_sampling_et_unsubtr;   //!
      TBranch        *b_cone6HI_bad_cell_n;   //!
      TBranch        *b_cone6HI_bad_cell_et;   //!
      TBranch        *b_cone6HI_bad_cell_area;   //!
      TBranch        *b_cone6HI_empty_cell_n;   //!
      TBranch        *b_cone6HI_empty_cell_et;   //!
      TBranch        *b_cone6HI_empty_cell_area;   //!
      TBranch        *b_cone6HI_total_cell_n;   //!
      TBranch        *b_cone6HI_total_cell_et;   //!
      TBranch        *b_cone6HI_total_cell_area;   //!
      TBranch        *b_CMSCone4HI_n;   //!
      TBranch        *b_CMSCone4HI_E;   //!
      TBranch        *b_CMSCone4HI_pt;   //!
      TBranch        *b_CMSCone4HI_m;   //!
      TBranch        *b_CMSCone4HI_eta;   //!
      TBranch        *b_CMSCone4HI_phi;   //!
      TBranch        *b_CMSCone4HI_MaxOverMean;   //!
      TBranch        *b_CMSCone4HI_MeanTowerEt;   //!
      TBranch        *b_CMSCone4HI_SubtractedEt;   //!
      TBranch        *b_CMSCone4HI_RMSTowerEt;   //!
      TBranch        *b_CMSCone4HI_SumJt;   //!
      TBranch        *b_CMSCone4HI_CoreEt;   //!
      TBranch        *b_CMSCone4HI_EdgeEt;   //!
      TBranch        *b_CMSCone4HI_CryoCorr;   //!
      TBranch        *b_CMSCone4HI_NoFlow;   //!
      TBranch        *b_CMSCone4HI_NumConstituents;   //!
      TBranch        *b_CMSCone4HI_UncalibEt;   //!
      TBranch        *b_CMSCone4HI_Discriminant;   //!
      TBranch        *b_CMSCone4HI_MeanTowerEtUnsubtr;   //!
      TBranch        *b_CMSCone4HI_n90;   //!
      TBranch        *b_CMSCone4HI_fracSamplingMax;   //!
      TBranch        *b_CMSCone4HI_SamplingMax;   //!
      TBranch        *b_CMSCone4HI_n90constituents;   //!
      TBranch        *b_CMSCone4HI_Timing;   //!
      TBranch        *b_CMSCone4HI_LArQuality;   //!
      TBranch        *b_CMSCone4HI_HECQuality;   //!
      TBranch        *b_CMSCone4HI_TileQuality;   //!
      TBranch        *b_CMSCone4HI_const_n;   //!
      TBranch        *b_CMSCone4HI_const_et;   //!
      TBranch        *b_CMSCone4HI_const_eta;   //!
      TBranch        *b_CMSCone4HI_const_phi;   //!
      TBranch        *b_CMSCone4HI_sampling_et;   //!
      TBranch        *b_CMSCone4HI_sampling_et_unsubtr;   //!
      TBranch        *b_CMSCone4HI_bad_cell_n;   //!
      TBranch        *b_CMSCone4HI_bad_cell_et;   //!
      TBranch        *b_CMSCone4HI_bad_cell_area;   //!
      TBranch        *b_CMSCone4HI_empty_cell_n;   //!
      TBranch        *b_CMSCone4HI_empty_cell_et;   //!
      TBranch        *b_CMSCone4HI_empty_cell_area;   //!
      TBranch        *b_CMSCone4HI_total_cell_n;   //!
      TBranch        *b_CMSCone4HI_total_cell_et;   //!
      TBranch        *b_CMSCone4HI_total_cell_area;   //!
      TBranch        *b_antikt4Track_n;   //!
      TBranch        *b_antikt4Track_E;   //!
      TBranch        *b_antikt4Track_pt;   //!
      TBranch        *b_antikt4Track_m;   //!
      TBranch        *b_antikt4Track_eta;   //!
      TBranch        *b_antikt4Track_phi;   //!
      TBranch        *b_antikt4Track_const_n;   //!
      TBranch        *b_antikt4Track_const_pt;   //!
      TBranch        *b_antikt4Track_const_eta;   //!
      TBranch        *b_antikt4Track_const_phi;   //!
      TBranch        *b_antikt4Track_const_chi2;   //!
      TBranch        *b_antikt4Track_const_d0_wrtPV;   //!
      TBranch        *b_antikt4Track_const_z0_wrtPV;   //!
      TBranch        *b_antikt4Track_const_phi0_wrtPV;   //!
      TBranch        *b_antikt4Track_const_theta_wrtPV;   //!
      TBranch        *b_antikt4Track_const_qop;   //!
      TBranch        *b_antikt4Track_const_ndof;   //!
      TBranch        *b_antikt4Track_const_nBLayerHits;   //!
      TBranch        *b_antikt4Track_const_nPixelHits;   //!
      TBranch        *b_antikt4Track_const_nSCTHits;   //!
      TBranch        *b_antikt4Track_const_nTRTHits;   //!
      TBranch        *b_antikt6Track_n;   //!
      TBranch        *b_antikt6Track_E;   //!
      TBranch        *b_antikt6Track_pt;   //!
      TBranch        *b_antikt6Track_m;   //!
      TBranch        *b_antikt6Track_eta;   //!
      TBranch        *b_antikt6Track_phi;   //!
      TBranch        *b_antikt6Track_const_n;   //!
      TBranch        *b_antikt6Track_const_pt;   //!
      TBranch        *b_antikt6Track_const_eta;   //!
      TBranch        *b_antikt6Track_const_phi;   //!
      TBranch        *b_antikt6Track_const_chi2;   //!
      TBranch        *b_antikt6Track_const_d0_wrtPV;   //!
      TBranch        *b_antikt6Track_const_z0_wrtPV;   //!
      TBranch        *b_antikt6Track_const_phi0_wrtPV;   //!
      TBranch        *b_antikt6Track_const_theta_wrtPV;   //!
      TBranch        *b_antikt6Track_const_qop;   //!
      TBranch        *b_antikt6Track_const_ndof;   //!
      TBranch        *b_antikt6Track_const_nBLayerHits;   //!
      TBranch        *b_antikt6Track_const_nPixelHits;   //!
      TBranch        *b_antikt6Track_const_nSCTHits;   //!
      TBranch        *b_antikt6Track_const_nTRTHits;   //!
      TBranch        *b_HICentrality_b_bin;   //!
      TBranch        *b_HICentrality_nw_bin;   //!
      TBranch        *b_HICentrality_ncoll_bin;   //!
      TBranch        *b_HICentrality_calocell_energy_bin;   //!
      TBranch        *b_HICentrality_number_of_siclusters_bin;   //!
      TBranch        *b_HICentrality_b_var;   //!
      TBranch        *b_HICentrality_nw_var;   //!
      TBranch        *b_HICentrality_ncoll_var;   //!
      TBranch        *b_HICentrality_calocell_energy_var;   //!
      TBranch        *b_HICentrality_number_of_siclusters_var;   //!
      TBranch        *b_HIFlow_PsiHICaloUtilLayers;   //!
      TBranch        *b_HIFlow_PsiEtHICaloUtilLayers;   //!
      TBranch        *b_HIFlow_PsiPtrack;   //!
      TBranch        *b_HIFlow_PsiNtrack;   //!
      TBranch        *b_HIFlow_v2EMB1sil;   //!
      TBranch        *b_HIFlow_v2FCAL0sil;   //!
      TBranch        *b_HIFlow_v2track;   //!
      TBranch        *b_HIFlow_PsiFCAL0_w;   //!
      TBranch        *b_HIFlow_PsiPFCAL0_w;   //!
      TBranch        *b_HIFlow_PsiNFCAL0_w;   //!
      TBranch        *b_HIFlow_Meanv2_Psi_From_EMB1CaloCel_IDLayers;   //!
      TBranch        *b_HIFlow_Meanv2_Psi_From_FCAL0CaloCel_IDLayers;   //!
      TBranch        *b_HIFlow_Meanv2Et_Psi_From_EMB1CaloCel_IDLayers;   //!
      TBranch        *b_HIFlow_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers;   //!
      TBranch        *b_HIFlow_v2Eta_Psi_From_EMBP1_InDet_EMBN1;   //!
      TBranch        *b_HIFlow_v2Eta_Psi_From_EMBN1_InDet_EMBP1;   //!
      TBranch        *b_HIFlow_v2Eta_Psi_From_EMBP1_InDet_FCALN0;   //!
      TBranch        *b_HIFlow_v2Eta_Psi_From_EMBN1_InDet_FCALP0;   //!
      TBranch        *b_HIFlow_v2Eta_Psi_From_FCALN0_InDet_EMBN1;   //!
      TBranch        *b_HIFlow_v2Eta_Psi_From_FCALP0_InDet_EMBP1;   //!
      TBranch        *b_HIFlow_v2Eta_Psi_From_FCALP0_InDet_FCALN0;   //!
      TBranch        *b_HIFlow_v2Eta_Psi_From_FCALN0_InDet_FCALP0;   //!
      TBranch        *b_HIFlow_v2EtaEt_Psi_From_EMBP1_InDet_EMBN1;   //!
      TBranch        *b_HIFlow_v2EtaEt_Psi_From_EMBN1_InDet_EMBP1;   //!
      TBranch        *b_HIFlow_v2EtaEt_Psi_From_EMBP1_InDet_FCALN0;   //!
      TBranch        *b_HIFlow_v2EtaEt_Psi_From_EMBN1_InDet_FCALP0;   //!
      TBranch        *b_HIFlow_v2EtaEt_Psi_From_FCALN0_InDet_EMBN1;   //!
      TBranch        *b_HIFlow_v2EtaEt_Psi_From_FCALP0_InDet_EMBP1;   //!
      TBranch        *b_HIFlow_v2EtaEt_Psi_From_FCALP0_InDet_FCALN0;   //!
      TBranch        *b_HIFlow_v2EtaEt_Psi_From_FCALN0_InDet_FCALP0;   //!
      TBranch        *b_HIFlow_EtaEMBN1;   //!
      TBranch        *b_HIFlow_EtaEMBP1;   //!
      TBranch        *b_HIFlow_EtaFCALN0;   //!
      TBranch        *b_HIFlow_EtaFCALP0;   //!
      TBranch        *b_emcl_n;   //!
      TBranch        *b_emcl_E;   //!
      TBranch        *b_emcl_pt;   //!
      TBranch        *b_emcl_m;   //!
      TBranch        *b_emcl_eta;   //!
      TBranch        *b_emcl_phi;   //!
      TBranch        *b_emcl_E_em;   //!
      TBranch        *b_emcl_E_had;   //!
      TBranch        *b_mu_staco_n;   //!
      TBranch        *b_mu_staco_E;   //!
      TBranch        *b_mu_staco_pt;   //!
      TBranch        *b_mu_staco_m;   //!
      TBranch        *b_mu_staco_eta;   //!
      TBranch        *b_mu_staco_phi;   //!
      TBranch        *b_mu_staco_px;   //!
      TBranch        *b_mu_staco_py;   //!
      TBranch        *b_mu_staco_pz;   //!
      TBranch        *b_mu_staco_charge;   //!
      TBranch        *b_mu_staco_allauthor;   //!
      TBranch        *b_mu_staco_author;   //!
      TBranch        *b_mu_staco_matchchi2;   //!
      TBranch        *b_mu_staco_matchndof;   //!
      TBranch        *b_mu_staco_etcone20;   //!
      TBranch        *b_mu_staco_etcone30;   //!
      TBranch        *b_mu_staco_etcone40;   //!
      TBranch        *b_mu_staco_nucone20;   //!
      TBranch        *b_mu_staco_nucone30;   //!
      TBranch        *b_mu_staco_nucone40;   //!
      TBranch        *b_mu_staco_ptcone20;   //!
      TBranch        *b_mu_staco_ptcone30;   //!
      TBranch        *b_mu_staco_ptcone40;   //!
      TBranch        *b_mu_staco_energyLossPar;   //!
      TBranch        *b_mu_staco_energyLossErr;   //!
      TBranch        *b_mu_staco_etCore;   //!
      TBranch        *b_mu_staco_energyLossType;   //!
      TBranch        *b_mu_staco_bestMatch;   //!
      TBranch        *b_mu_staco_isStandAloneMuon;   //!
      TBranch        *b_mu_staco_isCombinedMuon;   //!
      TBranch        *b_mu_staco_isLowPtReconstructedMuon;   //!
      TBranch        *b_mu_staco_loose;   //!
      TBranch        *b_mu_staco_medium;   //!
      TBranch        *b_mu_staco_tight;   //!
      TBranch        *b_mu_staco_d0_exPV;   //!
      TBranch        *b_mu_staco_z0_exPV;   //!
      TBranch        *b_mu_staco_phi_exPV;   //!
      TBranch        *b_mu_staco_theta_exPV;   //!
      TBranch        *b_mu_staco_qoverp_exPV;   //!
      TBranch        *b_mu_staco_cb_d0_exPV;   //!
      TBranch        *b_mu_staco_cb_z0_exPV;   //!
      TBranch        *b_mu_staco_cb_phi_exPV;   //!
      TBranch        *b_mu_staco_cb_theta_exPV;   //!
      TBranch        *b_mu_staco_cb_qoverp_exPV;   //!
      TBranch        *b_mu_staco_id_d0_exPV;   //!
      TBranch        *b_mu_staco_id_z0_exPV;   //!
      TBranch        *b_mu_staco_id_phi_exPV;   //!
      TBranch        *b_mu_staco_id_theta_exPV;   //!
      TBranch        *b_mu_staco_id_qoverp_exPV;   //!
      TBranch        *b_mu_staco_me_d0_exPV;   //!
      TBranch        *b_mu_staco_me_z0_exPV;   //!
      TBranch        *b_mu_staco_me_phi_exPV;   //!
      TBranch        *b_mu_staco_me_theta_exPV;   //!
      TBranch        *b_mu_staco_me_qoverp_exPV;   //!
      TBranch        *b_mu_staco_ie_d0_exPV;   //!
      TBranch        *b_mu_staco_ie_z0_exPV;   //!
      TBranch        *b_mu_staco_ie_phi_exPV;   //!
      TBranch        *b_mu_staco_ie_theta_exPV;   //!
      TBranch        *b_mu_staco_ie_qoverp_exPV;   //!
      TBranch        *b_mu_staco_cov_d0_exPV;   //!
      TBranch        *b_mu_staco_cov_z0_exPV;   //!
      TBranch        *b_mu_staco_cov_phi_exPV;   //!
      TBranch        *b_mu_staco_cov_theta_exPV;   //!
      TBranch        *b_mu_staco_cov_qoverp_exPV;   //!
      TBranch        *b_mu_staco_cov_d0_z0_exPV;   //!
      TBranch        *b_mu_staco_cov_d0_phi_exPV;   //!
      TBranch        *b_mu_staco_cov_d0_theta_exPV;   //!
      TBranch        *b_mu_staco_cov_d0_qoverp_exPV;   //!
      TBranch        *b_mu_staco_cov_z0_phi_exPV;   //!
      TBranch        *b_mu_staco_cov_z0_theta_exPV;   //!
      TBranch        *b_mu_staco_cov_z0_qoverp_exPV;   //!
      TBranch        *b_mu_staco_cov_phi_theta_exPV;   //!
      TBranch        *b_mu_staco_cov_phi_qoverp_exPV;   //!
      TBranch        *b_mu_staco_cov_theta_qoverp_exPV;   //!
      TBranch        *b_mu_staco_ms_d0;   //!
      TBranch        *b_mu_staco_ms_z0;   //!
      TBranch        *b_mu_staco_ms_phi;   //!
      TBranch        *b_mu_staco_ms_theta;   //!
      TBranch        *b_mu_staco_ms_qoverp;   //!
      TBranch        *b_mu_staco_id_d0;   //!
      TBranch        *b_mu_staco_id_z0;   //!
      TBranch        *b_mu_staco_id_phi;   //!
      TBranch        *b_mu_staco_id_theta;   //!
      TBranch        *b_mu_staco_id_qoverp;   //!
      TBranch        *b_mu_staco_me_d0;   //!
      TBranch        *b_mu_staco_me_z0;   //!
      TBranch        *b_mu_staco_me_phi;   //!
      TBranch        *b_mu_staco_me_theta;   //!
      TBranch        *b_mu_staco_me_qoverp;   //!
      TBranch        *b_mu_staco_ie_d0;   //!
      TBranch        *b_mu_staco_ie_z0;   //!
      TBranch        *b_mu_staco_ie_phi;   //!
      TBranch        *b_mu_staco_ie_theta;   //!
      TBranch        *b_mu_staco_ie_qoverp;   //!
      TBranch        *b_mu_staco_nBLHits;   //!
      TBranch        *b_mu_staco_nPixHits;   //!
      TBranch        *b_mu_staco_nSCTHits;   //!
      TBranch        *b_mu_staco_nTRTHits;   //!
      TBranch        *b_mu_staco_nTRTHighTHits;   //!
      TBranch        *b_mu_staco_nBLSharedHits;   //!
      TBranch        *b_mu_staco_nPixSharedHits;   //!
      TBranch        *b_mu_staco_nPixHoles;   //!
      TBranch        *b_mu_staco_nSCTSharedHits;   //!
      TBranch        *b_mu_staco_nSCTHoles;   //!
      TBranch        *b_mu_staco_nTRTOutliers;   //!
      TBranch        *b_mu_staco_nTRTHighTOutliers;   //!
      TBranch        *b_mu_staco_nMDTHits;   //!
      TBranch        *b_mu_staco_nMDTHoles;   //!
      TBranch        *b_mu_staco_nCSCEtaHits;   //!
      TBranch        *b_mu_staco_nCSCEtaHoles;   //!
      TBranch        *b_mu_staco_nCSCPhiHits;   //!
      TBranch        *b_mu_staco_nCSCPhiHoles;   //!
      TBranch        *b_mu_staco_nRPCEtaHits;   //!
      TBranch        *b_mu_staco_nRPCEtaHoles;   //!
      TBranch        *b_mu_staco_nRPCPhiHits;   //!
      TBranch        *b_mu_staco_nRPCPhiHoles;   //!
      TBranch        *b_mu_staco_nTGCEtaHits;   //!
      TBranch        *b_mu_staco_nTGCEtaHoles;   //!
      TBranch        *b_mu_staco_nTGCPhiHits;   //!
      TBranch        *b_mu_staco_nTGCPhiHoles;   //!
      TBranch        *b_mu_staco_nGangedPixels;   //!
      TBranch        *b_mu_staco_nOutliersOnTrack;   //!
      TBranch        *b_mu_staco_nMDTBIHits;   //!
      TBranch        *b_mu_staco_nMDTBMHits;   //!
      TBranch        *b_mu_staco_nMDTBOHits;   //!
      TBranch        *b_mu_staco_nMDTBEEHits;   //!
      TBranch        *b_mu_staco_nMDTBIS78Hits;   //!
      TBranch        *b_mu_staco_nMDTEIHits;   //!
      TBranch        *b_mu_staco_nMDTEMHits;   //!
      TBranch        *b_mu_staco_nMDTEOHits;   //!
      TBranch        *b_mu_staco_nMDTEEHits;   //!
      TBranch        *b_mu_staco_nRPCLayer1EtaHits;   //!
      TBranch        *b_mu_staco_nRPCLayer2EtaHits;   //!
      TBranch        *b_mu_staco_nRPCLayer3EtaHits;   //!
      TBranch        *b_mu_staco_nRPCLayer1PhiHits;   //!
      TBranch        *b_mu_staco_nRPCLayer2PhiHits;   //!
      TBranch        *b_mu_staco_nRPCLayer3PhiHits;   //!
      TBranch        *b_mu_staco_nTGCLayer1EtaHits;   //!
      TBranch        *b_mu_staco_nTGCLayer2EtaHits;   //!
      TBranch        *b_mu_staco_nTGCLayer3EtaHits;   //!
      TBranch        *b_mu_staco_nTGCLayer4EtaHits;   //!
      TBranch        *b_mu_staco_nTGCLayer1PhiHits;   //!
      TBranch        *b_mu_staco_nTGCLayer2PhiHits;   //!
      TBranch        *b_mu_staco_nTGCLayer3PhiHits;   //!
      TBranch        *b_mu_staco_nTGCLayer4PhiHits;   //!
      TBranch        *b_mu_staco_barrelSectors;   //!
      TBranch        *b_mu_staco_endcapSectors;   //!
      TBranch        *b_mu_staco_trackd0;   //!
      TBranch        *b_mu_staco_trackz0;   //!
      TBranch        *b_mu_staco_trackphi;   //!
      TBranch        *b_mu_staco_tracktheta;   //!
      TBranch        *b_mu_staco_trackqoverp;   //!
      TBranch        *b_mu_staco_trackcov_d0;   //!
      TBranch        *b_mu_staco_trackcov_z0;   //!
      TBranch        *b_mu_staco_trackcov_phi;   //!
      TBranch        *b_mu_staco_trackcov_theta;   //!
      TBranch        *b_mu_staco_trackcov_qoverp;   //!
      TBranch        *b_mu_staco_trackcov_d0_z0;   //!
      TBranch        *b_mu_staco_trackcov_d0_phi;   //!
      TBranch        *b_mu_staco_trackcov_d0_theta;   //!
      TBranch        *b_mu_staco_trackcov_d0_qoverp;   //!
      TBranch        *b_mu_staco_trackcov_z0_phi;   //!
      TBranch        *b_mu_staco_trackcov_z0_theta;   //!
      TBranch        *b_mu_staco_trackcov_z0_qoverp;   //!
      TBranch        *b_mu_staco_trackcov_phi_theta;   //!
      TBranch        *b_mu_staco_trackcov_phi_qoverp;   //!
      TBranch        *b_mu_staco_trackcov_theta_qoverp;   //!
      TBranch        *b_mu_staco_trackfitchi2;   //!
      TBranch        *b_mu_staco_trackfitndof;   //!
      TBranch        *b_mu_staco_hastrack;   //!
      TBranch        *b_mu_staco_EF_dr;   //!
      TBranch        *b_mu_staco_EF_cb_eta;   //!
      TBranch        *b_mu_staco_EF_cb_phi;   //!
      TBranch        *b_mu_staco_EF_cb_pt;   //!
      TBranch        *b_mu_staco_EF_ms_eta;   //!
      TBranch        *b_mu_staco_EF_ms_phi;   //!
      TBranch        *b_mu_staco_EF_ms_pt;   //!
      TBranch        *b_mu_staco_EF_me_eta;   //!
      TBranch        *b_mu_staco_EF_me_phi;   //!
      TBranch        *b_mu_staco_EF_me_pt;   //!
      TBranch        *b_mu_staco_EF_matched;   //!
      TBranch        *b_mu_staco_L2CB_dr;   //!
      TBranch        *b_mu_staco_L2CB_pt;   //!
      TBranch        *b_mu_staco_L2CB_eta;   //!
      TBranch        *b_mu_staco_L2CB_phi;   //!
      TBranch        *b_mu_staco_L2CB_id_pt;   //!
      TBranch        *b_mu_staco_L2CB_ms_pt;   //!
      TBranch        *b_mu_staco_L2CB_nPixHits;   //!
      TBranch        *b_mu_staco_L2CB_nSCTHits;   //!
      TBranch        *b_mu_staco_L2CB_nTRTHits;   //!
      TBranch        *b_mu_staco_L2CB_nTRTHighTHits;   //!
      TBranch        *b_mu_staco_L2CB_matched;   //!
      TBranch        *b_mu_staco_L1_dr;   //!
      TBranch        *b_mu_staco_L1_pt;   //!
      TBranch        *b_mu_staco_L1_eta;   //!
      TBranch        *b_mu_staco_L1_phi;   //!
      TBranch        *b_mu_staco_L1_thrNumber;   //!
      TBranch        *b_mu_staco_L1_RoINumber;   //!
      TBranch        *b_mu_staco_L1_sectorAddress;   //!
      TBranch        *b_mu_staco_L1_firstCandidate;   //!
      TBranch        *b_mu_staco_L1_moreCandInRoI;   //!
      TBranch        *b_mu_staco_L1_moreCandInSector;   //!
      TBranch        *b_mu_staco_L1_source;   //!
      TBranch        *b_mu_staco_L1_hemisphere;   //!
      TBranch        *b_mu_staco_L1_matched;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_2MU0;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_2MU0_FIRSTEMPTY;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_2MU0_MU6;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_2MU10;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_2MU6;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_EM10;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_EM10I;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_EM14;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_EM2;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_EM2_MV;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_EM2_UNPAIRED_ISO;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_EM2_UNPAIRED_NONISO;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_EM3;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_EM3_EMPTY;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_EM3_FIRSTEMPTY;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_EM4;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_EM5;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_EM5I;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_MU0;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_MU0_COMM;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_MU0_COMM_EMPTY;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_MU0_COMM_FIRSTEMPTY;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_ISO;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_NONISO;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_MU0_EMPTY;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_MU0_FIRSTEMPTY;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_MU0_MV;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_MU0_UNPAIRED_ISO;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_MU0_UNPAIRED_NONISO;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_MU10;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_MU10_FIRSTEMPTY;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_MU15;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_MU20;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_MU6;   //!
      TBranch        *b_EF_L1ItemStreamer_L1_MU6_FIRSTEMPTY;   //!
      TBranch        *b_EF_SeededStreamerL1Calo;   //!
      TBranch        *b_EF_g10_loose;   //!
      TBranch        *b_EF_g10_loose_larcalib;   //!
      TBranch        *b_EF_g5_NoCut_cosmic;   //!
      TBranch        *b_EF_g5_loose;   //!
      TBranch        *b_EF_g5_loose_larcalib;   //!
      TBranch        *b_EF_mu4;   //!
      TBranch        *b_EF_mu4_IDTrkNoCut;   //!
      TBranch        *b_EF_mu4_MSonly;   //!
      TBranch        *b_EF_mu4_MSonly_MB2_noL2_EFFS;   //!
      TBranch        *b_EF_mu4_MSonly_cosmic;   //!
      TBranch        *b_EF_mu4_MV;   //!
      TBranch        *b_EF_mu4_MV_MSonly;   //!
      TBranch        *b_EF_mu4_comm_MSonly_cosmic;   //!
      TBranch        *b_EF_mu4_comm_cosmic;   //!
      TBranch        *b_EF_mu4_cosmic;   //!
      TBranch        *b_L1_2EM2;   //!
      TBranch        *b_L1_2EM3;   //!
      TBranch        *b_L1_2EM4;   //!
      TBranch        *b_L1_2EM5;   //!
      TBranch        *b_L1_2MU0;   //!
      TBranch        *b_L1_2MU0_FIRSTEMPTY;   //!
      TBranch        *b_L1_2MU0_MU6;   //!
      TBranch        *b_L1_2MU10;   //!
      TBranch        *b_L1_2MU20;   //!
      TBranch        *b_L1_2MU6;   //!
      TBranch        *b_L1_EM10;   //!
      TBranch        *b_L1_EM10I;   //!
      TBranch        *b_L1_EM14;   //!
      TBranch        *b_L1_EM2;   //!
      TBranch        *b_L1_EM2_MV;   //!
      TBranch        *b_L1_EM2_UNPAIRED_ISO;   //!
      TBranch        *b_L1_EM2_UNPAIRED_NONISO;   //!
      TBranch        *b_L1_EM3;   //!
      TBranch        *b_L1_EM3_EMPTY;   //!
      TBranch        *b_L1_EM3_FIRSTEMPTY;   //!
      TBranch        *b_L1_EM4;   //!
      TBranch        *b_L1_EM5;   //!
      TBranch        *b_L1_EM5I;   //!
      TBranch        *b_L1_MU0;   //!
      TBranch        *b_L1_MU0_COMM;   //!
      TBranch        *b_L1_MU0_COMM_EMPTY;   //!
      TBranch        *b_L1_MU0_COMM_FIRSTEMPTY;   //!
      TBranch        *b_L1_MU0_COMM_UNPAIRED_ISO;   //!
      TBranch        *b_L1_MU0_COMM_UNPAIRED_NONISO;   //!
      TBranch        *b_L1_MU0_EMPTY;   //!
      TBranch        *b_L1_MU0_FIRSTEMPTY;   //!
      TBranch        *b_L1_MU0_MV;   //!
      TBranch        *b_L1_MU0_UNPAIRED_ISO;   //!
      TBranch        *b_L1_MU0_UNPAIRED_NONISO;   //!
      TBranch        *b_L1_MU10;   //!
      TBranch        *b_L1_MU10_FIRSTEMPTY;   //!
      TBranch        *b_L1_MU15;   //!
      TBranch        *b_L1_MU20;   //!
      TBranch        *b_L1_MU6;   //!
      TBranch        *b_L1_MU6_FIRSTEMPTY;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_2EM2;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_2EM3;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_2EM4;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_2EM5;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_2MU0;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_2MU0_FIRSTEMPTY;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_2MU0_MU6;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_2MU10;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_2MU6;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_EM10;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_EM10I;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_EM14;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_EM2;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_EM2_MV;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_EM2_UNPAIRED_ISO;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_EM2_UNPAIRED_NONISO;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_EM3;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_EM3_EMPTY;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_EM3_FIRSTEMPTY;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_EM4;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_EM5;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_EM5I;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_MU0;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_MU0_COMM;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_MU0_COMM_EMPTY;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_MU0_COMM_FIRSTEMPTY;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_ISO;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_NONISO;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_MU0_EMPTY;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_MU0_FIRSTEMPTY;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_MU0_MV;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_MU0_UNPAIRED_ISO;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_MU0_UNPAIRED_NONISO;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_MU10;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_MU10_FIRSTEMPTY;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_MU15;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_MU20;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_MU6;   //!
      TBranch        *b_L2_L1ItemStreamer_L1_MU6_FIRSTEMPTY;   //!
      TBranch        *b_L2_SeededStreamerL1Calo;   //!
      TBranch        *b_L2_em3_empty_larcalib;   //!
      TBranch        *b_L2_g10_loose;   //!
      TBranch        *b_L2_g5_NoCut_cosmic;   //!
      TBranch        *b_L2_g5_loose;   //!
      TBranch        *b_L2_mu4;   //!
      TBranch        *b_L2_mu4_IDTrkNoCut;   //!
      TBranch        *b_L2_mu4_MSonly;   //!
      TBranch        *b_L2_mu4_MSonly_MB2_noL2_EFFS;   //!
      TBranch        *b_L2_mu4_MSonly_cosmic;   //!
      TBranch        *b_L2_mu4_MV;   //!
      TBranch        *b_L2_mu4_MV_MSonly;   //!
      TBranch        *b_L2_mu4_comm_MSonly_cosmic;   //!
      TBranch        *b_L2_mu4_comm_cosmic;   //!
      TBranch        *b_L2_mu4_cosmic;   //!
      TBranch        *b_L2_mu6_cal;   //!
      TBranch        *b_mu_muid_n;   //!
      TBranch        *b_mu_muid_E;   //!
      TBranch        *b_mu_muid_pt;   //!
      TBranch        *b_mu_muid_m;   //!
      TBranch        *b_mu_muid_eta;   //!
      TBranch        *b_mu_muid_phi;   //!
      TBranch        *b_mu_muid_px;   //!
      TBranch        *b_mu_muid_py;   //!
      TBranch        *b_mu_muid_pz;   //!
      TBranch        *b_mu_muid_charge;   //!
      TBranch        *b_mu_muid_allauthor;   //!
      TBranch        *b_mu_muid_author;   //!
      TBranch        *b_mu_muid_matchchi2;   //!
      TBranch        *b_mu_muid_matchndof;   //!
      TBranch        *b_mu_muid_etcone20;   //!
      TBranch        *b_mu_muid_etcone30;   //!
      TBranch        *b_mu_muid_etcone40;   //!
      TBranch        *b_mu_muid_nucone20;   //!
      TBranch        *b_mu_muid_nucone30;   //!
      TBranch        *b_mu_muid_nucone40;   //!
      TBranch        *b_mu_muid_ptcone20;   //!
      TBranch        *b_mu_muid_ptcone30;   //!
      TBranch        *b_mu_muid_ptcone40;   //!
      TBranch        *b_mu_muid_energyLossPar;   //!
      TBranch        *b_mu_muid_energyLossErr;   //!
      TBranch        *b_mu_muid_etCore;   //!
      TBranch        *b_mu_muid_energyLossType;   //!
      TBranch        *b_mu_muid_bestMatch;   //!
      TBranch        *b_mu_muid_isStandAloneMuon;   //!
      TBranch        *b_mu_muid_isCombinedMuon;   //!
      TBranch        *b_mu_muid_isLowPtReconstructedMuon;   //!
      TBranch        *b_mu_muid_loose;   //!
      TBranch        *b_mu_muid_medium;   //!
      TBranch        *b_mu_muid_tight;   //!
      TBranch        *b_mu_muid_d0_exPV;   //!
      TBranch        *b_mu_muid_z0_exPV;   //!
      TBranch        *b_mu_muid_phi_exPV;   //!
      TBranch        *b_mu_muid_theta_exPV;   //!
      TBranch        *b_mu_muid_qoverp_exPV;   //!
      TBranch        *b_mu_muid_cb_d0_exPV;   //!
      TBranch        *b_mu_muid_cb_z0_exPV;   //!
      TBranch        *b_mu_muid_cb_phi_exPV;   //!
      TBranch        *b_mu_muid_cb_theta_exPV;   //!
      TBranch        *b_mu_muid_cb_qoverp_exPV;   //!
      TBranch        *b_mu_muid_id_d0_exPV;   //!
      TBranch        *b_mu_muid_id_z0_exPV;   //!
      TBranch        *b_mu_muid_id_phi_exPV;   //!
      TBranch        *b_mu_muid_id_theta_exPV;   //!
      TBranch        *b_mu_muid_id_qoverp_exPV;   //!
      TBranch        *b_mu_muid_me_d0_exPV;   //!
      TBranch        *b_mu_muid_me_z0_exPV;   //!
      TBranch        *b_mu_muid_me_phi_exPV;   //!
      TBranch        *b_mu_muid_me_theta_exPV;   //!
      TBranch        *b_mu_muid_me_qoverp_exPV;   //!
      TBranch        *b_mu_muid_ie_d0_exPV;   //!
      TBranch        *b_mu_muid_ie_z0_exPV;   //!
      TBranch        *b_mu_muid_ie_phi_exPV;   //!
      TBranch        *b_mu_muid_ie_theta_exPV;   //!
      TBranch        *b_mu_muid_ie_qoverp_exPV;   //!
      TBranch        *b_mu_muid_cov_d0_exPV;   //!
      TBranch        *b_mu_muid_cov_z0_exPV;   //!
      TBranch        *b_mu_muid_cov_phi_exPV;   //!
      TBranch        *b_mu_muid_cov_theta_exPV;   //!
      TBranch        *b_mu_muid_cov_qoverp_exPV;   //!
      TBranch        *b_mu_muid_cov_d0_z0_exPV;   //!
      TBranch        *b_mu_muid_cov_d0_phi_exPV;   //!
      TBranch        *b_mu_muid_cov_d0_theta_exPV;   //!
      TBranch        *b_mu_muid_cov_d0_qoverp_exPV;   //!
      TBranch        *b_mu_muid_cov_z0_phi_exPV;   //!
      TBranch        *b_mu_muid_cov_z0_theta_exPV;   //!
      TBranch        *b_mu_muid_cov_z0_qoverp_exPV;   //!
      TBranch        *b_mu_muid_cov_phi_theta_exPV;   //!
      TBranch        *b_mu_muid_cov_phi_qoverp_exPV;   //!
      TBranch        *b_mu_muid_cov_theta_qoverp_exPV;   //!
      TBranch        *b_mu_muid_ms_d0;   //!
      TBranch        *b_mu_muid_ms_z0;   //!
      TBranch        *b_mu_muid_ms_phi;   //!
      TBranch        *b_mu_muid_ms_theta;   //!
      TBranch        *b_mu_muid_ms_qoverp;   //!
      TBranch        *b_mu_muid_id_d0;   //!
      TBranch        *b_mu_muid_id_z0;   //!
      TBranch        *b_mu_muid_id_phi;   //!
      TBranch        *b_mu_muid_id_theta;   //!
      TBranch        *b_mu_muid_id_qoverp;   //!
      TBranch        *b_mu_muid_me_d0;   //!
      TBranch        *b_mu_muid_me_z0;   //!
      TBranch        *b_mu_muid_me_phi;   //!
      TBranch        *b_mu_muid_me_theta;   //!
      TBranch        *b_mu_muid_me_qoverp;   //!
      TBranch        *b_mu_muid_ie_d0;   //!
      TBranch        *b_mu_muid_ie_z0;   //!
      TBranch        *b_mu_muid_ie_phi;   //!
      TBranch        *b_mu_muid_ie_theta;   //!
      TBranch        *b_mu_muid_ie_qoverp;   //!
      TBranch        *b_mu_muid_nBLHits;   //!
      TBranch        *b_mu_muid_nPixHits;   //!
      TBranch        *b_mu_muid_nSCTHits;   //!
      TBranch        *b_mu_muid_nTRTHits;   //!
      TBranch        *b_mu_muid_nTRTHighTHits;   //!
      TBranch        *b_mu_muid_nBLSharedHits;   //!
      TBranch        *b_mu_muid_nPixSharedHits;   //!
      TBranch        *b_mu_muid_nPixHoles;   //!
      TBranch        *b_mu_muid_nSCTSharedHits;   //!
      TBranch        *b_mu_muid_nSCTHoles;   //!
      TBranch        *b_mu_muid_nTRTOutliers;   //!
      TBranch        *b_mu_muid_nTRTHighTOutliers;   //!
      TBranch        *b_mu_muid_nMDTHits;   //!
      TBranch        *b_mu_muid_nMDTHoles;   //!
      TBranch        *b_mu_muid_nCSCEtaHits;   //!
      TBranch        *b_mu_muid_nCSCEtaHoles;   //!
      TBranch        *b_mu_muid_nCSCPhiHits;   //!
      TBranch        *b_mu_muid_nCSCPhiHoles;   //!
      TBranch        *b_mu_muid_nRPCEtaHits;   //!
      TBranch        *b_mu_muid_nRPCEtaHoles;   //!
      TBranch        *b_mu_muid_nRPCPhiHits;   //!
      TBranch        *b_mu_muid_nRPCPhiHoles;   //!
      TBranch        *b_mu_muid_nTGCEtaHits;   //!
      TBranch        *b_mu_muid_nTGCEtaHoles;   //!
      TBranch        *b_mu_muid_nTGCPhiHits;   //!
      TBranch        *b_mu_muid_nTGCPhiHoles;   //!
      TBranch        *b_mu_muid_nGangedPixels;   //!
      TBranch        *b_mu_muid_nOutliersOnTrack;   //!
      TBranch        *b_mu_muid_nMDTBIHits;   //!
      TBranch        *b_mu_muid_nMDTBMHits;   //!
      TBranch        *b_mu_muid_nMDTBOHits;   //!
      TBranch        *b_mu_muid_nMDTBEEHits;   //!
      TBranch        *b_mu_muid_nMDTBIS78Hits;   //!
      TBranch        *b_mu_muid_nMDTEIHits;   //!
      TBranch        *b_mu_muid_nMDTEMHits;   //!
      TBranch        *b_mu_muid_nMDTEOHits;   //!
      TBranch        *b_mu_muid_nMDTEEHits;   //!
      TBranch        *b_mu_muid_nRPCLayer1EtaHits;   //!
      TBranch        *b_mu_muid_nRPCLayer2EtaHits;   //!
      TBranch        *b_mu_muid_nRPCLayer3EtaHits;   //!
      TBranch        *b_mu_muid_nRPCLayer1PhiHits;   //!
      TBranch        *b_mu_muid_nRPCLayer2PhiHits;   //!
      TBranch        *b_mu_muid_nRPCLayer3PhiHits;   //!
      TBranch        *b_mu_muid_nTGCLayer1EtaHits;   //!
      TBranch        *b_mu_muid_nTGCLayer2EtaHits;   //!
      TBranch        *b_mu_muid_nTGCLayer3EtaHits;   //!
      TBranch        *b_mu_muid_nTGCLayer4EtaHits;   //!
      TBranch        *b_mu_muid_nTGCLayer1PhiHits;   //!
      TBranch        *b_mu_muid_nTGCLayer2PhiHits;   //!
      TBranch        *b_mu_muid_nTGCLayer3PhiHits;   //!
      TBranch        *b_mu_muid_nTGCLayer4PhiHits;   //!
      TBranch        *b_mu_muid_barrelSectors;   //!
      TBranch        *b_mu_muid_endcapSectors;   //!
      TBranch        *b_mu_muid_trackd0;   //!
      TBranch        *b_mu_muid_trackz0;   //!
      TBranch        *b_mu_muid_trackphi;   //!
      TBranch        *b_mu_muid_tracktheta;   //!
      TBranch        *b_mu_muid_trackqoverp;   //!
      TBranch        *b_mu_muid_trackcov_d0;   //!
      TBranch        *b_mu_muid_trackcov_z0;   //!
      TBranch        *b_mu_muid_trackcov_phi;   //!
      TBranch        *b_mu_muid_trackcov_theta;   //!
      TBranch        *b_mu_muid_trackcov_qoverp;   //!
      TBranch        *b_mu_muid_trackcov_d0_z0;   //!
      TBranch        *b_mu_muid_trackcov_d0_phi;   //!
      TBranch        *b_mu_muid_trackcov_d0_theta;   //!
      TBranch        *b_mu_muid_trackcov_d0_qoverp;   //!
      TBranch        *b_mu_muid_trackcov_z0_phi;   //!
      TBranch        *b_mu_muid_trackcov_z0_theta;   //!
      TBranch        *b_mu_muid_trackcov_z0_qoverp;   //!
      TBranch        *b_mu_muid_trackcov_phi_theta;   //!
      TBranch        *b_mu_muid_trackcov_phi_qoverp;   //!
      TBranch        *b_mu_muid_trackcov_theta_qoverp;   //!
      TBranch        *b_mu_muid_trackfitchi2;   //!
      TBranch        *b_mu_muid_trackfitndof;   //!
      TBranch        *b_mu_muid_hastrack;   //!
      TBranch        *b_mu_muid_EF_dr;   //!
      TBranch        *b_mu_muid_EF_cb_eta;   //!
      TBranch        *b_mu_muid_EF_cb_phi;   //!
      TBranch        *b_mu_muid_EF_cb_pt;   //!
      TBranch        *b_mu_muid_EF_ms_eta;   //!
      TBranch        *b_mu_muid_EF_ms_phi;   //!
      TBranch        *b_mu_muid_EF_ms_pt;   //!
      TBranch        *b_mu_muid_EF_me_eta;   //!
      TBranch        *b_mu_muid_EF_me_phi;   //!
      TBranch        *b_mu_muid_EF_me_pt;   //!
      TBranch        *b_mu_muid_EF_matched;   //!
      TBranch        *b_mu_muid_L2CB_dr;   //!
      TBranch        *b_mu_muid_L2CB_pt;   //!
      TBranch        *b_mu_muid_L2CB_eta;   //!
      TBranch        *b_mu_muid_L2CB_phi;   //!
      TBranch        *b_mu_muid_L2CB_id_pt;   //!
      TBranch        *b_mu_muid_L2CB_ms_pt;   //!
      TBranch        *b_mu_muid_L2CB_nPixHits;   //!
      TBranch        *b_mu_muid_L2CB_nSCTHits;   //!
      TBranch        *b_mu_muid_L2CB_nTRTHits;   //!
      TBranch        *b_mu_muid_L2CB_nTRTHighTHits;   //!
      TBranch        *b_mu_muid_L2CB_matched;   //!
      TBranch        *b_mu_muid_L1_dr;   //!
      TBranch        *b_mu_muid_L1_pt;   //!
      TBranch        *b_mu_muid_L1_eta;   //!
      TBranch        *b_mu_muid_L1_phi;   //!
      TBranch        *b_mu_muid_L1_thrNumber;   //!
      TBranch        *b_mu_muid_L1_RoINumber;   //!
      TBranch        *b_mu_muid_L1_sectorAddress;   //!
      TBranch        *b_mu_muid_L1_firstCandidate;   //!
      TBranch        *b_mu_muid_L1_moreCandInRoI;   //!
      TBranch        *b_mu_muid_L1_moreCandInSector;   //!
      TBranch        *b_mu_muid_L1_source;   //!
      TBranch        *b_mu_muid_L1_hemisphere;   //!
      TBranch        *b_mu_muid_L1_matched;   //!
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
      TBranch        *b_trig_L2_resurrected;   //!
      TBranch        *b_trig_EF_resurrected;   //!
      TBranch        *b_trig_L2_passedThrough;   //!
      TBranch        *b_trig_EF_passedThrough;   //!
      TBranch        *b_L1_2J10;   //!
      TBranch        *b_L1_2J15;   //!
      TBranch        *b_L1_2J5;   //!
      TBranch        *b_L1_J10;   //!
      TBranch        *b_L1_J15;   //!
      TBranch        *b_L1_J30;   //!
      TBranch        *b_L1_J5;   //!
      TBranch        *b_L1_J55;   //!
      TBranch        *b_L1_J75;   //!
      TBranch        *b_L1_J95;   //!
      TBranch        *b_trig_L1_jet_n;   //!
      TBranch        *b_trig_L1_jet_eta;   //!
      TBranch        *b_trig_L1_jet_phi;   //!
      TBranch        *b_trig_L1_jet_thrNames;   //!
      TBranch        *b_trig_L1_jet_thrValues;   //!
      TBranch        *b_trig_L1_jet_thrPattern;   //!
      TBranch        *b_trig_L1_jet_et4x4;   //!
      TBranch        *b_trig_L1_jet_et6x6;   //!
      TBranch        *b_trig_L1_jet_et8x8;   //!
      TBranch        *b_trig_L1_jet_RoIWord;   //!
      TBranch        *b_trig_L1_esum_thrNames;   //!
      TBranch        *b_trig_L1_esum_energyX;   //!
      TBranch        *b_trig_L1_esum_energyY;   //!
      TBranch        *b_trig_L1_esum_energyT;   //!
      TBranch        *b_trig_L1_esum_overflowX;   //!
      TBranch        *b_trig_L1_esum_overflowY;   //!
      TBranch        *b_trig_L1_esum_overflowT;   //!
      TBranch        *b_trig_L1_esum_RoIWord0;   //!
      TBranch        *b_trig_L1_esum_RoIWord1;   //!
      TBranch        *b_trig_L1_esum_RoIWord2;   //!
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
      TBranch        *b_trig_L2_jet_ehad0;   //!
      TBranch        *b_trig_L2_jet_eem0;   //!
      TBranch        *b_trtRDO_countRDOhitsInEvent;   //!
      TBranch        *b_trtRDO_countBarrelhitsInEvent;   //!
      TBranch        *b_trtRDO_countEndCaphitsInEvent;   //!
      TBranch        *b_trtRDO_countEndCapAhitsInEvent;   //!
      TBranch        *b_trtRDO_countEndCapChitsInEvent;   //!
      TBranch        *b_trtRDO_countdeadstraws;   //!
      TBranch        *b_vx_n;   //!
      TBranch        *b_vx_x;   //!
      TBranch        *b_vx_y;   //!
      TBranch        *b_vx_z;   //!
      TBranch        *b_vx_cov_x;   //!
      TBranch        *b_vx_cov_y;   //!
      TBranch        *b_vx_cov_z;   //!
      TBranch        *b_vx_chi2;   //!
      TBranch        *b_vx_ndof;   //!
      TBranch        *b_vx_px;   //!
      TBranch        *b_vx_py;   //!
      TBranch        *b_vx_pz;   //!
      TBranch        *b_vx_E;   //!
      TBranch        *b_vx_m;   //!
      TBranch        *b_vx_nTracks;   //!
      TBranch        *b_vx_sumPt;   //!
      TBranch        *b_vx_type;   //!
      TBranch        *b_vx_trk_n;   //!
      TBranch        *b_vx_trk_chi2;   //!
      TBranch        *b_vx_trk_d0;   //!
      TBranch        *b_vx_trk_z0;   //!
      TBranch        *b_vx_trk_unbiased_d0;   //!
      TBranch        *b_vx_trk_unbiased_z0;   //!
      TBranch        *b_vx_trk_err_unbiased_d0;   //!
      TBranch        *b_vx_trk_err_unbiased_z0;   //!
      TBranch        *b_vx_trk_phi;   //!
      TBranch        *b_vx_trk_theta;   //!
      TBranch        *b_vx_trk_weight;   //!
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
      TBranch        *b_el_OQ;   //!
      TBranch        *b_el_convFlag;   //!
      TBranch        *b_el_isConv;   //!
      TBranch        *b_el_nConv;   //!
      TBranch        *b_el_nSingleTrackConv;   //!
      TBranch        *b_el_nDoubleTrackConv;   //!
      TBranch        *b_el_loose;   //!
      TBranch        *b_el_medium;   //!
      TBranch        *b_el_mediumIso;   //!
      TBranch        *b_el_tight;   //!
      TBranch        *b_el_tightIso;   //!
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
      TBranch        *b_el_Etcone20;   //!
      TBranch        *b_el_Etcone30;   //!
      TBranch        *b_el_Etcone40;   //!
      TBranch        *b_el_ptcone30;   //!
      TBranch        *b_el_convanglematch;   //!
      TBranch        *b_el_convtrackmatch;   //!
      TBranch        *b_el_pos7;   //!
      TBranch        *b_el_etacorrmag;   //!
      TBranch        *b_el_deltaeta1;   //!
      TBranch        *b_el_deltaeta2;   //!
      TBranch        *b_el_deltaphi2;   //!
      TBranch        *b_el_deltaphiRescaled;   //!
      TBranch        *b_el_deltaPhiRot;   //!
      TBranch        *b_el_expectHitInBLayer;   //!
      TBranch        *b_el_reta;   //!
      TBranch        *b_el_rphi;   //!
      TBranch        *b_el_EtringnoisedR03sig2;   //!
      TBranch        *b_el_EtringnoisedR03sig3;   //!
      TBranch        *b_el_EtringnoisedR03sig4;   //!
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
      TBranch        *b_el_zvertex;   //!
      TBranch        *b_el_errz;   //!
      TBranch        *b_el_etap;   //!
      TBranch        *b_el_depth;   //!
      TBranch        *b_el_refittedTrack_n;   //!
      TBranch        *b_el_refittedTrack_author;   //!
      TBranch        *b_el_refittedTrack_chi2;   //!
      TBranch        *b_el_refittedTrack_qoverp;   //!
      TBranch        *b_el_refittedTrack_d0;   //!
      TBranch        *b_el_refittedTrack_z0;   //!
      TBranch        *b_el_refittedTrack_theta;   //!
      TBranch        *b_el_refittedTrack_phi;   //!
      TBranch        *b_el_refittedTrack_LMqoverp;   //!
      TBranch        *b_el_refittedTrack_hasBrem;   //!
      TBranch        *b_el_refittedTrack_bremRadius;   //!
      TBranch        *b_el_refittedTrack_bremZ;   //!
      TBranch        *b_el_refittedTrack_bremRadiusErr;   //!
      TBranch        *b_el_refittedTrack_bremZErr;   //!
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
      TBranch        *b_el_refittedtrackcovd0;   //!
      TBranch        *b_el_refittedtrackcovz0;   //!
      TBranch        *b_el_refittedtrackcovphi;   //!
      TBranch        *b_el_refittedtrackcovtheta;   //!
      TBranch        *b_el_refittedtrackcovqoverp;   //!
      TBranch        *b_el_refittedtrackcovd0z0;   //!
      TBranch        *b_el_refittedtrackcovz0phi;   //!
      TBranch        *b_el_refittedtrackcovz0theta;   //!
      TBranch        *b_el_refittedtrackcovz0qoverp;   //!
      TBranch        *b_el_refittedtrackcovd0phi;   //!
      TBranch        *b_el_refittedtrackcovd0theta;   //!
      TBranch        *b_el_refittedtrackcovd0qoverp;   //!
      TBranch        *b_el_refittedtrackcovphitheta;   //!
      TBranch        *b_el_refittedtrackcovphiqoverp;   //!
      TBranch        *b_el_refittedtrackcovthetaqoverp;   //!
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
      TBranch        *b_el_nPixHoles;   //!
      TBranch        *b_el_nSCTHoles;   //!
      TBranch        *b_el_nBLSharedHits;   //!
      TBranch        *b_el_nPixSharedHits;   //!
      TBranch        *b_el_nSCTSharedHits;   //!
      TBranch        *b_el_nTRTHighTHits;   //!
      TBranch        *b_el_nTRTOutliers;   //!
      TBranch        *b_el_nTRTHighTOutliers;   //!
      TBranch        *b_el_nSiHits;   //!
      TBranch        *b_el_TRTHighTHitsRatio;   //!
      TBranch        *b_el_pixeldEdx;   //!
      TBranch        *b_el_eProbabilityComb;   //!
      TBranch        *b_el_eProbabilityHT;   //!
      TBranch        *b_el_eProbabilityToT;   //!
      TBranch        *b_el_eProbabilityBrem;   //!
      TBranch        *b_el_vertx;   //!
      TBranch        *b_el_verty;   //!
      TBranch        *b_el_vertz;   //!
      TBranch        *b_el_hastrack;   //!
      TBranch        *b_el_deltaEmax2;   //!
      TBranch        *b_el_calibHitsShowerDepth;   //!
      TBranch        *b_el_trackd0beam;   //!
      TBranch        *b_el_tracksigd0beam;   //!
      TBranch        *b_el_trackd0pv;   //!
      TBranch        *b_el_tracksigd0pv;   //!
      TBranch        *b_el_trackz0pv;   //!
      TBranch        *b_el_tracksigz0pv;   //!
      TBranch        *b_el_trackd0pvunbiased;   //!
      TBranch        *b_el_tracksigd0pvunbiased;   //!
      TBranch        *b_el_trackz0pvunbiased;   //!
      TBranch        *b_el_tracksigz0pvunbiased;   //!
      TBranch        *b_el_isIso;   //!
      TBranch        *b_el_mvaptcone20;   //!
      TBranch        *b_el_mvaptcone30;   //!
      TBranch        *b_el_mvaptcone40;   //!
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
      TBranch        *b_ph_OQ;   //!
      TBranch        *b_ph_loose;   //!
      TBranch        *b_ph_tight;   //!
      TBranch        *b_ph_tightIso;   //!
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
      TBranch        *b_ph_Etcone20;   //!
      TBranch        *b_ph_Etcone30;   //!
      TBranch        *b_ph_Etcone40;   //!
      TBranch        *b_ph_ptcone30;   //!
      TBranch        *b_ph_convanglematch;   //!
      TBranch        *b_ph_convtrackmatch;   //!
      TBranch        *b_ph_reta;   //!
      TBranch        *b_ph_rphi;   //!
      TBranch        *b_ph_EtringnoisedR03sig2;   //!
      TBranch        *b_ph_EtringnoisedR03sig3;   //!
      TBranch        *b_ph_EtringnoisedR03sig4;   //!
      TBranch        *b_ph_isolationlikelihoodjets;   //!
      TBranch        *b_ph_isolationlikelihoodhqelectrons;   //!
      TBranch        *b_ph_loglikelihood;   //!
      TBranch        *b_ph_photonweight;   //!
      TBranch        *b_ph_photonbgweight;   //!
      TBranch        *b_ph_neuralnet;   //!
      TBranch        *b_ph_Hmatrix;   //!
      TBranch        *b_ph_Hmatrix5;   //!
      TBranch        *b_ph_adaboost;   //!
      TBranch        *b_ph_zvertex;   //!
      TBranch        *b_ph_errz;   //!
      TBranch        *b_ph_etap;   //!
      TBranch        *b_ph_depth;   //!
      TBranch        *b_ph_cl_E;   //!
      TBranch        *b_ph_cl_pt;   //!
      TBranch        *b_ph_cl_eta;   //!
      TBranch        *b_ph_cl_phi;   //!
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
      TBranch        *b_ph_deltaEmax2;   //!
      TBranch        *b_ph_calibHitsShowerDepth;   //!
      TBranch        *b_ph_isIso;   //!
      TBranch        *b_ph_mvaptcone20;   //!
      TBranch        *b_ph_mvaptcone30;   //!
      TBranch        *b_ph_mvaptcone40;   //!
      TBranch        *b_ph_topoEtcone20;   //!
      TBranch        *b_ph_topoEtcone40;   //!
      TBranch        *b_ph_topoEtcone60;   //!

      extractor(){};
      extractor(string filelist);
      virtual ~extractor();

      virtual Int_t    Cut(Long64_t entry);
      virtual Int_t    GetEntry(Long64_t entry);
      virtual Long64_t LoadTree(Long64_t entry);
      virtual void     Init(TTree *tree);
      virtual void     Loop();
      virtual Bool_t   Notify();
      virtual void     Show(Long64_t entry = -1);
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
    pixClus_id = 0;
    pixClus_bec = 0;
    pixClus_layer = 0;
    pixClus_detElementId = 0;
    pixClus_phi_module = 0;
    pixClus_eta_module = 0;
    pixClus_col = 0;
    pixClus_row = 0;
    pixClus_charge = 0;
    pixClus_LVL1A = 0;
    pixClus_sizePhi = 0;
    pixClus_sizeZ = 0;
    pixClus_size = 0;
    pixClus_locX = 0;
    pixClus_locY = 0;
    pixClus_x = 0;
    pixClus_y = 0;
    pixClus_z = 0;
    pixClus_isFake = 0;
    pixClus_isGanged = 0;
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
    TotalEt_tower_eta = 0;
    TotalEt_tower_phi = 0;
    TotalEt_tower_area = 0;
    TotalEt_tower_sampling = 0;
    TotalEt_tower_sampling_calib = 0;
    TotalEt_layer_eta = 0;
    TotalEt_layer_phi = 0;
    TotalEt_layer_area = 0;
    TotalEt_layer_sampling = 0;
    TotalEt_layer_sampling_calib = 0;
    trk_pt = 0;
    trk_eta = 0;
    trk_d0_wrtPV = 0;
    trk_err_d0_wrtPV = 0;
    trk_z0_wrtPV = 0;
    trk_err_z0_wrtPV = 0;
    trk_phi_wrtPV = 0;
    trk_theta = 0;
    trk_err_theta_wrtPV = 0;
    trk_qoverp = 0;
    trk_cov_z0_theta_wrtPV = 0;
    trk_cov_d0_wrtPV = 0;
    trk_cov_z0_wrtPV = 0;
    trk_cov_phi_wrtPV = 0;
    trk_cov_theta_wrtPV = 0;
    trk_cov_qoverp_wrtPV = 0;
    trk_chi2 = 0;
    trk_ndof = 0;
    trk_nBLHits = 0;
    trk_nPixHits = 0;
    trk_nSCTHits = 0;
    trk_nTRTHits = 0;
    trk_nPixHoles = 0;
    trk_nSCTHoles = 0;
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
    trk_pixeldEdx = 0;
    trk_fitter = 0;
    trk_patternReco1 = 0;
    trk_patternReco2 = 0;
    trk_seedFinder = 0;
    trk_expectBLayerHit = 0;
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
    pTrklets_nBPixClus = 0;
    pTrklets_n1PixClus = 0;
    pTrklets_n2PixClus = 0;
    pTrklets_layerSum = 0;
    pTrklets_eta = 0;
    pTrklets_phi = 0;
    pTrklets_pt = 0;
    pTrklets_deta = 0;
    pTrklets_dphi = 0;
    pTrklets_etaS = 0;
    pTrklets_phiS = 0;
    pTrklets_energy0 = 0;
    pTrklets_energy1 = 0;
    pTrklets_cSize0 = 0;
    pTrklets_cSize1 = 0;
    pTrklets_cRowSize0 = 0;
    pTrklets_cRowSize1 = 0;
    pTrklets_cColSize0 = 0;
    pTrklets_cColSize1 = 0;
    pTrklets_clusIds = 0;
    trkPix_pt = 0;
    trkPix_eta = 0;
    trkPix_d0_wrtPV = 0;
    trkPix_z0_wrtPV = 0;
    trkPix_phi_wrtPV = 0;
    trkPix_theta_wrtPV = 0;
    trkPix_qoverp_wrtPV = 0;
    trkPix_cov_d0_wrtPV = 0;
    trkPix_cov_z0_wrtPV = 0;
    trkPix_cov_phi_wrtPV = 0;
    trkPix_cov_theta_wrtPV = 0;
    trkPix_cov_qoverp_wrtPV = 0;
    trkPix_chi2 = 0;
    trkPix_ndof = 0;
    trkPix_nBLHits = 0;
    trkPix_nPixHits = 0;
    trkPix_nSCTHits = 0;
    trkPix_nTRTHits = 0;
    trkPix_nPixHoles = 0;
    trkPix_nSCTHoles = 0;
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
    trkPix_pixeldEdx = 0;
    trkPix_fitter = 0;
    trkPix_patternReco1 = 0;
    trkPix_patternReco2 = 0;
    trkPix_seedFinder = 0;
    trkPix_blayerPrediction_expectHit = 0;
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
    antikt4Tow_tower_CaloBkgrEt = 0;
    antikt4Tow_tower_CaloBkgrRMS = 0;
    antikt4Tow_tower_CaloBkgrCounts = 0;
    antikt4Tow_tower_CaloBkgrEta = 0;
    antikt4Tow_layer_CaloBkgrEt = 0;
    antikt4Tow_layer_CaloBkgrRMS = 0;
    antikt4Tow_layer_CaloBkgrCounts = 0;
    antikt4Tow_layer_CaloBkgrEta = 0;
    antikt4FlowTow_tower_CaloBkgrEt = 0;
    antikt4FlowTow_tower_CaloBkgrRMS = 0;
    antikt4FlowTow_tower_CaloBkgrCounts = 0;
    antikt4FlowTow_tower_CaloBkgrEta = 0;
    antikt4FlowTow_layer_CaloBkgrEt = 0;
    antikt4FlowTow_layer_CaloBkgrRMS = 0;
    antikt4FlowTow_layer_CaloBkgrCounts = 0;
    antikt4FlowTow_layer_CaloBkgrEta = 0;
    antikt4EMTow_tower_CaloBkgrEt = 0;
    antikt4EMTow_tower_CaloBkgrRMS = 0;
    antikt4EMTow_tower_CaloBkgrCounts = 0;
    antikt4EMTow_tower_CaloBkgrEta = 0;
    antikt4EMTow_layer_CaloBkgrEt = 0;
    antikt4EMTow_layer_CaloBkgrRMS = 0;
    antikt4EMTow_layer_CaloBkgrCounts = 0;
    antikt4EMTow_layer_CaloBkgrEta = 0;
    AvgTower_tower_CaloBkgrEt = 0;
    AvgTower_tower_CaloBkgrRMS = 0;
    AvgTower_tower_CaloBkgrCounts = 0;
    AvgTower_tower_CaloBkgrEta = 0;
    AvgTower_layer_CaloBkgrEt = 0;
    AvgTower_layer_CaloBkgrRMS = 0;
    AvgTower_layer_CaloBkgrCounts = 0;
    AvgTower_layer_CaloBkgrEta = 0;
    AvgTower3Sigma_tower_CaloBkgrEt = 0;
    AvgTower3Sigma_tower_CaloBkgrRMS = 0;
    AvgTower3Sigma_tower_CaloBkgrCounts = 0;
    AvgTower3Sigma_tower_CaloBkgrEta = 0;
    AvgTower4Sigma_tower_CaloBkgrEt = 0;
    AvgTower4Sigma_tower_CaloBkgrRMS = 0;
    AvgTower4Sigma_tower_CaloBkgrCounts = 0;
    AvgTower4Sigma_tower_CaloBkgrEta = 0;
    AvgTowerFlow_tower_CaloBkgrEt = 0;
    AvgTowerFlow_tower_CaloBkgrRMS = 0;
    AvgTowerFlow_tower_CaloBkgrCounts = 0;
    AvgTowerFlow_tower_CaloBkgrEta = 0;
    AvgTowerFlow_layer_CaloBkgrEt = 0;
    AvgTowerFlow_layer_CaloBkgrRMS = 0;
    AvgTowerFlow_layer_CaloBkgrCounts = 0;
    AvgTowerFlow_layer_CaloBkgrEta = 0;
    antikt4TowItr_tower_CaloBkgrEt = 0;
    antikt4TowItr_tower_CaloBkgrRMS = 0;
    antikt4TowItr_tower_CaloBkgrCounts = 0;
    antikt4TowItr_tower_CaloBkgrEta = 0;
    antikt4TowItr_layer_CaloBkgrEt = 0;
    antikt4TowItr_layer_CaloBkgrRMS = 0;
    antikt4TowItr_layer_CaloBkgrCounts = 0;
    antikt4TowItr_layer_CaloBkgrEta = 0;
    antikt4TowFlowItr_tower_CaloBkgrEt = 0;
    antikt4TowFlowItr_tower_CaloBkgrRMS = 0;
    antikt4TowFlowItr_tower_CaloBkgrCounts = 0;
    antikt4TowFlowItr_tower_CaloBkgrEta = 0;
    antikt4TowFlowItr_layer_CaloBkgrEt = 0;
    antikt4TowFlowItr_layer_CaloBkgrRMS = 0;
    antikt4TowFlowItr_layer_CaloBkgrCounts = 0;
    antikt4TowFlowItr_layer_CaloBkgrEta = 0;
    antikt4HI_E = 0;
    antikt4HI_pt = 0;
    antikt4HI_m = 0;
    antikt4HI_eta = 0;
    antikt4HI_phi = 0;
    antikt4HI_MaxOverMean = 0;
    antikt4HI_MeanTowerEt = 0;
    antikt4HI_SubtractedEt = 0;
    antikt4HI_RMSTowerEt = 0;
    antikt4HI_SumJt = 0;
    antikt4HI_CoreEt = 0;
    antikt4HI_EdgeEt = 0;
    antikt4HI_CryoCorr = 0;
    antikt4HI_NoFlow = 0;
    antikt4HI_NumConstituents = 0;
    antikt4HI_UncalibEt = 0;
    antikt4HI_Discriminant = 0;
    antikt4HI_MeanTowerEtUnsubtr = 0;
    antikt4HI_n90 = 0;
    antikt4HI_fracSamplingMax = 0;
    antikt4HI_SamplingMax = 0;
    antikt4HI_n90constituents = 0;
    antikt4HI_Timing = 0;
    antikt4HI_LArQuality = 0;
    antikt4HI_HECQuality = 0;
    antikt4HI_TileQuality = 0;
    antikt4HI_const_n = 0;
    antikt4HI_const_et = 0;
    antikt4HI_const_eta = 0;
    antikt4HI_const_phi = 0;
    antikt4HI_sampling_et = 0;
    antikt4HI_sampling_et_unsubtr = 0;
    antikt4HI_bad_cell_n = 0;
    antikt4HI_bad_cell_et = 0;
    antikt4HI_bad_cell_area = 0;
    antikt4HI_empty_cell_n = 0;
    antikt4HI_empty_cell_et = 0;
    antikt4HI_empty_cell_area = 0;
    antikt4HI_total_cell_n = 0;
    antikt4HI_total_cell_et = 0;
    antikt4HI_total_cell_area = 0;
    antikt4HIFlow_E = 0;
    antikt4HIFlow_pt = 0;
    antikt4HIFlow_m = 0;
    antikt4HIFlow_eta = 0;
    antikt4HIFlow_phi = 0;
    antikt4HIFlow_MaxOverMean = 0;
    antikt4HIFlow_MeanTowerEt = 0;
    antikt4HIFlow_SubtractedEt = 0;
    antikt4HIFlow_RMSTowerEt = 0;
    antikt4HIFlow_SumJt = 0;
    antikt4HIFlow_CoreEt = 0;
    antikt4HIFlow_EdgeEt = 0;
    antikt4HIFlow_CryoCorr = 0;
    antikt4HIFlow_NoFlow = 0;
    antikt4HIFlow_NumConstituents = 0;
    antikt4HIFlow_UncalibEt = 0;
    antikt4HIFlow_Discriminant = 0;
    antikt4HIFlow_MeanTowerEtUnsubtr = 0;
    antikt4HIFlow_n90 = 0;
    antikt4HIFlow_fracSamplingMax = 0;
    antikt4HIFlow_SamplingMax = 0;
    antikt4HIFlow_n90constituents = 0;
    antikt4HIFlow_Timing = 0;
    antikt4HIFlow_LArQuality = 0;
    antikt4HIFlow_HECQuality = 0;
    antikt4HIFlow_TileQuality = 0;
    antikt4HIFlow_const_n = 0;
    antikt4HIFlow_const_et = 0;
    antikt4HIFlow_const_eta = 0;
    antikt4HIFlow_const_phi = 0;
    antikt4HIFlow_sampling_et = 0;
    antikt4HIFlow_sampling_et_unsubtr = 0;
    antikt4HIFlow_bad_cell_n = 0;
    antikt4HIFlow_bad_cell_et = 0;
    antikt4HIFlow_bad_cell_area = 0;
    antikt4HIFlow_empty_cell_n = 0;
    antikt4HIFlow_empty_cell_et = 0;
    antikt4HIFlow_empty_cell_area = 0;
    antikt4HIFlow_total_cell_n = 0;
    antikt4HIFlow_total_cell_et = 0;
    antikt4HIFlow_total_cell_area = 0;
    antikt4HIAvgFlow_E = 0;
    antikt4HIAvgFlow_pt = 0;
    antikt4HIAvgFlow_m = 0;
    antikt4HIAvgFlow_eta = 0;
    antikt4HIAvgFlow_phi = 0;
    antikt4HIAvgFlow_MaxOverMean = 0;
    antikt4HIAvgFlow_MeanTowerEt = 0;
    antikt4HIAvgFlow_SubtractedEt = 0;
    antikt4HIAvgFlow_RMSTowerEt = 0;
    antikt4HIAvgFlow_SumJt = 0;
    antikt4HIAvgFlow_CoreEt = 0;
    antikt4HIAvgFlow_EdgeEt = 0;
    antikt4HIAvgFlow_CryoCorr = 0;
    antikt4HIAvgFlow_NoFlow = 0;
    antikt4HIAvgFlow_NumConstituents = 0;
    antikt4HIAvgFlow_UncalibEt = 0;
    antikt4HIAvgFlow_Discriminant = 0;
    antikt4HIAvgFlow_MeanTowerEtUnsubtr = 0;
    antikt4HIAvgFlow_n90 = 0;
    antikt4HIAvgFlow_fracSamplingMax = 0;
    antikt4HIAvgFlow_SamplingMax = 0;
    antikt4HIAvgFlow_n90constituents = 0;
    antikt4HIAvgFlow_Timing = 0;
    antikt4HIAvgFlow_LArQuality = 0;
    antikt4HIAvgFlow_HECQuality = 0;
    antikt4HIAvgFlow_TileQuality = 0;
    antikt4HIAvgFlow_const_n = 0;
    antikt4HIAvgFlow_const_et = 0;
    antikt4HIAvgFlow_const_eta = 0;
    antikt4HIAvgFlow_const_phi = 0;
    antikt4HIAvgFlow_sampling_et = 0;
    antikt4HIAvgFlow_sampling_et_unsubtr = 0;
    antikt4HIAvgFlow_bad_cell_n = 0;
    antikt4HIAvgFlow_bad_cell_et = 0;
    antikt4HIAvgFlow_bad_cell_area = 0;
    antikt4HIAvgFlow_empty_cell_n = 0;
    antikt4HIAvgFlow_empty_cell_et = 0;
    antikt4HIAvgFlow_empty_cell_area = 0;
    antikt4HIAvgFlow_total_cell_n = 0;
    antikt4HIAvgFlow_total_cell_et = 0;
    antikt4HIAvgFlow_total_cell_area = 0;
    antikt4HIItr_E = 0;
    antikt4HIItr_pt = 0;
    antikt4HIItr_m = 0;
    antikt4HIItr_eta = 0;
    antikt4HIItr_phi = 0;
    antikt4HIItr_MaxOverMean = 0;
    antikt4HIItr_MeanTowerEt = 0;
    antikt4HIItr_SubtractedEt = 0;
    antikt4HIItr_RMSTowerEt = 0;
    antikt4HIItr_SumJt = 0;
    antikt4HIItr_CoreEt = 0;
    antikt4HIItr_EdgeEt = 0;
    antikt4HIItr_CryoCorr = 0;
    antikt4HIItr_NoFlow = 0;
    antikt4HIItr_NumConstituents = 0;
    antikt4HIItr_UncalibEt = 0;
    antikt4HIItr_Discriminant = 0;
    antikt4HIItr_MeanTowerEtUnsubtr = 0;
    antikt4HIItr_n90 = 0;
    antikt4HIItr_fracSamplingMax = 0;
    antikt4HIItr_SamplingMax = 0;
    antikt4HIItr_n90constituents = 0;
    antikt4HIItr_Timing = 0;
    antikt4HIItr_LArQuality = 0;
    antikt4HIItr_HECQuality = 0;
    antikt4HIItr_TileQuality = 0;
    antikt4HIItr_const_n = 0;
    antikt4HIItr_const_et = 0;
    antikt4HIItr_const_eta = 0;
    antikt4HIItr_const_phi = 0;
    antikt4HIItr_sampling_et = 0;
    antikt4HIItr_sampling_et_unsubtr = 0;
    antikt4HIItr_bad_cell_n = 0;
    antikt4HIItr_bad_cell_et = 0;
    antikt4HIItr_bad_cell_area = 0;
    antikt4HIItr_empty_cell_n = 0;
    antikt4HIItr_empty_cell_et = 0;
    antikt4HIItr_empty_cell_area = 0;
    antikt4HIItr_total_cell_n = 0;
    antikt4HIItr_total_cell_et = 0;
    antikt4HIItr_total_cell_area = 0;
    antikt4HIItrFlow_E = 0;
    antikt4HIItrFlow_pt = 0;
    antikt4HIItrFlow_m = 0;
    antikt4HIItrFlow_eta = 0;
    antikt4HIItrFlow_phi = 0;
    antikt4HIItrFlow_MaxOverMean = 0;
    antikt4HIItrFlow_MeanTowerEt = 0;
    antikt4HIItrFlow_SubtractedEt = 0;
    antikt4HIItrFlow_RMSTowerEt = 0;
    antikt4HIItrFlow_SumJt = 0;
    antikt4HIItrFlow_CoreEt = 0;
    antikt4HIItrFlow_EdgeEt = 0;
    antikt4HIItrFlow_CryoCorr = 0;
    antikt4HIItrFlow_NoFlow = 0;
    antikt4HIItrFlow_NumConstituents = 0;
    antikt4HIItrFlow_UncalibEt = 0;
    antikt4HIItrFlow_Discriminant = 0;
    antikt4HIItrFlow_MeanTowerEtUnsubtr = 0;
    antikt4HIItrFlow_n90 = 0;
    antikt4HIItrFlow_fracSamplingMax = 0;
    antikt4HIItrFlow_SamplingMax = 0;
    antikt4HIItrFlow_n90constituents = 0;
    antikt4HIItrFlow_Timing = 0;
    antikt4HIItrFlow_LArQuality = 0;
    antikt4HIItrFlow_HECQuality = 0;
    antikt4HIItrFlow_TileQuality = 0;
    antikt4HIItrFlow_const_n = 0;
    antikt4HIItrFlow_const_et = 0;
    antikt4HIItrFlow_const_eta = 0;
    antikt4HIItrFlow_const_phi = 0;
    antikt4HIItrFlow_sampling_et = 0;
    antikt4HIItrFlow_sampling_et_unsubtr = 0;
    antikt4HIItrFlow_bad_cell_n = 0;
    antikt4HIItrFlow_bad_cell_et = 0;
    antikt4HIItrFlow_bad_cell_area = 0;
    antikt4HIItrFlow_empty_cell_n = 0;
    antikt4HIItrFlow_empty_cell_et = 0;
    antikt4HIItrFlow_empty_cell_area = 0;
    antikt4HIItrFlow_total_cell_n = 0;
    antikt4HIItrFlow_total_cell_et = 0;
    antikt4HIItrFlow_total_cell_area = 0;
    antikt2HIAvg_E = 0;
    antikt2HIAvg_pt = 0;
    antikt2HIAvg_m = 0;
    antikt2HIAvg_eta = 0;
    antikt2HIAvg_phi = 0;
    antikt2HIAvg_MaxOverMean = 0;
    antikt2HIAvg_MeanTowerEt = 0;
    antikt2HIAvg_SubtractedEt = 0;
    antikt2HIAvg_RMSTowerEt = 0;
    antikt2HIAvg_SumJt = 0;
    antikt2HIAvg_CoreEt = 0;
    antikt2HIAvg_EdgeEt = 0;
    antikt2HIAvg_CryoCorr = 0;
    antikt2HIAvg_NoFlow = 0;
    antikt2HIAvg_NumConstituents = 0;
    antikt2HIAvg_UncalibEt = 0;
    antikt2HIAvg_Discriminant = 0;
    antikt2HIAvg_MeanTowerEtUnsubtr = 0;
    antikt2HIAvg_n90 = 0;
    antikt2HIAvg_fracSamplingMax = 0;
    antikt2HIAvg_SamplingMax = 0;
    antikt2HIAvg_n90constituents = 0;
    antikt2HIAvg_Timing = 0;
    antikt2HIAvg_LArQuality = 0;
    antikt2HIAvg_HECQuality = 0;
    antikt2HIAvg_TileQuality = 0;
    antikt2HIAvg_const_n = 0;
    antikt2HIAvg_const_et = 0;
    antikt2HIAvg_const_eta = 0;
    antikt2HIAvg_const_phi = 0;
    antikt2HIAvg_sampling_et = 0;
    antikt2HIAvg_sampling_et_unsubtr = 0;
    antikt2HIAvg_bad_cell_n = 0;
    antikt2HIAvg_bad_cell_et = 0;
    antikt2HIAvg_bad_cell_area = 0;
    antikt2HIAvg_empty_cell_n = 0;
    antikt2HIAvg_empty_cell_et = 0;
    antikt2HIAvg_empty_cell_area = 0;
    antikt2HIAvg_total_cell_n = 0;
    antikt2HIAvg_total_cell_et = 0;
    antikt2HIAvg_total_cell_area = 0;
    antikt4HIAvg_E = 0;
    antikt4HIAvg_pt = 0;
    antikt4HIAvg_m = 0;
    antikt4HIAvg_eta = 0;
    antikt4HIAvg_phi = 0;
    antikt4HIAvg_MaxOverMean = 0;
    antikt4HIAvg_MeanTowerEt = 0;
    antikt4HIAvg_SubtractedEt = 0;
    antikt4HIAvg_RMSTowerEt = 0;
    antikt4HIAvg_SumJt = 0;
    antikt4HIAvg_CoreEt = 0;
    antikt4HIAvg_EdgeEt = 0;
    antikt4HIAvg_CryoCorr = 0;
    antikt4HIAvg_NoFlow = 0;
    antikt4HIAvg_NumConstituents = 0;
    antikt4HIAvg_UncalibEt = 0;
    antikt4HIAvg_Discriminant = 0;
    antikt4HIAvg_MeanTowerEtUnsubtr = 0;
    antikt4HIAvg_n90 = 0;
    antikt4HIAvg_fracSamplingMax = 0;
    antikt4HIAvg_SamplingMax = 0;
    antikt4HIAvg_n90constituents = 0;
    antikt4HIAvg_Timing = 0;
    antikt4HIAvg_LArQuality = 0;
    antikt4HIAvg_HECQuality = 0;
    antikt4HIAvg_TileQuality = 0;
    antikt4HIAvg_const_n = 0;
    antikt4HIAvg_const_et = 0;
    antikt4HIAvg_const_eta = 0;
    antikt4HIAvg_const_phi = 0;
    antikt4HIAvg_sampling_et = 0;
    antikt4HIAvg_sampling_et_unsubtr = 0;
    antikt4HIAvg_bad_cell_n = 0;
    antikt4HIAvg_bad_cell_et = 0;
    antikt4HIAvg_bad_cell_area = 0;
    antikt4HIAvg_empty_cell_n = 0;
    antikt4HIAvg_empty_cell_et = 0;
    antikt4HIAvg_empty_cell_area = 0;
    antikt4HIAvg_total_cell_n = 0;
    antikt4HIAvg_total_cell_et = 0;
    antikt4HIAvg_total_cell_area = 0;
    antikt6HIAvg_E = 0;
    antikt6HIAvg_pt = 0;
    antikt6HIAvg_m = 0;
    antikt6HIAvg_eta = 0;
    antikt6HIAvg_phi = 0;
    antikt6HIAvg_MaxOverMean = 0;
    antikt6HIAvg_MeanTowerEt = 0;
    antikt6HIAvg_SubtractedEt = 0;
    antikt6HIAvg_RMSTowerEt = 0;
    antikt6HIAvg_SumJt = 0;
    antikt6HIAvg_CoreEt = 0;
    antikt6HIAvg_EdgeEt = 0;
    antikt6HIAvg_CryoCorr = 0;
    antikt6HIAvg_NoFlow = 0;
    antikt6HIAvg_NumConstituents = 0;
    antikt6HIAvg_UncalibEt = 0;
    antikt6HIAvg_Discriminant = 0;
    antikt6HIAvg_MeanTowerEtUnsubtr = 0;
    antikt6HIAvg_n90 = 0;
    antikt6HIAvg_fracSamplingMax = 0;
    antikt6HIAvg_SamplingMax = 0;
    antikt6HIAvg_n90constituents = 0;
    antikt6HIAvg_Timing = 0;
    antikt6HIAvg_LArQuality = 0;
    antikt6HIAvg_HECQuality = 0;
    antikt6HIAvg_TileQuality = 0;
    antikt6HIAvg_const_n = 0;
    antikt6HIAvg_const_et = 0;
    antikt6HIAvg_const_eta = 0;
    antikt6HIAvg_const_phi = 0;
    antikt6HIAvg_sampling_et = 0;
    antikt6HIAvg_sampling_et_unsubtr = 0;
    antikt6HIAvg_bad_cell_n = 0;
    antikt6HIAvg_bad_cell_et = 0;
    antikt6HIAvg_bad_cell_area = 0;
    antikt6HIAvg_empty_cell_n = 0;
    antikt6HIAvg_empty_cell_et = 0;
    antikt6HIAvg_empty_cell_area = 0;
    antikt6HIAvg_total_cell_n = 0;
    antikt6HIAvg_total_cell_et = 0;
    antikt6HIAvg_total_cell_area = 0;
    antikt4HIEM_E = 0;
    antikt4HIEM_pt = 0;
    antikt4HIEM_m = 0;
    antikt4HIEM_eta = 0;
    antikt4HIEM_phi = 0;
    antikt4HIEM_MaxOverMean = 0;
    antikt4HIEM_MeanTowerEt = 0;
    antikt4HIEM_SubtractedEt = 0;
    antikt4HIEM_RMSTowerEt = 0;
    antikt4HIEM_SumJt = 0;
    antikt4HIEM_CoreEt = 0;
    antikt4HIEM_EdgeEt = 0;
    antikt4HIEM_CryoCorr = 0;
    antikt4HIEM_NoFlow = 0;
    antikt4HIEM_NumConstituents = 0;
    antikt4HIEM_UncalibEt = 0;
    antikt4HIEM_Discriminant = 0;
    antikt4HIEM_MeanTowerEtUnsubtr = 0;
    antikt4HIEM_n90 = 0;
    antikt4HIEM_fracSamplingMax = 0;
    antikt4HIEM_SamplingMax = 0;
    antikt4HIEM_n90constituents = 0;
    antikt4HIEM_Timing = 0;
    antikt4HIEM_LArQuality = 0;
    antikt4HIEM_HECQuality = 0;
    antikt4HIEM_TileQuality = 0;
    antikt4HIEM_const_n = 0;
    antikt4HIEM_const_et = 0;
    antikt4HIEM_const_eta = 0;
    antikt4HIEM_const_phi = 0;
    antikt4HIEM_sampling_et = 0;
    antikt4HIEM_sampling_et_unsubtr = 0;
    antikt4HIEM_bad_cell_n = 0;
    antikt4HIEM_bad_cell_et = 0;
    antikt4HIEM_bad_cell_area = 0;
    antikt4HIEM_empty_cell_n = 0;
    antikt4HIEM_empty_cell_et = 0;
    antikt4HIEM_empty_cell_area = 0;
    antikt4HIEM_total_cell_n = 0;
    antikt4HIEM_total_cell_et = 0;
    antikt4HIEM_total_cell_area = 0;
    jetSeed_E = 0;
    jetSeed_pt = 0;
    jetSeed_m = 0;
    jetSeed_eta = 0;
    jetSeed_phi = 0;
    jetSeed3Sigma_E = 0;
    jetSeed3Sigma_pt = 0;
    jetSeed3Sigma_m = 0;
    jetSeed3Sigma_eta = 0;
    jetSeed3Sigma_phi = 0;
    jetSeed4Sigma_E = 0;
    jetSeed4Sigma_pt = 0;
    jetSeed4Sigma_m = 0;
    jetSeed4Sigma_eta = 0;
    jetSeed4Sigma_phi = 0;
    cone2HI_E = 0;
    cone2HI_pt = 0;
    cone2HI_m = 0;
    cone2HI_eta = 0;
    cone2HI_phi = 0;
    cone2HI_MaxOverMean = 0;
    cone2HI_MeanTowerEt = 0;
    cone2HI_SubtractedEt = 0;
    cone2HI_RMSTowerEt = 0;
    cone2HI_SumJt = 0;
    cone2HI_CoreEt = 0;
    cone2HI_EdgeEt = 0;
    cone2HI_CryoCorr = 0;
    cone2HI_NoFlow = 0;
    cone2HI_NumConstituents = 0;
    cone2HI_UncalibEt = 0;
    cone2HI_Discriminant = 0;
    cone2HI_MeanTowerEtUnsubtr = 0;
    cone2HI_n90 = 0;
    cone2HI_fracSamplingMax = 0;
    cone2HI_SamplingMax = 0;
    cone2HI_n90constituents = 0;
    cone2HI_Timing = 0;
    cone2HI_LArQuality = 0;
    cone2HI_HECQuality = 0;
    cone2HI_TileQuality = 0;
    cone2HI_const_n = 0;
    cone2HI_const_et = 0;
    cone2HI_const_eta = 0;
    cone2HI_const_phi = 0;
    cone2HI_sampling_et = 0;
    cone2HI_sampling_et_unsubtr = 0;
    cone2HI_bad_cell_n = 0;
    cone2HI_bad_cell_et = 0;
    cone2HI_bad_cell_area = 0;
    cone2HI_empty_cell_n = 0;
    cone2HI_empty_cell_et = 0;
    cone2HI_empty_cell_area = 0;
    cone2HI_total_cell_n = 0;
    cone2HI_total_cell_et = 0;
    cone2HI_total_cell_area = 0;
    cone4HI_E = 0;
    cone4HI_pt = 0;
    cone4HI_m = 0;
    cone4HI_eta = 0;
    cone4HI_phi = 0;
    cone4HI_MaxOverMean = 0;
    cone4HI_MeanTowerEt = 0;
    cone4HI_SubtractedEt = 0;
    cone4HI_RMSTowerEt = 0;
    cone4HI_SumJt = 0;
    cone4HI_CoreEt = 0;
    cone4HI_EdgeEt = 0;
    cone4HI_CryoCorr = 0;
    cone4HI_NoFlow = 0;
    cone4HI_NumConstituents = 0;
    cone4HI_UncalibEt = 0;
    cone4HI_Discriminant = 0;
    cone4HI_MeanTowerEtUnsubtr = 0;
    cone4HI_n90 = 0;
    cone4HI_fracSamplingMax = 0;
    cone4HI_SamplingMax = 0;
    cone4HI_n90constituents = 0;
    cone4HI_Timing = 0;
    cone4HI_LArQuality = 0;
    cone4HI_HECQuality = 0;
    cone4HI_TileQuality = 0;
    cone4HI_const_n = 0;
    cone4HI_const_et = 0;
    cone4HI_const_eta = 0;
    cone4HI_const_phi = 0;
    cone4HI_sampling_et = 0;
    cone4HI_sampling_et_unsubtr = 0;
    cone4HI_bad_cell_n = 0;
    cone4HI_bad_cell_et = 0;
    cone4HI_bad_cell_area = 0;
    cone4HI_empty_cell_n = 0;
    cone4HI_empty_cell_et = 0;
    cone4HI_empty_cell_area = 0;
    cone4HI_total_cell_n = 0;
    cone4HI_total_cell_et = 0;
    cone4HI_total_cell_area = 0;
    cone6HI_E = 0;
    cone6HI_pt = 0;
    cone6HI_m = 0;
    cone6HI_eta = 0;
    cone6HI_phi = 0;
    cone6HI_MaxOverMean = 0;
    cone6HI_MeanTowerEt = 0;
    cone6HI_SubtractedEt = 0;
    cone6HI_RMSTowerEt = 0;
    cone6HI_SumJt = 0;
    cone6HI_CoreEt = 0;
    cone6HI_EdgeEt = 0;
    cone6HI_CryoCorr = 0;
    cone6HI_NoFlow = 0;
    cone6HI_NumConstituents = 0;
    cone6HI_UncalibEt = 0;
    cone6HI_Discriminant = 0;
    cone6HI_MeanTowerEtUnsubtr = 0;
    cone6HI_n90 = 0;
    cone6HI_fracSamplingMax = 0;
    cone6HI_SamplingMax = 0;
    cone6HI_n90constituents = 0;
    cone6HI_Timing = 0;
    cone6HI_LArQuality = 0;
    cone6HI_HECQuality = 0;
    cone6HI_TileQuality = 0;
    cone6HI_const_n = 0;
    cone6HI_const_et = 0;
    cone6HI_const_eta = 0;
    cone6HI_const_phi = 0;
    cone6HI_sampling_et = 0;
    cone6HI_sampling_et_unsubtr = 0;
    cone6HI_bad_cell_n = 0;
    cone6HI_bad_cell_et = 0;
    cone6HI_bad_cell_area = 0;
    cone6HI_empty_cell_n = 0;
    cone6HI_empty_cell_et = 0;
    cone6HI_empty_cell_area = 0;
    cone6HI_total_cell_n = 0;
    cone6HI_total_cell_et = 0;
    cone6HI_total_cell_area = 0;
    CMSCone4HI_E = 0;
    CMSCone4HI_pt = 0;
    CMSCone4HI_m = 0;
    CMSCone4HI_eta = 0;
    CMSCone4HI_phi = 0;
    CMSCone4HI_MaxOverMean = 0;
    CMSCone4HI_MeanTowerEt = 0;
    CMSCone4HI_SubtractedEt = 0;
    CMSCone4HI_RMSTowerEt = 0;
    CMSCone4HI_SumJt = 0;
    CMSCone4HI_CoreEt = 0;
    CMSCone4HI_EdgeEt = 0;
    CMSCone4HI_CryoCorr = 0;
    CMSCone4HI_NoFlow = 0;
    CMSCone4HI_NumConstituents = 0;
    CMSCone4HI_UncalibEt = 0;
    CMSCone4HI_Discriminant = 0;
    CMSCone4HI_MeanTowerEtUnsubtr = 0;
    CMSCone4HI_n90 = 0;
    CMSCone4HI_fracSamplingMax = 0;
    CMSCone4HI_SamplingMax = 0;
    CMSCone4HI_n90constituents = 0;
    CMSCone4HI_Timing = 0;
    CMSCone4HI_LArQuality = 0;
    CMSCone4HI_HECQuality = 0;
    CMSCone4HI_TileQuality = 0;
    CMSCone4HI_const_n = 0;
    CMSCone4HI_const_et = 0;
    CMSCone4HI_const_eta = 0;
    CMSCone4HI_const_phi = 0;
    CMSCone4HI_sampling_et = 0;
    CMSCone4HI_sampling_et_unsubtr = 0;
    CMSCone4HI_bad_cell_n = 0;
    CMSCone4HI_bad_cell_et = 0;
    CMSCone4HI_bad_cell_area = 0;
    CMSCone4HI_empty_cell_n = 0;
    CMSCone4HI_empty_cell_et = 0;
    CMSCone4HI_empty_cell_area = 0;
    CMSCone4HI_total_cell_n = 0;
    CMSCone4HI_total_cell_et = 0;
    CMSCone4HI_total_cell_area = 0;
    antikt4Track_E = 0;
    antikt4Track_pt = 0;
    antikt4Track_m = 0;
    antikt4Track_eta = 0;
    antikt4Track_phi = 0;
    antikt4Track_const_n = 0;
    antikt4Track_const_pt = 0;
    antikt4Track_const_eta = 0;
    antikt4Track_const_phi = 0;
    antikt4Track_const_chi2 = 0;
    antikt4Track_const_d0_wrtPV = 0;
    antikt4Track_const_z0_wrtPV = 0;
    antikt4Track_const_phi0_wrtPV = 0;
    antikt4Track_const_theta_wrtPV = 0;
    antikt4Track_const_qop = 0;
    antikt4Track_const_ndof = 0;
    antikt4Track_const_nBLayerHits = 0;
    antikt4Track_const_nPixelHits = 0;
    antikt4Track_const_nSCTHits = 0;
    antikt4Track_const_nTRTHits = 0;
    antikt6Track_E = 0;
    antikt6Track_pt = 0;
    antikt6Track_m = 0;
    antikt6Track_eta = 0;
    antikt6Track_phi = 0;
    antikt6Track_const_n = 0;
    antikt6Track_const_pt = 0;
    antikt6Track_const_eta = 0;
    antikt6Track_const_phi = 0;
    antikt6Track_const_chi2 = 0;
    antikt6Track_const_d0_wrtPV = 0;
    antikt6Track_const_z0_wrtPV = 0;
    antikt6Track_const_phi0_wrtPV = 0;
    antikt6Track_const_theta_wrtPV = 0;
    antikt6Track_const_qop = 0;
    antikt6Track_const_ndof = 0;
    antikt6Track_const_nBLayerHits = 0;
    antikt6Track_const_nPixelHits = 0;
    antikt6Track_const_nSCTHits = 0;
    antikt6Track_const_nTRTHits = 0;
    HIFlow_PsiHICaloUtilLayers = 0;
    HIFlow_PsiEtHICaloUtilLayers = 0;
    HIFlow_Meanv2_Psi_From_EMB1CaloCel_IDLayers = 0;
    HIFlow_Meanv2_Psi_From_FCAL0CaloCel_IDLayers = 0;
    HIFlow_Meanv2Et_Psi_From_EMB1CaloCel_IDLayers = 0;
    HIFlow_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers = 0;
    HIFlow_v2Eta_Psi_From_EMBP1_InDet_EMBN1 = 0;
    HIFlow_v2Eta_Psi_From_EMBN1_InDet_EMBP1 = 0;
    HIFlow_v2Eta_Psi_From_EMBP1_InDet_FCALN0 = 0;
    HIFlow_v2Eta_Psi_From_EMBN1_InDet_FCALP0 = 0;
    HIFlow_v2Eta_Psi_From_FCALN0_InDet_EMBN1 = 0;
    HIFlow_v2Eta_Psi_From_FCALP0_InDet_EMBP1 = 0;
    HIFlow_v2Eta_Psi_From_FCALP0_InDet_FCALN0 = 0;
    HIFlow_v2Eta_Psi_From_FCALN0_InDet_FCALP0 = 0;
    HIFlow_v2EtaEt_Psi_From_EMBP1_InDet_EMBN1 = 0;
    HIFlow_v2EtaEt_Psi_From_EMBN1_InDet_EMBP1 = 0;
    HIFlow_v2EtaEt_Psi_From_EMBP1_InDet_FCALN0 = 0;
    HIFlow_v2EtaEt_Psi_From_EMBN1_InDet_FCALP0 = 0;
    HIFlow_v2EtaEt_Psi_From_FCALN0_InDet_EMBN1 = 0;
    HIFlow_v2EtaEt_Psi_From_FCALP0_InDet_EMBP1 = 0;
    HIFlow_v2EtaEt_Psi_From_FCALP0_InDet_FCALN0 = 0;
    HIFlow_v2EtaEt_Psi_From_FCALN0_InDet_FCALP0 = 0;
    HIFlow_EtaEMBN1 = 0;
    HIFlow_EtaEMBP1 = 0;
    HIFlow_EtaFCALN0 = 0;
    HIFlow_EtaFCALP0 = 0;
    emcl_E = 0;
    emcl_pt = 0;
    emcl_m = 0;
    emcl_eta = 0;
    emcl_phi = 0;
    emcl_E_em = 0;
    emcl_E_had = 0;
    mu_staco_E = 0;
    mu_staco_pt = 0;
    mu_staco_m = 0;
    mu_staco_eta = 0;
    mu_staco_phi = 0;
    mu_staco_px = 0;
    mu_staco_py = 0;
    mu_staco_pz = 0;
    mu_staco_charge = 0;
    mu_staco_allauthor = 0;
    mu_staco_author = 0;
    mu_staco_matchchi2 = 0;
    mu_staco_matchndof = 0;
    mu_staco_etcone20 = 0;
    mu_staco_etcone30 = 0;
    mu_staco_etcone40 = 0;
    mu_staco_nucone20 = 0;
    mu_staco_nucone30 = 0;
    mu_staco_nucone40 = 0;
    mu_staco_ptcone20 = 0;
    mu_staco_ptcone30 = 0;
    mu_staco_ptcone40 = 0;
    mu_staco_energyLossPar = 0;
    mu_staco_energyLossErr = 0;
    mu_staco_etCore = 0;
    mu_staco_energyLossType = 0;
    mu_staco_bestMatch = 0;
    mu_staco_isStandAloneMuon = 0;
    mu_staco_isCombinedMuon = 0;
    mu_staco_isLowPtReconstructedMuon = 0;
    mu_staco_loose = 0;
    mu_staco_medium = 0;
    mu_staco_tight = 0;
    mu_staco_d0_exPV = 0;
    mu_staco_z0_exPV = 0;
    mu_staco_phi_exPV = 0;
    mu_staco_theta_exPV = 0;
    mu_staco_qoverp_exPV = 0;
    mu_staco_cb_d0_exPV = 0;
    mu_staco_cb_z0_exPV = 0;
    mu_staco_cb_phi_exPV = 0;
    mu_staco_cb_theta_exPV = 0;
    mu_staco_cb_qoverp_exPV = 0;
    mu_staco_id_d0_exPV = 0;
    mu_staco_id_z0_exPV = 0;
    mu_staco_id_phi_exPV = 0;
    mu_staco_id_theta_exPV = 0;
    mu_staco_id_qoverp_exPV = 0;
    mu_staco_me_d0_exPV = 0;
    mu_staco_me_z0_exPV = 0;
    mu_staco_me_phi_exPV = 0;
    mu_staco_me_theta_exPV = 0;
    mu_staco_me_qoverp_exPV = 0;
    mu_staco_ie_d0_exPV = 0;
    mu_staco_ie_z0_exPV = 0;
    mu_staco_ie_phi_exPV = 0;
    mu_staco_ie_theta_exPV = 0;
    mu_staco_ie_qoverp_exPV = 0;
    mu_staco_cov_d0_exPV = 0;
    mu_staco_cov_z0_exPV = 0;
    mu_staco_cov_phi_exPV = 0;
    mu_staco_cov_theta_exPV = 0;
    mu_staco_cov_qoverp_exPV = 0;
    mu_staco_cov_d0_z0_exPV = 0;
    mu_staco_cov_d0_phi_exPV = 0;
    mu_staco_cov_d0_theta_exPV = 0;
    mu_staco_cov_d0_qoverp_exPV = 0;
    mu_staco_cov_z0_phi_exPV = 0;
    mu_staco_cov_z0_theta_exPV = 0;
    mu_staco_cov_z0_qoverp_exPV = 0;
    mu_staco_cov_phi_theta_exPV = 0;
    mu_staco_cov_phi_qoverp_exPV = 0;
    mu_staco_cov_theta_qoverp_exPV = 0;
    mu_staco_ms_d0 = 0;
    mu_staco_ms_z0 = 0;
    mu_staco_ms_phi = 0;
    mu_staco_ms_theta = 0;
    mu_staco_ms_qoverp = 0;
    mu_staco_id_d0 = 0;
    mu_staco_id_z0 = 0;
    mu_staco_id_phi = 0;
    mu_staco_id_theta = 0;
    mu_staco_id_qoverp = 0;
    mu_staco_me_d0 = 0;
    mu_staco_me_z0 = 0;
    mu_staco_me_phi = 0;
    mu_staco_me_theta = 0;
    mu_staco_me_qoverp = 0;
    mu_staco_ie_d0 = 0;
    mu_staco_ie_z0 = 0;
    mu_staco_ie_phi = 0;
    mu_staco_ie_theta = 0;
    mu_staco_ie_qoverp = 0;
    mu_staco_nBLHits = 0;
    mu_staco_nPixHits = 0;
    mu_staco_nSCTHits = 0;
    mu_staco_nTRTHits = 0;
    mu_staco_nTRTHighTHits = 0;
    mu_staco_nBLSharedHits = 0;
    mu_staco_nPixSharedHits = 0;
    mu_staco_nPixHoles = 0;
    mu_staco_nSCTSharedHits = 0;
    mu_staco_nSCTHoles = 0;
    mu_staco_nTRTOutliers = 0;
    mu_staco_nTRTHighTOutliers = 0;
    mu_staco_nMDTHits = 0;
    mu_staco_nMDTHoles = 0;
    mu_staco_nCSCEtaHits = 0;
    mu_staco_nCSCEtaHoles = 0;
    mu_staco_nCSCPhiHits = 0;
    mu_staco_nCSCPhiHoles = 0;
    mu_staco_nRPCEtaHits = 0;
    mu_staco_nRPCEtaHoles = 0;
    mu_staco_nRPCPhiHits = 0;
    mu_staco_nRPCPhiHoles = 0;
    mu_staco_nTGCEtaHits = 0;
    mu_staco_nTGCEtaHoles = 0;
    mu_staco_nTGCPhiHits = 0;
    mu_staco_nTGCPhiHoles = 0;
    mu_staco_nGangedPixels = 0;
    mu_staco_nOutliersOnTrack = 0;
    mu_staco_nMDTBIHits = 0;
    mu_staco_nMDTBMHits = 0;
    mu_staco_nMDTBOHits = 0;
    mu_staco_nMDTBEEHits = 0;
    mu_staco_nMDTBIS78Hits = 0;
    mu_staco_nMDTEIHits = 0;
    mu_staco_nMDTEMHits = 0;
    mu_staco_nMDTEOHits = 0;
    mu_staco_nMDTEEHits = 0;
    mu_staco_nRPCLayer1EtaHits = 0;
    mu_staco_nRPCLayer2EtaHits = 0;
    mu_staco_nRPCLayer3EtaHits = 0;
    mu_staco_nRPCLayer1PhiHits = 0;
    mu_staco_nRPCLayer2PhiHits = 0;
    mu_staco_nRPCLayer3PhiHits = 0;
    mu_staco_nTGCLayer1EtaHits = 0;
    mu_staco_nTGCLayer2EtaHits = 0;
    mu_staco_nTGCLayer3EtaHits = 0;
    mu_staco_nTGCLayer4EtaHits = 0;
    mu_staco_nTGCLayer1PhiHits = 0;
    mu_staco_nTGCLayer2PhiHits = 0;
    mu_staco_nTGCLayer3PhiHits = 0;
    mu_staco_nTGCLayer4PhiHits = 0;
    mu_staco_barrelSectors = 0;
    mu_staco_endcapSectors = 0;
    mu_staco_trackd0 = 0;
    mu_staco_trackz0 = 0;
    mu_staco_trackphi = 0;
    mu_staco_tracktheta = 0;
    mu_staco_trackqoverp = 0;
    mu_staco_trackcov_d0 = 0;
    mu_staco_trackcov_z0 = 0;
    mu_staco_trackcov_phi = 0;
    mu_staco_trackcov_theta = 0;
    mu_staco_trackcov_qoverp = 0;
    mu_staco_trackcov_d0_z0 = 0;
    mu_staco_trackcov_d0_phi = 0;
    mu_staco_trackcov_d0_theta = 0;
    mu_staco_trackcov_d0_qoverp = 0;
    mu_staco_trackcov_z0_phi = 0;
    mu_staco_trackcov_z0_theta = 0;
    mu_staco_trackcov_z0_qoverp = 0;
    mu_staco_trackcov_phi_theta = 0;
    mu_staco_trackcov_phi_qoverp = 0;
    mu_staco_trackcov_theta_qoverp = 0;
    mu_staco_trackfitchi2 = 0;
    mu_staco_trackfitndof = 0;
    mu_staco_hastrack = 0;
    mu_staco_EF_dr = 0;
    mu_staco_EF_cb_eta = 0;
    mu_staco_EF_cb_phi = 0;
    mu_staco_EF_cb_pt = 0;
    mu_staco_EF_ms_eta = 0;
    mu_staco_EF_ms_phi = 0;
    mu_staco_EF_ms_pt = 0;
    mu_staco_EF_me_eta = 0;
    mu_staco_EF_me_phi = 0;
    mu_staco_EF_me_pt = 0;
    mu_staco_EF_matched = 0;
    mu_staco_L2CB_dr = 0;
    mu_staco_L2CB_pt = 0;
    mu_staco_L2CB_eta = 0;
    mu_staco_L2CB_phi = 0;
    mu_staco_L2CB_id_pt = 0;
    mu_staco_L2CB_ms_pt = 0;
    mu_staco_L2CB_nPixHits = 0;
    mu_staco_L2CB_nSCTHits = 0;
    mu_staco_L2CB_nTRTHits = 0;
    mu_staco_L2CB_nTRTHighTHits = 0;
    mu_staco_L2CB_matched = 0;
    mu_staco_L1_dr = 0;
    mu_staco_L1_pt = 0;
    mu_staco_L1_eta = 0;
    mu_staco_L1_phi = 0;
    mu_staco_L1_thrNumber = 0;
    mu_staco_L1_RoINumber = 0;
    mu_staco_L1_sectorAddress = 0;
    mu_staco_L1_firstCandidate = 0;
    mu_staco_L1_moreCandInRoI = 0;
    mu_staco_L1_moreCandInSector = 0;
    mu_staco_L1_source = 0;
    mu_staco_L1_hemisphere = 0;
    mu_staco_L1_matched = 0;
    mu_muid_E = 0;
    mu_muid_pt = 0;
    mu_muid_m = 0;
    mu_muid_eta = 0;
    mu_muid_phi = 0;
    mu_muid_px = 0;
    mu_muid_py = 0;
    mu_muid_pz = 0;
    mu_muid_charge = 0;
    mu_muid_allauthor = 0;
    mu_muid_author = 0;
    mu_muid_matchchi2 = 0;
    mu_muid_matchndof = 0;
    mu_muid_etcone20 = 0;
    mu_muid_etcone30 = 0;
    mu_muid_etcone40 = 0;
    mu_muid_nucone20 = 0;
    mu_muid_nucone30 = 0;
    mu_muid_nucone40 = 0;
    mu_muid_ptcone20 = 0;
    mu_muid_ptcone30 = 0;
    mu_muid_ptcone40 = 0;
    mu_muid_energyLossPar = 0;
    mu_muid_energyLossErr = 0;
    mu_muid_etCore = 0;
    mu_muid_energyLossType = 0;
    mu_muid_bestMatch = 0;
    mu_muid_isStandAloneMuon = 0;
    mu_muid_isCombinedMuon = 0;
    mu_muid_isLowPtReconstructedMuon = 0;
    mu_muid_loose = 0;
    mu_muid_medium = 0;
    mu_muid_tight = 0;
    mu_muid_d0_exPV = 0;
    mu_muid_z0_exPV = 0;
    mu_muid_phi_exPV = 0;
    mu_muid_theta_exPV = 0;
    mu_muid_qoverp_exPV = 0;
    mu_muid_cb_d0_exPV = 0;
    mu_muid_cb_z0_exPV = 0;
    mu_muid_cb_phi_exPV = 0;
    mu_muid_cb_theta_exPV = 0;
    mu_muid_cb_qoverp_exPV = 0;
    mu_muid_id_d0_exPV = 0;
    mu_muid_id_z0_exPV = 0;
    mu_muid_id_phi_exPV = 0;
    mu_muid_id_theta_exPV = 0;
    mu_muid_id_qoverp_exPV = 0;
    mu_muid_me_d0_exPV = 0;
    mu_muid_me_z0_exPV = 0;
    mu_muid_me_phi_exPV = 0;
    mu_muid_me_theta_exPV = 0;
    mu_muid_me_qoverp_exPV = 0;
    mu_muid_ie_d0_exPV = 0;
    mu_muid_ie_z0_exPV = 0;
    mu_muid_ie_phi_exPV = 0;
    mu_muid_ie_theta_exPV = 0;
    mu_muid_ie_qoverp_exPV = 0;
    mu_muid_cov_d0_exPV = 0;
    mu_muid_cov_z0_exPV = 0;
    mu_muid_cov_phi_exPV = 0;
    mu_muid_cov_theta_exPV = 0;
    mu_muid_cov_qoverp_exPV = 0;
    mu_muid_cov_d0_z0_exPV = 0;
    mu_muid_cov_d0_phi_exPV = 0;
    mu_muid_cov_d0_theta_exPV = 0;
    mu_muid_cov_d0_qoverp_exPV = 0;
    mu_muid_cov_z0_phi_exPV = 0;
    mu_muid_cov_z0_theta_exPV = 0;
    mu_muid_cov_z0_qoverp_exPV = 0;
    mu_muid_cov_phi_theta_exPV = 0;
    mu_muid_cov_phi_qoverp_exPV = 0;
    mu_muid_cov_theta_qoverp_exPV = 0;
    mu_muid_ms_d0 = 0;
    mu_muid_ms_z0 = 0;
    mu_muid_ms_phi = 0;
    mu_muid_ms_theta = 0;
    mu_muid_ms_qoverp = 0;
    mu_muid_id_d0 = 0;
    mu_muid_id_z0 = 0;
    mu_muid_id_phi = 0;
    mu_muid_id_theta = 0;
    mu_muid_id_qoverp = 0;
    mu_muid_me_d0 = 0;
    mu_muid_me_z0 = 0;
    mu_muid_me_phi = 0;
    mu_muid_me_theta = 0;
    mu_muid_me_qoverp = 0;
    mu_muid_ie_d0 = 0;
    mu_muid_ie_z0 = 0;
    mu_muid_ie_phi = 0;
    mu_muid_ie_theta = 0;
    mu_muid_ie_qoverp = 0;
    mu_muid_nBLHits = 0;
    mu_muid_nPixHits = 0;
    mu_muid_nSCTHits = 0;
    mu_muid_nTRTHits = 0;
    mu_muid_nTRTHighTHits = 0;
    mu_muid_nBLSharedHits = 0;
    mu_muid_nPixSharedHits = 0;
    mu_muid_nPixHoles = 0;
    mu_muid_nSCTSharedHits = 0;
    mu_muid_nSCTHoles = 0;
    mu_muid_nTRTOutliers = 0;
    mu_muid_nTRTHighTOutliers = 0;
    mu_muid_nMDTHits = 0;
    mu_muid_nMDTHoles = 0;
    mu_muid_nCSCEtaHits = 0;
    mu_muid_nCSCEtaHoles = 0;
    mu_muid_nCSCPhiHits = 0;
    mu_muid_nCSCPhiHoles = 0;
    mu_muid_nRPCEtaHits = 0;
    mu_muid_nRPCEtaHoles = 0;
    mu_muid_nRPCPhiHits = 0;
    mu_muid_nRPCPhiHoles = 0;
    mu_muid_nTGCEtaHits = 0;
    mu_muid_nTGCEtaHoles = 0;
    mu_muid_nTGCPhiHits = 0;
    mu_muid_nTGCPhiHoles = 0;
    mu_muid_nGangedPixels = 0;
    mu_muid_nOutliersOnTrack = 0;
    mu_muid_nMDTBIHits = 0;
    mu_muid_nMDTBMHits = 0;
    mu_muid_nMDTBOHits = 0;
    mu_muid_nMDTBEEHits = 0;
    mu_muid_nMDTBIS78Hits = 0;
    mu_muid_nMDTEIHits = 0;
    mu_muid_nMDTEMHits = 0;
    mu_muid_nMDTEOHits = 0;
    mu_muid_nMDTEEHits = 0;
    mu_muid_nRPCLayer1EtaHits = 0;
    mu_muid_nRPCLayer2EtaHits = 0;
    mu_muid_nRPCLayer3EtaHits = 0;
    mu_muid_nRPCLayer1PhiHits = 0;
    mu_muid_nRPCLayer2PhiHits = 0;
    mu_muid_nRPCLayer3PhiHits = 0;
    mu_muid_nTGCLayer1EtaHits = 0;
    mu_muid_nTGCLayer2EtaHits = 0;
    mu_muid_nTGCLayer3EtaHits = 0;
    mu_muid_nTGCLayer4EtaHits = 0;
    mu_muid_nTGCLayer1PhiHits = 0;
    mu_muid_nTGCLayer2PhiHits = 0;
    mu_muid_nTGCLayer3PhiHits = 0;
    mu_muid_nTGCLayer4PhiHits = 0;
    mu_muid_barrelSectors = 0;
    mu_muid_endcapSectors = 0;
    mu_muid_trackd0 = 0;
    mu_muid_trackz0 = 0;
    mu_muid_trackphi = 0;
    mu_muid_tracktheta = 0;
    mu_muid_trackqoverp = 0;
    mu_muid_trackcov_d0 = 0;
    mu_muid_trackcov_z0 = 0;
    mu_muid_trackcov_phi = 0;
    mu_muid_trackcov_theta = 0;
    mu_muid_trackcov_qoverp = 0;
    mu_muid_trackcov_d0_z0 = 0;
    mu_muid_trackcov_d0_phi = 0;
    mu_muid_trackcov_d0_theta = 0;
    mu_muid_trackcov_d0_qoverp = 0;
    mu_muid_trackcov_z0_phi = 0;
    mu_muid_trackcov_z0_theta = 0;
    mu_muid_trackcov_z0_qoverp = 0;
    mu_muid_trackcov_phi_theta = 0;
    mu_muid_trackcov_phi_qoverp = 0;
    mu_muid_trackcov_theta_qoverp = 0;
    mu_muid_trackfitchi2 = 0;
    mu_muid_trackfitndof = 0;
    mu_muid_hastrack = 0;
    mu_muid_EF_dr = 0;
    mu_muid_EF_cb_eta = 0;
    mu_muid_EF_cb_phi = 0;
    mu_muid_EF_cb_pt = 0;
    mu_muid_EF_ms_eta = 0;
    mu_muid_EF_ms_phi = 0;
    mu_muid_EF_ms_pt = 0;
    mu_muid_EF_me_eta = 0;
    mu_muid_EF_me_phi = 0;
    mu_muid_EF_me_pt = 0;
    mu_muid_EF_matched = 0;
    mu_muid_L2CB_dr = 0;
    mu_muid_L2CB_pt = 0;
    mu_muid_L2CB_eta = 0;
    mu_muid_L2CB_phi = 0;
    mu_muid_L2CB_id_pt = 0;
    mu_muid_L2CB_ms_pt = 0;
    mu_muid_L2CB_nPixHits = 0;
    mu_muid_L2CB_nSCTHits = 0;
    mu_muid_L2CB_nTRTHits = 0;
    mu_muid_L2CB_nTRTHighTHits = 0;
    mu_muid_L2CB_matched = 0;
    mu_muid_L1_dr = 0;
    mu_muid_L1_pt = 0;
    mu_muid_L1_eta = 0;
    mu_muid_L1_phi = 0;
    mu_muid_L1_thrNumber = 0;
    mu_muid_L1_RoINumber = 0;
    mu_muid_L1_sectorAddress = 0;
    mu_muid_L1_firstCandidate = 0;
    mu_muid_L1_moreCandInRoI = 0;
    mu_muid_L1_moreCandInSector = 0;
    mu_muid_L1_source = 0;
    mu_muid_L1_hemisphere = 0;
    mu_muid_L1_matched = 0;
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
    trig_L1_jet_eta = 0;
    trig_L1_jet_phi = 0;
    trig_L1_jet_thrNames = 0;
    trig_L1_jet_thrValues = 0;
    trig_L1_jet_thrPattern = 0;
    trig_L1_jet_et4x4 = 0;
    trig_L1_jet_et6x6 = 0;
    trig_L1_jet_et8x8 = 0;
    trig_L1_jet_RoIWord = 0;
    trig_L1_esum_thrNames = 0;
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
    trig_L2_jet_ehad0 = 0;
    trig_L2_jet_eem0 = 0;
    vx_x = 0;
    vx_y = 0;
    vx_z = 0;
    vx_cov_x = 0;
    vx_cov_y = 0;
    vx_cov_z = 0;
    vx_chi2 = 0;
    vx_ndof = 0;
    vx_px = 0;
    vx_py = 0;
    vx_pz = 0;
    vx_E = 0;
    vx_m = 0;
    vx_nTracks = 0;
    vx_sumPt = 0;
    vx_type = 0;
    vx_trk_n = 0;
    vx_trk_chi2 = 0;
    vx_trk_d0 = 0;
    vx_trk_z0 = 0;
    vx_trk_unbiased_d0 = 0;
    vx_trk_unbiased_z0 = 0;
    vx_trk_err_unbiased_d0 = 0;
    vx_trk_err_unbiased_z0 = 0;
    vx_trk_phi = 0;
    vx_trk_theta = 0;
    vx_trk_weight = 0;
    vx_trk_index = 0;
    el_E = 0;
    el_Et = 0;
    el_pt = 0;
    el_m = 0;
    el_eta = 0;
    el_phi = 0;
    el_px = 0;
    el_py = 0;
    el_pz = 0;
    el_charge = 0;
    el_author = 0;
    el_isEM = 0;
    el_OQ = 0;
    el_convFlag = 0;
    el_isConv = 0;
    el_nConv = 0;
    el_nSingleTrackConv = 0;
    el_nDoubleTrackConv = 0;
    el_loose = 0;
    el_medium = 0;
    el_mediumIso = 0;
    el_tight = 0;
    el_tightIso = 0;
    el_goodOQ = 0;
    el_Ethad = 0;
    el_Ethad1 = 0;
    el_f1 = 0;
    el_f1core = 0;
    el_Emins1 = 0;
    el_fside = 0;
    el_Emax2 = 0;
    el_ws3 = 0;
    el_wstot = 0;
    el_emaxs1 = 0;
    el_deltaEs = 0;
    el_E233 = 0;
    el_E237 = 0;
    el_E277 = 0;
    el_weta2 = 0;
    el_f3 = 0;
    el_f3core = 0;
    el_rphiallcalo = 0;
    el_Etcone45 = 0;
    el_Etcone20 = 0;
    el_Etcone30 = 0;
    el_Etcone40 = 0;
    el_ptcone30 = 0;
    el_convanglematch = 0;
    el_convtrackmatch = 0;
    el_pos7 = 0;
    el_etacorrmag = 0;
    el_deltaeta1 = 0;
    el_deltaeta2 = 0;
    el_deltaphi2 = 0;
    el_deltaphiRescaled = 0;
    el_deltaPhiRot = 0;
    el_expectHitInBLayer = 0;
    el_reta = 0;
    el_rphi = 0;
    el_EtringnoisedR03sig2 = 0;
    el_EtringnoisedR03sig3 = 0;
    el_EtringnoisedR03sig4 = 0;
    el_isolationlikelihoodjets = 0;
    el_isolationlikelihoodhqelectrons = 0;
    el_electronweight = 0;
    el_electronbgweight = 0;
    el_softeweight = 0;
    el_softebgweight = 0;
    el_neuralnet = 0;
    el_Hmatrix = 0;
    el_Hmatrix5 = 0;
    el_adaboost = 0;
    el_softeneuralnet = 0;
    el_zvertex = 0;
    el_errz = 0;
    el_etap = 0;
    el_depth = 0;
    el_refittedTrack_n = 0;
    el_refittedTrack_author = 0;
    el_refittedTrack_chi2 = 0;
    el_refittedTrack_qoverp = 0;
    el_refittedTrack_d0 = 0;
    el_refittedTrack_z0 = 0;
    el_refittedTrack_theta = 0;
    el_refittedTrack_phi = 0;
    el_refittedTrack_LMqoverp = 0;
    el_refittedTrack_hasBrem = 0;
    el_refittedTrack_bremRadius = 0;
    el_refittedTrack_bremZ = 0;
    el_refittedTrack_bremRadiusErr = 0;
    el_refittedTrack_bremZErr = 0;
    el_Es0 = 0;
    el_etas0 = 0;
    el_phis0 = 0;
    el_Es1 = 0;
    el_etas1 = 0;
    el_phis1 = 0;
    el_Es2 = 0;
    el_etas2 = 0;
    el_phis2 = 0;
    el_Es3 = 0;
    el_etas3 = 0;
    el_phis3 = 0;
    el_E_PreSamplerB = 0;
    el_E_EMB1 = 0;
    el_E_EMB2 = 0;
    el_E_EMB3 = 0;
    el_E_PreSamplerE = 0;
    el_E_EME1 = 0;
    el_E_EME2 = 0;
    el_E_EME3 = 0;
    el_E_HEC0 = 0;
    el_E_HEC1 = 0;
    el_E_HEC2 = 0;
    el_E_HEC3 = 0;
    el_E_TileBar0 = 0;
    el_E_TileBar1 = 0;
    el_E_TileBar2 = 0;
    el_E_TileGap1 = 0;
    el_E_TileGap2 = 0;
    el_E_TileGap3 = 0;
    el_E_TileExt0 = 0;
    el_E_TileExt1 = 0;
    el_E_TileExt2 = 0;
    el_E_FCAL0 = 0;
    el_E_FCAL1 = 0;
    el_E_FCAL2 = 0;
    el_cl_E = 0;
    el_cl_pt = 0;
    el_cl_eta = 0;
    el_cl_phi = 0;
    el_firstEdens = 0;
    el_cellmaxfrac = 0;
    el_longitudinal = 0;
    el_secondlambda = 0;
    el_lateral = 0;
    el_secondR = 0;
    el_centerlambda = 0;
    el_rawcl_Es0 = 0;
    el_rawcl_etas0 = 0;
    el_rawcl_phis0 = 0;
    el_rawcl_Es1 = 0;
    el_rawcl_etas1 = 0;
    el_rawcl_phis1 = 0;
    el_rawcl_Es2 = 0;
    el_rawcl_etas2 = 0;
    el_rawcl_phis2 = 0;
    el_rawcl_Es3 = 0;
    el_rawcl_etas3 = 0;
    el_rawcl_phis3 = 0;
    el_rawcl_E = 0;
    el_rawcl_pt = 0;
    el_rawcl_eta = 0;
    el_rawcl_phi = 0;
    el_refittedtrackcovd0 = 0;
    el_refittedtrackcovz0 = 0;
    el_refittedtrackcovphi = 0;
    el_refittedtrackcovtheta = 0;
    el_refittedtrackcovqoverp = 0;
    el_refittedtrackcovd0z0 = 0;
    el_refittedtrackcovz0phi = 0;
    el_refittedtrackcovz0theta = 0;
    el_refittedtrackcovz0qoverp = 0;
    el_refittedtrackcovd0phi = 0;
    el_refittedtrackcovd0theta = 0;
    el_refittedtrackcovd0qoverp = 0;
    el_refittedtrackcovphitheta = 0;
    el_refittedtrackcovphiqoverp = 0;
    el_refittedtrackcovthetaqoverp = 0;
    el_trackd0 = 0;
    el_trackz0 = 0;
    el_trackphi = 0;
    el_tracktheta = 0;
    el_trackqoverp = 0;
    el_trackpt = 0;
    el_tracketa = 0;
    el_trackcov_d0 = 0;
    el_trackcov_z0 = 0;
    el_trackcov_phi = 0;
    el_trackcov_theta = 0;
    el_trackcov_qoverp = 0;
    el_trackcov_d0_z0 = 0;
    el_trackcov_d0_phi = 0;
    el_trackcov_d0_theta = 0;
    el_trackcov_d0_qoverp = 0;
    el_trackcov_z0_phi = 0;
    el_trackcov_z0_theta = 0;
    el_trackcov_z0_qoverp = 0;
    el_trackcov_phi_theta = 0;
    el_trackcov_phi_qoverp = 0;
    el_trackcov_theta_qoverp = 0;
    el_trackfitchi2 = 0;
    el_trackfitndof = 0;
    el_nBLHits = 0;
    el_nPixHits = 0;
    el_nSCTHits = 0;
    el_nTRTHits = 0;
    el_nPixHoles = 0;
    el_nSCTHoles = 0;
    el_nBLSharedHits = 0;
    el_nPixSharedHits = 0;
    el_nSCTSharedHits = 0;
    el_nTRTHighTHits = 0;
    el_nTRTOutliers = 0;
    el_nTRTHighTOutliers = 0;
    el_nSiHits = 0;
    el_TRTHighTHitsRatio = 0;
    el_pixeldEdx = 0;
    el_eProbabilityComb = 0;
    el_eProbabilityHT = 0;
    el_eProbabilityToT = 0;
    el_eProbabilityBrem = 0;
    el_vertx = 0;
    el_verty = 0;
    el_vertz = 0;
    el_hastrack = 0;
    el_deltaEmax2 = 0;
    el_calibHitsShowerDepth = 0;
    el_trackd0beam = 0;
    el_tracksigd0beam = 0;
    el_trackd0pv = 0;
    el_tracksigd0pv = 0;
    el_trackz0pv = 0;
    el_tracksigz0pv = 0;
    el_trackd0pvunbiased = 0;
    el_tracksigd0pvunbiased = 0;
    el_trackz0pvunbiased = 0;
    el_tracksigz0pvunbiased = 0;
    el_isIso = 0;
    el_mvaptcone20 = 0;
    el_mvaptcone30 = 0;
    el_mvaptcone40 = 0;
    ph_E = 0;
    ph_Et = 0;
    ph_pt = 0;
    ph_m = 0;
    ph_eta = 0;
    ph_phi = 0;
    ph_px = 0;
    ph_py = 0;
    ph_pz = 0;
    ph_author = 0;
    ph_isRecovered = 0;
    ph_isEM = 0;
    ph_OQ = 0;
    ph_loose = 0;
    ph_tight = 0;
    ph_tightIso = 0;
    ph_goodOQ = 0;
    ph_Ethad = 0;
    ph_Ethad1 = 0;
    ph_E033 = 0;
    ph_f1 = 0;
    ph_f1core = 0;
    ph_Emins1 = 0;
    ph_fside = 0;
    ph_Emax2 = 0;
    ph_ws3 = 0;
    ph_wstot = 0;
    ph_E132 = 0;
    ph_E1152 = 0;
    ph_emaxs1 = 0;
    ph_deltaEs = 0;
    ph_E233 = 0;
    ph_E237 = 0;
    ph_E277 = 0;
    ph_weta2 = 0;
    ph_f3 = 0;
    ph_f3core = 0;
    ph_rphiallcalo = 0;
    ph_Etcone45 = 0;
    ph_Etcone20 = 0;
    ph_Etcone30 = 0;
    ph_Etcone40 = 0;
    ph_ptcone30 = 0;
    ph_convanglematch = 0;
    ph_convtrackmatch = 0;
    ph_reta = 0;
    ph_rphi = 0;
    ph_EtringnoisedR03sig2 = 0;
    ph_EtringnoisedR03sig3 = 0;
    ph_EtringnoisedR03sig4 = 0;
    ph_isolationlikelihoodjets = 0;
    ph_isolationlikelihoodhqelectrons = 0;
    ph_loglikelihood = 0;
    ph_photonweight = 0;
    ph_photonbgweight = 0;
    ph_neuralnet = 0;
    ph_Hmatrix = 0;
    ph_Hmatrix5 = 0;
    ph_adaboost = 0;
    ph_zvertex = 0;
    ph_errz = 0;
    ph_etap = 0;
    ph_depth = 0;
    ph_cl_E = 0;
    ph_cl_pt = 0;
    ph_cl_eta = 0;
    ph_cl_phi = 0;
    ph_Es0 = 0;
    ph_etas0 = 0;
    ph_phis0 = 0;
    ph_Es1 = 0;
    ph_etas1 = 0;
    ph_phis1 = 0;
    ph_Es2 = 0;
    ph_etas2 = 0;
    ph_phis2 = 0;
    ph_Es3 = 0;
    ph_etas3 = 0;
    ph_phis3 = 0;
    ph_rawcl_Es0 = 0;
    ph_rawcl_etas0 = 0;
    ph_rawcl_phis0 = 0;
    ph_rawcl_Es1 = 0;
    ph_rawcl_etas1 = 0;
    ph_rawcl_phis1 = 0;
    ph_rawcl_Es2 = 0;
    ph_rawcl_etas2 = 0;
    ph_rawcl_phis2 = 0;
    ph_rawcl_Es3 = 0;
    ph_rawcl_etas3 = 0;
    ph_rawcl_phis3 = 0;
    ph_rawcl_E = 0;
    ph_rawcl_pt = 0;
    ph_rawcl_eta = 0;
    ph_rawcl_phi = 0;
    ph_deltaEmax2 = 0;
    ph_calibHitsShowerDepth = 0;
    ph_isIso = 0;
    ph_mvaptcone20 = 0;
    ph_mvaptcone30 = 0;
    ph_mvaptcone40 = 0;
    ph_topoEtcone20 = 0;
    ph_topoEtcone40 = 0;
    ph_topoEtcone60 = 0;
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
    fChain->SetBranchAddress("pixClus_n", &pixClus_n, &b_pixClus_n);
    fChain->SetBranchAddress("pixClus_id", &pixClus_id, &b_pixClus_id);
    fChain->SetBranchAddress("pixClus_bec", &pixClus_bec, &b_pixClus_bec);
    fChain->SetBranchAddress("pixClus_layer", &pixClus_layer, &b_pixClus_layer);
    fChain->SetBranchAddress("pixClus_detElementId", &pixClus_detElementId, &b_pixClus_detElementId);
    fChain->SetBranchAddress("pixClus_phi_module", &pixClus_phi_module, &b_pixClus_phi_module);
    fChain->SetBranchAddress("pixClus_eta_module", &pixClus_eta_module, &b_pixClus_eta_module);
    fChain->SetBranchAddress("pixClus_col", &pixClus_col, &b_pixClus_col);
    fChain->SetBranchAddress("pixClus_row", &pixClus_row, &b_pixClus_row);
    fChain->SetBranchAddress("pixClus_charge", &pixClus_charge, &b_pixClus_charge);
    fChain->SetBranchAddress("pixClus_LVL1A", &pixClus_LVL1A, &b_pixClus_LVL1A);
    fChain->SetBranchAddress("pixClus_sizePhi", &pixClus_sizePhi, &b_pixClus_sizePhi);
    fChain->SetBranchAddress("pixClus_sizeZ", &pixClus_sizeZ, &b_pixClus_sizeZ);
    fChain->SetBranchAddress("pixClus_size", &pixClus_size, &b_pixClus_size);
    fChain->SetBranchAddress("pixClus_locX", &pixClus_locX, &b_pixClus_locX);
    fChain->SetBranchAddress("pixClus_locY", &pixClus_locY, &b_pixClus_locY);
    fChain->SetBranchAddress("pixClus_x", &pixClus_x, &b_pixClus_x);
    fChain->SetBranchAddress("pixClus_y", &pixClus_y, &b_pixClus_y);
    fChain->SetBranchAddress("pixClus_z", &pixClus_z, &b_pixClus_z);
    fChain->SetBranchAddress("pixClus_isFake", &pixClus_isFake, &b_pixClus_isFake);
    fChain->SetBranchAddress("pixClus_isGanged", &pixClus_isGanged, &b_pixClus_isGanged);
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
    fChain->SetBranchAddress("TotalEt_n", &TotalEt_n, &b_TotalEt_n);
    fChain->SetBranchAddress("TotalEt_tower_eta", &TotalEt_tower_eta, &b_TotalEt_tower_eta);
    fChain->SetBranchAddress("TotalEt_tower_phi", &TotalEt_tower_phi, &b_TotalEt_tower_phi);
    fChain->SetBranchAddress("TotalEt_tower_area", &TotalEt_tower_area, &b_TotalEt_tower_area);
    fChain->SetBranchAddress("TotalEt_tower_sampling", &TotalEt_tower_sampling, &b_TotalEt_tower_sampling);
    fChain->SetBranchAddress("TotalEt_tower_sampling_calib", &TotalEt_tower_sampling_calib, &b_TotalEt_tower_sampling_calib);
    fChain->SetBranchAddress("TotalEt_layer_eta", &TotalEt_layer_eta, &b_TotalEt_layer_eta);
    fChain->SetBranchAddress("TotalEt_layer_phi", &TotalEt_layer_phi, &b_TotalEt_layer_phi);
    fChain->SetBranchAddress("TotalEt_layer_area", &TotalEt_layer_area, &b_TotalEt_layer_area);
    fChain->SetBranchAddress("TotalEt_layer_sampling", &TotalEt_layer_sampling, &b_TotalEt_layer_sampling);
    fChain->SetBranchAddress("TotalEt_layer_sampling_calib", &TotalEt_layer_sampling_calib, &b_TotalEt_layer_sampling_calib);
    fChain->SetBranchAddress("trk_n", &trk_n, &b_trk_n);
    fChain->SetBranchAddress("trk_pt", &trk_pt, &b_trk_pt);
    fChain->SetBranchAddress("trk_eta", &trk_eta, &b_trk_eta);
    fChain->SetBranchAddress("trk_d0_wrtPV", &trk_d0_wrtPV, &b_trk_d0_wrtPV);
    fChain->SetBranchAddress("trk_err_d0_wrtPV", &trk_err_d0_wrtPV, &b_trk_err_d0_wrtPV);
    fChain->SetBranchAddress("trk_z0_wrtPV", &trk_z0_wrtPV, &b_trk_z0_wrtPV);
    fChain->SetBranchAddress("trk_err_z0_wrtPV", &trk_err_z0_wrtPV, &b_trk_err_z0_wrtPV);
    fChain->SetBranchAddress("trk_phi_wrtPV", &trk_phi_wrtPV, &b_trk_phi_wrtPV);
    fChain->SetBranchAddress("trk_theta", &trk_theta, &b_trk_theta);
    fChain->SetBranchAddress("trk_err_theta_wrtPV", &trk_err_theta_wrtPV, &b_trk_err_theta_wrtPV);
    fChain->SetBranchAddress("trk_qoverp", &trk_qoverp, &b_trk_qoverp);
    fChain->SetBranchAddress("trk_cov_z0_theta_wrtPV", &trk_cov_z0_theta_wrtPV, &b_trk_cov_z0_theta_wrtPV);
    fChain->SetBranchAddress("trk_cov_d0_wrtPV", &trk_cov_d0_wrtPV, &b_trk_cov_d0_wrtPV);
    fChain->SetBranchAddress("trk_cov_z0_wrtPV", &trk_cov_z0_wrtPV, &b_trk_cov_z0_wrtPV);
    fChain->SetBranchAddress("trk_cov_phi_wrtPV", &trk_cov_phi_wrtPV, &b_trk_cov_phi_wrtPV);
    fChain->SetBranchAddress("trk_cov_theta_wrtPV", &trk_cov_theta_wrtPV, &b_trk_cov_theta_wrtPV);
    fChain->SetBranchAddress("trk_cov_qoverp_wrtPV", &trk_cov_qoverp_wrtPV, &b_trk_cov_qoverp_wrtPV);
    fChain->SetBranchAddress("trk_chi2", &trk_chi2, &b_trk_chi2);
    fChain->SetBranchAddress("trk_ndof", &trk_ndof, &b_trk_ndof);
    fChain->SetBranchAddress("trk_nBLHits", &trk_nBLHits, &b_trk_nBLHits);
    fChain->SetBranchAddress("trk_nPixHits", &trk_nPixHits, &b_trk_nPixHits);
    fChain->SetBranchAddress("trk_nSCTHits", &trk_nSCTHits, &b_trk_nSCTHits);
    fChain->SetBranchAddress("trk_nTRTHits", &trk_nTRTHits, &b_trk_nTRTHits);
    fChain->SetBranchAddress("trk_nPixHoles", &trk_nPixHoles, &b_trk_nPixHoles);
    fChain->SetBranchAddress("trk_nSCTHoles", &trk_nSCTHoles, &b_trk_nSCTHoles);
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
    fChain->SetBranchAddress("trk_pixeldEdx", &trk_pixeldEdx, &b_trk_pixeldEdx);
    fChain->SetBranchAddress("trk_fitter", &trk_fitter, &b_trk_fitter);
    fChain->SetBranchAddress("trk_patternReco1", &trk_patternReco1, &b_trk_patternReco1);
    fChain->SetBranchAddress("trk_patternReco2", &trk_patternReco2, &b_trk_patternReco2);
    fChain->SetBranchAddress("trk_seedFinder", &trk_seedFinder, &b_trk_seedFinder);
    fChain->SetBranchAddress("trk_expectBLayerHit", &trk_expectBLayerHit, &b_trk_expectBLayerHit);
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
    fChain->SetBranchAddress("pTrklets_n", &pTrklets_n, &b_pTrklets_n);
    fChain->SetBranchAddress("pTrklets_nBPixClus", &pTrklets_nBPixClus, &b_pTrklets_nBPixClus);
    fChain->SetBranchAddress("pTrklets_n1PixClus", &pTrklets_n1PixClus, &b_pTrklets_n1PixClus);
    fChain->SetBranchAddress("pTrklets_n2PixClus", &pTrklets_n2PixClus, &b_pTrklets_n2PixClus);
    fChain->SetBranchAddress("pTrklets_layerSum", &pTrklets_layerSum, &b_pTrklets_layerSum);
    fChain->SetBranchAddress("pTrklets_eta", &pTrklets_eta, &b_pTrklets_eta);
    fChain->SetBranchAddress("pTrklets_phi", &pTrklets_phi, &b_pTrklets_phi);
    fChain->SetBranchAddress("pTrklets_pt", &pTrklets_pt, &b_pTrklets_pt);
    fChain->SetBranchAddress("pTrklets_deta", &pTrklets_deta, &b_pTrklets_deta);
    fChain->SetBranchAddress("pTrklets_dphi", &pTrklets_dphi, &b_pTrklets_dphi);
    fChain->SetBranchAddress("pTrklets_etaS", &pTrklets_etaS, &b_pTrklets_etaS);
    fChain->SetBranchAddress("pTrklets_phiS", &pTrklets_phiS, &b_pTrklets_phiS);
    fChain->SetBranchAddress("pTrklets_energy0", &pTrklets_energy0, &b_pTrklets_energy0);
    fChain->SetBranchAddress("pTrklets_energy1", &pTrklets_energy1, &b_pTrklets_energy1);
    fChain->SetBranchAddress("pTrklets_cSize0", &pTrklets_cSize0, &b_pTrklets_cSize0);
    fChain->SetBranchAddress("pTrklets_cSize1", &pTrklets_cSize1, &b_pTrklets_cSize1);
    fChain->SetBranchAddress("pTrklets_cRowSize0", &pTrklets_cRowSize0, &b_pTrklets_cRowSize0);
    fChain->SetBranchAddress("pTrklets_cRowSize1", &pTrklets_cRowSize1, &b_pTrklets_cRowSize1);
    fChain->SetBranchAddress("pTrklets_cColSize0", &pTrklets_cColSize0, &b_pTrklets_cColSize0);
    fChain->SetBranchAddress("pTrklets_cColSize1", &pTrklets_cColSize1, &b_pTrklets_cColSize1);
    fChain->SetBranchAddress("pTrklets_clusIds", &pTrklets_clusIds, &b_pTrklets_clusIds);
    fChain->SetBranchAddress("trkPix_n", &trkPix_n, &b_trkPix_n);
    fChain->SetBranchAddress("trkPix_pt", &trkPix_pt, &b_trkPix_pt);
    fChain->SetBranchAddress("trkPix_eta", &trkPix_eta, &b_trkPix_eta);
    fChain->SetBranchAddress("trkPix_d0_wrtPV", &trkPix_d0_wrtPV, &b_trkPix_d0_wrtPV);
    fChain->SetBranchAddress("trkPix_z0_wrtPV", &trkPix_z0_wrtPV, &b_trkPix_z0_wrtPV);
    fChain->SetBranchAddress("trkPix_phi_wrtPV", &trkPix_phi_wrtPV, &b_trkPix_phi_wrtPV);
    fChain->SetBranchAddress("trkPix_theta_wrtPV", &trkPix_theta_wrtPV, &b_trkPix_theta_wrtPV);
    fChain->SetBranchAddress("trkPix_qoverp_wrtPV", &trkPix_qoverp_wrtPV, &b_trkPix_qoverp_wrtPV);
    fChain->SetBranchAddress("trkPix_cov_d0_wrtPV", &trkPix_cov_d0_wrtPV, &b_trkPix_cov_d0_wrtPV);
    fChain->SetBranchAddress("trkPix_cov_z0_wrtPV", &trkPix_cov_z0_wrtPV, &b_trkPix_cov_z0_wrtPV);
    fChain->SetBranchAddress("trkPix_cov_phi_wrtPV", &trkPix_cov_phi_wrtPV, &b_trkPix_cov_phi_wrtPV);
    fChain->SetBranchAddress("trkPix_cov_theta_wrtPV", &trkPix_cov_theta_wrtPV, &b_trkPix_cov_theta_wrtPV);
    fChain->SetBranchAddress("trkPix_cov_qoverp_wrtPV", &trkPix_cov_qoverp_wrtPV, &b_trkPix_cov_qoverp_wrtPV);
    fChain->SetBranchAddress("trkPix_chi2", &trkPix_chi2, &b_trkPix_chi2);
    fChain->SetBranchAddress("trkPix_ndof", &trkPix_ndof, &b_trkPix_ndof);
    fChain->SetBranchAddress("trkPix_nBLHits", &trkPix_nBLHits, &b_trkPix_nBLHits);
    fChain->SetBranchAddress("trkPix_nPixHits", &trkPix_nPixHits, &b_trkPix_nPixHits);
    fChain->SetBranchAddress("trkPix_nSCTHits", &trkPix_nSCTHits, &b_trkPix_nSCTHits);
    fChain->SetBranchAddress("trkPix_nTRTHits", &trkPix_nTRTHits, &b_trkPix_nTRTHits);
    fChain->SetBranchAddress("trkPix_nPixHoles", &trkPix_nPixHoles, &b_trkPix_nPixHoles);
    fChain->SetBranchAddress("trkPix_nSCTHoles", &trkPix_nSCTHoles, &b_trkPix_nSCTHoles);
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
    fChain->SetBranchAddress("trkPix_pixeldEdx", &trkPix_pixeldEdx, &b_trkPix_pixeldEdx);
    fChain->SetBranchAddress("trkPix_fitter", &trkPix_fitter, &b_trkPix_fitter);
    fChain->SetBranchAddress("trkPix_patternReco1", &trkPix_patternReco1, &b_trkPix_patternReco1);
    fChain->SetBranchAddress("trkPix_patternReco2", &trkPix_patternReco2, &b_trkPix_patternReco2);
    fChain->SetBranchAddress("trkPix_seedFinder", &trkPix_seedFinder, &b_trkPix_seedFinder);
    fChain->SetBranchAddress("trkPix_blayerPrediction_expectHit", &trkPix_blayerPrediction_expectHit, &b_trkPix_blayerPrediction_expectHit);
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
    fChain->SetBranchAddress("antikt4Tow_tower_CaloBkgrEt", &antikt4Tow_tower_CaloBkgrEt, &b_antikt4Tow_tower_CaloBkgrEt);
    fChain->SetBranchAddress("antikt4Tow_tower_CaloBkgrRMS", &antikt4Tow_tower_CaloBkgrRMS, &b_antikt4Tow_tower_CaloBkgrRMS);
    fChain->SetBranchAddress("antikt4Tow_tower_CaloBkgrCounts", &antikt4Tow_tower_CaloBkgrCounts, &b_antikt4Tow_tower_CaloBkgrCounts);
    fChain->SetBranchAddress("antikt4Tow_tower_CaloBkgrEta", &antikt4Tow_tower_CaloBkgrEta, &b_antikt4Tow_tower_CaloBkgrEta);
    fChain->SetBranchAddress("antikt4Tow_layer_CaloBkgrEt", &antikt4Tow_layer_CaloBkgrEt, &b_antikt4Tow_layer_CaloBkgrEt);
    fChain->SetBranchAddress("antikt4Tow_layer_CaloBkgrRMS", &antikt4Tow_layer_CaloBkgrRMS, &b_antikt4Tow_layer_CaloBkgrRMS);
    fChain->SetBranchAddress("antikt4Tow_layer_CaloBkgrCounts", &antikt4Tow_layer_CaloBkgrCounts, &b_antikt4Tow_layer_CaloBkgrCounts);
    fChain->SetBranchAddress("antikt4Tow_layer_CaloBkgrEta", &antikt4Tow_layer_CaloBkgrEta, &b_antikt4Tow_layer_CaloBkgrEta);
    fChain->SetBranchAddress("antikt4FlowTow_tower_CaloBkgrEt", &antikt4FlowTow_tower_CaloBkgrEt, &b_antikt4FlowTow_tower_CaloBkgrEt);
    fChain->SetBranchAddress("antikt4FlowTow_tower_CaloBkgrRMS", &antikt4FlowTow_tower_CaloBkgrRMS, &b_antikt4FlowTow_tower_CaloBkgrRMS);
    fChain->SetBranchAddress("antikt4FlowTow_tower_CaloBkgrCounts", &antikt4FlowTow_tower_CaloBkgrCounts, &b_antikt4FlowTow_tower_CaloBkgrCounts);
    fChain->SetBranchAddress("antikt4FlowTow_tower_CaloBkgrEta", &antikt4FlowTow_tower_CaloBkgrEta, &b_antikt4FlowTow_tower_CaloBkgrEta);
    fChain->SetBranchAddress("antikt4FlowTow_layer_CaloBkgrEt", &antikt4FlowTow_layer_CaloBkgrEt, &b_antikt4FlowTow_layer_CaloBkgrEt);
    fChain->SetBranchAddress("antikt4FlowTow_layer_CaloBkgrRMS", &antikt4FlowTow_layer_CaloBkgrRMS, &b_antikt4FlowTow_layer_CaloBkgrRMS);
    fChain->SetBranchAddress("antikt4FlowTow_layer_CaloBkgrCounts", &antikt4FlowTow_layer_CaloBkgrCounts, &b_antikt4FlowTow_layer_CaloBkgrCounts);
    fChain->SetBranchAddress("antikt4FlowTow_layer_CaloBkgrEta", &antikt4FlowTow_layer_CaloBkgrEta, &b_antikt4FlowTow_layer_CaloBkgrEta);
    fChain->SetBranchAddress("antikt4EMTow_tower_CaloBkgrEt", &antikt4EMTow_tower_CaloBkgrEt, &b_antikt4EMTow_tower_CaloBkgrEt);
    fChain->SetBranchAddress("antikt4EMTow_tower_CaloBkgrRMS", &antikt4EMTow_tower_CaloBkgrRMS, &b_antikt4EMTow_tower_CaloBkgrRMS);
    fChain->SetBranchAddress("antikt4EMTow_tower_CaloBkgrCounts", &antikt4EMTow_tower_CaloBkgrCounts, &b_antikt4EMTow_tower_CaloBkgrCounts);
    fChain->SetBranchAddress("antikt4EMTow_tower_CaloBkgrEta", &antikt4EMTow_tower_CaloBkgrEta, &b_antikt4EMTow_tower_CaloBkgrEta);
    fChain->SetBranchAddress("antikt4EMTow_layer_CaloBkgrEt", &antikt4EMTow_layer_CaloBkgrEt, &b_antikt4EMTow_layer_CaloBkgrEt);
    fChain->SetBranchAddress("antikt4EMTow_layer_CaloBkgrRMS", &antikt4EMTow_layer_CaloBkgrRMS, &b_antikt4EMTow_layer_CaloBkgrRMS);
    fChain->SetBranchAddress("antikt4EMTow_layer_CaloBkgrCounts", &antikt4EMTow_layer_CaloBkgrCounts, &b_antikt4EMTow_layer_CaloBkgrCounts);
    fChain->SetBranchAddress("antikt4EMTow_layer_CaloBkgrEta", &antikt4EMTow_layer_CaloBkgrEta, &b_antikt4EMTow_layer_CaloBkgrEta);
    fChain->SetBranchAddress("AvgTower_tower_CaloBkgrEt", &AvgTower_tower_CaloBkgrEt, &b_AvgTower_tower_CaloBkgrEt);
    fChain->SetBranchAddress("AvgTower_tower_CaloBkgrRMS", &AvgTower_tower_CaloBkgrRMS, &b_AvgTower_tower_CaloBkgrRMS);
    fChain->SetBranchAddress("AvgTower_tower_CaloBkgrCounts", &AvgTower_tower_CaloBkgrCounts, &b_AvgTower_tower_CaloBkgrCounts);
    fChain->SetBranchAddress("AvgTower_tower_CaloBkgrEta", &AvgTower_tower_CaloBkgrEta, &b_AvgTower_tower_CaloBkgrEta);
    fChain->SetBranchAddress("AvgTower_layer_CaloBkgrEt", &AvgTower_layer_CaloBkgrEt, &b_AvgTower_layer_CaloBkgrEt);
    fChain->SetBranchAddress("AvgTower_layer_CaloBkgrRMS", &AvgTower_layer_CaloBkgrRMS, &b_AvgTower_layer_CaloBkgrRMS);
    fChain->SetBranchAddress("AvgTower_layer_CaloBkgrCounts", &AvgTower_layer_CaloBkgrCounts, &b_AvgTower_layer_CaloBkgrCounts);
    fChain->SetBranchAddress("AvgTower_layer_CaloBkgrEta", &AvgTower_layer_CaloBkgrEta, &b_AvgTower_layer_CaloBkgrEta);
    fChain->SetBranchAddress("AvgTower3Sigma_tower_CaloBkgrEt", &AvgTower3Sigma_tower_CaloBkgrEt, &b_AvgTower3Sigma_tower_CaloBkgrEt);
    fChain->SetBranchAddress("AvgTower3Sigma_tower_CaloBkgrRMS", &AvgTower3Sigma_tower_CaloBkgrRMS, &b_AvgTower3Sigma_tower_CaloBkgrRMS);
    fChain->SetBranchAddress("AvgTower3Sigma_tower_CaloBkgrCounts", &AvgTower3Sigma_tower_CaloBkgrCounts, &b_AvgTower3Sigma_tower_CaloBkgrCounts);
    fChain->SetBranchAddress("AvgTower3Sigma_tower_CaloBkgrEta", &AvgTower3Sigma_tower_CaloBkgrEta, &b_AvgTower3Sigma_tower_CaloBkgrEta);
    fChain->SetBranchAddress("AvgTower4Sigma_tower_CaloBkgrEt", &AvgTower4Sigma_tower_CaloBkgrEt, &b_AvgTower4Sigma_tower_CaloBkgrEt);
    fChain->SetBranchAddress("AvgTower4Sigma_tower_CaloBkgrRMS", &AvgTower4Sigma_tower_CaloBkgrRMS, &b_AvgTower4Sigma_tower_CaloBkgrRMS);
    fChain->SetBranchAddress("AvgTower4Sigma_tower_CaloBkgrCounts", &AvgTower4Sigma_tower_CaloBkgrCounts, &b_AvgTower4Sigma_tower_CaloBkgrCounts);
    fChain->SetBranchAddress("AvgTower4Sigma_tower_CaloBkgrEta", &AvgTower4Sigma_tower_CaloBkgrEta, &b_AvgTower4Sigma_tower_CaloBkgrEta);
    fChain->SetBranchAddress("AvgTowerFlow_tower_CaloBkgrEt", &AvgTowerFlow_tower_CaloBkgrEt, &b_AvgTowerFlow_tower_CaloBkgrEt);
    fChain->SetBranchAddress("AvgTowerFlow_tower_CaloBkgrRMS", &AvgTowerFlow_tower_CaloBkgrRMS, &b_AvgTowerFlow_tower_CaloBkgrRMS);
    fChain->SetBranchAddress("AvgTowerFlow_tower_CaloBkgrCounts", &AvgTowerFlow_tower_CaloBkgrCounts, &b_AvgTowerFlow_tower_CaloBkgrCounts);
    fChain->SetBranchAddress("AvgTowerFlow_tower_CaloBkgrEta", &AvgTowerFlow_tower_CaloBkgrEta, &b_AvgTowerFlow_tower_CaloBkgrEta);
    fChain->SetBranchAddress("AvgTowerFlow_layer_CaloBkgrEt", &AvgTowerFlow_layer_CaloBkgrEt, &b_AvgTowerFlow_layer_CaloBkgrEt);
    fChain->SetBranchAddress("AvgTowerFlow_layer_CaloBkgrRMS", &AvgTowerFlow_layer_CaloBkgrRMS, &b_AvgTowerFlow_layer_CaloBkgrRMS);
    fChain->SetBranchAddress("AvgTowerFlow_layer_CaloBkgrCounts", &AvgTowerFlow_layer_CaloBkgrCounts, &b_AvgTowerFlow_layer_CaloBkgrCounts);
    fChain->SetBranchAddress("AvgTowerFlow_layer_CaloBkgrEta", &AvgTowerFlow_layer_CaloBkgrEta, &b_AvgTowerFlow_layer_CaloBkgrEta);
    fChain->SetBranchAddress("antikt4TowItr_tower_CaloBkgrEt", &antikt4TowItr_tower_CaloBkgrEt, &b_antikt4TowItr_tower_CaloBkgrEt);
    fChain->SetBranchAddress("antikt4TowItr_tower_CaloBkgrRMS", &antikt4TowItr_tower_CaloBkgrRMS, &b_antikt4TowItr_tower_CaloBkgrRMS);
    fChain->SetBranchAddress("antikt4TowItr_tower_CaloBkgrCounts", &antikt4TowItr_tower_CaloBkgrCounts, &b_antikt4TowItr_tower_CaloBkgrCounts);
    fChain->SetBranchAddress("antikt4TowItr_tower_CaloBkgrEta", &antikt4TowItr_tower_CaloBkgrEta, &b_antikt4TowItr_tower_CaloBkgrEta);
    fChain->SetBranchAddress("antikt4TowItr_layer_CaloBkgrEt", &antikt4TowItr_layer_CaloBkgrEt, &b_antikt4TowItr_layer_CaloBkgrEt);
    fChain->SetBranchAddress("antikt4TowItr_layer_CaloBkgrRMS", &antikt4TowItr_layer_CaloBkgrRMS, &b_antikt4TowItr_layer_CaloBkgrRMS);
    fChain->SetBranchAddress("antikt4TowItr_layer_CaloBkgrCounts", &antikt4TowItr_layer_CaloBkgrCounts, &b_antikt4TowItr_layer_CaloBkgrCounts);
    fChain->SetBranchAddress("antikt4TowItr_layer_CaloBkgrEta", &antikt4TowItr_layer_CaloBkgrEta, &b_antikt4TowItr_layer_CaloBkgrEta);
    fChain->SetBranchAddress("antikt4TowFlowItr_tower_CaloBkgrEt", &antikt4TowFlowItr_tower_CaloBkgrEt, &b_antikt4TowFlowItr_tower_CaloBkgrEt);
    fChain->SetBranchAddress("antikt4TowFlowItr_tower_CaloBkgrRMS", &antikt4TowFlowItr_tower_CaloBkgrRMS, &b_antikt4TowFlowItr_tower_CaloBkgrRMS);
    fChain->SetBranchAddress("antikt4TowFlowItr_tower_CaloBkgrCounts", &antikt4TowFlowItr_tower_CaloBkgrCounts, &b_antikt4TowFlowItr_tower_CaloBkgrCounts);
    fChain->SetBranchAddress("antikt4TowFlowItr_tower_CaloBkgrEta", &antikt4TowFlowItr_tower_CaloBkgrEta, &b_antikt4TowFlowItr_tower_CaloBkgrEta);
    fChain->SetBranchAddress("antikt4TowFlowItr_layer_CaloBkgrEt", &antikt4TowFlowItr_layer_CaloBkgrEt, &b_antikt4TowFlowItr_layer_CaloBkgrEt);
    fChain->SetBranchAddress("antikt4TowFlowItr_layer_CaloBkgrRMS", &antikt4TowFlowItr_layer_CaloBkgrRMS, &b_antikt4TowFlowItr_layer_CaloBkgrRMS);
    fChain->SetBranchAddress("antikt4TowFlowItr_layer_CaloBkgrCounts", &antikt4TowFlowItr_layer_CaloBkgrCounts, &b_antikt4TowFlowItr_layer_CaloBkgrCounts);
    fChain->SetBranchAddress("antikt4TowFlowItr_layer_CaloBkgrEta", &antikt4TowFlowItr_layer_CaloBkgrEta, &b_antikt4TowFlowItr_layer_CaloBkgrEta);
    fChain->SetBranchAddress("antikt4HI_n", &antikt4HI_n, &b_antikt4HI_n);
    fChain->SetBranchAddress("antikt4HI_E", &antikt4HI_E, &b_antikt4HI_E);
    fChain->SetBranchAddress("antikt4HI_pt", &antikt4HI_pt, &b_antikt4HI_pt);
    fChain->SetBranchAddress("antikt4HI_m", &antikt4HI_m, &b_antikt4HI_m);
    fChain->SetBranchAddress("antikt4HI_eta", &antikt4HI_eta, &b_antikt4HI_eta);
    fChain->SetBranchAddress("antikt4HI_phi", &antikt4HI_phi, &b_antikt4HI_phi);
    fChain->SetBranchAddress("antikt4HI_MaxOverMean", &antikt4HI_MaxOverMean, &b_antikt4HI_MaxOverMean);
    fChain->SetBranchAddress("antikt4HI_MeanTowerEt", &antikt4HI_MeanTowerEt, &b_antikt4HI_MeanTowerEt);
    fChain->SetBranchAddress("antikt4HI_SubtractedEt", &antikt4HI_SubtractedEt, &b_antikt4HI_SubtractedEt);
    fChain->SetBranchAddress("antikt4HI_RMSTowerEt", &antikt4HI_RMSTowerEt, &b_antikt4HI_RMSTowerEt);
    fChain->SetBranchAddress("antikt4HI_SumJt", &antikt4HI_SumJt, &b_antikt4HI_SumJt);
    fChain->SetBranchAddress("antikt4HI_CoreEt", &antikt4HI_CoreEt, &b_antikt4HI_CoreEt);
    fChain->SetBranchAddress("antikt4HI_EdgeEt", &antikt4HI_EdgeEt, &b_antikt4HI_EdgeEt);
    fChain->SetBranchAddress("antikt4HI_CryoCorr", &antikt4HI_CryoCorr, &b_antikt4HI_CryoCorr);
    fChain->SetBranchAddress("antikt4HI_NoFlow", &antikt4HI_NoFlow, &b_antikt4HI_NoFlow);
    fChain->SetBranchAddress("antikt4HI_NumConstituents", &antikt4HI_NumConstituents, &b_antikt4HI_NumConstituents);
    fChain->SetBranchAddress("antikt4HI_UncalibEt", &antikt4HI_UncalibEt, &b_antikt4HI_UncalibEt);
    fChain->SetBranchAddress("antikt4HI_Discriminant", &antikt4HI_Discriminant, &b_antikt4HI_Discriminant);
    fChain->SetBranchAddress("antikt4HI_MeanTowerEtUnsubtr", &antikt4HI_MeanTowerEtUnsubtr, &b_antikt4HI_MeanTowerEtUnsubtr);
    fChain->SetBranchAddress("antikt4HI_n90", &antikt4HI_n90, &b_antikt4HI_n90);
    fChain->SetBranchAddress("antikt4HI_fracSamplingMax", &antikt4HI_fracSamplingMax, &b_antikt4HI_fracSamplingMax);
    fChain->SetBranchAddress("antikt4HI_SamplingMax", &antikt4HI_SamplingMax, &b_antikt4HI_SamplingMax);
    fChain->SetBranchAddress("antikt4HI_n90constituents", &antikt4HI_n90constituents, &b_antikt4HI_n90constituents);
    fChain->SetBranchAddress("antikt4HI_Timing", &antikt4HI_Timing, &b_antikt4HI_Timing);
    fChain->SetBranchAddress("antikt4HI_LArQuality", &antikt4HI_LArQuality, &b_antikt4HI_LArQuality);
    fChain->SetBranchAddress("antikt4HI_HECQuality", &antikt4HI_HECQuality, &b_antikt4HI_HECQuality);
    fChain->SetBranchAddress("antikt4HI_TileQuality", &antikt4HI_TileQuality, &b_antikt4HI_TileQuality);
    fChain->SetBranchAddress("antikt4HI_const_n", &antikt4HI_const_n, &b_antikt4HI_const_n);
    fChain->SetBranchAddress("antikt4HI_const_et", &antikt4HI_const_et, &b_antikt4HI_const_et);
    fChain->SetBranchAddress("antikt4HI_const_eta", &antikt4HI_const_eta, &b_antikt4HI_const_eta);
    fChain->SetBranchAddress("antikt4HI_const_phi", &antikt4HI_const_phi, &b_antikt4HI_const_phi);
    fChain->SetBranchAddress("antikt4HI_sampling_et", &antikt4HI_sampling_et, &b_antikt4HI_sampling_et);
    fChain->SetBranchAddress("antikt4HI_sampling_et_unsubtr", &antikt4HI_sampling_et_unsubtr, &b_antikt4HI_sampling_et_unsubtr);
    fChain->SetBranchAddress("antikt4HI_bad_cell_n", &antikt4HI_bad_cell_n, &b_antikt4HI_bad_cell_n);
    fChain->SetBranchAddress("antikt4HI_bad_cell_et", &antikt4HI_bad_cell_et, &b_antikt4HI_bad_cell_et);
    fChain->SetBranchAddress("antikt4HI_bad_cell_area", &antikt4HI_bad_cell_area, &b_antikt4HI_bad_cell_area);
    fChain->SetBranchAddress("antikt4HI_empty_cell_n", &antikt4HI_empty_cell_n, &b_antikt4HI_empty_cell_n);
    fChain->SetBranchAddress("antikt4HI_empty_cell_et", &antikt4HI_empty_cell_et, &b_antikt4HI_empty_cell_et);
    fChain->SetBranchAddress("antikt4HI_empty_cell_area", &antikt4HI_empty_cell_area, &b_antikt4HI_empty_cell_area);
    fChain->SetBranchAddress("antikt4HI_total_cell_n", &antikt4HI_total_cell_n, &b_antikt4HI_total_cell_n);
    fChain->SetBranchAddress("antikt4HI_total_cell_et", &antikt4HI_total_cell_et, &b_antikt4HI_total_cell_et);
    fChain->SetBranchAddress("antikt4HI_total_cell_area", &antikt4HI_total_cell_area, &b_antikt4HI_total_cell_area);
    fChain->SetBranchAddress("antikt4HIFlow_n", &antikt4HIFlow_n, &b_antikt4HIFlow_n);
    fChain->SetBranchAddress("antikt4HIFlow_E", &antikt4HIFlow_E, &b_antikt4HIFlow_E);
    fChain->SetBranchAddress("antikt4HIFlow_pt", &antikt4HIFlow_pt, &b_antikt4HIFlow_pt);
    fChain->SetBranchAddress("antikt4HIFlow_m", &antikt4HIFlow_m, &b_antikt4HIFlow_m);
    fChain->SetBranchAddress("antikt4HIFlow_eta", &antikt4HIFlow_eta, &b_antikt4HIFlow_eta);
    fChain->SetBranchAddress("antikt4HIFlow_phi", &antikt4HIFlow_phi, &b_antikt4HIFlow_phi);
    fChain->SetBranchAddress("antikt4HIFlow_MaxOverMean", &antikt4HIFlow_MaxOverMean, &b_antikt4HIFlow_MaxOverMean);
    fChain->SetBranchAddress("antikt4HIFlow_MeanTowerEt", &antikt4HIFlow_MeanTowerEt, &b_antikt4HIFlow_MeanTowerEt);
    fChain->SetBranchAddress("antikt4HIFlow_SubtractedEt", &antikt4HIFlow_SubtractedEt, &b_antikt4HIFlow_SubtractedEt);
    fChain->SetBranchAddress("antikt4HIFlow_RMSTowerEt", &antikt4HIFlow_RMSTowerEt, &b_antikt4HIFlow_RMSTowerEt);
    fChain->SetBranchAddress("antikt4HIFlow_SumJt", &antikt4HIFlow_SumJt, &b_antikt4HIFlow_SumJt);
    fChain->SetBranchAddress("antikt4HIFlow_CoreEt", &antikt4HIFlow_CoreEt, &b_antikt4HIFlow_CoreEt);
    fChain->SetBranchAddress("antikt4HIFlow_EdgeEt", &antikt4HIFlow_EdgeEt, &b_antikt4HIFlow_EdgeEt);
    fChain->SetBranchAddress("antikt4HIFlow_CryoCorr", &antikt4HIFlow_CryoCorr, &b_antikt4HIFlow_CryoCorr);
    fChain->SetBranchAddress("antikt4HIFlow_NoFlow", &antikt4HIFlow_NoFlow, &b_antikt4HIFlow_NoFlow);
    fChain->SetBranchAddress("antikt4HIFlow_NumConstituents", &antikt4HIFlow_NumConstituents, &b_antikt4HIFlow_NumConstituents);
    fChain->SetBranchAddress("antikt4HIFlow_UncalibEt", &antikt4HIFlow_UncalibEt, &b_antikt4HIFlow_UncalibEt);
    fChain->SetBranchAddress("antikt4HIFlow_Discriminant", &antikt4HIFlow_Discriminant, &b_antikt4HIFlow_Discriminant);
    fChain->SetBranchAddress("antikt4HIFlow_MeanTowerEtUnsubtr", &antikt4HIFlow_MeanTowerEtUnsubtr, &b_antikt4HIFlow_MeanTowerEtUnsubtr);
    fChain->SetBranchAddress("antikt4HIFlow_n90", &antikt4HIFlow_n90, &b_antikt4HIFlow_n90);
    fChain->SetBranchAddress("antikt4HIFlow_fracSamplingMax", &antikt4HIFlow_fracSamplingMax, &b_antikt4HIFlow_fracSamplingMax);
    fChain->SetBranchAddress("antikt4HIFlow_SamplingMax", &antikt4HIFlow_SamplingMax, &b_antikt4HIFlow_SamplingMax);
    fChain->SetBranchAddress("antikt4HIFlow_n90constituents", &antikt4HIFlow_n90constituents, &b_antikt4HIFlow_n90constituents);
    fChain->SetBranchAddress("antikt4HIFlow_Timing", &antikt4HIFlow_Timing, &b_antikt4HIFlow_Timing);
    fChain->SetBranchAddress("antikt4HIFlow_LArQuality", &antikt4HIFlow_LArQuality, &b_antikt4HIFlow_LArQuality);
    fChain->SetBranchAddress("antikt4HIFlow_HECQuality", &antikt4HIFlow_HECQuality, &b_antikt4HIFlow_HECQuality);
    fChain->SetBranchAddress("antikt4HIFlow_TileQuality", &antikt4HIFlow_TileQuality, &b_antikt4HIFlow_TileQuality);
    fChain->SetBranchAddress("antikt4HIFlow_const_n", &antikt4HIFlow_const_n, &b_antikt4HIFlow_const_n);
    fChain->SetBranchAddress("antikt4HIFlow_const_et", &antikt4HIFlow_const_et, &b_antikt4HIFlow_const_et);
    fChain->SetBranchAddress("antikt4HIFlow_const_eta", &antikt4HIFlow_const_eta, &b_antikt4HIFlow_const_eta);
    fChain->SetBranchAddress("antikt4HIFlow_const_phi", &antikt4HIFlow_const_phi, &b_antikt4HIFlow_const_phi);
    fChain->SetBranchAddress("antikt4HIFlow_sampling_et", &antikt4HIFlow_sampling_et, &b_antikt4HIFlow_sampling_et);
    fChain->SetBranchAddress("antikt4HIFlow_sampling_et_unsubtr", &antikt4HIFlow_sampling_et_unsubtr, &b_antikt4HIFlow_sampling_et_unsubtr);
    fChain->SetBranchAddress("antikt4HIFlow_bad_cell_n", &antikt4HIFlow_bad_cell_n, &b_antikt4HIFlow_bad_cell_n);
    fChain->SetBranchAddress("antikt4HIFlow_bad_cell_et", &antikt4HIFlow_bad_cell_et, &b_antikt4HIFlow_bad_cell_et);
    fChain->SetBranchAddress("antikt4HIFlow_bad_cell_area", &antikt4HIFlow_bad_cell_area, &b_antikt4HIFlow_bad_cell_area);
    fChain->SetBranchAddress("antikt4HIFlow_empty_cell_n", &antikt4HIFlow_empty_cell_n, &b_antikt4HIFlow_empty_cell_n);
    fChain->SetBranchAddress("antikt4HIFlow_empty_cell_et", &antikt4HIFlow_empty_cell_et, &b_antikt4HIFlow_empty_cell_et);
    fChain->SetBranchAddress("antikt4HIFlow_empty_cell_area", &antikt4HIFlow_empty_cell_area, &b_antikt4HIFlow_empty_cell_area);
    fChain->SetBranchAddress("antikt4HIFlow_total_cell_n", &antikt4HIFlow_total_cell_n, &b_antikt4HIFlow_total_cell_n);
    fChain->SetBranchAddress("antikt4HIFlow_total_cell_et", &antikt4HIFlow_total_cell_et, &b_antikt4HIFlow_total_cell_et);
    fChain->SetBranchAddress("antikt4HIFlow_total_cell_area", &antikt4HIFlow_total_cell_area, &b_antikt4HIFlow_total_cell_area);
    fChain->SetBranchAddress("antikt4HIAvgFlow_n", &antikt4HIAvgFlow_n, &b_antikt4HIAvgFlow_n);
    fChain->SetBranchAddress("antikt4HIAvgFlow_E", &antikt4HIAvgFlow_E, &b_antikt4HIAvgFlow_E);
    fChain->SetBranchAddress("antikt4HIAvgFlow_pt", &antikt4HIAvgFlow_pt, &b_antikt4HIAvgFlow_pt);
    fChain->SetBranchAddress("antikt4HIAvgFlow_m", &antikt4HIAvgFlow_m, &b_antikt4HIAvgFlow_m);
    fChain->SetBranchAddress("antikt4HIAvgFlow_eta", &antikt4HIAvgFlow_eta, &b_antikt4HIAvgFlow_eta);
    fChain->SetBranchAddress("antikt4HIAvgFlow_phi", &antikt4HIAvgFlow_phi, &b_antikt4HIAvgFlow_phi);
    fChain->SetBranchAddress("antikt4HIAvgFlow_MaxOverMean", &antikt4HIAvgFlow_MaxOverMean, &b_antikt4HIAvgFlow_MaxOverMean);
    fChain->SetBranchAddress("antikt4HIAvgFlow_MeanTowerEt", &antikt4HIAvgFlow_MeanTowerEt, &b_antikt4HIAvgFlow_MeanTowerEt);
    fChain->SetBranchAddress("antikt4HIAvgFlow_SubtractedEt", &antikt4HIAvgFlow_SubtractedEt, &b_antikt4HIAvgFlow_SubtractedEt);
    fChain->SetBranchAddress("antikt4HIAvgFlow_RMSTowerEt", &antikt4HIAvgFlow_RMSTowerEt, &b_antikt4HIAvgFlow_RMSTowerEt);
    fChain->SetBranchAddress("antikt4HIAvgFlow_SumJt", &antikt4HIAvgFlow_SumJt, &b_antikt4HIAvgFlow_SumJt);
    fChain->SetBranchAddress("antikt4HIAvgFlow_CoreEt", &antikt4HIAvgFlow_CoreEt, &b_antikt4HIAvgFlow_CoreEt);
    fChain->SetBranchAddress("antikt4HIAvgFlow_EdgeEt", &antikt4HIAvgFlow_EdgeEt, &b_antikt4HIAvgFlow_EdgeEt);
    fChain->SetBranchAddress("antikt4HIAvgFlow_CryoCorr", &antikt4HIAvgFlow_CryoCorr, &b_antikt4HIAvgFlow_CryoCorr);
    fChain->SetBranchAddress("antikt4HIAvgFlow_NoFlow", &antikt4HIAvgFlow_NoFlow, &b_antikt4HIAvgFlow_NoFlow);
    fChain->SetBranchAddress("antikt4HIAvgFlow_NumConstituents", &antikt4HIAvgFlow_NumConstituents, &b_antikt4HIAvgFlow_NumConstituents);
    fChain->SetBranchAddress("antikt4HIAvgFlow_UncalibEt", &antikt4HIAvgFlow_UncalibEt, &b_antikt4HIAvgFlow_UncalibEt);
    fChain->SetBranchAddress("antikt4HIAvgFlow_Discriminant", &antikt4HIAvgFlow_Discriminant, &b_antikt4HIAvgFlow_Discriminant);
    fChain->SetBranchAddress("antikt4HIAvgFlow_MeanTowerEtUnsubtr", &antikt4HIAvgFlow_MeanTowerEtUnsubtr, &b_antikt4HIAvgFlow_MeanTowerEtUnsubtr);
    fChain->SetBranchAddress("antikt4HIAvgFlow_n90", &antikt4HIAvgFlow_n90, &b_antikt4HIAvgFlow_n90);
    fChain->SetBranchAddress("antikt4HIAvgFlow_fracSamplingMax", &antikt4HIAvgFlow_fracSamplingMax, &b_antikt4HIAvgFlow_fracSamplingMax);
    fChain->SetBranchAddress("antikt4HIAvgFlow_SamplingMax", &antikt4HIAvgFlow_SamplingMax, &b_antikt4HIAvgFlow_SamplingMax);
    fChain->SetBranchAddress("antikt4HIAvgFlow_n90constituents", &antikt4HIAvgFlow_n90constituents, &b_antikt4HIAvgFlow_n90constituents);
    fChain->SetBranchAddress("antikt4HIAvgFlow_Timing", &antikt4HIAvgFlow_Timing, &b_antikt4HIAvgFlow_Timing);
    fChain->SetBranchAddress("antikt4HIAvgFlow_LArQuality", &antikt4HIAvgFlow_LArQuality, &b_antikt4HIAvgFlow_LArQuality);
    fChain->SetBranchAddress("antikt4HIAvgFlow_HECQuality", &antikt4HIAvgFlow_HECQuality, &b_antikt4HIAvgFlow_HECQuality);
    fChain->SetBranchAddress("antikt4HIAvgFlow_TileQuality", &antikt4HIAvgFlow_TileQuality, &b_antikt4HIAvgFlow_TileQuality);
    fChain->SetBranchAddress("antikt4HIAvgFlow_const_n", &antikt4HIAvgFlow_const_n, &b_antikt4HIAvgFlow_const_n);
    fChain->SetBranchAddress("antikt4HIAvgFlow_const_et", &antikt4HIAvgFlow_const_et, &b_antikt4HIAvgFlow_const_et);
    fChain->SetBranchAddress("antikt4HIAvgFlow_const_eta", &antikt4HIAvgFlow_const_eta, &b_antikt4HIAvgFlow_const_eta);
    fChain->SetBranchAddress("antikt4HIAvgFlow_const_phi", &antikt4HIAvgFlow_const_phi, &b_antikt4HIAvgFlow_const_phi);
    fChain->SetBranchAddress("antikt4HIAvgFlow_sampling_et", &antikt4HIAvgFlow_sampling_et, &b_antikt4HIAvgFlow_sampling_et);
    fChain->SetBranchAddress("antikt4HIAvgFlow_sampling_et_unsubtr", &antikt4HIAvgFlow_sampling_et_unsubtr, &b_antikt4HIAvgFlow_sampling_et_unsubtr);
    fChain->SetBranchAddress("antikt4HIAvgFlow_bad_cell_n", &antikt4HIAvgFlow_bad_cell_n, &b_antikt4HIAvgFlow_bad_cell_n);
    fChain->SetBranchAddress("antikt4HIAvgFlow_bad_cell_et", &antikt4HIAvgFlow_bad_cell_et, &b_antikt4HIAvgFlow_bad_cell_et);
    fChain->SetBranchAddress("antikt4HIAvgFlow_bad_cell_area", &antikt4HIAvgFlow_bad_cell_area, &b_antikt4HIAvgFlow_bad_cell_area);
    fChain->SetBranchAddress("antikt4HIAvgFlow_empty_cell_n", &antikt4HIAvgFlow_empty_cell_n, &b_antikt4HIAvgFlow_empty_cell_n);
    fChain->SetBranchAddress("antikt4HIAvgFlow_empty_cell_et", &antikt4HIAvgFlow_empty_cell_et, &b_antikt4HIAvgFlow_empty_cell_et);
    fChain->SetBranchAddress("antikt4HIAvgFlow_empty_cell_area", &antikt4HIAvgFlow_empty_cell_area, &b_antikt4HIAvgFlow_empty_cell_area);
    fChain->SetBranchAddress("antikt4HIAvgFlow_total_cell_n", &antikt4HIAvgFlow_total_cell_n, &b_antikt4HIAvgFlow_total_cell_n);
    fChain->SetBranchAddress("antikt4HIAvgFlow_total_cell_et", &antikt4HIAvgFlow_total_cell_et, &b_antikt4HIAvgFlow_total_cell_et);
    fChain->SetBranchAddress("antikt4HIAvgFlow_total_cell_area", &antikt4HIAvgFlow_total_cell_area, &b_antikt4HIAvgFlow_total_cell_area);
    fChain->SetBranchAddress("antikt4HIItr_n", &antikt4HIItr_n, &b_antikt4HIItr_n);
    fChain->SetBranchAddress("antikt4HIItr_E", &antikt4HIItr_E, &b_antikt4HIItr_E);
    fChain->SetBranchAddress("antikt4HIItr_pt", &antikt4HIItr_pt, &b_antikt4HIItr_pt);
    fChain->SetBranchAddress("antikt4HIItr_m", &antikt4HIItr_m, &b_antikt4HIItr_m);
    fChain->SetBranchAddress("antikt4HIItr_eta", &antikt4HIItr_eta, &b_antikt4HIItr_eta);
    fChain->SetBranchAddress("antikt4HIItr_phi", &antikt4HIItr_phi, &b_antikt4HIItr_phi);
    fChain->SetBranchAddress("antikt4HIItr_MaxOverMean", &antikt4HIItr_MaxOverMean, &b_antikt4HIItr_MaxOverMean);
    fChain->SetBranchAddress("antikt4HIItr_MeanTowerEt", &antikt4HIItr_MeanTowerEt, &b_antikt4HIItr_MeanTowerEt);
    fChain->SetBranchAddress("antikt4HIItr_SubtractedEt", &antikt4HIItr_SubtractedEt, &b_antikt4HIItr_SubtractedEt);
    fChain->SetBranchAddress("antikt4HIItr_RMSTowerEt", &antikt4HIItr_RMSTowerEt, &b_antikt4HIItr_RMSTowerEt);
    fChain->SetBranchAddress("antikt4HIItr_SumJt", &antikt4HIItr_SumJt, &b_antikt4HIItr_SumJt);
    fChain->SetBranchAddress("antikt4HIItr_CoreEt", &antikt4HIItr_CoreEt, &b_antikt4HIItr_CoreEt);
    fChain->SetBranchAddress("antikt4HIItr_EdgeEt", &antikt4HIItr_EdgeEt, &b_antikt4HIItr_EdgeEt);
    fChain->SetBranchAddress("antikt4HIItr_CryoCorr", &antikt4HIItr_CryoCorr, &b_antikt4HIItr_CryoCorr);
    fChain->SetBranchAddress("antikt4HIItr_NoFlow", &antikt4HIItr_NoFlow, &b_antikt4HIItr_NoFlow);
    fChain->SetBranchAddress("antikt4HIItr_NumConstituents", &antikt4HIItr_NumConstituents, &b_antikt4HIItr_NumConstituents);
    fChain->SetBranchAddress("antikt4HIItr_UncalibEt", &antikt4HIItr_UncalibEt, &b_antikt4HIItr_UncalibEt);
    fChain->SetBranchAddress("antikt4HIItr_Discriminant", &antikt4HIItr_Discriminant, &b_antikt4HIItr_Discriminant);
    fChain->SetBranchAddress("antikt4HIItr_MeanTowerEtUnsubtr", &antikt4HIItr_MeanTowerEtUnsubtr, &b_antikt4HIItr_MeanTowerEtUnsubtr);
    fChain->SetBranchAddress("antikt4HIItr_n90", &antikt4HIItr_n90, &b_antikt4HIItr_n90);
    fChain->SetBranchAddress("antikt4HIItr_fracSamplingMax", &antikt4HIItr_fracSamplingMax, &b_antikt4HIItr_fracSamplingMax);
    fChain->SetBranchAddress("antikt4HIItr_SamplingMax", &antikt4HIItr_SamplingMax, &b_antikt4HIItr_SamplingMax);
    fChain->SetBranchAddress("antikt4HIItr_n90constituents", &antikt4HIItr_n90constituents, &b_antikt4HIItr_n90constituents);
    fChain->SetBranchAddress("antikt4HIItr_Timing", &antikt4HIItr_Timing, &b_antikt4HIItr_Timing);
    fChain->SetBranchAddress("antikt4HIItr_LArQuality", &antikt4HIItr_LArQuality, &b_antikt4HIItr_LArQuality);
    fChain->SetBranchAddress("antikt4HIItr_HECQuality", &antikt4HIItr_HECQuality, &b_antikt4HIItr_HECQuality);
    fChain->SetBranchAddress("antikt4HIItr_TileQuality", &antikt4HIItr_TileQuality, &b_antikt4HIItr_TileQuality);
    fChain->SetBranchAddress("antikt4HIItr_const_n", &antikt4HIItr_const_n, &b_antikt4HIItr_const_n);
    fChain->SetBranchAddress("antikt4HIItr_const_et", &antikt4HIItr_const_et, &b_antikt4HIItr_const_et);
    fChain->SetBranchAddress("antikt4HIItr_const_eta", &antikt4HIItr_const_eta, &b_antikt4HIItr_const_eta);
    fChain->SetBranchAddress("antikt4HIItr_const_phi", &antikt4HIItr_const_phi, &b_antikt4HIItr_const_phi);
    fChain->SetBranchAddress("antikt4HIItr_sampling_et", &antikt4HIItr_sampling_et, &b_antikt4HIItr_sampling_et);
    fChain->SetBranchAddress("antikt4HIItr_sampling_et_unsubtr", &antikt4HIItr_sampling_et_unsubtr, &b_antikt4HIItr_sampling_et_unsubtr);
    fChain->SetBranchAddress("antikt4HIItr_bad_cell_n", &antikt4HIItr_bad_cell_n, &b_antikt4HIItr_bad_cell_n);
    fChain->SetBranchAddress("antikt4HIItr_bad_cell_et", &antikt4HIItr_bad_cell_et, &b_antikt4HIItr_bad_cell_et);
    fChain->SetBranchAddress("antikt4HIItr_bad_cell_area", &antikt4HIItr_bad_cell_area, &b_antikt4HIItr_bad_cell_area);
    fChain->SetBranchAddress("antikt4HIItr_empty_cell_n", &antikt4HIItr_empty_cell_n, &b_antikt4HIItr_empty_cell_n);
    fChain->SetBranchAddress("antikt4HIItr_empty_cell_et", &antikt4HIItr_empty_cell_et, &b_antikt4HIItr_empty_cell_et);
    fChain->SetBranchAddress("antikt4HIItr_empty_cell_area", &antikt4HIItr_empty_cell_area, &b_antikt4HIItr_empty_cell_area);
    fChain->SetBranchAddress("antikt4HIItr_total_cell_n", &antikt4HIItr_total_cell_n, &b_antikt4HIItr_total_cell_n);
    fChain->SetBranchAddress("antikt4HIItr_total_cell_et", &antikt4HIItr_total_cell_et, &b_antikt4HIItr_total_cell_et);
    fChain->SetBranchAddress("antikt4HIItr_total_cell_area", &antikt4HIItr_total_cell_area, &b_antikt4HIItr_total_cell_area);
    fChain->SetBranchAddress("antikt4HIItrFlow_n", &antikt4HIItrFlow_n, &b_antikt4HIItrFlow_n);
    fChain->SetBranchAddress("antikt4HIItrFlow_E", &antikt4HIItrFlow_E, &b_antikt4HIItrFlow_E);
    fChain->SetBranchAddress("antikt4HIItrFlow_pt", &antikt4HIItrFlow_pt, &b_antikt4HIItrFlow_pt);
    fChain->SetBranchAddress("antikt4HIItrFlow_m", &antikt4HIItrFlow_m, &b_antikt4HIItrFlow_m);
    fChain->SetBranchAddress("antikt4HIItrFlow_eta", &antikt4HIItrFlow_eta, &b_antikt4HIItrFlow_eta);
    fChain->SetBranchAddress("antikt4HIItrFlow_phi", &antikt4HIItrFlow_phi, &b_antikt4HIItrFlow_phi);
    fChain->SetBranchAddress("antikt4HIItrFlow_MaxOverMean", &antikt4HIItrFlow_MaxOverMean, &b_antikt4HIItrFlow_MaxOverMean);
    fChain->SetBranchAddress("antikt4HIItrFlow_MeanTowerEt", &antikt4HIItrFlow_MeanTowerEt, &b_antikt4HIItrFlow_MeanTowerEt);
    fChain->SetBranchAddress("antikt4HIItrFlow_SubtractedEt", &antikt4HIItrFlow_SubtractedEt, &b_antikt4HIItrFlow_SubtractedEt);
    fChain->SetBranchAddress("antikt4HIItrFlow_RMSTowerEt", &antikt4HIItrFlow_RMSTowerEt, &b_antikt4HIItrFlow_RMSTowerEt);
    fChain->SetBranchAddress("antikt4HIItrFlow_SumJt", &antikt4HIItrFlow_SumJt, &b_antikt4HIItrFlow_SumJt);
    fChain->SetBranchAddress("antikt4HIItrFlow_CoreEt", &antikt4HIItrFlow_CoreEt, &b_antikt4HIItrFlow_CoreEt);
    fChain->SetBranchAddress("antikt4HIItrFlow_EdgeEt", &antikt4HIItrFlow_EdgeEt, &b_antikt4HIItrFlow_EdgeEt);
    fChain->SetBranchAddress("antikt4HIItrFlow_CryoCorr", &antikt4HIItrFlow_CryoCorr, &b_antikt4HIItrFlow_CryoCorr);
    fChain->SetBranchAddress("antikt4HIItrFlow_NoFlow", &antikt4HIItrFlow_NoFlow, &b_antikt4HIItrFlow_NoFlow);
    fChain->SetBranchAddress("antikt4HIItrFlow_NumConstituents", &antikt4HIItrFlow_NumConstituents, &b_antikt4HIItrFlow_NumConstituents);
    fChain->SetBranchAddress("antikt4HIItrFlow_UncalibEt", &antikt4HIItrFlow_UncalibEt, &b_antikt4HIItrFlow_UncalibEt);
    fChain->SetBranchAddress("antikt4HIItrFlow_Discriminant", &antikt4HIItrFlow_Discriminant, &b_antikt4HIItrFlow_Discriminant);
    fChain->SetBranchAddress("antikt4HIItrFlow_MeanTowerEtUnsubtr", &antikt4HIItrFlow_MeanTowerEtUnsubtr, &b_antikt4HIItrFlow_MeanTowerEtUnsubtr);
    fChain->SetBranchAddress("antikt4HIItrFlow_n90", &antikt4HIItrFlow_n90, &b_antikt4HIItrFlow_n90);
    fChain->SetBranchAddress("antikt4HIItrFlow_fracSamplingMax", &antikt4HIItrFlow_fracSamplingMax, &b_antikt4HIItrFlow_fracSamplingMax);
    fChain->SetBranchAddress("antikt4HIItrFlow_SamplingMax", &antikt4HIItrFlow_SamplingMax, &b_antikt4HIItrFlow_SamplingMax);
    fChain->SetBranchAddress("antikt4HIItrFlow_n90constituents", &antikt4HIItrFlow_n90constituents, &b_antikt4HIItrFlow_n90constituents);
    fChain->SetBranchAddress("antikt4HIItrFlow_Timing", &antikt4HIItrFlow_Timing, &b_antikt4HIItrFlow_Timing);
    fChain->SetBranchAddress("antikt4HIItrFlow_LArQuality", &antikt4HIItrFlow_LArQuality, &b_antikt4HIItrFlow_LArQuality);
    fChain->SetBranchAddress("antikt4HIItrFlow_HECQuality", &antikt4HIItrFlow_HECQuality, &b_antikt4HIItrFlow_HECQuality);
    fChain->SetBranchAddress("antikt4HIItrFlow_TileQuality", &antikt4HIItrFlow_TileQuality, &b_antikt4HIItrFlow_TileQuality);
    fChain->SetBranchAddress("antikt4HIItrFlow_const_n", &antikt4HIItrFlow_const_n, &b_antikt4HIItrFlow_const_n);
    fChain->SetBranchAddress("antikt4HIItrFlow_const_et", &antikt4HIItrFlow_const_et, &b_antikt4HIItrFlow_const_et);
    fChain->SetBranchAddress("antikt4HIItrFlow_const_eta", &antikt4HIItrFlow_const_eta, &b_antikt4HIItrFlow_const_eta);
    fChain->SetBranchAddress("antikt4HIItrFlow_const_phi", &antikt4HIItrFlow_const_phi, &b_antikt4HIItrFlow_const_phi);
    fChain->SetBranchAddress("antikt4HIItrFlow_sampling_et", &antikt4HIItrFlow_sampling_et, &b_antikt4HIItrFlow_sampling_et);
    fChain->SetBranchAddress("antikt4HIItrFlow_sampling_et_unsubtr", &antikt4HIItrFlow_sampling_et_unsubtr, &b_antikt4HIItrFlow_sampling_et_unsubtr);
    fChain->SetBranchAddress("antikt4HIItrFlow_bad_cell_n", &antikt4HIItrFlow_bad_cell_n, &b_antikt4HIItrFlow_bad_cell_n);
    fChain->SetBranchAddress("antikt4HIItrFlow_bad_cell_et", &antikt4HIItrFlow_bad_cell_et, &b_antikt4HIItrFlow_bad_cell_et);
    fChain->SetBranchAddress("antikt4HIItrFlow_bad_cell_area", &antikt4HIItrFlow_bad_cell_area, &b_antikt4HIItrFlow_bad_cell_area);
    fChain->SetBranchAddress("antikt4HIItrFlow_empty_cell_n", &antikt4HIItrFlow_empty_cell_n, &b_antikt4HIItrFlow_empty_cell_n);
    fChain->SetBranchAddress("antikt4HIItrFlow_empty_cell_et", &antikt4HIItrFlow_empty_cell_et, &b_antikt4HIItrFlow_empty_cell_et);
    fChain->SetBranchAddress("antikt4HIItrFlow_empty_cell_area", &antikt4HIItrFlow_empty_cell_area, &b_antikt4HIItrFlow_empty_cell_area);
    fChain->SetBranchAddress("antikt4HIItrFlow_total_cell_n", &antikt4HIItrFlow_total_cell_n, &b_antikt4HIItrFlow_total_cell_n);
    fChain->SetBranchAddress("antikt4HIItrFlow_total_cell_et", &antikt4HIItrFlow_total_cell_et, &b_antikt4HIItrFlow_total_cell_et);
    fChain->SetBranchAddress("antikt4HIItrFlow_total_cell_area", &antikt4HIItrFlow_total_cell_area, &b_antikt4HIItrFlow_total_cell_area);
    fChain->SetBranchAddress("antikt2HIAvg_n", &antikt2HIAvg_n, &b_antikt2HIAvg_n);
    fChain->SetBranchAddress("antikt2HIAvg_E", &antikt2HIAvg_E, &b_antikt2HIAvg_E);
    fChain->SetBranchAddress("antikt2HIAvg_pt", &antikt2HIAvg_pt, &b_antikt2HIAvg_pt);
    fChain->SetBranchAddress("antikt2HIAvg_m", &antikt2HIAvg_m, &b_antikt2HIAvg_m);
    fChain->SetBranchAddress("antikt2HIAvg_eta", &antikt2HIAvg_eta, &b_antikt2HIAvg_eta);
    fChain->SetBranchAddress("antikt2HIAvg_phi", &antikt2HIAvg_phi, &b_antikt2HIAvg_phi);
    fChain->SetBranchAddress("antikt2HIAvg_MaxOverMean", &antikt2HIAvg_MaxOverMean, &b_antikt2HIAvg_MaxOverMean);
    fChain->SetBranchAddress("antikt2HIAvg_MeanTowerEt", &antikt2HIAvg_MeanTowerEt, &b_antikt2HIAvg_MeanTowerEt);
    fChain->SetBranchAddress("antikt2HIAvg_SubtractedEt", &antikt2HIAvg_SubtractedEt, &b_antikt2HIAvg_SubtractedEt);
    fChain->SetBranchAddress("antikt2HIAvg_RMSTowerEt", &antikt2HIAvg_RMSTowerEt, &b_antikt2HIAvg_RMSTowerEt);
    fChain->SetBranchAddress("antikt2HIAvg_SumJt", &antikt2HIAvg_SumJt, &b_antikt2HIAvg_SumJt);
    fChain->SetBranchAddress("antikt2HIAvg_CoreEt", &antikt2HIAvg_CoreEt, &b_antikt2HIAvg_CoreEt);
    fChain->SetBranchAddress("antikt2HIAvg_EdgeEt", &antikt2HIAvg_EdgeEt, &b_antikt2HIAvg_EdgeEt);
    fChain->SetBranchAddress("antikt2HIAvg_CryoCorr", &antikt2HIAvg_CryoCorr, &b_antikt2HIAvg_CryoCorr);
    fChain->SetBranchAddress("antikt2HIAvg_NoFlow", &antikt2HIAvg_NoFlow, &b_antikt2HIAvg_NoFlow);
    fChain->SetBranchAddress("antikt2HIAvg_NumConstituents", &antikt2HIAvg_NumConstituents, &b_antikt2HIAvg_NumConstituents);
    fChain->SetBranchAddress("antikt2HIAvg_UncalibEt", &antikt2HIAvg_UncalibEt, &b_antikt2HIAvg_UncalibEt);
    fChain->SetBranchAddress("antikt2HIAvg_Discriminant", &antikt2HIAvg_Discriminant, &b_antikt2HIAvg_Discriminant);
    fChain->SetBranchAddress("antikt2HIAvg_MeanTowerEtUnsubtr", &antikt2HIAvg_MeanTowerEtUnsubtr, &b_antikt2HIAvg_MeanTowerEtUnsubtr);
    fChain->SetBranchAddress("antikt2HIAvg_n90", &antikt2HIAvg_n90, &b_antikt2HIAvg_n90);
    fChain->SetBranchAddress("antikt2HIAvg_fracSamplingMax", &antikt2HIAvg_fracSamplingMax, &b_antikt2HIAvg_fracSamplingMax);
    fChain->SetBranchAddress("antikt2HIAvg_SamplingMax", &antikt2HIAvg_SamplingMax, &b_antikt2HIAvg_SamplingMax);
    fChain->SetBranchAddress("antikt2HIAvg_n90constituents", &antikt2HIAvg_n90constituents, &b_antikt2HIAvg_n90constituents);
    fChain->SetBranchAddress("antikt2HIAvg_Timing", &antikt2HIAvg_Timing, &b_antikt2HIAvg_Timing);
    fChain->SetBranchAddress("antikt2HIAvg_LArQuality", &antikt2HIAvg_LArQuality, &b_antikt2HIAvg_LArQuality);
    fChain->SetBranchAddress("antikt2HIAvg_HECQuality", &antikt2HIAvg_HECQuality, &b_antikt2HIAvg_HECQuality);
    fChain->SetBranchAddress("antikt2HIAvg_TileQuality", &antikt2HIAvg_TileQuality, &b_antikt2HIAvg_TileQuality);
    fChain->SetBranchAddress("antikt2HIAvg_const_n", &antikt2HIAvg_const_n, &b_antikt2HIAvg_const_n);
    fChain->SetBranchAddress("antikt2HIAvg_const_et", &antikt2HIAvg_const_et, &b_antikt2HIAvg_const_et);
    fChain->SetBranchAddress("antikt2HIAvg_const_eta", &antikt2HIAvg_const_eta, &b_antikt2HIAvg_const_eta);
    fChain->SetBranchAddress("antikt2HIAvg_const_phi", &antikt2HIAvg_const_phi, &b_antikt2HIAvg_const_phi);
    fChain->SetBranchAddress("antikt2HIAvg_sampling_et", &antikt2HIAvg_sampling_et, &b_antikt2HIAvg_sampling_et);
    fChain->SetBranchAddress("antikt2HIAvg_sampling_et_unsubtr", &antikt2HIAvg_sampling_et_unsubtr, &b_antikt2HIAvg_sampling_et_unsubtr);
    fChain->SetBranchAddress("antikt2HIAvg_bad_cell_n", &antikt2HIAvg_bad_cell_n, &b_antikt2HIAvg_bad_cell_n);
    fChain->SetBranchAddress("antikt2HIAvg_bad_cell_et", &antikt2HIAvg_bad_cell_et, &b_antikt2HIAvg_bad_cell_et);
    fChain->SetBranchAddress("antikt2HIAvg_bad_cell_area", &antikt2HIAvg_bad_cell_area, &b_antikt2HIAvg_bad_cell_area);
    fChain->SetBranchAddress("antikt2HIAvg_empty_cell_n", &antikt2HIAvg_empty_cell_n, &b_antikt2HIAvg_empty_cell_n);
    fChain->SetBranchAddress("antikt2HIAvg_empty_cell_et", &antikt2HIAvg_empty_cell_et, &b_antikt2HIAvg_empty_cell_et);
    fChain->SetBranchAddress("antikt2HIAvg_empty_cell_area", &antikt2HIAvg_empty_cell_area, &b_antikt2HIAvg_empty_cell_area);
    fChain->SetBranchAddress("antikt2HIAvg_total_cell_n", &antikt2HIAvg_total_cell_n, &b_antikt2HIAvg_total_cell_n);
    fChain->SetBranchAddress("antikt2HIAvg_total_cell_et", &antikt2HIAvg_total_cell_et, &b_antikt2HIAvg_total_cell_et);
    fChain->SetBranchAddress("antikt2HIAvg_total_cell_area", &antikt2HIAvg_total_cell_area, &b_antikt2HIAvg_total_cell_area);
    fChain->SetBranchAddress("antikt4HIAvg_n", &antikt4HIAvg_n, &b_antikt4HIAvg_n);
    fChain->SetBranchAddress("antikt4HIAvg_E", &antikt4HIAvg_E, &b_antikt4HIAvg_E);
    fChain->SetBranchAddress("antikt4HIAvg_pt", &antikt4HIAvg_pt, &b_antikt4HIAvg_pt);
    fChain->SetBranchAddress("antikt4HIAvg_m", &antikt4HIAvg_m, &b_antikt4HIAvg_m);
    fChain->SetBranchAddress("antikt4HIAvg_eta", &antikt4HIAvg_eta, &b_antikt4HIAvg_eta);
    fChain->SetBranchAddress("antikt4HIAvg_phi", &antikt4HIAvg_phi, &b_antikt4HIAvg_phi);
    fChain->SetBranchAddress("antikt4HIAvg_MaxOverMean", &antikt4HIAvg_MaxOverMean, &b_antikt4HIAvg_MaxOverMean);
    fChain->SetBranchAddress("antikt4HIAvg_MeanTowerEt", &antikt4HIAvg_MeanTowerEt, &b_antikt4HIAvg_MeanTowerEt);
    fChain->SetBranchAddress("antikt4HIAvg_SubtractedEt", &antikt4HIAvg_SubtractedEt, &b_antikt4HIAvg_SubtractedEt);
    fChain->SetBranchAddress("antikt4HIAvg_RMSTowerEt", &antikt4HIAvg_RMSTowerEt, &b_antikt4HIAvg_RMSTowerEt);
    fChain->SetBranchAddress("antikt4HIAvg_SumJt", &antikt4HIAvg_SumJt, &b_antikt4HIAvg_SumJt);
    fChain->SetBranchAddress("antikt4HIAvg_CoreEt", &antikt4HIAvg_CoreEt, &b_antikt4HIAvg_CoreEt);
    fChain->SetBranchAddress("antikt4HIAvg_EdgeEt", &antikt4HIAvg_EdgeEt, &b_antikt4HIAvg_EdgeEt);
    fChain->SetBranchAddress("antikt4HIAvg_CryoCorr", &antikt4HIAvg_CryoCorr, &b_antikt4HIAvg_CryoCorr);
    fChain->SetBranchAddress("antikt4HIAvg_NoFlow", &antikt4HIAvg_NoFlow, &b_antikt4HIAvg_NoFlow);
    fChain->SetBranchAddress("antikt4HIAvg_NumConstituents", &antikt4HIAvg_NumConstituents, &b_antikt4HIAvg_NumConstituents);
    fChain->SetBranchAddress("antikt4HIAvg_UncalibEt", &antikt4HIAvg_UncalibEt, &b_antikt4HIAvg_UncalibEt);
    fChain->SetBranchAddress("antikt4HIAvg_Discriminant", &antikt4HIAvg_Discriminant, &b_antikt4HIAvg_Discriminant);
    fChain->SetBranchAddress("antikt4HIAvg_MeanTowerEtUnsubtr", &antikt4HIAvg_MeanTowerEtUnsubtr, &b_antikt4HIAvg_MeanTowerEtUnsubtr);
    fChain->SetBranchAddress("antikt4HIAvg_n90", &antikt4HIAvg_n90, &b_antikt4HIAvg_n90);
    fChain->SetBranchAddress("antikt4HIAvg_fracSamplingMax", &antikt4HIAvg_fracSamplingMax, &b_antikt4HIAvg_fracSamplingMax);
    fChain->SetBranchAddress("antikt4HIAvg_SamplingMax", &antikt4HIAvg_SamplingMax, &b_antikt4HIAvg_SamplingMax);
    fChain->SetBranchAddress("antikt4HIAvg_n90constituents", &antikt4HIAvg_n90constituents, &b_antikt4HIAvg_n90constituents);
    fChain->SetBranchAddress("antikt4HIAvg_Timing", &antikt4HIAvg_Timing, &b_antikt4HIAvg_Timing);
    fChain->SetBranchAddress("antikt4HIAvg_LArQuality", &antikt4HIAvg_LArQuality, &b_antikt4HIAvg_LArQuality);
    fChain->SetBranchAddress("antikt4HIAvg_HECQuality", &antikt4HIAvg_HECQuality, &b_antikt4HIAvg_HECQuality);
    fChain->SetBranchAddress("antikt4HIAvg_TileQuality", &antikt4HIAvg_TileQuality, &b_antikt4HIAvg_TileQuality);
    fChain->SetBranchAddress("antikt4HIAvg_const_n", &antikt4HIAvg_const_n, &b_antikt4HIAvg_const_n);
    fChain->SetBranchAddress("antikt4HIAvg_const_et", &antikt4HIAvg_const_et, &b_antikt4HIAvg_const_et);
    fChain->SetBranchAddress("antikt4HIAvg_const_eta", &antikt4HIAvg_const_eta, &b_antikt4HIAvg_const_eta);
    fChain->SetBranchAddress("antikt4HIAvg_const_phi", &antikt4HIAvg_const_phi, &b_antikt4HIAvg_const_phi);
    fChain->SetBranchAddress("antikt4HIAvg_sampling_et", &antikt4HIAvg_sampling_et, &b_antikt4HIAvg_sampling_et);
    fChain->SetBranchAddress("antikt4HIAvg_sampling_et_unsubtr", &antikt4HIAvg_sampling_et_unsubtr, &b_antikt4HIAvg_sampling_et_unsubtr);
    fChain->SetBranchAddress("antikt4HIAvg_bad_cell_n", &antikt4HIAvg_bad_cell_n, &b_antikt4HIAvg_bad_cell_n);
    fChain->SetBranchAddress("antikt4HIAvg_bad_cell_et", &antikt4HIAvg_bad_cell_et, &b_antikt4HIAvg_bad_cell_et);
    fChain->SetBranchAddress("antikt4HIAvg_bad_cell_area", &antikt4HIAvg_bad_cell_area, &b_antikt4HIAvg_bad_cell_area);
    fChain->SetBranchAddress("antikt4HIAvg_empty_cell_n", &antikt4HIAvg_empty_cell_n, &b_antikt4HIAvg_empty_cell_n);
    fChain->SetBranchAddress("antikt4HIAvg_empty_cell_et", &antikt4HIAvg_empty_cell_et, &b_antikt4HIAvg_empty_cell_et);
    fChain->SetBranchAddress("antikt4HIAvg_empty_cell_area", &antikt4HIAvg_empty_cell_area, &b_antikt4HIAvg_empty_cell_area);
    fChain->SetBranchAddress("antikt4HIAvg_total_cell_n", &antikt4HIAvg_total_cell_n, &b_antikt4HIAvg_total_cell_n);
    fChain->SetBranchAddress("antikt4HIAvg_total_cell_et", &antikt4HIAvg_total_cell_et, &b_antikt4HIAvg_total_cell_et);
    fChain->SetBranchAddress("antikt4HIAvg_total_cell_area", &antikt4HIAvg_total_cell_area, &b_antikt4HIAvg_total_cell_area);
    fChain->SetBranchAddress("antikt6HIAvg_n", &antikt6HIAvg_n, &b_antikt6HIAvg_n);
    fChain->SetBranchAddress("antikt6HIAvg_E", &antikt6HIAvg_E, &b_antikt6HIAvg_E);
    fChain->SetBranchAddress("antikt6HIAvg_pt", &antikt6HIAvg_pt, &b_antikt6HIAvg_pt);
    fChain->SetBranchAddress("antikt6HIAvg_m", &antikt6HIAvg_m, &b_antikt6HIAvg_m);
    fChain->SetBranchAddress("antikt6HIAvg_eta", &antikt6HIAvg_eta, &b_antikt6HIAvg_eta);
    fChain->SetBranchAddress("antikt6HIAvg_phi", &antikt6HIAvg_phi, &b_antikt6HIAvg_phi);
    fChain->SetBranchAddress("antikt6HIAvg_MaxOverMean", &antikt6HIAvg_MaxOverMean, &b_antikt6HIAvg_MaxOverMean);
    fChain->SetBranchAddress("antikt6HIAvg_MeanTowerEt", &antikt6HIAvg_MeanTowerEt, &b_antikt6HIAvg_MeanTowerEt);
    fChain->SetBranchAddress("antikt6HIAvg_SubtractedEt", &antikt6HIAvg_SubtractedEt, &b_antikt6HIAvg_SubtractedEt);
    fChain->SetBranchAddress("antikt6HIAvg_RMSTowerEt", &antikt6HIAvg_RMSTowerEt, &b_antikt6HIAvg_RMSTowerEt);
    fChain->SetBranchAddress("antikt6HIAvg_SumJt", &antikt6HIAvg_SumJt, &b_antikt6HIAvg_SumJt);
    fChain->SetBranchAddress("antikt6HIAvg_CoreEt", &antikt6HIAvg_CoreEt, &b_antikt6HIAvg_CoreEt);
    fChain->SetBranchAddress("antikt6HIAvg_EdgeEt", &antikt6HIAvg_EdgeEt, &b_antikt6HIAvg_EdgeEt);
    fChain->SetBranchAddress("antikt6HIAvg_CryoCorr", &antikt6HIAvg_CryoCorr, &b_antikt6HIAvg_CryoCorr);
    fChain->SetBranchAddress("antikt6HIAvg_NoFlow", &antikt6HIAvg_NoFlow, &b_antikt6HIAvg_NoFlow);
    fChain->SetBranchAddress("antikt6HIAvg_NumConstituents", &antikt6HIAvg_NumConstituents, &b_antikt6HIAvg_NumConstituents);
    fChain->SetBranchAddress("antikt6HIAvg_UncalibEt", &antikt6HIAvg_UncalibEt, &b_antikt6HIAvg_UncalibEt);
    fChain->SetBranchAddress("antikt6HIAvg_Discriminant", &antikt6HIAvg_Discriminant, &b_antikt6HIAvg_Discriminant);
    fChain->SetBranchAddress("antikt6HIAvg_MeanTowerEtUnsubtr", &antikt6HIAvg_MeanTowerEtUnsubtr, &b_antikt6HIAvg_MeanTowerEtUnsubtr);
    fChain->SetBranchAddress("antikt6HIAvg_n90", &antikt6HIAvg_n90, &b_antikt6HIAvg_n90);
    fChain->SetBranchAddress("antikt6HIAvg_fracSamplingMax", &antikt6HIAvg_fracSamplingMax, &b_antikt6HIAvg_fracSamplingMax);
    fChain->SetBranchAddress("antikt6HIAvg_SamplingMax", &antikt6HIAvg_SamplingMax, &b_antikt6HIAvg_SamplingMax);
    fChain->SetBranchAddress("antikt6HIAvg_n90constituents", &antikt6HIAvg_n90constituents, &b_antikt6HIAvg_n90constituents);
    fChain->SetBranchAddress("antikt6HIAvg_Timing", &antikt6HIAvg_Timing, &b_antikt6HIAvg_Timing);
    fChain->SetBranchAddress("antikt6HIAvg_LArQuality", &antikt6HIAvg_LArQuality, &b_antikt6HIAvg_LArQuality);
    fChain->SetBranchAddress("antikt6HIAvg_HECQuality", &antikt6HIAvg_HECQuality, &b_antikt6HIAvg_HECQuality);
    fChain->SetBranchAddress("antikt6HIAvg_TileQuality", &antikt6HIAvg_TileQuality, &b_antikt6HIAvg_TileQuality);
    fChain->SetBranchAddress("antikt6HIAvg_const_n", &antikt6HIAvg_const_n, &b_antikt6HIAvg_const_n);
    fChain->SetBranchAddress("antikt6HIAvg_const_et", &antikt6HIAvg_const_et, &b_antikt6HIAvg_const_et);
    fChain->SetBranchAddress("antikt6HIAvg_const_eta", &antikt6HIAvg_const_eta, &b_antikt6HIAvg_const_eta);
    fChain->SetBranchAddress("antikt6HIAvg_const_phi", &antikt6HIAvg_const_phi, &b_antikt6HIAvg_const_phi);
    fChain->SetBranchAddress("antikt6HIAvg_sampling_et", &antikt6HIAvg_sampling_et, &b_antikt6HIAvg_sampling_et);
    fChain->SetBranchAddress("antikt6HIAvg_sampling_et_unsubtr", &antikt6HIAvg_sampling_et_unsubtr, &b_antikt6HIAvg_sampling_et_unsubtr);
    fChain->SetBranchAddress("antikt6HIAvg_bad_cell_n", &antikt6HIAvg_bad_cell_n, &b_antikt6HIAvg_bad_cell_n);
    fChain->SetBranchAddress("antikt6HIAvg_bad_cell_et", &antikt6HIAvg_bad_cell_et, &b_antikt6HIAvg_bad_cell_et);
    fChain->SetBranchAddress("antikt6HIAvg_bad_cell_area", &antikt6HIAvg_bad_cell_area, &b_antikt6HIAvg_bad_cell_area);
    fChain->SetBranchAddress("antikt6HIAvg_empty_cell_n", &antikt6HIAvg_empty_cell_n, &b_antikt6HIAvg_empty_cell_n);
    fChain->SetBranchAddress("antikt6HIAvg_empty_cell_et", &antikt6HIAvg_empty_cell_et, &b_antikt6HIAvg_empty_cell_et);
    fChain->SetBranchAddress("antikt6HIAvg_empty_cell_area", &antikt6HIAvg_empty_cell_area, &b_antikt6HIAvg_empty_cell_area);
    fChain->SetBranchAddress("antikt6HIAvg_total_cell_n", &antikt6HIAvg_total_cell_n, &b_antikt6HIAvg_total_cell_n);
    fChain->SetBranchAddress("antikt6HIAvg_total_cell_et", &antikt6HIAvg_total_cell_et, &b_antikt6HIAvg_total_cell_et);
    fChain->SetBranchAddress("antikt6HIAvg_total_cell_area", &antikt6HIAvg_total_cell_area, &b_antikt6HIAvg_total_cell_area);
    fChain->SetBranchAddress("antikt4HIEM_n", &antikt4HIEM_n, &b_antikt4HIEM_n);
    fChain->SetBranchAddress("antikt4HIEM_E", &antikt4HIEM_E, &b_antikt4HIEM_E);
    fChain->SetBranchAddress("antikt4HIEM_pt", &antikt4HIEM_pt, &b_antikt4HIEM_pt);
    fChain->SetBranchAddress("antikt4HIEM_m", &antikt4HIEM_m, &b_antikt4HIEM_m);
    fChain->SetBranchAddress("antikt4HIEM_eta", &antikt4HIEM_eta, &b_antikt4HIEM_eta);
    fChain->SetBranchAddress("antikt4HIEM_phi", &antikt4HIEM_phi, &b_antikt4HIEM_phi);
    fChain->SetBranchAddress("antikt4HIEM_MaxOverMean", &antikt4HIEM_MaxOverMean, &b_antikt4HIEM_MaxOverMean);
    fChain->SetBranchAddress("antikt4HIEM_MeanTowerEt", &antikt4HIEM_MeanTowerEt, &b_antikt4HIEM_MeanTowerEt);
    fChain->SetBranchAddress("antikt4HIEM_SubtractedEt", &antikt4HIEM_SubtractedEt, &b_antikt4HIEM_SubtractedEt);
    fChain->SetBranchAddress("antikt4HIEM_RMSTowerEt", &antikt4HIEM_RMSTowerEt, &b_antikt4HIEM_RMSTowerEt);
    fChain->SetBranchAddress("antikt4HIEM_SumJt", &antikt4HIEM_SumJt, &b_antikt4HIEM_SumJt);
    fChain->SetBranchAddress("antikt4HIEM_CoreEt", &antikt4HIEM_CoreEt, &b_antikt4HIEM_CoreEt);
    fChain->SetBranchAddress("antikt4HIEM_EdgeEt", &antikt4HIEM_EdgeEt, &b_antikt4HIEM_EdgeEt);
    fChain->SetBranchAddress("antikt4HIEM_CryoCorr", &antikt4HIEM_CryoCorr, &b_antikt4HIEM_CryoCorr);
    fChain->SetBranchAddress("antikt4HIEM_NoFlow", &antikt4HIEM_NoFlow, &b_antikt4HIEM_NoFlow);
    fChain->SetBranchAddress("antikt4HIEM_NumConstituents", &antikt4HIEM_NumConstituents, &b_antikt4HIEM_NumConstituents);
    fChain->SetBranchAddress("antikt4HIEM_UncalibEt", &antikt4HIEM_UncalibEt, &b_antikt4HIEM_UncalibEt);
    fChain->SetBranchAddress("antikt4HIEM_Discriminant", &antikt4HIEM_Discriminant, &b_antikt4HIEM_Discriminant);
    fChain->SetBranchAddress("antikt4HIEM_MeanTowerEtUnsubtr", &antikt4HIEM_MeanTowerEtUnsubtr, &b_antikt4HIEM_MeanTowerEtUnsubtr);
    fChain->SetBranchAddress("antikt4HIEM_n90", &antikt4HIEM_n90, &b_antikt4HIEM_n90);
    fChain->SetBranchAddress("antikt4HIEM_fracSamplingMax", &antikt4HIEM_fracSamplingMax, &b_antikt4HIEM_fracSamplingMax);
    fChain->SetBranchAddress("antikt4HIEM_SamplingMax", &antikt4HIEM_SamplingMax, &b_antikt4HIEM_SamplingMax);
    fChain->SetBranchAddress("antikt4HIEM_n90constituents", &antikt4HIEM_n90constituents, &b_antikt4HIEM_n90constituents);
    fChain->SetBranchAddress("antikt4HIEM_Timing", &antikt4HIEM_Timing, &b_antikt4HIEM_Timing);
    fChain->SetBranchAddress("antikt4HIEM_LArQuality", &antikt4HIEM_LArQuality, &b_antikt4HIEM_LArQuality);
    fChain->SetBranchAddress("antikt4HIEM_HECQuality", &antikt4HIEM_HECQuality, &b_antikt4HIEM_HECQuality);
    fChain->SetBranchAddress("antikt4HIEM_TileQuality", &antikt4HIEM_TileQuality, &b_antikt4HIEM_TileQuality);
    fChain->SetBranchAddress("antikt4HIEM_const_n", &antikt4HIEM_const_n, &b_antikt4HIEM_const_n);
    fChain->SetBranchAddress("antikt4HIEM_const_et", &antikt4HIEM_const_et, &b_antikt4HIEM_const_et);
    fChain->SetBranchAddress("antikt4HIEM_const_eta", &antikt4HIEM_const_eta, &b_antikt4HIEM_const_eta);
    fChain->SetBranchAddress("antikt4HIEM_const_phi", &antikt4HIEM_const_phi, &b_antikt4HIEM_const_phi);
    fChain->SetBranchAddress("antikt4HIEM_sampling_et", &antikt4HIEM_sampling_et, &b_antikt4HIEM_sampling_et);
    fChain->SetBranchAddress("antikt4HIEM_sampling_et_unsubtr", &antikt4HIEM_sampling_et_unsubtr, &b_antikt4HIEM_sampling_et_unsubtr);
    fChain->SetBranchAddress("antikt4HIEM_bad_cell_n", &antikt4HIEM_bad_cell_n, &b_antikt4HIEM_bad_cell_n);
    fChain->SetBranchAddress("antikt4HIEM_bad_cell_et", &antikt4HIEM_bad_cell_et, &b_antikt4HIEM_bad_cell_et);
    fChain->SetBranchAddress("antikt4HIEM_bad_cell_area", &antikt4HIEM_bad_cell_area, &b_antikt4HIEM_bad_cell_area);
    fChain->SetBranchAddress("antikt4HIEM_empty_cell_n", &antikt4HIEM_empty_cell_n, &b_antikt4HIEM_empty_cell_n);
    fChain->SetBranchAddress("antikt4HIEM_empty_cell_et", &antikt4HIEM_empty_cell_et, &b_antikt4HIEM_empty_cell_et);
    fChain->SetBranchAddress("antikt4HIEM_empty_cell_area", &antikt4HIEM_empty_cell_area, &b_antikt4HIEM_empty_cell_area);
    fChain->SetBranchAddress("antikt4HIEM_total_cell_n", &antikt4HIEM_total_cell_n, &b_antikt4HIEM_total_cell_n);
    fChain->SetBranchAddress("antikt4HIEM_total_cell_et", &antikt4HIEM_total_cell_et, &b_antikt4HIEM_total_cell_et);
    fChain->SetBranchAddress("antikt4HIEM_total_cell_area", &antikt4HIEM_total_cell_area, &b_antikt4HIEM_total_cell_area);
    fChain->SetBranchAddress("jetSeed_n", &jetSeed_n, &b_jetSeed_n);
    fChain->SetBranchAddress("jetSeed_E", &jetSeed_E, &b_jetSeed_E);
    fChain->SetBranchAddress("jetSeed_pt", &jetSeed_pt, &b_jetSeed_pt);
    fChain->SetBranchAddress("jetSeed_m", &jetSeed_m, &b_jetSeed_m);
    fChain->SetBranchAddress("jetSeed_eta", &jetSeed_eta, &b_jetSeed_eta);
    fChain->SetBranchAddress("jetSeed_phi", &jetSeed_phi, &b_jetSeed_phi);
    fChain->SetBranchAddress("jetSeed3Sigma_n", &jetSeed3Sigma_n, &b_jetSeed3Sigma_n);
    fChain->SetBranchAddress("jetSeed3Sigma_E", &jetSeed3Sigma_E, &b_jetSeed3Sigma_E);
    fChain->SetBranchAddress("jetSeed3Sigma_pt", &jetSeed3Sigma_pt, &b_jetSeed3Sigma_pt);
    fChain->SetBranchAddress("jetSeed3Sigma_m", &jetSeed3Sigma_m, &b_jetSeed3Sigma_m);
    fChain->SetBranchAddress("jetSeed3Sigma_eta", &jetSeed3Sigma_eta, &b_jetSeed3Sigma_eta);
    fChain->SetBranchAddress("jetSeed3Sigma_phi", &jetSeed3Sigma_phi, &b_jetSeed3Sigma_phi);
    fChain->SetBranchAddress("jetSeed4Sigma_n", &jetSeed4Sigma_n, &b_jetSeed4Sigma_n);
    fChain->SetBranchAddress("jetSeed4Sigma_E", &jetSeed4Sigma_E, &b_jetSeed4Sigma_E);
    fChain->SetBranchAddress("jetSeed4Sigma_pt", &jetSeed4Sigma_pt, &b_jetSeed4Sigma_pt);
    fChain->SetBranchAddress("jetSeed4Sigma_m", &jetSeed4Sigma_m, &b_jetSeed4Sigma_m);
    fChain->SetBranchAddress("jetSeed4Sigma_eta", &jetSeed4Sigma_eta, &b_jetSeed4Sigma_eta);
    fChain->SetBranchAddress("jetSeed4Sigma_phi", &jetSeed4Sigma_phi, &b_jetSeed4Sigma_phi);
    fChain->SetBranchAddress("cone2HI_n", &cone2HI_n, &b_cone2HI_n);
    fChain->SetBranchAddress("cone2HI_E", &cone2HI_E, &b_cone2HI_E);
    fChain->SetBranchAddress("cone2HI_pt", &cone2HI_pt, &b_cone2HI_pt);
    fChain->SetBranchAddress("cone2HI_m", &cone2HI_m, &b_cone2HI_m);
    fChain->SetBranchAddress("cone2HI_eta", &cone2HI_eta, &b_cone2HI_eta);
    fChain->SetBranchAddress("cone2HI_phi", &cone2HI_phi, &b_cone2HI_phi);
    fChain->SetBranchAddress("cone2HI_MaxOverMean", &cone2HI_MaxOverMean, &b_cone2HI_MaxOverMean);
    fChain->SetBranchAddress("cone2HI_MeanTowerEt", &cone2HI_MeanTowerEt, &b_cone2HI_MeanTowerEt);
    fChain->SetBranchAddress("cone2HI_SubtractedEt", &cone2HI_SubtractedEt, &b_cone2HI_SubtractedEt);
    fChain->SetBranchAddress("cone2HI_RMSTowerEt", &cone2HI_RMSTowerEt, &b_cone2HI_RMSTowerEt);
    fChain->SetBranchAddress("cone2HI_SumJt", &cone2HI_SumJt, &b_cone2HI_SumJt);
    fChain->SetBranchAddress("cone2HI_CoreEt", &cone2HI_CoreEt, &b_cone2HI_CoreEt);
    fChain->SetBranchAddress("cone2HI_EdgeEt", &cone2HI_EdgeEt, &b_cone2HI_EdgeEt);
    fChain->SetBranchAddress("cone2HI_CryoCorr", &cone2HI_CryoCorr, &b_cone2HI_CryoCorr);
    fChain->SetBranchAddress("cone2HI_NoFlow", &cone2HI_NoFlow, &b_cone2HI_NoFlow);
    fChain->SetBranchAddress("cone2HI_NumConstituents", &cone2HI_NumConstituents, &b_cone2HI_NumConstituents);
    fChain->SetBranchAddress("cone2HI_UncalibEt", &cone2HI_UncalibEt, &b_cone2HI_UncalibEt);
    fChain->SetBranchAddress("cone2HI_Discriminant", &cone2HI_Discriminant, &b_cone2HI_Discriminant);
    fChain->SetBranchAddress("cone2HI_MeanTowerEtUnsubtr", &cone2HI_MeanTowerEtUnsubtr, &b_cone2HI_MeanTowerEtUnsubtr);
    fChain->SetBranchAddress("cone2HI_n90", &cone2HI_n90, &b_cone2HI_n90);
    fChain->SetBranchAddress("cone2HI_fracSamplingMax", &cone2HI_fracSamplingMax, &b_cone2HI_fracSamplingMax);
    fChain->SetBranchAddress("cone2HI_SamplingMax", &cone2HI_SamplingMax, &b_cone2HI_SamplingMax);
    fChain->SetBranchAddress("cone2HI_n90constituents", &cone2HI_n90constituents, &b_cone2HI_n90constituents);
    fChain->SetBranchAddress("cone2HI_Timing", &cone2HI_Timing, &b_cone2HI_Timing);
    fChain->SetBranchAddress("cone2HI_LArQuality", &cone2HI_LArQuality, &b_cone2HI_LArQuality);
    fChain->SetBranchAddress("cone2HI_HECQuality", &cone2HI_HECQuality, &b_cone2HI_HECQuality);
    fChain->SetBranchAddress("cone2HI_TileQuality", &cone2HI_TileQuality, &b_cone2HI_TileQuality);
    fChain->SetBranchAddress("cone2HI_const_n", &cone2HI_const_n, &b_cone2HI_const_n);
    fChain->SetBranchAddress("cone2HI_const_et", &cone2HI_const_et, &b_cone2HI_const_et);
    fChain->SetBranchAddress("cone2HI_const_eta", &cone2HI_const_eta, &b_cone2HI_const_eta);
    fChain->SetBranchAddress("cone2HI_const_phi", &cone2HI_const_phi, &b_cone2HI_const_phi);
    fChain->SetBranchAddress("cone2HI_sampling_et", &cone2HI_sampling_et, &b_cone2HI_sampling_et);
    fChain->SetBranchAddress("cone2HI_sampling_et_unsubtr", &cone2HI_sampling_et_unsubtr, &b_cone2HI_sampling_et_unsubtr);
    fChain->SetBranchAddress("cone2HI_bad_cell_n", &cone2HI_bad_cell_n, &b_cone2HI_bad_cell_n);
    fChain->SetBranchAddress("cone2HI_bad_cell_et", &cone2HI_bad_cell_et, &b_cone2HI_bad_cell_et);
    fChain->SetBranchAddress("cone2HI_bad_cell_area", &cone2HI_bad_cell_area, &b_cone2HI_bad_cell_area);
    fChain->SetBranchAddress("cone2HI_empty_cell_n", &cone2HI_empty_cell_n, &b_cone2HI_empty_cell_n);
    fChain->SetBranchAddress("cone2HI_empty_cell_et", &cone2HI_empty_cell_et, &b_cone2HI_empty_cell_et);
    fChain->SetBranchAddress("cone2HI_empty_cell_area", &cone2HI_empty_cell_area, &b_cone2HI_empty_cell_area);
    fChain->SetBranchAddress("cone2HI_total_cell_n", &cone2HI_total_cell_n, &b_cone2HI_total_cell_n);
    fChain->SetBranchAddress("cone2HI_total_cell_et", &cone2HI_total_cell_et, &b_cone2HI_total_cell_et);
    fChain->SetBranchAddress("cone2HI_total_cell_area", &cone2HI_total_cell_area, &b_cone2HI_total_cell_area);
    fChain->SetBranchAddress("cone4HI_n", &cone4HI_n, &b_cone4HI_n);
    fChain->SetBranchAddress("cone4HI_E", &cone4HI_E, &b_cone4HI_E);
    fChain->SetBranchAddress("cone4HI_pt", &cone4HI_pt, &b_cone4HI_pt);
    fChain->SetBranchAddress("cone4HI_m", &cone4HI_m, &b_cone4HI_m);
    fChain->SetBranchAddress("cone4HI_eta", &cone4HI_eta, &b_cone4HI_eta);
    fChain->SetBranchAddress("cone4HI_phi", &cone4HI_phi, &b_cone4HI_phi);
    fChain->SetBranchAddress("cone4HI_MaxOverMean", &cone4HI_MaxOverMean, &b_cone4HI_MaxOverMean);
    fChain->SetBranchAddress("cone4HI_MeanTowerEt", &cone4HI_MeanTowerEt, &b_cone4HI_MeanTowerEt);
    fChain->SetBranchAddress("cone4HI_SubtractedEt", &cone4HI_SubtractedEt, &b_cone4HI_SubtractedEt);
    fChain->SetBranchAddress("cone4HI_RMSTowerEt", &cone4HI_RMSTowerEt, &b_cone4HI_RMSTowerEt);
    fChain->SetBranchAddress("cone4HI_SumJt", &cone4HI_SumJt, &b_cone4HI_SumJt);
    fChain->SetBranchAddress("cone4HI_CoreEt", &cone4HI_CoreEt, &b_cone4HI_CoreEt);
    fChain->SetBranchAddress("cone4HI_EdgeEt", &cone4HI_EdgeEt, &b_cone4HI_EdgeEt);
    fChain->SetBranchAddress("cone4HI_CryoCorr", &cone4HI_CryoCorr, &b_cone4HI_CryoCorr);
    fChain->SetBranchAddress("cone4HI_NoFlow", &cone4HI_NoFlow, &b_cone4HI_NoFlow);
    fChain->SetBranchAddress("cone4HI_NumConstituents", &cone4HI_NumConstituents, &b_cone4HI_NumConstituents);
    fChain->SetBranchAddress("cone4HI_UncalibEt", &cone4HI_UncalibEt, &b_cone4HI_UncalibEt);
    fChain->SetBranchAddress("cone4HI_Discriminant", &cone4HI_Discriminant, &b_cone4HI_Discriminant);
    fChain->SetBranchAddress("cone4HI_MeanTowerEtUnsubtr", &cone4HI_MeanTowerEtUnsubtr, &b_cone4HI_MeanTowerEtUnsubtr);
    fChain->SetBranchAddress("cone4HI_n90", &cone4HI_n90, &b_cone4HI_n90);
    fChain->SetBranchAddress("cone4HI_fracSamplingMax", &cone4HI_fracSamplingMax, &b_cone4HI_fracSamplingMax);
    fChain->SetBranchAddress("cone4HI_SamplingMax", &cone4HI_SamplingMax, &b_cone4HI_SamplingMax);
    fChain->SetBranchAddress("cone4HI_n90constituents", &cone4HI_n90constituents, &b_cone4HI_n90constituents);
    fChain->SetBranchAddress("cone4HI_Timing", &cone4HI_Timing, &b_cone4HI_Timing);
    fChain->SetBranchAddress("cone4HI_LArQuality", &cone4HI_LArQuality, &b_cone4HI_LArQuality);
    fChain->SetBranchAddress("cone4HI_HECQuality", &cone4HI_HECQuality, &b_cone4HI_HECQuality);
    fChain->SetBranchAddress("cone4HI_TileQuality", &cone4HI_TileQuality, &b_cone4HI_TileQuality);
    fChain->SetBranchAddress("cone4HI_const_n", &cone4HI_const_n, &b_cone4HI_const_n);
    fChain->SetBranchAddress("cone4HI_const_et", &cone4HI_const_et, &b_cone4HI_const_et);
    fChain->SetBranchAddress("cone4HI_const_eta", &cone4HI_const_eta, &b_cone4HI_const_eta);
    fChain->SetBranchAddress("cone4HI_const_phi", &cone4HI_const_phi, &b_cone4HI_const_phi);
    fChain->SetBranchAddress("cone4HI_sampling_et", &cone4HI_sampling_et, &b_cone4HI_sampling_et);
    fChain->SetBranchAddress("cone4HI_sampling_et_unsubtr", &cone4HI_sampling_et_unsubtr, &b_cone4HI_sampling_et_unsubtr);
    fChain->SetBranchAddress("cone4HI_bad_cell_n", &cone4HI_bad_cell_n, &b_cone4HI_bad_cell_n);
    fChain->SetBranchAddress("cone4HI_bad_cell_et", &cone4HI_bad_cell_et, &b_cone4HI_bad_cell_et);
    fChain->SetBranchAddress("cone4HI_bad_cell_area", &cone4HI_bad_cell_area, &b_cone4HI_bad_cell_area);
    fChain->SetBranchAddress("cone4HI_empty_cell_n", &cone4HI_empty_cell_n, &b_cone4HI_empty_cell_n);
    fChain->SetBranchAddress("cone4HI_empty_cell_et", &cone4HI_empty_cell_et, &b_cone4HI_empty_cell_et);
    fChain->SetBranchAddress("cone4HI_empty_cell_area", &cone4HI_empty_cell_area, &b_cone4HI_empty_cell_area);
    fChain->SetBranchAddress("cone4HI_total_cell_n", &cone4HI_total_cell_n, &b_cone4HI_total_cell_n);
    fChain->SetBranchAddress("cone4HI_total_cell_et", &cone4HI_total_cell_et, &b_cone4HI_total_cell_et);
    fChain->SetBranchAddress("cone4HI_total_cell_area", &cone4HI_total_cell_area, &b_cone4HI_total_cell_area);
    fChain->SetBranchAddress("cone6HI_n", &cone6HI_n, &b_cone6HI_n);
    fChain->SetBranchAddress("cone6HI_E", &cone6HI_E, &b_cone6HI_E);
    fChain->SetBranchAddress("cone6HI_pt", &cone6HI_pt, &b_cone6HI_pt);
    fChain->SetBranchAddress("cone6HI_m", &cone6HI_m, &b_cone6HI_m);
    fChain->SetBranchAddress("cone6HI_eta", &cone6HI_eta, &b_cone6HI_eta);
    fChain->SetBranchAddress("cone6HI_phi", &cone6HI_phi, &b_cone6HI_phi);
    fChain->SetBranchAddress("cone6HI_MaxOverMean", &cone6HI_MaxOverMean, &b_cone6HI_MaxOverMean);
    fChain->SetBranchAddress("cone6HI_MeanTowerEt", &cone6HI_MeanTowerEt, &b_cone6HI_MeanTowerEt);
    fChain->SetBranchAddress("cone6HI_SubtractedEt", &cone6HI_SubtractedEt, &b_cone6HI_SubtractedEt);
    fChain->SetBranchAddress("cone6HI_RMSTowerEt", &cone6HI_RMSTowerEt, &b_cone6HI_RMSTowerEt);
    fChain->SetBranchAddress("cone6HI_SumJt", &cone6HI_SumJt, &b_cone6HI_SumJt);
    fChain->SetBranchAddress("cone6HI_CoreEt", &cone6HI_CoreEt, &b_cone6HI_CoreEt);
    fChain->SetBranchAddress("cone6HI_EdgeEt", &cone6HI_EdgeEt, &b_cone6HI_EdgeEt);
    fChain->SetBranchAddress("cone6HI_CryoCorr", &cone6HI_CryoCorr, &b_cone6HI_CryoCorr);
    fChain->SetBranchAddress("cone6HI_NoFlow", &cone6HI_NoFlow, &b_cone6HI_NoFlow);
    fChain->SetBranchAddress("cone6HI_NumConstituents", &cone6HI_NumConstituents, &b_cone6HI_NumConstituents);
    fChain->SetBranchAddress("cone6HI_UncalibEt", &cone6HI_UncalibEt, &b_cone6HI_UncalibEt);
    fChain->SetBranchAddress("cone6HI_Discriminant", &cone6HI_Discriminant, &b_cone6HI_Discriminant);
    fChain->SetBranchAddress("cone6HI_MeanTowerEtUnsubtr", &cone6HI_MeanTowerEtUnsubtr, &b_cone6HI_MeanTowerEtUnsubtr);
    fChain->SetBranchAddress("cone6HI_n90", &cone6HI_n90, &b_cone6HI_n90);
    fChain->SetBranchAddress("cone6HI_fracSamplingMax", &cone6HI_fracSamplingMax, &b_cone6HI_fracSamplingMax);
    fChain->SetBranchAddress("cone6HI_SamplingMax", &cone6HI_SamplingMax, &b_cone6HI_SamplingMax);
    fChain->SetBranchAddress("cone6HI_n90constituents", &cone6HI_n90constituents, &b_cone6HI_n90constituents);
    fChain->SetBranchAddress("cone6HI_Timing", &cone6HI_Timing, &b_cone6HI_Timing);
    fChain->SetBranchAddress("cone6HI_LArQuality", &cone6HI_LArQuality, &b_cone6HI_LArQuality);
    fChain->SetBranchAddress("cone6HI_HECQuality", &cone6HI_HECQuality, &b_cone6HI_HECQuality);
    fChain->SetBranchAddress("cone6HI_TileQuality", &cone6HI_TileQuality, &b_cone6HI_TileQuality);
    fChain->SetBranchAddress("cone6HI_const_n", &cone6HI_const_n, &b_cone6HI_const_n);
    fChain->SetBranchAddress("cone6HI_const_et", &cone6HI_const_et, &b_cone6HI_const_et);
    fChain->SetBranchAddress("cone6HI_const_eta", &cone6HI_const_eta, &b_cone6HI_const_eta);
    fChain->SetBranchAddress("cone6HI_const_phi", &cone6HI_const_phi, &b_cone6HI_const_phi);
    fChain->SetBranchAddress("cone6HI_sampling_et", &cone6HI_sampling_et, &b_cone6HI_sampling_et);
    fChain->SetBranchAddress("cone6HI_sampling_et_unsubtr", &cone6HI_sampling_et_unsubtr, &b_cone6HI_sampling_et_unsubtr);
    fChain->SetBranchAddress("cone6HI_bad_cell_n", &cone6HI_bad_cell_n, &b_cone6HI_bad_cell_n);
    fChain->SetBranchAddress("cone6HI_bad_cell_et", &cone6HI_bad_cell_et, &b_cone6HI_bad_cell_et);
    fChain->SetBranchAddress("cone6HI_bad_cell_area", &cone6HI_bad_cell_area, &b_cone6HI_bad_cell_area);
    fChain->SetBranchAddress("cone6HI_empty_cell_n", &cone6HI_empty_cell_n, &b_cone6HI_empty_cell_n);
    fChain->SetBranchAddress("cone6HI_empty_cell_et", &cone6HI_empty_cell_et, &b_cone6HI_empty_cell_et);
    fChain->SetBranchAddress("cone6HI_empty_cell_area", &cone6HI_empty_cell_area, &b_cone6HI_empty_cell_area);
    fChain->SetBranchAddress("cone6HI_total_cell_n", &cone6HI_total_cell_n, &b_cone6HI_total_cell_n);
    fChain->SetBranchAddress("cone6HI_total_cell_et", &cone6HI_total_cell_et, &b_cone6HI_total_cell_et);
    fChain->SetBranchAddress("cone6HI_total_cell_area", &cone6HI_total_cell_area, &b_cone6HI_total_cell_area);
    fChain->SetBranchAddress("CMSCone4HI_n", &CMSCone4HI_n, &b_CMSCone4HI_n);
    fChain->SetBranchAddress("CMSCone4HI_E", &CMSCone4HI_E, &b_CMSCone4HI_E);
    fChain->SetBranchAddress("CMSCone4HI_pt", &CMSCone4HI_pt, &b_CMSCone4HI_pt);
    fChain->SetBranchAddress("CMSCone4HI_m", &CMSCone4HI_m, &b_CMSCone4HI_m);
    fChain->SetBranchAddress("CMSCone4HI_eta", &CMSCone4HI_eta, &b_CMSCone4HI_eta);
    fChain->SetBranchAddress("CMSCone4HI_phi", &CMSCone4HI_phi, &b_CMSCone4HI_phi);
    fChain->SetBranchAddress("CMSCone4HI_MaxOverMean", &CMSCone4HI_MaxOverMean, &b_CMSCone4HI_MaxOverMean);
    fChain->SetBranchAddress("CMSCone4HI_MeanTowerEt", &CMSCone4HI_MeanTowerEt, &b_CMSCone4HI_MeanTowerEt);
    fChain->SetBranchAddress("CMSCone4HI_SubtractedEt", &CMSCone4HI_SubtractedEt, &b_CMSCone4HI_SubtractedEt);
    fChain->SetBranchAddress("CMSCone4HI_RMSTowerEt", &CMSCone4HI_RMSTowerEt, &b_CMSCone4HI_RMSTowerEt);
    fChain->SetBranchAddress("CMSCone4HI_SumJt", &CMSCone4HI_SumJt, &b_CMSCone4HI_SumJt);
    fChain->SetBranchAddress("CMSCone4HI_CoreEt", &CMSCone4HI_CoreEt, &b_CMSCone4HI_CoreEt);
    fChain->SetBranchAddress("CMSCone4HI_EdgeEt", &CMSCone4HI_EdgeEt, &b_CMSCone4HI_EdgeEt);
    fChain->SetBranchAddress("CMSCone4HI_CryoCorr", &CMSCone4HI_CryoCorr, &b_CMSCone4HI_CryoCorr);
    fChain->SetBranchAddress("CMSCone4HI_NoFlow", &CMSCone4HI_NoFlow, &b_CMSCone4HI_NoFlow);
    fChain->SetBranchAddress("CMSCone4HI_NumConstituents", &CMSCone4HI_NumConstituents, &b_CMSCone4HI_NumConstituents);
    fChain->SetBranchAddress("CMSCone4HI_UncalibEt", &CMSCone4HI_UncalibEt, &b_CMSCone4HI_UncalibEt);
    fChain->SetBranchAddress("CMSCone4HI_Discriminant", &CMSCone4HI_Discriminant, &b_CMSCone4HI_Discriminant);
    fChain->SetBranchAddress("CMSCone4HI_MeanTowerEtUnsubtr", &CMSCone4HI_MeanTowerEtUnsubtr, &b_CMSCone4HI_MeanTowerEtUnsubtr);
    fChain->SetBranchAddress("CMSCone4HI_n90", &CMSCone4HI_n90, &b_CMSCone4HI_n90);
    fChain->SetBranchAddress("CMSCone4HI_fracSamplingMax", &CMSCone4HI_fracSamplingMax, &b_CMSCone4HI_fracSamplingMax);
    fChain->SetBranchAddress("CMSCone4HI_SamplingMax", &CMSCone4HI_SamplingMax, &b_CMSCone4HI_SamplingMax);
    fChain->SetBranchAddress("CMSCone4HI_n90constituents", &CMSCone4HI_n90constituents, &b_CMSCone4HI_n90constituents);
    fChain->SetBranchAddress("CMSCone4HI_Timing", &CMSCone4HI_Timing, &b_CMSCone4HI_Timing);
    fChain->SetBranchAddress("CMSCone4HI_LArQuality", &CMSCone4HI_LArQuality, &b_CMSCone4HI_LArQuality);
    fChain->SetBranchAddress("CMSCone4HI_HECQuality", &CMSCone4HI_HECQuality, &b_CMSCone4HI_HECQuality);
    fChain->SetBranchAddress("CMSCone4HI_TileQuality", &CMSCone4HI_TileQuality, &b_CMSCone4HI_TileQuality);
    fChain->SetBranchAddress("CMSCone4HI_const_n", &CMSCone4HI_const_n, &b_CMSCone4HI_const_n);
    fChain->SetBranchAddress("CMSCone4HI_const_et", &CMSCone4HI_const_et, &b_CMSCone4HI_const_et);
    fChain->SetBranchAddress("CMSCone4HI_const_eta", &CMSCone4HI_const_eta, &b_CMSCone4HI_const_eta);
    fChain->SetBranchAddress("CMSCone4HI_const_phi", &CMSCone4HI_const_phi, &b_CMSCone4HI_const_phi);
    fChain->SetBranchAddress("CMSCone4HI_sampling_et", &CMSCone4HI_sampling_et, &b_CMSCone4HI_sampling_et);
    fChain->SetBranchAddress("CMSCone4HI_sampling_et_unsubtr", &CMSCone4HI_sampling_et_unsubtr, &b_CMSCone4HI_sampling_et_unsubtr);
    fChain->SetBranchAddress("CMSCone4HI_bad_cell_n", &CMSCone4HI_bad_cell_n, &b_CMSCone4HI_bad_cell_n);
    fChain->SetBranchAddress("CMSCone4HI_bad_cell_et", &CMSCone4HI_bad_cell_et, &b_CMSCone4HI_bad_cell_et);
    fChain->SetBranchAddress("CMSCone4HI_bad_cell_area", &CMSCone4HI_bad_cell_area, &b_CMSCone4HI_bad_cell_area);
    fChain->SetBranchAddress("CMSCone4HI_empty_cell_n", &CMSCone4HI_empty_cell_n, &b_CMSCone4HI_empty_cell_n);
    fChain->SetBranchAddress("CMSCone4HI_empty_cell_et", &CMSCone4HI_empty_cell_et, &b_CMSCone4HI_empty_cell_et);
    fChain->SetBranchAddress("CMSCone4HI_empty_cell_area", &CMSCone4HI_empty_cell_area, &b_CMSCone4HI_empty_cell_area);
    fChain->SetBranchAddress("CMSCone4HI_total_cell_n", &CMSCone4HI_total_cell_n, &b_CMSCone4HI_total_cell_n);
    fChain->SetBranchAddress("CMSCone4HI_total_cell_et", &CMSCone4HI_total_cell_et, &b_CMSCone4HI_total_cell_et);
    fChain->SetBranchAddress("CMSCone4HI_total_cell_area", &CMSCone4HI_total_cell_area, &b_CMSCone4HI_total_cell_area);
    fChain->SetBranchAddress("antikt4Track_n", &antikt4Track_n, &b_antikt4Track_n);
    fChain->SetBranchAddress("antikt4Track_E", &antikt4Track_E, &b_antikt4Track_E);
    fChain->SetBranchAddress("antikt4Track_pt", &antikt4Track_pt, &b_antikt4Track_pt);
    fChain->SetBranchAddress("antikt4Track_m", &antikt4Track_m, &b_antikt4Track_m);
    fChain->SetBranchAddress("antikt4Track_eta", &antikt4Track_eta, &b_antikt4Track_eta);
    fChain->SetBranchAddress("antikt4Track_phi", &antikt4Track_phi, &b_antikt4Track_phi);
    fChain->SetBranchAddress("antikt4Track_const_n", &antikt4Track_const_n, &b_antikt4Track_const_n);
    fChain->SetBranchAddress("antikt4Track_const_pt", &antikt4Track_const_pt, &b_antikt4Track_const_pt);
    fChain->SetBranchAddress("antikt4Track_const_eta", &antikt4Track_const_eta, &b_antikt4Track_const_eta);
    fChain->SetBranchAddress("antikt4Track_const_phi", &antikt4Track_const_phi, &b_antikt4Track_const_phi);
    fChain->SetBranchAddress("antikt4Track_const_chi2", &antikt4Track_const_chi2, &b_antikt4Track_const_chi2);
    fChain->SetBranchAddress("antikt4Track_const_d0_wrtPV", &antikt4Track_const_d0_wrtPV, &b_antikt4Track_const_d0_wrtPV);
    fChain->SetBranchAddress("antikt4Track_const_z0_wrtPV", &antikt4Track_const_z0_wrtPV, &b_antikt4Track_const_z0_wrtPV);
    fChain->SetBranchAddress("antikt4Track_const_phi0_wrtPV", &antikt4Track_const_phi0_wrtPV, &b_antikt4Track_const_phi0_wrtPV);
    fChain->SetBranchAddress("antikt4Track_const_theta_wrtPV", &antikt4Track_const_theta_wrtPV, &b_antikt4Track_const_theta_wrtPV);
    fChain->SetBranchAddress("antikt4Track_const_qop", &antikt4Track_const_qop, &b_antikt4Track_const_qop);
    fChain->SetBranchAddress("antikt4Track_const_ndof", &antikt4Track_const_ndof, &b_antikt4Track_const_ndof);
    fChain->SetBranchAddress("antikt4Track_const_nBLayerHits", &antikt4Track_const_nBLayerHits, &b_antikt4Track_const_nBLayerHits);
    fChain->SetBranchAddress("antikt4Track_const_nPixelHits", &antikt4Track_const_nPixelHits, &b_antikt4Track_const_nPixelHits);
    fChain->SetBranchAddress("antikt4Track_const_nSCTHits", &antikt4Track_const_nSCTHits, &b_antikt4Track_const_nSCTHits);
    fChain->SetBranchAddress("antikt4Track_const_nTRTHits", &antikt4Track_const_nTRTHits, &b_antikt4Track_const_nTRTHits);
    fChain->SetBranchAddress("antikt6Track_n", &antikt6Track_n, &b_antikt6Track_n);
    fChain->SetBranchAddress("antikt6Track_E", &antikt6Track_E, &b_antikt6Track_E);
    fChain->SetBranchAddress("antikt6Track_pt", &antikt6Track_pt, &b_antikt6Track_pt);
    fChain->SetBranchAddress("antikt6Track_m", &antikt6Track_m, &b_antikt6Track_m);
    fChain->SetBranchAddress("antikt6Track_eta", &antikt6Track_eta, &b_antikt6Track_eta);
    fChain->SetBranchAddress("antikt6Track_phi", &antikt6Track_phi, &b_antikt6Track_phi);
    fChain->SetBranchAddress("antikt6Track_const_n", &antikt6Track_const_n, &b_antikt6Track_const_n);
    fChain->SetBranchAddress("antikt6Track_const_pt", &antikt6Track_const_pt, &b_antikt6Track_const_pt);
    fChain->SetBranchAddress("antikt6Track_const_eta", &antikt6Track_const_eta, &b_antikt6Track_const_eta);
    fChain->SetBranchAddress("antikt6Track_const_phi", &antikt6Track_const_phi, &b_antikt6Track_const_phi);
    fChain->SetBranchAddress("antikt6Track_const_chi2", &antikt6Track_const_chi2, &b_antikt6Track_const_chi2);
    fChain->SetBranchAddress("antikt6Track_const_d0_wrtPV", &antikt6Track_const_d0_wrtPV, &b_antikt6Track_const_d0_wrtPV);
    fChain->SetBranchAddress("antikt6Track_const_z0_wrtPV", &antikt6Track_const_z0_wrtPV, &b_antikt6Track_const_z0_wrtPV);
    fChain->SetBranchAddress("antikt6Track_const_phi0_wrtPV", &antikt6Track_const_phi0_wrtPV, &b_antikt6Track_const_phi0_wrtPV);
    fChain->SetBranchAddress("antikt6Track_const_theta_wrtPV", &antikt6Track_const_theta_wrtPV, &b_antikt6Track_const_theta_wrtPV);
    fChain->SetBranchAddress("antikt6Track_const_qop", &antikt6Track_const_qop, &b_antikt6Track_const_qop);
    fChain->SetBranchAddress("antikt6Track_const_ndof", &antikt6Track_const_ndof, &b_antikt6Track_const_ndof);
    fChain->SetBranchAddress("antikt6Track_const_nBLayerHits", &antikt6Track_const_nBLayerHits, &b_antikt6Track_const_nBLayerHits);
    fChain->SetBranchAddress("antikt6Track_const_nPixelHits", &antikt6Track_const_nPixelHits, &b_antikt6Track_const_nPixelHits);
    fChain->SetBranchAddress("antikt6Track_const_nSCTHits", &antikt6Track_const_nSCTHits, &b_antikt6Track_const_nSCTHits);
    fChain->SetBranchAddress("antikt6Track_const_nTRTHits", &antikt6Track_const_nTRTHits, &b_antikt6Track_const_nTRTHits);
    fChain->SetBranchAddress("HICentrality_b_bin", &HICentrality_b_bin, &b_HICentrality_b_bin);
    fChain->SetBranchAddress("HICentrality_nw_bin", &HICentrality_nw_bin, &b_HICentrality_nw_bin);
    fChain->SetBranchAddress("HICentrality_ncoll_bin", &HICentrality_ncoll_bin, &b_HICentrality_ncoll_bin);
    fChain->SetBranchAddress("HICentrality_calocell_energy_bin", &HICentrality_calocell_energy_bin, &b_HICentrality_calocell_energy_bin);
    fChain->SetBranchAddress("HICentrality_number_of_siclusters_bin", &HICentrality_number_of_siclusters_bin, &b_HICentrality_number_of_siclusters_bin);
    fChain->SetBranchAddress("HICentrality_b_var", &HICentrality_b_var, &b_HICentrality_b_var);
    fChain->SetBranchAddress("HICentrality_nw_var", &HICentrality_nw_var, &b_HICentrality_nw_var);
    fChain->SetBranchAddress("HICentrality_ncoll_var", &HICentrality_ncoll_var, &b_HICentrality_ncoll_var);
    fChain->SetBranchAddress("HICentrality_calocell_energy_var", &HICentrality_calocell_energy_var, &b_HICentrality_calocell_energy_var);
    fChain->SetBranchAddress("HICentrality_number_of_siclusters_var", &HICentrality_number_of_siclusters_var, &b_HICentrality_number_of_siclusters_var);
    fChain->SetBranchAddress("HIFlow_PsiHICaloUtilLayers", &HIFlow_PsiHICaloUtilLayers, &b_HIFlow_PsiHICaloUtilLayers);
    fChain->SetBranchAddress("HIFlow_PsiEtHICaloUtilLayers", &HIFlow_PsiEtHICaloUtilLayers, &b_HIFlow_PsiEtHICaloUtilLayers);
    fChain->SetBranchAddress("HIFlow_PsiPtrack", &HIFlow_PsiPtrack, &b_HIFlow_PsiPtrack);
    fChain->SetBranchAddress("HIFlow_PsiNtrack", &HIFlow_PsiNtrack, &b_HIFlow_PsiNtrack);
    fChain->SetBranchAddress("HIFlow_v2EMB1sil", &HIFlow_v2EMB1sil, &b_HIFlow_v2EMB1sil);
    fChain->SetBranchAddress("HIFlow_v2FCAL0sil", &HIFlow_v2FCAL0sil, &b_HIFlow_v2FCAL0sil);
    fChain->SetBranchAddress("HIFlow_v2track", &HIFlow_v2track, &b_HIFlow_v2track);
    fChain->SetBranchAddress("HIFlow_PsiFCAL0_w", &HIFlow_PsiFCAL0_w, &b_HIFlow_PsiFCAL0_w);
    fChain->SetBranchAddress("HIFlow_PsiPFCAL0_w", &HIFlow_PsiPFCAL0_w, &b_HIFlow_PsiPFCAL0_w);
    fChain->SetBranchAddress("HIFlow_PsiNFCAL0_w", &HIFlow_PsiNFCAL0_w, &b_HIFlow_PsiNFCAL0_w);
    fChain->SetBranchAddress("HIFlow_Meanv2_Psi_From_EMB1CaloCel_IDLayers", &HIFlow_Meanv2_Psi_From_EMB1CaloCel_IDLayers, &b_HIFlow_Meanv2_Psi_From_EMB1CaloCel_IDLayers);
    fChain->SetBranchAddress("HIFlow_Meanv2_Psi_From_FCAL0CaloCel_IDLayers", &HIFlow_Meanv2_Psi_From_FCAL0CaloCel_IDLayers, &b_HIFlow_Meanv2_Psi_From_FCAL0CaloCel_IDLayers);
    fChain->SetBranchAddress("HIFlow_Meanv2Et_Psi_From_EMB1CaloCel_IDLayers", &HIFlow_Meanv2Et_Psi_From_EMB1CaloCel_IDLayers, &b_HIFlow_Meanv2Et_Psi_From_EMB1CaloCel_IDLayers);
    fChain->SetBranchAddress("HIFlow_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers", &HIFlow_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers, &b_HIFlow_Meanv2Et_Psi_From_FCAL0CaloCel_IDLayers);
    fChain->SetBranchAddress("HIFlow_v2Eta_Psi_From_EMBP1_InDet_EMBN1", &HIFlow_v2Eta_Psi_From_EMBP1_InDet_EMBN1, &b_HIFlow_v2Eta_Psi_From_EMBP1_InDet_EMBN1);
    fChain->SetBranchAddress("HIFlow_v2Eta_Psi_From_EMBN1_InDet_EMBP1", &HIFlow_v2Eta_Psi_From_EMBN1_InDet_EMBP1, &b_HIFlow_v2Eta_Psi_From_EMBN1_InDet_EMBP1);
    fChain->SetBranchAddress("HIFlow_v2Eta_Psi_From_EMBP1_InDet_FCALN0", &HIFlow_v2Eta_Psi_From_EMBP1_InDet_FCALN0, &b_HIFlow_v2Eta_Psi_From_EMBP1_InDet_FCALN0);
    fChain->SetBranchAddress("HIFlow_v2Eta_Psi_From_EMBN1_InDet_FCALP0", &HIFlow_v2Eta_Psi_From_EMBN1_InDet_FCALP0, &b_HIFlow_v2Eta_Psi_From_EMBN1_InDet_FCALP0);
    fChain->SetBranchAddress("HIFlow_v2Eta_Psi_From_FCALN0_InDet_EMBN1", &HIFlow_v2Eta_Psi_From_FCALN0_InDet_EMBN1, &b_HIFlow_v2Eta_Psi_From_FCALN0_InDet_EMBN1);
    fChain->SetBranchAddress("HIFlow_v2Eta_Psi_From_FCALP0_InDet_EMBP1", &HIFlow_v2Eta_Psi_From_FCALP0_InDet_EMBP1, &b_HIFlow_v2Eta_Psi_From_FCALP0_InDet_EMBP1);
    fChain->SetBranchAddress("HIFlow_v2Eta_Psi_From_FCALP0_InDet_FCALN0", &HIFlow_v2Eta_Psi_From_FCALP0_InDet_FCALN0, &b_HIFlow_v2Eta_Psi_From_FCALP0_InDet_FCALN0);
    fChain->SetBranchAddress("HIFlow_v2Eta_Psi_From_FCALN0_InDet_FCALP0", &HIFlow_v2Eta_Psi_From_FCALN0_InDet_FCALP0, &b_HIFlow_v2Eta_Psi_From_FCALN0_InDet_FCALP0);
    fChain->SetBranchAddress("HIFlow_v2EtaEt_Psi_From_EMBP1_InDet_EMBN1", &HIFlow_v2EtaEt_Psi_From_EMBP1_InDet_EMBN1, &b_HIFlow_v2EtaEt_Psi_From_EMBP1_InDet_EMBN1);
    fChain->SetBranchAddress("HIFlow_v2EtaEt_Psi_From_EMBN1_InDet_EMBP1", &HIFlow_v2EtaEt_Psi_From_EMBN1_InDet_EMBP1, &b_HIFlow_v2EtaEt_Psi_From_EMBN1_InDet_EMBP1);
    fChain->SetBranchAddress("HIFlow_v2EtaEt_Psi_From_EMBP1_InDet_FCALN0", &HIFlow_v2EtaEt_Psi_From_EMBP1_InDet_FCALN0, &b_HIFlow_v2EtaEt_Psi_From_EMBP1_InDet_FCALN0);
    fChain->SetBranchAddress("HIFlow_v2EtaEt_Psi_From_EMBN1_InDet_FCALP0", &HIFlow_v2EtaEt_Psi_From_EMBN1_InDet_FCALP0, &b_HIFlow_v2EtaEt_Psi_From_EMBN1_InDet_FCALP0);
    fChain->SetBranchAddress("HIFlow_v2EtaEt_Psi_From_FCALN0_InDet_EMBN1", &HIFlow_v2EtaEt_Psi_From_FCALN0_InDet_EMBN1, &b_HIFlow_v2EtaEt_Psi_From_FCALN0_InDet_EMBN1);
    fChain->SetBranchAddress("HIFlow_v2EtaEt_Psi_From_FCALP0_InDet_EMBP1", &HIFlow_v2EtaEt_Psi_From_FCALP0_InDet_EMBP1, &b_HIFlow_v2EtaEt_Psi_From_FCALP0_InDet_EMBP1);
    fChain->SetBranchAddress("HIFlow_v2EtaEt_Psi_From_FCALP0_InDet_FCALN0", &HIFlow_v2EtaEt_Psi_From_FCALP0_InDet_FCALN0, &b_HIFlow_v2EtaEt_Psi_From_FCALP0_InDet_FCALN0);
    fChain->SetBranchAddress("HIFlow_v2EtaEt_Psi_From_FCALN0_InDet_FCALP0", &HIFlow_v2EtaEt_Psi_From_FCALN0_InDet_FCALP0, &b_HIFlow_v2EtaEt_Psi_From_FCALN0_InDet_FCALP0);
    fChain->SetBranchAddress("HIFlow_EtaEMBN1", &HIFlow_EtaEMBN1, &b_HIFlow_EtaEMBN1);
    fChain->SetBranchAddress("HIFlow_EtaEMBP1", &HIFlow_EtaEMBP1, &b_HIFlow_EtaEMBP1);
    fChain->SetBranchAddress("HIFlow_EtaFCALN0", &HIFlow_EtaFCALN0, &b_HIFlow_EtaFCALN0);
    fChain->SetBranchAddress("HIFlow_EtaFCALP0", &HIFlow_EtaFCALP0, &b_HIFlow_EtaFCALP0);
    fChain->SetBranchAddress("emcl_n", &emcl_n, &b_emcl_n);
    fChain->SetBranchAddress("emcl_E", &emcl_E, &b_emcl_E);
    fChain->SetBranchAddress("emcl_pt", &emcl_pt, &b_emcl_pt);
    fChain->SetBranchAddress("emcl_m", &emcl_m, &b_emcl_m);
    fChain->SetBranchAddress("emcl_eta", &emcl_eta, &b_emcl_eta);
    fChain->SetBranchAddress("emcl_phi", &emcl_phi, &b_emcl_phi);
    fChain->SetBranchAddress("emcl_E_em", &emcl_E_em, &b_emcl_E_em);
    fChain->SetBranchAddress("emcl_E_had", &emcl_E_had, &b_emcl_E_had);
    fChain->SetBranchAddress("mu_staco_n", &mu_staco_n, &b_mu_staco_n);
    fChain->SetBranchAddress("mu_staco_E", &mu_staco_E, &b_mu_staco_E);
    fChain->SetBranchAddress("mu_staco_pt", &mu_staco_pt, &b_mu_staco_pt);
    fChain->SetBranchAddress("mu_staco_m", &mu_staco_m, &b_mu_staco_m);
    fChain->SetBranchAddress("mu_staco_eta", &mu_staco_eta, &b_mu_staco_eta);
    fChain->SetBranchAddress("mu_staco_phi", &mu_staco_phi, &b_mu_staco_phi);
    fChain->SetBranchAddress("mu_staco_px", &mu_staco_px, &b_mu_staco_px);
    fChain->SetBranchAddress("mu_staco_py", &mu_staco_py, &b_mu_staco_py);
    fChain->SetBranchAddress("mu_staco_pz", &mu_staco_pz, &b_mu_staco_pz);
    fChain->SetBranchAddress("mu_staco_charge", &mu_staco_charge, &b_mu_staco_charge);
    fChain->SetBranchAddress("mu_staco_allauthor", &mu_staco_allauthor, &b_mu_staco_allauthor);
    fChain->SetBranchAddress("mu_staco_author", &mu_staco_author, &b_mu_staco_author);
    fChain->SetBranchAddress("mu_staco_matchchi2", &mu_staco_matchchi2, &b_mu_staco_matchchi2);
    fChain->SetBranchAddress("mu_staco_matchndof", &mu_staco_matchndof, &b_mu_staco_matchndof);
    fChain->SetBranchAddress("mu_staco_etcone20", &mu_staco_etcone20, &b_mu_staco_etcone20);
    fChain->SetBranchAddress("mu_staco_etcone30", &mu_staco_etcone30, &b_mu_staco_etcone30);
    fChain->SetBranchAddress("mu_staco_etcone40", &mu_staco_etcone40, &b_mu_staco_etcone40);
    fChain->SetBranchAddress("mu_staco_nucone20", &mu_staco_nucone20, &b_mu_staco_nucone20);
    fChain->SetBranchAddress("mu_staco_nucone30", &mu_staco_nucone30, &b_mu_staco_nucone30);
    fChain->SetBranchAddress("mu_staco_nucone40", &mu_staco_nucone40, &b_mu_staco_nucone40);
    fChain->SetBranchAddress("mu_staco_ptcone20", &mu_staco_ptcone20, &b_mu_staco_ptcone20);
    fChain->SetBranchAddress("mu_staco_ptcone30", &mu_staco_ptcone30, &b_mu_staco_ptcone30);
    fChain->SetBranchAddress("mu_staco_ptcone40", &mu_staco_ptcone40, &b_mu_staco_ptcone40);
    fChain->SetBranchAddress("mu_staco_energyLossPar", &mu_staco_energyLossPar, &b_mu_staco_energyLossPar);
    fChain->SetBranchAddress("mu_staco_energyLossErr", &mu_staco_energyLossErr, &b_mu_staco_energyLossErr);
    fChain->SetBranchAddress("mu_staco_etCore", &mu_staco_etCore, &b_mu_staco_etCore);
    fChain->SetBranchAddress("mu_staco_energyLossType", &mu_staco_energyLossType, &b_mu_staco_energyLossType);
    fChain->SetBranchAddress("mu_staco_bestMatch", &mu_staco_bestMatch, &b_mu_staco_bestMatch);
    fChain->SetBranchAddress("mu_staco_isStandAloneMuon", &mu_staco_isStandAloneMuon, &b_mu_staco_isStandAloneMuon);
    fChain->SetBranchAddress("mu_staco_isCombinedMuon", &mu_staco_isCombinedMuon, &b_mu_staco_isCombinedMuon);
    fChain->SetBranchAddress("mu_staco_isLowPtReconstructedMuon", &mu_staco_isLowPtReconstructedMuon, &b_mu_staco_isLowPtReconstructedMuon);
    fChain->SetBranchAddress("mu_staco_loose", &mu_staco_loose, &b_mu_staco_loose);
    fChain->SetBranchAddress("mu_staco_medium", &mu_staco_medium, &b_mu_staco_medium);
    fChain->SetBranchAddress("mu_staco_tight", &mu_staco_tight, &b_mu_staco_tight);
    fChain->SetBranchAddress("mu_staco_d0_exPV", &mu_staco_d0_exPV, &b_mu_staco_d0_exPV);
    fChain->SetBranchAddress("mu_staco_z0_exPV", &mu_staco_z0_exPV, &b_mu_staco_z0_exPV);
    fChain->SetBranchAddress("mu_staco_phi_exPV", &mu_staco_phi_exPV, &b_mu_staco_phi_exPV);
    fChain->SetBranchAddress("mu_staco_theta_exPV", &mu_staco_theta_exPV, &b_mu_staco_theta_exPV);
    fChain->SetBranchAddress("mu_staco_qoverp_exPV", &mu_staco_qoverp_exPV, &b_mu_staco_qoverp_exPV);
    fChain->SetBranchAddress("mu_staco_cb_d0_exPV", &mu_staco_cb_d0_exPV, &b_mu_staco_cb_d0_exPV);
    fChain->SetBranchAddress("mu_staco_cb_z0_exPV", &mu_staco_cb_z0_exPV, &b_mu_staco_cb_z0_exPV);
    fChain->SetBranchAddress("mu_staco_cb_phi_exPV", &mu_staco_cb_phi_exPV, &b_mu_staco_cb_phi_exPV);
    fChain->SetBranchAddress("mu_staco_cb_theta_exPV", &mu_staco_cb_theta_exPV, &b_mu_staco_cb_theta_exPV);
    fChain->SetBranchAddress("mu_staco_cb_qoverp_exPV", &mu_staco_cb_qoverp_exPV, &b_mu_staco_cb_qoverp_exPV);
    fChain->SetBranchAddress("mu_staco_id_d0_exPV", &mu_staco_id_d0_exPV, &b_mu_staco_id_d0_exPV);
    fChain->SetBranchAddress("mu_staco_id_z0_exPV", &mu_staco_id_z0_exPV, &b_mu_staco_id_z0_exPV);
    fChain->SetBranchAddress("mu_staco_id_phi_exPV", &mu_staco_id_phi_exPV, &b_mu_staco_id_phi_exPV);
    fChain->SetBranchAddress("mu_staco_id_theta_exPV", &mu_staco_id_theta_exPV, &b_mu_staco_id_theta_exPV);
    fChain->SetBranchAddress("mu_staco_id_qoverp_exPV", &mu_staco_id_qoverp_exPV, &b_mu_staco_id_qoverp_exPV);
    fChain->SetBranchAddress("mu_staco_me_d0_exPV", &mu_staco_me_d0_exPV, &b_mu_staco_me_d0_exPV);
    fChain->SetBranchAddress("mu_staco_me_z0_exPV", &mu_staco_me_z0_exPV, &b_mu_staco_me_z0_exPV);
    fChain->SetBranchAddress("mu_staco_me_phi_exPV", &mu_staco_me_phi_exPV, &b_mu_staco_me_phi_exPV);
    fChain->SetBranchAddress("mu_staco_me_theta_exPV", &mu_staco_me_theta_exPV, &b_mu_staco_me_theta_exPV);
    fChain->SetBranchAddress("mu_staco_me_qoverp_exPV", &mu_staco_me_qoverp_exPV, &b_mu_staco_me_qoverp_exPV);
    fChain->SetBranchAddress("mu_staco_ie_d0_exPV", &mu_staco_ie_d0_exPV, &b_mu_staco_ie_d0_exPV);
    fChain->SetBranchAddress("mu_staco_ie_z0_exPV", &mu_staco_ie_z0_exPV, &b_mu_staco_ie_z0_exPV);
    fChain->SetBranchAddress("mu_staco_ie_phi_exPV", &mu_staco_ie_phi_exPV, &b_mu_staco_ie_phi_exPV);
    fChain->SetBranchAddress("mu_staco_ie_theta_exPV", &mu_staco_ie_theta_exPV, &b_mu_staco_ie_theta_exPV);
    fChain->SetBranchAddress("mu_staco_ie_qoverp_exPV", &mu_staco_ie_qoverp_exPV, &b_mu_staco_ie_qoverp_exPV);
    fChain->SetBranchAddress("mu_staco_cov_d0_exPV", &mu_staco_cov_d0_exPV, &b_mu_staco_cov_d0_exPV);
    fChain->SetBranchAddress("mu_staco_cov_z0_exPV", &mu_staco_cov_z0_exPV, &b_mu_staco_cov_z0_exPV);
    fChain->SetBranchAddress("mu_staco_cov_phi_exPV", &mu_staco_cov_phi_exPV, &b_mu_staco_cov_phi_exPV);
    fChain->SetBranchAddress("mu_staco_cov_theta_exPV", &mu_staco_cov_theta_exPV, &b_mu_staco_cov_theta_exPV);
    fChain->SetBranchAddress("mu_staco_cov_qoverp_exPV", &mu_staco_cov_qoverp_exPV, &b_mu_staco_cov_qoverp_exPV);
    fChain->SetBranchAddress("mu_staco_cov_d0_z0_exPV", &mu_staco_cov_d0_z0_exPV, &b_mu_staco_cov_d0_z0_exPV);
    fChain->SetBranchAddress("mu_staco_cov_d0_phi_exPV", &mu_staco_cov_d0_phi_exPV, &b_mu_staco_cov_d0_phi_exPV);
    fChain->SetBranchAddress("mu_staco_cov_d0_theta_exPV", &mu_staco_cov_d0_theta_exPV, &b_mu_staco_cov_d0_theta_exPV);
    fChain->SetBranchAddress("mu_staco_cov_d0_qoverp_exPV", &mu_staco_cov_d0_qoverp_exPV, &b_mu_staco_cov_d0_qoverp_exPV);
    fChain->SetBranchAddress("mu_staco_cov_z0_phi_exPV", &mu_staco_cov_z0_phi_exPV, &b_mu_staco_cov_z0_phi_exPV);
    fChain->SetBranchAddress("mu_staco_cov_z0_theta_exPV", &mu_staco_cov_z0_theta_exPV, &b_mu_staco_cov_z0_theta_exPV);
    fChain->SetBranchAddress("mu_staco_cov_z0_qoverp_exPV", &mu_staco_cov_z0_qoverp_exPV, &b_mu_staco_cov_z0_qoverp_exPV);
    fChain->SetBranchAddress("mu_staco_cov_phi_theta_exPV", &mu_staco_cov_phi_theta_exPV, &b_mu_staco_cov_phi_theta_exPV);
    fChain->SetBranchAddress("mu_staco_cov_phi_qoverp_exPV", &mu_staco_cov_phi_qoverp_exPV, &b_mu_staco_cov_phi_qoverp_exPV);
    fChain->SetBranchAddress("mu_staco_cov_theta_qoverp_exPV", &mu_staco_cov_theta_qoverp_exPV, &b_mu_staco_cov_theta_qoverp_exPV);
    fChain->SetBranchAddress("mu_staco_ms_d0", &mu_staco_ms_d0, &b_mu_staco_ms_d0);
    fChain->SetBranchAddress("mu_staco_ms_z0", &mu_staco_ms_z0, &b_mu_staco_ms_z0);
    fChain->SetBranchAddress("mu_staco_ms_phi", &mu_staco_ms_phi, &b_mu_staco_ms_phi);
    fChain->SetBranchAddress("mu_staco_ms_theta", &mu_staco_ms_theta, &b_mu_staco_ms_theta);
    fChain->SetBranchAddress("mu_staco_ms_qoverp", &mu_staco_ms_qoverp, &b_mu_staco_ms_qoverp);
    fChain->SetBranchAddress("mu_staco_id_d0", &mu_staco_id_d0, &b_mu_staco_id_d0);
    fChain->SetBranchAddress("mu_staco_id_z0", &mu_staco_id_z0, &b_mu_staco_id_z0);
    fChain->SetBranchAddress("mu_staco_id_phi", &mu_staco_id_phi, &b_mu_staco_id_phi);
    fChain->SetBranchAddress("mu_staco_id_theta", &mu_staco_id_theta, &b_mu_staco_id_theta);
    fChain->SetBranchAddress("mu_staco_id_qoverp", &mu_staco_id_qoverp, &b_mu_staco_id_qoverp);
    fChain->SetBranchAddress("mu_staco_me_d0", &mu_staco_me_d0, &b_mu_staco_me_d0);
    fChain->SetBranchAddress("mu_staco_me_z0", &mu_staco_me_z0, &b_mu_staco_me_z0);
    fChain->SetBranchAddress("mu_staco_me_phi", &mu_staco_me_phi, &b_mu_staco_me_phi);
    fChain->SetBranchAddress("mu_staco_me_theta", &mu_staco_me_theta, &b_mu_staco_me_theta);
    fChain->SetBranchAddress("mu_staco_me_qoverp", &mu_staco_me_qoverp, &b_mu_staco_me_qoverp);
    fChain->SetBranchAddress("mu_staco_ie_d0", &mu_staco_ie_d0, &b_mu_staco_ie_d0);
    fChain->SetBranchAddress("mu_staco_ie_z0", &mu_staco_ie_z0, &b_mu_staco_ie_z0);
    fChain->SetBranchAddress("mu_staco_ie_phi", &mu_staco_ie_phi, &b_mu_staco_ie_phi);
    fChain->SetBranchAddress("mu_staco_ie_theta", &mu_staco_ie_theta, &b_mu_staco_ie_theta);
    fChain->SetBranchAddress("mu_staco_ie_qoverp", &mu_staco_ie_qoverp, &b_mu_staco_ie_qoverp);
    fChain->SetBranchAddress("mu_staco_nBLHits", &mu_staco_nBLHits, &b_mu_staco_nBLHits);
    fChain->SetBranchAddress("mu_staco_nPixHits", &mu_staco_nPixHits, &b_mu_staco_nPixHits);
    fChain->SetBranchAddress("mu_staco_nSCTHits", &mu_staco_nSCTHits, &b_mu_staco_nSCTHits);
    fChain->SetBranchAddress("mu_staco_nTRTHits", &mu_staco_nTRTHits, &b_mu_staco_nTRTHits);
    fChain->SetBranchAddress("mu_staco_nTRTHighTHits", &mu_staco_nTRTHighTHits, &b_mu_staco_nTRTHighTHits);
    fChain->SetBranchAddress("mu_staco_nBLSharedHits", &mu_staco_nBLSharedHits, &b_mu_staco_nBLSharedHits);
    fChain->SetBranchAddress("mu_staco_nPixSharedHits", &mu_staco_nPixSharedHits, &b_mu_staco_nPixSharedHits);
    fChain->SetBranchAddress("mu_staco_nPixHoles", &mu_staco_nPixHoles, &b_mu_staco_nPixHoles);
    fChain->SetBranchAddress("mu_staco_nSCTSharedHits", &mu_staco_nSCTSharedHits, &b_mu_staco_nSCTSharedHits);
    fChain->SetBranchAddress("mu_staco_nSCTHoles", &mu_staco_nSCTHoles, &b_mu_staco_nSCTHoles);
    fChain->SetBranchAddress("mu_staco_nTRTOutliers", &mu_staco_nTRTOutliers, &b_mu_staco_nTRTOutliers);
    fChain->SetBranchAddress("mu_staco_nTRTHighTOutliers", &mu_staco_nTRTHighTOutliers, &b_mu_staco_nTRTHighTOutliers);
    fChain->SetBranchAddress("mu_staco_nMDTHits", &mu_staco_nMDTHits, &b_mu_staco_nMDTHits);
    fChain->SetBranchAddress("mu_staco_nMDTHoles", &mu_staco_nMDTHoles, &b_mu_staco_nMDTHoles);
    fChain->SetBranchAddress("mu_staco_nCSCEtaHits", &mu_staco_nCSCEtaHits, &b_mu_staco_nCSCEtaHits);
    fChain->SetBranchAddress("mu_staco_nCSCEtaHoles", &mu_staco_nCSCEtaHoles, &b_mu_staco_nCSCEtaHoles);
    fChain->SetBranchAddress("mu_staco_nCSCPhiHits", &mu_staco_nCSCPhiHits, &b_mu_staco_nCSCPhiHits);
    fChain->SetBranchAddress("mu_staco_nCSCPhiHoles", &mu_staco_nCSCPhiHoles, &b_mu_staco_nCSCPhiHoles);
    fChain->SetBranchAddress("mu_staco_nRPCEtaHits", &mu_staco_nRPCEtaHits, &b_mu_staco_nRPCEtaHits);
    fChain->SetBranchAddress("mu_staco_nRPCEtaHoles", &mu_staco_nRPCEtaHoles, &b_mu_staco_nRPCEtaHoles);
    fChain->SetBranchAddress("mu_staco_nRPCPhiHits", &mu_staco_nRPCPhiHits, &b_mu_staco_nRPCPhiHits);
    fChain->SetBranchAddress("mu_staco_nRPCPhiHoles", &mu_staco_nRPCPhiHoles, &b_mu_staco_nRPCPhiHoles);
    fChain->SetBranchAddress("mu_staco_nTGCEtaHits", &mu_staco_nTGCEtaHits, &b_mu_staco_nTGCEtaHits);
    fChain->SetBranchAddress("mu_staco_nTGCEtaHoles", &mu_staco_nTGCEtaHoles, &b_mu_staco_nTGCEtaHoles);
    fChain->SetBranchAddress("mu_staco_nTGCPhiHits", &mu_staco_nTGCPhiHits, &b_mu_staco_nTGCPhiHits);
    fChain->SetBranchAddress("mu_staco_nTGCPhiHoles", &mu_staco_nTGCPhiHoles, &b_mu_staco_nTGCPhiHoles);
    fChain->SetBranchAddress("mu_staco_nGangedPixels", &mu_staco_nGangedPixels, &b_mu_staco_nGangedPixels);
    fChain->SetBranchAddress("mu_staco_nOutliersOnTrack", &mu_staco_nOutliersOnTrack, &b_mu_staco_nOutliersOnTrack);
    fChain->SetBranchAddress("mu_staco_nMDTBIHits", &mu_staco_nMDTBIHits, &b_mu_staco_nMDTBIHits);
    fChain->SetBranchAddress("mu_staco_nMDTBMHits", &mu_staco_nMDTBMHits, &b_mu_staco_nMDTBMHits);
    fChain->SetBranchAddress("mu_staco_nMDTBOHits", &mu_staco_nMDTBOHits, &b_mu_staco_nMDTBOHits);
    fChain->SetBranchAddress("mu_staco_nMDTBEEHits", &mu_staco_nMDTBEEHits, &b_mu_staco_nMDTBEEHits);
    fChain->SetBranchAddress("mu_staco_nMDTBIS78Hits", &mu_staco_nMDTBIS78Hits, &b_mu_staco_nMDTBIS78Hits);
    fChain->SetBranchAddress("mu_staco_nMDTEIHits", &mu_staco_nMDTEIHits, &b_mu_staco_nMDTEIHits);
    fChain->SetBranchAddress("mu_staco_nMDTEMHits", &mu_staco_nMDTEMHits, &b_mu_staco_nMDTEMHits);
    fChain->SetBranchAddress("mu_staco_nMDTEOHits", &mu_staco_nMDTEOHits, &b_mu_staco_nMDTEOHits);
    fChain->SetBranchAddress("mu_staco_nMDTEEHits", &mu_staco_nMDTEEHits, &b_mu_staco_nMDTEEHits);
    fChain->SetBranchAddress("mu_staco_nRPCLayer1EtaHits", &mu_staco_nRPCLayer1EtaHits, &b_mu_staco_nRPCLayer1EtaHits);
    fChain->SetBranchAddress("mu_staco_nRPCLayer2EtaHits", &mu_staco_nRPCLayer2EtaHits, &b_mu_staco_nRPCLayer2EtaHits);
    fChain->SetBranchAddress("mu_staco_nRPCLayer3EtaHits", &mu_staco_nRPCLayer3EtaHits, &b_mu_staco_nRPCLayer3EtaHits);
    fChain->SetBranchAddress("mu_staco_nRPCLayer1PhiHits", &mu_staco_nRPCLayer1PhiHits, &b_mu_staco_nRPCLayer1PhiHits);
    fChain->SetBranchAddress("mu_staco_nRPCLayer2PhiHits", &mu_staco_nRPCLayer2PhiHits, &b_mu_staco_nRPCLayer2PhiHits);
    fChain->SetBranchAddress("mu_staco_nRPCLayer3PhiHits", &mu_staco_nRPCLayer3PhiHits, &b_mu_staco_nRPCLayer3PhiHits);
    fChain->SetBranchAddress("mu_staco_nTGCLayer1EtaHits", &mu_staco_nTGCLayer1EtaHits, &b_mu_staco_nTGCLayer1EtaHits);
    fChain->SetBranchAddress("mu_staco_nTGCLayer2EtaHits", &mu_staco_nTGCLayer2EtaHits, &b_mu_staco_nTGCLayer2EtaHits);
    fChain->SetBranchAddress("mu_staco_nTGCLayer3EtaHits", &mu_staco_nTGCLayer3EtaHits, &b_mu_staco_nTGCLayer3EtaHits);
    fChain->SetBranchAddress("mu_staco_nTGCLayer4EtaHits", &mu_staco_nTGCLayer4EtaHits, &b_mu_staco_nTGCLayer4EtaHits);
    fChain->SetBranchAddress("mu_staco_nTGCLayer1PhiHits", &mu_staco_nTGCLayer1PhiHits, &b_mu_staco_nTGCLayer1PhiHits);
    fChain->SetBranchAddress("mu_staco_nTGCLayer2PhiHits", &mu_staco_nTGCLayer2PhiHits, &b_mu_staco_nTGCLayer2PhiHits);
    fChain->SetBranchAddress("mu_staco_nTGCLayer3PhiHits", &mu_staco_nTGCLayer3PhiHits, &b_mu_staco_nTGCLayer3PhiHits);
    fChain->SetBranchAddress("mu_staco_nTGCLayer4PhiHits", &mu_staco_nTGCLayer4PhiHits, &b_mu_staco_nTGCLayer4PhiHits);
    fChain->SetBranchAddress("mu_staco_barrelSectors", &mu_staco_barrelSectors, &b_mu_staco_barrelSectors);
    fChain->SetBranchAddress("mu_staco_endcapSectors", &mu_staco_endcapSectors, &b_mu_staco_endcapSectors);
    fChain->SetBranchAddress("mu_staco_trackd0", &mu_staco_trackd0, &b_mu_staco_trackd0);
    fChain->SetBranchAddress("mu_staco_trackz0", &mu_staco_trackz0, &b_mu_staco_trackz0);
    fChain->SetBranchAddress("mu_staco_trackphi", &mu_staco_trackphi, &b_mu_staco_trackphi);
    fChain->SetBranchAddress("mu_staco_tracktheta", &mu_staco_tracktheta, &b_mu_staco_tracktheta);
    fChain->SetBranchAddress("mu_staco_trackqoverp", &mu_staco_trackqoverp, &b_mu_staco_trackqoverp);
    fChain->SetBranchAddress("mu_staco_trackcov_d0", &mu_staco_trackcov_d0, &b_mu_staco_trackcov_d0);
    fChain->SetBranchAddress("mu_staco_trackcov_z0", &mu_staco_trackcov_z0, &b_mu_staco_trackcov_z0);
    fChain->SetBranchAddress("mu_staco_trackcov_phi", &mu_staco_trackcov_phi, &b_mu_staco_trackcov_phi);
    fChain->SetBranchAddress("mu_staco_trackcov_theta", &mu_staco_trackcov_theta, &b_mu_staco_trackcov_theta);
    fChain->SetBranchAddress("mu_staco_trackcov_qoverp", &mu_staco_trackcov_qoverp, &b_mu_staco_trackcov_qoverp);
    fChain->SetBranchAddress("mu_staco_trackcov_d0_z0", &mu_staco_trackcov_d0_z0, &b_mu_staco_trackcov_d0_z0);
    fChain->SetBranchAddress("mu_staco_trackcov_d0_phi", &mu_staco_trackcov_d0_phi, &b_mu_staco_trackcov_d0_phi);
    fChain->SetBranchAddress("mu_staco_trackcov_d0_theta", &mu_staco_trackcov_d0_theta, &b_mu_staco_trackcov_d0_theta);
    fChain->SetBranchAddress("mu_staco_trackcov_d0_qoverp", &mu_staco_trackcov_d0_qoverp, &b_mu_staco_trackcov_d0_qoverp);
    fChain->SetBranchAddress("mu_staco_trackcov_z0_phi", &mu_staco_trackcov_z0_phi, &b_mu_staco_trackcov_z0_phi);
    fChain->SetBranchAddress("mu_staco_trackcov_z0_theta", &mu_staco_trackcov_z0_theta, &b_mu_staco_trackcov_z0_theta);
    fChain->SetBranchAddress("mu_staco_trackcov_z0_qoverp", &mu_staco_trackcov_z0_qoverp, &b_mu_staco_trackcov_z0_qoverp);
    fChain->SetBranchAddress("mu_staco_trackcov_phi_theta", &mu_staco_trackcov_phi_theta, &b_mu_staco_trackcov_phi_theta);
    fChain->SetBranchAddress("mu_staco_trackcov_phi_qoverp", &mu_staco_trackcov_phi_qoverp, &b_mu_staco_trackcov_phi_qoverp);
    fChain->SetBranchAddress("mu_staco_trackcov_theta_qoverp", &mu_staco_trackcov_theta_qoverp, &b_mu_staco_trackcov_theta_qoverp);
    fChain->SetBranchAddress("mu_staco_trackfitchi2", &mu_staco_trackfitchi2, &b_mu_staco_trackfitchi2);
    fChain->SetBranchAddress("mu_staco_trackfitndof", &mu_staco_trackfitndof, &b_mu_staco_trackfitndof);
    fChain->SetBranchAddress("mu_staco_hastrack", &mu_staco_hastrack, &b_mu_staco_hastrack);
    fChain->SetBranchAddress("mu_staco_EF_dr", &mu_staco_EF_dr, &b_mu_staco_EF_dr);
    fChain->SetBranchAddress("mu_staco_EF_cb_eta", &mu_staco_EF_cb_eta, &b_mu_staco_EF_cb_eta);
    fChain->SetBranchAddress("mu_staco_EF_cb_phi", &mu_staco_EF_cb_phi, &b_mu_staco_EF_cb_phi);
    fChain->SetBranchAddress("mu_staco_EF_cb_pt", &mu_staco_EF_cb_pt, &b_mu_staco_EF_cb_pt);
    fChain->SetBranchAddress("mu_staco_EF_ms_eta", &mu_staco_EF_ms_eta, &b_mu_staco_EF_ms_eta);
    fChain->SetBranchAddress("mu_staco_EF_ms_phi", &mu_staco_EF_ms_phi, &b_mu_staco_EF_ms_phi);
    fChain->SetBranchAddress("mu_staco_EF_ms_pt", &mu_staco_EF_ms_pt, &b_mu_staco_EF_ms_pt);
    fChain->SetBranchAddress("mu_staco_EF_me_eta", &mu_staco_EF_me_eta, &b_mu_staco_EF_me_eta);
    fChain->SetBranchAddress("mu_staco_EF_me_phi", &mu_staco_EF_me_phi, &b_mu_staco_EF_me_phi);
    fChain->SetBranchAddress("mu_staco_EF_me_pt", &mu_staco_EF_me_pt, &b_mu_staco_EF_me_pt);
    fChain->SetBranchAddress("mu_staco_EF_matched", &mu_staco_EF_matched, &b_mu_staco_EF_matched);
    fChain->SetBranchAddress("mu_staco_L2CB_dr", &mu_staco_L2CB_dr, &b_mu_staco_L2CB_dr);
    fChain->SetBranchAddress("mu_staco_L2CB_pt", &mu_staco_L2CB_pt, &b_mu_staco_L2CB_pt);
    fChain->SetBranchAddress("mu_staco_L2CB_eta", &mu_staco_L2CB_eta, &b_mu_staco_L2CB_eta);
    fChain->SetBranchAddress("mu_staco_L2CB_phi", &mu_staco_L2CB_phi, &b_mu_staco_L2CB_phi);
    fChain->SetBranchAddress("mu_staco_L2CB_id_pt", &mu_staco_L2CB_id_pt, &b_mu_staco_L2CB_id_pt);
    fChain->SetBranchAddress("mu_staco_L2CB_ms_pt", &mu_staco_L2CB_ms_pt, &b_mu_staco_L2CB_ms_pt);
    fChain->SetBranchAddress("mu_staco_L2CB_nPixHits", &mu_staco_L2CB_nPixHits, &b_mu_staco_L2CB_nPixHits);
    fChain->SetBranchAddress("mu_staco_L2CB_nSCTHits", &mu_staco_L2CB_nSCTHits, &b_mu_staco_L2CB_nSCTHits);
    fChain->SetBranchAddress("mu_staco_L2CB_nTRTHits", &mu_staco_L2CB_nTRTHits, &b_mu_staco_L2CB_nTRTHits);
    fChain->SetBranchAddress("mu_staco_L2CB_nTRTHighTHits", &mu_staco_L2CB_nTRTHighTHits, &b_mu_staco_L2CB_nTRTHighTHits);
    fChain->SetBranchAddress("mu_staco_L2CB_matched", &mu_staco_L2CB_matched, &b_mu_staco_L2CB_matched);
    fChain->SetBranchAddress("mu_staco_L1_dr", &mu_staco_L1_dr, &b_mu_staco_L1_dr);
    fChain->SetBranchAddress("mu_staco_L1_pt", &mu_staco_L1_pt, &b_mu_staco_L1_pt);
    fChain->SetBranchAddress("mu_staco_L1_eta", &mu_staco_L1_eta, &b_mu_staco_L1_eta);
    fChain->SetBranchAddress("mu_staco_L1_phi", &mu_staco_L1_phi, &b_mu_staco_L1_phi);
    fChain->SetBranchAddress("mu_staco_L1_thrNumber", &mu_staco_L1_thrNumber, &b_mu_staco_L1_thrNumber);
    fChain->SetBranchAddress("mu_staco_L1_RoINumber", &mu_staco_L1_RoINumber, &b_mu_staco_L1_RoINumber);
    fChain->SetBranchAddress("mu_staco_L1_sectorAddress", &mu_staco_L1_sectorAddress, &b_mu_staco_L1_sectorAddress);
    fChain->SetBranchAddress("mu_staco_L1_firstCandidate", &mu_staco_L1_firstCandidate, &b_mu_staco_L1_firstCandidate);
    fChain->SetBranchAddress("mu_staco_L1_moreCandInRoI", &mu_staco_L1_moreCandInRoI, &b_mu_staco_L1_moreCandInRoI);
    fChain->SetBranchAddress("mu_staco_L1_moreCandInSector", &mu_staco_L1_moreCandInSector, &b_mu_staco_L1_moreCandInSector);
    fChain->SetBranchAddress("mu_staco_L1_source", &mu_staco_L1_source, &b_mu_staco_L1_source);
    fChain->SetBranchAddress("mu_staco_L1_hemisphere", &mu_staco_L1_hemisphere, &b_mu_staco_L1_hemisphere);
    fChain->SetBranchAddress("mu_staco_L1_matched", &mu_staco_L1_matched, &b_mu_staco_L1_matched);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_2MU0", &EF_L1ItemStreamer_L1_2MU0, &b_EF_L1ItemStreamer_L1_2MU0);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_2MU0_FIRSTEMPTY", &EF_L1ItemStreamer_L1_2MU0_FIRSTEMPTY, &b_EF_L1ItemStreamer_L1_2MU0_FIRSTEMPTY);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_2MU0_MU6", &EF_L1ItemStreamer_L1_2MU0_MU6, &b_EF_L1ItemStreamer_L1_2MU0_MU6);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_2MU10", &EF_L1ItemStreamer_L1_2MU10, &b_EF_L1ItemStreamer_L1_2MU10);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_2MU6", &EF_L1ItemStreamer_L1_2MU6, &b_EF_L1ItemStreamer_L1_2MU6);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_EM10", &EF_L1ItemStreamer_L1_EM10, &b_EF_L1ItemStreamer_L1_EM10);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_EM10I", &EF_L1ItemStreamer_L1_EM10I, &b_EF_L1ItemStreamer_L1_EM10I);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_EM14", &EF_L1ItemStreamer_L1_EM14, &b_EF_L1ItemStreamer_L1_EM14);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_EM2", &EF_L1ItemStreamer_L1_EM2, &b_EF_L1ItemStreamer_L1_EM2);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_EM2_MV", &EF_L1ItemStreamer_L1_EM2_MV, &b_EF_L1ItemStreamer_L1_EM2_MV);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_EM2_UNPAIRED_ISO", &EF_L1ItemStreamer_L1_EM2_UNPAIRED_ISO, &b_EF_L1ItemStreamer_L1_EM2_UNPAIRED_ISO);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_EM2_UNPAIRED_NONISO", &EF_L1ItemStreamer_L1_EM2_UNPAIRED_NONISO, &b_EF_L1ItemStreamer_L1_EM2_UNPAIRED_NONISO);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_EM3", &EF_L1ItemStreamer_L1_EM3, &b_EF_L1ItemStreamer_L1_EM3);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_EM3_EMPTY", &EF_L1ItemStreamer_L1_EM3_EMPTY, &b_EF_L1ItemStreamer_L1_EM3_EMPTY);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_EM3_FIRSTEMPTY", &EF_L1ItemStreamer_L1_EM3_FIRSTEMPTY, &b_EF_L1ItemStreamer_L1_EM3_FIRSTEMPTY);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_EM4", &EF_L1ItemStreamer_L1_EM4, &b_EF_L1ItemStreamer_L1_EM4);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_EM5", &EF_L1ItemStreamer_L1_EM5, &b_EF_L1ItemStreamer_L1_EM5);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_EM5I", &EF_L1ItemStreamer_L1_EM5I, &b_EF_L1ItemStreamer_L1_EM5I);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_MU0", &EF_L1ItemStreamer_L1_MU0, &b_EF_L1ItemStreamer_L1_MU0);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_MU0_COMM", &EF_L1ItemStreamer_L1_MU0_COMM, &b_EF_L1ItemStreamer_L1_MU0_COMM);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_MU0_COMM_EMPTY", &EF_L1ItemStreamer_L1_MU0_COMM_EMPTY, &b_EF_L1ItemStreamer_L1_MU0_COMM_EMPTY);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_MU0_COMM_FIRSTEMPTY", &EF_L1ItemStreamer_L1_MU0_COMM_FIRSTEMPTY, &b_EF_L1ItemStreamer_L1_MU0_COMM_FIRSTEMPTY);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_ISO", &EF_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_ISO, &b_EF_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_ISO);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_NONISO", &EF_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_NONISO, &b_EF_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_NONISO);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_MU0_EMPTY", &EF_L1ItemStreamer_L1_MU0_EMPTY, &b_EF_L1ItemStreamer_L1_MU0_EMPTY);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_MU0_FIRSTEMPTY", &EF_L1ItemStreamer_L1_MU0_FIRSTEMPTY, &b_EF_L1ItemStreamer_L1_MU0_FIRSTEMPTY);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_MU0_MV", &EF_L1ItemStreamer_L1_MU0_MV, &b_EF_L1ItemStreamer_L1_MU0_MV);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_MU0_UNPAIRED_ISO", &EF_L1ItemStreamer_L1_MU0_UNPAIRED_ISO, &b_EF_L1ItemStreamer_L1_MU0_UNPAIRED_ISO);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_MU0_UNPAIRED_NONISO", &EF_L1ItemStreamer_L1_MU0_UNPAIRED_NONISO, &b_EF_L1ItemStreamer_L1_MU0_UNPAIRED_NONISO);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_MU10", &EF_L1ItemStreamer_L1_MU10, &b_EF_L1ItemStreamer_L1_MU10);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_MU10_FIRSTEMPTY", &EF_L1ItemStreamer_L1_MU10_FIRSTEMPTY, &b_EF_L1ItemStreamer_L1_MU10_FIRSTEMPTY);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_MU15", &EF_L1ItemStreamer_L1_MU15, &b_EF_L1ItemStreamer_L1_MU15);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_MU20", &EF_L1ItemStreamer_L1_MU20, &b_EF_L1ItemStreamer_L1_MU20);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_MU6", &EF_L1ItemStreamer_L1_MU6, &b_EF_L1ItemStreamer_L1_MU6);
    fChain->SetBranchAddress("EF_L1ItemStreamer_L1_MU6_FIRSTEMPTY", &EF_L1ItemStreamer_L1_MU6_FIRSTEMPTY, &b_EF_L1ItemStreamer_L1_MU6_FIRSTEMPTY);
    fChain->SetBranchAddress("EF_SeededStreamerL1Calo", &EF_SeededStreamerL1Calo, &b_EF_SeededStreamerL1Calo);
    fChain->SetBranchAddress("EF_g10_loose", &EF_g10_loose, &b_EF_g10_loose);
    fChain->SetBranchAddress("EF_g10_loose_larcalib", &EF_g10_loose_larcalib, &b_EF_g10_loose_larcalib);
    fChain->SetBranchAddress("EF_g5_NoCut_cosmic", &EF_g5_NoCut_cosmic, &b_EF_g5_NoCut_cosmic);
    fChain->SetBranchAddress("EF_g5_loose", &EF_g5_loose, &b_EF_g5_loose);
    fChain->SetBranchAddress("EF_g5_loose_larcalib", &EF_g5_loose_larcalib, &b_EF_g5_loose_larcalib);
    fChain->SetBranchAddress("EF_mu4", &EF_mu4, &b_EF_mu4);
    fChain->SetBranchAddress("EF_mu4_IDTrkNoCut", &EF_mu4_IDTrkNoCut, &b_EF_mu4_IDTrkNoCut);
    fChain->SetBranchAddress("EF_mu4_MSonly", &EF_mu4_MSonly, &b_EF_mu4_MSonly);
    fChain->SetBranchAddress("EF_mu4_MSonly_MB2_noL2_EFFS", &EF_mu4_MSonly_MB2_noL2_EFFS, &b_EF_mu4_MSonly_MB2_noL2_EFFS);
    fChain->SetBranchAddress("EF_mu4_MSonly_cosmic", &EF_mu4_MSonly_cosmic, &b_EF_mu4_MSonly_cosmic);
    fChain->SetBranchAddress("EF_mu4_MV", &EF_mu4_MV, &b_EF_mu4_MV);
    fChain->SetBranchAddress("EF_mu4_MV_MSonly", &EF_mu4_MV_MSonly, &b_EF_mu4_MV_MSonly);
    fChain->SetBranchAddress("EF_mu4_comm_MSonly_cosmic", &EF_mu4_comm_MSonly_cosmic, &b_EF_mu4_comm_MSonly_cosmic);
    fChain->SetBranchAddress("EF_mu4_comm_cosmic", &EF_mu4_comm_cosmic, &b_EF_mu4_comm_cosmic);
    fChain->SetBranchAddress("EF_mu4_cosmic", &EF_mu4_cosmic, &b_EF_mu4_cosmic);
    fChain->SetBranchAddress("L1_2EM2", &L1_2EM2, &b_L1_2EM2);
    fChain->SetBranchAddress("L1_2EM3", &L1_2EM3, &b_L1_2EM3);
    fChain->SetBranchAddress("L1_2EM4", &L1_2EM4, &b_L1_2EM4);
    fChain->SetBranchAddress("L1_2EM5", &L1_2EM5, &b_L1_2EM5);
    fChain->SetBranchAddress("L1_2MU0", &L1_2MU0, &b_L1_2MU0);
    fChain->SetBranchAddress("L1_2MU0_FIRSTEMPTY", &L1_2MU0_FIRSTEMPTY, &b_L1_2MU0_FIRSTEMPTY);
    fChain->SetBranchAddress("L1_2MU0_MU6", &L1_2MU0_MU6, &b_L1_2MU0_MU6);
    fChain->SetBranchAddress("L1_2MU10", &L1_2MU10, &b_L1_2MU10);
    fChain->SetBranchAddress("L1_2MU20", &L1_2MU20, &b_L1_2MU20);
    fChain->SetBranchAddress("L1_2MU6", &L1_2MU6, &b_L1_2MU6);
    fChain->SetBranchAddress("L1_EM10", &L1_EM10, &b_L1_EM10);
    fChain->SetBranchAddress("L1_EM10I", &L1_EM10I, &b_L1_EM10I);
    fChain->SetBranchAddress("L1_EM14", &L1_EM14, &b_L1_EM14);
    fChain->SetBranchAddress("L1_EM2", &L1_EM2, &b_L1_EM2);
    fChain->SetBranchAddress("L1_EM2_MV", &L1_EM2_MV, &b_L1_EM2_MV);
    fChain->SetBranchAddress("L1_EM2_UNPAIRED_ISO", &L1_EM2_UNPAIRED_ISO, &b_L1_EM2_UNPAIRED_ISO);
    fChain->SetBranchAddress("L1_EM2_UNPAIRED_NONISO", &L1_EM2_UNPAIRED_NONISO, &b_L1_EM2_UNPAIRED_NONISO);
    fChain->SetBranchAddress("L1_EM3", &L1_EM3, &b_L1_EM3);
    fChain->SetBranchAddress("L1_EM3_EMPTY", &L1_EM3_EMPTY, &b_L1_EM3_EMPTY);
    fChain->SetBranchAddress("L1_EM3_FIRSTEMPTY", &L1_EM3_FIRSTEMPTY, &b_L1_EM3_FIRSTEMPTY);
    fChain->SetBranchAddress("L1_EM4", &L1_EM4, &b_L1_EM4);
    fChain->SetBranchAddress("L1_EM5", &L1_EM5, &b_L1_EM5);
    fChain->SetBranchAddress("L1_EM5I", &L1_EM5I, &b_L1_EM5I);
    fChain->SetBranchAddress("L1_MU0", &L1_MU0, &b_L1_MU0);
    fChain->SetBranchAddress("L1_MU0_COMM", &L1_MU0_COMM, &b_L1_MU0_COMM);
    fChain->SetBranchAddress("L1_MU0_COMM_EMPTY", &L1_MU0_COMM_EMPTY, &b_L1_MU0_COMM_EMPTY);
    fChain->SetBranchAddress("L1_MU0_COMM_FIRSTEMPTY", &L1_MU0_COMM_FIRSTEMPTY, &b_L1_MU0_COMM_FIRSTEMPTY);
    fChain->SetBranchAddress("L1_MU0_COMM_UNPAIRED_ISO", &L1_MU0_COMM_UNPAIRED_ISO, &b_L1_MU0_COMM_UNPAIRED_ISO);
    fChain->SetBranchAddress("L1_MU0_COMM_UNPAIRED_NONISO", &L1_MU0_COMM_UNPAIRED_NONISO, &b_L1_MU0_COMM_UNPAIRED_NONISO);
    fChain->SetBranchAddress("L1_MU0_EMPTY", &L1_MU0_EMPTY, &b_L1_MU0_EMPTY);
    fChain->SetBranchAddress("L1_MU0_FIRSTEMPTY", &L1_MU0_FIRSTEMPTY, &b_L1_MU0_FIRSTEMPTY);
    fChain->SetBranchAddress("L1_MU0_MV", &L1_MU0_MV, &b_L1_MU0_MV);
    fChain->SetBranchAddress("L1_MU0_UNPAIRED_ISO", &L1_MU0_UNPAIRED_ISO, &b_L1_MU0_UNPAIRED_ISO);
    fChain->SetBranchAddress("L1_MU0_UNPAIRED_NONISO", &L1_MU0_UNPAIRED_NONISO, &b_L1_MU0_UNPAIRED_NONISO);
    fChain->SetBranchAddress("L1_MU10", &L1_MU10, &b_L1_MU10);
    fChain->SetBranchAddress("L1_MU10_FIRSTEMPTY", &L1_MU10_FIRSTEMPTY, &b_L1_MU10_FIRSTEMPTY);
    fChain->SetBranchAddress("L1_MU15", &L1_MU15, &b_L1_MU15);
    fChain->SetBranchAddress("L1_MU20", &L1_MU20, &b_L1_MU20);
    fChain->SetBranchAddress("L1_MU6", &L1_MU6, &b_L1_MU6);
    fChain->SetBranchAddress("L1_MU6_FIRSTEMPTY", &L1_MU6_FIRSTEMPTY, &b_L1_MU6_FIRSTEMPTY);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_2EM2", &L2_L1ItemStreamer_L1_2EM2, &b_L2_L1ItemStreamer_L1_2EM2);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_2EM3", &L2_L1ItemStreamer_L1_2EM3, &b_L2_L1ItemStreamer_L1_2EM3);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_2EM4", &L2_L1ItemStreamer_L1_2EM4, &b_L2_L1ItemStreamer_L1_2EM4);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_2EM5", &L2_L1ItemStreamer_L1_2EM5, &b_L2_L1ItemStreamer_L1_2EM5);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_2MU0", &L2_L1ItemStreamer_L1_2MU0, &b_L2_L1ItemStreamer_L1_2MU0);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_2MU0_FIRSTEMPTY", &L2_L1ItemStreamer_L1_2MU0_FIRSTEMPTY, &b_L2_L1ItemStreamer_L1_2MU0_FIRSTEMPTY);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_2MU0_MU6", &L2_L1ItemStreamer_L1_2MU0_MU6, &b_L2_L1ItemStreamer_L1_2MU0_MU6);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_2MU10", &L2_L1ItemStreamer_L1_2MU10, &b_L2_L1ItemStreamer_L1_2MU10);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_2MU6", &L2_L1ItemStreamer_L1_2MU6, &b_L2_L1ItemStreamer_L1_2MU6);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_EM10", &L2_L1ItemStreamer_L1_EM10, &b_L2_L1ItemStreamer_L1_EM10);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_EM10I", &L2_L1ItemStreamer_L1_EM10I, &b_L2_L1ItemStreamer_L1_EM10I);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_EM14", &L2_L1ItemStreamer_L1_EM14, &b_L2_L1ItemStreamer_L1_EM14);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_EM2", &L2_L1ItemStreamer_L1_EM2, &b_L2_L1ItemStreamer_L1_EM2);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_EM2_MV", &L2_L1ItemStreamer_L1_EM2_MV, &b_L2_L1ItemStreamer_L1_EM2_MV);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_EM2_UNPAIRED_ISO", &L2_L1ItemStreamer_L1_EM2_UNPAIRED_ISO, &b_L2_L1ItemStreamer_L1_EM2_UNPAIRED_ISO);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_EM2_UNPAIRED_NONISO", &L2_L1ItemStreamer_L1_EM2_UNPAIRED_NONISO, &b_L2_L1ItemStreamer_L1_EM2_UNPAIRED_NONISO);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_EM3", &L2_L1ItemStreamer_L1_EM3, &b_L2_L1ItemStreamer_L1_EM3);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_EM3_EMPTY", &L2_L1ItemStreamer_L1_EM3_EMPTY, &b_L2_L1ItemStreamer_L1_EM3_EMPTY);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_EM3_FIRSTEMPTY", &L2_L1ItemStreamer_L1_EM3_FIRSTEMPTY, &b_L2_L1ItemStreamer_L1_EM3_FIRSTEMPTY);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_EM4", &L2_L1ItemStreamer_L1_EM4, &b_L2_L1ItemStreamer_L1_EM4);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_EM5", &L2_L1ItemStreamer_L1_EM5, &b_L2_L1ItemStreamer_L1_EM5);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_EM5I", &L2_L1ItemStreamer_L1_EM5I, &b_L2_L1ItemStreamer_L1_EM5I);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_MU0", &L2_L1ItemStreamer_L1_MU0, &b_L2_L1ItemStreamer_L1_MU0);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_MU0_COMM", &L2_L1ItemStreamer_L1_MU0_COMM, &b_L2_L1ItemStreamer_L1_MU0_COMM);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_MU0_COMM_EMPTY", &L2_L1ItemStreamer_L1_MU0_COMM_EMPTY, &b_L2_L1ItemStreamer_L1_MU0_COMM_EMPTY);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_MU0_COMM_FIRSTEMPTY", &L2_L1ItemStreamer_L1_MU0_COMM_FIRSTEMPTY, &b_L2_L1ItemStreamer_L1_MU0_COMM_FIRSTEMPTY);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_ISO", &L2_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_ISO, &b_L2_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_ISO);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_NONISO", &L2_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_NONISO, &b_L2_L1ItemStreamer_L1_MU0_COMM_UNPAIRED_NONISO);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_MU0_EMPTY", &L2_L1ItemStreamer_L1_MU0_EMPTY, &b_L2_L1ItemStreamer_L1_MU0_EMPTY);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_MU0_FIRSTEMPTY", &L2_L1ItemStreamer_L1_MU0_FIRSTEMPTY, &b_L2_L1ItemStreamer_L1_MU0_FIRSTEMPTY);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_MU0_MV", &L2_L1ItemStreamer_L1_MU0_MV, &b_L2_L1ItemStreamer_L1_MU0_MV);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_MU0_UNPAIRED_ISO", &L2_L1ItemStreamer_L1_MU0_UNPAIRED_ISO, &b_L2_L1ItemStreamer_L1_MU0_UNPAIRED_ISO);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_MU0_UNPAIRED_NONISO", &L2_L1ItemStreamer_L1_MU0_UNPAIRED_NONISO, &b_L2_L1ItemStreamer_L1_MU0_UNPAIRED_NONISO);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_MU10", &L2_L1ItemStreamer_L1_MU10, &b_L2_L1ItemStreamer_L1_MU10);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_MU10_FIRSTEMPTY", &L2_L1ItemStreamer_L1_MU10_FIRSTEMPTY, &b_L2_L1ItemStreamer_L1_MU10_FIRSTEMPTY);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_MU15", &L2_L1ItemStreamer_L1_MU15, &b_L2_L1ItemStreamer_L1_MU15);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_MU20", &L2_L1ItemStreamer_L1_MU20, &b_L2_L1ItemStreamer_L1_MU20);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_MU6", &L2_L1ItemStreamer_L1_MU6, &b_L2_L1ItemStreamer_L1_MU6);
    fChain->SetBranchAddress("L2_L1ItemStreamer_L1_MU6_FIRSTEMPTY", &L2_L1ItemStreamer_L1_MU6_FIRSTEMPTY, &b_L2_L1ItemStreamer_L1_MU6_FIRSTEMPTY);
    fChain->SetBranchAddress("L2_SeededStreamerL1Calo", &L2_SeededStreamerL1Calo, &b_L2_SeededStreamerL1Calo);
    fChain->SetBranchAddress("L2_em3_empty_larcalib", &L2_em3_empty_larcalib, &b_L2_em3_empty_larcalib);
    fChain->SetBranchAddress("L2_g10_loose", &L2_g10_loose, &b_L2_g10_loose);
    fChain->SetBranchAddress("L2_g5_NoCut_cosmic", &L2_g5_NoCut_cosmic, &b_L2_g5_NoCut_cosmic);
    fChain->SetBranchAddress("L2_g5_loose", &L2_g5_loose, &b_L2_g5_loose);
    fChain->SetBranchAddress("L2_mu4", &L2_mu4, &b_L2_mu4);
    fChain->SetBranchAddress("L2_mu4_IDTrkNoCut", &L2_mu4_IDTrkNoCut, &b_L2_mu4_IDTrkNoCut);
    fChain->SetBranchAddress("L2_mu4_MSonly", &L2_mu4_MSonly, &b_L2_mu4_MSonly);
    fChain->SetBranchAddress("L2_mu4_MSonly_MB2_noL2_EFFS", &L2_mu4_MSonly_MB2_noL2_EFFS, &b_L2_mu4_MSonly_MB2_noL2_EFFS);
    fChain->SetBranchAddress("L2_mu4_MSonly_cosmic", &L2_mu4_MSonly_cosmic, &b_L2_mu4_MSonly_cosmic);
    fChain->SetBranchAddress("L2_mu4_MV", &L2_mu4_MV, &b_L2_mu4_MV);
    fChain->SetBranchAddress("L2_mu4_MV_MSonly", &L2_mu4_MV_MSonly, &b_L2_mu4_MV_MSonly);
    fChain->SetBranchAddress("L2_mu4_comm_MSonly_cosmic", &L2_mu4_comm_MSonly_cosmic, &b_L2_mu4_comm_MSonly_cosmic);
    fChain->SetBranchAddress("L2_mu4_comm_cosmic", &L2_mu4_comm_cosmic, &b_L2_mu4_comm_cosmic);
    fChain->SetBranchAddress("L2_mu4_cosmic", &L2_mu4_cosmic, &b_L2_mu4_cosmic);
    fChain->SetBranchAddress("L2_mu6_cal", &L2_mu6_cal, &b_L2_mu6_cal);
    fChain->SetBranchAddress("mu_muid_n", &mu_muid_n, &b_mu_muid_n);
    fChain->SetBranchAddress("mu_muid_E", &mu_muid_E, &b_mu_muid_E);
    fChain->SetBranchAddress("mu_muid_pt", &mu_muid_pt, &b_mu_muid_pt);
    fChain->SetBranchAddress("mu_muid_m", &mu_muid_m, &b_mu_muid_m);
    fChain->SetBranchAddress("mu_muid_eta", &mu_muid_eta, &b_mu_muid_eta);
    fChain->SetBranchAddress("mu_muid_phi", &mu_muid_phi, &b_mu_muid_phi);
    fChain->SetBranchAddress("mu_muid_px", &mu_muid_px, &b_mu_muid_px);
    fChain->SetBranchAddress("mu_muid_py", &mu_muid_py, &b_mu_muid_py);
    fChain->SetBranchAddress("mu_muid_pz", &mu_muid_pz, &b_mu_muid_pz);
    fChain->SetBranchAddress("mu_muid_charge", &mu_muid_charge, &b_mu_muid_charge);
    fChain->SetBranchAddress("mu_muid_allauthor", &mu_muid_allauthor, &b_mu_muid_allauthor);
    fChain->SetBranchAddress("mu_muid_author", &mu_muid_author, &b_mu_muid_author);
    fChain->SetBranchAddress("mu_muid_matchchi2", &mu_muid_matchchi2, &b_mu_muid_matchchi2);
    fChain->SetBranchAddress("mu_muid_matchndof", &mu_muid_matchndof, &b_mu_muid_matchndof);
    fChain->SetBranchAddress("mu_muid_etcone20", &mu_muid_etcone20, &b_mu_muid_etcone20);
    fChain->SetBranchAddress("mu_muid_etcone30", &mu_muid_etcone30, &b_mu_muid_etcone30);
    fChain->SetBranchAddress("mu_muid_etcone40", &mu_muid_etcone40, &b_mu_muid_etcone40);
    fChain->SetBranchAddress("mu_muid_nucone20", &mu_muid_nucone20, &b_mu_muid_nucone20);
    fChain->SetBranchAddress("mu_muid_nucone30", &mu_muid_nucone30, &b_mu_muid_nucone30);
    fChain->SetBranchAddress("mu_muid_nucone40", &mu_muid_nucone40, &b_mu_muid_nucone40);
    fChain->SetBranchAddress("mu_muid_ptcone20", &mu_muid_ptcone20, &b_mu_muid_ptcone20);
    fChain->SetBranchAddress("mu_muid_ptcone30", &mu_muid_ptcone30, &b_mu_muid_ptcone30);
    fChain->SetBranchAddress("mu_muid_ptcone40", &mu_muid_ptcone40, &b_mu_muid_ptcone40);
    fChain->SetBranchAddress("mu_muid_energyLossPar", &mu_muid_energyLossPar, &b_mu_muid_energyLossPar);
    fChain->SetBranchAddress("mu_muid_energyLossErr", &mu_muid_energyLossErr, &b_mu_muid_energyLossErr);
    fChain->SetBranchAddress("mu_muid_etCore", &mu_muid_etCore, &b_mu_muid_etCore);
    fChain->SetBranchAddress("mu_muid_energyLossType", &mu_muid_energyLossType, &b_mu_muid_energyLossType);
    fChain->SetBranchAddress("mu_muid_bestMatch", &mu_muid_bestMatch, &b_mu_muid_bestMatch);
    fChain->SetBranchAddress("mu_muid_isStandAloneMuon", &mu_muid_isStandAloneMuon, &b_mu_muid_isStandAloneMuon);
    fChain->SetBranchAddress("mu_muid_isCombinedMuon", &mu_muid_isCombinedMuon, &b_mu_muid_isCombinedMuon);
    fChain->SetBranchAddress("mu_muid_isLowPtReconstructedMuon", &mu_muid_isLowPtReconstructedMuon, &b_mu_muid_isLowPtReconstructedMuon);
    fChain->SetBranchAddress("mu_muid_loose", &mu_muid_loose, &b_mu_muid_loose);
    fChain->SetBranchAddress("mu_muid_medium", &mu_muid_medium, &b_mu_muid_medium);
    fChain->SetBranchAddress("mu_muid_tight", &mu_muid_tight, &b_mu_muid_tight);
    fChain->SetBranchAddress("mu_muid_d0_exPV", &mu_muid_d0_exPV, &b_mu_muid_d0_exPV);
    fChain->SetBranchAddress("mu_muid_z0_exPV", &mu_muid_z0_exPV, &b_mu_muid_z0_exPV);
    fChain->SetBranchAddress("mu_muid_phi_exPV", &mu_muid_phi_exPV, &b_mu_muid_phi_exPV);
    fChain->SetBranchAddress("mu_muid_theta_exPV", &mu_muid_theta_exPV, &b_mu_muid_theta_exPV);
    fChain->SetBranchAddress("mu_muid_qoverp_exPV", &mu_muid_qoverp_exPV, &b_mu_muid_qoverp_exPV);
    fChain->SetBranchAddress("mu_muid_cb_d0_exPV", &mu_muid_cb_d0_exPV, &b_mu_muid_cb_d0_exPV);
    fChain->SetBranchAddress("mu_muid_cb_z0_exPV", &mu_muid_cb_z0_exPV, &b_mu_muid_cb_z0_exPV);
    fChain->SetBranchAddress("mu_muid_cb_phi_exPV", &mu_muid_cb_phi_exPV, &b_mu_muid_cb_phi_exPV);
    fChain->SetBranchAddress("mu_muid_cb_theta_exPV", &mu_muid_cb_theta_exPV, &b_mu_muid_cb_theta_exPV);
    fChain->SetBranchAddress("mu_muid_cb_qoverp_exPV", &mu_muid_cb_qoverp_exPV, &b_mu_muid_cb_qoverp_exPV);
    fChain->SetBranchAddress("mu_muid_id_d0_exPV", &mu_muid_id_d0_exPV, &b_mu_muid_id_d0_exPV);
    fChain->SetBranchAddress("mu_muid_id_z0_exPV", &mu_muid_id_z0_exPV, &b_mu_muid_id_z0_exPV);
    fChain->SetBranchAddress("mu_muid_id_phi_exPV", &mu_muid_id_phi_exPV, &b_mu_muid_id_phi_exPV);
    fChain->SetBranchAddress("mu_muid_id_theta_exPV", &mu_muid_id_theta_exPV, &b_mu_muid_id_theta_exPV);
    fChain->SetBranchAddress("mu_muid_id_qoverp_exPV", &mu_muid_id_qoverp_exPV, &b_mu_muid_id_qoverp_exPV);
    fChain->SetBranchAddress("mu_muid_me_d0_exPV", &mu_muid_me_d0_exPV, &b_mu_muid_me_d0_exPV);
    fChain->SetBranchAddress("mu_muid_me_z0_exPV", &mu_muid_me_z0_exPV, &b_mu_muid_me_z0_exPV);
    fChain->SetBranchAddress("mu_muid_me_phi_exPV", &mu_muid_me_phi_exPV, &b_mu_muid_me_phi_exPV);
    fChain->SetBranchAddress("mu_muid_me_theta_exPV", &mu_muid_me_theta_exPV, &b_mu_muid_me_theta_exPV);
    fChain->SetBranchAddress("mu_muid_me_qoverp_exPV", &mu_muid_me_qoverp_exPV, &b_mu_muid_me_qoverp_exPV);
    fChain->SetBranchAddress("mu_muid_ie_d0_exPV", &mu_muid_ie_d0_exPV, &b_mu_muid_ie_d0_exPV);
    fChain->SetBranchAddress("mu_muid_ie_z0_exPV", &mu_muid_ie_z0_exPV, &b_mu_muid_ie_z0_exPV);
    fChain->SetBranchAddress("mu_muid_ie_phi_exPV", &mu_muid_ie_phi_exPV, &b_mu_muid_ie_phi_exPV);
    fChain->SetBranchAddress("mu_muid_ie_theta_exPV", &mu_muid_ie_theta_exPV, &b_mu_muid_ie_theta_exPV);
    fChain->SetBranchAddress("mu_muid_ie_qoverp_exPV", &mu_muid_ie_qoverp_exPV, &b_mu_muid_ie_qoverp_exPV);
    fChain->SetBranchAddress("mu_muid_cov_d0_exPV", &mu_muid_cov_d0_exPV, &b_mu_muid_cov_d0_exPV);
    fChain->SetBranchAddress("mu_muid_cov_z0_exPV", &mu_muid_cov_z0_exPV, &b_mu_muid_cov_z0_exPV);
    fChain->SetBranchAddress("mu_muid_cov_phi_exPV", &mu_muid_cov_phi_exPV, &b_mu_muid_cov_phi_exPV);
    fChain->SetBranchAddress("mu_muid_cov_theta_exPV", &mu_muid_cov_theta_exPV, &b_mu_muid_cov_theta_exPV);
    fChain->SetBranchAddress("mu_muid_cov_qoverp_exPV", &mu_muid_cov_qoverp_exPV, &b_mu_muid_cov_qoverp_exPV);
    fChain->SetBranchAddress("mu_muid_cov_d0_z0_exPV", &mu_muid_cov_d0_z0_exPV, &b_mu_muid_cov_d0_z0_exPV);
    fChain->SetBranchAddress("mu_muid_cov_d0_phi_exPV", &mu_muid_cov_d0_phi_exPV, &b_mu_muid_cov_d0_phi_exPV);
    fChain->SetBranchAddress("mu_muid_cov_d0_theta_exPV", &mu_muid_cov_d0_theta_exPV, &b_mu_muid_cov_d0_theta_exPV);
    fChain->SetBranchAddress("mu_muid_cov_d0_qoverp_exPV", &mu_muid_cov_d0_qoverp_exPV, &b_mu_muid_cov_d0_qoverp_exPV);
    fChain->SetBranchAddress("mu_muid_cov_z0_phi_exPV", &mu_muid_cov_z0_phi_exPV, &b_mu_muid_cov_z0_phi_exPV);
    fChain->SetBranchAddress("mu_muid_cov_z0_theta_exPV", &mu_muid_cov_z0_theta_exPV, &b_mu_muid_cov_z0_theta_exPV);
    fChain->SetBranchAddress("mu_muid_cov_z0_qoverp_exPV", &mu_muid_cov_z0_qoverp_exPV, &b_mu_muid_cov_z0_qoverp_exPV);
    fChain->SetBranchAddress("mu_muid_cov_phi_theta_exPV", &mu_muid_cov_phi_theta_exPV, &b_mu_muid_cov_phi_theta_exPV);
    fChain->SetBranchAddress("mu_muid_cov_phi_qoverp_exPV", &mu_muid_cov_phi_qoverp_exPV, &b_mu_muid_cov_phi_qoverp_exPV);
    fChain->SetBranchAddress("mu_muid_cov_theta_qoverp_exPV", &mu_muid_cov_theta_qoverp_exPV, &b_mu_muid_cov_theta_qoverp_exPV);
    fChain->SetBranchAddress("mu_muid_ms_d0", &mu_muid_ms_d0, &b_mu_muid_ms_d0);
    fChain->SetBranchAddress("mu_muid_ms_z0", &mu_muid_ms_z0, &b_mu_muid_ms_z0);
    fChain->SetBranchAddress("mu_muid_ms_phi", &mu_muid_ms_phi, &b_mu_muid_ms_phi);
    fChain->SetBranchAddress("mu_muid_ms_theta", &mu_muid_ms_theta, &b_mu_muid_ms_theta);
    fChain->SetBranchAddress("mu_muid_ms_qoverp", &mu_muid_ms_qoverp, &b_mu_muid_ms_qoverp);
    fChain->SetBranchAddress("mu_muid_id_d0", &mu_muid_id_d0, &b_mu_muid_id_d0);
    fChain->SetBranchAddress("mu_muid_id_z0", &mu_muid_id_z0, &b_mu_muid_id_z0);
    fChain->SetBranchAddress("mu_muid_id_phi", &mu_muid_id_phi, &b_mu_muid_id_phi);
    fChain->SetBranchAddress("mu_muid_id_theta", &mu_muid_id_theta, &b_mu_muid_id_theta);
    fChain->SetBranchAddress("mu_muid_id_qoverp", &mu_muid_id_qoverp, &b_mu_muid_id_qoverp);
    fChain->SetBranchAddress("mu_muid_me_d0", &mu_muid_me_d0, &b_mu_muid_me_d0);
    fChain->SetBranchAddress("mu_muid_me_z0", &mu_muid_me_z0, &b_mu_muid_me_z0);
    fChain->SetBranchAddress("mu_muid_me_phi", &mu_muid_me_phi, &b_mu_muid_me_phi);
    fChain->SetBranchAddress("mu_muid_me_theta", &mu_muid_me_theta, &b_mu_muid_me_theta);
    fChain->SetBranchAddress("mu_muid_me_qoverp", &mu_muid_me_qoverp, &b_mu_muid_me_qoverp);
    fChain->SetBranchAddress("mu_muid_ie_d0", &mu_muid_ie_d0, &b_mu_muid_ie_d0);
    fChain->SetBranchAddress("mu_muid_ie_z0", &mu_muid_ie_z0, &b_mu_muid_ie_z0);
    fChain->SetBranchAddress("mu_muid_ie_phi", &mu_muid_ie_phi, &b_mu_muid_ie_phi);
    fChain->SetBranchAddress("mu_muid_ie_theta", &mu_muid_ie_theta, &b_mu_muid_ie_theta);
    fChain->SetBranchAddress("mu_muid_ie_qoverp", &mu_muid_ie_qoverp, &b_mu_muid_ie_qoverp);
    fChain->SetBranchAddress("mu_muid_nBLHits", &mu_muid_nBLHits, &b_mu_muid_nBLHits);
    fChain->SetBranchAddress("mu_muid_nPixHits", &mu_muid_nPixHits, &b_mu_muid_nPixHits);
    fChain->SetBranchAddress("mu_muid_nSCTHits", &mu_muid_nSCTHits, &b_mu_muid_nSCTHits);
    fChain->SetBranchAddress("mu_muid_nTRTHits", &mu_muid_nTRTHits, &b_mu_muid_nTRTHits);
    fChain->SetBranchAddress("mu_muid_nTRTHighTHits", &mu_muid_nTRTHighTHits, &b_mu_muid_nTRTHighTHits);
    fChain->SetBranchAddress("mu_muid_nBLSharedHits", &mu_muid_nBLSharedHits, &b_mu_muid_nBLSharedHits);
    fChain->SetBranchAddress("mu_muid_nPixSharedHits", &mu_muid_nPixSharedHits, &b_mu_muid_nPixSharedHits);
    fChain->SetBranchAddress("mu_muid_nPixHoles", &mu_muid_nPixHoles, &b_mu_muid_nPixHoles);
    fChain->SetBranchAddress("mu_muid_nSCTSharedHits", &mu_muid_nSCTSharedHits, &b_mu_muid_nSCTSharedHits);
    fChain->SetBranchAddress("mu_muid_nSCTHoles", &mu_muid_nSCTHoles, &b_mu_muid_nSCTHoles);
    fChain->SetBranchAddress("mu_muid_nTRTOutliers", &mu_muid_nTRTOutliers, &b_mu_muid_nTRTOutliers);
    fChain->SetBranchAddress("mu_muid_nTRTHighTOutliers", &mu_muid_nTRTHighTOutliers, &b_mu_muid_nTRTHighTOutliers);
    fChain->SetBranchAddress("mu_muid_nMDTHits", &mu_muid_nMDTHits, &b_mu_muid_nMDTHits);
    fChain->SetBranchAddress("mu_muid_nMDTHoles", &mu_muid_nMDTHoles, &b_mu_muid_nMDTHoles);
    fChain->SetBranchAddress("mu_muid_nCSCEtaHits", &mu_muid_nCSCEtaHits, &b_mu_muid_nCSCEtaHits);
    fChain->SetBranchAddress("mu_muid_nCSCEtaHoles", &mu_muid_nCSCEtaHoles, &b_mu_muid_nCSCEtaHoles);
    fChain->SetBranchAddress("mu_muid_nCSCPhiHits", &mu_muid_nCSCPhiHits, &b_mu_muid_nCSCPhiHits);
    fChain->SetBranchAddress("mu_muid_nCSCPhiHoles", &mu_muid_nCSCPhiHoles, &b_mu_muid_nCSCPhiHoles);
    fChain->SetBranchAddress("mu_muid_nRPCEtaHits", &mu_muid_nRPCEtaHits, &b_mu_muid_nRPCEtaHits);
    fChain->SetBranchAddress("mu_muid_nRPCEtaHoles", &mu_muid_nRPCEtaHoles, &b_mu_muid_nRPCEtaHoles);
    fChain->SetBranchAddress("mu_muid_nRPCPhiHits", &mu_muid_nRPCPhiHits, &b_mu_muid_nRPCPhiHits);
    fChain->SetBranchAddress("mu_muid_nRPCPhiHoles", &mu_muid_nRPCPhiHoles, &b_mu_muid_nRPCPhiHoles);
    fChain->SetBranchAddress("mu_muid_nTGCEtaHits", &mu_muid_nTGCEtaHits, &b_mu_muid_nTGCEtaHits);
    fChain->SetBranchAddress("mu_muid_nTGCEtaHoles", &mu_muid_nTGCEtaHoles, &b_mu_muid_nTGCEtaHoles);
    fChain->SetBranchAddress("mu_muid_nTGCPhiHits", &mu_muid_nTGCPhiHits, &b_mu_muid_nTGCPhiHits);
    fChain->SetBranchAddress("mu_muid_nTGCPhiHoles", &mu_muid_nTGCPhiHoles, &b_mu_muid_nTGCPhiHoles);
    fChain->SetBranchAddress("mu_muid_nGangedPixels", &mu_muid_nGangedPixels, &b_mu_muid_nGangedPixels);
    fChain->SetBranchAddress("mu_muid_nOutliersOnTrack", &mu_muid_nOutliersOnTrack, &b_mu_muid_nOutliersOnTrack);
    fChain->SetBranchAddress("mu_muid_nMDTBIHits", &mu_muid_nMDTBIHits, &b_mu_muid_nMDTBIHits);
    fChain->SetBranchAddress("mu_muid_nMDTBMHits", &mu_muid_nMDTBMHits, &b_mu_muid_nMDTBMHits);
    fChain->SetBranchAddress("mu_muid_nMDTBOHits", &mu_muid_nMDTBOHits, &b_mu_muid_nMDTBOHits);
    fChain->SetBranchAddress("mu_muid_nMDTBEEHits", &mu_muid_nMDTBEEHits, &b_mu_muid_nMDTBEEHits);
    fChain->SetBranchAddress("mu_muid_nMDTBIS78Hits", &mu_muid_nMDTBIS78Hits, &b_mu_muid_nMDTBIS78Hits);
    fChain->SetBranchAddress("mu_muid_nMDTEIHits", &mu_muid_nMDTEIHits, &b_mu_muid_nMDTEIHits);
    fChain->SetBranchAddress("mu_muid_nMDTEMHits", &mu_muid_nMDTEMHits, &b_mu_muid_nMDTEMHits);
    fChain->SetBranchAddress("mu_muid_nMDTEOHits", &mu_muid_nMDTEOHits, &b_mu_muid_nMDTEOHits);
    fChain->SetBranchAddress("mu_muid_nMDTEEHits", &mu_muid_nMDTEEHits, &b_mu_muid_nMDTEEHits);
    fChain->SetBranchAddress("mu_muid_nRPCLayer1EtaHits", &mu_muid_nRPCLayer1EtaHits, &b_mu_muid_nRPCLayer1EtaHits);
    fChain->SetBranchAddress("mu_muid_nRPCLayer2EtaHits", &mu_muid_nRPCLayer2EtaHits, &b_mu_muid_nRPCLayer2EtaHits);
    fChain->SetBranchAddress("mu_muid_nRPCLayer3EtaHits", &mu_muid_nRPCLayer3EtaHits, &b_mu_muid_nRPCLayer3EtaHits);
    fChain->SetBranchAddress("mu_muid_nRPCLayer1PhiHits", &mu_muid_nRPCLayer1PhiHits, &b_mu_muid_nRPCLayer1PhiHits);
    fChain->SetBranchAddress("mu_muid_nRPCLayer2PhiHits", &mu_muid_nRPCLayer2PhiHits, &b_mu_muid_nRPCLayer2PhiHits);
    fChain->SetBranchAddress("mu_muid_nRPCLayer3PhiHits", &mu_muid_nRPCLayer3PhiHits, &b_mu_muid_nRPCLayer3PhiHits);
    fChain->SetBranchAddress("mu_muid_nTGCLayer1EtaHits", &mu_muid_nTGCLayer1EtaHits, &b_mu_muid_nTGCLayer1EtaHits);
    fChain->SetBranchAddress("mu_muid_nTGCLayer2EtaHits", &mu_muid_nTGCLayer2EtaHits, &b_mu_muid_nTGCLayer2EtaHits);
    fChain->SetBranchAddress("mu_muid_nTGCLayer3EtaHits", &mu_muid_nTGCLayer3EtaHits, &b_mu_muid_nTGCLayer3EtaHits);
    fChain->SetBranchAddress("mu_muid_nTGCLayer4EtaHits", &mu_muid_nTGCLayer4EtaHits, &b_mu_muid_nTGCLayer4EtaHits);
    fChain->SetBranchAddress("mu_muid_nTGCLayer1PhiHits", &mu_muid_nTGCLayer1PhiHits, &b_mu_muid_nTGCLayer1PhiHits);
    fChain->SetBranchAddress("mu_muid_nTGCLayer2PhiHits", &mu_muid_nTGCLayer2PhiHits, &b_mu_muid_nTGCLayer2PhiHits);
    fChain->SetBranchAddress("mu_muid_nTGCLayer3PhiHits", &mu_muid_nTGCLayer3PhiHits, &b_mu_muid_nTGCLayer3PhiHits);
    fChain->SetBranchAddress("mu_muid_nTGCLayer4PhiHits", &mu_muid_nTGCLayer4PhiHits, &b_mu_muid_nTGCLayer4PhiHits);
    fChain->SetBranchAddress("mu_muid_barrelSectors", &mu_muid_barrelSectors, &b_mu_muid_barrelSectors);
    fChain->SetBranchAddress("mu_muid_endcapSectors", &mu_muid_endcapSectors, &b_mu_muid_endcapSectors);
    fChain->SetBranchAddress("mu_muid_trackd0", &mu_muid_trackd0, &b_mu_muid_trackd0);
    fChain->SetBranchAddress("mu_muid_trackz0", &mu_muid_trackz0, &b_mu_muid_trackz0);
    fChain->SetBranchAddress("mu_muid_trackphi", &mu_muid_trackphi, &b_mu_muid_trackphi);
    fChain->SetBranchAddress("mu_muid_tracktheta", &mu_muid_tracktheta, &b_mu_muid_tracktheta);
    fChain->SetBranchAddress("mu_muid_trackqoverp", &mu_muid_trackqoverp, &b_mu_muid_trackqoverp);
    fChain->SetBranchAddress("mu_muid_trackcov_d0", &mu_muid_trackcov_d0, &b_mu_muid_trackcov_d0);
    fChain->SetBranchAddress("mu_muid_trackcov_z0", &mu_muid_trackcov_z0, &b_mu_muid_trackcov_z0);
    fChain->SetBranchAddress("mu_muid_trackcov_phi", &mu_muid_trackcov_phi, &b_mu_muid_trackcov_phi);
    fChain->SetBranchAddress("mu_muid_trackcov_theta", &mu_muid_trackcov_theta, &b_mu_muid_trackcov_theta);
    fChain->SetBranchAddress("mu_muid_trackcov_qoverp", &mu_muid_trackcov_qoverp, &b_mu_muid_trackcov_qoverp);
    fChain->SetBranchAddress("mu_muid_trackcov_d0_z0", &mu_muid_trackcov_d0_z0, &b_mu_muid_trackcov_d0_z0);
    fChain->SetBranchAddress("mu_muid_trackcov_d0_phi", &mu_muid_trackcov_d0_phi, &b_mu_muid_trackcov_d0_phi);
    fChain->SetBranchAddress("mu_muid_trackcov_d0_theta", &mu_muid_trackcov_d0_theta, &b_mu_muid_trackcov_d0_theta);
    fChain->SetBranchAddress("mu_muid_trackcov_d0_qoverp", &mu_muid_trackcov_d0_qoverp, &b_mu_muid_trackcov_d0_qoverp);
    fChain->SetBranchAddress("mu_muid_trackcov_z0_phi", &mu_muid_trackcov_z0_phi, &b_mu_muid_trackcov_z0_phi);
    fChain->SetBranchAddress("mu_muid_trackcov_z0_theta", &mu_muid_trackcov_z0_theta, &b_mu_muid_trackcov_z0_theta);
    fChain->SetBranchAddress("mu_muid_trackcov_z0_qoverp", &mu_muid_trackcov_z0_qoverp, &b_mu_muid_trackcov_z0_qoverp);
    fChain->SetBranchAddress("mu_muid_trackcov_phi_theta", &mu_muid_trackcov_phi_theta, &b_mu_muid_trackcov_phi_theta);
    fChain->SetBranchAddress("mu_muid_trackcov_phi_qoverp", &mu_muid_trackcov_phi_qoverp, &b_mu_muid_trackcov_phi_qoverp);
    fChain->SetBranchAddress("mu_muid_trackcov_theta_qoverp", &mu_muid_trackcov_theta_qoverp, &b_mu_muid_trackcov_theta_qoverp);
    fChain->SetBranchAddress("mu_muid_trackfitchi2", &mu_muid_trackfitchi2, &b_mu_muid_trackfitchi2);
    fChain->SetBranchAddress("mu_muid_trackfitndof", &mu_muid_trackfitndof, &b_mu_muid_trackfitndof);
    fChain->SetBranchAddress("mu_muid_hastrack", &mu_muid_hastrack, &b_mu_muid_hastrack);
    fChain->SetBranchAddress("mu_muid_EF_dr", &mu_muid_EF_dr, &b_mu_muid_EF_dr);
    fChain->SetBranchAddress("mu_muid_EF_cb_eta", &mu_muid_EF_cb_eta, &b_mu_muid_EF_cb_eta);
    fChain->SetBranchAddress("mu_muid_EF_cb_phi", &mu_muid_EF_cb_phi, &b_mu_muid_EF_cb_phi);
    fChain->SetBranchAddress("mu_muid_EF_cb_pt", &mu_muid_EF_cb_pt, &b_mu_muid_EF_cb_pt);
    fChain->SetBranchAddress("mu_muid_EF_ms_eta", &mu_muid_EF_ms_eta, &b_mu_muid_EF_ms_eta);
    fChain->SetBranchAddress("mu_muid_EF_ms_phi", &mu_muid_EF_ms_phi, &b_mu_muid_EF_ms_phi);
    fChain->SetBranchAddress("mu_muid_EF_ms_pt", &mu_muid_EF_ms_pt, &b_mu_muid_EF_ms_pt);
    fChain->SetBranchAddress("mu_muid_EF_me_eta", &mu_muid_EF_me_eta, &b_mu_muid_EF_me_eta);
    fChain->SetBranchAddress("mu_muid_EF_me_phi", &mu_muid_EF_me_phi, &b_mu_muid_EF_me_phi);
    fChain->SetBranchAddress("mu_muid_EF_me_pt", &mu_muid_EF_me_pt, &b_mu_muid_EF_me_pt);
    fChain->SetBranchAddress("mu_muid_EF_matched", &mu_muid_EF_matched, &b_mu_muid_EF_matched);
    fChain->SetBranchAddress("mu_muid_L2CB_dr", &mu_muid_L2CB_dr, &b_mu_muid_L2CB_dr);
    fChain->SetBranchAddress("mu_muid_L2CB_pt", &mu_muid_L2CB_pt, &b_mu_muid_L2CB_pt);
    fChain->SetBranchAddress("mu_muid_L2CB_eta", &mu_muid_L2CB_eta, &b_mu_muid_L2CB_eta);
    fChain->SetBranchAddress("mu_muid_L2CB_phi", &mu_muid_L2CB_phi, &b_mu_muid_L2CB_phi);
    fChain->SetBranchAddress("mu_muid_L2CB_id_pt", &mu_muid_L2CB_id_pt, &b_mu_muid_L2CB_id_pt);
    fChain->SetBranchAddress("mu_muid_L2CB_ms_pt", &mu_muid_L2CB_ms_pt, &b_mu_muid_L2CB_ms_pt);
    fChain->SetBranchAddress("mu_muid_L2CB_nPixHits", &mu_muid_L2CB_nPixHits, &b_mu_muid_L2CB_nPixHits);
    fChain->SetBranchAddress("mu_muid_L2CB_nSCTHits", &mu_muid_L2CB_nSCTHits, &b_mu_muid_L2CB_nSCTHits);
    fChain->SetBranchAddress("mu_muid_L2CB_nTRTHits", &mu_muid_L2CB_nTRTHits, &b_mu_muid_L2CB_nTRTHits);
    fChain->SetBranchAddress("mu_muid_L2CB_nTRTHighTHits", &mu_muid_L2CB_nTRTHighTHits, &b_mu_muid_L2CB_nTRTHighTHits);
    fChain->SetBranchAddress("mu_muid_L2CB_matched", &mu_muid_L2CB_matched, &b_mu_muid_L2CB_matched);
    fChain->SetBranchAddress("mu_muid_L1_dr", &mu_muid_L1_dr, &b_mu_muid_L1_dr);
    fChain->SetBranchAddress("mu_muid_L1_pt", &mu_muid_L1_pt, &b_mu_muid_L1_pt);
    fChain->SetBranchAddress("mu_muid_L1_eta", &mu_muid_L1_eta, &b_mu_muid_L1_eta);
    fChain->SetBranchAddress("mu_muid_L1_phi", &mu_muid_L1_phi, &b_mu_muid_L1_phi);
    fChain->SetBranchAddress("mu_muid_L1_thrNumber", &mu_muid_L1_thrNumber, &b_mu_muid_L1_thrNumber);
    fChain->SetBranchAddress("mu_muid_L1_RoINumber", &mu_muid_L1_RoINumber, &b_mu_muid_L1_RoINumber);
    fChain->SetBranchAddress("mu_muid_L1_sectorAddress", &mu_muid_L1_sectorAddress, &b_mu_muid_L1_sectorAddress);
    fChain->SetBranchAddress("mu_muid_L1_firstCandidate", &mu_muid_L1_firstCandidate, &b_mu_muid_L1_firstCandidate);
    fChain->SetBranchAddress("mu_muid_L1_moreCandInRoI", &mu_muid_L1_moreCandInRoI, &b_mu_muid_L1_moreCandInRoI);
    fChain->SetBranchAddress("mu_muid_L1_moreCandInSector", &mu_muid_L1_moreCandInSector, &b_mu_muid_L1_moreCandInSector);
    fChain->SetBranchAddress("mu_muid_L1_source", &mu_muid_L1_source, &b_mu_muid_L1_source);
    fChain->SetBranchAddress("mu_muid_L1_hemisphere", &mu_muid_L1_hemisphere, &b_mu_muid_L1_hemisphere);
    fChain->SetBranchAddress("mu_muid_L1_matched", &mu_muid_L1_matched, &b_mu_muid_L1_matched);
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
    fChain->SetBranchAddress("trig_L2_resurrected", &trig_L2_resurrected, &b_trig_L2_resurrected);
    fChain->SetBranchAddress("trig_EF_resurrected", &trig_EF_resurrected, &b_trig_EF_resurrected);
    fChain->SetBranchAddress("trig_L2_passedThrough", &trig_L2_passedThrough, &b_trig_L2_passedThrough);
    fChain->SetBranchAddress("trig_EF_passedThrough", &trig_EF_passedThrough, &b_trig_EF_passedThrough);
    fChain->SetBranchAddress("L1_2J10", &L1_2J10, &b_L1_2J10);
    fChain->SetBranchAddress("L1_2J15", &L1_2J15, &b_L1_2J15);
    fChain->SetBranchAddress("L1_2J5", &L1_2J5, &b_L1_2J5);
    fChain->SetBranchAddress("L1_J10", &L1_J10, &b_L1_J10);
    fChain->SetBranchAddress("L1_J15", &L1_J15, &b_L1_J15);
    fChain->SetBranchAddress("L1_J30", &L1_J30, &b_L1_J30);
    fChain->SetBranchAddress("L1_J5", &L1_J5, &b_L1_J5);
    fChain->SetBranchAddress("L1_J55", &L1_J55, &b_L1_J55);
    fChain->SetBranchAddress("L1_J75", &L1_J75, &b_L1_J75);
    fChain->SetBranchAddress("L1_J95", &L1_J95, &b_L1_J95);
    fChain->SetBranchAddress("trig_L1_jet_n", &trig_L1_jet_n, &b_trig_L1_jet_n);
    fChain->SetBranchAddress("trig_L1_jet_eta", &trig_L1_jet_eta, &b_trig_L1_jet_eta);
    fChain->SetBranchAddress("trig_L1_jet_phi", &trig_L1_jet_phi, &b_trig_L1_jet_phi);
    fChain->SetBranchAddress("trig_L1_jet_thrNames", &trig_L1_jet_thrNames, &b_trig_L1_jet_thrNames);
    fChain->SetBranchAddress("trig_L1_jet_thrValues", &trig_L1_jet_thrValues, &b_trig_L1_jet_thrValues);
    fChain->SetBranchAddress("trig_L1_jet_thrPattern", &trig_L1_jet_thrPattern, &b_trig_L1_jet_thrPattern);
    fChain->SetBranchAddress("trig_L1_jet_et4x4", &trig_L1_jet_et4x4, &b_trig_L1_jet_et4x4);
    fChain->SetBranchAddress("trig_L1_jet_et6x6", &trig_L1_jet_et6x6, &b_trig_L1_jet_et6x6);
    fChain->SetBranchAddress("trig_L1_jet_et8x8", &trig_L1_jet_et8x8, &b_trig_L1_jet_et8x8);
    fChain->SetBranchAddress("trig_L1_jet_RoIWord", &trig_L1_jet_RoIWord, &b_trig_L1_jet_RoIWord);
    fChain->SetBranchAddress("trig_L1_esum_thrNames", &trig_L1_esum_thrNames, &b_trig_L1_esum_thrNames);
    fChain->SetBranchAddress("trig_L1_esum_energyX", &trig_L1_esum_energyX, &b_trig_L1_esum_energyX);
    fChain->SetBranchAddress("trig_L1_esum_energyY", &trig_L1_esum_energyY, &b_trig_L1_esum_energyY);
    fChain->SetBranchAddress("trig_L1_esum_energyT", &trig_L1_esum_energyT, &b_trig_L1_esum_energyT);
    fChain->SetBranchAddress("trig_L1_esum_overflowX", &trig_L1_esum_overflowX, &b_trig_L1_esum_overflowX);
    fChain->SetBranchAddress("trig_L1_esum_overflowY", &trig_L1_esum_overflowY, &b_trig_L1_esum_overflowY);
    fChain->SetBranchAddress("trig_L1_esum_overflowT", &trig_L1_esum_overflowT, &b_trig_L1_esum_overflowT);
    fChain->SetBranchAddress("trig_L1_esum_RoIWord0", &trig_L1_esum_RoIWord0, &b_trig_L1_esum_RoIWord0);
    fChain->SetBranchAddress("trig_L1_esum_RoIWord1", &trig_L1_esum_RoIWord1, &b_trig_L1_esum_RoIWord1);
    fChain->SetBranchAddress("trig_L1_esum_RoIWord2", &trig_L1_esum_RoIWord2, &b_trig_L1_esum_RoIWord2);
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
    fChain->SetBranchAddress("trig_L2_jet_ehad0", &trig_L2_jet_ehad0, &b_trig_L2_jet_ehad0);
    fChain->SetBranchAddress("trig_L2_jet_eem0", &trig_L2_jet_eem0, &b_trig_L2_jet_eem0);
    fChain->SetBranchAddress("trtRDO_countRDOhitsInEvent", &trtRDO_countRDOhitsInEvent, &b_trtRDO_countRDOhitsInEvent);
    fChain->SetBranchAddress("trtRDO_countBarrelhitsInEvent", &trtRDO_countBarrelhitsInEvent, &b_trtRDO_countBarrelhitsInEvent);
    fChain->SetBranchAddress("trtRDO_countEndCaphitsInEvent", &trtRDO_countEndCaphitsInEvent, &b_trtRDO_countEndCaphitsInEvent);
    fChain->SetBranchAddress("trtRDO_countEndCapAhitsInEvent", &trtRDO_countEndCapAhitsInEvent, &b_trtRDO_countEndCapAhitsInEvent);
    fChain->SetBranchAddress("trtRDO_countEndCapChitsInEvent", &trtRDO_countEndCapChitsInEvent, &b_trtRDO_countEndCapChitsInEvent);
    fChain->SetBranchAddress("trtRDO_countdeadstraws", &trtRDO_countdeadstraws, &b_trtRDO_countdeadstraws);
    fChain->SetBranchAddress("vx_n", &vx_n, &b_vx_n);
    fChain->SetBranchAddress("vx_x", &vx_x, &b_vx_x);
    fChain->SetBranchAddress("vx_y", &vx_y, &b_vx_y);
    fChain->SetBranchAddress("vx_z", &vx_z, &b_vx_z);
    fChain->SetBranchAddress("vx_cov_x", &vx_cov_x, &b_vx_cov_x);
    fChain->SetBranchAddress("vx_cov_y", &vx_cov_y, &b_vx_cov_y);
    fChain->SetBranchAddress("vx_cov_z", &vx_cov_z, &b_vx_cov_z);
    fChain->SetBranchAddress("vx_chi2", &vx_chi2, &b_vx_chi2);
    fChain->SetBranchAddress("vx_ndof", &vx_ndof, &b_vx_ndof);
    fChain->SetBranchAddress("vx_px", &vx_px, &b_vx_px);
    fChain->SetBranchAddress("vx_py", &vx_py, &b_vx_py);
    fChain->SetBranchAddress("vx_pz", &vx_pz, &b_vx_pz);
    fChain->SetBranchAddress("vx_E", &vx_E, &b_vx_E);
    fChain->SetBranchAddress("vx_m", &vx_m, &b_vx_m);
    fChain->SetBranchAddress("vx_nTracks", &vx_nTracks, &b_vx_nTracks);
    fChain->SetBranchAddress("vx_sumPt", &vx_sumPt, &b_vx_sumPt);
    fChain->SetBranchAddress("vx_type", &vx_type, &b_vx_type);
    fChain->SetBranchAddress("vx_trk_n", &vx_trk_n, &b_vx_trk_n);
    fChain->SetBranchAddress("vx_trk_chi2", &vx_trk_chi2, &b_vx_trk_chi2);
    fChain->SetBranchAddress("vx_trk_d0", &vx_trk_d0, &b_vx_trk_d0);
    fChain->SetBranchAddress("vx_trk_z0", &vx_trk_z0, &b_vx_trk_z0);
    fChain->SetBranchAddress("vx_trk_unbiased_d0", &vx_trk_unbiased_d0, &b_vx_trk_unbiased_d0);
    fChain->SetBranchAddress("vx_trk_unbiased_z0", &vx_trk_unbiased_z0, &b_vx_trk_unbiased_z0);
    fChain->SetBranchAddress("vx_trk_err_unbiased_d0", &vx_trk_err_unbiased_d0, &b_vx_trk_err_unbiased_d0);
    fChain->SetBranchAddress("vx_trk_err_unbiased_z0", &vx_trk_err_unbiased_z0, &b_vx_trk_err_unbiased_z0);
    fChain->SetBranchAddress("vx_trk_phi", &vx_trk_phi, &b_vx_trk_phi);
    fChain->SetBranchAddress("vx_trk_theta", &vx_trk_theta, &b_vx_trk_theta);
    fChain->SetBranchAddress("vx_trk_weight", &vx_trk_weight, &b_vx_trk_weight);
    fChain->SetBranchAddress("vx_trk_index", &vx_trk_index, &b_vx_trk_index);
    fChain->SetBranchAddress("el_n", &el_n, &b_el_n);
    fChain->SetBranchAddress("el_E", &el_E, &b_el_E);
    fChain->SetBranchAddress("el_Et", &el_Et, &b_el_Et);
    fChain->SetBranchAddress("el_pt", &el_pt, &b_el_pt);
    fChain->SetBranchAddress("el_m", &el_m, &b_el_m);
    fChain->SetBranchAddress("el_eta", &el_eta, &b_el_eta);
    fChain->SetBranchAddress("el_phi", &el_phi, &b_el_phi);
    fChain->SetBranchAddress("el_px", &el_px, &b_el_px);
    fChain->SetBranchAddress("el_py", &el_py, &b_el_py);
    fChain->SetBranchAddress("el_pz", &el_pz, &b_el_pz);
    fChain->SetBranchAddress("el_charge", &el_charge, &b_el_charge);
    fChain->SetBranchAddress("el_author", &el_author, &b_el_author);
    fChain->SetBranchAddress("el_isEM", &el_isEM, &b_el_isEM);
    fChain->SetBranchAddress("el_OQ", &el_OQ, &b_el_OQ);
    fChain->SetBranchAddress("el_convFlag", &el_convFlag, &b_el_convFlag);
    fChain->SetBranchAddress("el_isConv", &el_isConv, &b_el_isConv);
    fChain->SetBranchAddress("el_nConv", &el_nConv, &b_el_nConv);
    fChain->SetBranchAddress("el_nSingleTrackConv", &el_nSingleTrackConv, &b_el_nSingleTrackConv);
    fChain->SetBranchAddress("el_nDoubleTrackConv", &el_nDoubleTrackConv, &b_el_nDoubleTrackConv);
    fChain->SetBranchAddress("el_loose", &el_loose, &b_el_loose);
    fChain->SetBranchAddress("el_medium", &el_medium, &b_el_medium);
    fChain->SetBranchAddress("el_mediumIso", &el_mediumIso, &b_el_mediumIso);
    fChain->SetBranchAddress("el_tight", &el_tight, &b_el_tight);
    fChain->SetBranchAddress("el_tightIso", &el_tightIso, &b_el_tightIso);
    fChain->SetBranchAddress("el_goodOQ", &el_goodOQ, &b_el_goodOQ);
    fChain->SetBranchAddress("el_Ethad", &el_Ethad, &b_el_Ethad);
    fChain->SetBranchAddress("el_Ethad1", &el_Ethad1, &b_el_Ethad1);
    fChain->SetBranchAddress("el_f1", &el_f1, &b_el_f1);
    fChain->SetBranchAddress("el_f1core", &el_f1core, &b_el_f1core);
    fChain->SetBranchAddress("el_Emins1", &el_Emins1, &b_el_Emins1);
    fChain->SetBranchAddress("el_fside", &el_fside, &b_el_fside);
    fChain->SetBranchAddress("el_Emax2", &el_Emax2, &b_el_Emax2);
    fChain->SetBranchAddress("el_ws3", &el_ws3, &b_el_ws3);
    fChain->SetBranchAddress("el_wstot", &el_wstot, &b_el_wstot);
    fChain->SetBranchAddress("el_emaxs1", &el_emaxs1, &b_el_emaxs1);
    fChain->SetBranchAddress("el_deltaEs", &el_deltaEs, &b_el_deltaEs);
    fChain->SetBranchAddress("el_E233", &el_E233, &b_el_E233);
    fChain->SetBranchAddress("el_E237", &el_E237, &b_el_E237);
    fChain->SetBranchAddress("el_E277", &el_E277, &b_el_E277);
    fChain->SetBranchAddress("el_weta2", &el_weta2, &b_el_weta2);
    fChain->SetBranchAddress("el_f3", &el_f3, &b_el_f3);
    fChain->SetBranchAddress("el_f3core", &el_f3core, &b_el_f3core);
    fChain->SetBranchAddress("el_rphiallcalo", &el_rphiallcalo, &b_el_rphiallcalo);
    fChain->SetBranchAddress("el_Etcone45", &el_Etcone45, &b_el_Etcone45);
    fChain->SetBranchAddress("el_Etcone20", &el_Etcone20, &b_el_Etcone20);
    fChain->SetBranchAddress("el_Etcone30", &el_Etcone30, &b_el_Etcone30);
    fChain->SetBranchAddress("el_Etcone40", &el_Etcone40, &b_el_Etcone40);
    fChain->SetBranchAddress("el_ptcone30", &el_ptcone30, &b_el_ptcone30);
    fChain->SetBranchAddress("el_convanglematch", &el_convanglematch, &b_el_convanglematch);
    fChain->SetBranchAddress("el_convtrackmatch", &el_convtrackmatch, &b_el_convtrackmatch);
    fChain->SetBranchAddress("el_pos7", &el_pos7, &b_el_pos7);
    fChain->SetBranchAddress("el_etacorrmag", &el_etacorrmag, &b_el_etacorrmag);
    fChain->SetBranchAddress("el_deltaeta1", &el_deltaeta1, &b_el_deltaeta1);
    fChain->SetBranchAddress("el_deltaeta2", &el_deltaeta2, &b_el_deltaeta2);
    fChain->SetBranchAddress("el_deltaphi2", &el_deltaphi2, &b_el_deltaphi2);
    fChain->SetBranchAddress("el_deltaphiRescaled", &el_deltaphiRescaled, &b_el_deltaphiRescaled);
    fChain->SetBranchAddress("el_deltaPhiRot", &el_deltaPhiRot, &b_el_deltaPhiRot);
    fChain->SetBranchAddress("el_expectHitInBLayer", &el_expectHitInBLayer, &b_el_expectHitInBLayer);
    fChain->SetBranchAddress("el_reta", &el_reta, &b_el_reta);
    fChain->SetBranchAddress("el_rphi", &el_rphi, &b_el_rphi);
    fChain->SetBranchAddress("el_EtringnoisedR03sig2", &el_EtringnoisedR03sig2, &b_el_EtringnoisedR03sig2);
    fChain->SetBranchAddress("el_EtringnoisedR03sig3", &el_EtringnoisedR03sig3, &b_el_EtringnoisedR03sig3);
    fChain->SetBranchAddress("el_EtringnoisedR03sig4", &el_EtringnoisedR03sig4, &b_el_EtringnoisedR03sig4);
    fChain->SetBranchAddress("el_isolationlikelihoodjets", &el_isolationlikelihoodjets, &b_el_isolationlikelihoodjets);
    fChain->SetBranchAddress("el_isolationlikelihoodhqelectrons", &el_isolationlikelihoodhqelectrons, &b_el_isolationlikelihoodhqelectrons);
    fChain->SetBranchAddress("el_electronweight", &el_electronweight, &b_el_electronweight);
    fChain->SetBranchAddress("el_electronbgweight", &el_electronbgweight, &b_el_electronbgweight);
    fChain->SetBranchAddress("el_softeweight", &el_softeweight, &b_el_softeweight);
    fChain->SetBranchAddress("el_softebgweight", &el_softebgweight, &b_el_softebgweight);
    fChain->SetBranchAddress("el_neuralnet", &el_neuralnet, &b_el_neuralnet);
    fChain->SetBranchAddress("el_Hmatrix", &el_Hmatrix, &b_el_Hmatrix);
    fChain->SetBranchAddress("el_Hmatrix5", &el_Hmatrix5, &b_el_Hmatrix5);
    fChain->SetBranchAddress("el_adaboost", &el_adaboost, &b_el_adaboost);
    fChain->SetBranchAddress("el_softeneuralnet", &el_softeneuralnet, &b_el_softeneuralnet);
    fChain->SetBranchAddress("el_zvertex", &el_zvertex, &b_el_zvertex);
    fChain->SetBranchAddress("el_errz", &el_errz, &b_el_errz);
    fChain->SetBranchAddress("el_etap", &el_etap, &b_el_etap);
    fChain->SetBranchAddress("el_depth", &el_depth, &b_el_depth);
    fChain->SetBranchAddress("el_refittedTrack_n", &el_refittedTrack_n, &b_el_refittedTrack_n);
    fChain->SetBranchAddress("el_refittedTrack_author", &el_refittedTrack_author, &b_el_refittedTrack_author);
    fChain->SetBranchAddress("el_refittedTrack_chi2", &el_refittedTrack_chi2, &b_el_refittedTrack_chi2);
    fChain->SetBranchAddress("el_refittedTrack_qoverp", &el_refittedTrack_qoverp, &b_el_refittedTrack_qoverp);
    fChain->SetBranchAddress("el_refittedTrack_d0", &el_refittedTrack_d0, &b_el_refittedTrack_d0);
    fChain->SetBranchAddress("el_refittedTrack_z0", &el_refittedTrack_z0, &b_el_refittedTrack_z0);
    fChain->SetBranchAddress("el_refittedTrack_theta", &el_refittedTrack_theta, &b_el_refittedTrack_theta);
    fChain->SetBranchAddress("el_refittedTrack_phi", &el_refittedTrack_phi, &b_el_refittedTrack_phi);
    fChain->SetBranchAddress("el_refittedTrack_LMqoverp", &el_refittedTrack_LMqoverp, &b_el_refittedTrack_LMqoverp);
    fChain->SetBranchAddress("el_refittedTrack_hasBrem", &el_refittedTrack_hasBrem, &b_el_refittedTrack_hasBrem);
    fChain->SetBranchAddress("el_refittedTrack_bremRadius", &el_refittedTrack_bremRadius, &b_el_refittedTrack_bremRadius);
    fChain->SetBranchAddress("el_refittedTrack_bremZ", &el_refittedTrack_bremZ, &b_el_refittedTrack_bremZ);
    fChain->SetBranchAddress("el_refittedTrack_bremRadiusErr", &el_refittedTrack_bremRadiusErr, &b_el_refittedTrack_bremRadiusErr);
    fChain->SetBranchAddress("el_refittedTrack_bremZErr", &el_refittedTrack_bremZErr, &b_el_refittedTrack_bremZErr);
    fChain->SetBranchAddress("el_Es0", &el_Es0, &b_el_Es0);
    fChain->SetBranchAddress("el_etas0", &el_etas0, &b_el_etas0);
    fChain->SetBranchAddress("el_phis0", &el_phis0, &b_el_phis0);
    fChain->SetBranchAddress("el_Es1", &el_Es1, &b_el_Es1);
    fChain->SetBranchAddress("el_etas1", &el_etas1, &b_el_etas1);
    fChain->SetBranchAddress("el_phis1", &el_phis1, &b_el_phis1);
    fChain->SetBranchAddress("el_Es2", &el_Es2, &b_el_Es2);
    fChain->SetBranchAddress("el_etas2", &el_etas2, &b_el_etas2);
    fChain->SetBranchAddress("el_phis2", &el_phis2, &b_el_phis2);
    fChain->SetBranchAddress("el_Es3", &el_Es3, &b_el_Es3);
    fChain->SetBranchAddress("el_etas3", &el_etas3, &b_el_etas3);
    fChain->SetBranchAddress("el_phis3", &el_phis3, &b_el_phis3);
    fChain->SetBranchAddress("el_E_PreSamplerB", &el_E_PreSamplerB, &b_el_E_PreSamplerB);
    fChain->SetBranchAddress("el_E_EMB1", &el_E_EMB1, &b_el_E_EMB1);
    fChain->SetBranchAddress("el_E_EMB2", &el_E_EMB2, &b_el_E_EMB2);
    fChain->SetBranchAddress("el_E_EMB3", &el_E_EMB3, &b_el_E_EMB3);
    fChain->SetBranchAddress("el_E_PreSamplerE", &el_E_PreSamplerE, &b_el_E_PreSamplerE);
    fChain->SetBranchAddress("el_E_EME1", &el_E_EME1, &b_el_E_EME1);
    fChain->SetBranchAddress("el_E_EME2", &el_E_EME2, &b_el_E_EME2);
    fChain->SetBranchAddress("el_E_EME3", &el_E_EME3, &b_el_E_EME3);
    fChain->SetBranchAddress("el_E_HEC0", &el_E_HEC0, &b_el_E_HEC0);
    fChain->SetBranchAddress("el_E_HEC1", &el_E_HEC1, &b_el_E_HEC1);
    fChain->SetBranchAddress("el_E_HEC2", &el_E_HEC2, &b_el_E_HEC2);
    fChain->SetBranchAddress("el_E_HEC3", &el_E_HEC3, &b_el_E_HEC3);
    fChain->SetBranchAddress("el_E_TileBar0", &el_E_TileBar0, &b_el_E_TileBar0);
    fChain->SetBranchAddress("el_E_TileBar1", &el_E_TileBar1, &b_el_E_TileBar1);
    fChain->SetBranchAddress("el_E_TileBar2", &el_E_TileBar2, &b_el_E_TileBar2);
    fChain->SetBranchAddress("el_E_TileGap1", &el_E_TileGap1, &b_el_E_TileGap1);
    fChain->SetBranchAddress("el_E_TileGap2", &el_E_TileGap2, &b_el_E_TileGap2);
    fChain->SetBranchAddress("el_E_TileGap3", &el_E_TileGap3, &b_el_E_TileGap3);
    fChain->SetBranchAddress("el_E_TileExt0", &el_E_TileExt0, &b_el_E_TileExt0);
    fChain->SetBranchAddress("el_E_TileExt1", &el_E_TileExt1, &b_el_E_TileExt1);
    fChain->SetBranchAddress("el_E_TileExt2", &el_E_TileExt2, &b_el_E_TileExt2);
    fChain->SetBranchAddress("el_E_FCAL0", &el_E_FCAL0, &b_el_E_FCAL0);
    fChain->SetBranchAddress("el_E_FCAL1", &el_E_FCAL1, &b_el_E_FCAL1);
    fChain->SetBranchAddress("el_E_FCAL2", &el_E_FCAL2, &b_el_E_FCAL2);
    fChain->SetBranchAddress("el_cl_E", &el_cl_E, &b_el_cl_E);
    fChain->SetBranchAddress("el_cl_pt", &el_cl_pt, &b_el_cl_pt);
    fChain->SetBranchAddress("el_cl_eta", &el_cl_eta, &b_el_cl_eta);
    fChain->SetBranchAddress("el_cl_phi", &el_cl_phi, &b_el_cl_phi);
    fChain->SetBranchAddress("el_firstEdens", &el_firstEdens, &b_el_firstEdens);
    fChain->SetBranchAddress("el_cellmaxfrac", &el_cellmaxfrac, &b_el_cellmaxfrac);
    fChain->SetBranchAddress("el_longitudinal", &el_longitudinal, &b_el_longitudinal);
    fChain->SetBranchAddress("el_secondlambda", &el_secondlambda, &b_el_secondlambda);
    fChain->SetBranchAddress("el_lateral", &el_lateral, &b_el_lateral);
    fChain->SetBranchAddress("el_secondR", &el_secondR, &b_el_secondR);
    fChain->SetBranchAddress("el_centerlambda", &el_centerlambda, &b_el_centerlambda);
    fChain->SetBranchAddress("el_rawcl_Es0", &el_rawcl_Es0, &b_el_rawcl_Es0);
    fChain->SetBranchAddress("el_rawcl_etas0", &el_rawcl_etas0, &b_el_rawcl_etas0);
    fChain->SetBranchAddress("el_rawcl_phis0", &el_rawcl_phis0, &b_el_rawcl_phis0);
    fChain->SetBranchAddress("el_rawcl_Es1", &el_rawcl_Es1, &b_el_rawcl_Es1);
    fChain->SetBranchAddress("el_rawcl_etas1", &el_rawcl_etas1, &b_el_rawcl_etas1);
    fChain->SetBranchAddress("el_rawcl_phis1", &el_rawcl_phis1, &b_el_rawcl_phis1);
    fChain->SetBranchAddress("el_rawcl_Es2", &el_rawcl_Es2, &b_el_rawcl_Es2);
    fChain->SetBranchAddress("el_rawcl_etas2", &el_rawcl_etas2, &b_el_rawcl_etas2);
    fChain->SetBranchAddress("el_rawcl_phis2", &el_rawcl_phis2, &b_el_rawcl_phis2);
    fChain->SetBranchAddress("el_rawcl_Es3", &el_rawcl_Es3, &b_el_rawcl_Es3);
    fChain->SetBranchAddress("el_rawcl_etas3", &el_rawcl_etas3, &b_el_rawcl_etas3);
    fChain->SetBranchAddress("el_rawcl_phis3", &el_rawcl_phis3, &b_el_rawcl_phis3);
    fChain->SetBranchAddress("el_rawcl_E", &el_rawcl_E, &b_el_rawcl_E);
    fChain->SetBranchAddress("el_rawcl_pt", &el_rawcl_pt, &b_el_rawcl_pt);
    fChain->SetBranchAddress("el_rawcl_eta", &el_rawcl_eta, &b_el_rawcl_eta);
    fChain->SetBranchAddress("el_rawcl_phi", &el_rawcl_phi, &b_el_rawcl_phi);
    fChain->SetBranchAddress("el_refittedtrackcovd0", &el_refittedtrackcovd0, &b_el_refittedtrackcovd0);
    fChain->SetBranchAddress("el_refittedtrackcovz0", &el_refittedtrackcovz0, &b_el_refittedtrackcovz0);
    fChain->SetBranchAddress("el_refittedtrackcovphi", &el_refittedtrackcovphi, &b_el_refittedtrackcovphi);
    fChain->SetBranchAddress("el_refittedtrackcovtheta", &el_refittedtrackcovtheta, &b_el_refittedtrackcovtheta);
    fChain->SetBranchAddress("el_refittedtrackcovqoverp", &el_refittedtrackcovqoverp, &b_el_refittedtrackcovqoverp);
    fChain->SetBranchAddress("el_refittedtrackcovd0z0", &el_refittedtrackcovd0z0, &b_el_refittedtrackcovd0z0);
    fChain->SetBranchAddress("el_refittedtrackcovz0phi", &el_refittedtrackcovz0phi, &b_el_refittedtrackcovz0phi);
    fChain->SetBranchAddress("el_refittedtrackcovz0theta", &el_refittedtrackcovz0theta, &b_el_refittedtrackcovz0theta);
    fChain->SetBranchAddress("el_refittedtrackcovz0qoverp", &el_refittedtrackcovz0qoverp, &b_el_refittedtrackcovz0qoverp);
    fChain->SetBranchAddress("el_refittedtrackcovd0phi", &el_refittedtrackcovd0phi, &b_el_refittedtrackcovd0phi);
    fChain->SetBranchAddress("el_refittedtrackcovd0theta", &el_refittedtrackcovd0theta, &b_el_refittedtrackcovd0theta);
    fChain->SetBranchAddress("el_refittedtrackcovd0qoverp", &el_refittedtrackcovd0qoverp, &b_el_refittedtrackcovd0qoverp);
    fChain->SetBranchAddress("el_refittedtrackcovphitheta", &el_refittedtrackcovphitheta, &b_el_refittedtrackcovphitheta);
    fChain->SetBranchAddress("el_refittedtrackcovphiqoverp", &el_refittedtrackcovphiqoverp, &b_el_refittedtrackcovphiqoverp);
    fChain->SetBranchAddress("el_refittedtrackcovthetaqoverp", &el_refittedtrackcovthetaqoverp, &b_el_refittedtrackcovthetaqoverp);
    fChain->SetBranchAddress("el_trackd0", &el_trackd0, &b_el_trackd0);
    fChain->SetBranchAddress("el_trackz0", &el_trackz0, &b_el_trackz0);
    fChain->SetBranchAddress("el_trackphi", &el_trackphi, &b_el_trackphi);
    fChain->SetBranchAddress("el_tracktheta", &el_tracktheta, &b_el_tracktheta);
    fChain->SetBranchAddress("el_trackqoverp", &el_trackqoverp, &b_el_trackqoverp);
    fChain->SetBranchAddress("el_trackpt", &el_trackpt, &b_el_trackpt);
    fChain->SetBranchAddress("el_tracketa", &el_tracketa, &b_el_tracketa);
    fChain->SetBranchAddress("el_trackcov_d0", &el_trackcov_d0, &b_el_trackcov_d0);
    fChain->SetBranchAddress("el_trackcov_z0", &el_trackcov_z0, &b_el_trackcov_z0);
    fChain->SetBranchAddress("el_trackcov_phi", &el_trackcov_phi, &b_el_trackcov_phi);
    fChain->SetBranchAddress("el_trackcov_theta", &el_trackcov_theta, &b_el_trackcov_theta);
    fChain->SetBranchAddress("el_trackcov_qoverp", &el_trackcov_qoverp, &b_el_trackcov_qoverp);
    fChain->SetBranchAddress("el_trackcov_d0_z0", &el_trackcov_d0_z0, &b_el_trackcov_d0_z0);
    fChain->SetBranchAddress("el_trackcov_d0_phi", &el_trackcov_d0_phi, &b_el_trackcov_d0_phi);
    fChain->SetBranchAddress("el_trackcov_d0_theta", &el_trackcov_d0_theta, &b_el_trackcov_d0_theta);
    fChain->SetBranchAddress("el_trackcov_d0_qoverp", &el_trackcov_d0_qoverp, &b_el_trackcov_d0_qoverp);
    fChain->SetBranchAddress("el_trackcov_z0_phi", &el_trackcov_z0_phi, &b_el_trackcov_z0_phi);
    fChain->SetBranchAddress("el_trackcov_z0_theta", &el_trackcov_z0_theta, &b_el_trackcov_z0_theta);
    fChain->SetBranchAddress("el_trackcov_z0_qoverp", &el_trackcov_z0_qoverp, &b_el_trackcov_z0_qoverp);
    fChain->SetBranchAddress("el_trackcov_phi_theta", &el_trackcov_phi_theta, &b_el_trackcov_phi_theta);
    fChain->SetBranchAddress("el_trackcov_phi_qoverp", &el_trackcov_phi_qoverp, &b_el_trackcov_phi_qoverp);
    fChain->SetBranchAddress("el_trackcov_theta_qoverp", &el_trackcov_theta_qoverp, &b_el_trackcov_theta_qoverp);
    fChain->SetBranchAddress("el_trackfitchi2", &el_trackfitchi2, &b_el_trackfitchi2);
    fChain->SetBranchAddress("el_trackfitndof", &el_trackfitndof, &b_el_trackfitndof);
    fChain->SetBranchAddress("el_nBLHits", &el_nBLHits, &b_el_nBLHits);
    fChain->SetBranchAddress("el_nPixHits", &el_nPixHits, &b_el_nPixHits);
    fChain->SetBranchAddress("el_nSCTHits", &el_nSCTHits, &b_el_nSCTHits);
    fChain->SetBranchAddress("el_nTRTHits", &el_nTRTHits, &b_el_nTRTHits);
    fChain->SetBranchAddress("el_nPixHoles", &el_nPixHoles, &b_el_nPixHoles);
    fChain->SetBranchAddress("el_nSCTHoles", &el_nSCTHoles, &b_el_nSCTHoles);
    fChain->SetBranchAddress("el_nBLSharedHits", &el_nBLSharedHits, &b_el_nBLSharedHits);
    fChain->SetBranchAddress("el_nPixSharedHits", &el_nPixSharedHits, &b_el_nPixSharedHits);
    fChain->SetBranchAddress("el_nSCTSharedHits", &el_nSCTSharedHits, &b_el_nSCTSharedHits);
    fChain->SetBranchAddress("el_nTRTHighTHits", &el_nTRTHighTHits, &b_el_nTRTHighTHits);
    fChain->SetBranchAddress("el_nTRTOutliers", &el_nTRTOutliers, &b_el_nTRTOutliers);
    fChain->SetBranchAddress("el_nTRTHighTOutliers", &el_nTRTHighTOutliers, &b_el_nTRTHighTOutliers);
    fChain->SetBranchAddress("el_nSiHits", &el_nSiHits, &b_el_nSiHits);
    fChain->SetBranchAddress("el_TRTHighTHitsRatio", &el_TRTHighTHitsRatio, &b_el_TRTHighTHitsRatio);
    fChain->SetBranchAddress("el_pixeldEdx", &el_pixeldEdx, &b_el_pixeldEdx);
    fChain->SetBranchAddress("el_eProbabilityComb", &el_eProbabilityComb, &b_el_eProbabilityComb);
    fChain->SetBranchAddress("el_eProbabilityHT", &el_eProbabilityHT, &b_el_eProbabilityHT);
    fChain->SetBranchAddress("el_eProbabilityToT", &el_eProbabilityToT, &b_el_eProbabilityToT);
    fChain->SetBranchAddress("el_eProbabilityBrem", &el_eProbabilityBrem, &b_el_eProbabilityBrem);
    fChain->SetBranchAddress("el_vertx", &el_vertx, &b_el_vertx);
    fChain->SetBranchAddress("el_verty", &el_verty, &b_el_verty);
    fChain->SetBranchAddress("el_vertz", &el_vertz, &b_el_vertz);
    fChain->SetBranchAddress("el_hastrack", &el_hastrack, &b_el_hastrack);
    fChain->SetBranchAddress("el_deltaEmax2", &el_deltaEmax2, &b_el_deltaEmax2);
    fChain->SetBranchAddress("el_calibHitsShowerDepth", &el_calibHitsShowerDepth, &b_el_calibHitsShowerDepth);
    fChain->SetBranchAddress("el_trackd0beam", &el_trackd0beam, &b_el_trackd0beam);
    fChain->SetBranchAddress("el_tracksigd0beam", &el_tracksigd0beam, &b_el_tracksigd0beam);
    fChain->SetBranchAddress("el_trackd0pv", &el_trackd0pv, &b_el_trackd0pv);
    fChain->SetBranchAddress("el_tracksigd0pv", &el_tracksigd0pv, &b_el_tracksigd0pv);
    fChain->SetBranchAddress("el_trackz0pv", &el_trackz0pv, &b_el_trackz0pv);
    fChain->SetBranchAddress("el_tracksigz0pv", &el_tracksigz0pv, &b_el_tracksigz0pv);
    fChain->SetBranchAddress("el_trackd0pvunbiased", &el_trackd0pvunbiased, &b_el_trackd0pvunbiased);
    fChain->SetBranchAddress("el_tracksigd0pvunbiased", &el_tracksigd0pvunbiased, &b_el_tracksigd0pvunbiased);
    fChain->SetBranchAddress("el_trackz0pvunbiased", &el_trackz0pvunbiased, &b_el_trackz0pvunbiased);
    fChain->SetBranchAddress("el_tracksigz0pvunbiased", &el_tracksigz0pvunbiased, &b_el_tracksigz0pvunbiased);
    fChain->SetBranchAddress("el_isIso", &el_isIso, &b_el_isIso);
    fChain->SetBranchAddress("el_mvaptcone20", &el_mvaptcone20, &b_el_mvaptcone20);
    fChain->SetBranchAddress("el_mvaptcone30", &el_mvaptcone30, &b_el_mvaptcone30);
    fChain->SetBranchAddress("el_mvaptcone40", &el_mvaptcone40, &b_el_mvaptcone40);
    fChain->SetBranchAddress("ph_n", &ph_n, &b_ph_n);
    fChain->SetBranchAddress("ph_E", &ph_E, &b_ph_E);
    fChain->SetBranchAddress("ph_Et", &ph_Et, &b_ph_Et);
    fChain->SetBranchAddress("ph_pt", &ph_pt, &b_ph_pt);
    fChain->SetBranchAddress("ph_m", &ph_m, &b_ph_m);
    fChain->SetBranchAddress("ph_eta", &ph_eta, &b_ph_eta);
    fChain->SetBranchAddress("ph_phi", &ph_phi, &b_ph_phi);
    fChain->SetBranchAddress("ph_px", &ph_px, &b_ph_px);
    fChain->SetBranchAddress("ph_py", &ph_py, &b_ph_py);
    fChain->SetBranchAddress("ph_pz", &ph_pz, &b_ph_pz);
    fChain->SetBranchAddress("ph_author", &ph_author, &b_ph_author);
    fChain->SetBranchAddress("ph_isRecovered", &ph_isRecovered, &b_ph_isRecovered);
    fChain->SetBranchAddress("ph_isEM", &ph_isEM, &b_ph_isEM);
    fChain->SetBranchAddress("ph_OQ", &ph_OQ, &b_ph_OQ);
    fChain->SetBranchAddress("ph_loose", &ph_loose, &b_ph_loose);
    fChain->SetBranchAddress("ph_tight", &ph_tight, &b_ph_tight);
    fChain->SetBranchAddress("ph_tightIso", &ph_tightIso, &b_ph_tightIso);
    fChain->SetBranchAddress("ph_goodOQ", &ph_goodOQ, &b_ph_goodOQ);
    fChain->SetBranchAddress("ph_Ethad", &ph_Ethad, &b_ph_Ethad);
    fChain->SetBranchAddress("ph_Ethad1", &ph_Ethad1, &b_ph_Ethad1);
    fChain->SetBranchAddress("ph_E033", &ph_E033, &b_ph_E033);
    fChain->SetBranchAddress("ph_f1", &ph_f1, &b_ph_f1);
    fChain->SetBranchAddress("ph_f1core", &ph_f1core, &b_ph_f1core);
    fChain->SetBranchAddress("ph_Emins1", &ph_Emins1, &b_ph_Emins1);
    fChain->SetBranchAddress("ph_fside", &ph_fside, &b_ph_fside);
    fChain->SetBranchAddress("ph_Emax2", &ph_Emax2, &b_ph_Emax2);
    fChain->SetBranchAddress("ph_ws3", &ph_ws3, &b_ph_ws3);
    fChain->SetBranchAddress("ph_wstot", &ph_wstot, &b_ph_wstot);
    fChain->SetBranchAddress("ph_E132", &ph_E132, &b_ph_E132);
    fChain->SetBranchAddress("ph_E1152", &ph_E1152, &b_ph_E1152);
    fChain->SetBranchAddress("ph_emaxs1", &ph_emaxs1, &b_ph_emaxs1);
    fChain->SetBranchAddress("ph_deltaEs", &ph_deltaEs, &b_ph_deltaEs);
    fChain->SetBranchAddress("ph_E233", &ph_E233, &b_ph_E233);
    fChain->SetBranchAddress("ph_E237", &ph_E237, &b_ph_E237);
    fChain->SetBranchAddress("ph_E277", &ph_E277, &b_ph_E277);
    fChain->SetBranchAddress("ph_weta2", &ph_weta2, &b_ph_weta2);
    fChain->SetBranchAddress("ph_f3", &ph_f3, &b_ph_f3);
    fChain->SetBranchAddress("ph_f3core", &ph_f3core, &b_ph_f3core);
    fChain->SetBranchAddress("ph_rphiallcalo", &ph_rphiallcalo, &b_ph_rphiallcalo);
    fChain->SetBranchAddress("ph_Etcone45", &ph_Etcone45, &b_ph_Etcone45);
    fChain->SetBranchAddress("ph_Etcone20", &ph_Etcone20, &b_ph_Etcone20);
    fChain->SetBranchAddress("ph_Etcone30", &ph_Etcone30, &b_ph_Etcone30);
    fChain->SetBranchAddress("ph_Etcone40", &ph_Etcone40, &b_ph_Etcone40);
    fChain->SetBranchAddress("ph_ptcone30", &ph_ptcone30, &b_ph_ptcone30);
    fChain->SetBranchAddress("ph_convanglematch", &ph_convanglematch, &b_ph_convanglematch);
    fChain->SetBranchAddress("ph_convtrackmatch", &ph_convtrackmatch, &b_ph_convtrackmatch);
    fChain->SetBranchAddress("ph_reta", &ph_reta, &b_ph_reta);
    fChain->SetBranchAddress("ph_rphi", &ph_rphi, &b_ph_rphi);
    fChain->SetBranchAddress("ph_EtringnoisedR03sig2", &ph_EtringnoisedR03sig2, &b_ph_EtringnoisedR03sig2);
    fChain->SetBranchAddress("ph_EtringnoisedR03sig3", &ph_EtringnoisedR03sig3, &b_ph_EtringnoisedR03sig3);
    fChain->SetBranchAddress("ph_EtringnoisedR03sig4", &ph_EtringnoisedR03sig4, &b_ph_EtringnoisedR03sig4);
    fChain->SetBranchAddress("ph_isolationlikelihoodjets", &ph_isolationlikelihoodjets, &b_ph_isolationlikelihoodjets);
    fChain->SetBranchAddress("ph_isolationlikelihoodhqelectrons", &ph_isolationlikelihoodhqelectrons, &b_ph_isolationlikelihoodhqelectrons);
    fChain->SetBranchAddress("ph_loglikelihood", &ph_loglikelihood, &b_ph_loglikelihood);
    fChain->SetBranchAddress("ph_photonweight", &ph_photonweight, &b_ph_photonweight);
    fChain->SetBranchAddress("ph_photonbgweight", &ph_photonbgweight, &b_ph_photonbgweight);
    fChain->SetBranchAddress("ph_neuralnet", &ph_neuralnet, &b_ph_neuralnet);
    fChain->SetBranchAddress("ph_Hmatrix", &ph_Hmatrix, &b_ph_Hmatrix);
    fChain->SetBranchAddress("ph_Hmatrix5", &ph_Hmatrix5, &b_ph_Hmatrix5);
    fChain->SetBranchAddress("ph_adaboost", &ph_adaboost, &b_ph_adaboost);
    fChain->SetBranchAddress("ph_zvertex", &ph_zvertex, &b_ph_zvertex);
    fChain->SetBranchAddress("ph_errz", &ph_errz, &b_ph_errz);
    fChain->SetBranchAddress("ph_etap", &ph_etap, &b_ph_etap);
    fChain->SetBranchAddress("ph_depth", &ph_depth, &b_ph_depth);
    fChain->SetBranchAddress("ph_cl_E", &ph_cl_E, &b_ph_cl_E);
    fChain->SetBranchAddress("ph_cl_pt", &ph_cl_pt, &b_ph_cl_pt);
    fChain->SetBranchAddress("ph_cl_eta", &ph_cl_eta, &b_ph_cl_eta);
    fChain->SetBranchAddress("ph_cl_phi", &ph_cl_phi, &b_ph_cl_phi);
    fChain->SetBranchAddress("ph_Es0", &ph_Es0, &b_ph_Es0);
    fChain->SetBranchAddress("ph_etas0", &ph_etas0, &b_ph_etas0);
    fChain->SetBranchAddress("ph_phis0", &ph_phis0, &b_ph_phis0);
    fChain->SetBranchAddress("ph_Es1", &ph_Es1, &b_ph_Es1);
    fChain->SetBranchAddress("ph_etas1", &ph_etas1, &b_ph_etas1);
    fChain->SetBranchAddress("ph_phis1", &ph_phis1, &b_ph_phis1);
    fChain->SetBranchAddress("ph_Es2", &ph_Es2, &b_ph_Es2);
    fChain->SetBranchAddress("ph_etas2", &ph_etas2, &b_ph_etas2);
    fChain->SetBranchAddress("ph_phis2", &ph_phis2, &b_ph_phis2);
    fChain->SetBranchAddress("ph_Es3", &ph_Es3, &b_ph_Es3);
    fChain->SetBranchAddress("ph_etas3", &ph_etas3, &b_ph_etas3);
    fChain->SetBranchAddress("ph_phis3", &ph_phis3, &b_ph_phis3);
    fChain->SetBranchAddress("ph_rawcl_Es0", &ph_rawcl_Es0, &b_ph_rawcl_Es0);
    fChain->SetBranchAddress("ph_rawcl_etas0", &ph_rawcl_etas0, &b_ph_rawcl_etas0);
    fChain->SetBranchAddress("ph_rawcl_phis0", &ph_rawcl_phis0, &b_ph_rawcl_phis0);
    fChain->SetBranchAddress("ph_rawcl_Es1", &ph_rawcl_Es1, &b_ph_rawcl_Es1);
    fChain->SetBranchAddress("ph_rawcl_etas1", &ph_rawcl_etas1, &b_ph_rawcl_etas1);
    fChain->SetBranchAddress("ph_rawcl_phis1", &ph_rawcl_phis1, &b_ph_rawcl_phis1);
    fChain->SetBranchAddress("ph_rawcl_Es2", &ph_rawcl_Es2, &b_ph_rawcl_Es2);
    fChain->SetBranchAddress("ph_rawcl_etas2", &ph_rawcl_etas2, &b_ph_rawcl_etas2);
    fChain->SetBranchAddress("ph_rawcl_phis2", &ph_rawcl_phis2, &b_ph_rawcl_phis2);
    fChain->SetBranchAddress("ph_rawcl_Es3", &ph_rawcl_Es3, &b_ph_rawcl_Es3);
    fChain->SetBranchAddress("ph_rawcl_etas3", &ph_rawcl_etas3, &b_ph_rawcl_etas3);
    fChain->SetBranchAddress("ph_rawcl_phis3", &ph_rawcl_phis3, &b_ph_rawcl_phis3);
    fChain->SetBranchAddress("ph_rawcl_E", &ph_rawcl_E, &b_ph_rawcl_E);
    fChain->SetBranchAddress("ph_rawcl_pt", &ph_rawcl_pt, &b_ph_rawcl_pt);
    fChain->SetBranchAddress("ph_rawcl_eta", &ph_rawcl_eta, &b_ph_rawcl_eta);
    fChain->SetBranchAddress("ph_rawcl_phi", &ph_rawcl_phi, &b_ph_rawcl_phi);
    fChain->SetBranchAddress("ph_deltaEmax2", &ph_deltaEmax2, &b_ph_deltaEmax2);
    fChain->SetBranchAddress("ph_calibHitsShowerDepth", &ph_calibHitsShowerDepth, &b_ph_calibHitsShowerDepth);
    fChain->SetBranchAddress("ph_isIso", &ph_isIso, &b_ph_isIso);
    fChain->SetBranchAddress("ph_mvaptcone20", &ph_mvaptcone20, &b_ph_mvaptcone20);
    fChain->SetBranchAddress("ph_mvaptcone30", &ph_mvaptcone30, &b_ph_mvaptcone30);
    fChain->SetBranchAddress("ph_mvaptcone40", &ph_mvaptcone40, &b_ph_mvaptcone40);
    fChain->SetBranchAddress("ph_topoEtcone20", &ph_topoEtcone20, &b_ph_topoEtcone20);
    fChain->SetBranchAddress("ph_topoEtcone40", &ph_topoEtcone40, &b_ph_topoEtcone40);
    fChain->SetBranchAddress("ph_topoEtcone60", &ph_topoEtcone60, &b_ph_topoEtcone60);
    Notify();
}

#endif // #ifdef extractor_cxx
