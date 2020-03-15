#pragma once

#include <pbr/api.h>

#include <pbr/type/bounds2f.h>
#include <pbr/type/bounds2i.h>
#include <pbr/type/bounds3f.h>
#include <pbr/type/bounds3i.h>

#include <pbr/function/max.h>
#include <pbr/function/min.h>

PBR_NAMESPACE_BEGIN

/// Compute the intersection of two bounding boxes.
/// THe computed intersection can be described as the overlapping bounding box formed by the two inputs.

PBR_API
inline void FnBoundsIntersection( const Bounds2i& i_boundsA, const Bounds2i& i_boundsB, Bounds2i& o_intersection )
{
    FnMax( i_boundsA.Min(), i_boundsB.Min(), o_intersection.Min() );
    FnMin( i_boundsA.Max(), i_boundsB.Max(), o_intersection.Max() );
}

PBR_API
inline void FnBoundsIntersection( const Bounds2f& i_boundsA, const Bounds2f& i_boundsB, Bounds2f& o_intersection )
{
    FnMax( i_boundsA.Min(), i_boundsB.Min(), o_intersection.Min() );
    FnMin( i_boundsA.Max(), i_boundsB.Max(), o_intersection.Max() );
}

PBR_API
inline void FnBoundsIntersection( const Bounds3i& i_boundsA, const Bounds3i& i_boundsB, Bounds3i& o_intersection )
{
    FnMax( i_boundsA.Min(), i_boundsB.Min(), o_intersection.Min() );
    FnMin( i_boundsA.Max(), i_boundsB.Max(), o_intersection.Max() );
}

PBR_API
inline void FnBoundsIntersection( const Bounds3f& i_boundsA, const Bounds3f& i_boundsB, Bounds3f& o_intersection )
{
    FnMax( i_boundsA.Min(), i_boundsB.Min(), o_intersection.Min() );
    FnMin( i_boundsA.Max(), i_boundsB.Max(), o_intersection.Max() );
}

PBR_NAMESPACE_END