#pragma once

/// \file core/integrator.h
///
/// Integrator class.

#include <pbr/pbr.h>

PBR_NS_OPEN

class Scene;

/// \class Integrator
///
/// Abstract base class to define an interface for rendering a scene.
class Integrator
{
public:
    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    virtual ~Integrator() {};

    // --------------------------------------------------------------------- //
    /// \name Rendering
    // --------------------------------------------------------------------- //

    /// Render the scene \p i_scene.
    virtual void Render( const Scene& i_scene ) = 0;
};

PBR_NS_CLOSE
