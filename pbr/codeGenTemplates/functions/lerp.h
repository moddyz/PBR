#pragma once

#include <pbr/api.h>

{% for dataType in context.types -%}
{% if dataType.isVector -%}
#include <pbr/types/{{ dataType.headerFileName }}>
{%- endif %}
{% endfor %}

/// Compute the linear interpolation between two values.
///
/// \param i_factor should be between [0,1]. Describes the percentage to interpolate between the two values,
/// where a factor of 0 would result in o_interpolated == i_a and a factor of 1 would result in o_interpolated == i_b.
/// \param i_a the source value to interpolate from.
/// \param i_b the target value to interpolate to.
/// \param o_interpolated the interpolated value.

PBR_NAMESPACE_BEGIN

{% for dataType in context.types %}
PBR_API
inline void FnLerp( const float& i_factor,
                    const {{ dataType.className }}& i_a,
                    const {{ dataType.className }}& i_b,
                    {{ dataType.className }}& o_interpolated )
{
    PBR_ASSERT_MSG( i_factor >= 0.0f && i_factor <= 1.0f,
                    "Expected i_factor between [0,1], got %f\n",
                    i_factor );
    o_interpolated = ( ( 1.0f - i_factor ) * i_a ) + ( i_factor * i_b );
}
{% endfor %}

PBR_NAMESPACE_END
