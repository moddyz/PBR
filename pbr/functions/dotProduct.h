#pragma once

#include <pbr/api.h>

/// Dot-product.

PBR_NAMESPACE_BEGIN

/// Compute the dot product of two vectors.
PBR_API
template < typename VecT >
inline void FnDotProduct( const VecT& i_lhs, const VecT& i_rhs, typename VecT::ElementType& o_product )
{
    o_product = ( i_lhs.X() * i_rhs.X() ) + ( i_lhs.Y() * i_rhs.Y() ) + ( i_lhs.Z() * i_rhs.Z() );
}

PBR_NAMESPACE_END
