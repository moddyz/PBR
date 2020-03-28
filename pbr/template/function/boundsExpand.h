#pragma once

#include <pbr/api.h>

{% for dataType in context.types -%}
#include <pbr/type/{{ dataType.headerFileName }}>
{% endfor %}

PBR_NAMESPACE_BEGIN

/// Expand a bounding box by a constant factor in each dimension.

{% for dataType in context.types %}
PBR_API
inline void BoundsExpand( const {{ dataType.className }}& i_bounds,
                            const {{ dataType.elements[0].type.elementType.className }}& i_factor,
                            {{ dataType.className }}& o_bounds )
{
{% for index in range(dataType.elements[0].type.elementSize) -%}
    o_bounds.Min()[ {{ index }} ] = i_bounds.Min()[ {{ index }} ] - i_factor;
{% endfor %}
{% for index in range(dataType.elements[0].type.elementSize) -%}
    o_bounds.Max()[ {{ index }} ] = i_bounds.Max()[ {{ index }} ] + i_factor;
{% endfor %}
}
{% endfor %}

PBR_NAMESPACE_END
