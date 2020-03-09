#pragma once

#include <pbr/api.h>

#include <pbr/functions/length.h>

/// Vector normalisation.

PBR_NAMESPACE_BEGIN

/// Compute the normalised vector.
PBR_API
template < typename VecT >
inline void FnNormalise( const VecT& i_vector, VecT& o_normalised )
{
    typename VecT::ElementType length;
    FnLength( i_vector, length );
    o_normalised = i_vector / length;
}

PBR_NAMESPACE_END
