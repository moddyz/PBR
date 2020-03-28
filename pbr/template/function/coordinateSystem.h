#pragma once

#include <pbr/api.h>
#include <pbr/tool/assert.h>
#include <pbr/tool/almost.h>

{% for vectorType in context.vectorTypes -%}
#include <pbr/type/{{ vectorType.headerFileName }}>
{% endfor %}

#include <pbr/function/debug.h>
#include <pbr/function/length.h>
#include <pbr/function/normalise.h>
#include <pbr/function/crossProduct.h>

PBR_NAMESPACE_BEGIN

{% for vectorType in context.vectorTypes -%}
/// Compute a local coordinate system from \ref i_vector.
/// The result is two new vectors, of which all three are mutually orthogonal.
PBR_API
inline void CoordinateSystem( const {{ vectorType.className }}& i_vector,
                                {{ vectorType.className }}& o_vectorA,
                                {{ vectorType.className }}& o_vectorB )
{
    PBR_ASSERT_NORMALISED( i_vector );

    // Compute first output vector by:
    // 1. Zeroing out one of the components,
    // 2. Swapping the 2 other ones.
    // 3. Negating one of the swapped components.
    // TODO: Describe why the following conditional expression is required.
    if ( std::abs( i_vector.X() ) > std::abs( i_vector.Y() ) )
    {
        o_vectorA = {{vectorType.className}}( -i_vector.Z(), 0, i_vector.X() );
    }
    else
    {
        o_vectorA = {{vectorType.className}}( 0, i_vector.Z(), -i_vector.Y() );
    }
    Normalise( o_vectorA, o_vectorA );

    // Compute the second output vector by via the cross product of the input & first output vector.
    CrossProduct( i_vector, o_vectorA, o_vectorB );
}
{%- endfor %}

PBR_NAMESPACE_END
