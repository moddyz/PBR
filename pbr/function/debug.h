#pragma once

#include <pbr/api.h>

#include <pbr/tool/almost.h>
#include <pbr/tool/assert.h>

#include <pbr/function/length.h>

/// Debugging tools for functions.

#ifdef PBR_DEBUG
#    define PBR_ASSERT_NORMALISED( vector )                                                                            \
        float length;                                                                                                  \
        ::pbr::FnLength( vector, length );                                                                             \
        PBR_ASSERT( ::pbr::TlAlmostEqual( length, 1.0f ) );
#else
#    define PBR_ASSERT_NORMALISED( vector ) void()
#endif

