// HIPileupTool.h

#ifndef HIPileupTool_H
#define HIPileupTool_H

// David Adams.
// January 2014
//
// This is a simple ASG dual-use tool intended as an
// example for tool developers.

#include "HIPileupTool/IHIPileupTool.h"
#include "AsgTools/AsgTool.h"
#include "xAODForward/ZdcModuleContainer.h"
#include "xAODHIEvent/HIEventShapeContainer.h"

class TH1D;
class TH2D;

class HIPileupTool
: public asg::AsgTool,
  virtual public IHIPileupTool {
ASG_TOOL_CLASS(HIPileupTool, IHIPileupTool)

public:

  HIPileupTool( const std::string& myname );
  ~HIPileupTool();

  virtual StatusCode initialize();

  virtual void print() const;

  // Display the message recorded as property "Message"
  //virtual int talk() const;

  double get_efficiency(const xAOD::HIEventShapeContainer&, double& );
  double get_purity(const xAOD::HIEventShapeContainer&, double& );
  double get_efficiency(double );
  double get_purity(double );
  bool   is_pileup(const xAOD::HIEventShapeContainer&, const xAOD::ZdcModuleContainer& );

private:

  double get_et(const xAOD::HIEventShapeContainer& evShCont);
  double get_nNeutrons(const xAOD::ZdcModuleContainer& ZdcCont);

  std::string m_msg;
  std::vector<double> m_etCutAndPurity;
  std::string m_fname;

  double m_etThreshold;
  double m_purityCut;
  bool m_setup;

  TH2D* m_hEvents;
  TH2D* m_hPileUp;
  TH1D* m_hCut;
  TH1D* m_hEff;
  TH1D* m_hPurity;
};

#endif
