#include <pbr/core/samplerIntegrator.h>

PBR_NS_OPEN

SamplerIntegrator::SamplerIntegrator( const CameraSharedPtr& i_camera, const SamplerSharedPtr& i_sampler )
    : m_camera( i_camera )
    , m_sampler( i_sampler )
{
}

void SamplerIntegrator::Render( const Scene& i_scene )
{
}

PBR_NS_CLOSE
