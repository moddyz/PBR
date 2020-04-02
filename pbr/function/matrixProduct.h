#pragma once

#include <pbr/api.h>

#include <pbr/type/mat3f.h>
#include <pbr/type/mat4f.h>

PBR_NAMESPACE_BEGIN

/// Compute the product of two matrices.

PBR_API
inline void MatrixProduct( const Mat3f& i_lhs, const Mat3f& i_rhs, Mat3f& o_matrix )
{
    Mat3f matrix;
    matrix( 0, 0 ) = i_lhs( 0, 0 ) * i_rhs( 0, 0 ) + i_lhs( 0, 1 ) * i_rhs( 1, 0 ) + i_lhs( 0, 2 ) * i_rhs( 2, 0 );
    matrix( 0, 1 ) = i_lhs( 0, 0 ) * i_rhs( 0, 1 ) + i_lhs( 0, 1 ) * i_rhs( 1, 1 ) + i_lhs( 0, 2 ) * i_rhs( 2, 1 );
    matrix( 0, 2 ) = i_lhs( 0, 0 ) * i_rhs( 0, 2 ) + i_lhs( 0, 1 ) * i_rhs( 1, 2 ) + i_lhs( 0, 2 ) * i_rhs( 2, 2 );
    matrix( 1, 0 ) = i_lhs( 1, 0 ) * i_rhs( 0, 0 ) + i_lhs( 1, 1 ) * i_rhs( 1, 0 ) + i_lhs( 1, 2 ) * i_rhs( 2, 0 );
    matrix( 1, 1 ) = i_lhs( 1, 0 ) * i_rhs( 0, 1 ) + i_lhs( 1, 1 ) * i_rhs( 1, 1 ) + i_lhs( 1, 2 ) * i_rhs( 2, 1 );
    matrix( 1, 2 ) = i_lhs( 1, 0 ) * i_rhs( 0, 2 ) + i_lhs( 1, 1 ) * i_rhs( 1, 2 ) + i_lhs( 1, 2 ) * i_rhs( 2, 2 );
    matrix( 2, 0 ) = i_lhs( 2, 0 ) * i_rhs( 0, 0 ) + i_lhs( 2, 1 ) * i_rhs( 1, 0 ) + i_lhs( 2, 2 ) * i_rhs( 2, 0 );
    matrix( 2, 1 ) = i_lhs( 2, 0 ) * i_rhs( 0, 1 ) + i_lhs( 2, 1 ) * i_rhs( 1, 1 ) + i_lhs( 2, 2 ) * i_rhs( 2, 1 );
    matrix( 2, 2 ) = i_lhs( 2, 0 ) * i_rhs( 0, 2 ) + i_lhs( 2, 1 ) * i_rhs( 1, 2 ) + i_lhs( 2, 2 ) * i_rhs( 2, 2 );
    o_matrix       = matrix;
}

PBR_API
inline void MatrixProduct( const Mat4f& i_lhs, const Mat4f& i_rhs, Mat4f& o_matrix )
{
    Mat4f matrix;
    matrix( 0, 0 ) = i_lhs( 0, 0 ) * i_rhs( 0, 0 ) + i_lhs( 0, 1 ) * i_rhs( 1, 0 ) + i_lhs( 0, 2 ) * i_rhs( 2, 0 ) +
                     i_lhs( 0, 3 ) * i_rhs( 3, 0 );
    matrix( 0, 1 ) = i_lhs( 0, 0 ) * i_rhs( 0, 1 ) + i_lhs( 0, 1 ) * i_rhs( 1, 1 ) + i_lhs( 0, 2 ) * i_rhs( 2, 1 ) +
                     i_lhs( 0, 3 ) * i_rhs( 3, 1 );
    matrix( 0, 2 ) = i_lhs( 0, 0 ) * i_rhs( 0, 2 ) + i_lhs( 0, 1 ) * i_rhs( 1, 2 ) + i_lhs( 0, 2 ) * i_rhs( 2, 2 ) +
                     i_lhs( 0, 3 ) * i_rhs( 3, 2 );
    matrix( 0, 3 ) = i_lhs( 0, 0 ) * i_rhs( 0, 3 ) + i_lhs( 0, 1 ) * i_rhs( 1, 3 ) + i_lhs( 0, 2 ) * i_rhs( 2, 3 ) +
                     i_lhs( 0, 3 ) * i_rhs( 3, 3 );
    matrix( 1, 0 ) = i_lhs( 1, 0 ) * i_rhs( 0, 0 ) + i_lhs( 1, 1 ) * i_rhs( 1, 0 ) + i_lhs( 1, 2 ) * i_rhs( 2, 0 ) +
                     i_lhs( 1, 3 ) * i_rhs( 3, 0 );
    matrix( 1, 1 ) = i_lhs( 1, 0 ) * i_rhs( 0, 1 ) + i_lhs( 1, 1 ) * i_rhs( 1, 1 ) + i_lhs( 1, 2 ) * i_rhs( 2, 1 ) +
                     i_lhs( 1, 3 ) * i_rhs( 3, 1 );
    matrix( 1, 2 ) = i_lhs( 1, 0 ) * i_rhs( 0, 2 ) + i_lhs( 1, 1 ) * i_rhs( 1, 2 ) + i_lhs( 1, 2 ) * i_rhs( 2, 2 ) +
                     i_lhs( 1, 3 ) * i_rhs( 3, 2 );
    matrix( 1, 3 ) = i_lhs( 1, 0 ) * i_rhs( 0, 3 ) + i_lhs( 1, 1 ) * i_rhs( 1, 3 ) + i_lhs( 1, 2 ) * i_rhs( 2, 3 ) +
                     i_lhs( 1, 3 ) * i_rhs( 3, 3 );
    matrix( 2, 0 ) = i_lhs( 2, 0 ) * i_rhs( 0, 0 ) + i_lhs( 2, 1 ) * i_rhs( 1, 0 ) + i_lhs( 2, 2 ) * i_rhs( 2, 0 ) +
                     i_lhs( 2, 3 ) * i_rhs( 3, 0 );
    matrix( 2, 1 ) = i_lhs( 2, 0 ) * i_rhs( 0, 1 ) + i_lhs( 2, 1 ) * i_rhs( 1, 1 ) + i_lhs( 2, 2 ) * i_rhs( 2, 1 ) +
                     i_lhs( 2, 3 ) * i_rhs( 3, 1 );
    matrix( 2, 2 ) = i_lhs( 2, 0 ) * i_rhs( 0, 2 ) + i_lhs( 2, 1 ) * i_rhs( 1, 2 ) + i_lhs( 2, 2 ) * i_rhs( 2, 2 ) +
                     i_lhs( 2, 3 ) * i_rhs( 3, 2 );
    matrix( 2, 3 ) = i_lhs( 2, 0 ) * i_rhs( 0, 3 ) + i_lhs( 2, 1 ) * i_rhs( 1, 3 ) + i_lhs( 2, 2 ) * i_rhs( 2, 3 ) +
                     i_lhs( 2, 3 ) * i_rhs( 3, 3 );
    matrix( 3, 0 ) = i_lhs( 3, 0 ) * i_rhs( 0, 0 ) + i_lhs( 3, 1 ) * i_rhs( 1, 0 ) + i_lhs( 3, 2 ) * i_rhs( 2, 0 ) +
                     i_lhs( 3, 3 ) * i_rhs( 3, 0 );
    matrix( 3, 1 ) = i_lhs( 3, 0 ) * i_rhs( 0, 1 ) + i_lhs( 3, 1 ) * i_rhs( 1, 1 ) + i_lhs( 3, 2 ) * i_rhs( 2, 1 ) +
                     i_lhs( 3, 3 ) * i_rhs( 3, 1 );
    matrix( 3, 2 ) = i_lhs( 3, 0 ) * i_rhs( 0, 2 ) + i_lhs( 3, 1 ) * i_rhs( 1, 2 ) + i_lhs( 3, 2 ) * i_rhs( 2, 2 ) +
                     i_lhs( 3, 3 ) * i_rhs( 3, 2 );
    matrix( 3, 3 ) = i_lhs( 3, 0 ) * i_rhs( 0, 3 ) + i_lhs( 3, 1 ) * i_rhs( 1, 3 ) + i_lhs( 3, 2 ) * i_rhs( 2, 3 ) +
                     i_lhs( 3, 3 ) * i_rhs( 3, 3 );
    o_matrix = matrix;
}

PBR_NAMESPACE_END