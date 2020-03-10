#pragma once

#include <pbr/api.h>

#include <pbr/types/vec2f.h>
#include <pbr/types/vec3f.h>
#include <pbr/types/vec4f.h>

PBR_NAMESPACE_BEGIN

/// Compute the squared length of a vector.
PBR_API
inline void FnLengthSquared( const Vec2f& i_vector, float& o_lengthSquared )
{
    o_lengthSquared = 0;
    o_lengthSquared += i_vector[ 0 ] * i_vector[ 0 ];
    o_lengthSquared += i_vector[ 1 ] * i_vector[ 1 ];
}

/// Compute the squared length of a vector.
PBR_API
inline void FnLengthSquared( const Vec3f& i_vector, float& o_lengthSquared )
{
    o_lengthSquared = 0;
    o_lengthSquared += i_vector[ 0 ] * i_vector[ 0 ];
    o_lengthSquared += i_vector[ 1 ] * i_vector[ 1 ];
    o_lengthSquared += i_vector[ 2 ] * i_vector[ 2 ];
}

/// Compute the squared length of a vector.
PBR_API
inline void FnLengthSquared( const Vec4f& i_vector, float& o_lengthSquared )
{
    o_lengthSquared = 0;
    o_lengthSquared += i_vector[ 0 ] * i_vector[ 0 ];
    o_lengthSquared += i_vector[ 1 ] * i_vector[ 1 ];
    o_lengthSquared += i_vector[ 2 ] * i_vector[ 2 ];
    o_lengthSquared += i_vector[ 3 ] * i_vector[ 3 ];
}

PBR_NAMESPACE_END