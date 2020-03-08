#pragma once

#include <pbr/api.h>
#include <pbr/types/vec3Float.h>

/// Dot-product.

PBR_NAMESPACE_BEGIN

class Vec3Float;

/// Compute the dot product of two vectors.
PBR_API
template < typename VecT >
inline void DotProduct( const VecT& i_lhs, const VecT& i_rhs, typename VecT::ElementType& o_product )
{
    o_product = ( i_lhs[ 0 ] * i_rhs[ 0 ] ) + ( i_lhs[ 1 ] * i_rhs[ 1 ] ) + ( i_lhs[ 2 ] * i_rhs[ 2 ] );
}

PBR_NAMESPACE_END
