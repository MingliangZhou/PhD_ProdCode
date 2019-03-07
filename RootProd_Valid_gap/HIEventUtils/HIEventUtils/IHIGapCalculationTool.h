// -*- c++ -*-
#pragma once
#ifndef HIEVENTUTILS_IHIGAPCALCULATIONTOOL_H
#define HIEVENTUTILS_IHIGAPCALCULATIONTOOL_H

#include "PATCore/IAsgSelectionTool.h"
#include "xAODTracking/Vertex.h"

namespace HI {

  //class IHIGapCalculationTool : public virtual ::IAsgSelectionTool {
  class IHIGapCalculationTool : public virtual ::IAsgSelectionTool {
    ASG_TOOL_INTERFACE( HI::IHIGapCalculationTool )
  public:

    virtual StatusCode initialize() = 0;
    virtual StatusCode finalize() = 0;

		virtual void CalculateGaps(double& gapA, double& gapC) = 0;

    virtual const Root::TAccept& getTAccept() const = 0;
    // we have to implement the IParticle function in order to inherit from IAsgSelectionTool
    // it will throw an exception
    virtual const Root::TAccept& accept( const xAOD::IParticle* ) const = 0;
    virtual const Root::TAccept& accept( const xAOD::Vertex& ) const = 0;

	};
}


#endif // HIEVENTUTILS_IHIGAPCALCULATIONTOOL_H
