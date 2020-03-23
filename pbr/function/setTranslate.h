#pragma once

#include <pbr/api.h>

#include <pbr/type/mat3f.h>
#include <pbr/type/mat4f.h>
#include <pbr/type/vec2f.h>
#include <pbr/type/vec3f.h>

/// Sets a translate transformation on a matrix.

PBR_NAMESPACE_BEGIN

PBR_API
inline void FnSetTranslate( const Vec2f& i_translate, Mat3f& o_matrix )
{
    o_matrix( 0, 2 ) = i_translate[ 0 ];
    o_matrix( 1, 2 ) = i_translate[ 1 ];
}

PBR_API
inline void FnSetTranslate( const Vec3f& i_translate, Mat4f& o_matrix )
{
    o_matrix( 0, 3 ) = i_translate[ 0 ];
    o_matrix( 1, 3 ) = i_translate[ 1 ];
    o_matrix( 2, 3 ) = i_translate[ 2 ];
}

PBR_NAMESPACE_END