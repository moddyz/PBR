#pragma once

#include <pbr/api.h>

{% for vectorType in context.vectorTypes -%}
#include <pbr/types/{{ vectorType.headerFileName }}>
{% endfor %}

PBR_NAMESPACE_BEGIN

{% for vectorType in context.vectorTypes %}
/// Compute the dot product of two {{ vectorType.className }}.
PBR_API
inline void FnDotProduct( const {{ vectorType.className }}& i_lhs,
                          const {{ vectorType.className }}& i_rhs,
                          {{ vectorType.scalarType }}& o_product )
{
    o_product = ( i_lhs.X() * i_rhs.X() ) + ( i_lhs.Y() * i_rhs.Y() ) + ( i_lhs.Z() * i_rhs.Z() );
}
{% endfor %}

PBR_NAMESPACE_END
