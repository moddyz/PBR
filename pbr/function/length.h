#pragma once

#include <pbr/api.h>

#include <pbr/type/vec2f.h>
#include <pbr/type/vec3f.h>
#include <pbr/type/vec4f.h>

#include <pbr/function/lengthSquared.h>

PBR_NAMESPACE_BEGIN

/// Compute the length of Vec2f.
PBR_API
inline void Length( const Vec2f& i_vector, float& o_length )
{
    LengthSquared( i_vector, o_length );
    o_length = sqrt( o_length );
}

/// Compute the length of Vec3f.
PBR_API
inline void Length( const Vec3f& i_vector, float& o_length )
{
    LengthSquared( i_vector, o_length );
    o_length = sqrt( o_length );
}

/// Compute the length of Vec4f.
PBR_API
inline void Length( const Vec4f& i_vector, float& o_length )
{
    LengthSquared( i_vector, o_length );
    o_length = sqrt( o_length );
}

PBR_NAMESPACE_END