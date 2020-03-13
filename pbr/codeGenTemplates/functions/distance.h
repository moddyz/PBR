#pragma once

#include <pbr/api.h>

{% for vectorType in context.vectorTypes -%}
#include <pbr/types/{{ vectorType.headerFileName }}>
{% endfor %}

#include <pbr/functions/length.h>

PBR_NAMESPACE_BEGIN

/// Compute the distance between two points.

{% for vectorType in context.vectorTypes %}
PBR_API
inline void FnDistance( const {{ vectorType.className }}& i_vectorA,
                        const {{ vectorType.className }}& i_vectorB,
                        {{ vectorType.scalarType }}& o_distance )
{
    {{ vectorType.className }} diffVector = i_vectorA - i_vectorB;
    FnLength( diffVector, o_distance );
}
{% endfor %}

PBR_NAMESPACE_END
