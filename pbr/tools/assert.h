#pragma once

/// \brief Assertion tools for printing function stack, allowing the developer
/// to locate the source of error.
///
/// In Debug builds, PBR_ASSERT macro will print the stacktrace when the input expression evaluates to false.
/// In Release builds, the PBR_ASSERT macro will be pre-processed away in Release builds.

/* clang-format off */
#ifdef PBR_DEBUG
#define PBR_ASSERT(expr)           \
    if ( !expr )                   \
    {                              \
        pbr::AssertHandler(#expr); \
    }
#else
#define PBR_ASSERT(expr) void()
#endif
/* clang-format on */

namespace pbr
{
void AssertHandler( const char* i_expression );

} // namespace pbr

