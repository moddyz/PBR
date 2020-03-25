#pragma once

#include <pbr/api.h>

#include <pbr/type/mat4f.h>

/// Transform a \p i_point with the transformation matrix \p i_matrix, and write the results
/// into \p o_point.

PBR_NAMESPACE_BEGIN

PBR_API
inline void FnTransformPoint( const Vec3f& i_point, const Mat4f& i_matrix, Vec3f& o_point )
{
    float element0 = i_point[ 0 ] * i_matrix( 0, 0 ) + i_point[ 1 ] * i_matrix( 0, 1 ) +
                     i_point[ 2 ] * i_matrix( 0, 2 ) + i_matrix( 0, 3 );
    float element1 = i_point[ 0 ] * i_matrix( 1, 0 ) + i_point[ 1 ] * i_matrix( 1, 1 ) +
                     i_point[ 2 ] * i_matrix( 1, 2 ) + i_matrix( 1, 3 );
    float element2 = i_point[ 0 ] * i_matrix( 2, 0 ) + i_point[ 1 ] * i_matrix( 2, 1 ) +
                     i_point[ 2 ] * i_matrix( 2, 2 ) + i_matrix( 2, 3 );
    float homogenousWeight = i_point[ 0 ] * i_matrix( 3, 0 ) + i_point[ 1 ] * i_matrix( 3, 1 ) +
                             i_point[ 2 ] * i_matrix( 3, 2 ) + i_matrix( 3, 3 );
    if ( homogenousWeight == 1.0 )
    {
        o_point = Vec3f( element0, element1, element2 );
    }
    else
    {
        o_point = Vec3f( element0, element1, element2 ) / homogenousWeight;
    }
}

PBR_NAMESPACE_END