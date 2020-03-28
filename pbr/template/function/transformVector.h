#pragma once

#include <pbr/api.h>

{% for vectorType, matrixType in context.types -%}
#include <pbr/type/{{ matrixType.headerFileName }}>
{% endfor %}

/// Transform a vector \p i_vector with the transformation matrix \p i_matrix, and write the results
/// into \p o_vector.

PBR_NAMESPACE_BEGIN

{% for vectorType, matrixType in context.types %}
PBR_API
inline void TransformVector( const {{ vectorType.className }}& i_vector,
                               const {{ matrixType.className }}& i_matrix,
                               {{ vectorType.className }}& o_vector )
{
{% for index in range(vectorType.elementSize) -%}
    o_vector[ {{ index }} ] =
{%- for col in range(matrixType.dims[1] - 1) -%}
    i_vector[ {{ col }} ] * i_matrix( {{ index }}, {{ col }} )
{%- if col + 2 < matrixType.dims[1] -%}
    +
{%- else -%}
    ;
{%- endif -%}
{%- endfor -%}
{%- endfor -%}
}
{% endfor %}

PBR_NAMESPACE_END
