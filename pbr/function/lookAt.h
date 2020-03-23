#pragma once

#include <pbr/api.h>

#include <pbr/type/mat4f.h>
#include <pbr/type/vec3f.h>

#include <pbr/function/crossProduct.h>
#include <pbr/function/normalise.h>
#include <pbr/function/setTranslate.h>

PBR_NAMESPACE_BEGIN

/// Compute the LookAt transform, provided a position, a point to look at, and a up vector for orientation.
/// This is generally used to position and orient a camera in a scene.

PBR_API
inline void FnLookAt( const Vec3f& i_position, const Vec3f& i_lookAt, const Vec3f& i_upVector, Mat4f& o_matrix )
{
    FnSetTranslate( i_position, o_matrix );
    o_matrix( 3, 3 ) = 1.0;

    // Compute forward vector.
    Vec3f forward = i_lookAt - i_position;
    FnNormalise( forward, forward );

    // Set forward as new Z-axis basis.
    o_matrix( 0, 2 ) = forward[ 0 ];
    o_matrix( 1, 2 ) = forward[ 1 ];
    o_matrix( 2, 2 ) = forward[ 2 ];
    o_matrix( 3, 2 ) = 0.0;

    // Compute right vector.
    Vec3f normUp, right;
    FnNormalise( i_upVector, normUp );
    FnCrossProduct( normUp, forward, right );
    FnNormalise( right, right );

    // Set right as new X-axis basis.
    o_matrix( 0, 0 ) = right[ 0 ];
    o_matrix( 1, 0 ) = right[ 1 ];
    o_matrix( 2, 0 ) = right[ 2 ];
    o_matrix( 3, 0 ) = 0.0;

    // Re-compute new up vector.
    // TODO: Explain why we have to do this.
    Vec3f newUp;
    FnCrossProduct( forward, right, newUp );

    // Set newUp as new X-axis basis.
    o_matrix( 0, 1 ) = newUp[ 0 ];
    o_matrix( 1, 1 ) = newUp[ 1 ];
    o_matrix( 2, 1 ) = newUp[ 2 ];
    o_matrix( 3, 1 ) = 0.0;
}

PBR_NAMESPACE_END