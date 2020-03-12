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

/// Compute the minimum between two values.
/// If the value type is a vector, then minimum is computed between the respective scalar element values.

PBR_API
inline void FnMin( const int& i_a, const int& i_b, int& o_min )
{
    o_min = std::min( i_a, i_b );
}

PBR_API
inline void FnMin( const float& i_a, const float& i_b, float& o_min )
{
    o_min = std::min( i_a, i_b );
}

PBR_API
inline void FnMin( const Vec2f& i_a, const Vec2f& i_b, Vec2f& o_min )
{
    o_min[ 0 ] = std::min( i_a[ 0 ], i_b[ 0 ] );
    o_min[ 1 ] = std::min( i_a[ 1 ], i_b[ 1 ] );
}

PBR_API
inline void FnMin( const Vec3f& i_a, const Vec3f& i_b, Vec3f& o_min )
{
    o_min[ 0 ] = std::min( i_a[ 0 ], i_b[ 0 ] );
    o_min[ 1 ] = std::min( i_a[ 1 ], i_b[ 1 ] );
    o_min[ 2 ] = std::min( i_a[ 2 ], i_b[ 2 ] );
}

PBR_API
inline void FnMin( const Vec4f& i_a, const Vec4f& i_b, Vec4f& o_min )
{
    o_min[ 0 ] = std::min( i_a[ 0 ], i_b[ 0 ] );
    o_min[ 1 ] = std::min( i_a[ 1 ], i_b[ 1 ] );
    o_min[ 2 ] = std::min( i_a[ 2 ], i_b[ 2 ] );
    o_min[ 3 ] = std::min( i_a[ 3 ], i_b[ 3 ] );
}

PBR_API
inline void FnMin( const Vec2i& i_a, const Vec2i& i_b, Vec2i& o_min )
{
    o_min[ 0 ] = std::min( i_a[ 0 ], i_b[ 0 ] );
    o_min[ 1 ] = std::min( i_a[ 1 ], i_b[ 1 ] );
}

PBR_API
inline void FnMin( const Vec3i& i_a, const Vec3i& i_b, Vec3i& o_min )
{
    o_min[ 0 ] = std::min( i_a[ 0 ], i_b[ 0 ] );
    o_min[ 1 ] = std::min( i_a[ 1 ], i_b[ 1 ] );
    o_min[ 2 ] = std::min( i_a[ 2 ], i_b[ 2 ] );
}

PBR_API
inline void FnMin( const Vec4i& i_a, const Vec4i& i_b, Vec4i& o_min )
{
    o_min[ 0 ] = std::min( i_a[ 0 ], i_b[ 0 ] );
    o_min[ 1 ] = std::min( i_a[ 1 ], i_b[ 1 ] );
    o_min[ 2 ] = std::min( i_a[ 2 ], i_b[ 2 ] );
    o_min[ 3 ] = std::min( i_a[ 3 ], i_b[ 3 ] );
}

PBR_NAMESPACE_END