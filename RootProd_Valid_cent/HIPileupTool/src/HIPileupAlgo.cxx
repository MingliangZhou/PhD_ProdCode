// HIPileupAlgo.cxx 

#include "HIPileupAlgo.h"
#include "GaudiKernel/Property.h"
#include "HIPileupTool/IHIPileupTool.h"
#include "AsgTools/AsgTool.h"

using std::string;

//**********************************************************************

HIPileupAlgo::
HIPileupAlgo(const std::string& name, 
                    ISvcLocator* pSvcLocator )
: ::AthAlgorithm( name, pSvcLocator ) {
   m_asgtools = new HIPileupTool("myTool");
   m_asgtools->setProperty("inpFilePath","../data/HIRun2PileUp_PbPb5p02_v2.root");
}

//**********************************************************************

HIPileupAlgo::~HIPileupAlgo() { }

//**********************************************************************

StatusCode HIPileupAlgo::initialize() {
  StatusCode sc;
  ATH_MSG_INFO("Initializing " << name() << "...");
  try {
     sc = m_asgtools->initialize();
  }
  catch (std::exception& excp) {
     std::cout << excp.what(); return StatusCode::FAILURE;
  }

  return sc;
  //return StatusCode::SUCCESS;
}

//**********************************************************************

StatusCode HIPileupAlgo::finalize() {
   ATH_MSG_INFO ("Finalizing " << name() << "...");
  return StatusCode::SUCCESS;
}

//**********************************************************************

StatusCode HIPileupAlgo::execute() {  
   ATH_MSG_INFO ("Executing " << name() << "...");
   static int cnt =0;
  // Loop over hello tools.
  string line = "---------------------------------------------------";
  ATH_MSG_INFO(line);

  m_asgtools->print();
  std::cout << "ET = " << 0.1+cnt << ": Efficiency = " << m_asgtools->get_efficiency(0.1+cnt) << std::endl;
  ATH_MSG_INFO(line);
  cnt++;
  return StatusCode::SUCCESS;
}

//**********************************************************************
