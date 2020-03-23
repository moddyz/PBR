#pragma once

#include <pbr/api.h>

#include <pbr/type/mat4f.h>

#include <pbr/function/degreesToRadians.h>

/// Sets a Y-axis rotate transformation on a matrix.

PBR_NAMESPACE_BEGIN

PBR_API
inline void FnSetRotateY( const float& i_degrees, Mat4f& o_matrix )
{
    float radians;
    FnDegreesToRadians( i_degrees, radians );
    float sine       = std::sin( radians );
    float cosine     = std::cos( radians );
    o_matrix( 0, 0 ) = cosine;
    o_matrix( 0, 2 ) = sine;
    o_matrix( 2, 0 ) = -sine;
    o_matrix( 2, 2 ) = cosine;
}

PBR_NAMESPACE_END