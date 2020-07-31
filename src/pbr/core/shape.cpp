#include <pbr/core/shape.h>
#include <pbr/core/transform.h>

PBR_NS_OPEN

Shape::Shape( const Transform& i_objectToWorld, const Transform& i_worldToObject )
    : m_objectToWorld( i_objectToWorld )
    , m_worldToObject( i_worldToObject )
{
}

gm::Vec3fRange Shape::WorldBounds() const
{
    return m_objectToWorld.TransformBounds( ObjectBounds() );
}

PBR_NS_CLOSE
