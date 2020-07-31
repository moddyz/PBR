//
// This file is auto-generated, please do not modify directly!
//

#pragma once

/// \file functions/transformVector.h
/// \ingroup gm_functions_linearAlgebra
///
/// Point transformation.

#include <gm/gm.h>

#include <gm/types/mat4f.h>
#include <gm/types/vec3f.h>

GM_NS_OPEN

/// Transform a \p i_vector with the transformation matrix \p i_matrix.
/// \ingroup gm_functions_linearAlgebra
///
/// \param i_matrix The input matrix to transpose.
///
/// \return Transformed vector.
GM_HOST_DEVICE inline Vec3f TransformVector( const Mat4f& i_matrix, const Vec3f& i_vector )
{
    return Vec3f( i_vector.X() * i_matrix( 0, 0 ) + i_vector.Y() * i_matrix( 0, 1 ) + i_vector.Z() * i_matrix( 0, 2 ),
                  i_vector.X() * i_matrix( 1, 0 ) + i_vector.Y() * i_matrix( 1, 1 ) + i_vector.Z() * i_matrix( 1, 2 ),
                  i_vector.X() * i_matrix( 2, 0 ) + i_vector.Y() * i_matrix( 2, 1 ) + i_vector.Z() * i_matrix( 2, 2 ) );
}

GM_NS_CLOSE