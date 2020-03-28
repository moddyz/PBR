#pragma once

#include <pbr/api.h>

#include <pbr/type/vec2f.h>
#include <pbr/type/vec3f.h>
#include <pbr/type/vec4f.h>

#include <pbr/function/length.h>

PBR_NAMESPACE_BEGIN

/// Compute the distance between two points.

PBR_API
inline void Distance( const Vec2f& i_vectorA, const Vec2f& i_vectorB, float& o_distance )
{
    Vec2f diffVector = i_vectorA - i_vectorB;
    Length( diffVector, o_distance );
}

PBR_API
inline void Distance( const Vec3f& i_vectorA, const Vec3f& i_vectorB, float& o_distance )
{
    Vec3f diffVector = i_vectorA - i_vectorB;
    Length( diffVector, o_distance );
}

PBR_API
inline void Distance( const Vec4f& i_vectorA, const Vec4f& i_vectorB, float& o_distance )
{
    Vec4f diffVector = i_vectorA - i_vectorB;
    Length( diffVector, o_distance );
}

PBR_NAMESPACE_END