#include <pbr/core/shape.h>
#include <pbr/core/transform.h>

PBR_NS_OPEN

gm::Vec3fRange Shape::WorldBounds() const
{
    return m_objectToWorld->TransformBounds( ObjectBounds() );
}

PBR_NS_CLOSE
