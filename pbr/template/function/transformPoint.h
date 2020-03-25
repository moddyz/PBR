#pragma once

#include <pbr/api.h>

{% for vectorType, matrixType in context.types -%}
#include <pbr/type/{{ matrixType.headerFileName }}>
{% endfor %}

/// Transform a \p i_point with the transformation matrix \p i_matrix, and write the results
/// into \p o_point.

PBR_NAMESPACE_BEGIN

{% for vectorType, matrixType in context.types %}
PBR_API
inline void FnTransformPoint( const {{ vectorType.className }}& i_point,
                              const {{ matrixType.className }}& i_matrix,
                              {{ vectorType.className }}& o_point )
{
{% for index in range(vectorType.elementSize + 1) -%}
{%- if index == 3 -%}
    {{vectorType.elementType.className }} homogenousWeight =
{%- else -%}
    {{vectorType.elementType.className }} element{{ index }} =
{%- endif -%}
{%- for col in range(matrixType.dims[1]) -%}
{%- if col < 3 -%}
    i_point[ {{ col }} ] * i_matrix( {{ index }}, {{ col }} ) +
{%- else -%}
    i_matrix( {{ index }}, {{ col }} );
{%- endif -%}
{%- endfor -%}
{%- endfor -%}

    if ( homogenousWeight == 1.0 )
    {
        o_point = {{ vectorType.className }}( element0, element1, element2 );
    }
    else
    {
        o_point = {{ vectorType.className }}( element0, element1, element2 ) / homogenousWeight;
    }

}
{% endfor %}

PBR_NAMESPACE_END
