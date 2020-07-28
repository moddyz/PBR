#pragma once

/// \file utils/assert.h
///
/// \brief Assertion tool for printing the call stack when an expression wrapped with PBR_ASSERT( ... ) fails to
/// evaluate.
///
/// In Debug builds, PBR_ASSERT macro will print the stacktrace when the input expression evaluates to false.
/// In Release builds, the PBR_ASSERT macro will be pre-processed away in Release builds.

#include <pbr/utils/stacktrace.h>

#ifdef PBR_DEBUG
#define PBR_ASSERT( expr )                                                                                             \
    if ( !( expr ) )                                                                                                   \
    {                                                                                                                  \
        printf( "PBR_ASSERT failed for expression: %s, ", expr );                                                      \
        pbr::PrintStacktrace();                                                                                        \
    }
#define PBR_ASSERT_MSG( expr, format, ... )                                                                            \
    if ( !( expr ) )                                                                                                   \
    {                                                                                                                  \
        printf( "PBR_ASSERT failed for expression: %s, ", expr );                                                      \
        printf( format, ##__VA_ARGS__ );                                                                               \
        pbr::PrintStacktrace();                                                                                        \
    }
#else
#define PBR_ASSERT( expr, ... ) void()
#define PBR_ASSERT_MSG( expr, format, ... ) void()
#endif
