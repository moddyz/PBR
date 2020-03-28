#pragma once

#include <pbr/api.h>

#include <pbr/type/vec2f.h>
#include <pbr/type/vec2i.h>
#include <pbr/type/vec3f.h>
#include <pbr/type/vec3i.h>
#include <pbr/type/vec4f.h>
#include <pbr/type/vec4i.h>

#include <cmath>

PBR_NAMESPACE_BEGIN

/// Compute the absolute value of the input, which is the magnitude of the value without its sign.
/// If the value type is a vector, the absolute value will be performed element-wise.

PBR_API
inline void Abs( const int& i_value, int& o_absoluteValue )
{
    o_absoluteValue = std::abs( i_value );
}

PBR_API
inline void Abs( const float& i_value, float& o_absoluteValue )
{
    o_absoluteValue = std::abs( i_value );
}

PBR_API
inline void Abs( const Vec2f& i_value, Vec2f& o_absoluteValue )
{
    o_absoluteValue[ 0 ] = std::abs( i_value[ 0 ] );
    o_absoluteValue[ 1 ] = std::abs( i_value[ 1 ] );
}

PBR_API
inline void Abs( const Vec3f& i_value, Vec3f& o_absoluteValue )
{
    o_absoluteValue[ 0 ] = std::abs( i_value[ 0 ] );
    o_absoluteValue[ 1 ] = std::abs( i_value[ 1 ] );
    o_absoluteValue[ 2 ] = std::abs( i_value[ 2 ] );
}

PBR_API
inline void Abs( const Vec4f& i_value, Vec4f& o_absoluteValue )
{
    o_absoluteValue[ 0 ] = std::abs( i_value[ 0 ] );
    o_absoluteValue[ 1 ] = std::abs( i_value[ 1 ] );
    o_absoluteValue[ 2 ] = std::abs( i_value[ 2 ] );
    o_absoluteValue[ 3 ] = std::abs( i_value[ 3 ] );
}

PBR_API
inline void Abs( const Vec2i& i_value, Vec2i& o_absoluteValue )
{
    o_absoluteValue[ 0 ] = std::abs( i_value[ 0 ] );
    o_absoluteValue[ 1 ] = std::abs( i_value[ 1 ] );
}

PBR_API
inline void Abs( const Vec3i& i_value, Vec3i& o_absoluteValue )
{
    o_absoluteValue[ 0 ] = std::abs( i_value[ 0 ] );
    o_absoluteValue[ 1 ] = std::abs( i_value[ 1 ] );
    o_absoluteValue[ 2 ] = std::abs( i_value[ 2 ] );
}

PBR_API
inline void Abs( const Vec4i& i_value, Vec4i& o_absoluteValue )
{
    o_absoluteValue[ 0 ] = std::abs( i_value[ 0 ] );
    o_absoluteValue[ 1 ] = std::abs( i_value[ 1 ] );
    o_absoluteValue[ 2 ] = std::abs( i_value[ 2 ] );
    o_absoluteValue[ 3 ] = std::abs( i_value[ 3 ] );
}

PBR_NAMESPACE_END