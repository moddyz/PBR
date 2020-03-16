#pragma once

/// Operating system variant definitions.

#if defined( _WIN32 ) || defined( _WIN64 )
#    define PBR_WINDOWS
#elif defined( __linux__ )
#    define PBR_LINUX
#elif defined( __APPLE__ ) && defined( __MACH__ )
#    define PBR_OSX
#endif
