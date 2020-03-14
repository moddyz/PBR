#pragma once

#include <pbr/api.h>

#include <pbr/types/vec2f.h>
#include <pbr/types/vec3f.h>
#include <pbr/types/vec4f.h>

#include <pbr/functions/dotProduct.h>

PBR_NAMESPACE_BEGIN

/// Given a normal and a directional vector, conditionally flip the normal so that it faces the hemisphere
/// as the directional vector.

PBR_API
inline void FnFaceForward( const Vec2f& i_normal, const Vec2f& i_direction, Vec2f& o_faceForwardNormal )
{
    // Input vector should be normalised.
#ifdef PBR_DEBUG
    float length;
    FnLength( i_normal, length );
    PBR_ASSERT( TlAlmostEqual( length, 1.0f ) );
#endif

    float product = 0.0f;
    FnDotProduct( i_normal, i_direction, product );
    o_faceForwardNormal = product >= 0 ? i_normal : -i_normal;
}
PBR_API
inline void FnFaceForward( const Vec3f& i_normal, const Vec3f& i_direction, Vec3f& o_faceForwardNormal )
{
    // Input vector should be normalised.
#ifdef PBR_DEBUG
    float length;
    FnLength( i_normal, length );
    PBR_ASSERT( TlAlmostEqual( length, 1.0f ) );
#endif

    float product = 0.0f;
    FnDotProduct( i_normal, i_direction, product );
    o_faceForwardNormal = product >= 0 ? i_normal : -i_normal;
}
PBR_API
inline void FnFaceForward( const Vec4f& i_normal, const Vec4f& i_direction, Vec4f& o_faceForwardNormal )
{
    // Input vector should be normalised.
#ifdef PBR_DEBUG
    float length;
    FnLength( i_normal, length );
    PBR_ASSERT( TlAlmostEqual( length, 1.0f ) );
#endif

    float product = 0.0f;
    FnDotProduct( i_normal, i_direction, product );
    o_faceForwardNormal = product >= 0 ? i_normal : -i_normal;
}

PBR_NAMESPACE_END