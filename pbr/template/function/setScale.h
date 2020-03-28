#pragma once

#include <pbr/api.h>

{% for vectorType, matrixType in context.types -%}
#include <pbr/type/{{ vectorType.headerFileName }}>
#include <pbr/type/{{ matrixType.headerFileName }}>
{% endfor %}

/// Sets a scale transformation on a matrix.

PBR_NAMESPACE_BEGIN

{% for vectorType, matrixType in context.types %}
PBR_API
inline void SetScale( const {{ vectorType.className }}& i_scale, {{ matrixType.className }}& o_matrix )
{
{% for row in range(matrixType.dims[0]) -%}
{% for col in range(matrixType.dims[1]) -%}
{% if row == col and row + 1 < matrixType.dims[0]  -%}
    o_matrix( {{ row }}, {{ col }} ) = i_scale[ {{ row }} ];
{%- endif %}
{%- endfor -%}
{%- endfor -%}
}
{% endfor %}

PBR_NAMESPACE_END
