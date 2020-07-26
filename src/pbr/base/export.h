#pragma once

/// \file base/export.h
///
/// Cross-platform symbol export definitions.
///
/// Windows platform requires flag for marking as symbol for external linkage.

#include <pbr/base/os.h>

#if defined( PBR_WINDOWS )
#    define PBR_EXPORT __declspec( dllexport )
#else
#    define PBR_EXPORT
#endif
