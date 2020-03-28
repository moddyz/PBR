#pragma once

#include <pbr/api.h>

{% for dataType in context.types -%}
#include <pbr/type/{{ dataType.headerFileName }}>
{% endfor %}

#include <pbr/function/boundsDiagonal.h>

PBR_NAMESPACE_BEGIN

/// Computes the index of the bounding box axes which is the longest.

{% for dataType in context.types %}
PBR_API
inline void BoundsMaxExtent( const {{ dataType.className }}& i_bounds,
                               size_t& o_maxExtentIndex )
{
    {{ dataType.elements[0].type.className }} diagonal;
    BoundsDiagonal( i_bounds, diagonal );
    if ( diagonal[ 0 ] > diagonal[ 1 ] && diagonal[ 0 ] > diagonal[ 2 ] )
    {
        o_maxExtentIndex = 0;
    }
    else
    {
        if ( diagonal[ 1 ] > diagonal[ 2 ] )
        {
            o_maxExtentIndex = 1;
        }
        else
        {
            o_maxExtentIndex = 2;
        }
    }
}
{% endfor %}

PBR_NAMESPACE_END
