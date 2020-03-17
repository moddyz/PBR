#pragma once

#include <pbr/api.h>

#include <pbr/type/bounds2f.h>
#include <pbr/type/bounds3f.h>

PBR_NAMESPACE_BEGIN

/// Compute the point relative to the corners of the bounding box, from the range (0, 0, 0) to (1, 1, 1).

PBR_API
inline void FnBoundsOffset( const Bounds2f& i_bounds, const Vec2f& i_point, Vec2f& o_offset )
{
    o_offset = i_point - i_bounds.Min();

    if ( i_bounds.Max()[ 0 ] > i_bounds.Min()[ 0 ] )
    {
        o_offset[ 0 ] /= i_bounds.Max()[ 0 ] - i_bounds.Min()[ 0 ];
    }

    if ( i_bounds.Max()[ 1 ] > i_bounds.Min()[ 1 ] )
    {
        o_offset[ 1 ] /= i_bounds.Max()[ 1 ] - i_bounds.Min()[ 1 ];
    }
}

PBR_API
inline void FnBoundsOffset( const Bounds3f& i_bounds, const Vec3f& i_point, Vec3f& o_offset )
{
    o_offset = i_point - i_bounds.Min();

    if ( i_bounds.Max()[ 0 ] > i_bounds.Min()[ 0 ] )
    {
        o_offset[ 0 ] /= i_bounds.Max()[ 0 ] - i_bounds.Min()[ 0 ];
    }

    if ( i_bounds.Max()[ 1 ] > i_bounds.Min()[ 1 ] )
    {
        o_offset[ 1 ] /= i_bounds.Max()[ 1 ] - i_bounds.Min()[ 1 ];
    }

    if ( i_bounds.Max()[ 2 ] > i_bounds.Min()[ 2 ] )
    {
        o_offset[ 2 ] /= i_bounds.Max()[ 2 ] - i_bounds.Min()[ 2 ];
    }
}

PBR_NAMESPACE_END