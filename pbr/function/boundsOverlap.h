#pragma once

#include <pbr/api.h>

#include <pbr/type/bounds2f.h>
#include <pbr/type/bounds2i.h>
#include <pbr/type/bounds3f.h>
#include <pbr/type/bounds3i.h>

PBR_NAMESPACE_BEGIN

/// Check if two bounds overlap.

PBR_API
inline void BoundsOverlap( const Bounds2i& i_boundsA, const Bounds2i& i_boundsB, bool& o_overlaps )
{
    o_overlaps = ( i_boundsA.Min()[ 0 ] <= i_boundsB.Max()[ 0 ] ) && ( i_boundsA.Max()[ 0 ] >= i_boundsB.Min()[ 0 ] ) &&
                 ( i_boundsA.Min()[ 1 ] <= i_boundsB.Max()[ 1 ] ) && ( i_boundsA.Max()[ 1 ] >= i_boundsB.Min()[ 1 ] );
}

PBR_API
inline void BoundsOverlap( const Bounds2f& i_boundsA, const Bounds2f& i_boundsB, bool& o_overlaps )
{
    o_overlaps = ( i_boundsA.Min()[ 0 ] <= i_boundsB.Max()[ 0 ] ) && ( i_boundsA.Max()[ 0 ] >= i_boundsB.Min()[ 0 ] ) &&
                 ( i_boundsA.Min()[ 1 ] <= i_boundsB.Max()[ 1 ] ) && ( i_boundsA.Max()[ 1 ] >= i_boundsB.Min()[ 1 ] );
}

PBR_API
inline void BoundsOverlap( const Bounds3i& i_boundsA, const Bounds3i& i_boundsB, bool& o_overlaps )
{
    o_overlaps = ( i_boundsA.Min()[ 0 ] <= i_boundsB.Max()[ 0 ] ) && ( i_boundsA.Max()[ 0 ] >= i_boundsB.Min()[ 0 ] ) &&
                 ( i_boundsA.Min()[ 1 ] <= i_boundsB.Max()[ 1 ] ) && ( i_boundsA.Max()[ 1 ] >= i_boundsB.Min()[ 1 ] ) &&
                 ( i_boundsA.Min()[ 2 ] <= i_boundsB.Max()[ 2 ] ) && ( i_boundsA.Max()[ 2 ] >= i_boundsB.Min()[ 2 ] );
}

PBR_API
inline void BoundsOverlap( const Bounds3f& i_boundsA, const Bounds3f& i_boundsB, bool& o_overlaps )
{
    o_overlaps = ( i_boundsA.Min()[ 0 ] <= i_boundsB.Max()[ 0 ] ) && ( i_boundsA.Max()[ 0 ] >= i_boundsB.Min()[ 0 ] ) &&
                 ( i_boundsA.Min()[ 1 ] <= i_boundsB.Max()[ 1 ] ) && ( i_boundsA.Max()[ 1 ] >= i_boundsB.Min()[ 1 ] ) &&
                 ( i_boundsA.Min()[ 2 ] <= i_boundsB.Max()[ 2 ] ) && ( i_boundsA.Max()[ 2 ] >= i_boundsB.Min()[ 2 ] );
}

PBR_NAMESPACE_END