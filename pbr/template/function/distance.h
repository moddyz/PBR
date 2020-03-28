#pragma once

#include <pbr/api.h>

{% for vectorType in context.vectorTypes -%}
#include <pbr/type/{{ vectorType.headerFileName }}>
{% endfor %}

#include <pbr/function/length.h>

PBR_NAMESPACE_BEGIN

/// Compute the distance between two points.

{% for vectorType in context.vectorTypes %}
PBR_API
inline void Distance( const {{ vectorType.className }}& i_vectorA,
                        const {{ vectorType.className }}& i_vectorB,
                        {{ vectorType.elementType.className }}& o_distance )
{
    {{ vectorType.className }} diffVector = i_vectorA - i_vectorB;
    Length( diffVector, o_distance );
}
{% endfor %}

PBR_NAMESPACE_END
