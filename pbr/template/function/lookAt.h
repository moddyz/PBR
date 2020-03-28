#pragma once

#include <pbr/api.h>

{% for vectorType, matrixType in context.types -%}
#include <pbr/type/{{ vectorType.headerFileName }}>
#include <pbr/type/{{ matrixType.headerFileName }}>
{% endfor %}

#include <pbr/function/setTranslate.h>
#include <pbr/function/normalise.h>
#include <pbr/function/crossProduct.h>

PBR_NAMESPACE_BEGIN

/// Compute the LookAt transform, provided a position, a point to look at, and a up vector for orientation.
/// This is generally used to position and orient a camera in a scene.

{% for vectorType, matrixType in context.types -%}
PBR_API
inline void LookAt( const {{ vectorType.className }}& i_position,
                      const {{ vectorType.className }}& i_lookAt,
                      const {{ vectorType.className }}& i_upVector,
                      {{ matrixType.className }}& o_matrix )
{
    SetTranslate( i_position, o_matrix );
    o_matrix( 3, 3 ) = 1.0;

    // Compute forward vector.
    {{ vectorType.className }} forward = i_lookAt - i_position;
    Normalise( forward, forward );

    // Set forward as new Z-axis basis.
    o_matrix( 0, 2 ) = forward[ 0 ];
    o_matrix( 1, 2 ) = forward[ 1 ];
    o_matrix( 2, 2 ) = forward[ 2 ];
    o_matrix( 3, 2 ) = 0.0;

    // Compute right vector.
    {{ vectorType.className }} normUp, right;
    Normalise( i_upVector, normUp );
    CrossProduct( normUp, forward, right );
    Normalise( right, right );

    // Set right as new X-axis basis.
    o_matrix( 0, 0 ) = right[ 0 ];
    o_matrix( 1, 0 ) = right[ 1 ];
    o_matrix( 2, 0 ) = right[ 2 ];
    o_matrix( 3, 0 ) = 0.0;

    // Re-compute new up vector.
    // TODO: Explain why we have to do this.
    {{ vectorType.className }} newUp;
    CrossProduct( forward, right, newUp );

    // Set newUp as new X-axis basis.
    o_matrix( 0, 1 ) = newUp[ 0 ];
    o_matrix( 1, 1 ) = newUp[ 1 ];
    o_matrix( 2, 1 ) = newUp[ 2 ];
    o_matrix( 3, 1 ) = 0.0;
}
{% endfor %}

PBR_NAMESPACE_END
