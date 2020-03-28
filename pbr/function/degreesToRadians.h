#pragma once

#include <pbr/api.h>

PBR_NAMESPACE_BEGIN

/// Converts an angle encoded in degrees to radians.

PBR_API
inline void DegreesToRadians( const float& i_degrees, float& o_radians )
{
    constexpr float halfRatio = 3.14159265358979323846 / 180.0;
    o_radians                 = i_degrees * halfRatio;
}

PBR_NAMESPACE_END