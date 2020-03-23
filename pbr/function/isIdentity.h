#pragma once

#include <pbr/api.h>

#include <pbr/type/mat3f.h>
#include <pbr/type/mat4f.h>

/// Checks if the input is an identity matrix.

PBR_NAMESPACE_BEGIN

PBR_API
inline void FnIsIdentity( const Mat3f& i_matrix, bool& o_isIdentity )
{
    o_isIdentity = i_matrix( 0, 0 ) == 1.0 && i_matrix( 0, 1 ) == 0.0 && i_matrix( 0, 2 ) == 0.0 &&
                   i_matrix( 1, 0 ) == 0.0 && i_matrix( 1, 1 ) == 1.0 && i_matrix( 1, 2 ) == 0.0 &&
                   i_matrix( 2, 0 ) == 0.0 && i_matrix( 2, 1 ) == 0.0 && i_matrix( 2, 2 ) == 1.0;
}

PBR_API
inline void FnIsIdentity( const Mat4f& i_matrix, bool& o_isIdentity )
{
    o_isIdentity =
        i_matrix( 0, 0 ) == 1.0 && i_matrix( 0, 1 ) == 0.0 && i_matrix( 0, 2 ) == 0.0 && i_matrix( 0, 3 ) == 0.0 &&
        i_matrix( 1, 0 ) == 0.0 && i_matrix( 1, 1 ) == 1.0 && i_matrix( 1, 2 ) == 0.0 && i_matrix( 1, 3 ) == 0.0 &&
        i_matrix( 2, 0 ) == 0.0 && i_matrix( 2, 1 ) == 0.0 && i_matrix( 2, 2 ) == 1.0 && i_matrix( 2, 3 ) == 0.0 &&
        i_matrix( 3, 0 ) == 0.0 && i_matrix( 3, 1 ) == 0.0 && i_matrix( 3, 2 ) == 0.0 && i_matrix( 3, 3 ) == 1.0;
}

PBR_NAMESPACE_END