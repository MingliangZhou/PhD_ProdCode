// HIPileupTool.cxx

#include "HIPileupTool/HIPileupTool.h"
#include "xAODForward/ZdcModule.h"
#include "xAODForward/ZdcModuleContainer.h"
#include "xAODForward/ZdcModuleAuxContainer.h"
#include "xAODTrigL1Calo/TriggerTowerContainer.h"

#include <xAODHIEvent/HIEventShape.h>
#include <xAODHIEvent/HIEventShapeContainer.h>

#include "TSystem.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TFile.h"
#include <vector>
#include <exception>

HIPileupTool::
HIPileupTool( const std::string& myname )
: AsgTool(myname) {
  declareProperty("Message", m_msg);
  declareProperty("EtCutAndPurity", m_etCutAndPurity);
  declareProperty("inpFilePath", m_fname);

  m_setup = 0;
}

HIPileupTool::~HIPileupTool() {

   if (m_setup) {
      delete m_hEvents; delete m_hPileUp;
      delete m_hCut; delete m_hEff; delete m_hPurity;
   }
}

StatusCode HIPileupTool::initialize() {

   ATH_MSG_VERBOSE( "Initialising tool " << name() );

   const char* fullInpFilePath = gSystem->ExpandPathName (m_fname.c_str());
   if (gSystem->AccessPathName(fullInpFilePath)) throw std::invalid_argument(("File not found at \"" + m_fname + "\"").c_str());
   TFile* fIn = new TFile(fullInpFilePath);

   std::string hname;
   hname = "hEvents"; if (!(fIn->GetListOfKeys()->Contains(hname.c_str()))) {
      fIn->Close(); throw std::invalid_argument(("Expected histogram \"" + hname + "\" not found in \"" + m_fname + "\"").c_str());}
   hname = "hPileUp"; if (!(fIn->GetListOfKeys()->Contains(hname.c_str()))) {
      fIn->Close(); throw std::invalid_argument(("Expected histogram \"" + hname + "\" not found in \"" + m_fname + "\"").c_str());}
   hname = "hCut";    if (!(fIn->GetListOfKeys()->Contains(hname.c_str()))) {
      fIn->Close(); throw std::invalid_argument(("Expected histogram \"" + hname + "\" not found in \"" + m_fname + "\"").c_str());}
   hname = "hEff";    if (!(fIn->GetListOfKeys()->Contains(hname.c_str()))) {
      fIn->Close(); throw std::invalid_argument(("Expected histogram \"" + hname + "\" not found in \"" + m_fname + "\"").c_str());}
   hname = "hPurity"; if (!(fIn->GetListOfKeys()->Contains(hname.c_str()))) {
      fIn->Close(); throw std::invalid_argument(("Expected histogram \"" + hname + "\" not found in \"" + m_fname + "\"").c_str());}
   
   m_hEvents = (TH2D*)((TH2D*)fIn->Get("hEvents"))->Clone("hEvents_Copy"); m_hEvents->SetDirectory(0);
   m_hPileUp = (TH2D*)((TH2D*)fIn->Get("hPileUp"))->Clone("hPileUp_Copy"); m_hPileUp->SetDirectory(0);
   m_hCut    = (TH1D*)((TH1D*)fIn->Get("hCut"))->Clone("hCut_Copy");       m_hCut->SetDirectory(0);
   m_hEff    = (TH1D*)((TH1D*)fIn->Get("hEff"))->Clone("hEff_Copy");       m_hEff->SetDirectory(0);
   m_hPurity = (TH1D*)((TH1D*)fIn->Get("hPurity"))->Clone("hPurity_Copy"); m_hPurity->SetDirectory(0);
   m_setup = 1;

   fIn->Close();

   m_etThreshold = 6.0;
   m_purityCut   = -1.0;
   if (!m_etCutAndPurity.empty()) {
      if (m_etCutAndPurity.size()<2) ATH_MSG_WARNING("Cuts vector should have two elements. Will use default settings");
      else {
         if (m_etCutAndPurity.at(1)<0 || m_etCutAndPurity.at(1)>1) ATH_MSG_WARNING("Purity cut should be between 0 and 1. Will use default settings");
         else {
            m_etThreshold = m_etCutAndPurity.at(0);
            m_purityCut   = m_etCutAndPurity.at(1);
         }
      }
   }

   for (int ibx=0;ibx<m_hPileUp->GetNbinsX();ibx++) {
      if (m_hPileUp->GetXaxis()->GetBinCenter(ibx+1) < m_etThreshold) continue;
      int NY = m_hPileUp->GetNbinsY();
      if (m_hPileUp->Integral(ibx+1,ibx+1,1,NY) == 0) {m_hCut->SetBinContent(ibx+1,0); continue;}
      if (m_hPileUp->GetXaxis()->GetBinCenter(ibx+1)>5.0 && fabs(m_purityCut-1)<1e-6) {m_hCut->SetBinContent(ibx+1,0); continue;}
      for (int iby=0;iby<NY;iby++) {
         if (m_hPileUp->Integral(ibx+1,ibx+1,NY-iby,NY)/m_hPileUp->Integral(ibx+1,ibx+1,1,NY) < m_purityCut) continue;
         m_hCut->SetBinContent(ibx+1,m_hPileUp->GetYaxis()->GetBinCenter(NY-iby)); break;
      }
   }

   for (int ibx=0;ibx<m_hEvents->GetNbinsX();ibx++) {
      if (m_hEvents->GetXaxis()->GetBinCenter(ibx+1) < m_etThreshold) {m_hEff->SetBinContent(ibx+1,1-m_hEff->GetBinContent(ibx+1)); continue;}
      double cut = m_hEvents->Integral(ibx+1,ibx+1,m_hEvents->GetYaxis()->FindBin(m_hCut->GetBinContent(ibx+1)), m_hEvents->GetNbinsY());
      double all = m_hEvents->Integral(ibx+1,ibx+1,1,m_hEvents->GetYaxis()->GetNbins());
      double pu_cut = m_hPileUp->Integral(ibx+1,ibx+1,m_hPileUp->GetYaxis()->FindBin(m_hCut->GetBinContent(ibx+1)), m_hPileUp->GetNbinsY());
      double pu_all = m_hPileUp->Integral(ibx+1,ibx+1,1,m_hPileUp->GetYaxis()->GetNbins());
      double eff = 1 - (cut - pu_cut)/all; if ((cut - pu_cut) < 0) eff=1;
      double pty = pu_cut/pu_all;
      if (all!=0) m_hEff->SetBinContent(ibx+1,eff);
      if (pu_all!=0) m_hPurity->SetBinContent(ibx+1,pty);
   }

   return StatusCode::SUCCESS;
}

bool HIPileupTool::is_pileup(const xAOD::HIEventShapeContainer& evShCont, const xAOD::ZdcModuleContainer& ZdcCont) {

   bool kPileup = false;
   double FCal_Et = get_et(evShCont);
   double nNeutrons = get_nNeutrons(ZdcCont);
	 if (nNeutrons > m_hCut->GetBinContent(m_hCut->FindBin(FCal_Et))) kPileup = true;

   return kPileup;
}

double HIPileupTool::get_efficiency(const xAOD::HIEventShapeContainer& evShCont, double& FCal_Et) {
    
   FCal_Et = get_et(evShCont);
   return m_hEff->GetBinContent(m_hEff->FindBin(FCal_Et));
}

double HIPileupTool::get_efficiency(double FCal_Et) {

   return m_hEff->GetBinContent(m_hEff->FindBin(FCal_Et));
}

double HIPileupTool::get_purity(const xAOD::HIEventShapeContainer& evShCont, double& FCal_Et) {

   FCal_Et = get_et(evShCont);
   return m_hPurity->GetBinContent(m_hPurity->FindBin(FCal_Et));
}

double HIPileupTool::get_purity(double FCal_Et) {

   return m_hPurity->GetBinContent(m_hPurity->FindBin(FCal_Et));
}

double HIPileupTool::get_et(const xAOD::HIEventShapeContainer& evShCont) {

   double Fcal_Et=0;
   for(const auto *ptrEvtShp : evShCont) {
      if(fabs((ptrEvtShp->etaMin()+ptrEvtShp->etaMax())/2.0)<3.2) continue;
      Fcal_Et += ptrEvtShp->et()/1000000;
   }
   return Fcal_Et;
}

double HIPileupTool::get_nNeutrons(const xAOD::ZdcModuleContainer& ZdcCont) { //Reimplement this when the Zdc Tool becomes available

   double singNp_A = 35.5, singNp_C = 38.1;

   double Zdc_E_A = 0, Zdc_E_C =0;
   for( const auto* ZdcIter : ZdcCont) {
      int side = ZdcIter->side();
      int module = ZdcIter->zdcModule();
      int type = ZdcIter->type();

      side += 1;;
      if (side==2) side = 1; 
      if (type!=0) continue;

      float en_lg = ZdcIter->amplitudeG0();
      if (module==0) {
         const std::vector<uint16_t> adc_g0d1 = (*(ZdcIter->TTg0d1Link()))->adc();
         float max1=0;
         for (unsigned isz=0;isz<adc_g0d1.size();isz++) {
            if (max1<adc_g0d1.at(isz)) max1 = adc_g0d1.at(isz);
         }
         max1 -= adc_g0d1.at(0);
         if (side==0) Zdc_E_C += max1;
         if (side==1) Zdc_E_A += max1;
      }
      if (module>0) {
         if (side==0) Zdc_E_C += en_lg; 
         if (side==1) Zdc_E_A += en_lg; 
      }
   }

   return Zdc_E_A/singNp_A + Zdc_E_C/singNp_C;
}

/*int HIPileupTool::talk() const {
   ATH_MSG_INFO("This is HIPileupTool");
   ATH_MSG_INFO("The current configurations are: ");
   print();
   return 0;
}*/

void HIPileupTool::print() const {
   AsgTool::print();
   if (m_purityCut<0) {
      ATH_MSG_INFO("ET throshold for purity cut = NONE");
      ATH_MSG_INFO("Purity cut = DEFAULT");
   }
   else {
      ATH_MSG_INFO("ET throshold for purity cut = " << m_etThreshold << " TeV");
      ATH_MSG_INFO("Purity cut = " << m_purityCut );
   }
}

