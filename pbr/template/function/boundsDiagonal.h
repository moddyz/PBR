#pragma once

#include <pbr/api.h>

{% for dataType in context.types -%}
#include <pbr/type/{{ dataType.headerFileName }}>
{% endfor %}

PBR_NAMESPACE_BEGIN

/// Compute the diagonal vector of a bounding box, defined as the vector from the min to the max.

{% for dataType in context.types %}
PBR_API
inline void BoundsDiagonal( const {{ dataType.className }}& i_bounds,
                              {{ dataType.elements[0].type.className }}& o_diagonal )
{
    o_diagonal = i_bounds.Max() - i_bounds.Min();
}
{% endfor %}

PBR_NAMESPACE_END
