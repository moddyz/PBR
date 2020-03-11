#pragma once

#include <pbr/api.h>

{% for vectorType in context.vectorTypes -%}
#include <pbr/types/{{ vectorType.headerFileName }}>
{% endfor %}

PBR_NAMESPACE_BEGIN

{% for vectorType in context.vectorTypes %}
/// Compute the dot product of two {{ vectorType.className }}.
PBR_API
inline void FnDotProduct( const {{ vectorType.className }}& i_lhs,
                          const {{ vectorType.className }}& i_rhs,
                          {{ vectorType.scalarType }}& o_product )
{
    o_product = 0;
{% for index in range(vectorType.elementSize) -%}
    o_product += i_lhs[ {{ index }} ] * i_rhs[ {{ index }} ];
{%- endfor %}
}
{% endfor %}

PBR_NAMESPACE_END
