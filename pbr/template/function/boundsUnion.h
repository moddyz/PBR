#pragma once

#include <pbr/api.h>

{% for dataType in context.types -%}
#include <pbr/type/{{ dataType.headerFileName }}>
{% endfor %}

#include <pbr/function/min.h>
#include <pbr/function/max.h>

PBR_NAMESPACE_BEGIN

/// Compute the union of two bounding boxes, or a bounding box and a point.
/// THe computed union is defined as the minimized bounding box encompassing both inputs.

{% for dataType in context.types %}
PBR_API
inline void FnBoundsUnion( const {{ dataType.className }}& i_boundsA,
                           const {{ dataType.className }}& i_boundsB,
                           {{ dataType.className }}& o_union )
{
    FnMin( i_boundsA.Min(), i_boundsB.Min(), o_union.Min() );
    FnMax( i_boundsA.Max(), i_boundsB.Max(), o_union.Max() );
}
{% endfor %}

{% for dataType in context.types %}
PBR_API
inline void FnBoundsUnion( const {{ dataType.className }}& i_bounds,
                           const {{ dataType.elements[0].type.className }}& i_point,
                           {{ dataType.className }}& o_union )
{
    FnMin( i_bounds.Min(), i_point, o_union.Min() );
    FnMax( i_bounds.Max(), i_point, o_union.Max() );
}
{% endfor %}

PBR_NAMESPACE_END
