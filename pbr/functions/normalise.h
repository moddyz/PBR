#pragma once

#include <pbr/api.h>

#include <pbr/types/vec2f.h>
#include <pbr/types/vec3f.h>
#include <pbr/types/vec4f.h>

#include <pbr/functions/length.h>

PBR_NAMESPACE_BEGIN

/// Compute the normalised version of the input vector.  A normalised vector has a length of 1.0.

PBR_API
inline void FnNormalise( const Vec2f& i_vector, Vec2f& o_normalised )
{
    float length;
    FnLength( i_vector, length );
    o_normalised = i_vector / length;
}

PBR_API
inline void FnNormalise( const Vec3f& i_vector, Vec3f& o_normalised )
{
    float length;
    FnLength( i_vector, length );
    o_normalised = i_vector / length;
}

PBR_API
inline void FnNormalise( const Vec4f& i_vector, Vec4f& o_normalised )
{
    float length;
    FnLength( i_vector, length );
    o_normalised = i_vector / length;
}

PBR_NAMESPACE_END