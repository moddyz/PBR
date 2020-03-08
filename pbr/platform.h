#pragma once

/// Cross-platform related tools and logic.

/// Platform resolution.

#if defined(_WIN32) || defined(_WIN64)

/// Windows platform requires explicit directive for external linkage.
#define PBR_EXPORT __declspec( dllexport )

#elif defined(__linux__)

#define PBR_EXPORT

#elif defined(__APPLE__) && defined(__MACH__)

#define PBR_EXPORT

#endif

