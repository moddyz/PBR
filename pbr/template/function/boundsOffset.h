#pragma once

#include <pbr/api.h>

{% for dataType in context.types -%}
#include <pbr/type/{{ dataType.headerFileName }}>
{% endfor %}

PBR_NAMESPACE_BEGIN

/// Compute the point relative to the corners of the bounding box, from the range (0, 0, 0) to (1, 1, 1).

{% for dataType in context.types %}
PBR_API
inline void BoundsOffset( const {{ dataType.className }}& i_bounds,
                            const {{ dataType.elements[0].type.className }}& i_point,
                            {{ dataType.elements[0].type.className }}& o_offset )
{
    o_offset = i_point - i_bounds.Min();
{% for index in range(dataType.elements[0].type.elementSize) %}
    if ( i_bounds.Max()[ {{ index }} ] > i_bounds.Min()[ {{ index }} ] )
    {
        o_offset[ {{ index }} ] /= i_bounds.Max()[ {{ index }} ] - i_bounds.Min()[ {{ index }} ];
    }
{% endfor %}
}
{% endfor %}

PBR_NAMESPACE_END
