#pragma once

/// \file pbr/pbr.h
///
/// Implementation of a physically based renderer.

#include <pbr/utils/export.h>

/// \def PBR_API
///
/// Mark a symbol for external linkage.
#define PBR_API PBR_EXPORT

/// \def PBR_NS
///
/// The namespace hosting all the symbols in the pbr library.
#define PBR_NS pbr

/// \def PBR_NS_USING
///
/// Convenience using directive for PBR_NS.
#define PBR_NS_USING using namespace PBR_NS;

/// \def PBR_NS_OPEN
///
/// Used throughout the library to open the pbr namespace scope.
#define PBR_NS_OPEN                                                                                                    \
    namespace PBR_NS                                                                                                   \
    {
/// \def PBR_NS_CLOSE
///
/// Used throughout the library to close the pbr namespace scope.
#define PBR_NS_CLOSE }
