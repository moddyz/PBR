#pragma once

#include <pbr/api.h>

{% for dataType in context.types -%}
#include <pbr/type/{{ dataType.headerFileName }}>
{% endfor %}

#include <pbr/function/min.h>
#include <pbr/function/max.h>

PBR_NAMESPACE_BEGIN

/// Compute the intersection of two bounding boxes.
/// THe computed intersection can be described as the overlapping bounding box formed by the two inputs.

{% for dataType in context.types %}
PBR_API
inline void FnBoundsIntersection( const {{ dataType.className }}& i_boundsA,
                                  const {{ dataType.className }}& i_boundsB,
                                  {{ dataType.className }}& o_intersection )
{
    FnMax( i_boundsA.Min(), i_boundsB.Min(), o_intersection.Min() );
    FnMin( i_boundsA.Max(), i_boundsB.Max(), o_intersection.Max() );
}
{% endfor %}

PBR_NAMESPACE_END
