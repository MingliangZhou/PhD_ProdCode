// -*- c++ -*-
#pragma once
#ifndef HIEVENTUTILS_HIVERTEXSELECTIONTOOL_H
#define HIEVENTUTILS_HIVERTEXSELECTIONTOOL_H

#include "HIEventUtils/IHIVertexSelectionTool.h"
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "InDetTrackSelectionTool/IInDetTrackSelectionTool.h"

namespace HI {

  class HIVertexSelectionTool : public virtual HI::IHIVertexSelectionTool,
				public asg::AsgTool {
    ASG_TOOL_CLASS2( HIVertexSelectionTool,
		     IAsgSelectionTool,
		     HI::IHIVertexSelectionTool )
  public:

    HIVertexSelectionTool( const std::string& name );
    ~HIVertexSelectionTool();

    virtual StatusCode initialize() override;
    virtual StatusCode finalize() override;

    virtual const Root::TAccept& getTAccept() const override;
    // we have to implement the IParticle function in order to inherit from IAsgSelectionTool
    // it will throw an exception
    virtual const Root::TAccept& accept( const xAOD::IParticle* ) const override;
    virtual const Root::TAccept& accept( const xAOD::Vertex& ) const override;

  private:
    mutable Root::TAccept m_accept;

    // configureable properties
    bool m_requirePrimary = true; //!< require the vertex to be of type PriVtx
    double m_maxAbsZ = 150.; //!< maximum |z| position of the vertex

    ToolHandle< InDet::IInDetTrackSelectionTool > m_trkSelTool; //!< track selection tool which can be optionally used for N_trk and sum pt cuts
    
  };
}


#endif // HIEVENTUTILS_HIVERTEXSELECTIONTOOL_H
