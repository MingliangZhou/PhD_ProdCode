// HIPileupTool_entries.cxx

#include "../HIPileupAlgo.h"
#include "HIPileupTool/HIPileupTool.h"
#include "GaudiKernel/DeclareFactoryEntries.h"

DECLARE_TOOL_FACTORY(HIPileupTool)

DECLARE_ALGORITHM_FACTORY(HIPileupAlgo)

DECLARE_FACTORY_ENTRIES(HIPileupTool) {
  DECLARE_TOOL(HIPileupTool)
  DECLARE_ALGORITHM(HIPileupAlgo)
}

