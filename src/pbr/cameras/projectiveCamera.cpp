#include <pbr/cameras/projectiveCamera.h>
#include <pbr/core/film.h>

PBR_NS_OPEN

ProjectiveCamera::ProjectiveCamera( const Transform&      i_cameraToWorld,
                                    const Transform&      i_cameraToScreen,
                                    const gm::Vec2fRange& i_screenWindow,
                                    const gm::FloatRange& i_shutterRange,
                                    float                 i_lensRadius,
                                    float                 i_focalDistance,
                                    const Medium&         i_medium,
                                    Film&                 o_film )
    : Camera( i_cameraToWorld, i_shutterRange, i_medium, o_film )
    , m_cameraToScreen( i_cameraToScreen )
    , m_lensRadius( i_lensRadius )
    , m_focalDistance( i_focalDistance )
{
    // Compute projective camera screen -> raster transformation.

    // Translate upper left corner of film plane to origin.
    Transform screenOffset =
        Transform::Translate( gm::Vec3f( -i_screenWindow.Min().X(), -i_screenWindow.Max().Y(), 0 ) );

    // Normalize screen space coordinates.
    Transform screenToNormDeviceCoord =
        Transform::Scale( gm::Vec3f( 1.0f / ( i_screenWindow.Max().X() - i_screenWindow.Min().X() ),
                                     1.0f / ( i_screenWindow.Min().Y() - i_screenWindow.Max().Y() ),
                                     1 ) );

    // Multiply normalized screen-space coordinates by full raster resolution.
    Transform normDeviceCoordToRaster =
        Transform::Scale( gm::Vec3f( m_film.GetFullResolution().X(), m_film.GetFullResolution().Y(), 1 ) );

    m_screenToRaster = normDeviceCoordToRaster * screenToNormDeviceCoord * screenOffset;
    m_rasterToScreen = m_screenToRaster.Inverse();
    m_rasterToCamera = m_cameraToScreen.Inverse() * m_rasterToScreen;
}

float ProjectiveCamera::GenerateRay( const CameraSample& i_sample, Ray& o_ray ) const
{
    return 1.0f;
}

PBR_NS_CLOSE

