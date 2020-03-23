#pragma once

#include <pbr/api.h>

#include <pbr/type/mat4f.h>
#include <pbr/type/vec3f.h>

#include <pbr/function/degreesToRadians.h>
#include <pbr/function/normalise.h>

/// Sets a rotation transformation around an arbitrary axis on a transform matrix.

PBR_NAMESPACE_BEGIN

PBR_API
inline void FnSetRotate( const float& i_degrees, const Vec3f& i_axis, Mat4f& o_matrix )
{
    // Axis must be normalised.
    Vec3f normAxis;
    FnNormalise( i_axis, normAxis );

    // Compute cosine and sine.
    float radians;
    FnDegreesToRadians( i_degrees, radians );
    float sinTheta = std::sin( radians );
    float cosTheta = std::cos( radians );

    o_matrix( 0, 0 ) = normAxis[ 0 ] * normAxis[ 0 ] + ( 1 - normAxis[ 0 ] * normAxis[ 0 ] ) * cosTheta;
    o_matrix( 0, 1 ) = normAxis[ 0 ] * normAxis[ 1 ] * ( 1 - cosTheta ) - normAxis[ 2 ] * sinTheta;
    o_matrix( 0, 2 ) = normAxis[ 0 ] * normAxis[ 2 ] * ( 1 - cosTheta ) + normAxis[ 1 ] * sinTheta;
    o_matrix( 0, 3 ) = 0;

    o_matrix( 1, 0 ) = normAxis[ 0 ] * normAxis[ 1 ] * ( 1 - cosTheta ) + normAxis[ 2 ] * sinTheta;
    o_matrix( 1, 1 ) = normAxis[ 1 ] * normAxis[ 1 ] + ( 1 - normAxis[ 1 ] * normAxis[ 1 ] ) * cosTheta;
    o_matrix( 1, 2 ) = normAxis[ 1 ] * normAxis[ 2 ] * ( 1 - cosTheta ) - normAxis[ 0 ] * sinTheta;
    o_matrix( 1, 3 ) = 0;

    o_matrix( 2, 0 ) = normAxis[ 0 ] * normAxis[ 2 ] * ( 1 - cosTheta ) - normAxis[ 1 ] * sinTheta;
    o_matrix( 2, 1 ) = normAxis[ 1 ] * normAxis[ 2 ] * ( 1 - cosTheta ) + normAxis[ 0 ] * sinTheta;
    o_matrix( 2, 2 ) = normAxis[ 2 ] * normAxis[ 2 ] + ( 1 - normAxis[ 2 ] * normAxis[ 2 ] ) * cosTheta;
    o_matrix( 2, 3 ) = 0;
}

PBR_NAMESPACE_END