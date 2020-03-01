#pragma once

#include <pxr/base/arch/export.h>

#if defined( PXR_STATIC )
#    define HDPBR_API
#    define HDPBR_API_TEMPLATE_CLASS( ... )
#    define HDPBR_API_TEMPLATE_STRUCT( ... )
#    define HDPBR_LOCAL
#else
#    if defined( HDPBR_EXPORTS )
#        define HDPBR_API ARCH_EXPORT
#        define HDPBR_API_TEMPLATE_CLASS( ... ) ARCH_EXPORT_TEMPLATE( class, __VA_ARGS__ )
#        define HDPBR_API_TEMPLATE_STRUCT( ... ) ARCH_EXPORT_TEMPLATE( struct, __VA_ARGS__ )
#    else
#        define HDPBR_API ARCH_IMPORT
#        define HDPBR_API_TEMPLATE_CLASS( ... ) ARCH_IMPORT_TEMPLATE( class, __VA_ARGS__ )
#        define HDPBR_API_TEMPLATE_STRUCT( ... ) ARCH_IMPORT_TEMPLATE( struct, __VA_ARGS__ )
#    endif
#    define HDPBR_LOCAL ARCH_HIDDEN
#endif
