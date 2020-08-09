#include <pbr/core/geometricPrimitive.h>

PBR_NS_OPEN

GeometricPrimitive::GeometricPrimitive( const ShapeSharedPtr& i_shape, const MaterialSharedPtr& i_material )
    : m_shape( i_shape )
    , m_material( i_material )
{
}

PBR_NS_CLOSE
