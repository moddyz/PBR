#pragma once

/// \file cameras/projectiveCamera.h
///
/// ProjectiveCamera class.

#include <pbr/core/camera.h>

#include <gm/types/floatRange.h>
#include <gm/types/vec2fRange.h>

PBR_NS_OPEN

/// \class ProjectiveCamera
///
/// A camera model which uses a 4x4 projective transformation matrix to
/// project a 3D screen onto a 2D image for display.
class ProjectiveCamera : public Camera
{
public:
    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Constructor with parameters.
    ///
    /// \param i_cameraToWorld The transform that places the camera in world-space.
    /// \param i_cameraToScreen The transform from camera-space to screen-space.
    /// \param i_screenWindow The 2D window at the near plane, in screen space.
    /// \param i_shutterRange The shutter open and close times.
    /// \param i_medium The medium that the camera resides in.
    /// \param i_lensRadius Radius of the camera lens.
    /// \param i_focalDistance Distance between the camera and the point of focus.
    /// \param o_film ?
    ProjectiveCamera( const Transform&      i_cameraToWorld,
                      const Transform&      i_cameraToScreen,
                      const gm::Vec2fRange& i_screenWindow,
                      const gm::FloatRange& i_shutterRange,
                      float                 i_lensRadius,
                      float                 i_focalDistance,
                      const Medium&         i_medium,
                      Film&                 o_film );

    // --------------------------------------------------------------------- //
    /// \name Ray generation
    // --------------------------------------------------------------------- //

    virtual float GenerateRay( const CameraSample& i_sample, Ray& o_ray ) const;

protected:
    Transform m_cameraToScreen;
    Transform m_rasterToCamera;
    Transform m_screenToRaster;
    Transform m_rasterToScreen;

    float m_lensRadius    = 0.0f;
    float m_focalDistance = 0.0f;
};

PBR_NS_CLOSE
