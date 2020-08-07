#include <pbr/core/camera.h>

PBR_NS_OPEN

Camera::Camera( const Transform&      i_cameraToWorld,
                const gm::FloatRange& i_shutterRange,
                const Medium&         i_medium,
                Film&                 o_film )
    : m_cameraToWorld( i_cameraToWorld )
    , m_shutterRange( i_shutterRange )
    , m_medium( i_medium )
    , m_film( o_film )
{
}

PBR_NS_CLOSE
