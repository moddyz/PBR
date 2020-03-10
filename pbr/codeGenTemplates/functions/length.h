#pragma once

#include <pbr/api.h>

{% for vectorType in context.vectorTypes -%}
#include <pbr/types/{{ vectorType.headerFileName }}>
{% endfor %}

#include <pbr/functions/lengthSquared.h>

PBR_NAMESPACE_BEGIN

{% for vectorType in context.vectorTypes %}
/// Compute the length of {{ vectorType.className }}.
PBR_API
inline void FnLength( const {{ vectorType.className }}& i_vector, {{ vectorType.scalarType }}& o_length )
{
    FnLengthSquared( i_vector, o_length );
    o_length = sqrt( o_length );
}
{% endfor %}

PBR_NAMESPACE_END
