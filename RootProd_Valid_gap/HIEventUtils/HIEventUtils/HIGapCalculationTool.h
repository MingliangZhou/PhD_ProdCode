// -*- c++ -*-
#pragma once
#ifndef HIEVENTUTILS_HIGAPCALCULATIONTOOL_H
#define HIEVENTUTILS_HIGAPCALCULATIONTOOL_H

#include "HIEventUtils/IHIGapCalculationTool.h"
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"

#include <EventLoop/Algorithm.h>
#include "xAODRootAccess/Init.h"
#include "xAODRootAccess/TEvent.h"

namespace HI {

	class HIGapCalculationTool : public virtual HI::IHIGapCalculationTool,
	public asg::AsgTool {
		ASG_TOOL_CLASS2( HIGapCalculationTool,
				IAsgSelectionTool,
				HI::IHIGapCalculationTool )
		public:

			HIGapCalculationTool( const std::string& name );
			~HIGapCalculationTool();

			StatusCode initialize() override;
			StatusCode finalize() override;

			void CalculateGaps(double& gapA, double& gapC) override;

			virtual const Root::TAccept& getTAccept() const override {Root::TAccept m_1; return m_1;}
			// we have to implement the IParticle function in order to inherit from IAsgSelectionTool
			// it will throw an exception
			virtual const Root::TAccept& accept( const xAOD::IParticle* ) const override {Root::TAccept m_1; return m_1;}
			virtual const Root::TAccept& accept( const xAOD::Vertex& ) const override {Root::TAccept m_1; return m_1;}

		private:
			double m_cell_sig_cut = 4.5;
			double m_percentage_cut = 0.01;
	};
}


#endif // HIEVENTUTILS_HIGAPCALCULATIONTOOL_H
