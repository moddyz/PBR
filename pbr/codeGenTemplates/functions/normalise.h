#pragma once

#include <pbr/api.h>

{% for vectorType in context.vectorTypes -%}
#include <pbr/types/{{ vectorType.headerFileName }}>
{% endfor %}

#include <pbr/functions/length.h>

PBR_NAMESPACE_BEGIN

{% for vectorType in context.vectorTypes %}
/// Compute the normalised vector.
PBR_API
inline void FnNormalise( const {{ vectorType.className }}& i_vector, {{ vectorType.className }}& o_normalised )
{
    {{ vectorType.scalarType }} length;
    FnLength( i_vector, length );
    o_normalised = i_vector / length;
}
{% endfor %}

PBR_NAMESPACE_END
