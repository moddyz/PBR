#pragma once

#include <pbr/api.h>

#include <pbr/type/mat4f.h>

/// Transform a vector \p i_vector with the transformation matrix \p i_matrix, and write the results
/// into \p o_vector.

PBR_NAMESPACE_BEGIN

PBR_API
inline void TransformVector( const Mat4f& i_matrix, const Vec3f& i_vector, Vec3f& o_vector )
{
    Vec3f vector;
    vector[ 0 ] =
        i_vector[ 0 ] * i_matrix( 0, 0 ) + i_vector[ 1 ] * i_matrix( 0, 1 ) + i_vector[ 2 ] * i_matrix( 0, 2 );
    vector[ 1 ] =
        i_vector[ 0 ] * i_matrix( 1, 0 ) + i_vector[ 1 ] * i_matrix( 1, 1 ) + i_vector[ 2 ] * i_matrix( 1, 2 );
    vector[ 2 ] =
        i_vector[ 0 ] * i_matrix( 2, 0 ) + i_vector[ 1 ] * i_matrix( 2, 1 ) + i_vector[ 2 ] * i_matrix( 2, 2 );
    o_vector = vector;
}

PBR_NAMESPACE_END