// HIPileupAlgo.h 

#ifndef HIPileupAlgo_H
#define HIPileupAlgo_H

#include "AthenaBaseComps/AthAlgorithm.h"
#include "GaudiKernel/ToolHandle.h"
#include "../HIPileupTool/HIPileupTool.h"

//class IHIPileupTool;
class IExecuteTool;

class HIPileupAlgo : public AthAlgorithm { 

public: 

  /// Constructor with parameters: 
  HIPileupAlgo(const std::string& name, ISvcLocator* pSvcLocator);

  /// Destructor: 
  ~HIPileupAlgo(); 

  /// Athena algorithm's Hooks
  StatusCode  initialize();
  StatusCode  execute();
  StatusCode  finalize();

private: 

  /// Default constructor: 
  HIPileupAlgo();

private:

  /// Athena configured tools
  HIPileupTool* m_asgtools;

}; 

#endif
