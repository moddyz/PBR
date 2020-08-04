#pragma once

#include <pbr/pbr.h>

#include <pbr/utils/log.h>
#include <pbr/utils/stacktrace.h>

#include <stdarg.h>

/// \file utils/diagnostic.h
///
/// Diagnostic utilities.

/// \def PBR_ASSERT( expr )
///
/// Asserts that the expression \p expr is \em true in debug builds. If \p expr evalutes \em false,
/// an error message will be printed with contextual information including the failure site.
///
/// In release builds, this is compiled out.
#ifdef PBR_DEBUG
#define PBR_ASSERT( expr )                                                                                             \
    if ( !( expr ) )                                                                                                   \
    {                                                                                                                  \
        PBR_NS::_Assert( #expr, __FILE__, __LINE__ );                                                                  \
        pbr::PrintStacktrace();                                                                                        \
    }
#else
#define PBR_ASSERT( expr, ... ) void()
#endif

/// \def PBR_ASSERT_MSG( expr, format, ... )
///
/// Similar to \ref PBR_ASSERT, with the addition of a formatted message when the expression \p expr fails to evaluate
/// in debug builds.
#ifdef PBR_DEBUG
#define PBR_ASSERT_MSG( expr, format, ... )                                                                            \
    if ( !( expr ) )                                                                                                   \
    {                                                                                                                  \
        PBR_NS::_Assert( #expr, __FILE__, __LINE__ );                                                                  \
        PBR_LOG_ERROR( format, ##__VA_ARGS__ );                                                                        \
        pbr::PrintStacktrace();                                                                                        \
    }
#else
#define PBR_ASSERT_MSG( expr, format, ... ) void()
#endif

/// \def PBR_VERIFY( expr )
///
/// Verifies that the expression \p expr evaluates to \em true at runtime. If \p expr evalutes \em false,
/// an error message will be printed with contextual information including the failure site.
///
/// PBR_VERIFY is different from \ref PBR_ASSERT in that it does \em not get compiled out for release builds,
/// so use sparingly!
#define PBR_VERIFY( expr )                                                                                             \
    if ( !( expr ) )                                                                                                   \
    {                                                                                                                  \
        PBR_NS::_Assert( #expr, __FILE__, __LINE__ );                                                                  \
        pbr::PrintStacktrace();                                                                                        \
    }

/// \def PBR_VERIFY_MSG( expr, format, ... )
///
/// Similar to \ref PBR_VERIFY, with the addition of a formatted message when the expression \p expr fails to evaluate.
#define PBR_VERIFY_MSG( expr, format, ... )                                                                            \
    if ( !( expr ) )                                                                                                   \
    {                                                                                                                  \
        PBR_NS::_Verify( #expr, __FILE__, __LINE__ );                                                                  \
        PBR_LOG_ERROR( format, ##__VA_ARGS__ );                                                                        \
        pbr::PrintStacktrace();                                                                                        \
    }

PBR_NS_OPEN

/// Not intended to be used directly, \ref PBR_ASSERT instead.
inline void _Assert( const char* i_expression, const char* i_file, size_t i_line )
{
    PBR_LOG_ERROR( "Assertion failed for expression: %s, at %s:%lu\n", i_expression, i_file, i_line );
}

/// Not intended to be used directly, \ref PBR_VERIFY instead.
inline void _Verify( const char* i_expression, const char* i_file, size_t i_line )
{
    PBR_LOG_ERROR( "Verification failed for expression: %s, at %s:%lu\n", i_expression, i_file, i_line );
}

PBR_NS_CLOSE
