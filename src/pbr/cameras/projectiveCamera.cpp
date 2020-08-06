#include <pbr/cameras/projectiveCamera.h>

PBR_NS_OPEN

ProjectiveCamera::ProjectiveCamera( const Transform&      i_cameraToWorld,
                                    const Transform&      i_cameraToScreen,
                                    const Vec2fRange&     i_screenWindow,
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
    Transform screenOffset = Transform::Translate( -i_screenWindow.Min().X(), -i_screenWindow.Max().Y(), 0 );

    // Normalize screen space coordinates.
    Transform screenToNormDeviceCoord =
        Transform::Scale( 1.0f / ( i_screenWindow.Max().X() - i_screenWindow.Min().X() ),
                          1.0f / ( i_screenWindow.Min().Y() - i_screenWindow.Max().Y() ),
                          1 );

    // Multiply normalized screen-space coordinates by full raster resolution.
    Transform normDeviceCoordToRaster =
        Transform::Scale( m_film->FullResolution().X(), m_film->FullResolution().Y(), 1 );

    m_screenToRaster = normDeviceCoordToRaster * screenToNormDeviceCoord * screenOffset;
    m_rasterToScreen = m_screenToRaster.Inverse();
    m_rasterToCamera = m_cameraToScreen.Inverse() * m_rasterToScreen;
}

PBR_NS_CLOSE

