#pragma once

#include <pbr/api.h>

#include <pbr/type/vec2f.h>
#include <pbr/type/vec3f.h>
#include <pbr/type/vec4f.h>

#include <pbr/function/debug.h>
#include <pbr/function/dotProduct.h>

PBR_NAMESPACE_BEGIN

/// Given a normal and a directional vector, conditionally flip the normal so that it faces the hemisphere
/// as the directional vector.

PBR_API
inline void FaceForward( const Vec2f& i_normal, const Vec2f& i_direction, Vec2f& o_faceForwardNormal )
{
    PBR_ASSERT_NORMALISED( i_normal );

    float product = 0.0f;
    DotProduct( i_normal, i_direction, product );
    o_faceForwardNormal = product >= 0 ? i_normal : -i_normal;
}

PBR_API
inline void FaceForward( const Vec3f& i_normal, const Vec3f& i_direction, Vec3f& o_faceForwardNormal )
{
    PBR_ASSERT_NORMALISED( i_normal );

    float product = 0.0f;
    DotProduct( i_normal, i_direction, product );
    o_faceForwardNormal = product >= 0 ? i_normal : -i_normal;
}

PBR_API
inline void FaceForward( const Vec4f& i_normal, const Vec4f& i_direction, Vec4f& o_faceForwardNormal )
{
    PBR_ASSERT_NORMALISED( i_normal );

    float product = 0.0f;
    DotProduct( i_normal, i_direction, product );
    o_faceForwardNormal = product >= 0 ? i_normal : -i_normal;
}

PBR_NAMESPACE_END