#pragma once

#include <pbr/api.h>

{% for dataType in context.types -%}
{% if dataType.isVector -%}
#include <pbr/type/{{ dataType.headerFileName }}>
{%- endif %}
{% endfor %}

#include <cmath>

PBR_NAMESPACE_BEGIN

/// Floor the input value, by rounding downwards, returning the largest integral value less than the input.
/// If the value type is a vector, the floor will be performed element-wise.

{% for dataType in context.types %}
PBR_API
inline void Floor( const {{ dataType.className }}& i_value,
                     {{ dataType.className }}& o_floored )
{
{% if dataType.isScalar -%}
    o_floored = std::floor( i_value );
{%- elif dataType.isVector -%}
{% for index in range(dataType.elementSize) %}
    o_floored[ {{ index }} ] = std::floor( i_value[ {{ index }} ] );
{%- endfor %}
{%- endif %}
}
{% endfor %}

PBR_NAMESPACE_END
