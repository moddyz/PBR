#pragma once

/* clang-format off */
#ifdef PBR_DEBUG
#define PBR_ASSERT(expr)        \
    if ( !expr )                \
    {                           \
        pbr::AssertHandler();   \
    }
#else
#define PBR_ASSERT(expr) void()
#endif
/* clang-format on */

namespace pbr
{
void AssertHandler();

} // namespace pbr

