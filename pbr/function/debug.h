#pragma once

#include <pbr/api.h>

#include <pbr/tool/almost.h>
#include <pbr/tool/assert.h>

#include <pbr/function/length.h>

#include <type_traits>

/// Debugging tools built with tool & function libraries.

/// PBR_ASSERT_NORMALISED asserts that the input vector must be normalised (length of 1.0) in debug builds.
#ifdef PBR_DEBUG
#    define PBR_ASSERT_NORMALISED( vector )                                                                            \
        typedef typename std::decay< decltype( vector ) >::type VectorT;                                               \
        typedef typename VectorT::ElementType                   ScalarT;                                               \
        ScalarT                                                 length;                                                \
        ::pbr::FnLength( vector, length );                                                                             \
        PBR_ASSERT( ::pbr::TlAlmostEqual( length, 1.0f ) );
#else
#    define PBR_ASSERT_NORMALISED( vector ) void()
#endif
