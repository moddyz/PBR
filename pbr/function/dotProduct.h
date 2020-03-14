#pragma once

#include <pbr/api.h>

#include <pbr/type/vec2f.h>
#include <pbr/type/vec3f.h>
#include <pbr/type/vec4f.h>

PBR_NAMESPACE_BEGIN

/// Compute the dot product of two Vec2f.
PBR_API
inline void FnDotProduct( const Vec2f& i_lhs, const Vec2f& i_rhs, float& o_product )
{
    o_product = 0;
    o_product += i_lhs[ 0 ] * i_rhs[ 0 ];
    o_product += i_lhs[ 1 ] * i_rhs[ 1 ];
}

/// Compute the dot product of two Vec3f.
PBR_API
inline void FnDotProduct( const Vec3f& i_lhs, const Vec3f& i_rhs, float& o_product )
{
    o_product = 0;
    o_product += i_lhs[ 0 ] * i_rhs[ 0 ];
    o_product += i_lhs[ 1 ] * i_rhs[ 1 ];
    o_product += i_lhs[ 2 ] * i_rhs[ 2 ];
}

/// Compute the dot product of two Vec4f.
PBR_API
inline void FnDotProduct( const Vec4f& i_lhs, const Vec4f& i_rhs, float& o_product )
{
    o_product = 0;
    o_product += i_lhs[ 0 ] * i_rhs[ 0 ];
    o_product += i_lhs[ 1 ] * i_rhs[ 1 ];
    o_product += i_lhs[ 2 ] * i_rhs[ 2 ];
    o_product += i_lhs[ 3 ] * i_rhs[ 3 ];
}

PBR_NAMESPACE_END