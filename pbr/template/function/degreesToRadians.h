#pragma once

#include <pbr/api.h>

PBR_NAMESPACE_BEGIN

/// Converts an angle encoded in degrees to radians.

{% for dataType in context.types %}
PBR_API
inline void DegreesToRadians( const {{ dataType.className }}& i_degrees,
                                {{ dataType.className }}& o_radians )
{
    constexpr {{ dataType.className }} halfRatio = 3.14159265358979323846 / 180.0;
    o_radians = i_degrees * halfRatio;
}
{% endfor %}

PBR_NAMESPACE_END
