#pragma once

#include <pbr/api.h>

#include <pbr/type/mat3f.h>
#include <pbr/type/mat4f.h>
#include <pbr/type/vec2f.h>
#include <pbr/type/vec3f.h>

/// Sets a scale transformation on a matrix.

PBR_NAMESPACE_BEGIN

PBR_API
inline void FnMatrixSetScale( const Vec2f& i_scale, Mat3f& o_matrix )
{
    o_matrix( 0, 0 ) = i_scale[ 0 ];
    o_matrix( 1, 1 ) = i_scale[ 1 ];
}

PBR_API
inline void FnMatrixSetScale( const Vec3f& i_scale, Mat4f& o_matrix )
{
    o_matrix( 0, 0 ) = i_scale[ 0 ];
    o_matrix( 1, 1 ) = i_scale[ 1 ];
    o_matrix( 2, 2 ) = i_scale[ 2 ];
}

PBR_NAMESPACE_END