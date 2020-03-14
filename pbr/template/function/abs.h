#pragma once

#include <pbr/api.h>

{% for dataType in context.types -%}
{% if dataType.isVector -%}
#include <pbr/type/{{ dataType.headerFileName }}>
{%- endif %}
{% endfor %}

#include <cmath>

PBR_NAMESPACE_BEGIN

/// Compute the absolute value of the input, which is the magnitude of the value without its sign.
/// If the value type is a vector, the absolute value will be performed element-wise.

{% for dataType in context.types %}
PBR_API
inline void FnAbs( const {{ dataType.className }}& i_value,
                    {{ dataType.className }}& o_absoluteValue )
{
{% if dataType.isScalar -%}
    o_absoluteValue = std::abs( i_value );
{%- elif dataType.isVector -%}
{% for index in range(dataType.elementSize) %}
    o_absoluteValue[ {{ index }} ] = std::abs( i_value[ {{ index }} ] );
{%- endfor %}
{%- endif %}
}
{% endfor %}

PBR_NAMESPACE_END
