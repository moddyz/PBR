#include <pbr/core/shape.h>
#include <pbr/core/transform.h>

PBR_NS_OPEN

Shape::Shape( const Transform& i_objectToWorld, const Transform& i_worldToObject )
    : m_objectToWorld( i_objectToWorld )
    , m_worldToObject( i_worldToObject )
{
}

gm::Vec3fRange Shape::ComputeWorldBounds() const
{
    return m_objectToWorld.TransformBounds( ComputeObjectBounds() );
}

bool Shape::IntersectPredicate( const Ray& i_ray ) const
{
    float rayMagnitude = i_ray.GetMaxMagnitude();
    SurfaceInteraction surfaceInteraction;
    return Intersect( i_ray, magnitude, surfaceInteraction );
}

PBR_NS_CLOSE
