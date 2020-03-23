#pragma once

#include <pbr/api.h>

{% for matrixType in context.types -%}
#include <pbr/type/{{ matrixType.headerFileName }}>
{% endfor %}

/// Tranpose the input matrix.

PBR_NAMESPACE_BEGIN

{% for matrixType in context.types %}
PBR_API
inline void FnTranspose( const {{ matrixType.className }}& i_matrix,
                               {{ matrixType.className }}& o_transposedMatrix )
{
    o_transposedMatrix = {{ matrixType.className }}(
{% for row in range(matrixType.dims[0]) -%}
{% for col in range(matrixType.dims[1]) -%}
    i_matrix( {{ col }}, {{ row }} )
{% if row + 1 < matrixType.dims[0] or col + 1 < matrixType.dims[ 1 ] -%}
    ,
{%- endif %}
{%- endfor -%}
{%- endfor -%}
    );
}
{% endfor %}

PBR_NAMESPACE_END
