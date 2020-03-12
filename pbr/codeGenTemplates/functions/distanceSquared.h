#pragma once

#include <pbr/api.h>

{% for vectorType in context.vectorTypes -%}
#include <pbr/types/{{ vectorType.headerFileName }}>
{% endfor %}

#include <pbr/functions/lengthSquared.h>

PBR_NAMESPACE_BEGIN

{% for vectorType in context.vectorTypes %}
/// Compute the squared distance between two {{ vectorType.className }}s.
PBR_API
inline void FnDistanceSquared( const {{ vectorType.className }}& i_vectorA,
                               const {{ vectorType.className }}& i_vectorB,
                               {{ vectorType.scalarType }}& o_distanceSquared )
{
    {{ vectorType.className }} diffVector = i_vectorA - i_vectorB;
    FnLengthSquared( diffVector, o_distanceSquared );
}
{% endfor %}

PBR_NAMESPACE_END
