#pragma once

#include <pbr/api.h>

PBR_NAMESPACE_BEGIN

/// Converts an angle encoded in units of radians to degrees.

{% for dataType in context.types %}
PBR_API
inline void FnRadiansToDegrees( const {{ dataType.className }}& i_radians,
                                {{ dataType.className }}& o_degrees )
{
    constexpr {{ dataType.className }} halfRatio = 180.0 / 3.14159265358979323846;
    o_degrees = i_radians * halfRatio;
}
{% endfor %}

PBR_NAMESPACE_END
