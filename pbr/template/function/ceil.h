#pragma once

#include <pbr/api.h>

{% for dataType in context.types -%}
{% if dataType.isVector -%}
#include <pbr/type/{{ dataType.headerFileName }}>
{%- endif %}
{% endfor %}

#include <cmath>

PBR_NAMESPACE_BEGIN

/// Compute the ceiling of the input value, by rounding upwards, returning the smallest integral value greater than the input.
/// If the value type is a vector, the ceiling will be operated element-wise.

{% for dataType in context.types %}
PBR_API
inline void Ceil( const {{ dataType.className }}& i_value,
                    {{ dataType.className }}& o_ceiled )
{
{% if dataType.isScalar -%}
    o_ceiled = std::ceil( i_value );
{%- elif dataType.isVector -%}
{% for index in range(dataType.elementSize) %}
    o_ceiled[ {{ index }} ] = std::ceil( i_value[ {{ index }} ] );
{%- endfor %}
{%- endif %}
}
{% endfor %}

PBR_NAMESPACE_END
