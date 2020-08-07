#include <pbr/shapes/sphere.h>

PBR_NS_OPEN

Sphere::Sphere( const Transform& i_objectToWorld, const Transform& i_worldToObject, float i_radius )
    : Shape( i_objectToWorld, i_worldToObject )
    , m_radius( i_radius )
{
}

gm::Vec3fRange Sphere::ComputeObjectBounds() const
{
    gm::Vec3f hypotenuse( m_radius, m_radius, m_radius );
    return gm::Vec3fRange( -hypotenuse, hypotenuse );
}

PBR_NS_CLOSE
