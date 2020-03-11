#pragma once

#include <pbr/api.h>
#include <pbr/tools/almost.h>
#include <pbr/tools/assert.h>

#include <pbr/types/vec3f.h>

#include <pbr/functions/crossProduct.h>
#include <pbr/functions/length.h>

PBR_NAMESPACE_BEGIN

/// Compute a local coordinate system from \ref i_vector.
/// The result is two new vectors, of which all three are mutually orthogonal.
PBR_API
inline void FnCoordinateSystem( const Vec3f& i_vector, Vec3f& o_vectorA, Vec3f& o_vectorB )
{
    // Input vector should be normalised.
#ifdef PBR_DEBUG
    float length;
    FnLength( i_vector, length );
    PBR_ASSERT( TlAlmostEqual( length, 1.0f ) );
#endif

    // Compute first output vector by:
    // 1. Zeroing out one of the components,
    // 2. Swapping the 2 other ones.
    // 3. Negating one of the swapped components.
    // TODO: Describe why the following conditional expression is required.
    if ( std::abs( i_vector.X() ) > std::abs( i_vector.Y() ) )
    {
        o_vectorA = Vec3f( -i_vector.Z(), 0, i_vector.X() );
    }
    else
    {
        o_vectorA = Vec3f( 0, i_vector.Z(), -i_vector.Y() );
    }
    FnNormalise( o_vectorA, o_vectorA );

    // Compute the second output vector by via the cross product of the input & first output vector.
    FnCrossProduct( i_vector, o_vectorA, o_vectorB );
}

PBR_NAMESPACE_END