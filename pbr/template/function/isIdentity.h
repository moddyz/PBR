#pragma once

#include <pbr/api.h>

{% for matrixType in context.types -%}
#include <pbr/type/{{ matrixType.headerFileName }}>
{% endfor %}

/// Checks if the input is an identity matrix.

PBR_NAMESPACE_BEGIN

{% for matrixType in context.types %}
PBR_API
inline void FnIsIdentity( const {{ matrixType.className }}& i_matrix, bool& o_isIdentity )
{
    o_isIdentity =
{% for row in range(matrixType.dims[0]) -%}
{% for col in range(matrixType.dims[1]) -%}
{% if row == col -%}
    i_matrix( {{ row }}, {{ col }} ) == 1.0
{%- else -%}
    i_matrix( {{ row }}, {{ col }} ) == 0.0
{%- endif %}
{% if row + 1 < matrixType.dims[0] or col + 1 < matrixType.dims[ 1 ] -%}
    &&
{%- endif %}
{%- endfor -%}
{%- endfor -%}
    ;
}
{% endfor %}

PBR_NAMESPACE_END
