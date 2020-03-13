#pragma once

#include <pbr/api.h>

#include <pbr/types/vec3f.h>

PBR_NAMESPACE_BEGIN

/// Compute the cross product of two vectors.

PBR_API
inline void FnCrossProduct( const Vec3f& i_lhs, const Vec3f& i_rhs, Vec3f& o_product )
{
    o_product =
        Vec3f( ( ( double ) i_lhs.Y() * ( double ) i_rhs.Z() ) - ( ( double ) i_lhs.Z() * ( double ) i_rhs.Y() ),
               ( ( double ) i_lhs.Z() * ( double ) i_rhs.X() ) - ( ( double ) i_lhs.X() * ( double ) i_rhs.Z() ),
               ( ( double ) i_lhs.X() * ( double ) i_rhs.Y() ) - ( ( double ) i_lhs.Y() * ( double ) i_rhs.X() ) );
}

PBR_NAMESPACE_END