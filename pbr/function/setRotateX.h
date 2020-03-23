#pragma once

#include <pbr/api.h>

#include <pbr/type/mat4f.h>

#include <pbr/function/degreesToRadians.h>

/// Sets a X-axis rotate transformation on a matrix.

PBR_NAMESPACE_BEGIN

PBR_API
inline void FnSetRotateX( const float& i_degrees, Mat4f& o_matrix )
{
    float radians;
    FnDegreesToRadians( i_degrees, radians );
    float sine       = std::sin( radians );
    float cosine     = std::cos( radians );
    o_matrix( 1, 1 ) = cosine;
    o_matrix( 1, 2 ) = -sine;
    o_matrix( 2, 1 ) = sine;
    o_matrix( 2, 2 ) = cosine;
}

PBR_NAMESPACE_END