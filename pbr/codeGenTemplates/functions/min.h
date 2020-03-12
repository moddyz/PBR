#pragma once

#include <pbr/api.h>

{% for dataType in context.types -%}
{% if dataType.isVector -%}
#include <pbr/types/{{ dataType.headerFileName }}>
{%- endif %}
{% endfor %}

#include <algorithm>

PBR_NAMESPACE_BEGIN

/// Compute the minimum between two values.
/// If the value type is a vector, then minimum is computed between the respective scalar element values.

{% for dataType in context.types %}
PBR_API
inline void FnMin( const {{ dataType.className }}& i_a,
                   const {{ dataType.className }}& i_b,
                   {{ dataType.className }}& o_min )
{
{% if dataType.isScalar -%}
    o_min = std::min( i_a, i_b );
{%- elif dataType.isVector -%}
{% for index in range(dataType.elementSize) -%}
    o_min[ {{index }} ] = std::min( i_a[ {{ index }} ], i_b[ {{ index }} ] );
{%- endfor %}
{%- endif %}
}
{% endfor %}

PBR_NAMESPACE_END
