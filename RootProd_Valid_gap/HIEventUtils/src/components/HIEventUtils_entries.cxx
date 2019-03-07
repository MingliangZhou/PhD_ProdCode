#include "GaudiKernel/DeclareFactoryEntries.h"
#include "HIEventUtils/HIEventShapeSummaryTool.h"
#include "HIEventUtils/HIVertexSelectionTool.h"
#include "HIEventUtils/HIGapCalculationTool.h"

DECLARE_TOOL_FACTORY( HIEventShapeSummaryTool )
DECLARE_TOOL_FACTORY( HI::HIVertexSelectionTool )
DECLARE_TOOL_FACTORY( HI::HIGapCalculationTool )

DECLARE_FACTORY_ENTRIES( HIEventUtils ) {
  DECLARE_TOOL( HIEventShapeSummaryTool );
  DECLARE_TOOL( HI::HIVertexSelectionTool );
  DECLARE_TOOL( HI::HIGapCalculationTool );
}

