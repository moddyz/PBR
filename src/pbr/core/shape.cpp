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

PBR_NS_CLOSE
