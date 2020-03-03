#pragma once

/* clang-format off */
#ifdef PBR_DEBUG
#define ASSERT(expr)            \
    if ( expr )                 \
    {                           \
        pbr::AssertHandler();   \
    }
#else
#define ASSERT(expr) void()
#endif
/* clang-format on */

namespace pbr
{
void AssertHandler();

} // namespace pbr

