#pragma once

#include <pbr/api.h>

{% for dataType in context.types -%}
#include <pbr/type/{{ dataType.headerFileName }}>
{% endfor %}

PBR_NAMESPACE_BEGIN

/// Check if two bounds overlap.

{% for dataType in context.types %}
PBR_API
inline void FnBoundsOverlap( const {{ dataType.className }}& i_boundsA,
                             const {{ dataType.className }}& i_boundsB,
                             bool& o_overlaps )
{
    o_overlaps =
{% for index in range(dataType.elements[0].type.elementSize) -%}
        ( i_boundsA.Min()[ {{ index }} ] <= i_boundsB.Max()[ {{ index }} ] ) &&
        ( i_boundsA.Max()[ {{ index }} ] >= i_boundsB.Min()[ {{ index }} ] )
{%- if index + 1 < dataType.elements[0].type.elementSize -%}
        &&
{% else -%}
        ;
{%- endif %}
{%- endfor %}
}
{% endfor %}

PBR_NAMESPACE_END
