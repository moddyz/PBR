#pragma once

#include <pbr/api.h>

#include <pbr/types/vec2f.h>
#include <pbr/types/vec3f.h>
#include <pbr/types/vec4f.h>

#include <pbr/functions/lengthSquared.h>

PBR_NAMESPACE_BEGIN

/// Compute the length of Vec2f.
PBR_API
inline void FnDistanceSquared( const Vec2f& i_vectorA, const Vec2f& i_vectorB, float& o_distanceSquared )
{
    Vec2f diffVector = i_vectorA - i_vectorB;
    FnLengthSquared( diffVector, o_distanceSquared );
}

/// Compute the length of Vec3f.
PBR_API
inline void FnDistanceSquared( const Vec3f& i_vectorA, const Vec3f& i_vectorB, float& o_distanceSquared )
{
    Vec3f diffVector = i_vectorA - i_vectorB;
    FnLengthSquared( diffVector, o_distanceSquared );
}

/// Compute the length of Vec4f.
PBR_API
inline void FnDistanceSquared( const Vec4f& i_vectorA, const Vec4f& i_vectorB, float& o_distanceSquared )
{
    Vec4f diffVector = i_vectorA - i_vectorB;
    FnLengthSquared( diffVector, o_distanceSquared );
}

PBR_NAMESPACE_END