#pragma once

#include <pbr/api.h>

PBR_NAMESPACE_BEGIN

/// Function for comparing if the difference between two values is within a small threshold.
PBR_API
template < typename ValueT >
bool TlAlmostEqual( const ValueT& i_valueA, const ValueT& i_valueB, const ValueT& i_threshold = 0.0001 )
{
    return std::abs( i_valueA - i_valueB ) < i_threshold;
}

PBR_NAMESPACE_END
