#pragma once

#include <pbr/api.h>

#include <pbr/types/vec2f.h>
#include <pbr/types/vec3f.h>
#include <pbr/types/vec4f.h>

#include <pbr/functions/lengthSquared.h>

PBR_NAMESPACE_BEGIN

/// Compute the length of Vec2f.
PBR_API
inline void FnLength( const Vec2f& i_vector, float& o_length )
{
    FnLengthSquared( i_vector, o_length );
    o_length = sqrt( o_length );
}

/// Compute the length of Vec3f.
PBR_API
inline void FnLength( const Vec3f& i_vector, float& o_length )
{
    FnLengthSquared( i_vector, o_length );
    o_length = sqrt( o_length );
}

/// Compute the length of Vec4f.
PBR_API
inline void FnLength( const Vec4f& i_vector, float& o_length )
{
    FnLengthSquared( i_vector, o_length );
    o_length = sqrt( o_length );
}

PBR_NAMESPACE_END