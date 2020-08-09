#include <pbr/core/geometricPrimitive.h>
#include <pbr/core/ray.h>

PBR_NS_OPEN

GeometricPrimitive::GeometricPrimitive( const ShapeSharedPtr& i_shape, const MaterialSharedPtr& i_material )
    : m_shape( i_shape )
    , m_material( i_material )
{
}

gm::Vec3fRange GeometricPrimitive::ComputeWorldBounds() const
{
    return m_shape->ComputeWorldBounds();
}

bool GeometricPrimitive::Intersect( const Ray& i_ray, SurfaceInteraction& o_interaction ) const
{
    float rayMagnitude;
    if ( !m_shape->Intersect( i_ray, rayMagnitude, o_interaction ) )
    {
        // Ray does not intersect shape.
        return false;
    }

    i_ray.SetMaxMagnitude( rayMagnitude ); // Limit the maximum magnitude

    // o_interaction.SetPrimitive( this )
    // TODO Medium interaction.

    return true;
}

bool GeometricPrimitive::IntersectPredicate( const Ray& i_ray ) const
{
    return m_shape->IntersectPredicate( i_ray );
}

PBR_NS_CLOSE
