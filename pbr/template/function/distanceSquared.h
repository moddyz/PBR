#pragma once

#include <pbr/api.h>

{% for vectorType in context.vectorTypes -%}
#include <pbr/type/{{ vectorType.headerFileName }}>
{% endfor %}

#include <pbr/function/lengthSquared.h>

PBR_NAMESPACE_BEGIN

/// Compute the squared distance between two points.

{% for vectorType in context.vectorTypes %}
PBR_API
inline void DistanceSquared( const {{ vectorType.className }}& i_vectorA,
                               const {{ vectorType.className }}& i_vectorB,
                               {{ vectorType.elementType.className }}& o_distanceSquared )
{
    {{ vectorType.className }} diffVector = i_vectorA - i_vectorB;
    LengthSquared( diffVector, o_distanceSquared );
}
{% endfor %}

PBR_NAMESPACE_END
