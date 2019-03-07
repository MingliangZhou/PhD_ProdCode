
#include "HIEventUtils/HIVertexSelectionTool.h"
#include "AsgTools/Check.h"

using std::string;

HI::HIVertexSelectionTool::HIVertexSelectionTool( const string& name )
  : asg::AsgTool( name )
  , m_accept( "HIVertexSelection" )
{

// #ifndef XAOD_STANDALONE
//   declareInterface<IHIVertexSelectionTool>(this);
// #endif
  
  declareProperty( "RequirePrimary", m_requirePrimary, "Require the vertex to have type PriVtx");
  declareProperty( "MaxAbsZ", m_maxAbsZ, "Maximum absolute value of the vertex z position");

  declareProperty( "TrackSelectionTool", m_trkSelTool );
}

HI::HIVertexSelectionTool::~HIVertexSelectionTool() = default;

StatusCode HI::HIVertexSelectionTool::initialize()
{
  ATH_MSG_INFO( "Initializing vertex selection tool." );
  ATH_CHECK( asg::AsgTool::initialize() );

  if (!m_trkSelTool.empty()) ATH_CHECK( m_trkSelTool.retrieve() );
  
  if (m_requirePrimary) {
    ATH_MSG_INFO( "Requiring vertex to be a primary vertex." );
    m_accept.addCut( "type", "Whether the vertex satisfies the requirement to be a primary vertex" );
  }
  else {
    ATH_MSG_INFO( "NOT requiring vertex to be a primary vertex." );
  }

  if (m_maxAbsZ > 0.) {
    ATH_MSG_INFO( "Maximum |z| = " << m_maxAbsZ << " mm." );
    m_accept.addCut( "z", "Whether the vertex's |z| is in an allowed range" );  
  }

  return StatusCode::SUCCESS;
}

StatusCode HI::HIVertexSelectionTool::finalize()
{
  ATH_MSG_INFO( "Finalizing vertex selection tool." );
  if (!m_trkSelTool.empty()) ATH_CHECK( m_trkSelTool->finalize() );
  return StatusCode::SUCCESS;
}

const Root::TAccept& HI::HIVertexSelectionTool::getTAccept() const
{
  // return the current TAccept object by reference. This allows users to avoid copying it.
  return m_accept;
}

const Root::TAccept& HI::HIVertexSelectionTool::accept( const xAOD::IParticle* ) const
{
  m_accept.clear();
  ATH_MSG_ERROR( "Vertex selection tool should not be passed an IParticle." );
  throw std::invalid_argument( "Vertex selection tool given an IParticle." );
  return m_accept;
}

const Root::TAccept& HI::HIVertexSelectionTool::accept( const xAOD::Vertex& vtx ) const
{
  m_accept.clear();

  if (!m_requirePrimary || vtx.vertexType() == xAOD::VxType::PriVtx) {
    m_accept.setCutResult( "type", true );
  }
  if (m_maxAbsZ < 0. || std::fabs( vtx.z() ) < m_maxAbsZ) {
    m_accept.setCutResult( "z", true );
  }

  return m_accept;
}
