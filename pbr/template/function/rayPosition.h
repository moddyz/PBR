#pragma once

#include <pbr/api.h>

{% for vectorType in context.vectorTypes -%}
#include <pbr/type/{{ vectorType.headerFileName }}>
{% endfor %}

#include <pbr/function/debug.h>

PBR_NAMESPACE_BEGIN

/// Compute the position of a ray, from an origin, direction, and a scaling factor.

{% for vectorType in context.vectorTypes %}
PBR_API
inline void FnRayPosition( const {{ vectorType.className }}& i_origin,
                           const {{ vectorType.className }}& i_direction,
                           const {{ vectorType.elementType }}& i_scale,
                           {{ vectorType.className }}& o_rayPosition )
{
    // Direction should be normalised.
    PBR_ASSERT_NORMALISED( i_direction );
    o_rayPosition = i_origin + ( i_direction * i_scale );
}
{% endfor %}

PBR_NAMESPACE_END
