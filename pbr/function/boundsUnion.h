#pragma once

#include <pbr/api.h>

#include <pbr/type/bounds2f.h>
#include <pbr/type/bounds2i.h>
#include <pbr/type/bounds3f.h>
#include <pbr/type/bounds3i.h>

#include <pbr/function/max.h>
#include <pbr/function/min.h>

PBR_NAMESPACE_BEGIN

/// Compute the union of two bounding boxes, or a bounding box and a point.
/// THe computed union is defined as the minimized bounding box encompassing both inputs.

PBR_API
inline void FnBoundsUnion( const Bounds2i& i_boundsA, const Bounds2i& i_boundsB, Bounds2i& o_union )
{
    FnMin( i_boundsA.Min(), i_boundsB.Min(), o_union.Min() );
    FnMax( i_boundsA.Max(), i_boundsB.Max(), o_union.Max() );
}

PBR_API
inline void FnBoundsUnion( const Bounds2f& i_boundsA, const Bounds2f& i_boundsB, Bounds2f& o_union )
{
    FnMin( i_boundsA.Min(), i_boundsB.Min(), o_union.Min() );
    FnMax( i_boundsA.Max(), i_boundsB.Max(), o_union.Max() );
}

PBR_API
inline void FnBoundsUnion( const Bounds3i& i_boundsA, const Bounds3i& i_boundsB, Bounds3i& o_union )
{
    FnMin( i_boundsA.Min(), i_boundsB.Min(), o_union.Min() );
    FnMax( i_boundsA.Max(), i_boundsB.Max(), o_union.Max() );
}

PBR_API
inline void FnBoundsUnion( const Bounds3f& i_boundsA, const Bounds3f& i_boundsB, Bounds3f& o_union )
{
    FnMin( i_boundsA.Min(), i_boundsB.Min(), o_union.Min() );
    FnMax( i_boundsA.Max(), i_boundsB.Max(), o_union.Max() );
}

PBR_API
inline void FnBoundsUnion( const Bounds2i& i_bounds, const Vec2i& i_point, Bounds2i& o_union )
{
    FnMin( i_bounds.Min(), i_point, o_union.Min() );
    FnMax( i_bounds.Max(), i_point, o_union.Max() );
}

PBR_API
inline void FnBoundsUnion( const Bounds2f& i_bounds, const Vec2f& i_point, Bounds2f& o_union )
{
    FnMin( i_bounds.Min(), i_point, o_union.Min() );
    FnMax( i_bounds.Max(), i_point, o_union.Max() );
}

PBR_API
inline void FnBoundsUnion( const Bounds3i& i_bounds, const Vec3i& i_point, Bounds3i& o_union )
{
    FnMin( i_bounds.Min(), i_point, o_union.Min() );
    FnMax( i_bounds.Max(), i_point, o_union.Max() );
}

PBR_API
inline void FnBoundsUnion( const Bounds3f& i_bounds, const Vec3f& i_point, Bounds3f& o_union )
{
    FnMin( i_bounds.Min(), i_point, o_union.Min() );
    FnMax( i_bounds.Max(), i_point, o_union.Max() );
}

PBR_NAMESPACE_END