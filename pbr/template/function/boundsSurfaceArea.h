#pragma once

#include <pbr/api.h>

{% for dataType in context.types -%}
#include <pbr/type/{{ dataType.headerFileName }}>
{% endfor %}

#include <pbr/function/boundsDiagonal.h>

PBR_NAMESPACE_BEGIN

/// Compute the surface area of the input bounding box.

{% for dataType in context.types %}
PBR_API
inline void BoundsSurfaceArea( const {{ dataType.className }}& i_bounds,
                                 {{ dataType.elements[0].type.elementType.className }}& o_surfaceArea )
{
    {{ dataType.elements[0].type.className }} diagonal;
    BoundsDiagonal( i_bounds, diagonal );
    o_surfaceArea = ( diagonal.X() * diagonal.Y() ) + ( diagonal.Y() * diagonal.Z() ) + ( diagonal.X() * diagonal.Z() );
}
{% endfor %}

PBR_NAMESPACE_END
