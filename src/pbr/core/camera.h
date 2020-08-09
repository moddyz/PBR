#pragma once

/// \file core/camera.h
///
/// Camera class.

#include <pbr/core/transform.h>

#include <gm/types/floatRange.h>

#include <memory>

PBR_NS_OPEN

// Forward declarations.
class CameraSample;
class Medium;
class Film;
class Ray;

/// \class Camera
///
/// Abstract base class representation of a camera.
class Camera
{
public:
    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Constructor with parameters.
    ///
    /// \param i_cameraToWorld The transform that places the camera in world-space./
    /// \param i_shutterRange The shutter open and close times.
    /// \param i_medium The medium that the camera resides in.
    /// \param o_film ?
    Camera( const Transform&      i_cameraToWorld,
            const gm::FloatRange& i_shutterRange,
            const Medium&         i_medium,
            Film&                 o_film );

    virtual ~Camera() {};

    // --------------------------------------------------------------------- //
    /// \name Ray generation
    // --------------------------------------------------------------------- //

    /// Generate a ray based for a camera sample.
    ///
    /// \param i_sample Specification of the ray to generate.
    /// \param o_ray The generated ray.
    ///
    /// \return The contributing percentage of radiance arriving at the film plane.
    virtual float GenerateRay( const CameraSample& i_sample, Ray& o_ray ) const = 0;

protected:
    Transform      m_cameraToWorld;
    gm::FloatRange m_shutterRange;
    const Medium&  m_medium;
    Film&          m_film;
};

/// \typedef CameraSharedPtr
///
/// Convenience type definition.
using CameraSharedPtr = std::shared_ptr< Camera >;

PBR_NS_CLOSE
