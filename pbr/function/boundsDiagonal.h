#pragma once

#include <pbr/api.h>

#include <pbr/type/bounds2f.h>
#include <pbr/type/bounds2i.h>
#include <pbr/type/bounds3f.h>
#include <pbr/type/bounds3i.h>

PBR_NAMESPACE_BEGIN

/// Compute the diagonal vector of a bounding box, defined as the vector from the min to the max.

PBR_API
inline void FnBoundsDiagonal( const Bounds2i& i_bounds, Vec2i& o_diagonal )
{
    o_diagonal = i_bounds.Max() - i_bounds.Min();
}

PBR_API
inline void FnBoundsDiagonal( const Bounds2f& i_bounds, Vec2f& o_diagonal )
{
    o_diagonal = i_bounds.Max() - i_bounds.Min();
}

PBR_API
inline void FnBoundsDiagonal( const Bounds3i& i_bounds, Vec3i& o_diagonal )
{
    o_diagonal = i_bounds.Max() - i_bounds.Min();
}

PBR_API
inline void FnBoundsDiagonal( const Bounds3f& i_bounds, Vec3f& o_diagonal )
{
    o_diagonal = i_bounds.Max() - i_bounds.Min();
}

PBR_NAMESPACE_END