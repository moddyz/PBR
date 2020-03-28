#pragma once

#include <pbr/api.h>

#include <pbr/type/bounds3f.h>
#include <pbr/type/bounds3i.h>

#include <pbr/function/boundsDiagonal.h>

PBR_NAMESPACE_BEGIN

/// Compute the surface area of the input bounding box.

PBR_API
inline void BoundsSurfaceArea( const Bounds3i& i_bounds, int& o_surfaceArea )
{
    Vec3i diagonal;
    BoundsDiagonal( i_bounds, diagonal );
    o_surfaceArea = ( diagonal.X() * diagonal.Y() ) + ( diagonal.Y() * diagonal.Z() ) + ( diagonal.X() * diagonal.Z() );
}

PBR_API
inline void BoundsSurfaceArea( const Bounds3f& i_bounds, float& o_surfaceArea )
{
    Vec3f diagonal;
    BoundsDiagonal( i_bounds, diagonal );
    o_surfaceArea = ( diagonal.X() * diagonal.Y() ) + ( diagonal.Y() * diagonal.Z() ) + ( diagonal.X() * diagonal.Z() );
}

PBR_NAMESPACE_END