#pragma once

#include <pbr/api.h>

#include <pbr/type/mat4f.h>

#include <pbr/function/transformPoint.h>

/// Transform a \p i_bounds with the transformation matrix \p i_matrix, and write the results
/// into \p o_bounds.

PBR_NAMESPACE_BEGIN

PBR_API
inline void TransformBounds( const Mat4f& i_matrix, const Bounds3f& i_bounds, Bounds3f& o_bounds )
{
    TransformPoint( i_matrix, i_bounds.Min(), o_bounds.Min() );
    TransformPoint( i_matrix, i_bounds.Max(), o_bounds.Max() );
}

PBR_NAMESPACE_END