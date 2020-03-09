#pragma once

#include <pbr/api.h>

#include <pbr/functions/lengthSquared.h>

PBR_NAMESPACE_BEGIN

/// Compute the length of a vector.
PBR_API
template < typename VecT >
inline void FnLength( const VecT& i_vector, typename VecT::ElementType& o_length )
{
    FnLengthSquared( i_vector, o_length );
    o_length = sqrt( o_length );
}

PBR_NAMESPACE_END
