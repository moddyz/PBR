//
// This file is auto-generated, please do not modify directly!
//

#pragma once

/// \file functions/transformPoint.h
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
GM_HOST_DEVICE inline Vec3f TransformPoint( const Mat4f& i_matrix, const Vec3f& i_vector )
{
    Vec3f transformedPoint( i_vector.X() * i_matrix( 0, 0 ) + i_vector.Y() * i_matrix( 0, 1 ) +
                                i_vector.Z() * i_matrix( 0, 2 ) + i_matrix( 0, 3 ),
                            i_vector.X() * i_matrix( 1, 0 ) + i_vector.Y() * i_matrix( 1, 1 ) +
                                i_vector.Z() * i_matrix( 1, 2 ) + i_matrix( 1, 3 ),
                            i_vector.X() * i_matrix( 2, 0 ) + i_vector.Y() * i_matrix( 2, 1 ) +
                                i_vector.Z() * i_matrix( 2, 2 ) + i_matrix( 2, 3 ) );
    float homogenousWeight = i_vector.X() * i_matrix( 3, 0 ) + i_vector.Y() * i_matrix( 3, 1 ) +
                             i_vector.Z() * i_matrix( 3, 2 ) + i_matrix( 3, 3 );
    if ( homogenousWeight == 1.0 )
    {
        return transformedPoint;
    }
    else
    {
        return transformedPoint / homogenousWeight;
    }
}

GM_NS_CLOSE