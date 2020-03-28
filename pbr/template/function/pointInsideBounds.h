#pragma once

#include <pbr/api.h>

{% for dataType in context.types -%}
#include <pbr/type/{{ dataType.headerFileName }}>
{% endfor %}

PBR_NAMESPACE_BEGIN

/// Check if a point is inside a bounding box.

{% for dataType in context.types %}
PBR_API
inline void PointInsideBounds( const {{ dataType.elements[0].type.className }}& i_point,
                                 const {{ dataType.className }}& i_bounds,
                                 bool& o_inside )
{
    o_inside =
{% for index in range(dataType.elements[0].type.elementSize) -%}
        ( i_bounds.Min()[ {{ index }} ] <= i_point[ {{ index }} ] ) &&
        ( i_bounds.Max()[ {{ index }} ] >= i_point[ {{ index }} ] )
{%- if index + 1 < dataType.elements[0].type.elementSize -%}
        &&
{% else -%}
        ;
{%- endif %}
{%- endfor %}
}
{% endfor %}

PBR_NAMESPACE_END
