#ifndef _CombineTriggers_HH_
#define _CombineTriggers_HH_

#include <string>
#include <vector>
#include "TFile.h"
#include "TGraphAsymmErrors.h"

class TChain;
class TH1;
class TH2;
class TProfile;

class CombineTriggers {

 public:
  CombineTriggers();
  ~CombineTriggers();

  double calc_weight_mbPrimHmt(const std::vector<float>* Prescales, int ntrk, double EtL1);           //get weight for MB + HMT
  double calc_weight_mbHmt    (const std::vector<float>* Prescales, int ntrk, double EtL1);           //get weight for MB + HMT
  double calc_weight_trig     (const std::vector<float>* Prescales, int ntrk, double EtL1, int trig); //get weight for individual triggers

 private:

  TFile *fEff;

  TGraphAsymmErrors* gEff[12];
  TGraphAsymmErrors* gCrc[3];

  int NTRIG_0;
};

#endif
