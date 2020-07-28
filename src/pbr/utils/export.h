#pragma once

/// \file utils/export.h
///
/// Cross-platform symbol export definitions.
///
/// Windows platform requires flag for marking as symbol for external linkage.

#include <pbr/utils/os.h>

#if defined( PBR_WINDOWS )
#    define PBR_EXPORT __declspec( dllexport )
#else
#    define PBR_EXPORT
#endif
