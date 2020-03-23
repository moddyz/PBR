#pragma once

#include <pbr/api.h>

{% for vectorType, matrixType in context.types -%}
#include <pbr/type/{{ vectorType.headerFileName }}>
#include <pbr/type/{{ matrixType.headerFileName }}>
{% endfor %}

#include <pbr/function/degreesToRadians.h>
#include <pbr/function/normalise.h>

/// Sets a rotation transformation around an arbitrary axis on a transform matrix.

PBR_NAMESPACE_BEGIN

{% for vectorType, matrixType in context.types %}
PBR_API
inline void FnSetRotate( const {{ matrixType.elementType.className }}& i_degrees,
                               const {{ vectorType.className }}& i_axis,
                               {{ matrixType.className }}& o_matrix )
{
    // Axis must be normalised.
    {{ vectorType.className }} normAxis;
    FnNormalise( i_axis, normAxis );

    // Compute cosine and sine.
    {{ matrixType.elementType.className }} radians;
    FnDegreesToRadians( i_degrees, radians );
    {{ matrixType.elementType.className }} sinTheta = std::sin( radians );
    {{ matrixType.elementType.className }} cosTheta = std::cos( radians );

    o_matrix( 0, 0 ) = normAxis[ 0 ] * normAxis[ 0 ] + (1 - normAxis[ 0 ] * normAxis[ 0 ]) * cosTheta;
    o_matrix( 0, 1 ) = normAxis[ 0 ] * normAxis[ 1 ] * (1 - cosTheta) - normAxis[ 2 ] * sinTheta;
    o_matrix( 0, 2 ) = normAxis[ 0 ] * normAxis[ 2 ] * (1 - cosTheta) + normAxis[ 1 ] * sinTheta;
    o_matrix( 0, 3 ) = 0;

    o_matrix( 1, 0 ) = normAxis[ 0 ] * normAxis[ 1 ] * (1 - cosTheta) + normAxis[ 2 ] * sinTheta;
    o_matrix( 1, 1 ) = normAxis[ 1 ] * normAxis[ 1 ] + (1 - normAxis[ 1 ] * normAxis[ 1 ]) * cosTheta;
    o_matrix( 1, 2 ) = normAxis[ 1 ] * normAxis[ 2 ] * (1 - cosTheta) - normAxis[ 0 ] * sinTheta;
    o_matrix( 1, 3 ) = 0;

    o_matrix( 2, 0 ) = normAxis[ 0 ] * normAxis[ 2 ] * (1 - cosTheta) - normAxis[ 1 ] * sinTheta;
    o_matrix( 2, 1 ) = normAxis[ 1 ] * normAxis[ 2 ] * (1 - cosTheta) + normAxis[ 0 ] * sinTheta;
    o_matrix( 2, 2 ) = normAxis[ 2 ] * normAxis[ 2 ] + (1 - normAxis[ 2 ] * normAxis[ 2 ]) * cosTheta;
    o_matrix( 2, 3 ) = 0;

}
{% endfor %}

PBR_NAMESPACE_END
