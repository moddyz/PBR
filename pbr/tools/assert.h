#pragma once

/* clang-format off */
#ifdef NDEBUG
#define ASSERT(expr)            \
    if ( expr )                 \
    {                           \
        pbr::AssertHandler();   \
    }
#else
#define void()
#endif
/* clang-format on */

namespace pbr
{
void AssertHandler();

} // namespace pbr

