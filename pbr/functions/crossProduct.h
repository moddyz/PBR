#pragma once

#include <pbr/api.h>

PBR_NAMESPACE_BEGIN

/// Compute the cross product of two vectors.
PBR_API
template < typename VecT >
inline void FnCrossProduct( const VecT& i_lhs, const VecT& i_rhs, VecT& o_product )
{
    o_product =
        VecT( ( ( double ) i_lhs.Y() * ( double ) i_rhs.Z() ) - ( ( double ) i_lhs.Z() * ( double ) i_rhs.Y() ),
              ( ( double ) i_lhs.Z() * ( double ) i_rhs.X() ) - ( ( double ) i_lhs.X() * ( double ) i_rhs.Z() ),
              ( ( double ) i_lhs.X() * ( double ) i_rhs.Y() ) - ( ( double ) i_lhs.Y() * ( double ) i_rhs.X() ) );
}

PBR_NAMESPACE_END
