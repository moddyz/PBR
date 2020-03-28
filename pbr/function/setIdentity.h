#pragma once

#include <pbr/api.h>

#include <pbr/type/mat3f.h>
#include <pbr/type/mat4f.h>

/// Sets the identity matrix on the output argument.

PBR_NAMESPACE_BEGIN

PBR_API
inline void SetIdentity( Mat3f& o_identityMatrix )
{
    o_identityMatrix = Mat3f( 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 );
}

PBR_API
inline void SetIdentity( Mat4f& o_identityMatrix )
{
    o_identityMatrix = Mat4f( 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 );
}

PBR_NAMESPACE_END