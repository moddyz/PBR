#pragma once

#include <pbr/api.h>

/// \brief Cross product.

PBR_NAMESPACE_BEGIN

/// Compute the cross product of two vectors.
PBR_API
template < typename VecT >
inline void FnCrossProduct( const VecT& i_lhs, const VecT& i_rhs, VecT& o_product )
{
    o_product =
        VecT( ( ( double ) i_lhs[ 1 ] * ( double ) i_rhs[ 2 ] ) - ( ( double ) i_lhs[ 2 ] * ( double ) i_rhs[ 1 ] ),
              ( ( double ) i_lhs[ 2 ] * ( double ) i_rhs[ 0 ] ) - ( ( double ) i_lhs[ 0 ] * ( double ) i_rhs[ 2 ] ),
              ( ( double ) i_lhs[ 0 ] * ( double ) i_rhs[ 1 ] ) - ( ( double ) i_lhs[ 1 ] * ( double ) i_rhs[ 0 ] ) );
}

PBR_NAMESPACE_END
