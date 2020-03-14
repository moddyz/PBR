#pragma once

#include <pbr/api.h>

#include <pbr/type/vec3f.h>

#include <pbr/function/debug.h>

PBR_NAMESPACE_BEGIN

/// Compute the position of a ray, from an origin, direction, and a scaling factor.

PBR_API
inline void FnRayPosition( const Vec3f& i_origin, const Vec3f& i_direction, const float& i_scale, Vec3f& o_rayPosition )
{
    // Direction should be normalised.
    PBR_ASSERT_NORMALISED( i_direction );
    o_rayPosition = i_origin + ( i_direction * i_scale );
}

PBR_NAMESPACE_END