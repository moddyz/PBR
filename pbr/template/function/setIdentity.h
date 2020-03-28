#pragma once

#include <pbr/api.h>

{% for matrixType in context.types -%}
#include <pbr/type/{{ matrixType.headerFileName }}>
{% endfor %}

/// Sets the identity matrix on the output argument.

PBR_NAMESPACE_BEGIN

{% for matrixType in context.types %}
PBR_API
inline void SetIdentity( {{ matrixType.className }}& o_identityMatrix )
{
    o_identityMatrix = {{ matrixType.className }}(
{% for row in range(matrixType.dims[0]) -%}
{% for col in range(matrixType.dims[1]) -%}
{% if row == col -%}
    1.0
{%- else -%}
    0.0
{%- endif %}
{% if row + 1 < matrixType.dims[0] or col + 1 < matrixType.dims[ 1 ] -%}
    ,
{%- endif %}
{%- endfor -%}
{%- endfor -%}
    );
}
{% endfor %}

PBR_NAMESPACE_END
