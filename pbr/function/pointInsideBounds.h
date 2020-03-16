#pragma once

#include <pbr/api.h>

#include <pbr/type/bounds2f.h>
#include <pbr/type/bounds2i.h>
#include <pbr/type/bounds3f.h>
#include <pbr/type/bounds3i.h>

PBR_NAMESPACE_BEGIN

/// Check if a point is inside a bounding box.

PBR_API
inline void FnPointInsideBounds( const Vec2i& i_point, const Bounds2i& i_bounds, bool& o_inside )
{
    o_inside = ( i_bounds.Min()[ 0 ] <= i_point[ 0 ] ) && ( i_bounds.Max()[ 0 ] >= i_point[ 0 ] ) &&
               ( i_bounds.Min()[ 1 ] <= i_point[ 1 ] ) && ( i_bounds.Max()[ 1 ] >= i_point[ 1 ] );
}

PBR_API
inline void FnPointInsideBounds( const Vec2f& i_point, const Bounds2f& i_bounds, bool& o_inside )
{
    o_inside = ( i_bounds.Min()[ 0 ] <= i_point[ 0 ] ) && ( i_bounds.Max()[ 0 ] >= i_point[ 0 ] ) &&
               ( i_bounds.Min()[ 1 ] <= i_point[ 1 ] ) && ( i_bounds.Max()[ 1 ] >= i_point[ 1 ] );
}

PBR_API
inline void FnPointInsideBounds( const Vec3i& i_point, const Bounds3i& i_bounds, bool& o_inside )
{
    o_inside = ( i_bounds.Min()[ 0 ] <= i_point[ 0 ] ) && ( i_bounds.Max()[ 0 ] >= i_point[ 0 ] ) &&
               ( i_bounds.Min()[ 1 ] <= i_point[ 1 ] ) && ( i_bounds.Max()[ 1 ] >= i_point[ 1 ] ) &&
               ( i_bounds.Min()[ 2 ] <= i_point[ 2 ] ) && ( i_bounds.Max()[ 2 ] >= i_point[ 2 ] );
}

PBR_API
inline void FnPointInsideBounds( const Vec3f& i_point, const Bounds3f& i_bounds, bool& o_inside )
{
    o_inside = ( i_bounds.Min()[ 0 ] <= i_point[ 0 ] ) && ( i_bounds.Max()[ 0 ] >= i_point[ 0 ] ) &&
               ( i_bounds.Min()[ 1 ] <= i_point[ 1 ] ) && ( i_bounds.Max()[ 1 ] >= i_point[ 1 ] ) &&
               ( i_bounds.Min()[ 2 ] <= i_point[ 2 ] ) && ( i_bounds.Max()[ 2 ] >= i_point[ 2 ] );
}

PBR_NAMESPACE_END