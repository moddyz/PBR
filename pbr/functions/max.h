#pragma once

#include <pbr/api.h>

#include <pbr/types/vec2f.h>
#include <pbr/types/vec2i.h>
#include <pbr/types/vec3f.h>
#include <pbr/types/vec3i.h>
#include <pbr/types/vec4f.h>
#include <pbr/types/vec4i.h>

#include <algorithm>

PBR_NAMESPACE_BEGIN

/// Compute the maximum between two values.
/// If the value type is a vector, then maximum is computed between the respective scalar element values.

PBR_API
inline void FnMax( const int& i_a, const int& i_b, int& o_max )
{
    o_max = std::max( i_a, i_b );
}

PBR_API
inline void FnMax( const float& i_a, const float& i_b, float& o_max )
{
    o_max = std::max( i_a, i_b );
}

PBR_API
inline void FnMax( const Vec2f& i_a, const Vec2f& i_b, Vec2f& o_max )
{
    o_max[ 0 ] = std::max( i_a[ 0 ], i_b[ 0 ] );
    o_max[ 1 ] = std::max( i_a[ 1 ], i_b[ 1 ] );
}

PBR_API
inline void FnMax( const Vec3f& i_a, const Vec3f& i_b, Vec3f& o_max )
{
    o_max[ 0 ] = std::max( i_a[ 0 ], i_b[ 0 ] );
    o_max[ 1 ] = std::max( i_a[ 1 ], i_b[ 1 ] );
    o_max[ 2 ] = std::max( i_a[ 2 ], i_b[ 2 ] );
}

PBR_API
inline void FnMax( const Vec4f& i_a, const Vec4f& i_b, Vec4f& o_max )
{
    o_max[ 0 ] = std::max( i_a[ 0 ], i_b[ 0 ] );
    o_max[ 1 ] = std::max( i_a[ 1 ], i_b[ 1 ] );
    o_max[ 2 ] = std::max( i_a[ 2 ], i_b[ 2 ] );
    o_max[ 3 ] = std::max( i_a[ 3 ], i_b[ 3 ] );
}

PBR_API
inline void FnMax( const Vec2i& i_a, const Vec2i& i_b, Vec2i& o_max )
{
    o_max[ 0 ] = std::max( i_a[ 0 ], i_b[ 0 ] );
    o_max[ 1 ] = std::max( i_a[ 1 ], i_b[ 1 ] );
}

PBR_API
inline void FnMax( const Vec3i& i_a, const Vec3i& i_b, Vec3i& o_max )
{
    o_max[ 0 ] = std::max( i_a[ 0 ], i_b[ 0 ] );
    o_max[ 1 ] = std::max( i_a[ 1 ], i_b[ 1 ] );
    o_max[ 2 ] = std::max( i_a[ 2 ], i_b[ 2 ] );
}

PBR_API
inline void FnMax( const Vec4i& i_a, const Vec4i& i_b, Vec4i& o_max )
{
    o_max[ 0 ] = std::max( i_a[ 0 ], i_b[ 0 ] );
    o_max[ 1 ] = std::max( i_a[ 1 ], i_b[ 1 ] );
    o_max[ 2 ] = std::max( i_a[ 2 ], i_b[ 2 ] );
    o_max[ 3 ] = std::max( i_a[ 3 ], i_b[ 3 ] );
}

PBR_NAMESPACE_END