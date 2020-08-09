#pragma once

/// \file core/samplerIntegrator.h
///
/// SamplerIntegrator class.

#include <pbr/core/camera.h>
#include <pbr/core/integrator.h>
#include <pbr/core/sampler.h>

PBR_NS_OPEN

/// \class SamplerIntegrator
///
/// Implementation of an integrator which uses a Sampler, for choosing the positions on the image plane
/// from which rays are traced.
///
/// \sa Sampler
class SamplerIntegrator : public Integrator
{
public:
    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Parameterized constructor.
    ///
    /// \param i_camera The camera to trace rays from.
    /// \param i_sampler The sampler for choosing the sample positions on the image plane.
    explicit SamplerIntegrator( const CameraSharedPtr& i_camera, const SamplerSharedPtr& i_sampler );

    // --------------------------------------------------------------------- //
    /// \name Rendering
    // --------------------------------------------------------------------- //

    virtual void Render( const Scene& i_scene ) override;

private:
    CameraSharedPtr  m_camera;
    SamplerSharedPtr m_sampler;
};

PBR_NS_CLOSE
