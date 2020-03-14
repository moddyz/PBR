#pragma once

#include <pbr/api.h>

{% for vectorType in context.vectorTypes -%}
#include <pbr/types/{{ vectorType.headerFileName }}>
{% endfor %}

#include <pbr/functions/dotProduct.h>

PBR_NAMESPACE_BEGIN

/// Given a normal and a directional vector, conditionally flip the normal so that it faces the hemisphere
/// as the directional vector.

{% for vectorType in context.vectorTypes %}
PBR_API
inline void FnFaceForward( const {{ vectorType.className }}& i_normal,
                           const {{ vectorType.className }}& i_direction,
                           {{ vectorType.className }}& o_faceForwardNormal )
{
    // Input vector should be normalised.
#ifdef PBR_DEBUG
    {{ vectorType.scalarType }} length;
    FnLength( i_normal, length );
    PBR_ASSERT( TlAlmostEqual( length, 1.0f ) );
#endif

    {{ vectorType.scalarType }} product = 0.0f;
    FnDotProduct( i_normal, i_direction, product );
    o_faceForwardNormal = product >= 0 ? i_normal : -i_normal;
}
{% endfor %}

PBR_NAMESPACE_END
