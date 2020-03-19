#pragma once

#include <pbr/api.h>

PBR_NAMESPACE_BEGIN

/// Converts an angle encoded in units of radians to degrees.

PBR_API
inline void FnRadiansToDegrees( const float& i_radians, float& o_degrees )
{
    constexpr float halfRatio = 180.0 / 3.14159265358979323846;
    o_degrees                 = i_radians * halfRatio;
}

PBR_NAMESPACE_END