#ifndef effTool_pPb_h
#define effTool_pPb_h

#include "TFile.h"
#include "TH2D.h"
#include "TGraphErrors.h"

class effTool_pPb {
 
   public :
      effTool_pPb(std::string fName);
      ~effTool_pPb();
      double get_eff(double eta, double vxz, double pt);//need set quality and centrality first.
      int Qual;//6 qualities, loose, tight, tighter and the three with matching
      void set_centb(double ntrk);
   private:
      enum {
         NQUAL = 9,
         NCENT = 4,
         NPT   = 12,
      };
      int centb;
      void set_etab(double eta);//set internal eta bins
      int get_zbin(double vxz);//get internal eta bin
      int get_ptbin(double pt);//get internal eta bin

      TFile* fIn;
      bool is_bad;
      TH2D* hEff[NCENT][NPT][NQUAL];      

      int eta_eff;
};

#endif
