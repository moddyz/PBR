#pragma once

#include <pbr/api.h>

#include <pbr/type/bounds3f.h>
#include <pbr/type/bounds3i.h>

#include <pbr/function/boundsDiagonal.h>

PBR_NAMESPACE_BEGIN

/// Compute the volume of the input bounding box.

PBR_API
inline void FnBoundsVolume( const Bounds3i& i_bounds, int& o_volume )
{
    Vec3i diagonal;
    FnBoundsDiagonal( i_bounds, diagonal );
    o_volume = diagonal.X() * diagonal.Y() * diagonal.Z();
}

PBR_API
inline void FnBoundsVolume( const Bounds3f& i_bounds, float& o_volume )
{
    Vec3f diagonal;
    FnBoundsDiagonal( i_bounds, diagonal );
    o_volume = diagonal.X() * diagonal.Y() * diagonal.Z();
}

PBR_NAMESPACE_END