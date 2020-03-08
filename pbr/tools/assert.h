#pragma once

#include <pbr/api.h>

/// \brief Assertion tools for printing the call stack when an expression wrapped with PBR_ASSERT( ... ) fails to
/// evaluate.
///
/// In Debug builds, PBR_ASSERT macro will print the stacktrace when the input expression evaluates to false.
/// In Release builds, the PBR_ASSERT macro will be pre-processed away in Release builds.

#ifdef PBR_DEBUG
#    define PBR_ASSERT( expr )                                                                                         \
        if ( !( expr ) )                                                                                               \
        {                                                                                                              \
            pbr::Assert( #expr );                                                                                      \
        }
#    define PBR_ASSERT_MSG( expr, format, ... )                                                                        \
        if ( !( expr ) )                                                                                               \
        {                                                                                                              \
            pbr::AssertMsg( #expr, format, ##__VA_ARGS__ );                                                            \
        }
#else
#    define PBR_ASSERT( expr, ... ) void()
#    define PBR_ASSERT_MSG( expr, format, ... ) void()
#endif

PBR_NAMESPACE_BEGIN

void Assert( const char* i_expression );
void AssertMsg( const char* i_expression, const char* i_format, ... );

PBR_NAMESPACE_END

