#pragma once

#include <pbr/api.h>

{% for vectorType in context.vectorTypes -%}
#include <pbr/type/{{ vectorType.headerFileName }}>
{% endfor %}

PBR_NAMESPACE_BEGIN

/// Compute the cross product of two vectors.

{% for vectorType in context.vectorTypes -%}
PBR_API
inline void CrossProduct( const {{ vectorType.className }}& i_lhs,
                            const {{ vectorType.className }}& i_rhs,
                            {{ vectorType.className }}& o_product )
{
    o_product =
        {{ vectorType.className }}(
              ( ( double ) i_lhs.Y() * ( double ) i_rhs.Z() ) - ( ( double ) i_lhs.Z() * ( double ) i_rhs.Y() ),
              ( ( double ) i_lhs.Z() * ( double ) i_rhs.X() ) - ( ( double ) i_lhs.X() * ( double ) i_rhs.Z() ),
              ( ( double ) i_lhs.X() * ( double ) i_rhs.Y() ) - ( ( double ) i_lhs.Y() * ( double ) i_rhs.X() ) );
}
{%- endfor %}

PBR_NAMESPACE_END
