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

bool Sphere::Intersect( const Ray& i_ray, float& o_rayMagnitude, SurfaceInteraction& o_interaction ) const
{
    // TODO
    return false;
}

float Sphere::ComputeSurfaceArea() const
{
    // TODO
    return -1;
}

PBR_NS_CLOSE
