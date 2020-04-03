#pragma once

#include <pbr/api.h>

{% for boundsType, matrixType in context.types -%}
#include <pbr/type/{{ matrixType.headerFileName }}>
{% endfor %}

#include <pbr/function/transformPoint.h>

/// Transform a \p i_bounds with the transformation matrix \p i_matrix, and write the results
/// into \p o_bounds.

PBR_NAMESPACE_BEGIN

{% for boundsType, matrixType in context.types %}
PBR_API
inline void TransformBounds( const {{ matrixType.className }}& i_matrix,
                             const {{ boundsType.className }}& i_bounds,
                             {{ boundsType.className }}& o_bounds )
{
    TransformPoint( i_matrix, i_bounds.Min(), o_bounds.Min() );
    TransformPoint( i_matrix, i_bounds.Max(), o_bounds.Max() );
}
{% endfor %}

PBR_NAMESPACE_END
