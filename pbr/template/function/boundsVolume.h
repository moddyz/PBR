#pragma once

#include <pbr/api.h>

{% for dataType in context.types -%}
#include <pbr/type/{{ dataType.headerFileName }}>
{% endfor %}

#include <pbr/function/boundsDiagonal.h>

PBR_NAMESPACE_BEGIN

/// Compute the volume of the input bounding box.

{% for dataType in context.types %}
PBR_API
inline void FnBoundsVolume( const {{ dataType.className }}& i_bounds,
                            {{ dataType.elements[0].type.elementType.className }}& o_volume )
{
    {{ dataType.elements[0].type.className }} diagonal;
    FnBoundsDiagonal( i_bounds, diagonal );
    o_volume = diagonal.X() * diagonal.Y() * diagonal.Z();
}
{% endfor %}

PBR_NAMESPACE_END
