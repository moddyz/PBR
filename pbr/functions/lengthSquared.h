#pragma once

#include <pbr/api.h>

PBR_NAMESPACE_BEGIN

/// Compute the squared length of a vector.
PBR_API
template < typename VecT >
inline void FnLengthSquared( const VecT& i_vector, typename VecT::ElementType& o_lengthSquared )
{
    o_lengthSquared = 0;
#pragma unroll
    for ( size_t elementIndex = 0; elementIndex < VecT::GetElementSize(); ++elementIndex )
    {
        o_lengthSquared += i_vector[ elementIndex ] * i_vector[ elementIndex ];
    }
}

PBR_NAMESPACE_END
