#pragma once

#include <pbr/api.h>

{% for dataType in context.types -%}
{% if dataType.isVector -%}
#include <pbr/type/{{ dataType.headerFileName }}>
{%- endif %}
{% endfor %}

#include <algorithm>

PBR_NAMESPACE_BEGIN

/// Compute the maximum between two values.
/// If the value type is a vector, then maximum is computed between the respective scalar element values.

{% for dataType in context.types %}
PBR_API
inline void Max( const {{ dataType.className }}& i_a,
                   const {{ dataType.className }}& i_b,
                   {{ dataType.className }}& o_max )
{
{% if dataType.isScalar -%}
    o_max = std::max( i_a, i_b );
{%- elif dataType.isVector -%}
{% for index in range(dataType.elementSize) -%}
    o_max[ {{index }} ] = std::max( i_a[ {{ index }} ], i_b[ {{ index }} ] );
{%- endfor %}
{%- endif %}
}
{% endfor %}

PBR_NAMESPACE_END
