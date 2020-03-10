#pragma once

#include <pbr/api.h>

#include <pbr/types/vec3f.h>

PBR_NAMESPACE_BEGIN

/// Compute the dot product of two Vec3f.
PBR_API
inline void FnDotProduct( const Vec3f& i_lhs, const Vec3f& i_rhs, float& o_product )
{
    o_product = ( i_lhs.X() * i_rhs.X() ) + ( i_lhs.Y() * i_rhs.Y() ) + ( i_lhs.Z() * i_rhs.Z() );
}

PBR_NAMESPACE_END