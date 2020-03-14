#pragma once

#include <pbr/api.h>

{% for vectorType in context.vectorTypes -%}
#include <pbr/type/{{ vectorType.headerFileName }}>
{% endfor %}

PBR_NAMESPACE_BEGIN

{% for vectorType in context.vectorTypes %}
/// Compute the squared length of a vector.
PBR_API
inline void FnLengthSquared( const {{ vectorType.className }}& i_vector, {{ vectorType.elementType }}& o_lengthSquared )
{
    o_lengthSquared = 0;
{% for index in range(vectorType.elementSize) -%}
    o_lengthSquared += i_vector[ {{ index }} ] * i_vector[ {{ index }} ];
{%- endfor %}
}
{% endfor %}

PBR_NAMESPACE_END
