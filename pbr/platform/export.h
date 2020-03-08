#pragma once

#include <pbr/platform/os.h>

/// Cross-platform export directives.

#if defined(PBR_WINDOWS)
/// Windows platform requires explicit directive for external linkage.
#define PBR_EXPORT __declspec( dllexport )
#else
#define PBR_EXPORT
#endif
