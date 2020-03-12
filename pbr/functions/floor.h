#pragma once

#include <pbr/api.h>

#include <pbr/types/vec2f.h>
#include <pbr/types/vec2i.h>
#include <pbr/types/vec3f.h>
#include <pbr/types/vec3i.h>
#include <pbr/types/vec4f.h>
#include <pbr/types/vec4i.h>

#include <cmath>

PBR_NAMESPACE_BEGIN

/// Floor the input value, by rounding downwards, returning the largest integral value less than the input.
/// If the value type is a vector, the floor will be performed element-wise.

PBR_API
inline void FnFloor( const int& i_value, int& o_floored )
{
    o_floored = std::floor( i_value );
}

PBR_API
inline void FnFloor( const float& i_value, float& o_floored )
{
    o_floored = std::floor( i_value );
}

PBR_API
inline void FnFloor( const Vec2f& i_value, Vec2f& o_floored )
{
    o_floored[ 0 ] = std::floor( i_value[ 0 ] );
    o_floored[ 1 ] = std::floor( i_value[ 1 ] );
}

PBR_API
inline void FnFloor( const Vec3f& i_value, Vec3f& o_floored )
{
    o_floored[ 0 ] = std::floor( i_value[ 0 ] );
    o_floored[ 1 ] = std::floor( i_value[ 1 ] );
    o_floored[ 2 ] = std::floor( i_value[ 2 ] );
}

PBR_API
inline void FnFloor( const Vec4f& i_value, Vec4f& o_floored )
{
    o_floored[ 0 ] = std::floor( i_value[ 0 ] );
    o_floored[ 1 ] = std::floor( i_value[ 1 ] );
    o_floored[ 2 ] = std::floor( i_value[ 2 ] );
    o_floored[ 3 ] = std::floor( i_value[ 3 ] );
}

PBR_API
inline void FnFloor( const Vec2i& i_value, Vec2i& o_floored )
{
    o_floored[ 0 ] = std::floor( i_value[ 0 ] );
    o_floored[ 1 ] = std::floor( i_value[ 1 ] );
}

PBR_API
inline void FnFloor( const Vec3i& i_value, Vec3i& o_floored )
{
    o_floored[ 0 ] = std::floor( i_value[ 0 ] );
    o_floored[ 1 ] = std::floor( i_value[ 1 ] );
    o_floored[ 2 ] = std::floor( i_value[ 2 ] );
}

PBR_API
inline void FnFloor( const Vec4i& i_value, Vec4i& o_floored )
{
    o_floored[ 0 ] = std::floor( i_value[ 0 ] );
    o_floored[ 1 ] = std::floor( i_value[ 1 ] );
    o_floored[ 2 ] = std::floor( i_value[ 2 ] );
    o_floored[ 3 ] = std::floor( i_value[ 3 ] );
}

PBR_NAMESPACE_END