#pragma once

#include <pxr/base/arch/export.h>

#if defined( PXR_STATIC )
#    define HDPBRT_API
#    define HDPBRT_API_TEMPLATE_CLASS( ... )
#    define HDPBRT_API_TEMPLATE_STRUCT( ... )
#    define HDPBRT_LOCAL
#else
#    if defined( HDPBRT_EXPORTS )
#        define HDPBRT_API ARCH_EXPORT
#        define HDPBRT_API_TEMPLATE_CLASS( ... ) ARCH_EXPORT_TEMPLATE( class, __VA_ARGS__ )
#        define HDPBRT_API_TEMPLATE_STRUCT( ... ) ARCH_EXPORT_TEMPLATE( struct, __VA_ARGS__ )
#    else
#        define HDPBRT_API ARCH_IMPORT
#        define HDPBRT_API_TEMPLATE_CLASS( ... ) ARCH_IMPORT_TEMPLATE( class, __VA_ARGS__ )
#        define HDPBRT_API_TEMPLATE_STRUCT( ... ) ARCH_IMPORT_TEMPLATE( struct, __VA_ARGS__ )
#    endif
#    define HDPBRT_LOCAL ARCH_HIDDEN
#endif
