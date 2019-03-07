// hello.cxx

// David Adams
// January 2014
//
// Demo main program to use HIPileupTool in a 
// standlone environment.

#include <string>
#include <iostream>
#include "HIPileupTool/HIPileupTool.h"

using std::string;
using std::cout;
using std::endl;

int main() {
  const string myname = "hello: ";
  cout << myname << "Begin." << endl;
  HIPileupTool htool("myhello");
  std::vector<double> cuts; 
  cuts.push_back(4.4); 
  cuts.push_back(1.0);
  ASG_CHECK_SA( "hello", htool.setProperty("Message", "Hello from ASG.") );
  ASG_CHECK_SA( "hello", htool.setProperty("EtCutAndPurity", cuts) );
  ASG_CHECK_SA( "hello", htool.setProperty("inpFilePath", "../data/HIRun2PileUp_PbPb5p02.root") );
  cout << myname << "Initialize" << endl;
  try {
     ASG_CHECK_SA( "hello", htool.initialize());
  }
  catch (std::exception& excp) {
     std::cout << "ERROR in HIPileupTool: " << excp.what() << std::endl;
     return 1;
  }
  cout << myname << "Show properties" << endl;
  htool.print();
  
  std::cout << "eff = " << htool.get_efficiency(4.42) << std::endl;
  
  cout << myname << "End." << endl;
  return 0;
}
