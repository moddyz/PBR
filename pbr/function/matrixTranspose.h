#pragma once

#include <pbr/api.h>

#include <pbr/type/mat3f.h>
#include <pbr/type/mat4f.h>

/// Tranpose the input matrix.

PBR_NAMESPACE_BEGIN

PBR_API
inline void FnMatrixTranspose( const Mat3f& i_matrix, Mat3f& o_transposedMatrix )
{
    o_transposedMatrix = Mat3f( i_matrix( 0, 0 ),
                                i_matrix( 1, 0 ),
                                i_matrix( 2, 0 ),
                                i_matrix( 0, 1 ),
                                i_matrix( 1, 1 ),
                                i_matrix( 2, 1 ),
                                i_matrix( 0, 2 ),
                                i_matrix( 1, 2 ),
                                i_matrix( 2, 2 ) );
}

PBR_API
inline void FnMatrixTranspose( const Mat4f& i_matrix, Mat4f& o_transposedMatrix )
{
    o_transposedMatrix = Mat4f( i_matrix( 0, 0 ),
                                i_matrix( 1, 0 ),
                                i_matrix( 2, 0 ),
                                i_matrix( 3, 0 ),
                                i_matrix( 0, 1 ),
                                i_matrix( 1, 1 ),
                                i_matrix( 2, 1 ),
                                i_matrix( 3, 1 ),
                                i_matrix( 0, 2 ),
                                i_matrix( 1, 2 ),
                                i_matrix( 2, 2 ),
                                i_matrix( 3, 2 ),
                                i_matrix( 0, 3 ),
                                i_matrix( 1, 3 ),
                                i_matrix( 2, 3 ),
                                i_matrix( 3, 3 ) );
}

PBR_NAMESPACE_END