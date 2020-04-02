#pragma once

#include <pbr/api.h>

{% for matrixType in context.types -%}
#include <pbr/type/{{ matrixType.headerFileName }}>
{% endfor %}

PBR_NAMESPACE_BEGIN

/// Compute the product of two matrices.

{% for matrixType in context.types %}
PBR_API
inline void MatrixProduct( const {{ matrixType.className }}& i_lhs,
                           const {{ matrixType.className }}& i_rhs,
                           {{ matrixType.className }}& o_matrix )
{
    {{ matrixType.className }} matrix;
{%- for row in range(matrixType.dims[0] ) -%}
{%- for col in range(matrixType.dims[1] ) -%}
    matrix( {{ row }}, {{ col }} ) =
{%- for index in range( matrixType.dims[0] ) -%}
    i_lhs( {{ row }}, {{ index }} ) * i_rhs( {{ index }}, {{ col }} )
{%- if index + 1 < matrixType.dims[0] -%}
    +
{%- else -%}
    ;
{%- endif -%}
{%- endfor -%}
{%- endfor -%}
{%- endfor -%}

    o_matrix = matrix;
}
{% endfor %}

PBR_NAMESPACE_END
