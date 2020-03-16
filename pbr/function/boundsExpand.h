#pragma once

#include <pbr/api.h>

#include <pbr/type/bounds2f.h>
#include <pbr/type/bounds2i.h>
#include <pbr/type/bounds3f.h>
#include <pbr/type/bounds3i.h>

PBR_NAMESPACE_BEGIN

/// Expand a bounding box by a constant factor in each dimension.

PBR_API
inline void FnBoundsExpand( const Bounds2i& i_bounds, const int& i_factor, Bounds2i& o_bounds )
{
    o_bounds.Min()[ 0 ] = i_bounds.Min()[ 0 ] - i_factor;
    o_bounds.Min()[ 1 ] = i_bounds.Min()[ 1 ] - i_factor;

    o_bounds.Max()[ 0 ] = i_bounds.Max()[ 0 ] + i_factor;
    o_bounds.Max()[ 1 ] = i_bounds.Max()[ 1 ] + i_factor;
}

PBR_API
inline void FnBoundsExpand( const Bounds2f& i_bounds, const float& i_factor, Bounds2f& o_bounds )
{
    o_bounds.Min()[ 0 ] = i_bounds.Min()[ 0 ] - i_factor;
    o_bounds.Min()[ 1 ] = i_bounds.Min()[ 1 ] - i_factor;

    o_bounds.Max()[ 0 ] = i_bounds.Max()[ 0 ] + i_factor;
    o_bounds.Max()[ 1 ] = i_bounds.Max()[ 1 ] + i_factor;
}

PBR_API
inline void FnBoundsExpand( const Bounds3i& i_bounds, const int& i_factor, Bounds3i& o_bounds )
{
    o_bounds.Min()[ 0 ] = i_bounds.Min()[ 0 ] - i_factor;
    o_bounds.Min()[ 1 ] = i_bounds.Min()[ 1 ] - i_factor;
    o_bounds.Min()[ 2 ] = i_bounds.Min()[ 2 ] - i_factor;

    o_bounds.Max()[ 0 ] = i_bounds.Max()[ 0 ] + i_factor;
    o_bounds.Max()[ 1 ] = i_bounds.Max()[ 1 ] + i_factor;
    o_bounds.Max()[ 2 ] = i_bounds.Max()[ 2 ] + i_factor;
}

PBR_API
inline void FnBoundsExpand( const Bounds3f& i_bounds, const float& i_factor, Bounds3f& o_bounds )
{
    o_bounds.Min()[ 0 ] = i_bounds.Min()[ 0 ] - i_factor;
    o_bounds.Min()[ 1 ] = i_bounds.Min()[ 1 ] - i_factor;
    o_bounds.Min()[ 2 ] = i_bounds.Min()[ 2 ] - i_factor;

    o_bounds.Max()[ 0 ] = i_bounds.Max()[ 0 ] + i_factor;
    o_bounds.Max()[ 1 ] = i_bounds.Max()[ 1 ] + i_factor;
    o_bounds.Max()[ 2 ] = i_bounds.Max()[ 2 ] + i_factor;
}

PBR_NAMESPACE_END